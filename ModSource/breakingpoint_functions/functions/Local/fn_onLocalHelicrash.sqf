/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Function: BP_fnc_onLocalHelicrash
	Description: Called when the locality of a Helicrash changes.

private ["_unit","_local"];
_unit = _this select 0;
_local = _this select 1;

if (!(_local)) exitWith {};
if (hasInterface) exitWith {};

if (isServer) then {
	["onLocalHelicrash: A Helicrash that has become local to the server has deleted."] call BP_fnc_DebugConsoleFormat;
	_unit call BPServer_fnc_unitCleanup;
} else {
	["onLocalHelicrash: A Helicrash that has become local to the hc has been deleted."] call BP_fnc_DebugConsoleFormat;
	_unit call BP_HC_fnc_unitCleanup;
};

*/