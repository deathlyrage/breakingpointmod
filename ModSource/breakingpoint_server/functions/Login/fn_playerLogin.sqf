/*
	Function: BPServer_fnc_playerLogin;
	Description: Checks player white listing and loads in character data.
	Example: [_playerID,_player,_playerName,_clientID,_timerAuthed] spawn BPServer_fnc_playerLogin;
	Call Method: Spawn
	Author: Deathlyrage
*/

#define POINTMIN -3000
#define POINTMAX 6000

scriptName "BP_playerLogin";

// Load Thread Params
params ["_playerID","_player","_playerName","_clientID","_timerAuthed"];

//Fetch Ticket For Stage 1 Of Character Data
_loginTicket = ["CHILD:201:%1:%2:",_playerID,_playerName] call BPServer_fnc_callExtensionTicket;

//Variables
_primary = [];
_worldspace = [];
_inventory = [];
_isNew = false;
_randomSpot = false;

//Check If Player Is An Admin
_playerRank = _playerID call BP_fnc_playerRank;
_isAdmin = (_playerRank > 0);

//Inform a Player if they have an admin rank
if (_isAdmin) then {
	BP_playerRank = _playerRank;
	_clientID publicVariableClient "BP_playerRank";
};

//Fetch Player Data
_primary = _loginTicket call BPServer_fnc_callExtensionResult;

//Hive Error Checking
if ((_primary select 0) == "ERROR") exitWith {	
    diag_log format ["LOGIN FAILED: %3 (%2) Unable to load _primary: %1 ",_primary,_playerID,_playerName];
	[_clientID,[_playerID,"ERROR","Login Failure: Critical Hive Failure #1"]] call BPServer_fnc_sendLogin;
};

//Process request
_primary params ["","_isNew","_charID","_inventory","_survival","_lastServer","_activeServer","_dogData","_guid"];

//Don't Allow Dead People To Login
if (_charID in BP_DeadCharacters) exitWith {
	[_clientID,[_playerID,"ERROR","5"]] call BPServer_fnc_sendLogin;
	["playerLogin: Error Character ID %1 (%2) is Attempting to Login While Already Dead.",_charID,_playerID] call BP_fnc_debugConsoleFormat;
	["CRITICAL WARNING: HIVE EXTENSION IS OVERLOADED!"] call BP_fnc_debugConsoleFormat;
};

_minsLastUpdated = 0; // Temp Fix For Ghosting
//_minsLastUpdated = _survival select 1;

//Anti-Multi server (Fuck Dupers)
if (_activeServer != 0 && {_minsLastUpdated < 11} && {_lastServer != BP_ServerInstance}) exitWith { [_clientID,[_playerID,"ERROR","6"]] call BPServer_fnc_sendLogin; };

//Async Call To Set This Character ID For This Server Instance
["CHILD:203:%1:%2:",_charID,BP_ServerInstance] call BPServer_fnc_callExtensionAsyncLow;

//Anti-Ghosting Timer
if (_lastServer != 0 && {_minsLastUpdated < 11} && {_lastServer != BP_ServerInstance} && {!_timerAuthed} && {!_isAdmin}) exitWith {
	//Send Ghosting Timer
	[_clientID,[_playerID,"TIMER"]] call BPServer_fnc_sendLogin;
};

//Cleanup Groups
{ if ((count units _x) == 0 ) then { deleteGroup _x; }; } count allGroups;

//Create Unit
_group = createGroup civilian;
_body = _group createUnit ["C_man_polo_BP", (markerPos BP_DebugMarker), [], 0, "CAN_COLLIDE"];
_body triggerDynamicSimulation true;
_body allowDamage false;
_body setVariable ["bodyName",_playerName,true];
_body setVariable ["CharacterID",_charID];
_body setVariable ["guid",_guid];
_body setVariable ["playerID",_playerID];
_player setVariable ["body",_body];

//Fetch Ticket For Stage 2 Of Character Data
_setupTicket = ["CHILD:202:%1:",_charID] call BPServer_fnc_callExtensionTicket;

//Start Loading Player Gear
[_body,_inventory] call BPServer_fnc_playerGearSet;

//Connection Attempt
_primary = _setupTicket call BPServer_fnc_callExtensionResult;

//Error Checking
if ((_primary select 0) == "ERROR") exitWith {	
	//Return Hive Extension Error
	diag_log format ["LOGIN FAILED: %3 (%2) Critical Hive Failure #2: %1 ",_primary,_playerID,_playerName];
	[_clientID,[_playerID,"ERROR","Login Failure: Critical Hive Failure #2"]] call BPServer_fnc_sendLogin;
	
	//Handle Cleanup
	deleteVehicle _body;
	deleteGroup _group;
};

