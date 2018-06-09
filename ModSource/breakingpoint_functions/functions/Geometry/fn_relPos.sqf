scriptName "Functions\geometry\fn_relPos.sqf";
/************************************************************
	Relative Position
	By Andrew Barron

Parameters: [object or position, distance, direction]

Returns a position that is a specified distance and compass
direction from the passed position or object.

Example: [player, 5, 100] call BIS_fnc_relPos
************************************************************/

private ["_pos","_dist","_dir"];

_pos  = _this select 0;
_dist = _this select 1;
_dir  = _this select 2;

//if an object, not position, was passed in, then get its position
if(typename _pos == "OBJECT") then {_pos = getpos _pos};

//find position relative to passed position
if (count _pos==3) then
{
	_pos = [(_pos select 0) + _dist*sin _dir, (_pos select 1) + _dist*cos _dir, _pos select 2];
}
else
{
	_pos = [(_pos select 0) + _dist*sin _dir, (_pos select 1) + _dist*cos _dir];
};
_pos
