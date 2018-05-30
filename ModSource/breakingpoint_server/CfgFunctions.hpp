/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgFunctions
{
	//Server Override For Client Functions and Event Handlers
	class BreakingPoint_Client 
	{
		tag = "BP";
		requiredAddons[] = {"breakingpoint_code"};
		class Storage {
			file = "\breakingpoint_server\functions\Storage";
			class onStorageInit {};
			class onStorageLocal {};
			class onStorageKilled {};
		};
		class Dog {
			file = "\breakingpoint_server\functions\Dog";
			class dogInit {};
			class dogLocal {};
			class dogHandleDamage {};
			class dogKilled {};
			delete dogFindTargetAgent;
			delete dogNameSet;
			delete loadDog;
			delete spawnDog;
		};
		class Vehicle {
			file = "\breakingpoint_server\functions\Vehicle";
			class vehicleDamage {};
			class vehicleEngine {};
			class vehicleFuel {};
			class vehicleInit {};
			class vehicleInteract {};
			class vehicleKilled {};
			class vehicleRepair {};
			class vehicleRemove {};
			class vehicleLocal {};
			class spawnVehicle {};
		};
		class Client_Init {
			file = "\breakingpoint_server\functions\Client\Init";
			class initUpdateUI {};
		};
	};

	class BPServer
	{
		clientOnly = 0;
		class Server
		{
			class PreInit {
				description = "Server Pre-Init";
				file = "\breakingpoint_server\preInit.sqf";
				preInit = 1;
			};
			class PostInit {
				description = "Server Post-Init";
				file = "\breakingpoint_server\postInit.sqf";
				postInit = 1;
			};
		};
		class General {
			file = "\breakingpoint_server\functions\General";
			class objectUID {};
			class unitCleanup {};
			class checkObject {};
			class eventKill {};
			class radioCheck {};
			class customChat {};
			class getMagazineNames {};
			class getMagazineIDs {};
			class getMagazineLocality {};
			class playerCheck {};
			class freshSpawnCheck {};
			class spawnServerLoot {};
			class setTimerCallback {};
		};
		class Simulation {
			file = "\breakingpoint_server\functions\Simulation";
			class checkSimulation {};
			class checkSimulationLocal {};
			class checkVehicleSimulation {};
		};
		class Faction {
			file = "\breakingpoint_server\functions\Faction";
			class addFactionPoints {};
			class radioManage {};
			class radioManageRemove {};
		};
		class Actions {
			file = "\breakingpoint_server\functions\Actions";
			class hostageGive {};
			class hostageAdd {};
			class playerGive {};
			class groupInvite {};
			class groupLeaveTimer {};
		};
		class Traps {
			file = "\breakingpoint_server\functions\Traps";
			class publishTrap {};
			class deleteTrap {};
		};
		class Weather {
			file = "\breakingpoint_server\functions\Weather";
			class weatherChange {};
		};
		class Loot {
			file = "\breakingpoint_server\functions\Loot";
			class containerSpawnLoot {};
		};
		class Queue {
			file = "\breakingpoint_server\functions\Queue";
			class updateQueueAdd {};
			class updateQueueDel {};
			class updateQueueProcess {};
			class destroyQueueAdd {};
			class destroyQueueDel {};
			class destroyQueueProcess {};
		};
		class Cleanup {
			file = "\breakingpoint_server\functions\Cleanup";
			class cleanupLoot {};
			class cleanupLootAll {};
			class cleanupRestart {};
		};
		class Rcon {
			file = "\breakingpoint_server\functions\Rcon";
			class rconLock {};
			class rconUnlock {};
		};
		class Updates {
			file = "\breakingpoint_server\functions\Updates";
			class updateAll {};
			class updateTime {};
			class updateWeapons {};
			class updateMagazines {};
			class updateScripts {};
			class updateTraps {};
		};
		class Database {
			file = "\breakingpoint_server\functions\Database";
			class callExtension {};
			class callExtensionAsync {};
			class callExtensionAsyncLow {};
			class callExtensionAsyncCB {};
			class callExtensionDirect {};
			class callExtensionTicket {};
			class callExtensionResult {};
			class callExtensionArray {};
		};
		class Database_General {
			file = "\breakingpoint_server\functions\Database\General";
			class killLog {};
			class combatLog {};
			class storageLog {};
			class adminLog {};
		};
		class Database_Object {
			file = "\breakingpoint_server\functions\Database\Object";
			class updateObject {};
			class updateObjectForce {};
			class updateNearbyObjects {};
			class updateObjectDamage {};
			class updateObjectInventory {};
			class updateObjectPosition {};
		};
		class Database_Player {
			file = "\breakingpoint_server\functions\Database\Player";
			class dogSync {};
			class gearSync {};
			class logoutSync {};
			class medSync {};
			class posSync {};
			class statsSync {};
		};
		class Login {
			file = "\breakingpoint_server\functions\Login";
			class checkLogin {};
			class playerLogin {};
			class playerLoginAI {};
			class playerSetup {};
			class playerGearSet {};
			class factionGear {};
			class sendLogin {};
		};
		class Combatlog {
			file = "\breakingpoint_server\functions\Combatlog";
			class discoMorph {};
			class discoKilled {};
		};
		class Object {
			file = "\breakingpoint_server\functions\Object";
			class deleteObj {};
			class publishObj {};
			class destroyObj {};
			class lockObj {};
			class unlockObj {};
		};
		class Houses {
			file = "\breakingpoint_server\functions\Houses";
			class lockHouse {};
			class unlockHouse {};
			class publishHouse {};
			class deleteHouse {};
			class upgradeHouse {};
			class saveHouse {};
			class houseKilled {};
			class houseHandleDamage {};
		};
		class Events {
			file = "\breakingpoint_server\functions\Events";
			class onPlayerConnect {};
			class onPlayerDisconnect {};
			class traitorFlag {};
			class playerDeath {};
			class playerDeathReg {};
			class playerRespawn {};
			class playerLoot {};
			class medicalUpdate {};
			class setLocalVar {};
			class handleDisconnect {};
			class setPosATL {};
			class containerOpened {};
			class containerClosed {};
			class containerTakeAll {};
			class containerSpawn {};
			class simulationToggle {};
			class igniteEntity {};
			class checkHealRecent {};
		};
		class Wrecks {
			file = "\breakingpoint_server\functions\Wrecks";
			class helicrashCleanup {};
			class spawnCrashHeli {};
			class spawnCrashCargo {};
			class spawnCrashCar {};
			class spawnFerry {};
		};
	};
};

