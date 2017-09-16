_unit = _this select 0;

if (_unit isKindOf "zZombie_Base") exitWith { _this call BP_fnc_zombieKilled; };