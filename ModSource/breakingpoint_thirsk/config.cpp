﻿/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/
#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

class CfgPatches {
	class breakingpoint_thirsk {
		units[] = {"Thirsk","ThirskW","Land_trafficSign_40","Land_trafficSign_80","Land_trafficSing_militaryArea","Land_trafficSign_moose","Land_trafficSign_rocks","Land_trafficSign_turnL","Land_trafficSign_turnR","Land_trafficSign_reflectorStick","Land_miscSigns_minesStick",TH_SNOWING1,TH_SNOWING2,TH_SNOWING3,TH_SNOWING4,TH_SNOWING_b1,TH_SNOWING_b2,TH_SNOWING_b3,TH_SNOWING_b4,TH_FOG1,TH_FOG2,TH_FOG3,TH_FOG_b1,TH_FOG_b2,TH_FOG_b3,TH_SNOWSTORM1,TH_SNOWSTORM2};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CAData", "CABuildings", "CAMisc", "CABuildings2", "CARoads2"};
	};
};

class CfgSounds
{
	class snowstorm
	{
		name = "Snowstorm";
		sound[] = {"\RHNET\Thirsk5\sounds\snowstorm.ogg", db+0, 1.0};
		titles[] = {0, "snowstorm"};
	};

	class snowstorm_silent
	{
		name = "Snowstorm";
		sound[] = {"\RHNET\Thirsk5\sounds\snowstorm.ogg", db-20, 1.0};
		titles[] = {0, "snowstorm_silent"};
	};
};

class CfgVehicleClasses
{
	class THIRSK_Weather { displayName = "Thirsk Weather"; };
	class hum_mapObjectsClass { displayName = "Thirsk Island"; };
};

class CfgVehicles {
	class All {};
	class Logic : All {};
	class Static : All {};
	
	class Land_trafficSignsBase : Static {
		armor = 150; // cannot be destroyed by bullets
		animated = false; // not animated
		mapSize = 0.1;
		icon = "iconStaticObject";
		scope = 2; // 2 = public (can be seen from editor)
		           // 1 = private
		accuracy = 0.2; // accuracy -> recognize type
		placement = "vertical";

		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;

		destrType = "destructtree"; // will fall like a tree

		class DestructionEffects {
			class DestroyPhase1 {	// wtf is happening here
				simulation = "destroy";
				type = "DelayedDestruction";
				lifeTime = 2.5;
				position = "";
				intensity = 1;
				interval = 1;
			};
		};
	};
	
	class Land_trafficSign_40 : Land_trafficSignsBase { // uses defaults from class trafficsignbase
		model = "\RHNET\Thirsk6\hum_trafficSigns_40.p3d"; // model location
		vehicleClass = "hum_mapObjectsClass"; // belongs to addon..
		displayName = "Speedlimit Sign 40km/h"; // object name
	};

	class Land_trafficSign_80 : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_80.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Speedlimit Sign 80km/h";
	};

	class Land_trafficSign_militaryArea : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_militaryArea.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Military Area Sign";
	};

	class Land_trafficSign_moose : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_moose.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Moose Warning Sign";
	};

	class Land_trafficSign_rocks : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_rocks.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Falling Rocks Sign";
	};

	class Land_trafficSign_turnL : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_turnL.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "S-turn Left Sign";
	};

	class Land_trafficSign_turnR : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_turnR.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "S-turn Right Sign";
	};

	class Land_trafficSign_reflectorStick : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_reflectorStick.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Roadway Marker";

		armor = 5; // can be shot down
		destrType = "destructtree"; // will fall like a tree
		class DestructionEffects;
	};

	class Land_miscSigns_minesStick : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_miscSigns_minesStick.p3d";
		vehicleClass = "hum_mapObjectsClass";
		displayName = "Mines Sign on Stick";

		armor = 10; // can be shot down
		destrType = "destructtree"; // will fall like a tree
		class DestructionEffects;
	};

	class THIRSK_WeatherPreSet: Logic
	{
		scope = private;
		vehicleClass = "THIRSK_Weather";
	};

	class TH_SNOWING1 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Snowing Strenght 1";
		icon = "\RHNET\Thirsk5\icons\snowing2";
		class eventhandlers
		{
			init = "[_this select 0,2] exec ""\RHNET\Thirsk5\scripts\THIRSK_Snow.sqs""";
		};
	};
	class TH_SNOWING2 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Snowing Strenght 2";
		icon = "\RHNET\Thirsk5\icons\snowing2";
		class eventhandlers
		{
			init = "[_this select 0,4] exec ""\RHNET\Thirsk5\scripts\THIRSK_Snow.sqs""";
		};
	};
	class TH_SNOWING3 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Snowing Strenght 3";
		icon = "\RHNET\Thirsk5\icons\snowing2";
		class eventhandlers
		{
			init = "[_this select 0,6] exec ""\RHNET\Thirsk5\scripts\THIRSK_Snow.sqs""";
		};
	};

	class TH_SNOWING4 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Snowing Strenght 4";
		icon = "\RHNET\Thirsk5\icons\snowing2";
		class eventhandlers
		{
			init = "[_this select 0,8] exec ""\RHNET\Thirsk5\scripts\THIRSK_Snow.sqs""";
		};
	};
	class TH_FOG1 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Fog Strenght 1";
		icon = "\RHNET\Thirsk5\icons\fog";
		class eventhandlers
		{
			init = "[_this select 0,1] exec ""\RHNET\Thirsk5\scripts\THIRSK_Fog.sqs""";
		};
	};
	class TH_FOG2 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Fog Strenght 2";
		icon = "\RHNET\Thirsk5\icons\fog";
		class eventhandlers
		{
			init = "[_this select 0,3] exec ""\RHNET\Thirsk5\scripts\THIRSK_Fog.sqs""";
		};
	};	

	class TH_FOG3 : THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Fog Strenght 3";
		icon = "\RHNET\Thirsk5\icons\fog";
		class eventhandlers
		{
			init = "[_this select 0,5] exec ""\RHNET\Thirsk5\scripts\THIRSK_Fog.sqs""";
		};
	};
	class TH_SNOWSTORM1: THIRSK_WeatherPreSet
	{
		scope = public;
		displayName = "Snowstorm";
		icon = "\RHNET\Thirsk5\icons\snowstorm2";		
		class eventhandlers
		{
			init = "[_this select 0,9] exec ""\RHNET\Thirsk5\scripts\THIRSK_snowstormServer.sqs""";
		};
	};
	
	class ThingEffect;	// External class reference
	class ThingEffectLight;	// External class reference
	class ThingEffectFeather;	// External class reference
	
	class FXCrWindLeaf1 : ThingEffectLight {
		scope = protected;
		model = "\ca\plants2\clutter\cr_leaf.p3d";
		displayName = "Internal: FxCrWindLeaf1";
		airFriction2[] = {2, 2, 8};
		airFriction1[] = {1, 1, 4};
		airFriction0[] = {0.3, 0.3, 0.1};
		airRotation = 0.35;
		minHeight = 0.3;
		avgHeight = 5.5;
		maxHeight = 10.0;
	};
	
	class FXCrWindLeaf2 : FXCrWindLeaf1 {
		model = "\ca\plants2\clutter\cr_leaf2.p3d";
		displayName = "Internal: FxCrWindLeaf2";
	};
	
	class FXCrWindLeaf3 : FXCrWindLeaf1 {
		model = "\ca\plants2\clutter\cr_leaf3.p3d";
		displayName = "Internal: FxCrWindLeaf3";
	};
	
	class Building: Static {};
	class NonStrategic: Building {};
	class Fire: NonStrategic {};
};

class CfgWorlds {
	class DefaultWorld
	{
		class Grid;	// External class reference
		class DefaultClutter;	// External class reference
		class Weather
		{
			class Overcast;
			class RainConfig;
		};
		class WaterExPars;
	};	
	class CAWorld: DefaultWorld
	{
		class DayLightingBrightAlmost;
		class DayLightingRainy;
		class DefaultClutter;
		class Weather: Weather
		{
			class Lighting;
			class RainConfig: RainConfig
			{
			};
			class LightningsConfig;
			class RainbowConfig;
			class Overcast: Overcast
			{
				class Weather1;
				class Weather2;
				class Weather3;
				class Weather4;
				class Weather5;
				class Weather6;
				class Weather7;
			};
		};
		class Rain
		{
			texture="A3\data_f\rain_ca.paa";
			raindrop="\A3\data_f\raindrop.p3d";
			speed=1;
			levels[]={8,2};
		};
		class RainParticles
		{
			//minRainDensity=0.0099999998;
			effectRadius=28;
			//dropSpeed=55;
			rndSpeed=0.2;
			rndDir=0.08;
		};
	};
	class DefaultLighting;
	/*class Stratis: CAWorld
	{
		class Grid;
		class DefaultClutter;
	};*/	
	class Thirsk : CAWorld {
		dynLightMinBrightnessAmbientCoef = 0.5;
		dynLightMinBrightnessAbsolute = 0.05;	
		access = 3;
		worldId = 4;
		cutscenes[] = {};
		author = "Raunhofer.net (Ported By Breaking Point)";
		description = "Thirsk Summer";
		icon = "";
		worldName = "\RHNET\Thirsk2\Thirsk.wrp";
		pictureMap = "\RHNET\Thirsk\data\ThirskSummer.jpg";			
		plateFormat = "ML$ - #####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		longitude = 26;	// positive is east
		latitude = -68;	// positive is south
		loadingTexts[]=
		{
			"Thirsk Summer was originally created by Raunhofer and then ported to Arma 3 by Breaking Point.",
		};
		
		class ReplaceObjects {};


		class Grid : Grid {
			offsetX = 0;
			offsetY = 0;
			
			class Zoom1 {
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = 100;
			};
			
			class Zoom2 {
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = 1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = 10000;
			};
		};
		startTime = 08:00;
		startDate = 10/4/2035;
		startWeather = 0.01;
		startFog = 0.01;
		forecastWeather = 0.05;
		forecastFog = 0.0;
		centerPosition[] = {1380, 2030, 300};
		seagullPos[] = {2626, 150, 1865};
		ilsPosition[] = {1106, 3236};
		ilsDirection[] = {-0.9205, 0.080, 0.3907};
		ilsTaxiIn[] = {1453, 3050, 1124, 3190, 1116, 3207, 1134, 3219, 1151, 3216};
		ilsTaxiOff[] = {1643, 3008, 1667, 2979, 1637, 2972, 1585, 2993};
		drawTaxiway = 1;
		
		class SecondaryAirports {
	        class Thirsk_Abafield {
				ilsPosition[] = {596, 565};
				ilsDirection[] = {-1.0000, 0.080, 0.0000};
				ilsTaxiIn[] = {681.975, 525.337, 638.61, 526.458, 616.927, 538.982, 612.254, 556.926, 630.199, 564.029};
				ilsTaxiOff[] = {1046.05, 565.157, 1071.41, 557.501, 1068.54, 534.054, 1033.61, 529.27, 822.112, 529.27};
				drawTaxiway = 1;
			};
		};
		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};
		
