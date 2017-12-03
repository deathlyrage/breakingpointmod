/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgFunctions
{
	class BreakingPoint_Client
	{
		tag = "BP";
		file = "\breakingpoint_client\functions";
		requiredAddons[] = {"breakingpoint_client"};
		class Misc {
			file = "\breakingpoint_client\functions\Misc";
			class customChat {};
			class switchMove {};
			class resetSelfActions {};
		};
		class Actions
		{
			file = "\breakingpoint_client\functions\Actions";
			class explodeObject {};
			class undeadAttack {};
			class houseExplosiveAdd {};
			class houseInfo {};
			class loadTurretAmmo {};
			class medicAnim {};
			class windCheck {};
			class trapUpdate {};
			class constructStorage {};
			class constructTrap {};
			class build {};
			class fireMake {};
			class firePack {};
			class flipVehicle {};
			class ejectParachute {};
			class pushBoat {};
			class forceSave {};
			class fuelFill {};
			class groupAdd {};
			class groupDel {};
			class hostageAdd {};
			class hostageDel {};
			class hostageEscape {};
			class hostageFood {};
			class hostageWater {};
			class playerFood {};
			class playerWater {};
			class partRemove {};
			class siphonFuel {};
			class lootBody {};
			class eatBody {};
			class objectDestroy {};
			class objectIgnite {};
			class entityIgnite {};
			class unpack {};
			class waterFill {};
			class groupFix {};
			class tameDog {};
			class safeLock {};
			class houseLock {};
			class houseUnlock {};
			class houseReset {};
			class cook {};
			class boil {};
			class drink {};
			class eat {};
			class sprayCan {};
			class gatherMeat {};
			class hideBody {};
			class refuel {};
			class repair {};
			class studyBody {};
			class useMeds {};
		};
		class Safe {
			file = "\breakingpoint_client\functions\Safe";
			class safeKeypad {};
			class safeKeypadSet {};
		};
		class Strongholds {
			file = "\breakingpoint_client\functions\Strongholds";
			class strongholdCheck {};
			class strongholdEnter {};
			class strongholdLeave {};
		};
		class Dog {
			file = "\breakingpoint_client\functions\Dog";
			//Event Handlers
			class dogInit {};
			class dogLocal {};
			class dogHandleDamage {};
			class dogKilled {};

			//Utility Functions
			class dogFindTargetAgent {};
			class dogNameSet {};
			class loadDog {};
			class spawnDog {};
		};
		class Dog_Actions {
			file = "\breakingpoint_client\functions\Actions\dog";
			class dogFeed {};
			class dogFollow {};
			class dogMove {};
			class dogSpeak {};
			class dogSpeed {};
			class dogStay {};
			class dogTrackAnimal {};
			class dogTrackPlayer {};
			class dogAlertPlayer {};
			class dogAlertStorage {};
			class dogAlertVehicle {};
			class dogCombatMode {};
			class dogWarn {};
		};
		class Television_Actions {
			file = "\breakingpoint_client\functions\Actions\television";
			class teleOn {};
			class teleOff {};
			class teleFull {};
			class teleCam {};
		};
		class Events {
			file = "\breakingpoint_client\functions\Events";
			class onFactionPoints {};
			class onDraw3D {};
		};
		class Group {
			file = "\breakingpoint_client\functions\Group";
			class groupIconInit {};
			class groupIconUpdate {};
			class groupIconDraw {};
		};
		class General {
			file = "\breakingpoint_client\functions\General";
			class eyeDir {};
			class losChance {};
			class losCheck {};
			class angleCheck {};
			class attackCheck {};
			class buildingUpdate {};
			class fileExists {};
			class pickupBike {};
			class dropWeaponHolderMag {};
		};
		class GUI {
			file = "\breakingpoint_client\functions\GUI";
			class onPause {};
			class skipBriefing { preInit = 1; };
			class spaceInterrupt {};
			class spaceInterruptInv {};
			class updateGui {};
			class UpdateUI {};
			class loginError {};
			class gameError {};
			class vonChannelID {};
			class vonEvent {};
			class loginUI {};
			class loginUILoaded {};
			class loadFactionStatsDiary{};
			class factionStatsDiary{};
		};
		class Inventory {
			file = "\breakingpoint_client\functions\Inventory";
			class magazineCheck {};
			class onInventoryOpened {};
			class onInventoryClosed {};
			class inventorySelectItem {};
			class inventoryTakeAll {};
			class inventoryChangeSkin {};
			class onTakeItem {};
			class onPutItem {};
		};
		class Sound {
			file = "\breakingpoint_client\functions\Sound";
			class playMPSound {};
		};
		class Storage {
			file = "\breakingpoint_client\functions\Storage";
			class onStorageInit {};
			class onStorageKilled {};
			class onStorageLocal {};
		};
		class Player {
			file = "\breakingpoint_client\functions\Player";
			class death {};
			class fired {};
			class updateVars {};
			class spawnCheck {};
			class medSave {};
			class resetPlayerNamespace {};
			class animalCheck {};
			class checkStealthVisual {};
			class checkStealthAudio {};
			class damageActions {};
			class spawnLoot {};
			class spawnLootBox {};
			class spawnLootHeliCrash {};
			class selfActions {};
		};
		class Vehicle {
			file = "\breakingpoint_client\functions\Vehicle";
			class vehicleDamage {};
			class vehicleInit {};
			class vehicleInteract {};
			class vehicleKilled {};
			class vehicleEngine {};
		};
		class Debug {
			file = "\breakingpoint_client\functions\Debug";
			class InitDebug {};
			class lootPos {};
			class vehiclePos {};
		};
		class World {
			file = "\breakingpoint_client\functions\World";
			class buildingSpawnLoot {};
			class buildingSpawnZombies {};
			class logicSpawnLoot {};
			class thirskSnow {};
		};
		class Init {
			file = "\breakingpoint_client\functions\Init";
			class initPublicEH {};
			class initVars {};
			class initVarsOnce {};
			class initLoot {};
			class initMedical {};
		};
		class _Medical {
			file = "\breakingpoint_client\functions\Medical";
			class medicalBulletHit {};
			class medicalDamageHandle {};
			class medicalDamageType {};
			class medicalEvent {};
			class medicalPitchWhine {};
			class medicalPlayerBleed {};
			class medicalRemoveMedicActions {};
			class medicalRemoveSelfActions {};
			class medicalSync {};
			class medicalUnconscious {};
			class medicalUnconsciousRecover {};
		};
		class Zombies {
			file = "\breakingpoint_client\functions\Zombies";
			class zombieAttack {};
			class zombieCheck {};
			class zombieFindTargetAgent {};
			class zombieGenerate {};
			class zombieLoiter {};
			class zombieAlert {};
			class zombieWildSpawn {};
			class zombieFired {};
		};
	};
};
