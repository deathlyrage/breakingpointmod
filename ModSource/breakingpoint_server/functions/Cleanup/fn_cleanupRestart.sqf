scriptName "BPServer_fnc_cleanupRestart";

shutdown = true;

//Handle Hive Extension Shutdown Queries
["CHILD:109:"] call BPServer_fnc_callExtensionAsync;

//Lock Server
call BPServer_fnc_rconLock;

//Broadcast Warning Message
BP_GameError = 8;
publicVariable "BP_GameError";

//Delete All Zombies
{deleteVehicle _x} count entities "zZombie_Base";

//Delete All Loot
{deleteVehicle _x} count entities "BP_LootBox";

//Delete All Local Animals
{ if (local _x) then { deleteVehicle _x; }; } count entities "Animal";

//Delete All Helicrashes
{deleteVehicle _x} count allMissionObjects "Land_Wreck_Heli_Attack_01_F";

//Delete All Fire Objects
{deleteVehicle _x} count allMissionObjects "BP_Fire";
{deleteVehicle _x} count allMissionObjects "BP_Smoke";
{deleteVehicle _x} count allMissionObjects "BP_SmokeShell";

//Delete All Weapon Holders
{deleteVehicle _x} count allMissionObjects "GroundWeaponHolder";
{deleteVehicle _x} count allMissionObjects "WeaponHolderSimulated";

//Process Update and Destroy Queue
_handle = [] spawn {
	scriptName "BP_cleanupRestart";
	call BPServer_fnc_updateQueueProcess;
	call BPServer_fnc_destroyQueueProcess;
};
[_handle] call BP_fnc_addThreadHandle;
