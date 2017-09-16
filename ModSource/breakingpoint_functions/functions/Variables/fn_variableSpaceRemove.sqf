scriptName "Functions\variables\fn_variableSpaceRemove.sqf";
/*
	File: variableSpaceAdd.sqf
	Author: Karel Moricky

	Description:
	Remove element from variable from someone's variable space.

	Parameter(s):
	_this select 0: OBJECT - owner of variable space
	_this select 1: STRING - Name of variable
	_this select 2: ANYTHING - element which will be removed (must be of same type as variable)
	_this select 3: BOOLEAN - optional - True if modified variable will be saved globally.¨

	Returned values:
	ANYTHING - updated variable

*/
private ["_object","_variablename","_element","_global","_variable","_match","_subelement"];

_object = _this select 0;
_variablename = _this select 1;
_element = _this select 2;
_global = if (count _this > 3) then {_this select 3} else {false};

_variable = +(_object getvariable _variablename);

if (isnull _object) exitwith {textLogFormat ["Log: [variableSpaceRemove] ERROR: Null object for %1!",_variablename]};
if (isnil "_variable") exitwith {textLogFormat ["Log: [variableSpaceRemove] ERROR: Variable '%1' does not exist in %2!",_variablename,_object]};

//--- Different types
if (typename _variable != "ARRAY" && typename _variable != typename _element) exitwith {_variable; debuglog "Log: [variableSpaceRemove] Mismatch of element and variable types."};

//--- If type is array, compare arrays inside
if (typename _variable == "ARRAY") then {
	for "_i" from 0 to (count _variable - 1) do {
		_subelement = _variable select _i;
		_match = if (typename _subelement == "ARRAY") then {
			if (count _element > 0) then {
				{[_subelement,_x] call BIS_fnc_arrayCompare} count _element > 0;
			} else {
				[_subelement,_element] call BIS_fnc_arrayCompare;
			};
		} else {
			_subelement in _element;
		};
		if (_match) then {
			_variable set [_i,"<DELETE>"];
		};
	};
	_element = ["<DELETE>"];
};

//--- Remove element and save modified variable
_variable = _variable - _element;

if (typename _object == "LOCATION") then {
	_object setvariable [_variablename,_variable];
} else {
	_object setvariable [_variablename,_variable,_global];
};


_variable;