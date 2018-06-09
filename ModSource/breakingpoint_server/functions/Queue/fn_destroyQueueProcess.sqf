/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BP_fnc_destroyQueueProcess";

//Process Entire Queue
{
	//Get Object Information
	_object = objectFromNetID _x;
	
	//Remote Item From The Queue
	BP_ObjectDestroyQueue deleteAt _forEachIndex;
	
	//If Object Is Valid, Delete It.
	if (!isNull _object) then 
	{
		if (_object isKindOf "BP_Fire") then
		{
			[objNull,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
		} else {
			deleteVehicle _object;
		};
	};
} forEach BP_ObjectDestroyQueue;