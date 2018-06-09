/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_item"];

_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {};

if !(_item in magazines player) exitWith {};

if (_item == "ItemBandage") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\bandage.sqf"; };
if (_item == "ItemFieldDressing") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\fielddressing.sqf"; };
if (_item == "ItemMorphine") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\morphine.sqf"; };
if (_item == "ItemAdrenaline") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\adrenaline.sqf"; };
if (_item == "ItemPainkiller") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\painkiller.sqf"; };
if (_item == "ItemAntibiotic") exitWith { [0,0,0,[player]] execVM "\breakingpoint_code\medical\antibiotics.sqf"; };