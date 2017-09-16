/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_dynamicVeh";

_numVehicles = _this select 0;

//Vehicles
_worldName = worldName;
_vehicleConfig = (configFile >> "CfgVehicleSpawns");
_vehicleConfigTypes = (_vehicleConfig >> "Types");
_maxVehicles = getNumber (_vehicleConfig >> "numVehicles");
if (_worldName == "thirskw") then { _worldName == "thirsk"; };

["Attempting to Spawn in Vehicles For %1. Current: %2 | Max: %3",_worldName,_numVehicles,_maxVehicles] call BP_fnc_debugConsoleFormat;

if (_numVehicles < _maxVehicles) then
{
	_dynamicVehicles = [];
	_staticVehicles = [];
	
	_vehicleConfigData = "true" configClasses (_vehicleConfigTypes);
	{
		_category = configName _x;
		_types = "true" configClasses (_x);
		_spawns = getArray (_vehicleConfig >> "Spawns" >> _worldName >> _category);
		{
			_classname = configName _x;
			_spawnCount = getNumber (_x >> "count");
			_actualCount = count entities _classname;
			if (_actualCount < _spawnCount) then
			{
				_staticVehicles pushBack [_classname,(selectRandom _spawns)];
			};
		} forEach _types;
	} forEach _vehicleConfigData;

	//Spawn Static Vehicles
	_spawnedCount = 
	{
		_return = false;
		_x params ["_class",["_pos",[0,0,0]]];
		
		if (_pos isEqualTo [0,0,0]) then
		{
			//Invalid Position
			["dynamicVeh: Tried to spawn vehicle with invalid position. Class: %1 | Pos: %2",_class,_pos] call BP_fnc_debugConsoleFormat;
		} else {
			_nearby = [_pos,25] call BP_fnc_nearbyVehicles;
			
			if (!_nearby) then
			{
				//Random Damage & Fuel
				_damage = random 1;
				_fuel = random 1;
				
				//Spawn The Vehicle
				_vehicle = [_class,_pos,false,_damage,_fuel] call BP_fnc_spawnVehicle;
				_return = true;
			};
		};

		_return
	} count _staticVehicles;
	
	//Debug Output
	["Spawned %1 Vehicles",_spawnedCount] call BP_fnc_debugConsoleFormat;
	
	//Chinook To Do Dynamic Vehicle Spawns
	//[_dynamicVehicles] call BPServer_fnc_spawnCrashCar;
};