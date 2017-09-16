/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

_player = _this;

if (isNull _player) exitWith {};

//Radio Channels:
//1 - Ranger
//2 - Outlaw
//3 - Nomad

_class = _player getVariable ["class",0];
_level = _player call BP_fnc_getFactionLevel;

//["radioCheck: Player: %1 | Level: %2",_player,_level] call BP_fnc_debugConsoleFormat;

if (_level > 0) then {
	if (_class == 1) then { //Ranger
		[_player,true,1] call BPServer_fnc_radioManage;
		[_player,false,2] call BPServer_fnc_radioManage;
		[_player,false,3] call BPServer_fnc_radioManage;
	};
	if (_class == 2) then { //Outlaw
		[_player,false,1] call BPServer_fnc_radioManage;
		[_player,true,2] call BPServer_fnc_radioManage;
		[_player,false,3] call BPServer_fnc_radioManage;
	};
	if (_class == 4) then { //Nomad
		[_player,false,3] call BPServer_fnc_radioManage;
		[_player,false,3] call BPServer_fnc_radioManage;
		[_player,true,3] call BPServer_fnc_radioManage;
	};
	if (_class == 5) then { //Survivalist
		[_player,true,1] call BPServer_fnc_radioManage;
		[_player,false,2] call BPServer_fnc_radioManage;
		[_player,true,3] call BPServer_fnc_radioManage;
	};
};
