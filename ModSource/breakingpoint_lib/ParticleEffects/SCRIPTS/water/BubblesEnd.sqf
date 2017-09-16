_pos = _this;
_depth = _this select 2;

if (_depth < -0.1) then {
	_source01 = "#particlesource" createVehicleLocal _pos;
	_source01 setParticleClass "BubblesSecondary";
	sleep 0.012;
	deleteVehicle _source01;
};
