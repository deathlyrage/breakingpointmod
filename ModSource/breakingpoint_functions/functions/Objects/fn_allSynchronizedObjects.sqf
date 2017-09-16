/*
	Author: Karel Moricky

	Description:
	Return all synchronized objects, including those synced to synced and so on.

	Parameter(s):
		0: OBJECT - starting object
		1: STRING or ARRAY of STRINGs (Optional) - object types on which searching stops

	Returns:
	ARRAY of OBJECTs
*/
private ["_object","_breaks","_synced"];

_object = [_this,0,objnull,[objnull]] call bis_fnc_param;
_breaks = [_this,1,[],[[],""]] call bis_fnc_param;
_synced = [];

if (typename _breaks != typename []) then {_breaks = [_breaks];};

_fnc_synced = {
	_synced set [count _synced,_this];
	if ({typeof _this == _x} count _breaks == 0 || _this == _object) then {
		{
				_x call _fnc_synced;
		} foreach (synchronizedobjects _this - _synced);
	};
};

_object call _fnc_synced;

_synced