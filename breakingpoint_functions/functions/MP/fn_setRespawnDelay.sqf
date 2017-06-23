/*
	Author: Karel Moricky

	Description:
	Increase the respawn time based on a condition

	Parameter(s):
		0: CODE - Condition, must return BOOL
		1: NUMBER - delay in seconds which is applied when the condition is true
		2: STRING - description displayed when the delay is in effect

	Returns:
	NOTHING
*/
private ["_condition","_delayMax","_description","_delay","_return","_time"];

_condition = [_this,0,{false},[{}]] call bis_fnc_param;
_delayMax = [_this,1,0,[0]] call bis_fnc_param;
_description = [_this,2,"",[""]] call bis_fnc_param;
_delay = 0;

["Function BIS_fnc_setRespawnDelay has been disabled."] call bis_fnc_error;