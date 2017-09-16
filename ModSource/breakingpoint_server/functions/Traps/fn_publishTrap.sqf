/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_playerNetID","_charID","_blueprint","_classname","_pos","_dir"];

_playerObj = objectFromNetID _playerNetID;
_playerID = getPlayerUID _playerObj;

["publishTrap: Character ID %1 Attempted to Publish Object %2 (%3) at %4.~0001",_charID,_classname,_playerID] call BP_fnc_debugConsoleFormat;

//Position Fixes If Glitched Underground
if ((_pos select 2) < 0) then { _pos set [2,0]; };

//Create Object
_object = _classname createVehicle _pos;
_object setDir _dir;
_object setPosATL _pos;
_object setVelocity [0,0,0.01];
_object enableDynamicSimulation true;

_databasePos = _object call BP_fnc_databasePos;
_uid = [_dir,_pos] call BPServer_fnc_objectUID;

["CHILD:410:%1:%2:%3:",_uid,_classname,_databasePos] call BPServer_fnc_callExtensionAsync;

0 = BP_Traps pushBack [_uid,_object,_dir];

publicVariable "BP_Traps";

["publishTrap: Object %1 Published with ID %2.~0001",_classname,_uid] call BP_fnc_debugConsoleFormat;