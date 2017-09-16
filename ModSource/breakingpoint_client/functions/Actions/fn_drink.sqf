/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_onLadder","_hasdrinkitem","_hasoutput","_config","_text","_sfx","_dis"];

_inVehicle = (vehicle player != player);
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {};

params ["_itemorignal"];

_hasdrinkitem = _itemorignal in magazines player;
_hasoutput = _itemorignal in drink_with_output;

_config = configFile >> "CfgMagazines" >> _itemorignal;
_text = getText (_config >> "displayName");

if (!_hasdrinkitem) exitWith {};

player removeMagazine _itemorignal;
if (_itemorignal in no_output_drink) then { player addMagazine "WaterbotEmpty"; };

if (!_inVehicle) then 
{
	player playActionNow "BP_Act_Man_Drink_Erc_x3_Gesture";
	_dis=6;
	_sfx =  getText (_config >> "sfx");
	[player,_sfx,0,false,_dis] call BP_fnc_objSpeak;
	[player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
};

if (_hasoutput && {!_inVehicle}) then
{
    sleep 2;
    [player,(drink_output select (drink_with_output find _itemorignal))] call BP_fnc_dropWeaponHolderMag;
};

if ((random 15 < 1) and (_itemorignal == "Waterbot")) then { r_player_infected = true; };

BP_thirst = 0;

player setVariable ["messing",[BP_hunger,BP_thirst]];

cutText [format["You have consumed a %1.",_text], "PLAIN DOWN"];

//Save Updated Medical Values
call BP_fnc_medSave;