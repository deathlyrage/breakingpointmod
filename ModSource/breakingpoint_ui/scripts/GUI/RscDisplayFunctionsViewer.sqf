#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

disbaleserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;
_selected = profilenamespace getvariable ["RscDisplayFunctionsViewer_selected",["","","",""]];

switch _mode do
{
	case "onLoad":
	{
		with missionnamespace do {
			if (isnil {bis_fnc_init}) then {4 call (uinamespace getvariable "bis_fnc_recompile");};
		};

		_display = _params select 0;
		_ctrlSources = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_SOURCES;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_TAGS;
		_ctrlCategories = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CATEGORIES;
		_ctrlFunctions = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_FUNCTIONS;
		_ctrlButtonRecompile = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_BUTTONRECOMPILE;

		_ctrlSources ctrladdeventhandler ["lbselchanged","with uinamespace do {['Sources',_this,''] call RscDisplayFunctionsViewer_script};"];
		_ctrlTags ctrladdeventhandler ["lbselchanged","with uinamespace do {['Tags',_this,''] call RscDisplayFunctionsViewer_script};"];
		_ctrlCategories ctrladdeventhandler ["lbselchanged","with uinamespace do {['Categories',_this,''] call RscDisplayFunctionsViewer_script};"];
		_ctrlFunctions ctrladdeventhandler ["lbselchanged","with uinamespace do {['Functions',_this,''] call RscDisplayFunctionsViewer_script};"];
		_ctrlFunctions ctrladdeventhandler ["keydown","with uinamespace do {['KeyDown',_this,''] call RscDisplayFunctionsViewer_script};"];
		_ctrlButtonRecompile ctrladdeventhandler ["buttonclick","with uinamespace do {1 call bis_fnc_recompile};"];

		//--- Disable recompile button when recompiling is not alllowed
		if (getnumber (missionconfigfile >> "allowFunctionsRecompile") == 0 && !cheatsenabled) then {
			_ctrlButtonRecompile ctrlenable false;
		};

		//--- Show specific function
		_function = missionnamespace getvariable ["RscDisplayFunctionsViewer_function",""];
		_functionMeta = _function call bis_fnc_functionmeta;
		if (_function != "") then {
			_selected = ["configFile",_functionMeta select 6,_functionMeta select 7,_function];
			uinamespace setvariable ["RscDisplayFunctionsViewer_selected",_selected];
			missionnamespace setvariable ["RscDisplayFunctionsViewer_function",nil];
		};

		_selectedSource = _selected select 0;
		_cursel = 0;
		{
			_index = _ctrlSources lbadd _x;
			_ctrlSources lbsetvalue [_index,_foreachindex];
			_ctrlSources lbsetdata [_index,_x];
			if (_x == _selectedSource) then {_cursel = _index;};
		} foreach ["configFile","campaignConfigFile","missionConfigFile"];
		_ctrlSources lbsetcursel _cursel;
	};

	case "Sources": {
		_display = ctrlparent (_params select 0);
		_index = _params select 1;
		_selected set [0,(_params select 0) lbdata _index];

		_ctrlSources = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_SOURCES;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_TAGS;

		_sourceIndex = _ctrlSources lbvalue (lbcursel _ctrlSources);
		_source = [configFile,campaignConfigFile,missionConfigFile] select _sourceIndex;

		lbclear _ctrlTags;
		_ctrlTags lbadd "<All>";
		_ctrlTags lbsetvalue [_index,-1];
		_ctrlTags lbsetdata [_index,""];
		{
			_index = _ctrlTags lbadd (_x call bis_fnc_displayname);
			_ctrlTags lbsetvalue [_index,_foreachindex];
			_ctrlTags lbsetdata [_index,configname _x];
		} foreach ((_source >> "CfgFunctions") call bis_fnc_returnchildren);
		lbsort _ctrlTags;
		_ctrlTags lbsetcursel _cursel;

		//--- Restore selection
		_selectedTag = _selected select 1;
		_cursel = 0;
		for "_i" from 0 to (lbsize _ctrlTags - 1) do {
			if ((_ctrlTags lbdata _i) == _selectedTag) then {_cursel = _i;};
		};
		_ctrlTags lbsetcursel _cursel;
	};

	case "Tags": {
		_display = ctrlparent (_params select 0);
		_index = _params select 1;
		_selected set [1,(_params select 0) lbdata _index];

		_ctrlSources = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_SOURCES;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_TAGS;
		_ctrlCategories = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CATEGORIES;

		_sourceIndex = _ctrlSources lbvalue (lbcursel _ctrlSources);
		_source = [configFile,campaignConfigFile,missionConfigFile] select _sourceIndex;
		_tag = _ctrlTags lbdata (lbcursel _ctrlTags);

		_fnc_addCategory = {
			_index = _ctrlCategories lbadd (_x call bis_fnc_displayname);
			_ctrlCategories lbsetvalue [_index,_foreachindex];
			_ctrlCategories lbsetdata [_index,configname _x];
		};

		lbclear _ctrlCategories;
		_ctrlCategories lbadd "<All>";
		_ctrlCategories lbsetvalue [_index,-1];
		if (_tag != "") then {
			{
				[] call _fnc_addCategory;
			} foreach ((_source >> "CfgFunctions" >> _tag) call bis_fnc_returnchildren);
		} else {
			_categories = [];
			{
				{
					if !((configname _x) in _categories) then {
						_categories set [count _categories,configname _x];
						[] call _fnc_addCategory;
					};
				} foreach (_x call bis_fnc_returnchildren);
			} foreach ((_source >> "CfgFunctions") call bis_fnc_returnchildren);
		};
		lbsort _ctrlCategories;
		_ctrlCategories lbsetcursel _cursel;

		//--- Restore selection
		_selectedCategory = _selected select 2;
		_cursel = 0;
		for "_i" from 0 to (lbsize _ctrlCategories - 1) do {
			if ((_ctrlCategories lbdata _i) == _selectedCategory) then {_cursel = _i;};
		};
		_ctrlCategories lbsetcursel _cursel;
	};

	case "Categories": {
		_display = ctrlparent (_params select 0);
		_index = _params select 1;
		_selected set [2,(_params select 0) lbdata _index];

		_ctrlSources = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_SOURCES;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_TAGS;
		_ctrlCategories = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CATEGORIES;
		_ctrlFunctions = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_FUNCTIONS;

		_sourceIndex = _ctrlSources lbvalue (lbcursel _ctrlSources);
		_source = [configFile,campaignConfigFile,missionConfigFile] select _sourceIndex;
		_tag = _ctrlTags lbdata (lbcursel _ctrlTags);
		_tagName = gettext (_source >> "CfgFunctions" >> _tag >> "tag");
		if (_tagName == "") then {_tagName = _tag;};
		_category = _ctrlCategories lbdata (lbcursel _ctrlCategories);
		_fnc_addFunction = {
			_index = _ctrlFunctions lbadd (configname _x);
			_ctrlFunctions lbsetvalue [_index,_foreachindex];
			_ctrlFunctions lbsetdata [_index,_tagName];
		};

		lbclear _ctrlFunctions;
		if (_category != "") then {
			
			if (_tag != "") then {
				//--- Selected Tag / Selected Category
				{
					[] call _fnc_addFunction;
				} foreach ((_source >> "CfgFunctions" >> _tag >> _category) call bis_fnc_returnchildren);
			} else {
				//--- All Tags / Selected Categories
				{
					_tagName = gettext (_x >> "tag");
					if (_tagName == "") then {_tagName = configname _x};
					{
						if (configname _x == _category) then {
							{
								[] call _fnc_addFunction;
							} foreach (_x call bis_fnc_returnchildren);
						};
					} foreach (_x call bis_fnc_returnchildren);
				} foreach ((_source >> "CfgFunctions") call bis_fnc_returnchildren);
			};
		} else {
			if (_tag != "") then {
				//--- Selected Tag / All Categories
				{
					{
						[] call _fnc_addFunction;
					} foreach (_x call bis_fnc_returnchildren);
				} foreach ((_source >> "CfgFunctions" >> _tag) call bis_fnc_returnchildren);
			} else {
				//--- All Tags / All Categories
				{
					_tagName = gettext (_x >> "tag");
					if (_tagName == "") then {_tagName = configname _x};
					{
						{
							[] call _fnc_addFunction;
						} foreach (_x call bis_fnc_returnchildren);
					} foreach (_x call bis_fnc_returnchildren);
				} foreach ((_source >> "CfgFunctions") call bis_fnc_returnchildren);
			};
		};
		lbsort _ctrlFunctions;

		//--- Restore selection
		_selectedFunction = _selected select 3;
		_cursel = 0;
		for "_i" from 0 to (lbsize _ctrlFunctions - 1) do {
			_xText = _ctrlFunctions lbtext _i;
			if (_xText == _selectedFunction || format ["%1_fnc_%2",_tagName,_xText] == _selectedFunction) then {_cursel = _i;};
		};
		_ctrlFunctions lbsetcursel _cursel;
	};

	case "Functions": {
		_display = ctrlparent (_params select 0);
		_index = _params select 1;
		_selected set [3,(_params select 0) lbtext _index];

		_ctrlSources = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_SOURCES;
		_ctrlTags = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_TAGS;
		_ctrlCategories = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CATEGORIES;
		_ctrlFunctions = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_FUNCTIONS;
		_ctrlName = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_NAME;
		_ctrlAuthor = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_AUTHOR;
		_ctrlPreview = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_PREVIEW;
		_ctrlCode = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CODE;
		_ctrlCodeStructured = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_CODESTRUCTURED;

		_sourceIndex = _ctrlSources lbvalue (lbcursel _ctrlSources);
		_source = [configFile,campaignConfigFile,missionConfigFile] select _sourceIndex;
		_tag = _ctrlFunctions lbdata (lbcursel _ctrlFunctions);
		_function = _ctrlFunctions lbtext (lbcursel _ctrlFunctions);

		_var = format ["%1_fnc_%2",_tag,_function];
		_meta = _var call bis_fnc_functionmeta;
		_metaPath = _meta select 0;
		_file = "";
		if (_metaPath != "") then {
			_file = loadfile _metaPath;
			_ctrlName ctrlsettext _var;
			_ctrlAuthor ctrlsettext _metaPath;
		} else {
			_ctrlName ctrlsettext "";
			_ctrlAuthor ctrlsettext "";
		};

		_fileArray = toarray _file;
		_text = "";
		for "_i" from 0 to ({_x == 10} count _fileArray) do {_text = _text + str _i + "<br />";};
		_ctrlCodeStructured ctrlenable false;
		_ctrlCodeStructured ctrlsetstructuredtext parsetext format ["<t size='0.8'>%1</t>",_text];
		_ctrlCodeStructuredPos = ctrlposition _ctrlCodeStructured;
		_ctrlCodeStructuredPos set [3,(ctrltextheight _ctrlCodeStructured + 0.1) max ((ctrlposition _ctrlPreview) select 3)];
		_ctrlCodeStructured ctrlsetposition _ctrlCodeStructuredPos;
		_ctrlCodeStructured ctrlcommit 0;
		_ctrlCodeStructured ctrlsetstructuredtext parsetext "";

		_ctrlCode ctrlsettext _file;
		_ctrlCodePos = ctrlposition _ctrlCode;
		_ctrlCodePos set [3,ctrlposition _ctrlCodeStructured select 3];
		_ctrlCode ctrlsetposition _ctrlCodePos;
		_ctrlCode ctrlsetbackgroundcolor [1,1,1,1];
		_ctrlCode ctrlcommit 0;
	};

	case "KeyDown": {
		_ctrl = _params select 3;
		if (_ctrl) then {
			_display = ctrlparent (_params select 0);
			_ctrlName = _display displayctrl IDC_RSCDISPLAYFUNCTIONSVIEWER_NAME;
			copytoclipboard ctrltext _ctrlName;
		};
	};
	case "onUnload":
	{
		saveprofilenamespace;
	};
};
profilenamespace setvariable ["RscDisplayFunctionsViewer_selected",_selected];