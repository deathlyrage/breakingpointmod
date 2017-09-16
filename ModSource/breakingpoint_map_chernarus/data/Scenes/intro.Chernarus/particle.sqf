//--- Velkej coud
_obj = position player nearestobject 647912;
_pos = position _obj;
_PS1 = "#particlesource" createVehicleLocal _pos;
_PS1 setParticleCircle [0, [0, 0, 0]];
_PS1 setParticleRandom [3, [0, 0, 0], [0.5, 0.5, 0.5], 2, 0.5, [0.05, 0.05, 0.05, 0.05], 0, 0];
_PS1 setParticleParams [["\Ca\Data\ParticleEffects\FireAndSmokeAnim\SmokeAnim.p3d", 8, 3, 1], "", "Billboard", 1, 20, [0, 0, 14], [(wind select 0)/5, (wind select 1)/5, 2], 1, 1.275, 1, 0.066, [2, 8, 16], [[0.1, 0.05, 0, 0.15], [0.35, 0.3, 0.2, 0.1], [0.4, 0.4, 0.4, 0]], [0], 1, 0, "", "", _obj];

_PS1 setDropInterval .1;

//--- Velkej coud (vysoky komin)
{
	_obj = position player nearestobject _x;
	_dir = direction _obj;
	_pos = position _obj;
	_PS1 = "#particlesource" createVehicleLocal _pos;
	_PS1 setParticleCircle [0, [0, 0, 0]];
	_PS1 setParticleRandom [3, [0, 0, 0], [0.5, 0.5, 0.5], 2, 0.5, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PS1 setParticleParams [["\Ca\Data\ParticleEffects\FireAndSmokeAnim\SmokeAnim.p3d", 8, 3, 1], "", "Billboard", 1, 20, [(cos _dir)*0.5, (sin _dir)*0.5, 19], [(wind select 0)/5, (wind select 1)/5, 3], 1, 1.275, 1, 0.066, [1, 7, 14], [[0.6, 0.6, 0.6, 0.1], [0.7, 0.7, 0.7, 0.01], [0.8, 0.8, 0.8, 0]], [0], 1, 0, "", "", _obj];
	_PS1 setDropInterval .1;
} foreach [689990,689991,690018];

//--- Maly coudy
{
	_PSx = "#particlesource" createVehicleLocal _x;
	_PSx setParticleCircle [0, [0, 0, 0]];
	_PSx setParticleRandom [1, [0, 0, 0], [0.2, 0.2, 0], 2, 0.2, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PSx setParticleParams [["\Ca\Data\ParticleEffects\FireAndSmokeAnim\SmokeAnim.p3d", 8, 3, 1], "", "Billboard", 1, (2 + random 1), [0,0,0], [(wind select 0)/5, (wind select 1)/5, 2], 1, 1.275, 1, 0.066, [0.7, 1, 2], [[0.6, 0.6, 0.6, 0.1], [0.7, 0.7, 0.7, 0.01], [0.7, 0.7, 0.7, 0]], [0], 1, 0, "", "", ""];
	_PSx setDropInterval .1;
} foreach [
	[10108.96,1877.86,11.11],
//	[10100.35,1879.42,11.59],
	[10079.95,1878.05,15.87],
	[10071.19,1877.99,16.01],
	[10054.36,1899.12,15.58],
	[10049.84,1924.86,15.71],
	[10076.17,1945.66,15.85],
	[10013.66,1998.19,11.73]
];
