disableSerialization;
private ["_control","_display","_temp","_event","_data","_x","_stopTheKey","_keyLeft"];
private ["_key","_keyRight","_keyTop","_keyBottom","_secondColumn","_activateControl","_output"];
_event = _this select 1;
_data = _this select 0;
_stopTheKey = false;

_setEnabledControlFocus = {
	_setFocusControl = _this select 0;
	ctrlSetFocus _setFocusControl;
	ctrlActivate _setFocusControl;
};
if(typeName(_data select 0) == "DISPLAY")then 
{
	_display = (_data select 0);
};

if(typeName(_data select 0) == "CONTROL")then 
{
	_control = (_data select 0);
	_display = ctrlParent _control;
	
};
_focus = false; 
if (_event == "onKeyDown")then
{
	_key = _data select 1;
	_focus = true;
};
_ctrlTop = _this select 2;
_ctrlRight = _this select 3;
_ctrlBottom = _this select 4;
_ctrlleft = _this select 5;

debuglog _this;

_keyLeft = [203,327700,327686];
_keyRight = [205,327696,327687];
_keyTop = [200,327697,327684];
_keyBottom = [208,327701,327685];
_nextCtrl = 0;

if((_keyLeft find _key)>=0)then {
	_nextCtrl = _ctrlLeft;
};
if((_keyRight find _key)>=0)then {
	_nextCtrl = _ctrlRight;
};
if((_keyTop find _key)>=0)then {
	_nextCtrl = _ctrlTop;
};
if((_keyBottom find _key)>=0)then {
	_nextCtrl = _ctrlBottom;
};
_output = false;
if (_nextCtrl != 0) then{
	_dummy = [_display displayctrl _nextCtrl] call _setEnabledControlFocus;
	_output = true;
};
debuglog _output;				



_output;
