
params ["_logic","_channel","_msg"];

["customChat: Logic: %1 | Channel: %2 | Msg: %3",_logic,_channel,_msg] call BP_fnc_debugConsoleFormat;

if (isNull _logic) exitWith {};

BP_CustomChat = _this;
publicVariable "BP_CustomChat";