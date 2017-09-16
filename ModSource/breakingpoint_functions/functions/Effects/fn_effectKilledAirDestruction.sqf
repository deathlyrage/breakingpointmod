_v=_this select 0;
_int = (fuel _v)*(8+random 2);
_t=time;

if (isServer) then {
	//Remove weapons/ammo to prevent explosion. Script will create its own explosions (doesnt work?)
	removeallweapons _v;

	if ((_v isKindOf "Helicopter") && (getNumber (configfile >> "CfgVehicles" >> typeOf _v >> "isUav") == 1)) then {
		_h = (getPos _v) select 2;
		waitUntil {((getPos _v) select 2) < 0.3};	
		_pos = getpos _v;
		if (!surfaceiswater(_pos)) then
		{
			// smoke cloud - important in destruction of non-flying UAV (on the ground without fall)
			_source01 = "#particlesource" createVehicle _pos;
			_source01 setParticleClass "UAVCrashSmoke";
			_source01 setPos _pos;
			
			// dust cloud - important when UAV falls from the sky
			if (_h > 4) then {
				_source02 = "#particlesource" createVehicle _pos;
				_source02 setPos _pos;
				_source02 setParticleCircle [0.4, [1.2, 1.2, 0]];
				_source02 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0], "", "Billboard", 1, 10, [0, 0, 0], [0, 0, 0], 5, 1.275, 1.0, 0.15, [2,4.6],
								[[0.5,0.45,0.4,(0.04 * _h) min 0.4],[0.5,0.45,0.4,(0.024 * _h) min 0.24],[0.5,0.45,0.4,(0.014 * _h) min 0.14],[0.5,0.45,0.4,0.01]], [0,1], 0.1, 0.05, "", "", ""];
				_source02 setParticleRandom [6, [0,0,0], [0.5,0.5,0.05], 20, 0.5, [0,0,0,0], 0, 0, 0];
				_source02 setDropInterval 0.0012; 
				
				sleep 0.15;
				deleteVehicle _source02;
			} else {
				sleep 0.15;
			};

			deleteVehicle _source01;
		};
	} else {
		//don't explode under water
		if ((((getPos _v) select 2) > 1) || (!surfaceiswater(getPos _v))) then {_expl="HelicopterExploSmall" createvehicle (getpos _v);};

		waitUntil {((getPos _v) select 2) < 2};
		_pos = getpos _v;
		if (!surfaceiswater(_pos)) then
		{	
			if ((speed _v) < 50) then {
				_velz=velocity _v select 2;
				if (_velz>1) then (_v setvelocity [velocity _v select 0,velocity _v select 1,0]);
				_pos = getPos _v;
				_expl="HelicopterExploBig" createvehicle [_pos select 0,_pos select 1,(_pos select 2) + 1];		//DD: ground explosion - should stay here
				sleep 0.05;
			};
			[_v,_int,_t] call BIS_fnc_effectKilledAirDestructionStage2;
		};
	};
};