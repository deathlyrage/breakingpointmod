/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_cursorTarget","_drinkClass"];
_cursorTarget = _this select 3;

player removeAction s_player_hostageWater;
s_player_hostageWater = -1;

if (isNull _cursorTarget) exitWith {};

_drinkClass = "";
{
	if (_x in magazines player) exitWith { _drinkClass = _x; };
} count AllDrinks;
if (_drinkClass == "") exitWith {
	cutText ["You don't have any water.", "PLAIN DOWN"];
};
player removeMagazine _drinkClass;

[(netID _cursorTarget),(netID player),_drinkClass] remoteExecCall ["BPServer_fnc_playerGive",2];