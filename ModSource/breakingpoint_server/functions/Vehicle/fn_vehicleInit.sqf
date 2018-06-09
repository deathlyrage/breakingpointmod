params ["_vehicle"];
_vehicle addEventHandler ["HandleDamage",{_this call BP_fnc_vehicleDamage;}];
_vehicle addEventHandler ["Engine", {_this call BP_fnc_vehicleEngine;}];
_vehicle addEventHandler ["Local", {_this call BP_fnc_vehicleLocal;}];
//["vehicleInit: %1",_vehicle] call BP_fnc_debugConsoleFormat;