/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_audible","_caliber","_distance"];

params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile"];

["fired: Unit: %1  Weapon: %2 Muzzle: %3 Mode: %4 Ammo: %5 Mag: %6 Projectile: %7",_unit,_weapon,_muzzle,_mode,_ammo,_magazine,_projectile] call BP_fnc_debugConsoleFormat;

_unitPos = getPosATL _unit;

//Prevent Player Resting + Add Interrupt
if (r_action_rest) then { r_action_rest = false; };

//Alert Nearby
_audible = getNumber (configFile >> "CfgAmmo" >> _ammo >> "audibleFire");
_caliber = getNumber (configFile >> "CfgAmmo" >> _ammo >> "caliber");

_primary = (primaryWeapon player);
_handgun = (handgunWeapon player);

_isPrimary = (_weapon == _primary);
_isHandgun = (_weapon == _handgun);

_isSilencer = false;
_Silencer = "";

_isSubsonic = false;
if (_audible < 11) then {
	_isSubsonic = true;
};

if (_isPrimary) then {
	_primaryItems = (primaryWeaponItems player);
	{
		if (_x in Attachments_Primary_Sound) exitWith { _isSilencer = true; _Silencer = _x;};
	} count _primaryItems;
};

if (_isHandgun) then {
	_handgunItems = (handgunItems player);
	{
		if (_x in Attachments_Handgun_Sound) exitWith { _isSilencer = true; _Silencer = _x;};
	} count _handgunItems;
};

if (_isSilencer) then {
	_audible = getNumber (configFile >> "CfgWeapons" >> _Silencer >> "ClassAmmoCoef" >> "audibleFire");
};

_distance = round(_audible * 10 * _caliber);

if (_isSubsonic and _isSilencer) then {
	_distance = 0;
};

//BP_disAudial = _distance;
BP_combat = 1;

if (_ammo isKindOf "Melee"  || {_ammo isKindOf "BP_Bayonet"} || {_ammo isKindOf "BP_Stab"} || {_ammo == "zombie"}) exitWith
{
	//Fetch Config Data
	_meleeCfg = (configFile >> "CfgAmmo" >> _ammo >> "Melee");
	_anim = getText (_meleeCfg >> "anim");
	_radius = getNumber (_meleeCfg >> "radius");
	_angle = getNumber (_meleeCfg >> "angle");
	_sounds = getArray (_meleeCfg >> "sounds");
	_damageHit = getNumber (_meleeCfg >> "damageHit");
	_damageBlood = getNumber (_meleeCfg >> "damageBlood");
	
	//Gesture
	_unit playActionNow _anim;

	//Damage
	_entities = _unitPos nearEntities ["CAManBase",_radius];
	_entities append (_unitPos nearEntities ["Animal",_radius]);
	_entities append (_unitPos nearEntities ["BP_Animal",_radius]);
	
	{
		if (!isNull _x) then
		{
			_isInView = [getPos _unit, getDir _unit, _angle, getPos _x] call BIS_fnc_inAngleSector;
			if (_isInView && {_x != _unit}) then 
			{
				//Damage
				[_x,"body",_damageHit,_damageBlood,_unit,_ammo] remoteExecCall ["BP_fnc_damageEvent",2];

				//Sound
				_sound = selectRandom _sounds;
				playSound3D [(_sound select 0),_unit, false, getPosASL _unit, (_sound select 1), (_sound select 2), (_sound select 3)];
			};
		};
	} forEach _entities;
};

_zombieCheck = [_ammo,_distance,_audible,_unit,_unitPos] spawn BP_fnc_zombieFired;
[_zombieCheck] call BP_fnc_addThreadHandle;
