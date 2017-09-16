#include "\A3\ui_f\hpp\defineCommonGrids.inc"

disableSerialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		//--- Remove blur (for better scene preview)
		'dynamicBlur' ppEffectAdjust [0];
		'dynamicBlur' ppEffectCommit 0.0;
		'dynamicBlur' ppEffectEnable false;
		
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 8434) ctrlSetText profileName;
		[_display, 8434] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Sets all texts toUpper
		["RscDisplayOptionsVideo",["RscText","RscTitle","CA_TextFillRate","CA_TextDisplayMode","TextBloom"],
					  ["PlayersName"]] call bis_fnc_toUpperDisplayTexts;

		
		//--- Hide button
		_control = _display displayctrl 2406; //1703 was replaced by 2406
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['hide',_this,''] call RscDisplayOptionsVideo_script};"];
		
		//--- General button (was Basic)
		_control = _display displayctrl 8431;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['basic',_this,''] call RscDisplayOptionsVideo_script};"];
		//--- Set focus to GENERAL button
		//ctrlSetFocus _control;
		_control ctrlSetBackgroundColor [1,1,1,1];
		_control ctrlSetTextColor [0,0,0,1];
		
		//--- AA&PP button (was Rendering)
		_control = _display displayctrl 8432;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['rendering',_this,''] call RscDisplayOptionsVideo_script};"];
		
		//--- Display button (was Quality)
		_control = _display displayctrl 8433;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['quality',_this,''] call RscDisplayOptionsVideo_script};"];

		//--- Action when Resolution, Aspect ratio, Window mode and UI Size listboxes changed (engine performs reset of coordinates).
		{
			_ctrlListbox = _display displayctrl _x;
			_ctrlListbox ctrladdeventhandler ["lbselchanged","with uinamespace do {['reset',ctrlparent (_this select 0),'RscDisplayOptionsVideo'] spawn RscDisplayOptionsVideo_script};"];
		} foreach [134,136,113,1131];
		
		//--- Switching content of the right panel (buttons Basic, Rendering, Quality)
		with uinamespace do {
			//--- Disable Rendering
			_RenderingGroup = _display displayctrl 2301;
			_RenderingGroup ctrlenable false;
			_RenderingGroup ctrlshow false;
			
			//--- Disable Quality
			_QualityGroup = _display displayctrl 2302;
			_QualityGroup ctrlenable false;
			_QualityGroup ctrlshow false;
			
			//Remember state of UI size ComboBox and check for changes onUnload
			uinamespace setvariable ["RscDisplayOptionsVideoUIsize", lbCurSel (_display displayctrl 136)];
		};

		//--- Clear custom GUI effects
		with missionnamespace do {
			if !(isnil "optionsMenuOpened") then {
				[] spawn optionsMenuOpened;
			};
		};
	};

	case "hide": {

		//--- Clicked on 'Hide' button
		_display = ctrlParent (_params select 0);

		_cfgControls = configfile >> "RscDisplayOptionsVideo" >> "controls";
		_cfgControlsBackground = configfile >> "RscDisplayOptionsVideo" >> "controlsbackground";

		{
			_cfg = _x;
			for "_i" from 0 to (count _cfg - 1) do {
				_current = _cfg select _i;
				if (isclass _current) then {
					if !( (getnumber (_current >> "idc")) == 1 ||		//configname (inheritsfrom _current) == "RscShortcutButton"
					     (getnumber (_current >> "idc")) == 2 ||		//Don't hide buttons at the bottom
					     (getnumber (_current >> "idc")) == 1291 ||
					     (getnumber (_current >> "idc")) == 2406
					) then { 
						_idc = getnumber (_current >> "idc");
						_control = _display displayctrl _idc;
						_fade = round (ctrlfade _control + 1) % 2;
						_control ctrlsetfade _fade;
						_control ctrlcommit 0.2;
					};
				};
			};
		} foreach [_cfgControls,_cfgControlsBackground];
		
		//--- change text of the button (SHOW/HIDE) according to fade of video options title
		_ctrlHide = _display displayctrl 2406;
		if ( (ctrlfade (_display displayctrl 1000)) < 0.5  ) then
		{
			_ctrlHide ctrlsettext toUpper(localize "STR_CA_SHOW");
		}
		else
		{
			_ctrlHide ctrlsettext toUpper(localize "STR_CA_HIDE");
		};
	};
	
	//--- Basic button
	case "basic": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_BasicGroup = _display displayctrl 2300;
		_RenderingGroup = _display displayctrl 2301;
		_QualityGroup = _display displayctrl 2302;
		_ctrlBasic = _display displayctrl 8431; //BASIC button
		
		//--- Enable Basic
		_BasicGroup ctrlenable true;
		_BasicGroup ctrlshow true;
		
		//--- Disable Rendering
		_RenderingGroup ctrlenable false;
		_RenderingGroup ctrlshow false;
		
		//--- Disable Quality
		_QualityGroup ctrlenable false;
		_QualityGroup ctrlshow false;
		
		//--- Set focus to BASIC button
		//ctrlSetFocus _ctrlBasic;
		
		//Test - highlight the selected tab (change background and text colours of all tabs)
		_GeneralButton = _display displayctrl 8431;
		_DisplayButton = _display displayctrl 8433;
		_AAPPButton = _display displayctrl 8432;
		
		_GeneralButton ctrlSetBackgroundColor [1,1,1,1];
		_GeneralButton ctrlSetTextColor [0,0,0,1];
		
		_DisplayButton ctrlSetBackgroundColor [0,0,0,1];
		_DisplayButton ctrlSetTextColor [1,1,1,1];
		
		_AAPPButton ctrlSetBackgroundColor [0,0,0,1];
		_AAPPButton ctrlSetTextColor [1,1,1,1];
		
	};
	
	//--- AAPP button (was Rendering)
	case "rendering": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_BasicGroup = _display displayctrl 2300;
		_RenderingGroup = _display displayctrl 2301;
		_QualityGroup = _display displayctrl 2302;
		_ctrlRendering = _display displayctrl 8432; //RENDERING button
		
		//--- Enable Rendering
		_RenderingGroup ctrlenable true;
		_RenderingGroup ctrlshow true;
		
		//--- Disable Basic
		_BasicGroup ctrlenable false;
		_BasicGroup ctrlshow false;
		
		//--- Disable Quality
		_QualityGroup ctrlenable false;
		_QualityGroup ctrlshow false;
		
		//--- Set focus to RENDERING button
		//ctrlSetFocus _ctrlRendering;
		
		//Test - highlight the selected tab (change background and text colours of all tabs)
		_GeneralButton = _display displayctrl 8431;
		_DisplayButton = _display displayctrl 8433;
		_AAPPButton = _display displayctrl 8432;
		
		_GeneralButton ctrlSetBackgroundColor [0,0,0,1];
		_GeneralButton ctrlSetTextColor [1,1,1,1];
		
		_DisplayButton ctrlSetBackgroundColor [0,0,0,1];
		_DisplayButton ctrlSetTextColor [1,1,1,1];
		
		_AAPPButton ctrlSetBackgroundColor [1,1,1,1];
		_AAPPButton ctrlSetTextColor [0,0,0,1];
	};
	
	//--- Display button (was Quality)
	case "quality": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_BasicGroup = _display displayctrl 2300;
		_RenderingGroup = _display displayctrl 2301;
		_QualityGroup = _display displayctrl 2302;
		_ctrlQuality = _display displayctrl 8433; //QUALITY button
		
		//--- Enable Quality
		_QualityGroup ctrlenable true;
		_QualityGroup ctrlshow true;
		
		//--- Disable Basic
		_BasicGroup ctrlenable false;
		_BasicGroup ctrlshow false;
		
		//--- Disable Rendering
		_RenderingGroup ctrlenable false;
		_RenderingGroup ctrlshow false;	
		
		//--- Set focus to QUALITY button
		//ctrlSetFocus _ctrlQuality;
		
		//Test - highlight the selected tab (change background and text colours of all tabs)
		_GeneralButton = _display displayctrl 8431;
		_DisplayButton = _display displayctrl 8433;
		_AAPPButton = _display displayctrl 8432;
		
		_GeneralButton ctrlSetBackgroundColor [0,0,0,1];
		_GeneralButton ctrlSetTextColor [1,1,1,1];
		
		_DisplayButton ctrlSetBackgroundColor [1,1,1,1];
		_DisplayButton ctrlSetTextColor [0,0,0,1];
		
		_AAPPButton ctrlSetBackgroundColor [0,0,0,1];
		_AAPPButton ctrlSetTextColor [1,1,1,1];
	};
	
	case "reset": {

		startloadingscreen [""];		

		//--- Resize the display accoridng to selected values
		_display = _params;

		_cfgControls = configfile >> _class >> "controls";
		_cfgControlsBackground = configfile >> _class >> "controlsbackground";

		with (uinamespace) do {
			{
				_cfg = _x;
				for "_i" from 0 to (count _cfg - 1) do {
					_current = _cfg select _i;
					
					if (isclass _current) then {
						
					
						_idc = getnumber (_current >> "idc");
						_sizeEx = (_current >> "sizeEx") call bis_fnc_parsenumber;
						_control = _display displayctrl _idc;
						_control ctrlsetfontheight _sizeEx;
						_x = (_current >> "x") call bis_fnc_parsenumber;
						_y = (_current >> "y") call bis_fnc_parsenumber;
						_w = (_current >> "w") call bis_fnc_parsenumber;
						_h = (_current >> "h") call bis_fnc_parsenumber;
						_control ctrlsetposition [_x,_y,_w,_h];
						_control ctrlcommit 0;
					};
				};

			} foreach [_cfgControls,_cfgControlsBackground];
			
			
			//if resetting keep accordion expanded (i.e. move certain buttons up) in Main Menu, Pause Menu, MP Pause Menu, Video Pause Menu
			
			//Reset of accordion in Main Menu
			if((_this select 2) == "RscDisplayMain") then
			{
				debuglog "Resetting Main menu. Expanding options in accordion again.";
				
				//Reposition all buttons when reset is done-------------------------------------------------
				//TEST-commented out since demo and dev should behave the same way
				// if( getNumber(configfile >> "isDemo") == 1 ) then
				// {
					// _displayMainMenu = findDisplay 0;
		
					// //Play Spotlight button isn't present, so move logo and title down
					// //Game Logo
					// _control = _displayMainMenu displayctrl 1202;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (11.5 * GUI_GRID_H + GUI_GRID_Y)]; //10.4
					// _control ctrlCommit 0;
					
					// //Title background
					// _control = _displayMainMenu displayctrl 1050;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (15.3 * GUI_GRID_H + GUI_GRID_Y)]; //14.2
					// _control ctrlCommit 0;
					
					// //Title
					// _control = _displayMainMenu displayctrl 1003;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (15.3 * GUI_GRID_H + GUI_GRID_Y)]; //14.2
					// _control ctrlCommit 0;
					
					// //Player's name
					// _control = _displayMainMenu displayctrl 109;
					// _control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (15.3 * GUI_GRID_H + GUI_GRID_Y)]; //14.2
					// _control ctrlCommit 0;
					
					// //Play button
					// _control = _displayMainMenu displayctrl 138;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Editor button
					// _control = _displayMainMenu displayctrl 142;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (17.5 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Options button
					// _control = _displayMainMenu displayctrl 102;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (18.6 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Field Manual button
					// _control = _displayMainMenu displayctrl 2417;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (19.7 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
				// };
				//Reposition all buttons when reset is done-------------------------------------------------	
				
				//If Options were expanded before reset, expand it again
				if(uiNamespace getvariable "BIS_MainMenu_isOptionsExpanded") then
				{
					uiNamespace setVariable ["BIS_MainMenu_isOptionsExpanded", false];			//set it to false to tell the script the current state. It will expand the options.
					['optionsButton', [(findDisplay 0) displayctrl 102], ''] call RscDisplayMain_script; 	//simulate click on Options button
				};
				
				//If Play was expanded before reset, expand it again
				if(uiNamespace getvariable "BIS_MainMenu_isPlayExpanded") then
				{
					uiNamespace setVariable ["BIS_MainMenu_isPlayExpanded", false];				//set it to false to tell the script the current state. It will expand play.
					['playButton', [(findDisplay 0) displayctrl 138], ''] call RscDisplayMain_script; 	//simulate click on Play button
				};
				

				////Expand accordion, Options buttons will will remain visible
				
				// _display = findDisplay 0;  //use Main Menu

				////Game Logo
				// _control = _display displayctrl 1202;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (2 * GUI_GRID_H + GUI_GRID_Y)];
				// _control ctrlCommit 0;
				
				////Title background
				// _control = _display displayctrl 1050;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (7.6 * GUI_GRID_H + GUI_GRID_Y), (15 * GUI_GRID_W), (GUI_GRID_H)];
				// _control ctrlCommit 0;
				
				////Title
				// _control = _display displayctrl 1003;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (7.6 * GUI_GRID_H + GUI_GRID_Y), 5 * GUI_GRID_W, GUI_GRID_H];
				// _control ctrlCommit 0;
				
				////Player's name
				// _control = _display displayctrl 109;
				// _control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (7.6 * GUI_GRID_H + GUI_GRID_Y), 10 * GUI_GRID_W, GUI_GRID_H];
				// _control ctrlCommit 0;
				
				////Play button
				////E3--------------------
				// if( getNumber(configfile >> "isDemo") == 1 ) then
				// {
					////PLUG IN AS SOON AS playMission command works
					// _control = _display displayctrl 190; //E3 Play
					////_control = _display displayctrl 138; //Normal Play
				// }
				// else
				// {
					// _control = _display displayctrl 138; //Normal Play
				// };
				////E3--------------------
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (8.7 * GUI_GRID_H + GUI_GRID_Y), 15 * GUI_GRID_W, GUI_GRID_H];
				// _control ctrlCommit 0;
				
				////Editor button
				// _control = _display displayctrl 142;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y), 15 * GUI_GRID_W, GUI_GRID_H];
				// _control ctrlCommit 0;
				
				////Profile button
				// _control = _display displayctrl 1001;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y), 15 * GUI_GRID_W, GUI_GRID_H];
				// _control ctrlCommit 0;
				
				////Options button
				// _control = _display displayctrl 102;
				// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12 * GUI_GRID_H + GUI_GRID_Y), (15 * GUI_GRID_W), (GUI_GRID_H)];
				// _control ctrlCommit 0;	
			};
			
			//Reset of Pause Menu
			if((_this select 2) == "RscDisplayInterrupt") then
			{
				debuglog "Resetting Pause Menu. Expanding options in accordion again.";
				
				//If Options in the Pause Menu were expanded before reset, expand it again
				if(uiNamespace getvariable "BIS_DisplayInterrupt_isOptionsExpanded") then
				{
					uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", false];			//set it to false to tell the script the current state. It will expand the options.
					['optionsButton', [(findDisplay 49) displayctrl 101], ''] call RscDisplayInterrupt_script; 	//simulate click on Options button
				};
				
				//_display = findDisplay 49;  //use Pause Menu (has same IDD as MP Pause menu and Video pause menu)
				
				
				//expand accordion and show buttons
				/*
				//Title background
				_control = _display displayctrl 1050;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Title - same position as title background
				_control = _display displayctrl 523;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Player's name - same position as title background
				_control = _display displayctrl 109;
				_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Continue button
				_control = _display displayctrl 2;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Save button
				_control = _display displayctrl 103;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.0 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Skip button - same position as Save
				_control = _display displayctrl 1002;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.0 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Revert
				_control = _display displayctrl 119;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Again - same position as Revert
				_control = _display displayctrl 1003;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Options button
				_control = _display displayctrl 101;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;

				//Enable and show buttons
				(_display displayctrl 301) ctrlEnable true;	//Video
				(_display displayctrl 302) ctrlEnable true;	//Audio
				(_display displayctrl 303) ctrlEnable true;	//Controls
				(_display displayctrl 307) ctrlEnable true;	//Game Options
				
				//--- Show all buttons from Options
				(_display displayctrl 301) ctrlSetFade 0;	//Video
				(_display displayctrl 302) ctrlSetFade 0;	//Audio
				(_display displayctrl 303) ctrlSetFade 0;	//Controls
				(_display displayctrl 307) ctrlSetFade 0;	//Game Options
				
				(_display displayctrl 301) ctrlCommit 0;
				(_display displayctrl 302) ctrlCommit 0;
				(_display displayctrl 303) ctrlCommit 0;
				(_display displayctrl 307) ctrlCommit 0;
				
				//set focus to Options button
				ctrlSetFocus (_display displayctrl 101);
				*/
			};
						
			//Reset of MP Pause Menu
			if((_this select 2) == "RscDisplayMPInterrupt") then
			{
				debuglog "Resetting MP Pause Menu. Expanding options in accordion again.";
				
				//If in demo, move following controls down --------------------------------------------------
				//TEST-commented out since demo and dev should behave the same way
				// if( getNumber(configfile >> "isDemo") == 1 ) then
				// {
					// _displayMPInterrupt = findDisplay 49;
				
					// //Title background
					// _control = _displayMPInterrupt displayctrl 1050;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Title - same position as title background
					// _control = _displayMPInterrupt displayctrl 523;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Player's name - same position as title background
					// _control = _displayMPInterrupt displayctrl 109;
					// _control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Continue button
					// _control = _displayMPInterrupt displayctrl 2;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (15.3 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Save button
					// _control = _displayMPInterrupt displayctrl 103;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Skip button - same position as Save
					// _control = _displayMPInterrupt displayctrl 1002;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Respawn
					// _control = _displayMPInterrupt displayctrl 1010;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (17.5 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //Options button
					// _control = _displayMPInterrupt displayctrl 101;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (18.6 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
					
					// //FieldManual button
					// _control = _displayMPInterrupt displayctrl 2407;
					// _control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (19.7 * GUI_GRID_H + GUI_GRID_Y)];
					// _control ctrlCommit 0;
				// };
				//If in demo, move following controls down --------------------------------------------------
				
				//If Options in the MP Pause Menu were expanded before reset, expand it again
				if(uiNamespace getvariable "BIS_DisplayInterrupt_isOptionsExpanded") then
				{
					uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", false];			//set it to false to tell the script the current state. It will expand the options.
					['optionsButton', [(findDisplay 49) displayctrl 101], ''] call RscDisplayMPInterrupt_script; 	//simulate click on Options button
				};
				
				//_display = findDisplay 49;  //use  RscDisplayMPInterrupt (has same IDD as Pause menu and Video pause menu)
				
				//expand accordion and show buttons
				/*
				//Title background
				_control = _display displayctrl 1050;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Title - same position as title background
				_control = _display displayctrl 523;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Player's name - same position as title background
				_control = _display displayctrl 109;
				_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Continue button
				_control = _display displayctrl 2;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Save button
				_control = _display displayctrl 103;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.0 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Skip button - same position as Save
				_control = _display displayctrl 1002;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.0 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Respawn
				_control = _display displayctrl 1010;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Options button
				_control = _display displayctrl 101;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;

				//Enable and show buttons
				(_display displayctrl 301) ctrlEnable true;	//Video
				(_display displayctrl 302) ctrlEnable true;	//Audio
				(_display displayctrl 303) ctrlEnable true;	//Controls
				(_display displayctrl 307) ctrlEnable true;	//Game Options
				
				//--- Show all buttons from Options
				(_display displayctrl 301) ctrlSetFade 0;	//Video
				(_display displayctrl 302) ctrlSetFade 0;	//Audio
				(_display displayctrl 303) ctrlSetFade 0;	//Controls
				(_display displayctrl 307) ctrlSetFade 0;	//Game Options
				
				(_display displayctrl 301) ctrlCommit 0;
				(_display displayctrl 302) ctrlCommit 0;
				(_display displayctrl 303) ctrlCommit 0;
				(_display displayctrl 307) ctrlCommit 0;
				
				//set focus to Options button
				ctrlSetFocus (_display displayctrl 101);
				*/
			};
			
			//Reset of Video Pause Menu
			//Pause menu, MP pause menu and Video pause menu - all have IDD_INTERRUPT 49
			if( (_this select 2) == "RscDisplayMovieInterrupt" ) then
			{
				debuglog "Resetting Video Pause Menu. Expanding options in accordion again.";
				
				//If Options in the MP Pause Menu were expanded before reset, expand it again
				if(uiNamespace getvariable "BIS_DisplayInterrupt_isOptionsExpanded") then
				{
					uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", false];			//set it to false to tell the script the current state. It will expand the options.
					['optionsButton', [(findDisplay 49) displayctrl 101], ''] call RscDisplayMovieInterrupt_script; 	//simulate click on Options button
				};
				
				//_display = findDisplay 49;  //use  RscDisplayMovieInterrupt (has same IDD as Pause menu and MP Pause menu)
				
				//expand accordion and show buttons
				/*
				//Title background
				_control = _display displayctrl 1050;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Title - same position as title background
				_control = _display displayctrl 1004;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Player's name - same position as title background
				_control = _display displayctrl 109;
				_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Continue button
				_control = _display displayctrl 2;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Skip button
				_control = _display displayctrl 1;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.0 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Again - same position as Revert
				_control = _display displayctrl 105;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Options button
				_control = _display displayctrl 101;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;

				//Enable and show buttons
				(_display displayctrl 301) ctrlEnable true;	//Video
				(_display displayctrl 302) ctrlEnable true;	//Audio
				(_display displayctrl 303) ctrlEnable true;	//Controls
				(_display displayctrl 307) ctrlEnable true;	//Game Options
				
				//--- Show all buttons from Options
				(_display displayctrl 301) ctrlSetFade 0;	//Video
				(_display displayctrl 302) ctrlSetFade 0;	//Audio
				(_display displayctrl 303) ctrlSetFade 0;	//Controls
				(_display displayctrl 307) ctrlSetFade 0;	//Game Options
				
				(_display displayctrl 301) ctrlCommit 0;
				(_display displayctrl 302) ctrlCommit 0;
				(_display displayctrl 303) ctrlCommit 0;
				(_display displayctrl 307) ctrlCommit 0;
				
				//set focus to Options button
				ctrlSetFocus (_display displayctrl 101);
				*/
			};	
		};
		endloadingscreen;
	};


	case "onUnload": {
	
		startloadingscreen [""];
	
		_display = _params select 0;
		_button = _params select 1;
		
		
		//if UI size changed and user clicked OK, resize displays
		if ( (_button == 1) && (lbCurSel(_display displayctrl 136) != (uinamespace getvariable "RscDisplayOptionsVideoUIsize")) ) then
		{
			//Remember new state of UI size ComboBox
			uinamespace setvariable ["RscDisplayOptionsVideoUIsize", lbCurSel (_display displayctrl 136)];

			//--- Resize all opened displays
			{
				['reset',_x,gui_classes select _foreachindex] spawn RscDisplayOptionsVideo_script;
			} foreach gui_displays;

			//--- Apply blur again (not in main menu)
			if !(isNull player) then {
				'dynamicBlur' ppEffectEnable true;
				'dynamicBlur' ppEffectAdjust [1.6];
				'dynamicBlur' ppEffectCommit 0;
			};

			//--- Reset grid positions
			false call bis_fnc_guiGridToProfile;
		};

		//--- Restore custom GUI effects
		with missionnamespace do {
			if !(isnil "optionsMenuClosed") then {
				[] spawn optionsMenuClosed;
			};
		};
		
		
		endloadingscreen;
	};

};