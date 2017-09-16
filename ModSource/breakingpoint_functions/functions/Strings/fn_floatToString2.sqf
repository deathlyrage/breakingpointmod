private "_arr";
_arr = toArray str abs (_this % 1);
_arr set [0, 32];
toString (toArray str (abs (_this - _this % 1) * _this / abs _this) + _arr - [32])