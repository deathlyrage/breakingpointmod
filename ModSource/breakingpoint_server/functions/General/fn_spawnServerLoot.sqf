/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

["loot: Starting Loot Mgr."] call BP_fnc_debugConsoleFormat;

BP_LootGlobal = 0;
BP_LootMax = 5000;

_radius = 999999;
_position = getMarkerPos "centre";
_nearby = _position nearObjects ["building",_radius];

_buildingCount = {
	//Check Building and Spawn Loot
	_type = (typeOf _x);

	// Mission config file loot table override.
	_config = configFile >> "CfgBuildingLoot" >> _type;
	if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
	{
		_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
	};

	_spawnLoot = isClass (_config);
	if (_spawnLoot) then {
		["loot: Spawning Loot For Building %1.",_type] call BP_fnc_debugConsoleFormat;
		[_x] call BP_fnc_buildingSpawnLoot;
	};
	_spawnLoot
} count _nearby;

//Output Loot Debug Info
_lootObjs =
{ _x enableSimulation false; } count (allMissionObjects "BP_LootBox");
["loot: Spawned Loot in %1 Buildings.",_buildingCount] call BP_fnc_debugConsoleFormat;
["loot: Lootbox Count: %1",_lootObjs] call BP_fnc_debugConsoleFormat;

