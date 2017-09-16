disableSerialization;

private ["_idd", "_display"];
_idd = getNumber(configFile >> "RscDisplayOptions" >> "idd");
_display = findDisplay _idd;
_display closeDisplay 2;

[] spawn
{
	sleep 0.005;
	playScriptedMission ["limnos", {private ["_handle"]; _handle = execVM "\A3\missions_f\data\scenes\credits1\init.sqf"}, configFile >> "CfgMissions" >> "Cutscenes" >> "Credits"];
};