/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Base Class
class BP_LootBox : Thing 
{
	scope = public;
	displayName = "Loot Box";
	mapSize = 0.7;
	accuracy = 0.2;
	vehicleClass = "Survival";
	maximumLoad = 750;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
	destrType = "DestructNo";
	hideDistance = 100;
	class EventHandlers {
		init = "_this call BP_fnc_onLootInit;";
		local = "_this call BP_fnc_onLootLocal;";
	};
};
	
class BP_Medicalbox: BP_LootBox
{
	scope = public;
	displayName = "Medical Box";
	model = "\breakingpoint\models\bp_medicalbox.p3d";
};

class BP_MedicalboxHelicrash: BP_LootBox
{
	scope = public;
	displayName = "Medical Box (Helicrash)";
	model = "\breakingpoint\models\bp_medicalbox.p3d";
	class transportmagazines {
		class _xx_ItemBandage {
			magazine = "ItemBandage";
			count = 10;
		};

		class _xx_ItemFieldDressing {
			magazine = "ItemFieldDressing";
			count = 3;
		};

		class _xx_ItemMorphine {
			magazine = "ItemMorphine";
			count = 3;
		};
		
		class _xx_ItemPainkiller {
			magazine = "ItemPainkiller";
			count = 3;
		};
		
		class _xx_ItemAntibiotic {
			magazine = "ItemAntibiotic";
			count = 1;
		};
		
		class _xx_ItemAdrenaline {
			magazine = "ItemAdrenaline";
			count = 1;
		};
		
		class _xx_ItemKnife {
			magazine = "ItemKnife";
			count = 1;
		};
		
		class _xx_ItemMatchbox {
			magazine = "ItemMatchbox";
			count = 1;
		};
		
		class _xx_ItemBrick1 {
			magazine = "ItemBrick1";
			count = 1;
		};
	};
};

/* Apex Mil Boxes*/	

class BP_ApexMilBox1 : BP_LootBox {
    displayName = "Apex Gun Crate";
	model = "\A3\Props_F_Exp\Commercial\Market\WoodenCrate_01_F.p3d";
};	

class BP_ApexMilBox2 : BP_LootBox {
    displayName = "Apex Gear Crate";
	model = "\A3\Supplies_F_Exp\Ammoboxes\Equipment_Box_F.p3d";
};
	
/* Military Boxes Very Small (Small Magazine Supply Boxes)*/	

class BP_AmmoBoxNew : BP_LootBox {
    displayName = "Small Ammo Box";
	model = "\A3\structures_f_epb\Items\Military\Ammobox_rounds_F.p3d";
};	
class BP_AmmoBoxOld : BP_LootBox {
    displayName = "Small Old Ammo Box";
	model = "\A3\weapons_F\AmmoBoxes\Proxy_UsBasicAmmoBoxSmall.p3d";
};

/* Military Boxes Small (Regular Sized Ammo/SideArm Crates)*/	
class BP_AmmoCrateNew : BP_LootBox {
    displayName = "Small Ammo Crate";
	model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F.p3d";
};
class BP_AmmoCrateOld : BP_LootBox {
    displayName = "Small Old Ammo Crate";
	model = "\A3\weapons_F\AmmoBoxes\Proxy_UsBasicAmmoBoxBig.p3d";
};

/* Military Boxes Medium (Universal Weapons Boxes)*/ 
class BP_WeaponCrateNew : BP_LootBox {
    displayName = "Weapon Crate";
	model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F.p3d";
};
class BP_WeaponCrateOld : BP_LootBox {
    displayName = "Old Weapon Crate";
	model = "\A3\weapons_F\AmmoBoxes\USBasicAmmo.p3d";
};
class BP_WeaponCrate_WWII : BP_LootBox {
	displayName = "Surplus Weapon Crate";
	model = "\breakingpoint\models\bp_crate1b.p3d";
};
	
