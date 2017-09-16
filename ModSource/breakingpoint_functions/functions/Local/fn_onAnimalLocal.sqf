/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Function: BP_fnc_onAnimalLocal
	Description: Called When An Animal Changes Locality
*/
private ["_unit","_local"];
_unit = _this select 0;
_local = _this select 1;

if (isNull _unit) exitWith {};

//if (_local) then {
//	_unit enableSimulation true;
//} else {
//	_unit enableSimulation false;
//};