/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_dog"];
_dog = _this select 0;
_local = (local _dog);

["dogInit: Dog: %1 Local: %2",_dog,_local] call BP_fnc_debugConsoleFormat;

if (isNull _dog) exitWith {};