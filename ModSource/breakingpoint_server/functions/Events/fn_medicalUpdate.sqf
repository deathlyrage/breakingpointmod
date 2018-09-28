/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_event","_unitNetID","_medicEventID"];

_unit = objectFromNetID _unitNetID;
_unitUID = getplayerUID _unit;
_medic = objectFromNetID _medicEventID;
_medicUID = getplayerUID _medic;
_isHostage = _unit getVariable ["med_hostage", false];
_perpetrator = _unit getVariable ["hostage_perpetrator", "0"];

if (_isHostage && _perpetrator != "0" && _event == "medGut") then
{
	_medic = objectFromNetID _perpetrator;
};

if (isNull _unit) exitWith {};
if (isNull _medic) exitWith {};

//Points Gain
_unitClassID = _unit getVariable ["class",0];
_unitFaction = _unitClassID call BP_fnc_getFactionName;

_medicClassID = _medic getVariable ["class",0];
_medicFaction = _medicClassID call BP_fnc_getFactionName;

_pointsChange = 0;
_valid = false;
_addPoints = true;
_selfHeal = (_unit == _medic);
_healedRecently = false;

switch (_event) do {
	case "medBandage": {
		if ("ItemBandage" in magazines _medic) then
		{
			_valid = true;
			_medic removeMagazineGlobal "ItemBandage";
			
			/*if (!_selfHeal) then {
				_recentBandage = _medic getVariable ["medBandage",[]];
				if (getPlayerUID _unit in _recentBandage) then {
					BP_GameError = 4;
					(owner _medic) publicVariableClient "BP_GameError";
				} else {
					_recentBandage pushBack (getPlayerUID _unit);
					_medic setVariable ["medBandage",_recentBandage];
					_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "bandage");
				};
			};*/
			
			
			if(!_selfHeal) then
			{
				_healedRecently = [_event,_unitUID,_medicUID] call BPServer_fnc_checkHealRecent;
				if (_healedRecently) then {
					BP_GameError = 4;
					(owner _medic) publicVariableClient "BP_GameError";
				} else {
					_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "bandage");
				};
			};
			
		};
	};
	case "medFieldDressing": {
		if ("ItemFieldDressing" in magazines _medic) then
		{
			_valid = true;
			_medic removeMagazineGlobal "ItemFieldDressing";
			
			if(!_selfHeal) then
			{
				_healedRecently = [_event,_unitUID,_medicUID] call BPServer_fnc_checkHealRecent;
				if (_healedRecently) then {
					BP_GameError = 4;
					(owner _medic) publicVariableClient "BP_GameError";
				} else {
					_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "bandage");
				};
			};
		};
	};
	case "medPainK": {
		if ("ItemPainkiller" in magazines _medic) then 
		{
			_medic removeMagazineGlobal "ItemPainkiller";
			_valid = true;
	
			if(!_selfHeal) then
			{
				_healedRecently = [_event,_unitUID,_medicUID] call BPServer_fnc_checkHealRecent;
				if (_healedRecently) then {
					BP_GameError = 4;
					(owner _medic) publicVariableClient "BP_GameError";
				} else {
					_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "bandage");
				};
			};
		};
	};
	case "medAdrenaline": {
		if ("ItemAdrenaline" in magazines _medic) then {
			_medic removeMagazineGlobal "ItemAdrenaline";
			_valid = true;
			_addPoints = false;
		};
	};
	case "medAntibiotic": {
		if ("ItemAntibiotic" in magazines _medic) then {
			_medic removeMagazineGlobal "ItemAntibiotic";
			_valid = true;
			_addPoints = false;
		};
	};
	case "medGrenade": {
		if ("HandGrenade" in magazines _medic) then {
			_medic removeMagazineGlobal "HandGrenade";
			_container = (backpackContainer _unit);
			_container addMagazineCargoGlobal ["HandGrenadeLive",1];
			playSound3D ["a3\sounds_f\characters\stances\concrete_adjust_prone_left.wss", _unit, false, getPosASL _unit,1,1,20];
			_valid = false;
			_addPoints = false;
		};
	};
	case "medZombie": {
		_valid = true;
		_addPoints = false;
		
		//Get Faction Details
		_class = _unit getVariable ["class",0];
		_factionName = _class call BP_fnc_getFactionName;
		_factionLevel = _unit call BP_fnc_getFactionLevel;
		
		//Backup Uniform Gear
		_uniform = (uniform _unit);
		_weaponsUniform = (getMagazineCargo uniformContainer _unit) call BP_fnc_cargoToPairs;
		_magsUniform = (getMagazineCargo uniformContainer _unit) call BP_fnc_cargoToPairs;
		_itemsUniform = (getItemCargo uniformContainer _unit) call BP_fnc_cargoToPairs;
		
		//Remove Old Uniform
		removeUniform _unit;
		
		if (_uniform in BP_ZombieClothing) then
		{
			_clothing = "";
			_clothingIndex = (BP_ZombieClothing find _uniform);
			if (_clothingIndex > -1) then {
				_clothing = (BP_NormalClothing select _clothingIndex);
			} else {
				_levelStr = format ["Level_%1",_factionLevel];
				_clothingArray = getArray (configFile >> "CfgFactions" >> _factionName >> "Levels" >> _levelStr >> "Spawn" >> "clothing");
				_clothing = (_clothingArray select 0);
			};
			_unit addUniform _clothing;
		} else {
			_unit addUniform format ["%1_Z",_uniform];
		};
		
		//Add Uniform Weapons
		{
			_x params ["_mag","_count"];
			_isOK = isClass(configFile >> "CfgWeapons" >> _mag);
			if (_isOK) then {  (uniformContainer _unit) addWeaponCargoGlobal [_mag,_count]; };
		} count _weaponsUniform;

		//Add Uniform Magazines
		{
			_x params ["_mag","_count"];
			_isOK = isClass(configFile >> "CfgMagazines" >> _mag);
			if (_isOK) then { (uniformContainer _unit) addMagazineCargoGlobal [_mag,_count]; };
		} count _magsUniform;

		//Add Uniform Items
		{
			_x params ["_mag","_count"];
			_isOK = isClass(configFile >> "CfgWeapons" >> _mag);
			if (_isOK) then { (uniformContainer _unit) addItemCargoGlobal [_mag,_count]; };
		} count _itemsUniform;
	};
	case "medSurgery": {
		_valid = true;	
		if(!_selfHeal) then
		{
			_healedRecently = [_event,_unitUID,_medicUID] call BPServer_fnc_checkHealRecent;
			if (_healedRecently) then
			{
				BP_GameError = 4;
				(owner _medic) publicVariableClient "BP_GameError";
			} else {
			    _pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "surgery");
			};
		};		
	};
	case "medSurgeryDog": {
		_addPoints = false;
		if ("ItemFieldDressing" in magazines _medic && "ItemMorphine" in magazines _medic) then
		{
				_valid = true;
				_unit setDamage 0;
		};
	};
	case "medBite": {
		_valid = true;
		_addPoints = false;
	};
	case "medMedkit": {
		_valid = true;
		_addPoints = false;
	};
	case "medMorphine":
	{
		if ("ItemMorphine" in magazines _medic) then
		{
			_medic removeMagazineGlobal "ItemMorphine";
			_valid = true;
			if(!_selfHeal) then
			{
					_healedRecently = [_event,_unitUID,_medicUID] call BPServer_fnc_checkHealRecent;
					if (_healedRecently) then {
						BP_GameError = 4;
						(owner _medic) publicVariableClient "BP_GameError";
					} else {
						_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "morphine");
					};
			};
		};
	};
	case "medGut": 
	{
		//Enable Simulation on Gutted Body
		_unit enableSimulation true;
		
		//Prevents Players from Gutting the same thing at once to exploit
		_alreadyGutted = _unit getVariable ["gutted",false];
		if (_alreadyGutted) exitWith
		{
			_valid = false;
			_addPoints = false;
		};

		//Flag as Valid
		_valid = true;
		_addPoints = true;

		//Flag Body as already Gutted
		_unit setVariable ["gutted",true,true];
		
		//Determine Type Information Of Gutted Body
		_type = typeOf _unit;
		_config = configFile >> "CfgSurvival" >> "Meat" >> _type;
		_isPlayer = ((_type in BP_AllPlayers) or (isPlayer _unit));
		_isZombie = (_unit isKindOf "zZombie_Base");
		_isAnimal = (_unit isKindOf "Animal");
		
		//Get Animal Type
		_isListed = isClass (_config);
		_text = getText (configFile >> "CfgVehicles" >> _type >> "displayName");

		_rawfoodtype = "FoodMeatRaw";
		if (_isZombie) then {
			_rawfoodtype = getText (configFile >> "CfgSurvival" >> "Meat" >> "zZombie_base" >> "rawfoodtype");
		} else {
			if (_isPlayer) then {
				_rawfoodtype = getText (configFile >> "CfgSurvival" >> "Meat" >> "BP_Player_Base" >> "rawfoodtype");
			} else {
				if (_isListed) then {
					_rawfoodtype = getText (configFile >> "CfgSurvival" >> "Meat" >> _type >> "rawfoodtype");
				} else {
					_rawfoodtype = getText (configFile >> "CfgSurvival" >> "Meat" >> "Default" >> "rawfoodtype");
				};
			};
		};
		
		//Determine Amount of Meat Generated
		_qty = 2;	
		if (_isListed) then { _qty = getNumber (_config >> "yield"); };

		//Create Weaponholder
		_loot = createVehicle ["groundWeaponHolder", getPosATL _unit, [], 0, "CAN_COLLIDE"];
		_loot addMagazineCargoGlobal [_rawfoodtype, _qty];
		_loot enableDynamicSimulation true;
		
		if (_isPlayer) then
		{
			_level = _unit call BP_fnc_getFactionLevel;
			//Override Level to 0 if Player has a Traitor Flag
			_isTraitor = _unit getVariable ["traitorFlag",false];
			if (_isTraitor) then { _level = 0; };

			//If Traitor Award Kill Points Else Fetch Gut Points From Config
			if (alive _unit) then
			{
				if (_level == 0) then {
					_pointsChange = [_unit,_medic] call BP_fnc_getFactionKillPoints;
				} else {
					_pointsChange = getNumber (configFile >> "CfgFactions" >> _medicFaction >> "Points" >> "Aid" >> _unitFaction >> "gut");
				};
				
				//Mission Config Custom Points Division
				_pointsChange = _pointsChange * BP_Factions_PointsRatio;
				
				//Check if mixed group points off for gutting
				_disableMixedGroupPointsGain = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "MixedGroupPointsGain" >> "disableMixedGroupPointsGain");
				_pointsOff = false;
				if(_disableMixedGroupPointsGain == 1 && _pointsChange > 0 && !_playerTraitorFlag) then {
					_medicGroupID = _medic getVariable ["group","0"];
					if(_medicGroupID != "0") then {
						_groupMembers = [];
						_groupMemberClass = -1;
						{
							_groupID = _x getVariable ["group","0"];
								if(_groupID == _medicGroupID) then {
									0 = _groupMembers pushBack _x;
								};
						} count allPlayers;		
						if (count _groupMembers > 1) then {
							_friendlyClass = [1,4,5];
							for [{_i=0}, {_i < (count _groupMembers) && !_pointsOff}, {_i = _i + 1}] do {
								_groupMemberClass = (_groupMembers select _i) getVariable ["class",0];
								if(((_groupMemberClass in _friendlyClass) && (_unitClassID in _friendlyClass)) || ((_groupMemberClass == 2) && (_unitClassID == 2))) then {
									_pointsOff = true;
								};
							};
							
						};
					};
				};
				
				//No points if misxed group points off for gutting
				if(_pointsOff) then {
					_pointsChange = 0;
				};
			};
		} else {
			//Delete Body / Object If It Isn't a Player
			//deleteVehicle _item;
			
			//Handle Point Gain for Survivalist and Nomad
			if (!_isZombie and _isAnimal) then {
				_class = _medic getVariable ["class",0];
				//Survivalist
				if (_class == 5) then { _pointsChange = 10; };
				//Nomad
				if (_class == 4) then { _pointsChange = 25; };
			};
		};
	};
};

//Forward Medical Event
if (_valid) then {
	BP_MedicalEvent = _this;
	(owner _unit) publicVariableClient "BP_MedicalEvent";
};

if (_addPoints and !_selfHeal) then 
{
	//Add Points (Global)
	[_medic,_pointsChange] call BPServer_fnc_addFactionPoints;

	//Sync Stats
	_medic call BPServer_fnc_statsSync;
};
