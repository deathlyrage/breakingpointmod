/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_player","_killer","_damage"];

["0 - damageHandlerHit: %1",_this] call BP_fnc_debugConsoleFormat;
["0 - player: %1",_player] call BP_fnc_debugConsoleFormat;
["0 - killer: %1",_killer] call BP_fnc_debugConsoleFormat;

//Exit if Invalid Object Refs
if (isNull _player) exitWith {};
if (isNull _killer) exitWith {};

//Exit If Damage Is Too Small
if (_damage < 0.01) exitWith {};

//Make sure it isn't self damage
if (_player == _killer) exitWith {};

//Player
private ["_playerClass","_playerFactionName","_playerFactionLevel","_playerFactionPoints","_playerTraitorFlag"];
_playerClass = _player getVariable ["class",0];
_playerFactionName = _playerClass call BP_fnc_getFactionName;
_playerFactionLevel = _player call BP_fnc_getFactionLevel;
_playerFactionPoints = _player call BP_fnc_getFactionPoints;
_playerTraitorFlag = _player getVariable ["traitorFlag",false];
_playerUniform = (uniform _player);

//Killer
private ["_killerClass","_killerFactionName","_killerFactionLevel","_killerFactionPoints","_killerTraitorFlag"];
_killerClass = _killer getVariable ["class",0];
_killerFactionName = _killerClass call BP_fnc_getFactionName;
_killerFactionLevel = _killer call BP_fnc_getFactionLevel;
_killerFactionPoints = _killer call BP_fnc_getFactionPoints;
_killerTraitorFlag = _killer getVariable ["traitorFlag",false];
_killerUniform = (uniform _killer);

_nearbyStronghold = [_player] call BP_fnc_strongholdNearby;

//Exit If Killer Already Flagged
if (_killerTraitorFlag) exitWith {
	["damageHandlerHit: Killer Already has Flag"] call BP_fnc_debugConsoleFormat;
};

//Exit If Player Already Flagged
if (_playerTraitorFlag) exitWith {
	["damageHandlerHit: Player Already has Flag"] call BP_fnc_debugConsoleFormat;
};

//Exit If Killer Uniform In Zombie Mode
if (_killerUniform in BP_ZombieClothing) exitWith {};

//Exit If Player Uniform In Zombie Mode
if (_playerUniform in BP_ZombieClothing) exitWith {};

//None Class Check
if (_killerClass == 0) exitWith {
	["damageHandlerHit: Killer None Class"] call BP_fnc_debugConsoleFormat;
};

if (_playerClass == 0) exitWith {
	["damageHandlerHit: Player None Class"] call BP_fnc_debugConsoleFormat;
};

//Exit If Player Is a Hunter
if (_playerClass == 3) exitWith {
	["damageHandlerHit: Player Hunter"] call BP_fnc_debugConsoleFormat;
};

if (_killerClass == 3) exitWith {
	["damageHandlerHit: Killer Hunter"] call BP_fnc_debugConsoleFormat;
};

//Exit If Player Is a Traitor
if (_playerUniform in BP_TraitorClothing) exitWith {
	["damageHandlerHit: Player is a traitor."] call BP_fnc_debugConsoleFormat;
};

//Exit If Player Is a Traitor
if (_killerUniform in BP_TraitorClothing) exitWith {
	["damageHandlerHit: Killer is a traitor."] call BP_fnc_debugConsoleFormat;
};

//Exit If Survivalist -> Outlaw
if ((_killerClass == 5) and (_playerClass == 2)) exitWith {
	["damageHandlerHit: Survivalist shooting Outlaw."] call BP_fnc_debugConsoleFormat;
};

["1 - damageHandlerHit: %1",_this] call BP_fnc_debugConsoleFormat;
["1 - player: %1",_player] call BP_fnc_debugConsoleFormat;
["1 - killer: %1",_killer] call BP_fnc_debugConsoleFormat;

//Get Kill Points
private "_pointsChange";
_pointsChange = [_player,_killer] call BP_fnc_getFactionKillPoints;
["damageHandlerHit: Points Change: %1",_pointsChange] call BP_fnc_debugConsoleFormat;

["2 - damageHandlerHit: %1",_this] call BP_fnc_debugConsoleFormat;
["2 - player: %1",_player] call BP_fnc_debugConsoleFormat;
["2 - killer: %1",_killer] call BP_fnc_debugConsoleFormat;

//Exit If Action is Positive Already
if (_pointsChange > -1) exitWith {
	["damageHandlerHit: Positive Points"] call BP_fnc_debugConsoleFormat;
};

//Flag Killer as Traitor
_killer setVariable ["traitorFlag",true,true];
["damageHandlerHit: Setting Traitor Flag %1 on %2",true,_killer] call BP_fnc_debugConsoleFormat;

