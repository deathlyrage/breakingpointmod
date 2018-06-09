_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;
disableserialization;

switch _mode do {

	//--- Display load
	case "onLoad": {
		
		//takes player's name from Main menu and sets it in Game Options
		private ["_display"];

		//take display that is being created (Game options)
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 601) ctrlSetText profileName;
		[_display, 601] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//Sets all texts toUpper
		["RscDisplayGameOptions",["RscText","RscTitle","CA_TextLanguage"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;
		
		//--- General button
		_control = _display displayctrl 2402;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['general',_this,''] call RscDisplayGameOptions_script};"];
		//--- Set focus to GENERAL button
		ctrlSetFocus _control;
		
		//--- Difficulty button
		_control = _display displayctrl 304;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['difficulty',_this,''] call RscDisplayGameOptions_script};"];
		
		//--- Interface colors button
		_control = _display displayctrl 2404;
		_control ctrladdeventhandler ["buttonclick","with uinamespace do {['colors',_this,''] call RscDisplayGameOptions_script};"];
		
		//--- Disable Interface colors group
		_ColorsGroup = _display displayctrl 2301;
		_ColorsGroup ctrlenable false;
		_ColorsGroup ctrlshow false;
		
		//--- Disable Difficulty Default button
		_DefaultButton = _display displayctrl 104;
		_DefaultButton ctrlenable false;
		_DefaultButton ctrlshow false;
		
		
		//Shows/hides UI elements in DifficultyGroup depending on parameter and AI Level ComboBox selected item.
		//Must be done per item, otherwise ControlsGroup shows AI Level controls when not desired.
		RscDisplayGameOptions_showDifficultyGroup = {
		
			_display = _this select 0;
			_show = _this select 1;
			_DifficultyGroupControls = configfile >> "RscDisplayGameOptions" >> "controls" >> "DifficultyGroup" >> "controls";
			_aiLevelIndex = lbCurSel (_display displayctrl 1511);
			
			for "_i" from 0 to (count _DifficultyGroupControls - 1) do
			{
				_difficultyControl = _DifficultyGroupControls select _i;
				_idc = getnumber (_difficultyControl >> "idc");
				_control = _display displayctrl _idc;
				
				if(_show) then
				{
					//Show only if AI Level is set to Custom
					if(_idc in [1512, 1513, 1514, 1515, 1516, 1517]) then
					{
						//AI Settings
						if(_aiLevelIndex == 3) then //TODO - read this from config (CfgAILevelPresets)
						{
							_control ctrlenable true;
							_control ctrlshow true;
						}
						else
						{
							_control ctrlenable false;
							_control ctrlshow false;
						};
					}
					else
					{
						//Non AI settings
						_control ctrlenable true;
						_control ctrlshow true;
					};
				}
				else
				{
					_control ctrlenable false;
					_control ctrlshow false;	
				};
			};	
		};
		
		//--- Disable and hide Difficulty group
		_DifficultyGroup = _display displayctrl 2302;
		_DifficultyGroup ctrlenable false;
		[_display, false] call RscDisplayGameOptions_showDifficultyGroup;

		_aiLevelComboBox = _display displayctrl 1511;		
		_aiLevelComboBox ctrladdeventhandler ["LBSelChanged","with uinamespace do {['aiLevel',_this,''] call RscDisplayGameOptions_script};"];


		//Karel's script---------------------------------------------------------------------------------------------
		//--- Functions are stored in uiNameSpace
		with uinamespace do {

			//_display = _params select 0;
			RscDisplayGameOptions_display = _display;

			//--- Load color preset
			_presetName = profileNameSpace getvariable ["GUI_BCG_RGB_preset",""];

			//--- Backup current values
/*
			RscDisplayGameOptions_current = [
				profilenamespace getvariable "GUI_BCG_RGB_R",
				profilenamespace getvariable "GUI_BCG_RGB_G",
				profilenamespace getvariable "GUI_BCG_RGB_B",
				profilenamespace getvariable "GUI_BCG_RGB_A",
				_presetName
			];
*/

			//--- Get IDCs
			_cfgDisplay = configfile >> _class;
			RscDisplayGameOptions_listTags =		_display displayctrl ([_cfgDisplay,"ListTags"] call bis_fnc_getIDC);
			RscDisplayGameOptions_listVariables =		_display displayctrl ([_cfgDisplay,"ListVariables"] call bis_fnc_getIDC);
			RscDisplayGameOptions_listPresets =		_display displayctrl ([_cfgDisplay,"ListPresets"] call bis_fnc_getIDC);
			RscDisplayGameOptions_buttonCancel =		_display displayctrl ([_cfgDisplay,"ButtonCancel"] call bis_fnc_getIDC);//changed CA_ButtonCancel
			RscDisplayGameOptions_buttonOK =		_display displayctrl ([_cfgDisplay,"ButtonOKscripted"] call bis_fnc_getIDC);	//changed CA_ButtonContinue
			RscDisplayGameOptions_sliderColorR =		_display displayctrl ([_cfgDisplay,"sliderColorR"] call bis_fnc_getIDC);
			RscDisplayGameOptions_sliderColorG =		_display displayctrl ([_cfgDisplay,"sliderColorG"] call bis_fnc_getIDC);
			RscDisplayGameOptions_sliderColorB =		_display displayctrl ([_cfgDisplay,"sliderColorB"] call bis_fnc_getIDC);
			RscDisplayGameOptions_sliderColorA =		_display displayctrl ([_cfgDisplay,"sliderColorA"] call bis_fnc_getIDC);
			RscDisplayGameOptions_valueColorR =		_display displayctrl ([_cfgDisplay,"valueColorR"] call bis_fnc_getIDC);
			RscDisplayGameOptions_valueColorG =		_display displayctrl ([_cfgDisplay,"valueColorG"] call bis_fnc_getIDC);
			RscDisplayGameOptions_valueColorB =		_display displayctrl ([_cfgDisplay,"valueColorB"] call bis_fnc_getIDC);
			RscDisplayGameOptions_valueColorA =		_display displayctrl ([_cfgDisplay,"valueColorA"] call bis_fnc_getIDC);
			RscDisplayGameOptions_preview =			_display displayctrl ([_cfgDisplay,"preview"] call bis_fnc_getIDC);
			RscDisplayGameOptions_previewBackground =	_display displayctrl ([_cfgDisplay,"previewBackground"] call bis_fnc_getIDC);


			//--- Button OK - save changes
			RscDisplayGameOptions_buttonOK_activated = false;
			RscDisplayGameOptions_buttonOK_action = {
					disableserialization;

					//_warning = [localize 'STR_MSG_RESTART_NEEDED',nil,nil,[localize 'STR_DISP_OK',nil],uinamespace getvariable 'RscDisplayGameOptions_display'] call bis_fnc_guiMessage;
					//--- Warning window temporarily removed
					_warning = [true];

					if (_warning select 0) then {
						RscDisplayGameOptions_buttonOK_activated = true;

						//(uinamespace getvariable 'RscDisplayGameOptions_display') closedisplay 3000; //Not needed (had broken options saving), display is closed by the engine

						{
							[configfile >> (GUI_classes select _foreachindex),_x] call bis_fnc_displayColorSet;
						} foreach GUI_displays;
		
						saveProfileNamespace;
					};//--- ToDo: Do not change display colors always (only for BCG_RGB)

					//--- Activate real button
					ctrlactivate ((uinamespace getvariable 'RscDisplayGameOptions_display') displayctrl 1);
			};


			//--- On slider moving (executed in uiNameSpace)
			RscDisplayGameOptions_SliderPosChanged = {
				_params = _this select 0;
				_display = _params select 0;
				_sliderPos = _params select 1;
				_sliderPos = _sliderPos / 10;
				_sliderId = _this select 1;
				_manual = _this select 2;

				_tag = RscDisplayGameOptions_listTags lbdata (lbcursel RscDisplayGameOptions_listTags);
				_varName = RscDisplayGameOptions_listVariables lbdata (lbcursel RscDisplayGameOptions_listVariables);
				_var = _tag + "_" + _varName + "_";

				_varList = [
					(_var + "R"),
					(_var + "G"),
					(_var + "B"),
					(_var + "A")
				];
				_valueList = [
					RscDisplayGameOptions_valueColorR,
					RscDisplayGameOptions_valueColorG,
					RscDisplayGameOptions_valueColorB,
					RscDisplayGameOptions_valueColorA
				];

				//--- No longer preset - set listbox to first item ("<Custom>")
				if (_manual && lbcursel RscDisplayGameOptions_listPresets > 0) then {

					//--- Move slide manually, because an issue prevents it from moving automatically
					_slider = [
						RscDisplayGameOptions_sliderColorR,
						RscDisplayGameOptions_sliderColorG,
						RscDisplayGameOptions_sliderColorB,
						RscDisplayGameOptions_sliderColorA
					] select _sliderID;
					[_slider,_sliderPos * 10] spawn {
						disableserialization;
						_this call bis_fnc_log;
						(_this select 0) slidersetposition (_this select 1);
					};
					RscDisplayGameOptions_listPresets lbsetcursel 0;
				};

				//--- Show value
				_valueText = (round (_sliderPos * 100));
				_value = _valueList select _sliderId;
				_value ctrlsettext (str _valueText + "%");

				//--- Save into profile and preview
				profilenamespace setvariable [_varList select _sliderId,_sliderPos];

				//--- Preview
				_preview = RscDisplayGameOptions_previewPath;
				if (_preview != "") then {
					if (_preview == "bcg") then {
						[configfile >> "RscDisplayGameOptions",ctrlparent _display] call bis_fnc_displayColorSet;
					} else {
						//--- Must be spawned, for some reason it doesn't work when used immediately
						_varList spawn {
							_varList = _this;
							with uinamespace do {
								RscDisplayGameOptions_preview ctrlsettextcolor [
									profilenamespace getvariable (_varList select 0),
									profilenamespace getvariable (_varList select 1),
									profilenamespace getvariable (_varList select 2),
									profilenamespace getvariable (_varList select 3)
								];
								RscDisplayGameOptions_preview ctrlcommit 0;
							};
						};
					};
				};

				//--- Change listbox preview picture
				RscDisplayGameOptions_listVariables lbsetpicture [
					lbcursel RscDisplayGameOptions_listVariables,
					format [
						"#(argb,8,8,3)color(%1,%2,%3,%4)",
						profilenamespace getvariable (_varList select 0),
						profilenamespace getvariable (_varList select 1),
						profilenamespace getvariable (_varList select 2),
						profilenamespace getvariable (_varList select 3)
					]
				];
			};
			{
				_x ctrladdeventhandler [
					"SliderPosChanged",
					format ["with uinamespace do {[_this,%1,true] call RscDisplayGameOptions_SliderPosChanged};",_forEachIndex]
				];
			} foreach [
				RscDisplayGameOptions_sliderColorR,
				RscDisplayGameOptions_sliderColorG,
				RscDisplayGameOptions_sliderColorB,
				RscDisplayGameOptions_sliderColorA
			];

			//--- On tag selected
			RscDisplayGameOptions_listTags_LBSelChanged = {
				lbclear RscDisplayGameOptions_listVariables;
				_cursel = lbcursel RscDisplayGameOptions_listTags;
				profilenamespace setvariable ["RscDisplayGameOptions_listTagsCurSel",_cursel];

				_tag = RscDisplayGameOptions_listTags lbdata _cursel;
				_cfgVariables = configfile >> "CfgUIColors" >> _tag >> "Variables";
				for "_i" from 0 to (count _cfgVariables - 1) do {
					_current = _cfgVariables select _i;

					if (isclass _current) then {
						_currentName = configname _current;

						//--- Add preset name to the list
						_displayName = _current call bis_fnc_displayName;
						_lbAdd = RscDisplayGameOptions_listVariables lbadd _displayName;
						RscDisplayGameOptions_listVariables lbsetdata [_lbAdd,_currentName];

						//--- Show color preview
						_colorVar = _tag + "_" + _currentName + "_";
						_color = format [
							"#(argb,8,8,3)color(%1,%2,%3,%4)",
							profilenamespace getvariable (_colorVar + "R"),
							profilenamespace getvariable (_colorVar + "G"),
							profilenamespace getvariable (_colorVar + "B"),
							profilenamespace getvariable (_colorVar + "A")
						];
						RscDisplayGameOptions_listVariables lbsetpicture [_lbAdd,_color];
					};
				};
				RscDisplayGameOptions_listVariables lbsetcursel 0;
				//RscDisplayGameOptions_listPresets lbsetcursel 0;
			};

			//--- On variable selected
			RscDisplayGameOptions_listVariables_LBSelChanged = {
				lbclear RscDisplayGameOptions_listPresets;

				_tag = RscDisplayGameOptions_listTags lbdata (lbcursel RscDisplayGameOptions_listTags);
				_varName = RscDisplayGameOptions_listVariables lbdata (lbcursel RscDisplayGameOptions_listVariables);
				_var = _tag + "_" + _varName + "_";
				_presetName = profileNameSpace getvariable [_var + "preset",""];
				_cfgVariable = configfile >> "CfgUIColors" >> _tag >> "Variables" >> _varName;

				//--- Preview background
				_previewBackground = [_cfgVariable,"previewBackground"] call BIS_fnc_returnConfigEntry;
				RscDisplayGameOptions_previewBackground ctrlsettext "";
				switch (typename _previewBackground) do {
					case (typename 1): {
						
					};
					case (typename ""): {
						RscDisplayGameOptions_previewBackground ctrlsettext _previewBackground;
					};
				};

				//--- Preview
				_preview = [_cfgVariable,"preview"] call BIS_fnc_returnConfigEntry;
				RscDisplayGameOptions_preview ctrlsettext "";
				RscDisplayGameOptions_previewPath = switch (typename _preview) do {
					case (typename 1): {
						if (_preview == 1) then {"bcg"} else {""};
					};
					case (typename ""): {

						_w = [_cfgVariable >> "previewW"] call bis_fnc_parsenumber;
						_h = [_cfgVariable >> "previewH"] call bis_fnc_parsenumber;
						if (_w > 0 && _h > 0) then {
							_posBcg = ctrlposition RscDisplayGameOptions_previewBackground;
							_x = (_posBcg select 0) + (_posBcg select 2) / 2;
							_y = (_posBcg select 1) + (_posBcg select 3) / 2;
							RscDisplayGameOptions_preview ctrlsetposition [
								_x - (_w / 2),
								_y - (_h / 2),
								_w,
								_h
							];	
						};

						RscDisplayGameOptions_preview ctrlsettext _preview;
						_preview
					};
					default {""};
				};

				//--- Load presets
				_lbAdd = RscDisplayGameOptions_listPresets lbadd (localize "str_a3_rscdisplayoptionslayout_custom");
				RscDisplayGameOptions_listPresets lbsetdata [_lbAdd,""];
				RscDisplayGameOptions_listPresets lbsetcursel 0;

				_CfgUIColors = configfile >> "CfgUIColors" >> _tag >> "Presets";
				for "_i" from 0 to (count _CfgUIColors - 1) do {
					_current = _CfgUIColors select _i;
					if (isclass _current) then {
						_currentVar = _current >> "Variables" >> _varName;
						if (isarray _currentVar) then {

							_currentName = configname _current;
							_default = getnumber (_current >> "default");

							//--- Add preset name to the list
							_displayName = _current call bis_fnc_displayName;
							if (_default > 0) then {_displayName = format ["%1 (%2)",_displayName,localize "str_disp_default"];};
							_lbAdd = RscDisplayGameOptions_listPresets lbadd _displayName;
							RscDisplayGameOptions_listPresets lbsetdata [_lbAdd,_currentName];

							//--- Current preset - set as selected
							if (_currentName == _presetName) then {RscDisplayGameOptions_listPresets lbsetcursel _lbAdd};
						};
					};
				};
				if (lbcursel RscDisplayGameOptions_listPresets < 0) then {RscDisplayGameOptions_listPresets lbsetcursel 0};
			};


			//--- On preset selected (executed in uiNameSpace)
			RscDisplayGameOptions_listPresets_LBSelChanged = {
				private ["_display","_lbId","_lbData","_cfgPreset","_colorBackground","_colorR","_colorG","_colorB","_colorA","_sliderList","_valueList"];
				_display = _this select 0;
				_lbId = _this select 1;
				_lbData = _display lbdata _lbId;

				_tag = RscDisplayGameOptions_listTags lbdata (lbcursel RscDisplayGameOptions_listTags);
				_varName = RscDisplayGameOptions_listVariables lbdata (lbcursel RscDisplayGameOptions_listVariables);
				_var = _tag + "_" + _varName + "_";

				_cfgPresetVariables = configfile >> "CfgUIColors" >> _tag >> "Presets" >> _lbData >> "Variables";
				_colorBackground = getarray (_cfgPresetVariables >> _varName);
				if (count _colorBackground == 4) then {

					_colorR = _colorBackground select 0;
					_colorG = _colorBackground select 1;
					_colorB = _colorBackground select 2;
					_colorA = _colorBackground select 3;
				} else {
					_colorR = profilenamespace getvariable (_var + "R");
					_colorG = profilenamespace getvariable (_var + "G");
					_colorB = profilenamespace getvariable (_var + "B");
					_colorA = profilenamespace getvariable (_var + "A");
				};

				if (typename _colorR == typename "") then {_colorR = call compile _colorR};
				if (typename _colorG == typename "") then {_colorG = call compile _colorG};
				if (typename _colorB == typename "") then {_colorB = call compile _colorB};
				if (typename _colorA == typename "") then {_colorA = call compile _colorA};

				RscDisplayGameOptions_sliderColorR slidersetposition (_colorR)*10;
				RscDisplayGameOptions_sliderColorG slidersetposition (_colorG)*10;
				RscDisplayGameOptions_sliderColorB slidersetposition (_colorB)*10;
				RscDisplayGameOptions_sliderColorA slidersetposition (_colorA)*10;

				//--- Set slider positions (handler is not doing it automatically)
				_sliderList = [RscDisplayGameOptions_sliderColorR,RscDisplayGameOptions_sliderColorG,RscDisplayGameOptions_sliderColorB,RscDisplayGameOptions_sliderColorA];
				_valueList = [_colorR,_colorG,_colorB,_colorA];
				{
					[
						[_sliderList select _forEachIndex,_x * 10],
						_forEachIndex,
						false
					] call RscDisplayGameOptions_SliderPosChanged;
				} foreach _valueList;

				//--- Modify related variables
				_cfgVariables = configfile >> "CfgUIColors" >> _tag >> "Variables";
				_n = 0;
				for "_v" from 0 to (count _cfgVariables - 1) do {
					_relatedVarClass = _cfgVariables select _v;
					if (isclass _relatedVarClass) then {
						_relatedVarName = configname _relatedVarClass;
						_relatedVar = _tag + "_" + _relatedVarName + "_";
						_relatedVarColor = getarray (_cfgPresetVariables >> _relatedVarName);
						if (count _relatedVarColor == 4) then {
							_colorR = _relatedVarColor select 0;
							_colorG = _relatedVarColor select 1;
							_colorB = _relatedVarColor select 2;
							_colorA = _relatedVarColor select 3;
							if (typename _colorR == typename "") then {_colorR = call compile _colorR};
							if (typename _colorG == typename "") then {_colorG = call compile _colorG};
							if (typename _colorB == typename "") then {_colorB = call compile _colorB};
							if (typename _colorA == typename "") then {_colorA = call compile _colorA};
							profileNameSpace setvariable [_relatedVar + "R",_colorR];
							profileNameSpace setvariable [_relatedVar + "G",_colorG];
							profileNameSpace setvariable [_relatedVar + "B",_colorB];
							profileNameSpace setvariable [_relatedVar + "A",_colorA];

							//--- Change listbox preview picture
							RscDisplayGameOptions_listVariables lbsetpicture [
								_n,
								format ["#(argb,8,8,3)color(%1,%2,%3,%4)",_colorR,_colorG,_colorB,_colorA]
							];
						};
						profileNameSpace setvariable [_relatedVar + "preset",_lbData];
						_n = _n + 1;
					};
				};

				//--- Refresh real-time preview
				[configfile >> "RscDisplayGameOptions",ctrlparent _display] call bis_fnc_displayColorSet;

				//--- Save preset into profileNameSpace
				profileNameSpace setvariable [_var + "preset",_lbData];
				//saveProfileNamespace;
			};
			RscDisplayGameOptions_listTags ctrladdeventhandler [
				"LBSelChanged",
				"with uinamespace do {_this call RscDisplayGameOptions_listTags_LBSelChanged};"
			];
			RscDisplayGameOptions_listVariables ctrladdeventhandler [
				"LBSelChanged",
				"with uinamespace do {_this call RscDisplayGameOptions_listVariables_LBSelChanged};"
			];
			RscDisplayGameOptions_listPresets ctrladdeventhandler [
				"LBSelChanged",
				"with uinamespace do {_this call RscDisplayGameOptions_listPresets_LBSelChanged};"
			];
			//RscDisplayGameOptions_buttonOK buttonsetaction "with uinamespace do {[] spawn RscDisplayGameOptions_buttonOK_action;};";

			RscDisplayGameOptions_buttonOK ctrladdeventhandler [
				"buttonclick",
				"with uinamespace do {[] spawn RscDisplayGameOptions_buttonOK_action;};"
			];


			//--- Load Tags
			RscDisplayGameOptions_currentNames = [];
			RscDisplayGameOptions_currentValues = [];
			_CfgUIColors = configfile >> "CfgUIColors";
			for "_i" from 0 to (count _CfgUIColors - 1) do {
				_current = _CfgUIColors select _i;
				if (isclass _current) then {
					_currentName = configname _current;

					//--- Add tag name to the list
					_displayName = _current call bis_fnc_displayName;
					_lbAdd = RscDisplayGameOptions_listTags lbadd _displayName;
					RscDisplayGameOptions_listTags lbsetdata [_lbAdd,_currentName];

					//--- Backup
					_cfgVariables = _current >> "variables";
					for "_v" from 0 to (count _cfgVariables - 1) do {
						_varName = _cfgVariables select _v;
						if (isclass _varName) then {
							_var = _currentName + "_" + configname _varName;
							_varR = _var + "_R";
							_varG = _var + "_G";
							_varB = _var + "_B";
							_varA = _var + "_A";
							_varPreset = _var + "_preset";

							RscDisplayGameOptions_currentNames set [count RscDisplayGameOptions_currentNames,_varR];
							RscDisplayGameOptions_currentNames set [count RscDisplayGameOptions_currentNames,_varG];
							RscDisplayGameOptions_currentNames set [count RscDisplayGameOptions_currentNames,_varB];
							RscDisplayGameOptions_currentNames set [count RscDisplayGameOptions_currentNames,_varA];
							RscDisplayGameOptions_currentNames set [count RscDisplayGameOptions_currentNames,_varPreset];

							RscDisplayGameOptions_currentValues set [count RscDisplayGameOptions_currentValues,profilenamespace getvariable [_varR,0]];
							RscDisplayGameOptions_currentValues set [count RscDisplayGameOptions_currentValues,profilenamespace getvariable [_varG,0]];
							RscDisplayGameOptions_currentValues set [count RscDisplayGameOptions_currentValues,profilenamespace getvariable [_varB,0]];
							RscDisplayGameOptions_currentValues set [count RscDisplayGameOptions_currentValues,profilenamespace getvariable [_varA,1]];
							RscDisplayGameOptions_currentValues set [count RscDisplayGameOptions_currentValues,profilenamespace getvariable [_varPreset,""]];
						};
					};
				};
			};
			if (lbcursel RscDisplayGameOptions_listTags < 0) then {RscDisplayGameOptions_listTags lbsetcursel (profilenamespace getvariable ["RscDisplayGameOptions_listTagsCurSel",0])};
		};
		//Karel's script---------------------------------------------------------------------------------------------
		
	};
	
	//--- General button
	case "general": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_GeneralGroup = _display displayctrl 2300;
		_ColorsGroup = _display displayctrl 2301;
		_DifficultyGroup = _display displayctrl 2302;
		_ctrlGeneral = _display displayctrl 2402;	//GENERAL button
		_DefaultButton = _display displayctrl 104;	//Difficulty Default button
		
		//--- Enable General
		_GeneralGroup ctrlenable true;
		_GeneralGroup ctrlshow true;
		
		//--- Disable Difficulty
		_DifficultyGroup ctrlenable false;
		//_DifficultyGroup ctrlshow false;
		[_display, false] call RscDisplayGameOptions_showDifficultyGroup;
		
		//--- Disable Difficulty Default button
		_DefaultButton ctrlenable false;
		_DefaultButton ctrlshow false;
		
		//--- Disable Colors
		_ColorsGroup ctrlenable false;
		_ColorsGroup ctrlshow false;
		
		//--- Set focus to GENERAL button
		ctrlSetFocus _ctrlGeneral;
	};
	
	//--- Difficulty button
	case "difficulty": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_GeneralGroup = _display displayctrl 2300;
		_ColorsGroup = _display displayctrl 2301;
		_DifficultyGroup = _display displayctrl 2302;
		_ctrlDifficulty = _display displayctrl 304;	//DIFFICULTY button
		_DefaultButton = _display displayctrl 104;	//Difficulty Default button
		
		//--- Enable Difficulty
		_DifficultyGroup ctrlenable true;
		//_DifficultyGroup ctrlshow true;
		[_display, true] call RscDisplayGameOptions_showDifficultyGroup;
		
		//--- Enable Difficulty Default button
		_DefaultButton ctrlenable true;
		_DefaultButton ctrlshow true;
		
		//--- Disable General
		_GeneralGroup ctrlenable false;
		_GeneralGroup ctrlshow false;
		
		//--- Disable Colors
		_ColorsGroup ctrlenable false;
		_ColorsGroup ctrlshow false;
		
		//--- Set focus to DIFFICULTY button
		ctrlSetFocus _ctrlDifficulty;
	};

	//--- Interface colors button
	case "colors": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_GeneralGroup = _display displayctrl 2300;
		_ColorsGroup = _display displayctrl 2301;
		_DifficultyGroup = _display displayctrl 2302;
		_ctrlColors = _display displayctrl 2404;	//COLORS button
		_DefaultButton = _display displayctrl 104;	//Difficulty Default button
		
		//--- Enable Colors
		_ColorsGroup ctrlenable true;
		_ColorsGroup ctrlshow true;
		
		//--- Disable General
		_GeneralGroup ctrlenable false;
		_GeneralGroup ctrlshow false;
		
		//--- Disable Difficulty
		_DifficultyGroup ctrlenable false;
		//_DifficultyGroup ctrlshow false;
		[_display, false] call RscDisplayGameOptions_showDifficultyGroup;
		
		//--- Disable Difficulty Default button
		_DefaultButton ctrlenable false;
		_DefaultButton ctrlshow false;
		
		//--- Set focus to GENERAL button
		ctrlSetFocus _ctrlColors;
	};
	
	//--- AI Level ComboBox
	case "aiLevel": {
	
		//If the ComboBox is enabled, it means we are on Difficulty page - all items
		//should be enabled. Sliders are enabled only if Custom is selected in ComboBox.
		_aiLevelComboBox = _params select 0;	
		_display = ctrlparent _aiLevelComboBox;
		[_display, true] call RscDisplayGameOptions_showDifficultyGroup;	
	};
	
	case "onUnload": {
	
		if(isStreamFriendlyUIEnabled) then
		{
			{
				_displayIDD = ctrlIDD _x;
			
				//0-Main Menu, 49-RscDisplayMovieInterrupt, 49-RscDisplayMPInterrupt
				if( (_displayIDD == 0) || (_displayIDD == 49) ) then
				{
					(_x displayctrl 109) ctrlSetFade 1; //109-MainMenu, Interrupt, MovieInterrupt, MPInterrupt;    8434-Campaign, Single Mission
					(_x displayctrl 109) ctrlCommit 0;
				};
				
				//2-Scenarios, 43-Campaign
				if( (_displayIDD == 2) || (_displayIDD == 43) ) then
				{
					(_x displayctrl 8434) ctrlSetFade 1;
					(_x displayctrl 8434) ctrlCommit 0;
				};
				
				//12-ingame map, 37-SP Briefing, 52-MP Server Briefing, 53-MP Client Briefing
				if( (_displayIDD == 12) || (_displayIDD == 37) || (_displayIDD == 52) || (_displayIDD == 53) ) then
				{
					(_x displayctrl 111) ctrlSetFade 1;
					(_x displayctrl 111) ctrlCommit 0;
				};
			}
			foreach (uinamespace getvariable "gui_displays");
		}
		else
		{
			//show player's name again
			{
				_displayIDD = ctrlIDD _x;
			
				//0-Main Menu, 49-RscDisplayMovieInterrupt, 49-RscDisplayMPInterrupt
				if( (_displayIDD == 0) || (_displayIDD == 49) ) then
				{
					(_x displayctrl 109) ctrlSetText profileName;
					(_x displayctrl 109) ctrlSetFade 0;
					(_x displayctrl 109) ctrlCommit 0;
				};
				
				//2-Scenarios, 43-Campaign
				if( (_displayIDD == 2) || (_displayIDD == 43) ) then
				{
					(_x displayctrl 8434) ctrlSetText profileName;
					(_x displayctrl 8434) ctrlSetFade 0;
					(_x displayctrl 8434) ctrlCommit 0;
				};
				
				//12-ingame map, 37-SP Briefing, 52-MP Server Briefing, 53-MP Client Briefing
				if( (_displayIDD == 12) || (_displayIDD == 37) || (_displayIDD == 52) || (_displayIDD == 53) ) then
				{
					(_x displayctrl 111) ctrlSetText profileName;
					(_x displayctrl 111) ctrlSetFade 0;
					(_x displayctrl 111) ctrlCommit 0;
				};
			}
			foreach (uinamespace getvariable "gui_displays");
		};
	
	//Karel's script---------------------------------------------------------------------------------------------
		with uinamespace do {

			//--- Reset Defaults
			if !(RscDisplayGameOptions_buttonOK_activated) then {

				{
					profilenamespace setvariable [_x,RscDisplayGameOptions_currentValues select _foreachindex];
				} foreach RscDisplayGameOptions_currentNames;
			};

			//--- Nil variable
			RscDisplayGameOptions_display = nil;
			RscDisplayGameOptions_SliderPosChanged = nil;
			RscDisplayGameOptions_listTags_LBSelChanged = nil;
			RscDisplayGameOptions_listVariables_LBSelChanged = nil;
			RscDisplayGameOptions_listPresets_LBSelChanged = nil;
			RscDisplayGameOptions_listTags = nil;
			RscDisplayGameOptions_listVariables = nil;
			RscDisplayGameOptions_listPresets = nil;
			RscDisplayGameOptions_buttonCancel = nil;
			RscDisplayGameOptions_buttonOK = nil;
			RscDisplayGameOptions_buttonOK_action = nil;
			RscDisplayGameOptions_buttonOK_activated = nil;
			RscDisplayGameOptions_sliderColorR = nil;
			RscDisplayGameOptions_sliderColorG = nil;
			RscDisplayGameOptions_sliderColorB = nil;
			RscDisplayGameOptions_sliderColorA = nil;
			RscDisplayGameOptions_valueColorR = nil;
			RscDisplayGameOptions_valueColorG = nil;
			RscDisplayGameOptions_valueColorB = nil;
			RscDisplayGameOptions_valueColorA = nil;
			RscDisplayGameOptions_currentNames = nil;
			RscDisplayGameOptions_currentValues = nil;
			RscDisplayGameOptions_showDifficultyGroup = nil;

		};
	//Karel's script---------------------------------------------------------------------------------------------
		
	};

	//--- Nothing
	default {};
};