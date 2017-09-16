if (not(isNil("source01"))) then {
deleteVehicle source01;
};

sleep 0.5;

_pos = position effect01;   
source01 = "#particlesource" createVehicleLocal _pos; 
source01 attachTo [effect01,[0,0,0]]; 
source01 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",8,0,64], "", "Billboard", 0.5, 2, [0,0,0], [0,0,0], 0, 1.275, 1,
0, [1], [[0.5,0.5,0.5,1]], [0,1], 0, 0, "", "", ""];
source01 setDropInterval 4;

 // ["JmenoModelu"],"NazevAnimace","TypAnimace",RychlostAnimace,DobaZivota,[Pozice],[SilaPohybu],Rotace,Hmotnost,Objem,Rubbing,[Velikost],[Barva],
 // [FazeAnimace],PeriodaNahodnehoSmeru,IntensitaNahodnehoSmeru,"OnTimer","PredZnicenim","Objekt";
