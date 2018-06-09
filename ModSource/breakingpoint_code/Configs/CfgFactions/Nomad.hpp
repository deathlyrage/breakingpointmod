/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Nomad : BP_BaseFaction 
	{
	    name = "Nomad";
		description = "Insert Epic Heroic Description Here";
		icon = "\breakingpoint_ui\icons\NomadIcon.paa";
		
		class Levels : Levels {
			class Level_Base : Level_Base {
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform : BP_BaseGear {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear {};
			};
			
			class Level_0 : Level_Base 
			{
				regenRateSitting = 15;
				class Spawn
				{
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_F"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform : BP_BaseGear {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear {};
			};
			
			class Level_1 : Level_Base {
				regenRateSitting = 20;
				class Spawn
				{
					//Array Of Toolbelt Items
					toolbelt[] = {"ItemMap"};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_1"};
					backpack[] = {"BP_AssaultPack_blk"};
					vest[] = {};
				};
				class Uniform : BP_BaseGear {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {"ItemBandage","ItemBandage"};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear {
					//Array Of Weapons Inside Backpack
					weapons[] = {};
					//Array Of Magazines Inside Backpack
					magazines[] = {"ItemPainkiller","ItemPainkiller"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
			};
			class Level_2 : Level_Base {
				regenRateSitting = 25;
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {"ItemMap"};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_2"};
					backpack[] = {"BP_Kitbag_sgg"};
					vest[] = {};
				};
				class Uniform : BP_BaseGear {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {"ItemBandage","ItemBandage"};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear  {
					//Array Of Weapons Inside Backpack
					weapons[] = {};
					//Array Of Magazines Inside Backpack
					magazines[] = {"ItemPainkiller","ItemPainkiller","ItemKnife","ItemFieldDressing"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
			};
			class Level_3 : Level_Base {
				regenRateSitting = 30;
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {"ItemMap"};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_3"};
					backpack[] = {"BP_Hpack"};
					vest[] = {};
				};
				class Uniform : BP_BaseGear  {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {"ItemBandage","ItemBandage"};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear 
				{
					//Array Of Weapons Inside Backpack
					weapons[] = {"BP_CZ455"};
					//Array Of Magazines Inside Backpack
					magazines[] = {"ItemPainkiller","ItemPainkiller","BP_MRT","BP_5Rnd_22_Mag","BP_5Rnd_22_Mag","BP_5Rnd_22_Mag","ItemAntibiotic","ItemDuctTape","ItemKnife","PartWoodPile"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {"Binocular"};
				};
			};
		};
		
		class Points
		{
			base = 0;
			min = -3000;
			max = 6000;
			//Dont Include Level 0 ( Evil ) It's auto detected if < base value.
			levels[] = {0,2000,5000};
			class Aid {
				class Ranger {
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -1000;
				};
				class Nomad {
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -2000;
				};
				class Survivalist {
					food = 25;
					drink = 25;
					bandage = 35;
					dressing = 40;
					morphine = 40;
					surgery = 50;
					gut = -500;
				};
				class Outlaw {
					food = 5;
					drink = 5;
					bandage = 5;
					dressing = 5;
					morphine = 5;
					surgery = 10;
					gut = 100;
				};
				class Hunter {
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 100;
				};
			};
			class Destroy {
				class None {
					vehicle = 50;
					storage = 50;
				};
				class Ranger {
					vehicle = 0;
					storage = 0;
				};
				class Nomad {
					vehicle = 0;
					storage = 0;
				};
				class Survivalist {
					vehicle = 0;
					storage = 0;
				};
				class Outlaw {
					vehicle = 100;
					storage = 50;
				};
				class Hunter {
					vehicle = 100;
					storage = 50;
				};
			};
			class Hunt
			{
				//Animal Classname = Points Gained / Lost
				class Kill
				{
					BP_Chicken = 0;
					BP_Sheep = 0;
					BP_Dog = 0;
					BP_Dog_Ranger = 0;
					BP_Dog_Nomad = 0;
					BP_Dog_Hunter = 0;
					BP_Dog_Outlaw = 0;
					BP_Dog_Survivalist = 0;
				};
				
				class Gut
				{
					BP_Chicken = 0;
					BP_Sheep = 0;
					BP_Dog = 0;
					BP_Dog_Ranger = 0;
					BP_Dog_Nomad = 0;
					BP_Dog_Hunter = 0;
					BP_Dog_Outlaw = 0;
					BP_Dog_Survivalist = 0;
				};
			};
			class Kill {
				class Ranger {
					Level_0 = 250;
					Level_1 = -500;
					Level_2 = -1500;
					Level_3 = -3000;
				};
				class Outlaw {
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
				class Hunter {
					Level_0 = 100;
					Level_1 = 100;
					Level_2 = 200;
					Level_3 = 500;
				};
				class Nomad {
					Level_0 = 500;
					Level_1 = -1500;
					Level_2 = -2500;
					Level_3 = -4000;
				};
				class Survivalist {
					Level_0 = 100;
					Level_1 = -500;
					Level_2 = -1000;
					Level_3 = -2500;
				};
			};
		};
	};