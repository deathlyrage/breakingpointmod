#include "\a3\Ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;

		_CT_STATIC = _display displayctrl CT_STATIC;
		_CT_BUTTON = _display displayctrl CT_BUTTON;
		_CT_EDIT = _display displayctrl CT_EDIT;
		_CT_SLIDER = _display displayctrl CT_SLIDER;
		_CT_COMBO = _display displayctrl CT_COMBO;
		_CT_LISTBOX = _display displayctrl CT_LISTBOX;
		_CT_TOOLBOX = _display displayctrl CT_TOOLBOX;
		_CT_CHECKBOXES = _display displayctrl CT_CHECKBOXES;
		_CT_PROGRESS = _display displayctrl CT_PROGRESS;
		_CT_HTML = _display displayctrl CT_HTML;
		_CT_ACTIVETEXT = _display displayctrl CT_ACTIVETEXT;
		_CT_TREE = _display displayctrl CT_TREE;
		_CT_STRUCTURED_TEXT = _display displayctrl CT_STRUCTURED_TEXT;
		_CT_CONTROLS_GROUP = _display displayctrl CT_CONTROLS_GROUP;
		_CT_SHORTCUTBUTTON = _display displayctrl CT_SHORTCUTBUTTON;
		_CT_XBUTTON = _display displayctrl CT_XBUTTON;
		_CT_XLISTBOX = _display displayctrl CT_XLISTBOX;
		_CT_XSLIDER = _display displayctrl CT_XSLIDER;
		_CT_XCOMBO = _display displayctrl CT_XCOMBO;
		_CT_OBJECT = _display displayctrl CT_OBJECT;
		_CT_OBJECT_ZOOM = _display displayctrl CT_OBJECT_ZOOM;
		_CT_OBJECT_CONTAINER = _display displayctrl CT_OBJECT_CONTAINER;
		_CT_MAP = _display displayctrl CT_MAP;
		_CT_MAP_MAIN = _display displayctrl CT_MAP_MAIN;
		_CT_LISTNBOX = _display displayctrl CT_LISTNBOX;
		_CT_CHECKBOX = _display displayctrl CT_CHECKBOX;

		// CT_COMBO / CT_LISTBOX / CT_XLISTBOX / CT_XCOMBO
		{
			_ctrl = _x;
			{
				_ctrl lbAdd gettext (_x >> "displayName");
				_ctrl lbSetPicture [_foreachindex,gettext (_x >> "texture")];
				_ctrl lbSetTooltip [_foreachindex,gettext (_x >> "displayName")];
			} foreach ("isclass _x" configclasses (configfile >> "CfgRanks"));
			_ctrl lbsetcursel 0;
		} foreach [
			_CT_COMBO,
			_CT_LISTBOX,
			_CT_XLISTBOX,
			_CT_XCOMBO
		];

		// CT_PROGRESS
		_CT_PROGRESS progresssetposition 0.5;

		// CT_TREE
		_CT_TREE tvAdd [[],localize "STR_A3_RADIO_A"];
		_CT_TREE tvAdd [[0],localize "STR_A3_RADIO_B"];
		_CT_TREE tvAdd [[0],localize "STR_A3_RADIO_C"];
		_CT_TREE tvAdd [[],localize "STR_A3_RADIO_D"];

		// CT_LISTNBOX
		{
			_CT_LISTNBOX lnbAddRow [gettext (_x >> "displayNameShort"),gettext (_x >> "displayName")];
			_CT_LISTNBOX lnbSetPicture [[_foreachindex,0],gettext (_x >> "texture")];
			_CT_LISTNBOX lnbSetData [[_foreachindex,1],gettext (_x >> "rank")];
			_CT_LISTNBOX lnbSetValue [[_foreachindex,1],parsenumber configname _x];
		} foreach ("isclass _x" configclasses (configfile >> "CfgRanks"));
		_CT_LISTNBOX lnbSetCurSelRow 0;

		// CT_ITEMSLOT
		// CT_CHECKBOX
	};
};