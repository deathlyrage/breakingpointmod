/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_Music";

waitUntil
{
	if (isNil "r_player_dead") exitWith {};
	if (r_player_dead) exitWith {};
	
	waitUntil {!r_player_unconscious};
	waitUntil {!r_pitchWhine};
	
	// Play Music
	_num = round(random 35);
	_sound = "bp_val_" + str(_num);
	playMusic _sound;
	//["playMusic: Starting Music %1~0001",_sound] call BP_fnc_debugConsoleFormat;

	// Wait Until Next Track
	_duration = getNumber (configFile >> "CfgMusic" >> _sound >> "duration");
	sleep _duration;
	
	// Wait Between Tracks
	_num = round(random 90);
	if (_num < 30) then { _num = 30; };
	//["musicWait: Waiting %1 Seconds Before Next Track.~0001",_num] call BP_fnc_debugConsoleFormat;
	sleep _num;
	
	(!alive player)
};