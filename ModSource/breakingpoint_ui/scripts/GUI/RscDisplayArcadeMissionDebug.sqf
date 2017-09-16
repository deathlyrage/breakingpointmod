#define DISPLAY	(uinamespace getvariable 'RscDisplayArcadeMissionDebug')
#define CONTROL	(DISPLAY displayctrl _idc)

45 call bis_fnc_log;
_idc = 1700;
CONTROL buttonsetaction "
	[finddisplay 26] spawn (uinamespace getvariable 'bis_fnc_help');
";

_idc = 1701;
CONTROL buttonsetaction "
	[] spawn {
		[finddisplay 26] spawn (uinamespace getvariable 'bis_fnc_configviewer');
	};
";

_idc = 1702;
CONTROL buttonsetaction "
	[finddisplay 26] spawn (uinamespace getvariable 'bis_fnc_guieditor');
";