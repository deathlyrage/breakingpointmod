/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Function: BP_fnc_onAnimalInit
	Description: Called When a Animal Entity is Created.
*/

private "_unit";
_unit = _this select 0;
if (isNull _unit) exitWith {};
//if (!local _unit) then {
//	_unit enableSimulation false;
//};
