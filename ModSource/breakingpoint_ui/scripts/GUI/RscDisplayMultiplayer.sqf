disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
	
		_display = _params select 0;
	
		//--- set player's name
		(_display displayctrl 1008) ctrlSetText profileName;
		[_display, 1008] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//Sets title and button texts toUpper
		["RscDisplayMultiplayer",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;

		//Hide chat
		showChat false;	
	};
	
	case "onUnload": {

		//Show chat to be available in SP again
		showChat true;
	};
};