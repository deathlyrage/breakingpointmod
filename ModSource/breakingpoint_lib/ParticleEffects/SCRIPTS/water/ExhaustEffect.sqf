_pos = _this;
_depth = _this select 2;

if (_depth > -0.3) then {

	_source01 = "#particlesource" createVehicleLocal _pos;
	_source01 setParticleClass "ExhaustWaterEffect1";
	
	_source02 = "#particlesource" createVehicleLocal _pos;
	_source02 setParticleClass "ExhaustSmokeOnWater1";
	
	sleep 0.012;
	deleteVehicle _source01;
	
};
