
params ["_playerNetID","_vehicleNetID","_hitpoint","_part"];

_player = objectFromNetID _playerNetID;
_vehicle = objectFromNetID _vehicleNetID;

if (isNull _player) exitWith {};
if (isNull _vehicle) exitWith {};

// Repairing
_damage = 0;

//Debug Log
["vehicleRepair: Vehicle: %1 | Hitpoint: %2 | Damage: %3",_vehicle,_hitpoint,_damage] call BP_fnc_debugConsoleFormat;

//Make sure Simulation is enabled
if (!simulationEnabled _vehicle) then { _vehicle enableSimulationGlobal true; };

//Make Sure No One Is In The Vehicle
if !(crew _vehicle isEqualTo []) exitWith {};

//Make Sure Vehicle Is not Being Towed
_rope = _vehicle getVariable ["tow",objNull];
if (!isNull _rope) exitWith {};

//Make Sure Player has Part
if !(_part in magazines _player) exitWith {};

//Remove Part From Player
_player removeMagazineGlobal _part;

// Update Vehicle Overall Damage and Hitpoints
_hitpoints = _vehicle call BP_fnc_vehicleHitpointsDmg;
_totalDamage = 0;
_totalHitpoints = count _hitpoints;
{
	_x params ["_hitName","_hitDmg"];
	
	if (_hitName != _hitpoint and _hitDmg > 0) then
	{
		_totalDamage = _totalDamage + (_hitDmg / _totalHitpoints);
	};
} count _hitpoints;

// Set Overall Vehicle Damage
_vehicle setDamage _totalDamage;

// Handle Locality Specific Repair
if (local _vehicle) then
{
	[_vehicle,_hitpoint,_damage,_hitpoints] call BP_fnc_vehicleHandleRepair;
} else {
	[_vehicle,_hitpoint,_damage,_hitpoints] remoteExecCall ["BP_fnc_vehicleHandleRepair", _vehicle];
};

// Add Vehicle To Update Queue
[_vehicle] call BPServer_fnc_updateQueueAdd;
