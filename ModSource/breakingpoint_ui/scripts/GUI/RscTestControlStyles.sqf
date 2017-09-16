#include "\a3\Ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;

		_ST_HORIZONTAL = _display displayctrl (CT_PROGRESS + ST_HORIZONTAL);
		_ST_VERTICAL = _display displayctrl (CT_PROGRESS + ST_VERTICAL);

		_ST_HORIZONTAL progresssetposition 0.5;
		_ST_VERTICAL progresssetposition 0.5;
	};
};