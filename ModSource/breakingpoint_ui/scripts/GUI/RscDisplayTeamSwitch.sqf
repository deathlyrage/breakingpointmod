_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		if (count switchableunits == 1 && alive player) exitwith {_display closedisplay 2;};
		_display = _params select 0;

		with missionnamespace do {
			_dummy = [_params,"CA_TS_Pause"] call compile preprocessFile "\A3\ui_f\scripts\TeamSwitch.sqf";
		};
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//--- toUpper Title
		_ctrlTitle = _display displayctrl 1000;
		_ctrlTitle ctrlSetText (toUpper (ctrlText _ctrlTitle));
	};

	case "onUnload": {
		with missionnamespace do {
			_dummy = [_params,"CA_TS_Resume"] call compile preprocessFile "\A3\ui_f\scripts\TeamSwitch.sqf";
		};
	};
};