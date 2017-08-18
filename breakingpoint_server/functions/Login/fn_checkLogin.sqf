/*
	Function: BPServer_fnc_checkLogin;
	Description: Checks a Login Event to see if it's valid before spawning a login thread.
	Example: [_playerID,_playerObj,_timerAuthed] call BPServer_fnc_checkLogin;
	Thread Blocking: Yes
	Author: Deathlyrage
*/

private ["_playerID","_playerObj","_timerAuthed","_playerName","_clientID"];

params ["_playerNetID",["_timerAuthed",false,[true]]];

_playerObj = objectFromNetID _playerNetID;
_playerID = getPlayerUID _playerObj;

//Error Checking
if (isNull _playerObj) exitWith {};
if (!isPlayer _playerObj) exitWith {};
if (_playerID == "") exitWith {};

//Load Player Data
_playerName = (name _playerObj);
_clientID = (owner _playerObj);

//Server Login
//if (_playerName == '__SERVER__') exitWith {};

//Headless Client
//if (_playerObj isKindOf "HeadlessClient_F") exitWith
//{
//	//Log
//	["headlessLogin: Headless Client Connected: PID: %1 | Obj: %2 Name: %3 | ID: %4 | Type: %5#0111",_playerID,_playerObj,_playerName,_clientID,(typeOf _playerObj)] call BP_fnc_debugConsoleFormat;
//
//	//Flag HC as Connected
//	BP_HC_Connected = true;
//	publicVariable "BP_HC_Connected";
//	
//	//Send HC Needed Server Datas
//	//(_clientID) publicVariableClient "BP_Strongholds";
//	
//	//Update Server HC Variables
//	BP_HC_ID = _clientID;
//	BP_HC_PID = _playerID;
//	BP_HC_OBJ = _playerObj;
//};

//Don't Let HC Login as a player
//if (_playerName == "headlessclient") exitWith {};
//if (_playerName == "hc") exitWith {};

//Server Not Ready - ERROR 1
if (!initialized) exitWith
{
	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 1",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
	[_clientID,[_playerID,"ERROR","1"]] call BPServer_fnc_sendLogin;
};

//Rejected Player (VAC BANNED) - ERROR 2
//if (_playerID in BP_VAC) exitWith {
//	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 2",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
//	[_clientID,[_playerID,"ERROR","2"]] call BPServer_fnc_sendLogin;
//};

//No HC Connected - ERROR 3
//_hasHC = (BP_HC_ID > 1);
//if (BP_HC and !_hasHC) exitWith {
//	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 3",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
//	[_clientID,[_playerID,"ERROR","3"]] call BPServer_fnc_sendLogin;
//};

//Server Is In Shutdown Mode - ERROR 4
if (shutdown) exitWith {
	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 4",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
	[_clientID,[_playerID,"ERROR","4"]] call BPServer_fnc_sendLogin;
};

//Rejected Player (BANNED) - ERROR 5
//if (_playerID in BP_Banned) exitWith {
//	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 5",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
//	[_clientID,[_playerID,"ERROR","5"]] call BPServer_fnc_sendLogin;
//};

//Character Still Active - ERROR 6
//if (_playerID in anti_disconnect) exitWith {
//	["checkLogin: REJECTED: Player %1 (%2) Login Failure: Error ID: 6",_playerName,_playerID] call BP_fnc_debugConsoleFormat;
//	[_clientID,[_playerID,"ERROR","6"]] call BPServer_fnc_sendLogin;
//};

//Update Local NetID Reference
//_netID = netID _playerObj;
//call compile format["player%1 = _netID;",_playerID];

//Check For Combat Log AI
_combatAI = false;
_index = BP_AntiDisconnectIDs find _playerID;
_body = objNull;
if (_index >= 0) then 
{
	BP_AntiDisconnectIDs deleteAt _index;
	_body = BP_AntiDisconnectObjs deleteAt _index;
	if (!isNull _body) then
	{
		_scriptHandle = _body getVariable ["handle",scriptNull];
		if (!isNull _scriptHandle) then { terminate _scriptHandle; };

		_characterID = _body getVariable ["CharacterID","0"];
		if (_characterID == "0") exitWith {};

		if (alive _body) then 
		{
			_combatAI = true;
			_body setVariable ["combatAI",true];
			_body setVariable ["hotReload",true];
		};
	};
};

//Handle Login
if (_combatAI) then {
	[_playerID,_playerObj,_playerName,_clientID,_body] call BPServer_fnc_playerLoginAI;
} else {
	[_playerID,_playerObj,_playerName,_clientID,_timerAuthed] spawn BPServer_fnc_playerLogin;
};

