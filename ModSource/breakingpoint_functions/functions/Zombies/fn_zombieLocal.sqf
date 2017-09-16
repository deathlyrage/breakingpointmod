/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_unit","_local"];
_unit = _this select 0;
_local = _this select 1;

//Debug Logging
//["onZombieLocal: %1",_this] call BP_fnc_debugConsoleFormat;

if (isNull _unit) exitWith {};

if (!_local) exitWith {};

if (hasInterface) exitWith
{
	//
};

if (isServer) exitWith {
	deleteVehicle _unit;
};

//Headless Client