/* Military Boxes Large (Helicrash/Underwater)*/	
class BP_HeavyWeaponCrate : BP_LootBox {
    model = "\A3\weapons_F\AmmoBoxes\AmmoBox.p3d";
};
class BP_VehicleAmmoCrate : BP_LootBox {
    model = "\A3\weapons_F\AmmoBoxes\AmmoVeh_F.p3d";
};
class BP_AirDropCrate : BP_LootBox {
    model = "\A3\Weapons_F\Ammoboxes\Supplydrop.p3d";
};
class BP_AmmoPallet1 : BP_LootBox {
    model = "\A3\structures_f_epa\Mil\Scrapyard\PaperBox_closed_F.p3d";
};		
class BP_AmmoPallet2 : BP_LootBox {
    model = "\A3\structures_f_epa\Mil\Scrapyard\PaperBox_open_empty_F.p3d";
};	
class BP_AmmoPallet3 : BP_LootBox {
    model = "\A3\structures_f_epa\Mil\Scrapyard\PaperBox_open_full_F.p3d";
};	
class BP_AmmoPallet4 : BP_LootBox {
    model = "\A3\structures_f_epa\Mil\Scrapyard\Pallet_MilBoxes_F.p3d";
};	

/* Cardboard Boxes */
class BP_CardboardBox_1: BP_LootBox {
	hiddenSelections[] = {"base"};
	hiddenSelectionsTextures[] = {"breakingpoint\textures\items\box1_co.paa"};
	model = "\breakingpoint\models\bp_box1.p3d";
	displayName = "Cardboard Box";
};
class BP_CardboardBox_2: BP_CardboardBox_1 {
	hiddenSelectionsTextures[] = {"breakingpoint\textures\items\box2_co.paa"};
};
class BP_CardboardBox_3: BP_LootBox {
	model = "\breakingpoint\models\bp_cardboardbox.p3d";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\cardboardbox1_co.paa"};
};
class BP_CardboardBox_4: BP_CardboardBox_1 {
	hiddenSelectionsTextures[] = {"breakingpoint\textures\items\box4_co.paa"};
};

/* Trashcan */
class BP_Trashcan : BP_LootBox { model = "\breakingpoint\models\bp_trashcan.p3d"; };

/* Bag */
class BP_Bag1 : BP_LootBox { model = "\breakingpoint\models\bp_bag1.p3d"; };
class BP_Bag2 : BP_LootBox { model = "\breakingpoint\models\bp_bag2.p3d"; };
class BP_LuggageBags : BP_LootBox { model = "\A3\structures_f_epb\Items\Luggage\LuggageHeap_01_F.p3d"; };	

class BP_Packs : BP_LootBox { model = "\A3\structures_f_epb\Items\Luggage\LuggageHeap_02_F.p3d"; };
class BP_MilPallet : BP_LootBox { model = "\A3\structures_f_epb\Items\Luggage\LuggageHeap_02_F.p3d"; };

/* Dumpster */
class BP_Dumpster1 : BP_LootBox {
	model = "\breakingpoint\models\bp_dumpster.p3d";
	hiddenSelections[] = {"base"};
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\dumpster1_co.paa"};
};
class BP_Dumpster2 : BP_Dumpster1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\dumpster2_co.paa"}; };
class BP_Dumpster3 : BP_Dumpster1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\dumpster3_co.paa"}; };
class BP_Dumpster4 : BP_Dumpster1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\dumpster4_co.paa"}; };
class BP_Dumpster5 : BP_Dumpster1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\dumpster5_co.paa"}; };

/* Skip */
class BP_Skip1 : BP_LootBox {
	model = "\breakingpoint\models\bp_skip.p3d";
	hiddenSelections[] = {"base"};
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\skip1_co.paa"};
	hideDistance = 800;
};
class BP_Skip2 : BP_Skip1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\skip2_co.paa"}; };
class BP_Skip3 : BP_Skip1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\skip1_co.paa"}; };
class BP_Skip4 : BP_Skip1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\skip1_co.paa"}; };
class BP_Skip5 : BP_Skip1 { hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\skip1_co.paa"}; };
	
