/*
#define IDC_MAIN_GAME               101
#define IDC_MAIN_OPTIONS            102
#define IDC_MAIN_TRAINING           103
#define IDC_MAIN_CUSTOM             104
#define IDC_MAIN_MULTIPLAYER        105
#define IDC_MAIN_QUIT               106
#define IDC_MAIN_CREDITS            107
#define IDC_MAIN_ARCADE             108
#define IDC_MAIN_PLAYER             109
#define IDC_MAIN_RANK               110
#define IDC_MAIN_ISLAND             111
#define IDC_MAIN_DATE               112
#define IDC_MAIN_MISSION            113
#define IDC_MAIN_CONTINUE           114
#define IDC_MAIN_EDITOR             115
#define IDC_MAIN_BOOK               116
#define IDC_MAIN_SINGLE             117
#define IDC_MAIN_VERSION            118
#define IDC_MAIN_SINGLE_PROFILES    119
#define IDC_MAIN_CAMPAIGN_PROFILES  120
#define IDC_MAIN_MP_PROFILES        121
#define IDC_MAIN_SETTINGS_PROFILES  122
#define IDC_MAIN_SYSTEM_LINK        123
#define IDC_MAIN_CUSTOM_PROFILES    124
#define IDC_MAIN_SIGN_IN_STATUS     125
#define IDC_MAIN_PLAYER_LABEL       126
#define IDC_MAIN_PLAYER_NAME        127
#define IDC_MAIN_CONTROLS           128
#define IDC_MAIN_PLAYER_ID          129
#define IDC_MAIN_PLAYER_COLOR       130
#define IDC_MAIN_SERVICE_ID_LABEL   131
#define IDC_MAIN_NICKNAME_LABEL     132
#define IDC_MAIN_NICKNAME_BG        133
*/
disableSerialization;
private ["_idcToExec","_ctrlToExec"];
_display = _this select 0;
_key= _this select 1;
_shift = _this select 2;
_ctrl = _this select 3;
_alt = _this select 4;
_key = _key * 10;

if (_shift) then {
	_key = _key  + 1;
};

if (_ctrl) then {
	_key = _key  + 2;
};

if (_alt) then {
	_key = _key  + 4;
};

switch _key do {
	//editor Alt+E
	case 184:{
		_idcToExec = 115;
	};
	//quit Alt+Q
	case 164:{
		_idcToExec = 106;
	};	
	//player profile Alt+P
	case 254:{
		_idcToExec = 109;
	};	
	//singleplayer Alt+S
	case 314:{
		_idcToExec = 117;
		debuglog "SP";
	};	
	//multiplayer Alt+M
	case 504:{
		_idcToExec = 105;
	};
	//options Alt+O
	case 244:{
		_idcToExec = 102;
	};		
	//campaign Alt+C
	case 464:{
		_idcToExec = 120;
	};		
	//Designers missions Alt+Y
	case 214:{
		_idcToExec = 104;
	};		
	//editor Alt+E
	case 182:{
		_idcToExec = 115;
	};
	//quit Alt+Q
	case 162:{
		_idcToExec = 106;
	};	
	//player profile Alt+P
	case 252:{
		_idcToExec = 109;
	};	
	//singleplayer Alt+S
	case 312:{
		_idcToExec = 138;
		debuglog "SP";
	};	
	//multiplayer Alt+M
	case 502:{
		_idcToExec = 105;
	};
	//options Alt+O
	case 242:{
		_idcToExec = 102;
	};		
	//campaign Alt+C
	case 462:{
		_idcToExec = 120;
	};		
	//Designers missions Alt+Y
	case 212:{
		_idcToExec = 104;
	};		
	default {
		_idcToExec = 0;
	};
};

if (_idcToExec != 0) then {
	_ctrlToExec = _display displayctrl _idcToExec;
	debuglog (str(_idcToExec) + " exec");
	ctrlActivate _ctrlToExec;
};

