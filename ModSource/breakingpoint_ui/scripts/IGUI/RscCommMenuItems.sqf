#include "\A3\ui_f\hpp\defineResinclDesign.inc"

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;
		_slots = [
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT1,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT2,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT3,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT4,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT5,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT6,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT7,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT8,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT9,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT0
		];
		_slotTexts = [
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT1TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT2TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT3TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT4TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT5TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT6TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT7TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT8TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT9TEXT,
			_display displayctrl IDC_RSCCOMMMENUITEMS_SLOT0TEXT
		];

		_height = missionnamespace getvariable ["RscCommMenuItems_height",0];

		_group = _display displayctrl IDC_RSCCOMMMENUITEMS_RSCCOMMMENUITEMS;
		_groupPos = ctrlposition _group;
		_groupPos set [3,_height];
		_group ctrlsetposition _groupPos;
		_group ctrlcommit 0;


		_menu = player getvariable ["BIS_fnc_addCommMenuItem_menu",[]];
		{
			_icon = _x select 6;
			if (_icon != "") then {
				_slot = _slots select _foreachindex;
				_slot ctrlsettext _icon;

				_slotPos = ctrlposition _slot;
				_height = (_slotPos select 1) + (_slotPos select 3);
			};

			_iconText = _x select 7;
			if (_iconText != "") then {
				_slotText = _slotTexts select _foreachindex;
				_slotText ctrlsettext _iconText;

				_slotTextPos = ctrlposition _slotText;
				_height = (_slotTextPos select 1) + (_slotTextPos select 3);
			};
		} foreach _menu;
		if (count _menu == 0) then {_height = 0};
		_groupPos set [3,_height];
		_group ctrlsetposition _groupPos;
		_group ctrlcommit 0.2;

		missionnamespace setvariable ["RscCommMenuItems_height",_height];
	};
};