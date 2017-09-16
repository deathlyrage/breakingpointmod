
//Don't Do Particles on Dedicated Servers
if (isDedicated) exitWith {};

_object = _this;
_object setVariable ["effects",[]];
_pos01 = getPos _object;

_source01 = "#particlesource" createVehicleLocal _pos01;
_source01 setParticleClass "ObjectDestructionFire1Smallx";
_source01 attachto [_object,[0,0,0]];

_source02 = "#particlesource" createVehicleLocal _pos01;
_source02 setParticleClass "ObjectDestructionSmokeSmallx";
_source02 attachto [_object,[0,0,0]];

_source03 = "#particlesource" createVehicleLocal _pos01;
_source03 setParticleClass "FireSparks";
_source03 attachto [_object,[0,0,0]];

_source04 = "#particlesource" createVehicleLocal _pos01;
_source04 setParticleClass "ObjectDestructionFire2Smallx";
_source04 attachto [_object,[0,0,0]];

_source05 = "#particlesource" createVehicleLocal _pos01;
_source05 setParticleClass "ObjectDestructionSmoke1_2Smallx";
_source05 attachto [_object,[0,0,0]];

_source06 = "#particlesource" createVehicleLocal _pos01;
_source06 setParticleClass "ObjectDestructionSmoke2x";
_source06 attachto [_object,[0,0,0]];

_li = "#lightpoint" createVehicleLocal _pos01;
_li setLightBrightness 0.08;
_li setLightAmbient [1,0.28,0.05];
_li setLightColor [1,0.28,0.05];
_li lightAttachObject [_object, [0,0,0]];

_object setVariable ["effects",[_source01,_source02,_source03,_source04,_source05,_source06,_li]];