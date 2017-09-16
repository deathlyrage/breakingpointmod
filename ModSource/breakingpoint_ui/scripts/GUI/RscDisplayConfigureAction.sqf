_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
	
		_display = _params select 0;
	
		//--- set player's name
		(_display displayctrl 491) ctrlSetText profileName;
		[_display, 491] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//Sets all texts toUpper
		["RscDisplayConfigureAction",["RscText","RscTitle"],["PlayersName","ControlName","CA_TextHelp","CA_TextReserved"]] call bis_fnc_toUpperDisplayTexts;
	};	
};
