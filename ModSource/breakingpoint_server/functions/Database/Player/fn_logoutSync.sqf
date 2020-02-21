/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private ["_character","_inv","_medical","_stats","_isLight","_characterID","_equippedWeapons","_weapons","_magazines","_items","_storage","_playerGear","_backpack","_playerBackp","_timeSync","_playerPos","_lastPos""_kills","_killsH","_headShots","_ranger","_outlaw","_hunter","_nomad","_survivalist"];

if (!initialized) exitWith {};

// Load Passed Params
_character = _this;

["logoutSync: Character: %1",_character] call BP_fnc_debugConsoleFormat;

// Invalid Sync Checks
if (isNull _character) exitWith {};
_characterID = _character getVariable ["CharacterID","0"];
if (_characterID == "0") exitWith { ["logoutSync: Cannot Sync Character %1 has no characterID. ~1001",(name _character)] call BP_fnc_debugConsoleFormat; };

// Undead Don't Save
// if (_character getVariable ["class",0] == 7) exitWith {};

// Initial Variables
//_isInVehicle = (vehicle _character != _character);

//Save Character Gear
_backpack = (backpack _character);
_vest = (vest _character);
_uniform = (uniform _character);
_headgear = (headgear _character);

_inv = _character call BP_fnc_getSaveInventory;

_inv params ["_weaponsData","_containerData","_partialMags","_extraWeapons","_assignedItems"];
	
_storage = [_backpack,_vest,_uniform,_headgear];
_playerGear = [_assignedItems,_storage,_weaponsData,_containerData,_partialMags,_extraWeapons];

[_character,_playerGear] call BPServer_fnc_gearSync;

