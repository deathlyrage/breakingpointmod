    private "_res";
    switch ((_this select 2) + (_this select 3)) do {
        case (-2): {
            _this set [7, true];
            _res = (_this call BP_fnc_numOp) call BP_fnc_trunkZero;
            if (_res != "0") then {
                _res = "-" + _res;
            };
            _res
        };
        case (0): {
            _this = +_this call BP_fnc_maxAbs;
            _this set [7, false];
            _res = (_this call BP_fnc_numOp) call BP_fnc_numZero;;
            if (_this select 2 < 0 && {_res != "0"}) then {
                _res = "-" + _res;
            };
            _res
        };
        case (2): {
            _this set [7, true];
            (_this call BP_fnc_numOp) call BP_fnc_trunkZero;
        };
    };