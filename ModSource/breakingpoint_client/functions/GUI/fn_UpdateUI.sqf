/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_UpdateUI";

private ["_id","_array"];
_array = player call BP_fnc_surfaceNoise;
BP_surfaceNoise = _array select 1;
BP_surfaceType = _array select 0;
BP_disVisual = player call BP_fnc_checkStealthVisual;
BP_disAudial = player call BP_fnc_checkStealthAudio;