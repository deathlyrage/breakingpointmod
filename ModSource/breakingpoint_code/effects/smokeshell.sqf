//Don't Do Particles on Dedicated Servers
if (isDedicated) exitWith {};

private ["_object","_pos01","_source02","_source05","_li"];
_object = _this;
_object setVariable ["effects",[]];
_pos01 = getPos _object;

_col = [1,1,1];
_c1 = _col select 0;
_c2 = _col select 1;
_c3 = _col select 2;

_source02 = "#particlesource" createVehicleLocal _pos01;
_source02 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 20, [0, 0, 0],
				[0.2, 0.1, 0.1], 0, 1.277, 1, 0.025, [0.1, 2, 6], [[_c1, _c2, _c3, 0.2], [_c1, _c2, _c3, 0.05], [_c1, _c2, _c3, 0]],
				[1.5,0.5], 1, 0.04, "", "", _object];
_source02 setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
_source02 setDropInterval 0.03;

_source05 = "#particlesource" createVehicleLocal _pos01;
_source05 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0], "", "Billboard", 1, 20, [0, 0, 0],
				[0.2, 0.1, 0.1], 0, 1.277, 1, 0.025, [0.1, 2, 6], [[_c1, _c2, _c3, 1], [_c1, _c2, _c3, 0.5], [_c1, _c2, _c3, 0]],
				[0.2], 1, 0.04, "", "", _object];
_source05 setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.2], 0, 0, 360];
_source05 setDropInterval 0.03;

_li = "#lightpoint" createVehicleLocal _pos01;
_li setLightBrightness 0.08;
_li setLightAmbient [1,0.28,0.05];
_li setLightColor [1,0.28,0.05];
_li lightAttachObject [_object, [0,0,0]];

_object setVariable ["effects",[_source02,_source05,_li]];