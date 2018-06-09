/*
	Author: Karel Moricky

	Description:
	Return an unique object variable.
	The variable is preserved after unit respawn.

	Parameter(s):
		0: OBJECT
		1 (Optional): STRING - variable name (number will be added behind it)

	Returns:
	STRING
*/

private ["_object","_var"];

_object = [_this,0,objnull,[objnull]] call bis_fnc_param;
if (isnull _object) exitwith {""};
_var = _object getvariable ["BIS_fnc_setObjectVar_var",""];

if (_var == "") then {

	//--- Calculate dynamic variable
	_var = vehiclevarname _object;
	if (_var == "") then {
		private ["_varID"];
		_var = [_this,1,"BIS_fnc_setObjectVar_object",[""]] call bis_fnc_param;
		_varID = [_var,1] call bis_fnc_counter;
		_var = _var + str _varID;
		publicvariable "BIS_fnc_setObjectVar_object";
	};
	_object setvariable ["BIS_fnc_setObjectVar_var",_var,true];
	missionnamespace setvariable [_var,_object];
	publicvariable _var;

	//--- Execute where the unit is local, otherwise changes would not be restored after respawn
	if !(local _object) then {[[_object,_var],_fnc_scriptName,_object] call bis_fnc_mp;};
};
if (local _object && vehiclevarname _object == "") then {
	_object setvehiclevarname _var;
};
_var