/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

BP_AllPlayers = ["C_man_polo_BP","C_man_zed_BP","C_man_zed2_BP","C_man_zed3_BP","C_man_zed4_BP","BP_officer_F","BP_officer_I","BP_soldier_F","BP_Sniper_soldier","BP_Sniper_soldier1","BP_Sniper_soldier2","BP_Sniper_soldier3","BP_Soldier_A_F","BP_Soldier_M_F","BP_Soldier_I_F","BP_Bandit_U_F","BP_Bandit_W_F","BP_Bandit_I_F"];
BP_AllPlayersVehicles =  BP_AllPlayers + ["AllVehicles"];

BP_ZombieClasses = ["zZombie_Base","z_villager1","z_villager2","z_villager3","z_villager4","z_villager5","z_villager6","z_suit1","z_suit2","BPZombie_Rebel1","BPZombie_Rebel2","BPZombie_Rebel3","BPZombie_Guardian1","BPZombie_Guardian2","BPZombie_Guardian3","BPZombie_Survivalist1","BPZombie_Survivalist2","BPZombie_Survivalist3","BPZombie_Refugee1","BPZombie_Refugee2","BPZombie_Refugee3","BPZombie_Hunter1","BPZombie_Hunter2","BPZombie_Hunter3"];
BP_LootClasses = [];
BP_StorageClasses = [];

bis_disabled_Door_1 = nil;

BP_SprayCans =
[
	"BP_SprayCan_WDL",
	"BP_SprayCan_DES",
	"BP_SprayCan_URB"
];

BP_TrapBuildables =
[
	"BP_TripMine_Mag",
	"BP_ATMine_Mag",
	"BP_BearTrap_Mag"
];

BP_NormalClothing =
[
	"BP_Refugee_F",
	"BP_Refugee_1",
	"BP_Refugee_2",
	"BP_Refugee_3",
	"BP_Guardian_F",
	"BP_Guardian_1",
	"BP_Guardian_2",
	"BP_Guardian_3",
	"BP_Rebel_F",
	"BP_Rebel_1",
	"BP_Rebel_2",
	"BP_Rebel_3",
	"BP_Hunter_1",
	"BP_Hunter_2",
	"BP_Hunter_3",
	"BP_Survivalist_F",
	"BP_Survivalist_1",
	"BP_Survivalist_2",
	"BP_Survivalist_3",
	"BP_Engineer_1",
	"BP_Engineer_1",
	"BP_Engineer_2",
	"BP_Engineer_3",
	"BP_Undead_1",
	"BP_Undead_2",
	"BP_Undead_3",
	"BP_OptOut",
	"BP_OptOut2",
	"BP_OptOut3",
	"BP_OptOut4",
	"BP_StoneGhillie",
	"BP_TreeGhillie",
	"BP_DirtGhillie",
	"BP_SnowGhillie",
	"BP_Guarilla_Faded",
	"BP_Guarilla_Khaki",
	"BP_Guarilla_Leader",
	"BP_Guarilla_Camo",
	"BP_Ghillie_Lush",
	"BP_JungleGhillie_Uniform",
	"BP_Paramilitary_Jacket_Uniform",
	"BP_Paramilitary_Shorts_Uniform",
	"BP_Paramilitary_Tee_Uniform",
	"U_B_GhillieSuit_BP",
	"BP_Wetsuit"
];

BP_ZombieClothing =
[
	"BP_Refugee_F_Z",
	"BP_Refugee_1_Z",
	"BP_Refugee_2_Z",
	"BP_Refugee_3_Z",
	"BP_Guardian_F_Z",
	"BP_Guardian_1_Z",
	"BP_Guardian_2_Z",
	"BP_Guardian_3_Z",
	"BP_Rebel_F_Z",
	"BP_Rebel_1_Z",
	"BP_Rebel_2_Z",
	"BP_Rebel_3_Z",
	"BP_Hunter_1_Z",
	"BP_Hunter_2_Z",
	"BP_Hunter_3_Z",
	"BP_Survivalist_F_Z",
	"BP_Survivalist_1_Z",
	"BP_Survivalist_2_Z",
	"BP_Survivalist_3_Z",
	"BP_Engineer_1_Z",
	"BP_Engineer_1_Z",
	"BP_Engineer_2_Z",
	"BP_Engineer_3_Z",
	"BP_OptOut_Z",
	"BP_OptOut2_Z",
	"BP_OptOut3_Z",
	"BP_StoneGhillie_Z",
	"BP_TreeGhillie_Z",
	"BP_DirtGhillie_Z",
	"BP_SnowGhillie_Z",
	"BP_Guarilla_Faded_Z",
	"BP_Guarilla_Khaki_Z",
	"BP_Guarilla_Leader_Z",
	"BP_Guarilla_Camo_Z",
	"BP_Ghillie_Lush_Z",
	"BP_Wetsuit_Z",
	"BP_Scientist_Z",
	"BP_Worker_Z",
	"BP_Medic_Z",
	"BP_Mechanic_Z",
	"BP_Construction_Z"
];

