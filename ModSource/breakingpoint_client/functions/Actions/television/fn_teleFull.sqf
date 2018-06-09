/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_television"];
_television = _this select 3;

_isActive = _television getVariable ["active",false];
if (!_isActive) exitWith {};

_building = nearestObject [player, "HouseBase"];
_buildingType = 	typeOf _building;
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};
_buildingLockable = (_buildingType in BP_Houses);
_buildingClaimed = ((netID _building) in BP_Buildings);
_buildingLocked = (_building getVariable ['bis_disabled_Door',0] == 1);

if (isNull _building) exitWith {};
if (_buildingLocked) exitWith {};

_pipcam = _television getVariable ["camera",objNull];
if (isNull _pipcam) exitWith {};

_pipcam cameraeffect ["internal","back"];
showcinemaborder false;
cameraEffectEnableHUD true;
vehicle cameraon switchcamera cameraview;

player setVariable ["television",_television];
