_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	//--- Display load
	case "onLoad":
	{
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 1001) ctrlSetText profileName;
		[_display, 1001] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//toUpper title
		_control = _display displayctrl 1000;
		_control ctrlSetText (toUpper (ctrlText _control));
	};
};