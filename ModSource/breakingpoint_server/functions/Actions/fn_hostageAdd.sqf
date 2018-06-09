/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_playerNetID","_hostageNetID"];

_player = objectFromNetID _playerNetID;
_hostage = objectFromNetID _hostageNetID;

if (isNull _player) exitWith {};
if (isNull _hostage) exitWith {};

if (!isPlayer _player) exitWith {};
if (!isPlayer _hostage) exitWith {};

if (!alive _player) exitWith {};
if (!alive _hostage) exitWith {};

_hostage setVariable ["med_hostage",true,true];
_hostage setVariable ["hostage_perpetrator", _playerNetID, true];

BP_HostageAdd = [_playerNetID,_hostageNetID];
(owner _hostage) publicVariableClient "BP_HostageAdd";
