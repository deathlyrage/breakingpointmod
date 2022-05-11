/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/
class SmallFire;
class Thing;
class UniformSlotInfo;
class WeaponCloudsMGun;

class CfgVehicles
{
	class Logic;
	class VirtualMan_F;
	class House_F;
	class House_Small_F: House_F{};
	class Land_House_Logic: House_F
	{
		scope=1;
		armor=400;
		model="\A3\Weapons_f\dummyweapon.p3d";
	};
	class Land_FuelStation_Feed_F: House_Small_F
	{
		transportFuel=0;
	};
	class Land_fs_feed_F: House_Small_F
	{
		transportFuel=0;
	};
	class Land_A_FuelStation_Feed: House_Small_F
	{
		transportFuel=0;
	};
	class Land_Ind_FuelStation_Feed_EP1: House_Small_F
	{
		transportFuel=0;
	};
	class BP_Player_Unit: VirtualMan_F
	{
		scope = 2;
		author = "Deathlyrage modified by Th3Dilli";
		displayName = "Breaking Point Player Unit";
		side = 3;
		modelSides[] = {3};
		faction = "CIV_F";
		vehicleClass = "Men";
		class EventHandlers
		{
			init = "";
			local = "";
		};
	};
	class BP_ServerLogic: Logic
	{
		displayName = "SERVER";
		class EventHandlers
		{
			init = "";
			local = "";
		};
	};
	class BP_PlayerLogic: Logic
	{
		displayName = "PLAYER";
		class EventHandlers
		{
			init = "";
			local = "";
		};
	};
	class BP_HeadlessClient: Logic
	{
		displayName = "Survivor";
		author = "Deathlyrage";
		class EventHandlers
		{
			init = "";
			local = "";
		};
	};
	class Thing;
	class BP_Haven: Thing
	{
		scope = 2;
		displayName = "Haven";
		model = "\A3\Weapons_f\dummyweapon.p3d";
		vehicleClass = "Survival";
		author = "Breaking Point";
		destrType = "DestructNo";
		side = 0;
		accuracy = 5;
		armor = 150;
		cost = 0;
	};
	class GroundWeaponHolder;
	class BP_DeadBody: GroundWeaponHolder
	{
		scope = 0;
		displayName = "Dead Body";
		model = "\A3\Weapons_f\dummyweapon.p3d";
		forceSupply = 0;
		maximumLoad = 1000;
		transportMaxMagazines = 400;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 6;
	};
	class BP_DeadBodyAI: BP_DeadBody{};
	class BP_SkeletonRemains: BP_DeadBody
	{
		scope = 1;
		model="\A3\Props_F_Orange\Humanitarian\Camps\Bodybag_01_F.p3d";
		hiddenSelectionsTextures[]=
		{
			"\A3\Props_F_Orange\Humanitarian\Camps\Data\Bodybag_01_black_CO.paa"
		};
	};
	class BP_SkeletonRemainsAI: BP_DeadBodyAI
	{
		scope = 1;
		model="\A3\Props_F_Orange\Humanitarian\Camps\Bodybag_01_F.p3d";
		hiddenSelectionsTextures[]=
		{
			"\A3\Props_F_Orange\Humanitarian\Camps\Data\Bodybag_01_black_CO.paa"
		};
	};
	class BP_GraveDirt: BP_DeadBody
	{
		scope = 1;
		model="\A3\Props_F_Orange\Humanitarian\Camps\Bodybag_01_F.p3d";
		hiddenSelectionsTextures[]=
		{
			"\A3\Props_F_Orange\Humanitarian\Camps\Data\Bodybag_01_blue_CO.paa"
		};
	};
	class BP_GraveDirtAI: BP_DeadBodyAI
	{
		scope = 1;
		model="\A3\Props_F_Orange\Humanitarian\Camps\Bodybag_01_F.p3d";
		hiddenSelectionsTextures[]=
		{
			"\A3\Props_F_Orange\Humanitarian\Camps\Data\Bodybag_01_blue_CO.paa"
		};
	};
	class B_supplyCrate_F;
	class BP_CarePkg: B_supplyCrate_F
	{
		scope = 1;
		displayName = "Care Package";
		hiddenSelectionsTextures[]=
		{
			"\a3\Supplies_F_Orange\Ammoboxes\Data\supplydrop_idap_co.paa"
		};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		class TransportBackpacks{};
	};
	class B_Heli_Transport_03_unarmed_F;
	class BP_Chinook: B_Heli_Transport_03_unarmed_F{};
	class test_EmptyObjectForFireBig;
	class BP_Fire: test_EmptyObjectForFireBig
	{
		scope = 1;
		displayName = "Fire";
		class Eventhandlers
		{
			init = "(_this select 0) execVM '\breakingpoint_code\effects\fire.sqf';";
		};
	};
	class BP_SmallFire: BP_Fire
	{
		scope = 1;
		displayName = "Small Fire";
		class Eventhandlers
		{
			init = "(_this select 0) execVM '\breakingpoint_code\effects\smallfire.sqf';";
		};
	};
	class test_EmptyObjectForSmoke;
	class BP_Smoke: test_EmptyObjectForSmoke
	{
		displayName = "Smoke";
		class Eventhandlers
		{
			init = "(_this select 0) execVM '\breakingpoint_code\effects\smoke.sqf';";
		};
	};
	class BP_SmokeShell: BP_Smoke
	{
		scope = 1;
		displayName = "Smoke Shell";
		class Eventhandlers
		{
			init = "(_this select 0) execVM '\breakingpoint_code\effects\smokeshell.sqf';";
		};
	};
	class Land_Billboard_F;
	class BP_Sign_Ranger: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Ranger)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_ranger.paa"};
	};
	class BP_Sign_Nomad: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Nomad)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_nomad.paa"};
	};
	class BP_Sign_Hunter: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Hunter)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_hunter.paa"};
	};
	class BP_Sign_Outlaw: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Outlaw)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_outlaw.paa"};
	};
	class BP_Sign_Survivalist: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Survivalist)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_survivalist.paa"};
	};
	class BP_Sign_Engineer: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (Engineer)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_engineer.paa"};
	};
	class BP_Sign_Leo: Land_Billboard_F
	{
		scope = 2;
		displayName = "Sign (iLeoChain)";
		model = "\A3\Structures_F\Civ\InfoBoards\Billboard_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"breakingpoint_ui\signs\sign_leo.paa"};
	};
	class ReammoBox;
	class BP_Bag_Base: ReammoBox
	{
		class TransportMagazines{};
		class TransportWeapons{};
		allowedSlots[] = {901};
		class DestructionEffects{};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_co.paa"};
		scope = 1;
		isbackpack = 1;
		reversed = 1;
		mapSize = 2;
		vehicleClass = "Backpacks";
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Small";
		displayName = "Bag";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\ui\backpack_CA.paa";
		icon = "iconBackpack";
		transportMaxWeapons = 1;
		transportMaxMagazines = 20;
		maximumLoad = 0;
		class ItemInfo;
	};
	class BP_AssaultPack_Base: BP_Bag_Base
	{
		scope = 2;
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_khk_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 100;
		mass = 60;
	};
	class BP_Kitbag_Base: BP_Bag_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 150;
		mass = 90;
	};
	class BP_Bergen_Base: BP_Bag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 220;
		mass = 150;
	};
	class BP_FieldPack_Base: BP_Bag_Base
	{
		scope = 2;
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Gorod";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_cbr_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 190;
		mass = 150;
	};
	class BP_Carryall_Base: BP_Bag_Base
	{
		scope = 2;
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Tortila";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_khk_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 280;
		mass = 200;
	};
	class BP_Coyote_Base: BP_Bag_Base
	{
		scope = 2;
		model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
		hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 350;
		mass = 120;
	};
	class BP_CivilianOneBlack: BP_Bag_Base
	{
		scope = 2;
		DLC = "AoW";
		displayName = "Civilian One Pack (Black)";
		model = "\a3\Supplies_F_AoW\Bags\B_CivilianBackpack_01_F.p3d";
		picture = "\a3\Supplies_F_AoW\Bags\Data\UI\icon_B_CivilianBackpack_01_Everyday_Black_F_ca.paa";
		hiddenSelectionsTextures[] = {"a3\Supplies_F_AoW\Bags\Data\CivilianBackpack_01_Everyday_Black_F_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 200;
		mass = 60;
		class ItemInfo: ItemInfo
		{
			passThrough = 0.8;
		};
	};
	class BP_CivilianOneBlue: BP_Bag_Base
	{
		scope = 2;
		DLC = "AoW";
		displayName = "Civilian One Pack (Blue)";
		model = "\a3\Supplies_F_AoW\Bags\B_CivilianBackpack_01_F.p3d";
		picture = "\a3\Supplies_F_AoW\Bags\Data\UI\icon_B_CivilianBackpack_01_Sport_Blue_F_ca.paa";
		hiddenSelectionsTextures[] = {"a3\Supplies_F_AoW\Bags\Data\CivilianBackpack_01_Sport_Blue_F_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 200;
		mass = 60;
		class ItemInfo: ItemInfo
		{
			passThrough = 0.8;
		};
	};
	class BP_CivilianOneGreen: BP_Bag_Base
	{
		scope = 2;
		DLC = "AoW";
		displayName = "Civilian One Pack (Green)";
		model = "\a3\Supplies_F_AoW\Bags\B_CivilianBackpack_01_F.p3d";
		picture = "\a3\Supplies_F_AoW\Bags\Data\UI\icon_B_CivilianBackpack_01_Sport_Green_F_ca.paa";
		hiddenSelectionsTextures[] = {"a3\Supplies_F_AoW\Bags\Data\CivilianBackpack_01_Sport_Green_F_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 200;
		mass = 60;
		class ItemInfo: ItemInfo
		{
			passThrough = 0.8;
		};
	};
	class BP_CivilianOneRed: BP_Bag_Base
	{
		scope = 2;
		DLC = "AoW";
		displayName = "Civilian One Pack (Red)";
		model = "\a3\Supplies_F_AoW\Bags\B_CivilianBackpack_01_F.p3d";
		picture = "\a3\Supplies_F_AoW\Bags\Data\UI\icon_B_CivilianBackpack_01_Sport_Red_F_ca.paa";
		hiddenSelectionsTextures[] = {"a3\Supplies_F_AoW\Bags\Data\CivilianBackpack_01_Sport_Red_F_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 200;
		mass = 60;
		class ItemInfo: ItemInfo
		{
			passThrough = 0.8;
		};
	};
	class BP_HPack: BP_Bag_Base
	{
		scope = 2;
		model = "\breakingpoint_classes\models\BP_HPack.p3d";
		picture = "\breakingpoint_ui\updatedimage\alicepack.paa";
		allowedSlots[] = {};
		maximumLoad = 260;
		mass = 200;
		displayName = "Nomad Alice Pack";
	};
	class BP_MPack: BP_Bag_Base
	{
		scope = 2;
		model = "\breakingpoint_classes\models\BP_MPack.p3d";
		picture = "\breakingpoint_ui\updatedimage\medic.paa";
		allowedSlots[] = {};
		maximumLoad = 150;
		mass = 120;
		displayName = "Ranger Medic Pack";
	};
	class BP_SPack: BP_Bag_Base
	{
		scope = 2;
		model = "\breakingpoint_classes\models\BP_SPack.p3d";
		picture = "\breakingpoint_ui\updatedimage\czecksurvival.paa";
		allowedSlots[] = {};
		maximumLoad = 330;
		mass = 250;
		displayName = "Czech Survival Pack";
	};
	class BP_RPack: BP_Bag_Base
	{
		scope = 2;
		model = "\breakingpoint_classes\models\BP_RPack.p3d";
		picture = "\breakingpoint_ui\updatedimage\outlaw.paa";
		allowedSlots[] = {};
		maximumLoad = 180;
		mass = 90;
		displayName = "Outlaw Equipment Pack";
	};
	class BP_RPack2: BP_Bag_Base
	{
		scope = 2;
		model = "\breakingpoint_classes\models\BP_RPack2.p3d";
		picture = "\breakingpoint_ui\updatedimage\outlaw2.paa";
		allowedSlots[] = {};
		maximumLoad = 240;
		mass = 100;
		displayName = "Outlaw Heavy Pack";
	};
	class BP_KPack: BP_Bag_Base
	{
		scope = 2;
		picture="\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_oli.paa";
		model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Small";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_oli_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 230;
		mass = 120;
		displayName = "Tactical Pack";
	};
	class BP_AssaultPack_khk: BP_AssaultPack_Base
	{
		scope = 2;
		displayName = "Civilian Bag (Khaki)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_AssaultPack_khk_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_khk_co.paa"};
	};
	class BP_AssaultPack_dgtl: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_dgtl_ca.paa";
		displayName = "Civilian Bag (Digital)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_digi_co.paa"};
	};
	class BP_AssaultPack_rgr: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_rgr_ca.paa";
		displayName = "Civilian Bag (Green)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_rgr_co.paa"};
	};
	class BP_AssaultPack_sgg: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_sgg_ca.paa";
		displayName = "Civilian Bag (Sage)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_sgg_co.paa"};
	};
	class BP_AssaultPack_blk: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
		displayName = "Civilian Bag (Black)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
	};
	class BP_AssaultPack_cbr: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_AssaultPack_cbr_ca.paa";
		displayName = "Civilian Bag (Tan)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_cbr_co.paa"};
	};
	class BP_AssaultPack_mcamo: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Compact_mcamo_ca.paa";
		displayName = "Civilian Bag (Camo)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_mcamo_co.paa"};
	};
	class BP_AssaultPack_drt: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_AssaultPack_cbr_ca.paa";
		displayName = "Civilian Bag (Dirt)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_compact_drt_co.paa"};
	};
	class BP_AssaultPack_grs: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_rgr_ca.paa";
		displayName = "Civilian Bag (Grass)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_compact_grs_co.paa"};
	};
	class BP_AssaultPack_stn: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Compact_mcamo_ca.paa";
		displayName = "Civilian Bag (Stone)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_compact_stn_co.paa"};
	};
	class BP_AssaultPack_tre: BP_AssaultPack_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_rgr_ca.paa";
		displayName = "Civilian Bag (Tree)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_compact_tre_co.paa"};
	};
	class BP_Kitbag_mcamo: BP_Kitbag_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_mcamo";
		displayName = "Sports Bag (Camo)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_mcamo_co.paa"};
	};
	class BP_Kitbag_sgg: BP_Kitbag_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_sgg";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_sgg_co.paa"};
		displayName = "Sports Bag (Sage)";
	};
	class BP_Kitbag_cbr: BP_Kitbag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_cbr_co.paa"};
		displayName = "Sports Bag (Tan)";
	};
	class BP_Kitbag_drt: BP_Kitbag_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_mcamo";
		displayName = "Sports Bag (Dirt)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_fast_drt_co.paa"};
	};
	class BP_Kitbag_grs: BP_Kitbag_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_sgg";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_fast_grs_co.paa"};
		displayName = "Sports Bag (Grass)";
	};
	class BP_Kitbag_stn: BP_Kitbag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_fast_stn_co.paa"};
		displayName = "Sports Bag (Stone)";
	};
	class BP_Kitbag_tre: BP_Kitbag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_fast_tre_co.paa"};
		displayName = "Sports Bag (Tree)";
	};
	class BP_Bergen_sgg: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_rgr.paa";
		displayName = "British Rucksack (Sage)";
	};
	class BP_Bergen_mcamo: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_mcamo.paa";
		displayName = "British Rucksack (Camo)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_mcamo_co.paa"};
	};
	class BP_Bergen_rgr: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_rgr.paa";
		displayName = "British Rucksack (Green)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_rgr_co.paa"};
	};
	class BP_Bergen_blk: BP_Bergen_Base
	{
		scope = 2;
		displayName = "British Rucksack (Black)";
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_b_c_small_blk.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_blk_co.paa"};
	};
	class BP_Bergen_drt: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_khk.paa";
		displayName = "British Rucksack (Dirt)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_small_drt_co.paa"};
	};
	class BP_Bergen_grs: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_rgr.paa";
		displayName = "British Rucksack (Grass)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_small_grs_co.paa"};
	};
	class BP_Bergen_stn: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_mcamo.paa";
		displayName = "British Rucksack (Stone)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_small_stn_co.paa"};
	};
	class BP_Bergen_tre: BP_Bergen_Base
	{
		scope = 2;
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Small_hex.paa";
		displayName = "British Rucksack (Tree)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_small_tre_co.paa"};
	};
	class BP_FieldPack_blk: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F_beta\ammoboxes\bags\data\ui\icon_B_Gorod_blk_ca.paa";
		displayName = "Activity Rucksack (Black)";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_blk_co.paa"};
	};
	class BP_FieldPack_ocamo: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Gorod_hex_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_hex_co.paa"};
		displayName = "Activity Rucksack (Hex)";
	};
	class BP_FieldPack_oucamo: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\ui\icon_B_C_Gorod_oucamo_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_oucamo_co.paa"};
		displayName = "Activity Rucksack (Urban)";
	};
	class BP_FieldPack_cbr: BP_FieldPack_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_cbr_co.paa"};
		displayName = "Activity Rucksack (Tan)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Gorod_cbr_ca.paa";
	};
	class BP_FieldPack_drt: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Gorod_hex_ca.paa";
		displayName = "Activity Rucksack (Dirt)";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_gorod_drt_co.paa"};
	};
	class BP_FieldPack_grs: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F_beta\ammoboxes\bags\data\ui\icon_B_Gorod_oli_ca.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_gorod_grs_co.paa"};
		displayName = "Activity Rucksack (Grass)";
	};
	class BP_FieldPack_stn: BP_FieldPack_Base
	{
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\ui\icon_B_C_Gorod_oucamo_ca.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_gorod_stn_co.paa"};
		displayName = "Activity Rucksack (Stone)";
	};
	class BP_FieldPack_tree: BP_FieldPack_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_gorod_tre_co.paa"};
		displayName = "Activity Rucksack (Tree)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Gorod_cbr_ca.paa";
	};
	class BP_Carryall_ocamo: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Hex)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_hex_co.paa"};
	};
	class BP_Carryall_oucamo: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Urban)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_oucamo.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_oucamo_co.paa"};
	};
	class BP_Carryall_mcamo: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Camo)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_mcamo.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_mcamo_co.paa"};
	};
	class BP_Carryall_blk: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Black)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
		hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_blk_co.paa"};
	};
	class BP_Carryall_drt: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Dirt)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_tortila_drt_co.paa"};
	};
	class BP_Carryall_grs: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Grass)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_oucamo.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_tortila_grs_co.paa"};
	};
	class BP_Carryall_stn: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Stone)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_mcamo.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_tortila_stn_co.paa"};
	};
	class BP_Carryall_tre: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Survival Backpack (Tree)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_tortila_tre_co.paa"};
	};
	class BP_Coyote_rgr: BP_Coyote_Base
	{
		scope = 2;
		displayName = "Coyote Backpack (Drab)";
		model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
		picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
		hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 390;
		mass = 120;
	};
	class BP_Coyote_oli: BP_Coyote_Base
	{
		scope = 2;
		displayName = "Coyote Backpack (Olive)";
		model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
		picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_oli_ca";
		hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_oli_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 390;
		mass = 120;
	};
	class BP_Coyote_cbr: BP_Coyote_Base
	{
		scope = 2;
		displayName = "Coyote Backpack (Brown)";
		model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
		picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_cbr_ca";
		hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_cbr_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 390;
		mass = 120;
	};
	class BP_Bergen_Hero: BP_Bergen_Base
	{
		scope = 2;
		displayName = "Rucksack (Hero)";
		picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_b_c_small_blk.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_herobergen_co.paa"};
	};
	class BP_Carryall_Hero: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Military Survival Pack";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_blk.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\BP_backpack_tortila_blk_co.paa"};
		class ItemInfo: ItemInfo
		{
			passThrough = 0.9;
		};
	};
	class BP_Carryall_Bandit: BP_Carryall_Base
	{
		scope = 2;
		displayName = "Military Survival (Bandit)";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_cbr.paa";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_tortila_cbr_co.paa"};
		maximumLoad = 360;
		mass = 100;
	};
	class BP_Coyote_Bandit: BP_Coyote_Base
	{
		scope = 2;
		displayName = "Coyote (Bandit)";
		picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_cbr_ca";
		model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
		hiddenSelectionsTextures[] = {"\breakingpoint\textures\backpack\backpack_coyote_bandit_co.paa"};
		allowedSlots[] = {};
		maximumLoad = 420;
		mass = 150;
	};
	class Wreck_base_F;
	class Land_Wreck_Transport_BP: Wreck_base_F
	{
		mapSize = 23.97;
		author = "Bohemia Interactive";
		scope = 2;
		displayName = "Blackfoot Wreck";
		model = "\A3\air_f_heli\Heli_Transport_03\Heli_Transport_03_wreck_F.p3d";
		icon = "iconObject_1x2";
		selectionDamage = "DamT_1";
	};
	class BP_LootBox;
	class BP_CampfireBase: BP_LootBox
	{
		scope = 0;
		displayName = "Camp Fire";
		author = "Breaking Point Mod";
		model = "\A3\Structures_F\Civ\Camping\Fireplace_F.p3d";
		icon = "iconObject_circle";
		vehicleClass = "Tents";
		destrType = "DestructNo";
		simulation = "fire";
		cost = 0;
		mapSize = 1.03;
		ladders[] = {};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		class EventHandlers
		{
			init = "";
			local = "if (_this select 1) then { deleteVehicle (_this select 0); };";
		};
		class Effects: SmallFire
		{
			class Light1
			{
				simulation = "light";
				type = "SmallFireLight";
			};
			class sound
			{
				simulation = "sound";
				type = "Fire";
			};
			class Smoke1
			{
				simulation = "particles";
				type = "SmallFireS";
			};
			class Fire1: Smoke1
			{
				simulation = "particles";
				type = "SmallFireBP";
			};
			class Refract1
			{
				simulation = "particles";
				type = "SmallFireFRefract";
			};
		};
	};
	class BP_LargeCampFire: BP_CampfireBase
	{
		scope = 2;
	};
	class BP_SmallCampFire: BP_CampfireBase
	{
		scope = 2;
	};
	class Man
	{
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
	};
	class CAManBase;
	class BP_Man: CAManBase
	{
		class HitPoints
		{
			class HitFace
			{
				armor = 1;
				material = -1;
				name = "face_hub";
				passThrough = 0.1;
				radius = 0.08;
				explosionShielding = 0.1;
				minimalHit = 0.01;
			};
			class HitNeck: HitFace
			{
				armor = 1;
				material = -1;
				name = "neck";
				passThrough = 0.1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0.01;
			};
			class HitHead: HitNeck
			{
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 0.5;
				minimalHit = 0.01;
				depends = "HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor = 1;
				material = -1;
				name = "pelvis";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor = 1;
				material = -1;
				name = "spine1";
				passThrough = 0.1;
				radius = 0.025;
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor = 1;
				material = -1;
				name = "spine2";
				passThrough = 0.1;
				radius = 0.025;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor = 1;
				material = -1;
				name = "spine3";
				passThrough = 0.1;
				radius = 0.05;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "body";
				passThrough = 0.1;
				radius = 0.15;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms
			{
				armor = 1;
				material = -1;
				name = "arms";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0.01;
			};
			class HitHands: HitArms
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0.01;
				depends = "HitArms";
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 0.1;
				radius = 0.09;
				explosionShielding = 1;
				visual = "injury_legs";
				minimalHit = 0.01;
			};
		};
		class SoundEquipment
		{
			soldier[] = {{"walk",{"A3\sounds_f\characters\movements\suit_run_01",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_02",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_03",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_04",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_05",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_06",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_07",0.046234,1,30}},{"walk",{"A3\sounds_f\characters\movements\suit_run_08",0.046234,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_01",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_02",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_03",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_04",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_05",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_06",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_07",0.053096,1,32}},{"run",{"A3\sounds_f\characters\movements\suit_run_08",0.053096,1,32}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_01",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_02",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_03",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_04",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_05",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_06",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_07",0.09,1,35}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_08",0.09,1,35}}};
			civilian[] = {{"walk",{"A3\sounds_f\characters\movements\suit_run_01",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_02",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_03",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_04",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_05",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_06",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_07",0.046234,1,20}},{"walk",{"A3\sounds_f\characters\movements\suit_run_08",0.046234,1,20}},{"run",{"A3\sounds_f\characters\movements\suit_run_01",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_02",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_03",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_04",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_05",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_06",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_07",0.064433,1,30}},{"run",{"A3\sounds_f\characters\movements\suit_run_08",0.064433,1,30}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_01",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_02",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_03",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_04",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_05",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_06",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_07",0.09,1,40}},{"sprint",{"A3\sounds_f\characters\movements\suit_sprint_08",0.09,1,40}}};
		};
		class SoundEnvironExt
		{
			generic[] = {{"healself",{"\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWrflDnon_medic",0.791251,1,70}},{"healselfprone",{"\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWrflDnon_medic",0.791251,1,70}},{"healselfpistolkneelin",{"\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medicIn",0.791251,1,70}},{"healselfpistolkneel",{"\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medic",0.791251,1,70}},{"healselfpistolkneelout",{"\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medicOut",0.791251,1,70}},{"healselfpistolpromein",{"\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medicin",0.791251,1,70}},{"healselfpistolprone",{"\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medic",0.791251,1,70}},{"healselfpistolpromeout",{"\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medicOut",0.791251,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"adjust_short",{"\A3\sounds_f\characters\stances\adjust_short1",0.158489,1,70}},{"adjust_short",{"\A3\sounds_f\characters\stances\adjust_short2",0.158489,1,70}},{"adjust_short",{"\A3\sounds_f\characters\stances\adjust_short3",0.158489,1,70}},{"adjust_short",{"\A3\sounds_f\characters\stances\adjust_short4",0.158489,1,70}},{"adjust_short",{"\A3\sounds_f\characters\stances\adjust_short5",0.158489,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\adjust_short1",0.158489,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\adjust_short1",0.158489,1,70}},{"adjust_kneelhigh_to_standlow",{"\A3\sounds_f\characters\stances\adjust_short3",0.158489,1,70}},{"adjust_standlow_to_kneelhigh",{"\A3\sounds_f\characters\stances\adjust_short1",0.158489,1,70}},{"grenade_throw",{"\A3\sounds_f\characters\stances\adjust_short1",0.354813,1,70}},{"grenade_throw",{"\A3\sounds_f\characters\stances\adjust_short2",0.354813,1,70}},{"grenade_throw",{"\A3\sounds_f\characters\stances\adjust_short3",0.354813,1,70}},{"grenade_throw",{"\A3\sounds_f\characters\stances\adjust_short4",0.354813,1,70}},{"grenade_throw",{"\A3\sounds_f\characters\stances\adjust_short5",0.354813,1,70}},{"inventory_in",{"\A3\sounds_f\characters\stances\adjust_short1",0.251189,1,70}},{"inventory_out",{"\A3\sounds_f\characters\stances\adjust_short2",0.251189,1,70}},{"handgun_to_launcher",{"\A3\sounds_f\characters\stances\handgun_to_launcher",0.251189,1,70}},{"handgun_to_rifle",{"\A3\sounds_f\characters\stances\handgun_to_rifle",0.251189,1,70}},{"handgun_to_unarmed",{"\A3\sounds_f\characters\stances\handgun_to_unarmed",0.251189,1,70}},{"launcher_to_handgun",{"\A3\sounds_f\characters\stances\launcher_to_handgun",0.251189,1,70}},{"launcher_to_rifle",{"\A3\sounds_f\characters\stances\launcher_to_rifle",0.251189,1,70}},{"launcher_to_unarmed",{"\A3\sounds_f\characters\stances\launcher_to_unarmed",0.251189,1,70}},{"rifle_to_handgun",{"\A3\sounds_f\characters\stances\rifle_to_handgun",0.251189,1,70}},{"rifle_to_launcher",{"\A3\sounds_f\characters\stances\rifle_to_launcher",0.251189,1,70}},{"rifle_to_unarmed",{"\A3\sounds_f\characters\stances\rifle_to_unarmed",0.251189,1,70}},{"unarmed_to_handgun",{"\A3\sounds_f\characters\stances\unarmed_to_handgun",0.251189,1,70}},{"unarmed_to_launcher",{"\A3\sounds_f\characters\stances\unarmed_to_launcher",0.251189,1,70}},{"unarmed_to_rifle",{"\A3\sounds_f\characters\stances\unarmed_to_rifle",0.251189,1,70}},{"to_binoc",{"\A3\sounds_f\characters\stances\rifle_to_binoculars",0.251189,1,70}},{"to_binoc_lnr",{"\A3\sounds_f\characters\stances\rifle_to_binoculars",0.251189,1,70}},{"to_binoc_civil",{"\A3\sounds_f\characters\stances\unarmed_to_binoculars",0.251189,1,70}},{"from_binoc",{"\A3\sounds_f\characters\stances\binoculars_to_rifle",0.251189,1,70}},{"from_binoc_lnr",{"\A3\sounds_f\characters\stances\handgun_to_launcher",0.251189,1,70}},{"from_binoc_civil",{"\A3\sounds_f\characters\stances\binoculars_to_unarmed",0.251189,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_01",0.301187,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_02",0.301187,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_03",0.301187,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_04",0.301187,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_05",0.301187,1,70}},{"ladder",{"\A3\Sounds_F\characters\movements\ladder\ladder_06",0.301187,1,70}},{"Acts_CrouchGetLowGesture",{"\A3\Sounds_F\characters\cutscenes\Acts_CrouchGetLowGesture",0.791251,1,70}},{"Acts_listeningToRadio_in",{"A3\Sounds_F\characters\cutscenes\Acts_listeningToRadio_in",0.791251,1,70}},{"Acts_listeningToRadio_Loop",{"\A3\Sounds_F\dummysound",0.791251,1,70}},{"Acts_listeningToRadio_Out",{"\A3\Sounds_F\characters\cutscenes\Acts_listeningToRadio_Out",0.791251,1,70}},{"Acts_LyingWounded_loop1",{"\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop1",0.791251,1,70}},{"Acts_LyingWounded_loop2",{"\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop2",0.791251,1,70}},{"Acts_LyingWounded_loop3",{"\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop3",0.791251,1,70}},{"Acts_NavigatingChopper_In",{"\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_In",0.362341,1,70}},{"Acts_NavigatingChopper_Loop",{"\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_Loop",0.362341,1,70}},{"Acts_NavigatingChopper_Out",{"\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_Out",0.362341,1,70}},{"Acts_PercMstpSlowWrflDnon_handup1",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1",0.362341,1,70}},{"Acts_PercMstpSlowWrflDnon_handup1b",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1b",0.362341,1,70}},{"Acts_PercMstpSlowWrflDnon_handup1c",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1c",0.362341,1,70}},{"Acts_PercMstpSlowWrflDnon_handup2",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2",0.362341,1,70}},{"Acts_PercMstpSlowWrflDnon_handup2b",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2b",0.791251,1,70}},{"Acts_PercMstpSlowWrflDnon_handup2c",{"\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2c",0.362341,1,70}},{"Acts_SignalToCheck",{"\A3\Sounds_F\characters\cutscenes\Acts_SignalToCheck",0.362341,1,70}},{"Acts_ShowingTheRightWay_in",{"\A3\Sounds_F\characters\cutscenes\Acts_ShowingTheRightWay_in",0.362341,1,70}},{"Acts_ShowingTheRightWay_loop",{"\A3\Sounds_F\characters\cutscenes\Acts_ShowingTheRightWay_Loop",0.362341,1,70}},{"Acts_ShowingTheRightWay_out",{"\A3\Sounds_F\characters\cutscenes\Acts_ShowingTheRightWay_Out",0.362341,1,70}},{"Acts_ShieldFromSun_loop",{"\A3\Sounds_F\dummysound",0.362341,1,70}},{"Acts_ShieldFromSun_out",{"\A3\Sounds_F\characters\cutscenes\Acts_ShieldFromSun_Out",0.362341,1,70}},{"Acts_TreatingWounded01",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded01",0.362341,1,70}},{"Acts_TreatingWounded02",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded02",0.362341,1,70}},{"Acts_TreatingWounded03",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded03",0.362341,1,70}},{"Acts_TreatingWounded04",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded04",0.362341,1,70}},{"Acts_TreatingWounded05",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded05",0.362341,1,70}},{"Acts_TreatingWounded06",{"\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded06",0.362341,1,70}},{"Acts_AidlPercMstpSlowWrflDnon_pissing",{"\A3\Sounds_F\characters\cutscenes\Acts_AidlPercMstpSlowWrflDnon_pissing",0.791251,1,70}},{"Acts_BoatAttacked01",{"\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked01",0.791251,1,70}},{"Acts_BoatAttacked02",{"\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked02",0.791251,1,70}},{"Acts_BoatAttacked03",{"\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked03",0.791251,1,70}},{"Acts_BoatAttacked04",{"\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked04",0.791251,1,70}},{"Acts_BoatAttacked05",{"\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked05",0.791251,1,70}},{"acts_CrouchingCoveringRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_CrouchingCoveringRifle01",0.362341,1,70}},{"acts_CrouchingIdleRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_CrouchingIdleRifle01",0.362341,1,70}},{"acts_CrouchingReloadingRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_CrouchingReloadingRifle01",0.362341,1,70}},{"acts_CrouchingWatchingRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_CrouchingWatchingRifle01",0.362341,1,70}},{"acts_InjuredAngryRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredAngryRifle01",0.362341,1,70}},{"acts_InjuredCoughRifle02",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredCoughRifle02",0.362341,1,70}},{"acts_InjuredLookingRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle01",0.362341,1,70}},{"acts_InjuredLookingRifle02",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle02",0.362341,1,70}},{"acts_InjuredLookingRifle03",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle03",0.362341,1,70}},{"acts_InjuredLookingRifle04",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle04",0.362341,1,70}},{"acts_InjuredLookingRifle05",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle05",0.362341,1,70}},{"acts_InjuredLyingRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredLyingRifle01",0.362341,1,70}},{"acts_InjuredSpeakingRifle01",{"\A3\Sounds_F\characters\cutscenes\Acts_InjuredSpeakingRIfle01",0.362341,1,70}},{"Acts_PknlMstpSlowWrflDnon",{"\A3\Sounds_F\characters\cutscenes\Acts_PknlMstpSlowWrflDnon",0.362341,1,70}},{"Acts_SittingJumpingSaluting_loop1",{"\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop1",0.362341,1,70}},{"Acts_SittingJumpingSaluting_loop2",{"\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_loop3",{"\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisekneeBendA",{"\A3\Sounds_F\characters\cutscenes\AmovPercMstpSnonWnonDnon_exercisekneeBendA",0.362341,1,70}}};
			rock[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\rock_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\rock_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\rock_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\rock_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\rock_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.223872,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			normal[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			tarmac[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.223872,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.223872,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",1,1,70}}};
			stony[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\stony_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\stony_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\stony_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\stony_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\stony_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			water[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\crawl\crawl_water_7",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\water_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\water_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\water_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\water_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\water_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\water_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_1",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_2",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_3",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_4",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_5",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_6",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_7",0.199526,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\crawl_water_8",0.199526,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default4",0.301187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-1",0.501187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-2",0.501187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-3",0.501187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-4",0.501187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-5",0.501187,1,70}},{"dive",{"A3\Sounds_F\characters\movements\diver-swim-6",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-1",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-2",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-3",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-4",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-5",0.501187,1,70}},{"dive_dry",{"A3\Sounds_F\characters\movements\diver-dry-swim-6",0.501187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			gravel[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\crawl\Gravel_crawl_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\gravel_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\gravel_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\gravel_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\gravel_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\gravel_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_1",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_2",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_3",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_4",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_5",0.199526,1,40}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			roof_tiles[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tiles_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tiles_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tiles_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			sand[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\sand_roll_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\sand_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\sand_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\sand_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\sand_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\sand_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\Sand_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Sand_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Sand_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Sand_crawl_4",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Sand_crawl_5",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			drygrass[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\grass_roll_2",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\new_dry_grass_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\new_dry_grass_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_4",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_5",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			grass[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\grass_roll_2",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\new_grass_walk_1",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_2",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_3",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_4",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_5",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_6",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_7",0.158489,1,70},{"\A3\sounds_f\characters\footsteps\new_grass_walk_8",0.158489,1,70},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_1",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_2",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_3",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_4",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_5",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_6",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_7",0.251189,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\new_grass_run_8",0.251189,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_1",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_2",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_3",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_4",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_5",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_6",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_7",0.158489,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\new_grass_walk_8",0.158489,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_1",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_2",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_3",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_4",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_5",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_6",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_7",0.316228,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\new_grass_sprint_8",0.316228,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_1",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_2",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_3",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_4",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Grass_crawl_5",0.177828,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			debris[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\dirt_roll_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\debris_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\debris_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\debris_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\debris_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\debris_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_4",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_5",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			wood[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\dirt_roll_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_1",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_2",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_3",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_4",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_5",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_6",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_7",0.301187,0.7,100},{"\A3\sounds_f\characters\footsteps\wood_walk_ext_8",0.301187,0.7,100},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_1",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_2",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_3",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_4",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_5",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_6",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_7",0.301187,0.7,100}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_ext_8",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_1",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_2",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_3",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_4",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_5",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_6",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_7",0.301187,0.7,100}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_ext_8",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_1",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_2",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_3",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_4",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_5",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_6",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_7",0.301187,0.7,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_ext_8",0.301187,0.7,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			wood_int[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\dirt_roll_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\wood_walk_int_1",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_2",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_3",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_4",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_5",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_6",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_7",0.301187,0.7,70},{"\A3\sounds_f\characters\footsteps\wood_walk_int_8",0.301187,0.7,70},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_1",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_2",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_3",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_4",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_5",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_6",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_7",0.301187,0.7,70}},{"run",{"\A3\sounds_f\characters\footsteps\wood_run_int_8",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_1",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_2",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_3",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_4",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_5",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_6",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_7",0.301187,0.7,70}},{"walk",{"\A3\sounds_f\characters\footsteps\wood_walk_int_8",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_1",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_2",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_3",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_4",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_5",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_6",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_7",0.301187,0.7,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\wood_sprint_int_8",0.301187,0.7,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			concrete_int[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_int_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_int_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_int_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_int_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			concrete[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\concrete_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\concrete_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,40}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			metal[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\metal_walk_1",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_2",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_3",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_4",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_5",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_6",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_7",0.301187,1,120},{"\A3\sounds_f\characters\footsteps\metal_walk_8",0.301187,1,120},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_1",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_2",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_3",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_4",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_5",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_6",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_7",0.301187,1,120}},{"run",{"\A3\sounds_f\characters\footsteps\metal_run_8",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_1",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_2",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_3",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_4",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_5",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_6",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_7",0.301187,1,120}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_walk_8",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_1",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_2",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_3",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_4",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_5",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_6",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_7",0.301187,1,120}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_sprint_8",0.301187,1,120}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,40}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			metal_int[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\metal_int_walk_1",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_2",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_3",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_4",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_5",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_6",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_7",0.301187,1,100},{"\A3\sounds_f\characters\footsteps\metal_int_walk_8",0.301187,1,100},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_1",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_2",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_3",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_4",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_5",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_6",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_7",0.301187,1,100}},{"run",{"\A3\sounds_f\characters\footsteps\metal_int_run_8",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_1",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_2",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_3",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_4",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_5",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_6",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_7",0.301187,1,100}},{"walk",{"\A3\sounds_f\characters\footsteps\metal_int_walk_8",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_1",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_2",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_3",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_4",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_5",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_6",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_7",0.301187,1,100}},{"sprint",{"\A3\sounds_f\characters\footsteps\metal_int_sprint_8",0.301187,1,100}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.199526,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.199526,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			tiles_int[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_1",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_2",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_3",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_4",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_5",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_6",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_7",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\tiles_int_walk_8",0.301187,1,70},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_1",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_2",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_3",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_4",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_5",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_6",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_7",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\tiles_int_run_8",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_1",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_2",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_3",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_4",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_5",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_6",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_7",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\tiles_int_walk_8",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_1",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_2",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_3",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_4",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_5",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_6",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_7",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\tiles_int_sprint_8",0.301187,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.177828,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.177828,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.177828,1,40}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.177828,1,40}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			dirt[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\dirt_roll_1",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_1",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_2",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_3",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_4",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_5",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_6",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_7",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\dirt_walk_new_8",0.301187,1,70},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_1",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_2",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_3",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_4",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_5",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_6",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_7",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\dirt_run_new_8",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_1",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_2",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_3",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_4",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_5",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_6",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_7",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\dirt_walk_new_8",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_1",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_2",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_3",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_4",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_5",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_6",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_7",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\dirt_sprint_new_8",0.301187,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_1",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_2",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_3",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_4",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\Dirt_crawl_5",0.177828,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\dirt_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
			roof_tin[] = {{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_stand_side",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.251189,1,70}},{"adjust_stand_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.251189,1,70}},{"adjust_kneel_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.251189,1,70}},{"adjust_stand_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.251189,1,70}},{"adjust_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.251189,1,70}},{"adjust_prone_up",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.251189,1,70}},{"adjust_prone_up_back",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.251189,1,70}},{"adjust_prone_down",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.251189,1,70}},{"adjust_prone_left",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.251189,1,70}},{"adjust_prone_right",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.251189,1,70}},{"adjust_kneel_to_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.251189,1,70}},{"adjust_prone_to_kneel",{"\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.251189,1,70}},{"adjust_stand_to_left_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.251189,1,70}},{"adjust_stand_to_right_prone",{"\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.251189,1,70}},{"adjust_left_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.251189,1,70}},{"adjust_right_prone_to_stand",{"\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.251189,1,70}},{"roll",{"A3\Sounds_F\characters\movements\roll\concrete_roll_3",0.791251,1,70}},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_1",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_2",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_3",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_4",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_5",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_6",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_7",0.301187,1,70},{"\A3\sounds_f\characters\footsteps\roof_tin_walk_8",0.301187,1,70},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_1",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_2",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_3",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_4",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_5",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_6",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_7",0.301187,1,70}},{"run",{"\A3\sounds_f\characters\footsteps\roof_tin_run_8",0.301187,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_1",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_2",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_3",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_4",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_5",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_6",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_7",0.005623,1,70}},{"walk",{"\A3\sounds_f\characters\footsteps\roof_tin_walk_8",0.005623,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_1",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_2",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_3",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_4",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_5",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_6",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_7",0.301187,1,70}},{"sprint",{"\A3\sounds_f\characters\footsteps\roof_tin_sprint_8",0.301187,1,70}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_1",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_2",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_3",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_4",0.177828,1,50}},{"crawl",{"\A3\sounds_f\characters\crawl\concrete_crawl_5",0.177828,1,50}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.301187,1,70}},{"bodyfall",{"\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default1",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default2",0.301187,1,70}},{"swim",{"A3\Sounds_F\characters\movements\swim\swim_default3",0.301187,1,70}},{"Acts_carFixingWheel",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.362341,1,70}},{"Acts_PercMwlkSlowWrflDf2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.362341,1,70}},{"Acts_SittingJumpingSaluting_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.362341,1,70}},{"Acts_WalkingChecking",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle02",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle03",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.362341,1,70}},{"Acts_CrouchingFiringLeftRifle04",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.362341,1,70}},{"Acts_HUBABriefing",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.362341,1,70}},{"Acts_PointingLeftUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.362341,1,70}},{"Acts_SittingJumpingSaluting_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.362341,1,70}},{"Acts_StandingSpeakingUnarmed",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.362341,1,70}},{"Acts_TreatingWounded_in",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.362341,1,70}},{"Acts_TreatingWounded_out",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.362341,1,70}},{"Acts_UnconsciousStandUp_part1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_1b",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB01_PlayerWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_4",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_5",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.362341,1,70}},{"Acts_WelcomeOnHUB02_AIWalk_6",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_1",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_2",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.362341,1,70}},{"Acts_WelcomeOnHUB02_PlayerWalk_3",{"A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.362341,1,70}},{"AmovPercMstpSnonWnonDnon_exercisePushup",{"\A3\Sounds_F\characters\cutscenes\concrete_AmovPercMstpSnonWnonDnon_exercisePushup",0.362341,1,70}}};
		};
		sensitivity = 10;
		sensitivityEar = 5;
		accuracy = 0.2;
		camouflage = 8;
		threat[] = {1,0.1,0.1};
	};
	class Animal;
	class BP_Animal: Man
	{
		class Wounds;
	};
	class BP_Animal_Base: BP_Animal
	{
		afMax = 30;
		mfMax = 0;
		mFact = 1;
		tBody = 37;
		side = 3;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		icon = "iconAnimal";
		agentTasks[] = {"AnimalMainTask"};
		moves = "CfgMovesAnimal";
		memoryPointHeadAxis = "head_axis";
		woman = 0;
		boneLEye = "l_eye";
		boneREye = "r_eye";
		boneLEyelidUp = "eye_upl";
		boneREyelidUp = "eye_upr";
		boneLEyelidDown = "eye_lwl";
		boneREyelidDown = "eye_lwr";
		boneLPupil = "l_pupila";
		boneRPupil = "r_pupila";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		simulation = "animal";
		features = "";
		isFish = 0;
		class Wounds: Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar
		{
			_threatMaxRadius = 50;
			_runDistanceMax = 100;
			_movePrefer = 0.7;
			_formationPrefer = 0.1;
			_scareLimit = 0.2;
			_dangerLimit = 1;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger = "(trees) * (forest) * (1 - meadow) * (1 - sea)";
		};
	};
	class Animal_Base_F;
	class BP_Dog: BP_Animal_Base
	{
		scope = 0;
		hasGeometry = 1;
		moves = "CfgMovesDog_BP";
		agentTasks[] = {};
		extCameraPosition[] = {0,0.5,-2.5};
		class EventHandlers
		{
			init = "_this call BP_fnc_dogInit;";
			local = "_this call BP_fnc_dogLocal;";
			handledamage = "_this call BP_fnc_dogHandleDamage;";
			killed = "_this call BP_fnc_dogKilled;";
		};
		class VariablesScalar{};
		class VariablesString{};
		baseClass = "BP_Dog";
	};
	class BP_Dog_Alsatian_Base: BP_Dog
	{
		scope = 0;
		displayName = "$STR_A3_CfgVehicles_Alsatian_Base_F0";
		model = "\A3\animals_f_beta\dog\Pastor_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\pastor_sand_co.paa"};
	};
	class BP_Dog_Fin_Base: BP_Dog
	{
		scope = 0;
		displayName = "$STR_A3_CfgVehicles_Fin_Base_F0";
		model = "\A3\animals_f_beta\dog\Fin_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\dog_yellow_co.paa"};
	};
	class BP_Dog_1: BP_Dog_Fin_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Fin_sand_F0";
	};
	class BP_Dog_2: BP_Dog_Fin_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Fin_blackwhite_F0";
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\Dog_black_white_co.paa"};
	};
	class BP_Dog_3: BP_Dog_Fin_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Fin_ocherwhite_F0";
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\Dog_white_ocher_CO.paa"};
	};
	class BP_Dog_4: BP_Dog_Fin_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Fin_tricolour_F0";
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\Dog_tricolor_CO.paa"};
	};
	class BP_Dog_5: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Alsatian_Sand_F0";
	};
	class BP_Dog_6: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Alsatian_Black_F0";
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\pastor_black_co.paa"};
	};
	class BP_Dog_7: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Alsatian_Sandblack_F0";
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\dog\data\pastor_co.paa"};
	};
	class BP_Dog_Ranger: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "Ranger Dog";
		baseClass = "BP_Dog_Ranger";
	};
	class BP_Dog_Nomad: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "Nomad Dog";
		baseClass = "BP_Dog_Nomad";
	};
	class BP_Dog_Hunter: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "Hunter Dog";
		baseClass = "BP_Dog_Hunter";
	};
	class BP_Dog_Outlaw: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "Outlaw Dog";
		baseClass = "BP_Dog_Outlaw";
	};
	class BP_Dog_Survivalist: BP_Dog_Alsatian_Base
	{
		scope = 2;
		displayName = "Survivalist Dog";
		baseClass = "BP_Dog_Survivalist";
	};
	class BP_DefaultEventHandlers
	{
		side = 0;
		scope = 1;
		init = "";
		killed = "";
		handledamage = "";
		getin = "";
		getout = "";
		fired = "";
		take = "";
		put = "";
	};
	class BP_VehicleEventHandlers: BP_DefaultEventHandlers
	{
		scope = 1;
		init = "_this call BP_fnc_vehicleInit;";
		killed = "_this call BP_fnc_vehicleKilled;";
		handledamage = "_this call BP_fnc_damageHandlerVehicle;";
		getin = "_this call BP_fnc_vehicleInteract;";
		getout = "_this call BP_fnc_vehicleInteract;";
	};
	class BP_PlayerEventHandlers: BP_DefaultEventHandlers
	{
		scope = 1;
	};
	class BP_AnimalEventHandlers: BP_DefaultEventHandlers
	{
		scope = 1;
	};
	class BP_Rabbit: Animal_Base_F
	{
		author="$STR_A3_Bohemia_Interactive";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\Rabbit_F.jpg";
		_generalMacro="Rabbit_F";
		scope=2;
		displayName="$STR_A3_CfgVehicles_Rabbit_F0";
		model="\A3\Animals_F\rabbit\rabbit_F.p3d";
		side=3;
		moves="CfgMovesRabbit_F";
		fsmFormation="";
		fsmDanger="";
		maxTurnAngularVelocity=30;
		costTurnCoef=9.9999997e-006;
		canBleed=0;
		boneHead="head";
		bonePrimaryWeapon="head";
		weaponBone="head";
		triggerAnim="";
		class VariablesScalar
		{
			_threatMaxRadius=20;
			_runDistanceMax=50;
			_movePrefer=0.69999999;
			_formationPrefer=0.2;
			_scareLimit=0.2;
			_dangerLimit=1;
			_walkSpeed=0.89999998;
		};
		class VariablesString
		{
			_expSafe="(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger="(trees) * (forest) * (1 - meadow) * (1 - houses) * (1 - sea)";
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"A3\Animals_F\Rabbit\data\Rabbit.rvmat",
				"A3\Animals_F\Rabbit\data\W1_Rabbit.rvmat",
				"A3\Animals_F\Rabbit\data\W2_Rabbit.rvmat"
			};
		};
	};
	class BP_Chicken: Animal_Base_F
	{
		scope = 2;
		displayName = "Chicken";
		model = "\A3\animals_f_beta\chicken\Cock_F.p3d";
		moves = "CfgMovesCock_F";
		baseClass = "BP_Chicken";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Chicken\data\brown_rooster_CO.paa"};
		class EventHandlers: BP_AnimalEventHandlers{};
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar
		{
			_threatMaxRadius = 5;
			_runDistanceMax = 30;
			_movePrefer = 0.8;
			_formationPrefer = 0.5;
			_scareLimit = 0.2;
			_dangerLimit = 1;
		};
		class VariablesString
		{
			_expSafe = "(1 - trees) * (1 - forest) * (houses) * (1 - sea)";
			_expDanger = "(1 - trees) * (1 - forest) * (houses) * (1 - sea)";
		};
	};
	class BP_Chicken_1: BP_Chicken
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Chicken\data\brown_rooster_CO.paa"};
	};
	class BP_Chicken_2: BP_Chicken
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Chicken\data\white_rooster_CO.paa"};
	};
	class BP_Sheep: Animal_Base_F
	{
		scope = 2;
		displayName = "Sheep";
		model = "\A3\animals_f_beta\Sheep\Sheep_F.p3d";
		hasGeometry = 1;
		moves = "CfgMovesSheep_F";
		baseClass = "BP_Sheep";
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\animals_f_beta\sheep\data\sheep.rvmat","A3\animals_f_beta\sheep\data\W1_sheep.rvmat","A3\animals_f_beta\sheep\data\W2_sheep.rvmat"};
		};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Sheep\data\white_sheep_co.paa"};
		class EventHandlers: BP_AnimalEventHandlers{};
		class VariablesScalar
		{
			_threatMaxRadius = 10;
			_runDistanceMax = 25;
			_movePrefer = 0.7;
			_formationPrefer = 0.7;
			_scareLimit = 0.2;
			_dangerLimit = 12;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
			_expDanger = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
		};
	};
	class BP_Sheep_1: BP_Sheep
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Sheep\data\white_sheep_co.paa"};
	};
	class BP_Sheep_2: BP_Sheep
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Sheep\data\blackwhite_sheep_co.paa"};
	};
	class BP_Sheep_3: BP_Sheep
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Sheep\data\brown_sheep_co.paa"};
	};
	class BP_Sheep_4: BP_Sheep
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Sheep\data\tricolor_sheep_co.paa"};
	};
	class BP_Goat: Animal_Base_F
	{
		scope = 2;
		displayName = "Goat";
		model = "\A3\animals_f_beta\Goat\Goat_F.p3d";
		hasGeometry = 1;
		moves = "CfgMovesGoat_F";
		baseClass = "BP_Goat";
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\animals_f_beta\Goat\data\goat.rvmat","A3\animals_f_beta\Goat\data\W1_goat.rvmat","A3\animals_f_beta\Goat\data\W2_goat.rvmat"};
		};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Goat\data\white_goat_co.paa"};
		class EventHandlers: BP_AnimalEventHandlers{};
		class VariablesScalar
		{
			_threatMaxRadius = 10;
			_runDistanceMax = 25;
			_movePrefer = 0.7;
			_formationPrefer = 0.7;
			_scareLimit = 0.2;
			_dangerLimit = 12;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
			_expDanger = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
		};
	};
	class BP_Goat_1: BP_Goat
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Goat\data\white_goat_co.paa"};
	};
	class BP_Goat_2: BP_Goat
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Goat\data\black_goat_co.paa"};
	};
	class BP_Goat_3: BP_Goat
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\goat\data\dirt_goat_co.paa"};
	};
	class BP_Goat_4: BP_Goat
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Goat\data\old_goat_co.paa"};
	};
	class C_man_polo_1_F;
	class Underwear_F;
	class BP_Underwear: Underwear_F
	{
		uniformClass = "BP_BasicBody";
		class HitPoints
		{
			class HitFace
			{
				armor = 1;
				material = -1;
				name = "face_hub";
				passThrough = 0.1;
				radius = 0.08;
				explosionShielding = 0.1;
				minimalHit = 0.01;
			};
			class HitNeck: HitFace
			{
				armor = 1;
				material = -1;
				name = "neck";
				passThrough = 0.1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0.01;
			};
			class HitHead: HitNeck
			{
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 0.5;
				minimalHit = 0.01;
				depends = "HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor = 1;
				material = -1;
				name = "pelvis";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor = 1;
				material = -1;
				name = "spine1";
				passThrough = 0.1;
				radius = 0.025;
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor = 1;
				material = -1;
				name = "spine2";
				passThrough = 0.1;
				radius = 0.025;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor = 1;
				material = -1;
				name = "spine3";
				passThrough = 0.1;
				radius = 0.05;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "body";
				passThrough = 0.1;
				radius = 0.15;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms
			{
				armor = 1;
				material = -1;
				name = "arms";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0.01;
			};
			class HitHands: HitArms
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0.01;
				depends = "HitArms";
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 0.1;
				radius = 0.09;
				explosionShielding = 1;
				visual = "injury_legs";
				minimalHit = 0.01;
			};
		};
	};
	class C_man_polo_BP: C_man_polo_1_F
	{
		displayName = "Survivor";
		uniformClass = "BP_Poloshirt_blue";
		nakedUniform = "BP_BasicBody";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Guarilla_Faded: BP_Man
	{
		scope = 2;
		model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla3_1.p3d";
		side = 3;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		uniformClass = "BP_Guarilla_Faded";
		identityTypes[] = {};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Guarilla_Faded_Z: BP_Guarilla_Faded
	{
		scope = 2;
		uniformClass = "BP_Guarilla_Faded_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guarilla_Khaki: BP_Man
	{
		scope = 2;
		model = "\A3\Characters_F_Bootcamp\Guerrilla\ig_guerrilla_6_1.p3d";
		side = 3;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		uniformClass = "BP_Guarilla_Khaki";
		identityTypes[] = {};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Guarilla_Khaki_Z: BP_Guarilla_Khaki
	{
		scope = 2;
		uniformClass = "BP_Guarilla_Khaki_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guarilla_Leader: BP_Man
	{
		scope = 2;
		model = "\A3\characters_F_gamma\Guerrilla\ig_leader.p3d";
		side = 3;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		uniformClass = "BP_Guarilla_Leader";
		identityTypes[] = {};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Guarilla_Leader_Z: BP_Guarilla_Leader
	{
		scope = 2;
		uniformClass = "BP_Guarilla_Leader_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guarilla_Camo: BP_Man
	{
		scope = 2;
		model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla1_1.p3d";
		side = 3;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		uniformClass = "BP_Guarilla_Camo";
		identityTypes[] = {};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Guarilla_Camo_Z: BP_Guarilla_Camo
	{
		scope = 2;
		uniformClass = "BP_Guarilla_Camo_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Jungle_Ghillie: BP_Man
	{
		scope = 2;
		displayName = "Jungle Ghillie";
		model = "\A3\Characters_F_Mark\BLUFOR\b_fullghillie_f.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		magazines[] = {};
		uniformAccessories[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_JungleGhillie_Uniform";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"camo","camo3","camo4"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Mark\BLUFOR\Data\ghillie_coverall_nato_co.paa","\A3\Characters_F_Exp\BLUFOR\Data\ghillie_threads_tna_ca.paa","\A3\Characters_F_Exp\BLUFOR\Data\ghillie_threads_5LOD_tna_co.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Paramilitary_Jacket: BP_Man
	{
		scope = 2;
		displayName = "Paramilitary Garb (Jacket)";
		model = "\A3\Characters_F_Exp\Syndikat\I_C_Soldier_Para_2_F.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		magazines[] = {};
		uniformAccessories[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_Paramilitary_Jacket_Uniform";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"camo1","camo2","insignia"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_2_F_1_co.paa","\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_2_F_2_co.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Paramilitary_Shorts: BP_Man
	{
		scope = 2;
		displayName = "Paramilitary Garb (Shorts)";
		model = "\A3\Characters_F_Exp\Syndikat\I_C_Soldier_Para_5_F.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		magazines[] = {};
		uniformAccessories[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_Paramilitary_Shorts_Uniform";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"camo1","camo2","insignia"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_5_F_1_co.paa","\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_5_F_2_co.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Paramilitary_Tee: BP_Man
	{
		scope = 2;
		displayName = "Paramilitary Garb (Tee)";
		model = "\A3\Characters_F_Exp\Syndikat\I_C_Soldier_Para_1_F.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		magazines[] = {};
		uniformAccessories[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_Paramilitary_Tee_Uniform";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"camo1","camo2","insignia"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_1_F_1_co.paa","\A3\Characters_F_Exp\Syndikat\Data\U_I_C_Soldier_Para_1_F_2_co.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Ghillie_Lush: BP_Man
	{
		scope = 2;
		model = "\A3\Characters_F_Mark\BLUFOR\b_fullghillie_f.p3d";
		side = 3;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		uniformClass = "BP_Ghillie_Lush";
		identityTypes[] = {};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Ghillie_Lush_Z: BP_Ghillie_Lush
	{
		scope = 2;
		uniformClass = "BP_Ghillie_Lush_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_DirtGhillie: BP_Man
	{
		scope = 2;
		displayName = "Sniper Dirt";
		model = "A3\Characters_F\common\ghillie.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		magazines[] = {};
		uniformAccessories[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_DirtGhillie";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures\ghillie_4_ca.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_DirtGhillie_Z: BP_DirtGhillie
	{
		scope = 2;
		uniformClass = "BP_DirtGhillie_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_GrassGhillie: BP_Man
	{
		scope = 2;
		displayName = "Sniper Grass";
		model = "\breakingpoint_ghillie\models\ghillieGrass.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		uniformAccessories[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_GrassGhillie";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures2\ghillie_4_co.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_GrassGhillie_Z: BP_GrassGhillie
	{
		scope = 2;
		uniformClass = "BP_GrassGhillie_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_StoneGhillie: BP_Man
	{
		scope = 2;
		displayName = "Sniper Stone";
		model = "A3\Characters_F\common\ghillie.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		uniformAccessories[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_StoneGhillie";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures\ghillie_2_ca.paa","\breakingpoint_ghillie\textures\ghillie_2_ca.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_StoneGhillie_Z: BP_StoneGhillie
	{
		scope = 2;
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
		uniformClass = "BP_StoneGhillie_Z";
	};
	class BP_TreeGhillie: BP_Man
	{
		scope = 2;
		displayName = "Sniper Tree";
		model = "A3\Characters_F\common\ghillie.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		uniformAccessories[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_TreeGhillie";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures\ghillie_3_ca.paa","\breakingpoint_ghillie\textures\ghillie_3_ca.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_TreeGhillie_Z: BP_TreeGhillie
	{
		scope = 2;
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
		uniformClass = "BP_TreeGhillie_Z";
	};
	class BP_SnowGhillie: BP_Man
	{
		scope = 2;
		displayName = "Sniper Winter";
		model = "A3\Characters_F\common\ghillie.p3d";
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		uniformAccessories[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		uniformClass = "BP_SnowGhillie";
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		side = 3;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures\ghillie_5_ca.paa","\breakingpoint_ghillie\textures\ghillie_5_ca.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_SnowGhillie_Z: BP_SnowGhillie
	{
		scope = 2;
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
		uniformClass = "BP_SnowGhillie_Z";
	};
	class BP_Wetsuit1_F: BP_Man
	{
		_generalMacro="I_diver_F";
		scope = 2;
		displayName = "Independent Wetsuit 1";
		uniformClass = "BP_Wetsuit";
		model = "\A3\characters_F\Common\diver_slotable";
		side = 3;
		camouflage=2;
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		identityTypes[] = {};
		hiddenSelections[]={"Camo1","Camo2","insignia"};
		hiddenSelectionsTextures[]=
		{
			"\A3\Characters_F\Common\Data\diver_suit_rus_co.paa",
			"\A3\Characters_F\Common\Data\diver_equip_rus_co.paa"
		};
		hiddenUnderwaterSelections[]={"hide"};
		shownUnderwaterSelections[]={"unhide","unhide2"};
		hiddenUnderwaterSelectionsTextures[]={"\A3\characters_f\common\data\diver_equip_nato_co.paa","\A3\characters_f\common\data\diver_equip_nato_co.paa",
		"\A3\characters_f\data\visors_ca.paa"};
		class EventHandlers: BP_PlayerEventHandlers{};
	};
	class BP_Wetsuit_Z: BP_Wetsuit1_F
	{
		scope = 2;
		uniformClass = "BP_Wetsuit_Z";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_RefugeeF_F: BP_Man
	{
		scope = 2;
		displayName = "Refugee 1";
		uniformClass = "BP_Refugee_F";
		model = "\breakingpoint_classes\models\BP_RefugeeF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_RefugeeF_Z: BP_RefugeeF_F
	{
		scope = 2;
		displayName = "Refugee 1";
		uniformClass = "BP_Refugee_F_Z";
		model = "\breakingpoint_classes\models\BP_RefugeeF.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Refugee1_F: BP_Man
	{
		scope = 2;
		displayName = "Refugee 1";
		uniformClass = "BP_Refugee_1";
		model = "\breakingpoint_classes\models\BP_Refugee1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Refugee1_Z: BP_Refugee1_F
	{
		scope = 2;
		displayName = "Refugee 1";
		uniformClass = "BP_Refugee_1_Z";
		model = "\breakingpoint_classes\models\BP_Refugee1.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Refugee2_F: BP_Man
	{
		scope = 2;
		displayName = "Refugee 2";
		uniformClass = "BP_Refugee_2";
		model = "\breakingpoint_classes\models\BP_Refugee2.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Refugee2_Z: BP_Refugee2_F
	{
		scope = 2;
		displayName = "Refugee 2";
		uniformClass = "BP_Refugee_2_Z";
		model = "\breakingpoint_classes\models\BP_Refugee2.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Refugee3_F: BP_Man
	{
		scope = 2;
		displayName = "Refugee 3";
		uniformClass = "BP_Refugee_3";
		model = "\breakingpoint_classes\models\BP_Refugee3.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Refugee3_Z: BP_Refugee3_F
	{
		scope = 2;
		displayName = "Refugee 3";
		uniformClass = "BP_Refugee_3_Z";
		model = "\breakingpoint_classes\models\BP_Refugee3.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_GuardianF_F: BP_Man
	{
		scope = 2;
		displayName = "Guardian 1";
		uniformClass = "BP_Guardian_F";
		model = "\breakingpoint_classes\models\BP_GuardianF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_GuardianF_Z: BP_GuardianF_F
	{
		scope = 2;
		displayName = "Guardian 1";
		uniformClass = "BP_Guardian_F_Z";
		model = "\breakingpoint_classes\models\BP_GuardianF.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guardian1_F: BP_Man
	{
		scope = 2;
		displayName = "Guardian 1";
		uniformClass = "BP_Guardian_1";
		model = "\breakingpoint_classes\models\BP_Guardian1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Guardian1_Z: BP_Guardian1_F
	{
		scope = 2;
		displayName = "Guardian 1";
		uniformClass = "BP_Guardian_1_Z";
		model = "\breakingpoint_classes\models\BP_Guardian1.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guardian2_F: BP_Man
	{
		scope = 2;
		displayName = "Guardian 2";
		uniformClass = "BP_Guardian_2";
		model = "\breakingpoint_classes\models\BP_Guardian4.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Guardian2_Z: BP_Guardian2_F
	{
		scope = 2;
		displayName = "Guardian 2";
		uniformClass = "BP_Guardian_2_Z";
		model = "\breakingpoint_classes\models\BP_Guardian4.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Guardian3_F: BP_Man
	{
		scope = 2;
		displayName = "Guardian 3";
		uniformClass = "BP_Guardian_3";
		model = "\breakingpoint_classes\models\BP_Guardian3.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Guardian3_Z: BP_Guardian3_F
	{
		scope = 2;
		displayName = "Guardian 3";
		uniformClass = "BP_Guardian_3_Z";
		model = "\breakingpoint_classes\models\BP_Guardian3.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_RebelF_F: BP_Man
	{
		scope = 2;
		displayName = "Fallen Rebel";
		uniformClass = "BP_Rebel_1";
		model = "\breakingpoint_classes\models\BP_Rebel0.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_RebelF_Z: BP_RebelF_F
	{
		scope = 2;
		displayName = "Fallen Rebel";
		uniformClass = "BP_Rebel_F_Z";
		model = "\breakingpoint_classes\models\BP_Rebel0.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Rebel1_F: BP_Man
	{
		scope = 2;
		displayName = "Rebel 1";
		uniformClass = "BP_Rebel_1";
		model = "\breakingpoint_classes\models\BP_Rebel1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Rebel1_Z: BP_Rebel1_F
	{
		scope = 2;
		displayName = "Rebel 1";
		uniformClass = "BP_Rebel_1_Z";
		model = "\breakingpoint_classes\models\BP_Rebel1.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Rebel2_F: BP_Man
	{
		scope = 2;
		displayName = "Rebel 2";
		uniformClass = "BP_Rebel_2";
		model = "\breakingpoint_classes\models\BP_Rebel2.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Rebel2_Z: BP_Rebel2_F
	{
		scope = 2;
		displayName = "Rebel 2";
		uniformClass = "BP_Rebel_2_Z";
		model = "\breakingpoint_classes\models\BP_Rebel2.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Rebel3_F: BP_Man
	{
		scope = 2;
		displayName = "Rebel 3";
		uniformClass = "BP_Rebel_3";
		model = "\breakingpoint_classes\models\BP_Rebel3.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Rebel3_Z: BP_Rebel3_F
	{
		scope = 2;
		displayName = "Rebel 3";
		uniformClass = "BP_Rebel_3_Z";
		model = "\breakingpoint_classes\models\BP_Rebel3.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Hunter1_F: BP_Man
	{
		scope = 2;
		displayName = "Hunter 1";
		uniformClass = "BP_Hunter_1";
		model = "\breakingpoint_classes\models\BP_Hunter1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Hunter1_Z: BP_Hunter1_F
	{
		scope = 2;
		displayName = "Hunter 1";
		uniformClass = "BP_Hunter_1_Z";
		model = "\breakingpoint_classes\models\BP_Hunter1.p3d";
		extCameraPosition[] = {0.22,0.02,-1.2};
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Hunter2_F: BP_Man
	{
		scope = 2;
		displayName = "Hunter 2";
		uniformClass = "BP_Hunter_2";
		model = "\breakingpoint_classes\models\BP_Hunter2.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Hunter2_Z: BP_Hunter2_F
	{
		scope = 2;
		displayName = "Hunter 2";
		uniformClass = "BP_Hunter_2_Z";
		model = "\breakingpoint_classes\models\BP_Hunter2.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Hunter3_F: BP_Man
	{
		scope = 2;
		displayName = "Hunter 3";
		uniformClass = "BP_Hunter_3";
		model = "\breakingpoint_classes\models\BP_Hunter3.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Hunter3_Z: BP_Hunter3_F
	{
		scope = 2;
		displayName = "Hunter 3";
		uniformClass = "BP_Hunter_3_Z";
		model = "\breakingpoint_classes\models\BP_Hunter3.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Survivalist1_F: BP_Man
	{
		scope = 2;
		displayName = "Survivalist 1";
		uniformClass = "BP_Survivalist_1";
		model = "\breakingpoint_classes\models\BP_Survivalist1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Survivalist1_Z: BP_Survivalist1_F
	{
		scope = 2;
		displayName = "Survivalist 1";
		uniformClass = "BP_Survivalist_1_Z";
		model = "\breakingpoint_classes\models\BP_Survivalist1.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Survivalist2_F: BP_Man
	{
		scope = 2;
		displayName = "Survivalist 2";
		uniformClass = "BP_Survivalist_2";
		model = "\breakingpoint_classes\models\BP_Survivalist2.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_classes\textures\ghillie_top_desert_co.paa"};
	};
	class BP_Survivalist2_Z: BP_Survivalist2_F
	{
		scope = 2;
		displayName = "Survivalist 2";
		uniformClass = "BP_Survivalist_2_Z";
		model = "\breakingpoint_classes\models\BP_Survivalist2.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Survivalist3_F: BP_Man
	{
		scope = 2;
		displayName = "Survivalist 3";
		uniformClass = "BP_Survivalist_3";
		model = "\breakingpoint_ghillie\models\ghilliegrass.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ghillie\textures2\ghillie_5_co.paa"};
	};
	class BP_Survivalist3_Z: BP_Survivalist3_F
	{
		scope = 2;
		displayName = "Survivalist 3";
		uniformClass = "BP_Survivalist_3_Z";
		model = "\breakingpoint_ghillie\models\ghilliegrass.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_SurvivalistF_F: BP_Man
	{
		scope = 2;
		displayName = "Fallen Survivalist";
		uniformClass = "BP_Survivalist_F";
		model = "\breakingpoint_classes\models\BP_SurvivalistF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_SurvivalistF_Z: BP_SurvivalistF_F
	{
		scope = 2;
		displayName = "Fallen Survivalist";
		uniformClass = "BP_Survivalist_F_Z";
		model = "\breakingpoint_classes\models\BP_SurvivalistF.p3d";
		moves = "CfgMovesZombieSdr";
	};
	class BP_Engineer1_F: BP_Man
	{
		scope = 2;
		displayName = "Engineer 1";
		uniformClass = "BP_Engineer_1";
		model = "\a3\characters_f\common\coveralls.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
	};
	class BP_Engineer1_Z: BP_Engineer1_F
	{
		scope = 2;
		displayName = "Engineer 1";
		uniformClass = "BP_Engineer_1_Z";
		model = "\a3\characters_f\common\coveralls.p3d";
		moves = "CfgMovesZombieSdr";
	};
	class BP_Engineer2_F: BP_Man
	{
		scope = 2;
		displayName = "Engineer 2";
		uniformClass = "BP_Engineer_2";
		model = "\a3\characters_f\common\coveralls.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
	};
	class BP_Engineer2_Z: BP_Engineer2_F
	{
		scope = 2;
		displayName = "Engineer 2";
		uniformClass = "BP_Engineer_2_Z";
		model = "\a3\characters_f\common\coveralls.p3d";
		moves = "CfgMovesZombieSdr";
	};
	class BP_Engineer3_F: BP_Man
	{
		scope = 2;
		displayName = "Engineer 3";
		uniformClass = "BP_Engineer_3";
		model = "\a3\characters_f\common\coveralls.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
	};
	class BP_Engineer3_Z: BP_Engineer3_F
	{
		scope = 2;
		displayName = "Engineer 3";
		uniformClass = "BP_Engineer_3_Z";
		model = "\a3\characters_f\common\coveralls.p3d";
		moves = "CfgMovesZombieSdr";
	};
	class BP_UndeadF_F: BP_Man
	{
		scope = 2;
		displayName = "Watcher Level 1";
		uniformClass = "BP_Undead_1";
		model = "\breakingpoint_classes\models\BP_GuardianF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Undead1_F: BP_Man
	{
		scope = 2;
		displayName = "Watcher Level 1";
		uniformClass = "BP_Undead_1";
		model = "\breakingpoint_classes\models\BP_RefugeeF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Undead2_F: BP_Man
	{
		scope = 2;
		displayName = "Watcher Level 2";
		uniformClass = "BP_Undead_2";
		model = "\breakingpoint_classes\models\BP_Rebel0.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};
	class BP_Undead3_F: BP_Man
	{
		scope = 2;
		displayName = "Watcher Level 3";
		uniformClass = "BP_Undead_3";
		model = "\breakingpoint_classes\models\BP_GuardianF.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
	};	
	class BP_Optout_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut";
		model = "\breakingpoint_classes\models\BP_OptOut.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
	};
	class BP_Optout_Z: BP_Optout_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOutF_Z";
		model = "\breakingpoint_classes\models\BP_OptOut.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Optout2_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut2";
		model = "\A3\characters_F\civil\c_poor.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_classes\textures\c_cloth1_black.paa"};
	};
	class BP_Optout2_Z: BP_Optout2_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut2_Z";
		model = "\A3\characters_F\civil\c_poor.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Optout3_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut3";
		model = "\A3\Characters_F_EPB\Guerrilla\ig_guerrilla4_1.p3d";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
	};
	class BP_Optout3_Z: BP_Optout3_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut3_Z";
		model = "\A3\Characters_F_EPB\Guerrilla\ig_guerrilla4_1.p3d";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Optout4_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_OptOut4";
		model = "\a3\Characters_F\Civil\ArtTShirt_01_F";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[] = {"Camo1","insignia"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ui\updatedimage\optout4.paa"};
	};
	class BP_Scientist_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Scientist_Z";
		model="\A3\characters_F\common\coveralls";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[]={"camo"};
		hiddenSelectionsTextures[]={"\A3\Characters_F\Common\Data\coveralls_scientist_co.paa"};
	};	
	class BP_Scientist_Z: BP_Scientist_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Scientist_Z";
		model="\A3\characters_F\common\coveralls";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Worker_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Worker_Z";
		model="\A3\characters_F\common\coveralls";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[]={"camo"};
		hiddenSelectionsTextures[]={"\A3\Characters_F\Common\Data\coveralls_dirty_co.paa"};
	};	
	class BP_Worker_Z: BP_Worker_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Worker_Z";
		model="\A3\characters_F\common\coveralls";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Medic_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Medic_Z";
		model="\a3\Characters_F_Orange\Uniforms\C_Paramedic_01_F";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[]={"camo"};
		hiddenSelectionsTextures[]={"\a3\Characters_F_Orange\Uniforms\Data\c_paramedic_01_co.paa"};
	};	
	class BP_Medic_Z: BP_Medic_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Medic_Z";
		model="\a3\Characters_F_Orange\Uniforms\C_Paramedic_01_F";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Mechanic_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Mechanic_Z";
		model="a3\Characters_F_Orange\Uniforms\C_Mechanic_01_F";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[]={"camo"};
		hiddenSelectionsTextures[]={"\a3\Characters_F_Orange\Uniforms\Data\c_mechanic_01_camo1_co.paa"};
	};	
	class BP_Mechanic_Z: BP_Mechanic_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Mechanic_Z";
		model="a3\Characters_F_Orange\Uniforms\C_Mechanic_01_F";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class BP_Construction_F: BP_Man
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Construction_Z";
		model="\a3\Characters_F\Civil\c_driver_f";
		side = 3;
		backpack = "";
		weapons[] = {"Throw","Put"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put"};
		respawnMagazines[] = {};
		Items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnlinkedItems[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {""};
				speechPlural[] = {""};
			};
		};
		textSingular = "";
		textPlural = "";
		nameSound = "";
		hiddenSelections[]={"camo"};
		hiddenSelectionsTextures[]={"\a3\Characters_F_Orange\Uniforms\Data\c_constructioncoverall_black_co"};
	};	
	class BP_Construction_Z: BP_Construction_F
	{
		scope = 2;
		displayName = "Civilian";
		uniformClass = "BP_Construction_Z";
		model="\a3\Characters_F\Civil\c_driver_f";
		moves = "CfgMovesZombieSdr";
		canHideBodies = 0;
	};
	class B_Heli_Light_01_F;
	class B_Heli_Transport_01_F;
	class O_Heli_Light_02_unarmed_F;
	class I_Heli_Transport_02_F;
	class B_MRAP_01_F;
	class B_MRAP_01_gmg_F;
	class B_MRAP_01_hmg_F;
	class C_Offroad_01_F;
	class C_Quadbike_01_F;
	class C_SUV_01_F;
	class C_Hatchback_01_F;
	class C_Hatchback_01_sport_F;
	class C_Van_01_box_F;
	class I_G_Van_01_fuel_F;
	class I_G_Van_01_transport_F;
	class B_Boat_Transport_01_F;
	class C_Boat_Civil_01_police_F;
	class I_MRAP_03_F;
	class O_Truck_02_covered_F;
	class O_Truck_02_transport_F;
	class B_G_Offroad_01_armed_F;
	class C_Scooter_Transport_01_F;
	class C_Boat_Transport_02_F;
	class C_Plane_Civil_01_F;
	class O_T_LSV_02_armed_F;
	class O_T_LSV_02_unarmed_F;
	class B_T_LSV_01_armed_F;
	class B_T_LSV_01_unarmed_F;
	class C_Offroad_02_unarmed_F;
	class C_Van_01_transport_F;
	class C_Tractor_01_F;
	class C_Kart_01_black_F;
	class BP_C_Scooter_Transport_01_F: C_Scooter_Transport_01_F
	{
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\C_Scooter_Transport_01_F.jpg";
		displayName = "Rusty Scooter";
		_generalMacro = "Rusty Scooter";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_CO.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_CO.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = 50;
				name = "hull";
				visual = "zbytek";
				passThrough = 0.1;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "Engine";
				visual = "";
				passThrough = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_C_Boat_Transport_02_F: C_Boat_Transport_02_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\C_Boat_Transport_02_F.jpg";
		_generalMacro = "Rusty RHIB";
		displayName = "Rusty RHIB";
		maximumLoad = 500;
		transportMaxBackpacks = 5;
		transportMaxMagazines = 100;
		transportMaxWeapons = 10;
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_exterior_civilian_CO.paa","\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_interior_2_civilian_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_exterior_civilian_CO.paa","\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_interior_2_civilian_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = 50;
				name = "hull";
				visual = "zbytek";
				passThrough = 0.1;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "Engine";
				visual = "";
				passThrough = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_C_Plane_Civil_01_F: C_Plane_Civil_01_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\C_Plane_Civil_01_F.jpg";
		_generalMacro = "Rusted Caesar BTT";
		scope = 2;
		scopeCurator = 2;
		displayName = "Rusty Caesar BTT";
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {""};
		accuracy = 1000;
		textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
		hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.25;
			};
			class HitEngine
			{
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics
			{
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.1;
			};
			class HitGlass1
			{
				armor = 1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_O_T_LSV_02_armed_F: O_T_LSV_02_armed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_LSV_02_armed_F.jpg";
		_generalMacro = "Rusted Qilin (Armed)";
		displayName = "Rusted Qilin (Armed)";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_O_T_LSV_02_unarmed_F: O_T_LSV_02_unarmed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_LSV_02_unarmed_F.jpg";
		_generalMacro = "Rusted Qilin";
		displayName = "Rusted Qilin";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_B_T_LSV_01_armed_F: B_T_LSV_01_armed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_LSV_01_armed_F.jpg";
		_generalMacro = "Rusted Prowler (Armed)";
		displayName = "Rusted Prowler (Armed)";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_B_T_LSV_01_unarmed_F: B_T_LSV_01_unarmed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_LSV_01_unarmed_F.jpg";
		_generalMacro = "Rusted Prowler";
		displayName = "Rusted Prowler";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_C_Offroad_02_unarmed_F: C_Offroad_02_unarmed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\C_Offroad_02_unarmed_F.jpg";
		_generalMacro = "Jeep Wrangler 4x4";
		displayName = "Jeep Wranger 4x4";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		faction = "CIV_F";
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa"};
		materials[] = {"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_metal.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_ext_chrome.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_int_metal.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_int_chrome.rvmat"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa"};
		hiddenSelectionsMaterials[] = {"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_metal.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_ext_chrome.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_int_metal.rvmat","\a3\soft_f_exp\offroad_02\data\offroad_02_int_chrome.rvmat"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		maxSpeed=200;
		clutchStrength=20;
		engineMOI=0.79999998;
		enginePower=350;
		minOmega=50;
		maxOmega=733;
		peakTorque=900;
		idleRpm=400;
		redRpm=5500;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_C_Offroad_03_unarmed_F: C_Offroad_02_unarmed_F
	{
		author = "Bohemia Interactive";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\C_Offroad_02_unarmed_F.jpg";
		_generalMacro = "Jeep Wrangler 4x4";
		displayName = "Jeep Wranger 4x4";
		scope = 2;
		scopeCurator = 2;
		DLC = "Expansion";
		side = 3;
		faction = "CIV_F";
		crew = "";
		typicalCargo[] = {};
		textures[] = {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa"};
		materials[] = {"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_metal.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_chrome.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_int_metal.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_int_chrome.rvmat"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa",
			"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa"};
		hiddenSelectionsMaterials[] = {"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_metal.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_ext_chrome.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_int_metal.rvmat",
			"\a3\soft_f_exp\offroad_02\data\offroad_02_int_chrome.rvmat"};
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		maxSpeed=200;
		clutchStrength=20;
		engineMOI=0.79999998;
		enginePower=350;
		minOmega=50;
		maxOmega=733;
		peakTorque=900;
		idleRpm=400;
		redRpm=5500;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_MRAP_01: B_MRAP_01_F
	{
		scope = 2;
		side = 3;
		displayName = "Rusty Vannad (Armoured)";
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\MRAP_01_base_CO.paa","\breakingpoint_vehicles\textures\MRAP_01_adds_CO.paa","\breakingpoint_vehicles\textures\MRAP_01_int_CO.paa","\breakingpoint_vehicles\textures\MRAP_01_int_det_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\mrap_01_base.rvmat","\breakingpoint_vehicles\textures\mrap_01_adds.rvmat","\breakingpoint_vehicles\textures\mrap_01_det_int.rvmat","\breakingpoint_vehicles\textures\mrap_01_int_destruct.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 2000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		armor = 50;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0.8;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0.8;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0.8;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0.8;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 0.8;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitGlass6
			{
				armor = 0.8;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.1;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 1;
			};
			class HitLFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Heli_Light_01: B_Heli_Light_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty OH-6A Cayuse";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\Heli_Light_01_ext_ion_CO.paa","\breakingpoint_vehicles\textures\Heli_Light_01_detail_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\heli_light_01_ext.rvmat","\breakingpoint_vehicles\textures\heli_light_01_detail.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 3;
		transportMaxBackpacks = 3;
		supplyRadius = 1.2;
		laserScanner = 0;
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.25;
			};
			class HitEngine
			{
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics
			{
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.1;
			};
			class HitVRotor
			{
				armor = 0.25;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.25;
			};
			class HitHRotor
			{
				armor = 0.25;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.25;
			};
			class HitGlass1
			{
				armor = 1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Heli_Transport_01: B_Heli_Transport_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty UH-60 StealthHawk";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\Heli_transport_01_ext01_co.paa","\breakingpoint_vehicles\textures\Heli_transport_01_ext02_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\Heli_transport_01_ext01.rvmat","\breakingpoint_vehicles\textures\Heli_transport_01_ext02.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 2500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		supplyRadius = 1.2;
		laserScanner = 0;
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.25;
			};
			class HitEngine
			{
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics
			{
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.1;
			};
			class HitVRotor
			{
				armor = 0.25;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.25;
			};
			class HitHRotor
			{
				armor = 0.25;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.25;
			};
			class HitGlass1
			{
				armor = 1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 1;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitGlass6
			{
				armor = 1;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Heli_Light_02_unarmed: O_Heli_Light_02_unarmed_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty KA-64 SkyHorse";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\Heli_Light_02_ext_CO.paa","\breakingpoint_vehicles\textures\heli_light_02_common_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\heli_light_02_ext.rvmat","\breakingpoint_vehicles\textures\heli_light_02_common_base.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 2500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		supplyRadius = 1.2;
		laserScanner = 0;
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.2;
			};
			class HitEngine
			{
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics
			{
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.1;
			};
			class HitVRotor
			{
				armor = 0.25;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.25;
			};
			class HitHRotor
			{
				armor = 0.25;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.25;
			};
			class HitGlass1
			{
				armor = 1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 1;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitGlass6
			{
				armor = 1;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Heli_Transport_02: I_Heli_Transport_02_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty HC3 Merlin";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2","camo3"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\heli_transport_02_1_Indep_co.paa","\breakingpoint_vehicles\textures\heli_transport_02_2_Indep_co.paa","\breakingpoint_vehicles\textures\heli_transport_02_3_Indep_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\heli_transport_02_1.rvmat","\breakingpoint_vehicles\textures\heli_transport_02_2.rvmat","\breakingpoint_vehicles\textures\heli_transport_02_3.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 3000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		supplyRadius = 1.2;
		laserScanner = 0;
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.25;
			};
			class HitEngine
			{
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics
			{
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.1;
			};
			class HitVRotor
			{
				armor = 0.25;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.25;
			};
			class HitHRotor
			{
				armor = 0.25;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.25;
			};
			class HitGlass1
			{
				armor = 1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 1;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitGlass6
			{
				armor = 1;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Offroad_01_armed_F: C_Offroad_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Pickup";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo","camo2","camo3"};
		hiddenSelectionsTextures[] = {"\breakingpoint_ui\updatedimage\Offroad_01_ext_base03_CO.paa","\breakingpoint_ui\updatedimage\Offroad_01_ext_base03_CO.paa","\breakingpoint_vehicles\textures\Offroad_01_proxy_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\offroad_01_ext.rvmat","\breakingpoint_vehicles\textures\offroad_01_ext.rvmat","\breakingpoint_vehicles\textures\offroad_01_proxy.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Offroad_02_armed_F: C_Offroad_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Pickup";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo","camo2","camo3"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\Offroad_02_ext_base04_CO.paa","\breakingpoint_vehicles\textures\Offroad_02_ext_base04_CO.paa","\breakingpoint_vehicles\textures\Offroad_01_proxy_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\offroad_02_ext.rvmat","\breakingpoint_vehicles\textures\offroad_02_ext.rvmat","\breakingpoint_vehicles\textures\offroad_01_proxy.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Offroad_03_armed_F: B_G_Offroad_01_armed_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Pickup (.50cal)";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo","camo2","camo3"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\Offroad_01_ext_base05_CO.paa","\breakingpoint_vehicles\textures\Offroad_01_ext_base05_CO.paa","\breakingpoint_vehicles\textures\Offroad_01_proxy_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\offroad_02_ext.rvmat","\breakingpoint_vehicles\textures\offroad_02_ext.rvmat","\breakingpoint_vehicles\textures\offroad_01_proxy.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Quadbike_01: C_Quadbike_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty ATV";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\quadbike_01_civ_black_co.paa","\breakingpoint_vehicles\textures\quadbike_01_wheel_indep_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\quadbike_01_base.rvmat","\breakingpoint_vehicles\textures\quadbike_01_wheel.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 250;
		transportMaxMagazines = 15;
		transportMaxWeapons = 2;
		transportMaxBackpacks = 1;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Quadbike_02_F: C_Quadbike_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty ATV";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\quadbike_01_co.paa","\breakingpoint_vehicles\textures\quadbike_01_wheel_indep_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\quadbike_01_base.rvmat","\breakingpoint_vehicles\textures\quadbike_01_wheel.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 250;
		transportMaxMagazines = 10;
		transportMaxWeapons = 2;
		transportMaxBackpacks = 1;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_SUV_01_F: C_SUV_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Luxury Crossover";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\suv_01_ext_04_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\suv_01_ext.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 35;
		transportMaxWeapons = 7;
		transportMaxBackpacks = 5;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 0;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_SUV_02_F: C_SUV_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Luxury Crossover";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\suv_01_ext_02_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\suv_02_ext.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 7;
		transportMaxBackpacks = 5;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 0;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Hatchback_01_F: C_Hatchback_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Car";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\hatchback_01_ext_base02_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\hatchback_01_paint.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 25;
		transportMaxWeapons = 4;
		transportMaxBackpacks = 3;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Hatchback_02_F: C_Hatchback_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Car";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\hatchback_01_ext_base01_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\hatchback_02_paint.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 25;
		transportMaxWeapons = 3;
		transportMaxBackpacks = 3;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Hatchback_01_sport_F: C_Hatchback_01_sport_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Car (Turbo)";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\hatchback_01_ext_sport01_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\hatchback_03_paint.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 20;
		transportMaxWeapons = 2;
		transportMaxBackpacks = 2;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Hatchback_02_sport_F: C_Hatchback_01_sport_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Car (Turbo)";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\hatchback_01_ext_sport06_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\hatchback_04_paint.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1000;
		transportMaxMagazines = 20;
		transportMaxWeapons = 2;
		transportMaxBackpacks = 2;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Van_01_Fuel_F: I_G_Van_01_fuel_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty FuelTruck";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\van_01_ext_CO.paa","\breakingpoint_vehicles\textures\van_01_tank_CO.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\van_01_ext.rvmat","\breakingpoint_vehicles\textures\van_01_tank.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 5;
		transportMaxBackpacks = 10;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 0.5;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitFuel2
			{
				armor = 0;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Truck_02_transport_F: O_Truck_02_transport_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Kamas (Open)";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\truck_02_kab_opfor_co.paa","\breakingpoint_vehicles\textures\truck_02_kuz_opfor_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\truck_02_kab.rvmat","\breakingpoint_vehicles\textures\truck_02_kuz.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 3000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 10;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftMiddleWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightMiddleWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "Engine";
				passThrough = 0.2;
			};
			class HitLMWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_1_3_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRMWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_2_3_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Truck_02_covered_F: O_Truck_02_covered_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Kamas (Enclosed)";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\truck_02_kab_opfor_co.paa","\breakingpoint_vehicles\textures\truck_02_kuz_opfor_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\truck_02_kab.rvmat","\breakingpoint_vehicles\textures\truck_02_kuz.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 3000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 10;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftMiddleWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.7;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightMiddleWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "Engine";
				passThrough = 0.2;
			};
			class HitLMWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_3_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRMWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_3_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_MRAP_03_F: I_MRAP_03_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty Fennek";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\mrap_03_ext_co.paa","\breakingpoint_vehicles\textures\turret_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\mrap_03_ext.rvmat","\breakingpoint_vehicles\textures\turret.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 2000;
		transportMaxMagazines = 50;
		transportMaxWeapons = 7;
		transportMaxBackpacks = 10;
		armor = 50;
		class RenderTargets
		{
			class commander_display
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderVisionMode = 0;
					renderQuality = 2;
					fov = 0.5;
				};
			};
			class driver_display
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderVisionMode = 0;
					renderQuality = 2;
					fov = 0.6;
				};
			};
			class mirrorL
			{
				renderTarget = "rendertarget4";
				class CameraView1
				{
					pointPosition = "PIP4_pos";
					pointDirection = "PIP4_dir";
					renderVisionMode = 4;
					renderQuality = 2;
					fov = 0.35;
				};
			};
			class mirrorR
			{
				renderTarget = "rendertarget5";
				class CameraView1
				{
					pointPosition = "PIP5_pos";
					pointDirection = "PIP5_dir";
					renderVisionMode = 4;
					renderQuality = 2;
					fov = 0.35;
				};
			};
		};
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0.8;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0.8;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0.8;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0.8;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitGlass5
			{
				armor = 0.8;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.1;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Boat_Civil_01_police_F: C_Boat_Civil_01_police_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty SpeedBoat";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\boat_civil_01_ext_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\boat_civil_01_ext.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 250;
		transportMaxMagazines = 10;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		class HitPoints
		{
			class HitEngine
			{
				armor = 1;
				material = 60;
				name = "engine";
				visual = "";
				passThrough = 1;
				radius = 0.1;
			};
			class HitHull
			{
				armor = 1;
				material = 50;
				name = "karoserie";
				visual = "zbytek";
				passThrough = 0.1;
				explosionShielding = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Boat_Transport_01_F: B_Boat_Transport_01_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Rusty PBX";
		typicalCargo[] = {};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\breakingpoint_vehicles\textures\boat_transport_01_co.paa"};
		hiddenSelectionsMaterials[] = {"\breakingpoint_vehicles\textures\boat_transport_01.rvmat"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 250;
		transportMaxMagazines = 10;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = 50;
				name = "hull";
				visual = "zbytek";
				passThrough = 0.1;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "Engine";
				visual = "";
				passThrough = 1;
			};
		};
		
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Van_01_box_F: C_Van_01_box_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Box Truck";
		typicalCargo[] = {};
		hiddenSelections[] = {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[] = {"\A3\soft_f_gamma\van_01\Data\Van_01_ext_black_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 2500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 10;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 0.5;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitFuel2
			{
				armor = 0;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Van_01_transport: C_Van_01_transport_F
	{
		scope = 2;
		side = 3;
		crew = "";
		displayName = "Mini Transport Truck";
		typicalCargo[] = {};
		hiddenSelections[] = {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]=
		{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_04_CO.paa","\a3\soft_f_gamma\van_01\data\van_01_int_base_co.paa"
		};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportItems{};
		commanderCanSee = "2 + 4 + 8";
		gunnerCanSee = "2 + 4 + 8";
		driverCanSee = "2 + 4 + 8";
		maximumLoad = 1500;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 10;
		class HitPoints
		{
			class HitGlass1
			{
				armor = 0;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 0.5;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.2;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitFuel2
			{
				armor = 0;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 0.5;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Tractor_01_F: C_Tractor_01_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Tractor";
		displayName = "Tractor";		
		scope = 2;
		scopeCurator = 2;
		DLC = "Enoch";
		side = 3;
		crew = "";
		typicalCargo[] = {};
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\C_Tractor_01_F.jpg";
		class TextureSources{};
		class TransportItems{};
		class TransportMagazines{};
		class TransportWeapons{};
		armor = 50;
		class HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.8;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
		};	
		class EventHandlers: BP_VehicleEventHandlers{};
	};
	class BP_Kart: C_Kart_01_black_F
	{
		scope = 2;
		author = "$STR_A3_Bohemia_Interactive";
		displayName = "Old Racing Kart";
		side = 3;
		faction = "CIV_F";
		crew = "";
		typicalCargo[] = {};
		DLC = "Kart";
		hiddenSelections[] = {"camo","camo2"};
		hiddenSelectionsTextures[] = {"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_black_CO.paa","\breakingpoint_ui\updatedimage\Kart_01_logos_black_CA.paa"};
		maximumLoad = 200;
		armor = 50;
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "Hull";
				passThrough = 0.1;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "FuelHose";
				passThrough = 1;
			};
			class HitLFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "LeftFrontWheel";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "LeftBackWheel";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "RightFrontWheel";
				passThrough = 0;
			};
			class HitRF2Wheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "RightBackWheel";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 1;
			};
		};
		class EventHandlers: BP_VehicleEventHandlers{};
	};
};