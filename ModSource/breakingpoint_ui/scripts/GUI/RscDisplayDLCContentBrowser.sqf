#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	//--- Display load
	case "onLoad":
	{
		_display = _params select 0;
		//_display displayaddeventhandler ["keydown","with uinamespace do {['keyDown',_this,''] call RscDisplayDLCContentBrowser_script};"];

		//--- set player's name
		(_display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_PLAYERSNAME) ctrlSetText profileName;
		[_display, IDC_RSCDISPLAYDLCCONTENTBROWSER_PLAYERSNAME] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Set selected texts toUpper
		_toUpperArray =
		[
			IDC_RSCDISPLAYDLCCONTENTBROWSER_TITLE,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSNAME,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSPURCHASED,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_HELINAME,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIPURCHASED,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENNAME,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENPURCHASED,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLENAME,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEOVERLAY
		];

		{
			_control = _display displayctrl _x;
			_control ctrlSetText (toUpper (ctrlText _control));
		} forEach _toUpperArray;

		//--- Disable and hide General group
		_GeneralGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_GENERALGROUP;
		_GeneralGroup ctrlEnable false;
		_GeneralGroup ctrlShow false;

		//--- Hide DLC bar and logo
		// _control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCBAR;
		// _control ctrlShow false;
		// _control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCLOGO;
		// _control ctrlShow false;

		//--- Disable and hide List group
		_ListGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_LISTGROUP;
		_ListGroup ctrlenable false;
		_ListGroup ctrlshow false;

		//Karts, Heli and Marksmen button click, mouse enter and mouse exit
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSOVERLAY; //IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSLOGO;  //TEST
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['dlcButtonClicked',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseenter","with uinamespace do {['dlcButtonMouseEnter',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseexit","with uinamespace do {['dlcButtonMouseExit',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIOVERLAY;//IDC_RSCDISPLAYDLCCONTENTBROWSER_HELILOGO;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['dlcButtonClicked',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseenter","with uinamespace do {['dlcButtonMouseEnter',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseexit","with uinamespace do {['dlcButtonMouseExit',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENOVERLAY;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['dlcButtonClicked',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseenter","with uinamespace do {['dlcButtonMouseEnter',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseexit","with uinamespace do {['dlcButtonMouseExit',_this,''] call RscDisplayDLCContentBrowser_script};"];

		//Assets, SP, MP and Features button.
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONASSETS;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['tabClicked',_this,''] call RscDisplayDLCContentBrowser_script}"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONSINGLEPLAYER;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['tabClicked',_this,''] call RscDisplayDLCContentBrowser_script}"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONMULTIPLAYER;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['tabClicked',_this,''] call RscDisplayDLCContentBrowser_script}"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONFEATURES;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['tabClicked',_this,''] call RscDisplayDLCContentBrowser_script}"];

		//Buttons that open Steam overlay - DLC Bundle button and Purchase button.
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEOVERLAY;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['openSteamOverlay',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseenter","with uinamespace do {['dlcButtonMouseEnter',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control ctrladdeventhandler ["mouseexit","with uinamespace do {['dlcButtonMouseExit',_this,''] call RscDisplayDLCContentBrowser_script};"];
		_control = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONPURCHASE;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['openSteamOverlay',_this,''] call RscDisplayDLCContentBrowser_script};"];

		//--- Back button
		_control = _display displayctrl 2;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['backButtonClicked',_this,''] call RscDisplayDLCContentBrowser_script}"];

		//Start loop that regularly check the DLC ownership (user can buy while in DLC Selection part)
		uinamespace setvariable ['RscDisplayDLCContentBrowser_OwnershipCheck', true];
		[_display] spawn
		{
			disableserialization;
			_display = _this select 0;

			while {uiNamespace getVariable ["RscDisplayDLCContentBrowser_OwnershipCheck", true]} do
			{
				["checkDLCOwnership", [_display], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;
				uisleep 3;
			};
		};
	};//onLoad


	case "checkDLCOwnership":
	{
		_display = _params select 0;
		_ownedDLCs = getDlcs 1;

		{ //for each class from cfgMods
			_appId = getNumber(_x >> "appId");

			switch(_appId) do
			{
				//Kart
				case 288520: //TODO - read from config?
				{
					//_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSBACKGROUND;
					//_background ctrlSetBackgroundColor getArray(_x >> "dlcColor");
					_purchasedText = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSPURCHASED;

					if(_appId in _ownedDLCs) then
					{
						//_background ctrlSetBackgroundColor [0.65, 0.65, 0.65, 1];
						_purchasedText ctrlShow true;
					}
					else
					{
						//_background ctrlSetBackgroundColor getArray(_x >> "dlcColor");
						_purchasedText ctrlShow false;
					};
				};

				//Heli
				case 304380:
				{
					//_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIBACKGROUND;
					//_background ctrlSetBackgroundColor getArray(_x >> "dlcColor");
					_purchasedText = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIPURCHASED;

					if(_appId in _ownedDLCs) then
					{
						// _background ctrlSetBackgroundColor [0.65, 0.65, 0.65, 1];
						_purchasedText ctrlShow true;
					}
					else
					{
						// _background ctrlSetBackgroundColor getArray(_x >> "dlcColor");
						_purchasedText ctrlShow false;
					};
				};

				//Mark
				case 332350:
				{
					_purchasedText = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENPURCHASED;

					if(_appId in _ownedDLCs) then
					{
						_purchasedText ctrlShow true;
					}
					else
					{
						_purchasedText ctrlShow false;
					};
				};
			};
		} foreach ((configfile >> "CfgMods") call bis_fnc_returnChildren);
	};


	case "fillListGroup":
	{
		_display = _params select 0;
		_selectedDLC = _params select 1; 		//STRING - Must be the same as name of the class in cfgMods, i.e.: Kart, Heli, ??Mark (doesn't yet exist)
		_selectedTab = _params select 2;		//STRING - Must be the same as name of the class in cfgMods >> selectedMod, i. e. Assets, SinglePlayer, MultiPlayer, Features
		_ListGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_LISTGROUP;

		//Delete the group and create it again, so it is empty (command for clearing is not available)
		//Only group created by the script can be deleted.
		ctrlDelete _ListGroup;
		_listGroupCfg = configfile >> "RscDisplayDLCContentBrowser_ListGroup";
		_ListGroup = _display ctrlCreate ["RscControlsGroupNoHScrollbars", IDC_RSCDISPLAYDLCCONTENTBROWSER_LISTGROUP];

		_ListGroup ctrlSetPosition [getNumber(_listGroupCfg >> "x"),
					    getNumber(_listGroupCfg >> "y"),
					    getNumber(_listGroupCfg >> "w"),
					    getNumber(_listGroupCfg >> "h")];
		_ListGroup ctrlCommit 0;



		//TODO - ctrlAddToGroup copies to group - should remove the former control as well.
		//
		//From where to read data:
		//	* For each DLC from cfgMods.
		//	* Priority: 1. If reference parameter found, search in the vehicle's class.
		//	            2. If parameter (picture/name/description) is not found there, search in cfgMod's class.


		//Sum of heights of all previous items
		_totalHeight = 0;

		{ //Search Karts - Assets. _x is assets class in cfgMods
			private["_blackBackgroundCtrl","_blackBackOffset"];

			_picture = "";
			_displayName = "";
			_description = "";
			_blackBackOffset = 0;
			_totalTimeHmsArray = [];
			_sessionTimeHmsArray = [];
			_itemConfigEntry = configfile;
			_reference = [_x, "reference",[]] call bis_fnc_returnConfigEntry;	//Search the selected asset for reference parameter. If not found, return empty array.
			_tryAsset = [_x, "tryAsset",[]] call bis_fnc_returnConfigEntry;		//Search the selected asset for tryAsset parameter.

			_highlightColor = ["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet;
			_highlightColor set [3, 1]; //set alpha to 1

			if((count _reference) != 0) then
			{
				//Try to read from vehicle config
				_itemConfigEntry = [_reference, configfile] call bis_fnc_loadclass; //tries to load the class according to path in reference.

				//Assets have different parameter names than missions. MP missions are read not by reference, but only from cfgMods.
				if(_selectedTab == "SinglePlayer") then
				{
					_picture = [_itemConfigEntry, "overviewPicture", ""] call bis_fnc_returnConfigEntry;
					_displayName = [_itemConfigEntry, "briefingName", ""] call bis_fnc_returnConfigEntry;
					_description = [_itemConfigEntry, "overviewText", ""] call bis_fnc_returnConfigEntry;
				}
				else
				{
					_picture = [_itemConfigEntry, "overviewPicture", ""] call bis_fnc_returnConfigEntry;

					//First try to search for overviewName (custom name added to the asset only for the purposes
					//of DLC Content Browser and DLC Debriefing), if not found, use displayName (needed for example for
					//counting time for vest, but displaying title Grenadier).
					_displayName = [_itemConfigEntry, "overviewName", ""] call bis_fnc_returnConfigEntry;

					if(_displayName == "") then
					{
						_displayName = [_itemConfigEntry, "displayName", ""] call bis_fnc_returnConfigEntry;
					};

					_description = [_itemConfigEntry >> "Library", "libTextDesc", ""] call bis_fnc_returnConfigEntry;

					//Item statistics (Only in assets tab)
					if(_selectedTab == "Assets") then
					{
						_model = [_itemConfigEntry, "model", ""] call bis_fnc_returnConfigEntry;

						//A3 allows the path to model to omit .p3d - if the extension is missing, add it.
						if(_model select [(count _model - 4)] != ".p3d") then
						{
							_model = _model + ".p3d";
						};

						_timesArray = getDLCAssetsUsageByName _model;
						_sessionTimeHmsArray = [_timesArray select 0, "HH:MM:SS", true] call bis_fnc_secondsToString;
						_totalTimeHmsArray = [_timesArray select 1, "HH:MM:SS", true] call bis_fnc_secondsToString;
					};
				};
			};

			//If reference or the parameter was not found read from cfgMods
			if((count _reference == 0) || (_picture == "")) then
			{
				_picture = gettext(_x >> "overviewPicture");
			};

			if((count _reference) == 0 || _displayName == "") then
			{
				_displayName = gettext(_x >> "displayName");
			};

			if((count _reference) == 0 || _description == "") then
			{
				_description = gettext(_x >> "description");
			};

			//_itemNumber = _forEachIndex; //number of config item processed by the outer forEach
			//_blackBackgroundCtrl = -1; //for storing the control handle of the black background

			//?? TODO - Add IDC increment (maybe not necessary).
			{ //Item creation
				private["_newControl"];

				_idc = getNumber(_x >> "idc");
				_parentClass = configName(inheritsFrom _x);

				_posX = getNumber(_x >> "x");
				//Y needs to be computed from Y and H of the previous item, since height changes dynamically with description height.
				_posY = _totalHeight + getNumber(_x >> "y");
				_posW = getNumber(_x >> "w");
				_posH = getNumber(_x >> "h");

				_newControl = _display ctrlCreate [_parentClass, _idc, _ListGroup];
				_newControl ctrlSetPosition [_posX, _posY, _posW, _posH];
				_newControl ctrlCommit 0;

				//Background (more items)
				_colorBackground = getArray(_x >> "colorBackground");
				if(count _colorBackground == 4) then
				{
					_newControl ctrlSetBackgroundColor _colorBackground;
				};

				//Black background - uses height of description text
				if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMBACKGROUNDBLACK) then
				{
					//Store handle of the black background control, so its height could be adjusted according to description height.
					//Since description is defined after black background, description will be processed later.
					_blackBackgroundCtrl = _newControl;
				};

				//Picture
				if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMPICTURE) then
				{
					_newControl ctrlSetText _picture;
				};

				//Name
				if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMNAME) then
				{
					_newControl ctrlSetText _displayName;
					_newControl ctrlSetTextColor _highlightColor;
				};

				//Statistics - Fill with text only if reference was found (see above)
				if(_selectedTab == "Assets") then
				{
					//Session statistic
					if(count _sessionTimeHmsArray > 0) then
					{
						if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMTEXTSESSIONTIME) then
						{
							_newControl ctrlSetText (localize "STR_A3_TIME_TRIALS_SESSION");
						};

						if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMSESSIONTIME) then
						{
							_newControl ctrlSetText (format[localize "STR_A3_RSCDISPLAYDEBRIEFING_TIME_FORMAT", _sessionTimeHmsArray select 0, _sessionTimeHmsArray select 1, _sessionTimeHmsArray select 2]);
							_newControl ctrlSetTextColor _highlightColor;
						};
					};

					//Total statistic
					if(count _totalTimeHmsArray > 0) then
					{
						if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMTEXTTOTALTIME) then
						{
							_newControl ctrlSetText (localize "STR_A3_FIRING_DRILLS_HINT_RESULTS_TOTAL");
						};

						if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMTOTALTIME) then
						{
							_newControl ctrlSetText (format[localize "STR_A3_RSCDISPLAYDEBRIEFING_TIME_FORMAT", _totalTimeHmsArray select 0, _totalTimeHmsArray select 1, _totalTimeHmsArray select 2]);
							_newControl ctrlSetTextColor _highlightColor;
						};
					};
				};

				//Try button
				if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONTRY) then
				{
					//Assets tab selected and item has assets for trying in Arsenal properly defined.
					if((_selectedTab == "Assets") && (count _tryAsset == 3)) then
					{
						_blackBackOffset = 1.2 * GUI_GRID_CENTER_H;
						_newControl ctrlSetText (localize "STR_A3_RSCDISPLAYARSENAL_BUTTONOK");

						//Launching of Arsenal is handled in RscDisplayMain.sqf, OnChildDestroyed
						_showArsenal = _tryAsset select 0;	//0-Arsenal, 1-Garage
						_assetArsenal = _tryAsset select 1;
						_assetGarage = _tryAsset select 2;

						//Arsenal asset could be Array or String, see Arsenal documentation.
						if( (typeName _assetArsenal == "ARRAY") && {(count _assetArsenal) == 2} ) then
						{
							//Array - String(soldier's class), Array(specific items)
							_assetArsenalItems = _assetArsenal select 1;

							if (typeName _assetArsenalItems == "ARRAY") then
							{
								//nil is converted to String while being read from config. Convert back to nil.
								{
									if (_x isequalto "nil") then
									{
										_assetArsenalItems set [_forEachIndex, nil];
									};
								} foreach _assetArsenalItems;
							};
						}
						else
						{
							//Only soldier class as a string.
							_assetArsenal = str _assetArsenal;
						};

						_newControl ctrladdeventhandler ["buttonclick", format ["
							[%1,%2,%3] spawn
							{
								disableserialization;
								_result = true;
								_showArsenal = _this select 0;
								_assetArsenal = _this select 1;
								_strAssetGarage = _this select 2;

								if( time > 0 && !isnull([] call bis_fnc_displayMission) ) then
								{
									_result = [localize 'STR_A3_RSCDISPLAYDLCCONTENTBROWSER_WARNING','', true, true, (findDisplay 174), true, false] call bis_fnc_guiMessage;
								};

								if(_result) then
								{
									uiNamespace setvariable ['BIS_fnc_arsenal_typeDefault', _showArsenal];
									uiNameSpace setvariable ['BIS_fnc_arsenal_defaultClass', _assetArsenal];
									uiNameSpace setvariable ['BIS_fnc_garage_defaultClass', _strAssetGarage];
									(findDisplay 174) closeDisplay 7;
								};
							};
						", _showArsenal, _assetArsenal, str _assetGarage]];
					}
					else
					{
						_newControl ctrlShow false;
					};
				};

				//Description - must be processed last, since it changes _totalHeight
				if(_idc == IDC_RSCDISPLAYDLCCONTENTBROWSER_ITEMDESCRIPTION) then
				{
					_newControl ctrlSetText _description;
					//Only description should change its height according to textHeight.
					_posH = ctrlTextHeight _newControl;
					_newControl ctrlSetPosition [_posX, _posY, _posW, _posH];
					_newControl ctrlCommit 0;

					//1.4-title+spaces, 4.4-semi transparent background - TODO: read from config
					//_blackBackH = (_posH + (1.4 * GUI_GRID_CENTER_H)) max (4.4 * GUI_GRID_CENTER_H); //1.4-title+spaces, 4.4-semi transparent background - TODO: read from config
					_blackBackH = (_posH + (1.4 * GUI_GRID_CENTER_H)) max (4.4 * GUI_GRID_CENTER_H + _blackBackOffset);
					_blackBackPos = ctrlPosition _blackBackgroundCtrl;
					_blackBackgroundCtrl ctrlSetPosition [_blackBackPos select 0, _blackBackPos select 1, _blackBackPos select 2, _blackBackH];
					_blackBackgroundCtrl ctrlCommit 0;

					_totalHeight = _totalHeight + _blackBackH + (0.5 * GUI_GRID_CENTER_H); //Spacing 0.5
				};
			} foreach ((configfile >> "RscDisplayDLCContentBrowser_ItemTemplate") call bis_fnc_returnChildren);
		} foreach ((configfile >> "CfgMods" >> _selectedDLC >> _selectedTab) call bis_fnc_returnChildren);
	}; //Fill ListGroup


	case "dlcButtonMouseEnter":
	{
		private ["_dlcColor","_logo","_name","_background","_dlcOverlay","_display"];
		_dlcOverlay = _params select 0;
		_display = ctrlparent _dlcOverlay;

		switch (ctrlIDC _dlcOverlay) do
		{
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Kart" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSLOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSNAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Heli" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELILOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELINAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Mark" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENLOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENNAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "DLCBundle" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLELOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLENAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEBACKGROUND;
			};
		};

		_logo ctrlSetTextColor _dlcColor;
		_name ctrlSetTextColor _dlcColor;
		_background ctrlSetBackgroundColor [1,1,1,1];
	};

	case "dlcButtonMouseExit":
	{
		private ["_dlcColor","_logo","_name","_background","_dlcOverlay","_display"];
		_dlcOverlay = _params select 0;
		_display = ctrlparent _dlcOverlay;

		switch (ctrlIDC _dlcOverlay) do
		{
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Kart" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSLOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSNAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Heli" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELILOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELINAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "Mark" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENLOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENNAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENBACKGROUND;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEOVERLAY:
			{
				_dlcColor = getarray(configfile >> "CfgMods" >> "DLCBundle" >> "dlcColor");
				_logo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLELOGO;
				_name = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLENAME;
				_background = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEBACKGROUND;
			};
		};

		_logo ctrlSetTextColor [1,1,1,1];
		_name ctrlSetTextColor [1,1,1,1];
		_background ctrlSetBackgroundColor _dlcColor;
	};

	case "dlcButtonClicked":
	{
		_dlcButton = _params select 0;
		_display = ctrlparent _dlcButton;
		_GeneralGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_GENERALGROUP;
		_ListGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_LISTGROUP;
		_DLCSelectionGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCSELECTIONGROUP;
		_assetsButton = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONASSETS;
		_spButton = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONSINGLEPLAYER;
		_mpButton = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONMULTIPLAYER;
		_featuresButton = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONFEATURES;
		_backButton = _display displayctrl 2;
		_purchaseButton = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONPURCHASE;
		_dlcOverviewPicture = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_OVERVIEWPICTURE;
		_dlcOverviewName = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_OVERVIEWDLCNAME;
		_dlcOverviewText = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_OVERVIEWTEXT;
		//_dlcBar = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCBAR;
		//_dlcLogo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCLOGO;

		//--- Hide DLCSelectionGroup
		_DLCSelectionGroup ctrlenable false;
		_DLCSelectionGroup ctrlshow false;

		//--- Show GeneralGroup
		_GeneralGroup ctrlenable true;
		_GeneralGroup ctrlshow true;

		//--- Show ListGroup
		_ListGroup ctrlenable true;
		_ListGroup ctrlshow true;

		_backButton ctrlSetText (localize "STR_DISP_BACK");

		switch (ctrlIDC _dlcButton) do
		{
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSOVERLAY: //IDC_RSCDISPLAYDLCCONTENTBROWSER_KARTSLOGO: //TEST
			{
				uiNamespace setVariable ["RscDisplayDLCContentBrowser_selectedDLC", "Kart"];
				_dlcOverviewName ctrlSetText (localize "STR_A3_TIME_TRIALS_KARTS_NAME");
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_HELIOVERLAY:
			{
				uiNamespace setVariable ["RscDisplayDLCContentBrowser_selectedDLC", "Heli"];
				_dlcOverviewName ctrlSetText (localize "STR_A3_TIME_TRIALS_HELI_NAME");
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_MARKSMENOVERLAY:
			{
				uiNamespace setVariable ["RscDisplayDLCContentBrowser_selectedDLC", "Mark"];
				_dlcOverviewName ctrlSetText (localize "STR_A3_RSCDISPLAYDEBRIEFING_DLCBUTTONMARKSMEN");
			};
		};

		_selectedDLC = uiNamespace getVariable ["RscDisplayDLCContentBrowser_selectedDLC", "Kart"];

		//If DLC is owned, change text of button to WEBSITE.
		if(getNumber(configfile >> "CfgMods" >> _selectedDLC >> "appId") in (getDLCs 1)) then
		{
			_purchaseButton ctrlSetText (localize "STR_MOD_LAUNCHER_ACTION");
		}
		else
		{
			_purchaseButton ctrlSetText (localize "STR_A3_BUTTON_PURCHASE");
		};

		//Fill the DLC picture and overview text
		_dlcOverviewPicture ctrlSetText gettext(configfile >> "CfgMods" >> _selectedDLC >> "contentBrowserPicture");
		_dlcOverviewText ctrlSetText gettext(configfile >> "CfgMods" >> _selectedDLC >> "overview");
		//Set colour to DLC name
		_highlightColor = ["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet;
		_highlightColor set [3, 1]; //set alpha to 1
		_dlcOverviewName ctrlSetTextColor _highlightColor;

		//--- Set values to and show DLC bar and logo
		// _dlcBar ctrlSetBackgroundColor getarray(configfile >> "CfgMods" >> _selectedDLC >> "dlcColor");
		// _dlcBar ctrlShow true;
		// _dlcLogo ctrlSetText gettext(configfile >> "CfgMods" >> _selectedDLC >> "logo");
		// _dlcLogo ctrlShow true;

		//Check what tabs should be disabled
		if(count((configfile >> "CfgMods" >> _selectedDLC >> "Assets") call bis_fnc_returnChildren) == 0) then
		{
			_assetsButton ctrlEnable false;
		}
		else
		{
			_assetsButton ctrlEnable true;
		};

		if(count((configfile >> "CfgMods" >> _selectedDLC >> "SinglePlayer") call bis_fnc_returnChildren) == 0) then
		{
			_spButton ctrlEnable false;
		}
		else
		{
			_spButton ctrlEnable true;
		};

		if(count((configfile >> "CfgMods" >> _selectedDLC >> "MultiPlayer") call bis_fnc_returnChildren) == 0) then
		{
			_mpButton ctrlEnable false;
		}
		else
		{
			_mpButton ctrlEnable true;
		};

		if(count((configfile >> "CfgMods" >> _selectedDLC >> "Features") call bis_fnc_returnChildren) == 0) then
		{
			_featuresButton ctrlEnable false;
		}
		else
		{
			_featuresButton ctrlEnable true;
		};

		//Simulate click on Assets button (Assets tab should be selected and listed). -- TODO-Find enabled button, since assets may be disabled.
		['tabClicked', [_assetsButton], ''] spawn RscDisplayDLCContentBrowser_script;
	};

	case "backButtonClicked":
	{
		_backButton = _params select 0;
		_display = ctrlparent _backButton;
		_GeneralGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_GENERALGROUP;
		_ListGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_LISTGROUP;
		_DLCSelectionGroup = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCSELECTIONGROUP;
		//_dlcBar = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCBAR;
		//_dlcLogo = _display displayctrl IDC_RSCDISPLAYDLCCONTENTBROWSER_DLCLOGO;

		if(ctrlEnabled _GeneralGroup) then
		{
			//--- Hide GeneralGroup
			_GeneralGroup ctrlenable false;
			_GeneralGroup ctrlshow false;

			//--- Hide ListGroup
			_ListGroup ctrlenable false;
			_ListGroup ctrlshow false;

			//--- Hide DLC bar and logo
			//_dlcBar ctrlShow false;
			//_dlcLogo ctrlShow false;

			//--- Show DLCSelectionGroup
			_DLCSelectionGroup ctrlenable true;
			_DLCSelectionGroup ctrlshow true;

			//Perform ownership check
			["checkDLCOwnership", [_display], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;

			_backButton ctrlSetText (localize "STR_DISP_CLOSE");
			true; //return true, so the dialogue isn't closed
		};
	};

	//Used with all four tabs
	case "tabClicked":
	{
		disableserialization;
		_tabButton = _params select 0;
		_display = ctrlparent _tabButton;
		_selectedDLC = uiNamespace getVariable ["RscDisplayDLCContentBrowser_selectedDLC", "Kart"];

		//Set highlight to proper tab
		_tabButtonsIDCs =
		[
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONASSETS,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONSINGLEPLAYER,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONMULTIPLAYER,
			IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONFEATURES
		];

		{
			if(_x != ctrlIDC _tabButton) then
			{
				_unselectedTabButton = _display displayctrl _x;
				_unselectedTabButton ctrlSetBackgroundColor [0,0,0,1];
				_unselectedTabButton ctrlSetTextColor [1,1,1,1];
			};
		} forEach _tabButtonsIDCs;

		_tabButton ctrlSetBackgroundColor [1,1,1,1];
		_tabButton ctrlSetTextColor [0,0,0,1];

		switch (ctrlIDC _tabButton) do
		{
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONASSETS:
			{
				["fillListGroup", [_display, _selectedDLC, "Assets"], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONSINGLEPLAYER:
			{
				["fillListGroup", [_display, _selectedDLC, "SinglePlayer"], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONMULTIPLAYER:
			{
				["fillListGroup", [_display, _selectedDLC, "MultiPlayer"], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;
			};
			case IDC_RSCDISPLAYDLCCONTENTBROWSER_BUTTONFEATURES:
			{
				["fillListGroup", [_display, _selectedDLC, "Features"], "RscDisplayDLCContentBrowser"] call RscDisplayDLCContentBrowser_script;
			};
		};
	};

	case "openSteamOverlay":
	{
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		if(ctrlIDC _ctrl == IDC_RSCDISPLAYDLCCONTENTBROWSER_BUNDLEOVERLAY) then
		{
			//Bundle button clicked
			openDlcPage getNumber(configfile >> "CfgMods" >> "DLCBundle" >> "appId");
		}
		else
		{
			//Purchase button clicked
			_selectedDLC = uiNamespace getVariable ["RscDisplayDLCContentBrowser_selectedDLC", "DLCBundle"];
			openDlcPage getNumber(configfile >> "CfgMods" >> _selectedDLC >> "appId");
		};
	};

	case "keyDown":
	{
		_display = _params select 0;
		_key = _params select 1;
		_shift = _params select 2;

		//SHIFT+P
		if(_shift && _key == 0x19) then
		{
			_display closeDisplay 2;
		};
	};

	case "onUnload":
	{
		//Stop the ownership check
		uinamespace setvariable ['RscDisplayDLCContentBrowser_OwnershipCheck', false];
	};
};