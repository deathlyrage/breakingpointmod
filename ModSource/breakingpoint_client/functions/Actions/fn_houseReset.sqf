/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_building","_buildingType","_buildingConfig"];
_building = _this select 3;
_buildingType = typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

//Exit If Null Building
if (isNull _building) exitWith {};

//Exit If Player Doesn't Have a Toolbox
_hasToolbox = "ItemToolbox" in assignedItems player;
if (!_hasToolbox) exitWith { cutText ["You need a toolbox to remove the lock from this building.", "PLAIN DOWN"]; };

_leaveReturn = ["Are you sure you would like to remove the lock on this house.","Remove Lock",nil,true] call BIS_fnc_guiMessage;
if (!_leaveReturn) exitWith {};

//Remove Action to Prevent Spam
player removeAction s_player_resetHouse;
s_player_resetHouse = -1;
player removeAction s_player_lockHouse;
s_player_lockHouse = 1;
player removeAction s_player_unlockHouse;
s_player_unlockHouse = 1;

//Send RPC call to reset house
[(netID _building)] remoteExecCall ["BPServer_fnc_deleteHouse",2];

cutText ["Lock Removed From Building", "PLAIN DOWN"];
