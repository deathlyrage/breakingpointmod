disableSerialization;
private ["_display", "_control","_topic"];
debuglog "on load single mission topic";
_display = (_this select 0) select 0;
_control = _display displayctrl 106;

_topic = ctrlText _control;
if (_topic == "tutorial") then {
	_setTopic = localize ("STR_DISP_MAIN_TRAINING");
	_control ctrlSetText _setTopic;
};
true;