/*
	Author: 
	AgentRev

	Description:
	Saves a unit's entire inventory in a key-value array, to be used in conjunction with BP_fnc_setFullInventory
	
	Parameter(s):
	_this: unit
		
	Returns: key-value array
*/

private ["_unit", "_data", "_allCargoMags", "_partialMags", "_loadedMags", "_mag", "_ammo", "_loadedInWeapon", "_container", "_fullMagsUniform", "_fullMagsVest", "_fullMagsBackpack"];
_unit = _this;
_data = [];

_allCargoMags = _unit call BP_fnc_getCargoMags;

// The reason why cargo magazines are acquired this way is because that magazinesAmmoFull does not return the
// proper container of handgrenades assigned to special muzzles ("SmokeShellMuzzle", "ChemlightGreenMuzzle", etc.)
// So, by gathering magazine cargos, they can be properly restored to their original container.

_partialMags = [];
_loadedMags = [];

{
	_mag = _x select 0;
	_ammo = _x select 1;
	_loadedInWeapon = (_x select 2 && {_x select 3 != 0}); // if loaded and not hand grenade
	_container = _x select 4;

	if (_mag in BP_DontSave) then // remove mags that don't save
	{
		_allCargoMags = [_mag, _container, _allCargoMags] call BP_fnc_removeCargoMag;
	}
	else
	{
		if (_loadedInWeapon) then
		{
			0 = _loadedMags pushBack [_mag, _ammo];
		}
		else
		{
			if (_ammo < getNumber (configFile >> "CfgMagazines" >> _mag >> "count")) then
			{
				0 = _partialMags pushBack [_mag, _ammo];
				_allCargoMags = [_mag, _container, _allCargoMags] call BP_fnc_removeCargoMag;
			};
		};
	};
} count magazinesAmmoFull _unit;

_fullMagsUniform = [];
_fullMagsVest = [];
_fullMagsBackpack = [];

{
	_id = _x select 2;
	call
	{
		if (_id == 0) exitWith { 0 = _fullMagsUniform pushBack [_x select 0, _x select 1]; };
		if (_id == 1) exitWith { 0 = _fullMagsVest pushBack [_x select 0, _x select 1]; };
		if (_id == 2) exitWith { 0 = _fullMagsBackpack pushBack [_x select 0, _x select 1]; };
	};
} count _allCargoMags;

_uniformContainer = (uniformContainer _unit);
_vestContainer = (vestContainer _unit);
_backpackContainer = (backpackContainer _unit);

_uniformWeapons = [];
_vestWeapons = [];
_backpackWeapons = [];

if (!isNull _uniformContainer) then { _uniformWeapons = weaponsItems _uniformContainer; };
if (!isNull _vestContainer) then { _vestWeapons = weaponsItems _vestContainer; };
if (!isNull _backpackContainer) then { _backpackWeapons = weaponsItems _backpackContainer; };

// The order below is important
_data pushBack ["Uniform",uniform _unit];
_data pushBack ["Vest",vest _unit];
_data pushBack ["Backpack",backpack _unit];
_data pushBack ["Goggles",goggles _unit];
_data pushBack ["Headgear",headgear _unit];

_data pushBack ["LoadedMagazines",_loadedMags];
_data pushBack ["PrimaryWeapon",primaryWeapon _unit];
_data pushBack ["PrimaryWeaponItems",primaryWeaponItems _unit];
_data pushBack ["SecondaryWeapon",secondaryWeapon _unit];
_data pushBack ["SecondaryWeaponItems",secondaryWeaponItems _unit];
_data pushBack ["HandgunWeapon",handgunWeapon _unit];
_data pushBack ["HandgunItems",handgunItems _unit];
_data pushBack ["AssignedItems",assignedItems _unit];

//_data pushBack ["UniformWeapons",(getWeaponCargo uniformContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["UniformWeapons",_uniformWeapons];
_data pushBack ["UniformItems",(getItemCargo uniformContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["UniformMagazines",_fullMagsUniform];

//_data pushBack ["VestWeapons",(getWeaponCargo vestContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["VestWeapons",_vestWeapons];
_data pushBack ["VestItems",(getItemCargo vestContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["VestMagazines",_fullMagsVest];

//_data pushBack ["BackpackWeapons",(getWeaponCargo backpackContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["BackpackWeapons",_backpackWeapons];
_data pushBack ["BackpackItems",(getItemCargo backpackContainer _unit) call BP_fnc_cargoToPairs];
_data pushBack ["BackpackMagazines",_fullMagsBackpack];

_data pushBack ["PartialMagazines",_partialMags];

_data
