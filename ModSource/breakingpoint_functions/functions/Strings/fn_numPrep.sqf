private ["_arr0","_arr1","_sgn0","_flp0","_sgn1","_flp1","_off","_arr","_max"];
_arr0 = toArray (_this select 0) - [44];
_arr1 = toArray (_this select 1) - [44];
_sgn0 = if (_arr0 select 0 == 45) then {
	_arr0 set [0, 'x'];
	_arr0 = _arr0 - ['x'];
	-1
} else {1};
_flp0 = _arr0 find 46;  
if (_flp0 < 0) then {_flp0 = count _arr0};
_sgn1 = if (_arr1 select 0 == 45) then {
	_arr1 set [0, 'x'];
	_arr1 = _arr1 - ['x'];
	-1
} else {1};
_flp1 = _arr1 find 46;
if (_flp1 < 0) then {_flp1 = count _arr1};
_off = _flp0 - _flp1;
if (_off != 0) then {
	_arr = []; 
	_arr resize abs _off;
	if (_off < 0) exitWith {_arr0 = _arr + _arr0};
	if (_off > 0) exitWith {_arr1 = _arr + _arr1};
};
_max = count _arr0 max count _arr1;
_arr0 resize _max; _arr1 resize _max;
[_arr0, _arr1, _sgn0, _sgn1, _flp0 max _flp1, _max]