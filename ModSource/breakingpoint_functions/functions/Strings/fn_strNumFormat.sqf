private ["_flp","_max","_num","_k"];
_this = toArray _this - [44];
_flp = _this find 46;
_max = count _this;
call {
	if (_flp < 0) exitWith {_this = _this + [46,48,48]};
	if (_flp < _max - 3) exitWith {_this resize (_flp + 3)};
	if (_flp > _max - 3) exitWith {_this = _this + [48]};
};
_max = count _this;
_num = ""; _k = -4;
for "_i" from _max - 1 to 0 step -1 do {
	_k = if (_k == 2) then [{_num = "," + _num; 0},{_k + 1}];
	_num = toString [_this select _i] + _num;
};
_num