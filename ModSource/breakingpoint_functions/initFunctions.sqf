scriptName "Functions\initFunctions.sqf";
/*
	File: init.sqf
	Author: Karel Moricky

	Description:
	Function library initialization.

	Parameter(s):
	_this select 0: 'Function manager' logic

	Returns:
	Nothing
*/

//"debug_console" callExtension format ["Functions Libary Initalization Start (%1)",_this];

//--- Fake header
_fnc_scriptName = if (isnil "_fnc_scriptName") then {"Functions Init"} else {_fnc_scriptName};


/******************************************************************************************************
	DEFINE HEADERS

	Headers are pieces of code inserted on the beginning of every function code before compiling.
	Using 'BIS_fnc_functionsDebug', you can alter the headers to provide special debug output.

	Modes can be following:
	0: No Debug - header saves parent script name and current script name into variables
	1: Save script Map - header additionaly save an array of all parent scripts into variable
	2: Save and log script map - apart from saving into variable, script map is also logged through debugLog

	Some system function are using simplified header unaffected to current debug mode.
	These functions has headerType = 1; set in config.

******************************************************************************************************/

private ["_this","_headerNoDebug","_headerSaveScriptMap","_headerLogScriptMap","_headerSystem","_debug","_headerDefault","_fncCompile","_recompile"];

_headerNoDebug = "
	_fnc_scriptNameParentTemp = if !(isnil '_fnc_scriptName') then {_fnc_scriptName} else {'%1'};
	private ['_fnc_scriptNameParent'];
	_fnc_scriptNameParent = _fnc_scriptNameParentTemp;
	_fnc_scriptNameParentTemp = nil;

	private ['_fnc_scriptName'];
	_fnc_scriptName = '%1';
	scriptname _fnc_scriptName;
";
_headerSaveScriptMap = "
	_fnc_scriptMapTemp = if !(isnil '_fnc_scriptMap') then {_fnc_scriptMap} else {[]};
	private ['_fnc_scriptMap'];
	_fnc_scriptMap = _fnc_scriptMapTemp + [_fnc_scriptName];
	_fnc_scriptMapTemp = nil;
";
_headerLogScriptMap = "
	_this call {
		private '_fnc_scriptMapText';
		_fnc_scriptMapText = '';
		{
			_fnc_scriptMapText = _fnc_scriptMapText + ' >> ' + _x;
		} count _fnc_scriptMap;
		textlogformat ['%2',_fnc_scriptMapText,_this];
	};
";
_headerSystem = "
	private ['_fnc_scriptNameParent'];
	_fnc_scriptNameParent = if !(isnil '_fnc_scriptName') then {_fnc_scriptName} else {'%1'};
	scriptname '%1';
";
_headerNone = "";

//--- Compose headers based on current debug mode
_debug = uinamespace getvariable ["bis_fnc_initFunctions_debugMode",0];
_headerDefault = switch _debug do {

	//--- 0 - Debug mode off
	default {
		_headerNoDebug
	};

	//--- 1 - Save script map (order of executed functions) to '_fnc_scriptMap' variable
	case 1: {
		_headerNoDebug + _headerSaveScriptMap
	};

	//--- 2 - Save script map and log it
	case 2: {
		_headerNoDebug + _headerSaveScriptMap + _headerLogScriptMap
	};
};


///////////////////////////////////////////////////////////////////////////////////////////////////////
//--- Compile function
_fncCompile = {
	private ["_fncVar","_fncMeta","_fncPath","_fncHeader","_fncExt","_header","_debugMessage"];
	params ["_fncVar","_fncMeta","_fncHeader","_fncFinal"];
	_fncMeta params ["_fncPath","_fncExt"];

	switch _fncExt do 
	{
		//--- SQF
		case ".sqf": {
			_header = switch (_fncHeader) do {

				//--- No header (used in low-level functions, like 'fired' event handlers for every weapon)
				case -1: {
					_headerNone
				};

				//--- System functions' header (rewrite default header based on debug mode)
				case 1: {
					_headerSystem
				};


				//--- Full header
				default {
					_headerDefault
				}
			};
			_debugMessage = "Log: [Functions]%1 | %2";
			if (_fncFinal) then {
				compileFinal (format [_header,_fncVar,_debugMessage] + preprocessFileLineNumbers _fncPath);
			} else {
				compile (format [_header,_fncVar,_debugMessage] + preprocessFileLineNumbers _fncPath);
			};
		};

		//--- FSM
		case ".fsm": {
			compileFinal format ["%1_fsm = _this execfsm '%2'; %1_fsm",_fncVar,_fncPath];
		};

		default {0}
	};
};


