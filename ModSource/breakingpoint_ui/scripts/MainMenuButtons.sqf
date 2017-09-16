disableSerialization;
private ["_dialog","_control"];

_action = _this  select 1;

_actionKeyCode = (_this  select 0) select 1;
_button_elements_array = _this select 2;

_ctrlMainNumber = (_this select 2) select 1;
_ctrlOverNumber = (_this select 2) select 2;
_ctrlFocusNumber = (_this select 2) select 3;

if ( typeName(_this select 0) == "DISPLAY" ) then {
	_control = 0;
	_dialog = _this select 0;
} else {
	_control = (_this select 0) select 0;
	_dialog = ctrlParent _control;
};

processIDCs = {
	private ["_processIDCs", "_ctrldelay"];
	_processIDCs = _this select 0;
	_ctrl_delay =  _this select 2;
	_move_ctrl =  _this select 3;
	
	private ["_x"];
	for [{_x=0},{_x<=(count _processIDCs)},{_x=_x+1}] do 
	{
		_control = _processIDCs select _x;
		_disp_ctrl = (_dialog displayCtrl _control); 
		_posX = ((ctrlPosition _disp_ctrl) select 0)+ (_move_ctrl select 0); 
		_posY = ((ctrlPosition _disp_ctrl) select 1) +  (_move_ctrl select 1);
		_disp_ctrl ctrlSetPosition [_posX, _posY];  
		_disp_ctrl ctrlCommit _ctrl_delay;
	};
};
if (isNil("MM_buttonDown")) then { MM_buttonDown = false;};

switch _action do 
{
	case "ButtonInit": 
	{

	};
	case "MouseButtonUp": 
	{
		if (( _actionKeyCode == 0 || _actionKeyCode == 57 || _actionKeyCode == 28 || _actionKeyCode == 156 || _actionKeyCode == 327680) && (MM_buttonDown) ) then {
			[_button_elements_array, false, 0, [-0.002,-0.002]] call processIDCs;
			MM_buttonDown = false;		
		};
	};
	case "MouseButtonDown": 
	{
		if (( _actionKeyCode == 0 || _actionKeyCode == 57 || _actionKeyCode == 28 || _actionKeyCode == 156 || _actionKeyCode == 327680) && (!MM_buttonDown) && (ctrlCommitted _control)) then {
			[_button_elements_array, false, 0, [0.002,0.002]] call processIDCs;
			MM_buttonDown = true;
		};
	};
	case "MouseEnter": 
	{

		_ctrlOver = _dialog displayCtrl _ctrlOverNumber;
		_ctrlMain =_dialog displayCtrl _ctrlMainNumber;
		
		_ctrlMain ctrlSetFade 0;
		_ctrlMain ctrlCommit 0;

		_ctrlOver ctrlSetFade 1;
		_ctrlover ctrlCommit 0;
		
		_ctrlOver ctrlSetTextColor [1,1,1,1];		 
		_ctrlOver ctrlSetFade 0;  
		_ctrlOver ctrlCommit 0.3;
		_ctrlMain ctrlSetFade 1;
  
		_ctrlMain ctrlCommit 0.3; 
		waitUntil {(ctrlCommitted _ctrlOver)}; 
		_ctrlOver ctrlSetTextColor [1,1,1,1];
		 
	};

	case "MouseExit": 
	{

		_ctrlOver = _dialog displayCtrl _ctrlOverNumber; 
		_ctrlOver ctrlSetFade 1;  
		_ctrlMain =_dialog displayCtrl _ctrlMainNumber; 
		_ctrlMain ctrlSetFade 0;  
		_ctrlMain ctrlCommit 0.1; 
		_ctrlOver ctrlCommit 0.1; 
		waitUntil {(ctrlCommitted _ctrlOver)}; 
		_ctrlOver ctrlSetTextColor [1,1,1,0];
	};
	case "SetFocus": 
	{
		 _ctrlFocus = _dialog displayCtrl _ctrlFocusNumber;
		 _ctrlFocus ctrlSetTextColor [1,1,1,1]; 
		 _ctrlFocus ctrlSetFade 0; 
		 _ctrlFocus ctrlCommit 0.1; 

	};
	case "KillFocus": 
	{
		_ctrlFocus = _dialog displayCtrl _ctrlFocusNumber;
		_ctrlFocus ctrlSetFade 0; 
		_ctrlFocus ctrlCommit 0;
			 
		_ctrlFocus ctrlSetFade 1; 
		_ctrlFocus ctrlCommit 0.1;
		waitUntil {(ctrlCommitted _ctrlFocus)};
		_ctrlFocus ctrlSetTextColor [1,1,1,0];
			
	};					
};

false