BP_Group = [];

BP_TraitorClothing = ["BP_Guardian_F","BP_Rebel_F","BP_Refugee_F","BP_Survivalist_F","BP_Engineer_F","BP_Undead_F"];

BP_Threads = [];

//Zombie Types
_config = configFile >> "CfgBuildingLoot";
if (isClass (missionConfigFile >> "CfgBuildingLoot")) then
{
	_config = missionConfigFile >> "CfgBuildingLoot";
};
BP_baseTypes = getArray (_config >> "Default" >> "zombieClass");

////////////////////////////////////////////////////////////////////////

BP_LoadObject =
[
 "BP_Heli_Transport_01", //Heli
 "BP_Offroad_03_armed_F", //Pickup
 "BP_B_T_LSV_01_armed_F", //Prowler
 "BP_O_T_LSV_02_armed_F"  //Prowler
];

BP_LoadAmmo =
[
 "BP_100Rnd_65x39", //Heli Turret Ammo
 "BP_100Rnd_127x99_box", //Pickup Turret Ammo
 "BP_100Rnd_127x99_box", //Pickup Turret Ammo
 "BP_100Rnd_127x99_box" //Prowler Turret Ammo
];

BP_TurretAmmo =
[
 "2000Rnd_65x39_Belt_Tracer_Red",
 "100Rnd_127x99_mag_Tracer_Yellow",
 "100Rnd_127x99_mag_Tracer_Red",
 "500Rnd_65x39_Belt_Tracer_Green_Splash"
];

////////////////////////////////////////////////////////////////////////

BP_FuelFull =
[
	"ItemFuelcan",
	"ItemFuelcanLarge"
];

BP_FuelEmpty =
[
	"ItemFuelcanEmpty",
	"ItemFuelcanLargeEmpty"
];

BP_VehicleHorns =
[
	"CarHorn",
	"MiniCarHorn",
	"SportCarHorn",
	"CMFlareLauncher"
];

BP_Throwables =
[
	"ItemBrick1",
	"ItemBrick2",
	"HandGrenade",
	"ItemKnife",
	"ItemInfectedNeedle",
	"ItemBook1",
	"ItemBook2",
	"ItemBook3",
	"ItemMug",
	"ItemPottery",
	"ItemVideoTape",
	"ItemZipDisk",
	"ItemRock",
	"ItemPlate1",
	"ItemPlate2",
	"ItemTennisBall",
	"ItemCanEmpty",
	"ItemHammer",
	"ChemR",
	"ChemG",
	"ChemB",
	"ChemY",
	"SmokeShell",
	"SmokeShellRed",
	"BP_M84_Flash",
	"BP_AlarmClock_Black",
	"BP_AlarmClock_Red"
];

