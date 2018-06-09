private ["_sh","_p","_tr1","_tr2","_vec","_i","_int"];
_sh = nearestobject [_this select 0, _this select 4];

_p = getpos _sh;
_vec = vectordir _sh;
_int = (((speed _sh)/3240) * (0.7 + random 0.6)) min 1;
_life = _int * (0.5 + random 0.2);
if (_life == 0) exitwith {};
drop [
	["\A3\data_f\ParticleEffects\Universal\Universal",16,12,8], 
	"",
	"Billboard",
	1,
	_life,
	[0, 0, 0],
	[0, (2 + random 1.5)*_int, 0],
	0,
	0.104,
	0.08, 
	0.2,
	[0.1, 1*_int,1.6*_int,_int*2],
	[[0.9, 0.9, 0.9, 0.1 + random 0.07],[1, 1, 1, 0]],
	[1/_life],
	1,
	0,
	"",
	"",
	_sh,
	random 360
];
if (
	(abs(_p select 2) < _int) and !(surfaceiswater _p)
) then {
	_tr1= (_int - abs(_p select 2))/1.3;
	drop [
		["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16, 12, 13, 0],
		"",
		"Billboard",
		1,
		0.9 + random 0.3, 
		[_p select 0, _p select 1, 0.07],
		[((_vec select 0) -0.4 +(random 0.8))*1.3, ((_vec select 1) -0.4 +(random 0.8))*1.3, 0],
		0, 
		0.104,
		0.08,
		0.2,
		[(0.2 + random 0.2)*_int,(1.3 +random 0.6)*_int],
		[[0.6, 0.5, 0.4, _tr1],[0.6, 0.5, 0.4, 0]],
		[1000],
		1,
		0,
		"",
		"",
		""
	];	
};