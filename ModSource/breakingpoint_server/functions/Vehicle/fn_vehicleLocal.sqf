params ["_vehicle","_local"];

if (isNull _vehicle) exitWith {};

["vehicleLocal: Vehicle: %1 | Local: %2~0001",_vehicle,_local] call BP_fnc_debugConsoleFormat;

[_vehicle] call BPServer_fnc_updateQueueAdd;