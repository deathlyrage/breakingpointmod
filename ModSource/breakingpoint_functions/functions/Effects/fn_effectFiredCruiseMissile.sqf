/*
	Cruise Missile Start VFX
	BIS_fnc_effectFiredCruiseMissile

	a: reyhard
*/
params["","","","","","","_missile"];


// Create particle effect & attach it to missile
private _particle = "#particlesource" createVehicleLocal [0,0,0];
_particle attachTo [_missile,[0,0,0]];

// Set particle effects parameters
_particle setParticleCircle [0, [0, 0, 0]];
_particle setParticleRandom [0, [0, 0, 0], [4, 4, 4], 53, 0.25, [0, 0, 0, 1], 2, 2];
_particle setParticleParams [["\a3\Data_f\ParticleEffects\Universal\smoke.p3d", 1, 0, 0], "", "Billboard", 1, 12.95, [0, -2, 0], [0, 0, 0], 0, 1.375, 1, 0.2, [1, 12, 16, 34], [[1, 1, 1, 0.1], [1, 1, 1, 0]], [1], 0, 0, "", "", _missile];
_particle setDropInterval 0.001;

// Spawn new loop where suspension is allowed
[_particle,_missile] spawn
{
	params["_particle","_missile"];

	// Define boot time (3 seconds)
	private _boostTime = time + 3;

	while{time < _boostTime}do
	{
		private _directionParams = linearConversion [0,3,_boostTime-time,4,7,true];
		_particle setParticleRandom [0, [0, 0, 0], [_directionParams, _directionParams, 0], 53, 0.25, [0, 0, 0, 1], 2, 2];
		sleep 0.1;
	};

	// Delete particle
	deleteVehicle _particle;
};