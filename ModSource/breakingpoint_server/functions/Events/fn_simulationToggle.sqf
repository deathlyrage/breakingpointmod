params ["_netID","_toggle"];
_netObj = objectFromNetID _netID;
if (isNull _netObj) exitWith {};
_netObj enableSimulationGlobal _toggle;