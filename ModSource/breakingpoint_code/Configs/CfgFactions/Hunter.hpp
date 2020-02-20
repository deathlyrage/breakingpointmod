/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Hunter: BP_BaseFaction
	{
		name = "Hunter";
		icon = "\breakingpoint_ui\icons\HunterIcon.paa";
		class Levels: Levels
		{
			class Level_Base: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
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
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Hunter_1"};
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
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Hunter_1"};
					backpack[] = {"BP_AssaultPack_khk"};
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
					magazines[] = {"ItemPainkiller","ItemKnife"};
					items[] = {};
				};
			};
			class Level_2: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Hunter_2"};
					backpack[] = {"BP_AssaultPack_sgg"};
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
					magazines[] = {"ItemPainkiller","ItemKnife"};
					items[] = {};
				};
			};
			class Level_3: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHatchet"};
					handgun[] = {};
					clothing[] = {"BP_Hunter_3"};
					backpack[] = {"BP_AssaultPack_mcamo"};
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
					magazines[] = {"ItemPainkiller","ItemKnife","ItemInfectedNeedle","ItemInfectedNeedle","ItemInfectedNeedle","ItemInfectedNeedle","ItemInfectedNeedle"};
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
					food = 0;
					drink = 0;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 500;
				};
				class Nomad
				{
					food = 0;
					drink = 0;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -25;
					gut = 250;
				};
				class Survivalist
				{
					food = 0;
					drink = 0;
					bandage = -10;
					dressing = -15;
					morphine = -15;
					surgery = -50;
					gut = 250;
				};
				class Outlaw
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 250;
				};
				class Hunter
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 250;
				};
				class Engineer
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 250;
				};
				class Undead
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 0;
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
					vehicle = 500;
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
					storage = 100;
				};
				class Outlaw
				{
					vehicle = 250;
					storage = 100;
				};
				class Hunter
				{
					vehicle = 250;
					storage = 250;
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
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 50;
					Level_3 = 50;
				};
				class Outlaw
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 50;
					Level_3 = 50;
				};
				class Hunter
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 50;
					Level_3 = 100;
				};
				class Nomad
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 50;
					Level_3 = 50;
				};
				class Survivalist
				{
					Level_0 = 50;
					Level_1 = 50;
					Level_2 = 50;
					Level_3 = 50;
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
					Level_2 = 50;
					Level_3 = 50;
				};
			};
		};
	};
