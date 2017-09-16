_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//--- Display load
	case "onLoad": {
		
		private ["_display"];

		//take display that is being created
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 601) ctrlSetText profileName;
		[_display, 601] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		
		//Sets all texts toUpper
		["RscDisplayCustomizeController",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;
	};
};