BP_ToolbeltItems = ["ItemWatch","ItemMap","ItemCompass","ItemGPS","ItemRadio","ItemSurgeryKit","ItemToolbox"];
BP_AllVests = ["V_PlateCarrierIA2_dgtl_BP","V_VPack_BP","V_CPack_BP","V_Chestrig_blk_BP","V_Chestrig_rgr_BP","V_Chestrig_khk_BP","V_HarnessO_brn_BP","V_RebreatherB","V_HarnessOGL_brn_BP","V_Rangemaster_belt_BP","V_BandollierB_cbr_BP","V_BandollierB_oli_BP","V_BandollierB_khk_BP","V_BandollierB_rgr_BP","V_BandollierB_blk_BP","V_PlateCarrierIA1_dgtl_BP","V_PlateCarrierIA1_dgt2_BP","V_PlateCarrier1_rgr_BP","V_PlateCarrier2_rgr_BP","V_PlateCarrier3_rgr_BP","V_PlateCarrierGL_rgr_BP","V_TacVest_brn_BP","V_TacVest_oli_BP","V_TacVest_blk_BP","V_TacVest_khk_BP","V_TacVest_camo_BP","V_HeroVest_BP","V_BanditBandolier_BP","V_PlateCarrierGL_tna_BP","V_TacVest_gen_BP","V_HarnessO_gry_BP","V_HarnessO_ghex_BP","V_BandollierB_ghex_BP","V_TacChestrig_grn_BP","V_TacChestrig_cbr_BP","V_PlateCarrierIAGL_dgtl_BP","V_TacVest_blk_POLICE_BP","V_TacVestIR_blk_BP","V_EngineerVest_BP","V_LBelt_BP","V_MBelt_BP","V_HBelt_BP","V_HVest_BP"];
BP_AllSkins = ["BP_JungleGhillie_Uniform","BP_Paramilitary_Jacket_Uniform","BP_Paramilitary_Shorts_Uniform","BP_Paramilitary_Tee_Uniform","BP_Optout4","BP_OptOut3","BP_OptOut2","BP_OptOut","BP_Refugee_F","BP_Guardian_F","BP_Rebel_F","BP_Survivalist_F","BP_Survivalist_3","BP_Survivalist_2","BP_Survivalist_1","BP_Hunter_3","BP_Hunter_2","BP_Hunter_1","BP_Rebel_3","BP_Rebel_2","BP_Rebel_1","BP_Guardian_3","BP_Guardian_2","BP_Guardian_1","BP_Refugee_3","BP_Refugee_2","BP_Refugee_1","BP_Poloshirt_blue","BP_Poloshirt_burgundy","BP_Poloshirt_stripped","BP_Poloshirt_tricolour","BP_Poloshirt_salmon","BP_Poloshirt_redwhite","U_B_CombatUniform_mcam_worn_BP","U_B_GhillieSuit_BP","U_Competitor_BP","U_I_CombatUniform_BP","U_I_GhillieSuit_BP","U_O_OfficerUniform_ocamo_BP","U_Rangemaster_BP","U_B_Wetsuit_BP","U_I_OfficerUniform_ocamo_BP","U_I_OfficerUniform_BP","BP_GrassGhillie","BP_StoneGhillie","BP_TreeGhillie","BP_DirtGhillie","BP_SnowGhillie","BP_Hero_1","BP_Hero_2","BP_Hero_3","BP_Bandit_1","BP_Bandit_2","BP_Bandit_3","BP_Rogue1","BP_Survivalist1","BP_Poloshirt_zed","BP_Poloshirt_zed2","BP_Poloshirt_zed3","BP_Poloshirt_zed4"];
BP_AllHeadgear = ["H_MilCap_dgtl","H_HelmetIA","H_Cap_headphones","H_Watchcap_blk","H_PilotHelmetFighter_B","BP_MilCap_Hero3","BP_MilCap_Hero1","BP_HeroCap","BP_HeroBoonie_cam","BP_Bandit_Bandanna","H_Shemag_olive","BP_Shemag_bandit","BP_RogueHat"];
BP_AllBackpacks = ["BP_KPack","BP_MPack","BP_SPack","BP_HPack","BP_RPack","BP_RPack2","BP_Bergen_Hero","BP_Carryall_Hero","BP_Carryall_Bandit","BP_Coyote_Bandit","BP_AssaultPack_khk","BP_AssaultPack_dgtl","BP_AssaultPack_rgr", "BP_AssaultPack_sgg", "BP_AssaultPack_blk", "BP_AssaultPack_cbr", "BP_AssaultPack_mcamo", "BP_AssaultPack_drt", "BP_AssaultPack_grs", "BP_AssaultPack_stn", "BP_AssaultPack_tre", "BP_Kitbag_mcamo", "BP_Kitbag_sgg", "BP_Kitbag_cbr", "BP_Kitbag_drt", "BP_Kitbag_grs", "BP_Kitbag_stn", "BP_Kitbag_tre", "BP_Bergen_sgg", "BP_Bergen_mcamo", "BP_Bergen_rgr", "BP_Bergen_blk", "BP_Bergen_drt", "BP_Bergen_grs", "BP_Bergen_stn", "BP_Bergen_tre", "BP_FieldPack_blk", "BP_FieldPack_ocamo", "BP_FieldPack_oucamo", "BP_FieldPack_cbr", "BP_FieldPack_drt", "BP_FieldPack_grs", "BP_FieldPack_stn", "BP_FieldPack_tree", "BP_Carryall_ocamo", "BP_Carryall_oucamo", "BP_Carryall_mcamo", "BP_Carryall_blk", "BP_Carryall_drt", "BP_Carryall_grs", "BP_Carryall_stn", "BP_Carryall_tre", "BP_Coyote_rgr", "BP_Coyote_oli", "BP_Coyote_cbr", "BP_CivilianOneBlack","BP_CivilianOneRed","BP_CivilianOneGreen","BP_CivilianOneBlue"];
BP_CustomItems = BP_ToolbeltItems + BP_AllVests + BP_AllSkins + BP_NormalClothing + BP_ZombieClothing + BP_AllHeadgear;

BP_Constructables = ["BP_Crate1","BP_Safe","BP_RockStash","BP_CamoNet"];

