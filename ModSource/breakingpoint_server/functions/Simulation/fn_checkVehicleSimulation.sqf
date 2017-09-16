/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_distance",0,[0]],["_object",objNull,[objNull]]];

if (_distance == 0) exitWith {};
if (isNull _object) exitWith {};

_nearby = [(getPosATL _object),_distance] call BP_fnc_nearbyPlayers;
_empty = (crew _object isEqualTo []);

if (simulationEnabled _object) then {
	if (_empty && {!_nearby}) then {
		_object enableSimulationGlobal false;
		["simulationMgr: Disabled Simulation on %1",_object] call BP_fnc_debugConsoleFormat;
	};
} else {
	if (!_empty || {_nearby}) then { 
		_object enableSimulationGlobal true;
		["simulationMgr: Enabled Simulation on %1",_object] call BP_fnc_debugConsoleFormat;
	};
};