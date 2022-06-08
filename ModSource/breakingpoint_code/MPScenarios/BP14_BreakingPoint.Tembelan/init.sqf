enableSaving [false, false];

BP_ServerInstance = (paramsArray select 0);
BP_Debug = (paramsArray select 1) == 1;
BP_HC = (paramsArray select 2) == 1;
BP_VIP = (paramsArray select 3) == 1;
BP_DynamicWeather = (paramsArray select 4) == 1;
BP_ClientSimulationManager = (paramsArray select 5) == 1;
BP_ServerSimulationManager = (paramsArray select 6) == 1;
BP_ThreadedCleanup = (paramsArray select 7) == 1;
BP_LootMax = (paramsArray select 8);
BP_LootServer = (paramsArray select 9) == 1;
BP_LegionOnly = (paramsArray select 10) == 1;
BP_FastBoot = (paramsArray select 11) == 1;

//Client Init Only
if (isServer) exitWith {};
if (!hasInterface) exitWith {};
if (isDedicated) exitWith {};

//Require This Mission to be used in MP Only.
if (!isMultiplayer) exitWith { call BIS_fnc_shutdown; };

// Breaking Point - Player Client Integration
initialized = true;

waitUntil {time > 0};
enableEnvironment [false,true];