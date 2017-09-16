with uiNamespace do 
{
	#include "\A3\ui_f\hpp\defineResincl.inc"
	#include "\A3\ui_f\hpp\defineResinclDesign.inc"

	_mode = _this select 0;
	_params = _this select 1;
	_class = _this select 2;

	switch _mode do 
	{

		case "onLoad": 
		{
			disableSerialization;

			_display = _params select 0;
			RscDisplayLoading_display = _display;

			//--- Initial loading - maintain visual style of RscDisplayStart
			if !(uiNamespace getVariable ["BIS_initGame",false]) exitWith 
			{
				_ctrlMap = _display displayCtrl 1200;
				_cfgLoading = configFile >> "CfgLoadingScreens" >> "World";
				_loadingScreens = getArray (_cfgLoading >> "General");
				_loadingScreen = _loadingScreens call BIS_fnc_selectRandom;
				_ctrlMap ctrlSetText _loadingScreen;
				_ctrlMap ctrlCommit 0;
			};

			///////////////////////////////////////////////////////////////////////////////////////////

			//--- Hide start loading screen
			_ctrlLoadingStart = _display displayCtrl IDC_LOADINGSTART_LOADINGSTART;
			_ctrlLoadingStart ctrlSetFade 1;
			_ctrlLoadingStart ctrlCommit 0;
			_pictureShot = "";
			

			//--- Map
			if (worldName != "") then 
			{
				//Setup Controls
				_ctrlMap = _display displayCtrl IDC_LOADING_MAP;
			
				//World Name / Desc
				_cfgWorld = configFile >> "CfgWorlds" >> worldName;
				_worldName = getText (_cfgWorld >> "description");
				
				//Random World Specific Loading Screen
				_cfgLoading = configFile >> "CfgLoadingScreens" >> "World";
				//_loadingScreens = getArray (_cfgLoading >> worldName);
				_loadingScreens = getArray (_cfgLoading >> "General");
				_loadingScreen = _loadingScreens call BIS_fnc_selectRandom;
				
				//Set Texts / Resources
				_ctrlMap ctrlSetText _loadingScreen;
				_ctrlMap ctrlCommit 0;

				//_ctrlMap = _display displayctrl IDC_LOADING_MAP;
				//_ctrlMapName = _display displayctrl IDC_LOADING_MAPNAME;
				//_ctrlMapAuthor = _display displayctrl IDC_LOADING_MAPAUTHOR;
				//_ctrlMapDescription = _display displayctrl IDC_LOADING_MAPDESCRIPTION;

				//_cfgWorld = configfile >> "cfgworlds" >> worldname;
				//_worldName = gettext (_cfgWorld >> "description");
				//_pictureMap = gettext (_cfgWorld >> "pictureMap");
				//if (_pictureMap == "") then {_pictureMap = "#(argb,8,8,3)color(1,1,1,0.2)";};
				//_pictureShot = gettext (_cfgWorld >> "pictureShot");
				//_loadingTexts = getarray (_cfgWorld >> "loadingTexts");
				//_loadingText = if (count _loadingTexts > 0) then {
				//	_loadingTexts select floor (((diag_ticktime / 10) % (count _loadingTexts)));
				//} else {
				//	""
				//};

				//--- Randomized map Y coordinate
				//_worldType = uinamespace getvariable ["RscDisplayLoading_worldType",""];
				//_ran = uinamespace getvariable ["RscDisplayLoading_ran",random 1];
				//if (worldname != _worldType) then {
				//	_ran = random 1;
				//	uinamespace setvariable ["RscDisplayLoading_ran",_ran];
				//	uinamespace setvariable ["RscDisplayLoading_worldType",worldname];
				//};
				//_ctrlMapPos = ctrlposition _ctrlMap;
				//_ctrlMapPos set [1,linearconversion [0,1,_ran,(safezoneY + safezoneH - (_ctrlMapPos select 3)),safezoneY,true]];
				//_ctrlMap ctrlsetposition _ctrlMapPos;
				//ctrlMap ctrlcommit 0;

				//--- Set texts
				//_ctrlMap ctrlsettext _pictureMap;
				//_ctrlMapName ctrlsettext toupper _worldName;
				//_ctrlMapAuthor ctrlsettext _author;
				//_ctrlMapDescription ctrlsetstructuredtext parsetext _loadingText;

				//[_cfgWorld,_ctrlMapAuthor] call bis_fnc_overviewauthor;
			};
			
			//--- Mission
			_fnc_loadMission = 
			{
				disableSerialization;
				
				_display = _this select 0;
				_isMultiplayer = serverTime > 0;

				/*
				_ctrlMissionType = _display displayctrl IDC_LOADING_MISSIONGAMETYPE;
				_ctrlMissionName = _display displayctrl IDC_LOADING_MISSIONNAME;
				_ctrlMissionAuthor = _display displayctrl IDC_LOADING_MISSIONAUTHOR;
				_ctrlMissionPicture = _display displayctrl IDC_LOAD_MISSION_PICTURE;
				_ctrlMissionProgress = _display displayctrl IDC_PROGRESS_TIME;
				_ctrlMissionDescription = _display displayctrl IDC_LOADING_MISSIONDESCRIPTION;
				_ctrlMissionDescriptionEngine = _display displayctrl IDC_LOAD_MISSION_NAME;

				//--- Picture
				_loadingPicture = gettext (missionconfigfile >> "loadScreen");
				if (_loadingPicture == "") then {_loadingPicture = gettext (missionconfigfile >> "overviewPicture");}; //--- Use overview data

				//--- Mission name
				_loadingName = gettext (missionconfigfile >> "onLoadName");

				//--- Description
				_loadingTextConfig = if (false) then {gettext (missionconfigfile >> "onLoadIntro")} else {gettext (missionconfigfile >> "onLoadMission")};
				_loadingText = ctrltext _ctrlMissionDescriptionEngine;
				if (_loadingText == "") then {_loadingText = _loadingTextConfig;}; //--- Use overview data
				if (_loadingText in ["",localize "str_load_world"]) then {_loadingText = gettext (missionconfigfile >> "overviewText");};

				//--- MP type
				_gameType = gettext (missionconfigfile >> "Header" >> "gameType");
				_gameTypeName = gettext (configfile >> "CfgMPGameTypes" >> _gameType >> "name");
				if (_gameTypeName == "") then {_gameTypeName = gettext (configfile >> "CfgMPGameTypes" >> "Unknown" >> "name");};

				//_showMission = if (false) then {missionconfigfile >> "onLoadIntroTime"} else {missionconfigfile >> "onLoadMissionTime"};
				//_showMission = if (isnumber _showMission) then {getnumber _showMission > 0} else {true};
				//if (_showMission && (_loadingText != "" || _loadingPicture != "")) then {

				//--- When loading a different terrain, current mission is sometimes still available. Check if it belongs to the terrain.
				_last = uinamespace getvariable ["RscDisplayLoading_last",[worldname,missionname]];
				_lastWorld = _last select 0;
				_lastMission = _last select 1;
				_showMission = if (missionname == _lastMission) then {worldname == _lastWorld} else {true};
				uinamespace setvariable ["RscDisplayLoading_last",[worldname,missionname]];

				//--- Get loading bars
				_progressMap = _display displayctrl IDC_PROGRESS_PROGRESS;
				if (isnull _progressMap) then {_display displayctrl IDC_CLIENT_PROGRESS};
				_progressMission = _display displayctrl IDC_LOADING_PROGRESSMISSION;
				RscDisplayLoading_progress = _progressMap;

				if (str missionconfigfile != "" && _showMission) then {
					_loadingName = _loadingName call (uinamespace getvariable "bis_fnc_localize");
					_loadingText = _loadingText call (uinamespace getvariable "bis_fnc_localize");

					if (_loadingName == "") then {_loadingName = briefingname;};
					if (_loadingName == "") then {_loadingName = localize "STR_a3_rscdisplay_loading_noname";};
					if (_loadingPicture == "") then {_loadingPicture = _pictureShot;};

					if (_gameTypeName != "" && _isMultiplayer) then {
						_ctrlMissionType ctrlsettext toupper _gameTypeName;
					} else {
						_ctrlMissionType ctrlshow false;
					};
					_ctrlMissionName ctrlsettext toupper _loadingName;
					_ctrlMissionPicture ctrlsettext _loadingPicture;
					_ctrlMissionDescription ctrlsetstructuredtext parsetext _loadingText;

					//--- Set height based on text
					_ctrlMissionDescriptionPos = ctrlposition _ctrlMissionDescription;
					_ctrlMissionDescriptionPos set [3,ctrltextheight _ctrlMissionDescription + 0.01];
					if (_loadingText == "") then {_ctrlMissionDescriptionPos set [3,0];};
					_ctrlMissionDescription ctrlsetposition _ctrlMissionDescriptionPos;
					_ctrlMissionDescription ctrlcommit 0;

					[missionconfigfile,_ctrlMissionAuthor] call bis_fnc_overviewauthor;

					//--- Mission loading bar
					_progressMapPos = ctrlposition _progressMap;
					_progressMissionPos = ctrlposition _progressMission;
					if (missionnamespace getvariable ["RscDisplayLoading_progressMission",false]) then {

						//--- Mission loading - make the terrain bar full and animate only the mission bar
						_progressMap ctrlsetposition _progressMissionPos;
						_progressMap ctrlcommit 0;
						_progressMission ctrlsetposition _progressMapPos;
						_progressMission ctrlcommit 0;
						_progressMission progresssetposition 1;
					} else {

						//--- When loading a different map, a rogue loading screen without progress bar appears. Move the progress bar by script.
						_limit = [1,2] select _isMultiplayer;
						if (count (uinamespace getvariable "loading_displays") > _limit) then {
							_progressMap ctrlshow false;
							_progressMission ctrlsetposition _progressMapPos;
							_progressMission ctrlcommit 0;
							_progressMission progresssetposition 0.33;
						} else {
							_progressMission ctrlshow false;
						};
					};
				} else {
					_ctrlMission ctrlsetfade 1;
					_ctrlMission ctrlcommit 0;
				};
				*/
			};

			//_ctrlMission = _display displayCtrl IDC_LOADING_MISSION;
			//if (!(isNull _ctrlMission)) then { [_display,0] call _fnc_loadMission; };

		};
	};
};