BP_Blueprints =
[
	//Haven Objects
	"BlueprintHaven", //ItemBlueprint_Haven
	"BlueprintHavenReinforce", //ItemBlueprint_HavenReinforcement
	"BlueprintChest", //ItemBlueprint_Chest
	"BlueprintIceBox", //ItemBlueprint_Refrigerator
	"BlueprintGunCab", //ItemBlueprint_GunCabinet
	"BlueprintStove", //ItemBlueprint_Stove
	"BlueprintTele", //ItemBlueprint_Television
	"BlueprintWaterBarrel",
	"BlueprintFuelBarrel",

	//World Objects
	"BlueprintCrate1", //ItemBlueprint_Crate1
	"BlueprintCache1", //ItemBlueprint_Cache1
	"BlueprintIED1", //ItemBlueprint_IED1
	"BlueprintCamoNet", //ItemBlueprint_CamoNet
	"BlueprintSafe", //ItemBlueprint_Safe
	"BlueprintRockStash" //ItemBlueprint_RockStash
];

BP_MeleeWeapons = ["MeleeHatchet","MeleeKatana","MeleePickaxe","MeleeHammer","MeleeHammer2","MeleeShovel","MeleeClub","MeleeCrowbar"];
BP_RandomWeapons = ["MeleeHatchet"];

BP_MeleeAmmo = ["Hatchet_Swing","Katana_Swing","Pickaxe_Swing","Hammer_Swing","BP_Bayonet_Stab","BP_Rifle_Butt"];

BP_DontSave = BP_MeleeAmmo + BP_VehicleHorns;

BP_FactionClothing = ["BP_Survivalist_3","BP_Survivalist_2","BP_Survivalist_1","BP_Hunter_3","BP_Hunter_2","BP_Hunter_1","BP_Rebel_3","BP_Rebel_2","BP_Rebel_1","BP_Guardian_3","BP_Guardian_2","BP_Guardian_1","BP_Refugee_3","BP_Refugee_2","BP_Refugee_1"];

BP_RandomZombie_Backpack = ["BP_Kitbag_sgg","BP_AssaultPack_rgr","BP_AssaultPack_sgg","BP_AssaultPack_blk","BP_AssaultPack_cbr","BP_AssaultPack_mcamo"];
BP_RandomZombie_Gun = ["BP_SUD_AK74M","BP_SUD_AK105","BP_LeeEnfield"];
BP_RandomZombie_Item = ["ItemBrick1","ItemBook1","ItemHammer","ItemPainkiller","ItemBandage","ItemSoda5","ItemCereal1","BP_16Rnd_9x21_Mag"];
BP_RandomZombie_Clothing = ["BP_Poloshirt_zed","BP_Poloshirt_zed2","BP_Poloshirt_zed3","BP_Poloshirt_zed4"];

