/*
	Breaking Point Mod: BP_fnc_medicalUnconsciousRecover;

	Description:
		None
	
	Parameter(s):
		None
	
	Returns:
		True
*/

if (isNull player) exitWith {};
if (r_player_dead) exitWith {};
r_player_unconscious = false;
r_player_handler1 = false;
r_player_timeout = 0;
player setVariable ["med_unconscious", false, true];
player setVariable ["unconsciousTime", 0, true];
player switchMove "AmovPpneMstpSnonWnonDnon_healed";
disableUserInput false;
player playActionNow "stop";