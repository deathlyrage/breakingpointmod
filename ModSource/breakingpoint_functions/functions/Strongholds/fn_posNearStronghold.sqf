/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_position","_return"];
_position = _this;
_return = false;

//Strongholds Disabled
if (!BP_FactionStrongholds) exitWith {false};

//Check Nearby Strongholds
{
	_strongholdRadius = _x getVariable "radius";
	if ((_x distance _position) < _strongholdRadius) exitWith {
		_return = true;
	};
} count entities "BP_Stronghold";

_return