/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_object",objNull,[objNull]],["_inventory",[],[[]]]];

if (isNull _object) exitWith {};
if (_inventory isEqualTo []) exitWith {};

//Add weapons
if (_object isKindOf "BP_Storage") then {
	[(_inventory select 0),_object] call BP_fnc_weaponsItems;
} else {
	(_inventory select 0) params ["_objWpnTypes","_objWpnQty"];		
	{
		if (isClass(configFile >> "CfgWeapons" >> _x)) then {
			_block = 	getNumber(configFile >> "CfgWeapons" >> _x >> "stopThis") == 1;
			_dontSave = (_x in BP_DontSave);
			if (!_block and !_dontSave) then {
				_object addWeaponCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
			};
		};
	} forEach _objWpnTypes;
};

//Full Magazines
{
	_x params ["_magName","_magCount"];
	_isOK = isClass(configFile >> "CfgMagazines" >> _magName);
	_dontSave = (_x in BP_DontSave);
	if (_isOk and !_dontSave) then { _object addMagazineCargoGlobal [_magName,_magCount]; };
} count (_inventory select 1); //_allCargoMags

//Partial Magazines
{
	_x params ["_magName","_magAmmo"];
	_isOK = isClass(configFile >> "CfgMagazines" >> _magName);
	_dontSave = (_magName in BP_DontSave);
	if (_isOk and !_dontSave) then { _object addMagazineAmmoCargo [_magName, 1, _magAmmo]; };
} count (_inventory select 2); //_partialMags

//Add Backpacks
(_inventory select 3) params ["_objWpnTypes","_objWpnQty"];
{
	_isOK = 	isClass(configFile >> "CfgVehicles" >> _x);
	if (_isOK) then {
		_block = 	getNumber(configFile >> "CfgVehicles" >> _x >> "stopThis") == 1;
		if (!_block) then {
			_object addBackpackCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
		};
	};
} forEach _objWpnTypes;

//Add Items
(_inventory select 4) params ["_objWpnTypes","_objWpnQty"];
{
	_object addItemCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
} forEach _objWpnTypes;

/*
_newSaving = (count _inventory > 4);

if (_newSaving) then
{
	//Add weapons
	if (_object isKindOf "BP_Storage") then {
		[(_inventory select 0),_object] call BP_fnc_weaponsItems;
	} else {
		(_inventory select 0) params ["_objWpnTypes","_objWpnQty"];		
		{
			if (isClass(configFile >> "CfgWeapons" >> _x)) then {
				_block = 	getNumber(configFile >> "CfgWeapons" >> _x >> "stopThis") == 1;
				_dontSave = (_x in BP_DontSave);
				if (!_block and !_dontSave) then {
					_object addWeaponCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
				};
			};
		} forEach _objWpnTypes;
	};
	
	//Full Magazines
	{
		_x params ["_magName","_magCount"];
		_isOK = isClass(configFile >> "CfgMagazines" >> _magName);
		_dontSave = (_x in BP_DontSave);
		if (_isOk and !_dontSave) then { _object addMagazineCargoGlobal [_magName,_magCount]; };
	} count (_inventory select 1); //_allCargoMags
	
	//Partial Magazines
	{
		_x params ["_magName","_magAmmo"];
		_isOK = isClass(configFile >> "CfgMagazines" >> _magName);
		_dontSave = (_magName in BP_DontSave);
		if (_isOk and !_dontSave) then { _object addMagazineAmmoCargo [_magName, 1, _magAmmo]; };
	} count (_inventory select 2); //_partialMags
	
	//Add Backpacks
	(_inventory select 3) params ["_objWpnTypes","_objWpnQty"];
	{
		_isOK = 	isClass(configFile >> "CfgVehicles" >> _x);
		if (_isOK) then {
			_block = 	getNumber(configFile >> "CfgVehicles" >> _x >> "stopThis") == 1;
			if (!_block) then {
				_object addBackpackCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
			};
		};
	} forEach _objWpnTypes;
	
	//Add Items
	(_inventory select 4) params ["_objWpnTypes","_objWpnQty"];
	{
		_object addItemCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
	} forEach _objWpnTypes;
} else {
	//Add weapons
	if (_object isKindOf "BP_Storage") then {
		[(_inventory select 0),_object] call BP_fnc_weaponsItems;
	} else {
		_objWpnTypes = (_inventory select 0) select 0;
		_objWpnQty = (_inventory select 0) select 1;			
		{
			_isOK = 	isClass(configFile >> "CfgWeapons" >> _x);
			if (_isOK) then {
				_block = 	getNumber(configFile >> "CfgWeapons" >> _x >> "stopThis") == 1;
				_dontSave = _x in BP_DontSave;
				if (!_block and !_dontSave) then {
					_object addWeaponCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
				};
			};
		} forEach _objWpnTypes;
	};
			
	//Add Magazines
	_objWpnTypes = (_inventory select 1) select 0;
	_objWpnQty = (_inventory select 1) select 1;
	{
		_isOK = 	isClass(configFile >> "CfgMagazines" >> _x);
		if (_isOK) then {
			_block = 	getNumber(configFile >> "CfgMagazines" >> _x >> "stopThis") == 1;
			if (!_block) then {
				_object addMagazineCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
			};
		};
	} forEach _objWpnTypes;
	
	//Add Backpacks
	_objWpnTypes = (_inventory select 2) select 0;
	_objWpnQty = (_inventory select 2) select 1;
	{
		_isOK = 	isClass(configFile >> "CfgVehicles" >> _x);
		if (_isOK) then {
			_block = 	getNumber(configFile >> "CfgVehicles" >> _x >> "stopThis") == 1;
			if (!_block) then {
				_object addBackpackCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
			};
		};
	} forEach _objWpnTypes;
	
	//Add Items
	_objWpnTypes = (_inventory select 3) select 0;
	_objWpnQty = (_inventory select 3) select 1;
	{
		_object addItemCargoGlobal [_x,(_objWpnQty select _forEachIndex)];
	} forEach _objWpnTypes;
};
*/
