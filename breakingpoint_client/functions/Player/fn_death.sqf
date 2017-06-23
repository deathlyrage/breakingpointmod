/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//TEMP (FIGURE OUT WHY PARAMS DONT WORK!)
private "_method";
_method = _this select 0;

//THIS IS SO FUCKED
//params ["_method",0,[0]];

// Don't Handle Death More Then Once
if (deathHandled) exitWith {};
deathHandled = true;

// Close Open Dialogs
closeDialog 0;

// Handle Players Dying Inside Vehicles
_isInVehicle = (vehicle player != player);
if (_isInVehicle) then {
	_playerObj action ["getOut", vehicle player]; // _playerObj action ["eject", vehicle _playerObj];
};

// Preload Rscs
BP_playerInventoryOnDeath = player call BP_fnc_getFullInventory; // inventory needs to be acquired here because primary weapon is already gone in the "Killed" event handler

//Flag Player as Dead Medical State
player setVariable ["med_isDead",true,true];

// Ensure Player Is Dead
player enableSimulation true;
player allowDamage true;
player setHitPointDamage ["HitBody",1];
player setHitPointDamage ["HitHead",1];
if (alive player) then { player setDamage 1; };

r_player_unconscious = false;
r_player_cardiac = false;
r_player_infected = false;
r_player_injured = false;

0.1 fadeSound 0;

r_player_dead = true;

_handle = [player,20,true,getPosATL player] spawn BP_fnc_zombieAlert;
[_handle] call BP_fnc_addThreadHandle;

// Set Body Death Reason
if (_method != 0) then { player setVariable ["deathType",_method,true]; };

// Clean Layers
_layers = [0,1,2,3,4];
{ _x cutRsc ["Default", "PLAIN",1] } count _layers;

// Custom Death Screen For Undead Class
_deathScreenName = "DeathScreenEnd";
if (player getVariable ["class",0] == 7) then { _deathScreenName = "DeathScreenEndZed"; };

// Player is Dead!
0 fadeSound 0.4;
playSound ["z_deathscreen", false];
0 cutText ["", "BLACK",0];
3 cutRsc [_deathScreenName, "BLACK OUT", 0];
4 cutRsc ["DeathScreenStart", "BLACK OUT",0];
4 cutFadeOut 30;

BP_DeathActioned = true;