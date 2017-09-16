//Don't Do Particles on Dedicated Servers
if (isDedicated) exitWith {};

_object = _this;
_object setVariable ["effects",[]];
_pos01 = getPos _object;

_source01 = "#particlesource" createVehicleLocal _pos01;
_source01 setParticleClass "MediumDestructionFire";
_source01 attachto [_object,[0,0,0]];

_source02 = "#particlesource" createVehicleLocal _pos01;
_source02 setParticleClass "MediumDestructionSmoke";
_source02 attachto [_object,[0,0,0]];

_li = "#lightpoint" createVehicleLocal _pos01;
_li setLightBrightness 0.08;
_li setLightAmbient [1,0.28,0.05];
_li setLightColor [1,0.28,0.05];
_li lightAttachObject [_object, [0,0,0]];


_object setVariable ["effects",[_source01,_source02,_li]];