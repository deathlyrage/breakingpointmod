/*
	File: timing.sqf
	Authors: Unknown & Joris-Jan van 't Land

	Description:
	Script for timing in MP missions.
	Must run on all computers.
	
	Returns:
	Success flag (Boolean)
*/

if (Param1 >= 10000) exitWith {false};

//Variables
BIS_ShowTime = 0;

private ["_times", "_strings", "_i", "_j"];
_times = [3600, 1800, 1200, 600, 300, 120];
_strings = [localize "STR_MP_07", localize "STR_MP_06", localize "STR_MP_05", localize "STR_MP_04", localize "STR_MP_03", localize "STR_MP_02"];
_i = 0;
_j = 0;

sleep 5;

//Initialization - for times set not to the max.
{
	_j = _times select _i;
	if (Param1 >= _j) exitWith {};
	
	_i = _i + 1;
} 
forEach _times;
//Initialization - End.

while {true} do 
{
	if (isServer) then 
	{
		//When the server reached the next time notification, it tells all clients.
		waitUntil {(Param1 - time) <= _j};
		
		BIS_ShowTime = _i + 1; 
		publicVariable "BIS_ShowTime";
	};
	
	//All clients wait for the server to tell them it's time to show a hint.
	waitUntil {BIS_ShowTime > 0};
	
	_i = (BIS_ShowTime - 1);
	hint (_strings select _i);
	
	//All times were shown.
	if (_i == (count _times)) exitWith {};
	
	sleep 30;
	
	BIS_ShowTime = 0; 
	publicVariable "BIS_ShowTime";
	
	if (isServer) then 
	{
		_i = _i + 1;
		_j = _times select _i;
	};
};

true