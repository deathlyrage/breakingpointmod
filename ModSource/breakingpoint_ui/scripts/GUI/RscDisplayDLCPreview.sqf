#include "\a3\Ui_f\hpp\defineResinclDesign.inc"
#include "\a3\Ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"

#define COMMIT_HOVER	0.1
#define COMMIT_BROWSE	0.3
#define DELAY_CONTINUE	10

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;
scopename "RscDisplayDLCPreview";

switch _mode do
{
	case "onLoad":
	{

		_dlc = uinamespace getvariable ["RscDisplayDLCPreview_dlc",""];
		uinamespace setvariable ["RscDisplayDLCPreview_dlc",nil];
		_showCurrentAssets = _dlc == "";

		_ctrlLogo = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_LOGO;
		_ctrlBackground = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_BACKGROUND;
		_ctrlOverview = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_OVERVIEW;
		_ctrlButtonPurchase = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_BUTTONPURCHASE;
		_ctrlAuthor = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_AUTHOR;
		_ctrlButtonClose = _display displayctrl IDC_CANCEL;
		_ctrlButtonOK = _display displayctrl IDC_OK;
		_ctrlBohemia = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_BOHEMIA;

		_ctrlButtonSound ctrlenable false;

		_posY = ctrlposition _ctrlLogo select 1;
		_dlcColor = [1,1,1,1];
		_dlcColorHTML = "#ffffff";
		_sections = [];
		_appId = -1;

		if (_showCurrentAssets) then {

			//--- Show currently used assets of all DLCs
			_ctrlOverview ctrlsetstructuredtext parsetext localize "STR_A3_DLC_DEBRIEFING_TEXT_GENERIC";
			_ctrlOverview call bis_fnc_ctrlFitToTextHeight;
			_posY = (ctrlposition _ctrlOverview select 1) + (ctrlposition _ctrlOverview select 3);

			//_ctrlBohemia ctrlshow false;
			_ctrlButtonClose ctrlshow false;
			_ctrlButtonPurchase ctrlshow false;
			_ctrlButtonOK ctrlshow true;

			_ctrlBohemiaPos = ctrlposition _ctrlBohemia;
			_ctrlBohemiaPos set [0,ctrlposition _ctrlButtonClose select 0];
			_ctrlBohemia ctrlsetposition _ctrlBohemiaPos;
			_ctrlBohemia ctrlcommit 0;

			//--- Disable Escape
			_display displayaddeventhandler [
				"keydown",
				{
					params ["_display","_key"];
					if (_key == DIK_ESCAPE && {!(ctrlenabled (_display displayctrl IDC_OK))}) then {
						//--- Flash the OK button
						_ctrlButtonOK = _display displayctrl IDC_OK;
						_ctrlButtonOK ctrlsetfade 1;
						_ctrlButtonOK ctrlcommit 0;
						_ctrlButtonOK ctrlsetfade 0;
						_ctrlButtonOK ctrlcommit 0.1;
						true
					} else {
						false
					}
				}
			];

			//--- Disable OK , but enable it after delay
			_ctrlButtonOK ctrlenable false;
			_display setvariable ["timeUnlock",diag_ticktime + DELAY_CONTINUE];
			_display setvariable ["timeColor",(["IGUI","WARNING_RGB"] call bis_fnc_displayColorGet) call bis_fnc_colorRGBtoHTML];
			{
				_display displayaddeventhandler [
					_x,
					{
						params ["_display"];
						_ctrlButtonOK = _display displayctrl IDC_OK;
						if (ctrlenabled _ctrlButtonOK) exitwith {};

						_countdown = (_display getvariable ["timeUnlock",diag_ticktime]) - diag_ticktime;
						if (_countdown > 0) then {
							_ctrlButtonOK ctrlsetstructuredtext parsetext format [
								"<t color='#66ffffff'>%1</t> <t color='%3' font='RobotoCondensedBold' size='1.2'>(%2)</t>",
								toupper localize "STR_DISP_CONTINUE",
								[(ceil _countdown)/60,"HH:MM"] call bis_fnc_timeToString,
								(_display getvariable ["timeColor","#CC8000"])
							];
						} else {
							_ctrlButtonOK ctrlsettext localize "STR_DISP_CONTINUE";
							_ctrlButtonOK ctrlenable true;
						};
					}
				];
			} foreach ["mousemoving","mouseholding"];

			_appIds = [];
			{_appIds pushbackunique (_x select 1);} foreach getDLCAssetsUsage;
			{
				private _appId = getnumber (_x >> "appId");
				if (_appId in _appIds) then {	
					private _dlcColor = (_x >> "dlcColor") call bis_fnc_colorConfigToRGBA;
					private _dlcColorHTML = _dlcColor call bis_fnc_colorRGBtoHTML;
					_sections pushback [_x >> "Assets",gettext (_x >> "name"),"RscDisplayDLCPreview_ListItem",_dlcColor,_dlcColorHTML,_appId];
					if (count _appIds == 1) then {
						_logo = gettext (_x >> "logoTitle");
						_ctrlLogo ctrlsettext _logo;

						_artwork = gettext (_x >> "artwork");
						_ctrlBackground ctrlsettext _artwork;
					};
				};
			} foreach configproperties [configfile >> "CfgMods","isclass _x"];
		} else {

			//--- Show everything for the current DLC
			_cfgDlc = configfile >> "CfgMods" >> _dlc;
			if !(isclass _cfgDlc) exitwith {["Error: Class '%1' not found in CfgMods!",_dlc] call bis_fnc_error; breakto "RscDisplayDLCPreview"};

			_logo = gettext (_cfgDlc >> "logoTitle");
			_ctrlLogo ctrlsettext _logo;

			_artwork = gettext (_cfgDlc >> "artwork");
			_ctrlBackground ctrlsettext _artwork;

			_overview = gettext (_cfgDlc >> "overview");
			_ctrlOverview ctrlsetstructuredtext parsetext _overview;
			_ctrlOverview call bis_fnc_ctrlFitToTextHeight;
			_posY = (ctrlposition _ctrlOverview select 1) + (ctrlposition _ctrlOverview select 3) + GUI_GRID_H;

			_ctrlButtonPurchasePos = ctrlposition _ctrlButtonPurchase;
			_ctrlButtonPurchasePos set [1,_posY];
			_appId = getnumber (_cfgDlc >> "appId");
			if (_appId in getdlcs 0) then {

				//--- Official DLC
				_ctrlButtonPurchase ctrlsetposition _ctrlButtonPurchasePos;
				_ctrlButtonPurchase ctrlcommit 0;
				_ctrlButtonPurchase ctrlsettext localize (if (_appId in getdlcs 1) then {"STR_MOD_LAUNCHER_ACTION"} else {"STR_A3_BUTTON_PURCHASE"});
				_ctrlButtonPurchase ctrladdeventhandler ["buttonclick",{with uinamespace do {["buttonPurchase",_this,''] call RscDisplayDLCPreview_script;};}];
				_ctrlButtonPurchase setvariable ["appId",_appId];
			} else {

				//--- Unofficial mod
				_ctrlButtonPurchase ctrlshow false;
				_ctrlAuthor ctrlshow true;
				_ctrlAuthor ctrlsetposition _ctrlButtonPurchasePos;
				_ctrlAuthor ctrlcommit 0;
				[_cfgDlc,_ctrlAuthor] call bis_fnc_overviewAuthor;
			};
			_posY = _posY + (_ctrlButtonPurchasePos select 3) + GUI_GRID_H;

			_dlcColor = getarray (_cfgDlc >> "dlcColor") call bis_fnc_colorConfigToRGBA;
			_dlcColorHTML = _dlcColor call bis_fnc_colorRGBtoHTML;

			_sections = [
				[_cfgDlc >> "Assets",		localize "STR_A3_RscDisplayDLCContentBrowser_ButtonAssets",	"RscDisplayDLCPreview_ListItem"],
				[_cfgDlc >> "Singleplayer",	localize "STR_DISP_MAIN_SINGLE_PLAYER",				"RscDisplayDLCPreview_ListItem"],
				[_cfgDlc >> "Multiplayer",	localize "STR_DISP_MAIN_MULTI",					"RscDisplayDLCPreview_ListItem"],
				[_cfgDlc >> "Features",		localize "STR_A3_RSCDISPLAYWELCOME_HELI_PARC_TITLE",		"RscDisplayDLCPreview_ListItem"],
				[_cfgDlc >> "Achievements",	localize "STR_A3_RSCDISPLAYWELCOME_KART_PARC_LIST8_TITLE",	"RscDisplayDLCPreview_ListItemSquare"]
			]
		};

		_ctrlListGroup = _display displayctrl IDC_RSCDISPLAYDLCPREVIEW_LISTGROUP;
		_ctrlListGroupPos = ctrlposition _ctrlListGroup;
		_ctrlListGroupPos set [1,_posY];

		//--- Fill the list
		_pictureAchievement = gettext (configfile >> "RscDisplayDLCPreview" >> "pictureAchievement");
		_ctrlListPosY = 0;
		_allListItems = [];
		{
			_x params [
				"_cfg",
				"_title",
				"_listItemTemplate",
				["_dlcColor",_dlcColor],
				["_dlcColorHTML",_dlcColorHTML],
				["_appId",_appId]
			];
			if (isclass _cfg && {count _cfg > 0}) then {
				_ctrlList = _display ctrlcreate ["RscDisplayDLCPreview_List",-1,_ctrlListGroup];
				_ctrlListPos = ctrlposition _ctrlList;
				_ctrlListPos set [1,_ctrlListPosY];
				_ctrlList ctrlsetposition _ctrlListPos;
				_ctrlList ctrlcommit 0;

				_ctrlInfoTitle = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_INFOTITLE;
				_ctrlInfoTitle ctrlsetbackgroundcolor _dlcColor;
				_ctrlInfoTitle ctrlsettext toupper _title;

				_ctrlPictureGroup = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREGROUP;
				_ctrlPictureGroup ctrlenable false;
				_ctrlPictureListGroup = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTURELISTGROUP;

				_ctrlPictureOverlay = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREOVERLAY;
				_ctrlPictureAnimOverlay = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREANIMOVERLAY;
				{_x ctrlsettextcolor _dlcColor;} foreach [_ctrlPictureOverlay,_ctrlPictureAnimOverlay];

				_ctrlListBrowsePrev = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BROWSEPREV;
				_ctrlListBrowsePrev ctrladdeventhandler ["buttonclick",{with uinamespace do {["listItemBrowse",[ctrlParentControlsGroup (_this select 0),-1],''] call RscDisplayDLCPreview_script;};}];
				_ctrlListBrowseNext = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BROWSENEXT;
				_ctrlListBrowseNext ctrladdeventhandler ["buttonclick",{with uinamespace do {["listItemBrowse",[ctrlParentControlsGroup (_this select 0),+1],''] call RscDisplayDLCPreview_script;};}];

				_ctrlButtonTry = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BUTTONTRY;
				_ctrlButtonTry ctrladdeventhandler ["buttonclick",{with uinamespace do {["buttonTry",_this,''] spawn RscDisplayDLCPreview_script;};}];

				private _ctrlButtonPurchase = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BUTTONPURCHASE;
				_ctrlButtonPurchase ctrladdeventhandler ["buttonclick",{with uinamespace do {["buttonPurchase",_this,''] call RscDisplayDLCPreview_script;};}];
				_ctrlButtonPurchase setvariable ["appId",_appId];
				_ctrlButtonPurchase ctrlshow _showCurrentAssets;

				_ctrlListItemPosX = 0;
				_listItems = [];
				_listItemsData = [];
				{
					_dlcType = gettext (_x >> "dlcType");
					_tryAsset = getarray (_x >> "tryAsset");
					_reference = getarray (_x >> "reference");
					_model = "";
					_usageAsCount = false; //--- When true, show usage as e.g., "3x" instead of duration

					_displayName = gettext (_x >> "displayName");
					_description = gettext (_x >> "description");
					_overviewPicture = gettext (_x >> "overviewPicture");
					_achievement = gettext (_x >> "achievement");
					_achievementHidden = getnumber (_x >> "achievementHidden");

					if (count _reference > 0) then {
						_cfgListItem = [["configfile"] + _reference,configfile] call bis_fnc_configPath;
						if (isclass _cfgListItem) then {
							if (_displayName == "") then {_displayName = gettext (_cfgListItem >> "overviewName");}; //--- Get DLC browswer specific name
							if (_displayName == "") then {_displayName = gettext (_cfgListItem >> "briefingName");}; //--- Get scenario specific name
							if (_displayName == "") then {_displayName = gettext (_cfgListItem >> "displayName");}; //--- Get default name when the specific one was not found
							if (_description == "") then {_description = gettext (_cfgListItem >> "Library" >> "libTextDesc");};
							if (_description == "") then {_description = gettext (_cfgListItem >> "overviewText")};
							if (_overviewPicture == "") then {_overviewPicture = gettext (_cfgListItem >> "overviewPicture");};
							_dlcType = configsourcemod _cfgListItem;
							_model = tolower gettext (_cfgListItem >> "model");
							if (_model select [(count _model - 4)] != ".p3d") then {_model = _model + ".p3d";};
							_simulation = gettext (_cfgListItem >> "simulation");
							if (_simulation == "shotMine") then {_usageAsCount = true;};
						} else {
							["Item reference not found for %1",_dlcType] call bis_fnc_error;
						};
					};

					//--- Make sure the currently used assets are first (assets used for longer time are first; only for non-owned DLCs)
					_index = _foreachindex;
					_usageTime = if (_model != "" && {_appId in getdlcs 2}) then {(getDLCAssetsUsageByName _model param [0,0])} else {0};
					if (_usageTime > 0) then {
						_index = _index - 100 - 100 * _usageTime;
					};

					if (!_showCurrentAssets || {_showCurrentAssets && _usageTime > 0}) then {

						//--- When not found in reference configs, read properties from CfgMods
						//_isPremium = _dlcType != "";
						_isPremium = getnumber (configfile >> "CfgMods" >> _dlcType >> "appId") in (getdlcs 0);

						if (_displayName != "" && _overviewPicture != "") then {

							//--- Process achievement
							_overviewPictureColor = [1,1,1,1];
							_textPremium = localize "STR_IGUI_AVT_PREMIUM_TEXT";
							_achievementLocked = false;
							if (_achievement != "" && {getstatvalue _achievement == 0}) then {
								if (_achievementHidden > 0) then {
									_displayName = localize "str_dn_unknown";
									_description = "";
									_overviewPicture = _pictureAchievement;
								};
								_achievementLocked = true;
								_overviewPictureColor = [0.5,0.5,0.5,1];
								_textPremium = toupper localize "STR_VEHICLE_LOCKED";
							};

							//--- Convert description to structured text friendly format (old texts were plain). Not when the text is using &amp; already
							if (_description find "&amp;" < 0) then {_description = _description splitstring "&" joinstring "&amp;"};

							_info = parsetext format [
								if (_isPremium || _achievementLocked) then {
									"<t font='RobotoCondensedBold' size='1.2'>%1</t><br /><t color='%4'>%3</t><br /><br />%2"
								} else {
									"<t font='RobotoCondensedBold' size='1.2'>%1</t><br /><br />%2"
								},
								_displayName,
								_description,
								_textPremium,
								_dlcColorHTML
							];

							//--- Save to be sorted and processed
							_listItemsData pushback [_index,_overviewPicture,_info,_isPremium,_tryAsset,_model,_dlcColorHTML,_usageAsCount,_overviewPictureColor];

						} else {
							["Overview or name not configured correctly for %1",_x] call bis_fnc_error;
						};
					};
				} foreach configproperties [_cfg,"isclass _x"];

				//--- Sort
				_listItemsData sort true;

				//--- Create info boxes
				{
					_x params ["_index","_overviewPicture","_info","_isPremium","_tryAsset","_model","_dlcColorHTML","_usageAsCount","_overviewPictureColor"];
					_ctrlListItem = _display ctrlcreate [_listItemTemplate,-1,_ctrlPictureListGroup];
					_ctrlListItemPos = ctrlposition _ctrlListItem;
					_ctrlListItemPos set [0,_ctrlListItemPosX];
					_ctrlListItem ctrlsetposition _ctrlListItemPos;
					_ctrlListItem ctrlcommit 0;

					_ctrlListItemPicture = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_PICTURE;
					_ctrlListItemPicture ctrlsettext _overviewPicture;
					_ctrlListItemPicture ctrlsettextcolor _overviewPictureColor;

					_ctrlListItemSelect = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_SELECT;
					_ctrlListItemSelect ctrlsetbackgroundcolor _dlcColor;

					_ctrlListItemButton = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_BUTTON;
					_ctrlListItemButton ctrladdeventhandler ["mouseenter",{with uinamespace do {["listItemEnter",[_this select 0,false],''] call RscDisplayDLCPreview_script;};}];
					_ctrlListItemButton ctrladdeventhandler ["setfocus",{with uinamespace do {["listItemEnter",[_this select 0,true],''] call RscDisplayDLCPreview_script;};}];
					_ctrlListItemButton ctrladdeventhandler ["mouseexit",{with uinamespace do {["listItemExit",[_this select 0,false],''] call RscDisplayDLCPreview_script;};}];
					_ctrlListItemButton ctrladdeventhandler ["killfocus",{with uinamespace do {["listItemExit",[_this select 0,true],''] call RscDisplayDLCPreview_script;};}];
					_ctrlListItemButton ctrladdeventhandler ["buttonclick",{with uinamespace do {["listItemClick",_this,''] call RscDisplayDLCPreview_script;};}];
					_ctrlListItemButton setvariable ["data",[_overviewPicture,_info,_isPremium,_tryAsset,_model,_dlcColorHTML,_usageAsCount,_overviewPictureColor]];
					//if (_ctrlListItemPosX == 0) then {["listItemClick",[_ctrlListItemButton],''] call RscDisplayDLCPreview_script;};

					_ctrlListItemSessionNotification = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_SESSIONNOTIFICATION;
					if (_index < 0) then {
						_ctrlListItemSessionNotification ctrlshow true;
					};

					_listItems pushback _ctrlListItem;
					_ctrlListItemPosX = _ctrlListItemPosX + (_ctrlListItemPos select 2);
				} foreach _listItemsData;

				if (count _listItems > 0) then {

					//--- Save list items so they can be browsed through
					_ctrlList setvariable ["listItems",_listItems];
					_allListItems append _listItems;

					["listItemBrowse",[_ctrlList,0],''] call RscDisplayDLCPreview_script;
					_ctrlListPosY = _ctrlListPosY + (_ctrlListPos select 3);

					if (count _listItems == 1) then {
						_ctrlListBrowsePrev ctrlshow false;
						_ctrlListBrowseNext ctrlshow false;
					};
				} else {

					//--- No items found, delete the list
					ctrldelete _ctrlList;
				};
			};
		} foreach _sections;
		_ctrlListGroupPos set [3,_ctrlListPosY];
		_ctrlListGroup ctrlsetposition _ctrlListGroupPos;
		_ctrlListGroup ctrlcommit 0;

		_display setvariable ["allListItems",_allListItems];

		//--- Fade-in
		_fadeInDuration = if (_showCurrentAssets) then {0.5} else {0.2};
		{
			_x ctrlsetfade 1; _x ctrlcommit 0;
			_x ctrlsetfade 0; _x ctrlcommit _fadeInDuration;
		} foreach [_ctrlLogo,_ctrlOverview,_ctrlButtonPurchase,_ctrlAuthor,_ctrlListGroup];

	};
	case "listItemEnter": {
		private _ctrlListItemButton = _params select 0;
		private _ctrlListItem = ctrlParentControlsGroup _ctrlListItemButton;
		private _ctrlListItemHover = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_HOVER;

		if (_params select 1) then {["listItemClick",[_ctrlListItemButton],''] call RscDisplayDLCPreview_script;};

		["listItemClear",[ctrlparent _ctrlListItemButton],''] call RscDisplayDLCPreview_script;

		_ctrlListItemHover ctrlsetfade 0;
		_ctrlListItemHover ctrlcommit COMMIT_HOVER;
	};
	case "listItemExit": {
		private _ctrlListItemButton = _params select 0;
		private _ctrlListItem = ctrlParentControlsGroup _ctrlListItemButton;
		private _ctrlListItemHover = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_HOVER;

		_ctrlListItemHover ctrlsetfade 1;
		_ctrlListItemHover ctrlcommit COMMIT_HOVER;
	};
	case "listItemClear": {
		private _display = _params select 0;
		{
			["listItemExit",[_x controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_BUTTON],''] call RscDisplayDLCPreview_script;
		} foreach (_display getvariable ["allListItems",[]]);
	};
	case "listItemBrowse": {
		private _ctrlList = _params select 0;
		private _listItemsDeltaID = _params select 1;
		private _listItems = _ctrlList getvariable ["listItems",[]];
		private _listItemsID = _ctrlList getvariable ["listItemsID",0];
		_listItemsID = (_listItemsID + _listItemsDeltaID + (count _listItems)) % (count _listItems);
		["listItemClick",[(_listItems select _listItemsID) controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_BUTTON,_listItemsDeltaID > 0],''] call RscDisplayDLCPreview_script;
	};
	case "listItemClick": {
		_ctrlListItemButton = _params select 0;
		_ctrlListItem = ctrlParentControlsGroup _ctrlListItemButton;
		_ctrlList = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlListItem;
		_ctrlListItemSessionNotification = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_SESSIONNOTIFICATION;
		_listItems = _ctrlList getvariable ["listItems",[]];
		_listItemsID = _ctrlList getvariable ["listItemsID",-1];
		_listItemsIDNew = _listItems find _ctrlListItem;

		_data = _ctrlListItemButton getvariable ["data",["",""]];
		_data params ["_overviewPicture","_info","_isPremium","_tryAsset","_model","_dlcColorHTML","_usageAsCount","_overviewPictureColor"];

		//--- Set text
		_ctrlBackgroundBottom = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BACKGROUNDBOTTOM;
		_ctrlBackgroundBottomPos = ctrlposition _ctrlBackgroundBottom;
		_ctrlInfoGroup = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_INFOGROUP;
		_ctrlInfoGroupPos = ctrlposition _ctrlInfoGroup;
		_ctrlInfoGroupPos set [3,(_ctrlBackgroundBottomPos select 1) - (_ctrlInfoGroupPos select 1)]; //--- Reset to default pos
		_ctrlInfo = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_INFO;
		_ctrlInfo ctrlsetstructuredtext _info;
		_ctrlInfo call bis_fnc_ctrlFitToTextHeight;

		//--- Show TRY button
		_canTry = count _tryAsset > 0;
		_ctrlButtonPurchase = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BUTTONPURCHASE;
		if !(ctrlshown _ctrlButtonPurchase) then {
			_ctrlButtonTry = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_BUTTONTRY;
			{
				_x ctrlshow _canTry;
			} foreach [_ctrlButtonTry,_ctrlBackgroundBottom];
			_ctrlButtonTry setvariable ["tryAsset",_tryAsset];
		};

		//--- Show stats (only for official models)
		_showStats = _model find "a3" in [0,1];
		_ctrlInfoStats = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_INFOSTATS;
		_ctrlInfoStats ctrlshow _showStats;
		if (_showStats && _canTry) then {
			_timesArray = getDLCAssetsUsageByName _model;
			_sessionTimeText = "";
			_totalTimeText = "";
			if (_usageAsCount) then {
				_sessionTimeText = format ["%1x",_timesArray select 0];
				_totalTimeText = format ["%1x",_timesArray select 1];
			} else {
				_sessionTime = _timesArray select 0;
				_sessionTimeText = if (_sessionTime > 0) then {
					_sessionTimeArray = [_sessionTime, "HH:MM:SS",true] call bis_fnc_secondsToString;
					format ([localize "STR_A3_RSCDISPLAYDEBRIEFING_TIME_FORMAT"] + _sessionTimeArray);
				} else {
					""
				};
				_totalTime = _timesArray select 1;
				_totalTimeArray = [_timesArray select 1, "HH:MM:SS",true] call bis_fnc_secondsToString;
				_totalTimeText = format ([localize "STR_A3_RSCDISPLAYDEBRIEFING_TIME_FORMAT"] + _totalTimeArray);
			};

			_ctrlInfoStats ctrlsetstructuredtext parsetext format [
				if (isnull finddisplay IDD_MISSION || _sessionTimeText == "") then {
					//--- Show only total time when not in a mission (i.e., when session time wouldn't make sense)
					"<t size='1.0' font='RobotoCondensedLight'><t align='left' color='#99ffffff'>%1</t><t align='right' color='%5'>%3</t></t>",
				} else {
					"<t size='1.0' font='RobotoCondensedLight'><t align='left' color='#99ffffff'>%1</t><t align='right' color='%5'>%3</t><br /><t align='left' color='#99ffffff'>%2 <img image='%6' shadow='0' size='0.7' color='#ffffff' /></t><t align='right' color='%5'>%4</t></t>",
				},
				localize "STR_A3_FIRING_DRILLS_HINT_RESULTS_TOTAL",
				localize "STR_A3_TIME_TRIALS_SESSION",
				_totalTimeText,
				_sessionTimeText,
				_dlcColorHTML,
				ctrltext _ctrlListItemSessionNotification
			];
		};

		//--- Adjust text area's height
		_ctrlInfoGroup ctrlsetposition _ctrlInfoGroupPos;
		_ctrlInfoGroup ctrlcommit 0;
		_animMoveRight = _params param [1,_listItemsIDNew > _listItemsID];
		_ctrlList setvariable ["listItemsID",_listItemsIDNew];

		_ctrlPictureBackground = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREBACKGROUND;
		_ctrlPicture = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTURE;
		_ctrlPictureOverlay = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREOVERLAY;
		_ctrlPictureOverlayIcon = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREOVERLAYICON;

		_ctrlPictureAnimBackground = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREANIMBACKGROUND;
		_ctrlPictureAnim = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREANIM;
		_ctrlPictureAnimOverlay = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREANIMOVERLAY;
		_ctrlPictureAnimOverlayIcon = _ctrlList controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LIST_PICTUREANIMOVERLAYICON;

		//--- Already animating, force replace
		if (_listItemsID == _listItemsIDNew || !ctrlcommitted _ctrlList) exitwith {
			_ctrlPictureOverlay ctrlshow _isPremium;
			_ctrlPictureOverlayIcon ctrlshow _isPremium;
			_ctrlPicture ctrlsettext _overviewPicture;
		};

		//--- Animate picture
		if (ctrltext _ctrlPicture != "") then {
			_ctrlPicturePos = ctrlposition _ctrlPicture;
			_ctrlPictureAnimPos = +_ctrlPicturePos;

			//--- Replace picture with fake picture
			_ctrlPictureAnimOverlayIcon ctrlshow ctrlshown _ctrlPictureOverlayIcon;
			_ctrlPictureAnimOverlay ctrlshow ctrlshown _ctrlPictureOverlay;
			_ctrlPictureAnim ctrlsettext ctrltext _ctrlPicture;
			_ctrlPictureAnim ctrlsettextcolor (_ctrlPicture getvariable ["color",[1,1,1,1]]);
			{
				_x ctrlsetposition _ctrlPictureAnimPos;
				_x ctrlcommit 0;
			} foreach [_ctrlPictureAnimBackground,_ctrlPictureAnim,_ctrlPictureAnimOverlay,_ctrlPictureAnimOverlayIcon];

			//--- Decide in which direction to animate
			if (_animMoveRight) then {
				_ctrlPicturePos set [0,(_ctrlPicturePos select 2)];
				_ctrlPictureAnimPos set [0,-(_ctrlPicturePos select 2)];
			} else {
				_ctrlPicturePos set [0,-(_ctrlPicturePos select 2)];
				_ctrlPictureAnimPos set [0,(_ctrlPicturePos select 2)];
			};

			//--- Move picture out
			{
				_x ctrlsetposition _ctrlPicturePos;
				_x ctrlcommit 0;
			} foreach [_ctrlPictureBackground,_ctrlPicture,_ctrlPictureOverlay,_ctrlPictureOverlayIcon];
			_ctrlPicturePos set [0,0];

			//--- Animate picture in
			{
				_x ctrlsetposition _ctrlPicturePos;
				_x ctrlcommit COMMIT_BROWSE;
			} foreach [_ctrlPictureBackground,_ctrlPicture,_ctrlPictureOverlay,_ctrlPictureOverlayIcon];

			//--- Animate fake picture out
			{
				_x ctrlsetposition _ctrlPictureAnimPos;
				_x ctrlcommit COMMIT_BROWSE;
			} foreach [_ctrlPictureAnimBackground,_ctrlPictureAnim,_ctrlPictureAnimOverlay,_ctrlPictureAnimOverlayIcon];

			//--- Animate list (used fore checking if animation is already happening)
			_ctrlList ctrlcommit COMMIT_BROWSE;
		};
		_ctrlPictureOverlay ctrlshow _isPremium;
		_ctrlPictureOverlayIcon ctrlshow _isPremium;
		_ctrlPicture ctrlsettext _overviewPicture;
		_ctrlPicture ctrlsettextcolor _overviewPictureColor;
		_ctrlPicture setvariable ["color",_overviewPictureColor];

		//--- Mark as selected
		{
			_ctrlListItemSelectX = _x controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_SELECT;
			_ctrlListItemSelectX ctrlsetfade 1;
			_ctrlListItemSelectX ctrlcommit 0;
		} foreach _listItems;
		_ctrlListItemSelect = _ctrlListItem controlsgroupctrl IDC_RSCDISPLAYDLCPREVIEW_LISTITEM_SELECT;
		_ctrlListItemSelect ctrlsetfade 0;
		_ctrlListItemSelect ctrlcommit COMMIT_HOVER;
	};
	case "buttonPurchase": {
		_ctrlButtonPurchase = _params select 0;
		_appId = _ctrlButtonPurchase getvariable ["appId",-1];
		openDlcPage _appId;
	};
	case "buttonTry": {
		disableserialization;
		_ctrlButtonTry = _params select 0;
		_tryAsset = _ctrlButtonTry getvariable ["tryAsset",[]];
		if (count _tryAsset > 0) then {
			_result = [localize "STR_A3_RSCDISPLAYDLCCONTENTBROWSER_WARNING","",true,true,ctrlparent _ctrlButtonTry,true,false] call (uinamespace getvariable "bis_fnc_guiMessage");
			if (_result) then {
				_typeDefault = _tryAsset select 0;
				_classArsenal = _tryAsset select 1;
				_classGarage = _tryAsset select 2;

				//--- Convert Arsenal path to correct format
				if (_classArsenal isequaltype [] && {count _classArsenal == 2}) then {
					_classArsenal set [1,(_classArsenal select 1) apply {if (_x == "nil") then {nil} else {_x}}];
				};

				//--- Save asset path and close display with ID which RscDisplayMain can recognize to launch Arsenal
				uiNamespace setvariable ['BIS_fnc_arsenal_typeDefault',_typeDefault];
				uiNameSpace setvariable ['BIS_fnc_arsenal_defaultClass',_classArsenal];
				uiNameSpace setvariable ['BIS_fnc_garage_defaultClass',_classGarage];
				(ctrlparent _ctrlButtonTry) closeDisplay 7;
				(findDisplay IDD_DLC_CONTENTBROWSER) closeDisplay 7;
			};
		};
	};
};