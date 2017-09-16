#include "\A3\ui_f\hpp\defineDIKCodes.inc"
#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_fnc_units = {
	private ["_groups","_allunits","_units"];
	_groups = if !(isnil {missionnamespace getvariable "RscSpectator_allowedGroups"}) then {missionnamespace getvariable "RscSpectator_allowedGroups"} else {allgroups};
	_allunits = playableunits + switchableunits;
	_units = [];
	{
		if (group _x in _groups) then {_units set [count _units,_x];};
	} foreach _allunits;
	if !(player in _units) then {_units set [count _units,player];};
	_units
};

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "onLoad": {
		_display = if (isnil {RscSpectator_display}) then {displaynull} else {RscSpectator_display};
		if (isnull _display) then {
			["init",_params,_class] spawn RscSpectator_script;
		};
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "init": {
		disableserialization;
		_display = _params select 0;
		_ctrlMap = _display displayctrl IDC_MAP;
		_ctrlMainMap = (finddisplay IDD_MAIN_MAP) displayctrl IDC_MAP;

		RscSpectator_display = _display;
		RscSpectator_vision = 0;
		RscSpectator_interface = true;
		RscSpectator_view = true;
		RscSpectator_map = false;
		RscSpectator_keys = [];
		if (isnil {RscSpectator_hints}) then {RscSpectator_hints = [false,false,false];};
		RscSpectator_playerIcon = gettext (configfile >> "cfgingameui" >> "cursor" >> "select");

		_displayMission = [] call bis_fnc_displayMission;
		_ctrlMap ctrladdeventhandler ["draw","with uinamespace do {['draw',_this,''] call RscSpectator_script};"];
		_ehDown = _displayMission displayaddeventhandler ["keydown","with uinamespace do {['keyDown',_this,''] call RscSpectator_script};"];
		_ehUp = _displayMission displayaddeventhandler ["keyup","with uinamespace do {['keyUp',_this,''] call RscSpectator_script};"];
		_ehClick = _ctrlMainMap ctrladdeventhandler ["mousebuttonclick","with uinamespace do {['click',_this,''] call RscSpectator_script};"];
		_ehDrawMap = _ctrlMainMap ctrladdeventhandler ["draw","with uinamespace do {['drawMap',_this,''] call RscSpectator_script};"];

		//--- Create camera
		_pos = getposatl cameraon;
		_pos set [2,(_pos select 2) + 2];
		_camera = "camera" camcreate _pos;
		_camera cameraeffect ["terminate","back"];
		_camera setdir direction cameraon;
		_camera camCommand "manual off";
		_camera camCommand "inertia on";
		showcinemaborder false;
		showhud false;

		missionnamespace setvariable ["RscSpectator_cameras",[[],[],[],[],[],[],[],[],[],[]]];
		missionnamespace setvariable ["RscSpectator_players",["","","","","","","","","",""]];
		with missionnamespace do {
			_units = [] call _fnc_units;
			RscSpectator_camera = _camera;
			RscSpectator_player = if (player in _units) then {player} else {if (count _units > 0) then {_units select 0} else {objnull}};
			if !(isnull RscSpectator_player) then {
				vehicle RscSpectator_player switchcamera cameraview
			} else {
				[] spawn {
					with uinamespace do {
						["keyDown",[displaynull,DIK_RIGHT,false,false,false],""] call RscSpectator_script;
						["keyUp",[displaynull,DIK_RIGHT,false,false,false],""] call RscSpectator_script;
					};
				};
			};
		};

		missionnamespace setvariable ["RscStatic_mode",0];
		("RscSpectator_fade" call bis_fnc_rscLayer) cutrsc ["rscstatic","plain"];

		if !(RscSpectator_hints select 0) then {
			RscSpectator_hints set [0,true];
			with missionnamespace do {
				[["spectating","spectatorinfo"]] spawn BIS_fnc_advHint;
				[["spectating","spectatorcamera"]] spawn BIS_fnc_advHint;
			};
		};

		//["switchView",[false,true],""] call RscSpectator_script;
		_camParams = [position _camera,vectorup _camera,vectordir _camera,velocity _camera];

		//--- Loop
		waituntil {
			//--- Disable free cam
			_allowFreeCam = if !(isnil {missionnamespace getvariable "RscSpectator_allowFreeCam"}) then {missionnamespace getvariable "RscSpectator_allowFreeCam"} else {true};
			if (!RscSpectator_view && !_allowFreeCam) then {["switchView",[false,true],""] call RscSpectator_script;};

			_time = time + 0.1;
			waituntil {isnull _camera || time > _time};

			//--- Restore the camera after RMB was pressed
			if (isnull _camera) then {
				_camera = "camera" camcreate getposatl cameraon;
				_camera cameraeffect ["internal","back"];
				_camera setpos (_camParams select 0);
				_camera setvectordir (_camParams select 1);
				_camera setVectorup (_camParams select 2);
				_camera setvelocity (_camParams select 3);
				_camera camCommand "inertia on";
				_camera camCommand "manual on";
				with missionnamespace do {
					RscSpectator_camera = _camera;
				};
			};
			_camParams = [position _camera,vectordir _camera,vectorup _camera,velocity _camera];
			isnull _display
		};
		//////////////////////////////////////////////////////////////////////////////////////////////////////////

		//--- Display closed
		("RscSpectator_fade" call bis_fnc_rscLayer) cuttext ["","black in"];
		showhud true;

		_display closedisplay 2;
		_displayMission displayremoveeventhandler ["keydown",_ehDown];
		_displayMission displayremoveeventhandler ["keyup",_ehUp];
		_ctrlMainMap ctrlremoveeventhandler ["mousebuttonclick",_ehClick];
		_ctrlMainMap ctrlremoveeventhandler ["draw",_ehDrawMap];

		RscSpectator_display = nil;
		RscSpectator_map = nil;
		RscSpectator_keys = nil;

		_camera cameraeffect ["terminate","back"];
		camdestroy _camera;

		with missionnamespace do {
			RscSpectator_player = nil;
			RscSpectator_camera = nil;
		};

		player switchcamera "internal";
	};
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "keyDown": {
		_key = _params select 1;
		if !(_key in RscSpectator_keys) then {RscSpectator_keys set [count RscSpectator_keys,_key];};
		_ctrl = (DIK_LCONTROL) in RscSpectator_keys;

		_switchPlayer = false;
		_deltaPlayerID = 0;
		_result = false;
		_camera = missionnamespace getvariable ["RscSpectator_camera",objnull];
		_view = RscSpectator_view;

		//--- Store players
		_setPlayer = {
			with missionnamespace do {
				RscSpectator_players set [_this,name RscSpectator_player];
			};
		};
		_getPlayer = {
			with missionnamespace do {
				_playerName = RscSpectator_players select _this;
				_currentPlayerName = name RscSpectator_player;
				_units = [] call _fnc_units;
				{
					if (name _x == _playerName && _playerName != _currentPlayerName) exitwith {
						_switchPlayer = true;
						RscSpectator_player = _x;
					};
				} foreach _units;
			};
		};

		//--- Store camera settings
		_setCamera = {
			with missionnamespace do {
				_cameraParams = if (_view) then {
					[_view,name RscSpectator_player,cameraview]
				} else {
					[_view,position RscSpectator_camera,vectordir RscSpectator_camera,vectorup RscSpectator_camera,velocity _camera]
				};
				RscSpectator_cameras set [_this,_cameraParams];
			};
		};
		_getCamera = {
			_cameraParams = (missionnamespace getvariable "RscSpectator_cameras") select _this;

			_view = _cameraParams select 0;
			_currentView = RscSpectator_view;
			_switchView = str _view != str _currentView;
			RscSpectator_view = _view;
			if (_switchView) then {RscSpectator_view = !RscSpectator_view};
			if (_view) then {
				_playerName = _cameraParams select 1;
				_cameraView = _cameraParams select 2;
				_units = [] call _fnc_units;
				{
					if (name _x == _playerName) exitwith {
						_switchPlayer = true;
						missionnamespace setvariable ["RscSpectator_player",_x];
					};
				} foreach _units;

				["switchView",[false,_switchView],""] call RscSpectator_script;
				cameraon switchcamera _cameraView;
			} else {
				["switchView",[false,_switchView],""] call RscSpectator_script;

				_position = _cameraParams select 1;
				_vectordir = _cameraParams select 2;
				_vectorup = _cameraParams select 3;
				_velocity = _cameraParams select 4;

				_camera camcommand "manual off";
				_camera campreparetarget objnull;
				_camera camcommitprepared 0;
				_camera setpos _position;
				_camera setvectordir _vectordir;
				_camera setvectorup _vectorup;
				_camera setvelocity _velocity;
				_camera camcommand "manual on";
			};
		};
		switch _key do {
			case (DIK_ESCAPE): {
				if (RscSpectator_map) then {
					openmap [false,false];
					RscSpectator_map = false;
				};
			};
			case (DIK_SPACE): {
				if !(RscSpectator_map) then {
					["switchView",[_ctrl,true],""] call RscSpectator_script;
					_result = true;
				};
			};
			case (DIK_LMENU): {
				if !(RscSpectator_map) then {
					["switchView",[_ctrl,false],""] call RscSpectator_script;
					_result = true;
				};
			};
			case (DIK_NUMPAD0): {
				_result = !_view; //--- Disable escaping camera by Numpad 0
			};

			case (DIK_N): {
				RscSpectator_vision = RscSpectator_vision + 1;
				_vision = RscSpectator_vision % 3;
				switch (_vision) do {
					case 0: {
						camusenvg false;
						false SetCamUseTi 0;
					};
					case 1: {
						camusenvg true;
						false SetCamUseTi 0;
					};
					case 2: {
						camusenvg false;
						true SetCamUseTi 0;
					};
					case 3: {
						camusenvg false;
						true SetCamUseTi 1;
					};
				};
				_result = true;
			};
			case (DIK_M): {
				if (RscSpectator_map) then {
					openmap [false,false];
					RscSpectator_map = false;
				} else {
					openmap [true,true];
					RscSpectator_map = true;
					mapanimadd [0,0.1,position _camera];
					mapanimcommit;
				};
			};

			case (DIK_J): {
				_display = RscSpectator_display;
				_fade = [0,1] select RscSpectator_interface;
				{
					_control = _display displayctrl _x;
					_control ctrlsetfade _fade;
					_control ctrlcommit 0.2;
				} foreach [
					IDC_RSCSPECTATOR_PLAYER,
					IDC_RSCSPECTATOR_PLAYERICON
				];
				RscSpectator_interface = !RscSpectator_interface;
				_result = true;			
			};

			case (DIK_LEFT): {_deltaPlayerID = -1; _switchPlayer = true; _result = true;};
			case (DIK_RIGHT): {_deltaPlayerID = +1; _switchPlayer = true; _result = true;};
			case (DIK_DOWN): {_deltaPlayerID = -10; _switchPlayer = true; _result = true;};
			case (DIK_UP): {_deltaPlayerID = +10; _switchPlayer = true; _result = true;};

			case (DIK_F1): {if (_ctrl) then {0 call _setPlayer} else {0 call _getPlayer}; _result = true;};
			case (DIK_F2): {if (_ctrl) then {1 call _setPlayer} else {1 call _getPlayer}; _result = true;};
			case (DIK_F3): {if (_ctrl) then {2 call _setPlayer} else {2 call _getPlayer}; _result = true;};
			case (DIK_F4): {if (_ctrl) then {3 call _setPlayer} else {3 call _getPlayer}; _result = true;};
			case (DIK_F5): {if (_ctrl) then {4 call _setPlayer} else {4 call _getPlayer}; _result = true;};
			case (DIK_F6): {if (_ctrl) then {5 call _setPlayer} else {5 call _getPlayer}; _result = true;};
			case (DIK_F7): {if (_ctrl) then {6 call _setPlayer} else {6 call _getPlayer}; _result = true;};
			case (DIK_F8): {if (_ctrl) then {7 call _setPlayer} else {7 call _getPlayer}; _result = true;};
			case (DIK_F9): {if (_ctrl) then {8 call _setPlayer} else {8 call _getPlayer}; _result = true;};
			case (DIK_F10): {if (_ctrl) then {9 call _setPlayer} else {9 call _getPlayer}; _result = true;};

			case (DIK_1): {if (_ctrl) then {0 call _setCamera} else {0 call _getCamera}; _result = true;};
			case (DIK_2): {if (_ctrl) then {1 call _setCamera} else {1 call _getCamera}; _result = true;};
			case (DIK_3): {if (_ctrl) then {2 call _setCamera} else {2 call _getCamera}; _result = true;};
			case (DIK_4): {if (_ctrl) then {3 call _setCamera} else {3 call _getCamera}; _result = true;};
			case (DIK_5): {if (_ctrl) then {4 call _setCamera} else {4 call _getCamera}; _result = true;};
			case (DIK_6): {if (_ctrl) then {5 call _setCamera} else {5 call _getCamera}; _result = true;};
			case (DIK_7): {if (_ctrl) then {6 call _setCamera} else {6 call _getCamera}; _result = true;};
			case (DIK_8): {if (_ctrl) then {7 call _setCamera} else {7 call _getCamera}; _result = true;};
			case (DIK_9): {if (_ctrl) then {8 call _setCamera} else {8 call _getCamera}; _result = true;};
			case (DIK_0): {if (_ctrl) then {9 call _setCamera} else {9 call _getCamera}; _result = true;};

		};

		with missionnamespace do {
			_units = [] call _fnc_units;
			if (_switchPlayer && count _units > 0) then {
				_playerID = _units find RscSpectator_player;
				_playerID = _playerID + _deltaPlayerID;
				_playerID = ((count _units) + _playerID) % (count _units);
				RscSpectator_player = _units select _playerID;
				if (_view) then {
					vehicle RscSpectator_player switchcamera cameraview;
					("RscSpectator_fade" call bis_fnc_rscLayer) cuttext ["","black in"];
				};
			};
		};

		_result
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "keyUp": {
		_key = _params select 1;
		RscSpectator_keys = RscSpectator_keys - [_key];
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "switchView": {
		_ctrl = _params select 0;
		_static = _params select 1;

		_allowFreeCam = if !(isnil {missionnamespace getvariable "RscSpectator_allowFreeCam"}) then {missionnamespace getvariable "RscSpectator_allowFreeCam"} else {true};
		_player = missionnamespace getvariable ["RscSpectator_player",player];
		if (!_allowFreeCam && isnull _player) then {
			_camera camCommand "manual off";
			_camera cameraeffect ["terminate","back"];
			player switchcamera "internal";
		} else {
			if !(_static) then {RscSpectator_view = !RscSpectator_view;};

			if (RscSpectator_view) then {

				//--- FreeCam
				if (_allowFreeCam) then {

					if (!_ctrl) then {
						_intCameraPosition = _player selectionposition "pilot";
						_extCameraPosition = getarray (configfile >> "CfgVehicles" >> typeof vehicle _player >> "extCameraPosition");
						if (count _extCameraPosition != 3) then {_extCameraPosition = [0,0,0]};
						_cameraPosition = [0,0,0];
						_cameraPosition set [0,(_intCameraPosition select 0) + (_extCameraPosition select 0)];
						_cameraPosition set [1,(_intCameraPosition select 1) + (_extCameraPosition select 2)]; //
						_cameraPosition set [2,(_intCameraPosition select 2) + (_extCameraPosition select 1)];
						_camera	setpos (_player modeltoworld _cameraPosition);
						_camera campreparetarget vehicle _player;
						_camera camcommitprepared 0;
					};

					_camera setvelocity [0,0,0];
					_camera camcommand "manual on";
					_camera cameraeffect ["internal","back"];
					cameraeffectenablehud true;

					if (_static) then {
						missionnamespace setvariable ["RscStatic_mode",0];
						("RscSpectator_fade" call bis_fnc_rscLayer) cutrsc ["rscstatic","plain"];
					} else {
						("RscSpectator_fade" call bis_fnc_rscLayer) cuttext ["","black in"];
					};

					if !(RscSpectator_hints select 1) then {
						RscSpectator_hints set [1,true];
						with missionnamespace do {
							[["spectating","spectatorfreeview"]] spawn BIS_fnc_advHint;
						};
					};
				};
				RscSpectator_view = !RscSpectator_view;
			} else {
				if (_static) then {
					//--- Player view
					_camera camCommand "manual off";
					_camera cameraeffect ["terminate","back"];
					_camera setvelocity [0,0,0];
					vehicle _player switchcamera cameraview;

					if (_allowFreeCam) then {
						if (_static) then {
							missionnamespace setvariable ["RscStatic_mode",0];
							("RscSpectator_fade" call bis_fnc_rscLayer) cutrsc ["rscstatic","plain"];
						} else {
							("RscSpectator_fade" call bis_fnc_rscLayer) cuttext ["","black in"];
						};
					};

					if !(RscSpectator_hints select 2) then {
						RscSpectator_hints set [2,true];
						with missionnamespace do {
							[["spectating","spectatorunitview"]] spawn BIS_fnc_advHint;
						};
					};
				};
				RscSpectator_view = !RscSpectator_view;
			};
		};
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "click": {
		_button = _params select 1;
		if (_button == 0) then {
			_x = _params select 2;
			_y = _params select 3;
			_worldpos = (_params select 0) posscreentoworld [_x,_y];
			_camera = missionnamespace getvariable ["RscSpectator_camera",objnull];
			_camera setpos [_worldpos select 0,_worldpos select 1,getposatl _camera select 2];
		};
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "draw": {
		_display = ctrlparent (_params select 0);
		_ctrlPlayer = _display displayctrl IDC_RSCSPECTATOR_PLAYER;
		_ctrlPlayerNameBackground = _display displayctrl IDC_RSCSPECTATOR_PLAYERNAMEBACKGROUND;
		_ctrlPlayerName = _display displayctrl IDC_RSCSPECTATOR_PLAYERNAME;
		_ctrlPlayerGroup = _display displayctrl IDC_RSCSPECTATOR_PLAYERGROUP;
		_ctrlPlayerIcon = _display displayctrl IDC_RSCSPECTATOR_PLAYERICON;
		_ctrlPlayerIconPos = ctrlposition _ctrlPlayerIcon;
		_ctrlPlayerIconPos set [0,-1];
		_ctrlPlayerIconPos set [1,-1];

		_player = missionnamespace getvariable "RscSpectator_player";
		if (isnull _player) then {
			_ctrlPlayer ctrlshow false;
			_ctrlPlayerIconPos set [0,-1];
			_ctrlPlayerIconPos set [1,-1];
			_ctrlPlayerIcon ctrlsetposition _ctrlPlayerIconPos;
			_ctrlPlayerIcon ctrlcommit 0;
		} else {
			_playerName = "";
			_playerColor = [0,0,0,1];
			if (alive _player) then {
				_playerName = name _player;
				_playerColor = side _player call bis_fnc_sidecolor;
			};

			_ctrlPlayer ctrlshow true;
			_ctrlPlayerName ctrlsettext _playerName;
			_ctrlPlayerNameBackground ctrlsetbackgroundcolor _playerColor;
			_ctrlPlayerGroup ctrlsettext gettext (configfile >> "cfgvehicles" >> typeof vehicle _player >> "displayName");

			if !(RscSpectator_view || RscSpectator_map) then {
				_playerPos = getposatl _player;
				if ((getterrainheightasl _playerPos) < 0) then {_playerPos = getposasl _player;};
				_playerScreenPos = worldtoscreen _playerPos;
				if (count _playerScreenPos > 0) then {
					_ctrlPlayerIconPos set [0,(_playerScreenPos select 0) - (_ctrlPlayerIconPos select 2) / 2];
					_ctrlPlayerIconPos set [1,(_playerScreenPos select 1) - (_ctrlPlayerIconPos select 3) / 2];
					_ctrlPlayerIcon ctrlsettextcolor _playerColor;
				};
			};
		};
		_ctrlPlayerIcon ctrlsetposition _ctrlPlayerIconPos;
		_ctrlPlayerIcon ctrlcommit 0;
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "drawMap": {
		_ctrlMap = _params select 0;
		_camera = missionnamespace getvariable ["RscSpectator_camera",objnull];

		_ctrlMap drawIcon [
			"\a3\Ui_f\data\GUI\Rsc\RscDisplayMissionEditor\iconCamera_ca.paa",
			[0,0,0,1],
			position _camera,
			32,
			32,
			direction _camera
		];
	};
};