_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
	
		//Sets all static texts toUpper
		["RscDisplayArcadeWaypoint",["RscText","RscTitle","CA_TextCategory"]] call bis_fnc_toUpperDisplayTexts;		
	};
};