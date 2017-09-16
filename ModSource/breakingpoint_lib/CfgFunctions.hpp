/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgFunctions
{
	//Functions
	//delete A3_Bootcamp;
	delete A2PMC;
	delete Curator_F;
	delete A3_Functions_F_Curator;

	//Modules
	delete A3_Modules;
	delete A3_Modules_F_Bootcamp;
	delete A3_Modules_F_Curator;
	delete A3_Modules_F_Kart;

	class A3 
	{
		class Conversations
		{
			class kbTell { file = "\breakingpoint_functions\void.sqf"; };
			class isUnitVirtual { file = "\breakingpoint_functions\void.sqf"; };
		};
		
		class Effects {
			file = "\breakingpoint_functions\functions\Effects";
			class effectFired {};
			class effectKilled {};
			class effectPlankton {};
			class effectFiredLongSmoke {};
			class effectFiredRifle {};
			class effectFiredArtillery {};
			class effectFiredRocket {};
			class effectFiredSmokeLauncher {};
			class effectFiredSmokeLauncher_boat {};
			class effectFiredFlares {};
			class effectFiredHeliRocket {};
			class effectKilledAirDestruction {};
			class effectKilledAirDestructionStage2 {};
			class effectKilledSecondaries {};
		};
		
		class Environment {
			file = "\breakingpoint_functions\functions\Environment";
			class setPPeffectTemplate {};
		};
		
		//Disabled Cause Nexus
		//class Variables
		//{
		//	file = "\breakingpoint_functions\functions\Variables";
		//	class areEqual {};
		//	class loadFunctions {};
		//	class swapVars {};
		//	class variableSpaceAdd {};
		//	class variableSpaceRemove {};
		//};
		
		class GUI
		{
			class credits { file = "\breakingpoint_functions\void.sqf"; };
			class credits_movie { file = "\breakingpoint_functions\void.sqf"; };
			class credits_movieConfig { file = "\breakingpoint_functions\void.sqf"; };
			class credits_movieSupport { file = "\breakingpoint_functions\void.sqf"; };
		};

		class Misc
		{
			class addStackedEventHandler { file = "\breakingpoint_functions\void.sqf"; };
			class executeStackedEventHandler { file = "\breakingpoint_functions\void.sqf"; };
			class removeStackedEventHandler { file = "\breakingpoint_functions\void.sqf"; };
			class initExpo { file = "\breakingpoint_functions\void.sqf"; };
			class enableSaving { file = "\breakingpoint_functions\void.sqf"; };
			class disableSaving { file = "\breakingpoint_functions\void.sqf"; };
		};
		class Respawn
		{
			class respawnTickets { file = "\breakingpoint_functions\void_num.sqf"; };
			class addRespawnPosition { file = "\breakingpoint_functions\void.sqf"; };
			class addRespawnInventory { file = "\breakingpoint_functions\void.sqf"; };
			class setRespawnInventory { file = "\breakingpoint_functions\void.sqf"; };
			class respawnEndMission { file = "\breakingpoint_functions\void.sqf"; };
		};
		
		class Modules
		{
			class moduleExecute { file = "\breakingpoint_functions\void.sqf"; };
		};
		
		class Diagnostic 
		{
			file = "A3\functions_f\Diagnostic";
			delete diagAAR;
			delete diagAARrecord;
			delete diagHit;
			delete diagKey;
			delete diagRadio;
			delete diagMissionWeapons;
			delete diagMissionPositions;
			delete diagPreview;
			delete diagPreviewVehicleCrew;
			delete diagPreviewCycle;
			delete diagKeyLayout;
			delete diagKeyTest;
			delete diagWiki;
			delete diagVehicleIcons;
			delete diagConfig;
			delete diagLoop;
			delete locWeaponInfo;
			delete diagKnownTargets;
			delete diagKnownAsTarget;
			delete diagBulletCam;
			delete diagMacros;
			delete diagMacrosVerify;
			delete diagMacrosMapSize;
			delete diagMacrosNameSound;
			delete diagMacrosAuthor;
			delete diagFindMissingAuthors;
			delete exportGroupFormations;
			delete exportCfgVehicles;
			delete exportCfgWeapons;
			delete exportCfgMagazines;
			delete exportCfgPatches;
			delete exportCfgHints;
			delete importImageLinks;
		};
		
		class Objects
		{
			class objectVar { file = "\breakingpoint_functions\void.sqf"; };
		};
		
		class Missions
		{
			class missionHandlers { file = "\breakingpoint_functions\void.sqf"; };
			class missionTasks { file = "\breakingpoint_functions\void.sqf"; };
		};
		
		delete Tasks;
		delete ModuleFiringDrills;
		delete ModuleTimeTrials;
		delete Vehicles;
		delete Waypoints;
		delete Hints;
		delete Map;
		delete MP;
		delete Spawning;
	};
	
	class A2OA
	{
		class GUI
		{
			class AAN { file = "\breakingpoint_functions\void.sqf"; };
			class dynamicText { file = "\breakingpoint_functions\void.sqf"; };
		};
		delete Misc;
		delete Systems;
	};
	
	class HSim 
	{
		tag = BIS;
		
		class Ambient {
			file = "A3\functions_f\ambient";
			
			class ambientBoats {
				description = "Ambient boats";
				ext = ".fsm";
			};
			
			class ambientHelicopters {
				description = "Ambient helicopters";
				ext = ".fsm";
			};
			
			class ambientPlanes {
				description = "Ambient planes";
				ext = ".fsm";
			};
			
			class ambientBlacklist {
				description = "Register blacklisted areas in mission for ambient environment";
			};
			
			class ambientBlacklistAdd {
				description = "Register blacklisted area for ambient environment";
			};
			
			class ambientPostprocess {
				description = "Ambient postprocess";
			};
		};
		
		delete Conversations;

		class Database {
			file = "A3\functions_f\database";
			
			class dbSymbolClass {
				description = "Returns database specific symbol for class";
			};
			
			class dbSymbolValue {
				description = "Returns database specific symbol for value";
			};
			
			class dbisClass {
				description = "Check if item is class";
			};
			
			class dbisValue {
				description = "Check if item is value";
			};
			
			class dbClassId {
				description = "Set class name";
			};
			
			class dbClassSet {
				description = "Add database container";
			};
			
			class dbClassCheck {
				description = "Check if container exists in database";
			};
			
			class dbClassIndex {
				description = "Returns index path to database container";
			};
			
			class dbClassRemove {
				description = "Remove database container";
			};
			
			class dbClassReturn {
				description = "Returns all values in database container.";
			};
			
			class dbClassList {
				description = "Returns classes in given class";
			};
			
			class dbValueId {
				description = "Set value name";
			};
			
			class dbValueSet {
				description = "Add a value to database";
			};
			
			class dbValueCheck {
				description = "Check if value exists in database";
			};
			
			class dbValueIndex {
				description = "Returns index path to database value";
			};
			
			class dbValueRemove {
				description = "Remove a value from database";
			};
			
			class dbValueReturn {
				description = "Returns value";
			};
			
			class dbValueList {
				description = "Returns values in given class";
			};
			
			class dbImportConfig {
				description = "Add database containers based on config containers";
			};
			
			class dbImportXML {
				description = "Add database containers based on XML file";
			};
			
			class dbConfigPath {
				description = "Returns config path with the same address as DB path";
			};
			
			class dbPrint {
				description = "Print a database";
			};
		};
		
		class Debug 
		{
			file = "A3\functions_f\Debug";
			
			class error {
				description = "Display debug error";
				headerType = 1;
			};
			
			class errorMsg {
				description = "Display dialog error";
				headerType = 1;
			};
			
			class halt {
				description = "Terminate script";
				headerType = 1;
			};
			
			class param {
				description = "Define script param";
				headerType = 1;
			};
			
			class paramIn {
				description = "Define script param without overload ability";
				headerType = 1;
			};
			
			class log {
				description = "Debug message";
				headerType = 1;
			};
			
			class functionsDebug {
				description = "Set Functions debug mode";
			};
			
			class functionPath {
				description = "Return path to the given function";
			};
			
			class codePerformance {
				description = "Measures how much time it takes to execute given expression";
			};
			
			class GC {
				description = "Garbage Collector";
			};
			
			class GCinit {
				description = "Garbage Collector Init";
				ext = ".fsm";
			};
			
			class shutdown {
				description = "Shut downs the game.";
			};
		};
		
		class GUI {
			file = "A3\functions_f\GUI";
			class getIDD {};
			class getIDC {};
			class GUIeditor {};
			class GUIbackground {};
			class GUImessage {};
			delete GUIhint;
			class GUIgrid {};
			class GUIgridToProfile {};
			class GUInewsfeed {};
			class PIP {};
			class camFollow {};
			class displayColorSet {};
			class displayColorGet {};
			class displayControls {};
			class displayResize {};
			class displayClouds {};
			class displayLoading {};
			class displayMission { file = "\breakingpoint_lib\GUI\fn_displayMission.sqf"; };
			class overviewTimeTrial {};
			class overviewMission {};
			class overviewAuthor {};
			class overviewTerrain {};
			class overviewDifficulty {};
			delete diaryHints;
			delete diaryMaps;
			class HUDLimits {};
			class credits { file = "\breakingpoint_functions\void.sqf"; };
			class titleText {};
			class ctrlTextHeight {};
			class shakeGauges {};
		};
		
		class Helicopters {
			file = "A3\functions_f\helicopters";
			class helicopterDamage {};
			class helicopterCanFly {};
			class helicopterSeat {};
			class helicopterSeatMove {};
			class helicopterType {};
			class helicopterGetHitpoints {};
		};
		
		class Map {
			file = "A3\functions_f\Map";
			class KMLimport {};
			class noFlyZonesCreate {};
			class noFlyZonesExport {};
			class noFlyZone {};
			class keypointsExport {};
			class keypointsExportFromKML {};
			class worldArea {};
			class randomPos {};
			class randomPosTrigger {};
			class markerCreate {};
			class markerParams {};
			class markerPath {};
			class posDegtoUTM {};
			class posDegToWorld {};
			class posUTMToDeg {};
			class nearestHelipad {};
		};
		
		class Misc 
		{
			file = "A3\functions_f\Misc";
			delete endMission;
			delete onLoad;
			delete onEnd;
			class displayName {};
			class counter {};
			class isLocalized {};
			class roundDir {};
			class saveGame {};
			class animType {};
			class position {};
			class assignPlayerRole {};
			class convertUnits {};
			class moveIn {};
			class setHeight {};
			class playerName {};
		};
		
		class Missions {
			file = "A3\functions_f\Missions";
			class singleMissionName {};
			class singleMissionConfig {};
			class singleMissionKeys {};
		};
		
		delete MP;
		
		class Numbers {
			file = "A3\functions_f\Numbers";
			class numberDigits {};
			class numberText {};
		};
		
		class Radio {
			file = "A3\functions_f\radio";
			class radioSetChannel {};
			class radioSetPlaylist {};
			class radioSetTrack {};
		};
		
		class Strings {
			file = "A3\functions_f\Strings";
			class secondsToString {};
		};
	};
};
