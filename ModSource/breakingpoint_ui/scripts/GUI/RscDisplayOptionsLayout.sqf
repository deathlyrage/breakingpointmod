#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

#define IDCBASE 12000

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;

		RscDisplayOptionsLayout_time = diag_ticktime + 0.1;
		RscDisplayOptionsLayout_selected = controlnull;
		RscDisplayOptionsLayout_mouse = [[],[]];

		_ctrlTags = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TAGS;
		_ctrlPresets = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_PRESETS;

		_ctrlTags ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbSelChanged_tags',_this,''] call RscDisplayOptionsLayout_script;};"];
		_ctrlPresets ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbSelChanged_presets',_this,''] call RscDisplayOptionsLayout_script;};"];

		{
			_tag = _x;
			_scope = getnumber (_tag >> "scope");
			if (_scope == 2 || !isnumber (_tag >> "scope")) then {
				_displayName = gettext (_tag >> "displayName");
				_lbAdd = _ctrlTags lbadd _displayName;
				_ctrlTags lbsetdata [_lbAdd,configname _tag];
			};
		} foreach ((configfile >> "CfgUIGrids") call bis_fnc_subClasses);
		if (lbsize _ctrlTags > 0) then {
			_ctrlTags lbsetcursel 0;
			if (lbsize _ctrlTags == 1) then {_ctrlTags ctrlenable false;};
		} else {
			["No CfgUIGrids categories found."] call bis_fnc_error;
		};

		_ctrlTooltip = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TOOLTIP;
		_ctrlTooltip ctrlenable false;

		_ctrlButtonOK = _display displayctrl IDC_OK;
		_ctrlButtonOK ctrladdeventhandler ["buttonclick","with uinamespace do {['buttonOK',_this,''] call RscDisplayOptionsLayout_script;};"];

		_ctrlButtonSave = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_BUTTONSAVE;
		_ctrlButtonSave ctrlshow false;

		for "_i" from 0 to 18 do {
			_control = _display displayctrl (IDCBASE + _i);
			_control ctrladdeventhandler ["mouseenter","with uinamespace do {['mouseEnter',_this,''] call RscDisplayOptionsLayout_script;};"];
			_control ctrladdeventhandler ["mouseexit","with uinamespace do {['mouseExit',_this,''] call RscDisplayOptionsLayout_script;};"];
			_control ctrladdeventhandler ["mouseholding","with uinamespace do {['mouseMoving',_this,''] call RscDisplayOptionsLayout_script;};"];
			_control ctrladdeventhandler ["mousemoving","with uinamespace do {['mouseMoving',_this,''] call RscDisplayOptionsLayout_script;};"];
			_control ctrladdeventhandler ["mousebuttondown","with uinamespace do {['mouseButtonDown',_this,''] call RscDisplayOptionsLayout_script;};"];
			_control ctrladdeventhandler ["mousebuttonup","with uinamespace do {['mouseButtonUp',_this,''] call RscDisplayOptionsLayout_script;};"];
		};
	};

	case "onUnload": {

		RscDisplayOptionsLayout_selected = nil;
		RscDisplayOptionsLayout_mouse = nil;
		RscDisplayOptionsLayout_time = nil;

		//--- Remove preview variables
		{
			_tag = _x;
			_tagName = configname _tag;
			uinamespace setvariable [_tagName + "preset",nil];
			{
				_var = _x;
				_varName = configname _var;
				{
					uinamespace setvariable [_x + "X",nil];
					uinamespace setvariable [_x + "Y",nil];
					uinamespace setvariable [_x + "W",nil];
					uinamespace setvariable [_x + "H",nil];
				} foreach [
					_tagName + "_" + _varName + "_",
					_tagName + "_preset_" + _varName + "_"
				];
			} foreach ((_tag >> "variables") call bis_fnc_subClasses);
		} foreach ((configfile >> "CfgUIGrids") call bis_fnc_subclasses);
	};

	case "lbSelChanged_tags": {
		_ctrlTags = _params select 0;
		_cursel = _params select 1;
		_tagName = _ctrlTags lbdata _cursel;
		_tag = configfile >> "CfgUIGrids" >> _tagName;
		_display = ctrlparent _ctrlTags;

		_ctrlPresets = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_PRESETS;
		lbclear _ctrlPresets;
		_ctrlPresets lbadd (localize "str_a3_rscdisplayoptionslayout_custom");

		_presetCurrent = profilenamespace getvariable [_tagName + "preset",""];
		_presetCurrent = uinamespace getvariable [_tagName + "preset",_presetCurrent];
		{
			_preset = _x;
			_presetName = configname _preset;
			_displayName = gettext (_preset >> "displayName");
			_default = getnumber (_preset >> "default");
			if (_default > 0) then {_displayName = format ["%1 (%2)",_displayName,localize "str_disp_default"];};

			_lbAdd = _ctrlPresets lbadd _displayName;
			_ctrlPresets lbsetdata [_lbAdd,_presetName];
			if (_presetName == _presetCurrent) then {_ctrlPresets lbsetcursel _lbAdd;};
		} foreach ((_tag >> "presets") call bis_fnc_subclasses);

		if (lbsize _ctrlPresets > 0) then {
			if (lbcursel _ctrlPresets < 0) then {_ctrlPresets lbsetcursel 0;};
		} else {
			["No %1 presets found.",_tagName] call bis_fnc_error;
		};

	};

	case "lbSelChanged_presets": {
		_ctrlPresets = _params select 0;
		_cursel = _params select 1;
		_presetName = _ctrlPresets lbdata _cursel;
		_display = ctrlparent _ctrlPresets;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TAGS;
		_tagName = _ctrlTags lbdata (lbcursel _ctrlTags);
		_presetDefault = profilenamespace getvariable [_tagName + "presetDefault",""];

		_tag = configfile >> "CfgUIGrids" >> _tagName;
		_preset = _tag >> "presets" >> _presetName;
		_presetDefault = _tag >> "presets" >> _presetDefault;
		if (!isclass _preset) then {_preset = _presetDefault;};
		["loadPreset",[_display,_tag,_presetName,_preset],""] call RscDisplayOptionsLayout_script;
	};

	case "loadPreset": {
		_display = _params select 0;
		_tag = _params select 1;
		_tagName = configname _tag;
		_presetName = _params select 2;
		_varPreset = if (_presetName == "") then {""} else {"preset_"};
		_preset = _params select 3;
		_commitTime = if (diag_ticktime > RscDisplayOptionsLayout_time) then {0.4} else {0};
		_idc = 0;
		_data = [];

		//--- Load config preset
		{
			_var = _x;
			_varName = configname _var;
			_varBase = _tagName + "_" + _varPreset + _varName + "_";
			_displayName = gettext (_var >> "displayname");
			_description = gettext (_var >> "description");
			_preview = gettext (_var >> "preview");
			_canResize = getnumber (_var >> "canResize") > 0;

			//--- Add instructions
			_infoMove = "LMB - move element";
			_infoResize = if (_canResize) then {"<br />RMB - resize element"} else {""};
			_displayName = format [
				"<t underline='1'>%1</t><br /><t size='0.8'>%2<br /><br /><t color='#99ffffff'>%3%4</t></t>",
				_displayName,
				_description,
				_infoMove,
				_infoResize
			];

			//--- Load config grid (load default one even when custom one is used)
			_grid = getArray (_preset >> "variables" >> _varName);
			_gridSize = [_grid,0,[],[[]]] call bis_fnc_paramin;
			_gridW = ([_grid,1,0] call bis_fnc_paramin) call bis_fnc_parsenumber;
			_gridH = ([_grid,2,0] call bis_fnc_paramin) call bis_fnc_parsenumber;

			_posX = ([_gridSize,0,0] call bis_fnc_paramin);
			_posY = ([_gridSize,1,0] call bis_fnc_paramin);
			_posW = ([_gridSize,2,0] call bis_fnc_paramin);
			_posH = ([_gridSize,3,0] call bis_fnc_paramin);
			_pos = [_posX,_posY,_posW,_posH];

			if (_presetName == "") then {

				//--- Load custom grid
				_varBase = _tagName + "_" + _varName + "_";

				_posX = (profilenamespace getvariable [_varBase + "X",_posX]);
				_posY = (profilenamespace getvariable [_varBase + "Y",_posY]);
				_posW = (profilenamespace getvariable [_varBase + "W",_posW]);
				_posH = (profilenamespace getvariable [_varBase + "H",_posH]);

				_posX = (uinamespace getvariable [_varBase + "X",_posX]);
				_posY = (uinamespace getvariable [_varBase + "Y",_posY]);
				_posW = (uinamespace getvariable [_varBase + "W",_posW]);
				_posH = (uinamespace getvariable [_varBase + "H",_posH]);

				_pos = [_posX,_posY,_posW,_posH];
			};
			_grid = [_pos,_gridW,_gridH];

			if (count _pos == 4) then {
				_pos = +_pos;
				{
					_pos set [_foreachindex,_x call bis_fnc_parsenumber];
				} foreach _pos;
				_control = _display displayctrl (IDCBASE + _idc);
				_control ctrlsettext _preview;
				_control ctrlsetposition _pos;
				_control ctrlcommit _commitTime;

				uinamespace setvariable [_varBase + "X",_posX];
				uinamespace setvariable [_varBase + "Y",_posY];
				uinamespace setvariable [_varBase + "W",_posW];
				uinamespace setvariable [_varBase + "H",_posH];
			};
			_data set [_idc,[_tagName,_varName,parsetext _displayName,_canResize,_grid]];

			_idc = _idc + 1;
		} foreach ((_tag >> "variables") call bis_fnc_subclasses);
		RscDisplayOptionsLayout_data = _data;
		uinamespace setvariable [_tagName + "preset",_presetName];
	};
	case "mouseMoving": {
		_control = _params select 0;
		_mX = _params select 1;
		_mY = _params select 2;

		_display = ctrlparent _control;
		_ctrlTooltip = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TOOLTIP;

		_LMB = RscDisplayOptionsLayout_mouse select 0;
		_RMB = RscDisplayOptionsLayout_mouse select 1;

		if (count _LMB == 0 && count _RMB == 0) then {
			_ctrlTooltipPosition = ctrlposition _ctrlTooltip;
			_ctrlTooltipPositionX = _mX;
			_ctrlTooltipPositionY = _mY + 0.05;
			_ctrlTooltipPositionW = _ctrlTooltipPosition select 2;
			_ctrlTooltipPositionH = _ctrlTooltipPosition select 3;
			if (((safezoneX + safezoneW) - _ctrlTooltipPositionX) < _ctrlTooltipPositionW) then {_ctrlTooltipPositionX = _ctrlTooltipPositionX - _ctrlTooltipPositionW};
			if (((safezoneY + safezoneH) - _ctrlTooltipPositionY) < _ctrlTooltipPositionH) then {_ctrlTooltipPositionY = _mY - _ctrlTooltipPositionH};
			_ctrlTooltipPosition set [0,_ctrlTooltipPositionX];
			_ctrlTooltipPosition set [1,_ctrlTooltipPositionY];
			_ctrlTooltipPosition set [2,_ctrlTooltipPositionW];
			_ctrlTooltipPosition set [3,_ctrlTooltipPositionH];
			_ctrlTooltip ctrlsetposition _ctrlTooltipPosition;
			_ctrlTooltip ctrlcommit 0;
			_ctrlTooltip ctrlshow true;
		} else {
			_isLMB = count _LMB > 0;
			_mouseArray = if (_isLMB) then {_LMB} else {_RMB};
			_control = _mouseArray select 0;
			_clickX = _mouseArray select 1;
			_clickY = _mouseArray select 2;
			_controlPos = +(_mouseArray select 3);

			_dX = _mX - _clickX;
			_dY = _mY - _clickY;

			_data = RscDisplayOptionsLayout_data select (ctrlidc _control - IDCBASE);
			_tagName = _data select 0;
			_varName = _data select 1;
			_canResize = _data select 3;

			_grid = _data select 4;
			//_gridSize = _grid select 0;
			//_gridSizeX = (_gridSize select 0) call bis_fnc_parsenumber;
			//_gridSizeY = (_gridSize select 1) call bis_fnc_parsenumber;
			_gridX = ((_grid select 1) call bis_fnc_parsenumber) / 2;
			_gridY = ((_grid select 2) call bis_fnc_parsenumber) / 2;

			_posX = _controlPos select 0;
			_posY = _controlPos select 1;
			_posW = _controlPos select 2;
			_posH = _controlPos select 3;

			if (_isLMB) then {
				_posX = _posX + _dX;
				_posY = _posY + _dY;

				//_posX = _posX - (_posX % _gridX);// + (_gridSizeX % _gridX);
				//_posY = _posY - (_posY % _gridY);// + (_gridSizeY % _gridY);
			} else {
				if (_canResize) then {
					//--- Determine which corner user grabbed
					_posXcorner = if (_clickX < (_posX + _posW / 2)) then {
						//--- Left
						_posX = _posX + _dX;
						_posW = _posW - _dX;
						0
					} else {
						//--- Right
						_posW = _posW + _dX; // Right
						1
					};
					_posYcorner = if (_clickY < (_posY + _posH / 2)) then {
						//--- Top
						_posY = _posY + _dY;
						_posH = _posH - _dY;
						0
					} else {
						//--- Bottom
						_posH = _posH + _dY; // Bottom
						1
					};

					//if (_posXcorner == 0) then {_posX = _posX + (_posW % _gridX);};
					//if (_posYcorner == 0) then {_posY = _posY + (_posH % _gridY);};
					_posW = _posW - (_posW % _gridX);
					_posH = _posH - (_posH % _gridY);
					_posW = _posW max 0.01;
					_posH = _posH max 0.01;
				};
			};
			_pos = [_posX,_posY,_posW,_posH];

			_control ctrlsetposition _pos;
			_control ctrlcommit 0;
			_control ctrlsettextcolor [1,1,1,1];

			//--- Set preset to "<Custom>"
			_ctrlPresets = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_PRESETS;
			if (lbcursel _ctrlPresets > 0) then {_ctrlPresets lbsetcursel 0;};

			_varBase = _tagName + "_" + _varName + "_";
			uinamespace setvariable [_varBase + "X",_posX];
			uinamespace setvariable [_varBase + "Y",_posY];
			uinamespace setvariable [_varBase + "W",_posW];
			uinamespace setvariable [_varBase + "H",_posH];

			_ctrlTooltip ctrlshow false;
		};
	};
	case "mouseEnter": {
		_control = _params select 0;
		_display = ctrlparent _control;

		_LMB = RscDisplayOptionsLayout_mouse select 0;
		_RMB = RscDisplayOptionsLayout_mouse select 1;
		if (count _LMB == 0 && count _RMB == 0) then {
			_data = RscDisplayOptionsLayout_data select (ctrlidc _control - IDCBASE);
			_tooltip = _data select 2;

			_ctrlTooltip = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TOOLTIP;
			_ctrlTooltip ctrlshow true;
			_ctrlTooltip ctrlsetstructuredtext _tooltip;
			_ctrlTooltipPosition = ctrlposition _ctrlTooltip;
			_ctrlTooltipPosition set [3,ctrltextheight _ctrlTooltip];
			_ctrlTooltip ctrlsetposition _ctrlTooltipPosition;
			_ctrlTooltip ctrlcommit 0;
		};
	};

	case "mouseExit": {
		_control = _params select 0;
		_display = ctrlparent _control;
		_ctrlTooltip = _display displayctrl IDC_RSCDISPLAYOPTIONSLAYOUT_TOOLTIP;
		_ctrlTooltip ctrlshow false;
	};

	case "mouseButtonDown": {
		_control = _params select 0;
		_button = _params select 1;
		_mX = _params select 2;
		_mY = _params select 3;
		RscDisplayOptionsLayout_mouse set [_button,[_control,_mX,_mY,ctrlposition _control]];
	};

	case "mouseButtonUp": {
		_control = _params select 0;
		_button = _params select 1;
		RscDisplayOptionsLayout_mouse set [_button,[]];
	};

	case "buttonOK": {
		_params spawn {
			disableserialization;
			_ctrlButtonOk = _this select 0;
			_display = ctrlparent _ctrlButtonOk;

			_commit = [localize "str_msg_restart_needed",nil,nil,true,_display] call bis_fnc_guiMessage;

			if (_commit) then {

				//--- Remove preview variables
				{
					_tag = _x;
					_tagName = configname _tag;
					_presetName = uinamespace getvariable [_tagName + "preset",""];
					_varPreset = if (_presetName == "") then {""} else {"preset_"};

					profilenamespace setvariable [_tagName + "preset",_presetName];
					{
						_var = _x;
						_varName = configname _var;
						_varBase = _tagName + "_" + _varPreset + _varName + "_";
						_posX = uinamespace getvariable (_varBase + "X");
						_posY = uinamespace getvariable (_varBase + "Y");
						_posW = uinamespace getvariable (_varBase + "W");
						_posH = uinamespace getvariable (_varBase + "H");

						if ({isnil _x} count ["_posX","_posY","_posW","_posH"] == 0) then {

							//--- Convert numbers to strings, so value types are compatible
							//if (typename _posX == typename 0) then {_posX = str _posX;};
							//if (typename _posY == typename 0) then {_posY = str _posY;};
							//if (typename _posW == typename 0) then {_posW = str _posW;};
							//if (typename _posH == typename 0) then {_posH = str _posH;};
							_posX = _posX call bis_fnc_parsenumber;
							_posY = _posY call bis_fnc_parsenumber;
							_posW = _posW call bis_fnc_parsenumber;
							_posH = _posH call bis_fnc_parsenumber;

							_varBase = _tagName + "_" + _varName + "_";
							profilenamespace setvariable [_varBase + "X",_posX];
							profilenamespace setvariable [_varBase + "Y",_posY];
							profilenamespace setvariable [_varBase + "W",_posW];
							profilenamespace setvariable [_varBase + "H",_posH];
						};

					} foreach ((_tag >> "variables") call bis_fnc_subClasses);
				} foreach ((configfile >> "CfgUIGrids") call bis_fnc_subclasses);

				saveprofilenamespace;
				_display closedisplay IDC_CANCEL;
			};
		};
		true
	};
};