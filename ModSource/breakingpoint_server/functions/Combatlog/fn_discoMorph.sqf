/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_playerID","_playerObj"];

//Error Checking
if (isNull _playerObj) exitWith {};

//Remove All Event Handlers
_playerObj removeAllEventHandlers "FiredNear";
_playerObj removeAllEventHandlers "HandleDamage";
_playerObj removeAllEventHandlers "Killed";
_playerObj removeAllEventHandlers "Fired";

//////////////////////////////////////////////////

//Make Unit Mortal
//_playerObj addEventHandler ["HandleDamage",{[_this] call BPServer_fnc_discoMedical;}];
_playerObj addEventHandler ["Killed",{_this call BPServer_fnc_discoKilled;}];
_playerObj allowDamage true;

//Select Default Weapon
private ["_currentWeapon","_primaryWeapon","_handgunWeapon","_launcherWeapon"];
_currentWeapon = currentWeapon _playerObj;
_primaryWeapon = primaryWeapon _playerObj;
_handgunWeapon = handgunWeapon _playerObj;
_launcherWeapon = secondaryWeapon _playerObj;

if (_currentWeapon == "") then {
	if (_primaryWeapon != "") then {
		_playerObj selectWeapon _primaryWeapon;
	} else {
		if (_handgunWeapon != "") then {
			_playerObj selectWeapon _handgunWeapon;
		} else {
			if (_launcherWeapon != "") then {
				_playerObj selectWeapon _launcherWeapon;
			};
		};
	};
};

//Add Player ID and Object to Anti Disconnect Array
BP_AntiDisconnectIDs pushBack _playerID;
BP_AntiDisconnectObjs pushBack _playerObj;

//Sync Stats
_playerObj call BPServer_fnc_statsSync;

//Sync Position
_playerObj call BPServer_fnc_posSync;

///////////////////////////////////////////////////
_discoMorphMonitor = scriptNull;
_discoMorphMonitor = [_playerID,_playerObj] spawn 
{
	scriptName "BP_DiscoMorphMonitor";

	params ["_playerID","_playerObj"];

	//Wait 44 Seconds
	if (!shutdown) then 
	{
		_blood = _playerObj getVariable ["med_BloodQty",12000];

		sleep 44;
	};
	
	//Cleanup AI Unit
	if (!isNull _playerObj) then 
	{
		if (alive _playerObj) then
		{
			//Make Unit Immortal
			_playerObj allowDamage false;

			//Remove All Event Handlers
			_playerObj removeAllEventHandlers "FiredNear";
			_playerObj removeAllEventHandlers "HandleDamage";
			_playerObj removeAllEventHandlers "Killed";
			_playerObj removeAllEventHandlers "Fired";
			
			//Exit this script if the player is attempting a hot reload login while in a combat log ai.
			_hotReload = _playerObj getVariable ["hotReload",false];
			if (_hotReload) exitWith {};
			
			//Save Unit
			_playerObj call BPServer_fnc_logoutSync;
			
			//Clean Up Unit
			_group = group _playerObj;
			if (!isNull _group) then { deleteGroup _group; };
			deleteVehicle _playerObj;
		};
	};
	
	//Remove Player ID and Object From Array
	_index = BP_AntiDisconnectIDs find _playerID;
	if (_index >= 0) then {
		BP_AntiDisconnectIDs deleteAt _index;
		BP_AntiDisconnectObjs deleteAt _index;
	};
};

_playerObj setVariable ["handle",_discoMorphMonitor];

[_discoMorphMonitor] call BP_fnc_addThreadHandle;
