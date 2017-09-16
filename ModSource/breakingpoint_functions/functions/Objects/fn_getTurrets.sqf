/*
	Author: Karel Moricky

	Description:
	Return vehicle turrets

	Parameter(s):
		0: OBJECT or STRING (classname)
		1: CONFIG or ARRAY - output type (array of config paths or IDs)

	Returns:
	ARRAT of CONFIGs or ARRAYs
*/

private ["_veh","_getTurrets","_vehConfig","_vehTurrets"];
_veh = [_this,0,objnull,[objnull,""]] call bis_fnc_param;
_returnType = [_this,1,configfile,[configfile,[]]] call bis_fnc_param;

_returnType = [typename configfile,typename []] find (typename _returnType);
_vehTurretPath = [];

if (typename _veh != typename "") then {_veh = typeof _veh;};

_getTurrets = {
	private ["_turrets","_turretPath","_turret","_hasGunner"];
	_turrets = (_this select 0) >> "turrets";
	_turretPath = _this select 1;
	if (isclass _turrets) then {
		if (count _turrets > 0) then {
			for "_t" from 0 to (count _turrets - 1) do {
				_turret = _turrets select _t;
				if (isclass _turret) then {

					_hasGunner = getnumber (_turret >> "hasGunner");
					if (_hasGunner > 0) then {
						_vehTurretPath set [count _vehTurretPath,_turretPath + [_t]];
						_vehTurrets set [count _vehTurrets,_turret];
					};

					[_turret,_turretPath + [_t]] call _getTurrets;
				};
			};
		};
	};
};

_vehConfig = configfile >> "cfgvehicles" >> _veh;
_vehTurrets = [_vehConfig];
[_vehConfig,+_vehTurretPath] call _getTurrets;

switch _returnType do {
	case 0: {_vehTurrets};
	case 1: {_vehTurretPath};
};