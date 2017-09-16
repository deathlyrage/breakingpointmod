/*
_amm=_this select 4;
_sh=_this select 5;

_trail=GetNumber (configFile >> "CfgAmmo" >> _amm >> "smokeTrail");
_delay=GetNumber (configFile >> "CfgAmmo" >> _amm >> "initTime");
_time=GetNumber (configFile >> "CfgAmmo" >> _amm >> "thrustTime");

sleep _delay;

_tr = "#particlesource" createVehicleLocal getpos _sh;
switch (_trail) do
{
	//Grey trail
	case 1: 
	{
	_tr setParticleRandom [1, [0.3, 0.3, 0.3], [1, 1, 1], 0, 0.4, [0, 0, 0, 0], 0, 0];
	_col = [[0.3,0.3,0.3,0.35],[0.4,0.4,0.4,0.1],[0.8,0.8,0.8,0]];
	_tr setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
			"", "Billboard", 1, 1.6, [0, 0, 0],
			[0,0,0], 1, 1, 0.80, 0.5, [1,3.5,4.5],_col,[1],0.1,0.1,"","",_sh,random 360];
	_tr setDropInterval 0.002;	
	};
	//Very short faint trail
	case 2: 
	{
	_tr setParticleRandom [0, [0.3, 0.3, 0.3], [3, 3, 3], 0, 0.2, [0, 0, 0, 0], 0, 0];
	_col = [[0.4,0.4,0.4,0.07], [0.6,0.6,0.6,0]];
	_tr setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
			"", "Billboard", 1, 0.2, [0, 0, 0],
			[0,0,0], 1, 1, 0.80, 0.5, [1,2],_col,[5],0.1,0.1,"","",_sh,random 360];	
	_tr setdropinterval 0.003;
	};
	//Thick White trail
	case 3: 
	{
	_tr setParticleRandom [0.5, [0.3, 0.3, 0.3], [0.4, 0.4, 0.4], 0, 0.3, [0, 0, 0, 0], 0, 0];
	_col = [[0.8,0.8,0.8,0.6], [0.9,0.9,0.9,0.3], [1,1,1,0]];
	_tr setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
			"", "Billboard", 1, 2, [0, 0, 0],
			[0,0,0], 1, 1, 0.80, 0.5, [2.5,3.5,4],_col,[1],0.1,0.1,"","",_sh,random 360];	
	_tr setdropinterval 0.002;
	};
	//Thinner White trail
	case 4: 
	{
	_tr setParticleRandom [0.3, [0.3, 0.3, 0.3], [0.4, 0.4, 0.4], 0, 0.2, [0, 0, 0, 0], 0, 0];
	_col = [[0.8,0.8,0.8,0.25], [1,1,1,0]];
	_tr setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
			"", "Billboard", 1, 1.5, [0, 0, 0],
			[0,0,0], 1, 1, 0.80, 0.5, [1.5,3],_col,[1],0.1,0.1,"","",_sh,random 360];	
	_tr setdropinterval 0.003;
	};
	//Rocket artillery
	case 5: 
	{
	_tr setParticleRandom [3, [0.3, 0.3, 0.3], [0.4, 0.4, 0.4], 0, 0.5, [0, 0, 0, 0], 0, 0];
	_col = [[0.8,0.8,0.8,0.8], [0.9,0.9,0.9,0.4], [1,1,1,0]];
	_tr setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
			"", "Billboard", 1, 7, [0, 0, 0],
			[0,0,0], 1, 1, 0.80, 0.5, [3,9],_col,[1],0.1,0.1,"","",_sh,random 360];	
	_tr setdropinterval 0.004;
	};
};
sleep _time;
deletevehicle _tr;

*/