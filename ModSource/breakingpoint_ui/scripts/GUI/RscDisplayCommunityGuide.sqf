#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		//--- set player's name
		(_display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_PLAYERSNAME) ctrlSetText profileName;
		[_display, IDC_RSCDISPLAYCOMMUNITYGUIDE_PLAYERSNAME] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//--- Title toUpper
		_ctrlTitle = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_TITLE;
		_ctrlTitle ctrlSetText (toUpper (ctrlText _ctrlTitle));
		
		//Fill the list
		_list = (_display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_GUIDELIST);
		_showedGuides = profilenamespace getvariable ['watchedCommunityGuides', []];
		
		{
			_index = _list lbAdd (getText(_x >> "name"));
			_guideClassName = configName _x;
			_list lbSetData [_index, _guideClassName];
			
			if(_guideClassName in _showedGuides) then
			{
				_list lbSetPicture [_index, "\A3\Ui_f\data\Map\Diary\Icons\taskSucceeded_ca.paa"];
			}
			else
			{
				_list lbSetPicture [_index, "\A3\Ui_f\data\Map\Diary\Icons\taskNone_ca.paa"];
			};
			
		} foreach ((configfile >> "CfgCommunityGuide") call bis_fnc_returnChildren);
		
		_list ctrladdeventhandler ["LBSelChanged","with uinamespace do {['list_LBSelChanged',_this,''] call RscDisplayCommunityGuide_script};"];
		_list lbSetCurSel 0;
		
		_watchButton = _display displayctrl 2400;
		_watchButton ctrladdeventhandler ["buttonclick","with uinamespace do {['watchButton',_this,''] call RscDisplayCommunityGuide_script};"];
		
		ctrlSetFocus _list;

		// _overviewGroup = _display displayctrl 2300;
		// _overviewGroup ctrlenable false;

		//_overviewNoise = _display displayctrl 1201;
		//_overviewNoise ctrlsettext "#(ai,512,256,1)perlinNoise(512,256,0,1)";

		//_display displayaddeventhandler ["mousemoving","with uinamespace do {['Noise',_this,''] call RscDisplaySingleMission_script};"];
		//_display displayaddeventhandler ["mouseholding","with uinamespace do {['Noise',_this,''] call RscDisplaySingleMission_script};"];
		
		
		//--- Zoom in the overview picture
		//_tree = _display displayctrl 101;
		//_tree ctrladdeventhandler ["TreeSelChanged", "with uinamespace do {['TreeSelChanged',_this,''] call RscDisplaySingleMission_script};"];
	};
	
	
	case "list_LBSelChanged":
	{
		_list = (_this select 1) select 0;
		_selItemNum = (_this select 1) select 1;
		_display = ctrlparent _list;
		_guideClass = (configfile >> "CfgCommunityGuide" >> (_list lbData _selItemNum));
				
		//Name
		_ctrl = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_BRIEFINGNAME;
		_ctrl ctrlSetText getText(_guideClass >> "name");
		
		//Author
		_author = getText(_guideClass >> "author");
		if(_author == "") then
		{
			_author = format [localize "STR_FORMAT_AUTHOR_SCRIPTED", localize "STR_AUTHOR_UNKNOWN"];
		}
		else
		{
			_author = format [localize "STR_FORMAT_AUTHOR_SCRIPTED", _author];
		};
		_ctrl = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_AUTHOR;
		_ctrl ctrlSetText _author;
		
		//Picture
		_ctrl = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_OVERVIEWPICTURE;
		_ctrl ctrlSetText getText(_guideClass >> "overviewPicture");	//TODO --- Add check for existence, if not found read from default DLC config.
		//Overview text
		_ctrl = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_OVERVIEWTEXT;
		_ctrl ctrlSetStructuredText (parseText getText(_guideClass >> "overviewText"));
	};
	
	case "watchButton":
	{
		_display = ctrlparent ((_this select 1) select 0);
		_list = _display displayctrl IDC_RSCDISPLAYCOMMUNITYGUIDE_GUIDELIST;
		_index = lbCurSel _list;
		_guideClassName = _list lbData _index;
		_nil = openYoutubeVideo getText(configfile >> "CfgCommunityGuide" >> _guideClassName >> "link");
		_showedGuides = profilenamespace getvariable ['watchedCommunityGuides', []];
		
		if(!(_guideClassName in _showedGuides)) then
		{
			_list lbSetPicture [_index, "\A3\Ui_f\data\Map\Diary\Icons\taskSucceeded_ca.paa"];
			_showedGuides = _showedGuides + [_guideClassName];
			profilenamespace setvariable ['watchedCommunityGuides', _showedGuides];
			saveprofilenamespace;
		};	
	};
	
	// case "Noise": {
		// disableSerialization;
		// _display = _params select 0;

		// _overviewGroup = _display displayctrl 2300;
		// _overviewNoise = _display displayctrl 1201;
		// _overviewPicture = _display displayctrl IDC_SINGLE_PICTURE;
		// if (isnull _overviewPicture) then {_overviewPicture = _display displayctrl IDC_CAMPAIGN_PICTURE;};
		// _pos = ctrlposition _overviewGroup;
		// _posW = _pos select 2;
		// _posH = _pos select 3;

		// _color = if (ctrltext _overviewPicture == "") then {[0.5,0.5,0.5,1]} else {[1,1,1,0.12]};
		// _overviewNoise ctrlsetposition [
			// -random _posW,
			// -random _posH,
			// _posW * 2,
			// _posH * 2
		// ];
		// _overviewNoise ctrlsettextcolor _color;
		// _overviewNoise ctrlcommit 0;
	// };
	
	// case "TreeSelChanged": {
		// _display = ctrlparent (_params select 0);
		// _overviewGroup = _display displayctrl 2300;
		// _overviewPicture = _display displayctrl IDC_SINGLE_PICTURE;
		// if (isnull _overviewPicture) then {_overviewPicture = _display displayctrl IDC_CAMPAIGN_PICTURE;};

		// _coef = 1.1;
		// _pos = ctrlposition _overviewGroup;
		// _posX = 0;
		// _posY = 0;
		// _posW = _pos select 2;
		// _posH = _pos select 3;
		// _posFinal = [_posX,_posY,_posW,_posH];
		// _pos = [
			// _posX - (_posW * _coef - _posW) / 2,
			// _posY - (_posH * _coef - _posH) / 2,
			// _posW * _coef,
			// _posH * _coef
		// ];
		// _overviewPicture ctrlsetposition _pos;
		// _overviewPicture ctrlcommit 0;
		// _overviewPicture ctrlsetposition _posFinal;
		// _overviewPicture ctrlcommit 1;
	// };

};