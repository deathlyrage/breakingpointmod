/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_serverMgr";

#define CLEANUP_CHECK_INT 60
#define CLEANUP_PLAYER_TIME 600
#define CLEANUP_BODY_TIME 120
#define CLEANUP_WPNHOLDER_TIME 300
#define CLEANUP_LOOT_TIME 1200

#define SIM_CHECK_INT 30
#define SIM_DIST_LOOT 8
#define SIM_DIST_VEH 1400
#define SIM_DIST_MAN 1400
#define SIM_DIST_ZED 1000

#define QUEUE_CHECK_INT 10

#define DUPE_CHECK_INT 60

#define HELI_CHECK_INT 1500

#define DEBUG_CHEK_INT 60

private ["_lastSimulationCheck","_lastCleanupCheck","_lastQueueCheck","_lastHelicrashCheck","_lastTimeoutCheck","_lastDebugCheck","_helicrashCount"];
_lastSimulationCheck = diag_tickTime;
_lastCleanupCheck = diag_tickTime;
_lastQueueCheck = diag_tickTime;
_lastDupeCheck = diag_tickTime;
_lastHelicrashCheck = diag_tickTime;
_lastTimeoutCheck = diag_tickTime;
_lastDebugCheck = diag_tickTime;
_helicrashCount = 5;

