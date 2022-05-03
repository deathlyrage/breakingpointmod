/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/


#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define NO_SIDE -1
#define EAST 0			// (Russian)
#define WEST 1			// (NATO)
#define RESISTANCE 2	// Guerilla 
#define CIVILIAN 3
#define NEUTRAL 4
#define ENEMY 5
#define FRIENDLY 6
#define LOGIC 7
 
#include "Configs\basicDefines.hpp"

class CfgPatches {
	class breakingpoint_code {
		units[] = {};
		weapons[] = {}; 
		requiredVersion = 0.1;
		requiredAddons[] = {
										"breakingpoint_functions",
										"breakingpoint",
										"A3_Characters_F",
										"A3_Structures_F_Households",
										"A3_Structures_F_Ind",
										"A3_Structures_F_Mil_Barracks",
										"A3_Weapons_F_Ammoboxes"
									};
	};
};

class CfgMods
{
	class BreakingPoint
	{
		dir = "@BreakingPoint";
		picture = "\breakingpoint_ui\general\BP_screen_logo.paa";
		name = "Breaking Point";
		author = "Deathlyrage";
		hidePicture = 1;
		hideName = 1;
		version = "0.3";
	};
};

#include "Configs\RscTitles.hpp"
#include "Configs\CfgVehicles.hpp"
#include "Configs\CfgWeapons.hpp"
#include "Configs\CfgMagazines.hpp"
#include "Configs\CfgLoot\CfgBuildingLoot.hpp"
#include "Configs\CfgAmmo.hpp"
#include "Configs\CfgFactions\CfgFactions.hpp"
#include "Configs\CfgMovesAnimal.hpp"
#include "Configs\CfgMovesDog.hpp"

#include "Configs\CfgMissions.hpp"
#include "Configs\CfgActions.hpp"
#include "Configs\CfgRemoteExec.hpp"
#include "Configs\CfgDifficultyPresets.hpp"

class CfgAddons
{
	class PreloadBanks
	{
	};
	class PreloadAddons
	{
		class breakingpoint
		{
			list[] = {"breakingpoint_functions","breakingpoint_code","breakingpoint","breakingpoint_infected","breakingpoint_weapons","breakingpoint_weapons_cfg","breakingpoint_anim","breakingpoint_sfx","breakingpoint_vehicles"};
		};
	};
};

class CfgRespawnTemplates
{
	//--- Defaults
	respawnTemplatesNone[] = {"BP_Base","Counter"};
	respawnTemplatesBird[] = {"BP_Base","Counter"};
	respawnTemplatesInstant[] = {"BP_Base","Counter"};
	respawnTemplatesBase[] = {"BP_Base","Counter"};
	respawnTemplatesGroup[] = {"BP_Base","Counter"};
	respawnTemplatesSide[] = {"BP_Base","Counter"};

	class BP_Base
	{
		onPlayerKilled = "\breakingpoint_code\events\onPlayerKilled.sqf";
		onPlayerRespawn = "\breakingpoint_code\events\onPlayerRespawn.sqf";
		respawnDelay = 45;
	};
};

class CfgAISkill {
	aimingaccuracy[] = {0, 0, 1, 1};
	aimingshake[] = {0, 0, 1, 1};
	aimingspeed[] = {0, 0, 1, 1};
	commanding[] = {0, 0, 1, 1};
	courage[] = {0, 1, 1, 1};
	endurance[] = {0, 0, 1, 1};
	general[] = {0, 0, 1, 1};
	reloadspeed[] = {0, 0, 1, 1};
	spotdistance[] = {0, 0, 1, 0.6};
	spottime[] = {0, 0, 1, 1};
};

class CfgSurvival {
	class Meat {
		class Default {
			yield = 2;
			rawfoodtype = "FoodMeatRaw";
		};
		
		/* Sheep */
		class BP_Sheep_Base: Default {
			yield = 4;
			rawfoodtype = "FoodMuttonRaw";
		};
		class BP_Sheep_1: BP_Sheep_Base {};
		class BP_Sheep_2: BP_Sheep_Base {};
		class BP_Sheep_3: BP_Sheep_Base {};
		class BP_Sheep_4: BP_Sheep_Base {};
		
		/* Chicken */
		class BP_Chicken_Base: Default {
			yield = 2;
			rawfoodtype = "FoodChickenRaw";
		};
		class BP_Chicken_1: BP_Chicken_Base {};
		class BP_Chicken_2: BP_Chicken_Base {};
		
