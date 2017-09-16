/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define private		0
#define protected		1
#define public		2

#define NO_SIDE -1		// (Optimised) Animals
#define EAST 0			// (Russian)
#define WEST 1			// (NATO)
#define RESISTANCE 2	// Guerilla 
#define CIVILIAN 3
#define NEUTRAL 4
#define ENEMY 5
#define FRIENDLY 6
#define LOGIC 7

class CfgVehicles 
{
	class CAManBase;
	class zZombie_Base : CAManBase 
	{
		scope = private;
		side = EAST;
		modelSides[] = {NO_SIDE, EAST, WEST, CIVILIAN};
		glassesEnabled = 0;
		model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
		vehicleClass = "Zombie";
		displayName = "Zombie";
		
		//Zombie Move Animations
		moves = "CfgMovesBPZombie1";
       
		//Vanilla FSMs
		//fsmFormation = "Formation";
		
		//Custom FSMs
		//fsmFormation = "breakingpoint_infected\scripts\formation.fsm";
        //fsmDanger = "breakingpoint_infected\scripts\formationDanger.fsm";
		
		//Disable FSMs
		fsmFormation = "";
		fsmDanger = "";
		
		maxSpeed = 24;
        formationX = 1;
        formationZ = 1;
        precision = 1;
	
		canHideBodies = 0;
		canDeactivateMines = 0;
		hideUnitInfo = 1;
		enableGPS = 0;
		isMan = false;
		weapons[] = {};
		magazines[] = {};
		respawnWeapons[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		sensitivity = 4;	// sensor sensitivity
		sensitivityEar = 2;
		faceType = "Man_A3";
		identityTypes[] = {"BP_Zombie1"};
		class TalkTopics {};
		languages[] = {"EN"};

		//Hidden Selection Textures
		hiddenSelections[] = {"Camo1", "Camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Clothes2.paa", "\A3\Characters_F\OPFOR\Data\tech_CO.paa"};

		//Remove Zombies Making Normal Human Sounds on These Effects
        class SoundEquipment {
			civilian[]={};
			soldier[]={};
		};
        class SoundGear {
			primary[]={};
			secondary[]={};
		};
        class SoundBreath {
			breath[]={};
		};
        class SoundDrown {
			breath[]={};
        };
        class SoundInjured {
			breath[]={};
        };
        class SoundBleeding {
			breath[]={};
        };
        class SoundBurning {
			breath[]={};
        };
        class SoundChoke {
			breath[]={};
        };
        class SoundRecovered {
			breath[]={};
        };
		
		//Zombie Event Handlers
		class Eventhandlers {
			init = "_this call BP_fnc_zombieInitialize;";
			local = "_this call BP_fnc_zombieLocal;";
			handledamage = "_this call BP_fnc_damageHandlerZ;";
			killed = "_this call BP_fnc_zombieKilled;";
		};
		
		//Wounds / Blood Textures
		class Wounds {
			tex[] = {};
			//mat[] = {};
			//mat[] = {"\breakingpoint\textures\custom.rvmat", "\breakingpoint\textures\custom.rvmat", "\breakingpoint\textures\custom.rvmat"};
			mat[] = {"A3\Characters_F\OPFOR\Data\clothing_injury.rvmat", "A3\Characters_F\OPFOR\Data\clothing_injury.rvmat", "A3\Characters_F\OPFOR\Data\clothing_injury.rvmat"};
		};
		
		//Hit Points / Damage
		class HitPoints {
			class HitHead {
				armor = 0.3;
				material = -1;
				name = "head_hit";
				passThrough = true;
				memoryPoint = "pilot";
			};
			
			class HitBody : HitHead {
				armor = 2;
				name = "body";
				memoryPoint = "aimPoint";
			};
			
			class HitSpine : HitHead {
				armor = 2;
				name = "Spine2";
				memoryPoint = "aimPoint";
			};
			
			class HitHands : HitHead {
				armor = 0.5;
				material = -1;
				name = "hands";
				passThrough = true;
			};
			
			class HitLArm : HitHands {
				name = "LeftArm";
				memoryPoint = "lelbow";
			};
			
			class HitRArm : HitHands {
				name = "RightArm";
				memoryPoint = "relbow";
			};
			
			class HitLForeArm : HitHands {
				name = "LeftForeArm";
				memoryPoint = "lwrist";
			};
			
			class HitRForeArm : HitHands {
				name = "RightForeArm";
				memoryPoint = "rwrist";
			};
			
			class HitLHand : HitHands {
				name = "LeftHand";
				memoryPoint = "LeftHandMiddle1";
			};
			
			class HitRHand : HitHands {
				name = "RightHand";
				memoryPoint = "RightHandMiddle1";
			};
			
			class HitLegs : HitHands {
				name = "legs";
				memoryPoint = "pelvis";
			};
			
			class HitLLeg : HitHands {
				name = "LeftLeg";
				memoryPoint = "lknee";
			};
			
			class HitLLegUp : HitHands {
				name = "LeftUpLeg";
				memoryPoint = "lfemur";
			};
			
			class HitRLeg : HitHands {
				name = "RightLeg";
				memoryPoint = "rknee";
			};
			
			class HitRLegUp : HitHands {
				name = "RightUpLeg";
				memoryPoint = "rfemur";
			};
		};
	};
	
