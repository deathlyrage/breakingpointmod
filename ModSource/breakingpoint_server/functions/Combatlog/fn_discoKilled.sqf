/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_player","_killer"];

//Fetch Information
_playerName = _player getVariable ["bodyName",""];
_characterID = _player getVariable ["CharacterID","0"];
_playerID = _player getVariable ["playerID","0"];

//Invalid Character ID
if (_characterID == "0") exitWith { [_player] call BPServer_fnc_unitCleanup; };

// Keep A Cache List Of All Dead People In Case Hive Extension is Failing
BP_DeadCharacters pushBack _characterID;

//Write Character Death to DB
_deathTicket = ["CHILD:301:%1:",_characterID] call BPServer_fnc_callExtensionTicket;
BP_DeadTickets pushBack _deathTicket;

["discoKilled: Killed Character: %1",_characterID] call BP_fnc_debugConsoleFormat;

//Update Character Variables
_player setVariable ["processedDeath",diag_tickTime];
_player setVariable ["med_isDead",true,true];

//Register Combat Logger Death Entry
[_playerID,_playerName,_characterID] call BPServer_fnc_combatLog;

//Handle Kill Processing
if (!isNull _killer) then 
{
	if (_killer != _player) then 
	{
		//Fresh Spawn Killing
		_freshSpawn = _player getVariable ["freshSpawn",false];
		if (_freshSpawn) exitWith {
			["playerDeath: Player: %1 was killed by %2. Stats Skipped. Fresh Spawn was killed.~0001",(name _player),(name _killer)] call BP_fnc_debugConsoleFormat;
			BP_GameError = 6;
			(owner _killer) publicVariableClient "BP_GameError";
		};
		
		//Recent Kills
		private ["_kills","_recentKills"];
		_kills = _killer getVariable ["humanKills",0];
		_recentKills = _killer getVariable["recentKills",[]];
		if (_playerID in _recentKills) exitWith {
			["playerDeath: Player: %1 was killed by %2. Stats Skipped. Killer has killed this person in this server session.~0001",(name _player),(name _killer)] call BP_fnc_debugConsoleFormat;
			[_killer,0] call BPServer_fnc_addFactionPoints;
		};
		0 = _recentKills pushBack _playerID;
		_killer setVariable ["recentKills",_recentKills];
		
		// Faction System 
		private ["_pointsChange"];
		_pointsChange = [_player,_killer] call BP_fnc_getFactionKillPoints;
		
		//Player
		private ["_playerClass","_playerFactionName","_playerFactionLevel","_playerFactionPoints"];
		_playerClass = _player getVariable ["class",0];
		_playerFactionName = _playerClass call BP_fnc_getFactionName;
		_playerFactionLevel = _player call BP_fnc_getFactionLevel;
		_playerFactionPoints = _player call BP_fnc_getFactionPoints;
		
		//Killer
		private ["_killerClass","_killerFactionName","_killerFactionLevel","_killerFactionPoints"];
		_killerClass = _killer getVariable ["class",0];
		_killerFactionName = _killerClass call BP_fnc_getFactionName;
		_killerFactionLevel = _killer call BP_fnc_getFactionLevel;
		_killerFactionPoints = _killer call BP_fnc_getFactionPoints;
		
		//None Player Kills None Player
		if (_playerClass == 0 && {_killerClass != 0}) then { _pointsChange = 25; };
		
		// If Player in Traitor Uniform and Doesn't Have Traitor Flag, Flag Anyway Due to Desync
		if (!_playerTraitorFlag) then { if (_playerUniform in BP_TraitorClothing) then { _playerTraitorFlag = true; }; };
		
		// If Killer in Traitor Uniform and Doesn't Have Traitor Flag, Flag Anyway Due to Desync
		if (!_killerTraitorFlag) then { if (_killerUniform in BP_TraitorClothing) then { _killerTraitorFlag = true; }; };
		
		// Check Traitor Flag
		if (_playerTraitorFlag) then { _pointsChange = getNumber (configFile >> "CfgFactions" >> _killerFactionName >> "Points" >> "Kill" >> _playerFactionName >> "Level_0"); };
		
		//Mission Config Custom Points Division
		_pointsChange = _pointsChange * BP_Factions_PointsRatio;

		//Add Points (Global)
		[_killer,_pointsChange] call BPServer_fnc_addFactionPoints;

		//Add Kill
		_killer setVariable ["humanKills",(_kills + 1)];
		
		//Sync Killer
		_killer call BPServer_fnc_statsSync;
	};
};

//Make Sure Weapon Holders are Deleted
_handle = [_player] spawn {
	scriptName "BP_handleKilledAI";
	_player = _this select 0;
	sleep 1;
	_weaponHolders = nearestObjects [getPosATL _player, ["WeaponHolder","WeaponHolderSimulated"], 18];
	{ deleteVehicle _x; } count _weaponHolders;
};
[_handle] call BP_fnc_addThreadHandle;