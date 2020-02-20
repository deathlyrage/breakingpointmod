

params ["_logicNetID","_playerNetID"];
_logic = objectFromNetID _logicNetID;
_player = objectFromNetID _playerNetID;
_clientID = (owner _logic);

//Make Sure Player Object is Valid and Local
if (isNull _logic) exitWith {};
if (isNull _player) exitWith {};
if (!local _player) exitWith {};

//Fetch Character ID
_charID = _player getVariable ["CharacterID","0"];
if (_charID == "0") exitWith {};

//Combat AI Fast Login
_combatAI = _player getVariable ["combatAI",false];
if (_combatAI) exitWith {
	bpSetupResult = [[(getDir _player),(getPosATL _player)]];
	_clientID publicVariableClient "bpSetupResult";
	_player call BPServer_fnc_radioCheck;
};

_worldspace = _player getVariable ["worldspace",[]];
_class = _player getVariable ["class",0];
_isSetup = _player getVariable ["classSetup",false];
_combatAI = _player getVariable ["combatAI",false];

//Handle Spawn Selection and Class Selection
if (count _this > 2) then
{
	_spawnLocation = _this select 2;
	_class = _this select 3;

	//Exit If Already Setup
	if (_isSetup) exitWith {};

	//Flag as Already Setup
	_player setVariable ["classSetup",true];

	//Publish Class Selection
	_player setVariable ["class",_class,true];

	//Spawn Class Gear
	[_player,_class] call BPServer_fnc_factionGear;

	//Handle Groups
	if(BP_Factions_disableMixedgrouping) then
	{
		_legionDataVarName="";
		_groupID="";
		_clanDB = _player getVariable ["clan","0"];
		if (_clanDB != "0") then //DB Groups
		{
			_squadData = squadParams _logic;
			_squadData params ["_squadDetails","_memberDetails"];
			_squadDetails params ["_squadNick","_squadName","_squadEmail"];
			if (_class in [0,3]) then
			{													//Legion Data Database
				_legionDataVarName = format["BP_LDDB_Bandit:%1", _clanDB];//None-Hunter
			}
			else
			{
				if (_class in [1,4,5]) then
				{
					_legionDataVarName = format["BP_LDDB_Friendly:%1", _clanDB];//Nomad-Ranger-Survialist
				}
				else
				{
					if(_class == 2) then
					{
						_legionDataVarName = format["BP_LDDB_Outlaw:%1", _clanDB];//Outlaw
					};
				};
			};
			if !(_legionDataVarName isEqualTo "") then
			{
				if !((missionNamespace getVariable [_legionDataVarName, ""]) isEqualTo "") then
				{
					_groupID = missionNamespace getVariable [_legionDataVarName, ""];
				}
				else
				{
					_groupID = call BP_fnc_groupCreateUID;
					missionNamespace setVariable [_legionDataVarName, _groupID];
				};
				_player setVariable ["group", _groupID, true];
				_player setVariable ["groupTag", _squadNick];
				_player setVariable ["groupName", _squadName];
				_validLegion = true;
			};
		};
	};
	
	//Handle Spawn Selection
	call
	{
		//Fetch WorldName
		_worldName = worldName;

		//Random
		if (_spawnLocation == -1) exitWith
		{
			_spawnPoints = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "SpawnPos" >> _worldName);
			_worldspace = selectRandom _spawnPoints;
			_player setVariable ["worldspace",_worldspace];
		};

		//Stronghold
		if (_spawnLocation == 0) exitWith
		{
			_factionName = _class call BP_fnc_getFactionName;
			_spawnPoints = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Factions" >> "Bases" >> _factionName >> "spawn");
			_worldspace = selectRandom _spawnPoints;
			_player setVariable ["worldspace",_worldspace];
		};

		//Spawn Selection
		if (_spawnLocation == 1) then { _worldName = "West"; };
		if (_spawnLocation == 2) then { _worldName = "East" };
		if (_spawnLocation == 3) then { _worldName = "Central" };
		_spawnPoints = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "SpawnPos" >> _worldName);
		_worldspace = selectRandom _spawnPoints;
		_player setVariable ["worldspace",_worldspace];
	};
};

//Transfer Locality Of Player To Client
//NOTE: THIS IS BROKEN. TRANSFERING LOCALITY CAN CAUSE
//A OLD POSITION TO BE USED INSIDE DEUBG.
//HOPEFULLY THE DOG LOCALITY WILL AUTO CHANGE WHEN
//THE LOCALITY OF THE PLAYER CHANGES ON selectPLayer
//(group _player) setGroupOwner _clientID;

//Set Dog Position
//_dog = _player getVariable ["dog",objNull];
//if (!isNull _dog) then { _dog setPosATL (_worldspace select 1); };

