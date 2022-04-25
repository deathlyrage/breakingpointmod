/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Survivalist: BP_BaseFaction
	{
		name = "Survivalist";
		description = "Insert Epic Heroic Description Here";
		icon = "\breakingpoint_ui\icons\SurvivalistIcon.paa";
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
					clothing[] = {"BP_Survivalist_F"};
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
					clothing[] = {"BP_Survivalist_1"};
					backpack[] = {"BP_AssaultPack_grs"};
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
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {};
					launcher[] = {};
					handgun[] = {"BP_TranQPistol"};
					clothing[] = {"BP_Survivalist_2"};
					backpack[] = {"BP_Kitbag_drt"};
					vest[] = {"V_VPack_BP"};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemBandage"};
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
					magazines[] = {"ItemPainkiller","ItemPainkiller","ItemFieldDressing","BP_15Rnd_9x21_Rubber"};
					items[] = {};
				};
			};
			class Level_3: Level_Base
			{
				class Spawn
				{
					toolbelt[] = {"ItemMap"};
					primary[] = {"BP_TranQRifle"};
					launcher[] = {};
					handgun[] = {"BP_TranQPistol"};
					clothing[] = {"BP_Survivalist_3"};
					backpack[] = {"BP_Kitbag_grs"};
					vest[] = {"V_CPack_BP"};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemBandage","ItemBandage"};
					items[] = {};
				};
				class Vest: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {};
					items[] = {};
				};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemAntibiotic","ItemDuctTape","ItemKnife","BP_10Rnd_762Rubber_Mag","BP_10Rnd_762Rubber_Mag","BP_10Rnd_762Rubber_Mag","BP_15Rnd_9x21_Rubber"};
					items[] = {"Binocular","BP_SOS"};
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
					dressing = 25;
					morphine = 25;
					surgery = 50;
					gut = -2000;
				};
				class Nomad
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 25;
					morphine = 25;
					surgery = 50;
					gut = -2000;
				};
				class Survivalist
				{
					food = 25;
					drink = 25;
					bandage = 10;
					dressing = 25;
					morphine = 25;
					surgery = 75;
					gut = -5000;
				};
				class Outlaw
				{
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 0;
				};
				class Hunter
				{
					food = -5;
					drink = -5;
					bandage = -5;
					dressing = -10;
					morphine = -25;
					surgery = -50;
					gut = 0;
				};
				class Engineer
				{
					food = 10;
					drink = 10;
					bandage = 10;
					dressing = 25;
					morphine = 25;
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
					vehicle = 0;
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
					Level_0 = 50;
					Level_1 = -1000;
					Level_2 = -2000;
					Level_3 = -3000;
				};
				class Outlaw
				{
					Level_0 = 50;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
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
					Level_1 = -1000;
					Level_2 = -2000;
					Level_3 = -3000;
				};
				class Survivalist
				{
					Level_0 = 50;
					Level_1 = -1000;
					Level_2 = -2000;
					Level_3 = -4000;
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
					Level_2 = 75;
					Level_3 = 100;
				};
			};
		};
	};
