/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BPServer_fnc_storageLog";

params [["_playerID","",[""]],["_playerName","Error: No unit",[""]],["_deployableID","0",[""]],["_deployableName","",[""]]];

//Handle Error: No Unit
if (_playerName == "Error: No unit") exitWith {};
if (_playerID == "") exitWith {};
if (_deployableID == "0") exitWith {};
if (_deployableName == "") exitWith {};

//Insert Storage Log Into Database
["CHILD:802:%1:%2:%3:%4:%5:",_playerID,_playerName,_deployableID,_deployableName,_ownerID] call BPServer_fnc_callExtensionAsyncLow;