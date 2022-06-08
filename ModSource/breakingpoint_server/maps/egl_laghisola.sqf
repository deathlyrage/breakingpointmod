_worldObjects = 
[
	//Soda Machines
	["BP_SodaMachine",249.599,[258.304,581.001,0],true],
	["BP_SodaMachine",235.520,[1362.42,8885.03,0.277551],true],
	["BP_SodaMachine",180.722,[1939.58,5758.86,0],true],
	["BP_SodaMachine",180.360,[4897.99,6330.22,4.73468],true],
	["BP_SodaMachine",269.954,[6619.93,2316.66,0.602991],true],
	["Land_BarrelWater_F",0,[8836.85,764.296,0],false],
	["Land_BarrelWater_F",0,[9834.46,6163.85,0],false],
	["Land_BarrelWater_F",0,[6506.01,9669.89,0],false],
	["Land_BarrelWater_F",0,[3908.77,3887.82,4.76837e-007],false]
];
{
	_x params ["_classname","_dir","_posATL","_random"];
	_obj = createVehicle [_classname, _posATL, [], 0, "CAN_COLLIDE"];
	_obj setDir _dir;
	_obj setPosATL _posATL;
	_obj enableDynamicSimulation true;
} count _worldObjects;