BP_Houses =
[
	"Land_i_Stone_Shed_V1_F",
	"Land_i_Stone_Shed_V3_F",
	"Land_i_House_Big_02_V3_F",
	"Land_i_House_Big_02_V2_F",
	"Land_i_House_Big_01_V3_F",
	"Land_i_House_Big_01_V2_F",
	"Land_i_House_Small_02_V1_F",
	"Land_i_House_Small_02_V2_F",
	"Land_i_House_Small_02_V3_F",
	"Land_i_House_Small_03_V1_F",
	"Land_i_House_Big_02_V1_F",
	"Land_i_Stone_HouseSmall_V1_F",
	"Land_i_Stone_HouseSmall_V1_dam_F",
	"Land_i_House_Small_01_V2_F",
	"Land_i_House_Small_01_V3_F",
	"Land_i_House_Big_01_V1_F",
	"Land_i_Stone_HouseSmall_V3_F",
	"Land_i_Stone_HouseSmall_V2_F",
	"Land_i_Stone_Shed_V2_F",
	"Land_i_House_Big_02_V3_dam_F",
	"Land_i_Shop_01_V2_dam_F",
	//New Damage Model Support
	"Land_i_House_Big_01_V3_dam_F",
	"Land_i_House_Big_01_V2_dam_F",
	"Land_i_House_Big_01_V1_dam_F",
	"Land_i_Stone_HouseSmall_V3_dam_F",
	//Malden
	"Land_i_House_Big_02_b_blue_F",
	"Land_i_House_Big_02_b_pink_F",
	"Land_i_House_Big_02_b_whiteblue_F",
	"Land_i_House_Big_02_b_white_F",
	"Land_i_House_Big_02_b_brown_F",
	"Land_i_House_Big_02_b_yellow_F",

	"Land_i_House_Big_01_b_blue_F",
	"Land_i_House_Big_01_b_pink_F",
	"Land_i_House_Big_01_b_whiteblue_F",
	"Land_i_House_Big_01_b_white_F",
	"Land_i_House_Big_01_b_brown_F",
	"Land_i_House_Big_01_b_yellow_F",
	
	"Land_i_House_Small_01_b_blue_F",
	"Land_i_House_Small_01_b_pink_F",
	"Land_i_House_Small_01_b_whiteblue_F",
	"Land_i_House_Small_01_b_white_F",
	"Land_i_House_Small_01_b_brown_F",
	"Land_i_House_Small_01_b_yellow_F",

	"Land_i_House_Small_02_b_blue_F",
	"Land_i_House_Small_02_b_pink_F",
	"Land_i_House_Small_02_b_whiteblue_F",
	"Land_i_House_Small_02_b_white_F",
	"Land_i_House_Small_02_b_brown_F",
	"Land_i_House_Small_02_b_yellow_F",

	"Land_i_Stone_Shed_01_b_clay_F",
	"Land_i_Stone_Shed_01_b_raw_F",
	"Land_i_Stone_Shed_01_b_white_F",

	//Tanoa
	"Land_House_Small_05_F",
	"Land_Shed_05_F",
	"Land_Shed_02_F",
	"Land_GarageShelter_01_F",
    "Land_House_Small_03_F",
    "Land_House_Small_04_F",
    "Land_House_Small_02_F",
    "Land_Slum_03_F",
    "Land_Slum_01_F",
	"Land_Slum_House02_F",
	//LIVONIA
	"Land_Camp_House_01_brown_F",
	"Land_House_1W01_F",
	"Land_House_1W02_F",
	"Land_House_1W03_F",
	"Land_House_1W04_F",
	"Land_House_1W05_F",
	"Land_House_1W06_F",
	"Land_House_1W07_F",
	"Land_House_1W08_F",
	"Land_House_1W09_F",
	"Land_House_1W10_F",
	"Land_House_1W11_F",
	"Land_House_1W12_F",
	"Land_House_1W08_F",
	"Land_House_2W01_F",
	"Land_House_2W02_F",
	"Land_House_2W03_F",
	"Land_House_2W04_F",
	"Land_House_2B01_F"	
];

Attachments_Both = ["acc_flashlight","acc_pointer_IR","BP_milSpec_suppr"];
Attachments_Primary_Light = ["BP_CPad","BP_AFG","BP_Handle","BP_flashlight","acc_pointer_IR","BP_mk12covers","BP_m16covers","BP_m4covers"];
Attachments_Primary_Sight = ["BP_ZF42","BP_SOS","BP_M8","BP_Unertl8x","BP_Unertl32x","BP_PSOP","BP_OldComp","BP_MRT","BP_VX2","BP_VX3","BP_L14x","BP_M3AMRAD","BP_PS22","BP_M3A","BP_M3A2","BP_NXS","BP_EnfieldOptic2","BP_compm4s","BP_m3lr","optic_Arco","optic_Hamr","optic_Aco","optic_ACO_grn","optic_Aco_smg","optic_ACO_grn_smg","optic_Holosight","optic_Holosight_smg","optic_MRCO","BP_optic_ACOG"];
Attachments_Primary_Sound = ["BP_762Muzzle","BP_R7P","BP_R7S","BP_CZSup_br","BP_762Sup2","BP_Sup22","BP_muzzle_snds_408","BP_muzzle_snds_M12","BP_muzzle_snds_M2","BP_muzzle_snds_M","BP_muzzle_snds_B","BP_muzzle_snds_H_MG","BP_muzzle_snds_H","BP_muzzle_snds_H_SN","BP_m110_suppr","BP_Sup417_DES","BP_milSpec_suppr","BP_M24Int_suppr","BP_308Int_suppr","BP_AWSMInt_suppr","BP_CZmod_br","BP_CZst_br","BP_CZol_br","BP_300Sup"];
Attachments_Handgun_Light = ["BP_Plight","BP_CQCKnife","BP_GhillieWL","BP_GhillieDes","BP_GhillieSnw"];
Attachments_Handgun_Sight = ["optic_mrd","optic_yorris"];
Attachments_Handgun_Sound = ["BP_Mk12Sup","BP_Demz","BP_muzzle_snds_L","BP_muzzle_snds_acp","BP_gemtech9","BP_gemtech45","BP_m9qd","BP_aacusp","BP_matchsd","BP_pmsd","BP_suppr9","BP_milSpec_suppr","BP_muzzle_MK18_L","BP_muzzle_MK18D_L"];
Attachments_Primary = Attachments_Primary_Light + Attachments_Primary_Sight + Attachments_Primary_Sound;
Attachments_Handgun = Attachments_Handgun_Light + Attachments_Handgun_Sight + Attachments_Handgun_Sound;
Attachments_Both = Attachments_Primary_Light + Attachments_Handgun_Light;
Attachments_All = Attachments_Primary + Attachments_Handgun;

