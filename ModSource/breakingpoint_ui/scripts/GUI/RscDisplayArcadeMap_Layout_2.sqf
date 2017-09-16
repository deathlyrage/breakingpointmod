#include "\A3\ui_f\hpp\defineCommonGrids.inc"

//Mission Editor - Prototype 2

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with (uinamespace) do {

			//--- Create missionnamespace variables
			//3 call bis_fnc_recompile;

			_display = _params select 0;

			//--- Save As - save 'save as' param and activate 'Save' button
			_ctrlSaveAs = _display displayctrl 1712;
			_ctrlSaveAs ctrladdeventhandler [
				"buttonclick",
				"
					uinamespace setvariable ['RscDisplayArcadeMap_saveAs',true];
					ctrlactivate ((ctrlparent (_this select 0)) displayctrl 102);
				"
			];
			
			uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isTexturesOn', false];  //to track if textures are on - changes background and button color
			uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isIDsOn', false];	      //to track if IDs are on - changes background and button color

			//--- Mouse moving
			RscDisplayArcadeMap_Layout_2_mousemoving = {
				_ctrlMap = _this select 0;
				_x = _this select 1;
				_y = _this select 2;
				_display = ctrlparent _ctrlMap;

				_pos = _ctrlMap ctrlMapScreenToWorld [_x,_y];
				_posX = _pos select 0;
				_posY = _pos select 1;
				_posZ = getTerrainHeightASL _pos;
				_posGrid = mapGridPosition _pos;
				
				_valueGrid = _display displayctrl 1010;
				_valueGrid ctrlsettext _posGrid;

				_valueX = _display displayctrl 1012;
				_valueX ctrlsettext (str _posX + (localize "STR_A3_RscDisplayArcadeMap_Meters"));

				_valueY = _display displayctrl 1014;
				_valueY ctrlsettext (str _posY + (localize "STR_A3_RscDisplayArcadeMap_Meters"));

				_valueZ = _display displayctrl 1016;
				_valueZ ctrlsettext (str _posZ + (localize "STR_A3_RscDisplayArcadeMap_Meters"));
			};
			_ctrlMap = _display displayctrl 51;
			_ctrlMap ctrladdeventhandler ["mousemoving","with uinamespace do {_this call RscDisplayArcadeMap_Layout_2_mousemoving};"];

			//--- Toolbox changed
			RscDisplayArcadeMap_Layout_2_ToolBoxSelChanged = {
				_id = _this select 1;
				_display = _this select 0;//ctrlparent (_this select 0);

				_ctrlMode = _display displayctrl 1017;
				_ctrlShortcut = _display displayctrl 1018;

				_modes = [
					localize "STR_DISP_ARCMAP_UNITS_key_first",
					localize "STR_DISP_ARCMAP_GROUPS_key_first",
					localize "STR_DISP_ARCMAP_SENSORS_key_first",
					localize "STR_DISP_ARCMAP_WAYPOINTS_key_first",
					localize "STR_DISP_ARCMAP_SYNCHRONIZE_key_first",
					localize "STR_DISP_ARCMAP_MARKERS_key_first",
					localize "STR_DISP_ARCMAP_MODULE_key_first"
				];
				_ctrlMode ctrlsettext (_modes select _id);
			};

			_ctrlToolbox = _display displayctrl 104;
			_ctrlToolbox ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {[ctrlparent (_this select 0),_this select 1] call RscDisplayArcadeMap_Layout_2_ToolBoxSelChanged};"];
			[_display,0] call RscDisplayArcadeMap_Layout_2_ToolBoxSelChanged;
			
			
			//--- Hide/Show button clicked
			RscDisplayArcadeMap_Layout_2_HideButtonClicked = {

				_display = _this select 0;

				_ctrlHide = _display displayctrl 2406;
				_cfgControls = configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls";
				
				//--- change text of the button (SHOW/HIDE) according to the position of background (if is in visible area, move SideBar away)
				//--- HIDE CONTROLS
				if ( ((ctrlPosition (_display displayctrl 108)) select 1) > -1.0  ) then  //check fade of Title Background
				{	
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if ( (getnumber (_current >> "idc")) == 109  ||		//mission ComboBox
								     (getnumber (_current >> "idc")) == 1081 ||		//sidebar background
								     (getnumber (_current >> "idc")) == 2301 ||		//intel
								     (getnumber (_current >> "idc")) == 1083 ||		//toolbox background
								     (getnumber (_current >> "idc")) == 104  ||		//toolbox
								     (getnumber (_current >> "idc")) == 108		//Continue button
								     // (getnumber (_current >> "idc")) == 1012 ||
								     // (getnumber (_current >> "idc")) == 1013 ||
								     // (getnumber (_current >> "idc")) == 1014 ||
								     // (getnumber (_current >> "idc")) == 1015 ||
								     // (getnumber (_current >> "idc")) == 1016 ||
								     // (getnumber (_current >> "idc")) == 1017 ||
								     // (getnumber (_current >> "idc")) == 1082 ||
								     // (getnumber (_current >> "idc")) == 2406
								) then { 
									_idc = getnumber (_current >> "idc");
									_control = _display displayctrl _idc;						
									_control ctrlSetPosition [-50, -50];	
									_control ctrlcommit 0;
								};
							};
						};
					} foreach [_cfgControls,_cfgControlsBackground];
					
					
					//Main background - change position and dimensions
					// _control = _display displayctrl 1081;
					// _control ctrlSetPosition [SafezoneX + SafezoneW - (8 * GUI_GRID_CENTER_W),
								  // SafezoneY,
								  // 8 * GUI_GRID_CENTER_W,
								  // 1 * GUI_GRID_CENTER_H];
					// _control ctrlcommit 0;
					
					//Preview button - change position and dimensions
					_control = _display displayctrl 107;
					_control ctrlSetPosition [SafezoneX + SafezoneW - (9.1 * GUI_GRID_CENTER_W),
								  SafezoneY + (0.1 * GUI_GRID_CENTER_H),
								  6 * GUI_GRID_CENTER_W,
								  1.3 * GUI_GRID_CENTER_H];
					_control ctrlcommit 0;
					
					//Mission name - change width
					_control = _display displayctrl 113;
					_control ctrlSetPosition [SafezoneX + (20.6 * GUI_GRID_CENTER_W),
								  SafezoneY,
								  SafezoneW - (29.8 * GUI_GRID_CENTER_W),
								  1.5 * GUI_GRID_CENTER_H];
					_control ctrlcommit 0;
					
					// x = SafezoneX + (18 * GUI_GRID_CENTER_W)
					// y = SafezoneY;
					// w = SafezoneW - (27 * GUI_GRID_CENTER_W);  //gets wider with smaller interface
					// h = 1 * GUI_GRID_CENTER_H;
					
					//show background of hide button
					// _control = _display displayctrl 1082;
					// _control ctrlsetfade 0;	
					// _control ctrlcommit 0;
					
					//move hide/show button to the background position (top right corner)
					//_x = getNumber (_cfgControls >> "HideButtonBackground" >> "x");
					//_y = getNumber (_cfgControls >> "HideButtonBackground" >> "y");
					//_ctrlHide ctrlSetPosition [_x, _y];
					//--_ctrlHide ctrlSetPosition [SafezoneX + SafezoneW - (8.5 * GUI_GRID_CENTER_W), SafezoneY];
					//--_ctrlHide ctrlcommit 0;
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_show_down.paa";
					_ctrlHide ctrlSetTooltip (localize "STR_A3_RscDisplayArcadeMap_ShowSidebar");	//"Show SideBar (BACKSPACE)";
				}
				//--- SHOW CONTROLS
				else
				{
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if ( (getnumber (_current >> "idc")) == 109  ||		//mission ComboBox
								     (getnumber (_current >> "idc")) == 1081 ||		//sidebar background
								     (getnumber (_current >> "idc")) == 2301 ||		//intel
								     (getnumber (_current >> "idc")) == 1083 ||		//toolbox background
								     (getnumber (_current >> "idc")) == 104  ||		//toolbox
								     (getnumber (_current >> "idc")) == 108		//Continue button
								) then { 
									_idc = getnumber (_current >> "idc");
									_control = _display displayctrl _idc;
									//get original coordinates from config to move control to proper position
									_x = getnumber (_current >> "x");
									_y = getnumber (_current >> "y");
									_control ctrlSetPosition [_x, _y];	
									_control ctrlcommit 0;
								};
							};
						};
					} foreach [_cfgControls,_cfgControlsBackground];
					
					//Main background - change position and dimensions
					// _x = getNumber (_cfgControls >> "Mainback" >> "x");
					// _y = getNumber (_cfgControls >> "Mainback" >> "y");
					// _w = getNumber (_cfgControls >> "Mainback" >> "w");
					// _h = getNumber (_cfgControls >> "Mainback" >> "h");
					// _control = _display displayctrl 1081;
					// _control ctrlSetPosition [_x, _y, _w, _h];
					// _control ctrlcommit 0;
					
					//Preview button - change position and dimensions
					_x = getNumber (_cfgControls >> "Preview" >> "x");
					_y = getNumber (_cfgControls >> "Preview" >> "y");
					_w = getNumber (_cfgControls >> "Preview" >> "w");
					_h = getNumber (_cfgControls >> "Preview" >> "h");
					_control = _display displayctrl 107;
					_control ctrlSetPosition [_x, _y, _w, _h];
					_control ctrlcommit 0;
					
					//Mission name - change width
					_x = getNumber (_cfgControls >> "CA_MissionName" >> "x");
					_y = getNumber (_cfgControls >> "CA_MissionName" >> "y");
					_w = getNumber (_cfgControls >> "CA_MissionName" >> "w");
					_h = getNumber (_cfgControls >> "CA_MissionName" >> "h");
					_control = _display displayctrl 113;
					_control ctrlSetPosition [_x, _y, _w, _h];
					_control ctrlcommit 0;
					
					
					
					//hide background of hide button
					// _control = _display displayctrl 1082;
					// _control ctrlsetfade 1;	
					// _control ctrlcommit 0;
					
					//move hide/show button to the original position (left of mission name)
					// _x = getNumber (_cfgControls >> "ButtonHide" >> "x");
					// _y = getNumber (_cfgControls >> "ButtonHide" >> "y");
					// _ctrlHide ctrlSetPosition [_x, _y];
					// _ctrlHide ctrlcommit 0;
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_hide_up.paa";
					_ctrlHide ctrlSetTooltip (localize "STR_A3_RscDisplayArcadeMap_HideSidebar");	//"Hide SideBar (BACKSPACE)";
				};
			};
			
			//--- Textures button clicked
			RscDisplayArcadeMap_Layout_2_TexturesButtonClicked = {

				_display = _this select 0;
				_texturesIcon = _display displayctrl 112;
				_texturesBackground = _display displayctrl 1087;
				
				if(uiNamespace getVariable "RscDisplayArcadeMap_Layout_2_isTexturesOn") then 
				{
					//textures ON, so switch them OFF (only colors, switching done in engine)
					_texturesBackground ctrlSetBackgroundColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "TexturesButtonBackground" >> "colorBackground");
					_texturesIcon ctrlSetTextColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "Textures" >> "color");
					_texturesIcon ctrlSetActiveColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "Textures" >> "colorActive");
					uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isTexturesOn', false];
				}
				else
				{
					//textures OFF, so switch them ON (only colors, switching done in engine)
					_texturesBackground ctrlSetBackgroundColor [1,1,1,1];
					_texturesIcon ctrlSetTextColor [0.05,0.05,0.05,0.8];
					_texturesIcon ctrlSetActiveColor [0,0,0,0.9];
					uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isTexturesOn', true];
				};
			};
			
			//--- IDs button clicked
			RscDisplayArcadeMap_Layout_2_IDsButtonClicked = {

				_display = _this select 0;
				_idIcon = _display displayctrl 111;
				_idBackground = _display displayctrl 1088;
				
				if(uiNamespace getVariable "RscDisplayArcadeMap_Layout_2_isIDsOn") then
				{
					//IDs ON, so switch them OFF (only colors, switching done in engine)
					_idBackground ctrlSetBackgroundColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "IDsButtonBackground" >> "colorBackground");
					_idIcon ctrlSetTextColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "Ids" >> "color");
					_idIcon ctrlSetActiveColor getArray(configfile >> "RscDisplayArcadeMap_Layout_2" >> "controls" >> "Ids" >> "colorActive");
					uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isIDsOn', false];
				}
				else
				{
					//IDs OFF, so switch them ON (only colors, switching done in engine)
					_idBackground ctrlSetBackgroundColor [1,1,1,1];
					_idIcon ctrlSetTextColor [0.05,0.05,0.05,0.8];
					_idIcon ctrlSetActiveColor [0,0,0,0.9];
					uinamespace setvariable ['RscDisplayArcadeMap_Layout_2_isIDsOn', true];
				};
			};

			//Init weather ToolBox (overcast is 0.3 bz default, opening and closing intel didn't work - stayed opened)
			(_display displayctrl 2602) lbSetCurSel 1;

			//Register event-handler for Show/Hide button. Pass _display as a parameter.
			_control = _display displayctrl 2406;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {[ctrlparent (_this select 0)] call RscDisplayArcadeMap_Layout_2_HideButtonClicked};"];
			
			//Register event-handler for Textures button. Pass _display as a parameter.
			_control = _display displayctrl 112;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {[ctrlparent (_this select 0)] call RscDisplayArcadeMap_Layout_2_TexturesButtonClicked};"];
	
			//IDs event-handler for IDs button. Pass _display as a parameter.
			_control = _display displayctrl 111;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {[ctrlparent (_this select 0)] call RscDisplayArcadeMap_Layout_2_IDsButtonClicked};"];
	
			//Register event-handler for Overcast ToolBox
			(_display displayctrl 2602) ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {['overcastChanged',_this,''] call RscDisplayArcadeMap_Layout_2_script};"];
			
			//Register event-handler for Time Slider
			_timeSlider = (_display displayctrl 2601);
			_timeSlider sliderSetRange [0, 1440];
			_timeSlider sliderSetspeed [60, 0];	//set slider step when clicking on arrow to 1h (don't know the purpose of second parameter).
			_timeSlider sliderSetPosition (720);	//init slider to 12h (when done via EH, Intel is not closed)
			_timeSlider ctrladdeventhandler ["SliderPosChanged","with uinamespace do {['timeChanged',_this,''] call RscDisplayArcadeMap_Layout_2_script};"];
			// ["timeChanged",[_timeSlider, 5.0], ""] call RscDisplayArcadeMap_Layout_2_script; //init slider - Intel is not closed properly


			//--- Pressed keys
			RscDisplayArcadeMap_Layout_2_KeyDown = {
				_display = _this select 0;
				_key = _this select 1;

				#define TOOLBOX_CHANGE(ID)	[_display,ID] call RscDisplayArcadeMap_Layout_2_ToolBoxSelChanged;

				switch _key do {
					//--- F
					case 33: {
						//--- Ctrl + Shift
						if ((_this select 2) && (_this select 3)) then {1 call (uinamespace getvariable "bis_fnc_recompile")};
					};

					//--- F1
					case 59: {TOOLBOX_CHANGE(0)};

					//--- F2
					case 60: {TOOLBOX_CHANGE(1)};

					//--- F3
					case 61: {TOOLBOX_CHANGE(2)};

					//--- F4
					case 62: {TOOLBOX_CHANGE(3)};

					//--- F5
					case 63: {TOOLBOX_CHANGE(4)};

					//--- F6
					case 64: {TOOLBOX_CHANGE(5)};

					//--- F7
					case 65: {TOOLBOX_CHANGE(6)};
					
					//--- Backspace
					//case 14: { [_display] call RscDisplayArcadeMap_Layout_2_HideButtonClicked; };	//click on hide button - done by shortcut in config
				};
				false
			};
			_display displayaddeventhandler ["keydown","with uinamespace do {_this call RscDisplayArcadeMap_Layout_2_KeyDown};"];
		};
		
		
		//converts button texts toUpper	
		_control = _display displayctrl 105;	//Edit Intel
		_control ctrlSetText (toUpper (ctrlText _control));
		_control = _display displayctrl 107;	//Preview
		_control ctrlSetText (toUpper (ctrlText _control));
		_control = _display displayctrl 108;	//Continue
		_control ctrlSetText (toUpper (ctrlText _control));
		_control = _display displayctrl 2;	//Exit
		_control ctrlSetText (toUpper (ctrlText _control));
				
		//hide background of hide button
		_control = _display displayctrl 1082;
		_control ctrlsetfade 1;	
		_control ctrlcommit 0;
		
		//Disable button for PA-Lite
		if((productVersion select 1) == "Arma3AlphaLite") then
		{
			//Load
			_control = (_display displayctrl 101);
			_control ctrlEnable false;
			_control ctrlSetTextColor [1, 1, 1, 0.2];
			_control ctrlSetTooltip "Load is available in non-lite version - upgrade now!";		//No need to localize since PA-Lite has expired.
			//Save
			_control = (_display displayctrl 102);
			_control ctrlEnable false;
			_control ctrlSetTextColor [1, 1, 1, 0.2];
			_control ctrlSetTooltip "Save is available in non-lite version - upgrade now!";
			//Save As
			_control = (_display displayctrl 1712);
			_control ctrlEnable false;
			_control ctrlSetTextColor [1, 1, 1, 0.2];
			_control ctrlSetTooltip "Save As is available in non-lite version - upgrade now!";
			//Merge
			_control = (_display displayctrl 106);
			_control ctrlEnable false;
			_control ctrlSetTextColor [1, 1, 1, 0.2];
			_control ctrlSetTooltip "Merge is available in non-lite version - upgrade now!";
		};
	};
	
	case "overcastChanged":
	{
		_toolBox = (_this select 1) select 0;
		_selectedItem = (_this select 1) select 1;
		_display = ctrlparent _toolBox;
	
		ctrlActivate (_display displayctrl 105); //click on Intel button
		_intelDisplay = (findDisplay 32);
		_overcastSlider = (_intelDisplay displayctrl 108);
		_forecastedOvercastSlider = (_intelDisplay displayctrl 110);

		
		//      x <= 20  //sunny
		// 20 < x <= 40  //partly cloudy
		// 40 < x <= 60  //cloudy
		// 60 < x <= 80  //rainy
		// 80 < x        //stormy
		
		//TODO-plug in as soon as ToolBox is correctly sorted with other UI controls
		// (_display displayctrl 2603) ctrlSetTextColor [1,1,1,1];
		// (_display displayctrl 2604) ctrlSetTextColor [1,1,1,1];
		// (_display displayctrl 2605) ctrlSetTextColor [1,1,1,1];
		// (_display displayctrl 2606) ctrlSetTextColor [1,1,1,1];
		// (_display displayctrl 2607) ctrlSetTextColor [1,1,1,1];
		
		//Sets slider to the middle of intervals from RscDisplayIntel.sqf, onUnload
		switch (_selectedItem) do
		{
			case 0:
			{
				//(_display displayctrl 2603) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.1;
				_forecastedOvercastSlider sliderSetPosition 0.1;
			};
			case 1:
			{
				//(_display displayctrl 2604) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.3;
				_forecastedOvercastSlider sliderSetPosition 0.3;
			};
			case 2:
			{
				//(_display displayctrl 2605) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.5;
				_forecastedOvercastSlider sliderSetPosition 0.5;
			};
			case 3:
			{
				//(_display displayctrl 2606) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.7;
				_forecastedOvercastSlider sliderSetPosition 0.7;
			};
			case 4:
			{
				//(_display displayctrl 2607) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.9;
				_forecastedOvercastSlider sliderSetPosition 0.9;
			};
		};

		ctrlActivate (_intelDisplay displayctrl 1); //click on OK button in Intel
	};
	
	case "timeChanged":
	{
		_slider = (_this select 1) select 0;
		_sliderPos = (_this select 1) select 1; //varies in interval <0, 10>
		_display = ctrlparent _slider;
		_hours = floor (_sliderPos / 60);
		_minutes = ((_sliderPos/60) - (floor (_sliderPos/60)))*60;
		
		//Max value could be only 23:55
		if(_hours == 24) then
		{
			_hours = 23;
			_minutes = 55;
		};
		
		ctrlActivate (_display displayctrl 105); 					//click on Intel button
		_intelDisplay = (findDisplay 32);
		(_intelDisplay displayctrl 104) lbSetCurSel (23 min _hours);			//set hours ComboBox
		(_intelDisplay displayctrl 105) lbSetCurSel (round ((55 min _minutes) / 5)); 	//12 positions in ComboBox 60/12=5
		ctrlActivate (_intelDisplay displayctrl 1);					//click on OK button in Intel	
	};
	
	case "onUnload": {
		with (uinamespace) do {
			RscDisplayArcadeMap_Layout_2_mousemoving = nil;
			RscDisplayArcadeMap_Layout_2_ToolBoxSelChanged = nil;
			RscDisplayArcadeMap_Layout_2_KeyDown = nil;
			RscDisplayArcadeMap_Layout_2_HideButtonClicked = nil;
			RscDisplayArcadeMap_Layout_2_TexturesButtonClicked = nil;
			RscDisplayArcadeMap_Layout_2_IDsButtonClicked = nil;
		};
	};
};