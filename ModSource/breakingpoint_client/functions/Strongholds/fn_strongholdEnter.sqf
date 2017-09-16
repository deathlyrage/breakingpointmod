/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_factionID"];

_factionName = _factionID call BP_fnc_getFactionName;
cutText [format["Now entering %1 territory, rival factions will be shot on sight.",_factionName],"PLAIN DOWN"];