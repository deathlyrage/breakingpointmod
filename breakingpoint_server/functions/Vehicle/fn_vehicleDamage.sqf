/*
	Function: BPServer_fnc_vehicleDamage

	Parameters:
		0: Vehicle (Object)
		1: Hitpoint Selection (String)
		2: Damage (Integer)
		3: Source (Object)
		4: Projectile (String)
	
	Method: Call VIA Event Handler
*/

params ["_unit","_selection","_total"];

_dam = damage _unit;

if (isNull _unit) exitWith {};

if (_dam < 1) then 
{
	if (_total > 0) then 
	{
		if (_total > 0.98) then {_total = 1;};
		[_unit] call BPServer_fnc_updateQueueAdd;
	};
};


_total