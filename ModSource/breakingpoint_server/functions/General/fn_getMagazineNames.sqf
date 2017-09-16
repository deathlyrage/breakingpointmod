_array = [];
_mags = magazinesDetail _this;
//if (currentMagazineDetail _this != "") then { _mags pushBack currentMagazineDetail _this; };

{
	_index = _x find "(";
	_cr = toArray _x;
	_cr deleteRange [_index,count _cr];
	_index = _array pushBack (toString _cr);
} count _mags;
_array
