/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgFunctions
{
	init = "breakingpoint_functions\initFunctions.sqf";
	
	class BreakingPoint_Shared
	{
		tag = "BP";
		requiredAddons[] = {"breakingpoint","breakingpoint_code"};
		file = "\breakingpoint_functions\functions";
		class Threading {
			file = "\breakingpoint_functions\functions\Threading";
			class addThreadHandle {};
			class resetThreadHandles {};
		};
		class Traps {
			file = "\breakingpoint_functions\functions\Traps";
			class trapActivate {};
			class trapCollect {};
			class trapDeactivate {};
			class trapInit {};
			class trapTrigger {};
		};
		class Fire {
			file = "\breakingpoint_functions\functions\Fire";
			class fireDelete {};
		};
		class Geometry {
			file = "\breakingpoint_functions\functions\Geometry";
			class dirTo {};
			class distance2D {};
			class distance2Dsqr {};
			class getLineDist {};
			class inAngleSector {};
			class relativeDirTo {};
			class relPos {};
			class relScaledDist {};
			class terrainGradAngle {};
		};
		class Strings {
			file = "\breakingpoint_functions\functions\Strings";
			class inString {};
			class checkName {};
			class addPrepd {};
			class floatToString {};
			class maxAbs {};
			class numOp {};
			class numPrep {};
			class positionToString {};
			class locationToString {};
			class strNumCompare {};
			class strNumFormat {};
			class strNumSubtract {};
			class trunkZero {};
		};
		class Code {
			file = "\breakingpoint_functions\functions\Code";
			class compileFinal {};
		};
		class Faction {
			file = "\breakingpoint_functions\functions\Faction";
			class getFactionName {};
			class getFactionLevel {};
			class getFactionPoints {};
			class getFactionKillPoints {};
			class getFactionOwner {};
			class checkFactionClothing {};
		};
		class Medical {
			file = "\breakingpoint_functions\functions\Medical";
			class damageEvent {};
			class damageHandler {};
			class damageHandlerHit {};
			class damageHandlerExplosion {};
			class damageHandlerVehicle {};
			class damageHandlerZ {};
			class sumMedical {};
		};
		class Object {
			file = "\breakingpoint_functions\functions\Object";
			class objProcessHit {};
			class objSound {};
			class objSpeak {};
			class objVehicleKilled {};
			class objCheck {};
		};
		class World {
			file = "\breakingpoint_functions\functions\World";
			class getBuildingID {};
			class isInsideBuilding {};
			class isInsideBuildingPos {};
			class setPitchBank {};
			class sunRise {};
			class surfaceNoise {};
			class nearbyPlayers {};
			class nearbyPlayersList {};
			class nearbyAnimals {};
			class nearbyAnimalsList {};
			class nearbyVehicles {};
			class isInDebug {};
			class databasePos {};
			class getTerrainGradient {};
			class isOutOfBounds {};
		};
		class Debug {
			file = "\breakingpoint_functions\functions\Debug";
			class debugConsole {};
			class debugConsoleFormat {};
		};
		class Arrays {
			file = "\breakingpoint_functions\functions\Arrays";
			class buildWeightedArray {};
			class arrayDelete {};
		};
		class Inventory {
			file = "\breakingpoint_functions\functions\Inventory";
			class addItem {};
			class addWeaponArray {};
			class cargoToPairs {};
			class getCargoMags {};
			class addCargoMag {};
			class removeCargoMag {};
			class getFullInventory {};
			class setFullInventory {};
			class weaponsItems {};
			class getSaveInventory {};
			class getObjectInventory {};
			class setObjectInventory {};
			class isEmptyInventory {};
		};
		class Local {
			file = "\breakingpoint_functions\functions\Local";
			class localSetFuel {};
			class onLootInit {};
			class onLootLocal {};
			class onAnimalInit {};
			class onAnimalLocal {};
		};
		class Vehicle {
			file = "\breakingpoint_functions\functions\Vehicle";
			class vehicleHitpoints {};
			class vehicleHitpointsDmg {};
			class vehicleHandleFuel {};
			class vehicleHandleRepair {};
			class vehicleHandleRemove {};
		};
		class Zombies {
			file = "\breakingpoint_functions\functions\Zombies";
			class zombieInitialize {};
			class zombieKilled {};
			class zombieLocal {};
		};
		class Group {
			file = "\breakingpoint_functions\functions\Group";
			class groupCreateUID {};
			class groupGetMembers {};
		};
		class Strongholds {
			file = "\breakingpoint_functions\functions\Strongholds";
			class strongholdNearby {};
			class strongholdNearbyRadius {};
			class strongholdGetLogic {};
			class strongholdGetLogicNearby {};
			class posNearStronghold {};
		};
	};
};

