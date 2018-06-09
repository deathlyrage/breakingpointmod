disableSerialization;

private ["_control","_display","_temp","_event","_data","_x","_stopTheKey","_keyLeft"];
private ["_key","_keyRight","_keyTop","_keyBottom","_secondColumn","_activateControl"];

if isNil("CA_DR_lastLeftFocus") then { CA_DR_lastLeftFocus = 81;};
if isNil("CA_DR_ctrlFocus") then { CA_DR_ctrlFocus = 81; };
if isNil("CA_DR_focusEnabled") then { CA_DR_focusEnabled = false; };

//debuglog  CA_DR_focusEnabled;

_firstColumn = [80,81,82,83,84,85,86,87,88];
_secondColumn = [102];
_keyLeft = [203,327700,327686];
_keyRight = [205,327696,327687];
_keyTop = [1];
_keyBottom = [1];

_event = _this select 1;
_data = _this select 0;
_stopTheKey = false;

_ctrlNumber = {
	private ["_x","_n","_findControl","_inputControl"];
	_inputControl = _this select 0;
	scopeName "findControl";
	_n = 0;
	for[{_x=1},{_x<120},{_x=_x+1}]do { 
		_findControl = _display displayctrl _x;
		if (_findControl==_inputControl)then{
			_n = _x; 
			breakTo "findControl";
		};
	};
	_n;
};

_setEnabledControlFocus = {
	_setFocusControl = _this select 0;
	if(ctrlEnabled _setFocusControl)then{
		ctrlSetFocus _setFocusControl;
		_stopTheKey = true;					
	} else {
		_stopTheKey = false;
	};
	_stopTheKey;
};

if(typeName(_data select 0) == "DISPLAY")then 
{
	_display = (_data select 0);
	_key = (_data select 1);	
};

if(typeName(_data select 0) == "CONTROL")then 
{
	_control = (_data select 0);
	_display = ctrlParent _control;
	CA_DR_ctrlFocus = [_control] call _ctrlNumber;
};

switch _event do 
{
	case "setfocusDISABLED":
	{			
	  	CA_DR_countdown = CA_DR_countdown - 1;
	  	//debuglog CA_DR_countdown;
		if (CA_DR_focusEnabled) then {
			if((_firstColumn find CA_DR_ctrlFocus)!=-1)then{
				_activateControl = _display displayctrl CA_DR_ctrlFocus;
				
				//_activateControl = _display displayctrl 84;
				ctrlActivate  _activateControl;
				CA_DR_ctrlLastActivated = CA_DR_ctrlFocus;
			};
		};
	};
	case "keydown":
	{
		if((_firstColumn find CA_DR_ctrlFocus)!=-1)then{
			if((_keyRight find _key)!=-1)then{
				_stopTheKey = true;
				CA_DR_lastLeftFocus = (CA_DR_ctrlFocus);
				_focusControl = _display displayctrl (_secondColumn select 0);				
				_stopTheKey = [_focusControl] call _setEnabledControlFocus;
			};
		};	
		if((_secondColumn find CA_DR_ctrlFocus)!=-1)then {
		 	if((_keyLeft find _key)!=-1)then{
				
				_stopTheKey = true;
				_focusControl = _display displayctrl (CA_DR_lastLeftFocus);	
				_stopTheKey = [_focusControl] call _setEnabledControlFocus;		
			};
		};			
	};	
	case "onloadDISABLED":
	{

	 	if isNil("CA_DR_lastLeftFocus")then{ 
	 		CA_DR_lastLeftFocus = 81;	 		
		} else {
			_focusControl = _display displayctrl CA_DR_lastLeftFocus;				
			ctrlSetFocus _focusControl;
		};
		CA_DR_focusEnabled = false;
		sleep 0.2;
		CA_DR_focusEnabled = true;		
	};
	default
	{
	};
};

_stopTheKey;
