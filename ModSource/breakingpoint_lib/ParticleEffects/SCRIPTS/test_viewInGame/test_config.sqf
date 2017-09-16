if (not(isNil("source01"))) then {
deleteVehicle source01;
};
sleep 0.5;

	_pos01 = position effect01;
	source01 = "#particlesource" createVehicleLocal _pos01; 
	source01 attachTo [effect01,[0,0,0]]; 
	source01 setParticleClass "effectClass";
