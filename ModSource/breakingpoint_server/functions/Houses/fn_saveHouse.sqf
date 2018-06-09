/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//["saveHouse: %1",_this] call BP_fnc_debugConsoleFormat;

private ["_building","_buildingType","_buildingConfig","_buildingLockable","_buildingDoors","_buildingID","_buildingUID","_buildingPID","_buildingExplosive","_lock","_buildingPos","_databasePos"];
_building = _this select 0;

if (isNull _building) exitWith {};

_buildingType = 	typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

_buildingLockable = (_buildingType in BP_Houses);
_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");

//Fetch Building Data
_buildingIndex = BP_Buildings find _buildingNetID;
if (_buildingIndex == -1) exitWith {}; // Building not found
_buildingData = BP_BuildingsData select _buildingIndex;

_buildingData params ["_objects","_buildingID","_buildingUID","_buildingPID","_lock","_unlockAttempts","_explosive","_reinforcement"];

_buildingExplosiveInt = 0;
if (_explosive) then { _buildingExplosiveInt = 1; };
_buildingPos = getPosATL _building;
_databasePos = [(round(direction _building)),(_buildingPos select 0),(_buildingPos select 1),(_buildingPos select 2)] call BP_fnc_locationToString;

if (_buildingID == "") exitWith {};
if (_buildingUID == "") exitWith {};
if (_buildingPID == "") exitWith {};
if (_lock == "") exitWith {};

//Save Building
["CHILD:407:%1:%2:%3:%4:%5:'%6':%7:%8:",_buildingPID,_buildingUID,_buildingID,_buildingType,_databasePos,_lock,_buildingExplosiveInt,_reinforcement] call BPServer_fnc_callExtensionAsyncLow;
