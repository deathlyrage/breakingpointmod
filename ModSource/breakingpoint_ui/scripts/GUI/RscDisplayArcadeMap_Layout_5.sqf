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
				if ( ((ctrlPosition (_display displayctrl 1084)) select 1) > -1.0  ) then  //check fade of Title Background
				{	
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if !( //(getnumber (_current >> "idc")) == 2   ||		//Don't hide exit buttons and StatusBar at the bottom
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
								     (getnumber (_current >> "idc")) == 2301 ||		//Intel
								     (getnumber (_current >> "idc")) == 1082 ||		//Hide Button background
								     (getnumber (_current >> "idc")) == 2406		//Hide Button
								     //(getnumber (_current >> "idc")) == 107  ||		//Preview
								     //(getnumber (_current >> "idc")) == 1085 ||		//Continue background
								     //(getnumber (_current >> "idc")) == 108			//Continue
								) then { 
									_idc = getnumber (_current >> "idc");
									_control = _display displayctrl _idc;						
									_control ctrlSetPosition [-50, -50];	
									_control ctrlcommit 0;
								};
							};
						};
					} foreach [_cfgControls,_cfgControlsBackground];
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_show_down.paa";
					_ctrlHide ctrlSetTooltip "Show ToolBar (BACKSPACE)";  //--- ToDo: Localize;	
				}
				else
				{
					{
						_cfg = _x;
						for "_i" from 0 to (count _cfg - 1) do {
							_current = _cfg select _i;
							if (isclass _current) then {
								if !( //(getnumber (_current >> "idc")) == 2   ||		//Don't hide exit buttons and StatusBar at the bottom
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
								     (getnumber (_current >> "idc")) == 2301 ||		//Intel
								     (getnumber (_current >> "idc")) == 1082 ||		//Hide Button background
								     (getnumber (_current >> "idc")) == 2406		//Hide Button
								     //(getnumber (_current >> "idc")) == 107  ||		//Preview
								     //(getnumber (_current >> "idc")) == 1085 ||		//Continue background
								     //(getnumber (_current >> "idc")) == 108			//Continue
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
					
					//change icon and tooltip
					_ctrlHide ctrlsettext "A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_sidebar_hide_up.paa";
					_ctrlHide ctrlSetTooltip "Hide ToolBar (BACKSPACE)";  //--- ToDo: Localize;
				};
			};

			
			//Register event-handler for Show/Hide button. Pass _display as a parameter.
			_control = _display displayctrl 2406;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {[ctrlparent (_this select 0)] call RscDisplayArcadeMap_HideButtonClicked};"];
	


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
	};
	
	
	case "onUnload": {
		with (uinamespace) do {
			RscDisplayArcadeMap_mousemoving = nil;
			RscDisplayArcadeMap_ToolBoxSelChanged = nil;
			RscDisplayArcadeMap_KeyDown = nil;
		};
	};
};