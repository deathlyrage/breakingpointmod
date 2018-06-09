////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Mon Mar 17 12:22:47 2014 : Source 'file' date Mon Mar 17 12:22:47 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class tracked2 : T34\config.bin{
class CfgPatches
{
	class CATracked2_T34
	{
		units[] = {"T34"};
		weapons[] = {};
		requiredVersion = 0.7;
		requiredAddons[] = {"CATracked2"};
	};
};
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
		class ViewOptics;
	};
	class Tank: LandVehicle
	{
		class HitPoints;
		class Turrets
		{
			class MainTurret;
		};
		class ViewOptics: ViewOptics{};
	};
	class T34: Tank
	{
		scope = 2;
		displayName = "T-34";
		model = "\ca\tracked2\T34\T34";
		picture = "\ca\tracked2\Data\UI\Picture_t34_CA.paa";
		Icon = "\ca\tracked2\Data\UI\Icon_t34_CA.paa";
		mapSize = 7;
		driverForceOptics = 1;
		driverAction = "T90_Driver";
		driverInAction = "T90_Driver";
		tracksSpeed = 0.215;
		wheelCircumference = 2.563;
		side = 2;
		faction = "GUE";
		crew = "GUE_Soldier_1";
		accuracy = 0.8;
		armor = 300;
		damageResistance = 0.01011;
		cost = 1500000;
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor = 0.85;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 1;
			};
		};
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo05"};
		hiddenSelectionsTextures[] = {"\ca\tracked2\t34\data\t34_body01_co.paa","\ca\tracked2\t34\data\t34_body02_co.paa","\ca\tracked2\t34\data\t34_turret_co.paa","\ca\tracked2\t34\data\t34_wheels_co.paa","\ca\tracked2\t34\data\t34_body03_co.paa"};
		maxSpeed = 55;
		supplyRadius = 5;
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust";
				direction = "exhaust_dir";
				effect = "ExhaustsEffectBig";
			};
			class Exhaust2
			{
				position = "exhaust_1";
				direction = "exhaust_1_dir";
				effect = "ExhaustsEffectBig";
			};
		};
		typicalCargo[] = {"GUE_Soldier_1","GUE_Soldier_1","GUE_Soldier_1"};
		insideSoundCoef = 0.9;
		soundGear[] = {"",5.6234134e-005,1};
		soundGetIn[] = {"ca\SOUNDS\Vehicles\Tracked\T72\int\int-tank-diesel-door-1",0.56234133,1};
		soundGetOut[] = {"ca\SOUNDS\Vehicles\Tracked\T72\ext\ext-tank-diesel-door-1",0.56234133,1,60};
		soundEngineOnInt[] = {"ca\sounds\Vehicles\Tracked\T72\int\int-tank-diesel-start-2",1.0,1.0};
		soundEngineOnExt[] = {"ca\SOUNDS\Vehicles\Tracked\T72\ext\ext-tank-diesel-start-2",2.5118864,1.0,500};
		soundEngineOffInt[] = {"ca\sounds\vehicles\Tracked\T72\int\int-tank-diesel-stop-1",1.0,1.0};
		soundEngineOffExt[] = {"ca\sounds\vehicles\Tracked\T72\ext\ext-tank-diesel-stop-1",1.0,0.8,500};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_building_01",0.70794576,1,150};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_building_02",0.70794576,1,150};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_building_03",0.70794576,1,150};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_building_04",0.70794576,1,150};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_wood_01",0.70794576,1,150};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_wood_02",0.70794576,1,150};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_wood_03",0.70794576,1,150};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_wood_04",0.70794576,1,150};
		soundWoodCrash[] = {"woodCrash0",0.25,"woodCrash1",0.25,"woodCrash2",0.25,"woodCrash3",0.25};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_01",0.70794576,1,150};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_02",0.70794576,1,150};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_03",0.70794576,1,150};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_04",0.70794576,1,150};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int-tank-diesel-acceleration-1",1.7782794,1.0};
				limit = "0.15";
				expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			class AccelerationOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext-tank-diesel-acceleration-1",1.7782794,1.0,650};
				limit = "0.15";
				expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext-tank-diesel-engine3",1.7782794,1.0,1000};
				frequency = "(randomizer*0.05+0.8)*rpm";
				volume = "engineOn*camPos*(rpm factor[0.4, 0.9])";
			};
			class IdleOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext-tank-diesel-engine3",0.56234133,1.0,300};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.6, 0.15])";
			};
			class NoiseOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\noise2",1.0,1.0,150};
				frequency = "1";
				volume = "camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_hard_01",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutH1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_hard_02",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutH2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_hard_03",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutH3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_hard_04",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutH4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_hard_05",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsOutS0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_soft_01",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutS1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_soft_02",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutS2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_soft_03",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutS3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_soft_04",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutS4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\ext\ext_diesel_treads_soft_05",1.0,1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class Movement
			{
				sound[] = {"",1.0,1.0};
				frequency = "0";
				volume = "0";
			};
			class EngineIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int-tank-diesel-engine3",1.0,1.0};
				frequency = "(randomizer*0.05+0.8)*rpm";
				volume = "engineOn*(1-camPos)*(rpm factor[0.4, 1])";
			};
			class IdleIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int-tank-diesel-engine3",1.7782794,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(rpm factor[0.6, 0.15])";
			};
			class NoiseIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\noise2",0.15848932,1.0};
				frequency = "1";
				volume = "(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsInH0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_hard_01",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInH1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_hard_02",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInH2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_hard_03",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInH3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_hard_04",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInH4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_hard_05",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsInS0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_soft_01",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInS1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_soft_02",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInS2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_soft_03",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInS3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_soft_04",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInS4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\T72\int\int_diesel_treads_soft_05",1.0,1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerAction = "BMP3_Gunner_OUT";
				gunnerInAction = "BMP3_Gunner";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				weapons[] = {"ZiS_S_53","DT_veh"};
				selectionFireAnim = "zasleh";
				magazines[] = {"10Rnd_85mmAP","33Rnd_85mmHE","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT"};
				soundServo[] = {"\Ca\sounds\Vehicles\Tracked\Other\int\int-servo",0.17782794,1.0};
				gunnerOpticsModel = "\ca\weapons\2Dscope_T90gun12";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsEffect[] = {};
				stabilizedInAxes = 0;
				minElev = -6;
				maxElev = 14;
				initElev = 0;
				gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur3","OpticsCHAbera3"};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.2;
					minFov = 0.025;
					maxFov = 0.2;
				};
				class Turrets: Turrets
				{
					class CommanderOptics: NewTurret
					{
						weapons[] = {};
						magazines[] = {};
						gunBeg = "gun_muzzle";
						gunEnd = "gun_chamber";
						body = "ObsTurret";
						gun = "ObsGun";
						gunnerAction = "BMP3_Commander_OUT";
						gunnerInAction = "BMP3_Commander";
						gunnerGetInAction = "GetInMedium";
						gunnerGetOutAction = "GetOutMedium";
						stabilizedInAxes = 0;
						minElev = -25;
						maxElev = 60;
						initElev = 0;
						minTurn = -360;
						maxTurn = 360;
						initTurn = 0;
						gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
						gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
						gunnerOutOpticsColor[] = {0,0,0,1};
						gunnerOutForceOptics = 0;
						gunnerOutOpticsShowCursor = 0;
						startEngine = 0;
						memoryPointGunnerOutOptics = "CommanderViewOut";
						memoryPointGunnerOptics = "commanderview";
						memoryPointsGetInGunner = "pos commander";
						memoryPointsGetInGunnerDir = "pos commander dir";
						memoryPointGun = "gun_muzzle";
						selectionFireAnim = "zasleh_1";
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur3","OpticsCHAbera3"};
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.3;
							minFov = 0.015;
							maxFov = 0.3;
						};
						class ViewGunner
						{
							initAngleX = 5;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.7;
							minFov = 0.25;
							maxFov = 1.1;
						};
						soundServo[] = {"\Ca\sounds\Vehicles\Tracked\Other\int\int-servo",0.17782794,1.0};
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						proxyType = "CPCommander";
						proxyIndex = 1;
						gunnerName = "$STR_POSITION_COMMANDER";
						primaryGunner = 0;
						primaryObserver = 1;
						animationSourceBody = "obsTurret";
						animationSourceGun = "obsGun";
						animationSourceHatch = "hatchCommander";
						commanding = 2;
						viewGunnerInExternal = 0;
					};
				};
			};
			class FrontGunner: MainTurret
			{
				gunnerName = "$STR_position_frontgunner";
				gunBeg = "FrontGunner_muzzle";
				gunEnd = "FrontGunner_chamber";
				body = "FrontGunnerTurret";
				gun = "FrontGunnerGun";
				gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
				animationSourceBody = "FrontGunnerTurret";
				animationSourceGun = "FrontGunnerGun";
				memoryPointGun = "FrontGunner_muzzle";
				memoryPointGunnerOptics = "FrontGunnerview";
				class Turrets{};
				proxyIndex = 2;
				weapons[] = {"DT_veh"};
				selectionFireAnim = "zasleh1";
				magazines[] = {"60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT"};
				startEngine = 0;
				stabilizedInAxes = 0;
				minElev = -16;
				maxElev = 16;
				initElev = 0;
				minTurn = -16;
				maxTurn = 16;
				initTurn = 0;
				forceHideGunner = 1;
			};
		};
		type = 1;
		threat[] = {0.4,0.4,0.0};
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
	};
};
//};
