/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define VSoft		0
#define VArmor		1
#define VAir		2

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

class CfgPatches {
	class newhaven {
		units[] = {"newhaven"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Data_F", "A3_Structures_F", "A3_Map_Data", "CABuildings", "CAbuildings2", "CAstructures", "CAMisc", "CAData"};
	};
};
class CfgMaterials
{
	class Water;
	class WaterRiver: Water
	{
		PixelShaderID="Water";
		VertexShaderID="Water";
		class Stage1
		{
			texture="A3\Map_Enoch\Data\water_nofhq.paa";
			uvSource="texWaterAnim";
			class uvTransform
			{
				aside[]={0,1,0};
				up[]={1,0,0};
				dir[]={0,0,1};
				pos[]={0.30000001,0.40000001,0};
			};
		};
		class Stage2
		{
			texture="A3\data_f\sea_foam_lco.paa";
			uvSource="none";
		};
		class Stage3
		{
			texture="A3\Map_Enoch\Data\water2_nohq.paa";
			uvSource="none";
		};
	};
};
class CfgLocationTypes {
	class Airport;	// External class reference
	
	class myairport : Airport {
		name = "CMC Airport";
		drawStyle = "icon";
		color[] = {1, 1, 1, 1};
		size = 32;
		textSize = 0.04;
		shadow = false;
		importance = 2;
		texture = "\newhaven\map_data_newhaven\icons\Airport32_ca.paa";
		font = "PuristaMedium";
	};
	class hospital;	// External class reference
	
	class myhosp : hospital {
		name = "Hospital";
		drawStyle = "icon";
		color[] = {1, 1, 1, 1};
		size = 32;
		textSize = 0.04;
		shadow = false;
		importance = 2;
		texture = "\newhaven\map_data_newhaven\icons\hosp32.paa";
		font = "PuristaMedium";
	};
};
class CfgWorlds
{
	initWorld = "newhaven";
	demoWorld = "newhaven";
	class DefaultLighting;

	class DefaultWorld
	{
		class Weather
		{
			class Overcast;
		};
		class WaterExPars;
	};
	class CAWorld : DefaultWorld
	{
		class Grid
		{
		};
		class DayLightingBrightAlmost;
		class DayLightingRainy;
		class DefaultClutter;
		class Weather: Weather
		{
			class Lighting;
			class Overcast: Overcast
			{
				class Weather1;
				class Weather2;
				class Weather3;
				class Weather4;
				class Weather5;
				class Weather6;
			};
		};
	};
	class newhaven : CAWorld 
	{
		access = ReadOnlyVerified;
		worldId = 1;
		cutscenes[] = {"newhavenIntro1"};
		description = "New Haven";
		icon = "";
		worldName = "\newhaven\newhaven.wrp";
		pictureMap = "\newhaven\picturemap_ca.paa";
		pictureShot = "\newhaven\ui_newhaven_ca.paa";
		plateFormat = "MH$-####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		author = "Aussie. Made Exclusively For Breaking Point.";
		mapSize = 10240;
		mapZone = 35;
		longitude = 17.352;	// positive is east
		latitude = -35.964;	// positive is south
		elevationOffset = 0;
		envTexture = "A3\Data_f\env_land_ca.tga";
		class OutsideTerrain {
			satellite = "newhaven\map_data_newhaven\s_satout_co.paa";
			enableTerrainSynth = 0;
			
			class Layers {
				class Layer0 {
					nopx = "A3\Map_Data\gdt_grass_green_nopx.paa";
					texture = "A3\Map_Data\gdt_grass_green_co.paa";
				};
			};
			colorOutside[] = {0.294118, 0.333333, 0.372549, 1};
		};		
		class Grid : Grid {
			offsetX = 0;
			offsetY = 10240;
			
			class Zoom1 {
				zoomMax = 0.02;
				format = "XY";
				formatX = 000;
				formatY = 000;
				stepX = 100;
				stepY = -100;
			};
			
