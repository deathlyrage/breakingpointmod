/*
fn_factionStatsDiary.sqf

based on fn_loginUILoaded.sqf
modified by Th3Dilli

shows faction stats on "breakingpoint_ui\info\InfoScreen.paa"
*/

_survival = BP_LocalSurvivalData;
_displayFSD = _this select 0;

//Grab Controls
_ctrlMap1 = (_displayFSD displayCtrl 1021);
_ctrlMap2 = (_displayFSD displayCtrl 1022);
_ctrlDay = (_displayFSD displayCtrl 1023);
_ctrlLocation = (_displayFSD displayCtrl 1024);
_ctrlRanger = (_displayFSD displayCtrl 1025);
_ctrlSurvivalist = (_displayFSD displayCtrl 1027);
_ctrlNomad = (_displayFSD displayCtrl 1026); 
_ctrlEngineer = (_displayFSD displayCtrl 1028);
_ctrlHunter = (_displayFSD displayCtrl 1029);
_ctrlOutlaw = (_displayFSD displayCtrl 1030);
_ctrlIndie = (_displayFSD displayCtrl 1031);
_ctrlUndead = (_displayFSD displayCtrl 1032);
_ctrlUndeadKills = (_displayFSD displayCtrl 1033);
_ctrlZKills = (_displayFSD displayCtrl 1034);
_ctrlHKills = (_displayFSD displayCtrl 1035);
_ctrlHeadshots = (_displayFSD displayCtrl 1036);
_ctrlDistTravel = (_displayFSD displayCtrl 1037);

//World
_worldName = worldName;

//Set Text for Top 2 Lines
_textTopL1 = ""; //not used
_textTopL2 = "Faction Points";


//Survival Time
_totalMins = _survival select 0;
_days = floor (_totalMins / 1440);

//Stats
_zombieKills = player getVariable ["zombieKills",0];
_humanKills = player getVariable ["humanKills",0];
_undeadKills = player getVariable ["undeadKills",0];
_headshots = player getVariable ["headShots",0];
_distTravel = player getVariable ["distTravel",0];

_rangerPoints = player getVariable ["ranger",0];
_nomadPoints = player getVariable ["nomad",0];
_survivalistPoints = player getVariable ["survivalist",0];
_engineerPoints = player getVariable ["engineer",0]; 
_hunterPoints = player getVariable ["hunter",0];
_outlawPoints = player getVariable ["outlaw",0];
_undeadPoints = player getVariable ["undead",0];


//Set Text
_ctrlMap1 ctrlSetText _textTopL1;
_ctrlMap2 ctrlSetText _worldName;
_ctrlLocation ctrlSetText _textTopL2;
_ctrlDay ctrlSetText (str _days);

_ctrlZKills ctrlSetText (str _zombieKills);
_ctrlHKills ctrlSetText (str _humanKills);
_ctrlUndeadKills ctrlSetText (str _undeadKills);
_ctrlHeadshots ctrlSetText (str _headshots);
_ctrlDistTravel ctrlSetText (str _distTravel);

_ctrlRanger ctrlSetStructuredText (parseText (str _rangerPoints));
_ctrlNomad ctrlSetStructuredText (parseText (str _nomadPoints));
_ctrlSurvivalist ctrlSetStructuredText (parseText (str _survivalistPoints));
_ctrlEngineer ctrlSetStructuredText (parseText (str _engineerPoints));
_ctrlHunter ctrlSetStructuredText (parseText (str _hunterPoints));
_ctrlOutlaw ctrlSetStructuredText (parseText (str _outlawPoints));
_ctrlIndie ctrlSetStructuredText (parseText "n/a");
_ctrlUndead ctrlSetStructuredText (parseText (str _undeadPoints));
