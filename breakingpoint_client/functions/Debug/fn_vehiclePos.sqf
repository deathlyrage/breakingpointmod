/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (!BP_Debug) exitWith {};
_pos = getPosATL (vehicle player);
_dir = getDir (vehicle player);
["Pos: %1 Dir: %2",_pos,_dir] call BP_fnc_debugConsole;