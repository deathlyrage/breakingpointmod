////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Mon Mar 17 11:58:29 2014 : Source 'file' date Mon Mar 17 11:58:29 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=4
enum {
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0
};

//Class wheeled2 : Kamaz\config.bin{
class CfgPatches
{
	class CAWheeled2_Kamaz
	{
		units[] = {"Kamaz","KamazOpen"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class Car;
	class Truck: Car
	{
		class ViewPilot;
	};
	class Kamaz_Base: Truck
	{
		HeadAimDown = 5;
		displayName = "$STR_DN_KAMAZ";
		vehicleClass = "Car";
		model = "\ca\wheeled2\Kamaz\Kamaz";
		picture = "\Ca\wheeled2\data\ui\Picture_kamaz_CA.paa";
		Icon = "\Ca\wheeled2\data\ui\Icon_kamaz_CA.paa";
		mapSize = 8;
		side = 0;
		faction = "RU";
		crew = "RU_Soldier";
		accuracy = 0.3;
		terrainCoef = 2.0;
		maxSpeed = 80;
		wheelCircumference = 3.776;
		turnCoef = 3.7;
		steerAheadSimul = 0.5;
		steerAheadPlan = 0.38;
		transportSoldier = 12;
		transportAmmo = 0;
		transportRepair = 0;
		weapons[] = {"TruckHorn"};
		magazines[] = {};
		cost = 50000;
		armor = 32;
		damageResistance = 0.00243;
		initCargoAngleY = 185;
		soundGear[] = {"",5.6234134e-005,1};
		soundGetIn[] = {"ca\sounds\vehicles\Wheeled\Kamaz\int\int-Kamaz-getout-1",0.31622776,1};
		soundGetOut[] = {"ca\sounds\vehicles\Wheeled\Kamaz\int\int-Kamaz-getout-1",0.31622776,1,50};
		soundEngineOnInt[] = {"ca\sounds\vehicles\Wheeled\Kamaz\int\int-Kamaz-start-1",0.1,1.0};
		soundEngineOnExt[] = {"ca\sounds\vehicles\Wheeled\Kamaz\ext\ext-Kamaz-start-1",0.1,1.0,400};
		soundEngineOffInt[] = {"ca\sounds\vehicles\Wheeled\Kamaz\int\int-Kamaz-stop-1",0.1,1.0};
		soundEngineOffExt[] = {"ca\sounds\vehicles\Wheeled\Kamaz\ext\ext-Kamaz-stop-1",0.1,1.0,400};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_building_01",0.70794576,1,200};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_building_02",0.70794576,1,200};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_building_03",0.70794576,1,200};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_building_04",0.70794576,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_01",0.70794576,1,200};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_02",0.70794576,1,200};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_03",0.70794576,1,200};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_04",0.70794576,1,200};
		WoodCrash4[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_05",0.70794576,1,200};
		WoodCrash5[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_06",0.70794576,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_01",0.70794576,1,200};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_02",0.70794576,1,200};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_03",0.70794576,1,200};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_04",0.70794576,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\int\int-Kamaz-acce-1",0.1,1.0};
				limit = "0.5";
				expression = "(engineOn*(1-camPos))*gmeterZ";
			};
			class AccelerationOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\ext\ext-Kamaz-acce-1",0.1,1.0,400};
				limit = "0.5";
				expression = "(engineOn*camPos)*gmeterZ";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\Kamaz\ext\ext-Kamaz-low-1",1.0,1.0,450};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*camPos*(thrust factor[0.7, 0.2])";
			};
			class EngineHighOut
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\Kamaz\ext\ext-Kamaz-high-1",1.0,1.0,550};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*camPos*(thrust factor[0.5, 0.9])";
			};
			class IdleOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\ext\ext-Kamaz-idle-1",0.17782794,1.0,350};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.4, 0])";
			};
			class EngineOnOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\ext\ext-Kamaz-start-1",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*2*engineOn*((rpm factor[0, 0.2]) min (rpm factor[0.2, 0]))";
			};
			class TiresRockOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel2",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3",0.1,1.0,50};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\ext\noise3",0.31622776,1.0,50};
				frequency = "1";
				volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
			};
			class EngineLowIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\int\int-Kamaz-low-1",0.56234133,1.0};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "((engineOn*thrust) factor[0.7, 0.2])*(1-camPos)";
			};
			class EngineHighIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Kamaz\int\int-Kamaz-high-1",0.56234133,1.0};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "((engineOn*thrust) factor[0.5, 0.9])*(1-camPos)";
			};
			class IdleIn
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\Kamaz\int\int-Kamaz-idle-1",0.17782794,1.0};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.4, 0])*(1-camPos)";
			};
			class EngineOnIn
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\Kamaz\int\int-Kamaz-start-1",0.17782794,1.0};
				frequency = "1";
				volume = "(1-camPos)*2*engineOn*(((rpm factor[0, 0.2]) min (rpm factor[0.2, 0])))";
			};
			class TiresRockIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel2",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3",0.1,1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\int\noise3",0.31622776,1.0};
				frequency = "1";
				volume = "(damper0 max 0.04)*(speed factor[0, 8])*(1-camPos)";
			};
			class Movement
			{
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
		};
		typicalCargo[] = {"RU_Soldier","RU_Soldier","RU_Soldier_AT"};
		hasGunner = 0;
		driverAction = "Kamaz_Driver";
		cargoAction[] = {"Truck_Cargo01","Truck_Cargo01","Truck_Cargo04","Truck_Cargo04","Truck_Cargo02","Truck_Cargo03","Truck_Cargo04","Truck_Cargo02","Truck_Cargo04","Truck_Cargo04","Truck_Cargo04","Truck_Cargo04"};
		cargoIsCoDriver[] = {1,1,0};
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow","GetInLow","GetInHigh"};
		cargoGetOutAction[] = {"GetOutLow","GetOutLow","GetOutHigh"};
		class ViewPilot: ViewPilot
		{
			initAngleX = -30;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class Turrets{};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled2\Kamaz\Data\kamaz_fuel.rvmat","ca\wheeled2\Kamaz\Data\kamaz_fuel_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_fuel_destruct.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass_damage.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass_damage.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass_in.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass_in_damage.rvmat","ca\wheeled2\Kamaz\Data\Kamaz_glass_in_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_chassis.rvmat","ca\wheeled2\Kamaz\Data\kamaz_chassis_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_chassis_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_int.rvmat","ca\wheeled2\Kamaz\Data\kamaz_int_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_int_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kab.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kab_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kab_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kuz.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kuz_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_kuz_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel_shine.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel_shine_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_panel_shine_destruct.rvmat","ca\wheeled2\Kamaz\Data\kamaz_repair.rvmat","ca\wheeled2\Kamaz\Data\kamaz_repair_damage.rvmat","ca\wheeled2\Kamaz\Data\kamaz_repair_destruct.rvmat"};
		};
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"\ca\wheeled2\kamaz\data\kamaz_kab_co.paa","\ca\wheeled2\kamaz\data\kamaz_kuz_co.paa"};
		class Library
		{
			libTextDesc = "$STR_LIB_KAMAZ";
		};
	};
	class Kamaz: Kamaz_Base
	{
		scope = 2;
		cargoAction[] = {"Truck_Cargo01","Truck_Cargo01","Truck_Cargo02","Truck_Cargo03","Truck_Cargo02","Truck_Cargo02","Truck_Cargo03","Truck_Cargo02","Truck_Cargo03","Truck_Cargo02","Truck_Cargo02","Truck_Cargo03"};
	};
	class KamazOpen: Kamaz_Base
	{
		scope = 2;
		displayName = "$STR_DN_KAMAZ_OPEN";
		model = "\ca\wheeled2\Kamaz\Kamaz_Open";
		picture = "\Ca\wheeled2\data\ui\Picture_kamaz_open_CA.paa";
		Icon = "\Ca\wheeled2\data\ui\Icon_kamaz_open_CA.paa";
		castCargoShadow = 1;
		class Library
		{
			libTextDesc = "$STR_LIB_KAMAZ_OPEN";
		};
	};
};
//};
