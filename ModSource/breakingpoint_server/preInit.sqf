/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Preload Variables
initialized = false;
allowConnection = false;
shutdown = false;

//Stash Extra Client Functions
BP_ClientFuncs = [];

//PVEHs
BP_SetPosATL = [];

//Determine If Dev Mission File is in Place
BP_Dev = (getNumber (missionConfigFile >> "enableDebugConsole") == 2);

BP_ServerLock = false;

//Server Cleanup Variables
BP_Cleanup_lastCheck = diag_tickTime;
BP_Cleanup_lastDead = diag_tickTime;
BP_Cleanup_lastSync = diag_tickTime;
BP_Cleanup_lastLoot = diag_tickTime;
BP_Cleanup_lastLootAll = diag_tickTime;

//Helicrashes
_cfgHelicrash = (configFile >> "CfgHelicrash");
if (isArray (_cfgHelicrash >> "World" >> worldName)) then
{
	BP_HeliCrash = true;
	BP_HeliCrashModels = getArray (_cfgHelicrash >> "models");
	BP_HeliCrashPos = getArray (_cfgHelicrash >> "World" >> worldName);
} else {
	BP_HeliCrash = false;
	BP_HeliCrashModels = [];
	BP_HeliCrashPos = [];
};

//Planecrashes
_cfgCargocrash = (configFile >> "CfgCargocrash");
if (isClass (_cfgCargocrash >> "World" >> worldName)) then
{
	BP_CargoCrash = true;
	BP_CargoCrashModels = getArray (_cfgCargocrash >> "models");
	BP_CargoCrashWaypoints = getArray (_cfgCargocrash >> "World" >> worldName >> "waypoints");
	BP_CargoCrashDroppoints = getArray (_cfgCargocrash >> "World" >> worldName >> "droppoints");
	BP_CargoCrashCrashpoints = getArray (_cfgCargocrash >> "World" >> worldName >> "crashpoints");
	BP_CargoCrashWaypoints = BP_CargoCrashWaypoints call BIS_fnc_arrayShuffle;
	BP_CargoCrashDroppoints = BP_CargoCrashDroppoints call BIS_fnc_arrayShuffle;
	
} else {
	BP_CargoCrash = false;
	BP_CargoCrashModels = [];
	BP_CargoCrashWaypoints = [];
	BP_CargoCrashDroppoints = [];
	BP_CargoCrashCrashpoints = [];
};

//Preload Server Variables
BP_HC_ID = 0;
BP_HC_PID = "NULL";
BP_HC_OBJ = objNull;

BP_DeadCharacters = [];
BP_DeadTickets = [];

BP_serverObjectMonitor = [];
BP_ObjectUpdateQueue = [];
BP_ObjectDestroyQueue = [];
BP_Buildings = [];
BP_BuildingsData = [];
BP_BuildingsLocks = [];
BP_Traps = [];
BP_Strongholds = [];
BP_UndeadQueue = [];
BP_AIRespawn = [];
BP_AIRespawnGroups = [];
BP_AIGroups = [];
BP_RadioChannels = [];
BP_DupeNetIDs = [];
BP_DupeMagIDs = [];
BP_DupeSelfMagIDs = [];
BP_AntiDisconnectIDs = [];
BP_AntiDisconnectObjs = [];
BP_HackMagIDs = [];
BP_groupLeaveTimers = [];
BP_applyBandage = [];
BP_applyPainkiller = [];
BP_applySurgery = [];
BP_applyMorphine = [];

//Preload Code
call compile preprocessFileLineNumbers "\breakingpoint_server\publicEH.sqf";
call BP_fnc_initVarsOnce;
call BP_fnc_initLoot;

//Weather Types
BP_Weather_None = 0;
BP_Weather_Default = 1;
BP_Weather_Sunny = 2;
BP_Weather_Overcast = 3;
BP_Weather_Rain = 4;
BP_Weather_Storm = 5;
BP_Weather_ThunderStorm = 6;
BP_Weather_Fog = 7;
BP_Weather_SyncTime = 0;

//Make Weather Sunny On Server Startup
BP_Weather_Current = BP_Weather_None;
