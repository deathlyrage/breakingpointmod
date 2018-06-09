/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_playerCtrl";

waitUntil
{
	call BP_fnc_UpdateUI;
	call BP_fnc_zombieCheck;
	BP_AllowInventory = true;
	sleep 0.6;
	r_player_dead
};