scriptName "modules_f\Functions\objects\fn_boundingBoxCorner.sqf";
/*
	File: fn_boundingBoxCorner.sqf
	Author: Karel Moricky

	Description:
	Returns position of all four bounfing box corners

	Parameter(s):
	_this: Object

	Returns:
	Array in format [pos1,pos2,pos3,pos4]
*/

private ["_obj","_pos","_bbox","_b1","_b2","_bbx","_bby","_dir","_size","_corner1","_corner2","_corner3","_corner4","_return","_disTemp","_returnTemp"];

_obj = _this;
_pos = [];
if (typename _obj == "ARRAY") then {
	_obj = _this select 0;
	_pos = _this select 1;
	if (typename _pos == "OBJECT") then {_pos = position _pos};
};
_bbox = boundingbox _obj;
_b1 = _bbox select 0;
_b2 = _bbox select 1;
_bbx = (abs(_b1 select 0) + abs(_b2 select 0)) / 2;
_bby = (abs(_b1 select 1) + abs(_b2 select 1)) / 2;
_bbx1 = _b1 select 0;
_bbx2 = _b2 select 0;
_bby1 = _b1 select 1;
_bby2 = _b2 select 1;



_size = _obj call bis_fnc_boundingcircle;

_dir = (direction _obj) + atan (_bbx/_bby);
_objpos = position _obj;//_obj modeltoworld (boundingcenter _obj);
_corner1 = [
	(_objpos select 0) + (sin _dir * _size / 2),
	(_objpos select 1) + (cos _dir * _size / 2),
	0
];
_dir = (direction _obj) - atan (_bbx/_bby);
_dir = _dir + 180;
_corner2 = [
	(_objpos select 0) + (sin _dir * _size / 2),
	(_objpos select 1) + (cos _dir * _size / 2),
	0
];
_dir = (direction _obj) + atan (_bbx/_bby);
_dir = _dir + 180;
_corner3 = [
	(_objpos select 0) + (sin _dir * _size / 2),
	(_objpos select 1) + (cos _dir * _size / 2),
	0
];
_dir = (direction _obj) - atan (_bbx/_bby);
_corner4 = [
	(_objpos select 0) + (sin _dir * _size / 2),
	(_objpos select 1) + (cos _dir * _size / 2),
	0
];
_return = [_corner1,_corner2,_corner3,_corner4];

/*
_marker = createmarker [format ["zzz%1",floor random 100000],_objpos];
_marker setmarkerdir direction _obj;
_marker setmarkershapelocal "rectangle";
_marker setmarkersizelocal [(abs _bbx1 + abs _bbx2) / 2,(abs _bby1 + abs _bby2) / 2];
_marker setmarkercolor "colorgreen";
_colors = ["coloryellow","colorred","colorblue","colorgreen"];
for "_i" from 0 to 3 do {
	_corner = _return select _i;

	_marker = createmarker [format ["xxx%2%1",_i,floor random 100000],_corner];
	_marker setmarkerdir direction _obj;
	_marker setmarkertypelocal "mil_dot";
	_marker setmarkercolor (_colors select _i);
};
*/

//--- Return nearest one only
if (count _pos > 0) then {
	_dis = 10e10;
	_returnTemp = [];
	{
		_disTemp = _x distance _pos;
		if (_disTemp < _dis) then {
			_dis = _disTemp;
			_returnTemp = _x;
		};	
	} foreach _return;
	_return = _returnTemp;
};

_return;