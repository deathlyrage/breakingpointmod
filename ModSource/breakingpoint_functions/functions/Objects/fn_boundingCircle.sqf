scriptName "modules_f\Functions\objects\fn_boundingCircle.sqf";
/*
	File: fn_boundingCircle.sqf
	Author: Karel Moricky

	Description:
	Returns size of bounding circle (calculated from X and Y coordinates)

	Parameter(s):
	_this: Object

	Returns:
	Number
*/

private ["_obj","_bbox","_b1","_b2","_bbx","_bby","_size"];
_obj = _this;
_bbox = boundingbox _obj;
_b1 = _bbox select 0;
_b2 = _bbox select 1;
_bbx = (abs(_b1 select 0) + abs(_b2 select 0));
_bby = (abs(_b1 select 1) + abs(_b2 select 1));
_size = (sqrt(_bbx^2 + _bby^2));
_size;