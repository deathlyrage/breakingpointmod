/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_playerNetID","_bodyNetID"];
_player = objectFromNetID _playerNetID;
_body = objectFromNetID _bodyNetID;

//Invalid Player
if (isNull _player) exitWith {};

//Invalid Body
if (isNull _body) exitWith {};

//Make Body Immortal
_body allowDamage false;
if !(simulationEnabled _body) then { _body enableSimulationGlobal true; };
_isAi = _body getVariable ["ai",false];

//Undead Body Harvesting
// if (_player getVariable ["class",0] == 7) exitWith
// {
// 	//Clear Body Inventory
// 	_body setVariable ["inv",[]];
// 	_body hideObjectGlobal true;

// 	_body setVariable ["processedDeath",-100 ];
	
// 	//Delete Body
// 	deleteVehicle _body;
// };

//Backup Body Data
_bodyPos = getPosATL _body;
_bodyName = _body getVariable ["bodyName",""];
_bodyInv = _body getVariable ["inv",[]];
_bodyDeathType = _body getVariable ["deathType",0];

//Fetch Faction Information
_playerClass = _player getVariable ["class",0];
_playerFactionName = _playerClass call BP_fnc_getFactionName;
_playerFactionLevel = _player call BP_fnc_getFactionLevel;
_playerFactionPoints = _player call BP_fnc_getFactionPoints;
_playerTraitorFlag = _player getVariable ["traitorFlag",false];
_playerUniform = (uniform _player);

//Clear Body Inventory
_body setVariable ["inv",[]];
_body hideObjectGlobal true;

//Delete Body
deleteVehicle _body;

//Determine Remains Type Based Off Faction
_remainsType = "BP_DeadBody";
if (_playerFactionName == "Hunter" || {_playerFactionName == "Outlaw"}) then {
	if (!_isAi) then { _remainsType = "BP_SkeletonRemains"; } else { _remainsType = "BP_SkeletonRemainsAI"; };
} else {
	if (!_isAi) then { _remainsType = "BP_GraveDirt"; } else { _remainsType = "BP_GraveDirtAI"; };
};

//Ensure Remains Doesn't Glitch Under The Ground
if ((_bodyPos select 2) < 0) then { _bodyPos set [2,0]; };

//Create Remains
_remains = createVehicle [_remainsType, _bodyPos, [], 0, "CAN_COLLIDE"];
_remains setPosATL _bodyPos;
_remains setVariable ["processedDeath",diag_tickTime];
_remins enableDynamicSimulation true;

//Load Remains Gear
[_remains, _bodyInv] call BP_fnc_setFullInventory;



