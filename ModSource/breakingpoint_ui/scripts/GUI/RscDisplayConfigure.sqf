disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;
		[_display] spawn {
			disableserialization;
			sleep 0.0001;
			((_this select 0) displayCtrl 108) lbsetcursel (profilenamespace getvariable ["RscDisplayConfigure_cursel",0]);
		};
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Sets all texts toUpper
		["RscDisplayConfigure",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;		
		
		
		//--- Keyboard button
		_control = _display displayctrl 2400;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['keyboardGroup',_this,''] call RscDisplayConfigure_script};"];
		//--- Set focus to Keyboard button
		ctrlSetFocus _control;
		
		//--- Mouse button
		_control = _display displayctrl 2401;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['mouseGroup',_this,''] call RscDisplayConfigure_script};"];
		
		//--- Disable Mouse group
		_MouseGroup = _display displayctrl 2301;
		_MouseGroup ctrlenable false;
		_MouseGroup ctrlshow false;
		
		//--- Hide Default button
		_control = _display displayctrl 101;
		_control ctrlenable false;
		_control ctrlshow false;
	};
	
	//--- Keyboard button
	case "keyboardGroup": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_KeyboardGroup = _display displayctrl 2300;
		_MouseGroup = _display displayctrl 2301;
		_ctrlKeyboard = _display displayctrl 2400;	//KEYBOARD button
		
		//--- Enable Keyboard
		_KeyboardGroup ctrlenable true;
		_KeyboardGroup ctrlshow true;
	
		//--- Disable Mouse
		_MouseGroup ctrlenable false;
		_MouseGroup ctrlshow false;
		
		//--- Set focus to KEYBOARD button
		ctrlSetFocus _ctrlKeyboard;
		
		//--- Show Presets button
		_control = _display displayctrl 114;
		_control ctrlenable true;
		_control ctrlshow true;
		
		//--- Hide Default button
		_control = _display displayctrl 101;
		_control ctrlenable false;
		_control ctrlshow false;
	};
	
	//--- Mouse button
	case "mouseGroup": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_KeyboardGroup = _display displayctrl 2300;
		_MouseGroup = _display displayctrl 2301;
		_ctrlMouse = _display displayctrl 2401;		//MOUSE button
		
		//--- Enable Mouse
		_MouseGroup ctrlenable true;
		_MouseGroup ctrlshow true;
				
		//--- Disable Keyboard
		_KeyboardGroup ctrlenable false;
		_KeyboardGroup ctrlshow false;
		
		//--- Set focus to MOUSE button
		ctrlSetFocus _ctrlMouse;
		
		//--- Show Default button
		_control = _display displayctrl 101;
		_control ctrlenable true;
		_control ctrlshow true;
		
		//--- Hide Presets button
		_control = _display displayctrl 114;
		_control ctrlenable false;
		_control ctrlshow false;
	};
	
	case "onUnload": {
		_display = _params select 0;
		profilenamespace setvariable ["RscDisplayConfigure_cursel",lbcursel (_display displayCtrl 108)];
		saveprofilenamespace;
		

	};
};



//Set helicopter controls as default - switched off in A3
//_class spawn 
//{
//	disableSerialization;
//	sleep 0.0001;
//	((uiNamespace getVariable _this) displayCtrl 108) lbSetCurSel 4; //TODO: fix when order changes
//};

//true