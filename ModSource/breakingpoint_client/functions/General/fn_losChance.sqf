/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_agent","_dis","_maxDis"];
_val = (_maxDis - _dis) max 0;
_maxExp = ((exp 2) * _maxDis);
_myExp = ((exp 2) * (_val)) / _maxExp;
_myExp = _myExp * 0.7;
_myExp