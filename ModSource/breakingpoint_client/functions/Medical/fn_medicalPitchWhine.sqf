/*
	Breaking Point Mod: BP_fnc_medicalPitchWhine;

	Description:
		Damage Handler Pitch / Whine Sound
	Parameter(s): []
		- visual (Int)
		- sound (Int)
	Returns:
		None
	Example: [20,45] call BP_fnc_medicalPitchWhine;
*/

params [["_visual",0],["_sound",0]];

0 fadeSound 0;
playMusic ["PitchWhine",0];

if (!r_player_unconscious) then {
	_visual call BP_fnc_medicalBulletHit;
	_sound fadeSound 1;
};

r_pitchWhine = true;

_handle = [] spawn 
{
	scriptName "BP_medicalPitchWhine";
	sleep 32;
	r_pitchWhine = false;
};
[_handle] call BP_fnc_addThreadHandle;