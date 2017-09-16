/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//private ["_assignedItems","_storage","_weaponsData","_containerData","_partialMags","_extraWeapons","_currentMuzzle","_loadedMags","_weapons","_primary","_secondary","_handgun","_backpackData","_weaponsBackpack","_itemsBackpack","_magsBackpack","_vestData","_weaponsVest","_itemsVest","_magsVest","_uniformData","_weaponsUniform","_itemsUniform","_magsUniform"];

params [["_player",objNull,[objNull]],["_inventory",[],[[]]]];

if (isNull _player) exitWith {};

//Clear Existing Player Unit
{ _player removeMagazine _x; } count magazines _player;
removeAllWeapons _player;
removeUniform _player;
removeHeadgear _player;
removeGoggles _player;
removeVest _player;
removeAllAssignedItems _player;

//Exit If Empty Inventory
if (_inventory isEqualTo []) exitWith {};

_inventory params ["_assignedItems","_storage","_weaponsData","_containerData","_partialMags",["_extraWeapons",[],[[]]]];

//["gearSet: assignedItems: %1~0011",_assignedItems] call BP_fnc_debugConsoleFormat;
//["gearSet: storage: %1~0011",_storage] call BP_fnc_debugConsoleFormat;
//["gearSet: weaponsData: %1~0011",_weaponsData] call BP_fnc_debugConsoleFormat;
//["gearSet: containerData: %1~0011",_containerData] call BP_fnc_debugConsoleFormat;
//["gearSet: partialMags: %1~0011",_partialMags] call BP_fnc_debugConsoleFormat;
//["gearSet: extraWeapons: %1~0011",_extraWeapons] call BP_fnc_debugConsoleFormat;

_weaponsData params [["_currentMuzzle","",[""]],["_loadedMags",[],[[]]],["_weapons",[],[[]]]];
_weapons params [["_primary",[],[[]]],["_secondary",[],[[]]],["_handgun",[],[[]]]];
//["gearSet: weapons: %1~0011",_weapons] call BP_fnc_debugConsoleFormat;
//["gearSet: primary: %1~0011",_primary] call BP_fnc_debugConsoleFormat;
//["gearSet: handgun: %1~0011",_handgun] call BP_fnc_debugConsoleFormat;

//Add Storage Items (Backpack,Uniform,Vest,Headgear)
{
	if (typeName _x == "STRING") then
	{
		//Storage: Backpack
		if (_x in BP_AllBackpacks) then 
		{
			if (isClass(configFile >> "CfgVehicles" >> _x)) then {
				_player addBackpack _x; 
			};
		} else {
			if (isClass (configFile >> "CfgWeapons" >> _x)) then 
			{
				if (_x in BP_CustomItems) then
				{
					if (_x in BP_AllSkins) then
					{
						//["gearSet: Adding Uniform: %1~0001",_x] call BP_fnc_debugConsoleFormat;
						_player addUniform _x;
					};
					if (_x in BP_NormalClothing) then
					{
						//["gearSet: Adding Uniform: %1~0001",_x] call BP_fnc_debugConsoleFormat;
						_player addUniform _x;
					};
					if (_x in BP_ZombieClothing) then
					{
						_clothing = "";
						_clothingIndex = (BP_ZombieClothing find _x);
						if (_clothingIndex > -1) then {
							_clothing = (BP_NormalClothing select _clothingIndex);
						} else {
							_levelStr = format ["Level_%1",_factionLevel];
							_clothingArray = getArray (configFile >> "CfgFactions" >> _factionName >> "Levels" >> _levelStr >> "Spawn" >> "clothing");
							_clothing = (_clothingArray select 0);
						};
						//["gearSet: Adding Uniform: %1~0001",_clothing] call BP_fnc_debugConsoleFormat;
						_player addUniform _clothing;
					};
					if (_x in BP_AllVests) then
					{
						//["gearSet: Adding Vest: %1~0001",_x] call BP_fnc_debugConsoleFormat;
						_player addVest _x;
					};
					if (_x in BP_AllHeadgear) then
					{
						//["gearSet: Adding Headgear: %1~0001",_x] call BP_fnc_debugConsoleFormat;
						_player addHeadgear _x;
					};
				};
			};
		};
	};
} count _storage;

//Add Assigned Items
{
	if (typeName _x == "STRING") then
	{
		if (_x in BP_ToolbeltItems) then
		{
			if (isClass(configFile >> "CfgWeapons" >> _x)) then 
			{
				//["gearSet: Adding Toolbelt Item: %1~0001",_x] call BP_fnc_debugConsoleFormat;
				_backpack = (unitBackpack _player);
				if (!isNull _backpack) then {
					_backpack addItemCargo [_x,1];
					_player assignItem _x;
				} else {
					_player addWeapon _x;
				};
			};
		};
	};
} count _assignedItems;

