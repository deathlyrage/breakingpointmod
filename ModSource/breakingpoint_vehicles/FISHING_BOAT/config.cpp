class CfgPatches 
{
	class bp_fishingboat
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[]= {"A3_Anims_F_Config_Sdr","A3_Boat_F_Gamma_Boat_Civil_01"};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		SB_Driver = "SB_Driver";
		SB_Cargo = "SB_Cargo";
		FB_Driver = "FB_Driver";
		FB_Cargo01 = "FB_Cargo01";
		FB_Cargo02 = "FB_Cargo02";
		FB_Cargo03 = "FB_Cargo03";
		FB_Cargo04 = "FB_Cargo04";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_SB_Driver: DefaultDie
		{
			actions = "DeadActions";
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\KIA_smallboat_driver.rtm";
			speed = 0.5;
			looped=false;
			terminal = 1;
			soundEnabled=0;
			connectTo[] = {"DeadState",0.1};
		};
		class SB_Driver: Crew
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\smallboat_driver.rtm";
			interpolateTo[]={"KIA_SB_Driver",1};
		};
		class SB_Cargo: Crew
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\cargo.rtm";
			interpolateTo[]={"KIA_SB_Driver",1};
		};
		class FB_Driver : SB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Driver.rtm";
		};
		class FB_Cargo01 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo01.rtm";
			connectTo[]={"FB_Cargo01",0.1,"FB_Cargo01_V1",0.1};
			equivalentTo="FB_Cargo01";
			variantsAI[]={"FB_Cargo01",0.5,"FB_Cargo01_V1",0.1};
			variantAfter[]={5,10,20};
			speed=0.3;
			head = "headDefault";
		};
		class FB_Cargo01_V1 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo01_Loop_01.rtm";
			connectTo[]={"FB_Cargo01",0.1};
			speed = 0.0526;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo02 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo02.rtm";
			connectTo[]={"FB_Cargo02",0.1,"FB_Cargo02_V1",0.1};
			equivalentTo="FB_Cargo02";
			variantsAI[]={"FB_Cargo02",0.5,"FB_Cargo02_V1",0.1};
			variantAfter[]={5,10,20};
			speed=0.3;
		};
		class FB_Cargo02_V1 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo02_Loop_01.rtm";
			connectTo[]={"FB_Cargo02",0.1};
			speed = 0.0909;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo03 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo03.rtm";
			connectTo[]={"FB_Cargo03",0.1,"FB_Cargo03_V1",0.1,"FB_Cargo03_V2",0.1,"FB_Cargo03_V3",0.1,"FB_Cargo03_V4",0.1};
			equivalentTo="FB_Cargo03";
			variantsAI[]={"FB_Cargo03",0.5,"FB_Cargo03_V1",0.1,"FB_Cargo03_V2",0.1,"FB_Cargo03_V3",0.1,"FB_Cargo03_V4",0.1};
			variantAfter[]={5,10,20};
			speed=0.3;
		};
		class FB_Cargo03_V1 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo03_Loop_01.rtm";
			connectTo[]={"FB_Cargo03",0.1};
			speed = 0.1111;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo03_V2 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo03_Loop_02.rtm";
			connectTo[]={"FB_Cargo03",0.1};
			speed = 0.0666;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo03_V3 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo03_Loop_03.rtm";
			connectTo[]={"FB_Cargo03",0.1};
			speed = 0.1428;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo03_V4 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo03_Loop_04.rtm";
			connectTo[]={"FB_Cargo03",0.1};
			speed = 0.3846;
			variantAfter[]={5,10,20};
		};
		class FB_Cargo04 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo04.rtm";
			connectTo[]={"FB_Cargo04",0.1,"FB_Cargo04_V1",0.1};
			equivalentTo="FB_Cargo04";
			variantsAI[]={"FB_Cargo04",0.5,"FB_Cargo04_V1",0.1};
			variantAfter[]={5,10,20};
			speed=0.3;
		};
		class FB_Cargo04_V1 : FB_Driver
		{
			file="\breakingpoint_vehicles\FISHING_BOAT\data\Anim\Cargo04_Loop_01.rtm";
			connectTo[]={"FB_Cargo04",0.1};
			speed = 0.25;
			variantAfter[]={5,10,20};
		};
	};
};
class CfgVehicles
{
	class Boat_Civil_01_base_F;

