/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (isNil "BP_Traps") exitWith {};

{
	_x params ["","_trap","_trapDir"];
	if (!isNull _trap) then { _trap setDir _trapDir; };
} count BP_Traps;
