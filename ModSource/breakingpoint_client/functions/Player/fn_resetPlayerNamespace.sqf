/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;
_unit setVariable ["CharacterID","0"];
_unit setVariable ["killer",objNull];
//_unit setVariable ["group","0",true];
_unit setVariable ["dog",objNull];
_unit setVariable ["dogID",0];
_unit setVariable ["combattimeout",0];
_unit setVariable ["traitorFlag",false];
_unit setVariable ["med_hostage",false];

_unit removeAllEventHandlers "FiredNear";
_unit removeAllEventHandlers "HandleDamage";
_unit removeAllEventHandlers "Killed";
_unit removeAllEventHandlers "Respawn";
_unit removeAllEventHandlers "Fired";
_unit removeAllEventHandlers "GetOut";
_unit removeAllEventHandlers "GetIn";
_unit removeAllEventHandlers "Local";
_unit removeAllEventHandlers "Take";
_unit removeAllEventHandlers "Put";
_unit removeAllEventHandlers "InventoryOpened";
_unit removeAllEventHandlers "InventoryClosed";