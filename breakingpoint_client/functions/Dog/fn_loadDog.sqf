/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (_this isEqualTo []) exitWith {};

params [["_typeID",0],["_name","Dog"],["_hunger",0],["_thirst",0],["_blood",8000],["_zombieKills",0],["_playerKills",0]];

private ["_array","_typeID","_hunger","_thirst","_classname","_dog","_fsmid"];

_classname = switch (_typeID) do {
	default 	{"BP_Dog_1"};
	case 1:	{"BP_Dog_1"};
	case 2: 	{"BP_Dog_2"};
	case 3: 	{"BP_Dog_3"};
	case 4: 	{"BP_Dog_4"};
	case 5: 	{"BP_Dog_5"};
	case 6: 	{"BP_Dog_6"};
	case 7: 	{"BP_Dog_7"};
};

// Classname, Dog Owner
_dog = [_classname,player,(getPosATL player)] call BP_fnc_spawnDog;
_dog setName [_name,_name,""];
_dog setVariable ["bodyName",_name,true];
_dog setVariable ["CharacterID",BP_characterID,true];

//Delay to Ensure the FSM is spawned and setup
//sleep 2;

//Check for Invalid Blood Levels (Don't Spawn Dead Dog)
if (_blood < 1) then {
	["loadDog: Invalid Dog Data: %1",_this] call BP_fnc_debugConsoleFormat;
	_blood = 8000;
};

//Setup Inital Values
_dogID = player getVariable "dogID";

_dogID setFSMVariable ["_combat", 0];
_dogID setFSMVariable ["_hunger", _hunger];
_dogID setFSMVariable ["_thirst", _thirst];
_dogID setFSMVariable ["_blood", _blood];
_dogID setFSMVariable ["_zombieKills", _zombieKills];
_dogID setFSMVariable ["_playerKills", _playerKills];
_dog setVariable ["created",true];