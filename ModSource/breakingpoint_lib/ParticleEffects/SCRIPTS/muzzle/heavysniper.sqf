private ["_sh","_p","_tr1","_tr2","_vec","_i","_no","_life"];
_sh = nearestobject [_this select 0, _this select 4];
_p = getpos _sh;
_vec = vectordir _sh;
_life=2.5 + random 1;
drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,12,8], "", 
"Billboard", 1, 1 + random 0.5, [0, 0, 0], [0, 2.2 + random 1.3, 0], 0, 0.104, 0.08, 0.2,
[0.1, 1.5, 2.1, 2.5], [[0.8, 0.8, 0.8, 0.3], [1, 1, 1, 0]], 
[1/_life], 1, 0, "", "", _sh];

_life=1.5 + random 1;
_i=0;
_no=3+random 2;
while {_i<_no} do
	{
		drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,12,8], "", 
		"Billboard", 1, 1.5 + random 1, [0, 0, 0], [0.7 + random 1.7, 0, 0], 0, 0.104, 0.08, 0.2,
		[0.1, _life - 0.6, _life, _life + 0.5], [[0.8, 0.8, 0.8, 0.2 + random 0.2], [1, 1, 1, 0]], 
		[1/_life], 1, 0, "", "", _sh,random 360];
		_i=_i+1;
	};
	
_life=1.5 + random 1;
_i=0;
_no=3+random 2;
while {_i<_no} do
	{
		drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,12,8], "", 
		"Billboard", 1, 1.5 + random 1, [0, 0, 0], [-0.7 - random 1.7, 0, 0], 0, 0.104, 0.08, 0.2,
		[0.1, _life - 0.6, _life, _life + 0.5], [[0.8, 0.8, 0.8, 0.2 + random 0.2], [1, 1, 1, 0]], 
		[1/_life], 1, 0, "", "", _sh,random 360];
		_i=_i+1;
	};

if ((abs(_p select 2) < 1) and !(surfaceiswater _p)) then 
		{
			_tr1= 1 - abs((_p select 2)/1.5);
			_tr2=_tr1/(3);
			_i=0;
			_no=13 + random 4;
			
			
			while {_i<_no} do 
			{
			drop [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0], "", "Billboard", 1, 1.5 + random 0.5, 
			[_p select 0, _p select 1, 0], [((_vec select 0) -2 +(random 4))*1.4, ((_vec select 1) -2 +(random 4))*1.4, 0], 0, 
			0.104, 0.08, 0.1, [0.2 + random 0.2,1.5 +random 1],[[0.6, 0.5, 0.4, _tr1], [0.6, 0.5, 0.4, _tr2], 
			[0.6, 0.5, 0.4, 0]], [1000], 1, 0, "", "", ""];
			_i=_i + 1;
			};
		};