/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//["trapDeactivate: %1",_this] call BP_fnc_debugConsoleFormat;

params ["_trap","_player"];

if (isNull _trap) exitWith {};

if (isServer) then
{
	_trap animate ['LeftShutter',1];
	_trap animate ['RightShutter',1];
	_trap setVariable ["armed",false];
} else {
	_this remoteExecCall ["BP_fnc_trapDeactivate",2];
};