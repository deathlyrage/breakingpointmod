/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_vehicle","_fuel"];

// Valid Vehicle
if (isNull _vehicle) exitWith {};

// Refueling doesn't work on remote vehicles
if (!local _vehicle) exitWith {};

// Set the Fuel Level
_vehicle setFuel _fuel;