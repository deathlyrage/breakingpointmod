/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_cursorTarget"];
_cursorTarget = _this select 3;

player removeAction s_player_groupAdd;
s_player_groupAdd = -1;

//Can Only Invite Valid Targets
if (isNull _cursorTarget) exitWith {};

//Can only add players to your group.
if (!isPlayer _cursorTarget) exitWith {};

//if (BP_combat == 1) exitWith {
//	cutText ["You can't invite someone to a group in combat.", "PLAIN DOWN"];
//};

if ((diag_tickTime - BP_LastGroupInvite) < 5) exitWith { cutText ["You are inviting players to groups too quickly. Please try again in 5 seconds.", "PLAIN DOWN"]; };

if (!isStreamFriendlyUIEnabled) then {
	cutText [format ["You have invited %1 to join your group.",(name _cursorTarget)], "PLAIN DOWN"];
} else {
	cutText ["You have invited a player to join your group.", "PLAIN DOWN"];
};

BP_LastGroupInvite = diag_tickTime;

//Get Existing Group ID
_groupUID = player getVariable ["group","0"];

//If Not in a group, create a new one
if (_groupUID == "0") then {
	_groupUID = call BP_fnc_groupCreateUID;
	player setVariable ["group",_groupUID,true];
};

[(netID player),(netID _cursorTarget),_groupUID] remoteExecCall ["BPServer_fnc_groupInvite",2];