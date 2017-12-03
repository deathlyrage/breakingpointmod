/*
	Breaking Point Mod: BP_fnc_constructStorage

	Description:
	Function for a player to create a storage component and sumbit it for creation server side.

	Parameter(s):
	-_this select 0: Classname Of Blueprint

	Returns:
	None

	Todo:
	-Custom Sounds, Animations, Effects
*/

private ["_onLadder","_isWater","_ToolsNum","_displayMsg","_amountHas","_itemConsumeCount","_tempCount","_tempSelect","_tempConsume","_countTempConsume","_blueprint","_ObjClass","_ObjName","_Tools","_Materials","_ToolsCount","_amountNeed","_hasItems","_playerPos","_dir","_location","_dis","_sfx","_storage"];

_onLadder =	(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_isWater = (surfaceIsWater (getPosATL player));

if (_onLadder) exitWith { cutText ["You can't build while on a ladder.","PLAIN DOWN"]; };
if (_isWater) exitWith { cutText ["You can't build while in water.","PLAIN DOWN"]; };
if ((vehicle player) != player) exitWith { cutText ["You can't build while in a vehicle.", "PLAIN DOWN"]; };

_blueprint = _this select 0;

if !(_blueprint in BP_Blueprints) exitWith { ["constructStorage: Undefined Blueprint (%1)~1001",_blueprint] call BP_fnc_debugConsoleFormat; };

//Close Inventory UI
closeDialog 0;

//Can't Construct things in strongholds
if (BP_FactionStronghold > 0) exitWith {
	cutText ["Construction restricted within Faction Territory.","PLAIN DOWN"];
};

_ObjClass = getText(ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Object");
_ObjName = getText(ConfigFile >> "CfgVehicles" >> _ObjClass >> "displayName");
_Weapons = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Weapons");
_Tools = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Tools");
_Materials = getArray (ConfigFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Materials");

_ToolsCount = (count _Tools);

//Tools Required
_ToolsNum = 0;
{
	if (_x in magazines player) then { _ToolsNum = _ToolsNum + 1; };
	if (_x in items player) then { _ToolsNum = _ToolsNum + 1; };
}
count _Tools;

if (_ToolsNum < _ToolsCount) exitWith {
	cutText [format ["You don't have the necessary tools to construct a %1.",_ObjName], "PLAIN DOWN"];
};

_WeaponCount = (count _Weapons);

//Tools Required
_WeaponNum = 0;
{
	if (_x in weapons player) then {
		_WeaponNum = _WeaponNum + 1;
	};
}
count _Weapons;

if (_WeaponNum < _WeaponCount) exitWith {
	cutText [format ["You don't have the necessary weapons to construct a %1.",_ObjName], "PLAIN DOWN"];
};

//*********************************************************************************
_amountNeed = count _Materials;
_amountHas = 0;
_tempConsume = _Materials;
_countTempConsume = count _tempConsume;

while {_countTempConsume != 0} do {
    _itemConsumeCount = {_x == (_tempConsume select 0)} count _Materials;
        _tempCount = {_x == (_tempConsume select 0)} count magazines player;
    if (_tempCount >= _itemConsumeCount) then {
        _amountHas = _amountHas + _itemConsumeCount;
    };
        _tempSelect = _tempConsume select 0;
        _tempConsume = _tempConsume - [_tempSelect];
        _countTempConsume = count _tempConsume;
};

_hasItems = (_amountHas >= _amountNeed);

if !(_hasItems) exitWith {
	cutText [format ["You don't have the necessary materials to construct a %1.",_ObjName], "PLAIN DOWN"];
};

//Take Items
//{ player removeMagazine _x; } count _Materials;

//*********************************************************************************

_playerPos = getPosATL player;
_dir = round(direction player);

_location = player modelToWorld [0,0.3,0];
if ((_location select 2) < 0) then { _location set [2,0]; };

_dis=20;
[player,"tentunpack",0,false,_dis] call BP_fnc_objSpeak;
[player,_dis,true,_playerPos] spawn BP_fnc_zombieAlert;

_finished = call BP_fnc_medicAnim;
if (!_finished) exitWith {};

if (_blueprint == "BlueprintIED1") exitWith
{
	//Remove Materials
	{ player removeMagazine _x; } count _Materials;

	//Remove Tools
	{ player removeItem _x; } count _Tools;

	//Create IED
	_weaponHolder = createVehicle ["groundWeaponHolder", (getPosATL player), [], 0, "CAN_COLLIDE"];
	_weaponHolder addMagazineCargoGlobal [_ObjClass,1];
	_weaponHolder enableDynamicSimulation true;
};

if (_blueprint == "BlueprintHaven") exitWith
{
	private ["_building","_buildingPos","_inside","_type","_size","_config","_lockable","_locked"];
	_building = nearestObject [player, "HouseBase"];
	_buildingPos = getPosATL _building;
	_inside = [player,_building] call BP_fnc_isInsideBuilding;
	_type = typeOf _building;
	_size = ((sizeOf _type)+5);

	// Mission config file loot table override.
	_config = configFile >> "CfgBuildingLoot" >> _type;
	if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
	{
		_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
	};

	_lockable = (_type in BP_Houses);
	_locked = (_building getVariable ['bis_disabled_Door',0] == 1);
	_weaponHolderTypes = ["BP_LootBox","GroundWeaponHolder","WeaponHolderSimulated"];
	_weaponHolder = (_type in _weaponHolderTypes);
	_storage = false;
	_nearByObj = nearestObjects [_buildingPos, ["BP_SaveObject"],_size];
	if (count _nearByObj > 0) then { _storage = true; };

	//Error Add / Blueprint
	if (!_inside or !_lockable or _locked or _storage or _weaponHolder) exitWith
	{
		//WeaponHolder
		if (_weaponHolder) then {
			//Remove Zombies / Loot
			{deleteVehicle _x} count (_building nearEntities ["zZombie_Base",40]);
			{deleteVehicle _x} count (_building nearEntities ["BP_LootBox",40]);
			{deleteVehicle _x} count (_building nearEntities ["GroundWeaponHolder",40]);
			{deleteVehicle _x} count (_building nearEntities ["WeaponHolderSimulated",40]);

			//Message
			cutText ["Unable to detect building. Please try again in a different spot.", "PLAIN DOWN"];
		};

		//Not In Building
		if (!_inside) then { cutText ["You need to be inside the building.", "PLAIN DOWN"]; };

		//Not Lockable
		if (!_lockable) then { cutText ["You need to be in a valid building.", "PLAIN DOWN"]; };

		//Already Locked
		if (_locked) then { cutText ["This building is already locked.", "PLAIN DOWN"]; };

		//Already Storage
		if (_storage) then { cutText ["You need to remove the nearby storage objects before constructing a haven.", "PLAIN DOWN"]; };
	};

	//Get Building Passcode
	BP_SafeSet = nil;
	_safeKeyThread = [] spawn BP_fnc_safeKeypadSet;
	[_safeKeyThread] call BP_fnc_addThreadHandle;
	waitUntil {scriptDone _safeKeyThread};

	//Check If Passcode Is Correct
	if (isNil "BP_SafeSet") then { BP_SafeSet = "0"; };
	_keyArray = toArray BP_SafeSet;
	if (count _keyArray < 4) exitWith
	{
		//Rest Code
		BP_SafeSet = nil;

		//Error Message
		cutText ["Invalid Lock Code. It must be 4 numbers.", "PLAIN DOWN"];
	};

	//Claim House
	[(netID player),BP_characterID,(netID _building),BP_SafeSet,_blueprint] remoteExecCall ["BPServer_fnc_publishHouse",2];

	//Remove Zombies / Loot
	{deleteVehicle _x} count (_building nearEntities ["zZombie_Base",40]);
	{deleteVehicle _x} count (_building nearEntities ["BP_LootBox",40]);
	{deleteVehicle _x} count (_building nearEntities ["GroundWeaponHolder",40]);
	{deleteVehicle _x} count (_building nearEntities ["WeaponHolderSimulated",40]);
};

if (_blueprint == "BlueprintHavenReinforce") exitWith
{
	private ["_building","_buildingLogic","_buildingPos","_inside","_type","_size","_config","_lockable","_locked"];
	_building = nearestObject [player, "HouseBase"];
	_buildingLogic = nearestObject [player, "BP_Haven"];
	_buildingPos = getPosATL _building;
	_inside = [player,_building] call BP_fnc_isInsideBuilding;
	_type = typeOf _building;
	_size = ((sizeOf _type)+5);

	// Mission config file loot table override.
	_config = configFile >> "CfgBuildingLoot" >> _type;
	if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
	{
		_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
	};

	_lockable = (_type in BP_Houses);
	_locked = (_building getVariable ['bis_disabled_Door',0] == 1);

	_weaponHolderTypes = ["BP_LootBox","GroundWeaponHolder","WeaponHolderSimulated"];
	_weaponHolder = (_type in _weaponHolderTypes);

	//Error Add / Blueprint
	if (!_inside or !_lockable or _locked or _weaponHolder) exitWith
	{
		//WeaponHolder
		if (_weaponHolder) then {
			//Remove Zombies / Loot
			{deleteVehicle _x} count (_building nearEntities ["zZombie_Base",40]);
			{deleteVehicle _x} count (_building nearEntities ["BP_LootBox",40]);
			{deleteVehicle _x} count (_building nearEntities ["GroundWeaponHolder",40]);
			{deleteVehicle _x} count (_building nearEntities ["WeaponHolderSimulated",40]);

			//Message
			cutText ["Unable to detect building. Please try again in a different spot.", "PLAIN DOWN"];
		};

		//Not In Building
		if (!_inside) then { cutText ["You need to be inside the building.", "PLAIN DOWN"]; };

		//Not Lockable
		if (!_lockable) then { cutText ["You need to be in a valid building.", "PLAIN DOWN"]; };

		//Already Locked
		if (_locked) then { cutText ["This building is locked. You need to unlock it.", "PLAIN DOWN"]; };
	};

	[(netID _building),(netID player),"reinforcement"] remoteExecCall ["BPServer_fnc_upgradeHouse",2];
};

//Determine Faction Specific Object Name
_class = player getVariable ["class",0];
_ObjClassFaction = _ObjClass;
switch (_class) do {
	//Ranger
	case 1: { _ObjClassFaction = _ObjClassFaction + "_Ranger"};
	//Outlaw
	case 2: { _ObjClassFaction = _ObjClassFaction + "Outlaw"};
	//Hunter
	case 3: { _ObjClassFaction = _ObjClassFaction + "_Hunter"};
	//Nomad
	case 4: { _ObjClassFaction = _ObjClassFaction + "_Nomad"};
	//Survivalist
	case 5: { _ObjClassFaction = _ObjClassFaction + "_Survivalist"};
};

//Handle Faction Specific Object Name If It Exists in CfgVehicles
_hasFactionSpecific = isClass (configFile >> "CfgVehicles" >> _ObjClassFaction);
if (_hasFactionSpecific) then {_ObjClass = _ObjClassFaction; };

["%1 %2 %3",_ObjClass,_ObjClassFaction,_hasFactionSpecific] call BP_fnc_debugConsoleFormat;

//New Construction Placement Code
cutText ["Use Q and E to rotate the object then select desired action. Collision Exploiting Storage Objects is a Bannable Offense.", "PLAIN DOWN"];

//_object = createVehicleLocal [_ObjClass, _location, [], 0, "NONE"];
_object = _ObjClass createVehicleLocal _location;
_object hideObject true;
_boundingBox = boundingBox _object;
_maxPoint = ((_boundingBox select 1) select 0) max ((_boundingBox select 1) select 1);
_object attachTo [player, [0, _maxPoint + 1, ((_boundingBox select 1) select 2)]];
_object hideObject false;

player setVariable ["constructionObject",_object];
player setVariable ["constructionClassname",_ObjClass];
player setVariable ["constructionBlueprint",_blueprint];

while {!isNull (player getVariable "constructionObject")} do
{
	if (vehicle player != player) then {
		player action ["eject", vehicle player];
	};

	private "_valid";
	_valid = _object call BP_fnc_objCheck;
	if (_valid) then {
		//Green
		_object setObjectTexture [0,'#(argb,8,8,3)color(0,1,0,1)'];
		_object setObjectTexture [1,'#(argb,8,8,3)color(0,1,0,1)'];
		_object setObjectTexture [2,'#(argb,8,8,3)color(0,1,0,1)'];
		_object setObjectTexture [3,'#(argb,8,8,3)color(0,1,0,1)'];
		_object setObjectTexture [4,'#(argb,8,8,3)color(0,1,0,1)'];
		_object setObjectTexture [5,'#(argb,8,8,3)color(0,1,0,1)'];

	} else {
		//Red
		_object setObjectTexture [0,'#(argb,8,8,3)color(1,0,0,1)'];
		_object setObjectTexture [1,'#(argb,8,8,3)color(1,0,0,1)'];
		_object setObjectTexture [2,'#(argb,8,8,3)color(1,0,0,1)'];
		_object setObjectTexture [3,'#(argb,8,8,3)color(1,0,0,1)'];
		_object setObjectTexture [4,'#(argb,8,8,3)color(1,0,0,1)'];
		_object setObjectTexture [5,'#(argb,8,8,3)color(1,0,0,1)'];
	};

	sleep 0.1;
};


