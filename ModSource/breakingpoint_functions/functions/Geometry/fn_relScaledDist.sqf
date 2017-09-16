/*
	File: fn_relScaledDist.sqf
	Author: Dean Hall

	Description:
	Returns 

	Parameter(s):
		_this select 0: Trigger
		_this select 1: Object

	Returns:
	- exponentially inflated rational number between 0 and 1, with 1 being center and 0 being edge of the trigger
	
	Todo:
	- Object or Position
	- BOOL flag for no exp scale
	- Finish rectangle implementation
*/
private["_trigger","_trgArea","_a","_b","_angle","_isRec","_posT","_posP","_xT","_yT","_xP","_yP","_hyp","_xD","_yD","_x","_y","_p","_ratio","_result"];
_trigger = 	[_this, 0, objNull] call bis_fnc_param;
_object = 	[_this, 1, objNull] call bis_fnc_param;
_trgArea = triggerArea _trigger;
_a = 	_trgArea select 0;
_b = 	_trgArea select 1;
_angle = _trgArea select 2;
_isRec = _trgArea select 3;

_posT =	getPosATL _trigger;
_posP =	getPosATL _object;
_xT = 	_posT select 0;
_yT = 	_posT select 1;
_xP = 	_posP select 0;
_yP = 	_posP select 1;
_hyp = 	[_xT,_yT,0] distance [_xP,_yP,0];

//Origin X/Y
_xD =	_xP - _xT;
_yD =	_yP - _yT;

//Transform
_x = (cos(_angle) * _xD) - (sin(_angle) * _yD);
_y = (sin(_angle) * _xD) + (cos(_angle) * _yD);

_p = 0;
//if (_isRec) then {
	//--- RECTANGLE
//	_x = abs _x;
//	_y = abs _y;
//	_ratio = _a / _b;
//	_p = ((_x * _ratio) + (_y * (1 - _ratio))) / (_x + _y);		
//} else {
	_p = (_x^2 / _a^2) + (_y^2 / _b^2);
//};

_result = (log (10 - (9 * _p)));

if (_result > 0) then {
	_result = _result^2;
	_result
} else {
	0
}