/******************************************************************************************************
	COMPILE ONE FUNCTION

	When input is string containing function name instead of number, only the function is recompiled.

	The script stops here, reads function's meta data and recompile the function
	based on its extension and header.

	Instead of creating missionNamespace shortcut, it saves the function directly. Use it only for debugging!

******************************************************************************************************/

//--- Compile only selected
if (isnil "_this") then {_this = [];};
if (typename _this != typename []) then {_this = [_this];};
_recompile = if (count _this > 0) then {_this select 0} else {0};

if (typename _recompile == typename "") exitwith {
	private ["_fnc","_fncMeta","_headerType","_var"];

	//--- Recompile specific function
	_fnc = uinamespace getvariable _recompile;
	if !(isnil "_fnc") then {
		_fncMeta = _recompile call (uinamespace getvariable "bis_fnc_functionMeta");
		_headerType = if (count _this > 1) then {_this select 1} else {0};
		_var = [_recompile,[_recompile,_fncMeta,_headerType,false] call _fncCompile];
		uinamespace setvariable _var;
		missionnamespace setvariable _var;
		if (isnil "_functions_listRecompile") then {
			textlogformat ["Log: [Functions]: %1 recompiled with meta %2",_recompile,_fncMeta];
		};
	} else {
		_fncError = uinamespace getvariable "bis_fnc_error";
		if !(isnil "_fncError") then {
			["%1 is not a function.",_recompile] call _fncError;
		} else {
			textlogformat ["Log: [Functions]: ERROR: %1 is not a function.",_recompile];
		};
	};
};


/******************************************************************************************************
	COMPILE EVERYTHING IN GIVEN NAMESPACE(S)

	Function codes are present only in uiNamespace. Mission variables contains only shortcuts to uiNamespace.
	To executed only required compilation section, input param can be one of following numbers:

	0 - Autodetect what compile type should be used
	1 - Forced recompile of all the things
	2 - Create only uiNamespace variables (used in UI)
	3 - Create missionNamespace variables and initialize mission
	4 - Create only missionNamespace variables

******************************************************************************************************/

RscDisplayLoading_progressMission = nil;

//--- Get existing lists (create new ones when they doesn't exist)
private ["_functions_list","_functions_listPreInit","_functions_listPostInit","_functions_listPreStart","_functions_listRecompile","_file","_cfgSettings","_listConfigs","_recompileNames"];

_functions_listPreStart = [];
_functions_list = call (uinamespace getvariable ["bis_functions_list",{[]}]);
_functions_listPreInit = [call (uinamespace getvariable ["bis_functions_listPreInit",{[]}]),[]];
_functions_listPostInit = [call (uinamespace getvariable ["bis_functions_listPostInit",{[]}]),[]];
_functions_listRecompile = call (uinamespace getvariable ["bis_functions_listRecompile",{[]}]);

//--- When not forced, recompile only mission if uiNamespace functions exists
if (typename _recompile != typename 1) then {
	_recompile = if (count _functions_list > 0) then {3} else {0};
};

//--- When autodetect, recognize what recompile type is required
if (_recompile == 0 && !isnil {uinamespace getvariable "bis_fnc_init"}) then {_recompile = 3;};
if (_recompile == 3 && !isnil {missionnamespace getvariable "bis_fnc_init"}) then {_recompile = 4;};

_file = gettext (configfile >> "cfgFunctions" >> "file");
_cfgSettings = [
	[	configfile,		_file,		0	],	//--- 0
	[	campaignconfigfile,	"functions",	1	],	//--- 1
	[	missionconfigfile,	"functions",	1	]	//--- 2
];
	
