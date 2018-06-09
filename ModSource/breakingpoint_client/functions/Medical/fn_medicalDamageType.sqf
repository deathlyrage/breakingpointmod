/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_damage","_ammo"];
if ((_ammo isKindof "Grenade") or (_ammo isKindof "ShellBase") or  (_ammo isKindof "TimeBombCore") or (_ammo isKindof "BombCore") or (_ammo isKindof "MissileCore") or (_ammo isKindof "RocketCore") or (_ammo isKindof "FuelExplosion") or (_ammo isKindof "GrenadeBase")) exitWith {1};
if ((_ammo isKindof "B_127x107_Ball") || {_ammo isKindof "B_127x99_Ball"}) exitWith {2};
0