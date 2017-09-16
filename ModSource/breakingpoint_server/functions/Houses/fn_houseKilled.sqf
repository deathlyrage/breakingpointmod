_building = _this select 0;
_buildingPos = getPosATL _building;
_buildingType = 	typeOf _building;
_buildingSize = ((sizeOf _buildingType)+5);

//Logging
//["houseKilled: %1",_building] call BP_fnc_debugConsoleFormat;

//Delete House
[(netID _building)] call BPServer_fnc_deleteHouse;

//Process Storage Damage
_deleteTypes = ["BP_LootBox","WeaponHolder","WeaponHolderSimulated"];
_nearbyStorage = nearestObjects [_buildingPos, ["BP_LootBox","WeaponHolder","WeaponHolderSimulated","BP_Storage"],_buildingSize];
{
	_type = (typeOf _x);
	if (_type in _deleteTypes) then {
		deleteVehicle _x;
	} else {
		_rnd = floor (random 100);
		if (_rnd < 75) then { _x setDamage 1; };
	};
} count _nearbyStorage;