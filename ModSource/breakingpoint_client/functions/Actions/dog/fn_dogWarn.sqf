/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_handle", "_watchDog", "_dog", "_warn"];
_handle = _this select 0;
_watchDog = _this select 1;
_dog = _handle getFSMVariable "_dog";

player removeAction s_player_warndog;
s_player_warndog = -1;

_handle setFSMVariable ["_watchDog",_watchDog];

_warn = {
	_handle = _this select 0;
	while {_watchDog and alive _dog} do {
		_watchDog = _handle getFSMVariable "_watchDog";
		_senseSkill = _handle getFSMVariable "_senseSkill";
		if (_watchDog) then {
			_nearby = (getPosATL _dog) nearEntities ["CAManBase",_senseSkill];

			_index = _nearby find player;
			if (_index >= 0) then { _nearby deleteAt _index; };

			if (count _nearby > 0) then {
				[_dog,"dog_growl",2,false] call BP_fnc_objSpeak;
			};
		};
		sleep 2;
	};
};

if (_watchDog) then {
	_handle setFSMVariable ["_idleTime",5];
	[_handle] spawn _warn;
} else {
	_handle setFSMVariable ["_idleTime",1];
};