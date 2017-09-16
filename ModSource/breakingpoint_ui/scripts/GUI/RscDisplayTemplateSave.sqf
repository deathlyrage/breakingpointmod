_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;

		_ctrlName = _display displayctrl 101;

		if (
			//--- 'Save As' was not triggered
			!(uinamespace getvariable ["RscDisplayArcadeMap_saveAs",false])
			&&
			//--- Mission name is not empty (cannot save non-existing mission)
			ctrltext _ctrlName != ""
		) then {
			ctrlactivate (_display displayctrl 1);
		};
		uinamespace setvariable ["RscDisplayArcadeMap_saveAs",nil];
			
		//Sets all static texts toUpper
		["RscDisplayTemplateSave",["RscText","RscTitle"]] call bis_fnc_toUpperDisplayTexts;	
	};
};