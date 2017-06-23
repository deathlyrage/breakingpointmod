/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_target","_agent","_degree"];
_inAngle = false;
_inAngle = [(getPosASL _agent),(direction _agent),_degree,(getPosASL _target)] call BIS_fnc_inAngleSector;
_inAngle