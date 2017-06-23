/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_cursorTarget","_text"];
_cursorTarget = _this select 3;

player removeAction s_player_safeLock;
s_player_safeLock = -1;

//_cursorTarget setVariable ["locked",true,true];

[_cursorTarget] remoteExecCall ["BPServer_fnc_lockObj",2];

cutText ["Safe Locked.", "PLAIN DOWN"];