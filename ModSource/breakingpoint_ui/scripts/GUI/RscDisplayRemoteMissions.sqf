disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Sets title and button texts toUpper
		["RscDisplayRemoteMissions",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;
		
		//Hide chat, show mission summary
		showChat false;
		_missionSummary = (_display displayctrl 2300);
		_missionSummary ctrlSetFade 0;
		_missionSummary ctrlCommit 0;
		_missionSummary ctrlEnable true;
		
		//Mission Summary button
		_button = _display displayctrl 1085;
		_button ctrladdeventhandler ["buttonclick","with uinamespace do {['missionSummaryButton',_this,''] call RscDisplayRemoteMissions_script};"];
		
		//Chat button
		_button = _display displayctrl 1086;
		_button ctrladdeventhandler ["buttonclick","with uinamespace do {['chatButton',_this,''] call RscDisplayRemoteMissions_script};"];
		
		//count missions
		//_vel = lbSize (_display displayctrl 102);
		
		//debuglog _vel;

		//don't count New-Editor and New-Wizard
		//_size = _size - 2;
		//if(_size < 0) then {_size = 0;};
		//(_display displayctrl 1014) ctrlSetText (str _vel);
		
		//(_display displayctrl 101) ctrladdeventhandler ["lbselchanged","with uinamespace do {['mapChanged',_this,''] call RscDisplayRemoteMissions_script};"];
	};
	
	//--- Mission Summary button
	case "missionSummaryButton": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		
		//Hide chat, show mission summary
		showChat false;
		_missionSummary = (_display displayctrl 2300);
		_missionSummary ctrlSetFade 0;
		_missionSummary ctrlCommit 0;
		_missionSummary ctrlEnable true;	
	};
	
	//--- Chat button
	case "chatButton": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		
		//Show chat, hide mission summary
		showChat true;
		_missionSummary = (_display displayctrl 2300);
		_missionSummary ctrlSetFade 1;
		_missionSummary ctrlCommit 0;
		_missionSummary ctrlEnable false;
	};

	/*
	case "mapChanged": {
		[] spawn
		{
			//_ctrl = _params select 0;
			_display = ctrlparent (_params select 0);
			
			sleep 0.2;
			
			//count missions
			_size = lbSize (_display displayctrl 102);
			//don't count New-Editor and New-Wizard
			_size = _size - 2;
			if(_size < 0) then {_size = 0;};
			(_display displayctrl 1014) ctrlSetText (str _size);
		};
	};
	*/
	
	case "onUnload": {
	
		//Hide chat to be sure it's hidden when returning back to Server List
		showChat false;
	};
	
};