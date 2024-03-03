/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

//#include "CfgLoot.hpp"
#include "CfgObjectLoot.hpp"

//Loot Box Class Names (Military Very Small) - BP_AmmoBoxNew - BP_AmmoBoxOld 

//Loot Box Class Names (Military Small) - BP_AmmoCrateNew - BP_AmmoCrateOld

//Loot Box Class Names (Military Universal Weapons Crates) - BP_WeaponCrateNew - BP_WeaponCrateOld

//Loot Box Class Names (Military Too Large For Buildings Weapon/Ammo Crates) - BP_HeavyWeaponCrate - BP_VehicleAmmoCrate - BP_AirDropCrate - BP_AmmoPallet1 - BP_AmmoPallet2 - BP_AmmoPallet3 - BP_AmmoPallet4

//Loot Box Class Names (Civilian Objects) - BP_CardboardBox_1 - BP_CardboardBox_2 - BP_CardboardBox_3 - BP_Bag1 - BP_Bag2 - BP_LuggageBags - BP_Trashcan - BP_Packs

//Loot Box Class Nmes (Industrial Objects) - BP_Dumpster1 - BP_Dumpster2 - BP_Dumpster3 - BP_Dumpster4 - BP_Dumpster5 - BP_Skip1 - BP_Skip2 - BP_Skip3 - BP_Skip4 - BP_Skip5

//Loot Box Class Names (Hospital) - BP_Medicalbox

