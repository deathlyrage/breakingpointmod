/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_vehicle","_isWater","_configVeh","_capacity","_nameText","_isMan","_isAnimal","_isZombie"];
_vehicle = _this select 3;
_isWater = (surfaceIsWater (position player)) or BP_isSwimming;

//Exit If Invalid Vehicle
if (isNull _vehicle) exitWith {};

//Exit If Player Inside Vehicle
if (vehicle player == _vehicle) exitWith { cutText ["You can't siphon fuel from a vehicle while inside it.", "PLAIN DOWN"]; };

//Exit If Action In Progress
if (r_action_refuel or r_action_siphon or r_action_repair) exitWith {
	cutText ["An action is already in progress.", "PLAIN DOWN"];
};

//Enable Simulation If Disabled
if (!simulationEnabled _vehicle) then {
	[(netID _vehicle),true] remoteExecCall ["BPServer_fnc_simulationToggle",2];
};

//Wait for simulation to be enabled
waitUntil {simulationEnabled _vehicle};

//Exit If No Empty Fuel Can
_full = "";
_empty = "";
{
	if (_x in magazines player) exitWith { 
		_full = BP_FuelFull select _forEachIndex;
		_empty = _x;
	};
} forEach BP_FuelEmpty;

if (_empty == "") exitWith { cutText ["You don't have any fuel cans.", "PLAIN DOWN"]; };

//Flag Player as Siphon In Progress
r_action_siphon = true;

// Static vehicle fuel information
_configVeh = configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = getNumber(_configVeh >> "fuelCapacity");
_nameText = getText(_configVeh >> "displayName");
_isMan = _vehicle isKindOf "Man";
_isAnimal = _vehicle isKindOf "Animal";
_isZombie = _vehicle isKindOf "zZombie_base";

["siphonFuel: Name: %1 Capacity: %2 isMan: %3 isZombie: %4 isAnimal: %5",_nameText,_capacity,_isMan,_isAnimal,_isZombie] call BP_fnc_debugConsoleFormat;

if (_isMan or _isAnimal or _isZombie) exitWith {
	cutText ["You can only siphon the fuel from a vehicle.", "PLAIN DOWN"];
	call BP_fnc_medicalRemoveMedicActions;
	r_action = false;
	r_action_siphon = false;
};

private ["_configCanEmpty","_canSizeEmpty","_canTypeEmpty","_canSize","_curFuel","_newFuel","_animState","_started","_isMedic","_finished"];

player removeMagazine _empty;

_configCanEmpty = configFile >> "CfgMagazines" >> _empty;
_canSizeEmpty = getNumber (_configCanEmpty >> "fuelQuantity");
_canTypeEmpty = getText (_configCanEmpty >> "displayName");
_canSize =	getNumber (configFile >> "CfgMagazines" >> _empty >> "fuelQuantity");

private "_curFuel";
if (_vehicle isKindOf "BP_BarrelFuel") then {
	_curFuel = ((getFuelCargo _vehicle) * _capacity);
} else {
	_curFuel = ((fuel _vehicle) * _capacity);
};

_newFuel = (_curFuel - _canSize);

// calculate new fuel
if (_capacity == 0) then {
	_newFuel = 0;
} else {
	_newFuel = (_newFuel / _capacity);
};

if (_newFuel > 0) then 
{
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
		// Ask the server to handle our refuel. 
		//The server will send a response back with the accepted fuel if we're the owner.
		[(netID _vehicle),(netID player),_newFuel] remoteExec ["BP_fnc_vehicleFuel",2];

		// Play sound
		[player,"refuel",0,false] call BP_fnc_objSpeak;

		// Add filled can
		player addMagazine _full;

		cutText [format["%1 was Siphoned for %2L Of Fuel.",_nameText,_canSize], "PLAIN DOWN"];
	} else {
		player addMagazine _empty;
	};
} else {
	player addMagazine _empty;
	cutText ["This vehicle doesn't have enough fuel left.", "PLAIN DOWN"];
};

call BP_fnc_medicalRemoveMedicActions;
r_action = false;
r_action_siphon = false;