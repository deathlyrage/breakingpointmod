/*
	Function: BPServer_fnc_dogSync;
	Description: Saves a character's dog to the database in a light update.
	Example: _dog call BPServer_fnc_dogSync;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

private ["_dog","_characterID","_dogData"];
_dog = _this;

if (isNull _dog) exitWith {};

_characterID = _dog getVariable ["CharacterID","0"];
if (_characterID == "0") exitWith {};

if (alive _dog) then
{
	_class = switch (typeOf _dog) do {
		default 					{0};
		case "BP_Dog_1":			{1};
		case "BP_Dog_2": 			{2};
		case "BP_Dog_3": 			{3};
		case "BP_Dog_4": 			{4};
		case "BP_Dog_5": 			{5};
		case "BP_Dog_6": 			{6};
		case "BP_Dog_7": 			{7};
	};
	_name = _dog getVariable ["bodyName","Dog"];
	_hunger = _dog getVariable ["hunger",0];
	_thirst = _dog getVariable ["thirst",0];
	_blood = _dog getVariable ["blood",8000];
	_zKills = _dog getVariable ["zombieKills",0];
	_pKills = _dog getVariable ["humanKills",0];
	_dogData = [_class,_name,_hunger,_thirst,_blood,_zKills,_pKills];
} else {
	_dogData = [];
};

["dogSync: %1",_dogData] call BP_fnc_debugConsoleFormat;

// Everything is ready, now publish to HIVE
["CHILD:304:%1:%2:",_characterID,_dogData] call BPServer_fnc_callExtensionAsync;
