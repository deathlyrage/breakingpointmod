/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (isServer) exitWith {};
if (isDedicated) exitWith {};
if (!hasInterface) exitWith {};
if (!isMultiplayer) exitWith {};

//Fetch Event Input Params
params ["_newUnit","_oldUnit","_respawn","_respawnDelay"];

//Wait Until Mission Init
waitUntil {missionNameSpace getVariable ["bis_fnc_init",false]};

//Logging
["onPlayerRespawn: New Unit: %1 Old Unit: %2 Respawn: %3 RespawnDelay %4~0001",_newUnit,_oldUnit,_respawn,_respawnDelay] call BP_fnc_DebugConsoleFormat;

//Send Respawn Event to Server
//if (!isNull _oldUnit) then {
//	BP_Respawn = [netID _newUnit,netID _oldUnit];
//	publicVariableServer "BP_Respawn";
//};

//Reset Blur Screen Effects
if (!isNil "BIS_UncCC") then { ppEffectDestroy BIS_UncCC; };
if (!isNil "BIS_UncRadialBlur") then { ppEffectDestroy BIS_UncRadialBlur;};
if (!isNil "BIS_UncBlur") then { ppEffectDestroy BIS_UncBlur; };
if (!isNil "BIS_SuffCC") then { ppEffectDestroy BIS_SuffCC; };
if (!isNil "BIS_SuffRadialBlur") then { ppEffectDestroy BIS_SuffRadialBlur; };
if (!isNil "BIS_SuffBlur") then { ppEffectDestroy BIS_SuffBlur; };
if (!isNil "BIS_TotDesatCC") then { ppEffectDestroy BIS_TotDesatCC; };
if (!isNil "BIS_TotCC") then { ppEffectDestroy BIS_TotCC; };
if (!isNil "BIS_TotRadialBlur") then { ppEffectDestroy BIS_TotRadialBlur; };
if (!isNil "BIS_TotBlur") then { ppEffectDestroy BIS_TotBlur; }; 
"dynamicBlur" ppEffectEnable false;

//Reset BIS Health / Effects Variables
BIS_myOxygen = 1.0;
BIS_wasHit = false;
BIS_PP_burning = false;
BIS_damageFromExplosion = 0;
BIS_performingDustPP = false;
BIS_oldLifeState = "HEALTHY";
BIS_fnc_feedback_allowDeathScreen = false;
BIS_fnc_feedback_fatiguePP = false;

BIS_respawnInProgress = false;
BIS_respawned = true;

r_hit_legs = 0;
r_hit_hands = 0;
r_player_infected = false;
r_player_injured = false;
r_player_inpain = false;
r_player_blood = 12000;
r_player_lowblood = false;
deathHandled = false;

BP_FactionStronghold = 0;

_newUnit setVariable ["traitorFlag",false,true];
r_traitorFlag = false;
r_traitorTime = diag_tickTime;

_newUnit enableSimulation true;

//Start Loading Screen
startLoadingScreen ["","RscDisplayLoadMission"];

//Disable Sound
0 fadeSound 0;

//Clear All UI Layers
{ _x cutRsc ["Default","PLAIN",0]; } count [0,1,2,3,4];

//Start Authentication Message
cutText ["","BLACK OUT"];

//Reset Player Character
_newUnit call BP_fnc_resetPlayerNamespace;

//Conduct map operations
0 cutText ["Requesting Authentication", "BLACK FADED",60];

BP_loadScreenMsg = "Requesting Authentication"; // Loading Character Data

call BP_fnc_initVars;

BP_clientPreload = false;

endLoadingScreen;

_authThread = [] execVM "\breakingpoint_code\threads\BP_Authentication.sqf";
[_authThread] call BP_fnc_addThreadHandle;

//Run the player monitor
_loginFSM = [] execFSM "\breakingpoint_code\system\login.fsm";
