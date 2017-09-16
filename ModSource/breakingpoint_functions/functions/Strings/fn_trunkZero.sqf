    private ["_max","_flp"];
    _this = toArray _this;
    _max = count _this;
    _flp = _this find 46;
    if (_flp < 0) then {_flp = _max};
    for "_i" from _max - 1 to _flp step -1 do {
        if (_this select _i == 46) exitWith {_this resize _i};
        if (_this select _i != 48) exitWith {_this resize (_i + 1)};
    };
    for "_i" from 0 to _flp - 2 do {
        if (_this select 0 != 48) exitWith {};
        _this set [0, 'x'];
        _this = _this - ['x'];
    };
    if (count _this == 0) then [{"0"},{toString _this}]