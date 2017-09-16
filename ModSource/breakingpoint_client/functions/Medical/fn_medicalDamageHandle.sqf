/*
	Breaking Point Mod: BP_fnc_medicalDamageHandle

	Description:
		Function to assign damage handler to a unit
	Parameter(s): []
		- Unit (OBJECT)
	Returns:
		None
	Example: [player] call BP_fnc_medicalDamageHandle;
*/

params [["_unit",objNull,[objNull]]];

if (isNull _unit) exitWith {};

//Remove Old Damage Handlers
//_unit removeAllEventHandlers "Explosion";
_unit removeAllEventHandlers "HandleDamage";
_unit removeAllEventHandlers "Hit";
_unit removeAllEventHandlers "Fired";
_unit removeAllEventHandlers "Take";
_unit removeAllEventHandlers "Put";
_unit removeAllEventHandlers "InventoryOpened";
_unit removeAllEventHandlers "InventoryClosed";

//Add New Damage Handlers
//_unit addEventHandler ["Explosion",{_this call BP_fnc_damageHandlerExplosion;} ];
_unit addEventHandler ["HandleDamage",{_this call BP_fnc_damageHandler;0} ];
//_unit addEventHandler ["Hit",{_this call BP_fnc_damageHandlerHit;} ];
_unit addEventHandler ["Fired", {_this call BP_fnc_fired;}];
_unit addEventHandler ["Take", {_this call BP_fnc_onTakeItem;}];
_unit addEventHandler ["Put", {_this call BP_fnc_onPutItem;}];
_unit addEventHandler ["InventoryOpened", {_this call BP_fnc_onInventoryOpened;}];
_unit addEventHandler ["InventoryClosed", {_this call BP_fnc_onInventoryClosed;}];
_unit addEventHandler ["InventoryClosed", {_this call BP_fnc_onInventoryClosed;}];
_unit addEventHandler ["HandleRating", {0}];
