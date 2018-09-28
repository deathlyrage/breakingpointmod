_building = _this select 0;
_buildingPos = getPosATL _building;
_buildingType = 	typeOf _building;
_buildingSize = ((sizeOf _buildingType)+5);

_buildingNetID = netID _building;
_buildingIndex = BP_Buildings find _buildingNetID;

if (_buildingIndex == -1) exitWith {}; // Building not found

_buildingData = BP_BuildingsData select _buildingIndex;
_buildingData params ["_objects","_buildingID","_buildingUID","_playerID","_lock","_unlockAttempts","_explosive","_reinforcement"]; 

//Logging
//["houseKilled: %1", _building] call BP_fnc_debugConsoleFormat;


if (_reinforcement > 0) then
{
    _buildingData set [7,_reinforcement-1];
	BP_BuildingsData set [_buildingIndex,_buildingData];
    [_building] call BPServer_fnc_saveHouse;

} else {
	//Delete House
	[_buildingNetID] call BPServer_fnc_deleteHouse;

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
};
