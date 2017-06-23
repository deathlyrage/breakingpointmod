/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_vehicle = (vehicle player);

//Only eject if you are in a vehicle
if !(player in _vehicle) exitWith {};

//Remove Scroll wheel action
player removeAction s_player_ejectParacute;
s_player_ejectParacute = -1;

_chuteheight = 200;
_dir = direction _vehicle;

//Backup Gear
[player, [missionNamespace, "inv"]] call BIS_fnc_saveInventory;

//Remove Backpack
removeBackpack player;

//Disable Collision / Prevent Damage
player disableCollisionWith _vehicle;
player allowdamage false;

//Add Parachute
player addBackPack "B_parachute";

//Eject
unassignvehicle player;
moveout player;

//Set Player Direction (Exit the chopper at right angles.)
//player setDir (_dir + 90);

//Delay
sleep 2;

player setVariable ["parachute",true];

//Landing (Wait Until Correct Height)
waitUntil {(position player select 2) <= _chuteheight};

player setVariable ["parachute",false];

//Open Parachute
player action ["openParachute",player];

//Wait Until Landing
waitUntil { isTouchingGround player || (position player select 2) < 1 };

//Eject Parachute
player action ["eject", (vehicle player)];

//Delay
sleep 1;

//Reload Inventory
[player, [missionNamespace, "inv"]] call BIS_fnc_loadInventory;

player allowdamage true; 


