/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_object",objNull,[objNull]]];

if (isNull _object) exitWith {};

{ [_x, "gear"] call BPServer_fnc_updateObject; } count nearestObjects [(getPosATL _object), ["Car", "Helicopter", "Motorcycle", "Ship", "BP_Storage","BP_Storage"], 10];
