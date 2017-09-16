/*
	File: onPlayerKilled.sqf
	Author: Karel Moricky

	Description:
	You were killed!
*/

//--- 1.60 - Visual states interpolation position was not correct
#define FNC_PLAYERPOS(WHO) \
	(if (isclass (configfile >> "CfgPatches" >> "ca_E")) then { \
		call compile ("visibleposition vehicle " + WHO) \
	} else { \
		call compile ("position vehicle " + WHO) \
	})

_player = _this select 0;
_killer = _this select 1;
if (isnull _killer) then {_killer = _player};

_soundVolume = soundvolume;
_musicvolume = musicvolume;	

_teamswitchcheck = {
	_player = _this select 0;
	_ppeffects = _this select 1;
	_soundvolume = _this select 2;
	_musicvolume = _this select 3;

	//waituntil {_player != player};
	waituntil {alive player};
	setacctime 1;
	terminate _ppeffects;
	"dynamicBlur" ppEffectEnable false;
	"colorCorrections" ppEffectEnable false;
	0 fadesound _soundvolume;
	0 fademusic _musicvolume;
};

//--- Initial postprocess effects
_ppeffects = _player spawn {
	_player = _this;

	//--- Version
	_musicTrack = "";
	if (isclass (configfile >> "cfgmusic" >> "EP1_Track06")) then {_musicTrack = "EP1_Track06"};
	if (isclass (configfile >> "cfgmusic" >> "Track06_Abandoned_Battlespace")) then {_musicTrack = "Track06_Abandoned_Battlespace"};

	//--- Light blur
	"dynamicBlur" ppEffectEnable true;
	"dynamicBlur" ppEffectAdjust [2];
	"dynamicBlur" ppEffectCommit 0.1;  

	//--- Full red
	"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 1], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
	"colorCorrections" ppEffectCommit 0.1;
	"colorCorrections" ppEffectEnable true;
	sleep 0.1;

	//--- Partly red
	"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 0.5], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
	"colorCorrections" ppEffectCommit 0.3;

	//--- Dialog
	sleep 0.3;
	enableenddialog;
	_soundVolume = soundvolume;
	_musicvolume = musicvolume;	
	3 fadesound 0;
	0 fademusic 0.5;
	playmusic _musicTrack;
	waituntil {velocity vehicle _player distance [0,0,0] == 0};

	//--- Total blur
	"dynamicBlur" ppEffectAdjust [10];
	"dynamicBlur" ppEffectCommit 5;
	sleep 3;

	//--- Total red
	"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 1], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
	"colorCorrections" ppEffectCommit 2;
	sleep 4;
};

//--- Team switch check
_check = [_player,_ppeffects,_soundvolume,_musicvolume] spawn _teamswitchcheck;
waituntil {scriptdone _ppeffects || _player != player};
if (_player != player) exitwith {};
terminate _check;

//--- Pulsing effects
_ppeffects = _player spawn {
	while {true} do {
		_delay = (2 + random 1) * acctime;
		"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 0.7], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
		"colorCorrections" ppEffectCommit _delay;
		"dynamicBlur" ppEffectAdjust [.5];
		"dynamicBlur" ppEffectCommit _delay;  
		sleep _delay;

		_delay = (2 + random 1) * acctime;
		"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 0.3], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
		"colorCorrections" ppEffectCommit _delay;
		"dynamicBlur" ppEffectAdjust [4];
		"dynamicBlur" ppEffectCommit _delay;   
		sleep _delay;
	};
};
_check = [_player,_ppeffects,_soundvolume,_musicvolume] spawn _teamswitchcheck;


//--- Break if killer is alive - show his internal view
if (alive _killer && (_player distance _killer < 150) && random 1 > 0.5) then {
	_killer switchcamera "internal";
	setacctime 0.5;

	//--- Killer is dead or time expired
	_sleep = [] spawn {sleep (30 + random 30)};
	waituntil {!alive _killer || scriptdone _sleep};
	setacctime 1;
	_killer = _player;

	//--- Light blur
	"dynamicBlur" ppEffectEnable true;
	"dynamicBlur" ppEffectAdjust [2];
	"dynamicBlur" ppEffectCommit 0.1;  

	//--- Full red
	"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 1], [1.0, 0.5, 0.5, 0.1], [0.199, 0.587, 0.114, 0.0]];
	"colorCorrections" ppEffectCommit 0.1;
	"colorCorrections" ppEffectEnable true;
	sleep 0.1;
};

//--- Random constants for player
_pos = FNC_PLAYERPOS("_player");
_flying = if ((_pos select 2) > 50) then {true} else {false};
_size = sizeof typeof vehicle _player;
_dir = random 360;
_dx = sin _dir * _size;
_dy = cos _dir * _size;
_dz = if (_flying) then {_size * 2} else {_size};

//--- Random constants for killer
_ksize = sizeof typeof vehicle _killer;
_kdir = random 360;
_kdx = sin _dir * _size;
_kdy = cos _dir * _size;
_kdz = _size;

//--- Create camera
_camera = "camera" camcreate FNC_PLAYERPOS("_player");
_camera cameraeffect ["internal","back"];
showcinemaborder false;
_camera campreparetarget _pos;
_camera campreparepos [(_pos select 0) + _dx,(_pos select 1) + _dy,(_pos select 2) + _dz];
_camera campreparefov 0.7;
_camera camcommitprepared 0;

//--- Track player
while {velocity vehicle _player distance [0,0,0] > 0 || _flying} do {
	_pos = FNC_PLAYERPOS("_player");

	if (!_flying || (_flying && (FNC_PLAYERPOS("_player") select 2) > 50)) then {
		_camera campreparepos [(_pos select 0) + _dx,(_pos select 1) + _dy,(_pos select 2) + _dz];
	};
	_camera campreparetarget _pos;
	_camera camcommitprepared 0;
	sleep 0.01;
};

//--- Zoom out from player
_delay = 5 + random 5;
_distancecoef = 1.2;
if (_player == _killer) then {_delay = 100 + random 100; _distancecoef = 5 + random 3};
_pos = FNC_PLAYERPOS("_player");
_camera campreparepos [(_pos select 0) + _dx * _distancecoef,(_pos select 1) + _dy * _distancecoef,(_pos select 2) + _dz * _distancecoef];
_camera camcommitprepared _delay;
waituntil {camcommitted _camera};

if (_player == _killer) exitwith {};

//--- Show killer
_pos = FNC_PLAYERPOS("_killer");
_camera campreparetarget vehicle _killer;
_camera campreparepos [(_pos select 0) + _kdx,(_pos select 1) + _kdy,(_pos select 2) + _kdz];
_camera camcommitprepared (5 + random 5);
waituntil {camcommitted _camera};

while {true} do {
	_pos = FNC_PLAYERPOS("_killer");
	_camera campreparepos [(_pos select 0) + _kdx,(_pos select 1) + _kdy,(_pos select 2) + _kdz];
	_camera campreparetarget _pos;
	_camera camcommitprepared 0;
	sleep 0.01;
};
