/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/


#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

class CfgPatches {
	class breakingpoint_lib {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Functions_F_Curator","A3_Functions_F","A3_Functions_F_EPA","A3_Functions_F_EPC","A3_Functions_F_Bootcamp","A3_Functions_F_Curator","A3_Modules_F","A3_Modules_F_Beta","A3_Modules_F","A3_Modules_F_EPB","A3_Modules_F_Curator","A3_Missions_F_Curator","A3_Modules_F_Bootcamp","A3_Weapons_F","A3_Weapons_F_Beta","A3_Weapons_F_Bootcamp","A3_Weapons_F_Gamma","A3_Weapons_F_EPC","A3_Weapons_F_EPA","A3_Weapons_F_EPB","breakingpoint_weapons_cfg"};
	};
};

#include "CfgFunctions.hpp"

class CfgWeapons {
	class Rifle_Base_F;
	class FakeWeapon : Rifle_Base_F
	{
		scope = private;
		blocked = true;
	};
	
	//Base Classes (Can't Delete)
	class MissileLauncher : FakeWeapon {};
	class SMG_01_Base : FakeWeapon {};
	class mk20_base_F : FakeWeapon {};
	class CannonCore : FakeWeapon {};
	class GM6_base_F : FakeWeapon {};
	class autocannon_Base_F : FakeWeapon {};
	class Launcher_Base_F : FakeWeapon {};
	class arifle_Katiba_Base_F : FakeWeapon {};
	class arifle_MX_Base_F : FakeWeapon {};
	class Tavor_base_F : FakeWeapon {};
	class launch_Titan_base : FakeWeapon {};
	class launch_Titan_short_base : FakeWeapon {};
	
