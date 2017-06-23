/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private "_zed";
_zed = _this select 0;

//Debug Logging
//["onZombieInitialize: %1",_this] call BP_fnc_debugConsoleFormat;

//Null Checks
if (isNull _zed) exitWith {};

//Add Event Handlers - Commented Due to being in config
//_zed addEventHandler ["Local",{_this call BP_fnc_zombieLocal;}];
//_zed addEventHandler ["HandleDamage",{_this call BP_fnc_damageHandlerZ;}];
//_zed addEventHandler ["Killed",{_this call BP_fnc_zombieKilled}];

//Disable Simulation If Server
//if (isServer) then { _zed enableSimulation false; };