private ["_sh","_p","_tr1","_tr2","_vec","_i","_int"];

if (count _this > 6) then
{
	_sh = _this select 6;
}
else
{
	_sh = nearestobject [_this select 0, _this select 4];
};

_col=GetArray (configFile >> "CfgAmmo" >> _amm >> "smokeColor");


[_sh,_col] spawn
	{
	_sh=_this select 0;
	_col=_this select 1;
	_c1=_col select 0;
	_c2=_col select 1;
	_c3=_col select 2;

	sleep (3+random 1);
	_source = "#particlesource" createVehicleLocal getpos _sh;
	_source setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 20, [0, 0, 0],
					[0.2, 0.1, 0.1], 0, 1.277, 1, 0.025, [0.1, 2, 6], [[_c1, _c2, _c3, 0.2], [_c1, _c2, _c3, 0.05], [_c1, _c2, _c3, 0]],
					 [1.5,0.5], 1, 0.04, "", "", _sh];
	_source setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
	_source setDropInterval 0.03;

	_source2 = "#particlesource" createVehicleLocal getpos _sh;
	_source2 setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8, 0], "", "Billboard", 1, 20, [0, 0, 0],
					[0.2, 0.1, 0.1], 0, 1.277, 1, 0.025, [0.1, 2, 6], [[_c1, _c2, _c3, 1], [_c1, _c2, _c3, 0.5], [_c1, _c2, _c3, 0]],
					 [0.2], 1, 0.04, "", "", _sh];
	_source2 setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.2], 0, 0, 360];
	_source2 setDropInterval 0.03;

	sleep (50+random 5);
	deletevehicle _source;deletevehicle _source2;
	};