/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_object",objNull,[objNull]],["_type","all",[""]]];

//Check If Object Is Valid
if (isNull _object) exitWith {};

//Check Server Has Completed Init
//if ((!initialized) && {_type != "killed"}) exitWith { ["updateObject: Warning Event: %1 was called before server initialisation.",_this] call BP_fnc_debugConsoleFormat;  };

//Get Object Variables
private ["_objNetID","_objTypeName","_objType","_objUID"];
_objNetID = netID _object;
_objTypeName = typeName _object;
_objType = typeOf _object;
_objUID = _object getVariable ["ObjectUID","0"];
_isSaveObject = (_object isKindOf "BP_SaveObject");

//Don't Update Destroyed Objects
if (_objNetID in BP_ObjectDestroyQueue) exitWith {};

//Don't Update Players
if (isPlayer _object) exitWith {};

//Make sure Simulation Is Enabled Before Saving
if (!simulationEnabled _object) then { _object enableSimulationGlobal true; };

//Log Request
["updateObject: Object %1 Requested Update | Save Type: %2 | UID: %3",_objTypeName,_type,_objUID] call BP_fnc_debugConsoleFormat;

//Check Object Valid
/*
if ("hash_id" callExtension format ["%1:%2#%3", netId _object, typeOf _object, _object getVariable [uiNamespace getVariable profileName, "NULL"]] != "PASS") exitWith {
	
	_ownerName = "Unknown";
	_ownerPID = "0";
	{
		if (owner _x == owner _object) then {
			_ownerName = (name _x);
			_ownerPID = (getPlayerUID _x);
		};
	} count playableUnits;
	["updateObject: Removing Invalid Object %1 (%2) Owned By Player %3 (%4) at Position: %5 Grid: %6",(name _object),_object,_ownerName,_ownerPID,(position _object),(mapGridPosition _object)] call BP_fnc_debugConsoleFormat;
	_object setDamage 1;
	deleteVehicle _object;
};
*/

//Non String Object
if (typeName _objUID != "string") exitWith {
   ["updateObject: Failed to Update Non-string Object: UID: %1~1001",_objUID] call BP_fnc_debugConsoleFormat;
};

//Invalid Object Type
if (_objUID == "0") exitWith {
	["updateObject: Deleting Invalid Object %1 with Invalid ID.~1001",_objType] call BP_fnc_debugConsoleFormat;
	[_object] call BPServer_fnc_unitCleanup;
};

//Update Object Timestamp
if (_isSaveObject) then {
	["CHILD:399:%1:",_objUID] call BPServer_fnc_callExtensionAsyncLow;
} else {
	["CHILD:504:%1:",_objUID] call BPServer_fnc_callExtensionAsyncLow;
};

//Queue Update From Server Mgr
if (_type == "queue") exitWith {
	_object call BPServer_fnc_updateObjectInventory;
	_object call BPServer_fnc_updateObjectPosition;
	_object call BPServer_fnc_updateObjectDamage;
	[_objNetID] call BPServer_fnc_updateQueueDel;
};

//Force Save The Object Regardless Of Anything
if (_type == "force") exitWith {
	_object call BPServer_fnc_updateObjectInventory;
	_object call BPServer_fnc_updateObjectPosition;
	_object call BPServer_fnc_updateObjectDamage;
	[_objNetID] call BPServer_fnc_updateQueueDel;
};

if (_type == "all") exitWith {
	_object call BPServer_fnc_updateObjectInventory;
	_object call BPServer_fnc_updateObjectPosition;
	_object call BPServer_fnc_updateObjectDamage;
	[_objNetID] call BPServer_fnc_updateQueueDel;
};

if (_type == "position") exitWith {
	_object call BPServer_fnc_updateObjectPosition;
};

if (_type == "gear") exitWith {
	_object call BPServer_fnc_updateObjectInventory;
};

if (_type == "damage") exitWith {
	_object call BPServer_fnc_updateObjectDamage;
};
if (_type == "repair") exitWith {
	_object call BPServer_fnc_updateObjectDamage;
};

