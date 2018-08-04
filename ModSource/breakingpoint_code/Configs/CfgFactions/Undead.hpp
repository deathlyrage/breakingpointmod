/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

class Undead : BP_BaseFaction
{
	name = "Undead";
		
	class Levels : Levels
	{
		class Level_Base : Level_Base 
		{
			class Spawn 
			{
				//Array Of Toolbelt Items
				toolbelt[] = {};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {};
				clothing[] = 
				{
					"BP_Refugee_1_Z",
					"BP_Guardian_1_Z",
					"BP_Rebel_1_Z",
					"BP_Hunter_1_Z",
					"BP_Survivalist_1_Z"/*,
					"BP_Engineer_1_Z"*/
				};
				backpack[] = {};
				vest[] = {};
			};
			class Uniform : BP_BaseGear 
			{
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
			maxHealth = 21000;
			regenRate = 60;
			class Spawn : Spawn
			{
				clothing[] = 
				{
					"BP_Refugee_F_Z",
					"BP_Guardian_F_Z",
					"BP_Rebel_F_Z",
					"BP_Hunter_F_Z",
					"BP_Survivalist_F_Z"/*,
					"BP_Engineer_F_Z"*/
				};
			};
		};
		
		class Level_1 : Level_Base 
		{
			maxHealth = 21000;
			regenRate = 60;
			class Spawn : Spawn
			{
				clothing[] = 
				{
					"BP_Refugee_1_Z",
					"BP_Guardian_1_Z",
					"BP_Rebel_1_Z",
					"BP_Hunter_1_Z",
					"BP_Survivalist_1_Z"/*,
					"BP_Engineer_1_Z"*/
				};
			};
		};
		
		class Level_2 : Level_Base 
		{
			maxHealth = 36000;
			regenRate = 90;
			class Spawn : Spawn
			{
				clothing[] = 
				{
					"BP_Refugee_2_Z",
					"BP_Guardian_2_Z",
					"BP_Rebel_2_Z",
					"BP_Hunter_2_Z",
					"BP_Survivalist_2_Z"/*,
					"BP_Engineer_2_Z"*/
				};
			};
		};
		
		class Level_3 : Level_Base 
		{
			maxHealth = 48000;
			regenRate = 120;
			class Spawn : Spawn
			{
				clothing[] = 
				{
					"BP_Refugee_3_Z",
					"BP_Guardian_3_Z",
					"BP_Rebel_3_Z",
					"BP_Hunter_3_Z",
					"BP_Survivalist_3_Z"/*,
					"BP_Engineer_3_Z"*/
				};
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
			class Ranger 
			{
				food = 10;
				drink = 10;
				bandage = 10;
				dressing = 25;
				morphine = 25;
				surgery = 50;
				gut = 0;
			};
			class Nomad 
			{
				food = 10;
				drink = 10;
				bandage = 10;
				dressing = 25;
				morphine = 25;
				surgery = 50;
				gut = 0;
			};
			class Survivalist 
			{
				food = 25;
				drink = 25;
				bandage = 10;
				dressing = 25;
				morphine = 25;
				surgery = 75;
				gut = 0;
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
				vehicle = 0;
				storage = 50;
			};
			class Hunter {
				vehicle = 100;
				storage = 50;
			};
			class Engineer {
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
				BP_Dog_Engineer = 0;
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
				BP_Dog_Engineer = 0;
			};
		};
		class Kill {
			class Ranger {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Outlaw {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Hunter {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Nomad {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Survivalist {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Engineer {
				Level_0 = 100;
				Level_1 = 100;
				Level_2 = 100;
				Level_3 = 100;
			};
			class Undead {
				Level_0 = 0;
				Level_1 = 0;
				Level_2 = 0;
				Level_3 = 0;
			};
		};
	};
};