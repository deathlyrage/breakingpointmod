disableSerialization;
private ["_x","_n", "_control", "_display","_y"];

_control = _this select 0;
_display = _control; 
_display = ctrlParent _control; 
_n = lbSize _control;  

for [{_x=_n-1},{_x>=(0)},{_x=_x-1}] do
{ 
	_color = _control lbColor _x;
	if ((_color select 0)> (_color select 1)) then {
		_color set [0,1];
		_color set [1,0];
		_color set [2,0];
		_color set [3,1];	
	} else {
		if ((_color select 0) == (_color select 1)) then {
			_color set [0,0];
			_color set [1,0];
			_color set [2,1];
			_color set [3,1];	
		} else {
			_color set [0,0];
			_color set [1,0.6];
			_color set [2,0];
			_color set [3,1];	
		
		};
	};

	_control lbSetColor [_x, _color];
}; 