	delete HMG_127;
	delete LMG_Minigun_heli;
	delete LMG_Minigun;
	delete LMG_M200;
	delete LMG_RCWS;
	delete M2;
	delete RocketPods;
	delete HMG_127_APC;
	delete HMG_01;
	delete HMG_NSVT;
	delete M134_minigun;
	delete mortar_82mm;
	delete missiles_DAGR;
	delete missiles_DAR;
	delete GMG_F;
	delete GMG_20mm;
	delete GMG_40mm;
	delete GMG_UGV_40mm;
	delete launch_NLAW_F;
	delete launch_RPG32_F;
	delete srifle_EBR_F;
	delete srifle_EBR_ACO_F;
	delete srifle_EBR_MRCO_pointer_F;
	delete srifle_EBR_SOS_F;
	delete srifle_EBR_ARCO_pointer_F;
	delete srifle_GM6_F;
	delete srifle_GM6_SOS_F;
	delete LRR_base_F;
	delete srifle_LRR_F;
	delete srifle_LRR_SOS_F;
	delete LMG_Mk200_F;
	delete LMG_Mk200_MRCO_F;
	delete LMG_Mk200_pointer_F;
	delete arifle_Katiba_F;
	delete arifle_Katiba_C_F;
	delete arifle_Katiba_GL_F;
	delete arifle_Katiba_C_ACO_pointer_F;
	delete arifle_Katiba_C_ACO_F;
	delete arifle_Katiba_ACO_F;
	delete arifle_Katiba_ACO_pointer_F;
	delete arifle_Katiba_ARCO_F;
	delete arifle_Katiba_ARCO_pointer_F;
	delete arifle_Katiba_GL_ACO_F;
	delete arifle_Katiba_GL_ARCO_pointer_F;
	delete arifle_Katiba_GL_ACO_pointer_F;
	delete arifle_MXC_F;
	delete arifle_MX_F;
	delete arifle_MX_GL_F;
	delete arifle_MX_SW_F;
	delete arifle_MXM_F;
	delete arifle_MX_pointer_F;
	delete arifle_MX_Holo_pointer_F;
	delete arifle_MX_Hamr_pointer_F;
	delete arifle_MX_ACO_pointer_F;
	delete arifle_MX_ACO_F;
	delete arifle_MX_GL_ACO_F;
	delete arifle_MX_GL_ACO_pointer_F;
	delete arifle_MX_GL_Hamr_pointer_F;
	delete arifle_MXC_Holo_F;
	delete arifle_MXC_Holo_pointer_F;
	delete arifle_MX_SW_pointer_F;
	delete arifle_MX_SW_Hamr_pointer_F;
	delete arifle_MXM_Hamr_pointer_F;
	delete SDAR_base_F;
	delete arifle_SDAR_F;
	delete arifle_TRG21_F;
	delete arifle_TRG20_F;
	delete arifle_TRG21_GL_F;
	delete arifle_TRG20_Holo_F;
	delete arifle_TRG20_ACO_pointer_F;
	delete arifle_TRG20_ACO_Flash_F;
	delete arifle_TRG20_ACO_F;
	delete arifle_TRG21_ACO_pointer_F;
	delete arifle_TRG21_ARCO_pointer_F;
	delete arifle_TRG21_MRCO_F;
	delete arifle_TRG21_GL_MRCO_F;
	delete arifle_TRG21_GL_ACO_pointer_F;
	delete autocannon_40mm_CTWS;
	delete autocannon_30mm_CTWS;
	delete gatling_20mm;
	delete gatling_30mm;
	delete missiles_ASRAAM;
	delete missiles_SCALPEL;
	delete missiles_titan;
	delete rockets_Skyfire;
	delete LMG_Minigun2;
	delete launch_B_Titan_F;
	delete launch_I_Titan_F;
	delete launch_O_Titan_F;
	delete launch_Titan_F;
	delete launch_B_Titan_short_F;
	delete launch_I_Titan_short_F;
	delete launch_O_Titan_short_F;
	delete launch_Titan_short_F;
	delete srifle_EBR_ARCO_pointer_snds_F;
	delete LMG_Zafir_F;
	delete LMG_Zafir_pointer_F;
	delete arifle_Katiba_GL_Nstalker_pointer_F;
	delete arifle_Katiba_GL_ACO_pointer_snds_F;
	delete arifle_Katiba_C_ACO_pointer_snds_F;
	delete arifle_Katiba_ACO_pointer_snds_F;
	delete arifle_Katiba_ARCO_pointer_snds_F;
	delete arifle_Mk20_F;
	delete arifle_Mk20_plain_F;
	delete arifle_Mk20C_F;
	delete arifle_Mk20C_plain_F;
	delete arifle_Mk20_GL_F;
	delete arifle_Mk20_GL_plain_F;
	delete arifle_Mk20C_ACO_F;
	delete arifle_Mk20C_ACO_pointer_F;
	delete arifle_Mk20_pointer_F;
	delete arifle_Mk20_Holo_F;
	delete arifle_Mk20_ACO_F;
	delete arifle_Mk20_ACO_pointer_F;
	delete arifle_Mk20_MRCO_F;
	delete arifle_Mk20_MRCO_plain_F;
	delete arifle_Mk20_MRCO_pointer_F;
	delete arifle_Mk20_GL_MRCO_pointer_F;
	delete arifle_Mk20_GL_ACO_F;
	delete arifle_MXC_ACO_F;
	delete arifle_MXC_Holo_pointer_snds_F;
	delete arifle_MXC_SOS_point_snds_F;
	delete arifle_MXC_ACO_pointer_snds_F;
	delete arifle_MXC_ACO_pointer_F;
	delete arifle_MX_ACO_pointer_snds_F;
	delete arifle_MX_RCO_pointer_snds_F;
	delete arifle_MX_GL_Holo_pointer_snds_F;
	delete arifle_MXM_SOS_pointer_F;
	delete arifle_MXM_RCO_pointer_snds_F;
	delete cannon_120mm;
	delete gatling_25mm;
	delete autocannon_35mm;
	delete mortar_155mm_AMOS;
	delete missiles_Zephyr;
	delete missiles_titan_static;
	delete GBU12BombLauncher;
	delete Mk82BombLauncher;
	delete rockets_230mm_GAT;
	delete optic_NVS;
	delete optic_Nightstalker;
	delete optic_tws;
	delete optic_tws_mg;
};

class CfgMagazines {
	//class CA_Magazine;
	//class FakeMagazine : CA_Magazine
	//{
	//	scope = private;
	//	blocked = true;
	//};
	
	//class HandGrenade : FakeMagazine {};
	//class MiniGrenade : FakeMagazine {};
	//class mini_Grenade : FakeMagazine {};
	//class HandGrenade_Stone : FakeMagazine {};
	//class GrenadeHand : FakeMagazine {};
};

