/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BP_fnc_updateAll";

BP_Cleanup_lastSync = diag_tickTime;

//Time Sync
call BPServer_fnc_updateTime;
call BPServer_fnc_updateTraps;