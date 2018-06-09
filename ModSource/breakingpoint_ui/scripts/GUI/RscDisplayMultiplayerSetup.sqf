_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad": {
		_display = _params select 0;
		
		//Be sure chat is shown in case it was switched off in one of the preceding displays
		showChat false;
		
		//--- set player's name
		//(_display displayctrl 701) ctrlSetText profileName;
		//[_display, 701] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//toUpper Title
		//_control = _display displayctrl 1000;
		//_control ctrlSetText (toUpper (ctrlText _control));
		
		//Count players - works but can be done better (wait until ListBox is filled, than count), or use event handler for changing count of ListBox
		_display displayAddEventHandler
		[
			"mousemoving",
			"
				_display = _this select 0;
				(_display displayctrl 1015) ctrlsettext str (lbsize (_display displayctrl 114));	
			"
		];
		
		//Move focus to Roles, since OK button is disabled. We don't want to move focus to Disconnect button on client.
		ctrlSetFocus (_display displayctrl 109);
	};
	
	case "onUnload": {
		//Hide chat to be sure it's hidden when returning back to Create Game
		showChat false;
	};
	
};