//Load Player State Variables
_primary params ["","_medical","_stats","_currentState","_worldspace","_class","_ranger","_outlaw","_hunter","_nomad","_survivalist","_engineer","_undead","_clan"];

//Workaround for int bug where things get converted to - max int from hive extension

["Class: %1 Ranger: %2",_class,_ranger] call BP_fnc_debugConsoleFormat;

//_class = parseNumber _class;
//_ranger = parseNumber _ranger;
//_outlaw = parseNumber _outlaw;
//_hunter = parseNumber _hunter;
//_nomad = parseNumber _nomad;
//_survivalist = parseNumber _survivalist;
//_engineer = parseNumber _engineer;
//_undead = parseNumber _undead;

//Work Around for people with < -3000 points. Remove this in a later patch
if (_ranger < POINTMIN or _ranger > POINTMAX) then { _ranger = 0; };
if (_outlaw < POINTMIN or _outlaw > POINTMAX) then { _outlaw = 0; };
if (_hunter < POINTMIN or _hunter > POINTMAX) then { _hunter = 0; };
if (_nomad < POINTMIN or _nomad > POINTMAX) then { _nomad = 0; };
if (_survivalist < POINTMIN or _survivalist > POINTMAX) then { _survivalist = 0; };
if (_engineer < POINTMIN or _engineer > POINTMAX) then { _engineer = 0; };
if (_undead < POINTMIN or _undead > POINTMAX) then { _undead = 0; };

_groupTimerActive = false;
_groupLeaveTimerOn = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "groupLeaveTimer" >> "groupLeaveTimeOut");
if(_groupLeaveTimerOn > 0) then
{
	//check if player left group recently
	_playerUID = getPlayerUID _player;
	for [{_i=0}, {_i < (count BP_groupLeaveTimers) && !_groupTimerActive}, {_i = _i + 1}] do
	{
		_checkPlayer = BP_groupLeaveTimers select _i;
		if((_checkPlayer select 0) == _playerUID && ((_checkPlayer select 1) > time)) then
		{
			_groupTimerActive = true;
		};
	};
};

//Persistent Groups
_validLegion = false;

