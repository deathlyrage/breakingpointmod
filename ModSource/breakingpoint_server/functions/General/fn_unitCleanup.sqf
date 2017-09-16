/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_unit"];

if (isNull _unit) exitWith {};

_type = typeOf _unit;
_myGroupUnit = group _unit;

//Commented These Because They Are Global
//_unit removeAllMPEventHandlers "MPKilled";
//_unit removeAllMPEventHandlers "MPHit";
//_unit removeAllMPEventHandlers "MPRespawn";

_unit removeAllEventHandlers "FiredNear";
_unit removeAllEventHandlers "HandleDamage";
_unit removeAllEventHandlers "Killed";
_unit removeAllEventHandlers "Fired";
_unit removeAllEventHandlers "GetOut";
_unit removeAllEventHandlers "GetIn";
_unit removeAllEventHandlers "Local";

deleteVehicle _unit;
deleteGroup _myGroupUnit;
