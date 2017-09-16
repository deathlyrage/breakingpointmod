_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;
		_display closedisplay 2;
	};
};