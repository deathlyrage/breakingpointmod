/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/* 
	Faction System  

	_level = _playerObj call BP_fnc_getFactionLevel;

*/

private ["_playerObj","_factionName","_base","_min","_max","_levels","_lvl1","_lvl2","_lvl3","_points"];

_playerObj = _this;

if (isNull _playerObj) exitWith {0};

_class = _playerObj getVariable ["class",0];
if (_class == 0) exitWith {0};

_factionName = _class call BP_fnc_getFactionName;
_base = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "base");
_min = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "min");
_max = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "max");
_levels = getArray (configFile >> "CfgFactions" >> _factionName >> "Points" >> "levels");
_lvl1 = (_levels select 0);
_lvl2 = (_levels select 1);
_lvl3 = (_levels select 2);

_points = _playerObj call BP_fnc_getFactionPoints;

//Level 3
if (_points > _lvl3) exitWith {3};
//Level 2
if (_points > _lvl2) exitWith {2};
//Level 1
if (_points > _lvl1) exitWith {1};
if (_points == _lvl1) exitWith {1};
//Level 0 - Evil
if (_points < _base) exitWith {0};

0