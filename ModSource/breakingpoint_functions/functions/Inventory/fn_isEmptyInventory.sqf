/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_object",objNull]];

if (isNull _object) exitWith {true};

if (getMagazineCargo _object isEqualTo [[],[]]) exitWith {false};
if (getWeaponCargo _object isEqualTo [[],[]]) exitWith {false};
if (getItemCargo _object isEqualTo [[],[]]) exitWith {false};
if (getBackpackCargo _object isEqualTo [[],[]]) exitWith {false};

true

