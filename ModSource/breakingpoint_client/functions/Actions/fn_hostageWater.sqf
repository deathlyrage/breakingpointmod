/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_cursorTarget","_drinkClass"];
_cursorTarget = _this select 3;

player removeAction s_player_hostageWater;
s_player_hostageWater = -1;

_drinkClass = "";
{
	if (_x in magazines player) exitWith { _drinkClass = _x; };
} count AllDrinks;
if (_drinkClass == "") exitWith {
	cutText ["You don't have any water.", "PLAIN DOWN"];
};
player removeMagazine _drinkClass;

if (!isStreamFriendlyUIEnabled) then {
	cutText [format ["You have given %1 some water.",(name _cursorTarget)], "PLAIN DOWN"];
} else {
	cutText ["You have given the hostage some water.", "PLAIN DOWN"];
};

[(netID _cursorTarget),_drinkClass] remoteExecCall ["BPServer_fnc_hostageGive",2];