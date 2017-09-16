scriptName "Functions\geometry\fn_distance2D.sqf";
/************************************************************
	Distance 2D
	By Andrew Barron

Parameters: [object or position 1, object or position 2]

Returns the distance between the two objects or positions
"as the crow flies" (ignoring elevation)
Example: [player, getpos dude] call BIS_fnc_distance2D
************************************************************/

//return squared distance between _pos1 and _pos2
sqrt(_this call BIS_fnc_distance2Dsqr)
