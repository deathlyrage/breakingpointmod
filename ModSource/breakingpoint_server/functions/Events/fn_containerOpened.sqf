_container = objectFromNetID (_this select 0);

if (isNull _container) exitWith {};

//Enable Simulation on Container and Nearby Objects
_nearByObj = nearestObjects [(getPosATL _container), ["BP_LootBox","WeaponHolder","WeaponHolderSimulated","BP_DeadBody","CAManBase","BP_SaveObject"],8];
if !(_container in _nearByObj) then { _index = _nearByObj pushBack _container; };
{
	//if !(simulationEnabled _x) then {
	//	_x enableSimulationGlobal true;
	//};
	
	//Spawn In Loot If It's a Loot Box
	//if (_x isKindOf "BP_LootBox") then
	//{
	//	[_x] call BPServer_fnc_containerSpawnLoot;
	//};
} forEach _nearByObj;