waitUntil
{
	//------ Server Cleanup Check ---------//
	if ((diag_tickTime - _lastCleanupCheck) > CLEANUP_CHECK_INT) then 
	{
		_lastCleanupCheck = diag_tickTime;
		
		// Check Undead Queue
		{
			_logic = objectFromNetID _x;
			if (isNull _logic) then {
				BP_UndeadQueue deleteAt _forEachIndex;
			} else {
				if (local _logic) then {
					BP_UndeadQueue deleteAt _forEachIndex;
					deleteVehicle _logic;
				};
			};
		} forEach BP_UndeadQueue;
		
		// Cleanup Groups
		{ if ((count units _x) == 0 ) then { deleteGroup _x; }; } count allGroups;
		
		// Dead Characters
		{
			// Remove Ticket
			0 = BP_DeadTickets deleteAt _forEachIndex;

			// Wait Until Result
			_result = _x call BPServer_fnc_callExtensionResult;
			
			// Process Result
			_result params [["_status","FAIL",[""]],["_characterID","0",[""]]];
			
			// Remove From Temp Dead Characters List If Success
			if (_status == "PASS") then
			{
				//Remove Character
				_index = BP_DeadCharacters find _characterID;
				if (_index > -1) then { 0 = BP_DeadCharacters deleteAt _index; };
			};

			// Log
			["Processed Dead Character Hive Ticket: %1",_result] call BP_fnc_debugConsoleFormat;

		} forEach BP_DeadTickets;
		
		// Save Character Positions
		{ _x call BPServer_fnc_playerCheck; } count allPlayers;

		// Server Sync / Updates (5 min)
		if ((diag_tickTime - BP_Cleanup_lastSync) > BP_Cleanup_Sync_Interval) then {
			["serverMgr: Server Sync / Updates (5 min)"] call BP_fnc_debugConsoleFormat;
			call BPServer_fnc_updateAll;
		};
			
		// Unused Objects Cleanup (15 min)
		if ((diag_tickTime - BP_Cleanup_lastLoot) > BP_Cleanup_Loot_Interval) then {
			["serverMgr: Unused Objects Cleanup (15 min)"] call BP_fnc_debugConsoleFormat;
			call BPServer_fnc_cleanupLoot;
		};
			
		// Unused Objects Cleanup (60 min)
		if ((diag_tickTime - BP_Cleanup_lastLootAll) > BP_Cleanup_GlobalLoot_Interval) then {
			["serverMgr: All Objects Cleanup (60 min)"] call BP_fnc_debugConsoleFormat;
			call BPServer_fnc_cleanupLootAll;
		};
			
		// Server Restart Cleanup (3 Hours)
		if (!shutdown) then
		{
			_result = ["CHILD:108:"] call BPServer_fnc_callExtension;
			if ((_result select 0) != "PASS") exitWith {};
			
			_result params ["","_localTime","_shutdown"];
			
			if (_shutdown) then {
				["serverMgr: Restart Cleanup and Sync (2 Hours 50 Mins)"] call BP_fnc_debugConsoleFormat;
				[[], BPServer_fnc_cleanupRestart] execFSM "\breakingpoint_code\system\call.fsm";
			};
		};
	};
	
	//------ Server Simulation Mgr ---------//
	if (BP_ServerSimulationManager) then
	{
		if ((diag_tickTime - _lastSimulationCheck) > SIM_CHECK_INT) then
		{
			_lastSimulationCheck = diag_tickTime;
			
			//Ground Weapon Holders
			{
				if (_x call BP_fnc_isInDebug) then { 
					deleteVehicle _x;
				} else {
					//Simulation Processing
					//[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulation;
					
					_keep = _x getVariable ["permaLoot",false];
					if (!_keep) then
					{
						//Dead Body Handling
						if (_x isKindOf "BP_DeadBody") then
						{
							_processedDeath = _x getVariable ["processedDeath",0];
							if (_processedDeath == 0) then {
								_x setVariable ["processedDeath",diag_tickTime];
							} else {
								if ((diag_tickTime - _processedDeath) > CLEANUP_PLAYER_TIME) then 
								{
									_nearby = [(getPosATL _x),BP_Cleanup_Dead_Nearby] call BP_fnc_nearbyPlayers;
									if (!_nearby) then {
										["cleanupDead: Cleaning Up Body %1",_x] call BP_fnc_debugConsoleFormat;
										deleteVehicle _x;
									};
								};
							};
						} else {
							_processedDeath = _x getVariable ["processedDeath",0];
							if (_processedDeath == 0) then {
								_x setVariable ["processedDeath",diag_tickTime];
							} else {
								if ((diag_tickTime - _processedDeath) > CLEANUP_WPNHOLDER_TIME) then 
								{
									_nearby = [(getPosATL _x),5] call BP_fnc_nearbyPlayers;
									if (!_nearby) then {
										["cleanupDead: Cleaning Up Weapon Holder %1",_x] call BP_fnc_debugConsoleFormat;
										deleteVehicle _x;
									};
								};
							};
						};
					};
				};
			} count allMissionObjects "GroundWeaponHolder";
			
			//Simulation On Vehicles
			{
				call
				{
					private ["_inDebug","_keep"];
					_inDebug = _x call BP_fnc_isInDebug;
					_keep = _x getVariable ["permaLoot",false];
					
					//Simulated Weapon Holders
					if (_x isKindOf "WeaponHolderSimulated") exitWith
					{
						if (!_keep and _inDebug) then { 
							deleteVehicle _x;
						} else {
							//Simulation Processing
							//[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulation;
							
							if (!_keep) then
							{
								_processedDeath = _x getVariable ["processedDeath",0];
								if (_processedDeath == 0) then {
									_x setVariable ["processedDeath",diag_tickTime];
								} else {
									if ((diag_tickTime - _processedDeath) > CLEANUP_WPNHOLDER_TIME) then 
									{
										_nearby = [(getPosATL _x),5] call BP_fnc_nearbyPlayers;
										if (!_nearby) then {
											["cleanupDead: Cleaning Up Weapon Holder %1",_x] call BP_fnc_debugConsoleFormat;
											deleteVehicle _x;
										};
									};
								};
							};
						};
					};
					
					//Loot Boxes
					if (_x isKindOf "BP_LootBox") exitWith
					{
						if (!_keep and _inDebug) then { 
							deleteVehicle _x;
						//} else {
							//[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulation;
						};
					};
					
					//Storage Objects
					if (_x isKindOf "BP_SaveObject") exitWith
					{
						if (_inDebug) then { 
							deleteVehicle _x;
						//} else {
						//	[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulation;
						};
					};
					
					//Vehicles
					if (_x isKindOf "Car_F" || {_x isKindOf "Helicopter"} || {_x isKindOf "Boat"}) exitWith
					{
						if (!_keep) then 
						{
							if (_inDebug) then {
								if (damage _x < 1) then { _x setDamage 1; };
							} else {
								//[SIM_DIST_VEH,_x] call BPServer_fnc_checkVehicleSimulation;
							};
						};
					};
				};
			} count vehicles;
			
			//Simulation on Dead Bodies
			{
				//Bodies In Debug
				if (_x call BP_fnc_isInDebug) then
				{
					deleteVehicle _x;
				} else {
					//Dead Player
					_med = _x getVariable ["med_isDead",false];
					if (_med or (isPlayer _x)) then
					{
						_processedDeath = _x getVariable ["processedDeath",0];
						if (_processedDeath == 0) then {
							_x setVariable ["processedDeath",diag_tickTime];
						} else {
							if ((diag_tickTime - _processedDeath) > CLEANUP_PLAYER_TIME) then { 
								_nearby = [(getPosATL _x),BP_Cleanup_Dead_Nearby] call BP_fnc_nearbyPlayers;
								if (!_nearby) then
								{
									//Delete Fire on Body
									_fire = _x getVariable ["fire",objNull];
									if !(isNull _fire) then { [objNull,_fire] remoteExecCall ["BP_fnc_fireDelete",0]; };
									
									//log Body Cleanup
									["cleanupDead: Cleaning Up Body %1",_x] call BP_fnc_debugConsoleFormat;
									
									//Delete Body
									deleteVehicle _x;
								};
							//} else {
							//	[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulationLocal;
							};
						};
					}
					else
					{
						//Dead Zed or Animal
						_processedDeath = _x getVariable ["processedDeath",0];
						if (_processedDeath == 0) then {
							_x setVariable ["processedDeath",diag_tickTime];
						} else {
							if ((diag_tickTime - _processedDeath) > CLEANUP_BODY_TIME) then 
							{
								//Delete Fire on Body
								_fire = _x getVariable ["fire",objNull];
								if !(isNull _fire) then { [objNull,_fire] remoteExecCall ["BP_fnc_fireDelete",0]; };
								
								//Log Body Cleanup
								["cleanupDead: Cleaning Up Body %1",_x] call BP_fnc_debugConsoleFormat;
								
								//Delete Body
								deleteVehicle _x;
							//} else {
							//	[SIM_DIST_LOOT,_x] call BPServer_fnc_checkSimulationLocal;
							};
						};
					};
				};
			} count allDeadMen;
			
			//Disable Simulation on Local Zombies
			{ _x enableSimulation (local _x); } count entities "zZombie_Base";
		};
	};

	//------ Vehicle Queue Updates ---------//
	if ((diag_tickTime - _lastQueueCheck) > QUEUE_CHECK_INT) then
	{
		_lastQueueCheck = diag_tickTime;

		if !(BP_ObjectUpdateQueue isEqualTo []) then
		{
			//Get Object Details
			_netID = BP_ObjectUpdateQueue deleteAt 0;
			_netObj = objectFromNetID _netID;
			
			// If Null Object Remove From Queue else Process
			if (!isNull _netObj) then {
				[_netObj,"queue"] call BPServer_fnc_updateObject;
				["serverMgr: Processing on %1 From Update Queue NetID: %2",_netObj,_netID] call BP_fnc_debugConsoleFormat;
			};
		};
	};
	
	//-- Anti Duping
	/*
	if ((diag_tickTime - _lastDupeCheck) > DUPE_CHECK_INT) then 
	{
		_lastDupeCheck = diag_tickTime;
		
		//_antiDupeCheck = [] spawn
		call
		{
			scriptName "BP_antiDupeCheck";
			_players = allPlayers;
			{
				_player1 = _x;
				_player1Mags = _player1 call BPServer_fnc_getMagazineNames;
				_player1MagIDs = _player1 call BPServer_fnc_getMagazineIDs;
				_player1Name = _player1 getVariable ["bodyName","Unknown"];
				_player1ID = _player1 getVariable ["playerID",""];
				
				{
					_player2 = _x;
					_player2Mags = _player2 call BPServer_fnc_getMagazineNames;
					_player2MagIDs = _player2 call BPServer_fnc_getMagazineIDs;
					_player2Name = _player1 getVariable ["bodyName","Unknown"];
					_player2ID = _player1 getVariable ["playerID",""];
				
					if (_player1 != _player2) then
					{
						//Check Uniform
						_container1 = uniformContainer _player1;
						if (isNil "_container1") then { _container1 = objNull; };
						_container1ID = netID _container1;
						_container2 = uniformContainer _player2;
						if (isNil "_container2") then { _container2 = objNull; };
						_container2ID = netID _container2;
						if (!isNull _container1 && {!isNull _container2} && {_container1ID == _container2ID} && {!(_container1ID in BP_DupeNetIDs)}) then
						{
							BP_DupeNetIDs pushBack _container1ID;
							_reason = format ["Uniform Duplication %1",_container1ID];
							["CHILD:503:%1:%2:%3:",_player1ID,_player1Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
							["CHILD:503:%1:%2:%3:",_player2ID,_player2Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
						};
						
						//Check Vest
						_container1 = vestContainer _player1;
						if (isNil "_container1") then { _container1 = objNull; };
						_container1ID = netID _container1;
						_container2 = vestContainer _player2;
						if (isNil "_container2") then { _container2 = objNull; };
						_container2ID = netID _container2;
						if (!isNull _container1 && {!isNull _container2} && {_container1ID == _container2ID} && {!(_container1ID in BP_DupeNetIDs)}) then
						{
							BP_DupeNetIDs pushBack _container1ID;
							_reason = format ["Vest Duplication %1",_container1ID];
							["CHILD:503:%1:%2:%3:",_player1ID,_player1Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
							["CHILD:503:%1:%2:%3:",_player2ID,_player2Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
						};
						
						//Check Backpack
						_container1 = backpackContainer _player1;
						if (isNil "_container1") then { _container1 = objNull; };
						_container1ID = netID _container1;
						_container2 = backpackContainer _player2;
						if (isNil "_container2") then { _container2 = objNull; };
						_container2ID = netID _container2;
						if (!isNull _container1 && {!isNull _container2} && {_container1ID == _container2ID} && {!(_container1ID in BP_DupeNetIDs)}) then
						{
							BP_DupeNetIDs pushBack _container1ID;
							_reason = format ["Backpack Duplication %1",_container1ID];
							["CHILD:503:%1:%2:%3:",_player1ID,_player1Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
							["CHILD:503:%1:%2:%3:",_player2ID,_player2Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
						};
						
						//Check Magazines
						{
							if (_x in _player2MagIDs && {!(_x in BP_DupeMagIDs)}) then
							{
								//Add Magazine ID to Known Duped Mags
								BP_DupeMagIDs pushBack _x;
								
								//Convert to Friendly Magazine Name
								_magazineName = _player1Mags select _forEachIndex;
								
								//Log Entry on Admin Log
								_reason = format ["Magazine Duplication %1",_magazineName];
								["CHILD:503:%1:%2:%3:",_player1ID,_player1Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
								["CHILD:503:%1:%2:%3:",_player2ID,_player2Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
							};
						} forEach _player1MagIDs;
					} else {
					
						_checkMagIDs = + _player2MagIDs;
						
						{
							//Take Mag Out Of Array
							_i = _checkMagIDs find _x;
							if (_i > -1) then { 0 = _checkMagIDs deleteAt _i; };
							
							//Check If It's in the Array (Duplicate)
							if (_x in _checkMagIDs && {!(_x in BP_DupeSelfMagIDs)}) then
							{
								//Add Magazine ID to Known Duped Mags
								BP_DupeSelfMagIDs pushBack _x;

								//Convert to Friendly Magazine Name
								_magazineName = _player2Mags select _forEachIndex;

								//Log Entry on Admin Log
								_reason = format ["Self Magazine Duplication %1",_magazineName];
								["CHILD:503:%1:%2:%3:",_player2ID,_player2Name,_reason] call BPServer_fnc_callExtensionAsyncLow;
							};
						} forEach _player2MagIDs;
					};
				} forEach _players;
			} forEach _players;
		};
		//[_antiDupeCheck] call BP_fnc_addThreadHandle;
		//waitUntil {scriptDone _antiDupeCheck};
	};
	*/
	
	//------ Helicrash Check ---------//
	if ((diag_tickTime - _lastHelicrashCheck) > HELI_CHECK_INT) then 
	{
		_lastHelicrashCheck = diag_tickTime;
		
		if (_helicrashCount > 0 and BP_Helicrashes) then
		{
			_helicrashCount = _helicrashCount - 1;
			if (random 1 <= 0.75) then 
			{
				if (BP_HeliCrash) then {
					["serverMgr: Calling Helicrash Spawn"] call BP_fnc_debugConsoleFormat;
					_handle = [] spawn BPServer_fnc_spawnCrashHeli;
					[_handle] call BP_fnc_addThreadHandle;
				};
			} else {
				if (BP_CargoCrash) then {
					["serverMgr: Calling Cargocrash Spawn"] call BP_fnc_debugConsoleFormat;
					_handle = [] spawn BPServer_fnc_spawnCrashCargo;
					[_handle] call BP_fnc_addThreadHandle;
				};
			};
		};
	};
	
	//------ Debug Check ------//
	//if ((diag_tickTime - _lastDebugCheck) > DEBUG_CHEK_INT) then
	//{
	//	_lastDebugCheck = diag_tickTime;
    //
	//	//SQF
	//	["--- Active Scripts Running Output: (SQF) ----"] call BP_fnc_debugConsoleFormat;
	//	{
	//		["%1",_x] call BP_fnc_debugConsoleFormat;
	//	} count diag_activeSQFScripts;
	//	
	//	//SQS
	//	["--- Active Scripts Running Output: (SQS) ----"] call BP_fnc_debugConsoleFormat;
	//	{
	//		["%1",_x] call BP_fnc_debugConsoleFormat;
	//	} count diag_activeSQSScripts;
	//	
	//	//FSM
	//	["--- Active Scripts Running Output: (FSM) ----"] call BP_fnc_debugConsoleFormat;
	//	{
	//		["%1",_x] call BP_fnc_debugConsoleFormat;
	//	} count diag_activeMissionFSMs;
	//};

	sleep 5;
	
	false
};
