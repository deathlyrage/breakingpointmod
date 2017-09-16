
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//--- Not used, RscDisplaCampaignLoad is sharing the script with RscDisplaySingleMission
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {

		with uinamespace do {
			_display = _params select 0;

//MUF-not needed in A3
/*
			_ctrlMissions = _display displayctrl 101;
			_ctrlMissions ctrladdeventhandler ["lbselchanged","with uinamespace do {_this call RscDisplayCampaignLoad_lbselchanged;};"];
			RscDisplayCampaignLoad_initEH = _ctrlMissions ctrladdeventhandler ["lbselchanged","with uinamespace do {_this call RscDisplayCampaignLoad_init;};"];

			//--- Mission selection
			RscDisplayCampaignLoad_lbselchanged = {
				_ctrlMissions = _this select 0;
				_cursel = _this select 1;

				//--- Detect heliports
				_heliports = [];
				_heliportsCurrentNames = [];
				_heliportsCurrent = [];
				_lbsize = lbsize _ctrlMissions;
				for "_i" from 0 to (_lbsize - 1) do {
					_configname = _ctrlMissions lbdata _i;
					_config = campaignconfigfile >> "campaign" >> "missions" >> _configname;
					_heliport = getnumber (_config >> "heliport");
					if (_heliport > 0) then {
						_heliports set [count _heliports,_i];
						_heliportId = _heliportsCurrentnames find _configName;
						if (_heliportId < 0) then {
							_heliportId = count _heliportsCurrentnames;
							_heliportsCurrentnames set [_heliportId,_configname];
						};
						_heliportsCurrent set [_heliportId,_i];
						//_ctrlMissions lbsetpicture [_i,"#(argb,8,8,3)color(1,1,1,1)"];
					};
				};

				//--- Delete duplicate heliports
				_heliports = _heliports - _heliportsCurrent;
				{_ctrlMissions lbdelete (_x - _foreachindex)} foreach _heliports;

				//--- Order has changed - Select different mission
				if (_lbsize != lbsize _ctrlMissions) exitwith {
					_ctrlMissions lbsetcursel (lbsize _ctrlMissions - 1)
				};
				//------------------------------------------------

				//--- Mark heliports
				_iconHeliport = gettext(campaignconfigfile >> "campaign" >> "iconHeliport");
				if (_iconHeliport != "") then {
					{
						_ctrlmissions lbsetpicture [_x,_iconHeliport];
					} foreach _heliportsCurrent;
				};

				//--- Selected mission
				_configname = _ctrlMissions lbdata _cursel;
				_config = if (_cursel > 0) then {
					campaignconfigfile >> "campaign" >> "missions" >> _configname
				} else {
					uinamespace getvariable ["RscDisplayCampaignSelect_cursel",campaignconfigfile >> "campaign"]
				};

				//--- Display custom overview
				[ctrlparent _ctrlMissions,_config,108] call bis_fnc_overviewMission;

				//--- Disable 'Revert' button (never for latest mission)
				if (getnumber (campaignconfigfile >> "campaign" >> "disableRevert") > 0) then {
					_display = ctrlparent _ctrlMissions;
					_ctrlRevert = _display displayctrl 109;
					_ctrlRevert ctrlenable (_cursel >= (lbsize _ctrlMissions - 1));
				};
			};

			//--- Init
			RscDisplayCampaignLoad_init = {

				//--- Remove init EH
				_ctrlMissions = _this select 0;
				_ctrlMissions ctrlremoveeventhandler ["lbselchanged",RscDisplayCampaignLoad_initEH];
				RscDisplayCampaignLoad_initEH = nil;

				//--- Save HTML size
				_display = ctrlparent _ctrlMissions;
				_ctrlHTML = _display displayCtrl 108;
				RscDisplayCampaignLoad_HTMLsize = ctrlposition _ctrlHTML;

				//--- Load campaign's name
				_campaign = campaignconfigfile >> "campaign";
				_campaignName = gettext (_campaign >> "name");
				_ctrlTitle = _display displayctrl 111; //in TKOH was: 1003; TODO: make this work for RscTree
				_ctrlTitle ctrlsettext _campaignName;
			};
*/
			
			//--- set player's name
			(_display displayctrl 8434) ctrlSetText profileName;
			[_display, 8434] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
			
			//--- Campaign Title toUpper
			_ctrlTitle = _display displayctrl 1000;
			_ctrlTitle ctrlSetText (toUpper (ctrlText _ctrlTitle));
			
			//--- Cancel
			//_button = _display displayctrl 2;
			//_button ctrlSetText (toUpper (ctrlText _button));
			
			//--- Game Options
			//_button = _display displayctrl 2401;//TODO - implement return from game options back to campaign
			//_button ctrlSetText (toUpper (ctrlText _button));
			
			//--- Host
			//_button = _display displayctrl 104;
			//_button ctrlSetText (toUpper (ctrlText _button));
			
			//--- Revert
			//_button = _display displayctrl 109;
			//_button ctrlSetText (toUpper (ctrlText _button));
			
			//--- Play/Replay
			//_button = _display displayctrl 1;
			//_button ctrlSetText (toUpper (ctrlText _button));
			
			//in demo disable Game Options button - MUF-leave the button enabled, but test that it works.
			// if( getNumber(configfile >> "isDemo") == 1 ) then
			// {
				// (_display displayctrl 307) ctrlEnable false;	//Game Options
			// };
		};
	};
	
	case "onUnload": {
	
		//MUF-not needed in A3
		// with uinamespace do {
			// RscDisplayCampaignLoad_init = nil;
			// RscDisplayCampaignLoad_initEH = nil;
		// };
		
		//in demo close SP menu, so player is moved to Main Menu immediately from campaign - Not needed anymore, commented out not to cause bug.
		// if( getNumber(configfile >> "isDemo") == 1 ) then
		// {
			// ctrlactivate ((finddisplay 140) displayctrl 2); //click on cancel in SP
		// };
	};




