/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_object","_inventory"];
_object = _this;

//Process Ammo Count Handling on Magazines
_allCargoMags = [];
_partialMags = [];

//Process Full / Partial Mags into separate arrays
{
	_x params ["_mag","_ammo"];
	_fullAmmo = getNumber (configFile >> "CfgMagazines" >> _mag >> "count");
	_dontSave = (_mag in BP_DontSave);
	
	if (!_dontSave) then
	{
		if (_ammo < _fullAmmo) then {
			0 = _partialMags pushBack [_mag, _ammo];
			//_allCargoMags = [_mag, "storage", _allCargoMags] call BP_fnc_removeCargoMag;
		} else {
			_allCargoMags = [_mag, "storage", _allCargoMags] call BP_fnc_addCargoMag;
		};
	};
} count (magazinesAmmoCargo _object);

["getObjectInventory: Full: %1",_allCargoMags] call BP_fnc_debugConsoleFormat;
["getObjectInventory: Partial: %1",_partialMags] call BP_fnc_debugConsoleFormat;

//Calculate Final Inventory
if (_object isKindOf "BP_Storage") then 
{
	_inventory = [
		weaponsItems _object,
		_allCargoMags,
		_partialMags,
		getBackpackCargo _object,
		getItemCargo _object
	];
} else {
	_inventory = [
		getWeaponCargo _object,
		_allCargoMags,
		_partialMags,
		getBackpackCargo _object,
		getItemCargo _object
	];
};

//Determine If Object Is Completely Empty
if (_inventory isEqualTo [[[],[]],[],[],[[],[]],[[],[]]]) then { _inventory = []; };

//Return Inventory Result
_inventory