/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_object",["_refund",true,[true]]];

if (isNull _object) exitWith {};

//Put Destroyed Item Contents On The Ground
_inventory = _object call BP_fnc_getObjectInventory;
_weaponHolder = createVehicle ["GroundWeaponHolder", (getPosATL _object), [], 0, "CAN_COLLIDE"];
if !(_inventory isEqualTo []) then {
	[_weaponHolder,_inventory] call BP_fnc_setObjectInventory;
};
_weaponHolder enableDynamicSimulation true;

//Add Materials Of Object to Weaponholder
if (_refund) then
{
	//Determine Blueprint from Object Type
	_blueprint = "";
	call
	{
		if (_object isKindOf "BP_Chest") exitWith { _blueprint = "BlueprintChest"; };
		if (_object isKindOf "BP_Refrigerator") exitWith { _blueprint = "BlueprintIceBox"; };
		if (_object isKindOf "BP_GunCabinet") exitWith { _blueprint = "BlueprintGunCab"; };
		if (_object isKindOf "BP_Stove") exitWith { _blueprint = "BlueprintStove"; };
		if (_object isKindOf "BP_Television") exitWith { _blueprint = "BlueprintTele"; };
	};
	
	//Process Refunds Based On That Blueprint
	if (_blueprint != "") then 
	{
		_mats = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Materials");

		if (_mats isEqualTo []) exitWith {};
		
		_matsRnd = (count _mats / 2);
		while {_matsRnd > 0} do
		{
			//Decrease Counter
			_matsRnd = _matsRnd - 1;
			
			//Fetch Random Magazine Material
			_selectedMag = selectRandom _mats;
			
			//Remove It From The List
			_index = _mats find _selectedMag;
			if (_index >= 0) then { _mats deleteAt _index; };
			
			//Add Magazine To Weaponholder
			_weaponHolder addMagazineCargoGlobal [_selectedMag,1];
		};
	};
};

//Destroy Object
_object setDamage 1;

/*
if (_object isKindOf "BP_Storage") then {
	[_object,"killed"] call BPServer_fnc_updateObject;
} else {
	[_object,"damage"] call BPServer_fnc_updateObject;
};
*/
