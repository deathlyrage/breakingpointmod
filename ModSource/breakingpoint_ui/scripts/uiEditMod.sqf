disableSerialization;
private ["_display","_control","_clicked","_mousePos","_closeCtrlID","_closeCtrlDistance","_keyUp","_inputArray","_input","_time"];


switch (typeName(_this select 0)) do {

	case "DISPLAY": 
	{
		_display = _this select 0;
		_clicked = false;
		_input = _this;
		_keyUp = false;
	}; 
	case "CONTROL": 
	{	
		_control = _this select 0;
		_display = ctrlParent _control;	
		_clicked = true; 
		_mousePos = [_this select 2,_this select 3];
		_input = _this;
		_keyUp = false;		
	}; 
	case "STRING": 
	{
		_clicked = false;		
		_keyUp = true;
		_input = _this select 1;
		_display = _input select 0;
	};
};


if isNil("UI_timerStopped") then { UI_timerStopped = true; };
if isNil("UI_editMode") then {	UI_editMode = false;	};
if isNil("UI_lastPushedKey") then {	UI_lastPushedKedy = 9999; };
if isNil("UI_startTime") then {	UI_startTime = dayTime; };

_enableEditMode = {
	_activezone = _display displayctrl 10006;
	_activezone ctrlSetPosition [-1,-1];
	_activezone ctrlCommit 0;
	UI_editMode = true;	
	_ctrlIndicator = _display  displayctrl 11100;	
	_ctrlIndicator ctrlSetPosition [0, 0];
	_ctrlIndicator ctrlCommit 0;
};

_timer = {
	_action = _this select 0;
	if (_action == "STOP") then { UI_timerStopped = true; }; 
	if ((_action == "START")&&(UI_timerStopped)) then 
	{
	 	UI_timerStopped = false; 
	 	UI_startTime = dayTime; 
	};	
	_time = dayTime -  UI_startTime;  
	_time = round(_time * 20000);
	_time;
};

_disableEditMode = {
	_activezone = _display displayctrl 10006;
	_activezone ctrlSetPosition [-2.9,-2.9];
	_activezone ctrlCommit 0;
	UI_editMode = false;	
	_ctrlIndicator = _display  displayctrl 11100;	
	_ctrlIndicator ctrlSetPosition [-1, -1];
	_ctrlIndicator ctrlCommit 0;	
};

_indicateFocus = {
	_ctrl = _display  displayctrl (_this select 0);
	_ctrlPos = ctrlPosition _ctrl;
	_ctrlPosX = (_ctrlPos select 0) - 0.021;
	_ctrlPosY = (_ctrlPos select 1) - 0.028;	
	_ctrlIndicator = _display  displayctrl 11100;	
	_ctrlIndicator ctrlSetPosition [_ctrlPosX, _ctrlPosY];
	_ctrlIndicator ctrlCommit 0;
};

_findControl = {
	_closeCtrlDistance = 10;
	for [{_x=0},{_x<=2000},{_x=_x+1}] do 
	{	
		_ctrl = _display displayctrl _x;
		if !(IsNull _ctrl) then {
			_ctrlPos = [(ctrlposition _ctrl) select 0,(ctrlposition _ctrl) select 1];
			_distToCtrl = (_ctrlPos distance _mousePos);
			if (_distToCtrl < _closeCtrlDistance) then {
				_closeCtrlID = _x;
				_closeCtrlDistance = _distToCtrl;
			}			
		};	
	}; 
	_closeCtrlID;
}; 

_ctrlMove = {
	_ctrlID = _this select 0;
	_pos = _this select 1;
	_PosXDelta = _pos select 0;
	_PosYDelta = _pos select 1;
	
	_ctrl = _display  displayctrl _ctrlID;
	_ctrlPos = ctrlPosition _ctrl;
	_ctrlPosX = (_ctrlPos select 0);
	_ctrlPosY = (_ctrlPos select 1);

	_ctrlPosX = _ctrlPosX + _PosXDelta;
	_ctrlPosY = _ctrlPosY + _PosYDelta;
	_ctrl ctrlSetPosition [_ctrlPosX, _ctrlPosY]; 
	_ctrl ctrlCommit 0.0;
};

_coordinatesOutput = {
	_ctrlID = _this select 0;
	_ctrl = _display  displayctrl _ctrlID;
	_ctrlPos = ctrlPosition _ctrl;
	_ctrlPosX = (_ctrlPos select 0);
	_ctrlPosY = (_ctrlPos select 1);
	_outputString = ("x = " + str(_ctrlPosX) + "; y = " + str(_ctrlPosY) + "; // idc = " + str(_ctrlID));
	copyToClipboard _outputString;  	
};

if (UI_editMode && _clicked) then {
	UI_ctrlToEditID = call _findControl;
	[UI_ctrlToEditID] call _indicateFocus;	
};

if (!(_clicked) && !(_keyUp)) then { 

	_time = (["START"] call _timer);	
	_pushedKey = _input select 1;
	if (_time>4) then { _time = 5;}; 
	_px = 1 + _time*5;
	
	_yDelta = (_px/816);
	_xDelta = (_px/612);
	
/*	if (_pushedKey != UI_lastPushedKey) then {
		_time = (["STOP"] call _timer); 
	} else {
		_time = (["START"] call _timer);	
	}; 
	
	UI_lastPushedKey = _pushedKey; */


	switch _pushedKey do {
		case 14:
		{
			if (UI_editMode) then {
				call _disableEditMode;

			} else {
				call _enableEditMode;
				_activeZone = _display displayctrl 10006;
				ctrlSetFocus _activeZone;				
			};
		};
		case 80:
		{
				[UI_ctrlToEditID,[0, _yDelta]] call _ctrlMove;
		};
		case 72:
		{
				[UI_ctrlToEditID,[0, (-1*_yDelta)]] call _ctrlMove;
		};
		case 75:
		{
				[UI_ctrlToEditID,[(-1*_xDelta),0]] call _ctrlMove;
		};
		case 77:
		{
				[UI_ctrlToEditID,[(_xDelta),0]] call _ctrlMove;		
		};
	};
	
};

if (_keyUp) then {
		_time = (["STOP"] call _timer); 
		[UI_ctrlToEditID] call _coordinatesOutput;		
};
	[UI_ctrlToEditID] call _indicateFocus;
true
