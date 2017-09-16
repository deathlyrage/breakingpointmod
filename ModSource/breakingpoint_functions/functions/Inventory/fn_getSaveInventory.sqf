/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;

// Gear Sync Functions
_allCargoMags = [];

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
	_containerID = -1;
	
	//Process Container
	call {
		if (_container == "Uniform") exitWith { _containerID = 0; };
		if (_container == "Vest") exitWith { _containerID = 1; };
		if (_container == "Backpack") exitWith { _containerID = 2; };
	};
	
	if !(_mag in BP_DontSave) then
	{
		if (_mag in BP_Throwables) then
		{
			0 = _partialMags pushBack [_mag, _ammo,_containerID];
		} else {
			if (_loadedInWeapon) then {
				0 = _loadedMags pushBack [_mag, _ammo];
			} else {
				//Not-Full Ammo
				_ammoFull = getNumber (configFile >> "CfgMagazines" >> _mag >> "count");
				if (_ammo < _ammoFull) then {
					0 = _partialMags pushBack [_mag, _ammo,_containerID];
					//_allCargoMags = [_mag, _container, _allCargoMags] call BP_fnc_removeCargoMag;
				} else {
					_allCargoMags = [_mag, _container, _allCargoMags] call BP_fnc_addCargoMag;
				};
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
	
_primaryWeapon = primaryWeapon _unit;
_primaryWeaponItems = primaryWeaponItems _unit;
_secondaryWeapon = secondaryWeapon _unit;
_secondaryWeaponItems = secondaryWeaponItems _unit;
_handgunWeapon = handgunWeapon _unit;
_handgunItems = handgunItems _unit;
	 
_currentMuzzle = currentMuzzle _unit;
	
_weaponsUniform = [];
_weaponsVest = [];
_weaponsBackpack = [];

//_weaponsUniform = (getWeaponCargo uniformContainer _unit) call BP_fnc_cargoToPairs;
//_weaponsVest = (getWeaponCargo vestContainer _unit) call BP_fnc_cargoToPairs;
//_weaponsBackpack = (getWeaponCargo backpackContainer _unit) call BP_fnc_cargoToPairs;

_weaponsUniform = (weaponsItems (uniformContainer _unit));
_weaponsVest = (weaponsItems (vestContainer _unit));
_weaponsBackpack = (weaponsItems (backpackContainer _unit));

if (isNil "_weaponsUniform") then { _weaponsUniform = []; };
if (isNil "_weaponsVest") then { _weaponsVest = []; };
if (isNil "_weaponsBackpack") then { _weaponsBackpack = []; };

_itemsUniform = (getItemCargo uniformContainer _unit) call BP_fnc_cargoToPairs;
_itemsVest = (getItemCargo vestContainer _unit) call BP_fnc_cargoToPairs;
_itemsBackpack = (getItemCargo backpackContainer _unit) call BP_fnc_cargoToPairs;
	
// Extra Weapons and Binoculars / Range Finders
_extraWeaponClasses = ["Binocular","Rangefinder"];	
_extraWeapons = [];
{
	if (_x in _extraWeaponClasses) then {
		0 = _extraWeapons pushBack _x;
	};
} count assignedItems _unit;

_assignedItems = assignedItems _unit - _extraWeaponClasses;
	
_weaponData = [_currentMuzzle,_loadedMags,[[_primaryWeapon,_primaryWeaponItems],[_secondaryWeapon,_secondaryWeaponItems],[_handgunWeapon,_handgunItems]]];
_containerData = [[_weaponsBackpack,_itemsBackpack,_fullMagsBackpack],[_weaponsVest,_itemsVest,_fullMagsVest],[_weaponsUniform,_itemsUniform,_fullMagsUniform]];
_currentInv = [_weaponData,_containerData,_partialMags,_extraWeapons,_assignedItems];

_currentInv