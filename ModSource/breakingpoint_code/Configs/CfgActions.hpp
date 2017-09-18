/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgActions
{
	class None; //External Class Ref
  
	// Disable Unused Actions */
	class Repair : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class RepairVehicle : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class Talk : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class PatchSoldier : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class HealSoldierSelf : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class HealBleedingOnly : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class HealBleedingSelfOnly : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class HealSoldierAuto : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class HealBleedingAuto : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class Rearm : None {
		show = 0;
		text = "";
		showWindow = 0;
	};

	/* Anti Duping Measures */
	class TakeItem : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class TakeWeapon : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
	class TakeMagazine : None {
		show = 0;
		text = "";
		showWindow = 0;
	};
  
	/*
		This is only a workaround. It will not solve the core
		problem. It will only prevent players from grabbing
		backpacks that lay on the ground. I advice you to
		remove this once Bohemia Interactive has fixed the
		problem in the engine, as the "Take Bag" action is
		a nice shortcut.
	*/
	class TakeBag: None { show = 0; };
	class AddBag: None { show = 0; };

	/*
		Remove the scroll wheel options for left/right panel (was added in jets DLC).
	*/
	class ListRightVehicleDisplay: None { show = 0; };
	class ListLeftVehicleDisplay: None { show = 0; };
	class ListPrevRightVehicleDisplay: None { show = 0; };
	class ListPrevLeftVehicleDisplay: None { show = 0; };
	class CloseRightVehicleDisplay: None { show = 0; };
	class CloseLeftVehicleDisplay: None { show = 0; };
	class NextModeRightVehicleDisplay: None { show = 0; };
	class NextModeLeftVehicleDisplay: None { show = 0; };
};