//Loot Box Class Names (HighEnd) - BP_AmmoPallet4


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////---ALTIS BUILDING LOOT---//////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CfgBuildingLoot 
{
	class Default {
		zombieChance = 0.1;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0;
		lootPos[] = {};
		itemType[] = {};
		itemChance[] = {};
		hangPos[] = {};
		vehPos[] = {};
		lootMin = 1;
		lootMax = 3;
	};
	class Master {
		weapons[] = {
			"SMAW",
			"Javelin",
			"Stinger"
		};
	};
	class Residential: Default {
		zombieChance = 0.15;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
            {"BP_CardboardBox_2","object","Supermarket"},
            {"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Trash"},
			{"BP_LuggageBags","object","Residential"},
			{"BP_Packs","object","Residential"}				
		};
		itemChance[] =	{
			0.01,	//BP_Surplus
			0.22,	//BP_CardBoardBox2
			0.25,	//BP_CardBoardBox3
			0.25,	//BP_Trashcan
			0.25,   //BP_Bag1
			0.25,   //BP_Bag2
			0.50,   //BP_LuggageBags
			0.25    //BP_Packs
		};		
	};
	class Residential2: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
            {"BP_CardboardBox_2","object","Supermarket"},
            {"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_WeaponCrateOld","object","Residential2"},
			{"BP_LuggageBags","object","Residential"},
			{"BP_Packs","object","Residential"}			
		};
		itemChance[] =	{
			0.01,	//BP_Surplus
			0.07,	//BP_CardBoardBox2
			0.10,	//BP_CardBoardBox3
			0.10,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.01,   //BP_WeaponCrateOld
			0.35,   //BP_LuggageBags
			0.15    //BP_Packs
		};		
	};
	
	class Supermarket: Default {
		lootChance = 0.05;
		minRoaming = 0;
		maxRoaming = 1;
		zombieChance = 0.3;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		itemType[] = {
			//{"BP_CardboardBox_1","object","Office"},
            {"BP_CardboardBox_2","object","Supermarket"},
            {"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Trash"},
			{"BP_LuggageBags","object","Residential"},
			{"BP_Packs","object","Residential"}	
		};
		itemChance[] =	{
			//0.10,	//BP_CardBoardBox1
			0.35,	//BP_CardBoardBox2
			0.05,	//BP_CardBoardBox3
			0.10,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.10,    //BP_LuggageBags
			0.10    //BP_Packs
		};		
	};	
	class Office: Default {
		lootChance = 0.10;
		minRoaming = 0;
		maxRoaming = 1;
		zombieChance = 0.10;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootPos[] = {};
		itemType[] =	{
			{"BP_CardboardBox_1","object","Office"},
            {"BP_CardboardBox_2","object","Supermarket"},
            {"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Trash"},
			{"BP_LuggageBags","object","Residential"},
			{"BP_Packs","object","Residential"}
		};
		itemChance[] =	{
			0.25,	//BP_CardBoardBox1
			0.01,	//BP_CardBoardBox2
			0.05,	//BP_CardBoardBox3
			0.10,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.10,    //BP_LuggageBags
			0.10    //BP_Packs
		};		
	};	
	class Hospital: Default {
		zombieChance = 0.4;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Medic","BPZombie_Scientist"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
			{"BP_MedicalBox","object","Hospital"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_WeaponCrateOld","object","Residential2"},
			{"BP_MedicalboxHelicrash","object","Hospital"}	
		};
		itemChance[] =	{
			0.50,	//BP_MedicalBox
            0.10,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.05,   //Weapons
			0.20    //Med_Bag			
		};		
	};
	class Windmill: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.25;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Trash"},
			{"BP_WeaponCrateOld","object","WindmillWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_AmmoBoxOld","object","WindmillAcc"}
		};
		itemChance[] =	{
			0.10,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.15,   //WINDMILL WPN
			0.01,   //SURPLUS WPN
			0.30    //WINDMILL ACC 
		};		
	};	
	class Farm: Default {
		zombieChance = 0.1;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.10;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Generic"},
			{"BP_AmmoBoxOld","object","WindmillAcc"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_CardboardBox_4","object","Farm"}
		};
		itemChance[] =	{
			0.15,   //BP_Bag1
			0.15,   //BP_Bag2
			0.15,   //BP_WindmillAcc
			0.01,   //SURPLUS WPN
			0.50    //BP_Farm
		};		
	};
	class Industrial: Default {
		zombieChance = 0.2;
		zombieClass[] = {"BPZombie_Construction1","BPZombie_Construction2","BPZombie_Construction3","BPZombie_Construction4","BPZombie_Mechanic","BPZombie_EngineerF","BPZombie_Worker"};
		minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.40;
		lootPos[] = {};
		itemType[] =	{
			{"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Trash"},
			{"BP_Skip1","object","Industrial"},
			{"BP_Skip2","object","IndustrialVehicle"},
			{"BP_Skip3","object","Industrial"},
			{"BP_Skip4","object","IndustrialVehicle"},
			{"BP_Skip5","object","Industrial"},
			{"BP_Dumpster1","object","IndustrialVehicle"},
			{"BP_Dumpster2","object","Industrial"},
			{"BP_Dumpster3","object","IndustrialVehicle"},
			{"BP_Dumpster4","object","Industrial"},
			{"BP_Dumpster5","object","IndustrialVehicle"}	
		};
		itemChance[] =	{
			0.05,	//BP_CardBoardBox3
			0.20,	//BP_Trashcan
			0.30,   //BP_Bag1
			0.10,	//BP_Skip1
			0.10,	//BP_Skip2
            0.10,   //BP_Skip3
            0.10,	//BP_Skip4
            0.10,	//BP_Skip5
            0.10,	//BP_Dumpster1
            0.10,	//BP_Dumpster2
            0.10,	//BP_Dumpster3
            0.10,	//BP_Dumpster4
            0.10	//BP_Dumpster5
		};		
	};	
	class IndustrialSmall: Default {
		zombieChance = 0.2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.4;
		lootPos[] = {};
		itemType[] =	{
			{"BP_CardboardBox_3","object","Generic"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Farm"}	
		};
		itemChance[] =	{
			0.05,	//BP_CardBoardBox3
			0.20,	//BP_Trashcan
			0.30,   //BP_Bag1
			0.30    //BP_Bag2
		};		
	};	
	class MilitaryGeneral: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoBoxOld","object","MilitaryGeneralAcc"},
			{"BP_AmmoCrateOld","object","MilitaryGeneralAcc"},
		    {"BP_WeaponCrateOld","object","MilitaryGeneralWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxOld
			0.20,   //BP_AmmoCrateOld
			0.35,   //BP_WeaponCrateOld
			0.02,   //BP_WeaponCrateOld
			0.10,   //TRASH
			0.10,   //GENERIC
			0.10    //BP_MedicalBox
		};		
	};
	class MilitarySpecial: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05; 
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoBoxOld","object","MilitarySpecialAcc"},
			{"BP_AmmoCrateOld","object","MilitarySpecialAcc"},
		    {"BP_WeaponCrateOld","object","MilitarySpecialWpn"},
			{"BP_WeaponCrateOld","object","MilitaryGeneralWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxOld
			0.10,   //BP_AmmoCrateOld
			0.20,   //BP_WeaponCrateOld
			0.20,   //BP_WeaponCrateOld
			0.02,   //BP_WeaponCrateOld
			0.10,   //TRASH
			0.10,   //GENERIC
			0.10    //BP_MedicalBox
		};		
	};	
	class MilitaryAirfield: Default {
		zombieChance = 0.5;
		minroaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoBoxNew","object","MilitaryAirfieldSpc"},
			{"BP_AmmoCrateOld","object","MilitarySpecialAcc"},
            {"BP_AmmoCrateNew","object","MilitaryAirfieldAcc"},
			{"BP_WeaponCrateNew","object","MilitaryAirfieldWpn"},
		    {"BP_WeaponCrateOld","object","MilitarySpecialWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.03,	//BP_AmmoBoxNew
			0.10,	//BP_AmmoBoxOld
			0.10,	//BP_AmmoCrateNew
			0.20,   //BP_WeaponCrateNew
			0.20,   //BP_WeaponCrateOld
			0.02,   //BP_WeaponSurplus
			0.10,   //TRASH
			0.10,   //GENERIC
			0.10,   //CARDBOARD
			0.10	//BP_MedicalBox
		};		
	};
	class MilitaryTower: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.15;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoCrateNew","object","MilitaryTower"},
			{"BP_Bag1","object","Generic"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_CardboardBox_1","object","Office"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxNew
			0.10,   //GENERIC
			0.02,   //SURPLUS
			0.10	//BP_AmmoBoxOld
		};		
	};
	class MilitaryRanger: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
			{"BP_AmmoBoxNew","object","MilitaryRangerAcc"},
            {"BP_AmmoCrateNew","object","MilitaryRangerAcc"},
			{"BP_WeaponCrateNew","object","MilitaryRangerWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.12,	//BP_AmmoBoxNew
			0.12,	//BP_AmmoCrateNew
			0.30,   //BP_WeaponCrateNew
			0.04,   //BP_WeaponCrateNew
			0.15,   //GENERIC
			0.10    //BP_MedicalBox
		};		
	};

	class GhostHotelAcc: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.07;
		lootPos[] = {};
		itemType[] =	{
			{"BP_AmmoBoxNew","object","HotelAcc"},
            {"BP_AmmoCrateNew","object","HotelAcc"},
			{"BP_WeaponCrateNew","object","HotelWpn"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.25,	//BP_AmmoBoxNew
			0.25,	//BP_AmmoCrateNew
			0.02,   //BP_WeaponCrateNew
			0.25,   //GENERIC
			0.03    //BP_MedicalBox
		};		
	};
	
	class GhostHotelWpn: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.07;
		lootPos[] = {};
		itemType[] =	{
			{"BP_AmmoBoxNew","object","HotelAcc"},
            {"BP_AmmoCrateNew","object","HotelAcc"},
			{"BP_WeaponCrateNew","object","HotelWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxNew
			0.10,	//BP_AmmoCrateNew
			0.20,   //BP_WeaponCrateNew
			0.03,   //BP_WeaponSurplus
			0.20,   //GENERIC
			0.10    //BP_MedicalBox
		};		
	};
	
