#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

private ["_mode","_params","_class"];
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;
		_init = true;

		//--- Menu already opened - use it and close the duplicate one
		if !(isnull (uinamespace getvariable ["RscDisplayRespawn_display",displaynull])) then {
			_display closedisplay 0;
			_display = RscDisplayRespawn_display;
			_init = false;
		};
		RscDisplayRespawn_display = _display;

		_ctrlSection = _display displayctrl IDC_RSCDISPLAYRESPAWN_SECTION;
		_ctrlButtonOK = _display displayctrl IDC_OK;
		_ctrlButtonCancel = _display displayctrl IDC_CANCEL;
		_ctrlTitle = _display displayctrl IDC_RSCDISPLAYRESPAWN_TITLE;

		_ctrlListBackground = _display displayctrl IDC_RSCDISPLAYRESPAWN_LISTBACKGROUND;
		_ctrlList = _display displayctrl IDC_RSCDISPLAYRESPAWN_LIST;
		_ctrlContentBackground = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENTBACKGROUND;
		_ctrlContentGroup = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENTGROUP;
		_ctrlContent = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENT;
		_ctrlMap = _display displayctrl IDC_RSCDISPLAYRESPAWN_MAP;

		if (_init) then {
			RscDisplayRespawn_defaultPositions = [
				ctrlposition _ctrlListBackground,
				ctrlposition _ctrlList,
				ctrlposition _ctrlContentBackground,
				ctrlposition _ctrlContentGroup,
				ctrlposition _ctrlContent,
				ctrlposition _ctrlMap
			];
			_ctrlSection ctrladdeventhandler ["lbselchanged",format ["with uinamespace do {['init',_this,'%1'] call %1_script};",_class]];
			RscDisplayRespawn_currentSection = -1;
		};

		_sectionsData = uinamespace getvariable ["RscDisplayRespawn_sections",[displaynull,[]]];
		_sectionsDisplay = _sectionsData select 0;
		_sections = if (_sectionsDIsplay == _display) then {_sectionsData select 1} else {[]};

		//--- Initialize sections
		_newSection = missionnamespace getvariable ["RscDisplayRespawn_section",[]];
		_newSectionText = [_newSection,0,"",[""]] call bis_fnc_paramin;
		_newSectionCode = [_newSection,1,{},[{}]] call bis_fnc_paramin;
		if (_newSectionText != "") then {
			_sections set [count _sections,[_newSectionText,_newSectionCode]];
			RscDisplayRespawn_sections = [_display,_sections];
			_sectionsOffset = 0;
			_sectionText = "%1 (%2/%3)";
			if (count _sections == 1) then {
				_sections = _sections + _sections;
				_sectionsOffset = 1;
				_sectionText = "%1";
			};

			_ctrlSection = _display displayctrl IDC_RSCDISPLAYRESPAWN_SECTION;
			lbclear _ctrlSection;
			{
				_text = _x select 0;
				_lbAdd = _ctrlSection lbadd format [_sectionText,_text,_foreachindex + 1,count _sections];
				_ctrlSection lbsetvalue [_lbAdd,_sectionsOffset];
			} foreach _sections;
			_ctrlSection lbsetcursel 0;
		};

		if (_init) then {
			_ppCommitTime = 0;

			_saturation = 0.0 + random 0.3;
			_ppColor = ppEffectCreate ["ColorCorrections", 1999];
			_ppColor ppEffectEnable true;
			_ppColor ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [1, 0.25, 0, 1.0]];
			_ppColor ppEffectCommit 0;
			_ppColor ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1 - _saturation, 1 - _saturation, 1 - _saturation, _saturation], [1, 0.25, 0, 1.0]];
			_ppColor ppEffectCommit _ppCommitTime;

			_ppGrain = ppEffectCreate ["filmGrain", 2012];
			_ppGrain ppEffectEnable true;
			_ppGrain ppEffectAdjust [0, 1, 1, 0, 1];
			_ppGrain ppEffectCommit 0;
			_ppGrain ppEffectAdjust [random 0.2, 1, 1, 0, 1];
			_ppGrain ppEffectCommit _ppCommitTime;

			_ppBlur = ppEffectCreate ["dynamicBlur", 475];
			_ppBlur ppEffectEnable true;
			_ppBlur ppEffectAdjust [0];
			_ppBlur ppEffectCommit 0;
			_ppBlur ppEffectAdjust [3];
			_ppBlur ppEffectCommit _ppCommitTime;
			RscDisplayRespawn_ppEffects = [_ppColor,_ppGrain,_ppBlur];

			_ctrlListBackground ctrlenable false;
			_ctrlContentBackground ctrlenable false;

			_ctrlBlack = _display displayctrl IDC_RSCDISPLAYRESPAWN_BLACK;
			_ctrlBlack ctrlsetfade 1;
			_ctrlBlack ctrlcommit 0.5;

			_ctrlBlackContent = _display displayctrl IDC_RSCDISPLAYRESPAWN_BLACKCONTENT;
			_ctrlBlackContent ctrlsetfade 1;
			_ctrlBlackContent ctrlcommit 0;

			_ctrlButtonOK ctrlenable false;
			_ctrlButtonOK ctrladdeventhandler ["buttonclick",format ["with uinamespace do {['buttonOK',_this,'%1'] call %1_script};",_class]];
			_ctrlButtonCancel ctrladdeventhandler ["buttonclick",format ["with uinamespace do {['buttonCancel',_this,'%1'] call %1_script};",_class]];
			_display displayaddeventhandler ["keydown",format ["with uinamespace do {['keyDown',_this,'%1'] call %1_script};",_class]];

			_ctrlList ctrlsetfontheight IGUI_GRID_WEAPON_H;

			//--- set player's name
			_ctrlPlayersName = _display displayctrl IDC_RSCDISPLAYRESPAWN_PLAYERSNAME;
			_ctrlPlayersName ctrlSetText profileName;
			_ctrlPlayersName call BIS_fnc_setIDCStreamFriendly;

			//--- Respawn counter
			[_ctrlTitle,_ctrlButtonOK,_class,_ppColor,_ppGrain,_ppBlur] spawn {
				scriptname "RscDisplayRespawn: Counter";
				disableserialization;
				_ctrlTitle = _this select 0;
				_ctrlButtonOK = _this select 1;
				_class  = _this select 2;
				_ppColor = _this select 3;
				_ppGrain = _this select 4;
				_ppBlur = _this select 5;

				_textDefault = localize "STR_A3_RscDisplayRespawn_ButtonOK";
				_textDisabled = localize "STR_A3_RscDisplayRespawn_ButtonOK_disabled";

				_titleDefault = toupper localize "STR_disp_int_respawn";
				_titleTickets = _titleDefault + " (" + localize "str_a3_rscdisplayrespawn_remaining" + ": %1)";

				//--- No background when on default pos
				_layer = "RscDisplayRespawn" call bis_fnc_rscLayer;
				if (player distance [0,0,0] > 100) then {
					_layer cuttext ["","plain"];
				} else {
					_layer cuttext ["","black in",1e10];
				};

				_respawnTime = -1;
				_timeCounter = time;
				_timeUpdate = time;
				_tickets = -1;
				_noRespawnPositions = false;
				//waituntil {
					while {playerrespawntime > 0 && !isnull _ctrlButtonOK && !alive player} do {

					//--- Update code
					if (time > _timeUpdate) then {
						["update",_this,_class] call (uinamespace getvariable [format ["%1_script",_class],{}]);
						_noRespawnPositions = count (([] call bis_fnc_getrespawnmarkers) + ([] call bis_fnc_getrespawnpositions)) == 0;
						_tickets = [player,0,true] call bis_fnc_respawnTickets;
						_timeUpdate = time + 1;
					};

					//--- Tickets
					if (_tickets >= 0) then {
						_ctrlTitle ctrlsettext format [_titleTickets,_tickets];
					} else {
						_ctrlTitle ctrlsettext _titleDefault;
					};

					//--- Counter
					_text = if (playerrespawntime < 3600 && !_noRespawnPositions) then {
						if (playerrespawntime != _respawnTime) then {
							_respawntime = playerrespawntime;
							_timeCounter = time;
						};
						_time = (playerrespawntime - (time - _timeCounter)) max 0;
						format [_textDefault + ": <t font='EtelkaMonospacePro' color='#ffffff'>%1</t>",[_time,"MM:SS.MS"] call bis_fnc_secondsToString];
					} else {
						_textDisabled
					};
					_ctrlButtonOK ctrlsetstructuredtext parsetext _text;

					sleep 0.05;
					//playerrespawntime <=1 || isnull _ctrlButtonOK || alive player
				};
				if (alive player) then {
					//(ctrlparent _ctrlButtonOK) closedisplay 1;
				};
				if !(isnull _ctrlButtonOK) then {
					ctrlsetfocus _ctrlButtonOK;
					_noRespawnPositions = false;
					while {!isnull _ctrlButtonOK && !alive player} do {
						//--- Update code
						if (time > _timeUpdate) then {
							["update",_this,_class] call (uinamespace getvariable [format ["%1_script",_class],{}]);
							_noRespawnPositions = count (([] call bis_fnc_getrespawnmarkers) + ([] call bis_fnc_getrespawnpositions)) == 0;
							_timeUpdate = time + 1;
						};

						_respawnDisabled = playerrespawntime > 99999 || _noRespawnPositions;
						_text = if (_respawnDisabled) then {_textDisabled} else {_textDefault};
						_ctrlButtonOK ctrlenable !_respawnDisabled;
						_ctrlButtonOK ctrlsettext _text;

						setplayerrespawntime (99999 max playerrespawntime);
						sleep 0.05;
					};
				};

				(ctrlparent _ctrlButtonOK) closedisplay 0;
				missionnamespace setvariable ["RscStatic_mode",0];
				titlersc ["RscStatic","plain"];
				cuttext ["","black in"];
				_layer cuttext ["","black in"];

				ppeffectdestroy _ppColor;
				ppeffectdestroy _ppGrain;
				ppeffectdestroy _ppBlur;
			};
		};
	};
	case "onUnload": {
		if ((_params select 1) != 0) then {
			RscDisplayRespawn_ppEffects = nil;
			//RscDisplayRespawn_currentSection = nil;
			//RscDisplayRespawn_defaultPositions = nil;
			//RscDisplayRespawn_sections = nil;
		};
	};

	case "init";
	case "update";
	case "select";
	case "preview": {
		_control = _params select 0;
		_display = ctrlparent _control;
		if (isnull _display) exitwith {};

		_ctrlSection = _display displayctrl IDC_RSCDISPLAYRESPAWN_SECTION;
		_sectionID = lbcursel _ctrlSection;
		_sectionsOffset = _ctrlSection lbvalue _sectionID;

		if (_mode == "init" && _sectionsOffset > 0 && RscDisplayRespawn_currentSection >= 0) exitwith {};

		_ctrlListBackground = _display displayctrl IDC_RSCDISPLAYRESPAWN_LISTBACKGROUND;
		_ctrlList = _display displayctrl IDC_RSCDISPLAYRESPAWN_LIST;
		_ctrlContentBackground = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENTBACKGROUND;
		_ctrlContentGroup = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENTGROUP;
		_ctrlContent = _display displayctrl IDC_RSCDISPLAYRESPAWN_CONTENT;
		_ctrlMap = _display displayctrl IDC_RSCDISPLAYRESPAWN_MAP;
		_ctrlBlackContent = _display displayctrl IDC_RSCDISPLAYRESPAWN_BLACKCONTENT;
		_args = [_ctrlListBackground,_ctrlList,_ctrlContentBackground,_ctrlContentGroup,_ctrlContent,_ctrlMap,_ctrlBlackContent];

		_sectionIDOld = RscDisplayRespawn_currentSection;
		_sectionsData = uinamespace getvariable ["RscDisplayRespawn_sections",[displaynull,[]]];
		_sections = _sectionsData select 1;
		_sectionID = _sectionID min (count _sections - 1);
		_section = _sections select _sectionID;
		_sectionCode = _section select 1;
		RscDisplayRespawn_currentSection = _sectionID;


		//---//if (_mode == "init") then {"RscDisplayRespawn" call bis_fnc_startLoadingScreen;};

		if (_mode == "init") then {
			if (_sectionIDOld >= 0 && _sectionIDOld < count _sections) then {
				private ["_mode","_control","_display","_ctrlSection","_sectionID","_sectionsOffset"];
				_sectionOld = _sections select _sectionIDOld;
				_sectionOldCode = _sectionOld select 1;
				_script = (["exit"] + _args) call _sectionOldCode;
			};

			//--- Clear all event handlers which might have been added in a section
			{
				_control = _x;
				_control ctrlsetposition (RscDisplayRespawn_defaultPositions select _foreachindex);
				_control ctrlsetfade 0;
				_control ctrlcommit 0;
				_control ctrlshow true;
				_control ctrlenable true;
				{
					_control ctrlremovealleventhandlers _x;
				} foreach [
					"Load",
					"Unload",
					"ChildDestroyed",
					"MouseEnter",
					"MouseExit",
					"SetFocus",
					"KillFocus",
					"Timer",
					"KeyDown",
					"KeyUp",
					"Char",
					"IMEChar",
					"IMEComposition",
					"JoystickButton",
					"onMouseButtonDown",
					"MouseButtonUp",
					"MouseButtonClick",
					"MouseButtonDblClick",
					"MouseMoving",
					"MouseHolding",
					"MouseZChanged",
					"CanDestroy",
					"Destroy",
					"ButtonClick",
					"ButtonDown",
					"ButtonUp",
					"LBSelChanged",
					"LBListSelChanged",
					"LBDblClick",
					"LBDrag",
					"LBDragging",
					"LBDrop",
					"TreeSelChanged",
					"TreeLButtonDown",
					"TreeDblClick",
					"TreeExpanded",
					"TreeCollapsed",
					"TreeMouseMove",
					"TreeMouseHold",
					"TreeMouseExit",
					"ToolBoxSelChanged",
					"CheckBoxesSelChanged",
					"HTMLLink",
					"SliderPosChanged",
					"ObjectMoved",
					"MenuSelected",
					"Draw",
					"VideoStopped"
				];
			} foreach [_ctrlListBackground,_ctrlList,_ctrlContentBackground,_ctrlContentGroup,_ctrlContent,_ctrlMap];

			_ctrlListBackground ctrlsettext "";
			_ctrlContentBackground ctrlsettext "";
			_ctrlContent ctrlsettext "";

			_ctrlList ctrladdeventhandler ["lbSelChanged",format ["with uinamespace do {['select',_this,''] call %1_script};",_class]];
			_ctrlList ctrladdeventhandler ["lbDblClick",format ["with uinamespace do {['preview',_this,''] call %1_script};",_class]];
			lbclear _ctrlList;
			_ctrlList lbsetcursel -1;
			_control lbsetcursel -1;

			_ctrlBlackContent ctrlsetfade 0;
			_ctrlBlackContent ctrlcommit 0;
			_ctrlBlackContent ctrlsetfade 1;
			_ctrlBlackContent ctrlcommit 0.2;
		};

		with missionnamespace do {

			([_mode] + _args) call _sectionCode;
			if (_mode == "init") then {
				(["update"] + _args) call _sectionCode;
			};
/*
			_script = ([_mode] + _args) call _sectionCode;

			[_mode,_args,_sectionCode,_script] spawn {
				_mode = _this select 0;
				_args = _this select 1;
				_sectionCode = _this select 2;
				_script = _this select 3;
				scriptname format ["RscDisplayRespawn: %1",_mode];

				_time = time + 1;
				waituntil {scriptdone _script || time > _time};
				if (_mode == "init") then {
					_script = (["update"] + _args) call _sectionCode;
					_time = time + 1;
					waituntil {scriptdone _script || time > _time};
					//---//"RscDisplayRespawn" call bis_fnc_endLoadingScreen;
				};
			};
*/
		};
	};

	case "buttonOK": {
		setplayerrespawntime 0;
		false
	};
	case "buttonCancel": {
		_params spawn {
			disableserialization;
			_ctrlButtonCancel = _this select 0;
			_text = if (isserver) then {"str_msg_confirm_return_lobby"} else {"str_msg_confirm_return_lobby_client"};
			_cancel = [localize _text,"",nil,true,ctrlparent _ctrlButtonCancel,true] call bis_fnc_guiMessage;
			if (_cancel) then {
				_ctrlButtonCancel ctrlremovealleventhandlers "buttonclick";
				ctrlactivate _ctrlButtonCancel;
			};
		};
		true
	};
	case "keyDown": {
		_display = _params select 0;
		_key = _params select 1;
		if (_key == DIK_ESCAPE) then {
			_ctrlButtonCancel = _display displayctrl IDC_CANCEL;
			["buttonCancel",[_ctrlButtonCancel],""] call (uinamespace getvariable [format ["%1_script",_class],{}]);
			true
		} else {
			false
		};
	};
};