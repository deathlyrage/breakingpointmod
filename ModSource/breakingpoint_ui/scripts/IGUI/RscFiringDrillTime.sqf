#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_params spawn {
			scriptname "RscFiringDrillTime_onLoad";
			disableserialization;

			_display = _this select 0;
			_defaultParseText = parsetext "";

			_ctrlGroup = _display displayctrl IDC_RSCFIRINGDRILLTIME_TIME;
			_ctrlCurrent = _display displayctrl IDC_RSCFIRINGDRILLTIME_CURRENT;
			_ctrlBonus = _display displayctrl IDC_RSCFIRINGDRILLTIME_BONUS;
			_ctrlPenalty = _display displayctrl IDC_RSCFIRINGDRILLTIME_PENALTY;
			_ctrlBest = _display displayctrl IDC_RSCFIRINGDRILLTIME_BEST;
			_ctrlPrevious = _display displayctrl IDC_RSCFIRINGDRILLTIME_PREVIOUS;

			//--- Animate
			_ctrlGroupPos = ctrlposition _ctrlGroup;
			//if (vehicle player != player) then {_ctrlGroupPos set [1,(_ctrlGroupPos select 1) + 0.2];};
			_ctrlGroupPosDefault = +_ctrlGroupPos;
			_ctrlGroupPosX = _ctrlGroupPos select 0;
			_ctrlGroupPosW = _ctrlGroupPos select 2;
			_ctrlGroupPos set [0,_ctrlGroupPosX + _ctrlGroupPosW / 2];
			_ctrlGroupPos set [2,0];
			_ctrlGroup ctrlsetposition _ctrlGroupPos;
			_ctrlGroup ctrlcommit 0;
			_ctrlGroup ctrlsetposition _ctrlGroupPosDefault;
			_ctrlGroup ctrlcommit 0.2;

			//--- Refresh
			waituntil {
				_current = missionnamespace getvariable "RscFiringDrillTime_current";
				if !(isnil {_current}) then {
					_ctrlCurrent ctrlsetstructuredtext _current;
					_ctrlCurrent ctrlshow true;
				} else {
					_ctrlCurrent ctrlshow false;
				};

				_bonus = missionnamespace getvariable "RscFiringDrillTime_bonus";
				if !(isnil {_bonus}) then {
					_ctrlBonus ctrlsetstructuredtext _bonus;
					_ctrlBonus ctrlshow true;
				} else {
					_ctrlBonus ctrlshow false;
				};

				_penalty = missionnamespace getvariable "RscFiringDrillTime_penalty";
				if !(isnil {_penalty}) then {
					_ctrlPenalty ctrlsetstructuredtext _penalty;
					_ctrlPenalty ctrlshow true;
				} else {
					_ctrlPenalty ctrlshow false;
				};
				
				_best = missionnamespace getvariable "RscFiringDrillTime_best";
				if !(isnil {_best}) then {
					_ctrlBest ctrlsetstructuredtext _best;
					_ctrlBest ctrlshow true;
				} else {
					_ctrlBest ctrlshow false;
				};

				_previous = missionnamespace getvariable "RscFiringDrillTime_previous";
				if !(isnil {_previous}) then {
					_ctrlPrevious ctrlsetstructuredtext _previous;
					_ctrlPrevious ctrlshow true;
				} else {
					_ctrlPrevious ctrlshow false;
				};

				sleep 0.01;
				isnull _display || (missionnamespace getvariable ["RscFiringDrillTime_done",false])
			};

			if !(isnull _display) then {
				_ctrlGroup ctrlsetposition _ctrlGroupPos;
				_ctrlGroup ctrlcommit 0.2;
				missionnamespace setvariable ["RscFiringDrillTime_done",false];
			};
		};
	};
};