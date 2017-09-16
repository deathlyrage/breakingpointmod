/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Thirsk Snow Viewdistance
setViewDistance 50;

[] spawn
{
	while {true} do
	{
		_ran = ceil random 5;
		_obj = vehicle player;
		_pos = position _obj;

		_velocity = [random 10,random 10,-1];
		_color = [1.0, 0.9, 0.8];
		_alpha = 0.02 + random 0.02;
		_ps = "#particlesource" createVehicleLocal _pos;
		_ps setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8,0], "", "Billboard", 1, 7, [0, 0, -6], _velocity, 1, 1.275, 1, 0, [9], [_color + [0], _color + [_alpha], _color + [0]], [1000], 1, 0, "", "", _obj];
		_ps setParticleRandom [3, [30, 30, 0], [0, 0, 0], 1, 0, [0, 0, 0, 0.01], 0, 0];
		_ps setParticleCircle [0.1, [0, 0, 0]];
		_ps setDropInterval 0.01;

		sleep (random 0.4);
		deletevehicle _ps;
		_delay = 10 + random 20;
		sleep _delay;
	};
};