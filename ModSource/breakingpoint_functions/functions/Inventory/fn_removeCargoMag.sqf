/*
	Author: 
	AgentRev

	Description:
	Removes one instance of a magazine type from a cargo array obtained via BP_fnc_getCargoMags
	
	It is mainly used in magazinesAmmoFull loops to remove partial mags from a BP_fnc_getCargoMags array,
	as the contents of BP_fnc_getCargoMags is generally used to restore full mags in their original container.
	
	Parameter(s):
	_this select 0: magazine class
	_this select 1: container name ("uniform", "vest", "backpack")
	_this select 1: magazine cargo array obtained via BP_fnc_getCargoMags, from which to remove the magazine
		
	Returns: new magazine cargo array
*/

private ["_allCargoMags","_cargoMag","_cargoCount","_cargoContainer"];

params ["_mag","_container"];

_allCargoMags = +(_this select 2);

switch (toLower _container) do
{
	case "uniform":  { _container = 0 };
	case "vest":     { _container = 1 };
	case "backpack": { _container = 2 };
	default          { _container = -1 };
};

{
	_x params ["_cargoMag","_cargoCount"];
	
	_cargoContainer = -1;
	if (count _x > 2) then { _cargoContainer = _x select 2;  };
   
	if (_mag == _cargoMag && {_cargoContainer == _container || {_container == -1}}) exitWith
	{
		_x set [1, _cargoCount - 1];
	   
		if (_x select 1 <= 0) then
		{
			0 = _allCargoMags deleteAt _forEachIndex;
		};
	};
} forEach _allCargoMags;

_allCargoMags
