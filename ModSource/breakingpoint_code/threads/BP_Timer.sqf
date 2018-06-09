/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_Timer";

private["_timeOut","_display","_control1","_control2"];
disableSerialization;

waitUntil {!(isNull (findDisplay 46))};

0 fadeSound 0;
0 cutText ["", "BLACK",0];
1 cutRsc ["BP_Ghosting","BLACK OUT",0];
2 cutRsc ["RscBPTimer","PLAIN",0];
3 cutRsc ["Default", "PLAIN",0];
4 cutRsc ["Default", "PLAIN",0];

_displayTimer = uiNameSpace getVariable "BP_Timer";
_timerTitle = controlNull;
_timerTime = controlNull;
_timerDescription = controlNull;

if (!isNil "_displayTimer") then {
	_timerTitle = _displayTimer displayctrl 1001;
	_timerTime = _displayTimer displayctrl 1003;
	_timerDescription = _displayTimer displayctrl 1100;
};

_timeOut = 480; // 8 Minutes
_FinalSeconds = 0;
_FinalMinutes = 0;
_timeOld = time;
_time = (480 - (time - _timeOld)) max 0;

disableUserInput false;
while { _time > 0 } do 
{
	_time = (480 - (time - _timeOld)) max 0;
	_timerTime ctrlsettext ([_time,"MM:SS.MS"] call bis_fnc_secondsToString);
	sleep 0.01;
};
disableUserInput true;

{ _x cutRsc ["Default","PLAIN",0]; } count [0,1,2,3,4];
