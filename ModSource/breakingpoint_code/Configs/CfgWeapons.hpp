/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgWeapons 
{
	//Breaking Point Equip
	class Default;	// External class reference

	//Breaking Point - Uniform
	class U_B_CombatUniform_mcam_worn;
	class U_B_GhillieSuit;
	class U_Competitor;
	class U_I_CombatUniform;
	class U_I_GhillieSuit;
	class U_O_OfficerUniform_ocamo;
	class U_Rangemaster;
	class U_B_Wetsuit;
	class Vest_NoCamo_Base;
	class Vest_Camo_Base;
	class VestItem;
	class Bag_Base;
	class InventoryItem_Base_F;
	class U_B_HeliPilotCoveralls;
	class HeadgearItem;
	class U_B_CombatUniform_mcam_vest;
	class Vest_Base;
	class B_Soldier_base_F;
	class U_B_CombatUniform_mcam;
	class UniformItem;
	class Uniform_Base;
	class H_MilCap_ocamo;
	class ItemCore;
	class ItemInfo;
	class H_Cap_red;
	class U_B_FullGhillie_lsh;
	class U_BG_leader;
	class U_BG_Guerilla1_1;
	class U_BG_Guerilla3_2;
	class U_BG_Guerilla3_1;
	class H_HelmetB: ItemCore {
		/*extern*/ class ItemInfo;
	};

	class U_BasicBody;
	
	class BP_BasicBody : U_BasicBody
	{
		scope = 2;
		//picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
		//model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Underwear";
			containerClass = "Supply0";
			mass = 1;
		};
	};
	
	class BP_Poloshirt_blue : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_1_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class BP_Poloshirt_zed : Uniform_Base {
		scope = public;
		displayName = "Civ Zombie Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_Zombie_Civilian1.paa"};
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_zed_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class BP_Poloshirt_zed2 : Uniform_Base {
		scope = public;
		displayName = "Civ Zombie Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_Zombie_Civilian2.paa"};
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_zed2_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class BP_Poloshirt_zed3 : Uniform_Base {
		scope = public;
		displayName = "Military Zombie Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"Camo1", "Camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_Zombie_Clothes2.paa", "\A3\Characters_F\OPFOR\Data\tech_CO.paa"};
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_zed3_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
			hiddenSelections[] = {"Camo1", "Camo2"};
		};
	};
	
	class BP_Poloshirt_zed4 : Uniform_Base {
		scope = public;
		displayName = "RangeMaster Zombie Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_Zombie_Clothes1.paa"};
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_zed4_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class BP_Poloshirt_burgundy : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_2_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class BP_Poloshirt_stripped : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_3_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class BP_Poloshirt_tricolour : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_4_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class BP_Poloshirt_salmon : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_5_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class BP_Poloshirt_redwhite : Uniform_Base {
		scope = public;
		displayName = "Civilian Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "C_man_polo_6_BP";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class U_B_CombatUniform_mcam_worn_BP : U_B_CombatUniform_mcam_worn { //GOOD
		scope = 2;
		displayName = "Combat Clothing";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Soldier2_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 60;
		};
	};
	
	class U_B_CombatUniform_mcam_worn_BP_Z : U_B_CombatUniform_mcam_worn { //GOOD
		scope = 2;
		displayName = "Combat Clothing";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_soldier2_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 60;
		};
	};
	
	class U_I_OfficerUniform_BP: Uniform_Base { //GOOD
		scope = 2;
		displayName = "European Officer Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_IR_Officer_spc_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_officer_I";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 50;
		};
	};
	
	class U_I_OfficerUniform_BP_Z: Uniform_Base { //GOOD
		scope = 2;
		displayName = "European Officer Clothing";
		picture = "\A3\characters_f\data\ui\icon_U_IR_Officer_spc_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_officer_I_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 50;
		};
	};

	class U_B_GhillieSuit_BP : U_B_GhillieSuit {
	
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "B_sniper_F";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 100;
		};
	};

	class U_I_CombatUniform_BP : U_I_CombatUniform {  //GOOD
		scope = 2;
		displayName = "Soldier Clothing";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_soldier_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class U_I_CombatUniform_BP_Z : U_I_CombatUniform {  //GOOD
		scope = 2;
		displayName = "Soldier Clothing";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_soldier_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};

	class U_I_OfficerUniform_ocamo_BP : U_O_OfficerUniform_ocamo {  //NAKED
	    scope = 2;
		displayName = "Russian Officer Clothing";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_officer_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class U_I_OfficerUniform_ocamo_BP_Z : U_O_OfficerUniform_ocamo {  //NAKED
	    scope = 2;
		displayName = "Russian Officer Clothing";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_officer_F_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};

	class U_Rangemaster_BP : U_Rangemaster {
	
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "B_RangeMaster_F";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class U_Rangemaster_BP_Z : U_Rangemaster {
	
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "B_RangeMaster_F";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	//NEW CLASS CLOTHING
	
	class BP_Refugee_F: Uniform_Base {
		scope = 2;
		displayName = "Traitor Nomad";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_RefugeeF_F";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 40;
		};
	};
	
	class BP_Refugee_F_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Nomad";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_RefugeeF_Z";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 40;
		};
	};
	
	class BP_Refugee_1: Uniform_Base {
		scope = 2;
		displayName = "Nomad level 1";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee1_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Refugee_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Nomad";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee1_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Refugee_2: Uniform_Base {
		scope = 2;
		displayName = "Nomad level 2";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee2_F";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Refugee_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Nomad";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee2_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Refugee_3: Uniform_Base {
		scope = 2;
		displayName = "Nomad level 3";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee3_F";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Refugee_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Nomad";
		picture = "\breakingpoint_ui\icons\NomadIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Refugee3_Z";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Guardian_F: Uniform_Base {
		scope = 2;
		displayName = "Traitor Ranger";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_GuardianF_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Guardian_F_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Ranger";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_GuardianF_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Guardian_1: Uniform_Base {
		scope = 2;
		displayName = "Ranger level 1";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian1_F";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Guardian_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Ranger";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian1_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Guardian_2: Uniform_Base {
		scope = 2;
		displayName = "Ranger level 2";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian2_F";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Guardian_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Ranger";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian2_Z";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Guardian_3: Uniform_Base {
		scope = 2;
		displayName = "Ranger level 3";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian3_F";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 40;
		};
	};
	
	class BP_Guardian_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "fallen Ranger";
		picture = "\breakingpoint_ui\icons\RangerIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Guardian3_Z";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 40;
		};
	};
	
	class BP_Rebel_F: Uniform_Base {
		scope = 2;
		displayName = "Traitor Outlaw";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_RebelF_F";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 40;
		};
	};
	
	class BP_Rebel_F_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Outlaw";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_RebelF_Z";
			allowedSlots[] = {};
			containerClass = "Supply10";
			mass = 40;
		};
	};
	
	class BP_Rebel_1: Uniform_Base {
		scope = 2;
		displayName = "Outlaw level 1";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel1_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Rebel_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Outlaw";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel1_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Rebel_2: Uniform_Base {
		scope = 2;
		displayName = "Outlaw level 2";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel2_F";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Rebel_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Outlaw";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel2_Z";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Rebel_3: Uniform_Base {
		scope = 2;
		displayName = "Outlaw level 3";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel3_F";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Rebel_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Outlaw";
		picture = "\breakingpoint_ui\icons\OutlawIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Rebel3_Z";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Hunter_1: Uniform_Base {
		scope = 2;
		displayName = "Hunter level 1";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter1_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Hunter_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Hunter";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter1_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Hunter_2: Uniform_Base {
		scope = 2;
		displayName = "Hunter level 2";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter2_F";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Hunter_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Hunter";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter2_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 40;
		};
	};
	
	class BP_Hunter_3: Uniform_Base {
		scope = 2;
		displayName = "Hunter level 3";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter3_F";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 40;
		};
	};
	
	class BP_Hunter_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Hunter";
		picture = "\breakingpoint_ui\icons\HunterIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Hunter3_Z";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 40;
		};
	};
	
	class BP_Survivalist_1: Uniform_Base {
		scope = 2;
		displayName = "Survivalist level 1";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist1_F";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Survivalist_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Survivalist";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist1_Z";
			allowedSlots[] = {};
			containerClass = "Supply50";
			mass = 40;
		};
	};
	
	class BP_Survivalist_2: Uniform_Base {
		scope = 2;
		displayName = "Survivalist level 2";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist2_F";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 40;
		};
	};
	
	class BP_Survivalist_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Survivalist";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist2_Z";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 40;
		};
	};
	
	class BP_Survivalist_3: Uniform_Base {
		scope = 2;
		displayName = "Survivalist level 3";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist3_F";
			allowedSlots[] = {};
			containerClass = "Supply90";
			mass = 40;
		};
	};
	
	class BP_Survivalist_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Fallen Survivalist";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Survivalist3_Z";
			allowedSlots[] = {};
			containerClass = "Supply90";
			mass = 40;
		};
	};
	
	class BP_Survivalist_F: Uniform_Base {
		scope = 2;
		displayName = "Traitor Survivalist";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_SurvivalistF_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Survivalist_F_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_SurvivalistF_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Engineer_1: Uniform_Base {
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer1_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Engineer_1_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer1_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_Engineer_2: Uniform_Base {
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer2_F";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Engineer_2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer2_Z";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class BP_Engineer_3: Uniform_Base {
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer3_F";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 40;
		};
	};
	
	class BP_Engineer_3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "";
		picture = "breakingpoint_weaponsiconsicon_f_b_combatuniform_ocam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Engineer3_Z";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 40;
		};
	};
	
	class BP_OptOut: Uniform_Base {
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout_F";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_OptOut_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout_Z";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 40;
		};
	};
	
	class BP_OptOut2: Uniform_Base {
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout2_F";
			containerClass = "Supply20";
			mass = 10;
	    };
	};
	
	class BP_OptOut2_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout2_Z";
			containerClass = "Supply20";
			mass = 10;
	    };
	};
	
	class BP_OptOut3: Uniform_Base {
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout3_F";
			containerClass = "Supply20";
			mass = 10;
	    };
	};
	
	class BP_OptOut3_Z: Uniform_Base { //ZOMBIE
		scope = 2;
		displayName = "Independent";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Optout3_Z";
			containerClass = "Supply20";
			mass = 10;
	    };
	};
	
	class BP_Survivalist1: Uniform_Base {
		scope = 2;
		displayName = "Survivalist Ghillie";
		picture = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "I_sniper_F";
			containerClass = "Supply30";
			mass = 60;
		};
	};
	
	class BP_Shemag_bandit: H_HelmetB {
	    scope = 2;
		displayName = "Bandit Leader Shemag";
		picture = "\breakingpoint\textures\icons\bp_shemag_ca.paa";
		model = "\A3\Characters_F_Gamma\Guerrilla\headgear_shemagmask";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_Shemag_Bandit3_co.paa"};

		class ItemInfo: Iteminfo {
			mass = 10;
			allowedSlots[] = {901};
			uniformModel = "\A3\Characters_F_gamma\Guerrilla\headgear_shemagmask";
			modelSides[] = {6};
			armor = "0";
			passThrough = 1.0000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	//VESTS & BELTS
	
	class V_EngineerVest_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "TacVest (Engineer)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint\textures\backpack\tacticalvest_engineer_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 120;
			armor = "0";
			passThrough = 0.500000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_LBelt_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Light Equipment Belt";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_LBelt.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			uniformModel = "\breakingpoint_classes\models\BP_LBelt.p3d";
			containerClass = "Supply40";
			mass = 35;
			armor = "0";
			passThrough = 1;
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_MBelt_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Medium Equipment Belt";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_MBelt.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			containerClass = "Supply60";
			uniformModel = "\breakingpoint_classes\models\BP_MBelt.p3d";
			mass = 55;
			armor = "0";
			passThrough = 1;
			hitpointName = "HitLegs";
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_HBelt_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Heavy Equipment Belt";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_HBelt.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			containerClass = "Supply100";
			uniformModel = "\breakingpoint_classes\models\BP_HBelt.p3d";
			mass = 85;
			armor = "0";
			passThrough = 1;
			hitpointName = "HitLegs";
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_HVest_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Heavy Equipment Vest";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_HVest.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			containerClass = "Supply120";
			uniformModel = "\breakingpoint_classes\models\BP_HVest.p3d";
			mass = 95;
			armor = "0";
			passThrough = 1;
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_CPack_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Heavy Vest Pouch";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_CPack.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			containerClass = "Supply90";
			uniformModel = "\breakingpoint_classes\models\BP_CPack.p3d";
			mass = 50;
			armor = "0";
			passThrough = 1;
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_VPack_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Light Vest Pouch";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\breakingpoint_classes\models\BP_VPack.p3d";
		//hiddenSelections[] = {"camo"};
		//hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			allowedSlots[] = {};
			containerClass = "Supply50";
			uniformModel = "\breakingpoint_classes\models\BP_VPack.p3d";
			mass = 10;
			armor = "0";
			passThrough = 1;
			//hiddenSelections[] = {"camo"};
		};
	};
	
	class V_BanditBandolier_BP: Vest_Camo_Base {
		scope = 2;
		displayName = "Bandolier (Bandit)";
		picture = "\A3\characters_f\Data\UI\icon_V_BandollierB_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_BanditBandolier_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 20;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class BP_MilCap_Hero3: H_MilCap_ocamo {
		displayName = "Hero Medic Cap";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroCap3_co.paa"};
	};
	
	class BP_MilCap_Hero1: H_MilCap_ocamo {
		displayName = "Hero Cap";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroCap1_co.paa"};
	};
	
	class BP_HeroCap: H_Cap_red {
		displayName = "Hero Cap";
		picture = "\A3\characters_f\Data\UI\icon_h_cap_blk_cmmg_ca.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroCap_co.paa"};
	};
	
	class BP_HeroBoonie_cam: H_HelmetB {
		displayName = "Hero Boonie Hat";
		picture = "\A3\Characters_F\data\ui\icon_H_booniehat_mcamo_ca.paa";
		model = "\A3\Characters_F\Common\booniehat";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroCap2_co.paa"};

		class ItemInfo: Iteminfo {
			mass = 10;
			allowedSlots[] = {901};
			uniformModel = "\A3\Characters_F\Common\booniehat";
			modelSides[] = {6};
			armor = "0";
			passThrough = 1.000000;
		};
	};
	
	class BP_RogueHat: H_HelmetB {
		displayName = "Rogue Hat";
		picture = "\A3\Characters_F\data\ui\icon_h_booniehat_desert_ca.paa";
		model = "\breakingpoint\models\BP_roguehat.p3d";

		class ItemInfo: Iteminfo {
			mass = 10;
			allowedSlots[] = {901};
			uniformModel = "\breakingpoint\models\BP_roguehat.p3d";
			modelSides[] = {6};
			armor = "0";
			passThrough = 1.000000;
		};
	};
	
	class BP_Bandit_Bandanna: H_HelmetB {
		displayName = "$STR_A3_H_Bandanna_surfer0";
		picture = "\A3\characters_f\Data\UI\icon_H_Bandanna_cbr_CA.paa";
		model = "\A3\Characters_F\Civil\headgear_c_bandana1.p3d";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_BanditBandanna_co.paa"};

		class ItemInfo: ItemInfo {
			mass = 2;
			allowedSlots[] = {901};
			uniformModel = "\A3\Characters_F\Civil\headgear_c_bandana1.p3d";
			modelSides[] = {6};
			armor = "3*0";
			passThrough = 1;
		};
	};


	class V_Rangemaster_belt_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Utility Belt (Olive)";
		picture = "\A3\Characters_F\data\ui\icon_V_Belt_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_belt";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_belt";
			allowedSlots[] = {};
			containerClass = "Supply40";
			mass = 20;
			armor = "0";
			passThrough = 0.980000;
		};
	};
	
	class V_BandollierB_khk_BP: Vest_Camo_Base {
		scope = 2;
		weaponPoolAvailable = 1;
		displayName = "$STR_A3_V_BandollierB_khk0";
		picture = "\A3\characters_f\Data\UI\icon_V_BandollierB_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\vests_khk_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 20;
			armor = "0";
			passThrough = 0.930000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_BandollierB_cbr_BP: Vest_Camo_Base {
		scope = 2;
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		displayName = "$STR_A3_V_BandollierB_cbr0";
		picture = "\A3\Characters_F\data\ui\icon_V_bandollier_khk_CA.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\vests_khk_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 20;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_BandollierB_rgr_BP: Vest_Camo_Base {
		scope = 2;
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		displayName = "$STR_A3_V_BandollierB_rgr0";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\vests_rgr_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 20;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_BandollierB_blk_BP: Vest_Camo_Base {
		scope = 2;
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		displayName = "$STR_A3_V_BandollierB_blk0";
		picture = "\A3\characters_f\Data\UI\icon_V_bandollier_blk_CA.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\vests_blk_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 20;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_BandollierB_oli_BP: Vest_Camo_Base {
		scope = 2;
		model = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
		picture = "\A3\Characters_F_Beta\Data\ui\icon_V_Bandolier_oli_ca.paa";
		displayName = "$STR_A3_V_BANDOLLIERB_OLI0";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Beta\INDEP\Data\vests_oli_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			allowedSlots[] = {};
			containerClass = "Supply60";
			mass = 20;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_PlateCarrier1_rgr_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "$STR_A3_V_PlateCarrier1_rgr0";
		picture = "\A3\characters_f\Data\UI\icon_V_plate_carrier_1_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_vest01";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01";
			allowedSlots[] = {};
			containerClass = "Supply110";
			mass = 80;
			armor = "0";
			passThrough = 0.750000;
		};
	};

	class V_PlateCarrier2_rgr_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "$STR_A3_V_PlateCarrier1_cbr0";
		picture = "\A3\characters_f\Data\UI\icon_V_plate_carrier_1_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_vest01";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
			allowedSlots[] = {};
			containerClass = "Supply100";
			mass = 80;
			armor = "0";
			passThrough = 0.750000;
		};
	};

	class V_PlateCarrier3_rgr_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "$STR_A3_V_PlateCarrier2_rgr0";
		picture = "\A3\characters_f\Data\UI\icon_V_plate_carrier_2_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 100;
			armor = "0";
			passThrough = 0.750000;
		};
	};
	
	class BP_JungleGhillie_Uniform : Uniform_Base { //Full Ghillie (Jungle)
		author = "Bohemia Interactive";
		displayName = "Full Ghillie (Jungle)";
		DLC = "Expansion";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\data\suitpack_soldier_blufor_co.paa"};
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		scope = 2;
		class ItemInfo : UniformItem { //["InventoryItem_Base_F"]
			containerClass = "Supply60";
			mass = 80;
			uniformClass = "BP_Jungle_Ghillie";
			uniformModel = "-";
		};
	};
	
	class BP_Paramilitary_Jacket_Uniform : Uniform_Base { //Paramilitary Garb (Jacket)
		author = "Bohemia Interactive";
		displayName = "Paramilitary Garb (Jacket)";
		DLC = "Expansion";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_2_F_1_co.paa"};
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		scope = 2;
		class ItemInfo : UniformItem { //["InventoryItem_Base_F"]
			containerClass = "Supply40";
			mass = 40;
			uniformClass = "BP_Paramilitary_Jacket";
			uniformModel = "-";
		};
	};
	
	class BP_Paramilitary_Shorts_Uniform : Uniform_Base { //Paramilitary Garb (Shorts)
		author = "Bohemia Interactive";
		displayName = "Paramilitary Garb (Shorts)";
		DLC = "Expansion";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_5_F_1_co.paa"};
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		scope = 2;
		class ItemInfo : UniformItem { //["InventoryItem_Base_F"]
			containerClass = "Supply40";
			mass = 40;
			uniformClass = "BP_Paramilitary_Shorts";
			uniformModel = "-";
		};
	};
	
	class BP_Paramilitary_Tee_Uniform : Uniform_Base { //Paramilitary Garb (Tee)
		author = "Bohemia Interactive";
		displayName = "Paramilitary Garb (Tee)";
		DLC = "Expansion";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_1_F_1_co.paa"};
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		scope = 2;
		class ItemInfo : UniformItem { //["InventoryItem_Base_F"]
			containerClass = "Supply40";
			mass = 40;
			uniformClass = "BP_Paramilitary_Tee";
			uniformModel = "-";
		};
	};
	
	class V_PlateCarrierGL_rgr;
	
	class V_PlateCarrierGL_tna_BP : V_PlateCarrierGL_rgr { //Carrier GL Rig (Tropic)
		_generalMacro = "V_PlateCarrierGL_tna_F";
		author = "Bohemia Interactive";
		displayName = "Carrier GL Rig (Tropic)";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Vests\Data\V_PlateCarrierGL_tna_F_co.paa"};
		picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_PlateCarrierGL_tna_F_ca.paa";
		
		class ItemInfo : VestItem {
			containerClass = "Supply140";
			hiddenSelections[] = {"camo"};
			mass = 100;
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_carrier_gl_rig.p3d";
		};
	};
	
	class V_HarnessO_gry;
	
	class V_HarnessO_ghex_BP : V_HarnessO_gry { //LBV Harness (Green Hex)
		_generalMacro = "V_HarnessO_ghex_F";
		author = "Bohemia Interactive";
		displayName = "LBV Harness (Green Hex)";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\OPFOR\Data\clothing_tna_CO.paa","\A3\Characters_F_Exp\OPFOR\Data\tech_tna_CO.paa"};
		picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_HarnessO_ghex_F_ca.paa";
	};
	
	class V_BandollierB_ghex_BP : V_BandollierB_khk_BP { //Slash Bandolier (Green Hex)
		_generalMacro = "V_BandollierB_ghex_F";
		author = "Bohemia Interactive";
		displayName = "Slash Bandolier (Green Hex)";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Vests\Data\V_BandollierB_ghex_F_co.paa"};
		picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_BandollierB_ghex_F_ca.paa";
	};
	
	class V_TacChestrig_grn_BP : Vest_Camo_Base { //Tactical Chest Rig (Green)
		_generalMacro = "V_TacChestrig_grn_F";
		author = "Bohemia Interactive";
		displayName = "Tactical Chest Rig (Green)";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Common\Data\equip_TacChestrig_grn_co.paa"};
		model = "\A3\Characters_F_Exp\Common\equip_TacChestrig.p3d";
		picture = "\A3\Characters_F_Exp\Data\UI\icon_V_TacChestrig_grn_ca.paa";
		scope = 2;
		class ItemInfo : ItemInfo {
			containerClass = "Supply140";
			hiddenSelections[] = {"camo"};
			mass = 20;
			uniformModel = "\A3\Characters_F_Exp\Common\equip_TacChestrig.p3d";
		};
	};
	
	class V_TacChestrig_cbr_BP : V_TacChestrig_grn_BP { //Tactical Chest Rig (Coyote)
		_generalMacro = "V_TacChestrig_cbr_F";
		author = "Bohemia Interactive";
		displayName = "Tactical Chest Rig (Coyote)";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Common\Data\equip_TacChestrig_cbr_co.paa"};
		picture = "\A3\Characters_F_Exp\Data\UI\icon_V_TacChestrig_cbr_ca.paa";
	};
	
	class V_HeroVest_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "TacVest (Hero)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\clothing\BP_HeroVest_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply150";
			mass = 120;
			armor = "5*0.6";
			passThrough = 0.100000;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_TacVest_khk_BP: Vest_Camo_Base {
		scope = 2;
		displayName = "TacVest (Khaki)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_khk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_khaki_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 100;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					hitpointName = "HitChest";
					armor = 8;
					passThrough = 0.5;
				};
				class Diaphragm
				{
					hitpointName = "HitDiaphragm";
					armor = 8;
					passThrough = 0.5;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 8;
					passThrough = 0.5;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.5;
				};
			};
			hiddenSelections[] = {"camo"};
		};
	};

	class V_TacVest_brn_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Brown)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_brn_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_brown_co.paa"};
		
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 100;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_TacVest_oli_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Olive)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_olive_co.paa"};
		
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 100;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_TacVest_blk_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Black)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_black_co.paa"};
		
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_HarnessO_brn_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Equipment Harness";
		descriptionUse = "Equipment Harness";
		descriptionShort = "Medium capacity, light armor";
		picture = "\A3\characters_f\Data\UI\icon_V_HarnessO_brn_CA.paa";
		model = "\A3\Characters_F\OPFOR\equip_o_vest01";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\OPFOR\equip_o_vest01";
			allowedSlots[] = {};
			containerClass = "Supply90";
			mass = 40;
			armor = "0";
			passThrough = 0.920000;
		};
	};
	
	class V_HarnessO_gry_BP : V_HarnessO_brn_BP { //LBV Harness (Grey)
		_generalMacro = "V_HarnessO_gry";
		author = "Bohemia Interactive";
		displayName = "LBV Harness (Grey)";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\OPFOR\Data\clothing_oucamo_co.paa","\A3\Characters_F\OPFOR\Data\tech_oucamo_co"};
		model = "\A3\Characters_F\OPFOR\equip_o_vest01";
		picture = "\A3\characters_f_beta\Data\UI\icon_V_HarnessOU_gry_CA.paa";
		class ItemInfo : ItemInfo {
			containerClass = "Supply160";
			hiddenSelections[] = {"Camo1","Camo2"};
			mass = 40;
			uniformModel = "\A3\Characters_F\OPFOR\equip_o_vest01";
		};
	};

	class V_HarnessOGL_brn_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Equipment Harness";
		descriptionShort = "Medium capacity, light armor";
		picture = "\A3\characters_f\Data\UI\icon_V_HarnessOGL_brn_CA.paa";
		model = "\A3\Characters_F\OPFOR\equip_o_vest_gl";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\OPFOR\equip_o_vest_gl";
			allowedSlots[] = {};
			containerClass = "Supply90";
			mass = 40;
			armor = "0";
			passThrough = 0.920000;
		};
	};
	
	class V_Chestrig_khk_BP: Vest_Camo_Base {
		scope = 2;
		displayName = "Survival Rig";
		descriptionShort = "Medium capacity, light armor";
		picture = "\A3\characters_f\Data\UI\icon_V_Chestrig_khk_CA.paa";
		model = "\A3\Characters_F\Common\equip_chestrig";
		hiddenSelections[] = {"Camo1", "Camo2"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\equip_chestrig_khk_co.paa", "\A3\Characters_F\BLUFOR\Data\vests_khk_co.paa"};

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\Common\equip_chestrig.p3d";
			containerClass = "Supply80";
			mass = 40;
			armor = "0";
			passThrough = 0.950000;
			hiddenSelections[] = {"camo1", "camo2"};
		};
	};

	class V_Chestrig_rgr_BP: V_Chestrig_khk_BP {
		scope = 2;
		displayName = "Survival Rig";
		picture = "\A3\characters_f\Data\UI\icon_V_Chestrig_rgr_CA.paa";
		model = "\A3\Characters_F\Common\equip_chestrig";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\equip_chestrig_rgr_co.paa", "\A3\Characters_f\BLUFOR\data\armor1_co.paa"};
	};

	class V_Chestrig_blk_BP: V_Chestrig_khk_BP {
		scope = 2;
		displayName = "Survival Rig";
		picture = "\A3\characters_F\data\ui\icon_V_FChestrig_blk_CA.paa";
		model = "\A3\Characters_F\Common\equip_chestrig";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\equip_chestrig_blk_co.paa", "\A3\Characters_F\BLUFOR\Data\vests_blk_co.paa"};
	};
	
	class V_PlateCarrierIA1_dgtl_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Plate Carrier Digital";
		descriptionUse = "Vest Digital";
		picture = "\A3\characters_f_Beta\Data\UI\icon_V_I_Vest_01_ca.paa";
		model = "A3\Characters_F_Beta\INDEP\equip_ia_vest01";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest01";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 60;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					hitpointName = "HitChest";
					armor = 16;
					passThrough = 0.3;
				};
				class Diaphragm
				{
					hitpointName = "HitDiaphragm";
					armor = 16;
					passThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 16;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};

	class V_PlateCarrierIA2_dgtl_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Plate Carrier+ Digital";
		descriptionUse = "Harness Digital";
		picture = "\A3\characters_f_Beta\Data\UI\icon_V_I_Vest_02_ca.paa";
		model = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					hitpointName = "HitChest";
					armor = 16;
					passThrough = 0.3;
				};
				class Diaphragm
				{
					hitpointName = "HitDiaphragm";
					armor = 16;
					passThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 16;
					passThrough = 0.3;
				};
				class Pelvis
				{
					hitpointName = "HitPelvis";
					armor = 16;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};

	class V_PlateCarrierIAGL_dgtl_BP: Vest_NoCamo_Base {
		scope = 2;
		displayName = "Plate Carrier+ Digital";
		picture = "\A3\Characters_F_Beta\Data\UI\icon_V_I_Vest_02_ca.paa";
		model = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
		
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
			allowedSlots[] = {};
			containerClass = "Supply110";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					hitpointName = "HitNeck";
					armor = 8;
					passThrough = 0.5;
				};
				class Arms
				{
					hitpointName = "HitArms";
					armor = 8;
					passThrough = 0.5;
				};
				class Chest
				{
					hitpointName = "HitChest";
					armor = 78;
					passThrough = 0.6;
				};
				class Diaphragm
				{
					hitpointName = "HitDiaphragm";
					armor = 78;
					passThrough = 0.6;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 16;
					passThrough = 0.3;
				};
				class Pelvis
				{
					hitpointName = "HitPelvis";
					armor = 16;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.6;
				};
			};
		};
	};
	
	class V_TacVest_camo_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Woodland)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_CA.paa";
		model = "A3\Characters_F\Common\equip_tacticalvest";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_camo_co.paa"};
	

		class ItemInfo: VestItem {
			hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_camo_co.paa"};
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};

	class V_TacVest_blk_POLICE_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Police)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_police_CA.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\tacticalvest_police_co.paa"};
		model = "A3\Characters_F\Common\equip_tacticalvest";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};
	
	class V_TacVest_gen_BP : V_TacVest_blk_POLICE_BP { //Gendarmerie Vest
		_generalMacro = "V_TacVest_gen_F";
		author = "Bohemia Interactive";
		displayName = "Gendarmerie Vest";
		DLC = "Expansion";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Vests\Data\V_TacVest_gen_F_co.paa"};
		picture = "\A3\Characters_F_Exp\Vests\Data\UI\icon_V_TacVest_gen_F_ca.paa";
		
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			allowedSlots[] = {};
			containerClass = "Supply80";
			mass = 60;
			hiddenSelections[] = {"camo"};
		};
	};
	

	class V_TacVestIR_blk_BP: V_TacVest_khk_BP {
		scope = 2;
		displayName = "TacVest (Grey)";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";
			allowedSlots[] = {};
			containerClass = "Supply70";
			mass = 60;
		};
	};
	
	class BP_Guarilla_Faded: U_BG_Guerilla3_1
	{
		scope = 2;
		displayName = "Guerilla Faded";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Guarilla_Faded";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class BP_Guarilla_Khaki: U_BG_Guerilla3_2
	{
		scope = 2;
		displayName = "Guerilla Khaki";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Guarilla_Khaki";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class BP_Guarilla_Leader: U_BG_leader
	{
		scope = 2;
		displayName = "Guerilla Leader";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Guarilla_Leader";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class BP_Guarilla_Camo: U_BG_Guerilla1_1
	{
		scope = 2;
		displayName = "Guerilla Khaki Camo";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Guarilla_Camo";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 80;
		};
	};
	
	class BP_Ghillie_Lush: U_B_FullGhillie_lsh
	{
		scope = 2;
		displayName = "Marksman Ghillie";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "BP_Ghillie_Lush";
			allowedSlots[] = {};
			containerClass = "Supply20";
			mass = 10;
		};
	};

	class BP_Wetsuit : U_B_Wetsuit 
	{
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		class ItemInfo : UniformItem 
		{
			uniformModel = "-";
			uniformClass = "BP_Wetsuit";
			allowedSlots[] = {};
			containerClass = "Supply30";
			uniformType = "Neopren";
			mass = 90;
			displayName = "Wetsuit (Black)";
		};
	};
	
	class BP_Wetsuit_Z : U_B_Wetsuit 
	{
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "BP_Wetsuit_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			uniformType = "Neopren";
			mass = 90;
			displayName = "Wetsuit (Black)";
		};
	};

	//GHILLIES
	class BP_DirtGhillie: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Dirt)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_DirtGhillie";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};

	class BP_DirtGhillie_Z: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Dirt)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_DirtGhillie_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};

	class BP_StoneGhillie: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Stone)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_StoneGhillie";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};
	
	class BP_StoneGhillie_Z: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Stone)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";

		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_StoneGhillie_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};

	class BP_TreeGhillie: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Tree)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_TreeGhillie";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};
	
	class BP_TreeGhillie_Z: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Tree)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_TreeGhillie_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};
	
	class BP_GrassGhillie: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Grass)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_GrassGhillie";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};
	
	class BP_GrassGhillie_Z: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Grass)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_GrassGhillie_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
		};
	};
	
	class BP_SnowGhillie: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Snow)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\Ghillies\ghillie1_ca.paa"};
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_SnowGhillie";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
			hiddenSelections[] = {"Camo"};
		};
	};
	
	class BP_SnowGhillie_Z: Uniform_Base {
		scope = 2;
		displayName = "Ghillie (Snow)";
		picture = "\breakingpoint_ui\icons\NoneIcon.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\Ghillies\ghillie1_ca.paa"};
		
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "BP_SnowGhillie_Z";
			allowedSlots[] = {};
			containerClass = "Supply30";
			mass = 80;
			hiddenSelections[] = {"Camo"};
		};
	};
	
	//End of Arma 3 Uniform

	// Breaking Point: Toolbelt Items

	class ItemMap: ItemCore {
		model = "breakingpoint\models\bp_map.p3d";
	};

	class ItemWatch: ItemCore {
		model = "breakingpoint\models\bp_watch.p3d";
	};

	class ItemCompass: ItemCore {
		model = "breakingpoint\models\bp_compass.p3d";
	};
	
	class ItemToolbox : ItemCore {
		scope = 2;
		displayName = "Toolbox";
		descriptionUse = "Toolbox";
		model = "\breakingpoint\models\bp_toolbox.p3d";
		picture = "\breakingpoint\textures\icons\bp_toolbox_ca.paa";
		descriptionShort = "All purpose toolkit used for basic to major mechanical repair";
		simulation = "ItemRadio";
		
		class ItemInfo {
		    mass = 99;
	    };
	};
	
	class ItemSurgeryKit : ItemCore {
		scope = public;
		displayName = "Portable Surgery Kit";
		descriptionUse = "Surgery Kit";
		model = "\breakingpoint\models\bp_surgerykit.p3d";
		picture = "\breakingpoint\textures\icons\bp_surgerykit_ca.paa";
		descriptionShort = "Used For: Treatment of life threatening wounds and blood loss.";
		simulation = "ItemRadio";
		
		class ItemInfo {
		    mass = 99;
	    };
	};
};