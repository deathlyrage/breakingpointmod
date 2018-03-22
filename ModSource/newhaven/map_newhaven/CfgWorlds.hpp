/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgWorlds {
	class DefaultWorld {
		cutscenes[] = {};
		
		class Weather {
			class Overcast;	// External class reference
		};
	};
	
	class CAWorld : DefaultWorld {
		class Grid {};
		class DayLightingBrightAlmost;	// External class reference
		class DayLightingRainy;	// External class reference
		class DefaultClutter;	// External class reference
		
		class Weather : Weather {
			class Lighting;	// External class reference
			
			class Overcast : Overcast {
				class Weather1;	// External class reference
				class Weather2;	// External class reference
				class Weather3;	// External class reference
				class Weather4;	// External class reference
				class Weather5;	// External class reference
				class Weather6;	// External class reference
			};
		};
	};
	class DefaultLighting;	// External class reference
	
	class newhaven : CAWorld {
		access = ReadOnlyVerified;
		worldId = 1;
		cutscenes[] = {};
		description = "NewHaven Ver 2.4 Beta.";
		icon = "";
		worldName = "\newhaven\map_newhaven\newhaven.wrp";
		pictureMap = "\newhaven\map_data_newhaven\picturemap_ca.paa";
		pictureShot = "\newhaven\map_data_newhaven\ui_newhaven_ca.paa";
		plateFormat = "MH$-####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		author = "Aussie. Made Exclusively For Breaking Point.";
		mapSize = 10240;
		mapZone = 35;
		longitude = 17.352;	// positive is east
		latitude = -35.964;	// positive is south
		elevationOffset = 0;
		envTexture = "A3\Data_f\env_land_ca.tga";
		newRoadsShape = "";
		
		class Sea {
			seaTexture = "a3\data_f\seatexture_co.paa";
			seaMaterial = "#water";
			shoreMaterial = "#shore";
			shoreFoamMaterial = "#shorefoam";
			shoreWetMaterial = "#shorewet";
			WaterMapScale = 20;
			WaterGrid = 50;
			MaxTide = 0;
			MaxWave = 0.25;
			SeaWaveXScale = 2.0/50;
			SeaWaveZScale = 1.0/50;
			SeaWaveHScale = 1.0;
			SeaWaveXDuration = 5000;
			SeaWaveZDuration = 10000;
		};
		
		class Underwater {
			noWaterFog = -0.04;
			fullWaterFog = -0.01;
			deepWaterFog = 100;
			waterFogDistanceNear = 5;
			waterFogDistance = 230;
			waterColor[] = {0.12, 0.12, 0.12};
			deepWaterColor[] = {0.0, 0.5, 0.8};
			surfaceColor[] = {0, 0, 0};
			deepSurfaceColor[] = {0, 0, 0};
		};
		
		class SeaWaterShaderPars {
			refractionMoveCoef = 0.03;
			minWaterOpacity = 0.0;
			waterOpacityDistCoef = 0.4;
			underwaterOpacity = 0.5;
			waterOpacityFadeStart = 60;
			waterOpacityFadeLength = 120;
		};
		
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
		startTime = 14:15;
		startDate = 6/1/2014;
		startWeather = 0.3;
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
		
		class Lighting : DefaultLighting 
		{
			groundReflection[] = {0.132,0.133,0.122};
			moonObjectColorFull[] = {460,440,400,1.0};
			moonHaloObjectColorFull[] = {465,477,475,1.0};
			moonsetObjectColor[] = {375,350,325,1.0};
			moonsetHaloObjectColor[] = {515,517,525,1.0};
			class ThunderBoltLight
			{
				diffuse[] = {2120,3170,5550};
				ambient[] = {0.001,0.001,0.001};
				intensity = 120000;
				class Attenuation
				{
					start = 0.0;
					constant = 0.0;
					linear = 0.0;
					quadratic = 1.0;
				};
			};
			starEmissivity = 25;
		};
		
		class DayLightingBrightAlmost
		{
			deepNight[] = {-15,{0.005,0.01,0.01},{0.0,0.002,0.003},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.002,0.003},{0.0,0.002,0.003},0};
			fullNight[] = {-5,{0.182,0.213,0.25},{0.05,0.111,0.221},{0.04,0.034,0.004},{0.039,0.049,0.072},{0.082,0.128,0.185},{0.283,0.35,0.431},0};
			sunMoon[] = {-3.75,{0.377,0.441,0.518},{0.103,0.227,0.453},{0.04,0.034,0.004},{0.039,0.049,0.072},{0.174,0.274,0.395},{0.582,0.72,0.887},0.5};
			earlySun[] = {-2.5,{0.675,0.69,0.784},{0.22,0.322,0.471},{0.04,0.034,0.004},{0.039,0.049,0.072},{0.424,0.549,0.745},{0.698,0.753,0.894},1};
			sunrise[] = {0,{0.675,0.69,0.784},{0.478,0.51,0.659},{0.2,0.19,0.07},{0.124,0.161,0.236},{{0.847,0.855,0.965},0.2},{{0.933,0.949,0.996},2},1};
			earlyMorning[] = {3,{{0.844,0.61,0.469},0.8},{0.424,0.557,0.651},{{1,0.45,0.2},1},{0.12,0.26,0.38},{{0.428,0.579,0.743},2},{{0.844,0.61,0.469},2.7},1};
			midMorning[] = {8,{{0.822,0.75,0.646},3.8},{{0.383,0.58,0.858},1.3},{{1.3,0.9,0.61},2.8},{{0.12,0.18,0.28},0.5},{{0.322,0.478,0.675},3.5},{{1.0,0.929,0.815},4.7},1};
			morning[] = {16,{{1,0.95,0.91},12.2},{{0.12,0.18,0.28},9.2},{{1,0.95,0.91},11.2},{{0.12,0.18,0.28},8.5},{{0.14,0.18,0.24},11.0},{{0.5,0.6,0.9},13.2},1};
			noon[] = {45,{{0.98,0.94,0.94},13.8},{{0.2,0.27,0.35},10.8},{{0.98,0.94,0.94},13.8},{{0.2,0.27,0.35},10.8},{{0.5,0.64,1.0},12.0},{{0.5,0.5,0.5},14.8},1,0.5,0.4,0.5,0.4};
		};
		
		class DayLightingRainy : DayLightingRainy {
			deepNight[] = {-15, {0.005, 0.01, 0.01}, {0.0, 0.002, 0.003}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.002, 0.003}, {0.0, 0.002, 0.003}, 0};
			fullNight[] = {-5, {0.023, 0.023, 0.023}, {0.02, 0.02, 0.02}, {0.023, 0.023, 0.023}, {0.02, 0.02, 0.02}, {0.01, 0.01, 0.02}, {0.08, 0.06, 0.06}, 0};
			sunMoon[] = {-3.75, {0.04, 0.04, 0.05}, {0.04, 0.04, 0.05}, {0.04, 0.04, 0.05}, {0.04, 0.04, 0.05}, {0.04, 0.035, 0.04}, {0.11, 0.08, 0.09}, 0.5};
			earlySun[] = {-2.5, {0.0689, 0.0689, 0.0804}, {0.06, 0.06, 0.07}, {0.0689, 0.0689, 0.0804}, {0.06, 0.06, 0.07}, {0.08, 0.07, 0.08}, {0.14, 0.1, 0.12}, 0.5};
			earlyMorning[] = {3, {{1, 1, 1}, (-4)+3.95}, {{1, 1, 1}, (-4)+3.0}, {{1, 1, 1}, (-4)+3.95}, {{1, 1, 1}, (-4)+3.0}, {{1, 1, 1}, (-4)+4}, {{1, 1, 1}, (-4)+5.5}, 1};
			morning[] = {16, {{1, 1, 1}, (-4)+5.7}, {{1, 1, 1}, (-4)+4.5}, {{1, 1, 1}, (-4)+5.7}, {{1, 1, 1}, (-4)+4.5}, {{1, 1, 1}, (-4)+7}, {{1, 1, 1}, (-4)+8}, 1};
			lateMorning[] = {25, {{1, 1, 1}, (-4)+10.45}, {{1, 1, 1}, (-4)+9.75}, {{1, 1, 1}, (-4)+10.45}, {{1, 1, 1}, (-4)+9.75}, {{1, 1, 1}, (-4)+12}, {{1, 1, 1}, (-4)+12.75}, 1};
			noon[] = {45, {{1, 1, 1}, 10.0}, {{1, 1, 1}, 9.0}, {{1, 1, 1}, 9.0}, {{1, 1, 1}, 8.0}, {{0.5, 0.64, 1}, 12.0}, {{0.5, 0.5, 0.5}, 14.8}, 1};
		};
		
		class Weather : Weather
		{
			rainEnabled = 1;
			temperatureDayMax[] = {10,12,15,20,25,35,35,35,25,20,10,10};
			temperatureDayMin[] = {-10,-6,-5,-1,5,6,7,10,5,2,-5,-10};
			temperatureNightMax[] = {5,6,8,10,13,18,26,25,15,13,8,4};
			temperatureNightMin[] = {-10,-10,-10,-5,0,4,5,6,5,0,-5,-10};
			overcastTemperatureFactor = 0.4;
			blackSurfaceTemperatureDelta = 5;
			whiteSurfaceTemperatureDelta = -2;
			class LightingNew
			{
				class Lighting0
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.14,0.19,0.3},4};
					diffuseCloud[] = {{0.14,0.19,0.3},0.2};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},0.05};
					ambientMid[] = {{0.1384,0.1912,0.2984},0.88};
					ambientMidCloud[] = {{0.1384,0.1912,0.2984},0.044};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.04224};
					bidirect[] = {0.025,0.025,0.023};
					bidirectCloud[] = {0.0125,0.0125,0.0115};
					sky[] = {0.231,0.314,0.467};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.09,0.137,0.22},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.5,0.65,1},11.016};
					swBrightness = 1;
				};
				class Lighting1
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting2
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting3
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {{0.2,0.25,0.45},4.734908};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 5;
					apertureMax = 10;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting4
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.16,0.18,0.28},3};
					diffuseCloud[] = {{0.16,0.18,0.28},3};
					ambient[] = {{0.173,0.239,0.373},4.6};
					ambientCloud[] = {{0.173,0.239,0.373},4.6};
					ambientMid[] = {{0.173,0.239,0.373},4.048};
					ambientMidCloud[] = {{0.173,0.239,0.373},4.048};
					groundReflection[] = {{0.173,0.239,0.373},3.88608};
					groundReflectionCloud[] = {{0.173,0.239,0.373},3.88608};
					bidirect[] = {0.0115,0.012,0.0125};
					bidirectCloud[] = {0.0115,0.012,0.0125};
					sky[] = {{0.2,0.298,0.541},4.6};
					skyAroundSun[] = {{0.7,0.35,0.28},7.636949};
					fogColor[] = {{0.106,0.161,0.267},4.715};
					apertureMin = 5;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting5
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.25,0.21,0.2},5};
					diffuseCloud[] = {{0.25,0.21,0.2},5};
					ambient[] = {{0.196,0.275,0.42},6.9};
					ambientCloud[] = {{0.196,0.275,0.42},6.9};
					ambientMid[] = {{0.196,0.275,0.42},6.072};
					ambientMidCloud[] = {{0.196,0.275,0.42},6.072};
					groundReflection[] = {{0.196,0.275,0.42},5.82912};
					groundReflectionCloud[] = {{0.196,0.275,0.42},5.82912};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.188,0.29,0.576},6.9};
					skyAroundSun[] = {{1.8,0.42,0.2},12.31766};
					fogColor[] = {{0.11,0.169,0.286},7.0725};
					apertureMin = 6;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting6
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.75,0.38,0.22},6};
					diffuseCloud[] = {{0.75,0.38,0.22},6};
					ambient[] = {{0.2497,0.31,0.467},7.8};
					ambientCloud[] = {{0.2497,0.31,0.467},7.8};
					ambientMid[] = {{0.2541,0.314,0.467},6.864};
					ambientMidCloud[] = {{0.2541,0.314,0.467},6.864};
					groundReflection[] = {{0.235,0.318,0.467},6.58944};
					groundReflectionCloud[] = {{0.235,0.318,0.467},6.58944};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.173,0.282,0.612},7.8};
					skyAroundSun[] = {{2,0.42,0.2},13.38876};
					fogColor[] = {{0.118,0.18,0.31},7.995};
					apertureMin = 7;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting7
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.95,0.42,0.22},8.4};
					diffuseCloud[] = {{0.95,0.42,0.22},8.4};
					ambient[] = {{0.306,0.357,0.463},8.4};
					ambientCloud[] = {{0.306,0.357,0.463},8.4};
					ambientMid[] = {{0.365,0.361,0.396},7.392};
					ambientMidCloud[] = {{0.365,0.361,0.396},7.392};
					groundReflection[] = {{0.416,0.38,0.388},7.09632};
					groundReflectionCloud[] = {{0.416,0.38,0.388},7.09632};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.157,0.275,0.651},8.4};
					skyAroundSun[] = {{2.2,0.8,0.2},13.38876};
					fogColor[] = {{0.125,0.192,0.329},8.61};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting8
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.95,0.55,0.35},10.2};
					diffuseCloud[] = {{0.95,0.55,0.35},10.2};
					ambient[] = {{0.337,0.404,0.525},9.6};
					ambientCloud[] = {{0.337,0.404,0.525},9.6};
					ambientMid[] = {{0.412,0.408,0.443},8.448};
					ambientMidCloud[] = {{0.412,0.408,0.443},8.448};
					groundReflection[] = {{0.475,0.435,0.431},8.11008};
					groundReflectionCloud[] = {{0.475,0.435,0.431},8.11008};
					bidirect[] = {0.01375,0.0132,0.01265};
					bidirectCloud[] = {0.01375,0.0132,0.01265};
					sky[] = {{0.145,0.263,0.686},9.6};
					skyAroundSun[] = {{0.4,0.32,0.6},13.38876};
					fogColor[] = {{0.133,0.204,0.357},9.84};
					apertureMin = 8;
					apertureStandard = 16;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.027,0.045};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting9
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1,0.65,0.45},12.3};
					diffuseCloud[] = {{1,0.65,0.45},12.3};
					ambient[] = {{0.388,0.471,0.612},10.9};
					ambientCloud[] = {{0.388,0.471,0.612},10.9};
					ambientMid[] = {{0.482,0.475,0.506},9.81};
					ambientMidCloud[] = {{0.482,0.475,0.506},9.81};
					groundReflection[] = {{0.557,0.51,0.494},9.4176};
					groundReflectionCloud[] = {{0.557,0.51,0.494},9.4176};
					bidirect[] = {0.01875,0.018,0.01725};
					bidirectCloud[] = {0.01875,0.018,0.01725};
					sky[] = {{0.129,0.259,0.722},10.9};
					skyAroundSun[] = {{0.13,0.25,0.8},13.524};
					fogColor[] = {{0.145,0.224,0.396},11.1725};
					apertureMin = 20;
					apertureStandard = 25;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.018,0.04};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},12.24};
					swBrightness = 1;
				};
				class Lighting10
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{1,0.75,0.62},15.8};
					diffuseCloud[] = {{1,0.75,0.62},15.8};
					ambient[] = {{0.435,0.533,0.698},13.8};
					ambientCloud[] = {{0.435,0.533,0.698},13.8};
					ambientMid[] = {{0.545,0.541,0.569},12.696};
					ambientMidCloud[] = {{0.545,0.541,0.569},12.696};
					groundReflection[] = {{0.635,0.58,0.557},12.18816};
					groundReflectionCloud[] = {{0.635,0.58,0.557},12.18816};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.118,0.251,0.753},13.8};
					skyAroundSun[] = {{0.115,0.245,0.8},13.662};
					fogColor[] = {{0.15,0.251,0.488},14.145};
					apertureMin = 45;
					apertureStandard = 60;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.4};
					swBrightness = 1;
				};
				class Lighting11
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},17.2};
					diffuseCloud[] = {{1,0.87,0.85},17.2};
					ambient[] = {{0.498,0.602,0.77},14.8};
					ambientCloud[] = {{0.498,0.602,0.77},14.8};
					ambientMid[] = {{0.635,0.635,0.663},14.504};
					ambientMidCloud[] = {{0.635,0.635,0.663},14.504};
					groundReflection[] = {{0.745,0.671,0.643},14.21392};
					groundReflectionCloud[] = {{0.745,0.671,0.643},14.21392};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.3,0.44,0.74},15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting12
				{
					height = 0;
					overcast = 0.25;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},17.2};
					diffuseCloud[] = {{1,0.87,0.85},17.2};
					ambient[] = {{0.498,0.602,0.77},14.8};
					ambientCloud[] = {{0.498,0.602,0.77},14.8};
					ambientMid[] = {{0.635,0.635,0.663},14.504};
					ambientMidCloud[] = {{0.635,0.635,0.663},14.504};
					groundReflection[] = {{0.745,0.671,0.643},14.21392};
					groundReflectionCloud[] = {{0.745,0.671,0.643},14.21392};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.3,0.44,0.74},15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting13
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.14,0.19,0.3},4};
					diffuseCloud[] = {{0.14,0.19,0.3},3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.1384,0.1912,0.2984},0.88};
					ambientMidCloud[] = {{0.1384,0.1912,0.2984},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0.025,0.025,0.023};
					bidirectCloud[] = {0.0245,0.0245,0.02254};
					sky[] = {0.231,0.314,0.467};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.09,0.137,0.22},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{0.5,0.65,1},11.016};
					swBrightness = 1;
				};
				class Lighting14
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting15
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting16
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {{0.173,0.239,0.373},1};
					ambientCloud[] = {{0.173,0.239,0.373},1};
					ambientMid[] = {{0.173,0.239,0.373},0.88};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.88};
					groundReflection[] = {{0.173,0.239,0.373},0.8448};
					groundReflectionCloud[] = {{0.173,0.239,0.373},0.8448};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {{0.2,0.25,0.45},4.734908};
					fogColor[] = {{0.094,0.141,0.231},0.025};
					apertureMin = 4;
					apertureStandard = 5;
					apertureMax = 10;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting17
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.16,0.18,0.28},2.25};
					diffuseCloud[] = {{0.16,0.18,0.28},1.6875};
					ambient[] = {{0.173,0.239,0.373},4.6};
					ambientCloud[] = {{0.173,0.239,0.373},4.6};
					ambientMid[] = {{0.173,0.239,0.373},4.048};
					ambientMidCloud[] = {{0.173,0.239,0.373},4.048};
					groundReflection[] = {{0.173,0.239,0.373},3.88608};
					groundReflectionCloud[] = {{0.173,0.239,0.373},3.88608};
					bidirect[] = {0.0115,0.012,0.0125};
					bidirectCloud[] = {0.01127,0.01176,0.01225};
					sky[] = {{0.2,0.298,0.541},4.6};
					skyAroundSun[] = {{0.7,0.35,0.28},7.636949};
					fogColor[] = {{0.106,0.161,0.267},4.715};
					apertureMin = 5;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting18
				{
					height = 0;
					overcast = 0.6;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.25,0.21,0.2},3.75};
					diffuseCloud[] = {{0.25,0.21,0.2},2.8125};
					ambient[] = {{0.196,0.275,0.42},6.9};
					ambientCloud[] = {{0.196,0.275,0.42},6.9};
					ambientMid[] = {{0.196,0.275,0.42},6.072};
					ambientMidCloud[] = {{0.196,0.275,0.42},6.072};
					groundReflection[] = {{0.196,0.275,0.42},5.82912};
					groundReflectionCloud[] = {{0.196,0.275,0.42},5.82912};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.188,0.29,0.576},6.9};
					skyAroundSun[] = {{1.8,0.42,0.2},12.31766};
					fogColor[] = {{0.11,0.169,0.286},7.0725};
					apertureMin = 6;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting19
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.75,0.38,0.22},4.5};
					diffuseCloud[] = {{0.75,0.38,0.22},3.375};
					ambient[] = {{0.2497,0.31,0.467},7.8};
					ambientCloud[] = {{0.2497,0.31,0.467},7.8};
					ambientMid[] = {{0.2541,0.314,0.467},6.864};
					ambientMidCloud[] = {{0.2541,0.314,0.467},6.864};
					groundReflection[] = {{0.235,0.318,0.467},6.58944};
					groundReflectionCloud[] = {{0.235,0.318,0.467},6.58944};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.173,0.282,0.612},7.8};
					skyAroundSun[] = {{2,0.42,0.2},13.38876};
					fogColor[] = {{0.118,0.18,0.31},7.995};
					apertureMin = 7;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting20
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.95,0.42,0.22},6.72};
					diffuseCloud[] = {{0.95,0.42,0.22},5.04};
					ambient[] = {{0.306,0.357,0.463},8.4};
					ambientCloud[] = {{0.306,0.357,0.463},8.4};
					ambientMid[] = {{0.365,0.361,0.396},7.392};
					ambientMidCloud[] = {{0.365,0.361,0.396},7.392};
					groundReflection[] = {{0.416,0.38,0.388},7.09632};
					groundReflectionCloud[] = {{0.416,0.38,0.388},7.09632};
					bidirect[] = {0.023,0.024,0.025};
					bidirectCloud[] = {0.023,0.024,0.025};
					sky[] = {{0.157,0.275,0.651},8.4};
					skyAroundSun[] = {{2.2,0.8,0.2},13.38876};
					fogColor[] = {{0.125,0.192,0.329},8.61};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting21
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.95,0.55,0.35},10.2};
					diffuseCloud[] = {{0.95,0.55,0.35},7.65};
					ambient[] = {{0.337,0.404,0.525},9.6};
					ambientCloud[] = {{0.337,0.404,0.525},9.6};
					ambientMid[] = {{0.412,0.408,0.443},8.448};
					ambientMidCloud[] = {{0.412,0.408,0.443},8.448};
					groundReflection[] = {{0.475,0.435,0.431},8.11008};
					groundReflectionCloud[] = {{0.475,0.435,0.431},8.11008};
					bidirect[] = {0.01375,0.0132,0.01265};
					bidirectCloud[] = {0.01375,0.0132,0.01265};
					sky[] = {{0.145,0.263,0.686},9.6};
					skyAroundSun[] = {{0.4,0.32,0.6},13.38876};
					fogColor[] = {{0.133,0.204,0.357},9.84};
					apertureMin = 8;
					apertureStandard = 16;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.027,0.045};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting22
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1,0.65,0.45},12.3};
					diffuseCloud[] = {{1,0.65,0.45},9.225};
					ambient[] = {{0.388,0.471,0.612},10.9};
					ambientCloud[] = {{0.388,0.471,0.612},10.9};
					ambientMid[] = {{0.482,0.475,0.506},9.81};
					ambientMidCloud[] = {{0.482,0.475,0.506},9.81};
					groundReflection[] = {{0.557,0.51,0.494},9.4176};
					groundReflectionCloud[] = {{0.557,0.51,0.494},9.4176};
					bidirect[] = {0.01875,0.018,0.01725};
					bidirectCloud[] = {0.01875,0.018,0.01725};
					sky[] = {{0.129,0.259,0.722},10.9};
					skyAroundSun[] = {{0.13,0.25,0.8},13.524};
					fogColor[] = {{0.145,0.224,0.396},11.1725};
					apertureMin = 20;
					apertureStandard = 25;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.018,0.04};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},12.24};
					swBrightness = 1;
				};
				class Lighting23
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{1,0.75,0.62},15.8};
					diffuseCloud[] = {{1,0.75,0.62},11.85};
					ambient[] = {{0.435,0.533,0.698},13.8};
					ambientCloud[] = {{0.435,0.533,0.698},13.8};
					ambientMid[] = {{0.545,0.541,0.569},12.696};
					ambientMidCloud[] = {{0.545,0.541,0.569},12.696};
					groundReflection[] = {{0.635,0.58,0.557},12.18816};
					groundReflectionCloud[] = {{0.635,0.58,0.557},12.18816};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.118,0.251,0.753},13.8};
					skyAroundSun[] = {{0.115,0.245,0.8},13.662};
					fogColor[] = {{0.15,0.251,0.488},14.145};
					apertureMin = 45;
					apertureStandard = 60;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.4};
					swBrightness = 1;
				};
				class Lighting24
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},17};
					diffuseCloud[] = {{1,0.87,0.85},12.75};
					ambient[] = {{0.498,0.602,0.77},14.8};
					ambientCloud[] = {{0.498,0.602,0.77},14.8};
					ambientMid[] = {{0.635,0.635,0.663},13.616};
					ambientMidCloud[] = {{0.635,0.635,0.663},13.616};
					groundReflection[] = {{0.745,0.671,0.643},14.21392};
					groundReflectionCloud[] = {{0.745,0.671,0.643},14.21392};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.3,0.44,0.74},13.9564};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting25
				{
					height = 0;
					overcast = 0.6;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},17};
					diffuseCloud[] = {{1,0.87,0.85},13.94};
					ambient[] = {{0.498,0.602,0.77},14.8};
					ambientCloud[] = {{0.498,0.602,0.77},14.8};
					ambientMid[] = {{0.635,0.635,0.663},14.504};
					ambientMidCloud[] = {{0.635,0.635,0.663},14.504};
					groundReflection[] = {{0.745,0.671,0.643},14.21392};
					groundReflectionCloud[] = {{0.745,0.671,0.643},14.21392};
					bidirect[] = {0.025,0.024,0.018};
					bidirectCloud[] = {0.025,0.024,0.018};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.3,0.44,0.74},15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting26
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.09,0.137,0.22},1};
					diffuseCloud[] = {{0,0,0},0.75};
					ambient[] = {{0.09,0.137,0.22},1};
					ambientCloud[] = {{0.09,0.137,0.22},1};
					ambientMid[] = {{0.09,0.137,0.22},0.8624};
					ambientMidCloud[] = {{0.09,0.137,0.22},0.8624};
					groundReflection[] = {{0.09,0.137,0.22},0.758912};
					groundReflectionCloud[] = {{0.09,0.137,0.22},0.758912};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {0.231,0.314,0.467};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {0.09,0.137,0.22};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting27
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.16954,0.239,0.37673};
					diffuseCloud[] = {0.042385,0.05975,0.094183};
					ambient[] = {{0.16954,0.239,0.37673},1};
					ambientCloud[] = {{0.16954,0.239,0.37673},1};
					ambientMid[] = {{0.173,0.239,0.373},0.8624};
					ambientMidCloud[] = {{0.173,0.239,0.373},0.8624};
					groundReflection[] = {{0.14705,0.20315,0.31705},0.758912};
					groundReflectionCloud[] = {{0.14705,0.20315,0.31705},0.758912};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {0.122,0.169,0.255};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting28
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.129,0.18,0.271};
					diffuseCloud[] = {0.03225,0.045,0.06775};
					ambient[] = {{0.129,0.18,0.271},1};
					ambientCloud[] = {{0.129,0.18,0.271},1};
					ambientMid[] = {{0.129,0.184,0.267},0.8624};
					ambientMidCloud[] = {{0.129,0.184,0.267},0.8624};
					groundReflection[] = {{0.125,0.176,0.263},0.758912};
					groundReflectionCloud[] = {{0.125,0.176,0.263},0.758912};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {0.2,0.25,0.45};
					fogColor[] = {0.122,0.169,0.255};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting29
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.129,0.18,0.271};
					diffuseCloud[] = {0.03225,0.045,0.06775};
					ambient[] = {{0.129,0.18,0.271},1};
					ambientCloud[] = {{0.129,0.18,0.271},1};
					ambientMid[] = {{0.129,0.184,0.267},0.8624};
					ambientMidCloud[] = {{0.129,0.184,0.267},0.8624};
					groundReflection[] = {{0.125,0.176,0.263},0.758912};
					groundReflectionCloud[] = {{0.125,0.176,0.263},0.758912};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.212,0.302,0.51},1};
					skyAroundSun[] = {{0.2,0.25,0.45},4.734908};
					fogColor[] = {0.122,0.169,0.255};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 10;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting30
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.157,0.212,0.306},0.5625};
					diffuseCloud[] = {{0.03925,0.053,0.0765},0.39375};
					ambient[] = {{0.157,0.212,0.306},3.22};
					ambientCloud[] = {{0.157,0.212,0.306},3.22};
					ambientMid[] = {{0.157,0.208,0.298},3.96704};
					ambientMidCloud[] = {{0.157,0.208,0.298},3.96704};
					groundReflection[] = {{0.149,0.204,0.29},3.649677};
					groundReflectionCloud[] = {{0.149,0.204,0.29},3.649677};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.2,0.298,0.541},4.6};
					skyAroundSun[] = {{0.7,0.35,0.28},7.636949};
					fogColor[] = {{0.141,0.192,0.282},3.96704};
					apertureMin = 5;
					apertureStandard = 5;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting31
				{
					height = 0;
					overcast = 0.85;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.184,0.247,0.341},0.9375};
					diffuseCloud[] = {{0.046,0.06175,0.08525},0.65625};
					ambient[] = {{0.184,0.247,0.341},6.9};
					ambientCloud[] = {{0.184,0.247,0.341},6.9};
					ambientMid[] = {{0.184,0.243,0.329},5.95056};
					ambientMidCloud[] = {{0.184,0.243,0.329},5.95056};
					groundReflection[] = {{0.176,0.231,0.322},5.593526};
					groundReflectionCloud[] = {{0.176,0.231,0.322},5.593526};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.188,0.29,0.576},6.9};
					skyAroundSun[] = {{1.8,0.42,0.2},12.31766};
					fogColor[] = {{0.165,0.22,0.31},5.95056};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting32
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.216,0.286,0.384},1.125};
					diffuseCloud[] = {{0.054,0.0715,0.096},0.7875};
					ambient[] = {{0.216,0.286,0.384},7.8};
					ambientCloud[] = {{0.216,0.286,0.384},7.8};
					ambientMid[] = {{0.22,0.278,0.365},6.72672};
					ambientMidCloud[] = {{0.22,0.278,0.365},6.72672};
					groundReflection[] = {{0.204,0.267,0.353},6.457651};
					groundReflectionCloud[] = {{0.204,0.267,0.353},6.457651};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.173,0.282,0.612},7.8};
					skyAroundSun[] = {{2,0.42,0.2},13.38876};
					fogColor[] = {{0.188,0.247,0.341},6.72672};
					apertureMin = 7;
					apertureStandard = 7;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting33
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.255,0.325,0.42},1.68};
					diffuseCloud[] = {{0.06375,0.08125,0.105},1.176};
					ambient[] = {{0.255,0.325,0.42},8.4};
					ambientCloud[] = {{0.255,0.325,0.42},8.4};
					ambientMid[] = {{0.259,0.314,0.396},7.24416};
					ambientMidCloud[] = {{0.259,0.314,0.396},7.24416};
					groundReflection[] = {{0.239,0.294,0.376},7.099277};
					groundReflectionCloud[] = {{0.239,0.294,0.376},7.099277};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.157,0.275,0.651},8.4};
					skyAroundSun[] = {{2.2,0.8,0.2},13.38876};
					fogColor[] = {{0.216,0.275,0.373},7.24416};
					apertureMin = 8;
					apertureStandard = 8;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting34
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.298,0.365,0.451},2.55};
					diffuseCloud[] = {{0.0745,0.09125,0.11275},1.785};
					ambient[] = {{0.298,0.365,0.451},9.6};
					ambientCloud[] = {{0.298,0.365,0.451},9.6};
					ambientMid[] = {{0.302,0.349,0.416},8.27904};
					ambientMidCloud[] = {{0.302,0.349,0.416},8.27904};
					groundReflection[] = {{0.275,0.318,0.384},8.11346};
					groundReflectionCloud[] = {{0.275,0.318,0.384},8.11346};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.145,0.263,0.686},9.6};
					skyAroundSun[] = {{0.4,0.32,0.6},13.38876};
					fogColor[] = {{0.243,0.306,0.408},8.27904};
					apertureMin = 8;
					apertureStandard = 14;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.027,0.045};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting35
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{0.376,0.431,0.506},3.075};
					diffuseCloud[] = {{0.094,0.10775,0.1265},2.1525};
					ambient[] = {{0.376,0.431,0.506},10.9};
					ambientCloud[] = {{0.376,0.431,0.506},10.9};
					ambientMid[] = {{0.38,0.408,0.447},9.6138};
					ambientMidCloud[] = {{0.38,0.408,0.447},9.6138};
					groundReflection[] = {{0.329,0.361,0.396},9.421524};
					groundReflectionCloud[] = {{0.329,0.361,0.396},9.421524};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.129,0.259,0.722},10.9};
					skyAroundSun[] = {{0.13,0.25,0.8},13.524};
					fogColor[] = {{0.286,0.353,0.463},9.6138};
					apertureMin = 20;
					apertureStandard = 22;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.018,0.04};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},12.24};
					swBrightness = 1;
				};
				class Lighting36
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{0.447,0.494,0.557},3.95};
					diffuseCloud[] = {{0,0,0},2.765};
					ambient[] = {{0.447,0.494,0.557},13.8};
					ambientCloud[] = {{0.447,0.494,0.557},13.8};
					ambientMid[] = {{0.455,0.467,0.475},12.44208};
					ambientMidCloud[] = {{0.455,0.467,0.475},12.44208};
					groundReflection[] = {{0.388,0.396,0.408},12.19324};
					groundReflectionCloud[] = {{0.388,0.396,0.408},12.19324};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.118,0.251,0.753},13.8};
					skyAroundSun[] = {{0.115,0.245,0.8},13.662};
					fogColor[] = {{0.333,0.404,0.518},12.44208};
					apertureMin = 45;
					apertureStandard = 50;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.4};
					swBrightness = 1;
				};
				class Lighting37
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.506,0.553,0.608},4.25};
					diffuseCloud[] = {0.1265,0.13825,0.152};
					ambient[] = {{0.506,0.553,0.608},14.8};
					ambientCloud[] = {{0.506,0.553,0.608},14.8};
					ambientMid[] = {{0.514,0.518,0.514},13.34368};
					ambientMidCloud[] = {{0.514,0.518,0.514},13.34368};
					groundReflection[] = {{0.435,0.439,0.439},13.07681};
					groundReflectionCloud[] = {{0.435,0.439,0.439},13.07681};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.369,0.447,0.565},13.34368};
					apertureMin = 70;
					apertureStandard = 100;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting38
				{
					height = 0;
					overcast = 0.85;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{0.549,0.596,0.651},4.25};
					diffuseCloud[] = {0.13725,0.149,0.16275};
					ambient[] = {{0.549,0.596,0.651},14.8};
					ambientCloud[] = {{0.549,0.596,0.651},14.8};
					ambientMid[] = {{0.557,0.557,0.585},14.21392};
					ambientMidCloud[] = {{0.557,0.557,0.585},14.21392};
					groundReflection[] = {{0.471,0.471,0.463},13.92964};
					groundReflectionCloud[] = {{0.471,0.471,0.463},13.92964};
					bidirect[] = {0.0117,0.0117,0.0117};
					bidirectCloud[] = {0.0117,0.0117,0.0117};
					sky[] = {{0.02,0.12,0.8},13.8};
					skyAroundSun[] = {{0.02,0.12,0.8},13.8};
					fogColor[] = {{0.4,0.48,0.6},15};
					apertureMin = 70;
					apertureStandard = 110;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting39
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.6,0.8,1},2.8};
					diffuseCloud[] = {{0.6,0.8,1},2.8};
					ambient[] = {{0.4,0.9,1},0.84};
					ambientCloud[] = {{0.4,0.9,1},0.84};
					ambientMid[] = {{0.24,0.63,1},0.9072};
					ambientMidCloud[] = {{0.24,0.63,1},0.9072};
					groundReflection[] = {{0.24,0.63,1},0.870912};
					groundReflectionCloud[] = {{0.24,0.63,1},0.870912};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0,0.2355,0.2335};
					skyAroundSun[] = {0,0.2355,0.2335};
					fogColor[] = {{0.09,0.137,0.22},0.0275};
					apertureMin = 4;
					apertureStandard = 4;
					apertureMax = 8;
					standardAvgLum = 4;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting40
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.6,0.8,1},2.1};
					diffuseCloud[] = {{0.6,0.8,1},2.1};
					ambient[] = {{0.4,0.9,1},3.68};
					ambientCloud[] = {{0.4,0.9,1},3.68};
					ambientMid[] = {{0.24,0.63,1},3.9744};
					ambientMidCloud[] = {{0.24,0.63,1},3.9744};
					groundReflection[] = {{0.24,0.63,1},3.815424};
					groundReflectionCloud[] = {{0.24,0.63,1},3.815424};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0,0.2235,0.2705},4.232};
					skyAroundSun[] = {{0,0.2235,0.2705},7.636949};
					fogColor[] = {{0.106,0.161,0.267},4.715};
					apertureMin = 5;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting41
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.6,0.8,1},3.5};
					diffuseCloud[] = {{0.6,0.8,1},3.5};
					ambient[] = {{0.4,0.9,1},5.52};
					ambientCloud[] = {{0.4,0.9,1},5.52};
					ambientMid[] = {{0.24,0.63,1},5.9616};
					ambientMidCloud[] = {{0.24,0.63,1},5.9616};
					groundReflection[] = {{0.24,0.63,1},5.723136};
					groundReflectionCloud[] = {{0.24,0.63,1},5.723136};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0,0.2175,0.288},6.348};
					skyAroundSun[] = {{0,0.2175,0.288},12.31766};
					fogColor[] = {{0.11,0.169,0.286},7.0725};
					apertureMin = 6;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting42
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.6,0.8,1},4.2};
					diffuseCloud[] = {{0.6,0.8,1},4.2};
					ambient[] = {{0.4,0.9,1},6.24};
					ambientCloud[] = {{0.4,0.9,1},6.24};
					ambientMid[] = {{0.24,0.63,1},6.7392};
					ambientMidCloud[] = {{0.24,0.63,1},6.7392};
					groundReflection[] = {{0.24,0.63,1},6.469632};
					groundReflectionCloud[] = {{0.24,0.63,1},6.469632};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0,0.2115,0.306},7.176};
					skyAroundSun[] = {{0,0.2115,0.306},13.38876};
					fogColor[] = {{0.118,0.18,0.31},7.995};
					apertureMin = 7;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.038,0.0675};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},11.016};
					swBrightness = 1;
				};
				class Lighting43
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.6,0.8,1},12.04};
					diffuseCloud[] = {{0.6,0.8,1},12.04};
					ambient[] = {{0.4,0.9,1},11.84};
					ambientCloud[] = {{0.4,0.9,1},11.84};
					ambientMid[] = {{0.36,0.72,1},11.4848};
					ambientMidCloud[] = {{0.36,0.72,1},11.4848};
					groundReflection[] = {{0.36,0.72,1},11.02541};
					groundReflectionCloud[] = {{0.36,0.72,1},11.02541};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0,0.09,0.4},13.8};
					skyAroundSun[] = {{0,0.09,0.4},13.8};
					fogColor[] = {{0.3,0.44,0.74},16.5};
					apertureMin = 12;
					apertureStandard = 18;
					apertureMax = 25;
					standardAvgLum = 150;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
				class Lighting44
				{
					height = -0.1;
					overcast = 0.8;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{0.6,0.8,1},12.04};
					diffuseCloud[] = {{0.6,0.8,1},12.04};
					ambient[] = {{0.4,0.9,1},11.84};
					ambientCloud[] = {{0.4,0.9,1},11.84};
					ambientMid[] = {{0.36,0.72,1},11.4848};
					ambientMidCloud[] = {{0.36,0.72,1},11.4848};
					groundReflection[] = {{0.36,0.72,1},11.02541};
					groundReflectionCloud[] = {{0.36,0.72,1},11.02541};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0,0.09,0.4},13.8};
					skyAroundSun[] = {{0,0.09,0.4},13.8};
					fogColor[] = {{0.3,0.44,0.74},16.5};
					apertureMin = 12;
					apertureStandard = 18;
					apertureMax = 25;
					standardAvgLum = 150;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007,0.01388,0.035};
					mie[] = {0.005,0.005,0.005};
					cloudsColor[] = {{1,1,1},14.8};
					swBrightness = 1;
				};
			};
			class Lighting
			{
				class BrightAlmost
				{
					overcast = 0;
				};
				class Rainy
				{
					overcast = 1;
				};
			};
			class RainConfig
			{
				minCloudiness = 0.5;
				averageCloudLimit = 0.6;
				minProbability = 0.02;
				maxProbability = 0.9;
				minRainDensity = 0.2;
				maxRainDensity = 1;
				rainChange = 60;
				rainFading = 30;
				squareLength = 0.5;
			};
			class RainbowConfig
			{
				distance = 10;
				intensityCoef = 0.35;
				maxCloudiness = 0.55;
			};
		   class Overcast
		   {
				class Weather1
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
					overcast = 0;
					alpha = 0;
					size = 0.1;
					height = 1;
					bright = 0.7;
					speed = 0;
					through = 1;
					diffuse = 1;
					cloudDiffuse = 0.95;
					waves = 0.2;
					lightingOvercast = 0;
				};

				class Weather2
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_almostclear_lco.paa";
					overcast = 0.25;
					alpha = 0.6;
					size = 0.3;
					height = 0.9;
					bright = 0.45;
					speed = 0.25;
					through = 1;
					lightingOvercast = 0.1;
					diffuse = 1;
					cloudDiffuse = 0.95;
					waves = 0.22;
				};
				class Weather3
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
					overcast = 0.4;
					alpha = 0.8;
					size = 0.5;
					height = 0.8;
					bright = 0.4;
					speed = 0.45;
					through = 0.7;
					lightingOvercast = 0.5;
					diffuse = 0.8;
					cloudDiffuse = 0.4;
					waves = 0.32;
				};
				class Weather4
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
					overcast = 0.6;
					alpha = 0.99;
					size = 0.65;
					height = 0.75;
					bright = 0.5;
					speed = 0.55;
					through = 0.4;
					lightingOvercast = 0.85;
					diffuse = 0.6;
					cloudDiffuse = 0.75;
					waves = 0.32;
				};
				class Weather5
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
					overcast = 0.9;
					alpha = 0.55;
					size = 0.8;
					height = 0.7;
					bright = 0.33;
					speed = 0.75;
					through = 0;
					lightingOvercast = 0.98;
					diffuse = 0.3;
					cloudDiffuse = 0.95;
					waves = 0.52;
				};
				class Weather6
				{
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
					overcast = 1;
					alpha = 0.4;
					bright = 0.2;
					size = 1;
					height = 0.6;
					speed = 0.95;
					through = 0;
					lightingOvercast = 0.98;
					diffuse = 0.1;
					cloudDiffuse = 0.95;
					waves = 0.7;
				};
				class Weather7
				{
						sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
						horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
						skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
						overcast = 0.07;
						alpha = 0.5;
						size = 0.2;
						height = 0.95;
						bright = 0.5;
						speed = 0.1;
						through = 1;
						diffuse = 1;
						cloudDiffuse = 0.95;
						waves = 0.2;
						lightingOvercast = 0;
					};
			};
			class SimulWeather
			{
				noiseTexture = "a3\data_f\noise_raw.paa";
				numKeyframesPerDay = 48;
				windSpeedCoef = "10.0f";
				moonIrradianceCoef = "10.0f";
				fadeMaxDistanceKm = 1000.0;
				fadeMaxAltitudeKm = 15.0;
				fadeNumAltitudes = 8;
				fadeNumElevations = 8;
				fadeNumDistances = 8;
				fadeEarthTest = 1;
				autoBrightness = 0;
				autoBrightnessStrength = 0.1;
				cloudGridWidth = 64;
				cloudGridLength = 64;
				cloudGridHeight = 16;
				helperGridElevationSteps = 24;
				helperGridAzimuthSteps = 15;
				helperEffectiveEarthRadius = 1000000;
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
				noisePeriod = 4.0;
				opticalDensity = 0.5;
				alphaSharpness = 0.85;
				selfShadowScale = 0.905;
				mieAsymmetry = 0.5087;
				minimumLightElevationDegrees = 6.0;
				directLightCoef = 1.0;
				indirectLightCoef = 0.04;
				fogStart = 0;
				fogEnd = 50000;
				fogHeight = 2000;
				class DefaultKeyframe
				{
					rayleigh[] = {0.00749,0.01388,0.02878};
					mie[] = {0.0046,0.0046,0.0046};
					haze = 30;
					hazeBaseKm = 5.0;
					hazeScaleKm = 1.0;
					hazeEccentricity = 1;
					brightnessAdjustment = 1.0;
					cloudiness = 0.6;
					cloudBaseKm = 2.85;
					cloudHeightKm = 6.0;
					directLight = 1.0;
					indirectLight = 1.0;
					ambientLight = 0.2;
					noiseOctaves = 4.3;
					noisePersistence = 0.535;
					fractalAmplitude = 2.3;
					fractalWavelength = 240.0;
					extinction = 4.7;
					diffusivity = 0.001;
				};
				class Overcast
				{
					class Weather1: DefaultKeyframe
					{
						overcast = 0.0;
						cloudiness = 0.0;
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
						cloudHeightKm = 8.0;
						seqFileKeyframe = 4;
					};
					class Weather6: DefaultKeyframe
					{
						overcast = 1.0;
						cloudiness = 1.0;
						diffusivity = 0.001;
						extinction = 4.0;
						cloudBaseKm = 1.7;
						cloudHeightKm = 10.0;
						seqFileKeyframe = 4;
					};
				};
			};
			class ThunderboltNorm
			{
				model = "\A3\data_f\blesk1.p3d";
				soundNear[] = {"\A3\Sounds_F\ambient\thunder\thunder_04",2.5118864,1};
				soundFar[] = {"\A3\Sounds_F\ambient\thunder\thunder_02",1.9952624,1};
			};
			class ThunderboltHeavy
			{
				model = "\A3\data_f\blesk2.p3d";
				soundNear[] = {"\A3\Sounds_F\ambient\thunder\thunder_03",3.1622777,1};
				soundFar[] = {"\A3\Sounds_F\ambient\thunder\thunder_01",2.5118864,1};
			};
			class LightningsConfig
			{
				minCloudiness = 0.85;
				minProbability = 0;
				maxProbability = 0.25;
				minCount = 0;
				maxCount = 6;
				scatter = 120;
			};
			class WindConfig
			{
				maxForce = 7;
				windChange = 5;
				minForce = 0;
				minForceScatter = 2;
				maxForceScatter = 5;
				minGustCount = 0;
				maxGustCount = 10;
				gustTimeScatter = 120;
				minGustScatter = 10;
				maxGustScatter = 20;
				gustInfluenceMin = 0.2;
				gustInfluenceMax = 0.4;
				speedOfWindChange = 2;
				minGustValue = 0;
				maxGustValue = 0.7;
			};
			hazeDistCoef = 0.1;
			hazeFogCoef = 0.98;
			hazeBaseHeight = 0;
			hazeBaseBeta0 = 8e-005;
			hazeDensityDecay = 0.00036;
			horizonParallaxCoef = 0.0;
			horizonFogColorationStart = 0.8;
			skyFogColorationStart = 0.7;
			horizonSunColorationIntensity = 0.001;
			aroundSunCoefMultiplier = 1.4;
			aroundSunCoefExponent = 12;
			soundMapSizeCoef = 4;
			satelliteNormalBlendStart = 10;
			satelliteNormalBlendEnd = 100;
			skyObject = "A3\Map_Stratis\data\obloha.p3d";
			horizontObject = "A3\Map_Stratis\data\horizont.p3d";
			skyTexture = "A3\Map_Stratis\data\sky_semicloudy_sky.paa";
			skyTextureR = "A3\Map_Stratis\data\sky_semicloudy_lco.paa";
			terrainBlendMaxDarkenCoef = 0.85;
			terrainBlendMaxBrightenCoef = 0.15;
			class EnvMaps
			{
				class EnvMap1
				{
					texture = "A3\Map_Stratis\data\env_land_ClearSky_ca.paa";
					overcast = 0;
				};
				class EnvMap2
				{
					texture = "A3\Map_Stratis\data\env_land_SemiCloudySky_ca.paa";
					overcast = 0.3;
				};
				class EnvMap3
				{
					texture = "A3\Map_Stratis\data\env_land_OvercastSky_ca.paa";
					overcast = 0.6;
				};
			};
			newRoadsShape = "A3\Map_Malden\Data\roads\roads.shp";
			class OutsideTerrain
			{
				satellite = "A3\map_Stratis\data\s_satout_co.paa";
				enableTerrainSynth = 0;
				class Layers
				{
					class Layer0
					{
						nopx = "A3\Map_Data\gdt_beach_nopx.paa";
						texture = "A3\Map_Data\gdt_beach_co.paa";
					};
				};
				colorOutside[] = {0.227451,0.27451,0.384314,1};
			};
		};

		humidityUpCoef = 0.1;
		humidityDownCoef = 0.05;
		
		class SimulWeather {
			noiseTexture = "a3\data_f\noise_raw.paa";
			numKeyframesPerDay = 48;
			windSpeedCoef = "10.0f";
			moonIrradianceCoef = "10.0f";
			fadeMaxDistanceKm = 1000.0;
			fadeMaxAltitudeKm = 15.0;
			fadeNumAltitudes = 8;
			fadeNumElevations = 8;
			fadeNumDistances = 8;
			fadeEarthTest = 1;
			autoBrightness = 0;
			autoBrightnessStrength = 0.1;
			cloudGridWidth = 64;
			cloudGridLength = 64;
			cloudGridHeight = 16;
			helperGridElevationSteps = 24;
			helperGridAzimuthSteps = 15;
			helperEffectiveEarthRadius = 160000;
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
			noisePeriod = 4.0;
			opticalDensity = 1.5;
			alphaSharpness = 0.5;
			selfShadowScale = 0.05;
			mieAsymmetry = 0.87;
			minimumLightElevationDegrees = 1.0;
			directLightCoef = 0.25;
			indirectLightCoef = 0.025;
			fogStart = 0;
			fogEnd = 2000;
			fogHeight = 2000;
			
			class DefaultKeyframe {
				rayleigh[] = {0.00749, 0.01388, 0.02878};
				mie[] = {0.0046, 0.0046, 0.0046};
				haze = 30;
				hazeBaseKm = 5.0;
				hazeScaleKm = 1.0;
				hazeEccentricity = 1;
				brightnessAdjustment = 1.0;
				cloudiness = 0.6;
				cloudBaseKm = 0.85;
				cloudHeightKm = 8.0;
				directLight = 0.4;
				indirectLight = 1.0;
				ambientLight = 3.0;
				noiseOctaves = 5;
				noisePersistence = 1.0;
				fractalAmplitude = 2.8;
				fractalWavelength = 190.0;
				extinction = 5.0;
				diffusivity = 0.001;
			};
			
			class Overcast {
				class Weather1 : DefaultKeyframe {
					overcast = 0.0;
					cloudiness = 0.0;
					seqFileKeyframe = 0;
				};
				
				class Weather2 : DefaultKeyframe {
					overcast = 0.2;
					cloudiness = 0.3;
					diffusivity = 0.5;
					seqFileKeyframe = 0;
				};
				
				class Weather3 : DefaultKeyframe {
					overcast = 0.4;
					cloudiness = 0.3;
					seqFileKeyframe = 3;
				};
				
				class Weather4 : DefaultKeyframe {
					overcast = 0.5;
					cloudiness = 0.4;
					seqFileKeyframe = 4;
				};
				
				class Weather5 : DefaultKeyframe {
					overcast = 0.8;
					cloudiness = 0.9;
					seqFileKeyframe = 5;
				};
				
				class Weather6 : DefaultKeyframe {
					overcast = 1.0;
					cloudiness = 1.0;
					seqFileKeyframe = 7;
				};
			};
		};
		clutterGrid = 0.6;
		clutterDist = 110;
		noDetailDist = 65;
		fullDetailDist = 10;
		midDetailTexture = "A3\Map_Data\middle_mco.paa";
		minTreesInForestSquare = 4;
		minRocksInRockSquare = 4;
		hazeDistCoef = 0.1;
		hazeFogCoef = 0.98;
		horizonParallaxCoef = 0.045;
		horizonFogColorationStart = "0.8f";
		skyFogColorationStart = "0.7f";
		soundMapSizeCoef = 4;
		satelliteNormalBlendStart = 10;
		satelliteNormalBlendEnd = 100;
		
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
		skyObject = "A3\Map_Stratis\data\obloha.p3d";
		horizontObject = "A3\Map_Stratis\data\horizont.p3d";
		skyTexture = "A3\Map_Stratis\data\sky_semicloudy_sky.paa";
		skyTextureR = "A3\Map_Stratis\data\sky_semicloudy_lco.paa";
		safePositionAnchor[] = {7966, 974};
		safePositionRadius = 1900;
	};
	initWorld = "newhaven";
	demoWorld = "newhaven";
};
