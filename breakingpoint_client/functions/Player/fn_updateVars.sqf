/*
	Function: BP_fnc_updateVars
	Called: Every 40 Seconds
	Purpose: Update Common Client Cached Variables
	Author: Deathlyrage
*/

#define RADIUS 300

if (isNil "r_player_dead") exitWith {};

BP_LootGlobal = (count entities "BP_LootBox");

private ["_allZeds","_aliveZeds","_localZeds","_remoteZeds","_deadZeds"];

_allZeds = 0;
_aliveZeds = 0;
_localZeds = 0;
_remoteZeds = 0;
_deadZeds = 0;

{
	// All Zombies
	_allZeds = _allZeds + 1;

	// Alive Zombies
	if (alive _x) then {
		_aliveZeds = _aliveZeds + 1;
	} else {
		_deadZeds = _deadZeds + 1;
	};

	if (local _x) then {
		_localZeds = _localZeds + 1;
	} else {
		_remoteZeds = _remoteZeds + 1;
	};
} count entities "zZombie_Base";

_position = getPosATL player;

BP_LocalZeds = _localZeds;
BP_NearbyZombies = {alive _x} count (_position nearEntities ["zZombie_Base",RADIUS]);
BP_GlobalZeds = _aliveZeds;
BP_SpawnZombies = {alive _x AND local _x} count (_position nearEntities ["zZombie_Base",RADIUS]);
BP_RemoteZeds = _remoteZeds;
BP_DeadZeds = _deadZeds;

BP_maxCurrentZeds = BP_GlobalZeds;