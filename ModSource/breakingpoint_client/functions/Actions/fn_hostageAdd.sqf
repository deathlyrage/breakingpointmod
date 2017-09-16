/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_cursorTarget"];
_cursorTarget = _this select 3;

player removeAction s_player_hostageAdd;
s_player_hostageAdd = -1;

_hasTape = (("ItemDuctTape" in magazines player) or ("ItemWaterTape" in magazines player));
if (!_hasTape) exitWith {
	cutText ["You don't have any tape to take this person hostage.", "PLAIN DOWN"];
};

if (speed player > 6) exitWith { cutText ["You are running too fast to take this person hostage.", "PLAIN DOWN"]; };
if (speed _cursorTarget > 6) exitWith { cutText ["This person is running too fast to take hostage.", "PLAIN DOWN"]; };

if ("ItemDuctTape" in magazines player) then {
	player removeMagazine "ItemDuctTape";
} else {
	player removeMagazine "ItemWaterTape";
};

if (!isStreamFriendlyUIEnabled) then {
	_msg = format ["You have taken %1 as a hostage.",(name _cursorTarget)];
	cutText [_msg, "PLAIN DOWN"];
} else {
	cutText ["You have taken a player as a hostage.", "PLAIN DOWN"];
};

[(netID player),(netID _cursorTarget)] remoteExecCall ["BPServer_fnc_hostageAdd",2];