//HELI CRASH TABLES		
	class MilitarCrash: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	{		
			{"ItemSurgeryKit","toolbelt"},
			{"BP_5Rnd_300_Mag","magazine"},
			{"BP_MedicalboxHelicrash","object"},
			{"V_TacVest_brn_BP","vest"},
			{"BP_SVT40","weapon"},
			{"BP_m9tac","weaponA"},
			{"BP_ScarH","weaponA"},
			{"BP_MX_SW","weapon"},
			{"BP_Carryall_blk","backpack"},
			{"BP_Zafir","weapon"},
			{"V_RebreatherB","vest"},
			{"BP_AWSM","weapon"},
			{"BP_MK20_GL","weapon"},
			{"BP_R700","weaponA"},
			{"BP_Wetsuit","uniform"},
			{"BP_MXM_black","weaponA"},
			{"BP_G36C","weapon"},
			{"BP_Garand","weapon"},
			{"BP_gemtech9","toolbelt"},
			{"Rangefinder","weaponNA"},
			{"BP_1Rnd_HE_shell","magazine"},
			{"BP_100Rnd_127x99_box","magazine"},
			{"BP_Crossbow","weapon"},
			{"BP_SUD_AK109","weaponA"},
			{"BP_SW44","weaponA"},
			{"BP_M4_300MK","weaponA"}
			
		};
		itemChance[] =	{
			0.13,   //SURGERY KIT
			0.05,   //.300 WINMAG
			0.18,	//MED BOX
			0.15,	//V_TacVest_camo
			0.11,	//SVT40
			0.12,	//M9TAC
			0.06,	//SCARH
			0.15,	//MX SW
			0.03,	//CARRYALL
			0.12,	//ZAFIR LMG
			0.06,	//REBREATHER
			0.02,	//AWSM
			0.13,	//MK20 GL
			0.05,	//R700
			0.18,	//WETSUIT
			0.10,   //MXM SpecOps
			0.11,	//G36C
			0.12,	//Garand
			0.02,	//SUPPRESSOR
			0.03,	//RANGEFINDERS
			0.15,   //HE SHELL
			0.01,   //50CAL M2 BOX
			0.07,    //Crossbow
			0.07,    //AK109
			0.07,    //BP_SW44
			0.07    //BP_M4_300MK
		};
	};
	class HeliCrash: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	{
			{"BP_MX_SW","weapon"},
			{"BP_RFB","weapon"},
			{"BP_MedicalboxHelicrash","object"},
			{"V_TacVest_camo_BP","vest"},
            {"MeleeClub","weapon"},
			{"BP_Garand","weapon"},
			{"BP_MK20Spec","weaponA"},
			{"BP_Uzi","weapon"},
			{"BP_Kar98k","weapon"},
			{"BP_VSS","weaponA"},
			{"BP_1Rnd_HE_shell","magazine"},
			{"BP_MX_GL","weapon"},
			{"V_Rangemaster_belt_BP","vest"},
			{"BP_22Sup","toolbelt"},
			{"ItemBandage","magazine"},
			{"BP_SUD_AK109","weapon"},
			{"V_Chestrig_blk_BP","vest"},
			{"BP_Rem6","weapon"},
			{"Rangefinder","weaponNA"},
			{"ItemKnife","magazine"},
			{"BP_CPad","toolbelt"},
			{"BP_M4_300MK","weapon"},
			{"BP_762x51_Box_Tracer","magazine"},
			{"BP_100Rnd_65x39","magazine"},
			{"Binocular","weaponNA"},
			{"ItemSurgeryKit","toolbelt"},
			{"V_PlateCarrierIA2_dgtl_BP","vest"},
			{"BP_AR10_WDL","weapon"},
			{"BP_SW44","weaponA"},
			{"BP_MedicalboxHelicrash","object"},
			{"U_B_GhillieSuit_BP","uniform"}
		};
		itemChance[] =	{
			0.10,	//MX SW
			0.11,	//KELTECRFB
			0.13,	//MEDICAL PACK
			0.12,	//TAC VEST
			0.11,	//CLUB
			0.10,	//Garand
			0.06,	//MK20 SPEC
			0.10,	//UZI
			0.11,	//Kar98k
			0.10,	//VSS
			0.09, 	//1Rnd HE Shell
			0.14,	//MX GL
			0.13,	//RANGEMASTERBELT
			0.08,	//22SUPPRESSOR
			0.10,	//BANDAGE
			0.10,	//AK109
			0.10,	//CHESTRIG
			0.06,	//Grendel
			0.07,	//RANGEFINDER
			0.10,   //KNIFE
			0.10,   //CHEEKPAD
			0.08,   //M4300K
			0.10,	//150 ROUND 7.62 BOX
			0.10,	//100 ROUND 6.5
			0.12,	//BINOCULAR
			0.07,   //SURGERY KIT
			0.03,    //PLATECARRIER
			0.10,    //AR10
			0.10,    //BP_SW44
			0.02,    //MEDICALBOX
			0.01	//Marksmen Ghillie
		};
	};
	class HeliCrash_No50s: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	{		
			{"BP_SR25","weaponA"},
			{"BP_SA582","weapon"},
			{"BP_FNFAL","weapon"},
			{"BP_Mark14","weapon"},
			{"BP_VS121","weapon"},
			{"BP_NegevNG5","weapon"},
			{"BP_Minimi_HG","weapon"},
			{"BP_R700","weaponA"},
			{"BP_M110","weaponA"},
			{"BP_1Rnd_HE_shell","magazine"},
			{"BP_MedicalboxHelicrash","object"},
			{"V_TacVest_khk_BP","vest"},
			{"BP_TreeGhillie","uniform"},
			{"V_RebreatherB","vest"},
			{"BP_Mk12mod1Spec","weaponA"},
			{"BP_M21K","weaponA"},
			{"BP_M24Des","weaponA"},
			{"BP_muzzle_snds_H","toolbelt"},
			{"BP_20Rnd_65x47_Lapua","magazine"},
			{"BP_150Rnd_762x51_Box","magazine"},
			{"ItemSurgeryKit","toolbelt"},
			{"U_B_GhillieSuit_BP","uniform"}
		};
		itemChance[] =	{
			0.05,	//SR25
			0.10,   //SA58
			0.10,   //FNFAL
			0.05,	//MARK14
			0.06,	//VS121
			0.06,	//MINIMI 762
			0.07,	//MINIMI HG
			0.08,   //R700
			0.06,	//M110
			0.04,	//HE SHELL
			0.11,	//MED BOX
			0.10,	//TACTICAL VEST
			0.02,	//TREE GHILLIE
			0.03,	//REBREATHER
			0.09,	//MK12MOD1
			0.08,	//M21K
			0.06,   //M24
			0.06,	//5.56 SUPPRESSOR
			0.05,	//LAPUA 6.5x47MM MAG
			0.05,   //150RND 762.51MM BOX
			0.10,   //SURGERY KIT
			0.01	//Marksmen Ghillie
		};
	};
	class BodyPile: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	{
			{"Meleehatchet","weapon"},
			{"V_TacVest_oli_BP","vest"},
			{"V_Rangemaster_belt_BP","vest"},
			{"V_BandollierB_rgr_BP","vest"},
			{"ItemMatchbox","magazine"},
            {"MeleeClub","weapon"},
			{"BP_StoneGhillie","uniform"},
			{"BP_TreeGhillie","uniform"},
			{"BP_DirtGhillie","uniform"},	
			{"BP_Guarilla_Camo","uniform"},
			{"BP_Guarilla_Leader","uniform"},
			{"BP_Guarilla_Faded","uniform"},
			{"MeleeShovel","weapon"},
			{"ItemDuctTape","magazine"},
			{"ItemBrick1","magazine"},
			{"ItemFuelcanLargeEmpty","magazine"},
			{"ItemFuelcanEmpty","magazine"},
			{"ItemNails","magazine"},
			{"ItemNettingMaterial","magazine"},
			{"ItemWoodenPoles","magazine"},			
			{"MeleeHammer","weapon"},
			{"MeleePickaxe","weapon"},
			{"BP_flashlight","toolbelt"}
		};
		itemChance[] =	{
			0.10,   //HATCHET
			0.10,   //TACVEST
			0.12,	//BELT
			0.11,	//BANDOLIER
			0.10,	//MATCHES
			0.10,	//CLUB
			0.03,	//STONE
			0.03,	//TREE
			0.03,	//DIRT
			0.12,	//GCAMO
			0.12,	//GLEADER
			0.12,	//GFADED
			0.18,	//SHOVEL
			0.15,	//DUCTTAPE
			0.12,	//BRICK
			0.08,	//FUELCANEMPTYLARGE
			0.10,	//FUELCANEMPTY
			0.12,	//NAILS
			0.12,	//NETTING
			0.12,	//WOODPOLES
			0.10,	//HAMMER
			0.10,	//PICKAXE
			0.10	//FLASHLIGHT
		};
	};
	class GarageFloor: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 0.15;
		lootPos[] = {};
		itemType[] =	{
			{"PartGlass","magazine"},
			{"PartSteel","magazine"},
			{"ItemToolbox","toolbelt"},
			{"ItemLiquidResin","magazine"},
			{"ItemMatchbox","magazine"},
            {"MeleeCrowbar","weapon"},
			{"PartEngine","magazine"},
			{"PartWheel","magazine"},
			{"ItemFuelhoseKit","magazine"},	
			{"ItemBattery","magazine"},
			{"ItemEngineCoolant","magazine"},
			{"PartFiberGlass","magazine"},
			{"MeleeShovel","weapon"},
			{"ItemDuctTape","magazine"},
			{"ItemBrick1","magazine"},
			{"ItemFuelcanLargeEmpty","magazine"},
			{"ItemFuelcanEmpty","magazine"},
			{"ItemNails","magazine"},
			{"ItemNettingMaterial","magazine"},
			{"ItemWoodenPoles","magazine"},			
			{"MeleeHammer","weapon"},
			{"MeleePickaxe","weapon"},
			{"ItemElectronics","magazine"}
		};
		itemChance[] =	{
			0.08,   //TOUGHGLASSPANEL
			0.03,   //STEEL
			0.08,	//TOOLBOX
			0.11,	//BANDOLIER
			0.11,	//MATCHES
			0.12,	//CROWBAR
			0.07,	//ENGINE
			0.09,	//TIRE
			0.11,	//FUEL HOSE KIT
			0.11,	//BATTERY
			0.11,	//ENGINE COOLANT
			0.09,	//FIBER GLASS
			0.12,	//SHOVEL
			0.13,	//DUCTTAPE
			0.12,	//BRICK
			0.08,	//FUELCANEMPTYLARGE
			0.10,	//FUELCANEMPTY
			0.13,	//NAILS
			0.12,	//NETTING
			0.12,	//WOODPOLES
			0.12,	//HAMMER
			0.12,	//PICKAXE
			0.07	//ELECTRONICS BOARD
		};
	};
	class DeerStandGround: Default {
		zombieChance = 0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {};
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"BP_TreeGhillie","uniform"},
			{"ItemWatch","toolbelt"},
			{"ItemCompass","toolbelt"},
			{"ItemRadio","toolbelt"},
			{"ItemKnife","magazine"},
			{"Binocular","weaponNA"},
			{"Rangefinder","weaponNA"},
			{"BP_FieldPack_ocamo","backpack"},
			{"Waterbot","magazine"},
			{"Meleehatchet","weapon"},
			{"BP_Crossbow","weapon"},
			{"BP_Crossbow_DigitCamo","weaponA"},
			{"BP_Arrow_Mag","magazine"},
			{"BP_1866C","weapon"},
			{"BP_Arrow_Poison","magazine"},
			{"BP_LeeEnfield","weapon"},
			{"BP_LeeEnfield2","weaponA"},
			{"BP_LeeEnfield_old","weapon"},
			{"BP_HA550","weaponA"},
			{"BP_MC550","weaponA"},
			{"BP_CZ550_old","weaponA"}
		};
		itemChance[] =	{
			0.01,	//GHILLIE
			0.10,	//WATCH
			0.10,	//COMPASS
			0.10,	//RADIO
			0.11,	//KNIFE
			0.12,	//BINOCULARS
			0.02,	//RANGEFINDER
			0.06,	//Fieldpack
			0.10,	//Waterbottle
			0.08,	//Hatchet
			0.09,	//Crossbow
			0.08,	//Crossbow camo
			0.14,	//Bolt
			0.10,	//1866C
			0.03,	//POISON BOLT
			0.11,	//ENFIELD
			0.10,	//ENFIELD2
			0.12,	//OLDENFIELD
			0.06,	//HA550
			0.06,	//MC550
			0.09	//CZ550
		};
	};
	class Castle: Default {
		zombieChance = 0.4;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.75;
		lootPos[] = {};
		itemType[] =	{		
			{"BP_Medicalbox","object"},
			{"AmmoBoxSmall_762","object"},
			{"V_TacVest_camo","vest"},
			{"Rangefinder","weaponNA"},
			//{"BP_G18","weapon"},
			{"BP_Bergen_rgr","backpack"}, 
			{"BP_Kitbag_sgg","backpack"}, 
			{"BP_Bergen_rgr","backpack"}, 
			{"BP_FieldPack_ocamo","backpack"}
		};
		itemChance[] =	{
			0.03,	//CAJA MEDICA
			0.03,	//AMMO BOX 7.62
			0.02,	//CAMO CLOTHING
			0.01,	//Telemetro
			//0.01,	//G18
			0.04, 	//ALICE PACK
			0.04, 	//ASSAULT PACK
			0.03,   //BRITISH BACKPACK
			0.01	//CZECH BACKPACK
			
		};
	};
	class AmmoPallet4: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.85;
		lootPos[] = {};
		itemType[] =	{		
			{"BP_AmmoPallet4","object","AmmoPallet4"},
			{"BP_AmmoPallet4","object","AmmoPalletTroll"}
		};
		itemChance[] =	{
			0.75,	//Military Pallet
			0.25   //Troll
		};
	};
	class ApexMilBox1: Default {
		zombieChance = 1;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.50;
		lootPos[] = {};
		itemType[] =	{		
			{"BP_ApexMilBox1","object","ApexMilBox1"},
			{"BP_ApexMilBox2","object","ApexMilBox2"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.01,	//ApexMilBox1
			0.01,	//ApexMilBox2
			0.10,	//WWII
			0.10,   //Generic
			0.10    //Hospital
		};
	};
	
	class ApexMilBox2: Default {
		zombieChance = 1;
		minRoaming = 0;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.50;
		lootPos[] = {};
		itemType[] =	{		
			{"BP_ApexMilBox1","object","ApexMilBox1"},
			{"BP_ApexMilBox2","object","ApexMilBox2"},
			{"BP_AmmoCrateNew","object","HotelAcc"},
			{"BP_WeaponCrateNew","object","HotelWpn"},
			{"BP_AmmoCrateNew","object","MilitaryRangerAcc"},
			{"BP_WeaponCrateNew","object","MilitaryRangerWpn"},
			{"BP_WeaponCrate_WWII","object","MilitarySurplusWpn"},
			{"BP_MedicalBox","object","Hospital"},
			{"BP_CardboardBox_3","object","Generic"}
		};
		itemChance[] =	{
			0.10,	//ApexMilBox1
			0.10,	//ApexMilBox2
			0.10,	//GHOST
			0.10,	//GHOST
			0.10,	//RANGER
			0.10,	//RANGER
			0.10,	//WWII
			0.15,    //Hospital
			0.15   //Generic
		};
	};
	

	class UnderWater: Default {
		zombieChance = 0.0;
		minRoaming = 0;
		maxRoaming = 0;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	{		
			{"DM_M4Box","vehicle"}
		};
		itemChance[] =	{
			1.00	//WEAPON BOX
			
		};
	};	

	class CivilCrash: Default 
	{
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 1;
		lootPos[] = {};
		itemType[] =	
		{
			{"Binocular","weaponNA"},
			{"ItemKnife","magazine"},
			{"ItemRadio","toolbelt"},
			{"BP_3Rnd_HE_shell","magazine"},					
			{"BP_MXM","weapon"},
			{"BP_MX_GL","weapon"},		
			{"BP_Kitbag_sgg","backpack"},
			{"V_Rangemaster_belt_BP","vest"},
			{"BP_Carryall_mcamo","backpack"},
			{"ItemMap","toolbelt"},
			{"ItemGPS","toolbelt"},
			{"BP_Bergen_rgr","backpack"}, 
			{"BP_FieldPack_ocamo","backpack"},
			{"V_Chestrig_blk_BP","vest"},
			//{"U_B_CombatUniform_mcam_worn_BP","uniform"},
			//{"U_Competitor_BP","uniform"},
			//{"U_I_CombatUniform_BP","uniform"},
			//{"U_O_OfficerUniform_ocamo_BP","uniform"},
			{"BP_Wetsuit","uniform"},
			{"V_RebreatherB","vest"},
			{"BP_Garand","weapon"},
			{"BP_GarandK","weapon"},
			{"BP_GarandU","weaponA"},
            {"BP_Kar98","weapon"},
			{"BP_Kar98k","weapon"},
			{"BP_Kar98z","weaponA"},
			{"BP_BAR","weapon"},
			{"BP_1911","weapon"},
			{"BP_SVT40","weapon"},
			{"BP_SVT40_2","weaponA"},
			{"BP_M1903","weaponA"},
			{"BP_M1903K","weaponA"},
			{"BP_M16OLD","weapon"},
			{"BP_SA58","weapon"},
			{"BP_M21","weaponA"},
			{"BP_FNFAL","weapon"}
		};
		itemChance[] =
		{	
			0.12,	//Binoculars
			0.12,	//Hunting Knife
			0.04,	//GPS		
			0.12,	//HE SHELL 3RND			
			0.12,	//MXM
			0.04,	//MX GL
			0.12, 	//Assault Pack (ACU)
		    0.12, 	//Patrol Pack (coyote)
		    0.06, 	//Backpack (coyote)
			0.10,	//Mapa
			0.15,	//GPS
			0.03,	//British Backpack
			0.02,	//Czech Backpack
			//0.01,	//TERRORIST CLOTHING
			//0.02,	//URBAN SOLDIER CLOTHING
			//0.02,	//URBAN SPEC-OPS CLOTHING
			//0.02,	//SPEC-OPS CLOTHING
			0.02,	//RUSSIAN CLOTHING
			0.02,	//FRENCH CLOTHING
			0.02,   //REBREATHER
			0.04,	//GARAND
			0.02,	//GARAND K
			0.02,	//GARAND SCOPE
			0.02,	//K98
			0.02,	//K98K
			0.01,	//K98 SCOPE
			0.02,	//BAR	
			0.08,	//1911
			0.03,	//SVT40
			0.02,	//SVT40 SCOPE
			0.02,	//M1903
			0.01,	//M1903K
			0.09,	//M16A2
			0.05,	//AK47
			0.01,	//M21
			0.04	//FNFAL
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////---A2 BUILDING LOOT---///////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//A2 RESIDENTIAL	
	class A2Residential: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
			{"BP_CardboardBox_1","object","Residential"},
            {"BP_CardboardBox_2","object","Residential"},
            {"BP_CardboardBox_3","object","Residential"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Generic"},
			{"BP_LuggageBags","object","Residential"},
			{"BP_Packs","object","Residential"}					
		};
		itemChance[] =	{
			0.20,	//BP_CardBoardBox1
			0.07,	//BP_CardBoardBox2
			0.10,	//BP_CardBoardBox3
			0.20,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.10,    //BP_LuggageBags
			0.15    //BP_Packs
		};		
	};
//A2 SUPERMARKET	
	class A2Supermarket: Default {
		lootChance = 0.05;
		minRoaming = 0;
		maxRoaming = 1;
		zombieChance = 0.4;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		itemType[] = {
			{"BP_CardboardBox_1","object","Supermarket"},
            {"BP_CardboardBox_2","object","Supermarket"},
            {"BP_CardboardBox_3","object","Supermarket"},
            {"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Generic"},
			{"BP_Packs","object","Residential"}
		};
		itemChance[] =	{
			0.10,	//BP_CardBoardBox1
			0.35,	//BP_CardBoardBox2
			0.05,	//BP_CardBoardBox3
			0.20,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10,    //BP_Bag2
			0.10    //BP_Packs
		};		
	};
//A2 MEDICAL	
	class A2Medical: Default {
		zombieChance = 0.4;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Medic","BPZombie_Scientist"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
			{"BP_MedicalBox","object","Hospital"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Generic"}	
		};
		itemChance[] =	{
			0.50,	//BP_MedicalBox
            0.20,	//BP_Trashcan
			0.10,   //BP_Bag1
			0.10    //BP_Bag2			
		};		
	};
//A2 INDUSTRIAL	
	class A2Industrial: Default {
		zombieChance = 0.2;
		zombieClass[] = {"BPZombie_Construction1","BPZombie_Construction2","BPZombie_Construction3","BPZombie_Construction4","BPZombie_Mechanic","BPZombie_EngineerF","BPZombie_Worker"};
		minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.50;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Skip1","object","Industrial"},
			{"BP_Skip2","object","IndustrialVehicle"},
			{"BP_Skip3","object","Industrial"},
			{"BP_Skip4","object","IndustrialVehicle"},
			{"BP_Skip5","object","Industrial"},
			{"BP_Dumpster1","object","IndustrialVehicle"},
			{"BP_Dumpster2","object","Industrial"},
			{"BP_Dumpster3","object","IndustrialVehicle"},
			{"BP_Dumpster4","object","Industrial"},
			{"BP_Dumpster5","object","IndustrialVehicle"}	
		};
		itemChance[] =	{
			0.10,	//BP_Skip1
			0.10,	//BP_Skip2
            0.10,   //BP_Skip3
            0.10,	//BP_Skip4
            0.10,	//BP_Skip5
            0.10,	//BP_Dumpster1
            0.10,	//BP_Dumpster2
            0.10,	//BP_Dumpster3
            0.10,	//BP_Dumpster4
            0.10	//BP_Dumpster5
		};		
	};
//A2 INDUSTRIAL SMALL	
	class A2IndustrialSmall: Default {
		zombieChance = 0.2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.50;
		lootPos[] = {};
		itemType[] =	{
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_CardboardBox_3","object","Industrial"},
            {"BP_Trashcan","object","Trash"}	
		};
		itemChance[] =	{
			0.10,	//BP_CardBoardBox3
			0.10,	//BP_CardBoardBox3
			0.20	//BP_Trashcan
		};		
	};
//A2 FARM	
	class A2Farm: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.10;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Bag1","object","Generic"},			
			{"BP_Bag2","object","Generic"},			
			{"BP_CardboardBox_4","object","Farm"},
			{"BP_CardboardBox_4","object","Industrial"}					
		};
		itemChance[] =	{
			0.15,   //BP_Bag1	
			0.15,   //BP_Bag2		
			0.10,	//BP_CardBoardBox4
			0.10	//BP_CardBoardBox4					
		};		
	};
