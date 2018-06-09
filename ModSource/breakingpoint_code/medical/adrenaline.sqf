/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_unit","_finished"];
_unit = (_this select 3) select 0;

call BP_fnc_medicalRemoveMedicActions;

if (isNull _unit) exitWith {};

["medAdrenaline",(netID _unit),(netID player)] remoteExecCall ["BPServer_fnc_medicalUpdate",2];