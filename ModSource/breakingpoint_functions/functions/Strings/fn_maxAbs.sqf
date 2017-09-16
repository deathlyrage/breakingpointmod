private ["_sgn0","_sgn1","_max","_n0","_n1"];
_sgn0 = _this select 2;
_sgn1 = _this select 3;
_this set [6, -1 max (_sgn0 - _sgn1) min 1];
for "_i" from 0 to (_this select 5) - 1 do {
	_n0 = _this select 0 select _i;
	_n0 = if (isNil "_n0") then [{0},{parseNumber toString [_n0]}];
	_n1 = _this select 1 select _i;
	_n1 = if (isNil "_n1") then [{0},{parseNumber toString [_n1]}];
	if (_n0 > _n1) exitWith {
		_this set [6, -1 max (_sgn0 * 2 + _sgn1) min 1]
	};
	if (_n1 > _n0) exitWith {
		_this = [
			_this select 1, _this select 0, _sgn1, _sgn0, 
			_this select 4, _this select 5,
			-(-1 max (_sgn0 + _sgn1 * 2) min 1)
		];
	};
};
_this