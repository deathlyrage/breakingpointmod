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
			_ValueVehicle = _display displayctrl 706;  //IDC_AS_SITETYPE, was IDC_ARCUNIT_VEHICLE 103
			_ValueVehicle ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbselchanged',_this,''] call RscDisplayArcadeSites_script};"];
			["lbselchanged",[_ValueVehicle,lbcursel _ValueVehicle],""] call RscDisplayArcadeSites_script;

			//--- Info button
			_ctrlInfo = _display displayctrl 1702;
			_ctrlInfo ctrladdeventhandler ["buttonclick","with uinamespace do {['info',_this,''] call RscDisplayArcadeSites_script};"];
		};
	};

	//--- Class listbox
	case "lbselchanged": {
		_ctrl = _params select 0;
		_id = _params select 1;
		_cursel = lbcursel _ctrl;
		_display = ctrlparent _ctrl;

		//--- Detect side
		_ctrlSide = _display displayctrl 703;	//IDC_AS_SIDE, was IDC_ARCUNIT_SIDE 102
		_sideId = _ctrlSide lbvalue (lbcursel _ctrlSide);
		_sideColorClass = [
			"colorEnemy",		//--- 0: OFPOR
			"colorCivilian",	//--- 1: BLUFOR
			"colorFriendly",	//--- 2: INDEPENDENT
			"colorNeutral",		//--- 3: CIVILIAN
			"colorCivilian",
			"colorCivilian",
			"colorCivilian",
			"colorCivilian",	//--- 7: LOGIC
			"colorUnknown",		//--- 8: EMPTY
			"colorCivilian"		//--- 9: AMBIENT
		] select _sideId;
		_sideColor = getarray (configfile >> "cfgingameUI" >> "islandMap" >> _sideColorClass);

		//--- Detect vehicle
		_text = _ctrl lbtext _cursel;
		_class = _ctrl lbdata _cursel;
		_cfg = configfile >> "cfgvehicles" >> _class;
		_description = gettext (_cfg >> "armory" >> "description");

		_icon = gettext (_cfg >> "icon");
		_iconArray = toarray _icon;
		if (count _iconArray > 0) then {
			if ((_iconArray select 0) != (toarray "\" select 0)) then {
				_icon = "";
			};
		};
		if (_icon == "") then {_icon = "A3\ui_f\data\map\markers\military\unknown_CA.paa"};

		_picture = gettext (_cfg >> "picture");
		_pictureArray = toarray _picture;
		if (count _pictureArray > 0) then {
			if ((_pictureArray select 0) != (toarray "\" select 0)) then {
				_picture = "";
			};
		};

		//--- Assign title
		_ctrlTitle = _display displayctrl 1022;
		_ctrlTitle ctrlsettext _text;

		//--- Assign class
		_ctrlClass = _display displayctrl 1023;
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
		[_display,_cfg] call bis_fnc_overviewAuthor;
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
		_ButtonInfo = _display displayctrl 1702;
		_ButtonInfo ctrlsettext localize (["str_disp_armory_show","str_disp_armory_hide"] select  _visibleSettings);
	};
};