		class BP_Player_Base : Default {
			rawfoodtype = "FoodPlayerRaw";
		};
		class BP_Rabbit: Default {
			yield = 1;
			rawfoodtype = "FoodrabbitRaw";
		};
		class zZombie_Base : Default {
			rawfoodtype = "FoodZombieRaw";
		};
	};
};


class UserActionGroups {
	class All {};
	class BasicInfantryControls {};
	class Car {};
	class Air {};
	class Helicopter {};
	class Submarine {};
	class Buldozer {};
	class UserActions {};
	
	class Common : UserActions {
		name = "$STR_A3_UserActionGroups_Common_0";
		group[] = {"gear", "showMap", "hideMap", "diary", "MiniMap", "MiniMapToggle", "compass", "compassToggle", "watch", "watchToggle", "nightVision", "binocular", "headlights", "prevAction", "nextAction", "Action", "ActionContext", "menuBack", "LiteUnitInfoToggle", "help", "vehicleTurbo", "GetOut", "Eject", "swapGunner", "selectAll", "switchCommand"};
	};
	
	class Weapons {
		name = "$STR_A3_UserActionGroups_Weapons_0";
		group[] = {"defaultAction", "fire", "reloadMagazine", "nextWeapon", "prevWeapon", "switchWeapon", "handgun", "optics", "opticsTemp", "opticsMode", "holdBreath", "tempRaiseWeapon", "toggleRaiseWeapon", "throw", "cycleThrownItems", "zeroingUp", "zeroingDown", "gunElevUp", "gunElevDown", "gunElevSlow", "gunElevAuto", "lockTarget", "lockTargetToggle", "revealTarget", "lockTargets", "lockEmptyTargets", "vehLockTargets", "vehLockEmptyTargets", "switchGunnerWeapon", "heliManualFire", "launchCM", "nextCM"};
	};
	
	class View : UserActions {
		name = "$STR_A3_UserActionGroups_View_0";
		group[] = {"AimUp", "AimDown", "AimLeft", "AimRight", "AimHeadUp", "AimHeadDown", "AimHeadLeft", "AimHeadRight", "personView", "tacticalView", "zoomTemp", "lookAround", "lookAroundToggle", "lookLeftUp", "lookUp", "lookRightUp", "lookLeft", "lookCenter", "lookRight", "lookLeftDown", "lookDown", "lookRightDown", "zoomIn", "zoomInToggle", "zoomOut", "zoomOutToggle", "lookShiftUp", "lookShiftDown", "lookShiftForward", "lookShiftLeft", "lookShiftCenter", "lookShiftRight", "lookShiftBack", "lookRollLeft", "lookRollRight", "lookLeftCont", "lookRightCont", "lookDownCont", "lookUpCont", "zoomContIn", "zoomContOut", "lookShiftLeftCont", "lookShiftRightCont", "lookShiftUpCont", "lookShiftForwardCont", "lookRollLeftCont", "lookRollRightCont"};
	};
	
	class Multiplayer : UserActions {
		name = "$STR_A3_UserActionGroups_Multiplayer_0";
		group[] = {"networkStats", "networkPlayers", "prevChannel", "nextChannel", "chat", "pushToTalk", "voiceOverNet", "PushToTalkCommand", "PushToTalkGroup", "PushToTalkVehicle", "PushToTalkDirect"};
	};
	
	class MovementInfantry : UserActions {
		name = "$STR_A3_UserActionGroups_MovementInfantry_0";
		group[] = {"MoveForward", "MoveBack", "TurnLeft", "TurnRight", "MoveFastForward", "MoveSlowForward", "turbo", "TurboToggle", "MoveLeft", "MoveRight", "TactTemp", "TactToggle", "TactShort", "WalkRunTemp", "WalkRunToggle", "adjust", "Stand", "Crouch", "Prone", "MoveUp", "MoveDown", "SwimUp", "SwimDown", "EvasiveLeft", "EvasiveRight", "LeanLeft", "LeanLeftToggle", "LeanRight", "LeanRightToggle", "GetOver", "Salute", "SitDown"};
	};
	
	class MovementCar : UserActions {
		name = "$STR_A3_UserActionGroups_MovementCar_0";
		group[] = {"CarForward", "CarBack", "CarLeft", "CarRight", "CarFastForward", "CarSlowForward", "CarHandBrake", "CarWheelLeft", "CarWheelRight", "CarAimUp", "CarAimDown", "CarAimLeft", "CarAimRight", "TurnIn", "TurnOut"};
	};
	
