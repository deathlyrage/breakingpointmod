/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_onLadder","_hasfooditem","_config","_text","_regen","_dis","_sfx"];

_inVehicle = (vehicle player != player);
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {};

params ["_itemorignal"];
_hasfooditem = _itemorignal in magazines player;

_config =   configFile >> "CfgMagazines" >> _itemorignal;
_text =     getText (_config >> "displayName");
_regen =    getNumber (_config >> "bloodRegen");

if (!_hasfooditem) exitWith {};

player removeMagazine _itemorignal;

if (!_inVehicle) then 
{
	player playActionNow "BP_Act_Man_Eat_Erc_x3_Gesture";
	_dis=6;
	_sfx = getText (_config >> "sfx");
	if (_sfx == "") then {_sfx = "eat"};
	[player,_sfx,0,false,_dis] call BP_fnc_objSpeak;
	_handle = [player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
	[_handle] call BP_fnc_addThreadHandle;
};

if ((_itemorignal in food_with_output) && {!_inVehicle}) then
{
    sleep 2;
	[player,(food_output select (food_with_output find _itemorignal))] call BP_fnc_dropWeaponHolderMag;
};

if ((_itemorignal in meatzombie) and (random 15 < 5)) then {
    r_player_infected = true;
} else {
	if ( (_itemorignal in meatraw) and (random 15 < 1)) then {
		r_player_infected = true;
	};
};

r_player_blood = r_player_blood + _regen;
if (r_player_blood > r_player_bloodTotal) then {
	r_player_blood = r_player_bloodTotal;
};

BP_hunger = 0;

player setVariable ["messing",[BP_hunger,BP_thirst]];

cutText [format["You have consumed a %1.",_text], "PLAIN DOWN"];

//Save Updated Medical Values
call BP_fnc_medSave;