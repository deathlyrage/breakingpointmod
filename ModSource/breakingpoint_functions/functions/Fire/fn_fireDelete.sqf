/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_fire"];

if !(_fire isKindOf "BP_Fire") exitWith {};

if (isServer) then
{
	detach _fire;
	deleteVehicle _fire;
	if !(isNull _unit) then
	{
		_unit setVariable ["fire",objNull,true];
	};
} else {
	_effects = _fire getVariable ["effects",[]];
	{ deleteVehicle _x; } forEach _effects;
};
