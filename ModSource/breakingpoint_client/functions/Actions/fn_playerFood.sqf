/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_cursorTarget","_foodClass"];
_cursorTarget = _this select 3;

player removeAction s_player_playerFood;
s_player_playerFood = -1;

if (isNull _cursorTarget) exitWith {};

_foodClass = "";
{
	if (_x in magazines player) exitWith { _foodClass = _x; };
} count AllFood;

if (_foodClass == "") exitWith {
	cutText ["You don't have any food.", "PLAIN DOWN"];
};

player removeMagazine _foodClass;

[(netID _cursorTarget),(netID player),_foodClass] remoteExecCall ["BPServer_fnc_playerGive",2];