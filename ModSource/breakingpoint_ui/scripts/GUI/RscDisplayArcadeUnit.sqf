#include "\A3\ui_f\hpp\defineCommonGrids.inc"

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with uinamespace do {
			_display = _params select 0;


			//--- Disable description
			_DescriptionGroup = _display displayctrl 2300;
			_DescriptionGroup ctrlenable false;
			_DescriptionGroup ctrlshow false;

			
			//--- Vehicle selected
			_ValueVehicle = _display displayctrl 103;
			_ValueVehicle ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbselchanged_unit',_this,''] spawn RscDisplayArcadeUnit_script};"];
			["lbselchanged_unit",[_ValueVehicle,lbcursel _ValueVehicle],""] call RscDisplayArcadeUnit_script;

			//--- Info button
			_ctrlInfo = _display displayctrl 2402;
			_ctrlInfo ctrladdeventhandler ["buttonclick","with uinamespace do {['info',_this,''] call RscDisplayArcadeUnit_script};"];
			_ctrlInfo ctrlshow false;

			//Sets all static texts toUpper
			["RscDisplayArcadeUnit",["RscText","RscTitle","CA_TextSide"],["CA_VehicleAuthor"]] call bis_fnc_toUpperDisplayTexts;
			
			//Set focus to Side ComboBox
			ctrlSetFocus (_display displayctrl 102);
		};
	};

	//--- Unit listbox
	case "lbselchanged_unit": {
		_ctrl = _params select 0;
		_id = _params select 1;
		_cursel = lbcursel _ctrl;
		_display = ctrlparent _ctrl;

		//--- Detect side
		_valueSide = _display displayctrl 102;
		_sideColor = (_valueSide lbvalue (lbcursel _valueSide)) call bis_fnc_sideColor;

		//--- Detect vehicle
		_text = _ctrl lbtext _cursel;
		_class = _ctrl lbdata _cursel;
		_cfg = configfile >> "cfgvehicles" >> _class;
		_description = gettext (_cfg >> "armory" >> "description");

		_icon = gettext (_cfg >> "icon");
		if (_icon == "") then {_icon = "iconVehicle"};
		_icon = _icon call bis_fnc_textureVehicleIcon;

		_picture = gettext (_cfg >> "picture");
		_picture = _picture call bis_fnc_textureVehicleIcon;

		//--- Assign class
		_ctrlClass = _display displayctrl 1407;
		_ctrlClass ctrlsettext _class;

		//--- Assign icon
		_ctrlPic = _display displayctrl 1201;
		_ctrlPic ctrlsettext _icon;
		_ctrlPic ctrlsettextcolor _sideColor;
		_ctrlPic ctrlsetbackgroundcolor [1,1,1,1];
		_ctrlPic ctrlcommit 0;

		//--- Assign description
		_ctrlDesc = _display displayctrl 1100;
		_ctrlDesc ctrlsetstructuredtext parsetext _description;

		//--- Assign picture
		_ctrlPreview = _display displayctrl 1202;
		_ctrlPreview ctrlsettext _picture;


		//--- Set author
		[_cfg,_display displayctrl 1022] call bis_fnc_overviewauthor;

	
	};

	//--- Info button
	case "info": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;

		_DescriptionGroup = _display displayctrl 2300;
		_SettingsGroup = _display displayctrl 2301;

		//--- Set control groups' visibility
		_visibleSettings = ctrlshown _SettingsGroup;

		_DescriptionGroup ctrlshow _visibleSettings;
		_SettingsGroup ctrlshow !_visibleSettings;

		_DescriptionGroup ctrlenable _visibleSettings;
		_SettingsGroup ctrlenable !_visibleSettings;

		//--- Modify Info button text
		_ButtonInfo = _display displayctrl 2402;
		_ButtonInfo ctrlsettext toUpper(localize (["str_disp_armory_show","str_disp_armory_hide"] select  _visibleSettings));
	};
};