//Zombie Queue Spawning System
//if (_class == 7) exitWith
//{
//	//Ensure Player Is In The Queue
//	_index = BP_UndeadQueue find _logicNetID;
//	if (_index == -1) then {
//		_index = BP_UndeadQueue pushBack _logicNetID;
//	};
//	_queueTotal = count BP_UndeadQueue;
//
//	//Check and Count Players
//	_nonUndeadPlayers = [];
//	_zombieCount =
//	{
//		_valid = false;
//		//Not In Debug
//		if !(_x call BP_fnc_isInDebug) then
//		{
//			//Alive
//			if (alive _x) then {
//				//Undead
//				if (_x getVariable ["class",0] == 7) then {
//					_valid = true;
//				} else {
//					_inVehicle = ((vehicle _x) != _x);
//					_isFreshSpawn = (_x getVariable ["freshSpawn",false]);
//					_survivalist = (_x getVariable ["class",0] == 5);
//					if (!_inVehicle and !_isFreshSpawn and !_survivalist) then {
//						_nonUndeadPlayers pushBack _x;
//					};
//				};
//			};
//		};
//		_valid
//	} count allPlayers;
//	_playerCount = (count allPlayers) - _zombieCount;
//	_maxZombies = (BP_maxPlayers / 5);
//
//	//Ensure There Is More Then One Non-Zombie Player
//	if (_playerCount == 1) exitWith {
//		_player setDir (_worldspace select 0);
//		_player setPosATL (_worldspace select 1);
//		_player enableSimulationGlobal true;
//
//		//Remove From Queue
//		BP_UndeadQueue deleteAt _index;
//
//		//Send Packet
//		bpSetupResult = [_worldspace];
//		_clientID publicVariableClient "bpSetupResult";
//
//		//bpSetupResult = ["Waiting For More Players",true];
//		//_clientID publicVariableClient "bpSetupResult";
//	};
//
//	if (_zombieCount < _maxZombies && {_index == 0}) then
//	{
//		//Locate Random Player
//		_foundSpawn = false;
//		_randomPlayer = selectRandom _nonUndeadPlayers;
//
//		//Find Zombie Spawn Position
//		_nearbyZombies = _randomPlayer nearEntities ["zZombie_Base", 250];
//		if !(_nearbyZombies isEqualTo []) then
//		{
//			_zombie = selectRandom _nearbyZombies;
//			if !(isNull _zombie) then
//			{
//				_worldspace = [(getDir _zombie),(getPosATL _zombie)];
//				deleteVehicle _zombie;
//				_foundSpawn = true;
//			};
//		} else {
//			//Fetch Nearby Buildings
//			_nearbyBuildings = (getPosATL _randomPlayer) nearObjects ["Building",200];
//
//			//Delete Nearest Building from Player
//			_nearestBuilding = nearestObject [_randomPlayer, "HouseBase"];
//			_index = _nearbyBuildings find _nearestBuilding;
//			if (_index >= 0) then { 0 = _nearbyBuildings deleteAt _index;};
//
//			//Shuffle Buildings Randomly
//			_nearbyBuildings = _nearbyBuildings call BIS_fnc_arrayShuffle;
//
//			//Go Thru Nearby Buildings for Valid Spawn
//			{
//				if (!isNull _x) then
//				{
//					//Don't Spawn In Havens
//					if ((netID _x) in BP_Buildings) exitWith {};
//
//					//Handle Spawning
//					// Mission config file loot table override.
//					_config = configFile >> "CfgBuildingLoot" >> (typeOf _x);
//					if (isClass (missionConfigFile >> "CfgBuildingLoot" >> (typeOf _x))) then
//					{
//						_config = missionConfigFile >> "CfgBuildingLoot" >> (typeOf _x);
//					};
//
//					if (isClass _config) then {
//						_unitTypes = getArray (_config >> "zombieClass");
//						_positions =	getArray (_config >> "zombiePos");
//						if !(_positions isEqualTo []) then
//						{
//							_position = selectRandom _positions;
//							_worldspace = [0,(_x modelToWorld _position)];
//							_foundSpawn = true;
//						};
//					};
//				};
//			} count _nearbyBuildings;
//		};
//
//		["playerSetup: foundSpawn: %1 | Worldspace: %2",_foundSpawn,_worldspace] call BP_fnc_debugConsoleFormat;
//
//		if (!_foundSpawn) exitWith {
//			//Send Queue Packet
//			bpSetupResult = ["Waiting For Suitable Spawn Location.",true];
//			_clientID publicVariableClient "bpSetupResult";
//		};
//
//		_player setDir (_worldspace select 0);
//		_player setPosATL (_worldspace select 1);
//		_player enableSimulationGlobal true;
//
//		//Remove From Queue
//		BP_UndeadQueue deleteAt _index;
//
//		//Send Packet
//		bpSetupResult = [_worldspace];
//		_clientID publicVariableClient "bpSetupResult";
//	} else {
//		//Send Queue Packet
//		_text = format ["Waiting In Undead Queue. Position %1 Of %2.",(_index + 1),_queueTotal];
//		bpSetupResult = [_text,true];
//		_clientID publicVariableClient "bpSetupResult";
//	};
//};

//Check Radio
_player call BPServer_fnc_radioCheck;

//Set Player Position and Direction
_player setDir (_worldspace select 0);
_player setPosATL (_worldspace select 1);

if (((eyePos _player) select 2 < 0) && ((_worldspace select 1) select 2 == 0)) then
{
	_player setPosASL [(_worldspace select 1) select 0, (_worldspace select 1) select 1, 0];
};

_player enableSimulationGlobal true;

//Send Login Result
bpSetupResult = [_worldspace];
_clientID publicVariableClient "bpSetupResult";

//Save Player Stats and Class
_player call BPServer_fnc_statsSync;
