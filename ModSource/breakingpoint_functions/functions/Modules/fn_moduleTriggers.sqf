private ["_object","_result"];
_object = [_this,0,objnull,[objnull]] call bis_fnc_param;
_result = [];

//--- Scan synchronized objects
{
	if (triggertype _x == "NONE") then {
		_result set [count _result,_x];
	};
} foreach (synchronizedobjects _object);

_result