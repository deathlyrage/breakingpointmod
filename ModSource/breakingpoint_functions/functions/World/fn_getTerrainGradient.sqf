/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;
_pos1 = getPosASL _unit;
_dir = getDir _unit;
_delta = 1;
	
_pos2 = [_pos1, _delta, _dir] call BIS_fnc_relPos;
_pos1 = getTerrainHeightASL [_pos1 select 0, _pos1 select 1];
_pos2 = getTerrainHeightASL [_pos2 select 0, _pos2 select 1];
	
_gradient = (atan((_pos2 - _pos1)/_delta));	
	
_gradient