//A2 MILITARY CIVILIAN	
	class A2MilitaryCivilian: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoPallet1","object","Supermarket"},
            {"BP_AmmoPallet1","object","Residential"},
            {"BP_AmmoPallet2","object","Generic"},
            {"BP_AmmoPallet2","object","Trash"},			
			{"BP_AmmoPallet3","object","CivilianWpn"},
			{"BP_AmmoPallet3","object","CivilianAcc"}		
		};
		itemChance[] =	{
			0.10,	//BP_AmmoPallet1
			0.10,	//BP_AmmoPallet1
			0.20,	//BP_AmmoPallet2
			0.20,   //BP_AmmoPallet2
			0.10,   //BP_AmmoPallet3		
			0.10    //BP_AmmoPallet3
		};		
	};	
	
//A2 MILITARY CASTLE	
	class A2MilitaryCastle: Default {
		zombieChance = 0.5;
		minRoaming = 1;
		maxRoaming = 4;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.25;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Bag1","object","Generic"},
			{"BP_Packs","object","CivilianAcc"},
			{"BP_WeaponCrateOld","object","CastleWpn"},
			{"BP_AmmoBoxOld","object","CastleAcc"}
		};
		itemChance[] =	{
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.10,   //WINDMILL WPN
			0.25    //WINDMILL ACC 
		};		
	};	
