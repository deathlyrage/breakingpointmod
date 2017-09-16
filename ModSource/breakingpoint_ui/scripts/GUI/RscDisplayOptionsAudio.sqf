_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//--- Display load
	case "onLoad": {
		
		//takes player's name from Main menu and sets it in Audio Options
		private ["_display"];

		//take display that is being created (Audio options)
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 601) ctrlSetText profileName;
		[_display, 601] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//Sets all texts toUpper
		["RscDisplayOptionsAudio",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;
		
		//--- Set focus to VOLUME button
		_volumeButton = _display displayctrl 8431;
		ctrlSetFocus _volumeButton;
	};

	//--- Nothing
	default {};
};