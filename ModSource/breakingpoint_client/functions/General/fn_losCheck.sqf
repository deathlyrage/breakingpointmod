/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_target","_agent"];

_cantSee = true;

if (!isNull _target) then {
	_tPos = eyePos _target;
	_zPos = eyePos _agent;
	if ((count _tPos > 0) and (count _zPos > 0)) then {
		_cantSee = terrainIntersectASL [_tPos, _zPos];
		if (!_cantSee) then {
			_cantSee = lineIntersects [_tPos, _zPos, _agent, vehicle _target];
		};
	};
};

_cantSee