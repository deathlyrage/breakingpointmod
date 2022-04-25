/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Outlaw: BP_BaseFaction
	{
		name = "Outlaw";
		icon = "\breakingpoint_ui\icons\OutlawIcon.paa";
		class Levels: Levels
		{
			class Level_Base: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear{};
			};
			class Level_0: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_F"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear{};
			};
			class Level_1: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_1"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemBandage"};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemPainkiller","ItemMatchbox"};
					items[] = {};
				};
			};
			class Level_2: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_2"};
					backpack[] = {"BP_Rpack"};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemBandage"};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemPainkiller","ItemMatchbox"};
					items[] = {};
				};
			};
			class Level_3: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Rebel_3"};
					backpack[] = {"BP_Rpack2"};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemBandage","ItemFieldDressing","BlueprintIED1"};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"HandGrenade","ItemMatchbox"};
					items[] = {};
				};
			};
		};
		class Points
		{
			base = 0;
			min = -3000;
			max = 6000;
			levels[] = {0,2000,5000};
			class Aid
			{
				class Ranger
				{
					food = -10;
					drink = -10;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 50;
				};
				class Nomad
				{
					food = -10;
					drink = -10;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 50;
				};
				class Survivalist
				{
					food = -10;
					drink = -10;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 50;
				};
				class Outlaw
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -500;
				};
				class Hunter
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 50;
				};
				class Engineer
				{
					food = -20;
					drink = -20;
					bandage = -20;
					dressing = -25;
					morphine = -30;
					surgery = -50;
					gut = 300;
				};
				class Undead
				{
					food = -10;
					drink = -10;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 50;
				};
			};
			class Destroy
			{
				class None
				{
					vehicle = 50;
					storage = 50;
				};
				class Ranger
				{
					vehicle = 250;
					storage = 100;
				};
				class Nomad
				{
					vehicle = 250;
					storage = 100;
				};
				class Survivalist
				{
					vehicle = 250;
					storage = 250;
				};
				class Outlaw
				{
					vehicle = 0;
					storage = 0;
				};
				class Hunter
				{
					vehicle = 250;
					storage = 100;
				};
				class Engineer
				{
					vehicle = 0;
					storage = 0;
				};
				class Undead
				{
					vehicle = 0;
					storage = 0;
				};
			};
			class Hunt
			{
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
			class Kill
			{
				class Ranger
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
				class Outlaw
				{
					Level_0 = 200;
					Level_1 = -200;
					Level_2 = -500;
					Level_3 = -1000;
				};
				class Hunter
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
				class Nomad
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
				class Survivalist
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
				class Engineer
				{
					Level_0 = 100;
					Level_1 = 150;
					Level_2 = 200;
					Level_3 = 300;
				};
				class Undead
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
				};
			};
		};
	};
