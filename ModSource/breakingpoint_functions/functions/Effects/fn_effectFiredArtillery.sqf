private ["_u", "_sh","_i","_no","_int","_li","_pos1","_pos2","_devPos1","_devCoef","_devPos"];
_u = _this select 0;
_sh = nearestobject [_u, _this select 4];
_pos1 = getPos _sh;

//Light
[_sh] spawn {
	sleep 0.02;
	_sh = _this select 0;
	_li = "#lightpoint" createVehicleLocal getpos _sh;
	_li setLightBrightness 0.8;
	_li setLightAmbient[0.8, 0.6, 0.6];
	_li setLightColor[0.8, 0.6, 0.6];
	_li setLightAttenuation [0,1,0,5];
	_li lightAttachObject [_sh, [0,0,0]];
	
	sleep 0.15;
	deleteVehicle _li;
};

[_sh,_pos1] spawn {
	_sh = _this select 0;
	_pos1 = _this select 1;
	sleep 0.02;
	_pos2 = getPos _sh;
	_devPos1 = [((_pos2 select 0) - (_pos1 select 0)),((_pos2 select 1) - (_pos1 select 1)),((_pos2 select 2) - (_pos1 select 2))];
	_devCoef = 1/(_pos1 distance _pos2);
	_devPos = [(_devPos1 select 0) * _devCoef,(_devPos1 select 1) * _devCoef,(_devPos1 select 2) * _devCoef];

	//Flash
	/*[_pos1,_devPos] spawn {
		_pos1 = _this select 0;
		_devPos = _this select 1;
		_i=1;
		_no=5+random 2;
		while {_i<_no} do {
			drop [["\A3\data_f\ParticleEffects\Universal\Universal",16,2,32],
			"", "Billboard", 1,(0.08 + 0.01*_i), 
			[0 + random 0.5, 2 + random 0.5, 0 + random 0.5], 
			[-5 + random 10, (_i*8) - 5 + random 10, -5 + random 10], 
			0, 10, 7.9, 0.075, 
			[1.5, _i*1.2], 
			[[1, 1, 1, -1.5],[1, 1, 1, -1.5], [1, 1, 1, -0.5], [1, 1, 1, -0]], 
			[3 + random 2], 1, 0, "", "", ""];
			
			_i=_i+1;
		}
	};*/

	//Smoke
	[_pos1,_devPos] spawn {
		_posX = _this select 0;
		_devPos = _this select 1;
		
		_posX1 = _posX select 0;
		_posX2 = _posX select 1;
		_posX3 = _posX select 2;
		_devPos1 = _devPos select 0;
		_devPos2 = _devPos select 1;
		_devPos3 = _devPos select 2;
		
		_arg1 = 3.2;
		_arg2 = 2.4;
		_varArg = 4;
				
		_pos1 = [_posX1 + (_devPos1 * _arg1),_posX2 + (_devPos2 * _arg1),_posX3 + (_devPos3 * _arg1)];
		_pos2 = [_posX1 + (_devPos1 * _arg2) - _devPos2,_posX2 + (_devPos2 * _arg2) + _devPos1,_posX3 + (_devPos3 * _arg2)];
		
		_coef = 8/(_pos1 distance _pos2);
		_var1_1 = _devPos1 * _varArg;
		_var1_2 = _devPos2 * _varArg;
		_var1_3 = _devPos3 * _varArg;
		_var2_1 = _devPos1 * _coef;
		_var2_2 = _devPos2 * _coef;
		_var2_3 = _devPos3 * _coef;
		
		_pos2 = [_posX1 + (_devPos1 * _arg2) - _var2_2,_posX2 + (_devPos2 * _arg2) + _var2_1,_posX3 + (_devPos3 * _arg2)];
		_pos3 = [_posX1 + (_devPos1 * _arg2) + _var2_2,_posX2 + (_devPos2 * _arg2) - _var2_1,_posX3 + (_devPos3 * _arg2)];
		
		[_var1_1,_var1_2,_var1_3,_pos1] spawn {
			_var1_1 = _this select 0;
			_var1_2 = _this select 1;
			_var1_3 = _this select 2;
			_pos1 = _this select 3;
			_i=1;
			_no=50+random 10;
			//center
			while {_i<_no} do {
				_r = random 1;
				_r1 = random 1;
				_r2 = random 1;
				_h = 4;
				_var1r = _r * _var1_1;
				_var2r = _r * _var1_2;
				_var3r = _r * _var1_3;
				drop [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 1],
				"", "Billboard", 1, 4+random 1,
				[(_pos1 select 0) + (_var1_1/10) - 1.5 + random 2, (_pos1 select 1) + (_var1_2/10) - 1.5 + random 2, (_pos1 select 2) + (_var1_3/10) - 1.5 + random 2],		//pos
				[(-1 + random 2)*_h,(-1 + random 2)*_h,(-1 + random 2)*_h],
				-8 + random 16, 1.276, 1, 0.8, 
				[2.5 + (_r2 * 1.2),6 + (_r2 * 2.4),10 + (_r2 * 6)],
				[[0.6,0.6,0.6,0.16],[0.6,0.6,0.6,0.11],[0.6,0.6,0.6,0.07],[0.6,0.6,0.6,0.04],[0.6,0.6,0.6,0.02], [0.6,0.6,0.6,0.01]],
				[2,0.7,0.5],0.1,0.5,"","",""];
				_i=_i+1;
			};
		};
		
		[_var1_1,_var1_2,_var1_3,_pos1] spawn {
			_var1_1 = _this select 0;
			_var1_2 = _this select 1;
			_var1_3 = _this select 2;
			_pos1 = _this select 3;
			_i=1;
			_no=50+random 10;
			//top
			while {_i<_no} do {
				_r = random 1;
				_r1 = random 1;
				_r2 = random 1;
				_var1r = _r * _var1_1;
				_var2r = _r * _var1_2;
				_var3r = _r * _var1_3;
				drop [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 1],
				"", "Billboard", 1, 4+random 1,
				[(_pos1 select 0) + (-_var1_1/2 + _var1r), (_pos1 select 1) + (-_var1_2/2 + _var2r), (_pos1 select 2) + (-_var1_3/2 + _var3r)],		//pos
				[1*_var1r - 0.19 + (random 0.38),1*_var2r - 0.19 + (random 0.38),1*_var3r - 0.19 + (random 0.38)],
				-8 + random 16, 1.276, 1, 0.8, 
				[0.2 + (1 * _r) + (_r2 * 0.3),1 + (5 * _r) + (_r2 * 0.6),2 + (8 * _r) + (_r2 * 1.1)],
				[[0.6,0.6,0.6,0.16],[0.6,0.6,0.6,0.11],[0.6,0.6,0.6,0.07],[0.6,0.6,0.6,0.04],[0.6,0.6,0.6,0.02], [0.6,0.6,0.6,0.01]],
				[2,0.7,0.5],0.1,0.5,"","",""];
				_i=_i+1;
			};
		};
		[_var2_1,_var2_2,_var2_3,_pos2] spawn {
			//left
			_var2_1 = _this select 0;
			_var2_2 = _this select 1;
			_var2_3 = _this select 2;
			_pos2 = _this select 3;
			_no=70+random 10;
			_i=1;
			while {_i<_no} do {
				_r = random 1;
				_r1 = random 1;
				_r2 = random 1;
				_var1r = _r * _var2_1;
				_var2r = _r * _var2_2;
				drop [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 1],
				"", "Billboard", 1, 4+random 1,
				[(_pos2 select 0) + (_var2_2 - _var2r*2) - 0.3 + random 0.6, (_pos2 select 1) + (-_var2_1 + _var1r*2) - 0.3 + random 0.6, (_pos2 select 2) - 0.3 + random 0.6],		//pos
				[-1*_var2r - 0.25 + (random 0.5),1*_var1r - 0.25 + (random 0.5),- 0.25 + (random 0.5)],
				-16 + random 32, 1.276, 1, 0.8, 
				[0.2 + (1 * _r) + (_r2 * 1),1 + (5 * _r) + (_r2 * 3),2 + (8 * _r) + (_r2 * 5)],
				[[0.6,0.6,0.6,0.16],[0.6,0.6,0.6,0.11],[0.6,0.6,0.6,0.07],[0.6,0.6,0.6,0.04],[0.6,0.6,0.6,0.02], [0.6,0.6,0.6,0.01]],
				[2,0.7,0.5],0.1,0.5,"","",""];
				_i=_i+1;
			};
		};
		[_var2_1,_var2_2,_var2_3,_pos3] spawn {
			//right
			_var2_1 = _this select 0;
			_var2_2 = _this select 1;
			_var2_3 = _this select 2;
			_pos3 = _this select 3;
			_no=70+random 10;
			_i=1;
			while {_i<_no} do {
				_r = random 1;
				_r1 = random 1;
				_r2 = random 1;
				_var1r = _r * _var2_1;
				_var2r = _r * _var2_2;
				drop [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 1],
				"", "Billboard", 1, 4+random 1,
				[(_pos3 select 0) + (-_var2_2 + _var2r*2) - 0.3 + random 0.6, (_pos3 select 1) + (_var2_1 - _var1r*2) - 0.3 + random 0.6, (_pos3 select 2) - 0.3 + random 0.6],		//pos
				[1*_var2r - 0.25 + (random 0.5),-1*_var1r - 0.25 + (random 0.5),- 0.25 + (random 0.5)],
				-16 + random 32, 1.276, 1, 0.8, 
				[0.2 + (1 * _r) + (_r2 * 1),1 + (5 * _r) + (_r2 * 3),2 + (8 * _r) + (_r2 * 5)],
				[[0.6,0.6,0.6,0.16],[0.6,0.6,0.6,0.11],[0.6,0.6,0.6,0.07],[0.6,0.6,0.6,0.04],[0.6,0.6,0.6,0.02], [0.6,0.6,0.6,0.01]],
				[2,0.7,0.5],0.1,0.5,"","",""];
				_i=_i+1;
			}
		}
	}
};
	
//Dust
_null = [_u] execVM "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\cannondust.sqf";
// ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
// [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
