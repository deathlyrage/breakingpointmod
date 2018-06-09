/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_trap","_player"];

//["trapCollect: %1",_this] call BP_fnc_debugConsoleFormat;

if (isNull _trap) exitWith {};
if (isNull _player) exitWith {};

if (isServer) then
{
	//Create Ground Item
	_loot = createVehicle ["groundWeaponHolder", getPosATL _trap, [], 0, "CAN_COLLIDE"];
	_loot addMagazineCargoGlobal ["BP_BearTrap_Mag", 1];
	
	//Remove Trigger and Trap
	_trigger = _trap getVariable ["trigger",objNull];
	deleteVehicle _trigger;
	deleteVehicle _trap;
} else {
	_this remoteExecCall ["BP_fnc_trapCollect",2];
};