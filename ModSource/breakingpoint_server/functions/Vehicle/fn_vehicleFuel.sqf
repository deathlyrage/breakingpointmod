/*
	Function: BPServer_fnc_vehicleFuel

	Paramaters:
		0: Vehicle
		1: Fuel
		2: Player (Player Fueling Vehicle)
	
	Thread Blocking: No
	
	Method: Call
*/

if (!initialized) exitWith {};

params ["_vehicleNetID","_playerNetID","_fuel"];

_vehicle = objectFromNetID _vehicleNetID;
_player = objectFromNetID _playerNetID;

//Object Checks for Player / Vehicle
if (isNull _vehicle) exitWith {};
if (isNull _player) exitWith {};

_simulation = (simulationEnabled _vehicle);
_local = (local _vehicle);

// Object Checks for Player / Vehicle
if (isNull _vehicle) exitWith {};
if (isNull _player) exitWith {};

// Debug Message
["vehicleFuel: Vehicle: %1 | Player: %2 | Fuel: %3 | Simulation: %4 | Local: %5 ~0001",_vehicle,_player,_fuel,_simulation,_local] call BP_fnc_debugConsoleFormat;

// Make sure Simulation is enabled
if (!_simulation) then { _vehicle enableSimulationGlobal true; };

// Make Sure No One Is In The Vehicle
if !(crew _vehicle isEqualTo []) exitWith {};

// Handle Fuel Barrels
if (_vehicle isKindOf "BP_BarrelFuel") exitWith 
{
	_vehicle setFuelCargo _fuel;
	_objectUID = _vehicle getVariable ["ObjectUID","0"];
	if (_objectUID != "0") then 
	{
		_objectFuelCargo = getFuelCargo _vehicle;
		["CHILD:398:%1:%2:",_objectUID,_objectFuelCargo] call BPServer_fnc_callExtensionAsyncLow;
	};
};

// Handle Refueling Based Upon Owner
if (local _vehicle) then
{
	_vehicle setFuel _fuel;
} else {
	[_vehicle,_fuel] remoteExecCall ["BP_fnc_vehicleHandleFuel", _vehicle];
};

[_vehicle] call BPServer_fnc_updateQueueAdd;