	class BPZombie_Rebel1 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Rebel1.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Rebel2 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Rebel2.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		identityTypes[] = {"BP_Zombie1"};
	};
	
	class BPZombie_Rebel3 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Rebel3.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\loc_opfor01_1_co.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};	

	class BPZombie_Guardian1 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Guardian1.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"breakingpoint\textures\clothing\gracenko_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};	

	class BPZombie_Guardian2 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Guardian4.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Guardian3 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Guardian3.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		identityTypes[] = {"BP_Zombie2"};
	};		

	class BPZombie_Survivalist1 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Survivalist1.p3d";
	    hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	    identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Survivalist2 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Survivalist2.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_classes\textures\ghillie_top_desert_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Survivalist3 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_ghillie\models\ghilliegrass.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures2\ghillie_4_co.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};
	
	class BPZombie_Refugee1 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Refugee1.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\overall_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Refugee2 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Refugee2.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"breakingpoint\textures\clothing\worker_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class BPZombie_Refugee3 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Refugee3.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		identityTypes[] = {"BP_Zombie2"};
	};
	class BPZombie_Hunter1 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Hunter1.p3d";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\acr_soldier_nic_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};
	class BPZombie_Hunter2 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Hunter2.p3d";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\acr_soldier_nic_co.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};
	class BPZombie_Hunter3 : zZombie_Base {
		scope = protected;
		model = "\breakingpoint_classes\models\BP_Hunter3.p3d";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\acr_soldier_nic_co.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};
};

/*
	class z_villager1 : zZombie_Base {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian1.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class z_villager2 : z_villager1 {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian2.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};
	
	class z_villager3 : z_villager1 {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian3.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class z_villager4 : z_villager1 {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian4.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};

	class z_villager5 : z_villager1 {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian5.paa"};
		identityTypes[] = {"BP_Zombie1"};
	};

	class z_villager6 : z_villager1 {
		model = "\A3\Characters_F\Civil\c_poloshirt.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Civilian6.paa"};
		identityTypes[] = {"BP_Zombie2"};
	};
		
	class z_suit1 : zZombie_Base {
		zombieLoot = "civilian";
		model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
		modelSides[] = {3, 1};
		identityTypes[] = {"BP_Zombie1"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Clothes1.paa"};
	};
	
	class z_suit2 : z_suit1 {
		zombieLoot = "civilian";
		model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
		modelSides[] = {3, 1};
		identityTypes[] = {"BP_Zombie2"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_infected\textures\clothing\BP_Zombie_Clothes1.paa"};
	};
	class z_soldier: zZombie_Base
	{
		displayName = "Zombie Soldier";
		zombieLoot = "military";
		class HitPoints: HitPoints
		{
			class HitHead
			{
				armor = 0.3;
				material = -1;
				name = "head_hit";
				passThrough = 1;
			};
			class HitBody
			{
				armor = 2.4;
				material = -1;
				name = "body";
				passThrough = 1;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
			};
		};
	};
	class z_soldier_pilot: z_soldier
	{
		displayName = "Zombie Soldier (Pilot)";
		class HitPoints: HitPoints
		{
			class HitHead
			{
				armor = 2;
				material = -1;
				name = "head_hit";
				passThrough = 1;
			};
			class HitBody
			{
				armor = 3;
				material = -1;
				name = "body";
				passThrough = 1;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
			};
		};
	};
	class z_soldier_heavy: z_soldier
	{
		displayName = "Zombie Soldier (Heavy)";
		class HitPoints: HitPoints
		{
			class HitHead
			{
				armor = 1;
				material = -1;
				name = "head_hit";
				passThrough = 1;
			};
			class HitBody
			{
				armor = 2.4;
				material = -1;
				name = "body";
				passThrough = 1;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
			};
		};
	};
};
*/
