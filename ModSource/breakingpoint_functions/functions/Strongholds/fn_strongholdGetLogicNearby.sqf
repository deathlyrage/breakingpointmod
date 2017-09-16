/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_pos","_return"];
_pos = _this;
_return = objNull;

{
	_strongholdRadius = _x getVariable "radius";
	if ((_x distance _pos) < _strongholdRadius) exitWith { _return = _x; };
} count entities "BP_Stronghold";

_return