_listConfigs = switch _recompile do {
	case 0: {
		[0,1,2];
	};
	case 1: {
		_functions_list = [];
		uinamespace setvariable ["bis_functions_list",_functions_list];
		_functions_listPreInit = [[],[]];
		uinamespace setvariable ["bis_functions_listPreInit",_functions_listPreInit];
		_functions_listPostInit = [[],[]];
		uinamespace setvariable ["bis_functions_listPostInit",_functions_listPostInit];
		_functions_listRecompile = [];
		uinamespace setvariable ["bis_functions_listRecompile",_functions_listRecompile];
		[0,1,2];
	};
	case 2: {
		[0];
	};
	case 3: {
		[1,2];
	};
	case 4: {
		[1,2];
	};
};


/******************************************************************************************************
	SCAN CFGFUNCTIONS

	Go through CfgFunctions, scan categories and declare all functions.

	Following variables are stored:
	<tag>_fnc_<functionName> - actual code of the function
	<tag>_fnc_<functionName>_meta - additional meta data of this format
		[<path>,<extension>,<header>,<preInit>,<postInit>,<recompile>,<category>]
		* path - path to actual file
		* extension - file extension, either ".sqf" or ".fsm"
		* header - header type. Usually 0, system functions are using 1 (see DEFINE HEADERS section)
		* preInit - function is executed automatically upon mission start, before objects are initalized
		* postInit - function is executed automatically upon mission start, after objects are initialized
		* recompile - function is recompiled upon mission start
		* category - function's category based on config structure

******************************************************************************************************/

//--- Allow recompile in dev version, in the editor and when description.ext contains 'allowFunctionsRecompile = 1;'
_compileFinal =
	//--- Dev version
	!cheatsEnabled
	&&
	//--- Editor mission
	((uinamespace getvariable ["gui_displays",[]]) find (finddisplay 26) != 1)
	&&
	//--- Manual toggle
	getnumber (missionconfigfile >> "allowFunctionsRecompile") == 0;

