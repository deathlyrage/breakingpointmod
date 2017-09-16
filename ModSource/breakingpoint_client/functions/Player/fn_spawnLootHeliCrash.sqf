/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_magRndCount","_itemTypes","_index","_item","_qty","_max","_tQty","_canType","_weights","_cntWeights","_dateNow","_mags"];

params ["_iItem","_iClass","_iPos","_radius"];

if (isNil "_iClass") then
{
	"debug_console" callExtension format ["Spawn_Loot: Loot Class Is Undefined: iItem: %1 | iClass: %2 | iPos: %3 #1000",_iItem,_iClass,_iPos];
	_iClass = "default";
};

if ((count _iPos) > 2) then
{
    _height = getTerrainHeightASL _iPos;
    if (_height < 0) then 
	{
		_iPos set [2, (_iPos select 2) - _height]; 
	};
};

switch (_iClass) do {
	default {
		//Item is food, add random quantity of cans along with an item (if exists)
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];

		_itemTypes = [] + ((getArray (configFile >> "cfgLoot" >> _iClass)) select 0);
		_index = BP_CLBase find _iClass;
		_weights = BP_CLChances select _index;
		_cntWeights = count _weights;
		_qty = 0;
		_max = ceil(random 2) + 1;
		while {_qty < _max} do {
			_tQty = round(random 1) + 1;
			_index = floor(random _cntWeights);
			_index = _weights select _index;
			_canType = _itemTypes select _index;
			_item addMagazineCargoGlobal [_canType,_tQty];
			_qty = _qty + _tQty;
		};
		if (_iItem != "") then {
			_item addWeaponCargoGlobal [_iItem,1];
		};
	};
	case "weapon": {
		//Item is a weapon, add it and a random quantity of magazines
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addWeaponCargoGlobal [_iItem,1];
		_mags = [] + getArray (configFile >> "cfgWeapons" >> _iItem >> "magazines");
		if ((count _mags) > 0) then {
			_magRndCount = round(random 3);
			if (_magRndCount < 1) then { _magRndCount = 1; };
			_item addMagazineCargoGlobal [(_mags select 0), (_magRndCount)];
		};
	};
	case "weaponA": {
		//Item is a weapon, add it and a random quantity of magazines
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addWeaponCargoGlobal [_iItem,1];
		_mags = [] + getArray (configFile >> "cfgWeapons" >> _iItem >> "magazines");
		_attach = getArray (configFile >> "cfgWeapons" >> _iItem >> "linkedAttach");
		{ _item addItemCargoGlobal [_x, 1]; } count _attach;
		if ((count _mags) > 0) then {
			_magRndCount = round(random 3);
			if (_magRndCount < 1) then { _magRndCount = 1; };
			_item addMagazineCargoGlobal [(_mags select 0), (_magRndCount)];
		};
	};
	case "weaponNA": {
		//Item is a weapon, add it with NO AMMO (NA)
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addWeaponCargoGlobal [_iItem,1];
	};
	case "magazine": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addMagazineCargoGlobal [_iItem,1];
	};
	case "object": {
		//Item is one magazine
		_item = createVehicle [_iItem, _iPos, [], _radius, "CAN_COLLIDE"];
	};
	case "vest": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addItemCargoGlobal [_iItem,1];
	};
	case "uniform": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addItemCargoGlobal [_iItem,1];
	};
	case "headgear": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addItemCargoGlobal [_iItem,1];
	};
	case "toolbelt": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addItemCargoGlobal [_iItem,1];
	};
	case "backpack": {
		//Item is one magazine
		_item = createVehicle ["WeaponHolderSimulated", _iPos, [], _radius, "CAN_COLLIDE"];
		_item addBackpackCargoGlobal [_iItem,1];
	};
};

_item