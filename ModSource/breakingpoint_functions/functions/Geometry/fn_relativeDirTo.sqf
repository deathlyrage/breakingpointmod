scriptName "Functions\geometry\fn_relativeDirTo.sqf";
/************************************************************
	Relative Direction To
	By Andrew Barron

Parameters: [object 1, object or position 2]

Returns the relative direction from object 1 to
object/position 2. Return is always 0-360.

A position to the right of unit would be at a relative direction of 90 degrees, for example.

Example: [player, getpos dude] call BIS_fnc_relativeDirTo
************************************************************/

private "_dir";

_dir = _this call BIS_fnc_dirTo;     //get direction to target
_dir = _dir - (getdir (_this select 0)); //subtract direction of unit

//ensure return is between 0-360
if (_dir < 0) then {_dir = _dir + 360};
if (_dir > 360) then {_dir = _dir - 360};

_dir