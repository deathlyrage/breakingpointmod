/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

class CfgFactions 
{
	factions[] = 
	{
		"None", 		//0
		"Ranger",		//1
		"Outlaw",		//2
		"Hunter",		//3
		"Nomad",		//4
		"Survivalist",	//5
		"Engineer",		//6
		"Undead"		//7
	};
	
	//Base Gear Class
	class BP_BaseGear {
		weapons[] = {};
		magazines[] = {};
		items[] = {};
	};
	
	//Base Faction Class
	class BP_BaseFaction 
	{
		name = "Base Faction";
		description = "This faction has not specified a override description.";
		
		class Levels {
			class Level_Base {
				maxHealth = 12000;
				regenRate = 0;
				regenRateSitting = 15;
				class Spawn : BP_BaseGear {};
				class Uniform : BP_BaseGear {};
				class Vest : BP_BaseGear {};
				class Backpack : BP_BaseGear {};
			};
			
			class Level_0 : Level_Base {};
			class Level_1 : Level_Base {};
			class Level_2 : Level_Base {};
			class Level_3 : Level_Base {};
		};

		class Points {
			base = 0;
			min = -5000;
			max = 5000;
			levels[] = {0,2000,3000};
			class Aid {};
			class Destroy {};
			class Hunt {};
			class Kill {};
			class Ignite {};
		};
	};
	
	//Default Starting Gear
	class BP_DefaultGear {
		class Uniform : BP_BaseGear {
			magazines[] = {"ItemPainkiller","ItemBandage","ItemBandage"};
		};
		class Vest : BP_BaseGear {};
		class Backpack : BP_BaseGear {};
	};

	#include "None.hpp"
	#include "Ranger.hpp"
	#include "Outlaw.hpp"
	#include "Hunter.hpp"
	#include "Nomad.hpp"
	#include "Survivalist.hpp"
	#include "Engineer.hpp"
	//#include "Undead.hpp"
};