/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//["playerDeath: %1",_this] call BP_fnc_debugConsoleFormat;

params [["_characterID","0",[""]],"_playerNetID",["_playerID","",[""]],["_playerName","Unknown",[""]],["_playerInventory","[]",[""]],"_killerNetID",["_killWeapon","",[""]],["_killDistance","0",[""]]];

// Resolve Player & Killer Objects from Net ID's
_player = (objectFromNetID _playerNetID);
_killer = (objectFromNetID _killerNetID);

// Invalid Character ID
if (_characterID == "0" or _playerID == "") exitWith { [_player] call BPServer_fnc_unitCleanup; };

// Invalid Player Object Reference - Write Death and Exit
if (isNull _player) exitWith { 
	BP_DeadTickets pushBack (["CHILD:301:%1:",_characterID] call BPServer_fnc_callExtensionTicket);
};

// Backup Position
_position = getPosATL _player;

//Fetch Detailed Player Information
_playerClass = _player getVariable ["class",0];
_playerFactionName = _playerClass call BP_fnc_getFactionName;
_playerFactionLevel = _player call BP_fnc_getFactionLevel;
_playerFactionPoints = _player call BP_fnc_getFactionPoints;
_playerTraitorFlag = _player getVariable ["traitorFlag",false];
_playerUniform = (uniform _player);

// Initial Vars and Conversion
_deathType = _player getVariable ["deathType",0];
_playerInventory = parseSimpleArray _playerInventory;
_playerKill = false;

// Delete Nearby Simulated Weapon Holders
[_position] spawn {
	sleep 1;
	{ deleteVehicle _x; } count (nearestObjects [(_this select 0), ["WeaponHolderSimulated"],10]);
};

// Set Death Variables
_player setVariable ["processedDeath",diag_tickTime];
_player setVariable ["body",objNull];
_player setVariable ["bodyName", _playerName,true];
//Already Set On Client in BP_fnc_death;
//_player setVariable ["med_isDead",true,true];
//_player setVariable ["deathType",_deathType,true];
_player setVariable ["inv",_playerInventory];

// Set Legion Death Details
_groupID = _player getVariable ["group","0"];
if (_groupID != "0") then
{
	//Fetch Local Group Tag + Name
	_groupTag = _player getVariable ["groupTag",""];
	_groupName = _player getVariable ["groupName",""];

	//Make It Global
	_player setVariable ["groupTag",_groupTag,true];
	_player setVariable ["groupName",_groupName,true];
};

// Handle Suicide
if (_killer == _player) then { _killer = objNull; };

