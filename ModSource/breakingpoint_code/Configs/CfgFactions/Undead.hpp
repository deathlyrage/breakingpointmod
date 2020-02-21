/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

	class Undead: BP_BaseFaction
	{
		name = "Engineer";
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
					clothing[] = {"BP_Guardian_F"};
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
					toolbelt[] = {};
					primary[] = {};
					launcher[] = {};
					handgun[] = {};
					clothing[] = {"BP_Undead_1"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemKnife"};
					items[] = {};
				};
				class Vest: BP_BaseGear{};
				class Backpack: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {};
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
					clothing[] = {"BP_Undead_2"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemKnife"};
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
					magazines[] = {};
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
					clothing[] = {"BP_Undead_3"};
					backpack[] = {};
					vest[] = {};
				};
				class Uniform: BP_BaseGear
				{
					weapons[] = {};
					magazines[] = {"ItemKnife"};
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
					magazines[] = {};
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
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 00;
					gut = 100;
				};
				class Nomad
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 100;
				};
				class Survivalist
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 100;
				};
				class Outlaw
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 100;
				};
				class Hunter
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 100;
				};
				class Engineer
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
					gut = 100;
				};
				class Undead
				{
					food = 0;
					drink = 0;
					bandage = 0;
					dressing = 0;
					morphine = 0;
					surgery = 0;
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
					vehicle = 50;
					storage = 50;
				};
				class Nomad
				{
					vehicle = 50;
					storage = 50;
				};
				class Survivalist
				{
					vehicle = 50;
					storage = 50;
				};
				class Outlaw
				{
					vehicle = 50;
					storage = 50;
				};
				class Hunter
				{
					vehicle = 50;
					storage = 50;
				};
				class Engineer
				{
					vehicle = 50;
					storage = 50;
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
					Level_2 = 75;
					Level_3 = 100;
				};
				class Outlaw
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 75;
					Level_3 = 100;
				};
				class Hunter
				{
					Level_0 = 0;
					Level_1 = 50;
					Level_2 = 75;
					Level_3 = 100;
				};
				class Nomad
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 75;
					Level_3 = 100;
				};
				class Survivalist
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 75;
					Level_3 = 100;
				};
				class Engineer
				{
					Level_0 = 100;
					Level_1 = 50;
					Level_2 = 75;
					Level_3 = 100;
				};
				class Undead
				{
					Level_0 = 0;
					Level_1 = 0;
					Level_2 = 0;
					Level_3 = 0;
				};
			};
		};
	};

