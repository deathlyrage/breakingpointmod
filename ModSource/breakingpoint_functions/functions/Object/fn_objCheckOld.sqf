/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_object","_isFlatEmpty","_valid"];

_valid = false;
_object = _this;

_bbr = boundingBoxReal _object;
_p1 = _bbr select 0;
_p2 = _bbr select 1;
_maxWidth = abs ((_p2 select 0) - (_p1 select 0));
_maxLength = abs ((_p2 select 1) - (_p1 select 1));
_maxHeight = abs ((_p2 select 2) - (_p1 select 2));
_unit = 0;

if (_maxWidth > _maxLength) then {
	_unit = _maxWidth;
} else {
	_unit = _maxLength;
};


_isFlatEmpty = (position _object) isFlatEmpty 
[
	_unit / 4,		//--- Minimal distance from another object
	0,			//--- If 0, just check position. If >0, select new one
	40,			//--- Max gradient
	_unit / 6,		//--- Gradient area
	0,			//--- 0 for restricted water, 2 for required water,
	false,		//--- True if some water can be in 25m radius
	_object		//--- Ignored object
];

/*
_isFlatEmpty = (position _object) isFlatEmpty 
[
	(sizeof typeof _object) / 4,		//--- Minimal distance from another object
	0,									//--- If 0, just check position. If >0, select new one
	1.5,								//--- Max gradient
	(sizeof typeof _object) / 4,		//--- Gradient area
	0,									//--- 0 for restricted water, 2 for required water,
	false,								//--- True if some water can be in 25m radius
	_object								//--- Ignored object
];
*/

if (_isFlatEmpty isEqualTo []) then {
	_valid = false;
} else {
	_valid = true;
};

_valid