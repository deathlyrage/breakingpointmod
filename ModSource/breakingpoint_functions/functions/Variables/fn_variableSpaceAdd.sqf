scriptName "Functions\variables\fn_variableSpaceAdd.sqf";
/*
	File: variableSpaceAdd.sqf
	Author: Karel Moricky

	Description:
	Add element to variable from someone's variable space.

	Parameter(s):
	_this select 0: OBJECT - owner of variable space
	_this select 1: STRING - Name of variable
	_this select 2: ANYTHING - element which will be added (must be of same type as variable)
	_this select 3: BOOLEAN - optional - True if modified variable will be saved globally.
	_this select 4: BOOLEAN - optional - True if you want to check whether element is already in variable (only for arrays).

	Returned values:
	ANYTHING - updated variable

*/
private ["_object","_variablename","_element","_global","_variable","_check"];

_object = _this select 0;
_variablename = _this select 1;
_element = _this select 2;
_global = if (count _this > 3) then {_this select 3} else {false};
_check = if (count _this > 4) then {_this select 4} else {false};

_variable = +(_object getvariable _variablename);

if (isnull _object) exitwith {debuglog "Log: [variableSpaceAdd] ERROR: Null object! %1", [_variablename, _element, _global, _check]};

//--- Safety check
if (isnil "_variable") then {_variable = _element; _check = true;} else {

	if (typename _variable != typename _element) exitwith {_variable; textLogFormat ["Log: [variableSpaceAdd] Mismatch of element and variable types (%1)!",_this]};

	//--- Variable is an array - check whether element is already in
	if (_check) then {
		if (typename _variable != "ARRAY") exitwith {debuglog "Log: [variableSpaceAdd] Variable is not an array!"};
		if (count _element > 1) exitwith {debuglog "Log: [variableSpaceAdd] Too many elements to check!"};
		if !((_element select 0) in _variable) then {_variable = _variable + _element};;
	} else {
		_variable = _variable + _element
	};
};
if (typename _object == "LOCATION") then {
	_object setvariable [_variablename,_variable];
} else {
	_object setvariable [_variablename,_variable,_global];
};

_variable;