// Process Kill Results
if (!isNull _killer) then
{
	//if (_killer isKindOf "BP_Stronghold_AI") then {
	//	// Handle Player Killed by Stronghold AI
	//	[_playerID,_playerName,"0","Stronghold AI",_killWeapon,_killDistance] call BPServer_fnc_killLog;
	
	// Kills Log
	_killerName = (name _killer);
	_killerID = (getPlayerUID _killer);
	[_playerID,_playerName,_killerID,_killerName,_killWeapon,_killDistance] call BPServer_fnc_killLog;
	
	// Headshot Check
	if (_deathType == 16) then
	{
		//Fetch Current Headshot Count
		_headshots = _killer getVariable ["headShots",0];
		
		//Update Headshots
		_killer setVariable ["headShots",(_headshots + 1)];
	};
	
	// Fresh Spawn Check
	_player call BPServer_fnc_freshSpawnCheck;
	_freshSpawn = _player getVariable ["freshSpawn",false];
	if (_freshSpawn and _killerClass != 7) exitWith {
		["playerDeath: Player: %1 was killed by %2. Stats Skipped. Fresh Spawn was killed.~0001",(name _player),(name _killer)] call BP_fnc_debugConsoleFormat;
		BP_GameError = 6;
		(owner _killer) publicVariableClient "BP_GameError";
	};
	
	_killerGroupID = _killer getVariable ["group","0"];
	_playerGroupID = _player getVariable ["group","0"];
	if ((_killerGroup == _playerGroup) and (_playerGroupID != "0") and (_killerGroupID != "0")) exitWith {
		["playerDeath: Player: %1 was killed by %2. Stats Skipped. Group member was killed.~0001",(name _player),(name _killer)] call BP_fnc_debugConsoleFormat;
		BP_GameError = 7;
		(owner _killer) publicVariableClient "BP_GameError";
	};
	
	// Faction System
	_pointsChange = [_player,_killer] call BP_fnc_getFactionKillPoints;
	
	//Recent Kills
	_recentKills = _killer getVariable ["recentKills",[]];
	if (_playerID in _recentKills) then {
		if (_pointsChange > 0) then { _pointsChange = 0; }; 
		["playerDeath: Player: %1 was killed by %2. Point Gain Skipped. Killer has killed this person in this server session.~0001",(name _player),(name _killer)] call BP_fnc_debugConsoleFormat;
	} else {
		0 = _recentKills pushBack _playerID;
		_killer setVariable ["recentKills",_recentKills,false];
	};
	
	//Killer
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

	//Zombie Walking Player Killing
	if ((_playerUniform in BP_ZombieClothing) || {_killerUniform in BP_ZombieClothing}) then {
		if (_pointsChange < 0) then { _pointsChange = 0; };
	};
	
	//Mission Config Custom Points Division
	_pointsChange = _pointsChange * BP_Factions_PointsRatio;
	
			//Check if mixed group points off for gutting
		_disableMixedGroupPointsGain = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "MixedGroupPointsGain" >> "disableMixedGroupPointsGain");
		_pointsOff = false;
		if(_disableMixedGroupPointsGain == 1 && _pointsChange > 0) then {
			_killerGroupID = _killer getVariable ["group","0"];
			if(_killerGroupID != "0") then {
				_groupMembers = [];
				_groupMemberClass = -1;
				{
					_groupID = _x getVariable ["group","0"];
						if(_groupID == _killerGroupID) then {
							0 = _groupMembers pushBack _x;
						};
				} count allPlayers;		
				if (count _groupMembers > 1) then {
					_friendlyClass = [1,4,5];
					for [{_i=0}, {_i < (count _groupMembers) && !_pointsOff}, {_i = _i + 1}] do {
						_groupMemberClass = (_groupMembers select _i) getVariable ["class",0];
						if(((_groupMemberClass in _friendlyClass) && (_playerClass in _friendlyClass)) || ((_groupMemberClass == 2) && (_playerClass == 2))) then {
							_pointsOff = true;
						} else {
							_pointsOff = false;
						};
					};
					
				};
			};
		};
	
	//Check if mixed group points off for killing
	if(_pointsOff) then	{
		_pointsChange = 0;
	};
	//Add Points (Global)
	[_killer,_pointsChange] call BPServer_fnc_addFactionPoints;
	
	//Fetch Current Kill Count
	_kills = _killer getVariable ["humanKills",0];
	
	//Update Kills
	_killer setVariable ["humanKills",(_kills + 1)];

	//Always Update Killer Stats
	_killer call BPServer_fnc_statsSync;

	//Log Kill
	["playerDeath: Points:%1 | Victim: %2 (%3) %4 Lvl %5 | Killer: %6 (%7) %8 Lvl %9 ~0001",_pointsChange,_playerName,_playerID,_playerFactionName,_playerFactionLevel,_killerName,_killerID,_killerFactionName,_killerFactionLevel] call BP_fnc_debugConsoleFormat;

	_playerKill = true;
} else {
	["playerDeath: Player: %1 (%2) killed himself.~0001",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
};

// Process Survivalist + Hunter Point Loss On Death
_playerPointLoss = 0;

// Log Death Message
["playerDied: Class: %1 | Faction: %2 | Level: %3 | Points: %4",_playerClass,_playerFactionName,_playerFactionLevel,_playerFactionPoints] call BP_fnc_debugConsoleFormat;

// Lose Survivalist Points on Death
if (_playerFactionName == "Survivalist") then 
{
	call {
		//Level 3
		if (_playerFactionLevel == 3) exitWith { if (_playerKill) then { _playerPointLoss = 504; } else { _playerPointLoss = 252; }; };
		//Level 2
		if (_playerFactionLevel == 2) exitWith { if (_playerKill) then { _playerPointLoss = 216; } else { _playerPointLoss = 108; }; };
		//Level 0 and 1
		if (_playerKill) then { _playerPointLoss = 72; } else { _playerPointLoss = 36; };
	};
	_survivalist = _player getVariable ["survivalist",0];
	_player setVariable ["survivalist",(_survivalist - _playerPointLoss)];
} else {
	// Lose Hunter Points on Death
	if (_playerFactionName == "Hunter" and _playerKill) then
	{
		call {
			//Level 3
			if (_playerFactionLevel == 3) exitWith { _playerPointLoss = 50; };
			//Level 2
			if (_playerFactionLevel == 2) exitWith { _playerPointLoss = 25; };
		};
		_playerPointLoss = _playerPointLoss * BP_Factions_PointsRatio;
		_hunter = _player getVariable ["hunter",0];
		_player setVariable ["hunter",(_hunter - _playerPointLoss)];
	};
};

// Update Player Stats
_player call BPServer_fnc_statsSync;

// Register Character Death
BP_DeadTickets pushBack (["CHILD:301:%1:",_characterID] call BPServer_fnc_callExtensionTicket);

// Remove Killed Player From Faction Chat Channels
_player call BPServer_fnc_radioManageRemove;

// Clear Dog Ownership On Player Death
_dog = _player getVariable ["dog",objNull];
if (!isNull _dog) then {
	_dog setVariable ["CharacterID","0",true];
	_player setVariable ["dog",objNull,true];
};

//End Of BPServer_fnc_playerDeath;
