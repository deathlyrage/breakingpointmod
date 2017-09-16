_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		if (isnil {missionnamespace getvariable "bis_fnc_arsenal_data"}) then {
			startloadingscreen [""];
			['Init',_params] spawn (uinamespace getvariable "BIS_fnc_arsenal");
		} else {
			['Init',_params] call (uinamespace getvariable "BIS_fnc_arsenal");
		};
	};
	case "onUnload": {
		['Exit',_params] call (uinamespace getvariable "BIS_fnc_arsenal");
	};
};