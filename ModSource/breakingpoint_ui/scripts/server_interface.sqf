disableSerialization;

private  ["_data","_action","_display","_control","_lbindex"];
debuglog _this;
_data = _this select 0;
_action = _this select 1;
debuglog _action;

if(typeName(_data select 0) == "DISPLAY")then 
{
	_display = (_data select 0);
};

_lbindex = 0;
_lbselected  = "";
if(typeName(_data select 0) == "CONTROL")then 
{
	_control = (_data select 0);
	_display = ctrlParent _control;
	_lbindex =  (_data select 1);
	_lbselected = _control lbData _lbindex;
};

if (_lbselected == "DSInterface") then {openDSInterface;};
if (isMultiplayer) then {player createDiarySubject ["DSInterface", "Server control"]};

