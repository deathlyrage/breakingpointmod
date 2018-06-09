/*ArmA 2 smokscreen, by Maddmatt
Uses code from VBS2 Smoke launcher by Philipp Pilhofer (raedor) & Andrew Barron
*/
private ["_v","_shells","_num","_vel","_useTDir","_angle","_dir","_deltaDir","_arc","_initDist","_posV","_Vdir","_vH","_vV","_smokeg"];
_v=_this select 0;
_shells=[];


//Read values from config

_num=GetNumber (configFile >> "CfgVehicles" >> typeof _v >> "smokeLauncherGrenadeCount");
_vel=GetNumber (configFile >> "CfgVehicles" >> typeof _v >> "smokeLauncherVelocity");
_useTDir=GetNumber (configFile >> "CfgVehicles" >> typeof _v >> "smokeLauncherOnTurret");
_angle=GetNumber (configFile >> "CfgVehicles" >> typeof _v >> "smokeLauncherAngle");

if (_num>0) then
{
	_dir = direction _v;
	if ((_useTDir==1) && (count weapons _v > 0)) then
	{
		_dir = _v weaponDirection ((weapons _v) select 0);
		_dir = (((_dir select 0) atan2 (_dir select 1))+360)%360;
	};

	_deltaDir = _angle/_num;			//degrees between grenades.
	_arc = _deltaDir*(_num-1);		//total arc to cover, in degrees

	//distance from vehicle center where grenades are created; base it on vertical height
	_initDist = (((boundingBox _v) select 1) select 2)-(((boundingBox _v) select 0) select 2);

	//sleep 0.25;
	_posV = getpos _v;
	_Vdir = 30;	                     //angle of elevation. Temporary: launch all grenades at same angle
	//derive velocity
	_vH = _vel * cos _Vdir;          //horizontal component of velocity
	_vV = _vel * sin _Vdir;          //vertical component


	for "_i" from 0 to (_num - 1) do
	{
		//find starting parameters
		_Hdir = ((_i*_deltaDir)+_dir) - _arc/2; //relative direction around vehicle


		_Gvel = [_vH *sin(_Hdir), _vH*cos (_Hdir), _vV]; //initial grenade velocity

		//find starting position for grenades
		_pH = _initDist * cos _Vdir;     //initial distance horizontally away from vehicle center to create grenade
		_pV = _initDist * sin _Vdir;     //vertical distance

		//create / launch the grenade
		_smokeg="SmokeShellVehicle_boat" createvehiclelocal ([(_pH * sin _Hdir) + (_posV select 0), (_pH * cos _Hdir)+ (_posV select 1), _pV+ (_posV select 2)]);
		_smokeg setVelocity _Gvel;
		_smokeg setVectorDir _Gvel;
		_shells=_shells+[_smokeg];
	};

	{
		[_x] spawn
		{
			_sh=_this select 0;

			sleep 0.7;
			_source2 = "#particlesource" createVehicleLocal getpos _sh;
			_source2 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1], "", "Billboard", 1, 10, [0, 0, 0],
						[0, 0, 0.5], 0, 1.277, 1, 0.025, [0.5, 8, 12, 15], [[1, 1, 1, 0.7],[1, 1, 1, 0.5], [1, 1, 1, 0.25], [1, 1, 1, 0]],
						[0.2], 1, 0.04, "", "", _sh];
			_source2 setParticleRandom [2, [0.3, 0.3, 0.3], [1.5, 1.5, 1], 20, 0.2, [0, 0, 0, 0.1], 0, 0, 360];
			_source2 setDropInterval 0.2;

			_source3 = "#particlesource" createVehicleLocal getpos _sh;
			_source3 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 7, 0], "", "Billboard", 1, 5, [0, 0, 0],
						[0, 0, 0.5], 0, 1.277, 1, 0.025, [0.5, 8, 12, 15], [[1, 1, 1, 1],[1, 1, 1, 1], [1, 1, 1, 0.5], [1, 1, 1, 0]],
						[0.2], 1, 0.04, "", "", _sh];
			_source3 setParticleRandom [2, [0.3, 0.3, 0.3], [1.5, 1.5, 1], 20, 0.2, [0, 0, 0, 0.1], 0, 0, 360];
			_source3 setDropInterval 0.15;

			sleep (55+random 3);
			deletevehicle _source2;
			deletevehicle _source3;
		};
	} foreach _shells;
};