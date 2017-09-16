_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//--- Display load
	case "onLoad": {
		
		//takes player's name from Main menu and sets it in Options dialogue
		private ["_display"];

		//take display that is being created (Options)
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
	};
	
	// case "onUnload": {
	
		// //disable cheat
		// if( getNumber(configfile >> "isDemo") == 1 ) then
		// {
			// uiNamespace setVariable ["BIS_isCheatOptions", false];
		// };
	// };

	//--- Nothing
	default {};
};