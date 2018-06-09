/*
	Author: 
	Deathlyrage
	
	Example:
	[_backpackWeapons,(backpackContainer player)] call BP_fnc_weaponsItems;

	Description:
	Loads a stored array of weaponsItem.
	
	Parameter(s):
	_this select 0: array of weaponsItems
	_this select 1: container to add gear to
		
	Returns: Nothing
*/

params [["_array",[]],["_container",objNull],["_ignoreItems",[]]];

if (_array isEqualTo []) exitWith {};
if (isNull _container) exitWith {};

{
	_count = (count _x);
	_x params [["_weapon",""],["_supressor",""],["_laser",""],["_optics",""]];

	if !(_weapon in _ignoreItems) then 
	{
		if (_weapon != "") then {
			_container addWeaponCargoGlobal [_weapon,1];
		};

		if (_supressor != "") then { 
			_container addItemCargoGlobal [_supressor,1];
		};

		if (_laser != "") then {
			_container addItemCargoGlobal [_laser,1];
		};
		
		if (_optics != "") then {
			_container addItemCargoGlobal [_optics,1];
		};

		//Magazine
		if (_count > 4) then {
			_magazine = _x select 4;
			if (count _magazine > 0) then {
				_magazine params ["_magClass","_magAmmo"];
				if !(_magazine in BP_DontSave) then {
					//_container addMagazineCargoGlobal [_magClass,1];
					_container addMagazineAmmoCargo [_magClass,1,_magAmmo];
				};
			};
		};
		//Grenade Magazine
		if (_count > 5) then {
			_grenade = _x select 5;
			if (count _grenade > 0) then {
				_grenade params ["_grenadeClass","_grenadeAmmo"];
				if !(_grenadeClass in BP_DontSave) then {
					//_container addMagazineCargoGlobal [_grenadeClass,_grenadeAmmo];
					_container addMagazineAmmoCargo [_grenadeClass,1,_grenadeAmmo];
				};
			};
		};
	};
} forEach _array;