		class Sea
		{
			seaTexture="a3\data_f\seatexture_co.paa";
			seaMaterial="#waterriver";
			shoreMaterial="#shore";
			shoreFoamMaterial="#shorefoam";
			shoreWetMaterial="#shorewet";
			WaterMapScale=20;
			WaterGrid=50;
			MaxTide=0;
			MaxWave=0.25;
			SeaWaveXScale="2.0/50";
			SeaWaveZScale="1.0/50";
			SeaWaveHScale=1;
			SeaWaveXDuration=5000;
			SeaWaveZDuration=10000;
		};
		class Underwater
		{
			noWaterFog=-0.001;
			fullWaterFog=0.001;
			deepWaterFog=60;
			waterFogDistanceNear=-10;
			waterFogDistance=90;
			waterColor[]={0,0.039999999,0.029999999};
			deepWaterColor[]={0,0.001,0.0089999996};
			surfaceColor[]={0,0.039999999,0.029999999};
			deepSurfaceColor[]={0,0.001,0.0089999996};
		};
		class SeaWaterShaderPars
		{
			refractionMoveCoef=0.029999999;
			minWaterOpacity=0;
			waterOpacityDistCoef=0.40000001;
			underwaterOpacity=0.5;
			waterOpacityFadeStart=60;
			waterOpacityFadeLength=120;
		};
		class WaterExPars: WaterExPars
		{
			fogDensity=0.25;
			fogColor[]=
			{
				"0.197*0.25",
				"0.25*0.25",
				"0.08*0.25"
			};
			fogColorExtinctionSpeed[]={0.30000001,0.30000001,0.051100001};
			ligtExtinctionSpeed[]=
			{
				"0.02+0.3",
				"0.02+0.3",
				"0.02+0.0511"
			};
			diffuseLigtExtinctionSpeed[]=
			{
				"0.82+0.3",
				"0.52+0.3",
				"1.32+0.0511"
			};
			fogGradientCoefs[]={0.34999999,1,1.7};
			fogColorLightInfluence[]={0.80000001,0.2,1};
			shadowIntensity=0;
			ssReflectionStrength=0.85000002;
			ssReflectionMaxJitter=1;
			ssReflectionRippleInfluence=0.2;
			ssReflectionEdgeFadingCoef=10;
			ssReflectionDistFadingCoef=4;
			refractionMinCoef=0.029999999;
			refractionMaxCoef=0.14;
			refractionMaxDist=5.0999999;
			specularMaxIntensity=75;
			specularPowerOvercast0=300;
			specularPowerOvercast1=3;
			specularNormalModifyCoef=0.001;
			foamAroundObjectsIntensity=0.2;
			foamAroundObjectsFadeCoef=8;
			foamColorCoef=2;
			foamDeformationCoef=0.02;
			foamTextureCoef=0.2;
			foamTimeMoveSpeed=0.2;
			foamTimeMoveAmount=0.1;
			shoreDarkeningMaxCoef=0.55000001;
			shoreDarkeningOffset=0.02;
			shoreDarkeningGradient=0.2;
			shoreWaveTimeScale=0.80000001;
			shoreWaveShifDerivativeOffset=-0.80000001;
			shoreFoamIntensity=0.5;
			shoreMaxWaveHeight=0.046;
			shoreWetLayerReflectionIntensity=0.55000001;
		};
		startFogBase=250;
		forecastFogBase=250;
		startFogDecay=0.018;
		forecastFogDecay=0.018;
		fogBeta0Min=0;
		fogBeta0Max=0.0049999999;		
		class HDRNewPars
		{
			minAperture=9.9999997e-006;
			maxAperture=256;
			apertureRatioMax=4;
			apertureRatioMin=10;
			bloomImageScale=1;
			bloomScale=0.15000001;
			bloomExponent=1.3;
			bloomLuminanceOffset=0.75;
			bloomLuminanceScale=0.75;
			bloomLuminanceExponent=0.75;
			tonemapMethod=1;
			tonemapShoulderStrength=0.22;
			tonemapLinearStrength=0.12;
			tonemapLinearAngle=0.1;
			tonemapToeStrength=0.2;
			tonemapToeNumerator=0.022;
			tonemapToeDenominator=0.2;
			tonemapLinearWhite=11.2;
			tonemapExposureBias=1;
			tonemapLinearWhiteReinhard=2.5;
			eyeAdaptFactorLight=3.3;
			eyeAdaptFactorDark=0.25;
			nvgApertureMin=10;
			nvgApertureStandard=12.5;
			nvgApertureMax=16.5;
			nvgStandardAvgLum=10;
			nvgLightGain=320;
			nvgTransition=1;
			nvgTransitionCoefOn=40;
			nvgTransitionCoefOff=0.0099999998;
			nightShiftMinAperture=0;
			nightShiftMaxAperture=0.0020000001;
			nightShiftMaxEffect=0.60000002;
			nightShiftLuminanceScale=600;
		};
		skyColorInfluencesFogColor=0;
		class Lighting: DefaultLighting
		{
			groundReflection[]={0.059999999,0.059999999,0.029999999};
			moonObjectColorFull[]={360,340,300,100};
			moonHaloObjectColorFull[]={15,17,25,50};
			moonsetObjectColor[]={275,250,225,1};
			moonsetHaloObjectColor[]={10,10,10,0.25};
			class ThunderBoltLight
			{
				diffuse[]={2120,3170,9550};
				ambient[]={0.001,0.001,0.001};
				intensity=120000;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=0;
					quadratic=1;
				};
			};
			starEmissivity=50;
		};
		class DayLightingBrightAlmost: DayLightingBrightAlmost
		{
			deepNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			fullNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunMoon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlySun[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunrise[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlyMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			midMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			morning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			noon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
		};
		class DayLightingRainy: DayLightingRainy
		{
			deepNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			fullNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunMoon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlySun[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlyMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			morning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			lateMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			noon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
		};
		class Weather: Weather
		{
			class LightingNew
			{
				class Lighting0
				{
					height=0;
					overcast=0.25;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.14,0.22},
						3.5
					};
					diffuseCloud[]={{0.1,0.1,0.2},2.8};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						4
					};
					ambientCloud[]={{0.51999998,0.67000002,1},3.5};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.3
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},3};
					groundReflection[]={0.57200003,0.67000002,0.89999998};
					groundReflectionCloud[]={0.57200003,0.67000002,0.89999998};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]=
					{
						{0.090000004,0.13699999,0.22},
						0.002
					};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.17,0.32,0.8},
						14
					};
					swBrightness=3;
				};
				class Lighting1
				{
					height=0;
					overcast=0.25;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.090000004,0.090000004,0.1},
						2.6
					};
					diffuseCloud[]={{0.090000004,0.090000004,0.2},2.3};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						5.4
					};
					ambientCloud[]={{0.51999998,0.67000002,1},5.2};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						5.4
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},5.2};
					groundReflection[]={{0.57200003,0.67000002,0.89999998},1};
					groundReflectionCloud[]={{0.57200003,0.67000002,0.89999998},0.05};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.15000001,0.30000001},
						4
					};
					skyAroundSun[]=
					{
						{0.40000001,0.30000001,0.30000001},
						9
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						3
					};
					apertureMin=6;
					apertureStandard=7;
					apertureMax=8;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.9,1,1},
						14
					};
					swBrightness=3;
				};
				class Lighting2
				{
					height=0;
					overcast=0.25;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.80000001,0.40000001,0.18000001},
						5
					};
					diffuseCloud[]=
					{
						{1,0.34999999,0.34},
						3
					};
					ambient[]=
					{
						{0.69999999,0.5,0.5},
						7.75
					};
					ambientCloud[]=
					{
						{0.60000002,0.5,0.5},
						5
					};
					ambientMid[]=
					{
						{0.55000001,0.60000002,0.80000001},
						6.5
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.60000002,0.80000001},
						5.5
					};
					groundReflection[]=
					{
						{0.55000001,0.60000002,0.80000001},
						6.5
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.60000002,0.89999998},
						3.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.2,0.40000001},
						6
					};
					skyAroundSun[]=
					{
						{0.25,0.1,0.029999999},
						11
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						5.5
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.5,0.5};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.69999999,0.69999999,0.69999999},
						9
					};
					swBrightness=2;
				};
				class Lighting3
				{
					height=0;
					overcast=0.25;
					sunAngle=4;
					sunOrMoon=0.9;
					diffuse[]=
					{
						{0.89999998,0.40000001,0.16},
						8
					};
					diffuseCloud[]=
					{
						{0.80000001,0.40000001,0.16},
						9
					};
					ambient[]=
					{
						{0.5,0.38999999,0.34999999},
						9
					};
					ambientCloud[]=
					{
						{0.5,0.38999999,0.34999999},
						9
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.44999999},
						8.1000004
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.44999999},
						7.6999998
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.44999999},
						7.0999999
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.5,0.5},
						6.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.25,0.40000001},
						10.5
					};
					skyAroundSun[]=
					{
						{0.30000001,0.2,0.1},
						12
					};
					fogColor[]=
					{
						{0.15000001,0.13500001,0.13},
						7
					};
					apertureMin=9;
					apertureStandard=13;
					apertureMax=30;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.12,0.050000001,0.050000001};
					mie[]={0.003,0.0020000001,0.003};
					cloudsColor[]=
					{
						{0.2,0.2,0.2},
						11
					};
					swBrightness=1;
				};
				class Lighting4
				{
					height=0;
					overcast=0.25;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.5,0.25999999},
						10.25
					};
					diffuseCloud[]=
					{
						{1,0.44999999,0.25999999},
						10.25
					};
					ambient[]=
					{
						{0.55000001,0.40000001,0.34999999},
						9.8000002
					};
					ambientCloud[]=
					{
						{0.60000002,0.40000001,0.40000001},
						9.8000002
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.44999999},
						8.3000002
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.5},
						8
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.44999999},
						7.75
					};
					groundReflectionCloud[]=
					{
						{0.60000002,0.64999998,0.76800001},
						7
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.69999999},
						10.5
					};
					skyAroundSun[]=
					{
						{0.15000001,0.2,0.2},
						12
					};
					fogColor[]=
					{
						{0.125,0.13,0.14},
						8.1999998
					};
					apertureMin=10;
					apertureStandard=15;
					apertureMax=40;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.059999999,0.1,0.090000004};
					mie[]={0.0020000001,0.0020000001,0.0020000001};
					cloudsColor[]=
					{
						{0.2,0.2,0.15000001},
						12
					};
					swBrightness=1;
				};
				class Lighting5
				{
					height=0;
					overcast=0.25;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.63,0.40000001},
						12
					};
					diffuseCloud[]=
					{
						{1,0.63,0.40000001},
						11.5
					};
					ambient[]=
					{
						{0.60000002,0.60000002,0.60000002},
						10.75
					};
					ambientCloud[]=
					{
						{0.56999999,0.60000002,0.69999999},
						10.75
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.50999999},
						9.1999998
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.5,0.50999999},
						9
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.50999999},
						9
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.61199999,0.69999999},
						8.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.33000001,0.80000001},
						10.75
					};
					skyAroundSun[]=
					{
						{0.1,0.30000001,0.60000002},
						12
					};
					fogColor[]=
					{
						{0.11,0.125,0.14},
						9.75
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.1,0.13,0.2};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.5,0.5,0.30000001},
						12
					};
					swBrightness=1;
				};
				class Lighting6
				{
					height=0;
					overcast=0.25;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.75,0.55000001},
						12.4
					};
					diffuseCloud[]=
					{
						{1,0.75,0.55000001},
						12.1
					};
					ambient[]=
					{
						{0.57999998,0.58999997,0.63},
						11
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.63},
						11
					};
					ambientMid[]=
					{
						{0.57999998,0.50999999,0.47999999},
						10.2
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10
					};
					groundReflection[]=
					{
						{0.57999998,0.50999999,0.47999999},
						10
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						9.8999996
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.28,0.94999999},
						11
					};
					skyAroundSun[]=
					{
						{0.1,0.28,0.80000001},
						12
					};
					fogColor[]=
					{
						{0.105,0.13,0.17},
						10
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						12
					};
					swBrightness=1;
				};
				class Lighting7
				{
					height=0;
					overcast=0.25;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.64999998},
						13.75
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.64999998},
						13.5
					};
					ambient[]=
					{
						{0.57999998,0.58999997,0.68000001},
						11.75
					};
					ambientCloud[]=
					{
						{0.56999999,0.58999997,0.68000001},
						11.7
					};
					ambientMid[]=
					{
						{0.57999998,0.53100002,0.47600001},
						11
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11
					};
					groundReflection[]=
					{
						{0.57999998,0.53100002,0.47600001},
						10.5
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.075000003,0.2,1},
						12
					};
					skyAroundSun[]=
					{
						{0.075000003,0.23,1},
						12.5
					};
					fogColor[]=
					{
						{0.105,0.14,0.2},
						11.7
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						13
					};
					swBrightness=1;
				};
				class Lighting8
				{
					height=0;
					overcast=0.25;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.66000003},
						14
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.66000003},
						13.7
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.49000001},
						12.1
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						12
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.49000001},
						11.2
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.075000003,0.22,1},
						13
					};
					skyAroundSun[]=
					{
						{0.075000003,0.22,1},
						13
					};
					fogColor[]=
					{
						{0.105,0.145,0.2},
						12
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						13
					};
					swBrightness=1;
				};
				class Lighting9
				{
					height=0;
					overcast=0.60000002;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.13,0.2},
						3.5
					};
					diffuseCloud[]=
					{
						{0.1,0.13,0.2},
						3
					};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						3.8
					};
					ambientCloud[]=
					{
						{1,1,1},
						3.4
					};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.2
					};
					ambientMidCloud[]=
					{
						{0.57200003,0.67000002,0.89999998},
						2.9
					};
					groundReflection[]=
					{
						{0.57200003,0.67000002,0.89999998},
						0.1
					};
					groundReflectionCloud[]=
					{
						{0.57200003,0.67000002,0.89999998},
						0.1
					};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]=
					{
						{0.090000004,0.13699999,0.22},
						0.002
					};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.17,0.32,0.8},
						14
					};
					swBrightness=3;
				};
				class Lighting10
				{
					height=0;
					overcast=0.60000002;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.090000004,0.090000004,0.2},
						2.5
					};
					diffuseCloud[]={{0,0,0},2.25};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						5.4
					};
					ambientCloud[]={{1,1,1},5};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						5.2
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},5};
					groundReflection[]={{0.57200003,0.67000002,0.89999998},1};
					groundReflectionCloud[]={{0.57200003,0.67000002,0.89999998},0.05};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.15000001,0.30000001},
						4
					};
					skyAroundSun[]=
					{
						{0.5,0.30000001,0.2},
						8
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						2
					};
					apertureMin=6;
					apertureStandard=7;
					apertureMax=8;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{1,1,1},
						16
					};
					swBrightness=3;
				};
				class Lighting11
				{
					height=0;
					overcast=0.60000002;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.89999998,0.34999999,0.075000003},
						4
					};
					diffuseCloud[]={{0.89999998,0.34999999,0.075000003},1};
					ambient[]=
					{
						{0.69999999,0.60000002,0.60000002},
						7
					};
					ambientCloud[]=
					{
						{1,1,1},
						6
					};
					ambientMid[]=
					{
						{0.55000001,0.60000002,0.89999998},
						6.5
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.60000002,0.89999998},
						6.1
					};
					groundReflection[]=
					{
						{0.55000001,0.60000002,0.80000001},
						3
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.60000002,0.80000001},
						2.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.2,0.5},
						6
					};
					skyAroundSun[]=
					{
						{0.5,0.15000001,0},
						10
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						5
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.050000001,0.12,0.17};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.69999999,0.69999999,0.69999999},
						4
					};
					swBrightness=2;
				};
				class Lighting12
				{
					height=0;
					overcast=0.60000002;
					sunAngle=4;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.89999998,0.34999999,0.1},
						8
					};
					diffuseCloud[]=
					{
						{0.89999998,0.30000001,0.050000001},
						4
					};
					ambient[]=
					{
						{0.30000001,0.23,0.2},
						8.6999998
					};
					ambientCloud[]=
					{
						{0.30000001,0.23,0.2},
						8.6999998
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.5},
						8
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.5},
						7.5
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.5},
						7
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.5,0.5},
						6.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.2,0.30000001,0.40000001},
						9.5
					};
					skyAroundSun[]=
					{
						{0.5,0.2,0.050000001},
						11.5
					};
					fogColor[]=
					{
						{0.15000001,0.13,0.12},
						6.5
					};
					apertureMin=9;
					apertureStandard=13;
					apertureMax=30;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.050000001,0.059999999,0.17};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						8
					};
					swBrightness=1;
				};
				class Lighting13
				{
					height=0;
					overcast=0.60000002;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.44999999,0.16},
						10.25
					};
					diffuseCloud[]=
					{
						{1,0.44999999,0.16},
						6
					};
					ambient[]=
					{
						{0.69999999,0.67000002,0.68000001},
						10
					};
					ambientCloud[]=
					{
						{0.69999999,0.67000002,0.68000001},
						9.6000004
					};
					ambientMid[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9.1999998
					};
					ambientMidCloud[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9
					};
					groundReflection[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9
					};
					groundReflectionCloud[]=
					{
						{0.64999998,0.60000002,0.60000002},
						8.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.13,0.30000001,0.5},
						11
					};
					skyAroundSun[]=
					{
						{0.5,0.23,0.1},
						12.5
					};
					fogColor[]=
					{
						{0.13,0.125,0.11},
						7.5
					};
					apertureMin=10;
					apertureStandard=15;
					apertureMax=40;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.059999999,0.090000004,0.090000004};
					mie[]={0.0020000001,0.0020000001,0.0020000001};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						8.5
					};
					swBrightness=1;
				};
				class Lighting14
				{
					height=0;
					overcast=0.60000002;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.67500001,0.44999999},
						12
					};
					diffuseCloud[]=
					{
						{1,0.69999999,0.44999999},
						8
					};
					ambient[]=
					{
						{0.64999998,0.61199999,0.69999999},
						10.8
					};
					ambientCloud[]=
					{
						{0.64999998,0.61199999,0.72000003},
						10.9
					};
					ambientMid[]=
					{
						{0.56999999,0.55000001,0.60000002},
						9.5
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.55000001,0.62},
						9.5
					};
					groundReflection[]=
					{
						{0.56999999,0.55000001,0.60000002},
						9.3000002
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.61199999,0.69999999},
						8.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.55000001},
						11.5
					};
					skyAroundSun[]=
					{
						{0.2,0.30000001,0.34999999},
						12
					};
					fogColor[]=
					{
						{0.125,0.13,0.13500001},
						9.75
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.090000004,0.1,0.1};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						9
					};
					swBrightness=1;
				};
				class Lighting15
				{
					height=0;
					overcast=0.60000002;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.75,0.60000002},
						12.4
					};
					diffuseCloud[]=
					{
						{1,0.75,0.68000001},
						11
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.63},
						11.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.64999998},
						11
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.56},
						10.4
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10.3
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.56},
						10
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						9.1999998
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]={0.11,0.30000001,0.64999998};
					skyAroundSun[]=
					{
						{0.11,0.30000001,0.64999998},
						11.7
					};
					fogColor[]=
					{
						{0.105,0.13,0.18000001},
						9
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						11.5
					};
					swBrightness=1;
				};
				class Lighting16
				{
					height=0;
					overcast=0.60000002;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.64999998},
						13.75
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.64999998},
						11.8
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.68000001},
						11.8
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.68000001},
						11.9
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.5},
						11.3
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.5},
						11.1
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.5},
						10.5
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						9.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.80000001},
						12
					};
					skyAroundSun[]=
					{
						{0.11,0.30000001,0.80000001},
						12.2
					};
					fogColor[]=
					{
						{0.105,0.13,0.17},
						10.25
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						12
					};
					swBrightness=1;
				};
				class Lighting17
				{
					height=0;
					overcast=0.60000002;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.66000003},
						14.1
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.66000003},
						12.2
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.56},
						11.8
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11.6
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.56},
						11.2
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						11
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,1},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.30000001,1},
						13
					};
					fogColor[]=
					{
						{0.105,0.145,0.2},
						10.1
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						14
					};
					swBrightness=1;
				};
				class Lighting18
				{
					height=0;
					overcast=0.90;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.13,0.2},
						3.2
					};
					diffuseCloud[]={{0.1,0.13,0.2},1};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						3.6
					};
					ambientCloud[]={{1,1,1},3.2};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.5
					};
					ambientMidCloud[]={{1,1,1},3};
					groundReflection[]={0.57200003,0.67000002,0.89999998};
					groundReflectionCloud[]={1,1,1};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]={0.090000004,0.13699999,0.22};
					apertureMin=4.5;
					apertureStandard=6;
					apertureMax=7.5;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{1,1,1},
						14,75
					};
					swBrightness=3;
				};
				class Lighting19
				{
					height=0;
					overcast=0.90;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.2,0.2,0.2},
						0.21
					};
					diffuseCloud[]={{0,0,0},0.21};
					ambient[]=
					{
						{0.5,0.55000001,1},
						4
					};
					ambientCloud[]={{1,1,1},4};
					ambientMid[]=
					{
						{0.55000001,0.55000001,0.85000002},
						4
					};
					ambientMidCloud[]={{1,1,1},4};
					groundReflection[]={{0.55000001,0.55000001,0.85000002},0.025};
					groundReflectionCloud[]={{1,1,1},0.025};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.30000001,0.69999999},
						3
					};
					skyAroundSun[]=
					{
						{0.2,0.30000001,0.60000002},
						7
					};
					fogColor[]={0.079999998,0.079999998,0.094999999};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.5};
					mie[]={0.050000001,0.050000001,0.050000001};
					cloudsColor[]=
					{
						{0.1,0.1,0.1},
						17
					};
					swBrightness=3;
				};
				class Lighting20
				{
					height=0;
					overcast=0.90;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.375,0.22499999,0.039999999},
						0.050000001
					};
					diffuseCloud[]=
					{
						{1,1,1},
						0.050000001
					};
					ambient[]=
					{
						{0.5,0.5,0.60000002},
						5.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						5.2
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.80000001},
						5.4
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						5
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.80000001},
						0.25
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						0.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						1
					};
					skyAroundSun[]=
					{
						{0.2,0.25,0.30000001},
						1
					};
					fogColor[]=
					{
						{0.079999998,0.079999998,0.094999999},
						0.25
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.5};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.44999999,0.22,0.15000001},
						3
					};
					swBrightness=2;
				};
				class Lighting21
				{
					height=0;
					overcast=0.90;
					sunAngle=4;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.1,0.1,0.1},
						0.1
					};
					diffuseCloud[]=
					{
						{1,1,1},
						0.0049999999
					};
					ambient[]=
					{
						{0.60000002,0.60000002,0.75},
						8.1999998
					};
					ambientCloud[]=
					{
						{1,1,1},
						8
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.62},
						7.1999998
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						7
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.62},
						6.5
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						6
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						9
					};
					skyAroundSun[]=
					{
						{0.2,0.2,0.30000001},
						10
					};
					fogColor[]=
					{
						{0.125,0.125,0.14},
						7.5
					};
					apertureMin=13;
					apertureStandard=17;
					apertureMax=40;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.30000001};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.44999999,0.30000001,0.15000001},
						3
					};
					swBrightness=1;
				};
				class Lighting22
				{
					height=0;
					overcast=0.90;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.30000001,0.30000001,0.34999999},
						0.75
					};
					diffuseCloud[]=
					{
						{1,1,1},
						1
					};
					ambient[]=
					{
						{0.64999998,0.64999998,0.80000001},
						9
					};
					ambientCloud[]=
					{
						{1,1,1},
						9
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.62},
						8
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						7.8000002
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.62},
						7.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						7.5999999
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						10
					};
					skyAroundSun[]=
					{
						{0.16,0.18000001,0.2},
						10
					};
					fogColor[]=
					{
						{0.125,0.125,0.15000001},
						8
					};
					apertureMin=14;
					apertureStandard=21;
					apertureMax=55;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.30000001};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.60000002,0.30000001,0.15000001},
						5
					};
					swBrightness=1;
				};
				class Lighting23
				{
					height=0;
					overcast=0.90;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.31999999,0.30000001,0.34999999},
						1
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						2
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						10
					};
					ambientCloud[]=
					{
						{1,1,1},
						10
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.60000002},
						9.3000002
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						9
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.60000002},
						8.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						8.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						10.8
					};
					skyAroundSun[]=
					{
						{0.16,0.18000001,0.2},
						11.4
					};
					fogColor[]=
					{
						{0.30000001,0.34,0.44},
						9
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.75,0.60000002,0.40000001},
						5
					};
					swBrightness=1;
				};
				class Lighting24
				{
					height=0;
					overcast=0.90;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						3.5
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						2.5
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						11
					};
					ambientCloud[]=
					{
						{1,1,1},
						10.8
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.56999999},
						10
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						9.8000002
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						9.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						9.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						12.6
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.19},
						12.6
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						8.2
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						7.5
					};
					swBrightness=1;
				};
				class Lighting25
				{
					height=0;
					overcast=0.90;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						9.8000002
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						6
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						11.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						11.2
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.56999999},
						11
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						10.5
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						10
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						9.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.18799999},
						13
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						9.15
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						7.5
					};
					swBrightness=1;
				};
				class Lighting26
				{
					height=0;
					overcast=0.90;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						10
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						6
					};
					ambient[]=
					{
						{0.69999999,0.64999998,0.80000001},
						12.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.55000001,0.56999999},
						11.5
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						11
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						11
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						10
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.18799999},
						13
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						9.5
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						8.7
					};
					swBrightness=1;
				};
			};
			class Lighting: Lighting
			{
				class BrightAlmost: DayLightingBrightAlmost
				{
					overcast=0;
				};
				class Rainy: DayLightingRainy
				{
					overcast=1;
				};
			};
			class LightningsConfig: LightningsConfig
			{
				minCloudiness=0.70;
				minProbability=0;
				maxProbability=1;
				minCount=0;
				maxCount=6;
				scatter=20;
			};
			class Overcast: Overcast
			{
				class Weather1: Weather1
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_clear_horizont_sky.paa";
					overcast=0;
					alpha=0.5;
					size=0.1;
					height=1;
					bright=0.69999999;
					speed=0;
					through=0.45;
					diffuse=1;
					cloudDiffuse=0.94999999;
					waves=0.2;
					lightingOvercast=0;
				};
				class Weather2: Weather2
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_clear_horizont_sky.paa";
					overcast=0.22000001;
					alpha=0.6;
					size=0.25;
					height=0.92;
					bright=0.47;
					speed=0.22;
					through=0.4;
					diffuse=1;
					cloudDiffuse=0.94999999;
					waves=0.2;
					lightingOvercast=0.1;
				};
				class Weather3: Weather3
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_almostclear_horizont_sky.paa";
					overcast=0.40;
					alpha=0.80000002;
					size=0.45000001;
					height=0.89999998;
					bright=0.39;
					speed=0.29;
					through=0.36;
					lightingOvercast=0.35;
					diffuse=1;
					waves=0.22;
				};
				class Weather4: Weather4
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_semicloudy_horizont_sky.paa";
					overcast=0.58000001;
					alpha=0.94000001;
					size=0.55;
					height=0.80000001;
					bright=0.25000001;
					speed=0.47;
					through=0.35;
					lightingOvercast=0.54;
					diffuse=1;
					waves=0.32;
				};
				class Weather5: Weather5
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_cloudy_horizont_sky.paa";
					overcast=0.67000002;
					alpha=0.99000001;
					size=0.64999998;
					height=0.75;
					bright=0.1;
					speed=0.60000001;
					through=0.31;
					lightingOvercast=0.72;
					diffuse=0;
					waves=0.40000001;
				};
				class Weather6: Weather6
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_mostlycloudy_horizont_sky.paa";
					overcast=0.84;
					alpha=1;
					size=0.80000001;
					height=0.69999999;
					bright=0.1;
					speed=0.75;
					through=0.2;
					lightingovercast=0.92; //Earlier and smoother transition to dark overcast&fog
					diffuse=0;
					waves=0.90000002;
				};
				class Weather7: Weather6
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_overcast_horizont_sky.paa";
					overcast=0.95;
					alpha=1;
					bright=0.1;
					size=1;
					height=0.60000002;
					speed=0.94999999;
					through=0.3;
					lightingOvercast=0.84;
					diffuse=1;
					waves=0.60000001;
				};
			};
		};
		humidityUpCoef=0.1;
		humidityDownCoef=0.050000001;
		class SimulWeather
		{
			noiseTexture="a3\data_f\noise_raw.paa";
			numKeyframesPerDay=48;
			windSpeedCoef="10.0f";
			moonIrradianceCoef="7.0f";
			fadeMaxDistanceKm=1000;
			fadeMaxAltitudeKm=15;
			fadeNumAltitudes=8;
			fadeNumElevations=8;
			fadeNumDistances=8;
			fadeEarthTest=1;
			autoBrightness=1;
			autoBrightnessStrength=0.1;
			cloudGridWidth=64;
			cloudGridLength=64;
			cloudGridHeight=16;
			helperGridElevationSteps=24;
			helperGridAzimuthSteps=15;
			helperEffectiveEarthRadius=1000000;
			helperCurvedEarth=1;
			helperAdjustCurvature=0;
			helperNumLayers=120;
			helperMaxDistance=160000;
			helperNearCloudFade=0.1;
			helperChurn=10;
			cloudWidth=40000;
			cloudLength=40000;
			wrapClouds=1;
			noiseResolution=8;
			noisePeriod=4;
			opticalDensity=1.5;
			alphaSharpness=0.85000002;
			selfShadowScale=0.90499997;
			mieAsymmetry=0.50870001;
			minimumLightElevationDegrees=6;
			directLightCoef=1;
			indirectLightCoef=0.04;
			fogStart=0;
			fogEnd=50000;
			fogHeight=2000;
			maxPrecipitationParticles = 1000000;
			class DefaultKeyframe
			{
				rayleigh[]={0.0074900002,0.01388,0.02878};
				mie[]={0.0046000001,0.0046000001,0.0046000001};
				haze=30;
				hazeBaseKm=5;
				hazeScaleKm=1;
				hazeEccentricity=1;
				brightnessAdjustment=1;
				cloudiness=0.60000002;
				cloudBaseKm=2.8499999;
				cloudHeightKm=6;
				directLight=1;
				indirectLight=1;
				ambientLight=0.2;
				noiseOctaves=4.3000002;
				noisePersistence=0.53500003;
				fractalAmplitude=2.3;
				fractalWavelength=240;
				extinction=4.7;
				diffusivity=0.001;
			};
			class Overcast
			{
				class Weather1: DefaultKeyframe
				{
					overcast=0;
					cloudiness=0.02;
					cloudBaseKm=1.6;
					diffusivity=0.001;
					seqFileKeyframe=0;
				};
				class Weather2: DefaultKeyframe
				{
					overcast=0.2;
					cloudiness=0.18;
					extinction=5.2;
					cloudBaseKm=1.5;
					cloudHeightKm=7.4;
					diffusivity=0.001;
					indirectLight=0.85;
					seqFileKeyframe=0;
				};
				class Weather3: DefaultKeyframe
				{
					overcast=0.40000001;
					cloudiness=0.36;
					extinction=9.8;
					cloudBaseKm=1.7;
					cloudHeightKm=10.5;
					diffusivity=0.001;
					indirectLight=0.5;
					seqFileKeyframe=3;
				};
				class Weather4: DefaultKeyframe
				{
					overcast=0.52;
					cloudiness=0.45;
					extinction=8.7;
					diffusivity=0.001;
					cloudBaseKm=1.4;
					cloudHeightKm=13.5;
					indirectLight=0.22;
					seqFileKeyframe=4;
				};
				class Weather5: DefaultKeyframe
				{
					overcast=0.72;
					cloudiness=0.66;
					diffusivity=0.001;
					extinction=10;
					cloudBaseKm=2.2;
					cloudHeightKm=18;
					indirectLight=0.12;
					seqFileKeyframe=4;
				};
				class Weather6: DefaultKeyframe
				{
					overcast=0.85;
					cloudiness=0.8;
					diffusivity=0.001;
					extinction=9;
					cloudBaseKm=1.6;
					cloudHeightKm=10;
					indirectLight=0.16;
					directLight=0.8;
					seqFileKeyframe=4;
				};
				class Weather7: DefaultKeyframe
				{
					overcast=0.95;
					cloudiness=1;
					diffusivity=0.001;
					extinction=3.5;
					cloudBaseKm=1.4;
					cloudHeightKm=12;
					indirectLight=1;
					directLight=1;
					seqFileKeyframe=4;
				};
			};
		};
		hazeDistCoef=0.1;
		hazeFogCoef=0.98000002;
		fogHeight=2000;
		hazeBaseHeight=0;
		hazeBaseBeta0=0.00004;
		hazeDensityDecay=0.00025000003;
		aroundSunCoefMultiplier=1.38;
		aroundSunCoefExponent=8;
		soundMapSizeCoef=4;
		satelliteNormalBlendStart=10;
		satelliteNormalBlendEnd=100;
		skyObject="A3\Map_Enoch\Data\skydome.p3d";
		horizontObject="A3\Map_Enoch\Data\horizon.p3d";
		skyTexture="A3\Map_Enoch\Data\sky_semicloudy_sky.paa";
		skyTextureR="A3\Map_Enoch\Data\sky_semicloudy_lco.paa";
		terrainBlendMaxDarkenCoef=1;
		terrainBlendMaxBrightenCoef=0;
		lightningsForced=1;
		class EnvMaps
		{
			class EnvMap1
			{
				texture="A3\Map_Enoch\Data\env_land_ClearSky_ca.paa";
				overcast=0;
			};
			class EnvMap2
			{
				texture="A3\Map_Enoch\Data\env_land_SemiCloudySky_ca.paa";
				overcast=0.40000001;
			};
			class EnvMap3
			{
				texture="A3\Map_Enoch\Data\env_land_OvercastSky_ca.paa";
				overcast=0.90;
			};
		};
		/*class OutsideTerrain
		{
			satellite="A3\Map_Enoch\Data\s_satout_co.paa";
			enableTerrainSynth=1;
			class Layers
			{
				class Layer0
				{
					nopx="A3\Map_Enoch\data\gdt_engrass1_nopx.paa";
					texture="A3\Map_Enoch\data\gdt_engrass1_co.paa";
				};
			};
			colorOutside[]={0.227451,0.27451,0.384314,1};
		};*/
		causticsEnabled=1;
		causticsTextureMask="A3\data_f\caustics\caustics_anim_%03d.paa";
		causticsTextureCount=32;
		causticsDistanceLimit=200;
		causticsDepthLimit=80;
		causticsTextureArea=2;
		causticsTextureAreaDeep=156;
		causticsTextureChangeInterval=0.039999999;
		causticsDepthFadeCoef=0.050000001;
		causticsTextureDepthGranularity=2.5;
		causticsBrightnessCoef=1;
		clutterGrid = 1.0;
		clutterDist = 200;
		noDetailDist = 40;
		fullDetailDist = 15;
		midDetailTexture = "RHNET\Thirsk\data\thirmiddle.paa";
		minTreesInForestSquare = 4;
		minRocksInRockSquare = 2;		
		class clutter {
			class GrassTall : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassTall.p3d";
				affectedByWind = 0.4;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.0;
			};
			
			class StubbleClutter : DefaultClutter {
				model = "ca\plants2\clutter\c_stubble.p3d";
				affectedByWind = 0.1;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.1;
			};
			
			class AutumnFlowers : DefaultClutter {
				model = "ca\plants2\clutter\c_autumn_flowers.p3d";
				affectedByWind = 0.4;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.0;
			};
			
			class GrassBunch : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassBunch.p3d";
				affectedByWind = 0.35;
				swLighting = 1;
				scaleMin = 0.6;
				scaleMax = 1.0;
			};
			
			class GrassCrooked : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrooked.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class GrassCrookedGreen : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrookedGreen.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.3;
			};
			
			class GrassCrookedForest : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrookedForest.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.4;
			};
			
			class WeedDead : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.75;
				scaleMax = 1.1;
			};
			
			class WeedDeadSmall : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead2.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.75;
				scaleMax = 0.9;
			};
			
			class HeatherBrush : DefaultClutter {
				model = "ca\plants2\clutter\c_caluna.p3d";
				affectedByWind = 0.15;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.8;
				surfaceColor[] = {0.53, 0.5, 0.37, 1};
			};
			
			class WeedSedge : DefaultClutter {
				model = "ca\plants2\clutter\c_weed3.p3d";
				affectedByWind = 0.2;
				swLighting = 1;
				scaleMin = 0.5;
				scaleMax = 0.85;
			};
			
			class WeedTall : DefaultClutter {
				model = "ca\plants2\clutter\c_weed2.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.1;
			};
			
			class BlueBerry : DefaultClutter {
				model = "ca\plants2\clutter\c_BlueBerry.p3d";
				affectedByWind = 0.05;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 1.4;
			};
			
			class RaspBerry : DefaultClutter {
				model = "ca\plants2\clutter\c_raspBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class FernAutumn : DefaultClutter {
				model = "ca\plants2\clutter\c_fern.p3d";
				affectedByWind = 0.1;
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			
			class FernAutumnTall : DefaultClutter {
				model = "ca\plants2\clutter\c_fernTall.p3d";
				affectedByWind = 0.15;
				scaleMin = 0.75;
				scaleMax = 1.25;
			};
			
			class SmallPicea : DefaultClutter {
				model = "ca\plants2\clutter\c_picea.p3d";
				affectedByWind = 0.05;
				scaleMin = 0.60;
				scaleMax = 1.30;
			};
			
			class PlantWideLeaf : DefaultClutter {
				model = "ca\plants2\clutter\c_WideLeafPlant.p3d";
				affectedByWind = 0.1;
				scaleMin = 1.0;
				scaleMax = 1.0;
			};
			
			class MushroomsHorcak : DefaultClutter {
				model = "ca\plants2\clutter\c_MushroomHorcak.p3d";
				affectedByWind = 0;
				scaleMin = 0.85;
				scaleMax = 1.25;
			};
			
			class MushroomsPrasivka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomPrasivky.p3d";
			};
			
			class MushroomsBabka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomBabka.p3d";
			};
			
			class MushroomsMuchomurka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomMuchomurka.p3d";
			};
		};
		
		class Subdivision {
			class Fractal {
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			
			class WhiteNoise {
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = 0.0;
			minSlope = 0.02;
		};
		
		class Ambient {
			class Mammals {
				radius = 200;
				cost = "(1 + forest + trees) * (0.5 + (0.5 * night)) * (1 - sea) * (1 - houses)";
				
				class Species {
					class Rabbit {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigBirds {
				radius = 300;
				cost = "((1 + forest + trees) - ((2 * rain)) - houses) * (1 - night) * (1 - sea)";
				
				class Species {
					class Hawk {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class Birds {
				radius = 170;
				cost = "(1 - night) * ((1 + (3 * sea)) - (2 * rain))";
				
				class Species {
					class Crow {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigInsects {
				radius = 20;
				cost = "(5 - (2 * houses)) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class DragonFly {
						probability = "0.6 - (meadow * 0.5) + (forest * 0.4)";
						cost = 1;
					};
					
					class ButterFly {
						probability = "0.4 + (meadow * 0.5) - (forest * 0.4)";
						cost = 1;
					};
				};
			};
			
			class BigInsectsAquatic {
				radius = 20;
				cost = "(3 * sea) * (1 - night) * (1 - rain) * (1 - windy)";
				
				class Species {
					class DragonFly {
						probability = 1;
						cost = 1;
					};
				};
			};
			
			class SmallInsects {
				radius = 3;
				cost = "(12 - 8 * hills) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class HouseFly {
						probability = "deadBody + (1 - deadBody) * (0.5 - forest * 0.1 - meadow * 0.2)";
						cost = 1;
					};
					
					class HoneyBee {
						probability = "(1 - deadBody) * (0.5 - forest * 0.1 + meadow * 0.2)";
						cost = 1;
					};
					
					class Mosquito {
						probability = "(1 - deadBody) * (0.2 * forest)";
						cost = 1;
					};
				};
			};
			
			class NightInsects {
				radius = 3;
				cost = "(9 - 8 * hills) * night * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class Mosquito {
						probability = 1;
						cost = 1;
					};
				};
			};
			
			class WindClutter {
				radius = 10;
				cost = "((20 - 5 * rain) * (3 * (windy factor [0.2, 0.5]))) * (1 - sea)";
				
				class Species {
					class FxWindGrass1 {
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					
					class FxWindGrass2 {
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					
					class FxWindRock1 {
						probability = "0.4 * hills";
						cost = 1;
					};
					
					class FxCrWindLeaf1 {
						probability = "0.2 * trees";
						cost = 1;
					};
					
					class FxCrWindLeaf2 {
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					
					class FxCrWindLeaf3 {
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
			
			class NoWindClutter {
				radius = 15;
				cost = 8;
				
				class Species {
					class FxWindPollen1 {
						probability = 1;
						cost = 1;
					};
					
					class FxCrWindLeaf1 {
						probability = "0.2 * trees";
						cost = 1;
					};
					
					class FxCrWindLeaf2 {
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					
					class FxCrWindLeaf3 {
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
		};
		
	class Names {
			class Thirsk_isl001 {
				name = "Thirsk";
				position[] = {1408, 3075};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl002 {
				name = "Taimenlahti";
				position[] = {3366, 1341};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl003 {
				name = "Itälahti";
				position[] = {4390, 2087};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl004 {
				name = "";
				position[] = {3648.75, 3940};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl005 {
				name = "";
				position[] = {1445, 3560};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl006 {
				name = "";
				position[] = {2610, 3638};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl007 {
				name = "";
				position[] = {811.25, 3388.75};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl008 {
				name = "";
				position[] = {3284, 2722};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl011 {
				name = "Siipilahti";
				position[] = {2098, 3093};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl012 {
				name = "гибель";
				position[] = {2879.17, 3243.96};
				type = "NameVillage";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl013 {
				name = "Eteläpato";
				position[] = {4078.99, 1662.73};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl014 {
				name = "Sudensuoja";
				position[] = {4131, 2670};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl015 {
				name = "Karhunhammas";
				position[] = {4026, 1206};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl016 {
				name = "Mansikkaniemi";
				position[] = {2286, 4658};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl017 {
				name = "Mustikkasaari";
				position[] = {3530, 4749};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl018 {
				name = "THIRSK";
				position[] = {1320.53, 2039.15};
				type = "NameCityCapital";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl019 {
				name = "Kuikin portti";
				position[] = {4006.25, 620.00};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl020 {
				name = "Vasarakarikko";
				position[] = {4721.48, 4816.55};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl021 {
				name = "Valliallas";
				position[] = {3700.77, 1641.78};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl022 {
				name = "";
				position[] = {3540.00, 675.00};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl023 {
				name = "Jafarinin kivi";
				position[] = {3159.42, 3627.25};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl024 {
				name = "Radiomäki";
				position[] = {4352.56, 1370.22};
				type = "Hill";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl025 {
				name = "Ilmarinen";
				position[] = {726.412, 562.765};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl026 {
				name = "";
				position[] = {4336, 1325};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl027 {
				name = "Vanha paloasema";
				position[] = {3972, 1386};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl028 {
				name = "Pieni Karhunhammas";
				position[] = {3510, 757};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl029 {
				name = "Potoskanlahti";
				position[] = {2019, 4352};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl030 {
				name = "Oikurin kallio";
				position[] = {2009, 4253};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl031 {
				name = "Malisen kallio";
				position[] = {2121, 3291};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl032 {
				name = "Pöyrynmäki";
				position[] = {3926, 3644};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl033 {
				name = "Ristikangas";
				position[] = {2556, 3829};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl034 {
				name = "";
				position[] = {2602, 3489};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl035 {
				name = "Välimetsä";
				position[] = {1392, 3583};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl036 {
				name = "";
				position[] = {1136, 4791};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl037 {
				name = "";
				position[] = {1213, 4474};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl038 {
				name = "";
				position[] = {2370, 4517};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl039 {
				name = "Ruosterinne";
				position[] = {615, 3698};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl040 {
				name = "Rocknoil";
				position[] = {664, 2419};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl041 {
				name = "";
				position[] = {964, 1978};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl042 {
				name = "Ykspihlaja";
				position[] = {1040, 4790};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl043 {
				name = "Hirvenpää";
				position[] = {2038, 1080};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl044 {
				name = "Kivipää";
				position[] = {454, 892};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl045 {
				name = "";
				position[] = {2915, 1810};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl046 {
				name = "Tuulensuoja";
				position[] = {1350, 4039};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl047 {
				name = "Etelälahti";
				position[] = {1386, 868};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl048 {
				name = "Elimyssalo";
				position[] = {3385, 3497};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl049 {
				name = "Ylämylly";
				position[] = {2732, 2099};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};
		};
	};
	
	class ThirskW : CAWorld {
		dynLightMinBrightnessAmbientCoef = 0.5;
		dynLightMinBrightnessAbsolute = 0.05;		
		access = 3;
		worldId = 4;
		cutscenes[] = {};
		author = "Raunhofer.net (Ported By Breaking Point)";		
		description = "Thirsk Winter";
		icon = "";
		worldName = "\RHNET\Thirsk4\ThirskW.wrp";
		pictureMap = "\RHNET\Thirsk\data\ThirskWinter.jpg";		
		plateFormat = "ML$ - #####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		longitude = 26;	// positive is east
		latitude = -68;	// positive is south
		loadingTexts[]=		
		{
			"Thirsk Winter was originally created by Raunhofer and then ported to Arma 3 by Breaking Point.",
		};
		class ReplaceObjects {};


		class Grid : Grid {
			offsetX = 0;
			offsetY = 0;
			
			class Zoom1 {
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = 100;
			};
			
			class Zoom2 {
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = 1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = 10000;
			};
		};
		startTime = 9:00;
		startDate = 27/3/2035;
		startWeather = 0.1;
		startFog = 0.01;
		forecastWeather = 0.2;
		forecastFog = 0.05;
		centerPosition[] = {1380, 2030, 300};
		seagullPos[] = {2626, 150, 1865};
		ilsPosition[] = {1106, 3236};
		ilsDirection[] = {-0.9205, 0.080, 0.3907};
		ilsTaxiIn[] = {1453, 3050, 1124, 3190, 1116, 3207, 1134, 3219, 1151, 3216};
		ilsTaxiOff[] = {1643, 3008, 1667, 2979, 1637, 2972, 1585, 2993};
		drawTaxiway = 1;
		
		class SecondaryAirports {

	        class Thirsk_Abafield {
                                ilsPosition[] = {596, 565};
                                ilsDirection[] = {-1.0000, 0.080, 0.0000};
                                ilsTaxiIn[] = {681.975, 525.337, 638.61, 526.458, 616.927, 538.982, 612.254, 556.926, 630.199, 564.029};
                                ilsTaxiOff[] = {1046.05, 565.157, 1071.41, 557.501, 1068.54, 534.054, 1033.61, 529.27, 822.112, 529.27};
                                drawTaxiway = 1;
                        };

		};
		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};
		
		class Sea
		{
			seaTexture="a3\data_f\seatexture_co.paa";
			seaMaterial="#waterriver";
			shoreMaterial="#shore";
			shoreFoamMaterial="#shorefoam";
			shoreWetMaterial="#shorewet";
			WaterMapScale=20;
			WaterGrid=50;
			MaxTide=0;
			MaxWave=0.25;
			SeaWaveXScale="2.0/50";
			SeaWaveZScale="1.0/50";
			SeaWaveHScale=1;
			SeaWaveXDuration=5000;
			SeaWaveZDuration=10000;
		};
		class Underwater
		{
			noWaterFog=-0.001;
			fullWaterFog=0.001;
			deepWaterFog=60;
			waterFogDistanceNear=-10;
			waterFogDistance=90;
			waterColor[]={0,0.039999999,0.029999999};
			deepWaterColor[]={0,0.001,0.0089999996};
			surfaceColor[]={0,0.039999999,0.029999999};
			deepSurfaceColor[]={0,0.001,0.0089999996};
		};
		class SeaWaterShaderPars
		{
			refractionMoveCoef=0.029999999;
			minWaterOpacity=0;
			waterOpacityDistCoef=0.40000001;
			underwaterOpacity=0.5;
			waterOpacityFadeStart=60;
			waterOpacityFadeLength=120;
		};
		class WaterExPars: WaterExPars
		{
			fogDensity=0.25;
			fogColor[]=
			{
				"0.197*0.25",
				"0.25*0.25",
				"0.08*0.25"
			};
			fogColorExtinctionSpeed[]={0.30000001,0.30000001,0.051100001};
			ligtExtinctionSpeed[]=
			{
				"0.02+0.3",
				"0.02+0.3",
				"0.02+0.0511"
			};
			diffuseLigtExtinctionSpeed[]=
			{
				"0.82+0.3",
				"0.52+0.3",
				"1.32+0.0511"
			};
			fogGradientCoefs[]={0.34999999,1,1.7};
			fogColorLightInfluence[]={0.80000001,0.2,1};
			shadowIntensity=0;
			ssReflectionStrength=0.85000002;
			ssReflectionMaxJitter=1;
			ssReflectionRippleInfluence=0.2;
			ssReflectionEdgeFadingCoef=10;
			ssReflectionDistFadingCoef=4;
			refractionMinCoef=0.029999999;
			refractionMaxCoef=0.14;
			refractionMaxDist=5.0999999;
			specularMaxIntensity=75;
			specularPowerOvercast0=300;
			specularPowerOvercast1=3;
			specularNormalModifyCoef=0.001;
			foamAroundObjectsIntensity=0.2;
			foamAroundObjectsFadeCoef=8;
			foamColorCoef=2;
			foamDeformationCoef=0.02;
			foamTextureCoef=0.2;
			foamTimeMoveSpeed=0.2;
			foamTimeMoveAmount=0.1;
			shoreDarkeningMaxCoef=0.55000001;
			shoreDarkeningOffset=0.02;
			shoreDarkeningGradient=0.2;
			shoreWaveTimeScale=0.80000001;
			shoreWaveShifDerivativeOffset=-0.80000001;
			shoreFoamIntensity=0.5;
			shoreMaxWaveHeight=0.046;
			shoreWetLayerReflectionIntensity=0.55000001;
		};
		startFogBase=250;
		forecastFogBase=250;
		startFogDecay=0.018;
		forecastFogDecay=0.018;
		fogBeta0Min=0;
		fogBeta0Max=0.0049999999;		
		class HDRNewPars
		{
			minAperture=9.9999997e-006;
			maxAperture=256;
			apertureRatioMax=4;
			apertureRatioMin=10;
			bloomImageScale=1;
			bloomScale=0.15000001;
			bloomExponent=1.3;
			bloomLuminanceOffset=0.75;
			bloomLuminanceScale=0.75;
			bloomLuminanceExponent=0.75;
			tonemapMethod=1;
			tonemapShoulderStrength=0.22;
			tonemapLinearStrength=0.12;
			tonemapLinearAngle=0.1;
			tonemapToeStrength=0.2;
			tonemapToeNumerator=0.022;
			tonemapToeDenominator=0.2;
			tonemapLinearWhite=11.2;
			tonemapExposureBias=1;
			tonemapLinearWhiteReinhard=2.5;
			eyeAdaptFactorLight=3.3;
			eyeAdaptFactorDark=0.25;
			nvgApertureMin=10;
			nvgApertureStandard=12.5;
			nvgApertureMax=16.5;
			nvgStandardAvgLum=10;
			nvgLightGain=320;
			nvgTransition=1;
			nvgTransitionCoefOn=40;
			nvgTransitionCoefOff=0.0099999998;
			nightShiftMinAperture=0;
			nightShiftMaxAperture=0.0020000001;
			nightShiftMaxEffect=0.60000002;
			nightShiftLuminanceScale=600;
		};
		skyColorInfluencesFogColor=0;
		class Lighting: DefaultLighting
		{
			groundReflection[]={0.059999999,0.059999999,0.029999999};
			moonObjectColorFull[]={360,340,300,100};
			moonHaloObjectColorFull[]={15,17,25,50};
			moonsetObjectColor[]={275,250,225,1};
			moonsetHaloObjectColor[]={10,10,10,0.25};
			class ThunderBoltLight
			{
				diffuse[]={2120,3170,9550};
				ambient[]={0.001,0.001,0.001};
				intensity=120000;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=0;
					quadratic=1;
				};
			};
			starEmissivity=50;
		};
		class DayLightingBrightAlmost: DayLightingBrightAlmost
		{
			deepNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			fullNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunMoon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlySun[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunrise[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlyMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			midMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			morning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			noon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
		};
		class DayLightingRainy: DayLightingRainy
		{
			deepNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			fullNight[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			sunMoon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlySun[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			earlyMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			morning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			lateMorning[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
			noon[]=
			{
				-15,
				{0.0049999999,0.0099999998,0.0099999998},
				{0,0.0020000001,0.003},
				{0,0,0},
				{0,0,0},
				{0,0.0020000001,0.003},
				{0,0.0020000001,0.003},
				0
			};
		};
		class Weather: Weather
		{
			class LightingNew
			{
				class Lighting0
				{
					height=0;
					overcast=0.25;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.14,0.22},
						3.5
					};
					diffuseCloud[]={{0.1,0.1,0.2},2.8};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						4
					};
					ambientCloud[]={{0.51999998,0.67000002,1},3.5};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.3
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},3};
					groundReflection[]={0.57200003,0.67000002,0.89999998};
					groundReflectionCloud[]={0.57200003,0.67000002,0.89999998};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]=
					{
						{0.090000004,0.13699999,0.22},
						0.002
					};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.17,0.32,0.8},
						14
					};
					swBrightness=3;
				};
				class Lighting1
				{
					height=0;
					overcast=0.25;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.090000004,0.090000004,0.1},
						2.6
					};
					diffuseCloud[]={{0.090000004,0.090000004,0.2},2.3};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						5.4
					};
					ambientCloud[]={{0.51999998,0.67000002,1},5.2};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						5.4
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},5.2};
					groundReflection[]={{0.57200003,0.67000002,0.89999998},1};
					groundReflectionCloud[]={{0.57200003,0.67000002,0.89999998},0.05};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.15000001,0.30000001},
						4
					};
					skyAroundSun[]=
					{
						{0.40000001,0.30000001,0.30000001},
						9
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						3
					};
					apertureMin=6;
					apertureStandard=7;
					apertureMax=8;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.9,1,1},
						14
					};
					swBrightness=3;
				};
				class Lighting2
				{
					height=0;
					overcast=0.25;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.80000001,0.40000001,0.18000001},
						5
					};
					diffuseCloud[]=
					{
						{1,0.34999999,0.34},
						3
					};
					ambient[]=
					{
						{0.69999999,0.5,0.5},
						7.75
					};
					ambientCloud[]=
					{
						{0.60000002,0.5,0.5},
						5
					};
					ambientMid[]=
					{
						{0.55000001,0.60000002,0.80000001},
						6.5
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.60000002,0.80000001},
						5.5
					};
					groundReflection[]=
					{
						{0.55000001,0.60000002,0.80000001},
						6.5
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.60000002,0.89999998},
						3.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.2,0.40000001},
						6
					};
					skyAroundSun[]=
					{
						{0.25,0.1,0.029999999},
						11
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						5.5
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.5,0.5};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.69999999,0.69999999,0.69999999},
						9
					};
					swBrightness=2;
				};
				class Lighting3
				{
					height=0;
					overcast=0.25;
					sunAngle=4;
					sunOrMoon=0.9;
					diffuse[]=
					{
						{0.89999998,0.40000001,0.16},
						8
					};
					diffuseCloud[]=
					{
						{0.80000001,0.40000001,0.16},
						9
					};
					ambient[]=
					{
						{0.5,0.38999999,0.34999999},
						9
					};
					ambientCloud[]=
					{
						{0.5,0.38999999,0.34999999},
						9
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.44999999},
						8.1000004
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.44999999},
						7.6999998
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.44999999},
						7.0999999
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.5,0.5},
						6.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.25,0.40000001},
						10.5
					};
					skyAroundSun[]=
					{
						{0.30000001,0.2,0.1},
						12
					};
					fogColor[]=
					{
						{0.15000001,0.13500001,0.13},
						7
					};
					apertureMin=9;
					apertureStandard=13;
					apertureMax=30;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.12,0.050000001,0.050000001};
					mie[]={0.003,0.0020000001,0.003};
					cloudsColor[]=
					{
						{0.2,0.2,0.2},
						11
					};
					swBrightness=1;
				};
				class Lighting4
				{
					height=0;
					overcast=0.25;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.5,0.25999999},
						10.25
					};
					diffuseCloud[]=
					{
						{1,0.44999999,0.25999999},
						10.25
					};
					ambient[]=
					{
						{0.55000001,0.40000001,0.34999999},
						9.8000002
					};
					ambientCloud[]=
					{
						{0.60000002,0.40000001,0.40000001},
						9.8000002
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.44999999},
						8.3000002
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.5},
						8
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.44999999},
						7.75
					};
					groundReflectionCloud[]=
					{
						{0.60000002,0.64999998,0.76800001},
						7
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.69999999},
						10.5
					};
					skyAroundSun[]=
					{
						{0.15000001,0.2,0.2},
						12
					};
					fogColor[]=
					{
						{0.125,0.13,0.14},
						8.1999998
					};
					apertureMin=10;
					apertureStandard=15;
					apertureMax=40;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.059999999,0.1,0.090000004};
					mie[]={0.0020000001,0.0020000001,0.0020000001};
					cloudsColor[]=
					{
						{0.2,0.2,0.15000001},
						12
					};
					swBrightness=1;
				};
				class Lighting5
				{
					height=0;
					overcast=0.25;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.63,0.40000001},
						12
					};
					diffuseCloud[]=
					{
						{1,0.63,0.40000001},
						11.5
					};
					ambient[]=
					{
						{0.60000002,0.60000002,0.60000002},
						10.75
					};
					ambientCloud[]=
					{
						{0.56999999,0.60000002,0.69999999},
						10.75
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.50999999},
						9.1999998
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.5,0.50999999},
						9
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.50999999},
						9
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.61199999,0.69999999},
						8.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.33000001,0.80000001},
						10.75
					};
					skyAroundSun[]=
					{
						{0.1,0.30000001,0.60000002},
						12
					};
					fogColor[]=
					{
						{0.11,0.125,0.14},
						9.75
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.1,0.13,0.2};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.5,0.5,0.30000001},
						12
					};
					swBrightness=1;
				};
				class Lighting6
				{
					height=0;
					overcast=0.25;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.75,0.55000001},
						12.4
					};
					diffuseCloud[]=
					{
						{1,0.75,0.55000001},
						12.1
					};
					ambient[]=
					{
						{0.57999998,0.58999997,0.63},
						11
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.63},
						11
					};
					ambientMid[]=
					{
						{0.57999998,0.50999999,0.47999999},
						10.2
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10
					};
					groundReflection[]=
					{
						{0.57999998,0.50999999,0.47999999},
						10
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						9.8999996
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.28,0.94999999},
						11
					};
					skyAroundSun[]=
					{
						{0.1,0.28,0.80000001},
						12
					};
					fogColor[]=
					{
						{0.105,0.13,0.17},
						10
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						12
					};
					swBrightness=1;
				};
				class Lighting7
				{
					height=0;
					overcast=0.25;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.64999998},
						13.75
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.64999998},
						13.5
					};
					ambient[]=
					{
						{0.57999998,0.58999997,0.68000001},
						11.75
					};
					ambientCloud[]=
					{
						{0.56999999,0.58999997,0.68000001},
						11.7
					};
					ambientMid[]=
					{
						{0.57999998,0.53100002,0.47600001},
						11
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11
					};
					groundReflection[]=
					{
						{0.57999998,0.53100002,0.47600001},
						10.5
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.075000003,0.2,1},
						12
					};
					skyAroundSun[]=
					{
						{0.075000003,0.23,1},
						12.5
					};
					fogColor[]=
					{
						{0.105,0.14,0.2},
						11.7
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						13
					};
					swBrightness=1;
				};
				class Lighting8
				{
					height=0;
					overcast=0.25;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.66000003},
						14
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.66000003},
						13.7
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.49000001},
						12.1
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						12
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.49000001},
						11.2
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.075000003,0.22,1},
						13
					};
					skyAroundSun[]=
					{
						{0.075000003,0.22,1},
						13
					};
					fogColor[]=
					{
						{0.105,0.145,0.2},
						12
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,0.89999998,0.69999999},
						13
					};
					swBrightness=1;
				};
				class Lighting9
				{
					height=0;
					overcast=0.60000002;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.13,0.2},
						3.5
					};
					diffuseCloud[]=
					{
						{0.1,0.13,0.2},
						3
					};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						3.8
					};
					ambientCloud[]=
					{
						{1,1,1},
						3.4
					};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.2
					};
					ambientMidCloud[]=
					{
						{0.57200003,0.67000002,0.89999998},
						2.9
					};
					groundReflection[]=
					{
						{0.57200003,0.67000002,0.89999998},
						0.1
					};
					groundReflectionCloud[]=
					{
						{0.57200003,0.67000002,0.89999998},
						0.1
					};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]=
					{
						{0.090000004,0.13699999,0.22},
						0.002
					};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{0.17,0.32,0.8},
						14
					};
					swBrightness=3;
				};
				class Lighting10
				{
					height=0;
					overcast=0.60000002;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.090000004,0.090000004,0.2},
						2.5
					};
					diffuseCloud[]={{0,0,0},2.25};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						5.4
					};
					ambientCloud[]={{1,1,1},5};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						5.2
					};
					ambientMidCloud[]={{0.57200003,0.67000002,0.89999998},5};
					groundReflection[]={{0.57200003,0.67000002,0.89999998},1};
					groundReflectionCloud[]={{0.57200003,0.67000002,0.89999998},0.05};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.15000001,0.30000001},
						4
					};
					skyAroundSun[]=
					{
						{0.5,0.30000001,0.2},
						8
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						2
					};
					apertureMin=6;
					apertureStandard=7;
					apertureMax=8;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{1,1,1},
						16
					};
					swBrightness=3;
				};
				class Lighting11
				{
					height=0;
					overcast=0.60000002;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.89999998,0.34999999,0.075000003},
						4
					};
					diffuseCloud[]={{0.89999998,0.34999999,0.075000003},1};
					ambient[]=
					{
						{0.69999999,0.60000002,0.60000002},
						7
					};
					ambientCloud[]=
					{
						{1,1,1},
						6
					};
					ambientMid[]=
					{
						{0.55000001,0.60000002,0.89999998},
						6.5
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.60000002,0.89999998},
						6.1
					};
					groundReflection[]=
					{
						{0.55000001,0.60000002,0.80000001},
						3
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.60000002,0.80000001},
						2.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.2,0.5},
						6
					};
					skyAroundSun[]=
					{
						{0.5,0.15000001,0},
						10
					};
					fogColor[]=
					{
						{0.15000001,0.15000001,0.175},
						5
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.050000001,0.12,0.17};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.69999999,0.69999999,0.69999999},
						4
					};
					swBrightness=2;
				};
				class Lighting12
				{
					height=0;
					overcast=0.60000002;
					sunAngle=4;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.89999998,0.34999999,0.1},
						8
					};
					diffuseCloud[]=
					{
						{0.89999998,0.30000001,0.050000001},
						4
					};
					ambient[]=
					{
						{0.30000001,0.23,0.2},
						8.6999998
					};
					ambientCloud[]=
					{
						{0.30000001,0.23,0.2},
						8.6999998
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.5},
						8
					};
					ambientMidCloud[]=
					{
						{0.55000001,0.5,0.5},
						7.5
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.5},
						7
					};
					groundReflectionCloud[]=
					{
						{0.55000001,0.5,0.5},
						6.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.2,0.30000001,0.40000001},
						9.5
					};
					skyAroundSun[]=
					{
						{0.5,0.2,0.050000001},
						11.5
					};
					fogColor[]=
					{
						{0.15000001,0.13,0.12},
						6.5
					};
					apertureMin=9;
					apertureStandard=13;
					apertureMax=30;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.050000001,0.059999999,0.17};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						8
					};
					swBrightness=1;
				};
				class Lighting13
				{
					height=0;
					overcast=0.60000002;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.44999999,0.16},
						10.25
					};
					diffuseCloud[]=
					{
						{1,0.44999999,0.16},
						6
					};
					ambient[]=
					{
						{0.69999999,0.67000002,0.68000001},
						10
					};
					ambientCloud[]=
					{
						{0.69999999,0.67000002,0.68000001},
						9.6000004
					};
					ambientMid[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9.1999998
					};
					ambientMidCloud[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9
					};
					groundReflection[]=
					{
						{0.64999998,0.60000002,0.60000002},
						9
					};
					groundReflectionCloud[]=
					{
						{0.64999998,0.60000002,0.60000002},
						8.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.13,0.30000001,0.5},
						11
					};
					skyAroundSun[]=
					{
						{0.5,0.23,0.1},
						12.5
					};
					fogColor[]=
					{
						{0.13,0.125,0.11},
						7.5
					};
					apertureMin=10;
					apertureStandard=15;
					apertureMax=40;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.059999999,0.090000004,0.090000004};
					mie[]={0.0020000001,0.0020000001,0.0020000001};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						8.5
					};
					swBrightness=1;
				};
				class Lighting14
				{
					height=0;
					overcast=0.60000002;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.67500001,0.44999999},
						12
					};
					diffuseCloud[]=
					{
						{1,0.69999999,0.44999999},
						8
					};
					ambient[]=
					{
						{0.64999998,0.61199999,0.69999999},
						10.8
					};
					ambientCloud[]=
					{
						{0.64999998,0.61199999,0.72000003},
						10.9
					};
					ambientMid[]=
					{
						{0.56999999,0.55000001,0.60000002},
						9.5
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.55000001,0.62},
						9.5
					};
					groundReflection[]=
					{
						{0.56999999,0.55000001,0.60000002},
						9.3000002
					};
					groundReflectionCloud[]=
					{
						{0.56999999,0.61199999,0.69999999},
						8.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.55000001},
						11.5
					};
					skyAroundSun[]=
					{
						{0.2,0.30000001,0.34999999},
						12
					};
					fogColor[]=
					{
						{0.125,0.13,0.13500001},
						9.75
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.090000004,0.1,0.1};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.25,0.25,0.2},
						9
					};
					swBrightness=1;
				};
				class Lighting15
				{
					height=0;
					overcast=0.60000002;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.75,0.60000002},
						12.4
					};
					diffuseCloud[]=
					{
						{1,0.75,0.68000001},
						11
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.63},
						11.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.64999998},
						11
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.56},
						10.4
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						10.3
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.56},
						10
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						9.1999998
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]={0.11,0.30000001,0.64999998};
					skyAroundSun[]=
					{
						{0.11,0.30000001,0.64999998},
						11.7
					};
					fogColor[]=
					{
						{0.105,0.13,0.18000001},
						9
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						11.5
					};
					swBrightness=1;
				};
				class Lighting16
				{
					height=0;
					overcast=0.60000002;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.64999998},
						13.75
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.64999998},
						11.8
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.68000001},
						11.8
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.68000001},
						11.9
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.5},
						11.3
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.5},
						11.1
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.5},
						10.5
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						9.3000002
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,0.80000001},
						12
					};
					skyAroundSun[]=
					{
						{0.11,0.30000001,0.80000001},
						12.2
					};
					fogColor[]=
					{
						{0.105,0.13,0.17},
						10.25
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						12
					};
					swBrightness=1;
				};
				class Lighting17
				{
					height=0;
					overcast=0.60000002;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{1,0.80000001,0.66000003},
						14.1
					};
					diffuseCloud[]=
					{
						{1,0.80000001,0.66000003},
						12.2
					};
					ambient[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12.1
					};
					ambientCloud[]=
					{
						{0.56999999,0.57999998,0.69999999},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.52200001,0.56},
						11.8
					};
					ambientMidCloud[]=
					{
						{0.56999999,0.52200001,0.56},
						11.6
					};
					groundReflection[]=
					{
						{0.56999999,0.52200001,0.56},
						11.2
					};
					groundReflectionCloud[]=
					{
						{0.5,0.5,0.5},
						11
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.30000001,1},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.30000001,1},
						13
					};
					fogColor[]=
					{
						{0.105,0.145,0.2},
						10.1
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{1,1,0.80000001},
						14
					};
					swBrightness=1;
				};
				class Lighting18
				{
					height=0;
					overcast=0.90;
					sunAngle=-15;
					sunOrMoon=0;
					diffuse[]=
					{
						{0.1,0.13,0.2},
						3.2
					};
					diffuseCloud[]={{0.1,0.13,0.2},1};
					ambient[]=
					{
						{0.51999998,0.67000002,1},
						3.6
					};
					ambientCloud[]={{1,1,1},3.2};
					ambientMid[]=
					{
						{0.57200003,0.67000002,0.89999998},
						3.5
					};
					ambientMidCloud[]={{1,1,1},3};
					groundReflection[]={0.57200003,0.67000002,0.89999998};
					groundReflectionCloud[]={1,1,1};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]={0.0231,0.31400001,0.46700001};
					skyAroundSun[]=
					{
						{0.2,0.25,0.44999999},
						0.02
					};
					fogColor[]={0.090000004,0.13699999,0.22};
					apertureMin=4.5;
					apertureStandard=6;
					apertureMax=7.5;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0070000002,0.052000001,0.103};
					mie[]={0.0099999998,0.0074999998,0.0049999999};
					cloudsColor[]=
					{
						{1,1,1},
						14,75
					};
					swBrightness=3;
				};
				class Lighting19
				{
					height=0;
					overcast=0.90;
					sunAngle=-4;
					sunOrMoon=0.2;
					diffuse[]=
					{
						{0.2,0.2,0.2},
						0.21
					};
					diffuseCloud[]={{0,0,0},0.21};
					ambient[]=
					{
						{0.5,0.55000001,1},
						4
					};
					ambientCloud[]={{1,1,1},4};
					ambientMid[]=
					{
						{0.55000001,0.55000001,0.85000002},
						4
					};
					ambientMidCloud[]={{1,1,1},4};
					groundReflection[]={{0.55000001,0.55000001,0.85000002},0.025};
					groundReflectionCloud[]={{1,1,1},0.025};
					bidirect[]={0.090000004,0.090000004,0.090000004};
					bidirectCloud[]={0.090000004,0.090000004,0.090000004};
					sky[]=
					{
						{0.1,0.30000001,0.69999999},
						3
					};
					skyAroundSun[]=
					{
						{0.2,0.30000001,0.60000002},
						7
					};
					fogColor[]={0.079999998,0.079999998,0.094999999};
					apertureMin=5;
					apertureStandard=7;
					apertureMax=9;
					standardAvgLum=4;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.5};
					mie[]={0.050000001,0.050000001,0.050000001};
					cloudsColor[]=
					{
						{0.1,0.1,0.1},
						17
					};
					swBrightness=3;
				};
				class Lighting20
				{
					height=0;
					overcast=0.90;
					sunAngle=0;
					sunOrMoon=0.6;
					diffuse[]=
					{
						{0.375,0.22499999,0.039999999},
						0.050000001
					};
					diffuseCloud[]=
					{
						{1,1,1},
						0.050000001
					};
					ambient[]=
					{
						{0.5,0.5,0.60000002},
						5.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						5.2
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.80000001},
						5.4
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						5
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.80000001},
						0.25
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						0.25
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						1
					};
					skyAroundSun[]=
					{
						{0.2,0.25,0.30000001},
						1
					};
					fogColor[]=
					{
						{0.079999998,0.079999998,0.094999999},
						0.25
					};
					apertureMin=8;
					apertureStandard=10;
					apertureMax=25;
					standardAvgLum=50;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.5};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.44999999,0.22,0.15000001},
						3
					};
					swBrightness=2;
				};
				class Lighting21
				{
					height=0;
					overcast=0.90;
					sunAngle=4;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.1,0.1,0.1},
						0.1
					};
					diffuseCloud[]=
					{
						{1,1,1},
						0.0049999999
					};
					ambient[]=
					{
						{0.60000002,0.60000002,0.75},
						8.1999998
					};
					ambientCloud[]=
					{
						{1,1,1},
						8
					};
					ambientMid[]=
					{
						{0.55000001,0.5,0.62},
						7.1999998
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						7
					};
					groundReflection[]=
					{
						{0.55000001,0.5,0.62},
						6.5
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						6
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						9
					};
					skyAroundSun[]=
					{
						{0.2,0.2,0.30000001},
						10
					};
					fogColor[]=
					{
						{0.125,0.125,0.14},
						7.5
					};
					apertureMin=13;
					apertureStandard=17;
					apertureMax=40;
					standardAvgLum=75;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.30000001};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.44999999,0.30000001,0.15000001},
						3
					};
					swBrightness=1;
				};
				class Lighting22
				{
					height=0;
					overcast=0.90;
					sunAngle=8;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.30000001,0.30000001,0.34999999},
						0.75
					};
					diffuseCloud[]=
					{
						{1,1,1},
						1
					};
					ambient[]=
					{
						{0.64999998,0.64999998,0.80000001},
						9
					};
					ambientCloud[]=
					{
						{1,1,1},
						9
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.62},
						8
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						7.8000002
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.62},
						7.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						7.5999999
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						10
					};
					skyAroundSun[]=
					{
						{0.16,0.18000001,0.2},
						10
					};
					fogColor[]=
					{
						{0.125,0.125,0.15000001},
						8
					};
					apertureMin=14;
					apertureStandard=21;
					apertureMax=55;
					standardAvgLum=100;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.5,0.5,0.30000001};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.60000002,0.30000001,0.15000001},
						5
					};
					swBrightness=1;
				};
				class Lighting23
				{
					height=0;
					overcast=0.90;
					sunAngle=15;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.31999999,0.30000001,0.34999999},
						1
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						2
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						10
					};
					ambientCloud[]=
					{
						{1,1,1},
						10
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.60000002},
						9.3000002
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						9
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.60000002},
						8.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						8.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						10.8
					};
					skyAroundSun[]=
					{
						{0.16,0.18000001,0.2},
						11.4
					};
					fogColor[]=
					{
						{0.30000001,0.34,0.44},
						9
					};
					apertureMin=18;
					apertureStandard=20;
					apertureMax=55;
					standardAvgLum=175;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.75,0.60000002,0.40000001},
						5
					};
					swBrightness=1;
				};
				class Lighting24
				{
					height=0;
					overcast=0.90;
					sunAngle=22;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						3.5
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						2.5
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						11
					};
					ambientCloud[]=
					{
						{1,1,1},
						10.8
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.56999999},
						10
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						9.8000002
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						9.8000002
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						9.6000004
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						12.6
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.19},
						12.6
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						8.2
					};
					apertureMin=20;
					apertureStandard=22;
					apertureMax=55;
					standardAvgLum=250;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						7.5
					};
					swBrightness=1;
				};
				class Lighting25
				{
					height=0;
					overcast=0.90;
					sunAngle=35;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						9.8000002
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						6
					};
					ambient[]=
					{
						{0.69999999,0.69999999,0.80000001},
						11.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						11.2
					};
					ambientMid[]=
					{
						{0.56999999,0.5,0.56999999},
						11
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						10.5
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						10
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						9.5
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.18799999},
						13
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						9.15
					};
					apertureMin=28;
					apertureStandard=35;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						7.5
					};
					swBrightness=1;
				};
				class Lighting26
				{
					height=0;
					overcast=0.90;
					sunAngle=40;
					sunOrMoon=1;
					diffuse[]=
					{
						{0.80000001,0.80000001,0.80000001},
						10
					};
					diffuseCloud[]=
					{
						{0.1,0.1,0.1},
						6
					};
					ambient[]=
					{
						{0.69999999,0.64999998,0.80000001},
						12.5
					};
					ambientCloud[]=
					{
						{1,1,1},
						12
					};
					ambientMid[]=
					{
						{0.56999999,0.55000001,0.56999999},
						11.5
					};
					ambientMidCloud[]=
					{
						{1,1,1},
						11
					};
					groundReflection[]=
					{
						{0.56999999,0.5,0.56999999},
						11
					};
					groundReflectionCloud[]=
					{
						{1,1,1},
						10
					};
					bidirect[]={0,0,0};
					bidirectCloud[]={0,0,0};
					sky[]=
					{
						{0.11,0.15000001,0.2},
						13
					};
					skyAroundSun[]=
					{
						{0.11,0.145,0.18799999},
						13
					};
					fogColor[]=
					{
						{0.105,0.12,0.16},
						9.5
					};
					apertureMin=33;
					apertureStandard=36;
					apertureMax=60;
					standardAvgLum=500;
					desiredLuminanceCoef=1;
					desiredLuminanceCoefCloud=1;
					luminanceRectCoef=1;
					luminanceRectCoefCloud=0.5;
					rayleigh[]={0.0075900001,0.01388,0.02878};
					mie[]={0.0049999999,0.0049999999,0.0049999999};
					cloudsColor[]=
					{
						{0.89999998,1,1},
						8.7
					};
					swBrightness=1;
				};
			};
			class Lighting: Lighting
			{
				class BrightAlmost: DayLightingBrightAlmost
				{
					overcast=0;
				};
				class Rainy: DayLightingRainy
				{
					overcast=1;
				};
			};
			class LightningsConfig: LightningsConfig
			{
				minCloudiness=0.70;
				minProbability=0;
				maxProbability=1;
				minCount=0;
				maxCount=6;
				scatter=20;
			};
			class Overcast: Overcast
			{
				class Weather1: Weather1
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_clear_horizont_sky.paa";
					overcast=0;
					alpha=0.5;
					size=0.1;
					height=1;
					bright=0.69999999;
					speed=0;
					through=0.45;
					diffuse=1;
					cloudDiffuse=0.94999999;
					waves=0.2;
					lightingOvercast=0;
				};
				class Weather2: Weather2
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_clear_horizont_sky.paa";
					overcast=0.22000001;
					alpha=0.6;
					size=0.25;
					height=0.92;
					bright=0.47;
					speed=0.22;
					through=0.4;
					diffuse=1;
					cloudDiffuse=0.94999999;
					waves=0.2;
					lightingOvercast=0.1;
				};
				class Weather3: Weather3
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_almostclear_horizont_sky.paa";
					overcast=0.40;
					alpha=0.80000002;
					size=0.45000001;
					height=0.89999998;
					bright=0.39;
					speed=0.29;
					through=0.36;
					lightingOvercast=0.35;
					diffuse=1;
					waves=0.22;
				};
				class Weather4: Weather4
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_semicloudy_horizont_sky.paa";
					overcast=0.58000001;
					alpha=0.94000001;
					size=0.55;
					height=0.80000001;
					bright=0.25000001;
					speed=0.47;
					through=0.35;
					lightingOvercast=0.54;
					diffuse=1;
					waves=0.32;
				};
				class Weather5: Weather5
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_cloudy_horizont_sky.paa";
					overcast=0.67000002;
					alpha=0.99000001;
					size=0.64999998;
					height=0.75;
					bright=0.1;
					speed=0.60000001;
					through=0.31;
					lightingOvercast=0.72;
					diffuse=0;
					waves=0.40000001;
				};
				class Weather6: Weather6
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_mostlycloudy_horizont_sky.paa";
					overcast=0.84;
					alpha=1;
					size=0.80000001;
					height=0.69999999;
					bright=0.1;
					speed=0.75;
					through=0.2;
					lightingovercast=0.92; //Earlier and smoother transition to dark overcast&fog
					diffuse=0;
					waves=0.90000002;
				};
				class Weather7: Weather6
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_overcast_horizont_sky.paa";
					overcast=0.95;
					alpha=1;
					bright=0.1;
					size=1;
					height=0.60000002;
					speed=0.94999999;
					through=0.3;
					lightingOvercast=0.84;
					diffuse=1;
					waves=0.60000001;
				};
			};
		};
		humidityUpCoef=0.1;
		humidityDownCoef=0.050000001;
		class SimulWeather
		{
			noiseTexture="a3\data_f\noise_raw.paa";
			numKeyframesPerDay=48;
			windSpeedCoef="10.0f";
			moonIrradianceCoef="7.0f";
			fadeMaxDistanceKm=1000;
			fadeMaxAltitudeKm=15;
			fadeNumAltitudes=8;
			fadeNumElevations=8;
			fadeNumDistances=8;
			fadeEarthTest=1;
			autoBrightness=1;
			autoBrightnessStrength=0.1;
			cloudGridWidth=64;
			cloudGridLength=64;
			cloudGridHeight=16;
			helperGridElevationSteps=24;
			helperGridAzimuthSteps=15;
			helperEffectiveEarthRadius=1000000;
			helperCurvedEarth=1;
			helperAdjustCurvature=0;
			helperNumLayers=120;
			helperMaxDistance=160000;
			helperNearCloudFade=0.1;
			helperChurn=10;
			cloudWidth=40000;
			cloudLength=40000;
			wrapClouds=1;
			noiseResolution=8;
			noisePeriod=4;
			opticalDensity=1.5;
			alphaSharpness=0.85000002;
			selfShadowScale=0.90499997;
			mieAsymmetry=0.50870001;
			minimumLightElevationDegrees=6;
			directLightCoef=1;
			indirectLightCoef=0.04;
			fogStart=0;
			fogEnd=50000;
			fogHeight=2000;
			maxPrecipitationParticles = 1000000;
			class DefaultKeyframe
			{
				rayleigh[]={0.0074900002,0.01388,0.02878};
				mie[]={0.0046000001,0.0046000001,0.0046000001};
				haze=30;
				hazeBaseKm=5;
				hazeScaleKm=1;
				hazeEccentricity=1;
				brightnessAdjustment=1;
				cloudiness=0.60000002;
				cloudBaseKm=2.8499999;
				cloudHeightKm=6;
				directLight=1;
				indirectLight=1;
				ambientLight=0.2;
				noiseOctaves=4.3000002;
				noisePersistence=0.53500003;
				fractalAmplitude=2.3;
				fractalWavelength=240;
				extinction=4.7;
				diffusivity=0.001;
			};
			class Overcast
			{
				class Weather1: DefaultKeyframe
				{
					overcast=0;
					cloudiness=0.02;
					cloudBaseKm=1.6;
					diffusivity=0.001;
					seqFileKeyframe=0;
				};
				class Weather2: DefaultKeyframe
				{
					overcast=0.2;
					cloudiness=0.18;
					extinction=5.2;
					cloudBaseKm=1.5;
					cloudHeightKm=7.4;
					diffusivity=0.001;
					indirectLight=0.85;
					seqFileKeyframe=0;
				};
				class Weather3: DefaultKeyframe
				{
					overcast=0.40000001;
					cloudiness=0.36;
					extinction=9.8;
					cloudBaseKm=1.7;
					cloudHeightKm=10.5;
					diffusivity=0.001;
					indirectLight=0.5;
					seqFileKeyframe=3;
				};
				class Weather4: DefaultKeyframe
				{
					overcast=0.52;
					cloudiness=0.45;
					extinction=8.7;
					diffusivity=0.001;
					cloudBaseKm=1.4;
					cloudHeightKm=13.5;
					indirectLight=0.22;
					seqFileKeyframe=4;
				};
				class Weather5: DefaultKeyframe
				{
					overcast=0.72;
					cloudiness=0.66;
					diffusivity=0.001;
					extinction=10;
					cloudBaseKm=2.2;
					cloudHeightKm=18;
					indirectLight=0.12;
					seqFileKeyframe=4;
				};
				class Weather6: DefaultKeyframe
				{
					overcast=0.85;
					cloudiness=0.8;
					diffusivity=0.001;
					extinction=9;
					cloudBaseKm=1.6;
					cloudHeightKm=10;
					indirectLight=0.16;
					directLight=0.8;
					seqFileKeyframe=4;
				};
				class Weather7: DefaultKeyframe
				{
					overcast=0.95;
					cloudiness=1;
					diffusivity=0.001;
					extinction=3.5;
					cloudBaseKm=1.4;
					cloudHeightKm=12;
					indirectLight=1;
					directLight=1;
					seqFileKeyframe=4;
				};
			};
		};
		hazeDistCoef=0.1;
		hazeFogCoef=0.98000002;
		fogHeight=2000;
		hazeBaseHeight=0;
		hazeBaseBeta0=0.00004;
		hazeDensityDecay=0.00025000003;
		aroundSunCoefMultiplier=1.38;
		aroundSunCoefExponent=8;
		soundMapSizeCoef=4;
		satelliteNormalBlendStart=10;
		satelliteNormalBlendEnd=100;
		skyObject="A3\Map_Enoch\Data\skydome.p3d";
		horizontObject="A3\Map_Enoch\Data\horizon.p3d";
		skyTexture="A3\Map_Enoch\Data\sky_semicloudy_sky.paa";
		skyTextureR="A3\Map_Enoch\Data\sky_semicloudy_lco.paa";
		terrainBlendMaxDarkenCoef=1;
		terrainBlendMaxBrightenCoef=0;
		lightningsForced=1;
		class EnvMaps
		{
			class EnvMap1
			{
				texture="A3\Map_Enoch\Data\env_land_ClearSky_ca.paa";
				overcast=0;
			};
			class EnvMap2
			{
				texture="A3\Map_Enoch\Data\env_land_SemiCloudySky_ca.paa";
				overcast=0.40000001;
			};
			class EnvMap3
			{
				texture="A3\Map_Enoch\Data\env_land_OvercastSky_ca.paa";
				overcast=0.90;
			};
		};
		/*class OutsideTerrain
		{
			satellite="A3\Map_Enoch\Data\s_satout_co.paa";
			enableTerrainSynth=1;
			class Layers
			{
				class Layer0
				{
					nopx="A3\Map_Enoch\data\gdt_engrass1_nopx.paa";
					texture="A3\Map_Enoch\data\gdt_engrass1_co.paa";
				};
			};
			colorOutside[]={0.227451,0.27451,0.384314,1};
		};*/
		causticsEnabled=1;
		causticsTextureMask="A3\data_f\caustics\caustics_anim_%03d.paa";
		causticsTextureCount=32;
		causticsDistanceLimit=200;
		causticsDepthLimit=80;
		causticsTextureArea=2;
		causticsTextureAreaDeep=156;
		causticsTextureChangeInterval=0.039999999;
		causticsDepthFadeCoef=0.050000001;
		causticsTextureDepthGranularity=2.5;
		causticsBrightnessCoef=1;
		minTreesInForestSquare = 4;
		minRocksInRockSquare = 2;
		clutterGrid = 1.0;
		clutterDist = 200;
		noDetailDist = 40;
		fullDetailDist = 15;
		midDetailTexture = "RHNET\Thirsk3\data\thir_middle_mco.paa";
		
		class clutter {
			class RaspSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wraspBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class BlueSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wblueBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class FernSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wfern.p3d";
				affectedByWind = 0.1;
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			
			class SnowPicea : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wpicea.p3d";
				affectedByWind = 0.0;
				scaleMin = 0.6;
				scaleMax = 1.3;
			};
		};
		
		class Subdivision {
			class Fractal {
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			
			class WhiteNoise {
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = 0.0;
			minSlope = 0.02;
		};
		
		class Ambient {
			class Mammals {
				radius = 200;
				cost = "(1 + forest + trees) * (0.5 + (0.5 * night)) * (1 - sea) * (1 - houses)";
				
				class Species {
					class Rabbit {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigBirds {
				radius = 300;
				cost = "((1 + forest + trees) - ((2 * rain)) - houses) * (1 - night) * (1 - sea)";
				
				class Species {
					class Hawk {
						probability = 0.1;
						cost = 1;
					};
				};
			};
			
			class Birds {
				radius = 170;
				cost = "(1 - night) * ((1 + (3 * sea)) - (2 * rain))";
				
				class Species {
					class Crow {
						probability = 0.1;
						cost = 1;
					};
				};
			};
			
			
		};

	class Names {
			class WThirsk_isl001 {
				name = "Thirsk";
				position[] = {1408, 3075};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl002 {
				name = "Taimenlahti";
				position[] = {3366, 1341};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl003 {
				name = "Itälahti";
				position[] = {4390, 2087};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl004 {
				name = "";
				position[] = {3648.75, 3940};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl005 {
				name = "";
				position[] = {1445, 3560};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl006 {
				name = "";
				position[] = {2610, 3638};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl007 {
				name = "";
				position[] = {811.25, 3388.75};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl008 {
				name = "";
				position[] = {3284, 2722};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl011 {
				name = "Siipilahti";
				position[] = {2098, 3093};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl012 {
				name = "гибель";
				position[] = {2879.17, 3243.96};
				type = "NameVillage";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl013 {
				name = "Eteläpato";
				position[] = {4078.99, 1662.73};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl014 {
				name = "Sudensuoja";
				position[] = {4131, 2670};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl015 {
				name = "Karhunhammas";
				position[] = {4026, 1206};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl016 {
				name = "Mansikkaniemi";
				position[] = {2286, 4658};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl017 {
				name = "Mustikkasaari";
				position[] = {3530, 4749};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl018 {
				name = "THIRSK";
				position[] = {1320.53, 2039.15};
				type = "NameCityCapital";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl019 {
				name = "Kuikin portti";
				position[] = {4006.25, 620.00};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl020 {
				name = "Vasarakarikko";
				position[] = {4721.48, 4816.55};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl021 {
				name = "Valliallas";
				position[] = {3700.77, 1641.78};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl022 {
				name = "";
				position[] = {3540.00, 675.00};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl023 {
				name = "Jafarinin kivi";
				position[] = {3159.42, 3627.25};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl024 {
				name = "Radiomäki";
				position[] = {4352.56, 1370.22};
				type = "Hill";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl025 {
				name = "Ilmarinen";
				position[] = {726.412, 562.765};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl026 {
				name = "";
				position[] = {4336, 1325};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl027 {
				name = "Vanha paloasema";
				position[] = {3972, 1386};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl028 {
				name = "Pieni Karhunhammas";
				position[] = {3510, 757};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl029 {
				name = "Potoskanlahti";
				position[] = {2019, 4352};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl030 {
				name = "Oikurin kallio";
				position[] = {2009, 4253};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl031 {
				name = "Malisen kallio";
				position[] = {2121, 3291};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl032 {
				name = "Pöyrynmäki";
				position[] = {3926, 3644};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl033 {
				name = "Ristikangas";
				position[] = {2556, 3829};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl034 {
				name = "";
				position[] = {2602, 3489};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl035 {
				name = "Välimetsä";
				position[] = {1392, 3583};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl036 {
				name = "";
				position[] = {1136, 4791};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl037 {
				name = "";
				position[] = {1213, 4474};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl038 {
				name = "";
				position[] = {2370, 4517};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl039 {
				name = "Ruosterinne";
				position[] = {615, 3698};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl040 {
				name = "Rocknoil";
				position[] = {664, 2419};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl041 {
				name = "";
				position[] = {964, 1978};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl042 {
				name = "Ykspihlaja";
				position[] = {1040, 4790};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl043 {
				name = "Hirvenpää";
				position[] = {2038, 1080};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl044 {
				name = "Kivipää";
				position[] = {454, 892};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl045 {
				name = "";
				position[] = {2915, 1810};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl046 {
				name = "Tuulensuoja";
				position[] = {1350, 4039};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl047 {
				name = "Etelälahti";
				position[] = {1386, 868};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl048 {
				name = "Elimyssalo";
				position[] = {3385, 3497};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl049 {
				name = "Ylämylly";
				position[] = {2732, 2099};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};
		};
	};
};

class CfgWorldList {
	class Thirsk {};
	class ThirskW {};
};

class CfgSurfaces {
	class Default {};
	
	class Water {};
	
	class THgrass2 : Default {
		access = 2;
		files = "nurmi_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "THPnurmi";
		soundHit = "soft_ground";
	};

	class THgrass3 : Default {
		access = 2;
		files = "heinikko_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "THPNurmi2";
		soundHit = "soft_ground";
	};
	
	class THForest1 : Default {
		access = ReadOnly;
		files = "metsa_*";
		rough = 0.11;
		dust = 0.2;
		soundEnviron = "grass";
		character = "THMetsa";
		soundHit = "soft_ground";
	};
	
	class THForest2 : Default {
		access = ReadOnly;
		files = "metsa2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "grass";
		character = "THMetsa2";
		soundHit = "soft_ground";
	};

	
	class THGrit1 : Default {
		access = ReadOnly;
		files = "kivi_*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};

	class THBetoni1 : Default {
		access = ReadOnly;
		files = "betoni_*";
		rough = 0.1;
		dust = 0.01;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THRock : Default {
		access = ReadOnly;
		files = "kivi2_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "snow";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THTarmac : Default {
		access = ReadOnly;
		files = "hiekka_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "tarmac";
		character = "Empty";
		soundHit = "hard_ground";
	};

	class THgrasW2 : Default {
		access = 2;
		files = "wnurmi_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "snow";
		character = "THPnurmW";
		soundHit = "soft_ground";
	};
	
	class THForesW1 : Default {
		access = 2;
		files = "wmetsa_*";
		rough = 0.5;
		dust = 0;
		soundEnviron = "snow";
		character = "THMetsW";
		soundHit = "soft_ground";
	};
	
	class THForesW2 : Default {
		access = 2;
		files = "wmetsa2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "snow";
		character = "THMetsW2";
		soundHit = "soft_ground";
	};
	
	class THGriW1 : Default {
		access = 2;
		files = "wbetoni_*";
		rough = 0.1;
		dust = 0;
		soundEnviron = "tarmac";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THRocW : Default {
		access = 2;
		files = "wkivi2_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THTarmaW : Default {
		access = 2;
		files = "whiekka_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "snow";
		character = "Empty";
		soundHit = "hard_ground";
	};
};

class CfgSurfaceCharacters {
	class THNurmi {
		probability[] = {0.78, 0.1, 0.06, 0.01, 0.05};
		names[] = {"GrassCrookedGreen", "GrassCrooked", "AutumnFlowers", "WeedDead", "SmallPicea"};
	};
	
	class THPnurmi {
		probability[] = {0.005, 0.1, 0.1, 0.3, 0.05};
		names[] = {"AutumnFlowers", "GrassCrooked", "GrassBunch", "GrassCrookedGreen", "RaspBerry"};
	};

	
	class THPnurmi2 {
		probability[] = {0.79, 0.1, 0.1, 0.01};
		names[] = {"GrassCrookedGreen", "GrassCrooked", "AutumnFlowers", "WeedDead"};
	};
	
	class THMetsa {
		probability[] = {0.55, 0.05, 0.15, 0.001, 0.003, 0.01, 0.2, 0.1};
		names[] = {"BlueBerry", "FernAutumn", "GrassCrooked", "MushroomsHorcak", "MushroomsPrasivka", "SmallPicea", "RaspBerry", "AutumnFlowers"};
	};
	
	class THMetsa2 {
		probability[] = {0.5, 0.3, 0.01, 0.4, 0.005, 0.008, 0.004};
		names[] = {"BlueBerry", "FernAutumn", "SmallPicea", "GrassCrooked", "MushroomsPrasivka", "MushroomsBabka", "MushroomsMuchomurka"};
	};
	
	class THKanerva {
		probability[] = {0.15, 0.5, 0.3, 0.1};
		names[] = {"BlueBerry", "HeatherBrush", "GrassCrooked", "WeedSedge"};
	};
	
	class THSekalainen {
		probability[] = {0.9, 0.01, 0.01, 0.005, 0.2};
		names[] = {"StubbleClutter", "AutumnFlowers", "WeedDeadSmall", "WeedDead", "SmallPicea"};
	};
	
	class THNurmW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THPnurmW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THNurmW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THPnurmW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THMetsW {
		probability[] = {0.001};
		names[] = {"SnowPicea"};
	};
	
	class THMetsW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THKanervW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THSekalaineW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
};