//A2 MILITARY DEERSTAND	
	class A2MilitaryDeerstand: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.25;
		lootPos[] = {};
		itemType[] =	{
			{"BP_Bag1","object","Generic"},
			{"BP_Bag2","object","Generic"},
			{"BP_WeaponCrateOld","object","DeerstandWpn"},
			{"BP_AmmoBoxOld","object","DeerstandAcc"}
		};
		itemChance[] =	{
			0.10,   //BP_Bag1
			0.10,   //BP_Bag2
			0.10,   //WINDMILL WPN
			0.25    //WINDMILL ACC 
		};		
	};

//A2 MILITARY CAMP
	class A2MilitaryCamp: Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 3;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.05;
		lootPos[] = {};
		itemType[] =	{
			{"BP_AmmoBoxNew","object","CampAcc"},
            {"BP_AmmoCrateNew","object","CampAcc"},
			{"BP_WeaponCrateNew","object","CampWpn"},
			{"BP_CardboardBox_4","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.15,	//BP_AmmoBoxNew
			0.15,	//BP_AmmoCrateNew
			0.30,   //BP_WeaponCrateNew
			0.20,   //BP_CardboardBox_4
			0.10    //BP_MedicalBox
		};		
	};	
	class A2MilitaryVanWreck: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 3;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoPallet1","object","Supermarket"},
            {"BP_AmmoPallet1","object","Residential"},
            {"BP_AmmoPallet2","object","Generic"},
            {"BP_AmmoPallet2","object","Trash"},			
			{"BP_AmmoPallet3","object","MilitaryGeneralWpn"},
			{"BP_AmmoPallet3","object","Residential2"}		
		};
		itemChance[] =	{
			0.10,	//BP_AmmoPallet1
			0.10,	//BP_AmmoPallet1
			0.20,	//BP_AmmoPallet2
			0.20,   //BP_AmmoPallet2
			0.05,   //BP_AmmoPallet3		
			0.05    //BP_AmmoPallet3
		};		
	};		
	class A2MilitaryBarracks: Default {
		zombieChance = 0.5;
		minRoaming = 1;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoBoxOld","object","MilitarySpecialAcc"},
			{"BP_AmmoCrateOld","object","MilitarySpecialAcc"},
		    {"BP_WeaponCrateOld","object","MilitarySpecialWpn"},
			{"BP_WeaponCrateOld","object","MilitaryGeneralWpn"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxOld
			0.10,   //BP_AmmoCrateOld
			0.20,   //BP_WeaponCrateOld
			0.20,   //BP_WeaponCrateOld
			0.10,   //BP_Trashcan
			0.10,   //BP_Bag1
			0.01    //BP_MedicalBox
		};		
	};
	class A2MilitaryATC: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoBoxNew","object","MilitaryAirfieldSpc"},
			{"BP_AmmoCrateOld","object","MilitarySpecialAcc"},
            {"BP_AmmoCrateNew","object","MilitaryAirfieldAcc"},
			{"BP_WeaponCrateNew","object","MilitaryAirfieldWpn"},
		    {"BP_WeaponCrateOld","object","MilitarySpecialWpn"},
			{"BP_Trashcan","object","Trash"},
			{"BP_Bag1","object","Generic"},
			{"BP_CardboardBox_3","object","Generic"},
			{"BP_MedicalBox","object","Hospital"}
		};
		itemChance[] =	{
			0.05,	//BP_AmmoBoxNew
			0.10,	//BP_AmmoBoxOld
			0.10,	//BP_AmmoCrateNew
			0.20,   //BP_WeaponCrateNew
			0.20,   //BP_WeaponCrateOld
			0.10,   //BP_Trashcan
			0.10,   //BP_Bag1
			0.10,   //BP_CardboardBox_3
			0.02    //BP_MedicalBox
		};		
	};	
	class A2MilitaryRadioTower: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
            {"BP_AmmoCrateNew","object","MilitaryTower"},
			{"BP_Bag1","object","Generic"},
			{"BP_CardboardBox_1","object","Office"}
		};
		itemChance[] =	{
			0.10,	//BP_AmmoBoxNew
			0.10,   //BP_Bag1
			0.10	//BP_AmmoBoxOld
		};		
	};
	class A2MilitaryPlaneWreck: Default {
		zombieChance = 0.5;
		minRoaming = 0;
		maxRoaming = 5;
		zombieClass[] = {"BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3","BPZombie_Optout","BPZombie_Optout2","BPZombie_Optout3","BPZombie_Optout4","BPZombie_Optout5","BPZombie_Optout6","BPZombie_Optout7","BPZombie_Optout8"};
		lootChance = 0.20;
		lootPos[] = {};
		itemType[] =	{
			{"BP_AirDropCrate","object","MilitaryRangerAcc"},
			{"BP_HeavyWeaponCrate","object","MilitaryRangerWpn"}

		};
		itemChance[] =	{
			0.15,	//BP_AirDropCrate
			0.07	//BP_HeavyWeaponCrate
		};		
	};	
#include "CfgBuildingPos.hpp"
};
