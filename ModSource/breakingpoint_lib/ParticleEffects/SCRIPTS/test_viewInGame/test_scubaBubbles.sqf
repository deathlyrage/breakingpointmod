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
	source01 setParticleParams ["\A3\data_f\ParticleEffects\Water\BubbleSmall", "", "Billboard", 10, 5, [0,0,0], [0,1,0], 0, 0.12, 0.1,
	0, [0.04], [[1,1,1,0.5],[1,1,1,0.5],[1,1,1,0.5]], [0,1], 0.2, 0.07, "", "", ""];
	source01 setDropInterval 0.05;
	
	_pos02 = position effect02;
	source02 = "#particlesource" createVehicleLocal _pos02; 
	source02 attachTo [effect02,[0,0,0]]; 
	source02 setParticleParams [["\A3\data_f\ParticleEffects\Water\BubbleBig",16,15,5], "", "Billboard", 10, 1.8, [0,0,0], [0,1,0], 0, 0.12, 0.1,
	0, [0.14], [[1,1,1,0.5],[1,1,1,0.5],[1,1,1,0.5]], [0,1], 0.2, 0.07, "", "", ""];
	source02 setDropInterval 0.1;
	

 // ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
 // [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
