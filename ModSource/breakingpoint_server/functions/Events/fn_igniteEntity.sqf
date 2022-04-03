/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_sourceNetID","_targetNetID"];

_player = objectFromNetID _sourceNetID;
_object = objectFromNetID _targetNetID;

if (isNull _player) exitWith {};
if (isNull _object) exitWith {};

if (_player distance _object > 10) exitWith {};

_objectPos = getPosATL _object;
_fireObj = _object getVariable ["fire",objNull];
if !(isNull _fireObj) exitWith {};

_fireObj = createVehicle ["BP_SmallFire", _objectPos, [], 0, "CAN_COLLIDE"];
_fireObj attachTo [_object, [-0.1, 0.1, 0.15], "Pelvis"];
_fireObj setVectorDirAndUp [ [0.5, 0.5, 0], [-0.5, 0.5, 0] ];
_object setVariable ["fire",_fireObj,true];

//if killer == victim no points change (zombie fire bolt kill) both objects are the same > fn_damageHandlerZ
if (_player isEqualTo _object) exitWith {};

//Faction Point Loss
_pointsChange = [_player,_object] call BP_fnc_getFactionKillPoints;



//Don't Add Pos Points for this action
if (_pointsChange > 0) exitWith {};
// kill points for destorying vehicles
if(_object isKindOf "AllVehicles") then {
	// Outlaw
	_victimClass = _player getVariable ["class",0];
	if(_victimClass == 2)then {
		_pointsChange = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "Faction" >> "outlawDestroyPoints");;
	};
};

//Mission Config Custom Points Division
_pointsChange = _pointsChange * BP_Factions_PointsRatio;									  

//Add Points (Global)
[_player,_pointsChange] call BPServer_fnc_addFactionPoints;