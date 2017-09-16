disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_params spawn {	
			disableSerialization;
			_idc = [_this,1,1200,[0]] call bis_fnc_paramin;

			_display = _this select 0;
			_noise = _display displayctrl _idc;
			_coef = 256;

			while {!isnull _display} do {
				_resX = getResolution select 0;
				_resY = getResolution select 1;

				_noise ctrlsettext format [
					"#(ai,2048,2048,1)perlinNoise(%1,%2,%3,%4)",
					_resX / 2,
					_resY / 2,
					missionnamespace getvariable ["RscNoise_min",0.0],
					missionnamespace getvariable ["RscNoise_max",1.0]
				];
				_noise ctrlsetposition [
					safeZoneXAbs - random safeZoneWAbs,
					safeZoneY - random safezoneH,
					safeZoneWAbs * 2,
					safeZoneH * 2
				];
				_noise ctrlsettextcolor (missionnamespace getvariable ["RscNoise_color",[1,1,1,1]]);
				_noise ctrlcommit 0;
				uisleep 0.02;
			};
		};
	};
};