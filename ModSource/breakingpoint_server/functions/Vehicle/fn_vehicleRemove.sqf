params ["_vehicle","_hitpoint","_damage","_pos","_part"];

// Vehicle is valid
if (isNull _vehicle) exitWith {};

["vehicleRemove: Vehicle: %1 | Hitpoint: %2 | Damage: %3",_vehicle,_hitpoint,_damage] call BP_fnc_debugConsoleFormat;

// Make sure Simulation is enabled
if (!simulationEnabled _vehicle) then { _vehicle enableSimulationGlobal true; };

// Make Sure No One Is In The Vehicle
if !(crew _vehicle isEqualTo []) exitWith {};

// Make Sure Vehicle Is not Being Towed
_rope = _vehicle getVariable ["tow",objNull];
if (!isNull _rope) exitWith {};

// Ensure the part we are removing isn't damaged
_currentDamage = _vehicle getHitPointDamage _hitpoint;
if (_currentDamage > 0) exitWith {};

// Update Vehicle Overall Damage and Hitpoints
_hitpoints = _vehicle call BP_fnc_vehicleHitpointsDmg;
_totalDamage = 0;
_totalHitpoints = count _hitpoints;
{
	_x params ["_hitName","_hitDmg"];
	
	if (_hitName == _hitpoint) then { _hitDmg = _damage; };	

	if (_hitDmg > 0) then
	{
		_totalDamage = _totalDamage + (_hitDmg / _totalHitpoints);
	};
} count _hitpoints;

// Set Overall Vehicle Damage
_vehicle setDamage _totalDamage;

// Handle Locality Specific Repair
if (local _vehicle) then
{
	[_vehicle,_hitpoint,_damage,_hitpoints] call BP_fnc_vehicleHandleRemove;
} else {
	[_vehicle,_hitpoint,_damage,_hitpoints] remoteExecCall ["BP_fnc_vehicleHandleRemove", _vehicle];
};

// Create Removed Part
_item = createVehicle ["groundWeaponHolder", _pos, [], 0, "CAN_COLLIDE"];
_item addMagazineCargoGlobal [_part,1];
_item enableDynamicSimulation true;

//Add Vehicle To Update Queue
[_vehicle] call BPServer_fnc_updateQueueAdd;
