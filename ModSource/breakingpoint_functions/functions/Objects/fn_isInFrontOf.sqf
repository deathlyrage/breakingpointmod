scriptName "Functions\objects\fn_isInFrontOf.sqf";

//------------------
// Author: Philipp Pilhofer (raedor)
// Purpose: This function checks, if a object is in front of another object
// Arguments: [object1, object2, offset (> 0 if position of object1 is not the front of object1)]
// Return: boolean
//
// Revision History:
// 20/11/06 0.1 - First cut
// 24/11/06 0.1 - added offset
//------------------


private["_obj", "_obj2", "_pos1", "_dirV", "_pos2"];
_obj = _this select 0;
_pos1 = position _obj;
_dirV = vectorDir _obj;
_obj2 = _this select 1;
_pos2 = position _obj2;
if (!(_obj2 in _obj) && ((_pos1 select 0)*(_dirV select 0)+(_pos1 select 1)*(_dirV select 1)+(_this select 2) < (_pos2 select 0)*(_dirV select 0)+(_pos2 select 1)*(_dirV select 1))) then [{true},{false}]