#include "\A3\ui_f\hpp\defineResinclDesign.inc"
/*
#define IDC_RSCNOTIFICATION_TITLE		1000
#define IDC_RSCNOTIFICATION_PICTUREBACKGROUND	1001
#define IDC_RSCNOTIFICATION_SCORE		1002
#define IDC_RSCNOTIFICATION_DESCRIPTION		1100
#define IDC_RSCNOTIFICATION_PICTURE		1200
*/

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "onLoadx": {
		_display = if (isnil {RscNotification_display}) then {displaynull} else {RscNotification_display};
		if (isnull _display) then {
			["init",_params,_class] spawn RscNotification_script;
		};
	};

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "onLoad": {
		_data = missionnamespace getvariable ["RscNotification_data",[]];
		if (count _data == 13) then { //--- Increase this number every time a new parameter is added!

			_display = _params select 0;
			_ctrlArea = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATIONAREA;
			_ctrlAreaPos = ctrlposition _ctrlArea;
			_ctrlNotification = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATION;
			_ctrlNotificationPosDefault = ctrlposition _ctrlNotification;
			_ctrlDescription = _display displayctrl IDC_RSCNOTIFICATION_DESCRIPTION;
			_ctrlDescriptionPos = ctrlposition _ctrlDescription;
			_isCurator = !isnull (finddisplay 312);
			if (_isCurator) then {
				_ctrlArea ctrlshow false;
				_display = finddisplay 312;
			};

			_title = _data select 0;
			_iconPicture = _data select 1;
			_iconText = _data select 2;
			_description = _data select 3;
			_color = _data select 4;
			_colorIconPicture = _data select 5;
			_colorIconText = _data select 6;
			_duration = _data select 7;
			_priority = _data select 8;
			_args = _data select 9;
			_sound = _data select 10;
			_soundClose = _data select 11;
			_soundRadio = _data select 12;

			_title = toupper format ([_title] + _args);
			_description = format ([_description] + _args);
			_iconPicture = format ([_iconPicture] + _args);
			_iconText = format ([_iconText] + _args);
			_soundRadio = format ([_soundRadio] + _args);

			//--- Log
			[
				player,
				localize "str_a3_cfguigrids_igui_variables_grid_notification_0",
				format ["<img image='%3' height='15'/> <font color='%4'>%1: %2</font>",_title,_description,_iconPicture,_color call bis_fnc_colorRGBAtoHTML]
			] call bis_fnc_createlogrecord;

			_ctrlArea = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATIONAREA;
			_ctrlArea ctrlsetposition _ctrlAreaPos;
			_ctrlArea ctrlcommit 0;
			_ctrlArea ctrlshow true;
			_moveUp = (ctrlposition _ctrlArea select 1) > 0.5;

			_ctrlTitle = _display displayctrl IDC_RSCNOTIFICATION_TITLE;
			_ctrlTitle ctrlsettext _title;

			_ctrlDescription = _display displayctrl IDC_RSCNOTIFICATION_DESCRIPTION;
			_ctrlDescription ctrlsetstructuredtext parsetext _description;
			_ctrlDescription ctrlsettextcolor _color;

			//--- Align description vertically
			_ctrlDescriptionPosH = (ctrltextheight _ctrlDescription) min (_ctrlDescriptionPos select 3);
			_ctrlDescriptionPos set [1,(_ctrlDescriptionPos select 1) + ((_ctrlDescriptionPos select 3) - _ctrlDescriptionPosH) / 2];
			_ctrlDescriptionPos set [3,_ctrlDescriptionPosH];
			_ctrlDescription ctrlsetposition _ctrlDescriptionPos;
			_ctrlDescription ctrlcommit 0;

			_ctrlIconPicture = _display displayctrl IDC_RSCNOTIFICATION_PICTURE;
			_ctrlIconPicture ctrlsettext _iconPicture;
			_ctrlIconPicture ctrlsettextcolor _colorIconPicture;

			_ctrlIconText = _display displayctrl IDC_RSCNOTIFICATION_SCORE;
			_ctrlIconText ctrlsettext _iconText;
			_ctrlIconText ctrlsettextcolor _colorIconText;

			_ctrlNotification = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATION;
			_ctrlNotificationPos = +_ctrlNotificationPosDefault;
			_ctrlNotificationPos set [0,(_ctrlNotificationPos select 0) + (_ctrlNotificationPos select 2) / 2];
			if (_moveUp && !_isCurator) then {
				_ctrlNotificationPos set [1,(_ctrlNotificationPos select 1) + (_ctrlNotificationPos select 3)];
			};
			_ctrlNotificationPos set [2,0];
			_ctrlNotificationPos set [3,ctrlposition _ctrlTitle select 3];
			_ctrlNotification ctrlsetposition _ctrlNotificationPos;
			_ctrlNotification ctrlsetfade 0;
			_ctrlNotification ctrlcommit 0;

			//--- Expand from the middle
			_ctrlNotificationPos set [0,_ctrlNotificationPosDefault select 0];
			_ctrlNotificationPos set [2,_ctrlNotificationPosDefault select 2];
			_ctrlNotification ctrlsetposition _ctrlNotificationPos;
			_ctrlNotification ctrlcommit 0.2;

			_animate = [_display,_ctrlNotificationPosDefault,_ctrlNotificationPos,_duration,_moveUp,_sound,_soundClose,_soundRadio,_isCurator] spawn {
				scriptname "RscNotification: Animation";
				disableserialization;
				_display = _this select 0;
				_ctrlNotificationPosDefault = _this select 1;
				_ctrlNotificationPos = _this select 2;
				_duration = ((_this select 3) - 0.2) max 0;
				_moveUp = _this select 4;
				_sound = _this select 5;
				_soundClose = _this select 6;
				_soundRadio = _this select 7;
				_isCurator = _this select 8;
				if (_isCurator) then {_duration = _duration - 0.5;};

				_ctrlArea = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATIONAREA;
				_ctrlNotification = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATION;
				_ctrlTitle = _display displayctrl IDC_RSCNOTIFICATION_TITLE;

				if (_sound != "") then {playSound [_sound,true];};
				if (_soundRadio != "") then {((player call bis_fnc_objectSide) call bis_fnc_moduleHQ) sideradio _soundRadio;};

				sleep 0.2;

				//--- Expand down
				_ctrlNotificationPos set [3,_ctrlNotificationPosDefault select 3];
				_ctrlNotification ctrlsetposition _ctrlNotificationPos;
				_ctrlNotification ctrlcommit 0.2;

				sleep _duration;

				//--- Push up when another notification is displayed
				_queueCount = "BIS_fnc_showNotification_counter" call bis_fnc_counter;
				if (_queueCount > 0 && !_isCurator) then {
					if (_moveUp) then {
						_ctrlNotificationPos set [1,(_ctrlNotificationPosDefault select 1)];
					} else {
						_ctrlNotificationPos set [1,(_ctrlNotificationPos select 1) + (_ctrlNotificationPos select 3)];
					};
					_ctrlNotification ctrlsetfade 0.75;
					_ctrlNotification ctrlsetposition _ctrlNotificationPos;
					_ctrlNotification ctrlcommit 0.3;

					sleep 2;
				};

				//--- Collapse up
				_ctrlNotificationPos set [3,ctrlposition _ctrlTitle select 3];
				_ctrlNotification ctrlsetposition _ctrlNotificationPos;
				_ctrlNotification ctrlcommit 0.2;

				if (_soundClose != "") then {playSound [_soundClose,true];};

				sleep 0.2;

				//--- Collapse to the middle
				_ctrlNotification ctrlcommit 0;
				_ctrlNotificationPos set [0,(_ctrlNotificationPos select 0) + (_ctrlNotificationPos select 2) / 2];
				_ctrlNotificationPos set [2,0];
				_ctrlNotification ctrlsetposition _ctrlNotificationPos;
				_ctrlNotification ctrlcommit 0.2;
			};

			[_display,_duration,_animate] spawn {
				scriptname "RscNotification: Position update";
				disableserialization;
				_display = _this select 0;
				_duration = _this select 1;
				_animate = _this select 2;
				_time = time + _duration + 3;

				_ctrlArea = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATIONAREA;
				_ctrlAreaPosDefault = ctrlposition _ctrlArea;

				//--- Load display spaces
				_paths = [];
				_cfgScriptPaths = configfile >> "cfgScriptPaths";
				for "_i" from 0 to (count _cfgScriptPaths - 1) do {
					_param = _cfgScriptPaths select _i;
					if (istext _param) then {
						_paths set [count _paths,configname _param + "_DISPLAYS"]; //--- ToDo: Make it a function
					};
				};

				//--- Check the position in a loop
				//while {time < _time} do {
				while {!scriptdone _animate} do {
					_ctrlAreaPos = +_ctrlAreaPosDefault;
					{
						_displays = uinamespace getvariable [_x,[]];
						_displays = _displays - [displaynull];
						if (count _displays > 0) then {
							_display = _displays select (count _displays - 1);
							_ctrlAreaCustom = _display displayctrl IDC_RSCNOTIFICATION_NOTIFICATIONAREA;
							if !(isnull _ctrlAreaCustom) then {
								_ctrlAreaPos set [0,ctrlposition _ctrlAreaCustom select 0];
								_ctrlAreaPos set [1,ctrlposition _ctrlAreaCustom select 1];
							};
						};
					} foreach _paths;
					_ctrlArea ctrlsetposition _ctrlAreaPos;
					_ctrlArea ctrlcommit 0;
					uisleep 0.1;
				};
			};
		};
	};
};