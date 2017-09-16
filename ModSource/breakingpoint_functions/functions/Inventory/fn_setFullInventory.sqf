/*
	Author: 
	AgentRev

	Description:
	Restores a unit's entire inventory from a key-value array obtained via BP_fnc_getFullInventory
	
	Parameter(s):
	_this select 0: unit
	_this select 0: key-value array obtained from BP_fnc_getFullInventory
*/

private ["_unit", "_data", "_name", "_value"];
_unit = _this select 0;
_data = _this select 1;

if (_unit isKindOf "BP_DeadBody") then
{
	{
		_name = _x select 0;
		_value = _x select 1;

		switch (_name) do
		{
			case "Uniform":               { if (_value != "") then { _unit addItemCargoGlobal [_value,1]; } };
			case "Vest":                  { if (_value != "") then { _unit addItemCargoGlobal [_value,1]; } };
			case "Backpack":              { if (_value != "") then { _unit addBackpackCargoGlobal [_value,1]; } };
			case "Goggles":               { if (_value != "") then { _unit addItemCargoGlobal [_value,1]; } };
			case "Headgear":              { if (_value != "") then { _unit addItemCargoGlobal [_value,1]; } };
			
			case "PrimaryWeapon":         { if (_value != "") then { _unit addWeaponCargoGlobal [_value,1]; } };
			case "SecondaryWeapon":       { if (_value != "") then { _unit addWeaponCargoGlobal [_value,1]; } };
			case "HandgunWeapon":         { if (_value != "") then { _unit addWeaponCargoGlobal [_value,1]; } };
			
			case "PrimaryWeaponItems":    { { if (_x != "") then { _unit addItemCargoGlobal [_x,1]; } } forEach _value };
			case "SecondaryWeaponItems":  { { if (_x != "") then { _unit addItemCargoGlobal [_x,1]; } } forEach _value };
			case "HandgunItems":          { { if (_x != "") then { _unit addItemCargoGlobal [_x,1]; } } forEach _value };
			
			//case "UniformWeapons":        { { (uniformContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "UniformWeapons": 		{ [_value,_unit] call BP_fnc_weaponsItems; };
			case "UniformItems":          { { _unit addItemCargoGlobal _x; } forEach _value };
			case "UniformMagazines":      { { _unit addMagazineCargoGlobal _x; } forEach _value };
			
			//case "VestWeapons":           { { (vestContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "VestWeapons": 			{ [_value,_unit] call BP_fnc_weaponsItems; };
			case "VestItems":             { { _unit addItemCargoGlobal _x; } forEach _value };
			case "VestMagazines":         { { _unit addMagazineCargoGlobal _x; } forEach _value };
			
			//case "BackpackWeapons":       { { (backpackContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "BackpackWeapons": 		{ [_value,_unit] call BP_fnc_weaponsItems; };
			case "BackpackItems":         { { _unit addItemCargoGlobal _x; } forEach _value };
			case "BackpackMagazines":     { { _unit addMagazineCargoGlobal _x; } forEach _value };
			
			case "LoadedMagazines":       { { _unit addMagazineAmmoCargo [(_x select 0),1,(_x select 1)]; } forEach _value };
			case "PartialMagazines":      { { _unit addMagazineAmmoCargo [(_x select 0),1,(_x select 1)]; } forEach _value };
			
			case "AssignedItems":
			{
				{
					if (_x in ["Binocular","Rangefinder"]) then {
						_unit addWeaponCargoGlobal [_x,1];
					} else {
						_unit addItemCargoGlobal [_x,1];
					};
				} forEach _value;
			};
		};
	} forEach _data;
} else {
	removeAllWeapons _unit;
	removeAllAssignedItems _unit;
	removeUniform _unit;
	removeVest _unit;
	removeBackpack _unit;
	removeGoggles _unit;
	removeHeadgear _unit;

	{
		_name = _x select 0;
		_value = _x select 1;

		switch (_name) do
		{
			case "Uniform":               { if (_value != "") then { _unit addUniform _value } };
			case "Vest":                  { if (_value != "") then { _unit addVest _value } };
			case "Backpack":              { if (_value != "") then { _unit addBackpack _value } };
			case "Goggles":               { if (_value != "") then { _unit addGoggles _value } };
			case "Headgear":              { if (_value != "") then { _unit addHeadgear _value } };
			
			case "PrimaryWeapon":         { if (_value != "") then { _unit addWeapon _value } };
			case "SecondaryWeapon":       { if (_value != "") then { _unit addWeapon _value } };
			case "HandgunWeapon":         { if (_value != "") then { _unit addWeapon _value } };
			
			case "PrimaryWeaponItems":    { { if (_x != "") then { _unit addPrimaryWeaponItem _x } } forEach _value };
			case "SecondaryWeaponItems":  { { if (_x != "") then { _unit addSecondaryWeaponItem _x } } forEach _value };
			case "HandgunItems":          { { if (_x != "") then { _unit addHandgunItem _x } } forEach _value };
			
			//case "UniformWeapons":        { { (uniformContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "UniformWeapons": 		{ [_value,(uniformContainer _unit)] call BP_fnc_weaponsItems; };
			case "UniformItems":          { { (uniformContainer _unit) addItemCargoGlobal _x } forEach _value };
			case "UniformMagazines":      { { (uniformContainer _unit) addMagazineCargoGlobal _x } forEach _value };
			
			//case "VestWeapons":           { { (vestContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "VestWeapons": 			{ [_value,(vestContainer _unit)] call BP_fnc_weaponsItems; };
			case "VestItems":             { { (vestContainer _unit) addItemCargoGlobal _x } forEach _value };
			case "VestMagazines":         { { (vestContainer _unit) addMagazineCargoGlobal _x } forEach _value };
			
			//case "BackpackWeapons":       { { (backpackContainer _unit) addWeaponCargoGlobal _x } forEach _value };
			case "BackpackWeapons": 		{ [_value,(backpackContainer _unit)] call BP_fnc_weaponsItems; };
			case "BackpackItems":         { { (backpackContainer _unit) addItemCargoGlobal _x } forEach _value };
			case "BackpackMagazines":     { { (backpackContainer _unit) addMagazineCargoGlobal _x } forEach _value };
			
			case "LoadedMagazines":       { { _unit addMagazine _x } forEach _value };
			case "PartialMagazines":      { { _unit addMagazine _x } forEach _value };
			
			case "AssignedItems":
			{
				{
					if (_x in ["Binocular","Rangefinder"]) then {
						_unit addWeapon _x;
					} else {
						_unit linkItem _x;
					};
				} forEach _value;
			};
		};
	} forEach _data;
};