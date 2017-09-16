/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Function: BP_fnc_onLootInit
	Description: Called When Loot Is Created.
*/
private "_loot";
_loot = _this select 0;

//Increment Loot Count
BP_LootGlobal = BP_LootGlobal + 1;