			class Zoom2 {
				zoomMax = 0.95;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = -10000;
			};
		};
		startTime = 11:00;
		startDate = 10/6/2035;
		startWeather = 0.4;
		startFog = 0.0;
		forecastWeather = 0.3;
		forecastFog = 0.0;
		centerPosition[] = {5120, 5120, 700};
		seagullPos[] = {5120, 300, 5120};
		ilsPosition[] = {1531, 5019};
		ilsDirection[] = {-0.2588, 0.08, -0.9659};
		ilsTaxiOff[] = {};
		ilsTaxiIn[] = {};		
		class ReplaceObjects {};		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};		
		dynLightMinBrightnessAmbientCoef = 0.5;
		dynLightMinBrightnessAbsolute = 0.05;
		class Sea
		{
			seaTexture = "a3\data_f\seatexture_co.paa";
			seaMaterial = "#waterriver";
			shoreMaterial = "#shore";
			shoreFoamMaterial = "#shorefoam";
			shoreWetMaterial = "#shorewet";
			WaterMapScale = 20;
			WaterGrid = 50;
			MaxTide = 0;
			MaxWave = 0.25;
			SeaWaveXScale = "2.0/50";
			SeaWaveZScale = "1.0/50";
			SeaWaveHScale = 1;
			SeaWaveXDuration = 5000;
			SeaWaveZDuration = 10000;
		};
		class Underwater
		{
			noWaterFog = -0.001;
			fullWaterFog = 0.001;
			deepWaterFog = 60;
			waterFogDistanceNear = -10;
			waterFogDistance = 90;
			waterColor[] = {0,0.04,0.03};
			deepWaterColor[] = {0,0.001,0.009};
			surfaceColor[] = {0,0.04,0.03};
			deepSurfaceColor[] = {0,0.001,0.009};
		};
		class SeaWaterShaderPars
		{
			refractionMoveCoef = 0.03;
			minWaterOpacity = 0;
			waterOpacityDistCoef = 0.4;
			underwaterOpacity = 0.5;
			waterOpacityFadeStart = 60;
			waterOpacityFadeLength = 120;
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
		startFogBase=250;
		forecastFogBase=250;
		startFogDecay=0.017999999;
		forecastFogDecay=0.017999999;
		fogBeta0Min=0;
		fogBeta0Max=0.0049999999;
		skyColorInfluencesFogColor=0;
		hazeDistCoef=0.1;
		hazeFogCoef=0.98000002;
		fogHeight=2000;
		hazeBaseHeight=0;
		hazeBaseBeta0=0.00012;
		hazeDensityDecay=0.00060000003;
		aroundSunCoefMultiplier=1.38;
		aroundSunCoefExponent=8;
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
		class Lighting: DefaultLighting
		{
			groundReflection[]={0.059999999,0.059999999,0.029999999};
			moonObjectColorFull[]={360,340,300,100};
			moonHaloObjectColorFull[]={15,17,25,50};
			moonsetObjectColor[]={275,250,225,1};
			moonsetHaloObjectColor[]={10,10,10,0.25};
			class ThunderBoltLight
			{
				diffuse[]={2120,2170,8550};
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
			starEmissivity=40;
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
					height = 0;
					overcast = 0.25;
					sunAngle = -15;
					sunOrMoon = 0;
					diffuse[] = {{0.1,0.14,0.22},5};
					diffuseCloud[] = {0.1,0.1,0.2};
					ambient[] = {{0.52,0.67,1},2};
					ambientCloud[] = {0.52,0.67,1};
					ambientMid[] = {{0.572,0.67,0.9},0.5};
					ambientMidCloud[] = {0.572,0.67,0.9};
					groundReflection[] = {0.572,0.67,0.9};
					groundReflectionCloud[] = {0.572,0.67,0.9};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {0.0231,0.314,0.467};
					skyAroundSun[] = {{0.2,0.25,0.45},0.02};
					fogColor[] = {{0.09,0.137,0.22},0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.052,0.103};
					mie[] = {0.01,0.0075,0.005};
					cloudsColor[] = {{1,1,1},9};
					swBrightness = 3;
				};
				class Lighting1
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -4;
					sunOrMoon = 1;
					diffuse[] = {{0.09,0.09,0.1},1.5};
					diffuseCloud[] = {0.09,0.09,0.2};
					ambient[] = {{0.52,0.67,1},4};
					ambientCloud[] = {0.52,0.67,1};
					ambientMid[] = {{0.572,0.67,0.9},2};
					ambientMidCloud[] = {0.572,0.67,0.9};
					groundReflection[] = {0.572,0.67,0.9};
					groundReflectionCloud[] = {0.572,0.67,0.9};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {{0.1,0.15,0.3},4};
					skyAroundSun[] = {{0.4,0.3,0.3},9};
					fogColor[] = {{0.15,0.15,0.175},3};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.052,0.103};
					mie[] = {0.01,0.0075,0.005};
					cloudsColor[] = {{1,1,1},9};
					swBrightness = 3;
				};
				class Lighting2
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.8,0.4,0.18},5};
					diffuseCloud[] = {{1,0.35,0.34},2};
					ambient[] = {{0.7,0.5,0.5},7.75};
					ambientCloud[] = {{0.6,0.5,0.5},1};
					ambientMid[] = {{0.55,0.6,0.8},6.5};
					ambientMidCloud[] = {{0.55,0.6,0.8},0.5};
					groundReflection[] = {{0.55,0.6,0.8},6.5};
					groundReflectionCloud[] = {{0.55,0.6,0.9},0.25};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.2,0.4},6};
					skyAroundSun[] = {{0.25,0.1,0.03},11};
					fogColor[] = {{0.15,0.15,0.175},5.5};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 25;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.5,0.5};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.7,0.7,0.7},9};
					swBrightness = 2;
				};
				class Lighting3
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{0.9,0.4,0.16},8};
					diffuseCloud[] = {{0.8,0.4,0.16},9};
					ambient[] = {{0.5,0.39,0.35},9};
					ambientCloud[] = {{0.5,0.39,0.35},9};
					ambientMid[] = {{0.55,0.5,0.45},8.1};
					ambientMidCloud[] = {{0.55,0.5,0.45},7.7};
					groundReflection[] = {{0.55,0.5,0.45},7.1};
					groundReflectionCloud[] = {{0.55,0.5,0.5},6.5};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.25,0.4},10.5};
					skyAroundSun[] = {{0.3,0.2,0.1},12};
					fogColor[] = {{0.15,0.135,0.13},7};
					apertureMin = 9;
					apertureStandard = 13;
					apertureMax = 30;
					standardAvgLum = 75;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.12,0.05,0.05};
					mie[] = {0.003,0.002,0.003};
					cloudsColor[] = {{0.2,0.2,0.2},11};
					swBrightness = 1;
				};
				class Lighting4
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{1,0.5,0.26},10.25};
					diffuseCloud[] = {{1,0.45,0.26},10.25};
					ambient[] = {{0.55,0.4,0.35},9.8};
					ambientCloud[] = {{0.6,0.4,0.4},9.8};
					ambientMid[] = {{0.55,0.5,0.45},8.3};
					ambientMidCloud[] = {{0.55,0.5,0.5},8};
					groundReflection[] = {{0.55,0.5,0.45},7.75};
					groundReflectionCloud[] = {{0.6,0.65,0.768},7};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.3,0.7},10.5};
					skyAroundSun[] = {{0.15,0.2,0.2},12};
					fogColor[] = {{0.125,0.13,0.14},8.2};
					apertureMin = 10;
					apertureStandard = 15;
					apertureMax = 40;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.06,0.1,0.09};
					mie[] = {0.002,0.002,0.002};
					cloudsColor[] = {{0.2,0.2,0.15},11};
					swBrightness = 1;
				};
				class Lighting5
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 15;
					sunOrMoon = 1;
					diffuse[] = {{1,0.63,0.4},12};
					diffuseCloud[] = {{1,0.63,0.4},11.5};
					ambient[] = {{0.6,0.6,0.6},10.75};
					ambientCloud[] = {{0.57,0.6,0.7},10.75};
					ambientMid[] = {{0.57,0.5,0.51},9.2};
					ambientMidCloud[] = {{0.57,0.5,0.51},9};
					groundReflection[] = {{0.57,0.5,0.51},9};
					groundReflectionCloud[] = {{0.57,0.612,0.7},8.3};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.33,0.8},10.75};
					skyAroundSun[] = {{0.1,0.3,0.6},12};
					fogColor[] = {{0.11,0.125,0.14},9.75};
					apertureMin = 18;
					apertureStandard = 20;
					apertureMax = 55;
					standardAvgLum = 175;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.1,0.13,0.2};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.5,0.5,0.3},11};
					swBrightness = 1;
				};
				class Lighting6
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 22;
					sunOrMoon = 1;
					diffuse[] = {{1,0.75,0.55},12.4};
					diffuseCloud[] = {{1,0.75,0.55},12.1};
					ambient[] = {{0.58,0.59,0.63},11};
					ambientCloud[] = {{0.57,0.58,0.63},11};
					ambientMid[] = {{0.58,0.51,0.48},10.2};
					ambientMidCloud[] = {{0.57,0.522,0.56},10};
					groundReflection[] = {{0.58,0.51,0.48},10};
					groundReflectionCloud[] = {{0.57,0.522,0.56},9.9};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.28,0.95},11};
					skyAroundSun[] = {{0.1,0.28,0.8},12};
					fogColor[] = {{0.105,0.13,0.17},10};
					apertureMin = 20;
					apertureStandard = 22;
					apertureMax = 55;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,0.9,0.7},11};
					swBrightness = 1;
				};
				class Lighting7
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{1,0.8,0.65},13.75};
					diffuseCloud[] = {{1,0.8,0.65},13.5};
					ambient[] = {{0.58,0.59,0.68},11.75};
					ambientCloud[] = {{0.57,0.59,0.68},11.7};
					ambientMid[] = {{0.58,0.531,0.476},11};
					ambientMidCloud[] = {{0.57,0.522,0.56},11};
					groundReflection[] = {{0.58,0.531,0.476},10.5};
					groundReflectionCloud[] = {{0.57,0.522,0.56},10.5};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.075,0.2,1},12};
					skyAroundSun[] = {{0.075,0.23,1},12.5};
					fogColor[] = {{0.105,0.14,0.2},11.2};
					apertureMin = 28;
					apertureStandard = 35;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,0.9,0.7},12};
					swBrightness = 1;
				};
				class Lighting8
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 40;
					sunOrMoon = 1;
					diffuse[] = {{1,0.8,0.66},14};
					diffuseCloud[] = {{1,0.8,0.66},13.7};
					ambient[] = {{0.57,0.58,0.7},12.1};
					ambientCloud[] = {{0.57,0.58,0.7},12};
					ambientMid[] = {{0.57,0.522,0.49},12.1};
					ambientMidCloud[] = {{0.57,0.522,0.56},12};
					groundReflection[] = {{0.57,0.522,0.49},11.2};
					groundReflectionCloud[] = {{0.57,0.522,0.56},11};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.075,0.22,1},13};
					skyAroundSun[] = {{0.075,0.22,1},13};
					fogColor[] = {{0.105,0.145,0.2},11.5};
					apertureMin = 33;
					apertureStandard = 36;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,0.9,0.7},12};
					swBrightness = 1;
				};
				class Lighting9
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -15;
					sunOrMoon = 0;
					diffuse[] = {{0.1,0.13,0.2},5};
					diffuseCloud[] = {{0,0,0},5};
					ambient[] = {{0.52,0.67,1},2};
					ambientCloud[] = {{1,1,1},2};
					ambientMid[] = {{0.572,0.67,0.9},1};
					ambientMidCloud[] = {{0.572,0.67,0.9},0.1};
					groundReflection[] = {{0.572,0.67,0.9},0.1};
					groundReflectionCloud[] = {{0.572,0.67,0.9},0.1};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {0.0231,0.314,0.467};
					skyAroundSun[] = {{0.2,0.25,0.45},0.02};
					fogColor[] = {{0.09,0.137,0.22},0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.052,0.103};
					mie[] = {0.01,0.0075,0.005};
					cloudsColor[] = {{1,1,1},4};
					swBrightness = 3;
				};
				class Lighting10
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -4;
					sunOrMoon = 1;
					diffuse[] = {{0.09,0.09,0.2},1};
					diffuseCloud[] = {0,0,0};
					ambient[] = {{0.52,0.67,1},3};
					ambientCloud[] = {1,1,1};
					ambientMid[] = {{0.572,0.67,0.9},2};
					ambientMidCloud[] = {0.572,0.67,0.9};
					groundReflection[] = {0.572,0.67,0.9};
					groundReflectionCloud[] = {0.572,0.67,0.9};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {{0.1,0.15,0.3},4};
					skyAroundSun[] = {{0.5,0.3,0.2},8};
					fogColor[] = {{0.15,0.15,0.175},2};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.052,0.103};
					mie[] = {0.01,0.0075,0.005};
					cloudsColor[] = {{1,1,1},4};
					swBrightness = 3;
				};
				class Lighting11
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.9,0.35,0.075},4};
					diffuseCloud[] = {0.9,0.35,0.075};
					ambient[] = {{0.7,0.6,0.6},7};
					ambientCloud[] = {{1,1,1},1};
					ambientMid[] = {{0.55,0.6,0.9},4.5};
					ambientMidCloud[] = {{0.55,0.6,0.9},0.5};
					groundReflection[] = {{0.55,0.6,0.8},3};
					groundReflectionCloud[] = {{0.55,0.6,0.8},0.25};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.2,0.5},6};
					skyAroundSun[] = {{0.5,0.15,0},10};
					fogColor[] = {{0.15,0.15,0.175},5};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 25;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.05,0.12,0.17};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.7,0.7,0.7},4};
					swBrightness = 2;
				};
				class Lighting12
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{0.9,0.35,0.1},8};
					diffuseCloud[] = {{0.9,0.3,0.05},4};
					ambient[] = {{0.3,0.23,0.2},8.7};
					ambientCloud[] = {{0.3,0.23,0.2},8.7};
					ambientMid[] = {{0.55,0.5,0.5},8};
					ambientMidCloud[] = {{0.55,0.5,0.5},7.5};
					groundReflection[] = {{0.55,0.5,0.5},7};
					groundReflectionCloud[] = {{0.55,0.5,0.5},6.5};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.2,0.3,0.4},9.5};
					skyAroundSun[] = {{0.5,0.2,0.05},11.5};
					fogColor[] = {{0.15,0.13,0.12},6.5};
					apertureMin = 9;
					apertureStandard = 13;
					apertureMax = 30;
					standardAvgLum = 75;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.05,0.06,0.17};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.25,0.25,0.2},8};
					swBrightness = 1;
				};
				class Lighting13
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{1,0.45,0.16},10.25};
					diffuseCloud[] = {{1,0.45,0.16},6};
					ambient[] = {{0.7,0.67,0.68},10};
					ambientCloud[] = {{0.7,0.67,0.68},9.6};
					ambientMid[] = {{0.65,0.6,0.6},9.2};
					ambientMidCloud[] = {{0.65,0.6,0.6},9};
					groundReflection[] = {{0.65,0.6,0.6},9};
					groundReflectionCloud[] = {{0.65,0.6,0.6},8.6};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.13,0.3,0.5},11};
					skyAroundSun[] = {{0.5,0.23,0.1},12.5};
					fogColor[] = {{0.13,0.125,0.11},7.5};
					apertureMin = 10;
					apertureStandard = 15;
					apertureMax = 40;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.06,0.09,0.09};
					mie[] = {0.002,0.002,0.002};
					cloudsColor[] = {{0.25,0.25,0.2},8.5};
					swBrightness = 1;
				};
				class Lighting14
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 15;
					sunOrMoon = 1;
					diffuse[] = {{1,0.675,0.45},12};
					diffuseCloud[] = {{1,0.7,0.45},8};
					ambient[] = {{0.65,0.612,0.7},10.8};
					ambientCloud[] = {{0.65,0.612,0.72},10.9};
					ambientMid[] = {{0.57,0.55,0.6},9.5};
					ambientMidCloud[] = {{0.57,0.55,0.62},9.5};
					groundReflection[] = {{0.57,0.55,0.6},9.3};
					groundReflectionCloud[] = {{0.57,0.612,0.7},8.3};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.3,0.55},11.5};
					skyAroundSun[] = {{0.2,0.3,0.35},12};
					fogColor[] = {{0.125,0.13,0.135},9.75};
					apertureMin = 18;
					apertureStandard = 20;
					apertureMax = 55;
					standardAvgLum = 175;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.09,0.1,0.1};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.25,0.25,0.2},9};
					swBrightness = 1;
				};
				class Lighting15
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 22;
					sunOrMoon = 1;
					diffuse[] = {{1,0.75,0.6},12.4};
					diffuseCloud[] = {{1,0.75,0.68},11};
					ambient[] = {{0.57,0.58,0.63},11.1};
					ambientCloud[] = {{0.57,0.58,0.65},11};
					ambientMid[] = {{0.57,0.522,0.56},10.4};
					ambientMidCloud[] = {{0.57,0.522,0.56},10.3};
					groundReflection[] = {{0.57,0.522,0.56},10};
					groundReflectionCloud[] = {{0.5,0.5,0.5},9.2};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.11,0.3,0.65};
					skyAroundSun[] = {{0.11,0.3,0.65},11.7};
					fogColor[] = {{0.105,0.13,0.18},10};
					apertureMin = 20;
					apertureStandard = 22;
					apertureMax = 55;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.001,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,0.8},10.5};
					swBrightness = 1;
				};
				class Lighting16
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{1,0.8,0.65},13.75};
					diffuseCloud[] = {{1,0.8,0.65},11.8};
					ambient[] = {{0.57,0.58,0.68},11.8};
					ambientCloud[] = {{0.57,0.58,0.68},11.9};
					ambientMid[] = {{0.57,0.522,0.5},11.3};
					ambientMidCloud[] = {{0.57,0.522,0.5},11.1};
					groundReflection[] = {{0.57,0.522,0.5},10.5};
					groundReflectionCloud[] = {{0.5,0.5,0.5},9.3};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.3,0.8},12};
					skyAroundSun[] = {{0.11,0.3,0.8},12.2};
					fogColor[] = {{0.105,0.13,0.17},10.75};
					apertureMin = 28;
					apertureStandard = 35;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.001,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,0.8},11};
					swBrightness = 1;
				};
				class Lighting17
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 40;
					sunOrMoon = 1;
					diffuse[] = {{1,0.8,0.66},14.1};
					diffuseCloud[] = {{1,0.8,0.66},12.2};
					ambient[] = {{0.57,0.58,0.7},12.1};
					ambientCloud[] = {{0.57,0.58,0.7},12};
					ambientMid[] = {{0.57,0.522,0.56},11.8};
					ambientMidCloud[] = {{0.57,0.522,0.56},11.6};
					groundReflection[] = {{0.57,0.522,0.56},11.2};
					groundReflectionCloud[] = {{0.5,0.5,0.5},11};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.3,1},13};
					skyAroundSun[] = {{0.11,0.3,1},13};
					fogColor[] = {{0.105,0.145,0.2},11.2};
					apertureMin = 33;
					apertureStandard = 36;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.001,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,0.8},12};
					swBrightness = 1;
				};
				class Lighting18
				{
					height = 0;
					overcast = 0.8;
					sunAngle = -15;
					sunOrMoon = 0;
					diffuse[] = {0.1,0.13,0.2};
					diffuseCloud[] = {0,0,0};
					ambient[] = {{0.52,0.67,1},0.05};
					ambientCloud[] = {1,1,1};
					ambientMid[] = {{0.572,0.67,0.9},0.01};
					ambientMidCloud[] = {1,1,1};
					groundReflection[] = {0.572,0.67,0.9};
					groundReflectionCloud[] = {1,1,1};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {0.0231,0.314,0.467};
					skyAroundSun[] = {{0.2,0.25,0.45},0.02};
					fogColor[] = {0.09,0.137,0.22};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.052,0.103};
					mie[] = {0.01,0.0075,0.005};
					cloudsColor[] = {{1,1,1},3};
					swBrightness = 3;
				};
				class Lighting19
				{
					height = 0;
					overcast = 0.8;
					sunAngle = -4;
					sunOrMoon = 1;
					diffuse[] = {0.2,0.2,0.2};
					diffuseCloud[] = {0,0,0};
					ambient[] = {{0.5,0.55,1},2};
					ambientCloud[] = {1,1,1};
					ambientMid[] = {{0.55,0.55,0.85},2};
					ambientMidCloud[] = {1,1,1};
					groundReflection[] = {0.55,0.55,0.85};
					groundReflectionCloud[] = {1,1,1};
					bidirect[] = {0.09,0.09,0.09};
					bidirectCloud[] = {0.09,0.09,0.09};
					sky[] = {{0.1,0.3,0.7},3};
					skyAroundSun[] = {{0.2,0.3,0.6},7};
					fogColor[] = {0.08,0.08,0.095};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 9;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.5,0.5,0.5};
					mie[] = {0.05,0.05,0.05};
					cloudsColor[] = {{0.1,0.1,0.1},3};
					swBrightness = 3;
				};
				class Lighting20
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.375,0.225,0.04},0.05};
					diffuseCloud[] = {{1,1,1},0.05};
					ambient[] = {{0.5,0.5,0.6},2.5};
					ambientCloud[] = {{1,1,1},1};
					ambientMid[] = {{0.55,0.5,0.8},2};
					ambientMidCloud[] = {{1,1,1},0.5};
					groundReflection[] = {{0.55,0.5,0.8},0.25};
					groundReflectionCloud[] = {{1,1,1},0.25};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},1};
					skyAroundSun[] = {{0.2,0.25,0.3},1};
					fogColor[] = {{0.08,0.08,0.095},0.25};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 25;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.5,0.5,0.5};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.45,0.22,0.15},3};
					swBrightness = 2;
				};
				class Lighting21
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{0.1,0.1,0.1},0.1};
					diffuseCloud[] = {{1,1,1},0.005};
					ambient[] = {{0.6,0.6,0.75},8.2};
					ambientCloud[] = {{1,1,1},8};
					ambientMid[] = {{0.55,0.5,0.62},7.2};
					ambientMidCloud[] = {{1,1,1},7};
					groundReflection[] = {{0.55,0.5,0.62},6.5};
					groundReflectionCloud[] = {{1,1,1},6};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},9};
					skyAroundSun[] = {{0.2,0.2,0.3},10};
					fogColor[] = {{0.125,0.125,0.14},7.5};
					apertureMin = 9;
					apertureStandard = 13;
					apertureMax = 30;
					standardAvgLum = 75;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.5,0.5,0.3};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.45,0.3,0.15},3};
					swBrightness = 1;
				};
				class Lighting22
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{0.3,0.3,0.35},0.75};
					diffuseCloud[] = {{1,1,1},1};
					ambient[] = {{0.65,0.65,0.8},9};
					ambientCloud[] = {{1,1,1},9};
					ambientMid[] = {{0.57,0.5,0.62},8};
					ambientMidCloud[] = {{1,1,1},7.8};
					groundReflection[] = {{0.57,0.5,0.62},7.8};
					groundReflectionCloud[] = {{1,1,1},7.6};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},10};
					skyAroundSun[] = {{0.16,0.18,0.2},10};
					fogColor[] = {{0.125,0.125,0.15},8};
					apertureMin = 10;
					apertureStandard = 15;
					apertureMax = 40;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.5,0.5,0.3};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.6,0.3,0.15},5};
					swBrightness = 1;
				};
				class Lighting23
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 15;
					sunOrMoon = 1;
					diffuse[] = {{0.32,0.3,0.35},1};
					diffuseCloud[] = {{0.1,0.1,0.1},2};
					ambient[] = {{0.7,0.7,0.8},10};
					ambientCloud[] = {{1,1,1},10};
					ambientMid[] = {{0.57,0.5,0.6},9.3};
					ambientMidCloud[] = {{1,1,1},9};
					groundReflection[] = {{0.57,0.5,0.6},8.8};
					groundReflectionCloud[] = {{1,1,1},8.6};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},10.8};
					skyAroundSun[] = {{0.16,0.18,0.2},11.4};
					fogColor[] = {{0.3,0.34,0.44},9};
					apertureMin = 18;
					apertureStandard = 20;
					apertureMax = 55;
					standardAvgLum = 175;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.75,0.6,0.4},5};
					swBrightness = 1;
				};
				class Lighting24
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 22;
					sunOrMoon = 1;
					diffuse[] = {{0.8,0.8,0.8},3.5};
					diffuseCloud[] = {{0.1,0.1,0.1},2.5};
					ambient[] = {{0.7,0.7,0.8},11};
					ambientCloud[] = {{1,1,1},10.8};
					ambientMid[] = {{0.57,0.5,0.57},10};
					ambientMidCloud[] = {{1,1,1},9.8};
					groundReflection[] = {{0.57,0.5,0.57},9.8};
					groundReflectionCloud[] = {{1,1,1},9.6};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},12.6};
					skyAroundSun[] = {{0.11,0.145,0.19},12.6};
					fogColor[] = {{0.105,0.12,0.16},10};
					apertureMin = 20;
					apertureStandard = 22;
					apertureMax = 55;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.9,1,1},6};
					swBrightness = 1;
				};
				class Lighting25
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{0.8,0.8,0.8},9.8};
					diffuseCloud[] = {{0.1,0.1,0.1},6};
					ambient[] = {{0.7,0.7,0.8},11.5};
					ambientCloud[] = {{1,1,1},11.2};
					ambientMid[] = {{0.57,0.5,0.57},11};
					ambientMidCloud[] = {{1,1,1},10.5};
					groundReflection[] = {{0.57,0.5,0.57},10};
					groundReflectionCloud[] = {{1,1,1},9.5};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},13};
					skyAroundSun[] = {{0.11,0.145,0.188},13};
					fogColor[] = {{0.105,0.12,0.16},10.75};
					apertureMin = 28;
					apertureStandard = 35;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.9,1,1},6};
					swBrightness = 1;
				};
				class Lighting26
				{
					height = 0;
					overcast = 0.8;
					sunAngle = 40;
					sunOrMoon = 1;
					diffuse[] = {{0.8,0.8,0.8},10};
					diffuseCloud[] = {{0.1,0.1,0.1},6};
					ambient[] = {{0.7,0.65,0.8},12.5};
					ambientCloud[] = {{1,1,1},12};
					ambientMid[] = {{0.57,0.55,0.57},11.5};
					ambientMidCloud[] = {{1,1,1},11};
					groundReflection[] = {{0.57,0.5,0.57},11};
					groundReflectionCloud[] = {{1,1,1},10};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.11,0.15,0.2},13};
					skyAroundSun[] = {{0.11,0.145,0.188},13};
					fogColor[] = {{0.105,0.12,0.16},11.5};
					apertureMin = 33;
					apertureStandard = 36;
					apertureMax = 60;
					standardAvgLum = 500;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.00759,0.01388,0.02878};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.9,1,1},7};
					swBrightness = 1;
				};
			};
			class Lighting: Lighting
			{
				class BrightAlmost: DayLightingBrightAlmost
				{
					overcast = 0;
				};
				class Rainy: DayLightingRainy
				{
					overcast = 1;
				};
			};
			class Overcast: Overcast
			{
				class Weather1: Weather1
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_clear_horizont_sky.paa";
				};
				class Weather2: Weather2
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_clear_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_almostclear_horizont_sky.paa";
				};
				class Weather3: Weather3
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_semicloudy_horizont_sky.paa";
				};
				class Weather4: Weather4
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_cloudy_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_cloudy_horizont_sky.paa";
				};
				class Weather5: Weather5
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_mostlycloudy_horizont_sky.paa";
				};
				class Weather6: Weather6
				{
					sky="A3\Map_Enoch\Data\sky_clear_sky.paa";
					skyR="A3\Map_Enoch\Data\sky_overcast_lco.paa";
					horizon="A3\Map_Enoch\Data\sky_overcast_horizont_sky.paa";
				};
			};
		};
		humidityUpCoef = 0.1;
		humidityDownCoef = 0.05;
		class SimulWeather
		{
			noiseTexture = "a3\data_f\noise_raw.paa";
			numKeyframesPerDay = 48;
			windSpeedCoef = "10.0f";
			moonIrradianceCoef = "10.0f";
			fadeMaxDistanceKm = 1000;
			fadeMaxAltitudeKm = 15;
			fadeNumAltitudes = 8;
			fadeNumElevations = 8;
			fadeNumDistances = 8;
			fadeEarthTest = 1;
			autoBrightness = 1;
			autoBrightnessStrength = 0.1;
			cloudGridWidth = 64;
			cloudGridLength = 64;
			cloudGridHeight = 16;
			helperGridElevationSteps = 24;
			helperGridAzimuthSteps = 15;
			helperEffectiveEarthRadius = 1e+06;
			helperCurvedEarth = 1;
			helperAdjustCurvature = 0;
			helperNumLayers = 120;
			helperMaxDistance = 160000;
			helperNearCloudFade = 0.1;
			helperChurn = 10;
			cloudWidth = 40000;
			cloudLength = 40000;
			wrapClouds = 1;
			noiseResolution = 8;
			noisePeriod = 4;
			opticalDensity = 1.5;
			alphaSharpness = 0.85;
			selfShadowScale = 0.905;
			mieAsymmetry = 0.5087;
			minimumLightElevationDegrees = 6;
			directLightCoef = 1;
			indirectLightCoef = 0.04;
			fogStart = 0;
			fogEnd = 50000;
			fogHeight = 2000;
			class DefaultKeyframe
			{
				rayleigh[] = {0.00749,0.01388,0.02878};
				mie[] = {0.0046,0.0046,0.0046};
				haze = 30;
				hazeBaseKm = 5;
				hazeScaleKm = 1;
				hazeEccentricity = 1;
				brightnessAdjustment = 1;
				cloudiness = 0.6;
				cloudBaseKm = 2.85;
				cloudHeightKm = 6;
				directLight = 1;
				indirectLight = 1;
				ambientLight = 0.2;
				noiseOctaves = 4.3;
				noisePersistence = 0.535;
				fractalAmplitude = 2.3;
				fractalWavelength = 240;
				extinction = 8;
				diffusivity = 0.001;
			};
			class Overcast
			{
				class Weather1: DefaultKeyframe
				{
					overcast = 0;
					cloudiness = 0;
					diffusivity = 0.001;
					seqFileKeyframe = 0;
				};
				class Weather2: DefaultKeyframe
				{
					overcast = 0.2;
					cloudiness = 0.25;
					diffusivity = 0.001;
					seqFileKeyframe = 0;
				};
				class Weather3: DefaultKeyframe
				{
					overcast = 0.4;
					cloudiness = 0.45;
					diffusivity = 0.001;
					seqFileKeyframe = 3;
				};
				class Weather4: DefaultKeyframe
				{
					overcast = 0.5;
					cloudiness = 0.46;
					diffusivity = 0.01;
					seqFileKeyframe = 4;
				};
				class Weather5: DefaultKeyframe
				{
					overcast = 0.8;
					cloudiness = 0.8;
					diffusivity = 0.01;
					extinction = 4.3;
					cloudBaseKm = 1.9;
					cloudHeightKm = 8;
					seqFileKeyframe = 4;
				};
				class Weather6: DefaultKeyframe
				{
					overcast = 1;
					cloudiness = 1;
					diffusivity = 0.001;
					extinction = 4;
					cloudBaseKm = 1.7;
					cloudHeightKm = 10;
					seqFileKeyframe = 4;
				};
			};
		};
		skyObject = "A3\Map_Enoch\Data\skydome.p3d";
		horizontObject = "A3\Map_Enoch\Data\horizon.p3d";
		skyTexture = "A3\Map_Enoch\Data\sky_semicloudy_sky.paa";
		skyTextureR = "A3\Map_Enoch\Data\sky_semicloudy_lco.paa";
		terrainBlendMaxDarkenCoef = 1;
		terrainBlendMaxBrightenCoef = 0;
		clutterGrid = 0.8;
		clutterDist = 100;
		noDetailDist = 50;
		fullDetailDist = 10;
		midDetailTexture = "A3\Map_Data\middle_mco.paa";
		minTreesInForestSquare = 3;
		minRocksInRockSquare = 3;
		class clutter {
			class bp_grassgreen : DefaultClutter {
				model="A3\plants_f\Clutter\c_StrGrassGreen_group.p3d";
				affectedByWind=0.60000002;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=1;
			};
			
			class bp_grassbunch : DefaultClutter {
				model="A3\Vegetation_F_Exp\Clutter\Grass\c_GrassBunch_HI.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.80000001;
				scaleMax=1.3;
			};
			
			class bp_grasstall : DefaultClutter {
				model = "a3\plants_f\Clutter\C_grasstall.p3d";
				affectedByWind = 0.8;
				swLighting = "true";
				scaleMin = 0.9;
				scaleMax = 1.2;
			};
			
			class bp_fernsmall : DefaultClutter {
				model="A3\Vegetation_F_Enoch\Clutter\c_fern.p3d";
				affectedByWind=0.1;
				swLighting=0;
				scaleMin=0.80000001;
				scaleMax=1.2;
			};
			
			class bp_ferntall : DefaultClutter {
				model="A3\Vegetation_F_Enoch\Clutter\c_fernTall.p3d";
				affectedByWind=0.2;
				swLighting=0;
				scaleMin=0.69999999;
				scaleMax=1;
			};
			
			class bp_wideleafplant : DefaultClutter {
				model = "ca\plants2\clutter\c_wideleafplant.p3d";
				affectedByWind = 0.1;
				swLighting = 1;
				scaleMin = 0.65;
				scaleMax = 1;
			};
			
			class bp_weed2 : DefaultClutter {
				model = "ca\plants2\clutter\C_weed2.p3d";
				affectedByWind = 0.5;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 1.1;
			};
			
			class bp_weed3 : DefaultClutter {
				model = "ca\plants2\clutter\C_weed3.p3d";
				affectedByWind = 0.5;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 1.1;
			};
			
			class bp_mushroom : DefaultClutter {
				model = "ca\plants2\clutter\c_MushroomBabka.p3d";
				affectedByWind = 0.1;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 1.2;
			};
			
			class bp_smallpinetree : DefaultClutter {
				model = "ca\plants2\clutter\c_picea.p3d";
				affectedByWind = 0.5;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 2.1;
			};
			
			class bp_Stubble : DefaultClutter {
				model="A3\Vegetation_F_Enoch\Clutter\c_weat.p3d";
				affectedByWind=0.5;
				swLighting=0;
				scaleMin=0.89999998;
				scaleMax=1.3;
			};

			class bp_StubbleTall : DefaultClutter {
				model="A3\Vegetation_F_Enoch\Clutter\c_weatTall.p3d";
				affectedByWind=0.5;
				swLighting=0;
				scaleMin=0.89999998;
				scaleMax=1.3;
			};
			
			class bp_GrassCrookedForest : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrookedForest.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.8;
				scaleMax = 1.4;
			};
			
			class bp_WeedDead : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.75;
				scaleMax = 1.1;
			};
			
			class bp_WeedDeadSmall : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead2.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.75;
				scaleMax = 0.9;
			};
			
			class bp_GrassCrooked : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrooked.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_desertgrass : DefaultClutter {
				model = "ca\plants\clutter_grass_desert.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_deadgrassbunch : DefaultClutter {
				model = "ca\plants2\clutter\c_deadGrassBunch.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_WeedBrownTallgroup : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrWeedBrownTall_group.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_thistlesmall : DefaultClutter {
				model = "a3\plants_f\Clutter\c_Thistle_Small.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_grassdryC : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrGrassDry.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_GrassDrygroup : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrGrassDry_group.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_GrassDrymediumgroup : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrGrassDryMedium_group.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_weedgreentall : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrWeedGreenTall.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_ThistleYellowShrub : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrThistleYellowShrub.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_mullein : DefaultClutter {
				model = "a3\plants_f\Clutter\c_StrPlantMullein.p3d";
				affectedByWind = 0.3;
				swLighting = "true";
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class bp_GrassBrushHighGreen : DefaultClutter {
				model = "A3\plants_f\Clutter\c_Grass_BrushHigh_Green.p3d";
				affectedByWind = 0.8;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.7;
			};
			
			class bp_GrassDry : DefaultClutter {
				model = "A3\plants_f\Clutter\c_Grass_Dry.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.3;
				scaleMax = 0.9;
			};
			
			class bp_ThistleHigh : DefaultClutter {
				model = "A3\plants_f\Clutter\c_Thistle_High.p3d";
				affectedByWind = 0.6;
				swLighting = "true";
				scaleMin = 0.6;
				scaleMax = 1.0;
			};
			
			class bp_GrassDesertGroupSoft : DefaultClutter {
				model = "A3\plants_f\Clutter\c_GrassGreen_GroupSoft.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.6;
				scaleMax = 1.1;
			};
			
			class bp_grasstalldead : DefaultClutter {
				model = "a3\plants_f\clutter\c_Grass_Tall_Dead.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.55;
				scaleMax = 0.78;
			};
			
			class bp_flowertansy : DefaultClutter {
				model = "a3\plants_f\clutter\c_Flower_Tansy.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.45;
				scaleMax = 0.6;
			};
			
			class bp_grassautummbrown : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassAutumnBrown.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.35;
				scaleMax = 0.6;
			};
			
			class bp_grassbunchsmall : DefaultClutter {
				model="A3\Vegetation_F_Exp\Clutter\Grass\c_GrassBunch_LO.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.64999998;
				scaleMax=1.4;
			};
			
			class bp_plantdoc : DefaultClutter {
				model = "a3\plants_f\clutter\c_Plant_Dock.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.45;
				scaleMax = 0.65;
			};
			
			class bp_grassdry_group : DefaultClutter {
				model = "a3\plants_f\clutter\c_StrGrassDry_group.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 1.0;
				scaleMax = 1.5;
			};
			
			class bp_greengrass : DefaultClutter {
				model = "a3\plants_f\clutter\c_Grass_Green.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.7;
			};
			
			class bp_Flower_BrushMedium_Blue : DefaultClutter {
				model = "a3\plants_f\clutter\c_Flower_BrushMedium_Blue.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.85;
			};
			
			class bp_wideleaf : DefaultClutter {
				model = "ca\plants2\clutter\c_wideLeafPlant.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.65;
			};
			
			class bp_GrassGreen_GroupHard : DefaultClutter {
				model = "a3\plants_f\clutter\c_GrassGreen_GroupHard.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.65;
			};
			
			class bp_grasslong_drybunch : DefaultClutter {
				model = "a3\plants_f\clutter\c_GrassLong_DryBunch.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.65;
			};
			
			class bp_PlantGreenShrub : DefaultClutter {
				model = "a3\plants_f\clutter\c_StrPlantGreenShrub.p3d";
				affectedByWind = 1.0;
				swLighting = "true";
				scaleMin = 0.5;
				scaleMax = 0.65;
			};
			
			class bp_GrassGreenGroup : DefaultClutter {
				model = "A3\plants_f\Clutter\c_StrGrassGreen_group.p3d";
				affectedByWind = 0.6;
				swLighting = "true";
				scaleMin = 0.7;
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
		class Ambient {};
		
		class AmbientA3 {
			maxCost = 500;
			
			class Radius440_500 {
				areaSpawnRadius = 440.0;
				areaMaxRadius = 500.0;
				spawnCircleRadius = 30.0;
				spawnInterval = 4.7;
				
				class Species {
					class Seagull {
						maxCircleCount = "((sea * (1 - night)) + (2 * houses * sea)) * (1 - night)";
						maxWorldCount = 18;
						cost = 3;
						spawnCount = 1;
						groupSpawnRadius = 10;
						maxAlt = 100;
						minAlt = -10;
					};
					
					class Rabbit_F {
						maxCircleCount = "(20 * (0.1 - houses)) * (1 - sea)";
						maxWorldCount = 4;
						cost = 5;
						spawnCount = 1;
						groupSpawnRadius = 10;
						maxAlt = 80;
						minAlt = -5;
					};
				};
			};
			
			class Radius40_60 {
				areaSpawnRadius = 40.0;
				areaMaxRadius = 60.0;
				spawnCircleRadius = 10.0;
				spawnInterval = 1.5;
				
				class Species {
					class CatShark_F {
						maxCircleCount = "(4 * (WaterDepth interpolate [1,30,0,1]))";
						maxWorldCount = 10;
						cost = 6;
						spawnCount = 1;
						groupSpawnRadius = 10;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Turtle_F {
						maxCircleCount = "(2 * (waterDepth interpolate [1,16,0,1]) * ((1-houses) * (1-houses)))";
						maxWorldCount = 6;
						cost = 5;
						spawnCount = 1;
						groupSpawnRadius = 10;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Snake_random_F {
						maxCircleCount = "(1 - houses) * ((2 * (1 - sea)) + (2 * (meadow)))";
						maxWorldCount = 3;
						cost = 5;
						spawnCount = 1;
						groupSpawnRadius = 5;
						maxAlt = 40;
						minAlt = -5;
					};
					
					class Salema_F {
						maxCircleCount = "(12 * ((WaterDepth interpolate [1,30,0,1]) + 0.07))";
						maxWorldCount = 40;
						cost = 5;
						spawnCount = 2;
						groupSpawnRadius = 5;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Ornate_random_F {
						maxCircleCount = "(12 * ((WaterDepth interpolate [1,30,0,1]) + 0.05))";
						maxWorldCount = 30;
						cost = 5;
						spawnCount = 3;
						groupSpawnRadius = 5;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Mackerel_F {
						maxCircleCount = "(8 * ((WaterDepth interpolate [1,30,0,1]) + 0.07))";
						maxWorldCount = 14;
						cost = 5;
						spawnCount = 2;
						groupSpawnRadius = 5;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Mullet_F {
						maxCircleCount = "(8 * ((WaterDepth interpolate [1,30,0,1]) + 0.07))";
						maxWorldCount = 14;
						cost = 5;
						spawnCount = 2;
						groupSpawnRadius = 5;
						maxAlt = 10;
						minAlt = -80;
					};
					
					class Tuna_F {
						maxCircleCount = "(8 * ((WaterDepth interpolate [1,30,0,1]) - 0.2))";
						maxWorldCount = 10;
						cost = 5;
						spawnCount = 2;
						groupSpawnRadius = 5;
						maxAlt = 10;
						minAlt = -80;
					};
				};
			};
			
			class Radius30_40 {
				areaSpawnRadius = 30.0;
				areaMaxRadius = 40.0;
				spawnCircleRadius = 3.0;
				spawnInterval = 3.75;
				
				class Species {
					class DragonFly {
						maxCircleCount = "4 * (1 - night) * (1 - (WaterDepth interpolate [1,30,0,1])) * sea * (1 - windy)";
						maxWorldCount = 4;
						cost = 1;
						spawnCount = 1;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class ButterFly_random {
						maxCircleCount = "3 * (1 - night) * (1 - (WaterDepth interpolate [1,30,0,1])) * (1 - windy)";
						maxWorldCount = 6;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
				};
			};
			
			class Radius15_20 {
				areaSpawnRadius = 15.0;
				areaMaxRadius = 20.0;
				spawnCircleRadius = 2.0;
				spawnInterval = 2.85;
				
				class Species {
					class FxWindGrass1 {
						maxCircleCount = "2 * (1 - (WaterDepth interpolate [1,30,0,1])) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount = 3;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 2.5;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class FxWindGrass2 {
						maxCircleCount = "2 * (1 - (WaterDepth interpolate [1,30,0,1])) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount = 3;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 2.5;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class FxWindLeaf1 {
						maxCircleCount = "2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount = 3;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 2.5;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class FxWindLeaf2 {
						maxCircleCount = "2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount = 3;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 2.5;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class FxWindLeaf3 {
						maxCircleCount = "2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount = 3;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 2.5;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class FxWindPollen1 {
						maxCircleCount = "(3 * (1 - (WaterDepth interpolate [1,30,0,1]))) * (windy interpolate [0.05,0.15,0,1])";
						maxWorldCount = 6;
						cost = 1;
						spawnCount = 1;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
				};
			};
			
			class Radius6_10 {
				areaSpawnRadius = 6.0;
				areaMaxRadius = 10.0;
				spawnCircleRadius = 1.0;
				spawnInterval = 0.1;
				
				class Species {
					class HoneyBee {
						maxCircleCount = "4 * (1 - night) * (1 - sea) * (1 - houses) * (1 - windy)";
						maxWorldCount = 8;
						cost = 1;
						spawnCount = 1;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class HouseFly {
						maxCircleCount = "(3 + 3 * (houses)) * (1 - night) * (1 - (WaterDepth interpolate [1,30,0,1])) * (1 - windy)";
						maxWorldCount = 10;
						cost = 1;
						spawnCount = 3;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
					
					class Mosquito {
						maxCircleCount = "3 * (1 - (WaterDepth interpolate [1,30,0,1])) * (1 - windy)";
						maxWorldCount = 2;
						cost = 1;
						spawnCount = 1;
						groupSpawnRadius = 1;
						maxAlt = 30;
						minAlt = -5;
					};
				};
			};
		};
		class Names {
			class New_Haven {
				name = "New Haven";
				position[] = {6367.2, 4190.52};
				type = "NameCityCapital";
				demography = CIV;
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class smugglers_cove {
				name = "Smugglers Cove";
				position[] = {1919.88, 640.95};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class bphill {
				name = "";
				position[] = {4813, 3265};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class MainBase {
				name = "Central Military Complex";
				position[] = {5420.6, 1629.3};
				type = "airport";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Elwood {
				name = "Elwood";
				position[] = {3668.3, 445.7};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class West_haven {
				name = "West Haven";
				position[] = {3613.28, 2850.61};
				type = "NameCity";
				demography = CIV;
				radiusA = 77.45;
				radiusB = 57.91;
				angle = 0.0;
			};
			
			class Refuge_bay {
				name = "Refuge Bay";
				position[] = {883.58, 4414.9};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class The_rip {
				name = "The Rip";
				position[] = {2380.03, 6984.48};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class stronghold1 {
				name = "Stronghold";
				position[] = {9388.88, 937.478};
				type = "NameLocal";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class stronghold2 {
				name = "Stronghold";
				position[] = {393.44, 5951.04};
				type = "NameLocal";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Shootingrange {
				name = "Shooting Range";
				position[] = {9331.61, 2384.85};
				type = "NameLocal";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class bphill1 {
				name = "";
				position[] = {3931.75, 1163.99};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class Saw_mill01 {
				name = "Sawmill";
				position[] = {8525.28, 1927.72};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Emerald {
				name = "Emerald";
				position[] = {1463.88, 2382.33};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class birchip {
				name = "Birchip";
				position[] = {2648.22, 3484.75};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class seville {
				name = "Seville";
				position[] = {3924.61, 2000.18};
				type = "NameCity";
				demography = CIV;
				radiusA = 77.45;
				radiusB = 57.91;
				angle = 0.0;
			};
			
			class tongala {
				name = "Tongala";
				position[] = {2380.67, 1787.84};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class flinders_island {
				name = "Flinders Island";
				position[] = {9272.09, 3735.48};
				type = "Namecity";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Western_port {
				name = "Western Port Bay";
				position[] = {621.06, 6884.9};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class Richmond {
				name = "Richmond";
				position[] = {5467.48, 2108.46};
				type = "Namecity";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class rosedale {
				name = "Rosedale";
				position[] = {5021.46, 3469.03};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class creswick {
				name = "Creswick";
				position[] = {8581.6, 2172.75};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class farmers_coop {
				name = "Farmers Coop";
				position[] = {8457.99, 2176.12};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class bphill02 {
				name = "Castle Ruins";
				position[] = {3931.03, 1163.09};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class bphill03 {
				name = "";
				position[] = {1233.06, 3308.92};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class Swan_island {
				name = "Swan Island";
				position[] = {6869.44, 3080.99};
				type = "Namecity";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class bphill04 {
				name = "Stoney Point";
				position[] = {4884.04, 7964.38};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class bphill05 {
				name = "";
				position[] = {1783.07, 5462.71};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class Shark_bay {
				name = "Shark Bay";
				position[] = {6094.17, 1029.3};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class Evac_centre {
				name = "Evac Base";
				position[] = {9115.54, 8712.57};
				type = "NameCityCapital";
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class checkpoint01 {
				name = "Checkpoint";
				position[] = {3211.67, 396.784};
				type = "NameVillage";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class Evac_center01 {
				name = "Evac Centre";
				position[] = {2889.9, 467.043};
				type = "NameVillage";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class checkpoint02 {
				name = "Checkpoint";
				position[] = {4229.75, 3956.27};
				type = "NameVillage";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class forest01 {
				name = "";
				position[] = {6965.43, 946.968};
				type = "VegetationFir";
				radiusA = 176.65;
				radiusB = 204.4;
				angle = 0.0;
			};
			
			class forest02 {
				name = "";
				position[] = {994.995, 3538.44};
				type = "VegetationFir";
				radiusA = 176.65;
				radiusB = 204.4;
				angle = 0.0;
			};
			
			class forest03 {
				name = "";
				position[] = {3007.37, 3262.19};
				type = "VegetationFir";
				radiusA = 176.65;
				radiusB = 204.4;
				angle = 0.0;
			};
			
			class broadleaf01 {
				name = "";
				position[] = {3007.37, 3262.19};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf02 {
				name = "";
				position[] = {4478.23, 1452.59};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class civiairport {
				name = "Civilian Airport";
				position[] = {3144.04, 8956.21};
				type = "NameLocal";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class essendon {
				name = "Essendon";
				position[] = {3258.73, 8612.2};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class broadleaf03 {
				name = "";
				position[] = {5220.99, 2044.18};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf04 {
				name = "";
				position[] = {7700.64, 1754.57};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf05 {
				name = "";
				position[] = {6379.45, 2090.46};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf06 {
				name = "";
				position[] = {3778.89, 1708.29};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf07 {
				name = "";
				position[] = {4120.75, 2329.32};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf08 {
				name = "";
				position[] = {3958.03, 2950.35};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf09 {
				name = "";
				position[] = {5277.72, 3644.53};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class broadleaf10 {
				name = "";
				position[] = {2180.03, 1587.36};
				type = "VegetationBroadleaf";
				radiusA = 134.6;
				radiusB = 152.28;
				angle = 0.0;
			};
			
			class northernBase {
				name = "Northern Supply Base";
				position[] = {2063.68, 5061.27};
				type = "NameLocal";
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class loggingcamp {
				name = "Logging Camp";
				position[] = {8268.4, 1018.5};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class loggincamp01 {
				name = "Logging Camp";
				position[] = {7632.63, 792.758};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class port01 {
				name = "Port";
				position[] = {8384.94, 2499.1};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class port02 {
				name = "Port";
				position[] = {5054, 4342.24};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class port03 {
				name = "Port";
				position[] = {3213.61, 8239.58};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Saw_mill02 {
				name = "Sawmill";
				position[] = {4069.91, 8628.29};
				type = "NameVillage";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class bass_island {
				name = "Bass Island";
				position[] = {8224.77, 9277.71};
				type = "NameCityCapital";
				demography = CIV;
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class The_narrows {
				name = "The Narrows";
				position[] = {3119.4, 5429.06};
				type = "NameMarine";
				radiusA = 100.0;
				radiusB = 100.0;
				angle = 0.0;
			};
			
			class north_island {
				name = "North Island";
				position[] = {4156.95, 8108.43};
				type = "NameCityCapital";
				demography = CIV;
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class bphill06 {
				name = "";
				position[] = {8578.26, 9044.34};
				type = "Hill";
				radiusA = 213.55;
				radiusB = 159.68;
				angle = 0.0;
			};
			
			class GrassyFlats {
				name = "GrassyFlats";
				position[] = {2006.68, 3993.79};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class BPHQ {
				name = "Breaking Point H.Q";
				position[] = {5313.86, 743.442};
				type = "NameLocal";
				demography = CIV;
				radiusA = 400.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class Tulla {
				name = "CMC Airport";
				position[] = {5050.61, 1638.62};
				type = "myairport";
				demography = CIV;
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
			
			class nhhospital {
				name = "Hospital";
				position[] = {6155, 4387};
				type = "myhosp";
				demography = CIV;
				radiusA = 200.0;
				radiusB = 200.0;
				angle = 0.0;
			};
		};
	};
};

class CfgWorldList {
	class newhaven {};
};
class CfgMissions
{
	class Cutscenes
	{
		class newhavenIntro1
		{
			directory = "breakingpoint_ui\intro1.vr";
		};
	};
};
class CfgSurfaces {
	class Default;

	class bpgrass : Default {
		access = ReadOnly;
		files = "bp_dirt_*";
		character = "bp_grassClutter";
		soundEnviron = "grass";
		soundHit = "soft_ground";
		rough = 0.04;
		maxSpeedCoef = 0.9;
		dust = 0.5;
		lucidity = 2;
		grassCover = 0.05;
		impact = "Hit_Foliage_green";
		surfaceFriction = 1.3;
	};
	
	class bpbeach : Default {
		access = ReadOnly;
		files = "bp_beach_*";
		character = "Empty";
		soundEnviron = "sand";
		soundHit = "soft_ground";
		rough = 0.04;
		maxSpeedCoef = 0.9;
		dust = 0.1;
		grassCover = 0.0;
		impact = "hitGroundSoft";
		surfaceFriction = 1.3;
	};
	
	class bppineforest : Default {
		access = ReadOnly;
		files = "cr_les2_*";
		character = "bp_pineforestClutter";
		soundEnviron = "drygrass";
		soundHit = "soft_ground";
		rough = 0.08;
		maxSpeedCoef = 0.8;
		dust = 0.4;
		lucidity = 1.5;
		grassCover = 0.04;
		impact = "Hit_Foliage_Pine";
		surfaceFriction = 1.3;
	};
	
	class bp_wheatstubble : Default {
		access = ReadOnly;
		files = "cr_strniste_*";
		rough = 0.13;
		dust = 0.3;
		soundEnviron = "dirt";
		character = "CRStubbleClutter";
		soundHit = "soft_ground";
	};
	
	class bp_ploughedground : Default {
		access = ReadOnly;
		files = "cr_oranice_*";
		rough = 0.15;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class bp_brownrockground : Default {
		access = ReadOnly;
		files = "bp_brownrock_*";
		character = EMPTY;
		soundEnviron = "gravel";
		soundHit = "hard_ground";
		rough = 0.12;
		maxSpeedCoef = 0.85;
		dust = 0.4;
		lucidity = 1.5;
		grassCover = 0.02;
		impact = "hitGroundHard";
		surfaceFriction = 1.9;
	};
	
	class bp_soilsurface : Default {
		access = ReadOnly;
		files = "bp_soil_*";
		character = "empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.08;
		maxSpeedCoef = 0.8;
		dust = 0.5;
		lucidity = 1.65;
		grassCover = 0.0;
		impact = "hitGroundSoft";
		surfaceFriction = 1.6;
	};
	
	class bp_flatgrasssurface : Default {
		access = ReadOnly;
		files = "bp_flatgrass_*";
		character = "bp_flatgrassClutter";
		soundEnviron = "grass";
		soundHit = "soft_ground";
		rough = 0.08;
		maxSpeedCoef = 0.9;
		dust = 0.5;
		lucidity = 2;
		grassCover = 0.05;
		impact = "Hit_Foliage_green";
		surfaceFriction = 1.7;
	};
};

class CfgSurfaceCharacters {
	class bp_grassClutter {
		probability[] = {0.3, 0.01, 0.5, 0.04, 0.03};
		names[] = {"bp_grassgreen", "bp_weed3", "bp_GrassGreenGroup", "bp_Flower_BrushMedium_Blue", "bp_wideleaf"};
	};
	
	class bp_pineforestClutter {
		probability[] = {0.03, 0.1, 0.09, 0.1, 0.1, 0.5};
		names[] = {"bp_smallpinetree", "bp_fernsmall", "bp_ferntall", "bp_wideleafplant", "bp_GrassCrookedForest", "bp_greengrass"};
	};
	
	class CRStubbleClutter {
		probability[]={0.80000001,0.2};
		names[] = {"bp_Stubble","bp_StubbleTall"};
	};
	
	class bp_desertgrassClutter {
		probability[] = {0.02, 0.03, 0.3, 0.04, 0.01, 0.01};
		names[] = {"bp_grasstalldead", "bp_flowertansy", "bp_grassautummbrown", "bp_deadgrassbunch", "bp_weed2", "bp_plantdoc"};
	};
	
	class bp_thistlestonyClutter {
		probability[] = {0.4, 0.5};
		names[] = {"bp_GrassTall", "bp_grassgreen"};
	};
	
	class bp_flatgrassClutter {
		probability[] = {0.5, 0.02, 0.01, 0.01};
		names[] = {"bp_grassgreen", "bp_wideleaf", "bp_weed3", "bp_Flower_BrushMedium_Blue"};
	};
};