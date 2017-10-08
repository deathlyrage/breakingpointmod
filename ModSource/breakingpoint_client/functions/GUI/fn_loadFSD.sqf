/*
fn_loadFSD.sqf

based on fn_loginUI.sqf
modified by Th3Dilli

toggels/creates "BP_fnc_factionStatsDiary" based on"breakingpoint_ui\info\InfoScreen.paa"
*/

disableSerialization;

if(BP_IsInfoScreenActive)then
{
cutRsc ["Default","PLAIN"];
BP_IsInfoScreenActive = false;
} else
{
cutRsc ["RscDisplayInfoScreenStats","PLAIN"];
call BP_fnc_factionStatsDiary;
BP_IsInfoScreenActive = true;
};