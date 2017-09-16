/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_object","_killer"];

_objectUID = _object getVariable ["ObjectUID","0"];
_objectCharID = _object getVariable ["CharacterID","0"];
_objectPlayerID = _object getVariable ["PlayerID","0"];
_netID = netID _object;

if (isNull _object) exitWith {};

//Log Object Details
["onStorageKilled: Object: %1 | Net ID: %2 | UID: %3 | Player ID: %4 | Char ID: %5 | ",_object,_netID,_objectUID,_objectPlayerID,_objectCharID] call BP_fnc_debugConsoleFormat;

//Remove From Database
["CHILD:402:%1:",_objectUID] call BPServer_fnc_callExtensionAsync;

//Log Database Remove
["onStorageKilled: Removed Object %1 using UID %2.",_object,_objectUID] call BP_fnc_debugConsoleFormat;

//Remove Object From Object Monitor
[BP_serverObjectMonitor,_netID] call BP_fnc_arrayDelete;

//Remove Object From Destroy Monitor
[BP_ObjectDestroyQueue,_netID] call BP_fnc_arrayDelete;

// Delete
deleteVehicle _object;

