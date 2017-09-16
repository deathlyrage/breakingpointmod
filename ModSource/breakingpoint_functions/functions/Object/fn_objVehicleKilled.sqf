/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_unit","_killer","_type","_pos","_dir"];
_unit = _this select 0;
_killer = _this select 1;
_type = typeOf _unit;
_pos = getposATL _unit;
_dir = direction _unit;
if (local _unit) then {
	deleteVehicle _unit;
	_unit = nil;
};
