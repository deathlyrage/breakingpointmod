_array = [];
_mags = magazinesDetail _this;
//if (currentMagazineDetail _this != "") then { _mags pushBack currentMagazineDetail _this; };

{
  _cr = _x select [_x find ":"];
  _cr = _cr select [_cr find "/"];
  _cr = _cr select [1, count _cr - 2];
  _index = _array pushBack _cr;
} count _mags;

_array