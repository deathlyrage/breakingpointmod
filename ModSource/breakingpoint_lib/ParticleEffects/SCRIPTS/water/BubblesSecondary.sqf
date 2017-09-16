_pos = _this;

_source01 = "#particlesource" createVehicleLocal _pos;
_source01 setParticleClass "BubblesSecondary";
sleep 0.0015;
deleteVehicle _source01;
