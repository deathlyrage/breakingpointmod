/*
	Function: BP_fnc_vehicleInit

	Parameters:
		0: Vehicle (OBJECT)
	
	Method: Call VIA Event Handler
*/

private "_vehicle";
_vehicle = _this select 0;

if (isNull _vehicle) exitWith {};

//["vehicleInit: Vehicle: %1",_vehicle] call BP_fnc_debugConsoleFormat;

_vehicle addEventHandler ["HandleDamage",{_this call BP_fnc_vehicleDamage;}];
_vehicle addEventHandler ["Engine", {_this call BP_fnc_vehicleEngine;}];
_vehicle addEventHandler ["Local", {_this call BP_fnc_vehicleLocal;}];
_vehicle addEventHandler ["Fired", {_this call BP_fnc_vehicleFired;}];
_vehicle disableTIEquipment true;
