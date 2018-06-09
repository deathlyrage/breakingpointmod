/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

private ["_container"];
_container = BP_CurrentContainer;

if (isNull _container) exitWith {};

[(netID _container),(netID player)] remoteExecCall ["BPServer_fnc_containerTakeAll",2];
