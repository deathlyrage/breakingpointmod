
//Fetch Input Params
params [["_type","",[""]],"_pos","_dynamic",["_damage",0,[0]],["_fuel",0,[0]]];

//Input Checks
if (_type == "") exitWith {objNull};

//Spawn Vehicle
_vehicle = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
_vehicle enableDynamicSimulation true;

if (isNull _vehicle) exitWith {objNull};
if (!alive _vehicle) exitWith {objNull};
		
//Clear Inventory
removeAllWeapons _vehicle;
clearWeaponCargoGlobal  _vehicle;
clearMagazineCargoGlobal  _vehicle;
clearBackpackCargoGlobal _vehicle;
clearItemCargoGlobal _vehicle;

//Ensure Vehicle Is Spawned Correctly on The Ground
if (!_dynamic) then { _vehicle setVelocity [0,0,2]; };

//Ensure Damage is low enough so the vehicle doesn't explode on spawn
if (_damage > 0.85) then { _damage = 0.85; };

//Clear Ammo & Set Fuel / Damage
_vehicle setVehicleAmmo 0;
_vehicle setFuel _fuel;
_vehicle setDamage _damage;

//Enable Rope Attachment
_vehicle enableRopeAttach true;

//Generate Data
_uniqueID = [(getDir _vehicle),(getPosATL _vehicle)] call BPServer_fnc_objectUID;
_databasePos = _vehicle call BP_fnc_databasePos;
_vehicle setVariable ["ObjectUID",_uniqueID];
_databasePos = _vehicle call BP_fnc_databasePos;
_inventory = [];
_hitPoints = [];

if (_uniqueID == "0") exitWith {objNull};

//Add Vehicle to Server Monitor
0 = BP_serverObjectMonitor pushBack (netID _vehicle);

//Put Vehicle In Database
["CHILD:500:%1:%2:%3:%4:%5:%6:%7:",_type,_damage,_databasePos,_inventory,_hitPoints,_fuel,_uniqueID] call BPServer_fnc_callExtensionAsyncLow;

//Return Vehicle
_vehicle