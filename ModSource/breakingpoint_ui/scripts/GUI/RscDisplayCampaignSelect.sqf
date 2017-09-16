disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		//[_class,_params select 0] call bis_fnc_displayResize;

		//--- Detect listbox size
		with uinamespace do {
			_display = _params select 0;
			_ctrlListbox = _display displayctrl 101;
			//RscDisplayCampaignSelect_lbselchanged = _ctrlListbox ctrladdeventhandler ["lbselchanged","with uinamespace do {['init',_this,''] call RscDisplayCampaignSelect_script};"];

			_ctrlListbox ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbselchanged',_this,''] call RscDisplayCampaignSelect_script};"];
		};
	};
	case "onUnload": {
		with uinamespace do {
			RscDisplayCampaignSelect_cursel = nil;
		};
	};

	case "lbselchanged": {
		_ctrlListbox = _params select 0;
		_cursel = _params select 1;

		//--- Overview
		_config = (configfile >> "cfgmissions" >> "campaigns") select _cursel;

		//--- Store current campaign's data
		RscDisplayCampaignSelect_cursel = _config;

		//--- Display custom overview
		[ctrlparent _ctrlListbox,_config,103] call bis_fnc_overviewMission;

		//--- Display author
		[ctrlParent _ctrlListbox,_config] call bis_fnc_overviewAuthor;
	};

/*
	case "init": {
		_ctrlListbox = _params select 0;
		_ctrlListbox ctrlremoveeventhandler ["lbselchanged",RscDisplayCampaignSelect_lbselchanged];
		RscDisplayCampaignSelect_lbselchanged = nil;

		//--- If only one campaign is found, skip the display completely
		if (lbsize _ctrlListbox == 1 && false) then {
			_display = ctrlparent _ctrlListbox;
			ctrlactivate (_display displayctrl 1);
			_display closedisplay 2;
		};
	};
*/
};