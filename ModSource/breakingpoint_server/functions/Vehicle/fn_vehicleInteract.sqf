/*
	Function: BPServer_fnc_vehicleInteract

	Parameters:
		0: Unit (Vehicle)
	
	Method: Call VIA Public Variable Event Handler
*/

params ["_vehicle"];

["vehicleInteract: Vehicle: %1~0001",_vehicle] call BP_fnc_debugConsoleFormat;

[_vehicle] call BPServer_fnc_updateQueueAdd;