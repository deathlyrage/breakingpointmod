/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private "_cantSee";

params ["_target","_agent","_degree"];

_attackCheck = false;
_inAngle = [_target,_agent,_degree] call BP_fnc_angleCheck;
if (_inAngle) then  {
	_cantSee = [_target,_agent] call BP_fnc_losCheck;
	if (!_cantSee) then {
		_attackCheck = true;
	};
};
_attackCheck