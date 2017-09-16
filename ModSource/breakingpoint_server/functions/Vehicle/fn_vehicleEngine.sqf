/*
	Function: BP_fnc_vehicleEngine

	Parameters:
		0: Unit (Vehicle)
	
	Method: Call VIA Event Handler
*/

params ["_vehicle","_engineState"];

//["vehicleEngine: Vehicle: %1~0001",_vehicle] call BP_fnc_debugConsoleFormat;
//if (!_engineState) then
//{
//	[_vehicle] call BPServer_fnc_updateQueueAdd;
//};