/*
	Function: BPServer_fnc_statsSync;
	Description: Saves a character's stats to the database in a light update.
	Example: _player call BPServer_fnc_statsSync;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

private ["_character","_characterID","_kills","_killsH","_headShots","_class","_ranger","_outlaw","_hunter","_nomad","_survivalist","_engineer","_undead","_medical","_currentWpn","_currentAnim","_config","_onLadder","_isTerminal","_temp","_isInVehicle"];

_character = _this;

// Invalid Sync Checks
if (isNull _character) exitWith {};
_characterID = _character getVariable ["CharacterID","0"];
if (_characterID == "0") exitWith { ["ERROR: Cannot Sync Character %1 has no characterID. ~1001",(name _character)] call BP_fnc_debugConsoleFormat; };

// Initial Variables
_kills = _character getVariable ["zombieKills",0];
_killsH = _character getVariable ["humanKills",0];
_headShots = _character getVariable ["headShots",0];
_class = _character getVariable ["class",0];
_ranger = _character getVariable ["ranger",0];
_outlaw = _character getVariable ["outlaw",0];
_hunter = _character getVariable ["hunter",0];
_nomad = _character getVariable ["nomad",0];
_survivalist = _character getVariable ["survivalist",0];
_engineer = _character getVariable ["engineer",0];
_undead = _character getVariable ["undead",0];

// Update Medical Stats
_medical = _character call BP_fnc_sumMedical;

["statsSync: Medical %1",_medical] call BP_fnc_debugConsoleFormat;

// Player State
_currentWpn = currentMuzzle _character;
_currentAnim = animationState _character;
_config = configFile >> "CfgMovesMaleSdr" >> "States" >> _currentAnim;
_onLadder = (getNumber (_config >> "onLadder")) == 1;
_isTerminal = (getNumber (_config >> "terminal")) == 1;
_isInVehicle = vehicle player != player;
if (_onLadder or _isInVehicle or _isTerminal) then { _currentAnim = ""; };
if (_isInVehicle) then {
	_currentWpn = "";
} else {
	if (typeName(_currentWpn) == "STRING") then {
		_muzzles = getArray(configFile >> "CfgWeapons" >> _currentWpn >> "muzzles");
		if (count _muzzles > 1) then { _currentWpn = currentMuzzle _character; };	
	} else {
		_currentWpn = "";
	};
};

_currentState = [_currentWpn,_currentAnim,0];

_character setVariable ["state",_currentState];

["statsSync: Zed Kills: %1 | Kills: %2 | Headshots: %3 | Ranger: %4 | Outlaw: %5 | Hunter: %6 | Nomad: %7 | Survivalist: %8 | Engineer: %9 | Undead: %10 | Class: %11",_kills,_killsH,_headShots,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead,_class] call BP_fnc_debugConsoleFormat;

// Everything is ready, now publish to HIVE
//["CHILD:302:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11:%12:%13:%14:",_characterID,_medical,_kills,_headShots,_killsH,_class,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead,_currentState] call BPServer_fnc_callExtensionAsync;

//Partial String
["CHILD:302:%1:%2:%3:%4:%5:'%6':'%7':'%8':'%9':'%10':'%11':'%12':'%13':%14:",_characterID,_medical,_kills,_headShots,_killsH,_class,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead,_currentState] call BPServer_fnc_callExtensionAsync;

//["CHILD:302:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11:%12:%13:%14:",_characterID,_medical,_kills,_headShots,_killsH,_class,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead,_currentState] call BPServer_fnc_callExtensionAsync;

