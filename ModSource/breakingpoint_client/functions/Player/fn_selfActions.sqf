/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_vehicle","_cursorTarget","_isPlayerChar","_inVehicle","_isWater","_hasAntiB","_hasMedBackpack","_isUnconscious"];
_vehicle = vehicle player;
_cursorTarget = cursorTarget;
_isPlayerChar = (isPlayer _cursorTarget);
_inVehicle = (_vehicle != player);
_isWater = (surfaceIsWater (position player)) or BP_isSwimming;
_isStove = (_cursorTarget isKindOf "BP_Stove");
_isCookable = (inflamed _cursorTarget or _isStove);
_hasAntiB = 	"ItemAntibiotic" in magazines player;
_hasFuelE = false;
{
	if (_x in magazines player) exitWith { _hasFuelE = true; };
} count BP_FuelEmpty;

_hasFuel = false;
{
	if (_x in magazines player) exitWith { _hasFuel = true; };
} count BP_FuelFull;

_hasbottleitem = (("Waterbot" in magazines player) or ("WaterbotBoiled" in magazines player));
_hasKnife = 	"ItemKnife" in magazines player;
_hasMatches = 	"ItemMatchbox" in magazines player;
_hasBlowtorch = 	"ItemBlowtorch" in magazines player;
_hasToolbox = 	"ItemToolbox" in assignedItems player;
_hasIED = "BP_IED1_Mag" in magazines player;
_hasMedBackpack = ("BP_Mpack" == (backpack player));

_isHostage = player getVariable ["med_hostage",false];
_hasTape = (("ItemDuctTape" in magazines player) or ("ItemWaterTape" in magazines player));
_isUnconscious = r_player_unconscious;
_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_canDo = (!r_action_refuel and !r_action_gut and !r_action_siphon and !r_action_repair and !r_player_unconscious and !_onLadder);

_isHarvested = false;

// Escape Hostage
if (_isHostage and _hasKnife and !_inVehicle) then {
	if (s_player_hostageEscape < 0) then {
		s_player_hostageEscape = player addAction ["Cut Tape", { _this spawn BP_fnc_hostageEscape; },nil, 1, true, true, "", ""];
	};
} else {
	player removeAction s_player_hostageEscape;
	s_player_hostageEscape = -1;
};

// Undead Attack
//if (BP_isUndead) then
//{
//	player removeAction s_player_undeadAttack;
//	s_player_undeadAttack = -1;
//};

// Allow Level 3 Ranger to Use Med Backpack
if (_hasMedBackpack and _canDo) then {
	if (s_player_medPack < 0) then {
		s_player_medPack = player addAction ["Use Medpack (Self)", "\breakingpoint_code\medical\medpack.sqf",[player], 1, false, true, "", ""];
	};
} else {
	player removeAction s_player_medPack;
	s_player_medPack = -1;
};

// Build
_object = player getVariable ["constructionObject", objNull];
if (!isNull _object) then {
	if (s_player_buildComplete < 0) then {
		s_player_buildComplete = player addAction ["Complete Build", { [true] spawn BP_fnc_build; },nil, 1, true, true, "", ""];
	};
	if (s_player_buildCancel < 0) then {
		s_player_buildCancel = player addAction ["Cancel Build", { [false] spawn BP_fnc_build; },nil, 1, true, true, "", ""];
	};
} else {
	player removeAction s_player_buildComplete;
	s_player_buildComplete = -1;
	player removeAction s_player_buildCancel;
	s_player_buildCancel = -1;
};

// Building
_building = nearestObject [player, "HouseBase"];
_buildingType = 	typeOf _building;
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};
_buildingLockable = (_buildingType in BP_Houses);
_buildingClaimed = ((netID _building) in BP_Buildings);
_buildingLocked = (_building getVariable ['bis_disabled_Door_1',0] == 1);

//Check Building Conditions
if (!isNull _building && {!_inVehicle} && {_canDo} && {_buildingLockable} && {_buildingClaimed} && {(player distance _building) < 10}) then
{
	if (_buildingLocked) then
	{
		if (s_player_unlockHouse < 0) then {
			s_player_unlockHouse = player addAction ["Unlock Building",{ _this spawn BP_fnc_houseUnlock; },_building, 0, false, true,"",""];
		};
		player removeAction s_player_lockHouse;
		s_player_lockHouse = -1;
		player removeAction s_player_resetHouse;
		s_player_resetHouse = -1;
		player removeAction s_player_explosiveHouseAdd;
		s_player_explosiveHouseAdd = -1;
		player removeAction s_player_infoHouse;
		s_player_infoHouse = -1;
	} else {
		if (s_player_lockHouse < 0) then {
			s_player_lockHouse = player addAction ["Lock Building",{ _this spawn BP_fnc_houseLock; },_building, 0, false, true,"",""];
		};
		if (s_player_resetHouse < 0) then {
			s_player_resetHouse = player addAction ["Remove Building Lock",{ _this spawn BP_fnc_houseReset; },_building, 0, false, true,"",""];
		};
		if (s_player_infoHouse < 0) then {
			s_player_infoHouse = player addAction ["Building Info",{ _this spawn BP_fnc_houseInfo; },_building, 0, false, true,"",""];
		};

		//Check for Adding an IED
		if (_hasIED) then {
			if (s_player_explosiveHouseAdd < 0) then {
				s_player_explosiveHouseAdd = player addAction ["Add Building IED",{ _this spawn BP_fnc_houseExplosiveAdd; },_building, 0, false, true,"",""];
			};
		} else {
			player removeAction s_player_explosiveHouseAdd;
			s_player_explosiveHouseAdd = -1;
		};

		player removeAction s_player_unlockHouse;
		s_player_unlockHouse = -1;
	};
} else {
	player removeAction s_player_lockHouse;
	s_player_lockHouse = -1;
	player removeAction s_player_unlockHouse;
	s_player_unlockHouse = -1;
	player removeAction s_player_resetHouse;
	s_player_resetHouse = -1;
	player removeAction s_player_explosiveHouseAdd;
	s_player_explosiveHouseAdd = -1;
	player removeAction s_player_infoHouse;
	s_player_infoHouse = -1;
};

