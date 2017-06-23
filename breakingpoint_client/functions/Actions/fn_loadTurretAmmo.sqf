/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Remove Action
player removeAction s_player_loadTurretAmmo;
s_player_loadTurretAmmo = -1;

private ["_player","_vehicle","_vehicleType","_vehicleIndex","_requiredMagazine","_actualMagazine"];
_player = player;
_vehicle = (vehicle player);
_vehicleType = (typeOf _vehicle);

//Invalid Vehicle Type
if !(_vehicleType in BP_LoadObject) exitWith {};

_vehicleIndex = BP_LoadObject find _vehicleType;
_requiredMagazine = BP_LoadAmmo select _vehicleIndex;
_actualMagazine = BP_TurretAmmo select _vehicleIndex;

//Check Player Ammo
if !(_requiredMagazine in magazines player) exitWith { cutText ["You need the correct ammo type to load into this turret.","PLAIN DOWN"]; };

//Check Player Is In Turret
_inTurret = false;
_turretPath = [0];
_turretPaths = allTurrets [_vehicle,true];
{
	_local = _vehicle turretLocal _x;
	if (_local) exitWith
	{
		_inTurret = true;
		_turretPath = _x;
	};
} count _turretPaths;

if (!_inTurret) exitWith { cutText ["You need to be inside the turret to load ammo into it.","PLAIN DOWN"]; };

//Remove Ammo
player removeMagazine _requiredMagazine;

//Add Turret Ammo
_vehicle addMagazineTurret [_actualMagazine,_turretPath];