	class MovementHelicopter : UserActions {
		name = "$STR_A3_UserActionGroups_MovementHelicopter_0";
		group[] = {"HeliCyclicForward", "HeliCyclicBack", "HeliCyclicLeft", "HeliCyclicRight", "HeliCollectiveRaise", "HeliCollectiveLower", "HeliRudderLeft", "HeliRudderRight", "HeliLeft", "HeliRight", "AutoHover", "AutoHoverCancel", "HeliCollectiveRaiseCont", "HeliCollectiveLowerCont"};
	};
	
	class MovementAir : UserActions {
		name = "$STR_A3_UserActionGroups_MovementAir_0";
		group[] = {"HeliForward", "HeliBack", "AirBankLeft", "AirBankRight", "HeliFastForward", "HeliUp", "HeliDown", "HeliRudderLeft", "HeliRudderRight", "HeliLeft", "HeliRight", "LandGear", "LandGearUp", "FlapsDown", "FlapsUp", "HeliThrottlePos", "HeliThrottleNeg"};
	};
	
	class MovementSubmarine : UserActions {
		name = "$STR_A3_UserActionGroups_MovementSubmarine_0";
		group[] = {"submarineUp", "submarineDown", "submarineLeft", "submarineRight", "submarineForward", "submarineBack", "submarineCyclicForward", "submarineCyclicBack"};
	};
	
	class BuldozerControls : UserActions {
		name = "$STR_A3_UserActionGroups_BuldozerControls_0";
		group[] = {"BuldSwitchCamera", "BuldFreeLook", "BuldSelect", "BuldResetCamera", "BuldMagnetizePoints", "BuldMagnetizePlanes", "BuldMagnetizeYFixed", "BuldTerrainRaise1m", "BuldTerrainRaise10cm", "BuldTerrainLower1m", "BuldTerrainLower10cm", "BuldTerrainRaise5m", "BuldTerrainRaise50cm", "BuldTerrainLower5m", "BuldTerrainLower50cm", "BuldTerrainShowNode", "BuldSelectionType", "BuldLeft", "BuldRight", "BuldForward", "BuldBack", "BuldMoveLeft", "BuldMoveRight", "BuldMoveForward", "BuldMoveBack", "BuldTurbo", "BuldUp", "BuldDown", "BuldLookLeft", "BuldLookRight", "BuldLookUp", "BuldLookDown", "BuldZoomIn", "BuldZoomOut", "BuldTextureInfo", "BuldBrushRatio", "BuldBrushStrength", "BuldBrushSmooth", "BuldBrushRandomize", "BuldBrushOuter", "BuldUndo", "BuldRedo", "BuldCreateObj", "BuldDuplicateSel", "BuldRemoveSel", "BuldRotateSelX", "BuldRotateSelZ", "BuldScaleSel", "BuldElevateSel", "SeagullUp", "SeagullDown", "SeagullForward", "SeagullBack", "SeagullFastForward", "cheat1", "cheat2"};
	};
	
	class UserActionsControls : UserActions {
		name = $STR_USRACT_GROUP_USER;
		group[] = {"User1", "User2", "User3", "User4", "User5", "User6", "User7", "User8", "User9", "User10", "User11", "User12", "User13", "User14", "User15", "User16", "User17", "User18", "User19", "User20"};
	};
};


/* Blood Mist Effects */

class CfgCloudlets {
	class Blood;	// External class reference
	
	class BloodMist : Blood {
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal_02";
		particleFSNtieth = 8;
		particleFSIndex = 4;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		lifeTime = 0.3;
		size[] = {"(hit/50 + 0.5)", "2*(hit/50 + 0.5)"};
		color[] = {{1, 0, 0, 0.1}, {1, 0, 0, 0.05}};
		randomDirectionPeriod = 0.3;
		randomDirectionIntensity = 0.3;
		weight = 0.127;
	};
	
	/*extern*/ class SmallFireF;

	class SmallFireBP: SmallFireF {
		coreIntensity = 0.000000;
		coreDistance = 0.000000;
		damageTime = 0.000000;
		constantDistance = 0.000000;
		damageType = "";
	};
};

class ImpactEffectsBlood {
	class BloodMist {
		simulation = "particles";
		type = "BloodMist";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
		MoveVelocityVar[] = {0, 0, 0};
	};
	
	class Blood {
		simulation = "particles";
		type = "Blood";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.2;
		MoveVelocityVar[] = {2, 2, 2};
	};
	
	class Blood1 {
		simulation = "particles";
		type = "Blood1";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.65;
	};
	
	class Blood2 {
		simulation = "particles";
		type = "Blood2";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.4;
	};
	
	class Blood3 {
		simulation = "particles";
		type = "Blood3";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.4;
	};
	
	class BloodUnderwater1 {
		simulation = "particles";
		type = "BloodUnderwater1";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.4;
	};
};
