/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_dog","_selectionName","_damage","_source","_ammo"];

if (isNull _dog) exitWith {0};
if (!alive _dog) exitWith {0};

["dogHandleDamage: %1",_this] call BP_fnc_debugConsoleFormat;

//Get FSM Data and Owner Character ID
_fsmID = _dog getVariable ["fsm_handle",0];
_charID = parseNumber (_dog getVariable ["CharacterID","0"]);
_playerDog = ((_fsmID > 0) and (_charID > 0));

//Not Player Dog
if (!_playerDog) exitWith {};

//Get Health
_type = [_damage,_ammo] call BP_fnc_medicalDamageType;
_isMinor = (_hit in med_MinorWounds);
_isHeadHit = (_hit == "head");
_selfDamage = (_dog == _source);

// Self Damage
if (_selfDamage) exitWith {0};

// Non-Lethal Rounds
if (_ammo isKindOf "BP_NonLethal") exitWith {0};