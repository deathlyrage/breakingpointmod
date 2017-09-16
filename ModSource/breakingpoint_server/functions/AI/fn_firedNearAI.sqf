/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_unit","_source","_distance","_weapon","_muzzle","_mode","_ammo"];

//Don't Register For Null Fire Events
if (isNull _source) exitWith {};

//Don't Register For Self Fire Events
if (_unit != _source) exitWith {};

//Reveal Attacking Unit
_unit reveal [_source,4];

//Send the AI After the person who shot near him
//_fsmID = _unit getVariable "fsm_handle";
//_fsmID setFSMVariable ["_fireTarget", _source];