//Settings
_cfgSettings = (missionConfigFile >> "BreakingPoint" >> "CfgSettings");
BP_DebugMarker = getText (_cfgSettings >> "Debug" >> "marker");
BP_DebugRadius = getNumber (_cfgSettings >> "Debug" >> "radius");

BP_dawn = getNumber (_cfgSettings >> "Time" >> "dawn");
BP_dusk = getNumber (_cfgSettings >> "Time" >> "dusk");

BP_MaxAnimals = getNumber (_cfgSettings >> "Animals" >> "max");
BP_AnimalDistance = getNumber (_cfgSettings >> "Animals" >> "distance");

BP_Zeds = (getNumber (_cfgSettings >> "Zombies" >> "enabled") == 1);
BP_ZedDistance = getNumber (_cfgSettings >> "Zombies" >> "distance");
BP_ZedMax = getNumber (_cfgSettings >> "Zombies" >> "max");
BP_ZedMaxNearby = getNumber (_cfgSettings >> "Zombies" >> "maxNearby");
BP_ZedMaxLocal = getNumber (_cfgSettings >> "Zombies" >> "maxLocal");
BP_ZedMaxGlobal = getNumber (_cfgSettings >> "Zombies" >> "maxGlobal");

BP_SpawnSelect = (getNumber (_cfgSettings >> "SpawnPos" >> "enabled") == 1);

BP_Factions = (getNumber (_cfgSettings >> "Factions" >> "enabled") == 1);

BP_Factions_None = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "none") == 1);
BP_Factions_Ranger = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "ranger") == 1);
BP_Factions_Outlaw = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "outlaw") == 1);
BP_Factions_Hunter = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "hunter") == 1);
BP_Factions_Nomad = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "nomad") == 1);
BP_Factions_Survivalist = (getNumber (_cfgSettings >> "Factions" >> "Classes" >> "survivalist") == 1);

BP_Factions_disableMixedgrouping = false;

if(isText (_cfgSettings >> "Factions" >> "disableMixedgrouping")) then
{
	if(getNumber (_cfgSettings >> "Factions" >> "disableMixedgrouping") == 1) then
	{
		BP_Factions_disableMixedgrouping = true;
	};
};

BP_Factions_Points = (getNumber (_cfgSettings >> "Factions" >> "Points" >> "enabled") == 1);
BP_Factions_PointsRatio = getNumber (_cfgSettings >> "Factions" >> "Points" >> "ratio");

BP_Loot = (getNumber (_cfgSettings >> "Loot" >> "enabled") == 1);
BP_LootBoxMinItems = getNumber (_cfgSettings >> "Loot" >> "minItems");
BP_LootBoxMaxItems = getNumber (_cfgSettings >> "Loot" >> "maxItems");
BP_LootBoxMinSpawn = (getNumber (_cfgSettings >> "Loot" >> "minSpawn") == 1);

BP_Loot_Override = (getNumber (_cfgSettings >> "Loot" >> "lootOverride") == 1);
BP_Loot_OverrideClass = getText (_cfgSettings >> "Loot" >> "lootOverrideClass");

BP_Helicrashes = (getNumber (_cfgSettings >> "HeliCrash" >> "enabled") == 1);

//BP_FactionStronghold = 0;
//BP_FactionStrongholds = isClass (_cfgSettings >> "Factions" >> "Bases");
////Ranger
//BP_FactionStronghold_Ranger = isClass (_cfgSettings >> "Factions" >> "Bases" >> "Ranger");
//BP_FactionStronghold_RangerPos = getArray (_cfgSettings >> "Factions" >> "Bases" >> "Ranger" >> "position");
//BP_FactionStronghold_RangerRadius = getNumber (_cfgSettings >> "Factions" >> "Bases" >> "Ranger" >> "radius");
////Outlaw
//BP_FactionStronghold_Outlaw = isClass (_cfgSettings >> "Factions" >> "Bases" >> "Outlaw");
//BP_FactionStronghold_OutlawPos = getArray (_cfgSettings >> "Factions" >> "Bases" >> "Outlaw" >> "position");
//BP_FactionStronghold_OutlawRadius = getNumber (_cfgSettings >> "Factions" >> "Bases" >> "Outlaw" >> "radius");
////Hunter
//BP_FactionStronghold_Hunter = isClass (_cfgSettings >> "Factions" >> "Bases" >> "Hunter");
//BP_FactionStronghold_HunterPos = getArray (_cfgSettings >> "Factions" >> "Bases" >> "Hunter" >> "position");
//BP_FactionStronghold_HunterRadius = getNumber (_cfgSettings >> "Factions" >> "Bases" >> "Hunter" >> "radius");
////Nomad
//BP_FactionStronghold_Nomad = isClass (_cfgSettings >> "Factions" >> "Bases" >> "Nomad");
//BP_FactionStronghold_NomadPos = getArray (_cfgSettings >> "Factions" >> "Bases" >> "Nomad" >> "position");
//BP_FactionStronghold_NomadRadius = getNumber (_cfgSettings >> "Factions" >> "Bases" >> "Nomad" >> "radius");
////Survivalist
//BP_FactionStronghold_Survivalist = isClass (_cfgSettings >> "Factions" >> "Bases" >> "Survivalist");
//BP_FactionStronghold_SurvivalistPos = getArray (_cfgSettings >> "Factions" >> "Bases" >> "Survivalist" >> "position");
//BP_FactionStronghold_SurvivalistRadius = getNumber (_cfgSettings >> "Factions" >> "Bases" >> "Survivalist" >> "radius");

