_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		uinamespace setvariable [_class,_params select 0];
	};
	case "onUnload": {
		[] call (uinamespace getvariable "bis_fnc_displayClouds");
	};
	default {};
};