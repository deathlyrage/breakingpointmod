if (not(isNil("source01"))) then {
deleteVehicle source01;
};
sleep 0.5;

	_pos01 = position effect01;
	source01 = "#particlesource" createVehicleLocal _pos01; 
	source01 attachTo [effect01,[0,0,0]]; 
	source01 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,15,1], "", "Billboard", 10, 5, [0,0,0], [0,0,0.2], 0, 0.12, 0.1,
	0, [0.06], [[0.5,0.5,0.5,1],[0.5,0.5,0.5,1],[0.5,0.5,0.5,1]], [0,1], 0.2, 0.02, "", "", ""];
	source01 setDropInterval 0.08;	

 // ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
 // [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
