/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_buildingNetID","_playerNetID","_type"];

_building = objectFromNetID _buildingNetID;
_player = objectFromNetID _playerNetID;

//["upgradeHouse: %1",_this] call BP_fnc_debugConsoleFormat;

//Fetch Building Data
_buildingIndex = BP_Buildings find _buildingNetID;
if (_buildingIndex == -1) exitWith {}; // Building not found
_buildingData = BP_BuildingsData select _buildingIndex;

_buildingData params ["_objects","_buildingID","_buildingUID","_playerID","_lock","_unlockAttempts","_explosive","_reinforcement"];

if (isNull _building) exitWith {};
if (isNull _player) exitWith {};

if (_type == "info") then
{
	_text = format ["Building: Reinforcement Level: %1 IED Planted: %2",_reinforcement,_explosive];
	BP_GameError = _text;
	(owner _player) publicVariableClient "BP_GameError";
};

if (_type == "reinforcement") then
{
	//Process Materials
	_hasMats = true;
	_mats = getArray (ConfigFile >> "CfgMagazines" >> "BlueprintHavenReinforce" >> "Construction" >> "Materials");
	if (_mats isEqualTo []) exitWith {};
	_magazines = magazines _player;
	{
		_index = _magazines find _x;
		if (_index == -1) exitWith { _hasMats = false; };
		0 = _magazines deleteAt _index;
	} count _mats;

	//Exit If Doesn't Have Materials
	if (!_hasMats) exitWith {};
	
	if (_reinforcement > 4) then 
	{
		//Show Msg
		BP_GameError = 12;
		(owner _player) publicVariableClient "BP_GameError";
		
		//Removed: Causes Duplication as it's already refunded on BP_GameError
		//Refund Materials in a Pile On The Ground
		//_weaponHolder = createVehicle ["GroundWeaponHolder", (getPosATL _player), [], 0, "CAN_COLLIDE"];
		//{ _weaponHolder addMagazineCargoGlobal [_x,1]; } count _mats;
		
	} else {
		//Increase Reinforcement Level
		_reinforcement = _reinforcement + 1;
		_buildingData set [7,_reinforcement];

		//Show Msg
		BP_GameError = 11;
		(owner _player) publicVariableClient "BP_GameError";
		
		//Remove Materials
		{ _player removeMagazineGlobal _x; } count _mats;
	};
};

if (_type == "explosive") then
{
	if (!_explosive) then
	{
		//Make Building Explosive
		_explosive = true;
		_buildingData set [6,_explosive];
		
		//Reset Unlock Attempts
		_unlockAttempts = 0;
		_buildingData set [5,_unlockAttempts];
		
		//Show Msg
		BP_GameError = 9;
		(owner _player) publicVariableClient "BP_GameError";
		
		//Remove IED
		_player removeMagazineGlobal "BP_IED1_Mag";
		
	} else {
		//Show Error Msg
		BP_GameError = 10;
		(owner _player) publicVariableClient "BP_GameError";
		
		//Refund Materials in a Pile On The Ground
		_weaponHolder = createVehicle ["GroundWeaponHolder", (getPosATL _player), [], 0, "CAN_COLLIDE"];
		_weaponHolder addMagazineCargoGlobal ["BP_IED1_Mag",1];
		_weaponHolder enableDynamicSimulation true;
	};
};

//Update Building Data
BP_BuildingsData set [_buildingIndex,_buildingData];
