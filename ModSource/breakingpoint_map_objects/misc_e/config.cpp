////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Fri Mar 21 13:04:08 2014 : Source 'file' date Fri Mar 21 13:04:08 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class misc_e : config.bin{
class CfgPatches
{
	class CAMisc_E
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.02;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class HouseBase;
	class House: HouseBase
	{
		class DestructionEffects;
	};
	class Ruins;
	class C130J_wreck_EP1: House
	{
		armor = 40;
		scope = 2;
		model = "\Ca\Misc_E\Wreck_C130J_EP1.p3d";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Wreck_C130J_EP1_ruins";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		icon = "\ca\air2\data\UI\icon_c130j_CA.paa";
		mapSize = 25;
		displayName = "$STR_EP1_DN_C130J_wreck_EP1";
		expansion = 1;
		vehicleClass = "Wrecks";
	};
	class Land_Wreck_C130J_EP1_ruins: Ruins
	{
		scope = 1;
		vehicleClass = "Ruins";
		model = "\Ca\misc_e\Wreck_C130J_EP1_ruins";
	};
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
	};
	class UH60_wreck_EP1: StaticWeapon
	{
		scope = 2;
		model = "\Ca\Misc_E\Wreck_UH60_EP1.p3d";
		icon = "ca\Misc_E\data\Icons\Icon_uh60_wreck_CA";
		mapSize = 7;
		displayName = "$STR_EP1_DN_UH60_wreck_EP1";
		expansion = 1;
		vehicleClass = "Wrecks";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body = "mainTurret";
				gun = "mainGun";
				minElev = -60;
				maxElev = 30;
				initElev = 0;
				minTurn = -7;
				maxTurn = 183;
				initTurn = 0;
				soundServo[] = {"",0.01,1.0};
				animationSourceHatch = "";
				stabilizedInAxes = "StabilizedInAxesNone";
				gunBeg = "muzzle_1";
				gunEnd = "chamber_1";
				weapons[] = {"M134"};
				magazines[] = {"2000Rnd_762x51_M134"};
				gunnerName = "$STR_POSITION_DOORGUNNER";
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 1;
				gunnerAction = "UH60_Gunner";
				gunnerInAction = "UH60_Gunner";
				commanding = -2;
				primaryGunner = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				gunnerCompartments = "Compartment2";
			};
		};
		class AnimationSources: AnimationSources
		{
			class Gatling_1
			{
				source = "revolving";
				weapon = "M134";
			};
		};
	};
	class GraveCross2;
	class GraveCross2_EP1: GraveCross2
	{
		scope = 2;
		model = "\ca\Misc_E\hrobecek_krizek2_ep1";
		displayName = "$STR_DN_GRAVECROSS2";
		expansion = 1;
	};
	class GraveCrossHelmet;
	class GraveCrossHelmet_EP1: GraveCrossHelmet
	{
		scope = 2;
		model = "\ca\Misc_E\hrobecek_krizekhelma_ep1";
		displayName = "$STR_DN_GRAVECROSSHELMET";
		expansion = 1;
	};
	class Land_fort_artillery_nest;
	class Land_fort_artillery_nest_EP1: Land_fort_artillery_nest
	{
		scope = 2;
		model = "\ca\Misc_E\fort_artillery_nest_ep1";
		displayName = "$STR_EP1_DN_Land_fort_artillery_nest_EP1";
		expansion = 1;
	};
	class Land_fort_rampart;
	class Land_fort_rampart_EP1: Land_fort_rampart
	{
		scope = 2;
		model = "\ca\Misc_E\fort_rampart_ep1";
		displayName = "$STR_EP1_DN_Land_fort_rampart_EP1";
		expansion = 1;
	};
	class Land_fortified_nest_big;
	class Land_fortified_nest_big_EP1: Land_fortified_nest_big
	{
		scope = 2;
		model = "\ca\Misc_E\fortified_nest_big_ep1";
		displayName = "$STR_DN_FORTIFIED_NEST_BIG";
		expansion = 1;
		armor = 2000;
	};
	class Land_fortified_nest_small;
	class Land_fortified_nest_small_EP1: Land_fortified_nest_small
	{
		scope = 2;
		model = "\ca\Misc_E\fortified_nest_small_ep1";
		displayName = "$STR_EP1_DN_Land_fortified_nest_small_EP1";
		expansion = 1;
	};
	class Land_Fort_Watchtower;
	class Land_Fort_Watchtower_EP1: Land_Fort_Watchtower
	{
		scope = 2;
		model = "\ca\Misc_E\fort_watchtower_ep1";
		displayName = "$STR_DN_FORT_WATCHTOWER";
		expansion = 1;
		armor = 2500;
	};
	class Hedgehog;
	class Hedgehog_EP1: Hedgehog
	{
		scope = 2;
		model = "\ca\Misc_E\jezek_kov_ep1";
		displayName = "$STR_DN_HEDGEHOG";
		expansion = 1;
	};
	class Fort_EnvelopeSmall;
	class Fort_EnvelopeSmall_EP1: Fort_EnvelopeSmall
	{
		scope = 2;
		model = "\ca\Misc_E\Fort_EnvelopeSmall_ep1";
		displayName = "$STR_DN_ENVELOPESMALL";
		expansion = 1;
	};
	class Fort_EnvelopeBig;
	class Fort_EnvelopeBig_EP1: Fort_EnvelopeBig
	{
		scope = 2;
		model = "\ca\Misc_E\Fort_EnvelopeBig_ep1";
		displayName = "$STR_DN_ENVELOPEBIG";
		expansion = 1;
	};
	class Fort_Barricade;
	class Fort_Barricade_EP1: Fort_Barricade
	{
		scope = 2;
		model = "\ca\Misc_E\Fort_Barricade_ep1";
		displayName = "$STR_DN_BARRICADE";
		expansion = 1;
	};
	class Land_CamoNet_NATO;
	class Land_CamoNet_NATO_EP1: Land_CamoNet_NATO
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNet_NATO_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNet_NATO_EP1";
		expansion = 1;
	};
	class Land_CamoNetVar_NATO;
	class Land_CamoNetVar_NATO_EP1: Land_CamoNetVar_NATO
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNet_NATO_var1_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNetVar_NATO_EP1";
		expansion = 1;
	};
	class Land_CamoNetB_NATO;
	class Land_CamoNetB_NATO_EP1: Land_CamoNetB_NATO
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNetB_NATO_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNetB_NATO_EP1";
		expansion = 1;
	};
	class Land_CamoNet_EAST;
	class Land_CamoNet_EAST_EP1: Land_CamoNet_EAST
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNet_EAST_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNet_EAST_EP1";
		expansion = 1;
	};
	class Land_CamoNetVar_EAST;
	class Land_CamoNetVar_EAST_EP1: Land_CamoNetVar_EAST
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNet_EAST_var1_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNetVar_EAST_EP1";
		expansion = 1;
	};
	class Land_CamoNetB_EAST;
	class Land_CamoNetB_EAST_EP1: Land_CamoNetB_EAST
	{
		scope = 2;
		model = "\ca\Misc_E\CamoNetB_EAST_ep1";
		displayName = "$STR_EP1_DN_Land_CamoNetB_EAST_EP1";
		expansion = 1;
	};
	class 76n6ClamShell;
	class 76n6ClamShell_EP1: 76n6ClamShell
	{
		expansion = 1;
		scope = 2;
		model = "\Ca\Misc_E\76n6_ClamShell_EP1";
		displayName = "$STR_DN_76N6CLAMSHELL";
	};
	class PowGen_Big: House
	{
		class DestructionEffects;
	};
	class PowGen_Big_EP1: PowGen_Big
	{
		expansion = 1;
		scope = 2;
		model = "\Ca\Misc_E\PowGen_Big_EP1";
		displayName = "$STR_DN_POWGEN_BIG";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\PowGen_Big_ruins_ep1";
				position = "";
				intensity = 1;
				interval = 0.05;
				lifeTime = 1;
			};
		};
	};
	class Land_PowGen_Big_ruins;
	class Land_PowGen_Big_ruins_EP1: Land_PowGen_Big_ruins
	{
		model = "\Ca\misc_e\PowGen_Big_ruins_ep1";
	};
	class Barrack2;
	class Land_Barrack2_EP1: Barrack2
	{
		scope = 2;
		model = "\ca\Misc_E\Barrack2_ep1";
		expansion = 1;
	};
	class MASH;
	class MASH_EP1: MASH
	{
		scope = 2;
		model = "\ca\Misc_E\MASH_ep1";
		displayName = "$STR_DN_MASH";
		expansion = 1;
	};
	class Misc_cargo_cont_small;
	class Misc_cargo_cont_small_EP1: Misc_cargo_cont_small
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_small";
		model = "\ca\Misc_E\Misc_cargo_cont_small_ep1";
		expansion = 1;
	};
	class Military_Item_NoInteractive;
	class AmmoCrate_NoInteractive_Base_EP1: Military_Item_NoInteractive
	{
		displayName = "$STR_EP1_DN_AmmoCrate_NoInteractive_Base_EP1";
		icon = "\ca\weapons\Data\map_ico\icomap_ammo_CA.paa";
		expansion = 1;
		mapSize = 2.0;
	};
	class AmmoCrate_NoInteractive_: AmmoCrate_NoInteractive_Base_EP1
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_AmmoCrate_NoInteractive_";
		model = "\ca\weapons\AmmoBoxes\USBasicAmmo.p3d";
	};
	class AmmoCrates_NoInteractive_Small: AmmoCrate_NoInteractive_Base_EP1
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_AmmoCrates_NoInteractive_Small";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
	};
	class AmmoCrates_NoInteractive_Medium: AmmoCrate_NoInteractive_Base_EP1
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_AmmoCrates_NoInteractive_Medium";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
	};
	class AmmoCrates_NoInteractive_Large: AmmoCrate_NoInteractive_Base_EP1
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_AmmoCrates_NoInteractive_Large";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
	};
	class Camp;
	class CampEast;
	class ACamp;
	class Camp_EP1: Camp
	{
		scope = 2;
		model = "\ca\Misc_E\Stan_ep1.p3d";
		expansion = 1;
	};
	class CampEast_EP1: CampEast
	{
		scope = 2;
		model = "\ca\Misc_E\Stan_east_ep1.p3d";
		expansion = 1;
	};
	class ACamp_EP1: ACamp
	{
		scope = 2;
		model = "\ca\Misc_E\Astan_ep1.p3d";
		expansion = 1;
	};
	class C130J_static_EP1: House
	{
		scope = 2;
		model = "\Ca\Misc_E\C130J_static.p3d";
		displayName = "$STR_EP1_DN_C130J_static_EP1";
		expansion = 1;
		vehicleClass = "Military";
		placement = "vertical";
		destrType = "DestructNo";
		class AnimationSources
		{
			class CargoAction
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class CargoClose
			{
				displayName = "$STR_EP1_DN_C130J_static_EP1_UserActions_CargoClose";
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				position = "cargo_door_handle";
				radius = 3;
				onlyForPlayer = 1;
				condition = "this animationPhase ""ramp_bottom"" >= 0.5";
				statement = "this animate [""ramp_bottom"",0];this animate [""ramp_top"",0]";
			};
			class CargoOpen
			{
				displayName = "$STR_EP1_DN_C130J_static_EP1_UserActions_CargoOpen";
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				position = "cargo_door_handle";
				radius = 3;
				onlyForPlayer = 1;
				condition = "this animationPhase ""ramp_bottom"" < 0.5";
				statement = "this animate [""ramp_bottom"",1];this animate [""ramp_top"",1]";
			};
		};
	};
	class Misc_TyreHeap;
	class Misc_TyreHeapEP1: Misc_TyreHeap
	{
		scope = 2;
		displayName = "$STR_DN_TYREHEAP";
		model = "\ca\Misc_E\Misc_TyreHeap_ep1";
		expansion = 1;
	};
	class Land_ladder: House
	{
		class AnimationSources;
	};
	class Land_ladderEP1: Land_ladder
	{
		scope = 2;
		displayName = "$STR_MISC_LADDER";
		model = "\ca\Misc_E\ladder_ep1";
		expansion = 1;
		class AnimationSources: AnimationSources
		{
			class Move_Ladder_Start
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1e-005;
			};
		};
	};
	class Land_ladder_half;
	class Land_ladder_half_EP1: Land_ladder_half
	{
		scope = 2;
		displayName = "$STR_MISC_LADDER_HALF";
		model = "\ca\Misc_E\ladder_half_ep1";
		expansion = 1;
	};
	class Land_radar;
	class Land_radar_EP1: Land_radar
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Land_radar_EP1";
		model = "\ca\Misc_E\vysilac_FM2_ep1";
	};
	class Notice_board;
	class Notice_board_EP1: Notice_board
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_MISC_NOTICE_BOARD";
		model = "\ca\Misc_E\nastenkaX_ep1";
	};
	class PowerGenerator;
	class PowerGenerator_EP1: PowerGenerator
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_MISC_POWERGENERATOR";
		model = "\ca\misc_e\PowerGenerator_EP1";
	};
	class Sign_MP_blu;
	class Sign_MP_blu_EP1: Sign_MP_blu
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_MP_blu_EP1";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_blufor_co.paa"};
	};
	class Sign_MP_op;
	class Sign_MP_op_EP1: Sign_MP_op
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_MP_op_EP1";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_opfor_co.paa"};
	};
	class Sign_MP_ind;
	class Sign_MP_ind_EP1: Sign_MP_ind
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_MP_ind_EP1";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_independent_co.paa"};
	};
	class Sign_1L_Firstaid;
	class Sign_1L_Firstaid_EP1: Sign_1L_Firstaid
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_1L_Firstaid_EP1";
		hiddenSelectionsTextures[] = {"\ca\signs_e\signm\data\sign_one_leg_h_first_aid_co.paa"};
	};
	class Sign_1L_Noentry;
	class Sign_1L_Noentry_EP1: Sign_1L_Noentry
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_1L_Noentry_EP1";
		hiddenSelectionsTextures[] = {"\ca\signs_e\signm\data\sign_one_leg_h_no_entry_co.paa"};
	};
	class Sign_Checkpoint;
	class Sign_Checkpoint_EP1: Sign_Checkpoint
	{
		expansion = 1;
	};
	class Sign_Checkpoint_US_EP1: Sign_Checkpoint
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_Checkpoint_US_EP1";
		hiddenSelectionsTextures[] = {"\ca\Signs_E\SignM\Data\Sign_Board_Checkpoint _US_CO.paa"};
	};
	class Sign_Checkpoint_TK_EP1: Sign_Checkpoint
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Sign_Checkpoint_TK_EP1";
		hiddenSelectionsTextures[] = {"\ca\Signs_E\SignM\Data\Sign_Board_Checkpoint _TK_CO.paa"};
	};
	class Land_Dirthump01;
	class Land_Dirthump01_EP1: Land_Dirthump01
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_DN_DIRTHUMP01";
		model = "\ca\Misc_E\dirthump01_ep1";
	};
	class Land_Dirthump02;
	class Land_Dirthump02_EP1: Land_Dirthump02
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_DN_DIRTHUMP02";
		model = "\ca\Misc_E\dirthump02_ep1";
	};
	class Land_Dirthump03;
	class Land_Dirthump03_EP1: Land_Dirthump03
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_DN_DIRTHUMP03";
		model = "\ca\Misc_E\dirthump03_ep1.p3d";
	};
	class TargetE;
	class TargetE_EP1: TargetE
	{
		scope = 2;
		displayName = "$STR_DN_TARGETE";
		model = "\ca\Misc\terc";
		expansion = 1;
	};
	class TargetGrenadBase;
	class TargetGrenade: TargetGrenadBase
	{
		scope = 1;
	};
	class TargetFakeTank;
	class TargetFakeTank_Lockable_EP1: TargetFakeTank
	{
		expansion = 1;
		scope = 2;
	};
	class TargetFakeTank_EP1: TargetFakeTank_Lockable_EP1
	{
		displayName = "$STR_DN_TARGETGRENADE";
		alwaysTarget = 0;
		irTarget = 0;
	};
	class Gunrack1;
	class GunrackUS_EP1: Gunrack1
	{
		scope = 2;
		model = "\ca\misc_E\Gunrack1_EP1";
		displayName = "$STR_EP1_DN_GunrackUS_EP1";
		expansion = 1;
	};
	class GunrackTK_EP1: GunrackUS_EP1
	{
		model = "\ca\misc_E\Gunrack2_EP1";
		displayName = "$STR_EP1_DN_GunrackTK_EP1";
		expansion = 1;
	};
	class Strategic;
	class Land_Fuel_tank_stairs_ep1: Strategic
	{
		model = "\CA\Misc_E\Fuel_tank_stairs_ep1.p3d";
		icon = "\Ca\misc\data\icons\i_fuel_CA.paa";
		ladders[] = {{ "start","end" }};
		armor = 50;
		accuracy = 0.5;
		destrType = "DestructEngine";
		expansion = 1;
	};
	class Map_for_briefing_EP1: Notice_board
	{
		scope = 1;
		displayName = "$STR_EP1_DN_Map_for_briefing_EP1";
		model = "\ca\Misc_E\Map_for_briefing_EP1";
		expansion = 1;
	};
	class Misc_Backpackheap;
	class Misc_Backpackheap_EP1: Misc_Backpackheap
	{
		scope = 2;
		displayName = "$STR_EP1_DN_Misc_Backpackheap_EP1";
		model = "\ca\Misc_E\Misc_Backpackheap_ep1.p3d";
		expansion = 1;
	};
	class FlagCarrier;
	class FlagPole_EP1: FlagCarrier
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_FlagPole_EP1";
		expansion = 1;
	};
	class FlagCarrierUNO_EP1: FlagCarrier
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_EP1_DN_FlagCarrierUNO_EP1";
		expansion = 1;
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_uno_co.paa""";
		};
	};
	class FlagCarrierRedCrystal_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierRedCrystal_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcrystal_co.paa""";
		};
	};
	class FlagCarrierTFKnight_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierTFKnight_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_knight_co.paa""";
		};
	};
	class FlagCarrierCDFEnsign_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierCDFEnsign_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cdf_co.paa""";
		};
	};
	class FlagCarrierRedCross_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierRedCross_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcross_co.paa""";
		};
	};
	class FlagCarrierUSArmy_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierUSArmy_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_usarmy_co.paa""";
		};
	};
	class FlagCarrierTKMilitia_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierTKMilitia_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tkm_co.paa""";
		};
	};
	class FlagCarrierRedCrescent_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierRedCrescent_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcrescent_co.paa""";
		};
	};
	class FlagCarrierGermany_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierGermany_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_ger_co.paa""";
		};
	};
	class FlagCarrierNATO_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierNATO_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_nato_co.paa""";
		};
	};
	class FlagCarrierBIS_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierBIS_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_bis_co.paa""";
		};
	};
	class FlagCarrierCzechRepublic_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierCzechRepublic_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cz_co.paa""";
		};
	};
	class FlagCarrierPOWMIA_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierPOWMIA_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_pow_co.paa""";
		};
	};
	class FlagCarrierBLUFOR_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierBLUFOR_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_blufor_co.paa""";
		};
	};
	class FlagCarrierOPFOR_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierOPFOR_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_opfor_co.paa""";
		};
	};
	class FlagCarrierINDFOR_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierINDFOR_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_indfor_co.paa""";
		};
	};
	class FlagCarrierTakistan_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierTakistan_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tka_co.paa""";
		};
	};
	class FlagCarrierTakistanKingdom_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierTakistanKingdom_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tkg_co.paa""";
		};
	};
	class FlagCarrierUSA_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierUSA_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_us_co.paa""";
		};
	};
	class FlagCarrierCDF_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierCDF_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cr_co.paa""";
		};
	};
	class FlagCarrierWhite_EP1: FlagCarrierUNO_EP1
	{
		displayName = "$STR_EP1_DN_FlagCarrierWhite_EP1";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_white_co.paa""";
		};
	};
	class Small_items_NoInteractive;
	class Microphone1_ep1: Small_items_NoInteractive
	{
		scope = 2;
		expansion = 1;
		model = "\ca\Misc_E\Mikrofon_EP1";
		displayName = "$STR_EP1_DN_Microphone1_ep1";
	};
	class Microphone2_ep1: Microphone1_ep1
	{
		model = "\ca\Misc_E\Mikrofon_ws_EP1";
		displayName = "$STR_EP1_DN_Microphone2_ep1";
	};
	class Microphone3_ep1: Microphone1_ep1
	{
		model = "\ca\Misc_E\Mikrofon_ws_logo_EP1";
		displayName = "$STR_EP1_DN_Microphone3_ep1";
	};
	class Thing;
	class ClutterCutter_EP1: Thing
	{
		expansion = 1;
		model = "\ca\Misc_E\clutterCutter_EP1.p3d";
		displayName = "$STR_EP1_DN_ClutterCutter_EP1";
		icon = "\ca\data\data\Unknown_object.paa";
		scope = 2;
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		transportFuel = 0;
		mapSize = 0.7;
		accuracy = 0.2;
		cost = 0;
		armor = 200000;
		destrType = "DestructNo";
	};
	class ClutterCutter_small_EP1: ClutterCutter_EP1
	{
		model = "\ca\Misc_E\clutterCutter_small_EP1.p3d";
		displayName = "$STR_EP1_DN_ClutterCutter_small_EP1";
	};
	class ClutterCutter_small_2_EP1: ClutterCutter_EP1
	{
		model = "\ca\Misc_E\clutterCutter_small_2_EP1.p3d";
		displayName = "$STR_EP1_DN_ClutterCutter_small_2_EP1";
	};
	class Misc_Videoprojektor_platno: Small_items_NoInteractive
	{
		scope = 1;
		displayName = "$STR_EP1_DN_Misc_Videoprojektor_platno";
	};
	class Land_Misc_Cargo1Ao_EP1: House
	{
		expansion = 1;
		model = "\ca\Misc_E\Misc_Cargo1Ao_EP1";
		class AnimationSources
		{
			class door_1_1
			{
				animPeriod = 2;
				initPhase = 0;
			};
			class door_1_2: door_1_1{};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "Door_Action1";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""door_1_1"" >= 0.5";
				statement = "this animate [""door_1_1"", 0];this animate [""door_1_2"", 0]";
			};
			class CloseDoors1
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_DOOR";
				position = "Door_Action1";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""door_1_1"" < 0.5";
				statement = "this animate [""door_1_1"", 1];this animate [""door_1_2"", 1]";
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1Bo_EP1: Land_Misc_Cargo1Ao_EP1
	{
		model = "\ca\Misc_E\Misc_Cargo1Bo_EP1";
		class AnimationSources: AnimationSources
		{
			class door_2_1: door_1_1{};
			class door_2_2: door_1_1{};
		};
		class UserActions: UserActions
		{
			class OpenDoors2
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "Door_Action2";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""door_2_1"" >= 0.5";
				statement = "this animate [""door_2_1"", 0];this animate [""door_2_2"", 0]";
			};
			class CloseDoors2
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_DOOR";
				position = "Door_Action2";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""door_2_1"" < 0.5";
				statement = "this animate [""door_2_1"", 1];this animate [""door_2_2"", 1]";
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1Eo_EP1: Land_Misc_Cargo1Bo_EP1
	{
		model = "\ca\Misc_E\Misc_Cargo1Eo_EP1";
		scope = 2;
		displayName = "$STR_EP1_DN_Land_Misc_Cargo1Eo_EP1";
		icon = "\Ca\buildings2\data\Icons\icon_container_ca.paa";
		mapSize = 7;
		vehicleClass = "Military";
		class AnimationSources: AnimationSources
		{
			class door_1_1: door_1_1
			{
				initPhase = 1;
			};
			class door_1_2: door_1_2
			{
				initPhase = 0.8;
			};
		};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\misc_e\wf\data\misc_cargo1b_desert_co.paa"};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1E_EP1: House
	{
		expansion = 1;
		model = "\ca\Misc_E\Misc_Cargo1E_EP1";
		scope = 2;
		displayName = "$STR_EP1_DN_Land_Misc_Cargo1E_EP1";
		icon = "\Ca\buildings2\data\Icons\icon_container_ca.paa";
		mapSize = 7;
		vehicleClass = "Military";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\misc_e\wf\data\misc_cargo1b_desert_co.paa"};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1A_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo1A_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1B_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo1B_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1C_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo1C_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1D_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo1D_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo2A_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo2A_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo2B_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo2B_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo2C_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo2C_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo2D_EP1: House
	{
		model = "\ca\Misc_E\Misc_Cargo2D_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_CargoMarket1a_EP1: House
	{
		model = "\ca\Misc_E\Misc_CargoMarket1a_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Misc_Cargo1A_ruins_EP1: Ruins
	{
		scope = 1;
		vehicleClass = "Ruins";
		model = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
	};
	class Sign_circle: Thing
	{
		vehicleClass = "helpers";
	};
	class Helper_Base_EP1: Sign_circle
	{
		scope = 0;
		expansion = 1;
		displayName = "";
	};
	class Sign_circle_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\sign_circle_EP1";
		displayName = "$STR_EP1_DN_Sign_circle_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Sign_sphere10cm_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\sphere10cm_EP1";
		displayName = "$STR_EP1_DN_Sign_sphere10cm_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Sign_sphere25cm_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\sphere25cm_EP1";
		displayName = "$STR_EP1_DN_Sign_sphere25cm_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Sign_sphere100cm_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\sphere100cm_EP1";
		displayName = "$STR_EP1_DN_Sign_sphere100cm_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Sign_arrow_down_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\arrow_down_EP1";
		displayName = "$STR_EP1_DN_Sign_arrow_down_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Sign_arrow_down_large_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\arrow_down_large_EP1";
		displayName = "$STR_EP1_DN_Sign_arrow_down_large_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class HMMWV_Ghost_EP1: Helper_Base_EP1
	{
		scope = 2;
		model = "ca\Misc_E\HMMWV_Ghost_EP1";
		displayName = "$STR_EP1_DN_HMMWV_Ghost_EP1";
		accuracy = 1000;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Training_target_EP1: House
	{
		expansion = 1;
		scope = 2;
		vehicleClass = "helpers";
		model = "ca\Misc_E\training_target_ep1";
		displayName = "$STR_EP1_DN_Training_target_EP1";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
	class Land_Hlidac_Budka;
	class Land_Hlidac_Budka_EP1: Land_Hlidac_Budka
	{
		expansion = 1;
		scope = 2;
		model = "\Ca\Misc_E\Hlidac_budka_ep1";
		displayName = "$STR_EP1_DN_Land_Hlidac_Budka_EP1";
	};
	class Land_Ind_TankSmall2;
	class Land_Ind_TankSmall2_EP1: Land_Ind_TankSmall2
	{
		expansion = 1;
		scope = 2;
		model = "\ca\Misc_E\Ind_TankSmall2_ep1";
	};
	class Land_Misc_Cargo2E_EP1: House
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_DN_CARGO2E";
		model = "\ca\Misc_E\Misc_Cargo2E_EP1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc_e\Misc_Cargo1A_ruins_EP1";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		vehicleClass = "misc";
	};
	class Bleacher_EP1: House
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Bleacher_EP1";
		model = "\Ca\Misc_E\bleacher.p3d";
		mapSize = 7;
		vehicleClass = "misc";
		class destructionEffects{};
	};
	class WaterBasin_conc_EP1: House
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_WaterBasin_conc_EP1";
		model = "\Ca\Misc_E\waterbasin_conc.p3d";
		mapSize = 7;
		vehicleClass = "misc";
		class destructionEffects{};
	};
	class Dirtmount_EP1: House
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_Dirtmount_EP1";
		model = "\Ca\Misc_E\dirtmount.p3d";
		mapSize = 7;
		vehicleClass = "training";
		class destructionEffects{};
	};
	class Infostand_1_EP1: Thing
	{
		expansion = 1;
		scope = 2;
		displayName = "$STR_EP1_DN_CfgVehicles_Infostand_1_EP1";
		model = "\Ca\Misc_E\infostand_1.p3d";
		mapSize = 1;
		vehicleClass = "signs";
	};
	class Infostand_2_EP1: Infostand_1_EP1
	{
		displayName = "$STR_EP1_DN_CfgVehicles_Infostand_2_EP1";
		model = "\Ca\Misc_E\infostand_2.p3d";
	};
	class ProtectionZone_Ep1: House
	{
		expansion = 2;
		scope = 1;
		model = "\Ca\Misc_E\protectionZone.p3d";
		displayName = "$STR_EP1_DN_CfgVehicles_ProtectionZone_Ep1";
		class destructionEffects{};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,0.5,0.5,0.5,ca)"};
	};
};
//};
