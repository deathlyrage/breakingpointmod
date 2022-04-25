/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Nomad: BP_BaseFaction
	{
		name = "Nomad";
		description = "Insert Epic Heroic Description Here";
		icon = "\breakingpoint_ui\icons\NomadIcon.paa";
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
				regenRateSitting = 15;
				class Spawn
				{
					toolbelt[] = {};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_F"};
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
				regenRateSitting = 20;
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_1"};
					backpack[] = {"BP_AssaultPack_blk"};
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
					magazines[] = {"ItemPainkiller","ItemPainkiller"};
					items[] = {};
				};
			};
			class Level_2: Level_Base
			{
				regenRateSitting = 25;
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_2"};
					backpack[] = {"BP_Kitbag_sgg"};
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
					magazines[] = {"ItemPainkiller","ItemPainkiller","ItemKnife","ItemFieldDressing"};
					items[] = {};
				};
			};
			class Level_3: Level_Base
			{
				regenRateSitting = 30;
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Refugee_3"};
					backpack[] = {"BP_Hpack"};
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
					weapons[] = {"BP_CZ455"};
					magazines[] = {"ItemPainkiller","ItemPainkiller","BP_MRT","BP_5Rnd_22_Mag","BP_5Rnd_22_Mag","BP_5Rnd_22_Mag","ItemAntibiotic","ItemDuctTape","ItemKnife","PartWoodPile"};
					items[] = {"Binocular"};
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
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -1000;
				};
				class Nomad
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 25;
					surgery = 50;
					gut = -2000;
				};
				class Survivalist
				{
					food = 25;
					drink = 25;
					bandage = 35;
					dressing = 40;
					morphine = 40;
					surgery = 50;
					gut = -500;
				};
				class Outlaw
				{
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 100;
				};
				class Hunter
				{
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 100;
				};
				class Engineer
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 20;
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
				class Undead
				{
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 100;
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
					vehicle = 0;
					storage = 0;
				};
				class Nomad
				{
					vehicle = 0;
					storage = 0;
				};
				class Survivalist
				{
					vehicle = 0;
					storage = 0;
				};
				class Outlaw
				{
					vehicle = 100;
					storage = 50;
				};
				class Hunter
				{
					vehicle = 100;
					storage = 50;
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
					Level_0 = 250;
					Level_1 = -500;
					Level_2 = -1500;
					Level_3 = -3000;
				};
				class Outlaw
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 100;
					Level_3 = 200;
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
					Level_0 = 500;
					Level_1 = -1500;
					Level_2 = -2500;
					Level_3 = -4000;
				};
				class Survivalist
				{
					Level_0 = 100;
					Level_1 = -500;
					Level_2 = -1000;
					Level_3 = -2500;
				};
				class Engineer
				{
					Level_0 = 50;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
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
