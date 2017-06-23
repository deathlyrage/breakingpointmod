/*
	Author: Karel Moricky

	Description:
	Executes a function on server every time a player connects the mission.
	Passed arguments are [player:Object,arguments]

	Parameter(s):
		0: STRING or CODE - function variable or code to be executed
		1: ANY - optional arguments passed to the function
	
	Returns:
	BOOL
*/

private ["_function","_args","_execute"];
_args = [_this,1,[]] call bis_fnc_param;
_execute = [_this,2,false,[false]] call bis_fnc_param;

["Function BIS_fnc_onPlayerConnected has been disabled."] call bis_fnc_error;