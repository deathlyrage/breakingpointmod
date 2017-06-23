/*
	Author: Karel Moricky

	Description:
	Execute received remote execution

	Parameter(s):
	_this select 0: STRING - Packet variable name (always "BIS_fnc_MP_packet")
	_this select 1: ARRAY - Packet value (sent by BIS_fnc_MP function; see it's description for more details)
	
	Returns:
	BOOL - true if function was executed successfuly
*/
private ["_params","_functionName","_target","_isPersistent","_isCall","_varName","_varValue","_function"];

_varName = _this select 0;
_varValue = _this select 1;

_mode = 	[_varValue,0,[0]] call bis_fnc_param;
_params = 	[_varValue,1,[]] call bis_fnc_param;
_functionName =	[_varValue,2,"",[""]] call bis_fnc_param;
_target =	[_varValue,3,true,[objnull,true,0,[],sideUnknown,grpnull,""]] call bis_fnc_param;
_isPersistent =	[_varValue,4,false,[false]] call bis_fnc_param;
_isCall =	[_varValue,5,false,[false]] call bis_fnc_param;

["Function BIS_fnc_MPexec has been disabled."] call bis_fnc_error;