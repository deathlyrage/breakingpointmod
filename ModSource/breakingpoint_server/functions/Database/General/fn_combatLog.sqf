/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BPServer_fnc_combatLog";

params [["_playerID","",[""]],["_playerName","Error: No unit",[""]],["_characterID","0",[""]]];

//Handle Error: No Unit
if (_playerID == "") exitWith {};
if (_playerName == "Error: No unit") exitWith {};
if (_characterID == "0") exitWith {};

//Insert Combat Log Into Database
["CHILD:800:%1:%2:%3:",_playerID,_playerName,_characterID] call BPServer_fnc_callExtensionAsyncLow;