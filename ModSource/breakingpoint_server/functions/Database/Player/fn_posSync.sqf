/*
	Function: BPServer_fnc_posSync;
	Description: Saves a character's position to the database in a extreme light update.
	Example: _player call BPServer_fnc_posSync;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

private ["_character","_characterID","_charPos","_debug","_distance","_databasePos"];
_character = _this;

// Invalid Sync Checks
if (isNull _character) exitWith {};
_characterID = _character getVariable ["CharacterID","0"];
if (_characterID == "0") exitWith { ["posSync: Cannot Sync Character %1 has no characterID ~1001",(name _character)] call BP_fnc_debugConsoleFormat; };

// Undead Don't Save
if (_character getVariable ["class",0] == 7) exitWith {};

//Ensure Player Isn't In Debug
_charPos = getPosATL _character;
_debug = getMarkerPos BP_DebugMarker;
_distance = _debug distance _charPos;
if (_distance < BP_DebugRadius) exitWith {  ["posSync: Cannot Sync Character %1 is in debug. ~1001",(name _character)] call BP_fnc_debugConsoleFormat; };

//Ensure Player Isn't in A Building
_inside = [_charPos] call BP_fnc_isInsideBuildingPos;
if (_inside) exitWith {};

// Player Position
_databasePos = _character call BP_fnc_databasePos;

// Everything is ready, now publish to HIVE
["CHILD:305:%1:%2:",_characterID,_databasePos] call BPServer_fnc_callExtensionAsync;