//init copied from RscDisplayArcadeSites

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with uinamespace do {
			_display = _params select 0;

			//--- Disable description
			_syncGroup = _display displayctrl 2300;
			_syncGroup ctrlenable false;
			_syncGroup ctrlshow false;
			_syncMap = _display displayctrl 1003;
			//_syncMap ctrlsetbackgroundcolor [0.9,0.9,0.9,1];
			_syncMap ctrlenable false;
			_syncMap ctrlshow false;
			_syncMap ctrladdeventhandler ["draw","with uinamespace do {['mapdraw',_this,''] call RscDisplayArcadeModules_script};"];
			_syncMap ctrladdeventhandler ["mousemoving","with uinamespace do {['mapmouse',_this,''] call RscDisplayArcadeModules_script};"];
			_syncMap ctrladdeventhandler ["mouseholding","with uinamespace do {['mapmouse',_this,''] call RscDisplayArcadeModules_script};"];
			_syncMap ctrladdeventhandler ["mousebuttonclick","with uinamespace do {['mapmouseclick',_this,''] call RscDisplayArcadeModules_script};"];
			RscDisplayArcadeModules_sizeCoef = ((_syncMap ctrlmapscreentoworld [0,0] select 1) - (_syncMap ctrlmapscreentoworld [0,1] select 1));

			//--- Vehicle selected
			_ValueVehicle = _display displayctrl 103;  //IDC_ARCUNIT_VEHICLE, was IDC_AS_SITETYPE 706
			_ValueVehicle ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbselchanged',_this,''] spawn RscDisplayArcadeModules_script};"];
			["lbselchanged",[_ValueVehicle,lbcursel _ValueVehicle],""] call RscDisplayArcadeModules_script;

			//--- Info button
			_ctrlInfo = _display displayctrl 2402;
			_ctrlInfo ctrladdeventhandler ["buttonclick","with uinamespace do {['info',_this,''] call RscDisplayArcadeModules_script};"];

			//Sets all static texts toUpper
			["RscDisplayArcadeModules",["RscText","RscTitle","CA_TextVehicle"],["CA_VehicleAuthor"]] call bis_fnc_toUpperDisplayTexts;
		};
	};

	//--- Class listbox
	case "lbselchanged": {
		_ctrl = _params select 0;
		_id = _params select 1;
		_cursel = lbcursel _ctrl;
		_display = ctrlparent _ctrl;

		//--- (Detect side-OBSOLETE) DETECT MODULE TYPE
		//_sideColor = sidelogic call bis_fnc_sideColor;

		//--- Detect vehicle
		_text = _ctrl lbtext _cursel;
		_class = _ctrl lbdata _cursel;

		//--- Assign title
		_ctrlTitle = _display displayctrl 1406;
		_ctrlTitle ctrlsettext _class;

		//--- Scan module description
		_colorIcon = sideLogic call bis_fnc_sidecolor;
		_colorLine = (configfile >> "CfgIngameUI" >> "IslandMap" >> "colorSync") call bis_fnc_colorConfigToRGBA;
		_colorSensor = (configfile >> "CfgIngameUI" >> "IslandMap" >> "colorSensor") call bis_fnc_colorConfigToRGBA;

		_cfgVehicleBase = configfile >> "cfgvehicles" >> _class;
		_cfgModuleBase = _cfgVehicleBase >> "ModuleDescription";
		_cfgModuleCore = configfile >> "cfgvehicles" >> "module_f" >> "moduledescription";

		_fnc_scan = {
			private ["_class","_center","_dir","_dis","_cfgModule","_vehicle","_cfgVehicle"];
			_class = _this select 0;
			_center = _this select 1;
			_dir = _this select 2;
			_dis = _this select 3;

			_cfgModule = _cfgModuleBase >> _class;
			_vehicle = gettext (_cfgModule >> "vehicle");
			if (_vehicle == "") then {_vehicle = _class;};
			_cfgVehicle = configfile >> "cfgvehicles" >> _vehicle;
			if !(isclass _cfgVehicle) then {_cfgVehicle = configfile >> "cfgnonaivehicles" >> _vehicle;};
			if !(isclass _cfgVehicle) then {_cfgVehicle = _cfgModule};

			if (_dis == 0) then {
				_cfgModule = _cfgModuleBase;
				_cfgVehicle = _cfgVehicleBase;
			};

			if (isclass _cfgModule || isclass _cfgVehicle) then {
				private ["_displayName","_icon","_description","_pos","_sync","_syncCount"];

				_side = getnumber (_cfgVehicle >> "side");
				_icon = (gettext (_cfgVehicle >> "icon")) call bis_fnc_textureVehicleIcon;
				if (_icon == "") then {_icon = "#(argb,8,8,3)color(1,1,1,1)";};

				//--- Get simulation
				_simulation = tolower gettext (_cfgVehicle >> "simulation");
				if (_side in [0,1,2,3] && !(_simulation in ["soldier","carx","tankx","helicopterx","airplanex","shipx","submarinex",""])) then {_side = 8;};

				//--- Locate path
				_displayName = gettext (_cfgModule >> "displayName");
				if (_displayName == "") then {_displayName = gettext (_cfgVehicle >> "displayName");};
				_path = if (_vehicle == "EmptyDetector") then {
					localize "str_disp_arcmap_sensors"
				} else {
					if (_cfgVehicle != _cfgModule) then {
						_vehicleClass = gettext (_cfgVehicle >> "vehicleclass");
						_vehicleClassName = (configfile >> "cfgvehicleclasses" >> _vehicleClass) call bis_fnc_displayname;
						if (_vehicleClass == "Modules") then {
							_categoryClass = gettext (_cfgVehicle >> "category");
							if (_categoryClass == "") then {_categoryClass = "NO_CATEGORY";};
							_categoryClassName = (configfile >> "cfgfactionclasses" >> _categoryClass) call bis_fnc_displayname;
							format ["%1 / %2",localize "str_disp_arcmap_module",_categoryClassName];
						} else {
							_sideName = _side call bis_fnc_sidename;
							if (_side == 8) then {
								format ["%1 / %2 / %3",localize "str_disp_arcmap_units",_sideName,_vehicleClassName];
							} else {
								_factionClass = gettext (_cfgVehicle >> "faction");
								_factionClassName = (configfile >> "cfgfactionclasses" >> _factionClass) call bis_fnc_displayname;
								format ["%1 / %2 / %3 / %4",localize "str_disp_arcmap_units",_sideName,_factionClassName,_vehicleClassName];
							};
						};
					} else {
						""
					};
				};
				if (_path != "") then {_path = _path + "<br />"};

				//--- Get colors
				_colorIconLocal = if (isnumber (_cfgVehicle >> "side")) then {_side call bis_fnc_sidecolor} else {+_colorIcon};
				_colorLineLocal = +_colorLine;

				//--- Get size
				_size = 32;
				if (_vehicle == "EmptyDetector") then {
					_size = 18;
					_colorIconLocal = +_colorSensor;
				};

				//--- Make the optional connection transparent
				_optional = getnumber (_cfgModule >> "optional");
				if (_optional > 0) then {
					_colorIconLocal set [3,0.42];
					//_colorLineLocal set [3,0.5]; //--- Transparent line looks a bit like grouping, might be confusing
					_displayName = format ["%1 (%2)",_displayName,localize "STR_A3_RscDisplayArcadeModules_optional"];
				};

				//--- Get info about position and direction
				_position = [_cfgModule >> "position",nil,0] call bis_fnc_returnConfigEntry;
				_position = switch (typename _position) do {
					case (typename 00): {if (_position > 0) then {gettext (_cfgModuleCore >> "positionEnabled")} else {gettext (_cfgModuleCore >> "positionDisabled")};};
					case (typename ""): {_position};
					case (typename []): {gettext (_cfgModuleCore >> "positionDisabled")};
				};
				_direction = [_cfgModule >> "direction",nil,0] call bis_fnc_returnConfigEntry;
				_direction = switch (typename _direction) do {
					case (typename 00): {if (_direction > 0) then {gettext (_cfgModuleCore >> "positionEnabled")} else {gettext (_cfgModuleCore >> "positionDisabled")};};
					case (typename ""): {_direction};
					case (typename []): {gettext (_cfgModuleCore >> "positionDisabled")};
				};
				_duplicate = getnumber (_cfgModule >> "duplicate");
				_duplicate = if (_duplicate > 0) then {gettext (_cfgModuleCore >> "duplicateEnabled")} else {gettext (_cfgModuleCore >> "duplicateDisabled")};
				if (_dis == 0) then {_duplicate = "";};

				//--- Process description
				_descriptionRaw = [_cfgModule >> "description"] call bis_fnc_returnConfigEntry;
				if (isnil {_descriptionRaw}) then {_descriptionRaw = [_cfgVehicle >> "moduledescription" >> "description",nil,""] call bis_fnc_returnConfigEntry;};
				_description = "";
				switch (typename _descriptionRaw) do {
					case (typename []): {{_description = _description + _x + "<br />";} foreach _descriptionRaw;};
					case (typename ""): {_description = _descriptionRaw;};
					case (typename 00): {_description = "";};
				};
				if (_description != "") then {_description = _description + "<br />"};
				_description = format [
					"%1<br /><t color='#99cccccc' size='0.8'>%2</t><t size='0.8'>%3<br />%4: %5<br />%6: %7<br />%8</t>",
					_displayName,
					_path,
					_description,
					localize "STR_A3_RscDisplayArcadeModules_position",
					_position,
					localize "STR_A3_RscDisplayArcadeModules_direction",
					_direction,
					_duplicate
				];

				//--- Calculate position offset
				_disOffset = RscDisplayArcadeModules_sizeCoef * _disCoef;
				_pos = if (_dis > 0) then {[_center,_disOffset,_dir] call bis_fnc_relpos} else {_center};
				_posX = _pos select 0;
				_posXmin = _posXmin min _posX;
				_posXmax = _posXmax max _posX;
				_posY = _pos select 1;
				_posYmin = _posYmin min _posY;
				_posYmax = _posYmax max _posY;

/*
				//--- Register center lines
				if (_dis == 0) then {
					_centerOffset = 100;
					_drawLines set [count _drawLines,[[(_center select 0)-_centerOffset,(_center select 1)-_centerOffset],[(_center select 0)+_centerOffset,(_center select 1)+_centerOffset],[0,0,0,0.15]]];
					_drawLines set [count _drawLines,[[(_center select 0)-_centerOffset,(_center select 1)+_centerOffset],[(_center select 0)+_centerOffset,(_center select 1)-_centerOffset],[0,0,0,0.15]]];
				};
*/

				//--- Register an icon and a line leading to it
				_drawLines set [count _drawLines,[_center,_pos,_colorLineLocal]];
				_drawIcons set [count _drawIcons,[[_icon,_colorIconLocal,_pos,_size,_size,0,"",false],_pos,_size,parsetext _description]];
				if (_vehicle == "EmptyDetector") then {_drawEllipses set [count _drawEllipses,[_pos,_disOffset * 0.5,_disOffset * 0.5,0,_colorIconLocal,""]];};

				_sync = getarray (_cfgModule >> "sync");

				//--- Add trigger activation when enabled
				if (_dis == 0) then {
					if (getnumber (_cfgVehicle >> "isTriggerActivated") > 0) then {
						_sync set [count _sync,"Condition"];
					};
				};
				_syncCount = count _sync;

				{
					private ["_xDir"];
					_xDir = if (_dis > 0) then {
						if (_syncCount > 1) then {
							_dir - (_dirRange / 2) + (_foreachindex * (_dirRange / (_syncCount - 1)))
						} else {
							_dir
						};
					} else {
						_foreachindex * (360 / _syncCount)
					};
					[_x,_pos,_xDir,_dis + 1] call _fnc_scan;
				} foreach _sync;
			};
		};

		_startPos = [10,10];
		_dirRange = 90;
		_disCoef = 0.15;
		_drawLines = [];
		_drawEllipses = [];
		_drawIcons = [];
		_posXmin = _startPos select 0;
		_posXmax = _posXmin;
		_posYmin = _startPos select 1;
		_posYmax = _posYmin;

		[_class,_startPos,0,0] call _fnc_scan;

		RscDisplayArcadeModules_drawLines = _drawLines;
		RscDisplayArcadeModules_drawEllipses = _drawEllipses;
		RscDisplayArcadeModules_drawIcons = _drawIcons;
		_sizeX = _posXmax - _posXmin;
		_sizeY = _posYmax - _posYmin;
		_size = _sizeX max _sizeY;
	
		_syncMap = _display displayctrl 1003;
		_syncMap ctrlmapanimadd [0,0.001 + 0.00015 * _size,[_posXmin + _sizeX / 2,_posYmin + _sizeY / 2]];
		ctrlmapanimcommit _syncMap;

		RscDisplayArcadeModules_indexHover = 0;
		RscDisplayArcadeModules_indexSelected = 0;
		["mapmouseclick",[_syncMap],""] spawn RscDisplayArcadeModules_script;

		//--- Set author
		[_cfgVehicleBase,_display displayctrl 1022] call bis_fnc_overviewauthor;

		//--- Scan arguments
		_cfg = configfile >> "cfgvehicles" >> _class;
		_cfgArguments = _cfg >> "Arguments";
		for "_i" from 0 to (count _cfgArguments - 1) do {
			_argument = _cfgArguments select _i;
			if (isclass _argument) then {
				_label = _display displayctrl (10000 + (_i + 1) * 2);
				_label ctrlshow (ctrltext _label != "")
			};
		};
	};

	case "mapdraw": {
		_ctrlMap = _params select 0;
		{_ctrlMap drawline _x;} foreach RscDisplayArcadeModules_drawLines;
		{_ctrlMap drawellipse _x;} foreach RscDisplayArcadeModules_drawEllipses;
		{_ctrlMap drawicon (_x select 0);} foreach RscDisplayArcadeModules_drawIcons;
	};

	case "mapmouse": {
		_ctrlMap = _params select 0;
		_ctrlMapScale = ctrlmapscale _ctrlMap;
		_dis = _ctrlMapScale * 32 * RscDisplayArcadeModules_sizeCoef;

		RscDisplayArcadeModules_index = -1;

		_mX = _params select 1;
		_mY = _params select 2;
		_mPos = _ctrlMap ctrlmapscreentoworld [_mX,_mY];
		{
			_xIcon = _x select 0;
			_xPos = _x select 1;
			_xSize = _x select 2;
			if (_xPos distance _mPos < _dis) then {
				RscDisplayArcadeModules_indexHover = _foreachindex;
				_xIcon set [3,_xSize * 1.2];
				_xIcon set [4,_xSize * 1.2];
			} else {
				_xIcon set [3,_xSize];
				_xIcon set [4,_xSize];
			};
		} foreach RscDisplayArcadeModules_drawIcons;
	};
	case "mapmouseclick": {
		if (RscDisplayArcadeModules_indexHover >= 0 && count RscDisplayArcadeModules_drawIcons > 0) then {
			RscDisplayArcadeModules_indexSelected = RscDisplayArcadeModules_indexHover;
			_icon = RscDisplayArcadeModules_drawIcons select RscDisplayArcadeModules_indexSelected;

			_ctrlMap = _params select 0;
			_display = ctrlparent _ctrlMap;
			_ctrlSyncDescription = _display displayctrl 1100;
			_ctrlSyncDescription ctrlsetstructuredtext (_icon select 3);
			_ctrlSyncDescription call bis_fnc_ctrlfittotextheight;
		};
	};

	//--- Info button
	case "info": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_syncGroup = _display displayctrl 2300;
		_syncMap = _display displayctrl 1003;
		_SettingsGroup = _display displayctrl 2301;
		_ArgumentsGroup = _display displayctrl 127; //2302;

		//--- Set control groups' visibility
		_visibleSettings = ctrlshown _SettingsGroup;

		_syncGroup ctrlshow _visibleSettings;
		_syncMap ctrlshow _visibleSettings;
		_SettingsGroup ctrlshow !_visibleSettings;
		_ArgumentsGroup ctrlshow !_visibleSettings;

		_syncGroup ctrlenable _visibleSettings;
		_syncMap ctrlenable _visibleSettings;
		_SettingsGroup ctrlenable !_visibleSettings;
		_ArgumentsGroup ctrlenable !_visibleSettings;

		//--- Modify Info button text
		_ButtonInfo = _display displayctrl 2402;
		_ButtonInfo ctrlsettext toUpper(localize (["str_disp_armory_show","str_disp_armory_hide"] select  _visibleSettings));
	};

	//--- Argument
	case "argument_mouseButtonClick": {
		if (true) exitwith {};

		_control = _params select 0;
		_display = ctrlparent _control;
		_module = _display displayctrl 103;
		_moduleType = _module lbdata (lbcursel _module);
		_idc = ctrlidc _control;

		_cfgModule = configfile >> "CfgVehicles" >> _moduleTYpe;
		_cfgModuleArguments = _cfgModule >> "Arguments";

		_cfgArgument = _cfgModuleArguments select ((_idc / 2) - 1);
		_previewCode = gettext (_cfgArgument >> "preview");

		_text = "";
		if (_previewCode != "") then {with uinamespace do {_text = [_cfgModule,_cfgArgument] call compile _previewCode;};};
		if !(isnil "_text") then {
			if (typename _text != typename "") then {_text = str _text;};

			_controlEdit = _display displayctrl (_idc + 1);
			_controlEdit ctrlsettext _text;
		};

	};
	case "argument_focus": {
		if (true) exitwith {};

		_control = _params select 0;
		if (ctrlscale _control == 1) exitwith {};
		_display = ctrlparent _control;
		_module = _display displayctrl 103;
		_moduleType = _module lbdata (lbcursel _module);

		_controlArray = toarray str _control;
		_numbers = toarray "0123456789";
		_idc = "";
		{
			if (_x in _numbers) then {_idc = _idc + tostring [_x]};	
		} foreach _controlArray;
		_idc = parsenumber _idc;

		_cfgModule = configfile >> "CfgVehicles" >> _moduleTYpe;
		_cfgModuleArguments = _cfgModule >> "Arguments";

		_cfgArgument = _cfgModuleArguments select ((_idc / 2) - 1);
		_previewCode = gettext (_cfgArgument >> "preview");

		_color = ["GUI","BCG_RGB"] call bis_fnc_displaycolorget;
		if (_params select 1) then {
			_color set [3,1];
		} else {
			_color set [3,0.2];
		};
		_control ctrlsetbackgroundcolor _color;
		_control ctrlcommit 0;
	};
};