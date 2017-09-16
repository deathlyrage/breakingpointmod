private ["_amm"];
_amm=_this select 4;
_this call (call compile GetText (configFile >> "CfgAmmo" >> _amm >> "muzzleEffect"));
