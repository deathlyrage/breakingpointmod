scriptName "BP_fnc_cleanupLoot";

// All Weapon Holder Objects
//{
//	_keep = _x getVariable ["permaLoot",false];
//	if (!_keep) then {
//		_nearby = [(getPosATL _x),25] call BP_fnc_nearbyPlayers;
//		if (!_nearby) then { deleteVehicle _x; };
//	};
//} count allMissionObjects "WeaponHolder";

// All Weapon Holder Objects
//{
//	_keep = _x getVariable ["permaLoot",false];
//	if (!_keep) then {
//		_nearby = [(getPosATL _x),25] call BP_fnc_nearbyPlayers;
//		if (!_nearby) then { deleteVehicle _x; };
//	};
//} count allMissionObjects "WeaponHolderSimulated";

// Loot Box Objects
{
	if !(_x getVariable ["permaLoot",false]) then {
		_nearby = [(getPosATL _x),75] call BP_fnc_nearbyPlayers;
		if (!_nearby) then { 
			deleteVehicle _x;
		};
	};
} count entities "BP_LootBox";

//Update Timer
BP_Cleanup_lastLoot = diag_tickTime;