/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

class Ranger : BP_BaseFaction 
{
	name = "Ranger";
	icon = "\breakingpoint_ui\icons\RangerIcon.paa";
	
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
			class Spawn
			{
				//Array Of Toolbelt Items
				toolbelt[] = {};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {};
				clothing[] = {"BP_Guardian_F"};
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
			class Spawn
			{
				//Array Of Toolbelt Items
				toolbelt[] = {"ItemCompass"};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {};
				clothing[] = {"BP_Guardian_1"};
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
			class Spawn {
				//Array Of Toolbelt Items
				toolbelt[] = {"ItemCompass"};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {};
				clothing[] = {"BP_Guardian_2"};
				backpack[] = {"BP_FieldPack_blk"};
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
				magazines[] = {"ItemPainkiller","ItemPainkiller","ItemMorphine","ItemFieldDressing"};
				//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
				items[] = {};
			};
		};
		class Level_3 : Level_Base {
			class Spawn {
				//Array Of Toolbelt Items
				toolbelt[] = {"ItemCompass"};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {"BP_1911"};
				clothing[] = {"BP_Guardian_3"};
				backpack[] = {"BP_Mpack"};
				vest[] = {};
			};
			class Uniform : BP_BaseGear  {
				//Array Of Weapons Inside Uniform
				weapons[] = {};
				//Array Of Magazines Inside Uniform
				magazines[] = {"BP_7Rnd_45acp","BP_7Rnd_45acp"};
				//Array Of Items Inside Uniform ( Add to Spawn Toolbelt If they should be assigned )
				items[] = {};
			};
			class Vest : BP_BaseGear {};
			class Backpack : BP_BaseGear 
			{
				//Array Of Weapons Inside Backpack
				weapons[] = {};
				//Array Of Magazines Inside Backpack
				magazines[] = {};
				//Array Of Items Inside Backpack ( Add to Spawn Toolbelt If they should be assigned )
				items[] = {};
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
				dressing = 10;
				morphine = 25;
				surgery = 50;
				gut = -3000;
			};
			class Nomad {
				food = 10;
				drink = 10;
				bandage = 10;
				dressing = 10;
				morphine = 25;
				surgery = 50;
				gut = -1000;
			};
			class Survivalist {
				food = 15;
				drink = 15;
				bandage = 15;
				dressing = 20;
				morphine = 35;
				surgery = 50;
				gut = -1000;
			};
			class Outlaw {
				food = 0;
				drink = 0;
				bandage = 0;
				dressing = -5;
				morphine = -10;
				surgery = -25;
				gut = 0;
			};
			class Hunter {
				food = -5;
				drink = -5;
				bandage = -5;
				dressing = -10;
				morphine = -25;
				surgery = -50;
				gut = 0;
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
				BP_Dog_Ranger = -250;
				BP_Dog_Nomad = 0;
				BP_Dog_Hunter = 25;
				BP_Dog_Outlaw = 0;
				BP_Dog_Survivalist = 0;
			};
			
			class Gut
			{
				BP_Chicken = 0;
				BP_Sheep = 0;
				BP_Dog = 0;
				BP_Dog_Ranger = -250;
				BP_Dog_Nomad = 0;
				BP_Dog_Hunter = 5;
				BP_Dog_Outlaw = 0;
				BP_Dog_Survivalist = 0;
			};
		};
		class Kill {
			class Ranger {
				Level_0 = 500;
				Level_1 = -1000;
				Level_2 = -2000;
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
				Level_0 = 100;
				Level_1 = -500;
				Level_2 = -1000;
				Level_3 = -2500;
			};
			class Survivalist {
				Level_0 = 100;
				Level_1 = -500;
				Level_2 = -1000;
				Level_3 = -2000;
			};
		};
	};
};