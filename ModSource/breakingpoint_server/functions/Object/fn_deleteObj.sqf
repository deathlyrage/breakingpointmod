/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_charID","0",[""]],"_objNetID",["_action","0",[""]],"_playerNetID"];

_obj = objectFromNetID _objNetID;
_playerObj = objectFromNetID _playerNetID;

if (isNull _obj) exitWith {};
if (isNull _playerObj) exitWith {};

if (_charID == "0") exitWith {};
if (_action == "0") exitWith {};

_playerID = getPlayerUID _playerObj;
_playerName = name _playerObj;
_deployableID = _obj getVariable ["ObjectUID","0"];

_objType = (typeOf _obj);
_objOwnerCharID = _obj getVariable ["CharacterID","0"];
_objOwnerPlayerID = _obj getVariable ["PlayerID","0"];
_objPos = (getPosATL _obj);

_log = true;

["destroyObject: Object: %1 | Char ID: %2 | Action: %3",_obj,_charID,_action] call BP_fnc_debugConsoleFormat;

switch (_action) do 
{
	case "Ignite": 	
	{
		_fireObj = createVehicle ["BP_Fire", _objPos, [], 0, "CAN_COLLIDE"];
		_fireObj setPosATL _objPos;
		_fireObj enableDynamicSimulation true;
		0 = BP_ObjectDestroyQueue pushBack (netID _fireObj);
		_obj allowDamage true;
		_obj setDamage 1;
		
		// Faction System - Points
		if ((_charID != _objOwnerCharID) and (_playerID != _objOwnerPlayerID)) then
		{
			_classID = _playerObj getVariable ["class",0];
			_pointsChange = 0;

			if (_classID > 0) then 
			{
				//Calculate Faction Information
				_factionName = _classID call BP_fnc_getFactionName;
				_ownerFaction = _objType call BP_fnc_getFactionOwner;
			
				//Calculate Point Gain / Loss
				_pointsChange = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "Destroy" >> _ownerFaction >> "storage");
				
				["destroyObject: Player Faction: %1 | Owner Faction: %2 | Points: %3",_factionName,_ownerFaction,_pointsChange] call BP_fnc_debugConsoleFormat;
	
				//Add Points (Global)
				[_playerObj,_pointsChange] call BPServer_fnc_addFactionPoints;
				
				//Sync Player
				if (_pointsChange != 0) then { _playerObj call BPServer_fnc_statsSync; };
			};

		};
	};
	case "Delete": 
	{
		[_obj,true] call BPServer_fnc_destroyObj;
	};
	case "Explode": 
	{
		_log = false;

		//Explode Object
		_explosive = "BP_IED" createVehicle _objPos;
		_explosive setPosATL _objPos;
		_explosive setDamage 1;
		
		//Unlock the safe so it spawns items on the ground
		[_obj] call BPServer_fnc_unlockObj;
		
		//Spawn Items on Ground
		[_obj,false] call BPServer_fnc_destroyObj;
	};
};

//Put Entry on Storage Log
if (_log) then {
	[_playerID,_playerName,_deployableID,_objType,_objOwnerPlayerID] call BPServer_fnc_storageLog;
};
