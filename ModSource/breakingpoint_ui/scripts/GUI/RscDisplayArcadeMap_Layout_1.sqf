disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with (uinamespace) do {

			//--- Testing
			//missionnamespace setvariable ["testVar",42];
			//(missionnamespace getvariable "testVar") call (uinamespace getvariable "bis_fnc_log");

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

			//--- Mouse moving
			RscDisplayArcadeMap_mousemoving = {
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
				_valueX ctrlsettext (str _posX + "m");

				_valueY = _display displayctrl 1014;
				_valueY ctrlsettext (str _posY + "m");

				_valueZ = _display displayctrl 1016;
				_valueZ ctrlsettext (str _posZ + "m");
			};
			_ctrlMap = _display displayctrl 51;
			_ctrlMap ctrladdeventhandler ["mousemoving","with uinamespace do {_this call RscDisplayArcadeMap_mousemoving};"];

			//--- Toolbox changed
			RscDisplayArcadeMap_ToolBoxSelChanged = {
				_id = _this select 1;
				_display = _this select 0;//ctrlparent (_this select 0);

				_ctrlMode = _display displayctrl 1017;
				_ctrlShortcut = _display displayctrl 1018;

				_modes = [
					localize "STR_DISP_ARCMAP_UNITS",
					localize "STR_DISP_ARCMAP_GROUPS",
					localize "STR_DISP_ARCMAP_SENSORS",
					localize "STR_DISP_ARCMAP_WAYPOINTS",
					localize "STR_DISP_ARCMAP_SYNCHRONIZE",
					localize "STR_DISP_ARCMAP_MARKERS",
					localize "STR_DISP_ARCMAP_MODULE"
				];
				_ctrlMode ctrlsettext (_modes select _id);
			};

			_ctrlToolbox = _display displayctrl 104;
			_ctrlToolbox ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {[ctrlparent (_this select 0),_this select 1] call RscDisplayArcadeMap_ToolBoxSelChanged};"];
			[_display,0] call RscDisplayArcadeMap_ToolBoxSelChanged;
			
			
			//--- Hide/Show button clicked
			RscDisplayArcadeMap_HideButtonClicked = {

				_display = _this select 0;

				_ctrlHide = _display displayctrl 2406;
				_cfgControls = configfile >> "RscDisplayArcadeMap" >> "controls";
				
				//--- change text of the button (SHOW/HIDE) according to the position of background (if is in visible area, move SideBar away)
				if ( ((ctrlPosition (_display displayctrl 1080)) select 1) > -1.0  ) then  //check fade of Title Background
				{	
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if !( (getnumber (_current >> "idc")) == 2 ||		//Don't hide exit buttons and StatusBar at the bottom
								     (getnumber (_current >> "idc")) == 1007 ||
								     (getnumber (_current >> "idc")) == 1009 ||
								     (getnumber (_current >> "idc")) == 1010 ||
								     (getnumber (_current >> "idc")) == 1011 ||
								     (getnumber (_current >> "idc")) == 1012 ||
								     (getnumber (_current >> "idc")) == 1013 ||
								     (getnumber (_current >> "idc")) == 1014 ||
								     (getnumber (_current >> "idc")) == 1015 ||
								     (getnumber (_current >> "idc")) == 1016 ||
								     (getnumber (_current >> "idc")) == 1017 ||
								     (getnumber (_current >> "idc")) == 1082 ||
								     (getnumber (_current >> "idc")) == 2406
								) then { 
									_idc = getnumber (_current >> "idc");
									_control = _display displayctrl _idc;						
									_control ctrlSetPosition [-50, -50];	
									_control ctrlcommit 0;
								};
							};
						};
					} foreach [_cfgControls,_cfgControlsBackground];
					
					//show background of hide button
					_control = _display displayctrl 1082;
					_control ctrlsetfade 0;	
					_control ctrlcommit 0;
					
					//move hide/show button to the background position (top right corner)
					_x = getNumber (_cfgControls >> "HideButtonBackground" >> "x");
					_y = getNumber (_cfgControls >> "HideButtonBackground" >> "y");
					_ctrlHide ctrlSetPosition [_x, _y];
					_ctrlHide ctrlcommit 0;
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_show.paa";
					_ctrlHide ctrlSetTooltip "Show SideBar (BACKSPACE)";  //--- ToDo: Localize;	
				}
				else
				{
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if !( (getnumber (_current >> "idc")) == 2 ||		//Don't hide exit buttons and StatusBar at the bottom	
								     (getnumber (_current >> "idc")) == 1007 ||	
								     (getnumber (_current >> "idc")) == 1009 ||
								     (getnumber (_current >> "idc")) == 1010 ||
								     (getnumber (_current >> "idc")) == 1011 ||
								     (getnumber (_current >> "idc")) == 1012 ||
								     (getnumber (_current >> "idc")) == 1013 ||
								     (getnumber (_current >> "idc")) == 1014 ||
								     (getnumber (_current >> "idc")) == 1015 ||
								     (getnumber (_current >> "idc")) == 1016 ||
								     (getnumber (_current >> "idc")) == 1017 ||
								     (getnumber (_current >> "idc")) == 1082 ||
								     (getnumber (_current >> "idc")) == 2406
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
					
					//hide background of hide button
					_control = _display displayctrl 1082;
					_control ctrlsetfade 1;	
					_control ctrlcommit 0;
					
					//move hide/show button to the original position (left of mission name)
					_x = getNumber (_cfgControls >> "ButtonHide" >> "x");
					_y = getNumber (_cfgControls >> "ButtonHide" >> "y");
					_ctrlHide ctrlSetPosition [_x, _y];
					_ctrlHide ctrlcommit 0;
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_hide.paa";
					_ctrlHide ctrlSetTooltip "Hide SideBar (BACKSPACE)";  //--- ToDo: Localize;
				};
			};
			
			
			//--- Overcast ToolBox changed - TODO
			/*
			RscDisplayArcadeMap_OvercastToolboxChanged = {
				
				disableserialization;
				_toolBox = (_this select 0) select 0;
				_selectedItem = (_this select 0) select 1;
				_display = ctrlparent _toolBox;
			
				//debuglog format["ToolBox: %1, Sel. Item: %2, Display: %3", _toolBox, _selectedItem, _display];
				ctrlActivate (_display displayctrl 105); //click on Intel button
				_intelDisplay = (findDisplay 32);
				_overcastTextBox = (_intelDisplay displayctrl 113);
				
				//_overcastTextBox ctrlSetText "11";
				
				//debuglog format["MUFTEST: IntelDisplay: %1, TextBox: %2, Sel. Item: %3", _intelDisplay, _overcastTextBox, _selectedItem];
				//_numValueWeather =  parseNumber(ctrlText (_intelDisplay displayctrl 113)); //Overcast TextBox in Intel dialogue
				//_toolBoxOvercast = (_display displayctrl 2602);
				
				// <=20
				// 20<
				// 40<
				// 60<
				// 80
				
				// uinamespace setvariable ["RscDisplayArcadeMap_Overcast", _selectedItem]; //saves which icon is selected in ToolBox
				
				switch (_selectedItem) do
				{
					case 0: {_overcastTextBox ctrlSetText "0"};
					case 1: {_overcastTextBox ctrlSetText "30"};
					case 2: {_overcastTextBox ctrlSetText "50"};
					case 3: {_overcastTextBox ctrlSetText "70"};
					case 4: {_overcastTextBox ctrlSetText "100"};
				};
				
				//sleep 2;
				
				//TODO - find out why this doesn't work?
				ctrlActivate (_intelDisplay displayctrl 1); //click on OK button in Intel
			
			};
			*/
				

			//Register event-handler for Show/Hide button. Pass _display as a parameter.
			_control = _display displayctrl 2406;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {[ctrlparent (_this select 0)] call RscDisplayArcadeMap_HideButtonClicked};"];
			
			//Register event-handler for Overcast ToolBox
			(_display displayctrl 2602) ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {['overcastChanged',_this,''] call RscDisplayArcadeMap_script};"];
			
			//Register event-handler for Time Slider
			_timeSlider = (_display displayctrl 2601);
			_timeSlider sliderSetPosition 5.0; //init slider (when done via EH, Intel is not closed)
			_timeSlider ctrladdeventhandler ["SliderPosChanged","with uinamespace do {['timeChanged',_this,''] call RscDisplayArcadeMap_script};"];
			// ["timeChanged",[_timeSlider, 5.0], ""] call RscDisplayArcadeMap_script; //init slider - Intel is not closed properly
			
			


			//--- Pressed keys
			RscDisplayArcadeMap_KeyDown = {
				_display = _this select 0;
				_key = _this select 1;

				#define TOOLBOX_CHANGE(ID)	[_display,ID] call RscDisplayArcadeMap_ToolBoxSelChanged;

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
					//case 14: { [_display] call RscDisplayArcadeMap_HideButtonClicked; };	//click on hide button - done by shortcut in config
				};
				false
			};
			_display displayaddeventhandler ["keydown","with uinamespace do {_this call RscDisplayArcadeMap_KeyDown};"];
		
		
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
		
		//------------------------------WEATHER PICTURE----------------------------------------------------
		// _toolBox = _this select 0;
		// _selectedItem = _this select 1;
		// _display = ctrlparent _toolBox;
	
		//debuglog format["ToolBox: %1, Sel. Item: %2, Display: %3", _toolBox, _selectedItem, _display];
		
		
		
		// ctrlActivate (_display displayctrl 105); //click on Intel button
		// _intelDisplay = (findDisplay 32);
		// _numValueWeather =  parseNumber(ctrlText (_intelDisplay displayctrl 113)); //Overcast TextBox in Intel dialogue
		// _toolBoxOvercast = (_display displayctrl 2602);
		// ctrlActivate (_intelDisplay displayctrl 1); //click on OK button in Intel
		//debuglog format["ToolBox: %1, Sel. Item: %2, Display: %3, IntelWeather: %4", _toolBox, _selectedItem, _display, ctrlText (_intelDisplay displayctrl 113)];
		
		// <=20
		// 20<
		// 40<
		// 60<
		// 80
		
		// if (_numValueWeather <= 20) then
		// {
			////sun
			// _toolBoxOvercast lbSetCurSel 0;
		// }
		// else
		// {
			// if ( (_numValueWeather > 20) && (_numValueWeather <= 40) ) then
			// {
				////partly cloudy
				// _toolBoxOvercast lbSetCurSel 1;
			// }
			// else
			// {
				// if ( (_numValueWeather > 40) && (_numValueWeather <= 60) ) then
				// {
					////cloudy
					// _toolBoxOvercast lbSetCurSel 2;
				// }
				// else
				// {
					// if ( (_numValueWeather > 60) && (_numValueWeather <= 80) ) then
					// {
						////rainy
						// _toolBoxOvercast lbSetCurSel 3;
					// }
					// else
					// {
						////stormy (_selectedItem > 80)
						// _toolBoxOvercast lbSetCurSel 4;
					// };
				// };	
			// };	
		// };
		
		
		
		//------------------------------WEATHER PICTURE----------------------------------------------------
		
			
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
		
		switch (_selectedItem) do
		{
			case 0:
			{
				//(_display displayctrl 2603) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.0;
			};
			case 1:
			{
				//(_display displayctrl 2604) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.3;
			};
			case 2:
			{
				//(_display displayctrl 2605) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.5;
			};
			case 3:
			{
				//(_display displayctrl 2606) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 0.7;
			};
			case 4:
			{
				//(_display displayctrl 2607) ctrlSetTextColor [0,0,0,1];
				_overcastSlider sliderSetPosition 1.0;
			};
		};

		ctrlActivate (_intelDisplay displayctrl 1); //click on OK button in Intel
	};
	
	case "timeChanged":
	{
		_slider = (_this select 1) select 0;
		_sliderPos = (_this select 1) select 1; //varies in interval <0, 10>
		_display = ctrlparent _slider;
		ctrlActivate (_display displayctrl 105); //click on Intel button
		_intelDisplay = (findDisplay 32);
		
		//hour: (floor (9.5*2.4))
		//min: ((9.5*2.4) - (floor (9.5*2.4))) * 60
		_hours = (floor (_sliderPos*2.4)); //0-23
		_minutes = ((_sliderPos*2.4) - (23 min (floor (_sliderPos*2.4))) )*60;
		
		((findDisplay 32) displayctrl 104) lbSetCurSel (23 min _hours); //set hours ComboBox
		((findDisplay 32) displayctrl 105) lbSetCurSel (round ((55 min _minutes) / 5));  //12 positions in ComboBox 60/12=5

		ctrlActivate (_intelDisplay displayctrl 1); //click on OK button in Intel
	};
	
	
	case "onUnload": {
		with (uinamespace) do {
			RscDisplayArcadeMap_mousemoving = nil;
			RscDisplayArcadeMap_ToolBoxSelChanged = nil;
			RscDisplayArcadeMap_KeyDown = nil;
		};
	};
};