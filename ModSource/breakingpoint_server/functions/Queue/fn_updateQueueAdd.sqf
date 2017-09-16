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

_objectNetID = netID _object;

if (_object isKindOf "BP_LootBox") exitWith {};
if (_object isKindOf "CAManBase") exitWith {};
if (_object isKindOf "GroundWeaponHolder") exitWith {};
if (_object isKindOf "WeaponHolderSimulated") exitWith {};

_index = BP_ObjectUpdateQueue pushBackUnique _objectNetID;
if (_index > -1) then
{
	["updateQueueAdd: Added %1 to the Object Update Queue with NetID %2.",_object,_objectNetID] call BP_fnc_debugConsoleFormat;
};