_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	//--- Display load
	case "onLoad":
	{
		private ["_display","_control"];

		//Set title text toUpper
		_display = _params select 0;
		_control = _display displayctrl 1000;
		_control ctrlSetText (toUpper (ctrlText _control));
	};
};