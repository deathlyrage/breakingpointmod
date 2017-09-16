/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/
	class Outlaw : BP_BaseFaction 
	{
		name = "Outlaw";
		icon = "\breakingpoint_ui\icons\OutlawIcon.paa";
		
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
			
			class Level_0 : Level_Base {
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_F"};
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
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_1"};
					backpack[] = {};
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
				class Backpack : BP_BaseGear {
					//Array Of Weapons Inside Backpack
					weapons[] = {};
					//Array Of Magazines Inside Backpack
					magazines[] = {"ItemPainkiller", "ItemMatchbox"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
			};
			class Level_2 : Level_Base {
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_2"};
					backpack[] = {"BP_Rpack"};
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
				class Backpack : BP_BaseGear 
				{
					//Array Of Weapons Inside Backpack
					weapons[] = {};
					//Array Of Magazines Inside Backpack
					magazines[] = {"ItemPainkiller","ItemMatchbox"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
			};
			class Level_3 : Level_Base {
				class Spawn {
					//Array Of Toolbelt Items
					toolbelt[] = {};
					//Array Of Random (Clothing,Backpack,Vest)
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_3"};
					backpack[] = {"BP_Rpack2"};
					vest[] = {};
				};
				class Uniform : BP_BaseGear  {
					//Array Of Weapons Inside Uniform
					weapons[] = {};
					//Array Of Magazines Inside Uniform
					magazines[] = {"ItemBandage","ItemBandage","ItemFieldDressing","BlueprintIED1"};
					//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear {
					//Array Of Weapons Inside Backpack
					weapons[] = {};
					//Array Of Magazines Inside Backpack
					magazines[] = {"HandGrenade","ItemMatchbox"};
					//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
					items[] = {};
				};
			};
		};
		
		class Points {
			base = 0;
			min = -3000;
			max = 6000;
			//Dont Include Level 0 ( Evil ) It's auto detected if < base value.
			levels[] = {0,2000,5000};
			class Aid
			{
				class Ranger {
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = -25;
					gut = 50;
				};
				class Nomad {
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = -25;
					gut = 10;
				};
				class Survivalist {
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = -25;
					gut = 10;
				};
				class Outlaw {
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -500;
				};
				class Hunter {
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 50;
				};
			};
			class Destroy {
				class None {
					vehicle = 50;
					storage = 50;
				};
				class Ranger {
					vehicle = 250;
					storage = 100;
				};
				class Nomad {
					vehicle = 250;
					storage = 100;
				};
				class Survivalist {
					vehicle = 250;
					storage = 250;
				};
				class Outlaw {
					vehicle = 0;
					storage = 0;
				};
				class Hunter {
					vehicle = 250;
					storage = 100;
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
					Level_0 = 100;
					Level_1 = 100;
					Level_2 = 100;
					Level_3 = 250;
				};
				class Outlaw {
					Level_0 = 200;
					Level_1 = -200;
					Level_2 = -500;
					Level_3 = -1000;
				};
				class Hunter {
					Level_0 = 100;
					Level_1 = 100;
					Level_2 = 100;
					Level_3 = 250;
				};
				class Nomad {
					Level_0 = 100;
					Level_1 = 100;
					Level_2 = 100;
					Level_3 = 250;
				};
				class Survivalist {
					Level_0 = 100;
					Level_1 = 100;
					Level_2 = 100;
					Level_3 = 250;
				};
			};
		};
	};