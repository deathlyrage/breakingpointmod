private ["_mode","_params","_class"];

with uinamespace do {

	//--- Functions init
	if (isnil "bis_fnc_init") then {
		_functionsInit = gettext (configfile >> "CfgFunctions" >> "init");
		if (_functionsInit != "") then {
			[2] call compile preprocessfilelinenumbers _functionsInit;
		} else {
			debuglog ["Log: ERROR: Functions Init not found!"];
		};
	};


	_mode = [_this,0,"",[""]] call bis_fnc_param;
	_params = [_this,1,[]] call bis_fnc_param;
	_class = [_this,2,"",[""]] call bis_fnc_param;
	_path = [_this,3,"default",[""]] call bis_fnc_param;

	_varDisplays = _path + "_displays";
	_varClasses = _path + "_classes";

	//--- Check color settings (when nil, set default values)
	if (_path == "GUI") then {["GUI","BCG_RGB"] call bis_fnc_displayColorGet;};

	//--- Register/unregister display
	_display = _params select 0;
	switch _mode do {
		case "onLoad": {
			_displays = uinamespace getvariable [_varDisplays,[]];
			_classes = uinamespace getvariable [_varClasses,[]];

			//--- Remove null displays
			{
				if (isnull _x) then {
					_displays set [_foreachindex,displaynull];
					_classes set [_foreachindex,""];
				};
			} foreach _displays;
			_displays = _displays - [displaynull];
			_classes = _classes - [""];
			_classes resize (count _displays);

			//--- Register current display
			_display = _params select 0;
			_displays set [count _displays,_display];
			_classes set [count _classes,_class];

			if (_path == "GUI") then {
				if (isnil "BIS_initGame") then {
					if ({ctrlidd _x >= 0} count _displays > 1) then {
						BIS_initGame = true;
					};
				};
			};

			//--- Store variables
			uinamespace setvariable [_varDisplays,_displays];
			uinamespace setvariable [_varClasses,_classes];
			uinamespace setVariable [_class, _params select 0];

			//--- Effects
			[_display,_class] call bis_fnc_guiEffectTiles;

		};
		case "onUnload": {
			if (_path == "GUI") then {
				_displays = uinamespace getvariable [_varDisplays,[]];
				if (count _displays == 2) then {
					(_displays select 0) call bis_fnc_guiNewsfeed;
				};
			};
		};
	};

	//--- Register script for the first time
	_fncName = _class + "_script";
	if (isnil _fncName || cheatsEnabled) then {

		//--- Set script path
		_scriptPath = gettext (configfile >> "cfgScriptPaths" >> _path);

		//--- Execute
		_fncFile = preprocessfilelinenumbers format [_scriptPath + "%1.sqf",_class];
		_fncFile = format ["scriptname '%1_%2'; _fnc_scriptName = '%1_%2';",_class,_mode] + _fncFile;
		uinamespace setvariable [
			_fncName,
			compileFinal _fncFile
		];
	};

	//--- Call script
	if (!cheatsEnabled || (cheatsEnabled && !(uinamespace getvariable ["BIS_disableUIscripts",false]))) then {
		[_mode,_params,_class] call (uinamespace getvariable _fncName);
	};

	//--- Call custom scripts
/*
	if (_class != "") then {
		[missionnamespace,_class,[_display]] spawn BIS_fnc_callScriptedEventHandler;
	};
*/
};