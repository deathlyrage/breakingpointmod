/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_position","_return"];
_position = _this;
_return = 8000;

//Strongholds Disabled
if (!BP_FactionStrongholds) exitWith {_return};

//Check Nearby Strongholds
{
	_strongholdRadius = _x getVariable "radius";
	_distance = (_x distance _position);
	if (_distance < _strongholdRadius) exitWith {_return = _distance; };
} count entities "BP_Stronghold";

_return