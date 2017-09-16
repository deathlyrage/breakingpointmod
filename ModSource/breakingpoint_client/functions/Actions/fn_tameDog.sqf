/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_player","_dog","_animalID","_fsmID"];
_array = _this select 3;
//_player = _array select 0;
_dog = _array select 1;

//Remove Action
player removeAction s_player_dog_tame;
s_player_dog_tame = -1;

if (isNull player) exitWith {};
if (isNull _dog) exitWith {};

_hasMeat = false;
_meatClassname = "";
_meatTypes = ["FoodMeatRaw","FoodSteakRaw","FoodMuttonRaw"];

{
	if (_x in _meatTypes) exitWith
	{
		_hasMeat = true;
		_meatClassname = _x;
	};
} count (magazines player);

if (!_hasMeat) exitWith { cutText ["You need either Raw Steak or Raw Mutton to tame this animal.","PLAIN DOWN"]; };

//Remove Meat
player removeMagazine _meatClassname;

//Save Dog's Information
_type = (typeOf _dog);
_position = (getPosATL _dog);

//Delete Dog
deleteVehicle _dog;

//Spawn a new Tamed Dog at that position
_dog = [_type,player,_position] call BP_fnc_spawnDog;

_dog setVariable ["CharacterID",BP_characterID,true];
_dogID = player getVariable "dogID";

//Force a Full Character Save After Taming
BP_SyncLastInventory = [];
BP_SyncLastStats = [];
BP_SyncLastMed = [];
BP_unsaved = true;

_dogID setFSMVariable ["_combat", 0];
_dogID setFSMVariable ["_hunger", 0];
_dogID setFSMVariable ["_thirst", 0];
_dogID setFSMVariable ["_blood", 8000];
_dogID setFSMVariable ["_zombieKills", 0];
_dogID setFSMVariable ["_playerKills", 0];

_dog setVariable ["created",true];

[_dog,player] spawn BP_fnc_dogNameSet;