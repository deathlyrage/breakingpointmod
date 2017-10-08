/*
fn_loadFSD.sqf

based on fn_loginUI.sqf
modified by Th3Dilli

creates "BP_fnc_factionStatsDiary" based on"breakingpoint_ui\info\InfoScreen.paa"
*/

disableSerialization;
cutRsc ["RscDisplayInfoScreenStats","PLAIN"];
call BP_fnc_factionStatsDiary;
