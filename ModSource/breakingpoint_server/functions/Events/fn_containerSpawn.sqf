params ["_type","_pos","_minItems","_lootType"];

//Only Spawn Valid Loot Object Types
if !(_type isKindOf "BP_LootBox") exitWith {};

//Spawn Loot Container
_container = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
_container setVariable ["lootItems",_minItems];
_container setVariable ["lootType",_lootType];
_container setVariable ["lootSpawned",false];

//Dynamic Simulation
_container enableDynamicSimulation true;

[_container] call BPServer_fnc_containerSpawnLoot;