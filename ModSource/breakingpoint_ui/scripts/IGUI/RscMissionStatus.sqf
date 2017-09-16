#include "\A3\ui_f\hpp\defineResinclDesign.inc"

#define ICONDISMIN	500
#define ICONDISMAX	2500
#define DISMAX		3000

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {

		_displayPrevious = uinamespace getvariable ["RscMissionStatus_display",displaynull];
		_display = _params select 0;
		if (ctrlidd _display < 0 && ctrlidd _displayPrevious > 0) exitwith {
			_group = _display displayctrl IDC_RSCMISSIONSTATUS_RSCMISSIONSTATUS;
			_group ctrlshow false;
		};
		uinamespace setvariable ["RscMissionStatus_display",_display];

		_group = _display displayctrl IDC_RSCMISSIONSTATUS_RSCMISSIONSTATUS;
		_groupPos = ctrlposition _group;
		_groupPos set [3,0];
		_group ctrlsetposition _groupPos;
		_group ctrlcommit 0;

		//--- When the group is on the left side, show progress bars on right
		if ((_groupPos select 0) < 0.5) then {
			_slot1Background = _display displayctrl IDC_RSCMISSIONSTATUS_SLOT1BACKGROUND;
			_ctrlBarBridge = _display displayctrl IDC_RSCMISSIONSTATUS_BARBRIDGE;
			_ctrlBarBridgePos = ctrlposition _ctrlBarBridge;
			_ctrlBarBridgePos set [0,ctrlposition _slot1Background select 0];
			_ctrlBarBridge ctrlsetposition _ctrlBarBridgePos;
			_ctrlBarBridge ctrlcommit 0;

			_posX = (_ctrlBarBridgePos select 0) + (_ctrlBarBridgePos select 2);
			{
				_ctrl = _display displayctrl _x;
				_ctrlPos = ctrlposition _ctrl;
				_ctrlPos set [0,_posX];
				_ctrl ctrlsetposition _ctrlPos;
				_ctrl ctrlcommit 0;
			} foreach [
				IDC_RSCMISSIONSTATUS_BARWEST,
				IDC_RSCMISSIONSTATUS_BAREAST,
				IDC_RSCMISSIONSTATUS_BARGUER,
				IDC_RSCMISSIONSTATUS_BARCIV
			];
		};


		//--- Show 3D sector icons
		if (isnil {missionnamespace getvariable "RscMissionStatus_draw3D"}) then {
			_draw3d = addmissioneventhandler [
				"draw3d",
				{
					if (difficultyenabled "hud") then {
						_sectors3D = missionnamespace getvariable ["RscMissionStatus_sectors3D",[]];
						_size = 1.5;
						_cam = if (isclass (configfile >> "CfgFunctions" >> "Curator_F")) then {call compile "curatorcamera"} else {objnull}; //--- Testing camera. ToDo: Remove
						if (isnull _cam) then {
							_cam = cameraon;
							_size = 1;
						};
						_alt = getposatl _cam select 2;
						_disMin = ICONDISMIN + _alt * 4;
						_disMax = ICONDISMAX + _alt * 4;
						{
							_player = _x select 0;
							_pos = _x select 1;
							_designation = _x select 2;
							_ownerTexture = _x select 3;
							_ownerColor = _x select 4;

							_alpha = linearconversion [_disMin,_disMax,_player distance _pos,0.5,0,true];
							_ownerColor set [3,_alpha];
							_textColor = [0,0,0,_alpha];
							drawicon3d [_ownerTexture,_ownerColor,_pos,_size,_size,0,""];
							drawicon3d ["#(argb,8,8,3)color(0,0,0,0)",_textColor,_pos,0,-0.55 * _size,0,_designation,false,_size * 0.03];
						} foreach _sectors3D;

						//--- Reopen the display
						if (isnull (uinamespace getvariable ["RscMissionStatus_display",displaynull])) then {
							_layer = "RscMissionStatus" call bis_fnc_rscLayer;
							_layer cutrsc ["RscMPProgress","plain"];
						};
					};
				}
			];
			missionnamespace setvariable ["RscMissionStatus_draw3D",_draw3D];
		};

		_params spawn {
			scriptname "RscDisplayMissionStatus";
			disableserialization;
			_display = _this select 0;
			_slots = [
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT1,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT2,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT3,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT4,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT5,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT6,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT7,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT8,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT9,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT0
			];
			_slotTexts = [
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT1TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT2TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT3TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT4TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT5TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT6TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT7TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT8TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT9TEXT,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT0TEXT
			];
			_slotBackgrounds = [
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT1BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT2BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT3BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT4BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT5BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT6BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT7BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT8BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT9BACKGROUND,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT0BACKGROUND
			];
			_slotProgresses = [
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT1PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT2PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT3PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT4PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT5PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT6PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT7PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT8PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT9PROGRESS,
				_display displayctrl IDC_RSCMISSIONSTATUS_SLOT0PROGRESS
			];
			_slotProgressPosHDefault = ctrlposition (_slotProgresses select 0) select 3;

			//--- Clicked on a slot
			{
				_slot = _x;
				{
					_slot ctrladdeventhandler [_x,format ["with uinamespace do {['buttonClick',_this + ['%1'],''] call RscMIssionStatus_script}",_x]];
				} foreach ["mousebuttonclick","mousebuttondblclick"];
			} foreach _slots;

			_ctrlBarBridge = _display displayctrl IDC_RSCMISSIONSTATUS_BARBRIDGE;
			_ctrlBarWest = _display displayctrl IDC_RSCMISSIONSTATUS_BARWEST;
			_ctrlBarEast = _display displayctrl IDC_RSCMISSIONSTATUS_BAREAST;
			_ctrlBarGuer = _display displayctrl IDC_RSCMISSIONSTATUS_BARGUER;
			_ctrlBarCiv = _display displayctrl IDC_RSCMISSIONSTATUS_BARCIV;
			_ctrlBarUnknown = _display displayctrl IDC_RSCMISSIONSTATUS_BARUNKNOWN;

			_ctrlBarBridge ctrlsetfade 1;
			_ctrlBarBridge ctrlcommit 0;

			{
				_x ctrlsetfade 1;
				_x ctrlcommit 0;
			} foreach [_ctrlBarWest,_ctrlBarEast,_ctrlBarGuer,_ctrlBarCiv,_ctrlBarUnknown];

			_colorWarning = ["IGUI","WARNING_RGB"] call bis_fnc_displayColorGet;
			_colorError = ["IGUI","Error_RGB"] call bis_fnc_displayColorGet;
			_colorDefault = [0.25,0.25,0.25,0.75];//sideUnknown call bis_fnc_sidecolor;
			_currentSectorOld = objnull;
			_fadeTime = 0.4;
			_showSide = false;
			_sides = [east,west,resistance,civilian];
			_sideOld = sideunknown;
			_icons = ["","","","",""];
			_names = ["","","","",""];
			_respawns = [[],[],[],[],[]];
			_textures = [
				"o_installation" call bis_fnc_textureMarker,
				"b_installation" call bis_fnc_textureMarker,
				"n_installation" call bis_fnc_textureMarker,
				"n_installation" call bis_fnc_textureMarker,
				"u_installation" call bis_fnc_textureMarker
			];

			//--- Continue only once briefing is finished
			waituntil {time > 0};

			//--- LOOP -------------------------------------------------------------------------------------------------------
			while {_display == uinamespace getvariable ["RscMissionStatus_display",_display]} do {
				_slotData = [];
				_posYsector = 0;

				//--- Show score or tickets (never combine it; tickets have priority)
				_ticketSides = [];
				_showTickets = false;
				_scoreTotal = 0;
				{
					if ([_x] call bis_fnc_respawnTickets >= 0) exitwith {_showTickets = true;};
					if (playableslotsnumber _x > 0) then {
						_scoreTotal = _scoreTotal + scoreside _x;
					};
				} foreach [west,east,resistance];

				//--- Show values. Tickets always, score based on difficulty and only if at least one side has more than 0 points
				if (_showTickets || (!_showTickets && difficultyenabled "netStats" && _scoreTotal > 0)) then {
					{
						_side = _x;
						if (playableslotsnumber _side > 0 || _showTickets) then {

							_sideID = _side call bis_fnc_sideID;
							_icon = _icons select _sideID;
							_name = _names select _sideID;
							_respawn = _respawns select _sideID;

							//--- Get faction icon
							if (_icon == "" && (playersnumber _side > 0 || !ismultiplayer)) then {
								_faction = _side call bis_fnc_playerSideFaction;
								_icon = gettext (configfile >> "cfgfactionclasses" >> _faction >> "icon");
								_name = gettext (configfile >> "cfgfactionclasses" >> _faction >> "displayName");
								_icons set [_sideID,_icon];
								_names set [_sideID,_name];
							};

							//--- Get side icon
							if (_icon == "") then {
								_icon = (_side call bis_fnc_sidecolor) call bis_fnc_colorRGBAtoTexture;
								_name = _side call bis_fnc_sidename;
							};

							//--- Get score value
							_score = if (_showTickets) then {[_side] call bis_fnc_respawnTickets} else {scoreside _x};

							if ((_showTickets && _score >= 0) || !_showTickets) then {

								if (_showTickets) then {_ticketSides pushback _side;};

								//--- Find side respawn position
								_respawnPositions = (_side call bis_fnc_getrespawnmarkers) + (_side call bis_fnc_getrespawnpositions);
								if (count _respawnPositions > 0) then {
									_respawn = (_respawnPositions select 0) call bis_fnc_position;
									_respawns set [_sideID,_respawn];
								} else {
									_respawns set [_sideID,[]];
								};

								_slotData pushback [
									format ["<t size='0.26' color='#00000000'>.<br /></t><t align='center' shadow='2' size='0.8'>%1</t>",_score],
									_icon,
									[0.7,0.7,0.7,0.75],
									0,
									_respawn,
									0
								];
							};
						};
					} foreach [west,east,resistance];
				};

				//--- Remaining time
				_time = [] call bis_fnc_countdown;
				if (_time <= 0) then {_time = estimatedendservertime - servertime;};
				if (_time > 0) then {
					_color = [0,0,0,0.35];
					if (_time <= 60) then {_color = _colorWarning;};
					if (_time <= 10) then {_color = _colorError;};
					_measure = if (_time > 60) then {_time = _time / 60; localize "STR_A3_RSCMPPROGRESS_min"} else {localize "STR_A3_RSCMPPROGRESS_sec"};
					_slotData pushback[
						format ["<t align='center' shadow='1'><t size='0.8'>%1</t><t size='0.6'><br />%2</t></t>",ceil _time,_measure],
						"\a3\Ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa",
						_color,//[0,0,0,0.35],
						0,
						[],
						0
					];
				};

				//--- Show respawn tickets (only when they're not already displayed for side)
				if ((ismultiplayer || cheatsenabled) && !((player call bis_fnc_objectSide) in _ticketSides) && !isnull group player) then {
					//--- Remaining respawns
					_tickets = [player,0,true] call bis_fnc_respawnTickets;
					if (_tickets >= 0) then {
						_color = [0,0,0,0.35];
						if (_tickets <= 5) then {_color = _colorWarning;};
						if (_tickets == 0) then {_color = _colorError;};
						_slotData pushback [
							format ["<t size='0.26' color='#00000000'>.<br /> </t><t align='center' shadow='1' size='0.8'>%1</t>",_tickets],
							"\a3\Ui_f\data\IGUI\RscTitles\MPProgress\respawn_ca.paa",
							_color,
							0,
							[],
							0
						];
					};
				};

				//--- Show custom slots
				{
					if !(isnil "_x") then {_slotData pushback _x;};
				} foreach (missionnamespace getvariable ["RscMissionStatus_icons",[]]);

				//--- Process sectors
				_sectors = missionnamespace getvariable ["BIS_fnc_moduleSector_sectors",[]];
				_sectors3D = [];
				_showAllSectors = count _sectors <= 7;
				_showOnlyRelatedSectors = false;
				_disMax = missionnamespace getvariable ["RscMissionStatus_sectorDistance",DISMAX];
				_currentSector = objnull;
				_currentSectorID = -1;
				_firstSector = count _slotData;
				_playerside = side group player;
				_playersideID = _playerside call bis_fnc_sideID;
				_player = if (isclass (configfile >> "CfgFunctions" >> "Curator_F")) then {call compile "curatorcamera"} else {objnull}; //--- Testing camera. ToDo: Remove
				if (isnull _player) then {
					_player = cameraon;
					_showOnlyRelatedSectors = true;
				};

				{
					if (count _slotData < 10) then {
						_logic = _x;
						_pos = _logic getvariable ["pos",[0,0,0]];
						_sides = _logic getvariable ["sides",[]];

						//--- Show only related sectors
						if (_playerside in _sides || (!_showOnlyRelatedSectors && count _sides > 0)) then {

							//--- Show only nearby sectors
							if ((_pos distance _player) < _disMax || _showAllSectors) then {
								_owner = _logic getvariable ["owner",sideUnknown];
								_ownerTexture = _textures select ((_owner call bis_fnc_sideID) min 4);
								_ownerColor = if (_owner == sideunknown) then {_colorDefault} else {_owner call bis_fnc_sidecolor};
								_designation = _logic getvariable ["designation",""];

								//--- Blink when player is capturing
								_contested = _logic getvariable ["contested",false];
								_fade = if (_contested) then {0.85 * (floor time % 2)} else {0};

								//--- Show capture progress of the sector player is in
								if (simulationenabled _logic) then {
									_areas = _logic getvariable ["areas",[]];
									if ({vehicle player in list _x} count _areas > 0) then {
										_currentSector = _logic;
										_currentSectorID = count _slotData;
									};
								};

								_sideScore = _logic getvariable ["sideScore",[]];
								_barHeight = _sideScore select _playersideID;

								_slotData pushback [
									format ["<t size='0.28' color='#00000000'>.<br /></t><t align='center' size='0.7' color='#000000'>%1</t>",_designation],
									_ownerTexture,
									+_ownerColor,
									_fade,
									_pos,
									if (_contested && _logic != _currentSector) then {_barHeight} else {0}
								];

								if (_logic != _currentSector && simulationenabled _logic) then {
									_sectors3D set [count _sectors3D,[_player,_pos,_designation,_ownerTexture,+_ownerColor]];
								};
							};
						};
					};
				} foreach _sectors;
				missionnamespace setvariable ["RscMissionStatus_sectors3D",_sectors3D];

				//--- Show
				_height = 0;
				_positions = [];
				{
					_text = _x select 0;
					_texture = _x select 1;
					_color = _x select 2;
					_fade = _x select 3;
					_position = _x select 4;
					_barHeight = _x select 5;

					_slot = _slots select _foreachindex;
					_slotText = _slotTexts select _foreachindex;
					_slotBackground = _slotBackgrounds select _foreachindex;
					_slotProgress = _slotProgresses select _foreachindex;

					_slot ctrlsettext _texture;
					_slot ctrlsettextcolor _color;
					_slot ctrlsetactivecolor [1,1,1,1];
					//_slot ctrlsetfade _fade;
					_slot ctrlcommit 1;

					_slotText ctrlsetstructuredtext parsetext _text;
					//_slotText ctrlsetfade _fade;
					//_slotText ctrlcommit 1;

					_slotProgress progresssetposition _barHeight;

					_slot ctrlenable (count _position > 0);
					_positions set [count _positions,_position];

					if (_foreachindex == _currentSectorID) then {
						_color set [3,0.75];
						_ctrlBarBridgePos = ctrlposition _ctrlBarBridge;
						_ctrlBarBridgePos set [1,ctrlposition _slotBackground select 1];
						_ctrlBarBridge ctrlsetposition _ctrlBarBridgePos;
						_ctrlBarBridge ctrlsetbackgroundcolor _color;
						_ctrlBarBridge ctrlcommit 0;
						_slotBackground ctrlshow false;
					} else {
						_slotBackground ctrlshow true;
					};

					if (_foreachindex == _firstSector) then {
						_posYsector = ctrlposition _slotBackground select 1;
					};

					_slotPos = ctrlposition _slotBackground;
					_height = (_slotPos select 1) + (_slotPos select 3);
				} foreach _slotData;
				missionnamespace setvariable ["RscMissionStatus_positions",_positions];

				_group = _display displayctrl IDC_RSCMISSIONSTATUS_RSCMISSIONSTATUS;
				_groupPos = ctrlposition _group;
				_groupPos set [3,_height];
				_group ctrlsetposition _groupPos;
				_group ctrlcommit 0.2;

				sleep 0.1;

				if !(isnull _currentSector) then {
					_sides = _currentSector getvariable ["sides",[]];
					_sideScore = _currentSector getvariable ["sideScore",[]];
					_owner = _currentSector getvariable ["owner",sideUnknown];

					_ctrlBarBridge ctrlsetfade 0;
					_ctrlBarBridge ctrlcommit _fadeTime;

					_height = _height - _posYsector;
					_posY = _posYsector;
					{
						_side = _x select 0;
						_ctrl = _x select 1;
						_sideID = _side call bis_fnc_sideid;//_sides find _side;
						_score = if (_sideID >= 0) then {_sideScore select _sideID;} else {0};

						_ctrlPos = ctrlposition _ctrl;
						_posH = _height * _score;
						_ctrlPos set [1,_posY];
						_ctrlPos set [3,_posH];
						_posY = _posY + _posH;

						_ctrl ctrlsetposition _ctrlPos;
						_ctrl ctrlcommit 1;
						if (isnull _currentSectorOld) then {
							_ctrl ctrlsetposition _ctrlPos;
							_ctrl ctrlcommit 0;
							_ctrl ctrlsetfade 0;
							_ctrl ctrlcommit _fadeTime;
						};
					} foreach [
						[civilian,_ctrlBarCiv],
						[resistance,_ctrlBarGuer],
						[east,_ctrlBarEast],
						[west,_ctrlBarWest],
						[sideunknown,_ctrlBarUnknown]
					];
				} else {
					_ctrlBarBridge ctrlsetfade 1;
					_ctrlBarBridge ctrlcommit _fadeTime;

					{
						_xPos = ctrlposition _x;
						if !(isnull _currentSectorOld) then {
							_x ctrlsetfade 1;
							_x ctrlcommit _fadeTime;
						};
					} foreach [_ctrlBarWest,_ctrlBarEast,_ctrlBarGuer,_ctrlBarCiv,_ctrlBarUnknown]
				};
				_currentSectorOld = _currentSector;

				sleep 0.9;
			};
			_group = _display displayctrl IDC_RSCMISSIONSTATUS_RSCMISSIONSTATUS;
			_group ctrlshow false;
		};
	};
	case "buttonClick": {
		_button = _params select 0;
		_type = _params select 7;
		_display = ctrlparent _button;
		_group = _display displayctrl IDC_RSCMISSIONSTATUS_RSCMISSIONSTATUS;
		ctrlsetfocus (_display displayctrl IDC_RSCMISSIONSTATUS_BARUNKNOWN);

		_buttonID = [
			IDC_RSCMISSIONSTATUS_SLOT1,
			IDC_RSCMISSIONSTATUS_SLOT2,
			IDC_RSCMISSIONSTATUS_SLOT3,
			IDC_RSCMISSIONSTATUS_SLOT4,
			IDC_RSCMISSIONSTATUS_SLOT5,
			IDC_RSCMISSIONSTATUS_SLOT6,
			IDC_RSCMISSIONSTATUS_SLOT7,
			IDC_RSCMISSIONSTATUS_SLOT8,
			IDC_RSCMISSIONSTATUS_SLOT9,
			IDC_RSCMISSIONSTATUS_SLOT0
		] find (ctrlidc _button);
		_position = +((missionnamespace getvariable ["RscMissionStatus_positions",[[],[],[],[],[],[],[],[],[],[]]]) select _buttonID);
		if (count _position > 0) then {
			[_position,_type == "mousebuttonclick"] call (missionnamespace getvariable ["RscMissionStatus_buttonClick",{}]);
		};
	};
};