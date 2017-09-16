/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_unit","_killer"];
_killer = _unit getVariable ["killer",objNull];

["handleKilledAI: Unit: %1 | Killer: %2",_unit,_killer] call BP_fnc_debugConsoleFormat;

if (isNull _unit) exitWith {};

_unit removeAllEventHandlers "Killed";
_unit removeAllEventHandlers "HandleDamage";
_unit removeAllEventHandlers "FiredNear";

//Handle Killing Of AI And Point Gain / Loss
if (!isNull _killer) then
{
	// Faction System
	private ["_pointsChange"];
	_pointsChange = 0;
	_pointsChange = [_unit,_killer] call BP_fnc_getFactionKillPoints;

	//Player
	private ["_playerClass","_playerFactionName","_playerFactionLevel","_playerFactionPoints","_playerTraitorFlag"];
	_playerClass = _unit getVariable ["class",0];
	_playerFactionName = _playerClass call BP_fnc_getFactionName;
	_playerFactionLevel = _unit call BP_fnc_getFactionLevel;
	_playerFactionPoints = _unit call BP_fnc_getFactionPoints;
	_playerTraitorFlag = _unit getVariable ["traitorFlag",false];
	_playerUniform = (uniform _unit);
	
	//Killer
	private ["_killerClass","_killerFactionName","_killerFactionLevel","_killerFactionPoints","_killerTraitorFlag"];
	_killerClass = _killer getVariable ["class",0];
	_killerFactionName = _killerClass call BP_fnc_getFactionName;
	_killerFactionLevel = _killer call BP_fnc_getFactionLevel;
	_killerFactionPoints = _killer call BP_fnc_getFactionPoints;
	_killerTraitorFlag = _killer getVariable ["traitorFlag",false];
	_killerUniform = (uniform _killer);
	
	//None Player Kills None Player
	if (_playerClass == 0 and _killerClass != 0) then { _pointsChange = 25; };
	
	// If Player in Traitor Uniform and Doesn't Have Traitor Flag, Flag Anyway Due to Desync
	if (!_playerTraitorFlag) then { if (_playerUniform in BP_TraitorClothing) then { _playerTraitorFlag = true; }; };
	
	// If Killer in Traitor Uniform and Doesn't Have Traitor Flag, Flag Anyway Due to Desync
	if (!_killerTraitorFlag) then { if (_killerUniform in BP_TraitorClothing) then { _killerTraitorFlag = true; }; };
	
	// Check Traitor Flag
	if (_playerTraitorFlag) then { _pointsChange = getNumber (configFile >> "CfgFactions" >> _killerFactionName >> "Points" >> "Kill" >> _playerFactionName >> "Level_0"); };
	
	//Mission Config Custom Points Division
	_pointsChange = _pointsChange * BP_Factions_PointsRatio;
	
	//Don't Give Positive Points on AI Death
	if (_pointsChange > 0) exitWith {};

	//Add Points (Global)
	[_killer,_pointsChange] call BPServer_fnc_addFactionPoints;
};

if (!isServer) exitWith {};

//Add AI To Respawn Queue
_respawnData = _unit getVariable ["respawn",[]];
["handleKilledAI: Adding Respawn Data %1 to Queue.",_respawnData];
if !(_respawnData isEqualTo []) then { 0 = BP_AIRespawn pushBack _respawnData; };

//Clear Backpack Magazines
clearMagazineCargoGlobal (backpackContainer _unit);

//Backup Inventory
_inventory = _unit call BP_fnc_getFullInventory;
_unit setVariable ["inv",_inventory];

//Clear Inventory
clearWeaponCargoGlobal (backpackContainer _unit);
clearWeaponCargoGlobal (vestContainer _unit);
clearWeaponCargoGlobal (uniformContainer _unit);
clearMagazineCargoGlobal (backpackContainer _unit);
clearMagazineCargoGlobal (vestContainer _unit);
clearMagazineCargoGlobal (uniformContainer _unit);
{ _unit removeMagazine _x; } count magazines _unit;
removeAllWeapons _unit;
removeAllItems _unit;
removeHeadgear _unit;
removeGoggles _unit;
removeVest _unit;
removeBackpack _unit;
removeAllAssignedItems _unit;

//Get Nearby Stronghold
_logic = (getPosATL _unit) call BP_fnc_strongholdGetLogicNearby;
["handleKilledAI: Stronghold Logic: %1",_logic] call BP_fnc_debugConsoleFormat;
if (!isNull _logic) then {
	_logic setVariable ["attacked",true];
	[_killer,_logic] call BPServer_fnc_revealUnit;
};

//Delete Weapon Holders
_weaponHolders = nearestObjects [getPosATL _unit, ["WeaponHolder","WeaponHolderSimulated"], 18];
{ deleteVehicle _x; } count _weaponHolders;

call BPServer_fnc_strongholdCheck;

//Make Sure Weapon Holders are Deleted
_handle = [_unit] spawn {
	scriptName "BP_handleKilledAI";
	_unit = _this select 0;
	sleep 1;
	_weaponHolders = nearestObjects [getPosATL _unit, ["WeaponHolder","WeaponHolderSimulated"], 18];
	{ deleteVehicle _x; } count _weaponHolders;
};
[_handle] call BP_fnc_addThreadHandle;