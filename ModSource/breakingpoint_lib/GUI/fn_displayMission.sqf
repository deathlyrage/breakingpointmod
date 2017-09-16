/*
	Author: Karel Moricky

	Description:
	Returns main display of current mission/intro/outro.

	Parameter(s):
	NOTHING

	Returns:
	DISPLAY
*/

disableSerialization;

private ["_displayMain","_idd","_display"];
_displayMain = displaynull;
{
	_idd = (configfile >> _x) call (uinamespace getvariable "bis_fnc_getIDD");
	_display = finddisplay _idd;
	if !(isnull _display) exitwith {_displayMain = _display};
} foreach [
	"RscDisplayMission",
	"RscDisplayIntro",
	"RscDisplayOutro",
	"RscDisplayMissionEditor"
];
_displayMain