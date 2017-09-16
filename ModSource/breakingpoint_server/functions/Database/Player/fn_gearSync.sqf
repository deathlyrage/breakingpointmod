/*
	Function: BPServer_fnc_gearSync;
	Description: Saves a character's stats to the database in a light update.
	Example: [_player,_inventory] call BPServer_fnc_gearSync;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

params ["_character","_inventory"];

// Invalid Sync Checks
if (isNull _character) exitWith {};

_characterID = _character getVariable ["CharacterID","0"];
if (_characterID == "0") exitWith { ["ERROR: Cannot Sync Character %1 has no characterID. ~1001",(name _character)] call BP_fnc_debugConsoleFormat; };

// Undead Don't Save
if (_character getVariable ["class",0] == 7) exitWith {};

// Everything is ready, now publish to HIVE
["CHILD:303:%1:%2:",_characterID,_inventory] call BPServer_fnc_callExtensionAsync;
