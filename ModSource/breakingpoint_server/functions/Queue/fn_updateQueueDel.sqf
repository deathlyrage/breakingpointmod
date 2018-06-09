/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

{
	_index = BP_ObjectUpdateQueue find _x;
	if (_index >= 0) then { BP_ObjectUpdateQueue deleteAt _index; };
	["updateQueueDel: Deleted NetID %1 from the Object Update Queue.",_x] call BP_fnc_debugConsoleFormat;
} count _this;