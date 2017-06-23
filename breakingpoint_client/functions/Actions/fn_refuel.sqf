/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_vehicle","_canSize","_configVeh","_capacity","_nameType","_curFuel","_newFuel"];

if (r_action_refuel or r_action_siphon or r_action_repair) exitWith { cutText ["An action is already in progress.", "PLAIN DOWN"]; };

_vehicle = _this select 3;
_isWater = (surfaceIsWater (position player)) or BP_isSwimming;

//Exit If Invalid Vehicle
if (isNull _vehicle) exitWith {};

//Exit If Player Inside Vehicle
if (vehicle player == _vehicle) exitWith { cutText ["You can't repair vehicle while inside it.", "PLAIN DOWN"]; };

//Enable Simulation If Disabled
if (!simulationEnabled _vehicle) then {
	[(netID _vehicle),true] remoteExecCall ["BPServer_fnc_simulationToggle",2];
};

//Wait for simulation to be enabled
waitUntil {simulationEnabled _vehicle};

r_action = true;
r_action_refuel = true;

//Read Vehicle Config and Calculate Fuel Level
_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = getNumber (_configVeh >> "fuelCapacity");
_nameType = getText (_configVeh >> "displayName");

private "_curFuel";
if (_vehicle isKindOf "BP_BarrelFuel") then {
	_curFuel = ((getFuelCargo _vehicle) * _capacity);
} else {
	_curFuel = ((fuel _vehicle) * _capacity);
};

_newFuel = _curFuel;
_refuelSize = 0;

//Vehicle already full of fuel
if (_curFuel == _capacity) exitWith { cutText ["This vehicle is already fully refuelled.", "PLAIN DOWN"]; };

//Sound SFX and Alert Zombies
[player,"refuel",0,false,20] call BP_fnc_objSpeak;  
[player,10,true,(getPosATL player)] spawn BP_fnc_zombieAlert;

//Handle Animation / Finishes
_finished = false;
if (_isWater) then {
	_finished = true;
} else {
	_finished = call BP_fnc_medicAnim;
};

if (_finished) then
{
	{
		_empty = BP_FuelEmpty select _forEachIndex;
		_full = _x;
		
		_qty = {_x == _full} count magazines player;
		
		_canSize = getNumber(configFile >> "CfgMagazines" >> _full >> "fuelQuantity");
		
		if (_full in magazines player) then 
		{
			for "_x" from 1 to _qty do 
			{
				if (_newFuel < _capacity) then 
				{
					//Swap Out Magazine
					player removeMagazine _full;
					player addMagazine _empty;
					
					//Update Fuel
					_newFuel = (_newFuel + _canSize);
					
					//Update Refuel Size
					_refuelSize = _refuelSize + _canSize;
				};
			};
		};
	} forEach BP_FuelFull;

	//Handle Fuel Overleaking
	if (_curFuel > _capacity) then { _curFuel = _capacity; };

	//Convert New Liters Fuel -> Decimal from 0.0 -> 1.0
	_newFuel = (_newFuel / _capacity);

	// Ask the server to handle our refuel. 
	//The server will send a response back with the accepted fuel if we're the owner.
	[(netID _vehicle),(netID player),_newFuel] remoteExec ["BP_fnc_vehicleFuel",2];
	
	//Show Refuel Message
	cutText [format["Vehicle has been filled with %1 Litres of Fuel.",_refuelSize], "PLAIN DOWN"];
};

r_action = false;
r_action_refuel = false;