//////////////////////////////////////////////////////////////////////////

/*
		_this spawn {
			if (true) exitwith {};

			disableserialization;
			_mode = _this select 0;
			_params = _this select 1;
			_class = _this select 2;

			//--- Show campaign name
			_displayCampaigns = finddisplay 74;
			_campaignName = ctrltext (_displayCampaigns displayctrl 102);
			_display = _params select 0;
			_ctrlTitle = _display displayctrl 1002;
			_ctrlTitle ctrlsettext _campaignName;
[0,_display] call bis_fnc_log;

			_ctrlMissions = _display displayctrl 101;
			_ctrlMissions ctrladdeventhandler [
				"lbselchanged",
				"
					_ctrlMissions = _this select 0;
					_cursel = _this select 1;
					[_cursel,_ctrlMissions lbtext _cursel,_ctrlMissions lbdata _cursel,_ctrlMissions lbvalue _cursel] call bis_fnc_log;
				"
			];
[1,_ctrlMissions,_display] call bis_fnc_log;

			//--- Detect selected campaign
			_ctrlCampaigns = _displayCampaigns displayctrl 101;
[2,campaignconfigfile] call bis_fnc_log;
			//_campaign = (configfile >> "cfgmissions" >> "campaigns") select (lbcursel _ctrlCampaigns);


			//--- Disable 'Revert' button
			if (getnumber (_campaign >> "disableRevert") > 0) then {

				if  (distributionregion > 0) then {
					_ctrlRevert = _display displayctrl 109;
					_ctrlRevert ctrlenable false;
				};

				//--- Filter listbox
				_ctrlListbox = _display displayctrl 101;
				_index = (lbsize _ctrlListbox) - 1;
				_missionText = _ctrlListbox lbtext _index;
				_missionValue = _ctrlListbox lbvalue _index;
				_startText = _ctrlListbox lbtext 0;
				_startValue = _ctrlListbox lbvalue 0;

				lbclear _ctrlListbox;

				_lbAdd = _ctrlListbox lbadd _startText;
				_ctrlListbox lbsetvalue [_lbAdd,_startValue];
				_lbAdd = _ctrlListbox lbadd _missionText;
				_ctrlListbox lbsetvalue [_lbAdd,_missionValue];

			};
		};
	};
*/
};