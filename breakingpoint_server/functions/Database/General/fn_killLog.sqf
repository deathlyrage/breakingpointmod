/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BPServer_fnc_killLog";

params [["_playerID","",[""]],["_playerName","Error: No unit",[""]],["_killerID","",[""]],["_killerName","Error: No unit",[""]],["_killWeapon","Unknown",[""]],["_killDistance","0",[""]]];

//Handle Error: No Unit
if (_playerName == "Error: No unit") exitWith {};
if (_killerName == "Error: No unit") exitWith {};

//Insert Kill Into Database
["CHILD:801:%1:%2:%3:%4:%5:%6:",_playerID,_playerName,_killerID,_killerName,_killDistance,_killWeapon] call BPServer_fnc_callExtensionAsyncLow;