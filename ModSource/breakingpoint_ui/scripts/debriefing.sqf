disableSerialization;
//#define IDC_DEBRIEFING_DEBRIEFING     113
//#define IDC_DEBRIEFING_STAT           103
//Reference to control which trigerred this script
_inputControl = (_this select 0) select 0;
_dialog = ctrlParent _inputControl ;
_controlDebriefing = (_dialog displayCtrl 114);
_controlStats = (_dialog displayCtrl 103);
_controlHintButton = (_dialog displayCtrl 1001);

//_disp_ctrl = (_dialog displayCtrl _inputControl); 

if !(ctrlShown _controlDebriefing) then { 
	//ctrlSetFocus _controlStats;
	_controlStats ctrlEnable false;
	_controlStats ctrlShow false;
	_controlDebriefing ctrlEnable true;
	_controlDebriefing ctrlShow true;
	_controlHintButton ctrlSettext "Statistics";

} else {
	//ctrlSetFocus (_dialog displayCtrl 103);
	_controlStats ctrlEnable true;
	_controlStats ctrlShow true;
	_controlDebriefing ctrlEnable false;
	_controlDebriefing ctrlShow false;
	_controlHintButton ctrlSettext "Objectives";
};
