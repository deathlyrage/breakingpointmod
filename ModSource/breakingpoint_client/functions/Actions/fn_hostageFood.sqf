/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_cursorTarget"];
_cursorTarget = _this select 3;

player removeAction s_player_hostageFood;
s_player_hostageFood = -1;

_foodClass = "";
{
	if (_x in magazines player) exitWith { _foodClass = _x; };
} count AllFood;
if (_foodClass == "") exitWith {
	cutText ["You don't have any food.", "PLAIN DOWN"];
	_handled = true;
};
player removeMagazine _foodClass;

if (!isStreamFriendlyUIEnabled) then {
	_msg = format ["You have given %1 some food.",(name _cursorTarget)];
	cutText [_msg, "PLAIN DOWN"];
} else {
	cutText ["You have given the hostage some food.", "PLAIN DOWN"];
};

[(netID _cursorTarget),_foodClass] remoteExecCall ["BPServer_fnc_hostageGive",2];