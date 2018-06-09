private ["_u", "_sh","_i","_no","_int"];
_u = _this select 0;
_sh = nearestobject [_u, _this select 4];

_i=1;
_no=5+random 2;
//Flash
while {_i<_no} do 
		{
		
		drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,2,32],
		"", "Billboard", 1,(0.08 + 0.01*_i), 
		[0 + random 0.5, 2 + random 0.5, 0 + random 0.5], 
		[-5 + random 10, (_i*8) - 5 + random 10, -5 + random 10], 
		0, 10, 7.9, 0.075, 
		[1.5, _i*1.2], 
		[[1, 1, 1, -1.5],[1, 1, 1, -1.5], [1, 1, 1, -0.5], [1, 1, 1, -0]], 
		[3 + random 2], 1, 0, "", "", _sh];
		
		_i=_i+1;
		};
//Smoke
_i=1;
_no=10+random 4;
while {_i<_no}
do
	{
	drop [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48],
	"", "Billboard", 1, 4+random 2,
	[-0.5 + random 1, 2 + random 0.5, -0.5 + random 1],
	[-1+random 2,(3+random 1.5)*_i,-1+random 2],
	1.2, 1.275, 1, 0.6, 
	[1.5,(5+random 2)*(_i/2)],
	[[0.7,0.7,0.7,0],[0.72,0.72,0.72,0.18],[0.75,0.75,0.75,0.14],[0.75,0.75,0.75,0.1],[0.8,0.8,0.8,0.06], [0.83,0.83,0.83,0.02]],
	[2,0.7,0.5],0.1,0.1,"","",_sh];
	_i=_i+1;
	};
	
//Dust
_null = [_u] execVM "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\cannondust.sqf";
// ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
// [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
