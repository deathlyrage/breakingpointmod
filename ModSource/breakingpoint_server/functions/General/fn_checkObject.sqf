/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_object",objNull,[objNull]]];

if (isNull _object) exitWith {};

_objectPos = (getPosATL _object);

//On Debug Island
if (((markerPos BP_DebugMarker) distance _objectPos) < BP_DebugRadius) exitWith
{
	_object setDamage 1;
	["Destroying Object %1 at %2 because it is in debug.",_object,_objectPos] call BP_fnc_debugConsoleFormat;
};

//Underwater
if (underwater _object) exitWith {
	_object setDamage 1;
	["Destroying Object %1 at %2 because it is underwater.",_object,_objectPos] call BP_fnc_debugConsoleFormat;
};

//Car or Storage Object on Water
_isCar = _object isKindOf "Car";
_isStorage = _object isKindOf "BP_Storage";
if ((_isCar or _isStorage) && {surfaceIsWater _objectPos}) exitWith {
	_object setDamage 1;
	["Destroying Object %1 at %2 because it is underwater.",_object,_objectPos] call BP_fnc_debugConsoleFormat;
};
