/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_vval = (eyeDirection _this);
_vdir = (_vval select 0) atan2 (_vval select 1);
if (_vdir < 0) then {_vdir = 360 + _vdir};
_vdir