class CfgAmmo
{
	class Default;
	class FakeAmmo : Default
	{
		scope = private;
		blocked = true;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		audibleFire = 0;
		model = "";
		modelModelDisabled = "";
		icon = "";
		defaultMagazine = "";
		soundHit[] = {"A3\Sounds_F\weapons\Mines\mine_debris_1",0, 0, 0};
		soundTrigger[] = {"A3\Sounds_F\weapons\mines\electron_trigger_1", 0, 0, 0};
		soundActivation[] = {"A3\Sounds_F\weapons\mines\electron_activate_mine_1", 0, 0, 0};
		explosionEffects = "";
		CraterEffects = "";
		whistleDist = 0;
		mineTrigger = "";
	};

	//Base Classes (Can't Delete)
	//class BombCore : FakeAmmo {};
	//class LaserBombCore : FakeAmmo {};
	//class TimeBombCore : FakeAmmo {};
	//class LaserCore : FakeAmmo {};
	//class PipeBombCore : FakeAmmo {};
	//class DirectionalBombCore : FakeAmmo {};
	//class BoundingMineCore : FakeAmmo {};
	//class MineCore : FakeAmmo {};
	//class BP_IED : FakeAmmo {};
	
	//delete ATMine_Range_Ammo;
	delete UnderwaterMine_Range_Ammo;
	delete UnderwaterMineAB_Range_Ammo;
	delete UnderwaterMinePDM_Range_Ammo;
	//delete APERSMine_Range_Ammo;
	//delete APERSBoundingMine_Range_Ammo;
	//delete SLAMDirectionalMine_Wire_Ammo;
	//delete APERSTripMine_Wire_Ammo;
	//delete ClaymoreDirectionalMine_Remote_Ammo;
	//delete SatchelCharge_Remote_Ammo;
	//delete DemoCharge_Remote_Ammo;
	delete IEDUrbanBig_Remote_Ammo;
	delete IEDLandBig_Remote_Ammo;
	delete IEDUrbanSmall_Remote_Ammo;
	delete IEDLandSmall_Remote_Ammo;
	delete M_Titan_AA;
	delete M_Zephyr;
	delete M_Zephyr_Mi06;
	delete Mo_cluster_AP;
	delete M_Air_AA;
	delete M_Air_AA_MI02;
	delete M_Titan_AT;
	delete M_Titan_AP;
	delete M_Air_AT;
	delete M_Zephyr_air;
	delete M_Titan_AA_static;
	delete M_Titan_AT_static;
	delete HelicopterExploSmall;
	delete HelicopterExploBig;
	delete SmallSecondary;
	delete Laserbeam;
	delete B_19mm_HE;
	delete B_30mm_HE;
	delete B_30mm_HE_Tracer_Red;
	delete B_30mm_HE_Tracer_Green;
	delete B_30mm_HE_Tracer_Yellow;
	delete B_30mm_MP;
	delete B_30mm_MP_Tracer_Red;
	delete B_30mm_MP_Tracer_Green;
	delete B_30mm_MP_Tracer_Yellow;
	delete B_40mm_GPR;
	delete B_40mm_GPR_Tracer_Red;
	delete B_40mm_GPR_Tracer_Green;
	delete B_40mm_GPR_Tracer_Yellow;
	delete B_20mm;
	delete B_20mm_Tracer_Red;
	delete B_25mm;
	delete B_30mm_AP;
	delete B_30mm_AP_Tracer_Red;
	delete B_30mm_AP_Tracer_Green;
	delete B_30mm_AP_Tracer_Yellow;
	delete B_30mm_APFSDS;
	delete B_30mm_APFSDS_Tracer_Red;
	delete B_30mm_APFSDS_Tracer_Green;
	delete B_30mm_APFSDS_Tracer_Yellow;
	delete B_40mm_APFSDS;
	delete B_40mm_APFSDS_Tracer_Red;
	delete B_40mm_APFSDS_Tracer_Green;
	delete B_40mm_APFSDS_Tracer_Yellow;
	delete B_35mm_AA;
	delete B_35mm_AA_Tracer_Red;
	delete B_35mm_AA_Tracer_Green;
	delete B_35mm_AA_Tracer_Yellow;
	delete B_coil_5g_spike;
	delete B_coil_20g_spike;
	delete SmokeLauncherAmmo;
	delete SmokeLauncherAmmo_boat;
	delete FlareLauncherAmmo;
	delete CMflareAmmo;
	delete CMflare_Chaff_Ammo;
	delete Sh_120mm_HE;
	delete Sh_120mm_HE_Tracer_Red;
	delete Sh_120mm_HE_Tracer_Green;
	delete Sh_120mm_HE_Tracer_Yellow;
	delete Sh_120mm_APFSDS;
	delete Sh_120mm_APFSDS_Tracer_Red;
	delete Sh_120mm_APFSDS_Tracer_Green;
	delete Sh_120mm_APFSDS_Tracer_Yellow;
	delete Sh_155mm_AMOS;
	delete Sh_82mm_AMOS;
	delete Sh_82mm_AMOS_guided; 
	delete Sh_82mm_AMOS_LG;
	delete Fire_82mm_AMOS;
	delete Sh_155mm_AMOS_guided;
	delete Sh_155mm_AMOS_LG;
	delete Smoke_120mm_AMOS_White;
	delete Mo_ClassicMineRange; 
	//delete Mo_ATMineRange; 
	delete Mo_UnderwaterMineRange;
	delete Mine_155mm_AMOS_range;
	delete AT_Mine_155mm_AMOS_range;
	delete UWMine_155mm_AMOS_range;
	delete Cluster_155mm_AMOS;
	delete M_PG_AT;
	delete M_AT;
	delete M_Mo_82mm_AT;
	delete M_Mo_82mm_AT_LG;
	delete M_Mo_120mm_AT;
	delete M_Mo_120mm_AT_LG;
	delete M_Mo_155mm_AT_LG;
	delete M_Scalpel_AT;
	delete M_Scalpel_AT_hidden;
	delete Bo_Air_LGB;
	delete Bo_Air_LGB_hidden;
	delete Bo_GBU12_LGB;
	delete Bo_GBU12_LGB_MI10;
	delete Bo_Mk82;
	delete Bo_Mk82_MI08;
	delete R_80mm_HE;
	delete R_60mm_HE;
	delete R_230mm_HE;
	delete R_230mm_fly;
	delete G_20mm_HE;
	delete G_40mm_HEDP;
	delete M_Titan_AA_long;
	delete Sh_125mm_APFSDS;
	delete Sh_125mm_APFSDS_T_Red;
	delete Sh_125mm_APFSDS_T_Green;
	delete Sh_125mm_APFSDS_T_Yellow;
	delete Sh_125mm_HE;
	delete Sh_125mm_HE_T_Red;
	delete Sh_125mm_HE_T_Green;
	delete Sh_125mm_HE_T_Yellow;
	delete Sh_125mm_HEAT;
	delete Sh_125mm_HEAT_T_Red;
	delete Sh_125mm_HEAT_T_Green;
	delete Sh_125mm_HEAT_T_Yellow;
	delete Gatling_30mm_HE_Plane_CAS_01_F;
	delete Missile_AA_04_F;
	delete Missile_AGM_02_F;
	delete Bomb_04_F;
	delete Rocket_04_HE_F;
	delete Rocket_04_AP_F;
	delete Cannon_30mm_HE_Plane_CAS_02_F;
	delete Missile_AA_03_F;
	delete Missile_AGM_01_F;
	delete Bomb_03_F;
	delete Rocket_03_HE_F;
	delete Rocket_03_AP_F;
	delete Sh_105mm_APFSDS;
	delete Sh_105mm_APFSDS_T_Red;
	delete Sh_105mm_APFSDS_T_Green;
	delete Sh_105mm_APFSDS_T_Yellow;
	delete Sh_105mm_HEAT_MP;
	delete Sh_105mm_HEAT_MP_T_Red;
	delete Sh_105mm_HEAT_MP_T_Green;
	delete Sh_105mm_HEAT_MP_T_Yellow;
	delete R_PG32V_F;
	delete R_TBG32V_F;
	delete M_NLAW_AT_F;
	delete G_40mm_HE;
	delete GrenadeHand;
	delete GrenadeHand_stone;
};