if(!_groupTimerActive) then
{
	if(BP_Factions_disableMixedgrouping) then
	{
		_legionDataVarName="";
		_groupID="";
		if (_clan != "0") then //DB Groups
		{
			_squadData = squadParams _player;
			if !(_squadData isEqualTo []) then
			{
				_squadData params ["_squadDetails","_memberDetails"];
				_squadDetails params ["_squadNick","_squadName","_squadEmail"];
				if (!(_squadNick isEqualTo []) && !(_squadName isEqualTo "")) then
				{
					if(_class == -1) then
					{
						_body setVariable ["clan", _clan];//when there is no class to process (respawn) it will be handeled in the fn_playerSetup.sqf
						_validLegion = true;
					}
					else
					{
						if (_class in [0,3]) then
						{													//Legion Data Database
							_legionDataVarName = format["BP_LDDB_Bandit:%1", _clan];//None-Hunter
						}
						else
						{
							if (_class in [1,4,5]) then
							{
								_legionDataVarName = format["BP_LDDB_Friendly:%1", _clan];//Nomad-Ranger-Survialist
							}
							else
							{
								if(_class == 2) then
								{
									_legionDataVarName = format["BP_LDDB_Outlaw:%1", _clan];//Outlaw
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
							_body setVariable ["group", _groupID, true];
							_body setVariable ["groupTag", _squadNick];
							_body setVariable ["groupName", _squadName];
							_validLegion = true;
						};
					};
				};
			};
		};
	}
	else
	{
		//Persistent Groups
		if (_clan != "0") then
		{
			_squadData = squadParams _player;
			if !(_squadData isEqualTo []) then
			{
				_squadData params ["_squadDetails","_memberDetails"];
				_squadDetails params ["_squadNick","_squadName","_squadEmail"];
				if (_squadEmail == _clan) then
				{
					_validLegion = true;
					_body setVariable ["group",_clan,true];
					_body setVariable ["groupTag",_squadNick,false];
					_body setVariable ["groupName",_squadName,false];
				};
			};
		};
	};
};

if (BP_LegionOnly and !_validLegion) exitWith
{
	["playerLoegion: REJECTED: Player %1 (%2) Login Failure: Error ID: 7",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
	[_clientID,[_playerID,"ERROR","7"]] call BPServer_fnc_sendLogin;
	
	//Handle Cleanup
	deleteVehicle _body;
	deleteGroup _group;
};

//Kill Corrupt Undead Characters
// if (_class == 7) exitWith { ["CHILD:301:%1:",_charID] call BPServer_fnc_callExtensionAsync; };

//Check Valid Positions and Inside Buildings
if !(_worldspace isEqualTo []) then
{
	if (count _worldspace > 1) then
	{
		_worldspace params ["_direction","_position"];

		//Ensure Player Has Valid Position
		if (count _position < 3) exitWith { _randomSpot = true; };
		
		//Ensure Player Isn't In Debug
		if (((getMarkerPos BP_DebugMarker) distance _position) < BP_DebugRadius) exitWith { _randomSpot = true; };
		
		//Ensure Player Isn't Near [0,0,0]
		if (([0,0,0] distance _position) < 500) exitWith { _randomSpot = true; };
		
		//Ensure Player Isn't Inside A Building
		_inside = [_position] call BP_fnc_isInsideBuildingPos;
		if (_inside) exitWith { _randomSpot = true; };
		
	} else {
		_randomSpot = true;
	};
} else {
	_randomSpot = true;
};

//Load Local Worldspace
_body setVariable ["worldspace",_worldspace];

//Set Local Player State Variables
_body setVariable ["class",_class,true];
_body setVariable ["ranger",_ranger];
_body setVariable ["outlaw",_outlaw];
_body setVariable ["hunter",_hunter];
_body setVariable ["nomad",_nomad];
_body setVariable ["survivalist",_survivalist];
_body setVariable ["engineer",_engineer];
_body setVariable ["undead",_undead];

//Load Stats
if !(_stats isEqualTo []) then {
	_body setVariable ["zombieKills",(_stats select 0)];
	_body setVariable ["headShots",(_stats select 1)];
	_body setVariable ["humanKills",(_stats select 2)];
	//_body setVariable ["freshSpawnKills",(_stats select 3)];
	//_body setVariable ["storageKills",(_stats select 4)];
};

//Dog
_body setVariable ["dog",objNull];
_body setVariable ["dogID",0];

//Medical
_body setVariable ["med_BloodQty",(_medical select 8)];
_body setVariable ["messing",(_medical select 10)];

//Misc ( No Need to Init Because Default Fetch Values )
//_body setVariable ["recentKills",[]];


if (_isNew) then {
	_body setVariable ["freshSpawn",true];
	_body setVariable ["freshSpawnTime",diag_tickTime];
};

//Fetch Current Character State
_currentState params [["_currentWpn","",[""]],["_currentAnim","",[""]]];

//Fetch Current Character State (Removed and replaced with the line above to be faster)
//_currentWpn = "";
//_currentAnim = "";
//if !(_currentState isEqualTo []) then {
//	_currentWpn = _currentState select 0;
//	if (typeName _currentWpn != "STRING") then { _currentWpn = ""; };
//	_currentAnim = _currentState select 1;
//	if (typeName _currentAnim != "STRING") then { _currentAnim = ""; };
//};

//Select A Weapon
if (_currentWpn != "") then {
	_body selectWeapon _currentWpn;
} else {
	//Establish default weapon
	if !(weapons _body isEqualTo []) then
	{
		_type = ((weapons _body) select 0);
		// check for multiple muzzles (eg: GL)
		_muzzles = getArray(configFile >> "CfgWeapons" >> _type >> "muzzles");
		if (count _muzzles > 1) then {
			_body selectWeapon (_muzzles select 0);
		} else {
			_body selectWeapon _type;
		};
	};
};

//Select An Anim
//if (_currentAnim != "") then {
//	_body playMoveNow _currentAnim;
//};

/*
//Load Players Dog
_dog = objNull;
if !(_dogData isEqualTo []) then
{
	//Load Dog Data
	_dogTypeID = _dogData select 0;
	_dogName = _dogData select 1;
	_dogClassname = switch (_typeID) do {
		default 	{"BP_Dog_1"};
		case 1:	{"BP_Dog_1"};
		case 2: 	{"BP_Dog_2"};
		case 3: 	{"BP_Dog_3"};
		case 4: 	{"BP_Dog_4"};
		case 5: 	{"BP_Dog_5"};
		case 6: 	{"BP_Dog_6"};
		case 7: 	{"BP_Dog_7"};
	};

	//Create Dog
	_dog = _group createUnit [_dogClassname, (getPosATL _body), [], 0, "CAN_COLLIDE"];
	_dog setVariable ["CharacterID",_charID,true];
	_dog setVariable ['BIS_noCoreConversations',true];
	_dog setVariable ['BIS_fnc_animalBehaviour_disable',true];
	_body setVariable ["dog",_dog,true];	
};
*/

//Remember Survival For Combat Log AI
_body setVariable ["survival",_survival];

//Send Login Data
[_clientID,[_playerID,(netID _body),_charID,_isNew,_randomSpot,_medical,_survival,[_class,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead],_dogData]] call BPServer_fnc_sendLogin;