med_woundHit =
[
	"",
	"body",
	"hands",
	"legs",
	"head"
];

BP_woundHit 	=
[
	[
		"body",
		"hands",
		"legs",
		"head_hit"
	],
	[ 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,3]
];

BP_woundHit_ok =
[
	[
		"body",
		"hands",
		"legs"
	],
	[0,0,0,0,0,1,1,1,2,2]
];

med_MinorWounds =
[
	"hands",
	"legs",
	"hitlegs",
	"hitarms",
	"hithands"
];

med_woundPoint	= [
	["Pelvis","aimpoint"],
	["aimpoint"], //,"RightShoulder","LeftShoulder"
	["lelbow","relbow"],
	["RightFoot","LeftFoot"],
	["neck","pilot"]
];

med_typeOfWounds =
[
	"Pelvis",
	"aimpoint",
	"lelbow","relbow",
	"RightFoot","LeftFoot",
	"neck","pilot"
];

BP_partClasses =
[
	//"PartGeneric",	//No need to add, it is default for everything
	"PartFueltank",
	"PartWheel",
	"PartEngine"
];

BP_explosiveParts = [
	"HitEngine",
	"HitEngine2",
	"HitEngine3",
	"HitFuel"
];

//Cooking
meatraw =
[
    "FoodSteakRaw",
    "FoodMeatRaw",
	"FoodZombieRaw",
	"FoodPlayerRaw",
    "FoodBeefRaw",
    "FoodMuttonRaw",
    "FoodChickenRaw",
    "FoodRabbitRaw",
    "FoodBaconRaw"
];

meatcooked =
[
    "FoodSteakCooked",
    "FoodMeatCooked",
	"FoodZombieCooked",
	"FoodPlayerCooked",
    "FoodBeefCooked",
    "FoodMuttonCooked",
    "FoodChickenCooked",
    "FoodRabbitCooked",
    "FoodBaconCooked"
];

meatzombie = ["FoodZombieRaw","FoodZombieCooked"];

//Eating
no_output_food = ["FoodPistachio", "FoodNutmix"]+meatcooked+meatraw;
food_with_output =
[
	"ItemCan1",
	"ItemCan2",
	"ItemCan3",
	"ItemCan4",
	"ItemCan5",
	"FoodCanUnlabeled"
];

food_output = [
    "ItemCanEmpty",
    "ItemCanEmpty",
    "ItemCanEmpty",
    "ItemCanEmpty",
	"ItemCanEmpty",
	"FoodCanUnlabeledEmpty"
];
//Drinking
no_output_drink = ["Waterbot", "WaterbotBoiled"];
drink_with_output = [
    "ItemSoda1",
	"ItemSoda2",
	"ItemSoda3",
	"ItemSoda4",
	"ItemSoda5"
];
drink_output = [
    "ItemCanEmpty", //"ItemSoda1Empty",
	"ItemCanEmpty", //"ItemSoda2Empty",
	"ItemCanEmpty", //"ItemSoda3Empty",
	"ItemCanEmpty", //"ItemSoda4Empty",
	"ItemCanEmpty" //"ItemSoda5Empty",
];
boil_tin_cans = [
    "ItemCanEmpty",
	"FoodCanUnlabeledEmpty",
    "ItemSodaEmpty"
];

AllFood = [];
AllDrinks = ["ItemWatercan"];
AllMedical = ["ItemBandage","ItemFieldDressing","ItemMorphine","ItemAdrenaline","ItemHeatPack","ItemPainkiller","ItemAntibiotic"];

