/*
	Function: BP_fnc_vehicleInteract

	Parameters:
		0: Vehicle (OBJECT) Vehicle the event handler is assigned to
		1: Position (STRING) Can be either "driver", "gunner", "commander" or "cargo"
		2: Unit (OBJECT) Unit that entered the vehicle
	
	Method: Call VIA Event Handler
*/

params ["_vehicle","_position","_unit"];

if (isNull _vehicle) exitWith {};

["vehicleDamage: Vehicle: %1 | Selection: %2 | Damage: %3 | Source: %4 | Projectile: %5",_vehicle,_selection,_damage,_source,_projectile] call BP_fnc_debugConsoleFormat;

//Check Vehicle Engine
if (local _vehicle) then {
	[_vehicle,(isEngineOn _vehicle)] call BP_fnc_vehicleEngine;
};