private ["_mode", "_params", "_class"];
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch (_mode) do {
	case "onLoad": {uiNamespace setVariable ["BIS_revive_progress_display", _params select 0]};
	case "onUnload": {uiNamespace setVariable ["BIS_revive_progress_display", displayNull]};
};