//Add Loaded Magazines
{  _player addMagazine _x; } count _loadedMags;

//Add Weapon Attachments / Items
if !(_primary isEqualTo []) then {
	_primary params [["_primaryWeapon","",[""]],"_primaryWeaponItems"];
	if (_primaryWeapon != "") then { _player addWeapon _primaryWeapon; };
	{ if (_x != "") then { _player addPrimaryWeaponItem _x } } count _primaryWeaponItems;
};

if !(_secondary isEqualTo []) then {
	_secondary params [["_secondaryWeapon","",[""]],"_secondaryWeaponItems"];
	if (_secondaryWeapon != "") then { _player addWeapon _secondaryWeapon; };
	{ if (_x != "") then { _player addSecondaryWeaponItem _x } } count _secondaryWeaponItems;
};

if !(_handgun isEqualTo []) then {
	_handgun params [["_handgunWeapon","",[""]],"_handgunItems"];
	if (_handgunWeapon != "") then { _player addWeapon _handgunWeapon; };
	{ if (_x != "") then { _player addHandgunItem _x } } count _handgunItems;
};

//Select Last Used Weapon
if (_currentMuzzle != "") then { _player selectWeapon _currentMuzzle; };

//Add Extra Weapons
{ _player addWeapon _x } count _extraWeapons;

//Fetch Player Containers
private ["_uniformContainer","_vestContainer","_backpackContainer"];
_uniformContainer = (uniformContainer _player);
_vestContainer = (vestContainer _player);
_backpackContainer = (backpackContainer _player);

_containerData params [["_backpackData",[],[[]]],["_vestData",[],[[]]],["_uniformData",[],[[]]]];

//Add Uniform Weapons
if (!isNull _uniformContainer) then
{
	_uniformData params [["_weaponsUniform",[],[[]]],["_itemsUniform",[],[[]]],["_magsUniform",[],[[]]]];
	
	[_weaponsUniform,_uniformContainer] call BP_fnc_weaponsItems;
	//{ _uniformContainer addWeaponCargo _x } count _weaponsUniform;
	{ _uniformContainer addItemCargoGlobal _x } count _itemsUniform;
	{ _uniformContainer addMagazineCargoGlobal _x } count _magsUniform;
};

if (!isNull _vestContainer) then
{
	_vestData params [["_weaponsVest",[],[[]]],["_itemsVest",[],[[]]],["_magsVest",[],[[]]]];
	
	[_weaponsVest,_vestContainer] call BP_fnc_weaponsItems;
	//{ _vestContainer addWeaponCargo _x; } count _weaponsVest;
	{ _vestContainer addItemCargoGlobal _x; } count _itemsVest;
	{ _vestContainer addMagazineCargoGlobal _x; } count _magsVest;
};

if (!isNull _backpackContainer) then
{
	_backpackData params [["_weaponsBackpack",[],[[]]],["_itemsBackpack",[],[[]]],["_magsBackpack",[],[[]]]];
	
	[_weaponsBackpack,_backpackContainer] call BP_fnc_weaponsItems;
	//{ _backpackContainer addWeaponCargo _x; } count _weaponsBackpack;
	{ _backpackContainer addItemCargoGlobal _x; } count _itemsBackpack;
	{ _backpackContainer addMagazineCargoGlobal _x; } count _magsBackpack;
};

{
	_x params [["_magazine","",[""]],["_ammo",0,[0]],["_containerID",-1]];

	call
	{
		if !(isClass (configFile >> "CfgMagazines" >> _magazine)) exitWith {};
		if (_magazine in BP_DontSave) exitWith {};

		if (_containerID == -1) exitWith { _player addMagazine [_magazine,_ammo]; };
		if (_containerID == 0) exitWith {
			if (!isNull _uniformContainer) then { _uniformContainer addMagazineAmmoCargo [_magazine,1,_ammo]; };
		};
		if (_containerID == 1) exitWith {
			if (!isNull _vestContainer) then { _vestContainer addMagazineAmmoCargo [_magazine,1,_ammo]; };
		};
		if (_containerID == 2) exitWith {
			if (!isNull _backpackContainer) then { _backpackContainer addMagazineAmmoCargo [_magazine,1,_ammo]; };
		};
	};
} count _partialMags;
