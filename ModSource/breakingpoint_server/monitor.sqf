/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Init Hive
["CHILD:100:%1:",BP_ServerInstance] call BPServer_fnc_callExtension;
["Hive: Starting Connection Process with Instance ID: %1",BP_ServerInstance] call BP_fnc_debugConsoleFormat;

//Send Client Functions Over Network
_clientFunctionsList = ["Client_Init"];

{
	_functions = "true" configClasses (configFile >> "CfgFunctions" >> "BreakingPoint_Client" >> _x);
	{
		_fncName = format ["BP_fnc_%1",(configName _x)];
		0 = BP_ClientFuncs pushBack _fncName;
		publicVariable _fncName;
	} forEach _functions;
} forEach _clientFunctionsList;

//Broadcast Server Stored Functions list for Whitelisting Of Vars
publicVariable "BP_ClientFuncs";

//Calculate Player Count For This Instance
BP_maxPlayers = 100;

//Object Arrays
_spawnObjects = [];
_spawnVehicles = [];
_spawnHouses = [];
_spawnTraps = [];

if !(BP_FastBoot) then
{
	//Lock Server
	call BPServer_fnc_rconLock;

	//Request Objects
	[_spawnObjects,["CHILD:101:"],"ObjectStreamStart"] call BPServer_fnc_callExtensionArray;

	//Request Vehicles
	[_spawnVehicles,["CHILD:102:"],"VehicleStreamStart"] call BPServer_fnc_callExtensionArray;

	//Request Houses
	[_spawnHouses,["CHILD:103:"],"HouseStreamStart"] call BPServer_fnc_callExtensionArray;

	//Request Traps
	[_spawnTraps,["CHILD:104:"],"TrapStreamStart"] call BPServer_fnc_callExtensionArray;

};

// DISABLED: Not functional in open source version yet
// call BPServer_fnc_updateWeapons;
// call BPServer_fnc_updateMagazines;
// call BPServer_fnc_updateScripts;

//Connected Default Value
BP_HC_Connected = false;

//Wait Until Mission Init
waitUntil {missionNameSpace getVariable ["bis_fnc_init",false]};

//Update Time Sync
call BPServer_fnc_updateTime;

//Create Strongholds
//if (BP_FactionStrongholds) then
//{
//	_cfgBases = (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Factions" >> "Bases");
//	_factionsList = getArray (configFile >> "CfgFactions" >> "factions");
//	for "_c" from 0 to (count _cfgBases - 1) do
//	{
//		private ["_currentBase","_baseName"];
//		_currentBase = _cfgBases select _c;
//		_baseName = configName _currentBase;
//		if (isClass _currentBase) then
//		{
//			_basePosition = getArray (_cfgBases >> _baseName >> "position");
//			_baseRadius = getNumber (_cfgBases >> _baseName >> "radius");
//			_factionID = _factionsList find _baseName;
//			_logic = createVehicle ["BP_Stronghold", _basePosition, [], 0, "NONE"];
//			_logic setPosATL _basePosition;
//			//not global because anyone can convert ID -> Faction Name from missionConfigFile
//			_logic setVariable ["name",_baseName,true];
//			_logic setVariable ["class",_factionID,true];
//			_logic setVariable ["radius",_baseRadius,true];
//			_logic setVariable ["alert",false,true];
//			_logic setVariable ["alertTime",diag_tickTime,true];
//			_logic setVariable ["attacked",false,true];
//			_logic allowDamage false;
//			0 = BP_Strongholds pushBack _logic;
//			["Creating Stronghold: %1 %2 %3",_baseName,_factionID,_baseRadius] call BP_fnc_debugConsoleFormat;
//		};
//	};
//};

//Spawn In Map Specific Objects
["Spawning in Map Specific Objects for %1",worldName] call BP_fnc_debugConsoleFormat;
call compile preprocessFileLineNumbers format ["\breakingpoint_server\maps\%1.sqf",worldName];

