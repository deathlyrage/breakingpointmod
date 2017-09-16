_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
	
		_display = _params select 0;
		
		//Convert title to upper-case.
		_control = _display displayctrl 1000;
		_control ctrlSetText (toUpper (ctrlText _control));
	};
};