for "_t" from 0 to (count _listConfigs - 1) do {
	private ["_cfg","_pathConfig","_pathFile","_pathAccess","_cfgFunctions"];
	_cfg = _cfgSettings select (_listConfigs select _t);
	
	_cfg params ["_pathConfig","_pathFile","_pathAccess"];

	_cfgFunctions = (_pathConfig >> "cfgfunctions");
	for "_c" from 0 to (count _cfgFunctions - 1) do 
	{
		private ["_currentTag"];
		_currentTag = _cfgFunctions select _c;

		//--- Is Tag
		if (isClass _currentTag) then 
		{

			//--- Check of all required patches are in CfgPatches
			private ["_requiredAddons","_requiredAddonsMet"];
			_requiredAddons = getarray (_currentTag >> "requiredAddons");
			_requiredAddonsMet = true;
			{
				_requiredAddonsMet = _requiredAddonsMet && isclass (configfile >> "CfgPatches" >> _x);
			} count _requiredAddons;
			
			//--- Check If It's a Client or Server Only Function
			//private ["_clientOnly"];
			//_clientOnly = getnumber (_currentTag >> "clientOnly");
			//if (isServer or isDedicated) then {
			//	if (_clientOnly == 1) then {
			//		_requiredAddonsMet = false;
			//	};
			//};

			if (_requiredAddonsMet) then 
			{

				//--- Initialize tag
				private ["_tag","_tagName","_itemPathRag"];
				_tag = configname _currentTag;
				_tagName = gettext (_currentTag >> "tag");
				if (_tagName == "") then {_tagName = configname _currentTag};
				_itemPathTag = gettext (_currentTag >> "file");

				for "_i" from 0 to (count _currentTag - 1) do {
					private ["_currentCategory"];
					_currentCategory = _currentTag select _i;

					//--- Is Category
					if (isclass _currentCategory) then {
						private ["_categoryName","_itemPathCat"];
						_categoryName = configname _currentCategory;
						_itemPathCat = gettext (_currentCategory >> "file");

						for "_n" from 0 to (count _currentCategory - 1) do {
							private ["_currentItem"];
							_currentItem = _currentCategory select _n;

							//--- Is Item
							if (isClass _currentItem) then 
							{
								private ["_itemName","_itemPathItem","_itemExt","_itemPath","_itemVar","_itemCompile","_itemPreInit","_itemPostInit","_itemPreStart","_itemRecompile","_itemCheatsEnabled"];

								//--- Read function
								_itemName = configName _currentItem;
								_itemPathItem = getText (_currentItem >> "file");
								_itemExt = getText (_currentItem >> "ext");
								_itemPreInit = getNumber (_currentItem >> "preInit");
								_itemPostInit = getNumber (_currentItem >> "postInit");
								_itemPreStart = getNumber (_currentItem >> "preStart");
								_itemRecompile = getNumber (_currentItem >> "recompile");
								_itemCheatsEnabled = getNumber (_currentItem >> "cheatsEnabled");
								if (_itemExt == "") then {_itemExt = ".sqf"};
								_itemPath = if (_itemPathItem != "") then {_itemPathItem} else {
									if (_itemPathCat != "") then {_itemPathCat + "\fn_" + _itemName + _itemExt} else {
										if (_itemPathTag != "") then {_itemPathTag + "\fn_" + _itemName + _itemExt} else {""};
									};
								};
								_itemHeader = getNumber (_currentItem >> "headerType");
								
								//No Debug / Header Information On Breaking Point Functions
								if (_tagName != "BIS") then { _itemheader = -1; };

								//--- Compile function
								if (_itemPath == "") then {_itemPath = _pathFile + "\" + _categoryName + "\fn_" + _itemName + _itemExt};
								_itemVar = _tagName + "_fnc_" + _itemName;
								_itemMeta = [_itemPath,_itemExt,_itemHeader,_itemPreInit > 0,_itemPostInit > 0,_itemRecompile> 0,_tag,_categoryName];
								_itemCompile = if (_itemCheatsEnabled == 0 || (_itemCheatsEnabled > 0 && cheatsEnabled)) then {
									[_itemVar,_itemMeta,_itemHeader,_compileFinal] call _fncCompile;
								} else {
									{false} //--- Function not available in retail version
								};

								//--- Register function
								if (typename _itemCompile == typename {}) then 
								{
									if !(_itemVar in _functions_list) then {
										private ["_namespaces"];
										_namespaces = if (_pathAccess == 0) then {[uinamespace]} else {[missionnamespace]};
										{
											//---- Save function
											_x setvariable [
												_itemVar,
												_itemCompile
											];
											//--- Save function meta data
											_x setvariable [
												_itemVar + "_meta",
												compileFinal str _itemMeta
											];
										} count _namespaces;
										if (_pathAccess == 0) then { _functions_list pushBack _itemVar; };
									};

									//--- Add to list of functions executed upon mission start
									if (_itemPreInit > 0) then {
										_functions_listPreInitAccess = _functions_listPreInit select _pathAccess;
										if !(_itemVar in _functions_listPreInitAccess) then {
											_functions_listPreInitAccess pushBack _itemVar;
										};
									};
									if (_itemPostInit > 0) then {
										_functions_listPostInitAccess = _functions_listPostInit select _pathAccess;
										if !(_itemVar in _functions_listPostInitAccess) then {
											_functions_listPostInitAccess pushBack _itemVar;
										};
									};
								
									//--- Add to list of functions executed upon game start
									if (_itemPreStart > 0) then {
										if (_pathAccess == 0) then {
											if !(_itemVar in _functions_listPreStart) then {
												_functions_listPreStart pushBack _itemVar;
											};
										} else {
											_errorFnc = uinamespace getvariable "bis_fnc_error";
											_errorText = "%1 is a mission / campaign function and cannot contain 'preStart = 1;' param";
											if !(isnil {_errorFnc}) then {[_errorText,_itemVar] call _errorFnc;} else {diag_log format ["Log: [Functions]: " + _errorText,_itemVar];};
										};
									};

									//--- Add to list of functions recompiled upon mission start
									if (_itemRecompile > 0) then {
										if (_pathAccess == 0) then {
											if !(_itemVar in _functions_listRecompile) then {
												_functions_listRecompile pushBack _itemVar;
											};
										} else {
											_errorFnc = uinamespace getvariable "bis_fnc_error";
											_errorText = "Redundant use of 'recompile = 1;' in %1 - mission / campaign functions are recompiled on start by default.";
											if !(isnil {_errorFnc}) then {[_errorText,_itemVar] call _errorFnc;} else {diag_log format ["Log: [Functions]: " + _errorText,_itemVar];};
										};
									};

									//if (_itemRecompile > 0) then {
									//	_functions_listRecompileAccess = _functions_listRecompile select _pathAccess;
									//	_functions_listRecompileAccess pushBack _itemVar;
									//};
									//--- Debug
									//debuglog ["Log:::::::::::::::::::Function",_itemVar,_itemPath,_pathAccess];
								};
							};
						};
					};
				};
			};
		};
	};
};

//--- Save the lists
uinamespace setvariable ["BIS_functions_list",compileFinal str (_functions_list)];
uinamespace setvariable ["BIS_functions_listPreInit",compileFinal str (_functions_listPreInit select 0)];
uinamespace setvariable ["BIS_functions_listPostInit",compileFinal str (_functions_listPostInit select 0)];
uinamespace setvariable ["BIS_functions_listRecompile",compileFinal str (_functions_listRecompile)];


/******************************************************************************************************
	FINISH

	When functions are saved, following operations are executed:
	1. MissionNamespace shortcuts are created
	2. Functions with 'recompile' param set to 1 are recompiled
	3. Functions with 'preInit' param set to 1 are executed
	4. Multiplayer framework is initialized
	5. Modules are initialized (running their own scripts, functions just wait until those scripts are ready)
	6. Automatic scripts "initServer.sqf", "initPlayerServer.sqf" and "initPlayerLocal.sqf" are executed
	7. Functions with 'postInit' param set to 1 are executed

	When done, system will set 'bis_fnc_init' to true so other systems can catch it.

******************************************************************************************************/

//--- Not core
if (_recompile in [0,1,3,4]) then {
	{
		_allowRecompile = (_x call bis_fnc_functionMeta) select 5;

		_xCode = uinamespace getvariable _x;
		if (_allowRecompile || !_compileFinal) then {
			_xCode = call compile str (uinamespace getvariable _x);
		};
		missionnamespace setvariable [_x,_xCode];
	} count _functions_list;
};

//--- Core only
if (_recompile == 2) then {
	//--- Call preStart functions
	if (isnull (finddisplay 0)) then {
		{
			["preStart %1",_x] call bis_fnc_logFormat;
			_function = [] call (uinamespace getVariable _x);
			uinamespace setvariable [_x + "_preStart",_function];
		} count _functions_listPreStart;
	};
};

//--- Mission only
if (_recompile == 3) then 
{
	//--- Create functions logic (cannot be created when game is launching; server only)
	if (isserver && isnull (missionnamespace getvariable ["bis_functions_mainscope",objnull]) && !isnil {uinamespace getvariable "bis_fnc_init"} && worldname != "") then {
		private ["_grpLogic"];
		createCenter sideLogic;
		_grpLogic = createGroup sidelogic;
		bis_functions_mainscope = _grpLogic createUnit ["Logic",[9,9,9],[],0,"none"];
		bis_functions_mainscope setVariable ["isDedicated",isDedicated,true];
	};
	
	//--- Setup and Broadcast Breaking Point Version Numbers
	BP_versionNo = getText(configFile >> "CfgMods" >> "BreakingPoint" >> "version");
	if (isServer) then {
		sm_done = BP_versionNo;
		publicVariable "sm_done";
	};

	//--- Execute script preload
	if (isnil "BIS_fnc_preload_server") then {BIS_fnc_preload_server = compilefinal "true";};
	_fnc_scriptname = "BIS_fnc_preload";
	["----- Scripts initialized at %1 ms -----",(diag_ticktime - (_this select 0)) * 1000] call bis_fnc_logFormat;
	bis_fnc_preload_init = true;

	//--- Recompile selected functions
	_fnc_scriptname = "recompile";
	{
		["recompile %1",_x] call bis_fnc_logFormat;
		_x call bis_fnc_recompile;
	} count _functions_listRecompile;

	//--- Call preInit functions
	_fnc_scriptname = "preInit";
	{
		{
			_time = diag_ticktime;
			[_x] call {
				private ["_recompile","_functions_list","_functions_listPreInit","_functions_listPostInit","_functions_listRecompile","_time"];
				["preInit"] call (missionNamespace getVariable (_this select 0))
			};
			["%1 (%2 ms)",_x,(diag_ticktime - _time) * 1000] call bis_fnc_logFormat;
		} forEach _x;
	} forEach _functions_listPreInit;

	//--- Call postInit functions once player is present
	_functions_listPostInit spawn 
	{
		private ["_fnc_scriptName","_didJIP"];
		_fnc_scriptName = "script";
		_didJIP = false;

		//--- After JIP, units cannot be initialized during the loading screen		
		if !(isserver) then 
		{
			endloadingscreen;
			waituntil {!isnull cameraon && getClientState != "MISSION RECEIVED" && getClientState != "GAME LOADED"};
			_didJIP = getClientState == "BRIEFING READ";
			startloadingscreen [""];
			//startloadingscreen ["","RscDisplayLoadBreakingPoint"];
		};
		
		if (!isServer) then 
		{
			waitUntil {!isNull player};
			waitUntil {player == player};
			waitUntil {time > 3};
			
			if (hasInterface) then
			{
				//Invalid Object Checking
				if (player isKindOf "Animal" || player isKindOf "Seagull") exitWith { ["BP_ServerFailure"] call BP_fnc_loginError; };
				
				//Check Client / Server Version is Invalid Or Not
				if (!isNil "sm_done") then
				{
					//Parse Version Numbers
					_clientVer = parseNumber BP_VersionNo;
					_serverVer = parseNumber sm_done;
					
					//Outdated Client
					if (_clientVer < _serverVer) exitWith { ["BP_InvalidVersion"] call BP_fnc_loginError; };
					
					//Outdated Server
					if (_clientVer < _serverVer) exitWith { ["BP_OutdatedServer"] call BP_fnc_loginError; };
				};
				
				//Add Mission Event Handler
				addMissionEventHandler ["Draw3D",{_this call BP_fnc_onDraw3D}];
			};
			
			//Mark Preload as Completed
			missionNameSpace setVariable ["BP_preloadFinished",true];
		};

		//--- Call postInit functions
		_fnc_scriptname = "postInit";
		{
			{
				_time = diag_ticktime;
				[_x,_didJIP] call {
					private ["_didJIP","_time"];
					["postInit",_this select 1] call (missionNamespace getVariable (_this select 0))
				};
				["%1 (%2 ms)",_x,(diag_ticktime - _time) * 1000] call bis_fnc_logFormat;
			} forEach _x;
		} forEach _this;
		
		//--- Client Login
		if (!isServer and hasInterface) then 
		{
			//Wait Until Mission File Init.sqf has finished
			waitUntil {!isNil "BP_ServerInstance"};
			
			//Wait Until Server Functions have been received
			waitUntil {!isNil "BP_ClientFuncs"};
			{ 
				//["Waiting for Remote Function %1 to be defined",_x] call BP_fnc_debugConsoleFormat;
				waitUntil {!isNil _x};
			} count BP_ClientFuncs;
			
			//["All Remote Functions Loaded."] call BP_fnc_debugConsoleFormat;
			
			//Load One Time Bootup Functions
			call BP_fnc_initVarsOnce;
			call BP_fnc_initLoot;
			call BP_fnc_initPublicEH;
			call BP_fnc_InitDebug;
			
			//Removed because onPlayerRespawn will end the loading screen when the login fsm is ready
			cutText ["","BLACK OUT"];
			closeDialog 0;
			0 fadeSound 0;
			BP_loadScreenMsg = "Requesting Authentication";
			0 cutText ["Requesting Authentication", "BLACK FADED",60];
			endLoadingScreen;
		};

		//--- MissionNamespace init
		missionNamespace setVariable ["bis_fnc_init",true];
		
		disableRemoteSensors true;
	};
};

//--- Not mission
if (_recompile in [0,1,2]) then {

	//--- UInameSpace init
	uiNamespace setVariable ["bis_fnc_init",true]
};

//--- Only mission variables
if (_recompile in [4]) then {

	//--- MissionNameSpace init
	missionNamespace setVariable ["bis_fnc_init",true];
};

//--- Only mission variables
if (_recompile in [1]) then {
	"Functions recompiled" call bis_fnc_log;
};

//--- Log the info about selected recompile type
_recompileNames = [
	"ERROR: Autodetect failed",
	"Forced",			
	"Core Only",
	"Mission/Campaign Only"	
];