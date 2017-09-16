params ["_object"];

//Valid Object
if (isNull _object) exitWith {};

//Only Allow Locking Of Safes
if !(_object isKindOf "BP_Safe") exitWith {};

_locked = _object getVariable ["locked",false];
if !(_locked) then
{	
	//Update Inventory
	_object call BPServer_fnc_updateObjectInventory;

	//Lock Safe
	_object setVariable ["locked",true,true];
	
	//Remove Contents
	clearWeaponCargoGlobal _object;
	clearMagazineCargoGlobal _object;
	clearItemCargoGlobal _object;
	clearBackpackCargoGlobal _object;
};