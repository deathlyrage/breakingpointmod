/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_container","_item"];

//Debug Logging
//["onTakeItem: Unit: %1 | Container: %2 | Item: %3",_unit,_container,_item] call BP_fnc_debugConsoleFormat;

//Magazine Check
call BP_fnc_magazineCheck;

//Flag Player as Unsaved
BP_unsaved = true;