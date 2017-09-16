_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		endLoadingScreen; //--- Interrupt a loading screen to prevent freeze
		uinamespace setvariable ["BIS_fnc_startLoadingScreen_ids",[]];

		_display = _params select 0;
		
		//--- toUpper all button and title texts. Show/hide button backgrounds according to button visibility
		//OK (Later) button
		_button = _display displayctrl 6;
		_background = _display displayctrl 11002;
		_button ctrlSetText (toUpper (ctrlText _button));
		_background ctrlShow  !(ctrlShown _button);
		
		//Restart button
		_button = _display displayctrl 1;
		_background = _display displayctrl 11003;
		_button ctrlSetText (toUpper (ctrlText _button));
		_background ctrlShow  !(ctrlShown _button);
		
		//Cancel button
		_button = _display displayctrl 2;
		_background = _display displayctrl 11004;
		_button ctrlSetText (toUpper (ctrlText _button));
		_background ctrlShow  !(ctrlShown _button);
	};

	default {};
};