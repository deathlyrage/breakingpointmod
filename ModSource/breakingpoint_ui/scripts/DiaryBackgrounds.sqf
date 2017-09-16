disableSerialization;
//debuglog _this;

private ["_data","_display","_control"];
_fadeControls = [101,102,103,114,1001,1002,1003,1004,1005,1006,1013,1020,1021,1022,1023];
_hideControls = [1023,1022];
_updateCoordinates = {
  _constant = 0.02;
  _inputArray = _this;
  _y = (_inputArray select 1) - _constant;
  _h = (_inputArray select 3) + 2*_constant;
  _inputArray set [1, _y];
  _inputArray set [3, _h];
  _inputArray;  
};



_data = _this select 0;
_action = _this select 1;
if (_action == "onload") then {
  _delay = 0.0;
} else { 
  _delay = 0.2;
};
if(typeName(_data select 0) == "DISPLAY")then 
{
	_display = (_data select 0);
	
};

if(typeName(_data select 0) == "CONTROL")then 
{
	_control = (_data select 0);
	_display = ctrlParent _control;
};

_hideDiary = {  
  for [{_x=0},{_x<=(count _hideControls)},{_x=_x+1}] do {
  	_control = _hideControls select _x;
		_disp_ctrl = (_display displayCtrl _control); 
     if (_this) then {
        _disp_ctrl ctrlShow  false;
        
     } else {
       _disp_ctrl ctrlShow  true;
     };
     	_disp_ctrl ctrlCommit _delay;
  };
};  

_fadeDiary = {  
  for [{_x=0},{_x<=(count _fadeControls)},{_x=_x+1}] do {
  	_control = _fadeControls select _x;
		_disp_ctrl = (_display displayCtrl _control); 
     if (_this) then {
        _disp_ctrl ctrlSetFade 0.6;
        
     } else {
        _disp_ctrl ctrlSetFade 0;
     };
     	_disp_ctrl ctrlCommit _delay;
  };
    
};

if (_action=="onload") then {
  (_display displayctrl 1001) lbSetCurSel 1;
}; 
/*
_coordinates = 	ctrlPosition (_display displayctrl 1001); 	
_coordinates = 	_coordinates call _updateCoordinates;					
(_display displayctrl 1021) ctrlSetPosition		_coordinates;
(_display displayctrl 1021) ctrlCommit _delay;


_coordinates = 	ctrlPosition (_display displayctrl 1002); 							
_coordinates = 	_coordinates call _updateCoordinates;
(_display displayctrl 1022) ctrlSetPosition		_coordinates;
(_display displayctrl 1022) ctrlCommit _delay;

_coordinates = 	ctrlPosition (_display displayctrl 1013); 							
_coordinates = 	_coordinates call _updateCoordinates;

(_display displayctrl 1023) ctrlSetPosition		_coordinates;
(_display displayctrl 1023) ctrlCommit _delay; */
/*
if ( ((_display displayctrl 1001)==_control) && ((_data select 1) == 0) ) then {
      _dummy = true call _fadeDiary;
      _dummy = true call _hideDiary;
  } else {
      _dummy = false call _fadeDiary;
      _dummy = false call _hideDiary;
};

_dummy = ((lbSize (_display displayctrl 1002))==0) call _hideDiary;
*/
