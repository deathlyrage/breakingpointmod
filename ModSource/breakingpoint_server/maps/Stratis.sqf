
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

_additions = ["Airfield","Marina","Tempest","LZConnor"];
{ call compile preprocessFileLineNumbers format ["\breakingpoint_server\maps\Stratis\%1.sqf",_x]; } count _additions;