//Spawn In Loot 3.0 Coords
_customLootSetting = getNumber(configFile >> "CfgBreakingPointServerSettings" >> "CustomLoot" >> "customLootSetting");
if(_customLootSetting > 0) then
{
	{
		_x params ["_minLoot","_maxLoot","_radius","_lootType","_lootPos",["_chance",1]];
		if(_customLootSetting == 2 && _lootType == "AmmoPallet4") then
		{
			_lootType = "GhostHotelWpn";
		};
		_rnd = random 1;
		if (_rnd < _chance) then
		{
			_logic = createVehicle ["Land_House_Logic", _lootPos, [], 0, "NONE"];
			_logic setVariable ["minLoot",_minLoot,true];
			_logic setVariable ["maxLoot",_maxLoot,true];
			_logic setVariable ["lootRadius",_radius,true];
			_logic setVariable ["lootType",_lootType,true];
		};
	} count (getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Loot" >> "customLoot"));
};

// get config if buildings are immortal
_immortalHaven = getNumber(configfile >> "CfgBreakingPointServerSettings" >> "StorageObjects" >> "immortalHavens");

//Lock The Houses
{
	_x params ["_header","_playerID","_buildingUID","_buildingID","_buildingName","_worldSpace","_lock","_explosive","_reinforcement"];
	if (_header == "HOUSE") then
	{
		_worldSpace params ["_direction","_position"];
		_building = _position nearestObject (parseNumber _buildingID);
		_objects = [];
		_unlockAttempts = 0;
		["updateBuildings: Header: %1 Building: %2 | Building ID: %3 | Player ID: %4 | Unique ID: %5",_header,_building,_buildingID,_playerID,_buildingUID] call BP_fnc_debugConsoleFormat;

		//Handle Haven Locking
		if (!isNull _building && {_buildingName == (typeOf _building)}) then
		{
			//Make Building Immortal
			if(_immortalHaven == 1) then
			{
				_building allowDamage false;
			};

			//Get Building Config Data
			//_buildingType = typeOf _building;

			// Mission config file loot table override.
			//_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
			//if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
			//{
			//	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
			//};

			//_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");

			_building addEventHandler ["HandleDamage",{_this call BPServer_fnc_houseHandleDamage;}];
			_building addEventHandler ["Killed",{_this call BPServer_fnc_houseKilled;}];

			//Add Building To Array
			0 = BP_Buildings pushBack (netID _building);
			0 = BP_BuildingsData pushBack [_objects,_buildingID,_buildingUID,_playerID,_lock,_unlockAttempts,_explosive,_reinforcement];
			0 = BP_BuildingsLocks pushBack 1;
		} else {
			["updateBuildings: Invalid Building with ID %1 | UID: %2 | Pos: %3 | Saved Type: %4 | Type: %5 #1001",_buildingID,_buildingUID,_position,_buildingName,(typeOf _building)] call BP_fnc_debugConsoleFormat;
			["CHILD:408:%1:%2:",_buildingID,_buildingUID] call BPServer_fnc_callExtensionAsync;
		};
	};
} count _spawnHouses;

//Clear Houses now that it has been processed
_spawnHouses = nil;

//Broadcast Buildings
publicVariable "BP_Buildings";
publicVariable "BP_BuildingsLocks";

//Spawn The Traps
{
	_x params ["_header","_uniqueID","_classname","_worldSpace"];
	if (_header == "TRAP") then
	{
		_worldSpace params ["_direction","_position"];
		_trap = _classname createVehicle _position;
		_trap setDir _direction;
		_trap setPosATL _position;
		_trap enableDynamicSimulation true;
		0 = BP_Traps pushBack [_uniqueID,_trap,_direction];
	};
} count _spawnTraps;

//Clear Traps now that it has been processed
_spawnTraps = nil;

//Broadcast Traps
publicVariable "BP_Traps";

//Spawn The Objects
{
	//Fetch Object Data
	_x params ["","_uniqueID","_type","_ownerID","_playerID","_worldspace","_inventory","_fuel","_lock","_buildingID"];

	if (_uniqueID != "0") then
	{
		_object = objNull;
		_building = objNull;

		//Get Worldspace Dir and Pos
		_worldspace params ["_dir","_pos"];

		//Check for Valid Haven Objects in Buildings
		if (_buildingID != "0") then
		{
			_building = _pos nearestObject (parseNumber _buildingID);
			if (!isNull _building) then
			{
				if !(netID _building in BP_Buildings) then {
					_building = objNull;
				};
			};
		};

		if (!isNull _building) exitWith
		{
			_buildingIndex = BP_Buildings find (netID _building);
			if (_buildingIndex >= 0) then
			{
				_buildingData = BP_BuildingsData select _buildingIndex;
				_buildingObjects = _buildingData select 0;
				_index = _buildingObjects pushBack [objNull,str(_uniqueID),_type,_ownerID,_playerID,_worldspace,_inventory,_fuel];
				_buildingData set [0,_buildingObjects];
				BP_BuildingsData set [_buildingIndex,_buildingData];
				["Skipping Haven Object %1 ID: %2 Pos: %3",_type,_uniqueID,_pos] call BP_fnc_debugConsoleFormat;
			};
		};

		//Logging
		["Created Object %1 ID: %2 Pos: %3",_type,_uniqueID,_pos] call BP_fnc_debugConsoleFormat;

		//Create Object
		_object = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
		_object enableDynamicSimulation true;

		//Wait for Object Creation
		waitUntil {!isNil "_object" && {!isNull _object}};

		//Make Object Immortal
		_object allowDamage false;

		//Position Fixes If Glitched Underground
		if ((_pos select 2) < 0) then { _pos set [2,0]; };

		//Set Direction
		_object setDir _dir;

		//Set Exact Position
		_object setPosATL _pos;

		//Make Object Mortal
		_object allowDamage true;

		//Set Owner ID
		if (_ownerID != "0") then { _object setVariable ["CharacterID",_ownerID]; };

		//Set Player ID
		if (_playerID != "0") then { _object setVariable ["PlayerID",_playerID]; };

		//Set Object UID
		_object setVariable ["ObjectUID",str(_uniqueID)];

		//Safe Object
		if (_object isKindOf "BP_Safe") then {
			_object setVariable ["locked",true,true];
			_object setVariable ["key",_lock,true];
		};

		//Setup Object Inventory
		if !(_inventory isEqualTo [] || {_inventory isEqualTo [[],[],[],[[],[]],[[],[]]]}) then
		{
			//Don't Add Inventory on Safes
			if !(_object isKindOf "BP_Safe") then
			{
				//Set Object Inventory
				[_object,_inventory] call BP_fnc_setObjectInventory;
			};

			//Update Local Inventory for Gear Saving Checks
			_object setVariable ["lastInventory",_inventory];
		} else {
			//Delete Empty Objects that are not of a certain type
			if !(_type in ["BP_BarrelFuel","BP_BarrelWater","BP_CamoNet","BP_Stove","BP_Television"]) then {
				_object setDamage 1;
			};
		};

		// Restore fuel value on fuel barrels
		if (_type in ["BP_BarrelFuel"]) then {
			_object setFuelCargo _fuel;
		};

		//Object has not been deleted or removed
		if (!isNull _object) then
		{
			//Add Object to Server Monitor
			0 = BP_serverObjectMonitor pushBack (netID _object);

			//Check Object
			[_object] call BPServer_fnc_checkObject;

			//Simulation Mgr
			_object enableSimulationGlobal false;
		};
	};
} count _spawnObjects;

_spawnObjects = nil;

//Spawn The Vehicles
_numVehicles =
{
	//Fetch Vehicle Data
	_x params ["","_uniqueID","_type","_worldspace","_inventory","_hitpoints","_fuel","_damage"];

	if (_uniqueID != "0") then
	{
		_worldspace params ["_dir","_pos"];

		//Logging
		["Created Vehicle %1 ID: %2 Pos: %3",_type,_uniqueID,_pos] call BP_fnc_debugConsoleFormat;

		//Create Object
		_object = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
		_object enableDynamicSimulation true;

		//Wait for Object Creation
		waitUntil {!isNil "_object" && {!isNull _object}};

		//Make Object Immortal
		_object allowDamage false;

		//Set Unique IDs
		_object setVariable ["ObjectUID",str(_uniqueID)];

		//Set Direction
		_object setDir _dir;

		//Set Exact Position
		if (_object isKindOf "Ship") then {
			if (surfaceIsWater _pos) then
			{
				_object setPosASL [(_pos select 0),(_pos select 1),0];
			} else {
				_object setPosATL _pos;
			}
		} else {
			_object setPosATL _pos;
			//Set Vector Update on Cars and Helicopters
			_object setVectorUp (surfaceNormal _pos);
		};

		//Fix for Helicopters Exploding when you enter them - Agent Rev
		// https://github.com/A3Wasteland/ArmA3_Wasteland.Altis/blob/ae57a23489c4fb733cee3deb51a45f65bfcbebf1/server/spawning/staticHeliCreation.sqf#L26-L27
		if (_object isKindOf "Helicopter") then {
			//_object setPos [_pos select 0, _pos select 1, 0.01];
			_object setVelocity [0,0,0.01];
		};

		//Make Object Mortal
		_object allowDamage true;

		//Clear All Spawn Magazines / Gear / Items / Uniform / Backpacks
		removeAllWeapons _object;
		clearWeaponCargoGlobal  _object;
		clearMagazineCargoGlobal  _object;
		clearBackpackCargoGlobal _object;
		clearItemCargoGlobal _object;

		//Set Object Direction / Damage
		_object setDamage _damage;

		//Setup Object Inventory
		if !(_inventory isEqualTo []) then
		{
			//Set Object Inventory
			[_object,_inventory] call BP_fnc_setObjectInventory;

			//Update Local Inventory for Gear Saving Checks
			_object setVariable ["lastInventory",_inventory];
		};

		//Set Object Hitpoints
		{
			_x params ["_selection","_dam"];
			if (_selection in BP_explosiveParts and _dam > 0.89) then {_dam = 0.89};
			_object setHitPointDamage [_selection,_dam];
		} count _hitpoints;
		_object setVelocity [0,0,2];
		_object setVehicleAmmo 0;
		_object setFuel _fuel;
		_object enableRopeAttach true;

		//Add Object to Server Monitor
		0 = BP_serverObjectMonitor pushBackUnique (netID _object);

		//Check Object
		[_object] call BPServer_fnc_checkObject;
	};

	//Return True
	true
} count _spawnVehicles;

_spawnVehicles = nil;

//Server Building and Vehicle / Bootup Completed
initialized = true;

//Register Hive In Use & Allow Player Connections
allowConnection = true;

//Dynamic Vehicle Thread
if !(BP_FastBoot) then
{
	_dynamicVeh = [_numVehicles] execVM "\breakingpoint_server\threads\BP_dynamicVeh.sqf";
	[_dynamicVeh] call BP_fnc_addThreadHandle;
};

//Server Mgr Thread
_serverMgr = [] execVM "\breakingpoint_server\threads\BP_serverMgr.sqf";
[_serverMgr] call BP_fnc_addThreadHandle;

["Server Startup Completed.-~0101",BP_versionNo] call BP_fnc_debugConsoleFormat;

if (BP_FastBoot) exitWith {};

//Unlock Server
call BPServer_fnc_rconUnlock;
