/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Load Mission File Configuration
BP_ServerInstance = (paramsArray select 0);
BP_Debug = (paramsArray select 1) == 1;
BP_HC = (paramsArray select 2) == 1;
BP_VIP = (paramsArray select 3) == 1;
BP_DynamicWeather = (paramsArray select 4) == 1;
BP_ClientSimulationManager = (paramsArray select 5) == 1;
BP_ServerSimulationManager = (paramsArray select 6) == 1;
BP_ThreadedCleanup = (paramsArray select 7) == 1;
BP_LootMax = (paramsArray select 8);
BP_LootServer = (paramsArray select 9) == 1;
BP_LegionOnly = (paramsArray select 10) == 1;
BP_FastBoot = (paramsArray select 11) == 1;

//Server Main Variables
BP_ServerLogic = missionNamespace getVariable ["bis_functions_mainscope",objNull];
//BP_ServerID = (owner BP_ServerLogic);
BP_MissionRoot = format ["mpmissions\__CUR_MP.%1\", worldName];

//Events
onPlayerConnected		"[_id,_name,_uid,_owner,_jip] call BPServer_fnc_onPlayerConnect;";
onPlayerDisconnected 	"[_id,_name,_uid] call BPServer_fnc_onPlayerDisconnect;";
addMissionEventHandler ["HandleDisconnect",{_this call BPServer_fnc_handleDisconnect;}];

//Removed Hack BIS_fnc_MainScope Logic
//deleteVehicle bis_functions_mainscope;
bis_functions_mainscope = objNull;

BP_ServerLogic setName ["SERVER","SERVER",""];

//Dead Bodies
BP_Cleanup_Dead_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Dead" >> "interval");
BP_Cleanup_Dead_Nearby = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Dead" >> "nearby");
BP_Cleanup_Dead_Player = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Dead" >> "player");
//Sync
BP_Cleanup_Sync_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Sync" >> "interval");
//Loot
BP_Cleanup_Loot_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Loot" >> "interval");
BP_Cleanup_Loot_Nearby = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Loot" >> "nearby");
//Entities
BP_Cleanup_Entities_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Entities" >> "interval");
BP_Cleanup_Entities_Nearby = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Entities" >> "nearby");
//Global Loot
BP_Cleanup_GlobalLoot_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "GlobalLoot" >> "interval");
//Restart
BP_Cleanup_Restart_Interval = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "Cleanup" >> "Restart" >> "interval");

// Setup Radio Channels
BP_Radio_Ranger = radioChannelCreate [[0, 1, 0, 0.8], "Ranger", "%UNIT_NAME", []];
BP_Radio_Outlaw = radioChannelCreate [[1, 0, 0, 0.8], "Outlaw", "%UNIT_NAME", []];
BP_Radio_Nomad = radioChannelCreate [[0, 0, 1, 0.8], "Nomad", "%UNIT_NAME", []];
BP_RadioChannels = [BP_Radio_Ranger,BP_Radio_Outlaw,BP_Radio_Nomad];

//Make Server Logic Join Faction Chats
{ _x radioChannelAdd [BP_ServerLogic]; } count BP_RadioChannels;

_extra = ["ItemKnife"];
BP_RemoteAllowedMags = BP_FuelFull + BP_FuelEmpty + BP_Throwables + BP_MeleeAmmo + AllFood + AllDrinks + AllMedical + food_output + drink_output + _extra;

BP_Devs = 
{
	[
	]
};

BP_SeniorAdmins = 
{
	[
	]
};

BP_NinjaAdmins =
{
	[
	]
};

BP_JuniorAdmins = 
{
	[
	]
};

BP_Moderators = 
{
	[
	]
};

BP_fnc_playerRank = 
{
	_playerID = _this;
	_return = 0;
	
	//Developer
	if (_playerID in call BP_Devs) then { _return = 4; };
	//Senior Admin
	if (_playerID in call BP_SeniorAdmins) then { _return = 3; };
	//Ninja Admin
	if (_playerID in call BP_NinjaAdmins) then { _return = 1; };
	//Junior Admin
	if (_playerID in call BP_JuniorAdmins) then { _return = 2; };
	//Moderator
	if (_playerID in call BP_Moderators) then { _return = 1; };

	_return
};

["BP_fnc_playerRank"] call BP_fnc_compileFinal;
["BP_Devs"] call BP_fnc_compileFinal;
["BP_SeniorAdmins"] call BP_fnc_compileFinal;
["BP_NinjaAdmins"] call BP_fnc_compileFinal;
["BP_JuniorAdmins"] call BP_fnc_compileFinal;
["BP_Moderators"] call BP_fnc_compileFinal;

//Create Center
createCenter civilian;
createCenter east;
createCenter west;

east setFriend [west,0];
west setFriend [east,0];

// Spawn Vehicles
_serverStartup = [] execVM "\breakingpoint_server\monitor.sqf";
[_serverStartup] call BP_fnc_addThreadHandle;
