/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_building"];
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

//Exit If Null Building
if (isNull _building) exitWith {};

//_buildingLogic setVariable ['bis_disabled_Door',1,true];

//Ensure Player Isn't Inside Building
//_inside = [player] call BP_fnc_isInsideBuilding;
//if (_inside) exitWith {
//	cutText ["You can't lock the building while inside it.", "PLAIN DOWN"];
//};

//Remove Action to Prevent Spam
player removeAction s_player_lockHouse;
s_player_lockHouse = -1;
player removeAction s_player_unlockHouse;
s_player_unlockHouse = -1;

//Lock Doors

[(netID _building)] remoteExecCall ["BPServer_fnc_lockHouse",2];

//Message
cutText ["Building Locked.", "PLAIN DOWN"];

sleep 1;

call BP_fnc_buildingUpdate;
