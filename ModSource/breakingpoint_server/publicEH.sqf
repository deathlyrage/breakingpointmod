/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

"BP_SetPosATL"			addPublicVariableEventHandler {(_this select 1) call BPServer_fnc_setPosATL};

"BIS_fnc_MP_packet"	 addPublicVariableEventHandler {};

"BP_PickupBike" addPublicVariableEventHandler
{
	(_this select 1) params ["_bicycle"];
	_vecloc = getPosATL _bicycle;
	_location = [_vecloc select 0,_vecloc select 1,(_vecloc select 2) + 1];
	_bicycle setPosATL _location;
	_bicycle setVectorUp [0,0,1];
	_bicycle setVelocity [0,0,0];
	_bicycle enableSimulation false;
	_bicycle setPosATL [_vecloc select 0,_vecloc select 1,_vecloc select 2];
	_bicycle setVelocity [0,0,0];
	_bicycle enableSimulation true;
};

"BP_WeaponSwitch" addPublicVariableEventHandler 
{
	BP_WeaponSwitch = (_this select 1);
	publicVariable "BP_WeaponSwitch";
};

"BP_Simulation" addPublicVariableEventHandler 
{
	(_this select 1) params ["_netID","_toggle"];
	_netObj = objectFromNetID _netID;
	if (isNull _netObj) exitWith {};
	_netObj enableSimulationGlobal _toggle;
};

"BP_Deathlyrage" addPublicVariableEventHandler 
{
	(_this select 1) params ["_playerNetID","_action"];
	_player = objectFromNetID _playerNetID;
	if (isNull _player) exitWith {};
	[(getPlayerUID _player),(name _player),_action] call BPServer_fnc_adminLog;
};

"BP_DebugNotice" addPublicVariableEventHandler 
{
	(_this select 1) params ["_playerNetID","_objectNetID"];
	
	_player = objectFromNetID _playerNetID;
	if (isNull _player) exitWith {};
	_object = objectFromNetID _objectNetID;
	if (isNull _object) exitWith {};
	
	_objectID = _object getVariable ["ObjectID","0"];
	_objectUID = _object getVariable ["ObjectUID","0"];
	_objectPlayerID = _object getVariable ["PlayerID","0"];
	
	if (_object isKindOf "BP_Storage") exitWith
	{
		//Admin Log
		_action = format ["Storage ID %1 UID %2 PID %3",_objectID,_objectUID,_objectPlayerID];
		[_playerID,_playerName,_action] call BPServer_fnc_adminLog;
	
		BP_DebugNotice = [(netID _object),_objectID,_objectUID,_objectPlayerID,0];
		(owner _player) publicVariableClient "BP_DebugNotice";
	};
	
	if (_object isKindOf "Building") exitWith
	{
		_logic = _object getVariable ["logic",objNull];
		_locked = _logic getVariable ["bis_disabled_Door",0];
		
		//Admin Log
		_action = format ["Building ID %1 UID %2 PID %3 LOCK %4",_objectID,_objectUID,_objectPlayerID,_locked];
		[_playerID,_playerName,_action] call BPServer_fnc_adminLog;
	
		BP_DebugNotice = [(netID _object),_objectID,_objectUID,_objectPlayerID,_locked];
		(owner _player) publicVariableClient "BP_DebugNotice";
	};
};

"BP_PlayerRCMD" addPublicVariableEventHandler 
{
	(_this select 1) params ["_playerNetID","_flag","_data"];
	
	_player = objectFromNetID _playerNetID;
	
	if (isNull _player) exitWith {};
	
	if (_flag == -1) exitWith 
	{ 
		_player setVariable ["lastPing",diag_tickTime];
		_player setVariable ["lastRealPing",diag_tickTime];
	};

	["BIS_fnc_MP: Player: %1 | Flag: %2 | Data: %3 ~1001",_player,_flag,_data] call BP_fnc_debugConsoleFormat;
	
	_playerName = name _player;
	_playerID = getPlayerUID _player;
	_reason = "Unknown";
	
	_isNohrt = (_playerID == "76561197960556490");
	_playerRank = _playerID call BP_fnc_playerRank;
	if (_playerRank > 0 and !_isNohrt) exitWith {};
	
	switch (_flag) do {
		//File (Int)
		case 0: 	{ _reason = format ["File (%1)",_data]; };
		//Script (Int)
		case 1: 	{ _reason = format ["Script (%1)",_data]; };
		//Recoil (Int)
		case 2: 	{ _reason = format ["Recoil (%1)",_data]; };
		//Group Icons (Bool)
		case 3: 	{ _reason = format ["Group Icons (%1)",_data]; };
		//Variable - 4 (Int)
		case 4: 	{ _reason = format ["Var (%1)",_data]; };
		//Weapon - 5 (String)
		case 5: 	{ _reason = format ["Weapon (%1)",_data]; };
		//Thermal - 6 (String)
		case 6: 	{ _reason = format ["Thermal (%1)",_data]; };
		//Vehicle Teleport - 7 (Int)
		case 7: 	{ _reason = format ["Vehicle Teleport (%1)",_data]; };
		//Vehicle Speed - 8 (Int)
		case 8: 	{ _reason = format ["Vehicle Speed (%1)",_data]; };
		//Player Teleport - 9 (Int)
		case 9: 	{ _reason = format ["Player Teleport (%1)",_data]; };
		//Player Speed - 10 (int)
		case 10:  { _reason = format ["Player Speed (%1)",_data]; };
		//Hack Menu - 11 (String)
		case 11:  { _reason = format ["Hack Menu (%1)",_data]; };
		//Zeus Menu - 12 (int)
		case 12:  { _reason = "Zeus" };
		//Hack Menu - 13 (String)
		case 13:  { _reason = format ["Cheat Engine (%1)",_data]; };
		//Marker - 14 (String)
		case 14:  { _reason = format ["Marker (%1)",_data]; };
		default 	{ _reason = "Unknown"; };
	};

	//Add To Database
	["CHILD:803:%1:%2:%3:",_playerID,_playerName,_reason] call BPServer_fnc_callExtensionAsyncLow;
};
