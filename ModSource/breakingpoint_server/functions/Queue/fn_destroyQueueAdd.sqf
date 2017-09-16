/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

{
	if (!isNull _x) then 
	{
		_netID = netID _x;
		_index = BP_ObjectDestroyQueue pushBackUnique _netID;
		if (_index > -1) then
		{
			["destroyQueueAdd: Added %1 to the Object Destroy Queue with NetID %2.",_x,_netID] call BP_fnc_debugConsoleFormat;
		};
	};
} count _this;