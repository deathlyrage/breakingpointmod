#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#define CONTROL	(_display displayctrl _idc)

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		disableserialization;
		_display = _params select 0;

		_idc = IDC_RSCDISPLAYDEBUG_CA_TITLE;
		_title = missionname;
		_author = gettext (missionconfigfile >> "dev");
		if (_author != "") then {_title = _title + format ["<t color='#999999' size='0.8' font='PuristaLight' valign='bottom' > %1</t>",format [localize "STR_FORMAT_AUTHOR_SCRIPTED",_author]];};
		CONTROL ctrlsetstructuredtext parsetext _title;

		//--- Game version (copied from main menu display)
		_idc = IDC_RSCDISPLAYDEBUG_CA_VERSION;
		CONTROL ctrlsettext ctrltext ((finddisplay 0) displayctrl 118);

		//--- Player
		if (!isnull player) then {
			_idc = IDC_RSCDISPLAYDEBUG_CA_PLAYER;
			CONTROL ctrlsettext str position vehicle player;
		};

		//--- Simulation is not running
		if (isnull ([] call (uinamespace getvariable "BIS_fnc_displayMission"))) then {
			{
				_idc = _x;
				CONTROL ctrlenable false;
			} foreach [
				IDC_RSCDISPLAYDEBUG_DEBUGFLOW,
				IDC_RSCDISPLAYDEBUG_DEBUGANIM,
				IDC_RSCDISPLAYDEBUG_DEBUGGUI,
				//IDC_RSCDISPLAYDEBUG_DEBUGFUNCTIONS,
				//IDC_RSCDISPLAYDEBUG_DEBUGCONFIG,
				IDC_RSCDISPLAYDEBUG_B_CAMERA
			];
		};

		_idc = IDC_RSCDISPLAYDEBUG_CREATEJIRAISSUE;
		CONTROL ctrlsetstructuredtext parsetext format ["<img image='\a3\Ui_f\data\GUI\Rsc\RscDisplayCreateJIRAIssue\jira_ca.paa' />%1",ctrltext CONTROL];
		CONTROL ctrladdeventhandler ["buttonclick",{(ctrlparent (_this select 0)) createdisplay "RscDisplayCreateJIRAIssue";}];

		//--- Mission HTML
		//_idc = IDC_RSCDISPLAYDEBUG_CA_MISSIONLINKS;
		//CONTROL htmlload "design.html";

		//--- Delete log
		_idc = IDC_DEBUG_LOG;
		CONTROL ctrladdeventhandler ["LBDblClick","ctrlactivate ((ctrlparent (_this select 0)) displayctrl 151)"];

		//--- Diag functions
		_addList = {
			if (typename _x == typename []) then {
				_add = CONTROL lbadd (_x select 0);
				CONTROL lbsetdata [_add,(_x select 1)];
			} else {
				_add = CONTROL lbadd _x;
				if (_idc == IDC_RSCDISPLAYDEBUG_DIAGLIST) then {
					CONTROL lbsetdata [_add,format ["diag_toggle '%1'",_x]];
				} else {
					CONTROL lbsetdata [_add,format ["diag_drawmode '%1'",_x]];
				};
			};
		};
		_addButton = "
			_display = ctrlparent (_this select 0);
			_list = _display displayctrl %1;
			_data = _list lbdata lbcursel _list;
			call compile _data;
		";

		//--- Diag lists
		_idc = IDC_RSCDISPLAYDEBUG_DIAGLIST;
		_addList foreach ([["<None>","'all' diag_enable false"]] + diag_list "toggle");
		lbsort CONTROL;
		CONTROL lbsetcursel (profilenamespace getvariable ["RscDisplayDebug_listDiag_lbCurSel",0]);
		CONTROL ctrladdeventhandler ["LBDblClick",format [_addButton,_idc]];
		
		_idc = IDC_RSCDISPLAYDEBUG_DRAWLIST;
		_addList foreach ([["<Normal>","diag_drawmode 'Normal'"]] + diag_list "drawMode");
		lbsort CONTROL;
		CONTROL lbsetcursel (profilenamespace getvariable ["RscDisplayDebug_listDraw_lbCurSel",0]);
		CONTROL ctrladdeventhandler ["LBDblClick",format [_addButton,_idc]];

		//--- Diag buttons
		_idc = IDC_RSCDISPLAYDEBUG_DIAGBUTTON;
		CONTROL ctrladdeventhandler ["buttondown",format [_addButton,IDC_RSCDISPLAYDEBUG_DIAGLIST]];
		_idc = IDC_RSCDISPLAYDEBUG_DRAWBUTTON;
		CONTROL ctrladdeventhandler ["buttondown",format [_addButton,IDC_RSCDISPLAYDEBUG_DRAWLIST]];

		_idc = IDC_RSCDISPLAYDEBUG_DEBUGFUNCTIONS;
		CONTROL ctrladdeventhandler [
			"mousebuttondown",
			"
				_ctrl = _this select 5;
				if (_ctrl) then {
					1 call (uinamespace getvariable 'bis_fnc_recompile');
				};
			"
		];
	};


	case "onUnload": {
		_idc = IDC_RSCDISPLAYDEBUG_DIAGLIST;
		profilenamespace setvariable ["RscDisplayDebug_listDiag_lbCurSel",lbcursel CONTROL];
		_idc = IDC_RSCDISPLAYDEBUG_DRAWLIST;
		profilenamespace setvariable ["RscDisplayDebug_listDraw_lbCurSel",lbcursel CONTROL];
		saveprofilenamespace;
	};

	default {};
};