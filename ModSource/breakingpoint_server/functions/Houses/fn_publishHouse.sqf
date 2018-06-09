/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//["publishHouse: %1",_this] call BP_fnc_debugConsoleFormat;

params ["_playerNetID","_characterID","_buildingNetID","_lock","_blueprint"];

_player = objectFromNetID _playerNetID;
_building = objectFromNetID _buildingNetID;

if (isNull _player) exitWith {};
if (isNull _building) exitWith {};

_playerID = (getPlayerUID _player);

if (_characterID == "0") exitWith {};
if (_lock == "") exitWith {};
if (_blueprint == "") exitWith {};

_buildingType = 	typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

_buildingLockable = (_buildingType in BP_Houses);
_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");
_buildingID = _building call BP_fnc_getBuildingID;
_buildingUID = [(direction _building),(getPosATL _building)] call BPServer_fnc_objectUID;

_buildingPos = getPosATL _building;
_databasePos = [(round(direction _building)),(_buildingPos select 0),(_buildingPos select 1),(_buildingPos select 2)] call BP_fnc_locationToString;

//Check Building Limit
_buildingCount = 0;
{
	_x params ["","","","_playerIDBuilding","","","",""];
	if (_playerID == _playerIDBuilding) then { _buildingCount = _buildingCount + 1; };
} count BP_BuildingsData;

//Check Building Isn't Already Claimed
if (netID _building in BP_Buildings) then { _buildingLockable = false; };

//["publishHouse: Lockable: %1 | Building Count: %2",_buildingLockable,_buildingCount] call BP_fnc_debugConsoleFormat;

//Over Building Limit or Not Lockable
if (!_buildingLockable || {_buildingCount > 0}) exitWith {
	//Failure Message
	BP_PublishResult = [false,_blueprint];
	(owner _player) publicVariableClient "BP_PublishResult";
};

//Process Materials
_hasMats = true;
_mats = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Materials");
_magazines = magazines _player;
{
	_index = _magazines find _x;
	if (_index == -1) exitWith { _hasMats = false; };
	0 = _magazines deleteAt _index;
} count _mats;

//Exit If Doesn't Have Materials
if (!_hasMats) exitWith {};

//Remove Materials
{ _player removeMagazineGlobal _x; } count _mats;

//Set Lock Code, Building UID and Player ID
_objects = [];
_unlockAttempts = 0;
_explosive = false;
_reinforcement = 0;

_building addEventHandler ["HandleDamage",{_this call BPServer_fnc_houseHandleDamage;}];
_building addEventHandler ["Killed",{_this call BPServer_fnc_houseKilled;}];

//Add Building To Array
0 = BP_Buildings pushBack (netID _Building);
0 = BP_BuildingsData pushBack [_objects,_buildingID,_buildingUID,_playerID,_lock,_unlockAttempts,_explosive,_reinforcement];
0 = BP_BuildingsLocks pushBack 1;

//Publish New Buildings List
publicVariable "BP_Buildings";
publicVariable "BP_BuildingsLocks";

//Save Building
["CHILD:407:%1:%2:%3:%4:%5:'%6':%7:%8:",_playerID,_buildingUID,_buildingID,_buildingType,_databasePos,_lock,0,0] call BPServer_fnc_callExtensionAsync;

//Success Message
BP_PublishResult = [true,_blueprint];
(owner _player) publicVariableClient "BP_PublishResult";
