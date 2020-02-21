/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

class None : BP_BaseFaction 
{
	name = "None";
	description = "N/A";
	//icon = "\a3\ui_f\data\map\Markers\NATO\b_inf.paa";
	icon = "\breakingpoint_ui\icons\NoneIcon.paa";
	
	class Levels : Levels {
		class Level_Base : Level_Base {
			class Spawn {
				//Array Of Toolbelt Items
				toolbelt[] = {};
				//Array Of Random (Clothing,Backpack,Vest)
				primary[] = {};
				launcher[] = {};
				handgun[] = {};
				clothing[] = {"BP_OptOut","BP_OptOut2","BP_OptOut3"};
				backpack[] = {};
				vest[] = {};
			};
			class Uniform : BP_BaseGear {
				magazines[] = {"ItemPainkiller","ItemBandage","ItemBandage"};
			};
			class Vest : BP_BaseGear {};
			class Backpack : BP_BaseGear {};
		};
		
		class Level_0 : Level_Base {};
		class Level_1 : Level_Base {};
	};
};