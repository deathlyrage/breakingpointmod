_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

#define BORDER	0.005

switch _mode do {

	case "onLoad": {
		with uinamespace do {
			_params spawn {
				disableserialization;
				_display = _this select 0;

				_text = _display displayctrl 101;
				_picture = _display displayctrl 102;
				_buttonOK = _display displayctrl 1;
				_buttonCancel = _display displayctrl 2;
				_buttonInfo = _display displayctrl 2400;
				_description = _display displayctrl 1100;
				_title = _display displayctrl 1001;
				_info = _display displayctrl 1101;

				//--- Background
				_pos = ctrlposition _text;
				_posX = (_pos select 0) + 0.01;
				_posY = _pos select 1;
				_posW = _pos select 2;
				_posH = _pos select 3;
				_pos set [0,_posX];
				_text ctrlsetposition _pos;
				_text ctrlcommit 0;

				//--- Title
				_pos set [1,_posY - 2*_posH - BORDER];
				_pos set [3,_posH];
				_title ctrlsetposition _pos;
				_title ctrlcommit 0;

				_pos set [1,_posY - 1*_posH];
				_pos set [3,2*_posH];
				_description ctrlsetposition _pos;
				_description ctrlsetstructuredtext parsetext format ["<t size='0.8'>%1</t>","Description:"]; //--- ToDo: Localze
				_description ctrlcommit 0;

				_activeColor = (["IGUI","WARNING_RGB"] call bis_fnc_displaycolorget) call bis_fnc_colorRGBtoHTML;
				_info ctrlsetstructuredtext parsetext format [
					"<t size='0.8'><t color='%1'>%2</t>:<br />%3<br /><t color='%1'>%4</t>:<br />%5<br /><br />%6<br /><br />%7</t>",
					_activeColor,
					"Arrow up/down",
					"select marker icon",
					"Shift + arrow up/down",
					"select marker color",
					format ["You can later delete custom marker by pressing %1 while hovering over it with mouse.",format ["<t color='%1'>",_activeColor] + (keyname 0xD3) + "</t>"],
					if (ismultiplayer) then {"Marker will be visible only to players on the current channel."} else {""}
				]; //--- ToDo: Localze
				_pos set [1,_posY + 2 * _posH + 2 * BORDER];
				_pos set [3,0];
				_info ctrlsetposition _pos;
				_info ctrlcommit 0;

			
				//--- ButtonInfo
				_pos set [1,_posY + 1 * _posH + BORDER];
				_pos set [3,_posH];
				_buttonInfo ctrlsetposition _pos;
				_buttonInfo ctrlcommit 0;
				_buttonInfo ctrladdeventhandler ["buttonclick","with (uinamespace) do {['buttonclick',_this,''] call RscDisplayInsertMarker_script;};"];

				//--- ButtonOK
				_pos set [1,_posY + 2 * _posH + 2 * BORDER];
				_pos set [2,_posW / 2 - BORDER];
				_pos set [3,_posH];
				_buttonOk ctrlsetposition _pos;
				_buttonOk ctrlcommit 0;

				//--- ButtonCancel
				_pos set [0,_posX + _posW / 2];
				_pos set [1,_posY + 2 * _posH + 2 * BORDER];
				_pos set [2,_posW / 2];
				_pos set [3,_posH];
				_buttonCancel ctrlsetposition _pos;
				_buttonCancel ctrlcommit 0;
			};
		};
	};

	case "buttonclick": {
		_display = ctrlparent (_params select 0);

		_text = _display displayctrl 101;
		_picture = _display displayctrl 102;
		_buttonOK = _display displayctrl 1;
		_buttonCancel = _display displayctrl 2;
		_buttonInfo = _display displayctrl 2400;
		_description = _display displayctrl 1100;
		_title = _display displayctrl 1001;
		_info = _display displayctrl 1101;

		_posText = ctrlposition _text;
		_posTextX = (_posText select 0) + 0.01;
		_posTextY = _posText select 1;
		_posTextW = _posText select 2;
		_posTextH = _posText select 3;

		_animate = {
			private ["_control","_dY","_dH","_borderCoef","_pos"];
			_control = _this select 0;
			_dY = _this select 1;
			_dH = _this select 2;
			_borderCoef = _this select 3;
			_pos = ctrlposition _control;
			_pos set [1,_posTextY + _dY * _posTextH + _borderCoef * BORDER];
			_pos set [3,_dH * _posTextH];
			_control ctrlsetposition _pos;
			_control ctrlcommit _delay;
		};

		_delay = 0.2;

		if (isnil "RscDisplayInsertMarker_info") then {
			_buttonInfo ctrlsettext toupper "hide info"; //--- ToDo: Localze
			RscDisplayInsertMarker_info = true;
			_mp = if (ismultiplayer) then {2} else {0};

			//		Y H B
			[_info,		2,8+_mp,2] call _animate;
			[_buttonOK,	10+_mp,1,3] call _animate;
			[_buttonCancel,	10+_mp,1,3] call _animate;
		} else {
			_buttonInfo ctrlsettext toupper "show info"; //--- ToDo: Localze
			RscDisplayInsertMarker_info = nil;

			[_info,		2,0,2] call _animate;
			[_buttonOK,	2,1,2] call _animate;
			[_buttonCancel,	2,1,2] call _animate;
		};

	};

	case "onUnload": {
		RscDisplayInsertMarker_info = nil;
	};
};