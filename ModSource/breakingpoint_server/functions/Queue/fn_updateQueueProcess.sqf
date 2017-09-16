/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BP_fnc_updateQueueProcess";

//Process Entire Queue
{
	//Get Object Details
	_netObj = objectFromNetID _x;
	
	//Remove Object From The Queue
	BP_ObjectUpdateQueue deleteAt _forEachIndex;

	// If Null Object Remove From Queue else Process
	if (!isNull _netObj) then
	{
		["serverMgr: Starting Processing on %1 From Update Queue NetID: %2",_netObj,_x] call BP_fnc_debugConsoleFormat;
		_handle = [_netObj,"queue"] spawn BPServer_fnc_updateObject;
		[_handle] call BP_fnc_addThreadHandle;
		["serverMgr: Processing on %1 From Update Queue NetID: %2",_netObj,_x] call BP_fnc_debugConsoleFormat;
		waitUntil {scriptDone _handle};
		["serverMgr: Finished Processing on %1 From Update Queue NetID: %2",_netObj,_x] call BP_fnc_debugConsoleFormat;
	};

} forEach BP_ObjectUpdateQueue;

//Debug
//["updateQueueProcess: Processing %1 Items in Queue.",(count BP_ObjectUpdateQueue)] call BP_fnc_debugConsoleFormat;