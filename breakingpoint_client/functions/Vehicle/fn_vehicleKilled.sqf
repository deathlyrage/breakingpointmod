/*
	Function: BP_fnc_vehicleKilled

	Parameters:
		0: Vehicle (OBJECT)
		1: Killer (OBJECT)
	
	Method: Call VIA Event Handler
*/

params ["_vehicle","_killer"];

if (isNull _vehicle) exitWith {};

["vehicleKilled: Vehicle: %1 | Killer: %2",_vehicle,_killer] call BP_fnc_debugConsoleFormat;

if (local _vehicle) then {
	//Don't Use NetID Here to allow for both vehicles / event handlers to use the same code
	[_vehicle,_killer] remoteExecCall ["BP_fnc_vehicleKilled",2];
};

//Commented These because they are global
//_vehicle removeAllMPEventHandlers "MPKilled";
//_vehicle removeAllMPEventHandlers "MPHit";
//_vehicle removeAllMPEventHandlers "MPRespawn";
_vehicle removeAllEventHandlers "FiredNear";
_vehicle removeAllEventHandlers "HandleDamage";
_vehicle removeAllEventHandlers "Explosion";
_vehicle removeAllEventHandlers "Killed";
_vehicle removeAllEventHandlers "Fired";
_vehicle removeAllEventHandlers "GetOut";
_vehicle removeAllEventHandlers "GetIn";
_vehicle removeAllEventHandlers "Local";
_vehicle removeAllEventHandlers "Engine";