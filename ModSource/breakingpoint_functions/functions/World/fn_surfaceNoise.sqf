/*
	Breaking Point: BP_fnc_surfaceNoise
	
	Description:
	Returns the sun's rise in hours for the current day of the year on any island (whos latitude may differ).
	
	Parameter(s):
	_this: unit
	
	Returns:
	Array
	
	TODO:
	Fix Calculation of the sound values for Arma 3's new dev update
*/

private["_unit","_pos","_type","_typeA","_test","_soundType","_soundVal","_array"];

_unit = 	_this;
_pos = 		getPosATL _unit;
_type = 	surfaceType _pos;
_typeA = 	toArray _type;
_typeA 		set [0,"DEL"];
_typeA = 	_typeA - ["DEL"];
_type = 	toString _typeA;
_test = 	0;

//diag_log ("FINDME: " + _type);

_soundType = 	getText (configFile >> "CfgSurfaces" >> _type >> "soundEnviron");
//_soundVal =		parseNumber format["%1",((getArray (configFile >> "CfgVehicles" >> "CAManBase" >> "SoundEnvironExt" >> _soundType) select 0) select 3)];
//if (_soundVal == 0) then {
_soundVal = 25;
//};
//_soundVal = 25;
_array = [_soundType,_soundVal];
_array