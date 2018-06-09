/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/
private ["_building","_buildingID","_buildingUID"];

params ["_buildingNetID"];

_building = objectFromNetID _buildingNetID;

if (isNull _building) exitWith {};

//Fetch Building Data
_buildingIndex = BP_Buildings find _buildingNetID;
if (_buildingIndex == -1) exitWith {}; // Building not found
_buildingData = BP_BuildingsData select _buildingIndex;

_buildingData params ["","_buildingID","_buildingUID"];

if (_buildingID == "0" || {_buildingUID == "0"}) exitWith {};

//["deleteHouse: %1 (%2)",_building,_buildingUID] call BP_fnc_debugConsoleFormat;

//Destroy Building
["CHILD:408:%1:%2:",_buildingID,_buildingUID] call BPServer_fnc_callExtensionAsyncLow;

//Update Arrays and Publish Data
BP_Buildings deleteAt _buildingIndex;
BP_BuildingsData deleteAt _buildingIndex;
BP_BuildingsLocks deleteAt _buildingIndex;
publicVariable "BP_Buildings";
publicVariable "BP_BuildingsLocks";
