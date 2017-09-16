/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

_player = objectFromNetID (_this select 0);
if (isNull _player) exitWith {};

//Add Points (Global)
[_player,-250] call BPServer_fnc_addFactionPoints;

//Sync Stats
_player call BPServer_fnc_statsSync;