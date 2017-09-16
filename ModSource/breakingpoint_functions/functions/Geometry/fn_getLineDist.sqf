scriptName "Functions\geometry\fn_getLineDist.sqf";

//------------------
// Author: Philipp Pilhofer (raedor)
// Purpose: This function returns the distance between two sections of a straight line
// Arguments: [start section 1, length section 1, start section 2, length section 2]
// Return: float
//
// Revision History:
// 10/11/06 0.1 - First cut
//------------------


private["_l1", "_l2"];

_l1 = _this select 1;
_l2 = _this select 3;

(abs(2*(_this select 0) - 2*(_this select 2) + _l1 - _l2) -_l2 - _l1)/2