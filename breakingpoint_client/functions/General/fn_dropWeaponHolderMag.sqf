/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_mag"];

_item = objNull;
_unitPos = position _unit;

_nearByPile = nearestObjects [_unitPos, ["WeaponHolder","WeaponHolderSimulated"],3];
if (_nearByPile isEqualTo []) then { 
    _item = createVehicle ["groundWeaponHolder", _unitPos, [], 0.0, "CAN_COLLIDE"];
} else {
    _item = _nearByPile select 0;
};

_item addMagazineCargoGlobal [_mag,1];
_item setVelocity [0,0,1];