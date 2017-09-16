params ["_vehicle","_killer"];

if (isNull _vehicle) exitWith {};

//Fetch UID
_objectUID = _vehicle getVariable ["ObjectUID","0"];

//Log Destruction
["vehicleKilled: Vehicle: %1 | Killer: %2",_vehicle,_killer] call BP_fnc_debugConsoleFormat;

//Remove All Event Handlers
_vehicle removeAllEventHandlers "FiredNear";
_vehicle removeAllEventHandlers "HandleDamage";
_vehicle removeAllEventHandlers "Killed";
_vehicle removeAllEventHandlers "Local";
_vehicle removeAllEventHandlers "Fired";
_vehicle removeAllEventHandlers "GetOut";
_vehicle removeAllEventHandlers "GetIn";
_vehicle removeAllEventHandlers "Local";

//Add To Destroy Queue
[_object] call BPServer_fnc_destroyQueueAdd;

//Save Vehicle as Destroyed
["CHILD:501:%1:",_objectUID] call BPServer_fnc_callExtensionAsync;