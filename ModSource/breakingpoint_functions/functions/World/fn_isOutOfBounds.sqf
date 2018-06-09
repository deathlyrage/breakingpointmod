/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_object = _this;

if (isNull _object) exitWith {false};

//Out Of Bounds (For Maps Like Chernarus)
_mapConfig = (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Map");
if !(isClass _mapConfig) exitWith {false};

//Fetch Bounds, Min XY, Max XY and Target XY
_minBounds = getArray (_mapConfig >> "BoundryMin");
if (_minBounds isEqualTo []) exitWith {false};
_maxBounds = getArray (_mapConfig >> "BoundryMax");
if (_maxBounds isEqualTo []) exitWith {false};

_minBounds params ["_minX","_minY"];
_maxBounds params ["_maxX","_maxY"];
(getPosATL _object) params ["_x","_y"];

//["isOutOfBounds: Object: %1 | Pos: %2 | Min Bounds: %3 | Max Bounds: %4",_object,(getPosATL _object),_minBounds,_maxBounds] call BP_fnc_debugConsoleFormat;

//Position Checks
if (_x < _minX || {_x > _maxX} || {_y < _minY} || {_y > _maxY}) exitWith {true};
	
false