_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		private ["_display"];
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//toUpper title - TODO: This must be done in code
		//(_display displayctrl 118) ctrlSetText (toUpper (ctrlText _control));
	};
};