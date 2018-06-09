_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		['Init',_params] spawn (uinamespace getvariable "BIS_fnc_animViewer");
	};
	case "onUnload": {
		['Exit',_params] spawn (uinamespace getvariable "BIS_fnc_animViewer");
	};
};