/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_cursorTarget"];
_cursorTarget = _this select 3;

player removeAction s_player_hostageDel;
s_player_hostageDel = -1;

if (isNull _cursorTarget) exitWith {};

if (!isStreamFriendlyUIEnabled) then {
	_msg = format ["You have released %1 from being a hostage.",(name _cursorTarget)];
	cutText [_msg, "PLAIN DOWN"];
} else {
	cutText ["You have released a player from being a hostage.", "PLAIN DOWN"];
};

_cursorTarget setVariable ["med_hostage",false,true];