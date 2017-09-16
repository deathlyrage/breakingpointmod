/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/
_player = _this;
_characterID = _player getVariable ["CharacterID","0"];

//Check Character ID
if (_characterID == "0") exitWith {};

//Make Suer Character is Human
if !(_player isKindOf "CAManBase") exitWith {};

//Make Sure Character Isn't In Debug
if (_player call BP_fnc_isInDebug) exitWith {};

//Make Sure Character is a player
if (!isPlayer _player) exitWith {};

//Survivalist Points
_class = _player getVariable ["class",0];
if (_class == 5) then {
	_lastPointCheck = _player getVariable ["lastPointCheck",0];
	_lastPos = _player getVariable ["lastPointPos",[0,0,0]];
	if ((diag_tickTime - _lastPointCheck) > 60) then 
	{
		if ((_player distance _lastPos) > 1) then
		{
			_player setVariable ["lastPointPos",getPosATL _player];
			[_player,2,false] call BPServer_fnc_addFactionPoints;
			_player setVariable ["lastPointCheck",diag_tickTime];
		};
	};
};

//Fresh Spawn Timer
_player call BPServer_fnc_freshSpawnCheck;

//Magazines
//_playerID = (getPlayerUID _player);
//if !(_playerID == "76561198121853016") then
//{
//	_magNames = _player call BPServer_fnc_getMagazineNames;
//	_magIDs = _player call BPServer_fnc_getMagazineIDs;
//	{
//		if (_x != "2") then 
//		{
//			_magName = (_magNames select _forEachIndex);
//			_magID = (_magIDs select _forEachIndex);
//			
//			if !(_magID in BP_HackMagIDs) then
//			{
//				//Flag That Magazine ID
//				BP_HackMagIDs pushBack _magID;
//				
//				//Log
//				_reason = format ["Remote Magazine (%1)",_magName];
//				["CHILD:503:%1:%2:%3:",(getPlayerUID _player),(name _player),_reason] call BPServer_fnc_callExtensionAsync;
//				
//				//Flag as Hacker
//				_player setVariable ["hacker",true];
//			};
//		};
//	} forEach (_player call BPServer_fnc_getMagazineLocality);
//};

//Anti-Hack
//_lastPing = _player getVariable ["lastPing",0];
//if ((diag_tickTime - _lastPing) > 180) then {
//	_player setVariable ["lastPing",diag_tickTime];
//	_lastRealPing = _player getVariable ["lastRealPing",0];
//	_reason = format ["Timeout (%1)",_lastRealPing];
//	["CHILD:503:%1:%2:%3:",(getPlayerUID _player),(name _player),_reason] call BPServer_fnc_callExtensionAsync;
//};

//Save Player Position
_player call BPServer_fnc_posSync;

//Save Player Gear + Medical + Stats
_lastSaveTime = _player getVariable ["lastSave",0];
if ((diag_tickTime - _lastSaveTime) > 240) then {
	_player setVariable ["lastSave",diag_tickTime];
	_player call BPServer_fnc_logoutSync;
};