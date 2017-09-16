/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private ["_object","_objectUID","_inventory","_previous"];

_object = _this;

if (isNull _object) exitWith {};

//Don't Update Inventory on Locked Objects
_locked = _object getVariable ["locked",false];
if (_locked) exitWith {};

//Calculate Object UID and Inventory
_objectUID = _object getVariable ["ObjectUID","0"];
_inventory = _object call BP_fnc_getObjectInventory;

//Compare Inventory against Previous
_previous = str(_object getVariable["lastInventory",[]]);
if (str(_inventory) != _previous) then 
{
	_object setVariable ["lastInventory",_inventory];
	if (_object isKindOf "BP_SaveObject") then {
		["CHILD:401:%1:%2:",_objectUID,_inventory] call BPServer_fnc_callExtensionAsyncLow;
	} else {
		["CHILD:502:%1:%2:",_objectUID,_inventory] call BPServer_fnc_callExtensionAsyncLow;
	};
	["updateObjectInventory: Object: %1 | Save Type: %2 | UID: %3 | Inventory Saved (Changes)",(typeName _object),_type,_objectUID] call BP_fnc_debugConsoleFormat;
} else {
	["updateObjectInventory: Object: %1 | Save Type: %2 | UID: %3 | Inventory Skipped (No Changes)",(typeName _object),_type,_objectUID] call BP_fnc_debugConsoleFormat;
};
