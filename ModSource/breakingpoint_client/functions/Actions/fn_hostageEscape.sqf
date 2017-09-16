/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_hasKnife","_isHarvested","_escapeChance","_nearByPile","_item"];

player removeAction s_player_hostageEscape;
s_player_hostageEscape = -1;

_hasKnife = "ItemKnife" in magazines player;

if (!_hasKnife) exitWith {};

_isHarvested = player getVariable ["gutted",false];
_escapeChance = ((random 1) < 0.5);

if (_escapeChance && {!_isHarvested}) then {
	cutText ["You have successfully escaped from being a hostage.", "PLAIN DOWN"];
	player setVariable ["med_hostage",false,true];
} else {
	cutText ["You have failed to escape from being a hostage.", "PLAIN DOWN"];
	player removeMagazine "ItemKnife";

    _nearByPile = nearestObjects [(position player), ["WeaponHolder","WeaponHolderSimulated"],3];
    if (count _nearByPile ==0) then { 
        _item = createVehicle ["groundWeaponHolder", position player, [], 0.0, "CAN_COLLIDE"];
    } else {
        _item = _nearByPile select 0;
    };
	_item addMagazineCargoGlobal [_empty,1];
	_item setVelocity [0,0,1];
};