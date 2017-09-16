/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

private ["_object","_objectUID","_array"];

_object = _this;

if (isNull _object) exitWith {};

_objectUID = _object getVariable ["ObjectUID","0"];

_array = [];
{
	_hit = _object getHitPointDamage _x;
	0 = _array pushBack [_x,_hit];
} count (_object call BP_fnc_vehicleHitpoints);

["CHILD:506:%1:%2:%3:",_objectUID,_array,(damage _object)] call BPServer_fnc_callExtensionAsyncLow;

["updateObjectDamage: Object: %1 | UID: %2",(typeName _object),_objectUID] call BP_fnc_debugConsoleFormat;