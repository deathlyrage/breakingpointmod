/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_zed","_killer"];

//Null Checks
if (isNull _zed) exitWith {};
if (isNull _killer) exitWith {};

//Server
if (isServer) then {
	_kills = _killer getVariable ["zombieKills",0];
	_killer setVariable ["zombieKills",(_kills + 1)];
	_zed setVariable ["processedDeath",diag_tickTime];
} else {
	if (local _killer) then {
		_kills = _killer getVariable ["zombieKills",0];
		_killer setVariable ["zombieKills",(_kills + 1)];
	};
	_this remoteExecCall ["BPServer_fnc_eventKill",2];
};
