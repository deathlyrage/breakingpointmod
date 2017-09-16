private ["_container","_nearByObj"];
_container = objectFromNetID (_this select 0);

//["containerClosed: %1",_container] call BP_fnc_debugConsoleFormat;

//Save Nearby Objects
_nearByObj = nearestObjects [(getPosATL _container), ["BP_LootBox","GroundWeaponHolder","WeaponHolderSimulated","BP_DeadBody","BP_SaveObject","Car","Boat","Helicopter"],10];
if !(_container in _nearByObj) then { _index = _nearByObj pushBack _container; };
{
	if (_container isKindOf "BP_Storage" || {_container isKindOf "Car"} || {_container isKindOf "Boat"} || {_container isKindOf "Helicopter"}) then {
		[_x] call BPServer_fnc_updateQueueAdd;
	};
} count _nearByObj;
