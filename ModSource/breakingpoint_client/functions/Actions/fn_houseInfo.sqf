/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_building","_buildingType","_buildingConfig","_buildingLockable","_buildingDoors","_buildingExplosive"];
_building = _this select 3;
_buildingType = 	typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

_buildingLockable = (_buildingType in BP_Houses);
_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");

//Remove Action to Prevent Spam
player removeAction s_player_infoHouse;
s_player_infoHouse = -1;

//Exit If Null Building
if (isNull _building) exitWith {};

[(netID _building),(netID player),"info"] remoteExecCall ["BPServer_fnc_upgradeHouse",2];
