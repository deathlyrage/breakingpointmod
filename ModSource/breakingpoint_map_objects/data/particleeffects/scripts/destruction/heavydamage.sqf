// Heavy damage for creatures

private ["_damage"];
private ["_Position"];

_damage = _this select 1;	//mira poskozeni
_position = _this select 0;	//pozice mrtveho

// particlovy efekt
_BodyParts = "#particlesource" createVehicleLocal _position;
_BodyParts setParticleRandom [2, [2, 2, 0], [0, 0, 0], 0, 0.3, [0, 0, 0, 0.1], 0, 0];
_BodyParts setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 5, "BodyParts", 
				[0, 0, 5], 0, 10, 7.9, 0.075, [4,8,12,14], [[0.3, 0.3, 0.3, 1], 
				[0.45, 0.45, 0.45, 1],[0.6, 0.6, 0.6, 0.6], [0.7, 0.7, 0.7, 0.25], [1, 1, 1, 0]], [0.8,0.3,0.25], 1, 0, "", "", ""];
_BodyParts setDropInterval 0.01;
sleep 0.1;
deleteVehicle _BodyParts;