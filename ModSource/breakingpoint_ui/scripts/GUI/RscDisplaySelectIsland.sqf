#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		RscDisplaySelectIsland_worldname = "";

		_display = _params select 0;

		_ctrlIslandBox = _display displayctrl IDC_SELECT_ISLAND;
		_ctrlIslandBox ctrladdeventhandler ["lbselchanged","with uinamespace do {['lbselchanged',_this,''] call RscDisplaySelectIsland_script};"];
		['lbselchanged',[_ctrlIslandBox,lbcursel _ctrlIslandBox],''] call RscDisplaySelectIsland_script;
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//--- To upper title
		_ctrlTitle = _display displayctrl IDC_RSCDISPLAYSELECTISLAND_TITLE;
		_ctrlTitle ctrlsettext (toupper ctrltext _ctrlTitle);
	};
	case "onUnoad": {
		RscDisplaySelectIsland_worldname = nil;
	};
	case "lbselchanged": {
		_ctrlIslandBox = _params select 0;
		_cursel = _params select 1;
		_world = _ctrlIslandBox lbdata _cursel;
		_worldConfig = configfile >> "cfgworlds" >> _world;

		_author = gettext (_worldConfig >> "author");
		if (_author == "") then {_author = localize "STR_AUTHOR_UNKNOWN"};
		_author = if (_author == "") then {""} else {format [localize "STR_FORMAT_AUTHOR_SCRIPTED",_author]};

		_picture = gettext (_worldConfig >> "pictureMap");
		if (_picture == "") then {_picture = gettext (configfile >> "RscDisplaySelectIsland" >> "defaultPicture")};


		_display = ctrlparent _ctrlIslandBox;
		_ctrlName = _display displayctrl IDC_RSCDISPLAYSELECTISLAND_NAME;
		_ctrlAuthor = _display displayctrl IDC_RSCDISPLAYSELECTISLAND_AUTHOR;
		_ctrlIslandPanorama = _display displayctrl IDC_RSCDISPLAYSELECTISLAND_ISLANDPANORAMA;

		_ctrlName ctrlsettext toupper (_ctrlIslandBox lbtext _cursel);
		_ctrlAuthor ctrlsettext _author;
		_ctrlIslandPanorama ctrlsettext _picture;

		//--- Generate clouds
		if (_world != "vr") then {
			if (RscDisplaySelectIsland_worldname != _world) then {
				_ctrlGroup = _display displayctrl IDC_RSCDISPLAYSELECTISLAND_ISLANDGROUP;
				_ctrlGroupPos = ctrlposition _ctrlGroup;
				_ctrlGroupPosW = _ctrlGroupPos select 2;
				_ctrlGroupPosH = _ctrlGroupPos select 3;
				{
					_ran = 0.25 + random 0.25;
					_ranAlpha = random 0.25;
					_cloud = _display displayctrl _x;
					_cloudPosW = _ctrlGroupPosW * _ran;
					_cloudPosH = _ctrlGroupPosH * _ran;
					_cloud ctrlsetposition [
						-(_cloudPosW / 2) + random _ctrlGroupPosW,
						-(_cloudPosH / 2) + random _ctrlGroupPosH,
						_cloudPosW,
						_cloudPosH
					];
					//_cloud ctrlsettextcolor [1,1,1,0.5 + random 0.5];
					_cloud ctrlsetfade (_ranAlpha + 0.5);
					_cloud ctrlcommit 0;
					_cloud ctrlsetfade _ranAlpha;
					_cloud ctrlcommit 2;
				} foreach [
					IDC_RSCDISPLAYSELECTISLAND_CLOUD1,
					IDC_RSCDISPLAYSELECTISLAND_CLOUD2,
					IDC_RSCDISPLAYSELECTISLAND_CLOUD3,
					IDC_RSCDISPLAYSELECTISLAND_CLOUD4
				];
			};
		} else {
			{
				_cloud = _display displayctrl _x;
				_cloud ctrlsetfade 1;
				_cloud ctrlcommit 0;
			} foreach [
				IDC_RSCDISPLAYSELECTISLAND_CLOUD1,
				IDC_RSCDISPLAYSELECTISLAND_CLOUD2,
				IDC_RSCDISPLAYSELECTISLAND_CLOUD3,
				IDC_RSCDISPLAYSELECTISLAND_CLOUD4
			];
		};
		RscDisplaySelectIsland_worldname = _world;
	};
	default {};
};