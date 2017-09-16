_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onUnload": {
		[] spawn {
			//--- Assign default values
			true call bis_fnc_displayColorGet;
			false call bis_fnc_guiGridToProfile;
		};
	};

	default {};
};