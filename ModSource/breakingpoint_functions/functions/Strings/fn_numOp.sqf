    private ["_c","_n","_num","_n0","_n1"];
    _c = 0; _n = 0; _num = "";
    for "_i" from (_this select 5) - 1 to 0 step -1 do {
        _num = (if (_i == (_this select 4)) then {"."} else {
            _n0 = _this select 0 select _i;
            _n0 = if (isNil "_n0") then [{0},{parseNumber toString [_n0]}];
            _n1 = _this select 1 select _i;
            _n1 = if (isNil "_n1") then [{0},{parseNumber toString [_n1]}];
            if (_this select 7) then {
                _n = _n0 + _n1 + _c;
                _c = if (_n > 9) then [{_n = _n - 10; 1},{0}];
            } else {
                _n = _n0 - _n1 - _c;
                _c = if (_n < 0) then [{_n = _n + 10; 1},{0}];
            };
            str _n
        }) + _num;
    };
    _num