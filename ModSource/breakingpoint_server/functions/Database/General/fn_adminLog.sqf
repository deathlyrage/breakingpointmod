/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BPServer_fnc_adminLog";

params [["_playerID","",[""]],["_playerName","Error: No unit",[""]],["_action","",[""]]];

//Handle Error: No Unit
if (_playerID == "") exitWith {};
if (_playerName == "Error: No unit") exitWith {};
if (_action == "") exitWith {};

//Insert Combat Log Into Database
["CHILD:804:%1:%2:%3:",_playerID,_playerName,_action] call BPServer_fnc_callExtensionAsyncLow;