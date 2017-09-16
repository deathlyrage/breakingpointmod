_pos = _this;
_pos1 = [_this select 0,_this select 1,(_this select 2) + 0.1];
_depth = _this select 2;

[_pos,_pos1,_depth] spawn {
	if ((_this select 2) > -0.3 && (random 1 > 0.95)) then {
		_source01 = "#particlesource" createVehicleLocal (_this select 1);
		_source01 setParticleClass "ExhaustWaterEffect1";		
		sleep 0.01;
		deleteVehicle _source01;
	};
};

[_pos,_pos1,_depth] spawn {
	if ((_this select 2) > -0.3 && (random 1 > 0.97)) then {
		_source02 = "#particlesource" createVehicleLocal (_this select 1);
		_source02 setParticleClass "ExhaustSmokeBigOnWater1";
		sleep 0.01;
		deleteVehicle _source02;
	};
};