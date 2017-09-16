disableSerialization;
// ctrlSetTooltip 
// ctrltext

_arrayInput =  _this select 0;
_display = (_arrayInput select 0);

_control = _display displayctrl 81;
ctrlActivate _control;
closeDialog 0;
true;
