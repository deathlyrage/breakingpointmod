/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/* 
	Faction System 
	_points = _playerObj call BP_fnc_getFactionPoints;
*/

private ["_playerObj","_class"];
_playerObj = _this;
_class = _playerObj getVariable ["class",0];
if (_class == 0) exitWith {0};
(_playerObj getVariable [(toLower (_class call BP_fnc_getFactionName)),0])