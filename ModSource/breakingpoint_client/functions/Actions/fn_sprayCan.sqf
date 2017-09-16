/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_inVehicle = (vehicle player != player);
if (_inVehicle) exitWith {};
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {};

params ["_classname"];

_hasItem = (_classname in magazines player);
if (!_hasItem) exitWith {};

player removeMagazine _classname;

_config = (configFile >> "CfgMagazines" >> _classname);
_type = getText (_config >> "weapon");
_colour = getText (_config >> "colour");
_invalid = false;

_weapon = currentWeapon player;
if (_weapon == "") exitWith {};

_newClassName = format ["%1_%2",_weapon,_colour];

if !(isClass (configFile >> "CfgWeapons" >> _newClassName)) exitWith {};

//Test Functionality (TODO: Server Side Implementation)
player removeWeapon _weapon;

//Add New Weapon Skin
player addWeapon _newClassName;
