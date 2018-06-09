/*
	Author: Karel Moricky

	Description:
	Multiplayer mission init, executed automatically upon mission start.

	Parameter(s):
	None

	Returns:
	NOTHING
*/

if (isMultiplayer) then {
	["Function BIS_fnc_initMultiplayer has been disabled."] call bis_fnc_error;
	BIS_fnc_MP_packet = nil;
	"BIS_fnc_MP_packet" addPublicVariableEventHandler {};
	waituntil {!isnil "bis_functions_mainscope"};
	bis_functions_mainscope setvariable ["BIS_fnc_MP_queue",nil];
};