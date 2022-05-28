/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Engineer: BP_BaseFaction
	{
		name = "Engineer";
		icon = "\breakingpoint_ui\icons\EngineerIcon.paa";
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
					clothing[] = {"BP_Engineer_F"};
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
					launcher[] = {"MeleeCrowbar"};
					handgun[] = {};
					clothing[] = {"BP_Engineer_1"};
					backpack[] = {"BP_AssaultPack_blk"};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage"};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemPainkiller"};
					items[] = {};
				};
			};
			class Level_2: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemToolbox","ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHammer"};
					handgun[] = {};
					clothing[] = {"BP_Engineer_2"};
					backpack[] = {"BP_Kitbag_sgg"};
					vest[] = {"V_BandollierB_oli_BP"};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemFieldDressing"};
					items[] = {};
				};
				class Vest: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemKnife"};
					items[] = {};
				};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemPainkiller","ItemAntibiotic"};
					items[] = {};
				};
			};
			class Level_3: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemToolbox","ItemMap"};
					primary[] = {};
					launcher[] = {"MeleeHammer2"};
					handgun[] = {};
					clothing[] = {"BP_Engineer_3"};
					backpack[] = {"BP_Bergen_rgr"};
					vest[] = {"V_BandollierB_oli_BP"};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemFieldDressing"};
					items[] = {};
				};
				class Vest: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemAdrenaline"};
					items[] = {};
				};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemAntibiotic","ItemDuctTape","ItemKnife","ItemMorphine","BlueprintCache1","BlueprintRockStash"};
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
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
				class Nomad
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
				class Survivalist
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
				class Outlaw
				{
					food = -10;
					drink = -10;
					bandage = -20;
					dressing = -25;
					morphine = -25;
					surgery = -50;
					gut = 300;
				};
				class Hunter
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
				class Engineer
				{
					food = 20;
					drink = 20;
					bandage = 20;
					dressing = 30;
					morphine = 30;
					surgery = 75;
					gut = 0;
				};
				class Undead
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 15;
					morphine = 20;
					surgery = 50;
					gut = 0;
				};
			};
			class Destroy
			{
				class None
				{
					vehicle = 0;
					storage = 0;
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
					vehicle = 50;
					storage = 50;
				};
				class Hunter
				{
					vehicle = 0;
					storage = 0;
				};
				class Engineer
				{
					vehicle = -100;
					storage = -100;
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
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
				class Outlaw
				{
					Level_0 = 50;
					Level_1 = 150;
					Level_2 = 200;
					Level_3 = 300;
				};
				class Hunter
				{
					Level_0 = 0;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
				class Nomad
				{
					Level_0 = 50;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
				class Survivalist
				{
					Level_0 = 50;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
				class Engineer
				{
					Level_0 = 100;
					Level_1 = -500;
					Level_2 = -1000;
					Level_3 = -2000;
				};
				class Undead
				{
					Level_0 = 50;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
			};
		};
	};
