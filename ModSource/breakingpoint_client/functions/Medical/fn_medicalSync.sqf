/*
	Breaking Point Mod: BP_fnc_updateMedical

	Description:
		Update and Sync All Medical Related Variables that are outdated.
	
	Parameter(s):
		None
	
	Returns:
		True
*/

if (isNil "r_player_dead") exitWith {
	["Error: Undefined Variable in BP_fnc_updateMedical.#1000"] call BP_fnc_debugConsoleFormat;
};

_unconscious = format ["%1",(player getVariable["med_unconscious", false])];
_r_unconscious = format ["%1",(r_player_unconscious)];

_infected = format ["%1",(player getVariable["med_infected", false])];
_r_infected = format ["%1",(r_player_infected)];

_injured = format ["%1",(player getVariable["med_injured", false])];
_r_injured = format ["%1",(r_player_injured)];

_pain = format ["%1",(player getVariable["med_inPain", false])];
_r_pain = format ["%1",(r_player_inpain)];

_cardiac = format ["%1",(player getVariable["med_isCardiac", false])];
_r_cardiac = format ["%1",(r_player_cardiac)];

_lowBlood = format ["%1",(player getVariable["med_lowBlood", false])];
_r_lowBlood = format ["%1",(r_player_lowblood)];

_bleedingLevel = format ["%1",(player getVariable["med_bleedingLevel", 0])];
_r_bleedingLevel = format ["%1",(r_player_bleedingLevel)];

_blood = format ["%1",(player getVariable["med_BloodQty", 12000])];
_r_blood = format ["%1",(r_player_blood)];

if (_unconscious != _r_unconscious) then {
	player setVariable["med_unconscious", r_player_unconscious,true];
	["updateMedical: Published Global Variable: med_unconscious with value %1",r_player_unconscious] call BP_fnc_debugConsoleFormat;
};

if (_infected != _r_infected) then {
	player setVariable["med_infected", r_player_infected,true];
	["updateMedical: Published Global Variable: med_infected with value %1",r_player_infected] call BP_fnc_debugConsoleFormat;
};

if (_injured != _r_injured) then {
	player setVariable["med_injured", r_player_injured,true];
	["updateMedical: Published Global Variable: med_injured with value %1",r_player_injured] call BP_fnc_debugConsoleFormat;
};

if (_pain != _r_pain) then {
	player setVariable["med_inPain", r_player_inpain,true];
	["updateMedical: Published Global Variable: med_inPain with value %1",r_player_inpain] call BP_fnc_debugConsoleFormat;
};

if (_cardiac != _r_cardiac) then {
	player setVariable["med_isCardiac", r_player_cardiac,true];
	["updateMedical: Published Global Variable: med_isCardiac with value %1",r_player_cardiac] call BP_fnc_debugConsoleFormat;
};

if (_blood != _r_blood) then {
	player setVariable["med_BloodQty",r_player_blood];
	["updateMedical: Published Local Variable: med_BloodQty with value %1",r_player_blood] call BP_fnc_debugConsoleFormat;
};

if (r_player_blood < r_player_bloodTotal) then {
	r_player_lowblood = true;
} else {
	r_player_lowblood = false;
};

if (_lowBlood != _r_lowBlood) then {
	player setVariable["med_lowBlood", r_player_lowblood,true];
	["updateMedical: Published Global Variable: med_lowBlood with value %1",r_player_lowblood] call BP_fnc_debugConsoleFormat;
};

if (_bleedingLevel != _r_bleedingLevel) then {
	player setVariable["med_bleedingLevel",r_player_bleedingLevel,true];
	["updateMedical: Published Global Variable: med_bleedingLevel with value %1",r_player_bleedingLevel] call BP_fnc_debugConsoleFormat;
};
