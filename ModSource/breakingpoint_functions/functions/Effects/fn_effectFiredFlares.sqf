/*ArmA 2 flares, by Maddmatt
*/
private ["_v", "_vec","_flares","_emmiters","_launcherCount","_vel","_i","_relPos","_dirPos","_div","_flarelevel","_vvel","_muzzzLevel","_flare","_sm","_sp","_li"];
_v=_this select 0;
_vec = vectordir _v;
_flares=[];
_emmiters=[];
_launchercount=0;

//_muzzzlevel=150; 

_muzzzlevel=GetNumber (configFile >> "CfgVehicles" >> typeof _v >> "flareVelocity");

_min = ((boundingbox _v) select 0) select 2;
;
//Count up memory points
_launchercount=0;
while {([0,0,0] distance (_v selectionposition (format ["flare_launcher%1",_launchercount+1]))) != 0} 
do
{
	_launchercount=_launchercount+1;
};


_vel=velocity _v;

for "_i" from 1 to (_launchercount) do
{
_relpos=_v modeltoworld (_v selectionposition format["flare_launcher%1",_i]);
_dirpos=_v modeltoworld (_v selectionposition format["flare_launcher%1_dir",_i]);


_flare="FlareCountermeasure" createvehiclelocal _relpos;

_dirpos=[(_dirpos select 0) - (_relpos select 0),(_dirpos select 1) - (_relpos select 1),(_dirpos select 2) - (_relpos select 2)];

//Calculate vehocity to launch flare at
_div=abs(_dirpos select 0)+abs(_dirpos select 1)+abs(_dirpos select 2);
_flarevel=[(_dirpos select 0)/_div*_muzzzlevel,(_dirpos select 1)/_div*_muzzzlevel,(_dirpos select 2)/_div*_muzzzlevel];
_vvel=velocity _v;


_flare setvelocity [(_flarevel select 0) + (_vvel select 0),(_flarevel select 1) + (_vvel select 1),(_flarevel select 2) + (_vvel select 2)];
hint format ["%1",_flarevel];
_flares=_flares+[_flare];

_sm = "#particlesource" createVehicleLocal getpos _flare;
_sm setParticleRandom [0.5, [0.3, 0.3, 0.3], [0.5, 0.5, 0.5], 0, 0.3, [0, 0, 0, 0], 0, 0,360];
_sm setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
		"", "Billboard", 1, 3, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [1.3,4],
		[[0.9,0.9,0.9,0.6], [1,1,1,0.3], [1,1,1,0]],[1],0.1,0.1,"","",_flare];	
_sm setdropinterval 0.02;

_sp = "#particlesource" createVehicleLocal getpos _flare;
_sp setParticleRandom [0.03, [0.3, 0.3, 0.3], [1, 1, 1], 0, 0.2, [0, 0, 0, 0], 0, 0,360];
_sp setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 13, 2,0],
		"", "Billboard", 1, 0.1, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [1.5,0],
		[[1,1,1,-4], [1,1,1,-4], [1,1,1,-2],[1,1,1,0]],[1000],0.1,0.1,"","",_flare,360];	
_sp setdropinterval 0.001;

_li = "#lightpoint" createVehicleLocal getpos _flare;
_li setLightBrightness 0.1;
_li setLightAmbient[0.8, 0.6, 0.2];
_li setLightColor[1, 0.5, 0.2];
_li lightAttachObject [_flare, [0,0,0]];

_emmiters=_emmiters+[_sm,_sp,_li];

};

(_emmiters + _flares) spawn 
{
	sleep 4.5 + random 1;
	{deletevehicle _x} count _this;
};	
