scriptName "Functions\geometry\fn_distance2Dsqr.sqf";
/************************************************************
	Distance 2D Squared
	By Andrew Barron

Parameters: [object or position 1, object or position 2]

Returns the SQUARE of the distance between the two objects or
positions "as the crow flies" (ignoring elevation).
Working in the squared domain is a little faster than using the
fn_distance2D function.

Example: [player, getpos dude] call  BIS_fnc_distance2Dsqr
************************************************************/

private ["_pos1","_pos2"];

_pos1 = _this select 0;
_pos2 = _this select 1;

//if objects, not positions, were passed in, then get their positions
if(typename _pos1 == "OBJECT") then {_pos1 = getpos _pos1};
if(typename _pos2 == "OBJECT") then {_pos2 = getpos _pos2};

//return SQUARED distance between _pos1 and _pos2
(
	((_pos1 select 0) - (_pos2 select 0))^2 +
	((_pos1 select 1) - (_pos2 select 1))^2
)