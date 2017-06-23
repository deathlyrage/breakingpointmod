/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_hit","_damage","_source","_ammo"];
_isBurning = (isBurning _unit);
_burnRate = (getBurningValue _unit);

/* Burning Damage */
if (_isBurning) then {
	if (_burnRate < 0.001) then { _damage = 0; _total = 0; };
	["damageHandlerVehicle: Burn Rate: %1 | Hit: %2 | Damage: %3 #1000",_burnRate,_hit,_damage] call BP_fnc_debugConsoleFormat;
} else {
	["damageHandlerVehicle: Unit: %1 | Hit: %2 | Damage: %3 | Source: %4 | Ammo: %5 #1000",_unit,_hit,_damage,_source,_ammo] call BP_fnc_debugConsoleFormat;
};


_damage