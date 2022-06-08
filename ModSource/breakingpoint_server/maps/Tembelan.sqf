_worldObjects = 
[
	//Soda Machines
	["BP_SodaMachine",233,[4709.76,2758.57,0],true],
	["BP_SodaMachine",112,[7487.64,4576.27,0],true],
	["BP_SodaMachine",323,[2318.16,7946.73,0],true],
	["BP_SodaMachine",246,[4559.33,6949.83,0],true],
	["BP_SodaMachine",307,[3348.43,3693.19,0],true]
];
{
	_x params ["_classname","_dir","_posATL","_random"];
	_obj = createVehicle [_classname, _posATL, [], 0, "CAN_COLLIDE"];
	_obj setDir _dir;
	_obj setPosATL _posATL;
	_obj enableDynamicSimulation true;
} count _worldObjects;

private ["_objs"];
_objs = [
];
{
	private ["_obj"];
	_obj = createVehicle [_x select 0, [0,0,0], [], 0, "CAN_COLLIDE"];
	if (_x select 4) then {
		_obj setDir (_x select 2);
		_obj setPos (_x select 1);
	} else {
		_obj setPosATL (_x select 1);
		_obj setVectorDirAndUp (_x select 3);
	};
	_obj enableDynamicSimulation true;
} count _objs;
_additions = ["Tembelan1","Tembelan2"];
{ call compile preprocessFileLineNumbers format ["\breakingpoint_server\maps\Tembelan\%1.sqf",_x]; } count _additions;