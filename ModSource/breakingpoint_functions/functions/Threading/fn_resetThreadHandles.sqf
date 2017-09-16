/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Undefined Thread Handles then Exit
if (isNil "BP_Threads") exitWith {false};

//Loop Through All Threads and Terminate Them
{
	if (!isNull _x) then {
		terminate _x;
		["Terminating Thread: %1",_x] call BP_fnc_debugConsoleFormat;
	};
} count BP_Threads;

//Reset Thread Handle Array to Undefined
BP_Threads = nil;

//Return Success
true