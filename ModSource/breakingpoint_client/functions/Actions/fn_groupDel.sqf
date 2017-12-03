/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_group","_leaveReturn","_endState"];

if (s_player_groupDel > -1) then {
	player removeAction s_player_groupDel;
	s_player_groupDel = -1;
};

//Can't Leave Groups In a Vehicle7
if (vehicle player != player) exitWith { cutText ["You can't leave a group inside a vehicle.", "PLAIN DOWN"]; };

//Leave Group Dialog Message
_leaveReturn = ["Are you sure you would like to leave your current group? This will add a (default 10 mins) rejoin timout!!!","Leave Group",nil,true] call BIS_fnc_guiMessage;
if (_leaveReturn) then {
	[player] joinSilent grpNull;
	_group = createGroup civilian;
	_group setBehaviour "CARELESS";
	[player] joinSilent _group;

	player setVariable ["group","0",true];
	BP_Group = [];
	//leave group timer
	[(netID player)] remoteExecCall ["BPServer_fnc_groupLeaveTimer",2];
};