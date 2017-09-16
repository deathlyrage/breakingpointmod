/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_buildingNetID","_combo","_playerNetID"];
_building = objectFromNetID _buildingNetID;
_player = objectFromNetID _playerNetID;

//Logging
["unlockHouse: %1",_this] call BP_fnc_debugConsoleFormat;

//Null Checks
if (isNull _building) exitWith {};
if (isNull _player) exitWith {};

_saveHouse = false;

//Fetch Building Data
_buildingIndex = BP_Buildings find _buildingNetID;
if (_buildingIndex == -1) exitWith {}; // Building not found
_buildingData = BP_BuildingsData select _buildingIndex;

_buildingData params ["_objects","_buildingID","_buildingUID","_playerID","_lock","_unlockAttempts","_explosive","_reinforcement"];

BP_HavenUnlockResult = (_combo == _lock);

if (BP_HavenUnlockResult) then 
{
	//Unlock House
	_building setVariable ["bis_disabled_Door",0];
	BP_BuildingsLocks set [_buildingIndex,0];
	publicVariable "BP_BuildingsLocks";
	
	//Spawn Objects
	{
		_x params ["_object","_idKey","_type","_ownerID","_playerID","_worldspace","_inventory","_fuel"];

		_worldspace params ["_dir","_pos"];
		
		if (isNull _object) then
		{
			//Log
			//["Created %1 ID: %2 Pos: %3",_type,_idKey,_pos] call BP_fnc_debugConsoleFormat;
			
			//Create Object
			_object = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
			_object setDir _dir;
			_object setPosATL _pos;
			_object enableDynamicSimulation true;
			
			//Set Owner ID
			if (_ownerID != "0") then { _object setVariable ["CharacterID", _ownerID, false]; };
			
			//Set Player ID
			if (_playerID != "0") then { _object setVariable ["PlayerID", _playerID, false]; };
			
			//Set Object UID
			_object setVariable ["ObjectID","0"];
			_object setVariable ["ObjectUID",_idKey];

			//Setup Fuel
			if (_object isKindOf "BP_BarrelFuel") then {
				_object setFuelCargo _fuel;
				//Fuel Barrels have no Inventory
				_inventory = [];
			};
			
			//Setup Object Inventory
			if !(_inventory isEqualTo []) then 
			{
				//Set Object Inventory
				[_object,_inventory] call BP_fnc_setObjectInventory;

				//Update Local Inventory for Gear Saving Checks
				_object setVariable ["lastInventory",_inventory];
			};
			
			//Add Object to Server Monitor
			0 = BP_serverObjectMonitor pushBack (netID _object);
		};
		_objects set [_forEachIndex,[_object,_idKey,_type,_ownerID,_playerID,_worldspace,_inventory,_fuel]];
	} forEach _objects;
	
	//Update Buildings Local Cached Objects
	_buildingData set [0,_objects];
} else {
	//Increase Unlock Attempts
	_unlockAttempts = _unlockAttempts + 1;
	_buildingData set [5,_unlockAttempts];

	//Explosions!
	if (_explosive and (_unlockAttempts > 2)) then
	{
		//Flag Building as No longer Explosive
		_saveHouse = true;
		_explosive = false;
		_buildingData set [6,_explosive];
		
		//Make Building Immortal
		_building allowDamage false;
		_building setDamage 0;
		
		//Let IED Rip! (TODO: Cool Beeping Sound Effect B4 Explosion?)
		_playerPosition = getPosATL _player;
		_explosive = "BP_IED" createVehicle _playerPosition;
		_explosive setPosATL _playerPosition;
		_explosive setDamage 1;
		
		//Make Building Mortal
		_building allowDamage true;
		_building setDamage 0;
	};
};

//Update Building Data
BP_BuildingsData set [_buildingIndex,_buildingData];

//Handle Save
if (_saveHouse) then {
	[_building] call BPServer_fnc_saveHouse;
};

//Send Client Unlock Result
(owner _player) publicVariableClient "BP_HavenUnlockResult";
