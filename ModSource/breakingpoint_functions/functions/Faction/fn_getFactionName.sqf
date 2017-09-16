/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/* 
	Faction System

	_class = _playerObj getVariable ["class",0];
	_factionName = _class call BP_fnc_getFactionName;

*/

if (_this < 0) exitWith {"None"};
((getArray (configFile >> "CfgFactions" >> "factions")) select _this)