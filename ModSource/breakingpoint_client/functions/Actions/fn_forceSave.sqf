/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_cursorTarget = _this select 3;

player removeAction s_player_saveObject;
s_player_saveObject = -1;
player removeAction s_player_saveVehicle;
s_player_saveVehicle = -1;

(netID _cursorTarget) remoteExecCall ["BPServer_fnc_updateObjectForce",2];

cutText ["A request to force save the object has been sent to the server.", "PLAIN DOWN"];