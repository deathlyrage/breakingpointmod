/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Function: BP_fnc_databasePos;
	Description: Feteches a player's stored database position
	Example: player call BPServer_fnc_databasePos;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

private ["_object","_objectPos","_databasePos"];
_object = _this;

if (isNull _object) exitWith {"[]"};

_objectPos = getPosATL _object;

if (_object isKindOf "CAManBase") then {
	_isInVehicle = vehicle _object != _object;
	_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState _object) >> "onLadder")) == 1;
	if (_isInVehicle || {_onLadder}) then { if (count _objectPos > 0) then { _objectPos set [2, 0];} ; };
};

([(round(direction _object)),(_objectPos select 0),(_objectPos select 1),(_objectPos select 2)] call BP_fnc_locationToString)