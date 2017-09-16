_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		private ['_dummy'];
		_dummy = [_params,'onload'] call compile preprocessFile '\A3\ui_f\scripts\pauseCutScene.sqf';
		_dummy = ['Init', _params] call compile preprocessFile '\A3\ui_f\scripts\pauseLoadinit.sqf';

		//--- Editor Debug Console
		if (true) then {
			_display = _params select 0;
			_display displayaddeventhandler ["keydown","['keyDown',_this,'RscDisplayDebugPublic'] call (uinamespace getvariable 'RscDisplayMovieInterrupt_script'); false"];
		};

		//--- Blur ON
		"dynamicBlur" ppEffectEnable true; 
		"dynamicBlur" ppEffectAdjust [6];
		"dynamicBlur" ppEffectCommit 0;
	};

	case "onUnload": {
		private ["_dummy"];
		_dummy = [_params,'unload'] call compile preprocessFile '\A3\ui_f\scripts\pauseCutScene.sqf';

		//--- Blur OFF
		"dynamicBlur" ppEffectAdjust [0];
		"dynamicBlur" ppEffectCommit 0.0;
		"dynamicBlur" ppEffectEnable false;
	};

	case "keyDown": {
		_display = _params select 0;
		_key = _params select 1;
		switch (_key) do {

			//--- F1
			case 59: {
				_display closedisplay 2;
				createdialog 'RscDisplayDebugPublic';
			};
		};
	};

	default {};
};