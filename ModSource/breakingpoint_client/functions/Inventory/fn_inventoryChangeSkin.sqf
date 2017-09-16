/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

with missionNameSpace do
{
	//Select Next / Previous Skin
	BP_CurrentInventorySkin = BP_CurrentInventorySkin + 1;
	if (BP_CurrentInventorySkin == count BP_InventorySkins) then { BP_CurrentInventorySkin = 0; };

	//Custom Inventory Skin Selection
	_controlInventoryBG = ((findDisplay 602) displayCtrl 1000);
	_controlGroundBG = ((findDisplay 602) displayCtrl 1001);
	_inventorySkin = BP_InventorySkins select BP_CurrentInventorySkin;
	_controlInventoryBG ctrlSetText (_inventorySkin select 0);
	_controlInventoryBG ctrlCommit 0;
	_controlGroundBG ctrlSetText (_inventorySkin select 1);;
	_controlGroundBG ctrlCommit 0;
};