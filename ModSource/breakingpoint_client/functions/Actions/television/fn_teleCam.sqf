/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_television","_camID","_data"];

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

_totalCameraData = getArray (_buildingConfig >> "camPos");
_cameraData = _totalCameraData select _camID;

_cameraData params ["_relPos","","_pitch","_fov"];

_pos = _building modelToWorld _relPos;

_pipcam = _television getVariable ["camera",objNull];
if (isNull _pipcam) then {
	_pipcam = "camera" camCreate _pos;
	_television setVariable ["camera",_pipcam];
};

_relDir = [_pos,_building] call BIS_fnc_dirTo;
_dir = _relDir - 200;

_previousCamID = _television getVariable ["cameraID",-1];
if (_camID != _previousCamID) then
{
	_television setVariable ["cameraPos",_pos];
	_television setVariable ["cameraDir",_dir];
	_television setVariable ["cameraID",_camID];
	_television setVariable ["cameraDirMod",0];
	_television setVariable ["cameraHMod",0];
};

_renderTargetName = format ["render_%1",(netID _television)];

_actualPos = _television getVariable ["cameraPos",[0,0,0]];
_actualDir = _television getVariable ["cameraDir",0];
_modHeight = _television getVariable ["cameraHMod",0];
_modDir = _television getVariable ["cameraDirMod",0];

//Apply Height and Direction Modifiers
//_actualPos set [2,((_actualPos select 2) + _modHeight)];
_actualDir = _actualDir + _modDir;

_pipcam setPosATL _actualPos;
_pipcam setDir _actualDir;
_pipcam cameraEffect ["Internal", "Back", _renderTargetName];
_pipcam camSetFov _fov;

_pipcam camCommit 1;

[_pipcam,_modHeight,0] call bis_fnc_setpitchbank;

waitUntil {camCommitted _pipcam};

_television setObjectTexture [1, format ["#(argb,512,512,1)r2t(%1,1)",_renderTargetName]];

vehicle cameraon switchcamera cameraview;

cameraon switchcamera "internal";
