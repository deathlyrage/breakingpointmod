/*
	File: fn_boundingBoxMarker.sqf
	Author: Karel Moricky

	Description:
	Creates marker on object with size of objects' bounding box.

	Parameter(s):
	_this: Object

	Returns:
	String (marker)
*/

private ["_obj","_logic","_id","_bbox","_b1","_b2","_bbx","_bby","_marker"];

_obj = _this;
_logic = bis_functions_mainscope;

//--- ID not defined yet
_id = if (isnil {_logic getvariable "bundingBoxMarker_id"}) then {_logic setvariable ["bundingBoxMarker_id",-1];-1} else {_logic getvariable "bundingBoxMarker_id"};
[_logic,"bundingBoxMarker_id",1] call bis_fnc_variablespaceadd;

_bbox = boundingboxreal _obj;
_b1 = _bbox select 0;
_b2 = _bbox select 1;
_bbx = (abs(_b1 select 0) + abs(_b2 select 0));
_bby = (abs(_b1 select 1) + abs(_b2 select 1));
_marker = createmarkerlocal [format ["bundingBoxMarker_%1",_id],position _obj];
_marker setmarkerdir direction _obj;
_marker setmarkershapelocal "rectangle";
_marker setmarkersizelocal [_bbx/2,_bby/2];
_marker setmarkercolor "colorblack";

_marker