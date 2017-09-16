disableSerialization;
// ctrlSetTooltip 
// ctrltext

_arrayInput =  _this select 0;
_display = (_arrayInput select 0);


for [{_x=0},{_x<=500},{_x=_x+1}] do 
{
	_control = _display displayctrl _x;
	_type = ctrlType _control;
	if (_type == 16) then {	
		_text = ctrltext _control;
		_control ctrlSetTooltip _text;
	};
};
true;