AllFood = meatcooked + food_with_output + no_output_food;
AllFood = AllFood + ["ItemCereal1","ItemCereal2","ItemCereal3","ItemCereal4","ItemCereal5", "ItemCereal6"];
AllDrinks = no_output_drink + drink_with_output;

//Survival Variables
SleepFood =	getNumber (_cfgSettings >> "Survival" >> "Food");
SleepWater = getNumber (_cfgSettings >> "Survival" >> "Water");
SleepTemperature = getNumber (_cfgSettings >> "Survival" >> "Temperature");

if (isServer) exitWith {};

BP_CurrentInventorySkin = 0;
BP_InventorySkins =
[
	//Default Skin
	[
		"\breakingpoint_ui\inventory\background_inventory_1.paa",
		"\breakingpoint_ui\inventory\background_ground_1.paa"
	],
	//Minimal UI Skin
	[
		"\breakingpoint_ui\inventory\background_inventory_2.paa",
		"\breakingpoint_ui\inventory\background_ground_2.paa"
	]
];

BP_PreloadTitleObj = [];

BP_PreloadTitleRsc =
[
	"TitleScreen",
	"BP_Ghosting",
	"DeathScreenStart",
	"DeathScreenEnd",
	"DeathScreenEndZed",
	"BP_Unconscious",
	"BP_BloodspraySmall",
	"BP_BloodsprayMedium",
	"BP_BloodsprayLarge",
	"Bp_BloodsprayStunned",
	"BP_Flashbang",
	"BP_Resting",
	"BP_AuthFailed",
	"BP_InvalidVersion",
	"BP_OutdatedServer",
	"BP_InvalidAddons",
	"BP_InvalidName",
	"BP_NoPlayerID",
	"BP_ServerNotReady",
	"BP_LegionOnly",
	"BP_Whitelist",
	"BP_Scratch_1",
	"BP_Scratch_2",
	"BP_Scratch_3",
	"BP_Scratch_4",
	"BP_Scratch_5",
	"BP_Dog_1",
	"BP_Dog_2",
	"BP_Dog_3",
	"BP_Dog_4",
	"BP_Dog_5",
	"BP_Dog_6"
];

BP_ObjectPreload =
[
	//Zombies
	"BPZombie_Rebel1",
	"BPZombie_Rebel2",
	"BPZombie_Rebel3",
	"BPZombie_Guardian1",
	"BPZombie_Guardian2",
	"BPZombie_Guardian3",
	"BPZombie_Survivalist1",
	"BPZombie_Survivalist2",
	"BPZombie_Survivalist3",
	"BPZombie_Refugee1",
	"BPZombie_Refugee2",
	"BPZombie_Refugee3",
	"BPZombie_Hunter1",
	"BPZombie_Hunter2",
	"BPZombie_Hunter3",
	"BPZombie_EngineerF",
	"BPZombie_Engineer1",
	"BPZombie_Optout",
	"BPZombie_Optout2",
	"BPZombie_Optout3",
	"BPZombie_Optout4",
	"BPZombie_Optout5",
	"BPZombie_Optout6",
	"BPZombie_Optout7",
	"BPZombie_Optout8",
	"BPZombie_Scientist",
	"BPZombie_Worker",
	"BPZombie_Medic",
	"BPZombie_Mechanic",
	"BPZombie_Construction1",
	"BPZombie_Construction2",
	"BPZombie_Construction3",
	"BPZombie_Construction4",
	//Storage Objects

	//Loot Boxes
	"BP_Medicalbox",
	"BP_AmmoBoxNew",
	"BP_AmmoBoxOld",
	"BP_AmmoCrateNew",
	"BP_AmmoCrateOld",
	"BP_WeaponCrateNew",
	"BP_WeaponCrateOld",
	"BP_WeaponCrate_WWII",
	"BP_HeavyWeaponCrate",
	"BP_VehicleAmmoCrate",
	"BP_AirDropCrate",
	"BP_AmmoPallet1",
	"BP_AmmoPallet2",
	"BP_AmmoPallet3",
	"BP_AmmoPallet4",
	"BP_CardboardBox_1",
	"BP_CardboardBox_2",
	"BP_CardboardBox_3",
	"BP_CardboardBox_4",
	"BP_Trashcan",
	"BP_Bag1",
	"BP_Bag2",
	"BP_LuggageBags",
	"BP_Dumpster1",
	"BP_Dumpster2",
	"BP_Dumpster3",
	"BP_Dumpster4",
	"BP_Dumpster5",
	"BP_Skip1",
	"BP_Skip2",
	"BP_Skip3",
	"BP_Skip4",
	"BP_Skip5"
];
