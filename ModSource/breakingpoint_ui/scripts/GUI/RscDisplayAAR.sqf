_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with missionnamespace do {
			['Init',_params] spawn (uinamespace getvariable "bis_fnc_diagAAR");
		};
	};
};