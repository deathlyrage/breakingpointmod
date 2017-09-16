private ["_u", "_sh","_i","_no","_int"];
_u = _this select 0;
_sh = nearestobject [_u, _this select 4];

_i=1;
_no=2+random 1;
//Flash
while {_i<_no} do 
		{
		
		drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,2,32],
		"", "Billboard", 1,(0.35 + 0.05*_i), 
		[0, 0.33, 0], 
		[-0.25 + random 0.5, 0.5 + (1*_i), -0.25 + random 0.5], 
		0, 10, 7.9, 0.075, 
		[0.3, _i*0.6], 
		[[1, 1, 1, -1.5],[1, 1, 1, -1.2], [1, 1, 1, -0.2], [1, 1, 1, 0]], 
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
	[-0.2 + random 0.4, -0.2 + random 0.4, -0.6 + random 0.2],
	[-1+random 2,(2+random 1)*_i,-1+random 2],
	1.2, 1.275, 1, 0.7, 
	[1.2,(5+random 2)*(_i/4)],
	[[0.7,0.7,0.7,0],[0.72,0.72,0.72,0.08],[0.75,0.75,0.75,0.06],[0.75,0.75,0.75,0.04],[0.8,0.8,0.8,0.02], [0.83,0.83,0.83,0.01]],
	[2,0.7,0.5],0.1,0.1,"","",_sh];
	_i=_i+1;
	};

// ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
// [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
