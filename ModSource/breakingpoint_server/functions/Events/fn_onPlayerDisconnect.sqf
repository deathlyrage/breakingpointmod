/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_id","_name","_uid"];

//Don't Handle Connection Events from this name
if (_name in ["__SERVER__","hc","headlessclient"]) exitWith {};

//Don't Handle Logins if Server Is Locked
if (BP_ServerLock) exitWith {};

//Log Player Disconnect
["onPlayerDisconnect: Name: %1 | UID: %2", _name,_uid] call BP_fnc_debugConsoleFormat;

//Event Call for Hive Extension
["CHILD:111:%1:%2:",_uid,_name] call BPServer_fnc_callExtensionAsyncLow;