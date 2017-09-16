disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_params spawn {	
			disableSerialization;

			_display = _this select 0;
			uinamespace setvariable ["RscStatic_display",_display];
	
			private ["_mode"];
			_mode = [missionnamespace getvariable ["RscStatic_mode",1],0,1,[0]] call bis_fnc_paramin;
			missionnamespace setvariable ["RscStatic_mode",nil];
	
			private ["_steps", "_idcGroup"];
			_steps = 12;
			_idcGroup = 2400;
	
			for "_i" from 0 to _steps do {
				private ["_idc"];
				_idc = if (_mode == 0) then {_idcGroup + _i} else {_idcGroup + (_steps - _i)};
		
				// Show static
				(_display displayCtrl _idc) ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW, safeZoneH];
				(_display displayCtrl _idc) ctrlCommit 0;
		
				// 30 FPS
				sleep (0.03);
		
				// Remove static
				(_display displayCtrl _idc) ctrlSetPosition [0,0,0,0];
				(_display displayCtrl _idc) ctrlCommit 0;
			};
			uinamespace setvariable ["RscStatic_display",displaynull];
		};
	};
};