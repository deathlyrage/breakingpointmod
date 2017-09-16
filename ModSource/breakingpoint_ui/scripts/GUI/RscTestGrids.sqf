#define RESOLUTIONS	[480,576,600,720,768,800,960,1024,1080,2160]
#define ASPECTS		[[5,4], [4,3], [16,10], [16,9], [12,3]]
#define UISIZES		[0.47,0.55,0.7,0.85,1]
#define UISIZE_NAMES	["str_very_small","str_small","str_medium","str_large","str_very_large"]

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {

		_display = _params select 0;
		_ctrlResolution = _display displayctrl 1500;
		_ctrlAspect = _display displayctrl 1501;
		_ctrlUISize = _display displayctrl 1502;

		_colorSelected = ["GUI","BCG_RGB"] call bis_fnc_displayColorGet;
		_colorSelected set [3,1];

		//--- Resolution
		{
			_ctrlResolution lbadd format ["%1p",_x];
			_ctrlResolution lbsetvalue [_foreachindex,_x];
		} foreach RESOLUTIONS;
		_currentResolution = getresolution select 1;
		if !(_currentResolution in RESOLUTIONS) then {
			_lbAdd = _ctrlResolution lbadd format ["%1p",_currentResolution];
			_ctrlResolution lbsetvalue [_lbAdd,_currentResolution];
		};
		lbsortbyvalue _ctrlResolution;
		for "_i" from 0 to (lbsize _ctrlResolution) do {if ((_ctrlResolution lbvalue _i) == _currentResolution) exitwith {_ctrlResolution lbsetcursel _i; _ctrlResolution lbsetcolor [_i,_colorSelected];};};

		//--- Aspect Ratio
		{
			_ctrlAspect lbadd format ["%2:%3",(_x select 0) / (_x select 1),_x select 0,_x select 1];
			_ctrlAspect lbsetdata [_foreachindex,str ((_x select 0) / (_x select 1))];
		} foreach ASPECTS;
		_currentAspect = getResolution select 4;
		if ({((_x select 0) / (_x select 1)) == _currentAspect} count ASPECTS == 0) then {
			_lbAdd = _ctrlAspect lbadd format ["(%1)",_currentAspect];
			_ctrlAspect lbsetdata [_lbAdd,str _currentAspect];
		};
		for "_i" from 0 to (lbsize _ctrlAspect) do {if ((_ctrlAspect lbdata _i) == str _currentAspect) exitwith {_ctrlAspect lbsetcursel _i; _ctrlAspect lbsetcolor [_i,_colorSelected];};};

		//--- UI Size
		_currentUISIze = getresolution select 5;
		{
			_ctrlUISize lbadd localize (UISIZE_NAMES select _foreachindex);
			_ctrlUISize lbsetdata [_foreachindex,str _x];
		} foreach UISIZES;
		for "_i" from 0 to (lbsize _ctrlUISize) do {if (parsenumber (_ctrlUISize lbdata _i) == _currentUISIze) exitwith {_ctrlUISize lbsetcursel _i; _ctrlUISize lbsetcolor [_i,_colorSelected];};};

		["refresh",[_display],""] call RscTestGrids_script;

		{
			_x ctrladdeventhandler ["lbselchanged",{with uinamespace do {["refresh",[ctrlparent (_this select 0)],""] call RscTestGrids_script;};}];
		} foreach [_ctrlResolution,_ctrlAspect,_ctrlUISize];

		//--- Initialize copy button
		_ctrlButtonCopy = _display displayctrl 2400;
		_ctrlButtonCopy ctrladdeventhandler ["buttonclick",{copytoclipboard loadfile "\a3\Ui_f\hpp\Test\RscTestGridsExported.inc"}];

		//--- Initialize grid tooltips
		_text_GUI_GRID = "Grid used in majority of game's menus, does not use pixel accurate coordinates.\nAffected only by interface size, giving user ability to customize its scale on the screen.\nDesigned to use only 40x25 grids (i.e., size on 16:10 screen with Very Large interface size),\nalthough some menus may be stretched to fill the whole screen. Never gets smaller than 40x25 grids.\nDefault grid in the GUI editor.";
		_text_pixel = "Actual pixel size, remains constant. On displays with too fine resolution (e.g., 4K),\nit can get too small for practical use.";
		_text_pixelGrid = "Pixel accurate grid introduced to replace GUI_GRID. Respects both resolution and interface size,\nbut always returns whole number which can be divided by up to 4 and still be a whole number.\nDue to this rounding, some interface sizes may use the same value.";
		_text_pixelGridNoUIScale = "Similar to pixelGrid, but affected only by resolution, not interface size.\nUsually used to keep some important elements, e.g., spotlight buttons in the main menu.";
		{
			_ctrl = _display displayctrl (_x select 0);
			_ctrl ctrlsettooltip (_x select 1);
			_ctrl ctrladdeventhandler ["mouseenter",{_ctrlMenu = (ctrlparent (_this select 0)) displayctrl 2300; _ctrlMenu ctrlsetfade 0.75; _ctrlMenu ctrlcommit 0.1;}];
			_ctrl ctrladdeventhandler ["mouseexit",{_ctrlMenu = (ctrlparent (_this select 0)) displayctrl 2300; _ctrlMenu ctrlsetfade 0; _ctrlMenu ctrlcommit 0.1;}];
		} foreach [
			[111,_text_GUI_GRID],
			[112,_text_pixel],
			[113,_text_pixelGrid],
			[114,_text_pixelGridNoUIScale]
		];
		setmouseposition [0.5,0.5];
	};

	case "refresh": {
		disableserialization;

		_display = _params select 0;

		//--- Delete existing grids
		{
			if (ctrlidc ctrlparentcontrolsgroup _x == 101) then {ctrldelete _x;};
		} foreach allcontrols _display;

		_ctrlGrids = _display displayctrl 101;
		_ctrlResolution = _display displayctrl 1500;
		_ctrlAspect = _display displayctrl 1501;
		_ctrlUISize = _display displayctrl 1502;

		//--- Ger real values
		_screenHReal = (getResolution select 1);
		_aspectReal = (getResolution select 4);

		//--- Screen definitions
		_aspect = parsenumber (_ctrlAspect lbdata lbcursel _ctrlAspect);
		_screenH = _ctrlResolution lbvalue lbcursel _ctrlResolution;
		_screenW = _screenH * _aspect;
		_uiSize = parsenumber (_ctrlUISize lbdata lbcursel _ctrlUISize);

		//--- Calculate virtual safezone size
		_safezoneH = safezoneH * (((_screenH / _screenHReal) min 1) min ((_aspectReal / _aspect) min 1));
		_safezoneW = _safezoneH * _aspect * 3/4;
		_safezoneX = 0.5 - 0.5 * _safezoneW;
		_safezoneY = 0.5 - 0.5 * _safezoneH;

		//--- Calculate virtual pixel grid values
		_uiScaleMaxGrids = getnumber (configfile >> "uiScaleMaxGrids");
		_uiScaleFactor = getnumber (configfile >> "uiScaleFactor");
		_pixelW = _safezoneW / _screenW;
		_pixelH = _safezoneH / _screenH;
		_pixelGridBase = _screenH / _uiScaleMaxGrids;
		_pixelGridNoUIScale = (round (_pixelGridBase / _uiScaleFactor)) * _uiScaleFactor;
		_pixelGrid = (round ((_pixelGridBase * _uiSize) / _uiScaleFactor)) * _uiScaleFactor;
		_GUI_GRID_WAbs = ((_safezoneW / _safezoneH) min 1.2) * _uiSize;
		_GUI_GRID_HAbs = _GUI_GRID_WAbs / 1.2;
		_GUI_GRID_W = _GUI_GRID_WAbs / 40;
		_GUI_GRID_H = _GUI_GRID_HAbs / 25;

		_posL = 0;
		_posR = _safezoneW / 2;
		_posT = 0;
		_posB = _safezoneH / 2;

		_title_GUI_GRID = "GUI_GRID";
		_title_pixel = "Pixel Size";
		_title_pixelGrid = "pixelGrid";
		_title_pixelGridNoUIScale = "pixelGridNoUIScale";

		//--- Group
		_ctrlGrids ctrlsetposition [
			_safezoneX,
			_safezoneY,
			_safezoneW,
			_safezoneH
		];
		_ctrlGrids ctrlcommit 0;
		_ctrlGrids ctrlenable false;

		//--- Grids
		{
			_ref = _x select 0;
			_max = _x select 1;
			_gridX = _x select 2;
			_gridY = _x select 3;
			_startX = _x select 4;
			_startY = _x select 5;
			_color = _x select 6;
			_title = _x select 7;
			_coefNames = _x select 8;

			_colorCoef1 = 0.6;
			_colorCoef2 = 0.55;
			_colorCoefText = 1.2;
			_color1 = [(_color select 0) * _colorCoef1,(_color select 1) * _colorCoef1,(_color select 2) * _colorCoef1,1];
			_color2 = [(_color select 0) * _colorCoef2,(_color select 1) * _colorCoef2,(_color select 2) * _colorCoef2,1];
			_colorText = [(_color select 0) * _colorCoefText,(_color select 1) * _colorCoefText,(_color select 2) * _colorCoefText,1];
			_offset = 0;

			//--- Background
			_ctrl = _display ctrlcreate ["RscText",-1,_ctrlGrids];
			_ctrl ctrlSetBackgroundColor _color2;
			_ctrl ctrlSetPosition [_startX,_startY,_safezoneW / 2,_safezoneH / 2];
			_ctrl ctrlCommit 0;

			//--- Grid
			for "_posY" from 0 to (_screenH / 2) step _gridY do {
				for "_posX" from (_offset * _gridX) to (_screenW / 2) step (_gridX * 2) do {
					_ctrl = _display ctrlcreate ["RscText",-1,_ctrlGrids];
					_ctrl ctrlSetBackgroundColor _color1;
					_ctrl ctrlSetPosition [
						_startX + _posX * _pixelW,
						_startY + _posY * _pixelH,
						1 * _gridX * _pixelW,
						1 * _gridY * _pixelH
					];
					_ctrl ctrlCommit 0;
				};
				_offset = (_offset + 1) % 2;
			};

			//--- Reference
			_refW = _ref * _max * _pixelW;
			_refH = _ref * _max * _pixelH;
			_ctrlRef = _display ctrlcreate ["RscStructuredText",-1,_ctrlGrids];
			_ctrlRef ctrlsetstructuredtext parsetext format ["<t align='center' size='%4' shadow='0'>w = %1 * %2;<br />h = %1 * %3;</t>",_ref,_coefNames select 0,_coefNames select 1,2.5 * _refH];
			_ctrlRef ctrlsetbackgroundcolor (_color + [1]);
			_ctrlRef ctrlsettextcolor _color2;
			_ctrlRef ctrlsetposition [
				_startX + _safezoneW / 4 - _refW / 2,
				_startY + _safezoneH / 4 - _refH / 2,
				_refW,
				_refH
			];
			_ctrlRef ctrlcommit 0;

			//--- Text
			_align = if (_startX == 0) then {"left"} else {"right"};
			_ctrlText = _display ctrlcreate ["RscStructuredText",-1,_ctrlGrids];
			_ctrlText ctrlsettextcolor _colorText;
			_ctrlText ctrlsetposition [0,0,_safezoneW / 2,1]; //--- Set the width forst, so ctrlTextHeight is calculated correctly
			_ctrlText ctrlcommit 0;
			_ctrlText ctrlsetstructuredtext parsetext format [
				"<t align='%1'><t size='1.5'>%2</t><br />Grid size: %3 px<br />Max grids W: %4<br />Max grids H: %5</t>",
				_align,
				_title,
				_max,
				floor (_screenW / _max),
				floor (_screenH / _max)
			];
			_ctrlTextHeight = ctrltextheight _ctrlText;
			_ctrlText ctrlsetposition [_startX,if (_startY == 0) then {_startY} else {_safezoneH - _ctrlTextHeight - 0.01},_safezoneW / 2,_ctrlTextHeight];
			_ctrlText ctrlcommit 0;

		} foreach [
			[10,	_GUI_GRID_H * _screenH,		_GUI_GRID_H * _screenH,		_GUI_GRID_H * _screenH,	_posL,	_posT,	[1.0, 0.5, 0.5],	_title_GUI_GRID,		["GUI_GRID_W","GUI_GRID_H"]],
			[100,	1,				100,				100,			_posR,	_posT,	[0.5, 1.0, 0.5],	_title_pixel,			["pixelW","pixelH"]],
			[20,	_pixelGrid	,		_pixelGrid,			_pixelGrid,		_posL,	_posB,	[0.5, 0.5, 1.0],	_title_pixelGrid,		["pixelGrid * pixelW","pixelGrid * pixelH"]],
			[10,	_pixelGridNoUIScale,		_pixelGridNoUIScale,		_pixelGridNoUIScale,	_posR,	_posB,	[1.0, 1.0, 0.5],	_title_pixelGridNoUIScale,	["pixelGridNoUIScale * pixelW","pixelGridNoUIScale * pixelH"]]
		];
	};
};