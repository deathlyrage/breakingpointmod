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
				
				_valueGrid = _display displayctrl 1003;
				_valueGrid ctrlsettext _posGrid;

				_valueX = _display displayctrl 1005;
				_valueX ctrlsettext (str _posX + "m");

				_valueY = _display displayctrl 1007;
				_valueY ctrlsettext (str _posY + "m");

				_valueZ = _display displayctrl 1009;
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
				//_ctrlMode ctrlsettext (_modes select _id);
			};

			_ctrlToolbox = _display displayctrl 104;
			_ctrlToolbox ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {[ctrlparent (_this select 0),_this select 1] call RscDisplayArcadeMap_ToolBoxSelChanged};"];
			[_display,0] call RscDisplayArcadeMap_ToolBoxSelChanged;

			_ctrlToolboxSection = _display displayctrl 1019;
			_ctrlToolboxSection ctrladdeventhandler ["ToolBoxSelChanged","with uinamespace do {['section',_this,''] call RscDisplayArcadeMap_script};"];
			_ctrlToolboxSection lbsetcursel 0;

			
			//Register event-handler for Show/Hide button. Pass _display as a parameter.
			_control = _display displayctrl 1201;
			_control ctrladdeventhandler ["buttonclick","with uinamespace do {['collapse',_this,''] call RscDisplayArcadeMap_script};"];
	


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
					/* F1 */ case 59: {TOOLBOX_CHANGE(0)};
					/* F2 */ case 60: {TOOLBOX_CHANGE(1)};
					/* F3 */ case 61: {TOOLBOX_CHANGE(2)};
					/* F4 */ case 62: {TOOLBOX_CHANGE(3)};
					/* F5 */ case 63: {TOOLBOX_CHANGE(4)};
					/* F6 */ case 64: {TOOLBOX_CHANGE(5)};
					/* F7 */ case 65: {TOOLBOX_CHANGE(6)};
					
					//--- Backspace
					//case 14: { [_display] call RscDisplayArcadeMap_HideButtonClicked; };	//click on hide button - done by shortcut in config
				};
				false
			};
			_display displayaddeventhandler ["keydown","with uinamespace do {_this call RscDisplayArcadeMap_KeyDown};"];
			
			
			//Disable buttons for PA-Lite
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
	};

	case "collapse": {
		_display = ctrlparent (_params select 0);
		_enabled = false;
		{
			_control = _display displayctrl _x;
			_enabled = ctrlfade _control < 1;
			_control ctrlenable !_enabled;
			_control ctrlsetfade ([0,1] select _enabled);
			_control ctrlcommit 0.1;
		} foreach [2302,2303,1012,1224,107,108];

		_map = _display displayctrl 51;
		_mapPos = ctrlposition _map;
		_y = [configfile >> "RscDisplayArcadeMap" >> "controlsBackground" >> "CA_Map","y"] call bis_fnc_returnconfigentry;
		_h = [configfile >> "RscDisplayArcadeMap" >> "controlsBackground" >> "CA_Map","h"] call bis_fnc_returnconfigentry;
		if (_enabled) then {
			_yCollapsed = [configfile >> "RscDisplayArcadeMap" >> "controlsBackground" >> "CA_Map","yCollapsed"] call bis_fnc_returnconfigentry;
			_hCollapsed = [configfile >> "RscDisplayArcadeMap" >> "controlsBackground" >> "CA_Map","hCollapsed"] call bis_fnc_returnconfigentry;
			if !(isnil "_yCollapsed") then {_y = _yCollapsed;};
			if !(isnil "_hCollapsed") then {_h = _hCollapsed;};
		};
		_y = _y call bis_fnc_parsenumber;
		_h = _h call bis_fnc_parsenumber;
		_mapPos set [1,_y];
		_mapPos set [3,_h];
		_map ctrlsetposition _mapPos;
		_map ctrlcommit 0.1;
	};

	case "section": {
		_display = ctrlparent (_params select 0);
		_ctrlSection = _display displayctrl 109;
		_ctrlSection lbsetcursel (_params select 1);
	};

	case "onUnload": {
		with (uinamespace) do {
			RscDisplayArcadeMap_mousemoving = nil;
			RscDisplayArcadeMap_ToolBoxSelChanged = nil;
			RscDisplayArcadeMap_KeyDown = nil;
		};
	};
};