params ["_object"];

//Valid Object
if (isNull _object) exitWith {};

//Only Allow Unlocking Of Safes
if !(_object isKindOf "BP_Safe") exitWith {};

_locked = _object getVariable ["locked",false];
if (_locked) then
{
	//Remove Contents
	clearWeaponCargoGlobal _object;
	clearMagazineCargoGlobal _object;
	clearItemCargoGlobal _object;
	clearBackpackCargoGlobal _object;
	
	//Fetch Last Inventory
	_inventory = _object getVariable ["lastInventory",[]];
	
	//Setup Object Inventory
	if !(_inventory isEqualTo []) then 
	{
		//Set Object Inventory
		[_object,_inventory] call BP_fnc_setObjectInventory;
	};
	
	//Lock Safe
	_object setVariable ["locked",false,true];	
};