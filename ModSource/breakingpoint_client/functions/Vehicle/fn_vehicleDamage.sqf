/*
	Function: BP_fnc_vehicleDamage

	Parameters:
		0: Vehicle (OBJECT)
		1: Selection (STRING)
		2: Damage (NUMBER)
		3: Source (OBJECT)
		4: Projectile (STRING)
	
	Method: Call VIA Event Handler
*/

params ["_vehicle","_selection","_damage","_source","_projectile"];

if (isNull _vehicle) exitWith {0};

_local = (local _vehicle);

//Logging
["vehicleDamage: Vehicle: %1 | Selection: %2 | Damage: %3 | Source: %4 | Projectile: %5 | Local: %6",_vehicle,_selection,_damage,_source,_projectile,_local] call BP_fnc_debugConsoleFormat;

_damage