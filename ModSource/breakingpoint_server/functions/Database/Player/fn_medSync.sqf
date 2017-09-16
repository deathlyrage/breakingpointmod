/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

if (!initialized) exitWith {};

// Load Passed Params
params ["_characterNetID",["_medical",[],[[]]]];
_character = objectFromNetID _characterNetID;

// Invalid Sync Checks
if (isNull _character) exitWith {};
if (!isPlayer _character) exitWith {};
if (!alive _character) exitWith {};
if (_medical isEqualTo []) exitWith {};

// Update Local Server Side Medical Variables
_character setVariable ["med_BloodQty",(_medical select 8)];
_character setVariable ["med_fractures",(_medical select 9)];
_character setVariable ["messing",(_medical select 10)];