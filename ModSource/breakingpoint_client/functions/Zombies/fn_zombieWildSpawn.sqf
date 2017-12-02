/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_position","_doLoiter","_unitTypes","_isNoone","_loot","_array","_agent","_type","_radius","_method","_nearByPlayer","_attempt","_myDest","_newDest","_lootType"];

if (speed (vehicle player) >= 140) exitWith {};

if (true) exitWith {};

if (!BP_Zeds) exitWith {};
if (BP_LocalZeds > BP_ZedMaxLocal) exitWith {};
if (BP_NearbyZombies > BP_ZedMaxNearby) exitwith {};
if (BP_SpawnZombies > BP_ZedMaxNearby) exitWith {};
if (BP_RemoteZeds > BP_GlobalZeds) exitWith {};
if (BP_GlobalZeds > BP_ZedMaxGlobal) exitWith {};

_player = _this select 0;

_config = configFile >> "CfgBuildingLoot";
if (isClass (missionConfigFile >> "CfgBuildingLoot")) then
{
	_config = missionConfigFile >> "CfgBuildingLoot";
};
_unitTypes = 	[]+ getArray (_config >> "Default" >> "zombieClass");
_doLoiter = 	true;

_loot = 	"";
_array = 	[];
_agent = 	objNull;

_type = selectRandom _unitTypes;

_radius = 40;
_method = "NONE";

_position = [_player,120,200,10,0,0,0] call BIS_fnc_findSafePos;

//Wild Zombies Don't Spawn in Claimed Houses
_building = _position nearestObject "HouseBase";
_buildingClaimed = (_building getVariable ["key",""] != "");
if (_buildingClaimed) exitWith {};

//Wild Zombies Don't Spawn In Faction Strongholds
//_nearStronghold = _position call BP_fnc_posNearStronghold;
//if (_nearStronghold) exitWith {};

_agent = createAgent [_type, _position, [], _radius, _method];
if (_doLoiter) then {
	//_agent setPosATL _position;
	_agent setDir round(random 180);
};

BP_NearbyZombies = BP_NearbyZombies + 1;
BP_LocalZeds = BP_LocalZeds + 1;
BP_GlobalZeds = BP_GlobalZeds + 1;

_isAlive = alive _agent;

_myDest = getPosATL _agent;
_newDest = getPosATL _agent;
_agent setVariable ["myDest",_myDest];
_agent setVariable ["newDest",_newDest];
_agent addRating -2500;

_agentID = [_position,_agent] execFSM "\breakingpoint_code\system\zombie_agent.fsm";
