/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private ["_netID"];
{
	if (!isNull _x) then {
		_netID = netID _x;
		if (_netID in BP_ObjectDestroyQueue) then {
			_index = BP_ObjectDestroyQueue find _netID;
			if (_index >= 0) then { BP_ObjectDestroyQueue deleteAt _index; };
			["updateQueueDel: Deleted %1 from the Object Destroy Queue with NetID %2.",_x,_netID] call BP_fnc_debugConsoleFormat;
		};
	};
} count _this;