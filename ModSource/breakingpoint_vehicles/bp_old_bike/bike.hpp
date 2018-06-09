class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Old_bike_dead = "Old_bike_dead";
		OldBike_Driver = "OldBike_Driver";
		OldBike_Cargo = "OldBike_Cargo";
	};
	class Actions {};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Old_bike_dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\breakingpoint_vehicles\bp_old_bike\anims\MMT_Driver.rtm";
			speed = 1;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class OldBike_Driver: Crew
		{
			file = "\breakingpoint_vehicles\bp_old_bike\anims\MMT_Driver.rtm";
			interpolateTo[] = {"Old_bike_dead",1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
			speed = 1;
		};
		class OldBike_Cargo: Crew
		{
			file = "\breakingpoint_vehicles\bp_old_bike\anims\OldBike_Cargo.rtm";
			interpolateTo[] = {"Old_bike_dead",1};
			speed = 2;
		};
	};
};

class CfgWeapons
{
	class Default;
	class CarHorn;	
	class BikeHorn;	
	class Old_Bike_Bell: BikeHorn
	{
		scope = 2;
		displayName = "Bell";
		drySound[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\bicycle_ring_v1",db+25,1,200};
	};
};

class NoDust {};

class CfgVehicles
{
	class Bicycle;
	class Bicycle_F: Bicycle
	{
		class HitPoints{};	
	};
	class BP_Old_Bicycle: Bicycle_F
	{
		scope = 2;
		side = 3;
		weapons[] = {"Old_Bike_Bell"};
		turnCoef = 2;
		model = "\breakingpoint_vehicles\bp_old_bike\bp_old_bike.p3d";
		displayName = "Old Bicycle";
		Picture = "\breakingpoint_vehicles\bp_old_bike\Data\Picture_MMT_CA.paa";
		Icon = "\breakingpoint_vehicles\bp_old_bike\Data\Icon_MMT_CA.paa";
		mapSize = 3;
		memoryPointTrack1L = "";
		memoryPointTrack1R = "";
		memoryPointTrack2L = "";
		memoryPointTrack2R = "";
		memoryPointTrackFLL = "";
		memoryPointTrackBLL = "";
		memoryPointTrackFRL = "";
		memoryPointTrackBRL = "";
		threat[] = {0.0,0.0,0.0};
		driverAction = "OldBike_Driver";
		transportSoldier = 1;
		cargoAction[] = {"OldBike_Cargo"};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		memoryPointsGetInCargo[] = 
		{
			"pos cargo"
		}; 
		memoryPointsGetInCargoDir[] = 
		{
			"pos cargo dir"
		};
		damageResistance = 0.00913;
		ejectDeadDriver = "true";
		ejectDeadCargo = "true";
		secondaryExplosion = 0;
		leftDustEffect = "NoDust";
		rightDustEffect = "NoDust";
		maxSpeed = 60;
		extCameraPosition[] = {0,1.5,-4.5};
		acceleration = 25;
		brakeDistance = 15;
		terrainCoef = 5;
		driverLeftHandAnimName 	= "drivewheel";
		driverRightHandAnimName = "drivewheel";
		class Library
		{
			libTextDesc = "Old Bicycle";
		};
		#include "sounds.hpp"
		//#include "physx.hpp"
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\low1",0.56234133,1.0};
				limit = "0.2";
				expression = "(engineOn*(1-camPos))*thrust";
			};
			class AccelerationOut
			{
				sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\low1",0.56234133,1.0};
				limit = "0.2";
				expression = "(engineOn*camPos)*thrust";
			};
		};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		dammageHalf[]=
		{
		};
		dammageFull[]=
		{
		};
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		class DestructionEffects{};
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = 1;
				name = "karoserie";
				visual = "";
				passThrough = 1;
			};
			class HitFuel
			{
				armor = 0.3;
				material = 1;
				name = "palivo";
				passThrough = 0;
			};
			class HitFWheel
			{
				armor = 1;
				material = 1;
				name = "wheel_1_damper";
				visual = "wheel_1";
				passThrough = 0;
			};
			class HitBWheel
			{
				armor = 1;
				material = 1;
				name = "wheel_2_damper";
				visual = "wheel_2";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.4;
				material = 1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
		};
		class AnimationSources
		{
			class wheel_1_damper
			{
				source = "Hit";
				hitpoint = "HitFWheel";
				raw = 1;
			};
			class wheel_2_damper: wheel_1_damper
			{
				hitpoint = "HitBWheel";
			};
			class HitFWheel
			{
				source = "Hit";
				hitpoint = "HitFWheel";
				raw = 1;
			};
			class HitBWheel: HitFWheel
			{
				hitpoint = "HitBWheel";
			};
			class pedals: wheel_1_damper
			{
				hitpoint = "pedals";
			};
		};
		class Useractions
		{
			class BikePickup
			{
				displayNameDefault = "";
				displayName = "Pick Up";
				position = Driver;
				radius = 5;
				priority = 10;
				onlyforplayer = 1;
				condition = "(player distance this < 5) and (alive this)";
				statement = "[this] call BP_fnc_pickupBike;";
			};
		};
		class Reflectors 
		{
			class headlamp 
			{
				color[] = {0.8, 0.8, 1, 0.5};
				ambient[] = {0.7, 0.7, 0.9, 0.4};
				position = "lamp_source";
				direction = "lamp_direction";
				hitpoint = "lamp_light";
				selection = "lamp_light";
				size = 0.3;
				brightness = 0.5;
			};
			class rearlamp 
			{
				color[] = {1.0, 0.0, 0.0, 0.1};
				ambient[] = {0.8, 0.0, 0.0, 0.1};
				position = "lamp_sourcer";
				direction = "lamp_directionr";
				hitpoint = "lamp_lightr";
				selection = "lamp_lightr";
				size = 0.1;
				brightness = 0.1;
			};
		};
	};
};