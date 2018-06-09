/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_playerNetID","_charID","_blueprint","_lock","_classname","_pos","_dir","_building"];

_playerObj = objectFromNetID _playerNetID;
_playerID = getPlayerUID _playerObj;

//["publishObj: %1",_this] call BP_fnc_debugConsoleFormat;

if (_pos isEqualTo [0,0,0]) exitWith {};

_valid = true;

//Check Object Limit
_limit = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "StorageObjects" >> "storageLimit");
_storageCount = 0;
{
	if (!isNull _x) then {
		if !((_classname isKindOf "BP_HouseStorage") or (_classname isKindOf "BP_HouseObject")) then
		{
			_storagePID = _x getVariable ["PlayerID","0"];
			if (_storagePID == _playerID) then { _storageCount = _storageCount + 1; };	
		};
	};
} count allMissionObjects "BP_SaveObject";

//Check Haven Objects
{
	_havenPlayerID = _x select 3;
	if (_playerID == _havenPlayerID) exitWith
	{
		_objects = _x select 0;
		_objectCount = count _objects;
		_storageCount = _storageCount + _objectCount;
	};
} forEach BP_BuildingsData;

if (_storageCount > _limit) then { _valid = false; };

//Check and Get Building ID
_buildingID = "0";
_buildingIndex = -1;
if (!isNull _building) then
{
	_buildingID = _building call BP_fnc_getBuildingID;
	_buildingIndex = BP_Buildings find (netID _building);
	if (_buildingIndex >= 0) then
	{
		_locked = BP_BuildingsLocks select _buildingIndex;
		if (_locked == 1) then {
			_valid = false;
		};
	} else {
		_valid = false;
	};
};

//Check If Object Requires Link To A Haven Building
if (_buildingID == "0") then 
{
	if (_classname isKindOf "BP_HouseStorage") then { _valid = false; };
	if (_classname isKindOf "BP_HouseObject") then { _valid = false; };
};

//Not Valid Publish (Cancel and Refund)
if (!_valid) exitWith 
{
	//Publish Result Message
	BP_PublishResult = [false,_blueprint];
	(owner _playerObj) publicVariableClient "BP_PublishResult";
	
	//Refund Materials in a Pile On The Ground
	//_mats = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Materials");
	//if (_mats isEqualTo []) exitWith {};
	//_weaponHolder = createVehicle ["GroundWeaponHolder", (getPosATL _playerObj), [], 0, "CAN_COLLIDE"];
	//{ _weaponHolder addMagazineCargoGlobal [_x,1]; } count _mats;
};

//Process Materials
_hasMats = true;
_mats = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Materials");
_magazines = magazines _playerObj;
{
	_index = _magazines find _x;
	if (_index == -1) exitWith { _hasMats = false; };
	0 = _magazines deleteAt _index;
} count _mats;

//Exit If Doesn't Have Materials
if (!_hasMats) exitWith {};

//Remove Materials
{ _playerObj removeMagazineGlobal _x; } count _mats;

//Position Fixes If Glitched Underground
if ((_pos select 2) < 0) then { _pos set [2,0]; };

//Create Object
_object = createVehicle [_classname, _pos, [], 0, "CAN_COLLIDE"];
_object setDir _dir;
_object setPosATL _pos;
_object enableDynamicSimulation true;

if !(_object isKindOf "BP_SaveObject") exitWith { deleteVehicle _object; };

_object setVariable ["CharacterID",_charID];
_object setVariable ["PlayerID",_playerID];

//Safe - Lock and Set Combo
if (_object isKindOf "BP_Safe") then {
	_object setVariable ["locked",true,true];
	_object setVariable ["key",_lock,true];
};

_databasePos = _object call BP_fnc_databasePos;
_uid = [(getDir _object),(getPosATL _object)] call BPServer_fnc_objectUID;
_object setVariable ["ObjectUID",_uid];

0 = BP_serverObjectMonitor pushBack (netID _object);

["CHILD:400:%1:%2:%3:%4:%5:%6:%7:%8:'%9':%10:%11:",_classname,0,_charID,_playerID,_databasePos,[],[],0,_lock,_uid,_buildingID] call BPServer_fnc_callExtensionAsync;

["publishObj: Object %1 Published with ID %2.~0001",_classname,_uid] call BP_fnc_debugConsoleFormat;

//Check Building
if (_buildingIndex >= 0) then
{
	_buildingData = BP_BuildingsData select _buildingIndex;
	_buildingObjects = _buildingData select 0;
	_index = _buildingObjects pushBack [_object,_uid,_classname,_charID,_playerID,[(getDir _object),(getPosATL _object)],[]];
	_buildingData set [0,_buildingObjects];
	BP_BuildingsData set [_buildingIndex,_buildingData];
};

//Success Message
BP_PublishResult = [true,_blueprint];
(owner _playerObj) publicVariableClient "BP_PublishResult";

//Fuel Barrels Start Empty
if (_object isKindOf "BP_BarrelFuel") then { _object setFuelCargo 0; };

//Add the Object to Update Queue when it's published
[_object] call BPServer_fnc_updateQueueAdd;
