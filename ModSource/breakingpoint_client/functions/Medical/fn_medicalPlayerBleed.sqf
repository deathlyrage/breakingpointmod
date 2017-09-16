/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_bleedTime","_bleedPerSec","_total","_bTime","_myBleedTime","_startingBleedingLevel"];

if (r_player_dead) exitWith {};

_bleedTime = 400; //seconds
_bleedPerSec = (r_player_bloodTotal / _bleedTime);
_startingBleedingLevel = r_player_bleedingLevel;
switch (_startingBleedingLevel) do {
	case 0: 	{ _bleedPerSec = 30; };
	case 1: 	{ _bleedPerSec = 50; };
	case 2: 	{ _bleedPerSec = 75; };
	case 3: 	{ _bleedPerSec = 100; };
};
_total = r_player_bloodTotal;
r_player_injured = true;
_myBleedTime = (random 500) + 100;
_bTime = 5;
while {r_player_injured} do 
{
	if (r_player_dead) exitWith {};
	//bleed out
	if (r_player_blood > 0) then {
		r_player_blood = r_player_blood - _bleedPerSec;
		[_bTime] call BIS_Fnc_bloodEffect;
	};
	_bTime = _bTime + 1;
	if (_bTime > _myBleedTime) then {
		if (_startingBleedingLevel < 2) then {
			r_player_injured = false;
		};
	};
	sleep 1;
};

["medBandage",(netID player),(netID player)] call BP_fnc_medicalEvent;
r_player_bleedingLevel = 0;
player setVariable ["med_injured",false,true];
r_player_handler = false;	