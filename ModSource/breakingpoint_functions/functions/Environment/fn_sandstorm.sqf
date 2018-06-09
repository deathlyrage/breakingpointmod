scriptName "fn_sandstorm.sqf";
/*
	Author: Karel Moricky

	Description:
	Creates particle sandstorma round given object.

	Parameter(s):
	_this select 0: OBJECT - Sandstorm center
	_this select 1 (Optional): NUMBER - particle refresh time
	_this select 2 (Optional): NUMBER - color brightness coeficient (1 - bright, 0 dark)
	_this select 3 (Optional): BOOL - true for flying newspapers

	Returns:
	ARRAY - Particle sources
*/
private ["_obj","_density","_colorCoef","_newspapers","_pos","_velocity","_relPos","_color","_alpha","_ps","_newsParams","_newsRandom","_newsCircle","_newsInterval","_times","_herald","_tribune","_result"];

_obj = _this select 0;
_density = if (count _this > 1) then {_this select 1} else {0.07}; if (_density < 0) then {_density = 0.07};
_colorCoef = if (count _this > 2) then {_this select 2} else {1}; if (_colorCoef < 0) then {_density = 1};
_newspapers = if (count _this > 3) then {_this select 3} else {true};
_pos = position _obj;

//--- Dust
_duration = 2;
_velocity = [0,7,0];
_relPos = [-((_velocity select 1) * (_duration / 2)), 0, -6];
_color = [1.0 * _colorCoef, 0.9 * _colorCoef, 0.8 * _colorCoef];
_alpha = 0.2;
_ps = "#particlesource" createVehicleLocal _pos;  
_ps setParticleParams [["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 12, 8, 0], "", "Billboard", 1, _duration, _relPos, _velocity, 1, 1.275, 1, 0, [5], [_color + [0], _color + [_alpha], _color + [0]], [1000], 1, 0, "", "", _obj];
_ps setParticleRandom [3, [10, 10, 0], [0, 0, 0], 1, 0, [0, 0, 0, 0.05], 0, 0];
_ps setParticleCircle [0.1, [0, 0, 0]];
_ps setDropInterval _density;

//--- Newspapers
_result = if (_newspapers && false) then {
	_newsParams = [["\A3\Missions_PMC\gnews1.p3d", 1, 0, 1], "", "SpaceObject", 1, 5, [0, 0, 1], _velocity, 1, 1.25, 1, 0.2, [0,1,1,1,0], [[1,1,1,1]], [0.7], 1, 0, "", "", _obj];
	_newsRandom = [0, [30, 30, 0], [5, 5, 0], 2, 0.3, [0, 0, 0, 0], 10, 0];
	_newsCircle = [0.1, [1, 1, 0]];
	_newsInterval = 1;

	_times = "#particlesource" createVehicleLocal _pos;  
	_times setParticleParams _newsParams;
	_times setParticleRandom _newsRandom;
	_times setParticleCircle _newsCircle;
	_times setDropInterval _newsInterval;

	_newsParams set [0,["\A3\Missions_PMC\gnews2.p3d", 1, 0, 1]];
	_herald = "#particlesource" createVehicleLocal _pos;  
	_herald setParticleParams _newsParams;
	_herald setParticleRandom _newsRandom;
	_herald setParticleCircle _newsCircle;
	_herald setDropInterval _newsInterval;

	_newsParams set [0,["\A3\Missions_PMC\gnews3.p3d", 1, 0, 1]];
	_tribune = "#particlesource" createVehicleLocal _pos;  
	_tribune setParticleParams _newsParams;
	_tribune setParticleRandom _newsRandom;
	_tribune setParticleCircle _newsCircle;
	_tribune setDropInterval _newsInterval;

	[_ps,_times,_herald,_tribune]
} else {
	[_ps]
};

_result
