private ["_min", "_max", "_step", "_maxFactor", "_radius", "_maxTime"];
_min = _this select 0;
_max = _this select 1;
_step = _this select 2;
_maxFactor = _this select 3;
_maxTime = 10;

_radius = _step / 2;

private ["_funcAnalyzeCell"];
_funcAnalyzeCell =
{
	private ["_pos"];
	_pos = _this select 0;

	private ["_posTL", "_posTR", "_posBL", "_posBR"];
	_posTL = [(_pos select 0) - _radius, (_pos select 1) - _radius];
	_posTR = [(_pos select 0) + _radius, (_pos select 1) - _radius];
	_posBL = [(_pos select 0) - _radius, (_pos select 1) + _radius];
	_posBR = [(_pos select 0) + _radius, (_pos select 1) + _radius];

	private ["_result"];
	_result = [false, _pos];

	private ["_water"];
	_water = false;
	{
		if (surfaceIsWater _x) exitWith
		{
			_water = true;
		};
	}
	forEach [_pos, _posTL, _posTR, _posBL, _posBR];

	private ["_gradientTooBig"];
	_gradientTooBig = false;

	private ["_posArray"];
	_posArray = [_pos, _posTL, _posTR, _posBL, _posBR];

	for "_i" from 0 to ((count _posArray) - 1) do
	{
		for "_k" from 0 to ((count _posArray) - 1) do
		{
			private ["_pos1", "_pos2"];
			_pos1 = _posArray select _i;
			_pos2 = _posArray select _k;

			if (((_pos1 select 0) != (_pos2 select 0)) && ((_pos1 select 1) != (_pos2 select 1))) then
			{
				private ["_sample1", "_sample2", "_posASL1", "_posASL2"];
				_sample1 = "Logic" createVehicle _pos1;
				_sample2 = "Logic" createVehicle _pos2;

				_posASL1 = getPosASL _sample1;
				_posASL2 = getPosASL _sample2;

				deleteVehicle _sample1;
				deleteVehicle _sample2;

				private ["_heightDiff"];
				_heightDiff = abs ((_posASL1 select 2) - (_posASL2 select 2));

				if (_heightDiff > _maxFactor) then
				{
					_gradientTooBig = true;
				};
			};
		};
	};

	if (!_water && !_gradientTooBig) then
	{
		_result = [true, _pos];
	};

	_result
};

private ["_result", "_found", "_timeNow"];
_found = false;
_timeNow = time;
while {!_found && ((time - _timeNow) < _maxTime)} do
{
	_result = [[random _max, random _max]] call _funcAnalyzeCell;
	
	_found = _result select 0;
};

//Set to default position (center of map) if maximum time elapsed.
if !(_found) then 
{
	_result = [true, getArray (configFile >> "CfgWorlds" >> worldName >> "centerPosition")];
};

private ["_pos"];
_pos = _result select 1;

_pos