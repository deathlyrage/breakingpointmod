/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_dog","_local"];

if (isNull _dog) exitWith {};

//Save Player Dogs When They Logout on Locality Change
if (_local) then { 
	_dog call BPServer_fnc_dogSync;
	deleteVehicle _dog;
};

//["dogLocal: %1",_this] call BP_fnc_debugConsoleFormat;