/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_trigger","_units"];

if (!isServer) exitWith {};

_trap = _trigger getVariable ["trap",objNull];
if (isNull _trap) exitWith {};

_armed = _trap getVariable ["armed",false];
if (!_armed) exitWith {};

_players = nearestObjects [getPosATL _trap, ["CAManBase"], 5];
_unit = _players select 0;

//Deactivate Trap
[_trap,objNull] call BP_fnc_trapDeactivate;

//Bear Trap Triggered If Ran Over By Animal
if (_unit isKindOf "Animal" || {_unit isKindOf "zZombie_Base"}) exitWith { _unit setDamage 1; };

//Do Medical Damage
BP_MedicalEvent = ["medBearTrap",(netID _unit),(netID _unit)];
(owner _unit) publicVariableClient "BP_MedicalEvent";
