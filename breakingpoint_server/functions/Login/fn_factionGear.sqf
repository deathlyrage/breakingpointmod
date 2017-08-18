/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

// Faction System - Gear On Login

//private ["_factionName","_factionLevel","_levelStr","_baseConfig","_clothingRnd","_vestRnd","_backpackRnd"];

params [["_player",objNull,[objNull]],["_choice",0,[0]]];

_factionName = _choice call BP_fnc_getFactionName;
_factionLevel = _player call BP_fnc_getFactionLevel;
_levelStr = format ["Level_%1",_factionLevel];
_baseConfig = (configFile >> "CfgFactions" >> _factionName >> "Levels" >> _levelStr);

removeUniform _player;
removeVest _player;
removeBackpack _player;

//Clothing
_clothingRnd = getArray (_baseConfig >> "Spawn" >> "clothing");
if !(_clothingRnd isEqualTo []) then {
	_player addUniform (selectRandom _clothingRnd);
};

//Vest
_vestRnd = getArray (_baseConfig >> "Spawn" >> "vest");
if !(_vestRnd isEqualTo []) then {
	_player addVest (selectRandom _vestRnd);
};

//Backpack
_backpackRnd = getArray (_baseConfig >> "Spawn" >> "backpack");
if (_backpackRnd isEqualTo []) then {
	_backpackRnd = ["BP_AssaultPack_mcamo","BP_AssaultPack_cbr","BP_AssaultPack_blk","BP_AssaultPack_sgg","BP_AssaultPack_rgr","BP_AssaultPack_dgtl","BP_AssaultPack_khk"];
};
_player addBackpack (selectRandom _backpackRnd);

//Toolbelt
{
	_player addItem _x;
	_player assignItem _x;
} count (getArray (_baseConfig >> "Spawn" >> "toolbelt"));

//Container Magazines
{ (uniformContainer _player) addWeaponCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Uniform" >> "weapons"));
{ (uniformContainer _player) addItemCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Uniform" >> "items"));
{ (uniformContainer _player) addMagazineCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Uniform" >> "magazines"));
	 
{ (vestContainer _player) addWeaponCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Vest" >> "weapons"));
{ (vestContainer _player) addItemCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Vest" >> "items"));
{ (vestContainer _player) addMagazineCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Vest" >> "magazines"));
	 
{ (backpackContainer _player) addWeaponCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Backpack" >> "weapons"));
{ (backpackContainer _player) addItemCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Backpack" >> "items"));
{ (backpackContainer _player) addMagazineCargoGlobal [_x,1] } count (getArray (_baseConfig >> "Backpack" >> "magazines"));

//Weapons
_primaryRnd = getArray (_baseConfig >> "Spawn" >> "primary");
_launcherRnd = getArray (_baseConfig >> "Spawn" >> "launcher");
_handgunRnd = getArray (_baseConfig >> "Spawn" >> "handgun");

if !(_primaryRnd isEqualTo []) then { _player addWeapon (selectRandom _primaryRnd); };
if !(_launcherRnd isEqualTo []) then { _player addWeapon (selectRandom _launcherRnd); };
if !(_handgunRnd isEqualTo []) then { _player addWeapon (selectRandom _handgunRnd); };