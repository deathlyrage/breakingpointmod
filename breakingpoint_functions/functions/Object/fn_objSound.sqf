/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_unit","_type","_chance","_sound","_dis"];
_unit = _this select 0;
_type = _this select 1;
_chance = _this select 2;
_dis = 40;

if ((round(random _chance) == _chance) or (_chance == 0)) then {
	_sound = "z_" + _type;
	_unit say [_sound, _dis];
};