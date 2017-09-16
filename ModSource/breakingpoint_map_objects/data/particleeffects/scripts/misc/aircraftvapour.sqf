/*
Aircraft vapour simulation by Maddmatt 
for ArmA 2

Script will exit if memory points for wingtip vapour don't exist
*/


private ["_v","_trail1","_trail2","_lemmiters","_remmiters"];


_v=_this select 0;

sleep (0.1 + random 0.2);

//if (finite ([0,0,0] distance (_v selectionposition "cerveny pozicni"))) then 
if (([0,0,0] distance (_v selectionposition "cerveny pozicni"))!=0) then 
{
//hint "wings";
_trail1 = "#particlesource" createVehicleLocal getpos _v;
_trail1 attachto [_v,[0,0,0],"cerveny pozicni"];
_trail1 setParticleRandom [0.2, [0.05, 0.05, 0.05], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];

_trail2 = "#particlesource" createVehicleLocal getpos _v;
_trail2 attachto [_v,[0,0,0],"zeleny pozicni"];
_trail2 setParticleRandom [0.2, [0.05, 0.05, 0.05], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
};
if (isnull _trail1) exitwith {};

/*
//Temporary - until memory points are done
_body_vapour_L_S = [-1,3,0];
_body_vapour_L_E = [-5,2,0];
_body_vapour_R_S = [1,3,0];
_body_vapour_R_E = [5,2,0];
*/

//Fusalage vapour
if (([0,0,0] distance (_v selectionposition "body_vapour_L_S"))!=0) then 
{	
	_body_vapour_L_S = _v selectionposition "body_vapour_L_S";
	_body_vapour_L_E = _v selectionposition "body_vapour_L_E";
	_body_vapour_R_S = _v selectionposition "body_vapour_R_S";
	_body_vapour_R_E = _v selectionposition "body_vapour_R_E";
	_lgap = _body_vapour_L_S distance _body_vapour_L_E;
	_rgap = _body_vapour_R_S distance _body_vapour_R_E;
	
	_lemmiters = [_fusv1];
	_remmiters = [_fusv2];
	
	//Left body emmiters
	_xdiff = (_body_vapour_L_E select 0)-(_body_vapour_L_S select 0);
	_ydiff = (_body_vapour_L_E select 1)-(_body_vapour_L_S select 1);
	_zdiff = (_body_vapour_L_E select 2)-(_body_vapour_L_S select 2);
	_i=0;
	while {_i<_lgap} do
		{
		_pe = "#particlesource" createVehicleLocal getpos _v;
		_pe setParticleRandom [0.2, [0.05, 0.05, 0.05], [0, 0, 0], 0, 0.2, [0, 0, 0, 0], 0, 0];
		_pe attachto [_v,[(_body_vapour_L_S select 0) +  _i*(_xdiff/_lgap),(_body_vapour_L_S select 1) + _i*(_ydiff/_lgap),(_body_vapour_L_S select 2) + _i*(_zdiff/_lgap)]];
		_lemmiters=_lemmiters+[_pe];
		_i=_i+1;
		};
		
	//Right body emmiters	
	_xdiff = (_body_vapour_R_E select 0)-(_body_vapour_R_S select 0);
	_ydiff = (_body_vapour_R_E select 1)-(_body_vapour_R_S select 1);
	_zdiff = (_body_vapour_R_E select 2)-(_body_vapour_R_S select 2);
	_i=0;
	while {_i<_rgap} do
		{
		_pe = "#particlesource" createVehicleLocal getpos _v;
		_pe setParticleRandom [0.2, [0.05, 0.05, 0.05], [0, 0, 0], 0, 0.2, [0, 0, 0, 0], 0, 0];
		_pe attachto [_v,[(_body_vapour_R_S select 0) +  _i*(_xdiff/_lgap),(_body_vapour_R_S select 1) + _i*(_ydiff/_lgap),(_body_vapour_R_S select 2) + _i*(_zdiff/_lgap)]];
		_remmiters=_remmiters+[_pe];
		_i=_i+1;
		};
};
	

//_pitchbank=_v call BIS_fnc_getPitchBank;
//_pitch=abs(_pitchbank select 0);
//_bank=abs(_pitchbank select 1);
_dir=getdir _v;

while {!(isnull _v)} do
	{

	_velocity=abs(velocity _v select 0)+abs(velocity _v select 1)+abs(velocity _v select 2);
	if (_velocity > 50) then
	{
	sleep 0.05;
	/*
	//old values
	_pitchprev=_pitch;
	//_bankprev=_bank;
	_dirprev=_dir;
	
	//new values
	_pitchbank=_v call BIS_fnc_getPitchBank;
	_pitch=abs(_pitchbank select 0);
	//_bank=abs(_pitchbank select 1);
	_dir=getdir _v;
	if (_dir > 180) then {_dir=-(360-_dir)};
	
	//Rates of change
	_pitchrate=abs(_pitch-_pitchprev)*20;
	//_bankrate=abs(_bank-_bankprev)*20;
	_dirrate=abs(_dir-_dirprev)*20;
	*/
	
	
	//Calculate angle of Attack
	_xv=velocity _v select 0;
	_yv=velocity _v select 1;
	_zv=velocity _v select 2;
	_2dvel= (_xv+_yv);

	_dirvel = abs(_xv atan2 _yv);
	_dir= getdir _v;
	if (_dir>180) then {_dir=360-_dir};
	
	_pitchvel= abs(_zv atan2 _2dvel);
	//_pitchvel= abs(atan _yv);
	//_pitch=abs(atan (vectordir _v select 2));
	_vdir=vectordir _v;
	_pitch=abs((_vdir select 2) atan2 ((_vdir select 0)+(_vdir select 1)));
	
	_aoap = abs(_pitch-_pitchvel);
	_aoad = abs(_dir-_dirvel);
	
	//The Angle of Attack
	_aoa = _aoap+_aoad;
	
	
	//Drop interval
	_interval=1/(_velocity*2.5);
	
	//Intensity
	_intensity = (_aoa)*(_velocity/4000);
	//_intensity=3;
	if (_intensity>3) then {_intensity=3};
	if (_intensity>0.3) then
		{
		//hint format ["int: %1",_intensity];
		_trail1 setdropinterval _interval;
		_trail1 setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 13, 3, 0],
		"", "Billboard", 1, 0.6*_intensity, 
		[0,0,0], velocity _v, 
		0, 1, 0.79, 0.18, 
		[0.5, 1+_intensity/1.7], 
		[[1, 1, 1, 0.04*_intensity],[1, 1, 1, 0.14*_intensity],[1, 1, 1, 0.05*_intensity], [1, 1, 1, 0]], [1000], 100, 0.01, "", "", "",360];
		
		_trail2 setdropinterval _interval;
		_trail2 setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 13, 3, 0],
		"", "Billboard", 1, 0.6*_intensity, 
		[0,0,0], velocity _v, 
		0, 1, 0.79, 0.18, 
		[0.4, 1+_intensity/1.7], 
		[[1, 1, 1, 0.04*_intensity],[1, 1, 1, 0.14*_intensity],[1, 1, 1, 0.05*_intensity], [1, 1, 1, 0]], [1000], 100, 0.01, "", "", "",360];
		
		}
	else
		{
		_trail1 setdropinterval 0;
		_trail2 setdropinterval 0;
		{_x setdropinterval 0} foreach _lemmiters;
		{_x setdropinterval 0} foreach _remmiters;

		};
		
	if ((_intensity>0.4)) then
	{
		_i=0;
		{
		
		_i=_i+1;
		_int2 = _intensity - _i/(count _lemmiters);
		if (_int2>0) then
			{
			_x setdropinterval _interval*3;
			_x setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0],
			//"", "Billboard", 1, 0.2 +_int2/(5+random 5), 
			"", "Billboard", 1, (0.2+random 0.2)*_int2, 
			[0,0,0], velocity _v, 
			0, 1, 0.79, 0.1,
			[1.5, 2+_int2/(1+random 1)],
			[[1, 1, 1, (0.15*_int2)/_i], [1, 1, 1, 0]], [1000], 0.01, 2, "", "", "",360];
			};
		} foreach _lemmiters;
		
		_i=0;
		{
		//_intensity = _intensity-0.45;
		_i=_i+1;
		_int2 = _intensity - _i/(count _remmiters);
		if (_int2>0) then
			{
			_x setdropinterval _interval*3;
			_x setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0],
			//"", "Billboard", 1, 0.2 +_int2/(5+random 5), 
			"", "Billboard", 1, (0.2+random 0.2)*_int2, 
			[0,0,0], velocity _v, 
			0, 1, 0.79, 0.1, 
			[1.5, 2+_int2/(1+random 1)], 
			[[1, 1, 1, (0.15*_int2)/_i], [1, 1, 1, 0]], [1000], 0.01, 2, "", "", "",360];
			};
		} foreach _remmiters;
	}
	else
	{
		{_x setdropinterval 0} foreach _lemmiters;
		{_x setdropinterval 0} foreach _remmiters;
	};
	
	
	/*if (player in _v) then
		{
		hint format ["aoap: %1\naoad: %2\naoa: %3", _aoap, _aoad,_aoa];
		};
		
	*/
	}
	
	else 
	{
		_trail1 setdropinterval 0;
		_trail2 setdropinterval 0;
		{_x setdropinterval 0} foreach _lemmiters;
		{_x setdropinterval 0} foreach _remmiters;
		sleep 2;
	};
	};
	
deletevehicle _trail1;
deletevehicle _trail2;
deletevehicle _fusv1;
deletevehicle _fusv2;