//Storage Object
_storage = nearestObject [player, "BP_SaveObject"];
if (_cursorTarget isKindOf "BP_SaveObject") then { _storage = _cursorTarget; };

//Clear Actions on Storage Change
if (BP_NearStorage != _storage) then
{
	BP_NearStorage = _storage;
	player removeAction s_player_inventoryObject;
	s_player_inventoryObject = -1;
	player removeAction s_player_saveObject;
	s_player_saveObject = -1;
	player removeAction s_player_igniteObject;
	s_player_igniteObject = -1;
	player removeAction s_player_destroyObject;
	s_player_destroyObject = -1;
};

//Check Storage Conditions
if (!isNull _storage and !_inVehicle and _canDo and (player distance _storage < 2)) then
{
	_isHarvested = _storage getVariable["gutted",false];
	_storageName = getText (configFile >> "CfgVehicles" >> (typeOf _storage) >> "displayName");
	_isStorage = (_storage isKindOf "BP_Storage");
	_isWorld = ((_storage isKindOf "BP_WorldStorage") or (_storage isKindOf "BP_WorldObject"));
	_isHouse = ((_storage isKindOf "BP_HouseStorage") or (_storage isKindOf "BP_HouseObject"));
	_isSafe = (_storage isKindOf "BP_Safe");
	_isTele = (_storage isKindOf "BP_Television");

	//Save Object ( Storage Objects Only )
	if (_isStorage) then
	{
		if (s_player_saveObject < 0) then {
			s_player_saveObject = player addAction [format ["Force Save %1",_storageName],{ _this spawn BP_fnc_forceSave; },_storage, 0, false, true,"",""];
		};
		if (s_player_inventoryObject < 0) then {
			s_player_inventoryObject = player addAction [format ["Inventory %1",_storageName],{ player action ["Gear", (_this select 3)]; },_storage, 0, false, true,"",""];
		};
	} else {
		player removeAction s_player_saveObject;
		s_player_saveObject = -1;
		player removeAction s_player_inventoryObject;
		s_player_inventoryObject = -1;
	};

	//Haven Television
	if (_isTele) then
	{
		_tvOn = _storage getVariable ["active",false];
		if (_tvOn) then
		{
			if (s_player_teleOff < 0) then {
				s_player_teleOff = player addAction ["Television: Turn Off", { _this spawn BP_fnc_teleOff; },_storage, 0, false, true, "", ""];
			};
			if (s_player_teleFull < 0) then {
				s_player_teleFull = player addAction ["Television: Full Screen", { _this spawn BP_fnc_teleFull; },_storage, 0, false, true, "", ""];
			};
			if (s_player_teleCam1 < 0) then {
				s_player_teleCam1 = player addAction ["Television: Camera 1", { _this spawn BP_fnc_teleCam; },[_storage,0], 0, false, true, "", ""];
			};
			if (s_player_teleCam2 < 0) then {
				s_player_teleCam2 = player addAction ["Television: Camera 2", { _this spawn BP_fnc_teleCam; },[_storage,1], 0, false, true, "", ""];
			};
			player removeAction s_player_teleOn;
			s_player_teleOn = -1;
		} else {
			if (s_player_teleOn < 0) then {
				s_player_teleOn = player addAction ["Television: Turn On", { _this spawn BP_fnc_teleOn; },_storage, 0, false, true, "", ""];
			};
			player removeAction s_player_teleOff;
			s_player_teleOff = -1;
			player removeAction s_player_teleFull;
			s_player_teleFull = -1;
			player removeAction s_player_teleCam1;
			s_player_teleCam1 = -1;
			player removeAction s_player_teleCam2;
			s_player_teleCam2 = -1;
		};
	} else {
		player removeAction s_player_teleOn;
		s_player_teleOn = -1;
		player removeAction s_player_teleOff;
		s_player_teleOff = -1;
		player removeAction s_player_teleFull;
		s_player_teleFull = -1;
		player removeAction s_player_teleCam1;
		s_player_teleCam1 = -1;
		player removeAction s_player_teleCam2;
		s_player_teleCam2 = -1;
	};

	//Ignite Object ( World Objects Only and Not Safe )
	if (_hasMatches and _isWorld and !_isSafe and !_isHarvested) then
	{
		if (s_player_igniteObject < 0) then {
			s_player_igniteObject = player addAction [format["Ignite %1",_storageName], { _this spawn BP_fnc_objectIgnite; },_storage, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_igniteObject;
		s_player_igniteObject = -1;
	};

	//Destroy Safe
	if (_hasIED and _isSafe and !_isHarvested) then
	{
		if (s_player_destroySafe < 0) then {
			s_player_destroySafe = player addAction ["Detonate IED on Safe", { _this spawn BP_fnc_explodeObject; },_storage, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_destroySafe;
		s_player_destroySafe = -1;
	};

	//Destroy Object ( House Objects Only )
	if (_isHouse) then
	{
		if (s_player_destroyObject < 0) then {
			s_player_destroyObject = player addAction [format["Destroy %1",_storageName], { _this spawn BP_fnc_objectDestroy; },_storage, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_destroyObject;
		s_player_destroyObject = -1;
	};
} else {
	player removeAction s_player_saveObject;
	s_player_saveObject = -1;
	player removeAction s_player_inventoryObject;
	s_player_inventoryObject = -1;
	player removeAction s_player_destroyObject;
	s_player_destroyObject = -1;
	player removeAction s_player_igniteObject;
	s_player_igniteObject = -1;

	player removeAction s_player_destroySafe;
	s_player_destroySafe = -1;

	player removeAction s_player_teleOn;
	s_player_teleOn = -1;
	player removeAction s_player_teleOff;
	s_player_teleOff = -1;
	player removeAction s_player_teleFull;
	s_player_teleFull = -1;
	player removeAction s_player_teleCam1;
	s_player_teleCam1 = -1;
	player removeAction s_player_teleCam2;
	s_player_teleCam2 = -1;
};

//Nearby Bodies Targeting Helper
if (isNull _cursorTarget) then {
	_bodies = nearestObjects [position player,["Man"],5];
	_index = (_bodies find player);
	if (_index > -1) then {
		0 = _bodies deleteAt _index;
	};
	if !(_bodies isEqualTo []) then { _cursorTarget = _bodies select 0; };
};

//Load Turret Vehicle Ammo
if (typeOf (vehicle player) in BP_LoadObject) then {
	if (s_player_loadTurretAmmo < 0) then {
		s_player_loadTurretAmmo = player addAction ["Load Turret Ammo", { _this spawn BP_fnc_loadTurretAmmo; }, [], 1, false, true, "", ""];
	};
} else {
	player removeAction s_player_loadTurretAmmo;
	s_player_loadTurretAmmo = -1;
};

if (!isNull _cursorTarget and !_inVehicle and (player distance _cursorTarget < 6)) then //has some kind of target
{
	_targetName = getText (configFile >> "CfgVehicles" >> (typeOf _cursorTarget) >> "displayName");
	_isHarvested = _cursorTarget getVariable ["gutted",false];
	_isVehicle = _cursorTarget isKindOf "AllVehicles";
	_isVehicletype = typeOf _cursorTarget isEqualTo "BP_Quadbike_01";
	_isMan = _cursorTarget isKindOf "Man";
	_ownerID = _cursorTarget getVariable ["CharacterID","0"];
	_isAnimal = ((_cursorTarget isKindOf "Animal") or (_cursorTarget isKindOf "Animal_Base_F") or (_cursorTarget isKindOf "BP_Dog"));
	_isZombie = (_cursorTarget isKindOf "zZombie_base");
	_isPlayer = (typeOf _cursorTarget in BP_AllPlayers);
	_isDestructable = _cursorTarget isKindOf "BuiltItems";
	_isFuel = false;
	_isAlive = alive _cursorTarget;
	_canmove = canMove _cursorTarget;
	_text = getText (configFile >> "CfgVehicles" >> typeOf _cursorTarget >> "displayName");
	_isNotDestroyed = ((damage _cursorTarget) < 1);
	_myGroupID = player getVariable ["group","0"];
	_targetGroupID = _cursorTarget getVariable ["group","0"];
	_isInMyGroup = ((_myGroupID == _targetGroupID) and (_myGroupID != "0") and (_targetGroupID != "0"));
	_isTargetUnconscious = _cursorTarget getVariable ["med_unconscious", false];
	_isTargetHostage = _cursorTarget getVariable ["med_hostage", false];
	_lowBlood = _cursorTarget getVariable ["med_lowBlood", false];
	_isUndead = (player getVariable ["class",0] == 7);
	_targetUndead = (_cursorTarget getVariable ["class",0] == 7);
	_sameFaction = false;
	if(BP_Factions_disableMixedgrouping) then
	{
		_playerClass = player getVariable ["class",0];
		_cursorTargetClass =_cursorTarget getVariable ["class",0];
		if (_playerClass in [0,3] && _cursorTargetClass in [0,3]) then
		{
			_sameFaction = true;
		}
		else
		{
			if (_playerClass in [1,4,5] && _cursorTargetClass in [1,4,5]) then
			{
				_sameFaction = true;
			}
			else
			{
				if (_playerClass == 2 && _cursorTargetClass == 2) then
				{
					_sameFaction = true;
				}
				else
				{
					_sameFaction = false;
				};
			};
		};
	}
	else
	{
		_sameFaction = true;
	};
	

	//Dog
	_isDog = (_cursorTarget isKindOf "BP_Dog");

	//Safe
	_isSafe = _cursorTarget isKindOf "BP_Safe";
	_safeLocked = (_cursorTarget getVariable ["locked",false]);

	_rawmeat = meatraw;
	_hasRawMeat = false;
	{ if (_x in magazines player) exitWith { _hasRawMeat = true; }; } count _rawmeat;

	if (_hasFuelE) then {
		_isFuel = false;
		if (_cursorTarget isKindOf "Land_FuelStation_Feed_F") then { _isFuel = true };
		if (_cursorTarget isKindOf "Land_Tank_rust_F") then { _isFuel = true };
		if (_cursorTarget isKindOf "Land_fs_feed_F") then { _isFuel = true };
	};

	// Dog
	if (_isDog and _isAlive and (_hasRawMeat) and _canDo and _ownerID == "0" and player getVariable ["dogID", 0] == 0) then {
		if (s_player_dog_tame < 0) then {
			s_player_dog_tame = player addAction ["Tame Dog", { _this spawn BP_fnc_tameDog; }, [player,_cursorTarget], 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_dog_tame;
		s_player_dog_tame = -1;
	};

	// Dog
	if (_isDog and _isAlive and _lowBlood and _canDo) then {
		if (s_player_dog_heal < 0) then {
			s_player_dog_heal = player addAction ["Dog: Perform Operation", "\breakingpoint_code\medical\surgerykit.sqf",[_cursorTarget], 0, true, true, "", "'ItemSurgeryKit' in assignedItems player"];
		};
	} else {
		player removeAction s_player_dog_heal;
		s_player_dog_heal = -1;
	};

	if (_isDog and _ownerID == BP_characterID and _isAlive and _canDo) then
	{
		_dogHandle = player getVariable ["dogID", 0];
		if (s_player_dog_food < 0 and _hasRawMeat) then {
			s_player_dog_food = player addAction ["Dog: Give Food",{ _this spawn BP_fnc_dogFeed; },[_cursorTarget,_dogHandle,0], 0, false, true,"",""];
		};
		if (s_player_dog_water < 0 and _hasbottleitem) then {
			s_player_dog_water = player addAction ["Dog: Give Water",{ _this spawn BP_fnc_dogFeed; },[_cursorTarget,_dogHandle,1], 0, false, true,"",""];
		};
		if (s_player_dog_track < 0) then {
			s_player_dog_track = player addAction ["Dog: Track Animal",{ _this spawn BP_fnc_dogTrackAnimal; }, [_cursorTarget,_dogHandle], 4, false, true,"",""];
		};
		if (s_player_dog_speak < 0) then {
			s_player_dog_speak = player addAction ["Dog: Speak",{ _this spawn BP_fnc_dogSpeak; }, [_cursorTarget,_dogHandle], 3, false, true,"",""];
		};
		//if (s_player_dog_warn < 0) then {
		//	_warn = _dogHandle getFSMVariable "_watchDog";
		//	if (_warn) then { _text = "Quiet"; _warn = false; } else { _text = "Alert"; _warn = true; };
		//	s_player_dog_warn = player addAction [format["%1",_text],{ _this spawn BP_fnc_dogWarn; },[_cursorTarget,_dogHandle, _warn], 2, false, true,"",""];
		//};
		if (s_player_dog_follow < 0) then {
			s_player_dog_follow = player addAction ["Dog: Follow",{ _this spawn BP_fnc_dogFollow; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		//Faction Specific Actions
		/*
		if (s_player_dog_ranger_alertPlayer < 0) then {
			s_player_dog_ranger_alertPlayer = player addAction ["Dog: Alert Player",{ _this spawn BP_fnc_dogAlertPlayer; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		if (s_player_dog_ranger_alertGroup < 0) then {
			s_player_dog_ranger_alertGroup = player addAction ["Dog: Alert Group",{ _this spawn BP_fnc_dogAlertGroup;; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		if (s_player_dog_hunter_trackPlayer < 0) then {
			s_player_dog_hunter_trackPlayer = player addAction ["Dog: Track Player",{ _this spawn BP_fnc_dogFollow; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		if (s_player_dog_outlaw_alertStorage < 0) then {
			s_player_dog_outlaw_alertStorage = player addAction ["Dog: Alert Storage",{ _this spawn BP_fnc_dogFollow; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		if (s_player_dog_outlaw_alertVehicle < 0) then {
			s_player_dog_outlaw_alertVehicle = player addAction ["Dog: Alert Vehicle",{ _this spawn BP_fnc_dogFollow; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		if (s_player_dog_survivalist_heal < 0) then {
			s_player_dog_survivalist_heal = player addAction ["Dog: Heal From Medpack",{ _this spawn BP_fnc_dogFollow; },[_cursorTarget,_dogHandle,true], 6, false, true,"",""];
		};
		*/
	} else {
		player removeAction s_player_dog_food;
		s_player_dog_food = -1;
		player removeAction s_player_dog_water;
		s_player_dog_water = -1;
		player removeAction s_player_dog_track;
		s_player_dog_track = -1;
		player removeAction s_player_dog_speak;
		s_player_dog_speak = -1;
		player removeAction s_player_dog_warn;
		s_player_dog_warn = -1;
		player removeAction s_player_dog_follow;
		s_player_dog_follow = -1;

		//player removeAction s_player_dog_ranger_alertPlayer;
		//s_player_dog_ranger_alertPlayer = -1;
		//player removeAction s_player_dog_ranger_alertGroup;
		//s_player_dog_ranger_alertGroup = -1;
		//player removeAction s_player_dog_hunter_trackPlayer;
		//s_player_dog_hunter_trackPlayer = -1;
		//player removeAction s_player_dog_outlaw_alertStorage;
		//s_player_dog_outlaw_alertStorage = -1;
		//player removeAction s_player_dog_outlaw_alertVehicle;
		//s_player_dog_outlaw_alertVehicle = -1;
		//player removeAction s_player_dog_survivalist_heal;
		//s_player_dog_survivalist_heal = -1;
	};

	//Towing
	/*
	if ((_isVehicle) and _canDo and !_isMan and _isNotDestroyed) then
	{
		//Set Tow Source
		if (isNull BP_TowSource) then
		{
			if (s_player_towSource < 0) then {
				s_player_towSource = player addAction [format ["Tow Vehicle: Source (%1)",_targetName], { _this call BP_fnc_towSource; },_cursorTarget, 1, false, true, "", ""];
			};
		} else {
			player removeAction s_player_towSource;
			s_player_towSource = -1;
		};

		//Set Tow Target
		if (isNull BP_TowTarget) then
		{
			if (s_player_towTarget < 0) then {
				s_player_towTarget = player addAction [format ["Tow Vehicle: Target (%1)",_targetName], { _this call BP_fnc_towTarget; },_cursorTarget, 1, false, true, "", ""];
			};
		} else {
			player removeAction s_player_towTarget;
			s_player_towTarget = -1;
		};

		_towRope = _cursorTarget getVariable ["tow",objNull];
		if (isNull _towRope) then
		{
			if (s_player_towStart < 0) then {
				s_player_towStart = player addAction [format ["Tow Vehicle: Start",_targetName], { _this call BP_fnc_towStart; },_cursorTarget, 1, false, true, "", ""];
			};
			player removeAction s_player_towEnd;
			s_player_towEnd = -1;
		} else {
			if (s_player_towEnd < 0) then {
				s_player_towEnd = player addAction [format ["Tow Vehicle: Stop",_targetName], { _this call BP_fnc_towEnd; },_cursorTarget, 1, false, true, "", ""];
			};
			player removeAction s_player_towStart;
			s_player_towStart = -1;
		};
	} else {
		player removeAction s_player_towSource;
		s_player_towSource = -1;
		player removeAction s_player_towTarget;
		s_player_towTarget = -1;
		player removeAction s_player_towStart;
		s_player_towStart = -1;
		player removeAction s_player_towEnd;
		s_player_towEnd = -1;
	};
	*/

	// Force Save (Vehicle)
	if (_isVehicle and _canDo and !_isMan and _isNotDestroyed) then {
		if (s_player_saveVehicle < 0) then {
			s_player_saveVehicle = player addAction [format ["Force Save %1",_targetName], { _this call BP_fnc_forceSave; },_cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_saveVehicle;
		s_player_saveVehicle = -1;
	};

	// Push Vehicle
	if (_isVehicle and _canDo and !_isMan and _isNotDestroyed) then {
		if (s_player_pushBoat < 0) then {
			s_player_pushBoat = player addAction [format ["Push Vehicle %1",_targetName], { _this spawn BP_fnc_pushBoat; },_cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_pushBoat;
		s_player_pushBoat = -1;
	};


	//Destroy Vehicle
	if (_hasIED and _isVehicle and _isNotDestroyed) then
	{
		if (s_player_destroyVehicle < 0) then {
			s_player_destroyVehicle = player addAction ["Detonate IED on Vehicle", { _this spawn BP_fnc_explodeObject; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_destroyVehicle;
		s_player_destroyVehicle = -1;
	};

	// Safe Actions
	if (_isSafe and _canDo) then
	{
		//Lock Safe
		if (!_safeLocked) then {
			if (s_player_safeLock < 0) then {
				s_player_safeLock = player addAction ["Lock Safe", { _this call BP_fnc_safeLock; },_cursorTarget, 1, false, true, "", ""];
			};
		} else {
			player removeAction s_player_safeLock;
			s_player_safeLock = -1;
		};
	} else {
		player removeAction s_player_safeLock;
		s_player_safeLock = -1;
	};

	/* Add To Group */
	if (_isPlayer and !_isInMyGroup and !_isUndead and !_targetUndead and _isAlive and _isPlayerChar and _canDo and _sameFaction) then {
		if (s_player_groupAdd < 0) then {
			s_player_groupAdd = player addAction ["Add To Group", { _this call BP_fnc_groupAdd; },_cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_groupAdd;
		s_player_groupAdd = -1;
	};

	/* Take Hostage */
	if (_isPlayer and !_isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isHostage and _hasTape and !_isUnconscious and _isPlayerChar and _canDo) then {
		if (s_player_hostageAdd < 0) then {
			s_player_hostageAdd = player addAction ["Take Hostage", { _this spawn BP_fnc_hostageAdd; },_cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_hostageAdd;
		s_player_hostageAdd = -1;
	};

	/* Release Hostage */
	if (_isPlayer and _isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isHostage and _isPlayerChar and _canDo) then {
		if (s_player_hostageDel < 0) then {
			s_player_hostageDel = player addAction ["Release Hostage", { _this spawn BP_fnc_hostageDel; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_hostageDel;
		s_player_hostageDel = -1;
	};

	/* Hostage Food */
	if (_isPlayer and _isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isWater and !_isHostage and _isPlayerChar and _canDo) then {
		if (s_player_hostageFood < 0) then {
			s_player_hostageFood = player addAction ["Give Food", { _this spawn BP_fnc_hostageFood; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_hostageFood;
		s_player_hostageFood = -1;
	};

	/* Hostage Water */
	if (_isPlayer and _isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isWater and !_isHostage and _isPlayerChar and _canDo) then {
		if (s_player_hostageWater < 0) then {
			s_player_hostageWater = player addAction ["Give Water", { _this spawn BP_fnc_hostageWater; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_hostageWater;
		s_player_hostageWater = -1;
	};

	/* Player Food */
	if (_isPlayer and !_isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isWater and !_isHostage and _isPlayerChar and _canDo) then {
		if (s_player_playerFood < 0) then {
			s_player_playerFood = player addAction ["Give Food", { _this spawn BP_fnc_playerFood; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_playerFood;
		s_player_playerFood = -1;
	};

	/* Player Water */
	if (_isPlayer and !_isTargetHostage and !_isUndead and !_targetUndead and _isAlive and !_isWater and !_isHostage and _isPlayerChar and _canDo) then {
		if (s_player_playerWater < 0) then {
			s_player_playerWater = player addAction ["Give Water", { _this spawn BP_fnc_playerWater; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		player removeAction s_player_playerWater;
		s_player_playerWater = -1;
	};

	/* Flip Vehicle */
	if ((_isVehicletype) and !_canmove and _canDo and _isAlive and !_isWater and !_isHostage and (player distance _cursorTarget >= 2) and (count (crew _cursorTarget))== 0 and ((vectorUp _cursorTarget) select 2) < 0.5) then {
		if (s_player_flipveh  < 0) then {
			s_player_flipveh = player addAction [format["Flip %1",_targetName], {_this spawn BP_fnc_flipVehicle; },_cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_flipveh;
		s_player_flipveh = -1;
	};

	// Fill Fuel Can
	if (_isFuel && {_hasFuelE} && {!_isZombie} && {!_isAnimal} && {!_isHostage} && {!_isMan} && {_canDo} && {damage _cursorTarget < 1}) then {
		if (s_player_fillfuel < 0) then {
			s_player_fillfuel = player addAction ["Fill Fuelcan", { _this spawn BP_fnc_fuelFill; },[], 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_fillfuel;
		s_player_fillfuel = -1;
	};

	//Siphon vehicles
	if (_isVehicle && {_hasFuelE} && {!(_cursorTarget isKindOf "Bicycle_F")} && {_canDo} && {fuel _cursorTarget > 0} && {damage _cursorTarget < 1} && {!(count (crew _cursorTarget)> 0)}) then {
		if (s_player_siphonfuel < 0) then {
			s_player_siphonfuel = player addAction [format["Siphon %1",_targetName],{ _this spawn BP_fnc_siphonFuel; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		if (_cursorTarget isKindOf "BP_BarrelFuel" and _canDo and (getFuelCargo _cursorTarget > 0) and (damage _cursorTarget < 1)) then
		{
			if (s_player_siphonfuel < 0) then {
				s_player_siphonfuel = player addAction [format["Siphon %1",_targetName],{ _this spawn BP_fnc_siphonFuel; },_cursorTarget, 0, false, true, "", ""];
			};
		} else {
			player removeAction s_player_siphonfuel;
			s_player_siphonfuel = -1;
		};
	};

	//Refuel Vehicles
	if (_isVehicle && {_hasFuel} && {!(_cursorTarget isKindOf "Bicycle_F")} && {fuel _cursorTarget < 1} && {damage _cursorTarget < 1} && {!(count (crew _cursorTarget)> 0)}) then {
		if (s_player_refuelVeh < 0) then {
			s_player_refuelVeh = player addAction [format["Refuel %1",_targetName], { _this spawn BP_fnc_refuel; },_cursorTarget, 0, false, true, "", ""];
		};
	} else {
		if (_cursorTarget isKindOf "BP_BarrelFuel" and _canDo and (getFuelCargo _cursorTarget < 1) and (damage _cursorTarget < 1)) then
		{
			if (s_player_refuelVeh < 0) then {
				s_player_refuelVeh = player addAction [format["Refuel %1",_targetName], { _this spawn BP_fnc_refuel; },_cursorTarget, 0, false, true, "", ""];
			};
		} else {
			player removeAction s_player_refuelVeh;
			s_player_refuelVeh = -1;
		};
	};

	/* Med Pack */

	/* Gut Player / Animal / Hostage / Zombie */
	_canGut = (!_isAlive or _isTargetUnconscious or _isTargetHostage);
	if (_canGut and (_isAnimal or _isZombie or _isPlayer) and !_isHarvested and _hasKnife and _canDo) then {
		if (s_player_butcher < 0) then {
			_text = "Gut Body";
			if (_isAnimal) then { _text = "Gut Animal"; };
			if (_isZombie) then { _text = "Gut Zombie"; };
			if (_isPlayer) then { _text = "Gut Player"; };
			if (_isTargetHostage) then { _text = "Gut Hostage"; };
			s_player_butcher = player addAction [_text, { _this spawn BP_fnc_gatherMeat; },_cursorTarget, 3, false, true, "", ""];
		};
	} else {
		player removeAction s_player_butcher;
		s_player_butcher = -1;
	};

	/* Cooking */
	if (_isCookable && {_hasRawMeat} && {!_isHostage} && {_canDo}) then {
		if (s_player_cook < 0) then {
			s_player_cook = player addAction ["Cook Meat", { _this spawn BP_fnc_cook; },_cursorTarget, 3, false, true, "", ""];
		};
	} else {
		player removeAction s_player_cook;
		s_player_cook = -1;
	};

	// Boil water
	if (_isCookable && {("Waterbot" in magazines player)} && {!_isHostage} && {_canDo}) then {
		if (s_player_boil < 0) then {
			s_player_boil = player addAction ["Boil Water", { _this spawn BP_fnc_boil; },_cursorTarget, 3, false, true, "", ""];
		};
	} else {
		player removeAction s_player_boil;
		s_player_boil = -1;
	};

	//Destroy Fire
	if (_cursorTarget == BP_hasFire && {_canDo}) then {
		if ((s_player_fireout < 0) and !(inflamed _cursorTarget) and _canDo and (player distance _cursorTarget < 4)) then {
			s_player_fireout = player addAction ["Destroy Fire", { _this spawn BP_fnc_firePack; },_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_fireout;
		s_player_fireout = -1;
	};

	// Vehicle Repar / Replace / Remove
	if ((BP_myCursorTarget != _cursorTarget) and _isVehicle and !_isUndead and _canDo and !_isMan and _hasToolbox and (count (crew _cursorTarget))== 0 and (damage _cursorTarget < 1)) then
	{
		_vehicle = _cursorTarget;

		{BP_myCursorTarget removeAction _x} count s_player_repairActions;
		s_player_repairActions = [];

		{BP_myCursorTarget removeAction _x} count s_player_removeActions;
		s_player_removeActions = [];

		BP_myCursorTarget = _vehicle;

		_hitpoints = _vehicle call BP_fnc_vehicleHitpoints;
		{
			_damage = _vehicle getHitPointDamage _x;
			_part = "";
			_repair = "";

			//change "HitPart" to " - Part" rather than complicated string replace
			_cmpt = toArray (_x);
			_cmpt set [0,20];
			_cmpt set [1,toArray ("-") select 0];
			_cmpt set [2,20];
			_cmpt = toString _cmpt;

			_canRemove = true;

			if(["Avionics",_x,false] call BP_fnc_inString) then {
				_part = "ItemElectronics";
				_repair = "ItemElectricalWire";
				_canRemove = false;
			};

			if(["Body",_x,false] call BP_fnc_inString) then {
				_part = "PartFiberGlass";
				_repair = "ItemDuctTape";
				_canRemove = false;
			};

			if(["Hull",_x,false] call BP_fnc_inString) then {
				_part = "PartFiberGlass";
				_repair = "ItemDuctTape";
				_canRemove = false;
			};

			if(["Engine",_x,false] call BP_fnc_inString) then {
				_part = "PartEngine";
				_repair = "ItemEngineCoolant";
			};

			if(["Rotor",_x,false] call BP_fnc_inString) then {
				_part = "ItemHydraulicCylinder";
				_repair = "ItemLubricant";
			};

			if(["Fuel",_x,false] call BP_fnc_inString) then {
				_part = "ItemFuelhoseKit";
				_repair = "ItemWaterTape";
			};

			if(["Wheel",_x,false] call BP_fnc_inString) then {
				_part = "PartWheel";
				_repair = "ItemPunctureKit";
			};

			if(["Glass",_x,false] call BP_fnc_inString) then {
				_part = "PartGlass";
				_repair = "ItemLiquidResin";
			};
			if(["Battery",_x,false] call BP_fnc_inString) then {
				_part = "ItemBattery";
				_repair = "ItemBattery"; //ItemChargerKit
			};

			//_color = "color='#ffffff'"; //White
			_color = "color='#ff8800'";
			if (_damage >= 0.4) then {_color = "color='#ff8800'";}; //orange
			if (_damage >= 0.6) then {_color = "color='#ff0000'";}; //red

			if (_damage > 0) then
			{
				_allFixed = false;

				// Repair
				if (_damage < 0.6) then
				{
					if !(_repair == "") then
					{
						_string = format["<t %2>Repair%1</t>",_cmpt,_color]; //Repair - Part
						_handle = BP_myCursorTarget addAction [_string, { _this spawn BP_fnc_repair; },[_vehicle,_repair,_x], 0, false, true, "",""];
						0 = s_player_repairActions pushBack _handle;
					};
				};

				// Replace
				if !(_part == "") then
				{
					_string = format["<t %2>Replace%1</t>",_cmpt,_color]; //Replace - Part
					_handle = BP_myCursorTarget addAction [_string, { _this spawn BP_fnc_repair; },[_vehicle,_part,_x], 0, false, true, "",""];
					0 = s_player_repairActions pushBack _handle;
				};

			} else {
				if (_canRemove) then {
					_invalidVehicle = (_vehicle isKindOf "Motorcycle") or (_vehicle isKindOf "Tractor");
					if (!_invalidVehicle) then {
						_string = format["<t color='#00b34a'>Remove%1</t>",_cmpt,_color]; //Remove - Part
						_handle = BP_myCursorTarget addAction [_string, { _this spawn BP_fnc_partRemove; },[_vehicle,_part,_x], 0, false, true, "",""];
						0 = s_player_repairActions pushBack _handle;
					};
				};
			};
		} count _hitpoints;
	};

	if (!_isMan && {_cursorTarget isKindOf "BP_DeadBody"} && {_canDo}) then
	{
		if (s_player_destroyGrave < 0) then {
			s_player_destroyGrave = player addAction ["Destroy Body", { deleteVehicle (_this select 3); player removeAction s_player_destroyGrave; s_player_destroyGrave = -1; },_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_destroyGrave;
		s_player_destroyGrave = -1;
	};

	//Hide Bodies
	if (_isMan && {!_isAlive} && {_canDo} && {!_isAnimal}) then {
		if (s_player_hidebody < 0) then {
			s_player_hidebody = player addAction ["Hide Remains", { _this spawn BP_fnc_hideBody; },_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_hidebody;
		s_player_hidebody = -1;
	};

	//Ignite Entites
	_manOrVehicle = (_isMan or _isVehicle);
	if (_manOrVehicle && {_canDo} && {_hasFuel} && {_hasMatches} && {!_isHarvested}) then
	{
		_text = "Person";

		call
		{
			if (_isZombie) exitWith { _text = "Zombie"; };
			if (_isAnimal) exitWith { _text = "Animal"; };
			if (_isPlayer) exitWith { _text = "Player"; };
			if (_isTargetHostage) exitWith { _text = "Hostage"; };
			if (_isVehicle) exitWith { _text = "Vehicle"; };
		};

		if (s_player_igniteEntity < 0) then {
			s_player_igniteEntity = player addAction [format ["Ignite %1",_text], { _this spawn BP_fnc_entityIgnite; },_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_igniteEntity;
		s_player_igniteEntity = -1;
	};

	//_canGut = (!_isAlive or _isTargetUnconscious or _isTargetHostage);
	//if (_canGut and (_isAnimal or _isZombie or _isPlayer) and !_isHarvested and _hasKnife and _canDo) then {
	//	if (s_player_butcher < 0) then {
	//		_text = "Gut Body";
	//		if (_isAnimal) then { _text = "Gut Animal"; };
	//		if (_isZombie) then { _text = "Gut Zombie"; };
	//		if (_isPlayer) then { _text = "Gut Player"; };
	//		if (_isTargetHostage) then { _text = "Gut Hostage"; };
	//		s_player_butcher = player addAction [_text, { _this spawn BP_fnc_gatherMeat; },_cursorTarget, 3, false, true, "", ""];
	//	};
	//} else {
	//	player removeAction s_player_butcher;
	//	s_player_butcher = -1;
	//};

	//Study / Loot / Hide Bodies
	if (_isMan && {!_isAlive} && {_canDo} && {!_isZombie} && {!_isAnimal}) then {
		if (s_player_studybody < 0) then {
			s_player_studybody = player addAction ["Study Remains", { _this spawn BP_fnc_studyBody; },_cursorTarget, 0, false, true, "",""];
		};
		if (s_player_lootbody < 0) then {
			s_player_lootbody = player addAction ["Loot Remains", { _this spawn BP_fnc_lootBody; },_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_studybody;
		s_player_studybody = -1;
		player removeAction s_player_lootbody;
		s_player_lootbody = -1;
	};

	//Harvest Remains (Undead)
	// if (_isMan and !_isAlive and _canDo and !_isZombie and !_isAnimal and _isUndead and !_targetUndead) then
	// {
	// 	if (s_player_eatbody < 0) then {
	// 		s_player_eatbody = player addAction ["Harvest Remains", { _this spawn BP_fnc_eatBody; },_cursorTarget, 0, false, true, "",""];
	// 	};
	// } else {
	// 	player removeAction s_player_eatbody;
	// 	s_player_eatbody = -1;
	// };

} else {
	//Vehicle Remove Actions
	{BP_myCursorTarget removeAction _x} count s_player_removeActions;
	s_player_removeActions = [];
	//Vehicle Repair Actions
	{BP_myCursorTarget removeAction _x} count s_player_repairActions;
	s_player_repairActions = [];
	//Cursor Target
	BP_myCursorTarget = objNull;
	//Others
	player removeAction s_player_saveVehicle;
	s_player_saveVehicle = -1;
	player removeAction s_player_pushBoat;
	s_player_pushBoat = -1;
	player removeAction s_player_groupAdd;
	s_player_groupAdd = -1;
	player removeAction s_player_groupDel;
	s_player_groupDel = -1;
	player removeAction s_player_hostageAdd;
	s_player_hostageAdd = -1;
	player removeAction s_player_hostageDel;
	s_player_hostageDel = -1;
	player removeAction s_player_hostageFood;
	s_player_hostageFood = -1;
	player removeAction s_player_hostageWater;
	s_player_hostageWater = -1;
	player removeAction s_player_playerFood;
	s_player_playerFood = -1;
	player removeAction s_player_playerWater;
	s_player_playerWater = -1;
	player removeAction s_player_flipveh;
	s_player_flipveh = -1;
	player removeAction s_player_sleep;
	s_player_sleep = -1;
	player removeAction s_player_saveVehicle;
	s_player_saveVehicle = -1;
	player removeAction s_player_butcher;
	s_player_butcher = -1;
	player removeAction s_player_cook;
	s_player_cook = -1;
	player removeAction s_player_boil;
	s_player_boil = -1;
	player removeAction s_player_fireout;
	s_player_fireout = -1;
	player removeAction s_player_fillfuel;
	s_player_fillfuel = -1;
	player removeAction s_player_studybody;
	s_player_studybody = -1;
	player removeAction s_player_lootbody;
	s_player_lootbody = -1;
	player removeAction s_player_hidebody;
	s_player_hidebody = -1;
	player removeAction s_player_eatbody;
	s_player_eatbody = -1;
	player removeAction s_player_destroyGrave;
	s_player_destroyGrave = -1;
	player removeAction s_player_siphonfuel;
	s_player_siphonfuel = -1;
	player removeAction s_player_refuelVeh;
	s_player_refuelVeh = -1;

	//Towing
	//player removeAction s_player_towSource;
	//s_player_towSource = -1;
	//player removeAction s_player_towTarget;
	//s_player_towTarget = -1;
	//player removeAction s_player_towStart;
	//s_player_towStart = -1;
	//player removeAction s_player_towEnd;
	//s_player_towEnd = -1;

	//Ignite
	player removeAction s_player_igniteEntity;
	s_player_igniteEntity = -1;

	//Destroy Vehicle
	player removeAction s_player_destroyVehicle;
	s_player_destroyVehicle = -1;

	//Dog
	player removeAction s_player_dog_tame;
	s_player_dog_tame = -1;
	player removeAction s_player_dog_heal;
	s_player_dog_heal = -1;
	player removeAction s_player_dog_food;
	s_player_dog_food = -1;
	player removeAction s_player_dog_water;
	s_player_dog_water = -1;
	player removeAction s_player_dog_track;
	s_player_dog_track = -1;
	player removeAction s_player_dog_speak;
	s_player_dog_speak = -1;
	player removeAction s_player_dog_warn;
	s_player_dog_warn = -1;
	player removeAction s_player_dog_follow;
	s_player_dog_follow = -1;

	//player removeAction s_player_dog_ranger_alertPlayer;
	//s_player_dog_ranger_alertPlayer = -1;
	//player removeAction s_player_dog_ranger_alertGroup;
	//s_player_dog_ranger_alertGroup = -1;
	//player removeAction s_player_dog_hunter_trackPlayer;
	//s_player_dog_hunter_trackPlayer = -1;
	//player removeAction s_player_dog_outlaw_alertStorage;
	//s_player_dog_outlaw_alertStorage = -1;
	//player removeAction s_player_dog_outlaw_alertVehicle;
	//s_player_dog_outlaw_alertVehicle = -1;
	//player removeAction s_player_dog_survivalist_heal;
	//s_player_dog_survivalist_heal = -1;

	//Safe
	player removeAction s_player_safeLock;
	s_player_safeLock = -1;
};

//Air Actions (Eject / Parachute)
_inAirVehicle = ((vehicle player) isKindOf "Air");
if (_inAirVehicle) then
{
	if (s_player_ejectParacute < 0) then {
		s_player_ejectParacute = player addAction ["Eject (Parachute)", { _this spawn BP_fnc_ejectParachute; },_cursorTarget, 1, false, true, "", ""];
	};
} else {
	player removeAction s_player_ejectParacute;
	s_player_ejectParacute = -1;
};

//Dog actions on player self
_dogHandle = player getVariable ["dogID", 0];
if (_dogHandle > 0 and !_inVehicle) then
{
	_dog = player getVariable ["dog",objNull];
	_ownerID = _dog getVariable ["CharacterID","0"];

	if (_canDo and alive _dog and _ownerID == BP_characterID) then
	{
		if (s_player_dog_call < 0) then {
			s_player_dog_call = player addAction ["Dog: Call", { _this spawn BP_fnc_dogFollow; },[_dog,_dogHandle,true], 2, false, true, "", ""];
		};
		if (s_player_dog_stay < 0) then {
			s_player_dog_stay = player addAction ["Dog: Stay",{ _this spawn BP_fnc_dogStay; }, [_dog,_dogHandle], 2, false, true,"",""];
		};
		if (s_player_dog_combat < 0) then {
			_combatMode = _dogHandle getFSMVariable "_combat";
			_nextMode = 0;
			_text = "Passive";
			//Aggressive
			if (_combatMode == 2) then {
				_text = "Aggressive";
				_nextMode = 0;
			};
			//Defensive
			if (_combatMode == 1) then {
				_text = "Defensive";
				_nextMode = 2;
			};
			//Defensive
			if (_combatMode == 0) then {
				_text = "Passive";
				_nextMode = 1;
			};
			s_player_dog_combat = player addAction [format["Dog: Combat: %1",_text],{ _this spawn BP_fnc_dogCombatMode; },[_dog,_dogHandle,_nextMode], 2, false, true,"",""];
		};
	} else {
		player removeAction s_player_dog_call;
		s_player_dog_call = 		-1;
		player removeAction s_player_dog_stay;
		s_player_dog_stay = 		-1;
		player removeAction s_player_dog_combat;
		s_player_dog_combat = 		-1;
	};
} else {
	player removeAction s_player_dog_call;
	s_player_dog_call = 		-1;
	player removeAction s_player_dog_stay;
	s_player_dog_stay = 		-1;
	player removeAction s_player_dog_combat;
	s_player_dog_combat = 		-1;
};
