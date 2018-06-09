#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": 
	{
		_display = _params select 0;
		_isDebriefing = (ctrlidd _display) > 0;
		_okButton = _display displayCtrl 2;
		ctrlActivate _okButton;
	};
	case "onUnload": {
		if (missionnamespace getvariable ["RscDisplayDebriefing_noise",false]) then {
			0 cuttext ["","black"];
			1 cuttext ["","plain"];
		};
	};
};
