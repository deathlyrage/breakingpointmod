#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_params spawn {
			scriptname "RscFiringDrillCheckpoint_onLoad";
			disableserialization;

			_display = _this select 0;

			_ctrlGroup = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_CHECKPOINT;
			_ctrlCheckpointBackground = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_CHECKPOINTBACKGROUND;
			_ctrlCheckpointPicture = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_CHECKPOINTPICTURE;
			_ctrlCheckpointText = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_CHECKPOINTTEXT;
			_ctrlTargetBackground = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_TARGETBACKGROUND;
			_ctrlTargetPicture = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_TARGETPICTURE;
			_ctrlTargetTextCurrent = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_TARGETTEXTCURRENT;
			_ctrlTargetTextTotal = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_TARGETTEXTTOTAL;
			_ctrlStanceBackground = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_STANCEBACKGROUND;
			_ctrlStancePicture = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_STANCEPICTURE;
			_ctrlWeaponBackground = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_WEAPONBACKGROUND;
			_ctrlWeaponPicture = _display displayctrl IDC_RSCFIRINGDRILLCHECKPOINT_WEAPONPICTURE;

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

				_checkpointPicture = [missionnamespace getvariable ["RscFiringDrillCheckpoint_checkpointPicture",""],0,"",[""]] call bis_fnc_paramin;
				_ctrlCheckpointPicture ctrlsettext _checkpointPicture;

				_checkpointText = [missionnamespace getvariable ["RscFiringDrillCheckpoint_checkpointText",""],0,"",[""]] call bis_fnc_paramin;
				_ctrlCheckpointText ctrlsettext _checkpointText;
				_checkpointTextColor = [[missionnamespace getvariable ["RscFiringDrillCheckpoint_checkpointTextColor",[]]],0,[],[[]]] call bis_fnc_paramin;
				if (count _checkpointTextColor == 4) then {
					_ctrlCheckpointText ctrlsettextcolor _checkpointTextColor;
				};

				_targetPicture = [missionnamespace getvariable ["RscFiringDrillCheckpoint_targetPicture",""],0,"",[""]] call bis_fnc_paramin;
				if (_targetPicture != "") then {
					_ctrlTargetPicture ctrlsettext _targetPicture;

					_targetTextCurrent = [missionnamespace getvariable ["RscFiringDrillCheckpoint_targetTextCurrent",""],0,"",[""]] call bis_fnc_paramin;
					_ctrlTargetTextCurrent ctrlshow true;
					_ctrlTargetTextCurrent ctrlsettext _targetTextCurrent;
					_targetTextCurrentColor = [[missionnamespace getvariable ["RscFiringDrillCheckpoint_targetTextCurrentColor",[]]],0,[],[[]]] call bis_fnc_paramin;
					if (count _targetTextCurrentColor == 4) then {
						_ctrlTargetTextCurrent ctrlsettextcolor _targetTextCurrentColor;
					};

					_targetTextTotal = [missionnamespace getvariable ["RscFiringDrillCheckpoint_targetTextTotal",""],0,"",[""]] call bis_fnc_paramin;
					_ctrlTargetTextTotal ctrlshow true;					
					_ctrlTargetTextTotal ctrlsettext _targetTextTotal;
					_targetTextTotalColor = [[missionnamespace getvariable ["RscFiringDrillCheckpoint_targetTextTotalColor",[]]],0,[],[[]]] call bis_fnc_paramin;
					if (count _targetTextTotalColor == 4) then {
						_ctrlTargetTextTotal ctrlsettextcolor _targetTextTotalColor;
					};
					_ctrlTargetBackground ctrlsetfade 0;
				} else {
					_ctrlTargetTextCurrent ctrlshow false;
					_ctrlTargetTextTotal ctrlshow false;
					_ctrlTargetBackground ctrlsetfade 0.75;
				};
				_ctrlTargetBackground ctrlcommit 0;

				_stancePicture = [missionnamespace getvariable ["RscFiringDrillCheckpoint_stancePicture",""],0,"",[""]] call bis_fnc_paramin;
				if (_stancePicture != "") then {
					_ctrlStancePicture ctrlsettext _stancePicture;
					_ctrlStancePicture ctrlshow true;
					_ctrlStanceBackground ctrlsetfade 0;
				} else {
					_ctrlStancePicture ctrlshow false;
					_ctrlStanceBackground ctrlsetfade 0.75;
				};
				_ctrlStanceBackground ctrlcommit 0;

				_weaponPicture = [missionnamespace getvariable ["RscFiringDrillCheckpoint_weaponPicture",""],0,"",[""]] call bis_fnc_paramin;
				if (_weaponPicture != "") then {
					_ctrlWeaponPicture ctrlsettext _weaponPicture;
					_ctrlWeaponPicture ctrlshow true;
					_ctrlWeaponBackground ctrlsetfade 0;
				} else {
					_ctrlWeaponPicture ctrlshow false;
					_ctrlWeaponBackground ctrlsetfade 0.75;
				};
				_ctrlWeaponBackground ctrlcommit 0;

				sleep 0.1;
				isnull _display || (missionnamespace getvariable ["RscFiringDrillCheckpoint_done",false])
			};

			if !(isnull _display) then {
				_ctrlGroup ctrlsetposition _ctrlGroupPos;
				_ctrlGroup ctrlsetfade 1;
				_ctrlGroup ctrlcommit 0.2;
				missionnamespace setvariable ["RscFiringDrillCheckpoint_done",false];
			};
		};
	};
};