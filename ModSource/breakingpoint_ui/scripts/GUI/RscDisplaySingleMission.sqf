#include "\A3\ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		//--- set player's name
		(_display displayctrl 8434) ctrlSetText profileName;
		[_display, 8434] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Scenarios title change must be in spawn otherwise engine overwrites it.
		_params spawn
		{
			disableSerialization;
			_title = uinamespace getvariable ["RscDisplaySingleMission_title", toUpper (localize "STR_A3_RSCDISPLAYMAIN_BUTTONSCENARIOS")]; // SCENARIOS
			_display = _this select 0;
			_control = _display displayctrl 106;
			_control ctrlsettext _title;
			uinamespace setvariable ["RscDisplaySingleMission_title",nil];
		};
		
		//Campaign Title - set text to Campaign or Bootcamp
		_ctrlTitle = _display displayctrl 1000;
		_titleText = uinamespace getvariable ["RscDisplayCampaignLoad_title", toUpper (localize "STR_A3_RSCDISPLAYMAIN_BUTTONCAMPAIGN")]; // CAMPAIGN
		_ctrlTitle ctrlSetText _titleText;

		_overviewGroup = _display displayctrl 2300;
		_overviewGroup ctrlenable false;

		_overviewNoise = _display displayctrl 1201;
		_overviewNoise ctrlsettext "#(ai,512,256,1)perlinNoise(512,256,0,1)";

		_display displayaddeventhandler ["mousemoving","with uinamespace do {['Noise',_this,''] call RscDisplaySingleMission_script};"];
		_display displayaddeventhandler ["mouseholding","with uinamespace do {['Noise',_this,''] call RscDisplaySingleMission_script};"];
		
		//Stripe colour. TODO: Having one .sqf for two displays (Scenarios and Campaign) may result in IDC conflicts.
		_scenariosDLCStripe = _display displayctrl 121;
		_campaignDLCStripe = _display displayctrl 147;
		_stripeColor = getArray(configfile >> "CfgMods" >> "Kart" >> "dlcColor");
		if(count _stripeColor == 4) then
		{
			_scenariosDLCStripe ctrlSetTextColor _stripeColor;
			_campaignDLCStripe ctrlSetTextColor _stripeColor;
		};
		
		//--- Zoom in the overview picture
		//_tree = _display displayctrl 101;
		//_tree ctrladdeventhandler ["TreeSelChanged", "with uinamespace do {['TreeSelChanged',_this,''] call RscDisplaySingleMission_script};"];
	};

	case "Noise": {
		disableSerialization;
		_display = _params select 0;

		_overviewGroup = _display displayctrl 2300;
		_overviewNoise = _display displayctrl 1201;
		_overviewPicture = _display displayctrl IDC_SINGLE_PICTURE;
		if (isnull _overviewPicture) then {_overviewPicture = _display displayctrl IDC_CAMPAIGN_PICTURE;};
		_pos = ctrlposition _overviewGroup;
		_posW = _pos select 2;
		_posH = _pos select 3;

		_color = if (ctrltext _overviewPicture == "") then {[0.5,0.5,0.5,1]} else {[1,1,1,0.12]};
		_overviewNoise ctrlsetposition [
			-random _posW,
			-random _posH,
			_posW * 2,
			_posH * 2
		];
		_overviewNoise ctrlsettextcolor _color;
		_overviewNoise ctrlcommit 0;
	};
	
	case "TreeSelChanged": {
		_display = ctrlparent (_params select 0);
		_overviewGroup = _display displayctrl 2300;
		_overviewPicture = _display displayctrl IDC_SINGLE_PICTURE;
		if (isnull _overviewPicture) then {_overviewPicture = _display displayctrl IDC_CAMPAIGN_PICTURE;};

		_coef = 1.1;
		_pos = ctrlposition _overviewGroup;
		_posX = 0;
		_posY = 0;
		_posW = _pos select 2;
		_posH = _pos select 3;
		_posFinal = [_posX,_posY,_posW,_posH];
		_pos = [
			_posX - (_posW * _coef - _posW) / 2,
			_posY - (_posH * _coef - _posH) / 2,
			_posW * _coef,
			_posH * _coef
		];
		_overviewPicture ctrlsetposition _pos;
		_overviewPicture ctrlcommit 0;
		_overviewPicture ctrlsetposition _posFinal;
		_overviewPicture ctrlcommit 1;
	};

	default {};
};