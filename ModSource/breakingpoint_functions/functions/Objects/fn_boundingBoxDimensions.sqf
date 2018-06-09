scriptName "modules_f\Functions\objects\fn_boundingBoxDimensions.sqf";
/*
	File: fn_boundingBoxDimensions.sqf
	Author: Joris-Jan van 't Land

	Description:
	Returns the sizes of the three dimension of an object's bounding box.

	Parameter(s):
	_this: Object (object)
	
	Returns:
	Array (dimensions)
		0: x
		1: y
		2: z
*/

private ["_boundBox", "_bbPos1", "_bbPos2"];
_boundBox = boundingBox _this;
_bbPos1 = _this modelToWorld (_boundBox select 0);
_bbPos2 = _this modelToWorld (_boundBox select 1);

private ["_xDim", "_yDim", "_zDim"];
_xDim = abs ((_bbPos1 select 0) - (_bbPos2 select 0));
_yDim = abs ((_bbPos1 select 1) - (_bbPos2 select 1));
_zDim = abs ((_bbPos1 select 2) - (_bbPos2 select 2));

[_xDim, _yDim, _zDim]