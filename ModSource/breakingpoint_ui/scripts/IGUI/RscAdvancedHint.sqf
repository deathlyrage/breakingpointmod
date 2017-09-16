#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;
		_displayCustom = finddisplay 312;
		if (isnull _displayCustom) then {_displayCustom = finddisplay 160;}; //--- AV Terminal

		//--- When curator is available, use its controls group
		if !(isnull _displayCustom) then {
			_ctrlHintGroup = _display displayctrl IDC_RSCADVANCEDHINT_HINTGROUP;
			_ctrlHintGroup ctrlshow false;
			_display = _displayCustom;
		};

		missionnamespace setvariable ["RscAdvancedHint_close",false];
		_displayOld = uinamespace getvariable ["RscAdvancedHint_display",displaynull];
		RscAdvancedHint_display = _display;

		_ctrlTitle = _display displayctrl IDC_RSCADVANCEDHINT_TITLE;
		_ctrlHint = _display displayctrl IDC_RSCADVANCEDHINT_HINT;
		_ctrlHintGroup = _display displayctrl IDC_RSCADVANCEDHINT_HINTGROUP;

		_title = missionnamespace getvariable ["RscAdvancedHint_title",""];
		_hint = missionnamespace getvariable ["RscAdvancedHint_hint",parsetext ""];
		_state = missionnamespace getvariable ["RscAdvancedHint_state",["unknown","unknown"]];
		missionnamespace setVariable ["BIS_fnc_advHint_state",[_state select 0,"animating"]];

		_ctrlTitle ctrlsettext _title;
		_ctrlHint ctrlsetstructuredtext _hint;
		_ctrlHint call bis_fnc_ctrlfittotextheight;

		if (isnull _displayOld && isnull _displayCustom) then {
			_ctrlTitlePos = ctrlPosition _ctrlTitle;
			_ctrlTitlePosDefault = +_ctrlTitlePOs;
			_ctrlTitlePos set [0,(_ctrlTitlePos select 0) + (_ctrlTitlePos select 2) / 2];
			_ctrlTitlePos set [2,0];
			_ctrlTitle ctrlsetposition _ctrlTitlePos;
			_ctrlTitle ctrlcommit 0;

			_ctrlTitle ctrlsetposition _ctrlTitlePosDefault;
			_ctrlTitle ctrlcommit 0.2;
		};

		_ctrlHintGroupPos = ctrlPosition _ctrlHintGroup;
		_ctrlHintGroupPosDefault = +_ctrlHintGroupPos;
		_ctrlHintGroupPos set [3,0];
		_ctrlHintGroup ctrlsetposition _ctrlHintGroupPos;
		_ctrlHintGroup ctrlsetfade 0;
		_ctrlHintGroup ctrlcommit 0;
		_ctrlHintGroup ctrlshow true;

		_ctrlTitle ctrlsetfade 0;
		_ctrlTitle ctrlcommit 0;

		[_ctrlTitle,_ctrlHint,_ctrlHintGroup,_state] spawn {
			scriptname "RscAdvancedHint_animate";
			_fnc_scriptName = "RscAdvancedHint_animate";

			disableserialization;
			_ctrlTitle = _this select 0;
			_ctrlHint = _this select 1;
			_ctrlHintGroup = _this select 2;
			_state = _this select 3;

			_height = (ctrltextheight _ctrlHint) + (ctrlposition _ctrlTitle select 3);
			_heightLimit = 0.7;
			_commitTime = _height / 2;
			if (_height > _heightLimit) then {
				_hintData = missionnamespace getvariable ["BIS_fnc_advHint_hint",[localize "STR_A3_CFGMPGAMETYPES_UNKNOWN_SHORTCUT_0"]];
				_hintClass = _hintData select 0;
				["Hint '%3' is too long (%1, shouldn't exceed %2)",_height,_heightLimit,_hintClass] call bis_fnc_error;
			};

			sleep 0.3;
			_ctrlHintGroupPos = ctrlposition _ctrlHintGroup;
			_ctrlHintGroupPos set [3,_height];
			_ctrlHintGroup ctrlsetposition _ctrlHintGroupPos;
			_ctrlHintGroup ctrlcommit _commitTime;

			missionnamespace setVariable ["BIS_fnc_advHint_state",_state];
			
			waituntil {
				if (missionnamespace getvariable ["BIS_fnc_advHint_refresh",false]) then {
					missionnamespace setVariable ["BIS_fnc_advHint_refresh",nil];
					
					_title = missionnamespace getvariable ["RscAdvancedHint_title",""];
					_hint = missionnamespace getvariable ["RscAdvancedHint_hint",parsetext ""];

					_ctrlTitle ctrlsettext _title;
					_ctrlHint ctrlsetstructuredtext _hint;
					_ctrlHint call bis_fnc_ctrlfittotextheight;
					
					_ctrlTitle ctrlcommit 0;
					_ctrlHint ctrlcommit 0;
				};
				isnull _ctrlHintGroup || missionnamespace getvariable ["RscAdvancedHint_close",false];
			};
			
			if (isnull _ctrlHintGroup) exitwith {missionnamespace setVariable ["BIS_fnc_advHint_state",nil];};
			missionnamespace setVariable ["BIS_fnc_advHint_state",[_state select 0,"animating"]];
			_ctrlHintGroupPos set [3,0];
			_ctrlHintGroup ctrlsetposition _ctrlHintGroupPos;
			_ctrlHintGroup ctrlcommit _commitTime;

			waituntil {ctrlcommitted _ctrlHintGroup};
			_ctrlTitlePos = ctrlPosition _ctrlTitle;
			_ctrlTitlePosDefault = +_ctrlTitlePOs;
			_ctrlTitlePos set [0,(_ctrlTitlePos select 0) + (_ctrlTitlePos select 2) / 2];
			_ctrlTitlePos set [2,0];
			//_ctrlTitle ctrlsetposition _ctrlTitlePos;
			_ctrlTitle ctrlsetfade 1;
			_ctrlTitle ctrlcommit 0.2;

			waituntil {ctrlcommitted _ctrlTitle};
			missionnamespace setVariable ["BIS_fnc_advHint_state",nil];
			("RscAdvancedHint" call bis_fnc_rsclayer) cuttext ["","plain"];
		};
	};
};