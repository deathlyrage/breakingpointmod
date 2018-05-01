/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/* 
	Faction System  

	_points = [_victim,_killer] call BP_fnc_getFactionKillPoints;

*/

params [["_victim",objNull,[objNull]],["_killer",objNull,[objNull]]];

if (isNull _victim) exitWith {0};
if (isNull _killer) exitWith {0};

if (_killer isEqualTo _victim) exitWith {["getFactionKillPoints: Victim == Killer: no points change"] call BP_fnc_debugConsoleFormat;};

_nearbyStronghold = [_victim] call BP_fnc_strongholdNearby;

//Victim
_victimClass = _victim getVariable ["class",0];
_victimFactionName = _victimClass call BP_fnc_getFactionName;
_victimFactionLevel = _victim call BP_fnc_getFactionLevel;
_victimFactionPoints = _victim call BP_fnc_getFactionPoints;
		
//Killer
_killerClass = _killer getVariable ["class",0];
_killerFactionName = _killerClass call BP_fnc_getFactionName;
_killerFactionLevel = _killer call BP_fnc_getFactionLevel;
_killerFactionPoints = _killer call BP_fnc_getFactionPoints;

_levelStr = format ["Level_%1",_victimFactionLevel];
_pointsChange = getNumber (configFile >> "CfgFactions" >> _killerFactionName >> "Points" >> "Kill" >> _victimFactionName >> _levelStr);

["getFactionKillPoints: Victim: %1 (%2 %3) | Killer: %4 (%5 %6) | Points: %7 | LevelStr: %8",_victim,_victimFactionName,_victimFactionPoints,_killer,_killerFactionName,_killerFactionPoints,_pointsChange,_levelStr] call BP_fnc_debugConsoleFormat;

_pointsChange