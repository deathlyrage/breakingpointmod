/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

r_action = false;

if (currentWeapon player in BP_MeleeWeapons) then
{
	player action ["SwitchWeapon", player, player, 100];
	player switchcamera cameraView;
	sleep 1;
};

player playActionNow "Medic";

r_interrupt = false;
_animState = animationState player;
r_doLoop = true;
_started = false;
_finished = false;
[player,"bandage",0,false] call BP_fnc_objSpeak;
while {r_doLoop} do {
	_animState = animationState player;
	_isMedic = ["medic",_animState] call BP_fnc_inString;
	if (_isMedic) then {
		_started = true;
	};
	if (_started and !_isMedic) then {
		r_doLoop = false;
		_finished = true;
	};
	if (r_interrupt) then {
		r_doLoop = false;
	};
	
	if (r_player_dead) exitWith {};
	
	sleep 0.1;
};
r_doLoop = false;

if (!_finished) then {
	r_interrupt = false;
	player switchMove "";
	player playActionNow "stop";
};

_finished