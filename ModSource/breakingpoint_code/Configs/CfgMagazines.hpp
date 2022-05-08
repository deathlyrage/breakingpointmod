/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgMagazines 
{
	class CA_Magazine;	// External class reference
	class BP_Magazine : CA_Magazine {};
	
	class BP_Food : BP_Magazine {
		isFood = 1;
		count = 1;
		type = 256;
		bloodRegen = 400; //225
	};
	
	class BP_BaseSprayCan : BP_Magazine 
	{
		displayName = "Spray Can (Base)";
		descriptionUse = "Spray Can (Base)";
		descriptionShort = "Does Epic Things.";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneCanister_F.p3d";
		//model = "breakingpoint\models\bp_spraycan.p3d";
		picture = "\breakingpoint\textures\icons\bp_soda1_ca.paa";
	};
	
	class BP_SprayCan_WDL : BP_BaseSprayCan 
	{
		displayName = "Spray Can (Woodland)";
		picture = "\breakingpoint\textures\icons\bp_soda1_ca.paa";
		colour = "WDL";
	};
	
	class BP_SprayCan_DES : BP_BaseSprayCan 
	{
		displayName = "Spray Can (Desert)";
		descriptionUse = "Spray Can (Desert)";
		picture = "\breakingpoint\textures\icons\bp_soda2_ca.paa";
		colour = "DES";
	};
	
	class BP_SprayCan_URB : BP_BaseSprayCan 
	{
		displayName = "Spray Can (Urban)";
		descriptionUse = "Spray Can (Urban)";
		picture = "\breakingpoint\textures\icons\bp_soda3_ca.paa";
		colour = "URB";
	};

	// Explosive Shit And Traps
	class BP_TripMine_Mag : CA_Magazine
	{
		count = 1;
		type = 256;
		mass = 10;
		displayName = "APERS Tripwire Mine";
		picture = "\A3\Weapons_F\Data\UI\gear_mine_AP_tripwire_CA.paa";
		model = "\A3\Weapons_F\explosives\mine_AP_tripwire_i";
		descriptionShort = "Type: Anti-personnel tripwire mine<br />Rounds: 1<br />Used on: Ground";
		ammo = "BP_TripMine_Ammo";
	};
	
	class BP_ATMine_Mag : CA_Magazine
	{
		count = 1;
		type = 256;
		mass = 120;
		displayName = "AT Mine";
		picture = "\A3\Weapons_F\Data\UI\gear_mine_AT_CA.paa";
		model = "\A3\Weapons_f\Explosives\mine_at_i";
		descriptionShort = "Type: Anti-tank mine <br />Rounds: 1<br />Used on: Ground";
		ammo = "BP_ATMine_Ammo";
	};
	
	class BP_BearTrap_Mag : CA_Magazine
	{
		count = 1;
		type = 256;
		mass = 45;
		displayName = "Bear Trap";
		picture = "\breakingpoint\textures\icons\bp_beartrap_ca.paa";
		model = "\breakingpoint\models\bp_beartrap.p3d";
		descriptionShort = "Type: Bear Trap <br />Rounds: 1<br />Used on: Ground";
		ammo = "BP_BearTrap";
	};
	
	class HandGrenade;
	class HandGrenadeLive : HandGrenade 
	{
		displayName = "Modified Grenade";
		descriptionShort = "It appears someone has modified this grenade. It looks like it has been pulled apart and put back together.";
	};
	
	// Food Items
	class ItemCereal : BP_Food {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Cereal";
		descriptionUse = "Cereal";
		model = "\breakingpoint\models\bp_cereal1.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal1_ca.paa";
		descriptionShort = "";
		mass = 5;
	};
	
	class FoodEdible : CA_Magazine {
		isFood = 1;
		count = 1;
		type = 256;
		bloodRegen = 200;
	};
	
	class ItemCereal1 : ItemCereal {
		displayName = "Cereal (Bloodsucker Balls)";
		descriptionUse = "Cereal (Bloodsucker Balls)";
		model = "\breakingpoint\models\bp_cereal1.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal1_ca.paa";
		descriptionShort = "One bite and you won't be able to get rid of them!";
	};
	class ItemCereal2 : ItemCereal {
		displayName = "Cereal (Honey Hoops)";
		descriptionUse = "Cereal (Honey Hoops)";
		model = "\breakingpoint\models\bp_cereal2.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal2_ca.paa";
		descriptionShort = "Now with real honey!";
	};
	class ItemCereal3 : ItemCereal {
		displayName = "Cereal (Crispy Squares)";
		descriptionUse = "Cereal (Crispy Squares)";
		model = "\breakingpoint\models\bp_cereal3.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal3_ca.paa";
		descriptionShort = "Probably stale by now";
	};
	class ItemCereal4 : ItemCereal {
		displayName = "Cereal (Crunchy Stars)";
		descriptionUse = "Cereal (Crunchy Stars)";
		model = "\breakingpoint\models\bp_cereal4.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal4_ca.paa";
		descriptionShort = "Lets be honest, mostly sugar";
	};
	class ItemCereal5 : ItemCereal {
		displayName = "Cereal (Captain Kush)";
		descriptionUse = "Cereal (Captain Kush)";
		model = "\breakingpoint\models\bp_cereal5.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal5_ca.paa";
		descriptionShort = "Guaranteed to cut the roof of your mouth";
	};
	
	class ItemCereal6 : ItemCereal {
		displayName = "Cereal? (Rickaronis)";
		descriptionUse = "Cereal? (Rickaronis)";
		model = "\breakingpoint\models\bp_cereal6.p3d";
		picture = "\breakingpoint\textures\icons\bp_cereal6_ca.paa";
		descriptionShort = "A Ranger's best friend!";
		bloodRegen = 1500;
	};

	class ItemCan1 : ItemCereal {
		displayName = "Can (Spam)";
		descriptionUse = "Can (Spam)";
		model = "\breakingpoint\models\bp_can1.p3d";
		picture = "\breakingpoint\textures\icons\bp_can1_ca.paa";
		descriptionShort = "Made from only the finest questionable meat products (now with less horse!)";
		class InventoryPreview
		{
			scale = 1;
			direction[] = {0, -0.35, -0.65};
			up[] = {0, 0.65, -0.35};
		};
	};
	class ItemCan2 : ItemCan1 {
		displayName = "Can (Tuna Chunks)";
		descriptionUse = "Can (Tuna Chunks)";
		model = "\breakingpoint\models\bp_can2.p3d";
		hiddenSelectionsTextures[] = {"breakingpoint\textures\items\can2_co.paa"};
		picture = "\breakingpoint\textures\icons\bp_can2_ca.paa";
		descriptionShort = "100% real tuna, does not contain COD!";
	};
	class ItemCan3 : ItemCan1 {
		displayName = "Can (Moms Spaghetti)";
		descriptionUse = "Can (Moms Spaghetti)";
		model = "\breakingpoint\models\bp_can3.p3d";
		picture = "\breakingpoint\textures\icons\bp_can3_ca.paa";
		descriptionShort = "Just eat it";
	};
	class ItemCan4 : ItemCan1 {
		displayName = "Can (Meatballs)";
		descriptionUse = "Can (Meatballs)";
		model = "\breakingpoint\models\bp_can4.p3d";
		picture = "\breakingpoint\textures\icons\bp_can4_ca.paa";
		descriptionShort = "May or may not be particularly fresh";
	};
	class ItemCan5 : ItemCan1 {
		displayName = "Can (Hotdogs)";
		descriptionUse = "Can (Hotdogs)";
		model = "\breakingpoint\models\bp_can5.p3d";
		picture = "\breakingpoint\textures\icons\bp_can5_ca.paa";
		descriptionShort = "Suggestively tubed meat product";
	};
	
	class ItemSoda: BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		sfx = "soda";
		mass = 5;
	};

	class ItemSoda1 : ItemSoda {
		displayName = "Soda (Apple)";
		descriptionUse = "Soda (Apple)";
		descriptionShort = "Carbonated sugar water, contains 0.01% apple";
		model = "breakingpoint\models\bp_soda1_full.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_soda1_ca.paa";
	};
	class ItemSoda2 : ItemSoda {
		displayName = "Soda (Orange)";
		descriptionUse = "Soda (Orange)";
		descriptionShort = "Carbonated sugar water, does not actually contain orange";
		model = "breakingpoint\models\bp_soda2_full.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_soda2_ca.paa";
	};
	class ItemSoda3 : ItemSoda {
		displayName = "Soda (Lemonade)";
		descriptionUse = "Soda (Lemonade)";
		descriptionShort = "Carbonated sugar water, doesn't even taste like lemons";
		model = "breakingpoint\models\bp_soda3_full.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_soda3_ca.paa";
	};
	class ItemSoda4 : ItemSoda {
		displayName = "Soda (Cola)";
		descriptionUse = "Soda (Cola)";
		descriptionShort = "Carbonated sugar water, contains Coca leaf extract";
		model = "breakingpoint\models\bp_soda4_full.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_soda4_ca.paa";
	};
	class ItemSoda5 : ItemSoda {
		displayName = "Soda (Cherry Cola)";
		descriptionUse = "Soda (Cherry Cola)";
		descriptionShort = "Carbonated sugar water, contains only trace amounts of cherry";
		model = "breakingpoint\models\bp_soda5_full.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_soda5_ca.paa";
	};

	class ItemBlowtorch : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Blowtorch";
		descriptionUse = "Blowtorch";
		model = "\breakingpoint\models\bp_blowtorch1.p3d";
		picture = "\breakingpoint\textures\icons\bp_blowtorch1_ca.paa";
		descriptionShort = "Hand held propane torch";
		mass = 25;
	};

	class ItemCanvasMaterial : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Canvas Material";
		descriptionUse = "Canvas Material";
		model = "\breakingpoint\models\bp_tent_netting.p3d";
		picture = "\breakingpoint\textures\icons\bp_tent_netting_ca.paa";
		descriptionShort = "Heavy duty canvas";
		mass = 20;
	};
	
	class ItemNettingMaterial : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Netting Material";
		descriptionUse = "Netting Material";
		model = "\breakingpoint\models\bp_camo_netting.p3d";
		picture = "\breakingpoint\textures\icons\bp_camo_netting_ca.paa";
		descriptionShort = "";
		mass = 10;
	};

	class ItemWoodenPoles : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Pair of Aluminium Poles";
		descriptionUse = "Pair of Aluminium Poles";
		model = "\breakingpoint\models\bp_woodenpoles.p3d";
		picture = "\breakingpoint\textures\icons\bp_woodenpoles_ca.paa";
		descriptionShort = "";
		mass = 10;
	};
	
	class ItemCementBag : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Bag of Cement";
		descriptionUse = "Bag of Cement";
		model = "\breakingpoint\models\bp_cementbag.p3d";
		picture = "\breakingpoint\textures\icons\bp_cementbag_ca.paa";
		descriptionShort = "";
		mass = 40;
	};

	class ItemSandBag : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Bag of Sand";
		descriptionUse = "Bag of Sand";
		model = "\breakingpoint\models\bp_sandbag.p3d";
		picture = "\breakingpoint\textures\icons\bp_sandbag_ca.paa";
		descriptionShort = "";
		mass = 40;
	};

	// Consumable Items
	class ItemWatercan : BP_Magazine {
		scope = 2;
		count = 10;
		type = 256;
		displayName = "Watercan";
		descriptionUse = "Watercan";
		model = "\breakingpoint\models\bp_watercan.p3d";
		picture = "\breakingpoint\textures\icons\bp_watercan_ca.paa";
		descriptionShort = "";
		mass = 25;
	};

	class ItemWatercanEmpty : BP_Magazine {
		scope = 2;
		count = 10;
		type = 256;
		displayName = "Watercan (Empty)";
		descriptionUse = "Watercan (Empty)";
		model = "\breakingpoint\models\bp_watercan.p3d";
		picture = "\breakingpoint\textures\icons\bp_watercan_empty_ca.paa";
		descriptionShort = "";
		mass = 25;
	};
	
	class ItemFuelcanLarge : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		fuelQuantity = 20;
		displayName = "Large Fuelcan";
		descriptionUse = "Large Fuelcan";
		model = "\breakingpoint\models\bp_fuelcan.p3d";
		picture = "\breakingpoint\textures\icons\bp_fuelcan_ca.paa";
		descriptionShort = "";
		mass = 65;
	};

	class ItemFuelcanLargeEmpty : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		fuelQuantity = 20;
		displayName = "Large Fuelcan (Empty)";
		descriptionUse = "Large Fuelcan (Empty)";
		model = "\breakingpoint\models\bp_fuelcan.p3d";
		picture = "\breakingpoint\textures\icons\bp_fuelcan_empty_ca.paa";
		descriptionShort = "";
		mass = 65;
	};

	class ItemFuelcan : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		fuelQuantity = 5;
		displayName = "Fuelcan";
		descriptionUse = "Fuelcan";
		model = "\breakingpoint\models\bp_fuelcan.p3d";
		picture = "\breakingpoint\textures\icons\bp_fuelcan_ca.paa";
		descriptionShort = "";
		mass = 20;
	};

	class ItemFuelcanEmpty : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		fuelQuantity = 5;
		displayName = "Fuelcan (Empty)";
		descriptionUse = "Fuelcan (Empty)";
		model = "\breakingpoint\models\bp_fuelcan.p3d";
		picture = "\breakingpoint\textures\icons\bp_fuelcan_empty_ca.paa";
		descriptionShort = "Can be filled at gas stations or siphoned vehicles.";
		mass = 20;
	};

	// Medical Items

	class ItemWool : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Wool";
		descriptionUse = "Wool";
		model = "\breakingpoint\models\bp_wool.p3d";
		picture = "\breakingpoint\textures\icons\wool_ca.paa";
		descriptionShort = "Used For: Building a bed inside a haven.";
		mass = 1;
	};

	class ItemFeathers : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Feathers";
		descriptionUse = "Feathers";
		model = "\breakingpoint\models\bp_feathers.p3d";
		picture = "\breakingpoint\textures\icons\bp_feathers_ca.paa";
		descriptionShort = "Used For: Building a bed inside a haven.";
		mass = 1;
	};

	class ItemFieldDressing : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Military Field Dressing";
		descriptionUse = "Military Field Dressing";
		model = "\breakingpoint\models\bp_fielddressing.p3d";
		picture = "\breakingpoint\textures\icons\bp_fielddressing_ca.paa";
		descriptionShort = "Used For: Treatment of more serious wounds.";
		mass = 1;
	};

	class ItemBandage : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Small Bandage";
		descriptionUse = "Small Bandage";
		model = "\breakingpoint\models\bp_bandage.p3d";
		picture = "\breakingpoint\textures\icons\bp_bandage_ca.paa";
		descriptionShort = "Used For: Treatment of minor injuries.";
		mass = 1;
	};
	
	class ItemMorphine : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Morphine Syringe";
		descriptionUse = "Morphine Syringe";
		model = "\breakingpoint\models\bp_morphine.p3d";
		picture = "\breakingpoint\textures\icons\bp_morphine_ca.paa";
		descriptionShort = "Used For: Treatment of limb damage and extreme pain.";
		mass = 2;
	};
	
	class ItemAdrenaline : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Synthetic Adrenaline Syringe";
		descriptionUse = "Synthetic Adrenaline Syringe";
		model = "\breakingpoint\models\bp_morphine.p3d";
		//model = "\breakingpoint\models\bp_adrenaline.p3d";
		picture = "\breakingpoint\textures\icons\bp_morphine_ca.paa";
		//picture = "\breakingpoint\textures\icons\bp_adrenaline_ca.paa";
		descriptionShort = "Used For: Temporary health restoration and pain relief.";
		mass = 2;
	};

	class ItemAntibiotic : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Antivirals";
		descriptionUse = "Antivirals";
		model = "\breakingpoint\models\bp_antibiotics.p3d";
		picture = "\breakingpoint\textures\icons\bp_antibiotics_ca.paa";
		descriptionShort = "Used For: Treatment of viral infections.";
		mass = 1;
	};
	
	class ItemPainkiller : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Painkillers";
		descriptionUse = "Painkillers";
		model = "\breakingpoint\models\bp_painkillers.p3d";
		picture = "\breakingpoint\textures\icons\bp_painkillers_ca.paa";
		descriptionShort = "Used For: Fast acting pain relief.";
		mass = 1;
	};
	
	/* Toolbelt */
	
	//class HandGrenade;	// External class reference

	class ItemKnife : HandGrenade {
		scope = 2;
		count = 1;
		type = 256;
		ammo = "BP_ThrowingKnife";
		displayName = "KA-BAR Combat Knife";
		descriptionUse = "KA-BAR Combat Knife";
		model = "\breakingpoint\models\bp_knife.p3d";
		picture = "\breakingpoint\textures\icons\bp_knife_ca.paa";
		initSpeed = 25;
		descriptionShort = "Standard USMC combat knife, can be thrown or used to gut animals/people";
		displayNameShort = "KA-BAR Knife";
		mass = 4;
	};
	
	class ItemInfectedNeedle : HandGrenade {
		scope = 2;
		count = 1;
		type = 256;
		ammo = "BP_InfectedNeedle";
		displayName = "Infected Needle";
		descriptionUse = "Infected Needle";
		model = "\breakingpoint\models\bp_morphine2.p3d";
		initSpeed = 25;
		picture = "\breakingpoint\textures\icons\bp_morphine2_ca.paa";
		descriptionShort = "Used For: Infecting your enemies.";
		displayNameShort = "Infected Needle";
		mass = 1;
	};

	class ItemMatchbox : BP_Magazine {
		scope = 2;
		count = 1;
		type = 16;
		displayName = "Matchbox";
		descriptionUse = "Matchbox";
		model = "\a3\structures_f_epa\Items\Tools\Matches_F.p3d";
		picture = "\breakingpoint\textures\icons\bp_matches_ca.paa";
		descriptionShort = "Box of waterproof matches, double click with Wood Pile to create a fireplace.";
		mass = 2;
	};

	// Construction and Part Items

	class ItemPunctureKit : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Tire Repair Kit";
		descriptionUse = "Tire Repair Kit";
		model = "\breakingpoint\models\bp_puncturekit.p3d";
		picture = "\breakingpoint\textures\icons\bp_puncturekit_ca.paa";
		descriptionShort = "";
		mass = 20;
	};

	class PartSteel : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Reinforced Steel";
		descriptionUse = "Reinforced Steel";
		model = "\breakingpoint\models\bp_safemetal.p3d";
		picture = "\breakingpoint\textures\icons\bp_safemetal_ca.paa";
		descriptionShort = "A mixture of steel materials that can be used to build various constructables.";
		mass = 25;
	};

	class PartPalette : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Small Wooden Palette";
		descriptionUse = "Small Wooden Palette";
		model = "\breakingpoint\models\bp_palette.p3d";
		picture = "\breakingpoint\textures\icons\bp_palette_ca.paa";
		descriptionShort = "Traditional wooden palette that can be used to build various storage containers.";
		mass = 30;
	};

	class PartWheel : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 6);
		displayName = "Worn Tire";
		descriptionUse = "Worn Tire";
		model = "\breakingpoint\models\bp_tire.p3d";
		picture = "\breakingpoint\textures\icons\bp_tire_ca.paa";
		//descriptionShort = $STR_EQUIP_DESC_9;
		mass = 101;
	};
	
	class ItemLubricant : BP_Magazine {
		scope = 2;
		count = 1;
		type = 16;
		displayName = "Hydraulic Fluid";
		descriptionUse = "Hydraulic Fluid";
		model = "\breakingpoint\models\bp_container1.p3d";
		picture = "\breakingpoint\textures\icons\bp_container1_ca.paa";
		descriptionShort = "";
		mass = 40;
	};

	class ItemLiquidResin : BP_Magazine {
		scope = 2;
		count = 1;
		type = 16;
		displayName = "Liquid Resin";
		descriptionUse = "Liquid Resin";
		model = "\breakingpoint\models\bp_container2.p3d";
		picture = "\breakingpoint\textures\icons\bp_container2_ca.paa";
		descriptionShort = "";
		mass = 25;
	};

	class PartEngine : BP_Magazine {
		scope = 2;
		count = 1;
		type = 16;
		displayName = "Starter Motor";
		descriptionUse = "Starter Motor";
		model = "\breakingpoint\models\bp_motor.p3d";
		picture = "\breakingpoint\textures\icons\bp_motor_ca.paa";
		descriptionShort = "";
		mass = 65;
	};

	class ItemFuelhoseKit : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Fuel Hose Kit";
		descriptionUse = "Fuel Hose Kit";
		model = "\breakingpoint\models\bp_fuelhose.p3d";
		picture = "\breakingpoint\textures\icons\bp_fuelhose_ca.paa";
		descriptionShort = "";
		mass = 30;
	};

	class ItemBattery : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Battery";
		descriptionUse = "Battery";
		model = "\breakingpoint\models\bp_battery.p3d";
		picture = "\breakingpoint\textures\icons\bp_battery_ca.paa";
		descriptionShort = "";
		mass = 30;
	};

	class ItemEngineCoolant : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Engine Coolant";
		descriptionUse = "Engine Coolant";
		model = "\breakingpoint\models\bp_container3.p3d";
		picture = "\breakingpoint\textures\icons\bp_container3_ca.paa";
		descriptionShort = "";
		mass = 10;
	};

	class ItemHydraulicCylinder : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Hydraulic Cylinder";
		descriptionUse = "Hydraulic Cylinder";
		model = "\breakingpoint\models\bp_hydraulic.p3d";
		picture = "\breakingpoint\textures\icons\bp_hydraulic_ca.paa";
		descriptionShort = "";
		mass = 65;
	};

	class PartGlass : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Toughened Glass Panel";
		descriptionUse = "Toughened Glass Panel";
		model = "\breakingpoint\models\bp_glass.p3d";
		picture = "\breakingpoint\textures\icons\bp_glass_ca.paa";
		descriptionShort = "";
		mass = 40;
	};

	class ItemElectronics : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Electronics Board";
		descriptionUse = "Eletronics Board";
		model = "\breakingpoint\models\bp_electronics.p3d";
		picture = "\breakingpoint\textures\icons\bp_electronics_ca.paa";
		descriptionShort = "";
		mass = 15;
	};
	
	class ItemElectricalWire: BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Electrical Wire";
		descriptionUse = "Electrical Wire";
		model = "\breakingpoint\models\bp_electricalwire.p3d";
		picture = "\breakingpoint\textures\icons\bp_electricalwire_ca.paa";
		descriptionShort = "";
		mass = 5;
	};
	
	class ItemStove: BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Electric Stove Top";
		descriptionUse = "Electric Stove Top";
		model = "\breakingpoint\models\bp_ovenItem.p3d";
		picture = "\breakingpoint\textures\icons\bp_stovetop_ca.paa";
		descriptionShort = "Allow boil water and cook meat in a Haven.";
		mass = 20;
	};

	class PartFiberGlass : BP_Magazine {
		scope = 2;
		count = 1;
		type = (256 * 2);
		displayName = "Fibreglass Panel";
		descriptionUse = "Fibreglass Panel";
		model = "\breakingpoint\models\bp_fiberglass.p3d";
		picture = "\breakingpoint\textures\icons\bp_fiberglass_ca.paa";
		descriptionShort = "";
		mass = 50;
	};

	class PartWoodPile : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Wood Pile";
		descriptionUse = "Wood Pile";
		model = "\breakingpoint\models\bp_wood.p3d";
		picture = "\breakingpoint\textures\icons\bp_wood_ca.paa";
		descriptionShort = "Small pile of wood, good for starting fires.";
		mass = 20;
	};
	
	class PartWool : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Sheeps Wool";
		descriptionUse = "Sheeps Wool";
		model = "\breakingpoint\models\bp_wool.p3d";
		picture = "\breakingpoint\textures\icons\wool_ca.paa";
		descriptionShort = "Sheeps wool used for Beds.";
		mass = 20;
	};
	
	class PartFeathers : BP_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Feathers";
		descriptionUse = "Feathers";
		model = "\breakingpoint\models\bp_feathers.p3d";
		picture = "\breakingpoint\textures\icons\bp_feathers_ca.paa";
		descriptionShort = "Feathers used for Beds";
		mass = 20;
	};

	class ItemHammer : HandGrenade {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Hammer";
		descriptionUse = "Hammer";
		displayNameShort = "Hammer";
		initSpeed = 25;
		ammo = "BP_HammerTime";
		model = "\breakingpoint\models\bp_hammer.p3d";
		picture = "\breakingpoint\textures\icons\bp_hammer_ca.paa";
		descriptionShort = "Old fashioned style hammer that can be used to build storage containers.";
		mass = 10;
	};
	
	class ItemNails : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Nails";
		descriptionUse = "Nails";
		descriptionShort = "High quality nails that can be used to hold together wooden pallets.";
		model = "\breakingpoint\models\bp_nails.p3d";
		picture = "\breakingpoint\textures\icons\bp_nails_ca.paa";
		mass = 10;
	};

	class ItemBlueprint : BP_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Blueprint Generic";
		descriptionUse = "Blueprint Generic";
		model = "\breakingpoint\models\bp_blueprint.p3d";
		picture = "\breakingpoint\textures\icons\bp_blueprint_ca.paa";
		descriptionShort = "A generic blueprint.";
		mass = 1;
	};
	
	/* House Objects */
	
	class BlueprintHaven : ItemBlueprint {
		displayName = "Blueprint Haven Locking Kit";
		descriptionUse = "Blueprint Haven Locking Kit";
		descriptionShort = "Allows for the creation of a Safe Haven Hideout. Can only be used inside lockable buildings.<br/>Requires- Hammer, 1x Hydraulic Cylinder, 1x Battery, 1x Reinforced Steel, 1x Electronics, 2x Electrical Wire.";
		class Construction {
			Object = "BP_Haven";  // Not a real object
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemHydraulicCylinder", "ItemBattery", "PartSteel", "ItemElectronics", "ItemElectricalWire", "ItemElectricalWire"};
		};
	};
	
	class BlueprintHavenReinforce : ItemBlueprint {
		displayName = "Blueprint Haven Reinforcement Kit";
		descriptionUse = "Blueprint Haven Reinforcement Kit";
		descriptionShort = "Allows for the reinforcement of a Safe Haven Hideout. Can only be used inside a unlocked haven. Haven can be upgraded multible times.<br/>Requires 1x Reinforced Steel, 4x Cement Bag";
		class Construction {
			Object = "BP_HavenReinforcement";  // Not a real object
			Tools[] = {};
			Materials[] = {"PartSteel", "ItemCementBag", "ItemCementBag", "ItemCementBag"};
		};
	};
	
	class BlueprintChest : ItemBlueprint {
		displayName = "Blueprint Haven Chest";
		descriptionUse = "Blueprint Haven Chest";
		descriptionShort = "Allows for the creation of a Safe Haven Storage Chest.<br/>Requires- Hammer, 3x Box of Nails, 3x Small Wooden Palette, 1x Steel.";
		class Construction {
			Object = "BP_Chest";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails", "ItemNails", "ItemNails", "PartSteel", "PartPalette", "PartPalette", "PartPalette"};
		};
	};
	
	class BlueprintIceBox : ItemBlueprint {
		displayName = "Blueprint Haven Refrigerator";
		descriptionUse = "Blueprint Haven Refrigerator";
		descriptionShort = "Allows for the creation of a Safe Haven Refrigerator.<br/>Requires- Hammer, 2x Fiberglass, 2x Reinforced Steel, 1x Battery.";
		class Construction {
			Object = "BP_Refrigerator";
			Tools[] = {"ItemHammer"};
			Materials[] = {"PartFiberGlass", "PartFiberGlass", "PartSteel", "PartSteel", "ItemBattery"};
		};
	};
	
	class BlueprintBed : ItemBlueprint {
		displayName = "Blueprint Haven Bed";
		descriptionUse = "Blueprint Haven Bed";
		descriptionShort = "Allows for the creation of a Safe Haven Bed.<br/>Requires- Hammer, 2x Feathers, 2x Wool.";
		class Construction {
			Object = "BP_Bed";
			Tools[] = {"ItemHammer"};
			Materials[] = {"PartFeathers", "PartFeathers", "PartWool", "PartWool"};
		};
	};
	
	class BlueprintGunCab : ItemBlueprint {
		displayName = "Blueprint Haven Gun Cabinet";
		descriptionUse = "Blueprint Haven Gun Cabinet";
		descriptionShort = "Allows for the creation of a Safe Haven Gun Cabinet.<br/>Requires- Hammer, 4x Box of Nails, 3x Reinforced Steel, 3x Fiberglass.";
		class Construction {
			Object = "BP_GunCabinet";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails", "ItemNails", "ItemNails", "ItemNails", "PartSteel", "PartSteel", "PartSteel", "PartFiberGlass", "PartFiberGlass","PartFiberGlass"};
		};
	};
	
	class BlueprintStove : ItemBlueprint {
		displayName = "Blueprint Haven Stove";
		descriptionUse = "Blueprint Haven Stove";
		descriptionShort = "Allows for the creation of a Safe Haven Oven.<br/>Requires- Hammer, 1x Stove Top, 2x Aluminium Poles, 1x Fiberglass, 1x Battery, 1x Electrical Wire.";
		class Construction {
			Object = "BP_Stove";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemStove", "ItemWoodenPoles", "ItemWoodenPoles", "PartFiberGlass", "ItemElectricalWire", "ItemBattery"};
		};
	};
	
	class BlueprintTele : ItemBlueprint {
		displayName = "Blueprint Haven Old Television";
		descriptionUse = "Blueprint Haven Old Television";
		descriptionShort = "Allows for the creation of a Old Television with Camera Secruity System.<br/>Requires- Hammer, 1x Box of Nails, 5x Electrical Wire, 3x Electronics Board, 2x Reinforced Steel.";
		class Construction {
			Object = "BP_Television";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails","ItemElectricalWire","ItemElectricalWire","ItemElectricalWire","ItemElectricalWire","ItemElectricalWire","ItemElectronics","ItemElectronics","ItemElectronics","PartSteel","PartSteel"};
		};
	};
	
	class BlueprintWaterBarrel : ItemBlueprint {
		displayName = "Blueprint Haven Water Barrel";
		descriptionUse = "Blueprint Haven Water Barrel";
		descriptionShort = "Allows for the creation of a water barrel for use in havens.<br/>Requires- Hammer, 1x Box of Nails, 1x Fiberglass, 2x Fuel Hose Kits, 2x Waterproof Tape.";
		class Construction {
			Object = "BP_BarrelWater";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails","PartFiberGlass","ItemFuelhoseKit","ItemFuelhoseKit","ItemWaterTape","ItemWaterTape"};
		};
	};
	
	class BlueprintFuelBarrel : ItemBlueprint {
		displayName = "Blueprint Haven Fuel Barrel";
		descriptionUse = "Blueprint Haven Fuel Barrel";
		descriptionShort = "Allows for the creation of a fuel barrel for use in havens.<br/>Requires- Hammer, 1x Box of Nails, 1x Fiberglass, 2x Fuel Hose Kits, 2x Waterproof Tape.";
		class Construction {
			Object = "BP_BarrelFuel";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails","PartFiberGlass","ItemFuelhoseKit","ItemFuelhoseKit","ItemWaterTape","ItemWaterTape"};
		};
	};

	/* End Of House Objects */
	
	class BlueprintCrate1 : ItemBlueprint {
		displayName = "Blueprint (Military Crate)";
		descriptionUse = "Blueprint (Military Crate)";
		descriptionShort = "Allows for the construction of a Storage Crate.<br/>Requires- Hammer, 2x Box of Nails and 3x Small Wooden Pallet.";
		class Construction {
			Object = "BP_Crate1";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails","ItemNails","PartPalette","PartPalette","PartPalette"};
		};
	};
	
	class BlueprintCache1 : ItemBlueprint {
		displayName = "Blueprint (Military Cache)";
		descriptionUse = "Blueprint (Military Cache)";
		descriptionShort = "Allows for the construction of a Storage Cache.<br/>Requires- Hammer, 4x Box of Nails, 5x Small Wooden Pallet and 2x Netting Material.";
		class Construction {
			Object = "BP_Cache1";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNails","ItemNails","ItemNails","ItemNails","PartPalette","PartPalette","PartPalette","PartPalette","PartPalette","ItemNettingMaterial","ItemNettingMaterial"};
		};
	};
	
	class BlueprintIED1 : ItemBlueprint {
		displayName = "Blueprint (IED Proximity)";
		descriptionUse = "Blueprint (IED Proximity)";
		descriptionShort = "Allows for the construction of an Improvised Explosive Device.<br/>Requires- Radio, 4x Hand Grenades, 2x Box of Nails, 1x Engine Coolant, 1x Electrical Wire.";
		class Construction {
			Object = "BP_IED1_Mag";
			Tools[] = {"ItemRadio"};
			Materials[] = {"HandGrenade","HandGrenade","HandGrenade","HandGrenade","ItemNails","ItemNails","ItemEngineCoolant","ItemElectricalWire"};
		};
	};

	class BlueprintCamoNet : ItemBlueprint {
		displayName = "Blueprint (Military Netting)";
		descriptionUse = "Blueprint (Military Netting)";
		descriptionShort = "Allows for the construction of Military Netting.<br/>Requires- Hammer, 4x Netting Material and 4x Pair of Aluminium Poles.";
		class Construction {
			Object = "BP_CamoNet";
			Tools[] = {"ItemHammer"};
			Materials[] = {"ItemNettingMaterial","ItemNettingMaterial","ItemNettingMaterial","ItemNettingMaterial","ItemWoodenPoles","ItemWoodenPoles","ItemWoodenPoles","ItemWoodenPoles"};
		};
	};

	class BlueprintSafe : ItemBlueprint {
		displayName = "Blueprint (Cast Iron Safe)";
		descriptionUse = "Blueprint (Cast Iron Safe)";
		descriptionShort = "Allows for the construction of a Cast Iron Safe.<br/>Requires- Blowtorch, 6x Reinforced Steel.";
		class Construction {
			Object = "BP_Safe";
			Tools[] = {"ItemBlowtorch"};
			Materials[] = {"PartSteel","PartSteel","PartSteel","PartSteel","PartSteel","PartSteel"};
		};
	};

	class BlueprintRockStash : ItemBlueprint {
		displayName = "Blueprint (Secret Stash)";
		descriptionUse = "Blueprint (Secret Stash)";
		descriptionShort = "Allows for the construction of a secret rock stash.<br/>Requires- Shovel, 3x Bag of Cement and 3x Bag of Sand.";
		class Construction {
			Object = "BP_RockStash";
			Weapons[] = {"MeleeShovel"};
			Materials[] = {"ItemSandBag","ItemSandBag","ItemSandBag","ItemCementBag","ItemCementBag","ItemCementBag"};
		};
	};
	
	// Trash Items
	class ItemTrashBase : HandGrenade {
		scope = 2;
		count = 1;
		initSpeed = 25;
		type = 256;
		mass = 3;
	};

	class ItemBook1 : ItemTrashBase {
		displayName = "BreakingPoint For Dummies";
		displayNameShort = "Book";
		descriptionShort = "Mostly for people who refuse to read.";
		descriptionUse = "(Instructional)";
		ammo = "BP_Book1";
		model = "\breakingpoint\models\bp_book1.p3d";
		picture = "\breakingpoint\textures\icons\bp_book1_ca.paa";
		mass = 5;
	};

	class ItemBook2 : ItemTrashBase {
		displayName = "The Necronomicon";
		displayNameShort = "Book";
		descriptionUse = "(Instructional)";
		ammo = "BP_Book2";
		model = "\breakingpoint\models\bp_book2.p3d";
		picture = "\breakingpoint\textures\icons\bp_book2_ca.paa";
		mass = 5;
	};

	class ItemBook3 : ItemTrashBase {
		displayName = "Fellowship of the Ring";
		displayNameShort = "Book";
		descriptionUse = "(Novel)";
		ammo = "BP_Book3";
		model = "\breakingpoint\models\bp_book3.p3d";
		picture = "\breakingpoint\textures\icons\bp_book3_ca.paa";
		mass = 5;
	};

	class ItemMug : ItemTrashBase {
		displayName = "Mug";
		displayNameShort = "Mug";
		descriptionUse = "Mug";
		ammo = "BP_Mug";
		model = "\breakingpoint\models\bp_mug.p3d";
		picture = "\breakingpoint\textures\icons\bp_mug_ca.paa";
		mass = 3;
	};	

	class ItemBrick1 : ItemTrashBase {
		displayName = "Brick";
		displayNameShort = "Brick";
		descriptionShort = "Potentially lethal if thrown accurately";
		ammo = "BP_Brick1";
		model = "\breakingpoint\models\bp_brick1.p3d";
		picture = "\breakingpoint\textures\icons\bp_brick1_ca.paa";
		mass = 15;
	};

	class ItemBrick2 : ItemTrashBase {
		displayName = "Brick";
		displayNameShort = "Brick";
		descriptionShort = "Potentially lethal if thrown accurately";
		ammo = "BP_Brick2";
		model = "\breakingpoint\models\bp_brick2.p3d";
		picture = "\breakingpoint\textures\icons\bp_brick2_ca.paa";
		mass = 15;
	};
	
	class ItemPottery : ItemTrashBase {
		displayName = "Pottery";
		displayNameShort = "Pottery";
		descriptionUse = "Pottery";
		ammo = "BP_Pottery";
		model = "\breakingpoint\models\bp_pottery.p3d";
		picture = "\breakingpoint\textures\icons\bp_pottery_ca.paa";
		mass = 4;
	};

	class ItemVideoTape : ItemTrashBase {
		displayName = "Video Tape";
		displayNameShort = "VHS Tape";
		descriptionUse = "Obsolete video format";
		ammo = "BP_Videotape";
		model = "\breakingpoint\models\bp_videotape.p3d";
		picture = "\breakingpoint\textures\icons\bp_videotape_ca.paa";
		mass = 1;
	};

	class ItemZipDisk : ItemTrashBase {
		displayName = "Zip Disk";
		displayNameShort = "Zip Disk";
		descriptionShort = "Obsolete Data storage";
		ammo = "BP_ZipDisk";
		model = "\breakingpoint\models\bp_zipdisk.p3d";
		picture = "\breakingpoint\textures\icons\bp_zipdisk_ca.paa";
		mass = 1;
	};

	class ItemTireRim : ItemTrashBase {
		displayName = "Tire Rim";
		descriptionUse = "Tire Rim";
		model = "\breakingpoint\models\bp_tirerim.p3d";
		picture = "\breakingpoint\textures\icons\bp_tirerim_ca.paa";
		descriptionShort = "Can be used to create an IED Bomb (Coming Soon).";
		mass = 50;
	};

	class ItemRock : ItemTrashBase {
		displayName = "Rock";
		displayNameShort = "Rock";
		descriptionUse = "Rock";
		ammo = "BP_Rock";
		model = "\breakingpoint\models\bp_rock.p3d";
		picture = "\breakingpoint\textures\icons\bp_rock_ca.paa";
		mass = 15;
	};

	class ItemPlate1 : ItemTrashBase {
		displayName = "Plate";
		displayNameShort = "Plate";
		descriptionUse = "Plate";
		ammo = "BP_Plate1";
		model = "\breakingpoint\models\bp_plate1.p3d";
		picture = "\breakingpoint\textures\icons\bp_plate1_ca.paa";
		mass = 4;
	};

	class ItemPlate2 : ItemTrashBase {
		displayName = "Plate";
		displayNameShort = "Plate";
		descriptionUse = "Plate";
		ammo = "BP_Plate2";
		model = "\breakingpoint\models\bp_plate2.p3d";
		picture = "\breakingpoint\textures\icons\bp_plate2_ca.paa";
		mass = 4;
	};

	class ItemCards : ItemTrashBase {
		displayName = "Cards";
		displayNameShort = "Cards";
		descriptionUse = "Cards";
		model = "\breakingpoint\models\bp_cards.p3d";
		picture = "\breakingpoint\textures\icons\bp_cards_ca.paa";
		mass = 1;
	};

	class ItemTennisBall : ItemTrashBase {
		displayName = "Tennis Ball";
		displayNameShort = "Tennis Ball";
		descriptionUse = "Unusually heavy for a tennis ball, seems to have been used as a weapon";
		model = "\breakingpoint\models\bp_tennisball.p3d";
		ammo = "BP_TennisBall";
		picture = "\breakingpoint\textures\icons\bp_tennisball_ca.paa";
		mass = 1;
	};
	
	class ItemToiletPaper : ItemTrashBase {
		displayName = "Toilet Paper";
		displayNameShort = "Toilet Paper";
		descriptionUse = "Toilet Paper";
		model = "\breakingpoint\models\bp_toiletpaper.p3d";
		picture = "\breakingpoint\textures\icons\bp_toiletpaper_ca.paa";
		mass = 2;
	};
	
	class ItemGlue : ItemTrashBase {
		displayName = "Glue";
		descriptionUse = "Glue";
		model = "\breakingpoint\models\bp_glue.p3d";
		picture = "\breakingpoint\textures\icons\bp_glue_ca.paa";
		mass = 2;
	};
	
	class ItemDuctTape : ItemTrashBase {
		displayName = "Duct Tape";
		descriptionUse = "Duct Tape";
		model = "\breakingpoint\models\bp_tape1.p3d";
		picture = "\breakingpoint\textures\icons\bp_tape1_ca.paa";
		mass = 3;
	};

	class ItemWaterTape : ItemTrashBase {
		displayName = "Waterproof Tape";
		descriptionUse = "Waterproof Tape";
		model = "\breakingpoint\models\bp_tape2.p3d";
		picture = "\breakingpoint\textures\icons\bp_tape2_ca.paa";
		mass = 3;
	};

	class ItemClipboard : ItemTrashBase {
		displayName = "Clipboard";
		descriptionUse = "Clipboard";
		model = "\breakingpoint\models\bp_clipboard.p3d";
		picture = "\breakingpoint\textures\icons\bp_clipboard_ca.paa";
		mass = 3;
	};

	class ItemCanEmpty : ItemTrashBase {
		displayName = "Can (Empty)";
		displayNameShort = "Can";
		descriptionUse = "Can (Empty)";
		ammo = "BP_EmptyCan";
		model = "\breakingpoint\models\bp_canempty.p3d";
		picture = "\breakingpoint\textures\icons\bp_canempty_ca.paa";
		mass = 3;
	};

	//Food: Meat

	class FoodMeatRaw : FoodEdible {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Meat (Raw)";
		model = "\breakingpoint\models\bp_meat.p3d";
		picture = "\breakingpoint\textures\icons\bp_meat_ca.paa";
		descriptionShort = "Can be cooked on a campfire.";
		bloodRegen = 100;
		mass = 10;
	};

	class FoodPlayerRaw : FoodMeatRaw {
		displayName = "Strange Raw Meat";
		descriptionShort = "";
		bloodRegen = 350;
		mass = 10;
	};

	class FoodZombieRaw : FoodMeatRaw {
		displayName = "Infected Raw Meat";
		descriptionShort = "";
		bloodRegen = 100;
		mass = 10;
	};

	class FoodMuttonRaw : FoodmeatRaw {
		displayName = "Mutton (Raw)";
		descriptionShort = "Can be cooked on a campfire.";
		bloodRegen = 100;
		mass = 10;
	};
	
	class FoodChickenRaw : FoodmeatRaw {
		displayName = "Chicken Leg (Raw)";
		descriptionShort = "Can be cooked on a campfire.";
		bloodRegen = 100;
		mass = 10;
	};
	
	class FoodRabbitRaw : FoodmeatRaw {
		displayName = "Rabbit (Raw)";
		descriptionShort = "Can be cooked on a campfire.";
		bloodRegen = 400;
		mass = 10;
	};
	
	class FoodBaconRaw : FoodmeatRaw {
		displayName = "Bacon (Raw)";
		descriptionShort = "";
		bloodRegen = 150;
		mass = 10;
	};
	class FoodBeefRaw : FoodmeatRaw {
		displayName = "Beef (Raw)";
		descriptionShort = "";
		bloodRegen = 100;
		mass = 10;
	};
	
	// Cooked Meat
	
	class FoodMeatCooked : FoodEdible {
		scope = public;
		count = 1;
		displayName = "Meat (Cooked)";
		model = "\breakingpoint\models\bp_meat_cooked.p3d";
		picture = "\breakingpoint\textures\icons\bp_meat_cooked_ca.paa";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};

	class FoodSteakCooked : FoodEdible {
		scope = public;
		count = 1;
		displayName = "Meat (Cooked)";
		model = "\breakingpoint\models\bp_meat_cooked.p3d";
		picture = "\breakingpoint\textures\icons\bp_meat_cooked_ca.paa";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};
	
	class FoodSteakRaw : FoodEdible {
		scope = public;
		count = 1;
		displayName = "Meat (Raw)";
		model = "\breakingpoint\models\bp_meat_cooked.p3d";
		picture = "\breakingpoint\textures\icons\bp_meat_cooked_ca.paa";
		descriptionShort = "";
		bloodRegen = 250;
		mass = 10;
	};

	class FoodPlayerCooked : FoodMeatCooked {
		displayName = "Strange Meat (Cooked)";
		descriptionShort = "";
		bloodRegen = 1250;
		mass = 10;
	};

	class FoodZombieCooked : FoodMeatCooked {
		displayName = "Infected Meat (Cooked)";
		descriptionShort = "";
		bloodRegen = 450;
		mass = 10;
	};

	class FoodMuttonCooked : FoodMeatCooked {
		displayName = "Mutton (Cooked)";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};
	
	class FoodChickenCooked : FoodMeatCooked {
		displayName = "Chicken Leg (Cooked)";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};
	
	class FoodBaconCooked : FoodMeatCooked {
		displayName = "Bacon (Cooked)";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};
	class FoodRabbitCooked : FoodMeatCooked {
		displayName = "Rabbit (Cooked)";
		descriptionShort = "";
		bloodRegen = 1600;
		mass = 10;
	};
	class FoodBeefCooked : FoodMeatCooked {
		displayName = "Beef (Cooked)";
		descriptionShort = "";
		bloodRegen = 1000;
		mass = 10;
	};

	class FoodPumpkin : FoodEdible {
		scope = public;
		count = 1;
		bloodRegen = 1000;
		displayName = "Pumpkin";
		descriptionShort = "";
		model = "\breakingpoint\models\bp_pumpkin.p3d";
		picture = "\breakingpoint\textures\icons\bp_pumpkin_ca.paa";
		mass = 10;
	};

	class FoodMushroom : FoodEdible {
		scope = public;
		count = 1;
		bloodRegen = 400;
		displayName = "Mushroom";
		descriptionShort = "";
		model = "\breakingpoint\models\bp_mushroom.p3d";
		picture = "\breakingpoint\textures\icons\bp_mushroom_ca.paa";
		mass = 3;
	};

	class FoodDrink : CA_Magazine {
		isWater = 1;
		count = 1;
		type = 256;
	};
	
	class Waterbot : FoodDrink {
		scope = 2;
		refillable = 1;
		sfx = "drink";
		displayName = "Canteen (Full)";
		descriptionShort = "Can be boiled on a campfire.";
		model = "\a3\structures_f_epa\Items\Food\Canteen_F.p3d";
		picture = "\breakingpoint\textures\icons\bp_waterbottle_ca.paa";
		mass = 5;
	};
	
	class WaterbotEmpty : CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Canteen (Empty)";
		model = "\a3\structures_f_epa\Items\Food\Canteen_F.p3d";
		picture = "\breakingpoint\textures\icons\bp_waterbottle_empty_ca.paa";
		descriptionShort = "";
		mass = 5;
	};

	class WaterbotBoiled : Waterbot {
		displayName = "Canteen (Boiled)";
		descriptionShort = "";
		mass = 5;
	 };
};