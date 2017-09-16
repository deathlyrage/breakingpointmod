//Don't Do Particles on Dedicated Servers
if (isDedicated) exitWith {};

_object = _this;
_object setVariable ["effects",[]];
_pos01 = getPos _object;

_source02 = "#particlesource" createVehicleLocal _pos01;
_source02 setParticleClass "ObjectDestructionSmokeSmallx";
_source02 attachto [_object,[0,0,0]];

_source05 = "#particlesource" createVehicleLocal _pos01;
_source05 setParticleClass "ObjectDestructionSmoke1_2Smallx";
_source05 attachto [_object,[0,0,0]];

_li = "#lightpoint" createVehicleLocal _pos01;
_li setLightBrightness 0.08;
_li setLightAmbient [1,0.28,0.05];
_li setLightColor [1,0.28,0.05];
_li lightAttachObject [_object, [0,0,0]];

_object setVariable ["effects",[_source02,_source05,_li]];