	class BP_Fishingboat : Boat_Civil_01_base_F 
	{
		author = "Bohemia Interactive";
		mapSize = 7.39;
		textSingular = "boat";
		textPlural = "boats";
		nameSound = "veh_ship_boat_s";
		_generalMacro = "Boat_Civil_01_base_F";
		displayName = "Trawler";
		model = "\breakingpoint_vehicles\FISHING_BOAT\fishing_boat";
		editorSubcategory = "EdSubcat_Boats";
		picture = "\A3\boat_f_gamma\Boat_Civil_01\data\UI\portrait_civilian_boat_CA.paa";
		Icon = "\A3\boat_f_gamma\Boat_Civil_01\data\UI\map_civilian_boat_CA.paa";
		memoryPointTaskMarker = "TaskMarker_1_pos";
		scope = 2;
		crewExplosionProtection = 1;
		crew = "BP_OptOut";
		side = 3;
		faction = "CIV_F";
		cost = 20000;
		threat[] = {0,0,0};
		accuracy = 0.5;
		armor = 60;
		unitInfoType = "RscUnitInfoNoWeapon";
		leftEngineEffect = "LEngEffectsSmall";
		rightEngineEffect = "REngEffectsSmall";
		simulation = "shipx";
		maxSpeed = 65;
		overSpeedBrakeCoef = 1.2;
		enginePower = 835;
		engineShiftY = 0.1;
		waterLeakiness = 1;
		turnCoef = 0.25;
		thrustDelay = 2;
		waterLinearDampingCoefY = 5;
		waterLinearDampingCoefX = 10;
		waterAngularDampingCoef = 5;
		waterResistanceCoef = 0.012;
		rudderForceCoef = 1;
		rudderForceCoefAtMaxSpeed = 0.003;
		idleRpm = 200;
		redRpm = 1200;
		brakeDistance = 1;
		getInAction = "GetInBoat";
		getOutAction = "GetOutBoat";
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		cargoGetInAction[] = {"GetInBoat"};
		cargoGetOutAction[] = {"GetOutBoat"};
		hasdriver = 1;
		driverAction="FB_Driver";
		cargoAction[]={"FB_Cargo01","FB_Cargo02","FB_Cargo03","FB_Cargo03","FB_Cargo03","FB_Cargo03","FB_Cargo04"};
		getInRadius=50;
		cargoIsCoDriver[] = {0};
		ejectDeadDriver = 0;
		ejectDeadCargo = 1;
		transportSoldier = 7;
		damageResistance = 0.00882;
		attenuationEffectType = "OpenCarAttenuation";
		insideSoundCoef = 1;
		soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_start",0.562341,1};
		soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_start",0.562341,1,300};
		soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_stop",0.562341,1};
		soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_stop",0.562341,1,300};
		buildCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_building_01",1.77828,1,200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_building_02",1.77828,1,200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_building_03",1.77828,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.33,"buildCrash1",0.33,"buildCrash2",0.34};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_wood_01",1.77828,1,200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_wood_02",1.77828,1,200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_wood_03",1.77828,1,200};
		soundWoodCrash[] = {"woodCrash0",0.33,"woodCrash1",0.33,"woodCrash2",0.34};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_01",3.16228,1,200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_02",3.16228,1,200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_03",3.16228,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.33,"ArmorCrash1",0.33,"ArmorCrash2",0.34};
		soundGeneralCollision1[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_01",1.77828,1,100};
		soundGeneralCollision2[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_02",1.77828,1,100};
		soundGeneralCollision3[] = {"A3\sounds_f\Vehicles\boat\noises\Light_metal_boat_crash_armor_03",1.77828,1,100};
		soundCrashes[] = {"soundGeneralCollision1",0.33,"soundGeneralCollision2",0.33,"soundGeneralCollision3",0.34};
		extCameraPosition[] = {0,8.0,-30.0};
		leftFastWaterEffect = "LFastWaterEffects";
		rightFastWaterEffect = "RFastWaterEffects";
		waterEffectSpeed = 5;
		engineEffectSpeed = 5;
		waterFastEffectSpeed = 28;
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class complexGearbox {
			GearboxRatios[] = {"R1",-0.782,"N",0,"D1",1.9};
			TransmissionRatios[] = {"High",1};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		class Sounds {
			class IdleOut {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_idle",0.446684,1,300};
				frequency = "0.95	+	((rpm/	1000) factor[(100/	1000),(250/	1000)])*0.15";
				volume = "engineOn*(((rpm/	1000) factor[(100/	1000),(150/	1000)])	*	((rpm/	1000) factor[(270/	1000),(200/	1000)]))";
			};
			class Engine {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_1",0.630957,1,350};
				frequency = "0.85	+	((rpm/	1000) factor[(200/	1000),(370/	1000)])*0.2";
				volume = "engineOn*(((rpm/	1000) factor[(190/	1000),(250/	1000)])	*	((rpm/	1000) factor[(380/	1000),(280/	1000)]))";
			};
			class EngineMidOut {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_3",0.794328,1,380};
				frequency = "0.85	+	((rpm/	1000) factor[(280/	1000),(480/	1000)])*0.2";
				volume = "engineOn*(((rpm/	1000) factor[(250/	1000),(350/	1000)])	*	((rpm/	1000) factor[(480/	1000),(390/	1000)]))";
			};
			class EngineMaxOut2 {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_4",0.891251,1,440};
				frequency = "0.86	+	((rpm/	1000) factor[(380/	1000),(580/	1000)])*0.2";
				volume = "engineOn*(((rpm/	1000) factor[(370/	1000),(440/	1000)])	*	((rpm/	1000) factor[(585/	1000),(495/	1000)]))";
			};
			class EngineMaxOut3 {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_5",1,1,500};
				frequency = "0.85	+	((rpm/	1000) factor[(490/	1000),(800/	1000)])*0.2";
				volume = "engineOn*(((rpm/	1000) factor[(460/	1000),(550/	1000)])	*	((rpm/	1000) factor[(780/	1000),(620/	1000)]))";
			};
			class EngineMaxOut4 {
				sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_6",1.25893,1,550};
				frequency = "0.85	+	((rpm/	1000) factor[(650/	1000),(1000/	1000)])*0.2";
				volume = "engineOn*((rpm/	1000) factor[(600/	1000),(800/	1000)])";
			};
			class WaternoiseOutW0 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.707946,1,150};
				frequency = "1";
				volume = "(speed factor[4, 1]) * water";
			};
			class WaternoiseOutW1 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.794328,1,250};
				frequency = "1";
				volume = "((speed factor[2, 6]) min (speed factor[6, 4]))";
			};
			class WaternoiseOutW2 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1,1,350};
				frequency = "1";
				volume = "(speed factor[3, 9])";
			};
			class WaternoiseOutW3 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.707946,1,150};
				frequency = "1";
				volume = "(speed factor[-4, -1]) * water";
			};
			class WaternoiseOutW4 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.794328,0.9,250};
				frequency = "1";
				volume = "((speed factor[-2, -6]) min (speed factor[-6, -4]))";
			};
			class WaternoiseOutW5 {
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1,0.9,350};
				frequency = "1";
				volume = "(speed factor[-3, -9])";
			};
			class scrubLandExt {
				sound[] = {"A3\Sounds_F\vehicles\boat\noises\boat_land_on_shallow",1.77828,1,100};
				frequency = 1;
				volume = "(scrubLand factor[0.01, 0.20])";
			};
		};
		class Exhausts {
			class Exhaust1 {
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustsEffect";
			};
		};
		class Damage
		{
			tex[]={};
			mat[]={
			};
		};
	};
};