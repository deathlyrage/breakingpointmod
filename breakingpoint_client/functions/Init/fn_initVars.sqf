/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/


//Global Count of Total Loot Objects
BP_LootGlobal = 0;

if (isServer) exitWith {};

BP_GPSWindID = -1;

//Self Actions Near Object Checks
BP_NearBuilding = objNull;
BP_NearStorage = objNull;

//Fired
BP_FiredAmmo = "";
BP_FiredTime = 0;

//Visual and Audio Noise
BP_disVisual = 0;
BP_disAudial = 0;

//Undead Variables
BP_isUndead = false;
BP_isHungryUndead = false;

//Auto Run
BP_AutoRun = false;
BP_AutoRunThread = scriptNull;

//Inventory
BP_RestrictedInventory = false;
BP_CurrentContainer = objNull;
BP_AllowInventory = true;
BP_InventoryThread = scriptNull;
BP_WaitingForContainer = false;

BP_NetID = 0;

BP_SafeSet = "";

//Login and Auth
BP_AuthTimer = false;
BP_PauseAuth = false;

//Timers
BP_LastGroupInvite = diag_tickTime;

//Zombies
BP_ZombieSounds = true;

//Fireplaces
BP_hasFire = objNull; //Last Created Fireplace

//Actions
call BP_fnc_resetSelfActions;

//Arm And Leg Health
r_hit_legs = 0;
r_hit_hands = 0;

//Traitor Flag and Last Flag Time
r_traitorFlag = false;
r_traitorTime = diag_tickTime;

//Engineering variables
s_player_lastTarget =	objNull;
s_player_removeActions = [];
s_player_repairActions = [];

//Initialize Medical Variables
r_player_gearSet =		false;
r_interrupt = 			false;
r_doLoop = 				false;
r_self = 				false;
r_self_actions = 		[];
r_drag_sqf = 			false;

//Anti Dupe/Glitch Actions
r_action = false;
r_action_refuel = false;
r_action_siphon = false;
r_action_repair = false;
r_action_gut = false;

//Complex Medical Variables
r_action_unload = 		false;
r_player_handler = 		false;
r_player_handler1 = 	false;
r_player_dead = 		false;
r_player_unconscious = 	false;
r_player_unconsciousWeapon = false;
r_player_infected =		false;
r_player_injured = 		false;
r_player_adrenaline = false;
r_player_adrenalineTime = diag_tickTime;
r_player_inpain = 		false;
r_player_painLevel = 	0;
r_player_loaded = 		false;
r_player_cardiac = 		false;
r_fracture_legs =		false;
r_fracture_arms =		false;
r_player_vehicle =		player;
r_player_blood = 		12000;
r_player_lowblood = 	false;
r_player_killer = objNull;
r_player_timeout =		0;
r_player_bloodTotal = 	r_player_blood;
r_public_blood =		r_player_blood;
r_player_bloodDanger =	r_player_bloodTotal * 0.2;
r_player_bleedingLevel = 0;
r_player_actions = 		[];
r_handlerCount = 		0;
r_action_repair = 		false;
r_action_targets = 		[];
r_action_rest = 		false;
r_action_restTime =		0;
r_pitchWhine = false;

//ammo routine
r_player_actions2 = [];
r_action2 = false;
r_player_lastVehicle = objNull;
r_player_lastSeat = [];

//PVEH Base Defaults
BP_Anim = [];
BP_MedicalEvent = [];
BP_PostLogin = [];

//Sync
BP_SyncLastStats = [];
BP_SyncLastInventory = [];
BP_SyncLastMed = [];

//How Long Ago Player Has Been a Hostage for enabling the respawn button
uiNamespace setVariable ["BP_LastHostageTime",0];

//player special variables
BP_forceSave =			false;
BP_unsaved =			false;
BP_lastSave =			time;
BP_lastSaveMed =		time;
BP_lastPlayerUpdate = 	time;
BP_hunger =				0;
BP_thirst = 			0;
BP_combat =				0;
BP_DeathActioned =		false;
BP_preloadFinished = 	false;
BP_statusArray =		[1,1];
BP_firedCooldown = 	0;
BP_damageCounter =	time;
BP_isSwimming	=		false;
BP_siphonFuelInProgress = false;
BP_hasLight = 		false;
BP_surfaceNoise =		0;
BP_surfaceType =		"None";
BP_noPenalty = 		[];
deathHandled = 			false;
BP_clientPreload = 	false;
BP_LocalZeds = 			0;
BP_NearbyZombies = 		0;
BP_GlobalZeds = 		0;
BP_SpawnZombies = 		0;
BP_RemoteZeds = 		0;
BP_DeadZeds = 			0;
BP_inVehicle =		false;
