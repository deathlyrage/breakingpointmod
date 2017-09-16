if (not(isNil("source01"))) then {
deleteVehicle source01;
};

if (not(isNil("source02"))) then {
deleteVehicle source02;
};

sleep 0.5;

	_pos01 = position effect01;
	source01 = "#particlesource" createVehicleLocal _pos01; 
	source01 attachTo [effect01,[0,0,0]]; 
	source01 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,14,1], "", "Billboard", 0, 0.8, [0,0,-0.5], [0,10,2.5], 80, 2.5, 1,
	0.4, [0.08], [[0.5,0.5,0.5,1],[0.5,0.5,0.5,1],[0.5,0.5,0.5,1]], [0], 0.2, 0.3, "", "", ""];
	source01 setDropInterval 0.6;
	
	sleep 0.2;
	
	_pos02 = position effect02;
	source02 = "#particlesource" createVehicleLocal _pos02; 
	source02 attachTo [effect02,[0,0,0]]; 
	source02 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,15,1], "", "Billboard", 0, 0.8, [0,0,-0.5], [0,10,2.5], 70, 2.5, 1,
	0.4, [0.08], [[0.5,0.5,0.5,1],[0.5,0.5,0.5,1],[0.5,0.5,0.5,1]], [0], 0.2, 0.3, "", "", ""];
	source02 setDropInterval 0.7;
	

 // ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
 // [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
