/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private ["_buildingNetID","_building","_buildingType","_buildingConfig","_buildingDoors"];
_buildingNetID = _this select 0;
_building = objectFromNetID _buildingNetID;
_buildingType = typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");

//Null Checking
if (isNull _building) exitWith {};

//Logging
["lockHouse: %1",_this] call BP_fnc_debugConsoleFormat;

//Fetch Building Data
_buildingIndex = BP_Buildings find _buildingNetID;
if (_buildingIndex == -1) exitWith {}; // Building not found
_buildingData = BP_BuildingsData select _buildingIndex;

_buildingData params ["_objects","_buildingID","_buildingUID","_playerID","_lock","_unlockAttempts","_explosive","_reinforcement"];

//Lock House
_building setVariable ["bis_disabled_Door",1];
BP_BuildingsLocks set [_buildingIndex,1];
publicVariable "BP_BuildingsLocks";

//Force Close All Doors
//for "_i" from 1 to _buildingDoors do
//{
//	_doorNameL = format ["dvere%1L",_i];
//	_doorNameR = format ["dvere%1R",_i];
//	//if ((_building animationPhase _doorNameL) >= 0.5) then
//	//{
//	_building animate [_doorNameL, 0];
//	_building animate [_doorNameR, 0];
//	//};
//};

//Get Building Position
_buildingPos = getPosATL _building;
_databasePos = [(round(direction _building)),(_buildingPos select 0),(_buildingPos select 1),(_buildingPos select 2)] call BP_fnc_locationToString;

//Update House Data / Timestamp
["CHILD:409:%1:",_buildingUID] call BPServer_fnc_callExtensionAsyncLow;

//Save and Despawn Storage Objects
{
	//Fetch Object
	_object = _x select 0;

	if (!isNull _object) then
	{
		//Save Object
		if (_object isKindOf "BP_BarrelFuel") then {
			//Fuel ( Barrel )
			//_object call BPServer_fnc_updateObjectPosition;

			//Update Local Variable Fuel
			_fuel = getFuelCargo _object;
			_x set [7,_fuel];
		} else {
			//Inventory
			_object call BPServer_fnc_updateObjectInventory;

			//Update Local Variable Inventory
			_inventory = _object getVariable ["lastInventory",[]];
			_x set [6,_inventory];
		};

		//Remove Object From Server Monitor
		_index = BP_serverObjectMonitor find (netID _object);
		if (_index >= 0) then { BP_serverObjectMonitor deleteAt _index; };

		//Delete Storage
		deleteVehicle _object;

		//Update Variable
		_objects set [_forEachIndex,_x];
	} else {
		//Object Has Been Destroyed So Delete It
		_objects deleteAt _forEachIndex;
	};
} forEach _objects;

//Update Buildings Local Cached Objects
_buildingData set [0,_objects];
BP_BuildingsData set [_buildingIndex,_buildingData];

//Save House
[_building] call BPServer_fnc_saveHouse;
