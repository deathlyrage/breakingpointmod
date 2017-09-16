scriptName "fn_destroyCity.sqf";
/*
	Author: Karel Moricky

	Description:
	Destroys building in given area based on input seed.

	Parameter(s):
	_this select 0: OBJECT - Destruction center
	_this select 1 (Optional): NUMBER - Destruction area diameter
	_this select 2 (Optional): NUMBER - Random seed
	_this select 3 (Optional): ARRAY - Array of blacklisted objects

	Returns:
	ARRAY - Particle sources
*/
if (!isserver) exitwith {debuglog "Log: [Functions] ERROR: 'BIS_fnc_destroyCity' cannot run on client.";};

private ["_center","_areaSize","_seed","_blacklist","_debug","_buildings","_pos","_posX","_posY","_posTotal","_seedLocal"];
_center = _this select 0;
_areaSize = if (count _this > 1) then {_this select 1} else {1000};
_seed = if (count _this > 2) then {_this select 2} else {1138};
_blacklist = if (count _this > 3) then {_this select 3} else {[]};
_debug = if (isnil "_debug") then {false} else {_debug};

if (typename _center == typename "") then {_center = markerpos _center};
if (typename _center == typename objnull) then {_center = position _center};

if (_areaSize < 0) then {_areaSize = 1000;};
if (_seed < 0) then {_seed = 1138;};

_seed =  round(_seed % 42);
if (_seed == 0) then {_seed = 42;};

_buildings = _center nearobjects ["house",_areaSize];
_buildings = _buildings - _blacklist;
{
	_pos = position _x;
	_posX = _pos select 0;
	_posY = _pos select 1;
	_posTotal = _posX + _posY;
	_seedLocal = (_posTotal % _seed) / _seed;

	if (_seedLocal < 0.5) then {
		//_x setdamage 1;
		for "_i" from 1 to 7 do {
			_x sethit [format ["dam%1",_i],1];
			_x sethit [format ["dam %1",_i],1];
		};
		if (_debug) then {_marker =_x call bis_fnc_boundingboxmarker; _marker setmarkercolor "colorred";};
	} else {
		if (_seedLocal > 0.9) then {
			//_x hideobject true;
			_x setdamage 1;
			if (_debug) then {_marker =_x call bis_fnc_boundingboxmarker; _marker setmarkercolor "colorblue";};

		} else {
			_x setdamage 0.5;
			if (_debug) then {_marker =_x call bis_fnc_boundingboxmarker; _marker setmarkercolor "colorgreen";};
		};
	};
} foreach _buildings;

true