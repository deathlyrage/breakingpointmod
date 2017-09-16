/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_loot","_lootCount","_nearby"];
_loot = _this getVariable ["loot",[]];
_lootCount = {!isNull _x} count _loot;
_nearby = [(getPosATL _this),500] call BP_fnc_nearbyPlayers;
(_lootCount < 1 && {!_nearby})