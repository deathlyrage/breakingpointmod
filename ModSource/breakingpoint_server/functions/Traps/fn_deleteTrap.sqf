/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_trapUID"];

//Logging
["deleteTrap: %1",_trapUID] call BP_fnc_DebugConsoleFormat;

//Hive Call
["CHILD:411:%1:",_trapUID] call BPServer_fnc_callExtensionAsync;