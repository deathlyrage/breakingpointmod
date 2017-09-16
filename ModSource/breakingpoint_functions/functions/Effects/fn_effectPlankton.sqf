/*
	File: fn_effectPlankton.sqf
	Author: Borivoj Hlava

	Description:
	Plankton particle effect. Function must be started for any plankton in the water.

	Parameter(s):
	None.

	Returned value:
	None.
*/

_null = [] spawn {
	private ["_vehArray","_pos","_vehicle","_plankton","_oldVehicle","_vehPos","_x","_defVeh"];
	
	// definition of emitter pos for different vehicles (no plankton for other vehicles) - [["vehicle_class",position],["vehicle_class",position],...]
	_vehArray = [["SDV_01_base_F",[0,3,0]]];

	// position definition
	_pos = [0,0,0];
	_vehicle = player;
	_pos = getPos _vehicle;

	// emitter creation
	_plankton = "#particlesource" createVehicleLocal _pos;
	_plankton setParticleClass "PlanktonEffect";
	_plankton attachto [player,[0,2,0]];
	
	BIS_debug_plankton = _plankton; 	// debug
	
	// check if player is in the vehicle
	while {alive player} do {
		if (surfaceIsWater (getPos player)) then {
			_oldVehicle = _vehicle;
			_vehicle = vehicle player;
		
			if (_oldVehicle != _vehicle) then {
				if (_vehicle == player) then {
					_plankton attachto [player,[0,2,0]]				
				} else {
					_vehPos = [0,0,0];
					_defVeh = false;
					{
						if (_vehicle isKindOf (_x select 0)) then {
							_vehPos = _x select 1;
							_defVeh = true;
						};
					} forEach _vehArray;
					
					if (_defVeh) then {
						_plankton attachto [_vehicle,_vehPos];
					} else {
						_plankton attachto [player,[0,2,0]];
					};
				};
			};
			sleep 0.9;
		} else {
			sleep 2.5;
		};
	};
};