/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

["trapActivate: %1",_this] call BP_fnc_debugConsoleFormat;

params [["_trap",objNull,[objNull]],["_player",objNull,[objNull]]];

if (isNull _trap) exitWith {};

if (isServer) then
{
	_trap animate ['LeftShutter',0];
	_trap animate ['RightShutter',0];
	_trap setVariable ["armed",true];
} else {
	_this remoteExecCall ["BP_fnc_trapActivate",2];
};