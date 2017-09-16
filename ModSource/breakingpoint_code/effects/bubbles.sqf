
//Don't Do Particles on Dedicated Servers
if (isDedicated) exitWith {};
_object = _this;
_object setVariable ["effects",[]];

waitUntil
{
	_pos01 = getPos _object;
	_source01 = "#particlesource" createVehicleLocal _pos01;
	_source01 setParticleClass "PointBubbles1";
	_source01 attachto [_object,[0,0,0]];
	_source01s = "#particlesource" createVehicleLocal _pos01;
	_source01s setParticleClass "PointBubbles2";
	_source01s attachto [_object,[0,0,0]];
	_object setVariable ["effects",[_source01,_source01s]];
	sleep 0.25;
	deleteVehicle _source01s;

	(!alive player)
};