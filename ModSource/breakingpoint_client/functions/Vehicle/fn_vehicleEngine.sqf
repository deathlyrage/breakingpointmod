/*
	Function: BP_fnc_vehicleEngine

	Parameters:
		0: Vehicle (OBJECT)
		1: Engine State (BOOLEAN) TRUE = ON | FALSE = OFF
	
	Method: Call VIA Event Handler
*/

params ["_vehicle","_engineState"];

if (isNull _vehicle) exitWith {};

//Vehicle Damage Check
if (local _vehicle) then 
{
	if (_engineState) then 
	{
		{
			if (["Engine",_x,false] call BP_fnc_inString) then {
				if ((_vehicle getHitPointDamage _x) > 0.82) exitWith
				{
					(vehicle player) engineOn false;
					cutText ["This vehicle's engine is too damaged to drive.", "PLAIN DOWN"];
				};
			};

			if (["Fuel",_x,false] call BP_fnc_inString) then {
				if ((_vehicle getHitPointDamage _x) > 0.82) exitWith
				{
					(vehicle player) engineOn false;
					cutText ["This vehicle's fuel tank is too damaged to drive.", "PLAIN DOWN"];
				};
			};
		} count (_vehicle call BP_fnc_vehicleHitpoints);
	};
};
