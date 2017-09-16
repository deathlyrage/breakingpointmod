disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with (uinamespace) do {
			BIS_configviewer_display = _params select 0;
		};
	};
	case "onUnload": {
		[] spawn BIS_configviewer_unload;
	};
};