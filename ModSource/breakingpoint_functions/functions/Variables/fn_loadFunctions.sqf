/*
	Author: Karel Moricky

	Description:
	Compile scripts and save them into globally available functions.

	Parameter(s):
		0: STRING - script path
		1: STRING - variable prefix
		2: ARRAY - list of variables to be declared. Elements can be of following types:
			variable: STRING - variable is (prefix + variable), loaded from (path + variable + ".sqf")
			[variable:STRING,fileName:STRING] - variable is (prefix  variable), loaded from (path + fileName + ".sqf")

	Returns:
	BOOL
*/

private ["_path","_variables","_globalExec","_variable","_fileName"];

_path = [_this,0,"",[""]] call bis_fnc_param;
_prefix = [_this,1,"",[""]] call bis_fnc_param;
_variables = [_this,2,[],[[]]] call bis_fnc_param;

if (_prefix == "BIS_fnc_") then {_prefix = ""; ["Prefix 'BIS_fnc_' is reserved for functions."] call bis_fnc_error;};
{
	_variable = [_x,0,"",[""]] call bis_fnc_paramin;
	_fileName = [_x,1,_variable,[""]] call bis_fnc_paramin;
	if (_variable != "" && _fileName != "") then {
		_file = format ["scriptname '%1'; private '_fnc_scriptName'; _fnc_scriptName = '%1';",_prefix + _variable] + preprocessfilelinenumbers (_path + _fileName + ".sqf");
		missionnamespace setvariable [_prefix + _variable,compileFinal _file];
	};
} foreach _variables;

true