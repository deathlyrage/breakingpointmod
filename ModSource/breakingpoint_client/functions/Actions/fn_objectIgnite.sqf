/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_entity","_igniteInProgress","_animState","_isMedic","_started","_finished"];
_entity = _this select 3;

player removeAction s_player_igniteObject;
s_player_igniteObject = -1;

if (isNull _entity) exitWith {};

//Mutex Lock On Igniting
_alreadyHarvested = _entity getVariable ["gutted",false];
if (_alreadyHarvested) exitWith {};

_leaveReturn = ["Are you sure you would like to ignite this object?","Ignite",nil,true] call BIS_fnc_guiMessage;
if (!_leaveReturn) exitWith {};

_entity setVariable ["gutted",true,true];

call BP_fnc_medicalRemoveMedicActions;
r_action = false;

player playActionNow "Medic";

r_interrupt = false;
_animState = animationState player;
r_doLoop = true;
_started = false;
_finished = false;
//[player,"bandage",0,false] call BP_fnc_objSpeak;
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

if (_finished) then {
	[BP_characterID,(netID _entity),"Ignite",(netID player)] remoteExecCall ["BPServer_fnc_deleteObj",2];
} else {
	_entity setVariable ["gutted",false,true];
	r_interrupt = false;
	player playActionNow "stop";
};