/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_aimingPos"];

_pos = [];
_deg = [_unit, _aimingPos] call BP_fnc_relativeDirTo;
_trip = [_unit, _aimingPos] call BP_fnc_distance2D;
_maxlength = 80;

if ((_trip < 2 * 3.5) || {(_trip > 200)}) then 
{
	_trip = 2*3.5 + random _maxlength;
	_deg = -20 + random 40;
	_posList = (getPosATL _unit) nearObjects ["ReammoBox", _maxlength];
	if !(_posList isEqualTo []) then 
	{
		//Select Random Position Of Loot Box
		_pos = getPosATL (selectRandom _posList);
		if (isNil "_pos") then { _pos = []; };
	};
};

if (count _pos < 3) then 
{
	_trip = _trip * ((random(2) - 1) / 5 + 1);
	if (_deg > 180) then { _deg = _deg - 360; };
	_deg = _deg * ((random(2) - 1) / 10 + 1);
	_deg = _deg + 10 * (random(2) - 1);
	_pos = _unit modelToWorld [ sin(_deg) * _trip, cos(_deg) * _trip, 0];
};

_unit setVariable ["myDest",_pos];

_pos