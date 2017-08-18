/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_hostageNetID","_classname"];

_hostage = objectFromNetID _hostageNetID;

if (isNull _hostage) exitWith {};
if (!alive _hostage) exitWith {};

BP_HostageGive = _classname;
(owner _hostage) publicVariableClient "BP_HostageGive";