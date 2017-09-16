/*
	Author: 
	AgentRev

	Description:
	Adds one instance of a magazine type from a cargo array obtained via BP_fnc_getCargoMags
	
	It is mainly used in magazinesAmmoFull loops to remove partial mags from a BP_fnc_getCargoMags array,
	as the contents of BP_fnc_getCargoMags is generally used to restore full mags in their original container.
	
	Parameter(s):
	_this select 0: magazine class
	_this select 1: container name ("uniform", "vest", "backpack")
	_this select 1: magazine cargo array obtained via BP_fnc_getCargoMags, from which to add the magazine
		
	Returns: new magazine cargo array
*/

params ["_mag","_container"];

_allCargoMags = +(_this select 2);

switch (toLower _container) do
{
	case "uniform":  { _container = 0 };
	case "vest":     { _container = 1 };
	case "backpack": { _container = 2 };
	default          { _container = -1 };
};

_found = false;
{
	_x params ["_magName","_magCount",["_magContainer",-1,[0]]];	

	if ((_magName == _mag) and (_magContainer == _container)) exitWith {
		_found = true;
		_magCount = _magCount + 1;
		if (_container > -1) then {
			_allCargoMags set [_forEachIndex, [_magName,_magCount,_magContainer]];
		} else {
			_allCargoMags set [_forEachIndex, [_magName,_magCount]];
		};
	};
} forEach _allCargoMags;

if (!_found) then 
{ 
	if (_container > -1) then
	{
		0 = _allCargoMags pushBack [_mag,1,_container];
	} else {
		0 = _allCargoMags pushBack [_mag,1];
	};
};

_allCargoMags
