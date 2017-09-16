/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/* 
	Faction System  

	_ownerFactionName = (typeOf _storageObject) call BP_fnc_getFactionOwner;
*/

private ["_objectName","_factions","_ownerFaction"];
_objectName = _this;

_factions = getArray (configFile >> "CfgFactions" >> "factions");
_ownerFaction = "None";

{ if ([_x,_objectName,false] call BP_fnc_inString) exitWith { _x }; } count _factions;

_ownerFaction