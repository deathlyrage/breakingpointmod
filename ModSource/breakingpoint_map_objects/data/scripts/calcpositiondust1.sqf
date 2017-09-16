//Function used to calculate relative positions next a helicopter for dust generation.
private ["_angle", "_target", "_quadrant", "_result", "_pos", "_vec", "_dir", "_radius", "_speed"];

_angle = (_this select 0);
_target = (_this select 1);
_quadrant = 0;
_pos = (position _target);
_dir = ((direction _target) + _angle);
_vec = [0, 0, 0];
_radius = 2;
_speed = (10 + (2 - (random 4)));
_result = [];

if (_dir >= 360) then {_dir = _dir - 360;};

if (_dir > 0 && _dir <= 90) then 
{
	_quadrant = 0;
} 
else 
{
	if (_dir > 90 && _dir <= 180) then 
	{
		_quadrant = 90;
	} 
	else 
	{
		if (_dir > 180 && _dir <= 270) then 
		{
			_quadrant = 180;
		} 
		else 
		{
			if (_dir > 270 && _dir <= 360) then 
			{
				_quadrant = 270;
			};
		};
	};
};

switch (_quadrant) do 
{
	case 0: 
	{
		_pos = [(_pos select 0) + ((sin (_dir - _quadrant)) * _radius), (_pos select 1) + ((cos (_dir - _quadrant)) * _radius), -0.5];
		_vec = [((sin (_dir - _quadrant)) * _speed), ((cos (_dir - _quadrant)) * _speed), 0]
	};
	
	case 90: 
	{
		_pos = [(_pos select 0) + ((cos (_dir - _quadrant)) * _radius), (_pos select 1) - ((sin (_dir - _quadrant)) * _radius), -0.5];
		_vec = [((cos (_dir - _quadrant)) * _speed), -((sin (_dir - _quadrant)) * _speed), 0]
	};
	
	case 180: 
	{
		_pos = [(_pos select 0) - ((sin (_dir - _quadrant)) * _radius), (_pos select 1) - ((cos (_dir - _quadrant)) * _radius), -0.5];
		_vec = [-((sin (_dir - _quadrant)) * _speed), -((cos (_dir - _quadrant)) * _speed), 0]
	};
	
	case 270: 
	{
		_pos = [(_pos select 0) - ((cos (_dir - _quadrant)) * _radius), (_pos select 1) + ((sin (_dir - _quadrant)) * _radius), -0.5];
		_vec = [-((cos (_dir - _quadrant)) * _speed), ((sin (_dir - _quadrant)) * _speed), 0]
	};			
	
	default {};
};

_result = [_pos, _vec];
_result