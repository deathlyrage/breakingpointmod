/*
	Function: BPServer_fnc_playerLoginAI;
	Description: Checks player white listing and loads in character data.
	Example: [_playerID,_player,_playerName,_clientID,_timerAuthed] call BPServer_fnc_playerLogin;
	Call Method: Call
	Author: Deathlyrage
*/

//private ["_timerAuthed","_isAdmin","_whitelisted","_primary","_worldspace","_inventory","_isNew","_newPlayer","_charID","_survival","_model","_lastserver","_class"];

// Load Thread Params
params ["_playerID","_player","_playerName","_clientID","_body"];

//Don't Let HC Login
//if (_playerName == "headlessclient") exitWith {};
//if (_playerName == "hc") exitWith {};

_body triggerDynamicSimulation true;

_isNew = false;
_charID = _body getVariable ["CharacterID","0"];
_dogData = _body getVariable ["dogData",[]];
_randomSpot = false;

//Load Local Player State Variables
//_kills = _body getVariable ["zombieKills",0];
//_killsH = _body getVariable ["humanKills",0];
//_headShots = _body getVariable ["headShots",0];
_class = _body getVariable ["class",0];
_ranger = _body getVariable ["ranger",0];
_outlaw = _body getVariable ["outlaw",0];
_hunter = _body getVariable ["hunter",0];
_nomad = _body getVariable ["nomad",0];
_survivalist = _body getVariable ["survivalist",0];
_engineer = _body getVariable ["engineer",0];
_undead = _body getVariable ["undead",0];

//Fetch Medical
_medical = _body call BP_fnc_sumMedical;

//Fetch Survival
_survival = _body getVariable ["survival",[0,0]];

//Set Dog
_body setVariable ["dog",objNull];
_body setVariable ["dogID",0];

//Set Misc
_body setVariable ["recentKills",[]];
_body setVariable ["med_BloodQty",(_medical select 8)];
_body setVariable ["messing",(_medical select 10)];


//Remove Player from disconnection list, because we terminated the script early due to hot reloading
_index = BP_AntiDisconnectIDs find _playerID;
if (_index >= 0) then 
{
	BP_AntiDisconnectIDs deleteAt _index;
	BP_AntiDisconnectObjs deleteAt _index;
};

//Cancel any other hot reloads if it is happening
_body setVariable ["hotReload",false];

//Send Login Data
[_clientID,[_playerID,(netID _body),_charID,_isNew,_randomSpot,_medical,_survival,[_class,_ranger,_outlaw,_hunter,_nomad,_survivalist,_engineer,_undead],_dogData]] call BPServer_fnc_sendLogin;