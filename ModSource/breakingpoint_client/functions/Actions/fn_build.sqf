/*
	Breaking Point Mod: BP_fnc_constructStorage

	Description:
	Function for a player to create a storage component and submit it for creation server side.
	
	Parameter(s):
	-_this select 0: Classname Of Blueprint
	
	Returns:
	None
	
	Todo:
	-Custom Sounds, Animations, Effects
*/

private ["_build","_object","_classname","_blueprint","_objectName","_isFlatEmpty"];

//Remove Actions To Avoid Duplicate Actions
player removeAction s_player_buildComplete;
s_player_buildComplete = -1;
player removeAction s_player_buildCancel;
s_player_buildCancel = -1;

_build = (_this select 0);

_object = player getVariable ["constructionObject", objNull];
_classname = player getVariable ["constructionClassname",""];
_blueprint = player getVariable ["constructionBlueprint",""];

if (isNull _object) exitWith {};
if (_classname == "") exitWith {};
if (_blueprint == "") exitWith {};

_objectName = getText(ConfigFile >> "CfgVehicles" >> _classname >> "displayName");

if (_build) then 
{
	if (_blueprint in BP_TrapBuildables) then
	{
		_valid = false;
		if (_blueprint in magazines player) then
		{
			_valid = true;
			player removeMagazine _blueprint;
		
			//Deattach Old Crate
			detach _object;
		
			//Get Object Exact Position and Rotation
			_dir = getDir _object;		
			_pos = getPosATL _object;
			
			//Delete Old Crate
			deleteVehicle _object;

			[(netID player),BP_characterID,_blueprint,_classname,_pos,_dir] remoteExecCall ["BPServer_fnc_publishTrap",2];
		};

		//Remove Complete Build Option
		player setVariable ["constructionObject", objNull];
		player setVariable ["constructionClassname",""];
		player setVariable ["constructionBlueprint",""];

		if (!_valid) then
		{
			deleteVehicle _object;

			cutText ["Item no longer in your inventory. Building Cancelled.", "PLAIN DOWN"];
		};
	} else {
		_objectType = (typeOf _object);
		_valid = _object call BP_fnc_objCheck;
		if (!_valid) exitWith { cutText ["You must be on flat ground and clear of other objects.", "PLAIN DOWN"]; };

		//Deattach Old Crate
		detach _object;

		//Get Object Exact Position and Rotation
		_pos = getPosATL _object;
		_dir = getDir _object;
		
		_isSafe = (_object isKindOf "BP_Safe");
		
		//Delete Old Crate
		deleteVehicle _object;
		
		//Get Combo (If Safe)
		_failure = false;

		if (_isSafe) then 
		{
			//Keep Going Until Valid Code Recieved
			_validCode = false;
			while {!_validCode} do
			{
				//Get Building Passcode
				BP_SafeSet = nil;
				_safeKeyThread = [] spawn BP_fnc_safeKeypadSet;
				[_safeKeyThread] call BP_fnc_addThreadHandle;
				waitUntil {scriptDone _safeKeyThread};
				
				//Check If Passcode Is Correct
				if (isNil "BP_SafeSet") then { BP_SafeSet = "0"; };
				_keyArray = toArray BP_SafeSet;
				if (count _keyArray < 4) then {
					_validCode = false;
				} else {
					_validCode = true;
				};
			};
		};
		
		if (_failure) exitWith {};
		
		_building = objNull;
		if (_classname isKindOf "BP_HouseStorage" || {_classname isKindOf "BP_HouseObject"}) then {
			_building = nearestObject [player, "HouseBase"];
		};
		
		//Publish Object To Server
		if (isNil "BP_SafeSet") then { BP_SafeSet = ""; };
		[(netID player),BP_characterID,_blueprint,BP_SafeSet,_classname,_pos,_dir,_building] remoteExecCall ["BPServer_fnc_publishObj",2];

		//Remove Complete Build Option
		player setVariable ["constructionObject", objNull];
		player setVariable ["constructionClassname",""];
		player setVariable ["constructionBlueprint",""];
	};
} else {	
	player setVariable ["constructionObject", objNull];
	player setVariable ["constructionClassname",""];
	player setVariable ["constructionBlueprint",""];

	deleteVehicle _object;

	cutText ["Building Cancelled.", "PLAIN DOWN"];
};
