_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//--- Display load
	case "onLoad": {
		_display = _params select 0;
		BIS_fnc_advHint_hintHandlers = false;		//variable for advanced hint system
	
		//--- Game version number (copied from main menu display)
		(_display displayctrl 1000) ctrlsettext ctrltext ((finddisplay 0) displayctrl 118);
	
		if ((productVersion select 4) == "Stable") then
		{
			//Hide the watermark
			_control = _display displayctrl 11400;
			_control ctrlsetfade 1;
			_control ctrlcommit 0;
		};
		
		//Hide chat in MP when Stream Friendly UI is on.
		if (isMultiplayer && isStreamFriendlyUIEnabled) then
		{
			showChat false;
		};
		
		if ((productVersion select 4) == "Development") then
		{
			_display displayaddeventhandler [
				"keydown",
				"
					disableserialization;
					_key = _this select 1;

					if(_key == 197) then {
						_display = _this select 0;
						_control = _display displayctrl 1202;
						_control ctrlsetfade round ((ctrlfade _control + 1) % 2);
						_control ctrlcommit 0.2;

						_control = _display displayctrl 11400;
						_control ctrlsetfade round ((ctrlfade _control + 1) % 2);
						_control ctrlcommit 0.2;
					};
				"
			];
		};
		
		//Hide vehicle notification displayed next to action menu. TODO - Remove this as soon as showing/hiding is implemented in code.
		_vehicleNotification = _display displayctrl 11406;
		_vehicleNotification ctrlShow false;

		//--- Reset menu tile effect
		[] call bis_fnc_guiEffectTiles;
	};
};