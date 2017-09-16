/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private "_object";
_object = _this select 0;
_object addEventHandler ["local", {
	if(_this select 1) then {
		private["_type","_unit"];
		_unit = _this select 0;
		_type = typeOf _unit;
		_myGroupUnit = group _unit;
		//Commented These because they are global
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
		_unit = nil;
	};
}];