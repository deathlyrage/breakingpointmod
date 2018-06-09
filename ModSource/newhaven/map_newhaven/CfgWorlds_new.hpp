/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgWorlds 
{
	class DefaultWorld 
	{
		cutscenes[] = {};
		
		class Weather {
			class Overcast;	// External class reference
		};
	};
	
	class DefaultLighting;	// External class reference
	
	class CAWorld : DefaultWorld
	{
		class Grid {};
		class DayLightingBrightAlmost;	// External class reference
		class DayLightingRainy;	// External class reference
		class DefaultClutter;	// External class reference

		class Lighting : DefaultLighting 
		{
			moonObjectColorFull[] = {460, 440, 400, 1};
			moonHaloObjectColorFull[] = {465, 477, 475, 1};
			moonsetObjectColor[] = {375, 350, 325, 1};
			moonsetHaloObjectColor[] = {515, 517, 525, 1};
			
			class ThunderBoltLight {
				diffuse[] = {2120, 3170, 5550};
			};
			starEmissivity = 25;
		};
		
		class Weather : Weather 
		{
			class Weather1; // External class reference
			class Weather2; // External class reference
			class Weather3; // External class reference
			class Weather4; // External class reference
			class Weather5; // External class reference
			class Weather6; // External class reference
			
			class LightingNew 
			{
				class Lighting0 
				{
					height = 0;
					overcast = 0.25;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.14, 0.19, 0.3}, 4};
					diffuseCloud[] = {{0.14, 0.19, 0.3}, 0.2};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 0.05};
					ambientMid[] = {{0.1384, 0.1912, 0.2984}, 0.88};
					ambientMidCloud[] = {{0.1384, 0.1912, 0.2984}, 0.044};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.04224};
					bidirect[] = {0.025, 0.025, 0.023};
					bidirectCloud[] = {0.0125, 0.0125, 0.0115};
					sky[] = {0.231, 0.314, 0.467};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.09, 0.137, 0.22}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{0.5, 0.65, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting1 {
					height = 0;
					overcast = 0.25;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting2 {
					height = 0;
					overcast = 0.25;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting3 {
					height = 0;
					overcast = 0.25;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {{0.2, 0.25, 0.45}, 4.73491};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting4 {
					height = 0;
					overcast = 0.25;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.16, 0.18, 0.28}, 3};
					diffuseCloud[] = {{0.16, 0.18, 0.28}, 3};
					ambient[] = {{0.173, 0.239, 0.373}, 4.6};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 4.6};
					ambientMid[] = {{0.173, 0.239, 0.373}, 4.048};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 4.048};
					groundReflection[] = {{0.173, 0.239, 0.373}, 3.88608};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 3.88608};
					bidirect[] = {0.0115, 0.012, 0.0125};
					bidirectCloud[] = {0.0115, 0.012, 0.0125};
					sky[] = {{0.2, 0.298, 0.541}, 4.6};
					skyAroundSun[] = {{0.7, 0.35, 0.28}, 7.63695};
					fogColor[] = {{0.106, 0.161, 0.267}, 4.715};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting5 {
					height = 0;
					overcast = 0.25;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.25, 0.21, 0.2}, 5};
					diffuseCloud[] = {{0.25, 0.21, 0.2}, 5};
					ambient[] = {{0.196, 0.275, 0.42}, 6.9};
					ambientCloud[] = {{0.196, 0.275, 0.42}, 6.9};
					ambientMid[] = {{0.196, 0.275, 0.42}, 6.072};
					ambientMidCloud[] = {{0.196, 0.275, 0.42}, 6.072};
					groundReflection[] = {{0.196, 0.275, 0.42}, 5.82912};
					groundReflectionCloud[] = {{0.196, 0.275, 0.42}, 5.82912};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.188, 0.29, 0.576}, 6.9};
					skyAroundSun[] = {{1.8, 0.42, 0.2}, 12.3177};
					fogColor[] = {{0.11, 0.169, 0.286}, 7.0725};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting6 {
					height = 0;
					overcast = 0.25;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.75, 0.38, 0.22}, 6};
					diffuseCloud[] = {{0.75, 0.38, 0.22}, 6};
					ambient[] = {{0.2497, 0.31, 0.467}, 7.8};
					ambientCloud[] = {{0.2497, 0.31, 0.467}, 7.8};
					ambientMid[] = {{0.2541, 0.314, 0.467}, 6.864};
					ambientMidCloud[] = {{0.2541, 0.314, 0.467}, 6.864};
					groundReflection[] = {{0.235, 0.318, 0.467}, 6.58944};
					groundReflectionCloud[] = {{0.235, 0.318, 0.467}, 6.58944};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.173, 0.282, 0.612}, 7.8};
					skyAroundSun[] = {{2, 0.42, 0.2}, 13.3888};
					fogColor[] = {{0.118, 0.18, 0.31}, 7.995};
					apertureMin = 8;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting7 {
					height = 0;
					overcast = 0.25;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.95, 0.42, 0.22}, 8.4};
					diffuseCloud[] = {{0.95, 0.42, 0.22}, 8.4};
					ambient[] = {{0.306, 0.357, 0.463}, 8.4};
					ambientCloud[] = {{0.306, 0.357, 0.463}, 8.4};
					ambientMid[] = {{0.365, 0.361, 0.396}, 7.392};
					ambientMidCloud[] = {{0.365, 0.361, 0.396}, 7.392};
					groundReflection[] = {{0.416, 0.38, 0.388}, 7.09632};
					groundReflectionCloud[] = {{0.416, 0.38, 0.388}, 7.09632};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.157, 0.275, 0.651}, 8.4};
					skyAroundSun[] = {{2.2, 0.8, 0.2}, 13.3888};
					fogColor[] = {{0.125, 0.192, 0.329}, 8.61};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting8 {
					height = 0;
					overcast = 0.25;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.95, 0.55, 0.35}, 10.2};
					diffuseCloud[] = {{0.95, 0.55, 0.35}, 10.2};
					ambient[] = {{0.337, 0.404, 0.525}, 9.6};
					ambientCloud[] = {{0.337, 0.404, 0.525}, 9.6};
					ambientMid[] = {{0.412, 0.408, 0.443}, 8.448};
					ambientMidCloud[] = {{0.412, 0.408, 0.443}, 8.448};
					groundReflection[] = {{0.475, 0.435, 0.431}, 8.11008};
					groundReflectionCloud[] = {{0.475, 0.435, 0.431}, 8.11008};
					bidirect[] = {0.01375, 0.0132, 0.01265};
					bidirectCloud[] = {0.01375, 0.0132, 0.01265};
					sky[] = {{0.145, 0.263, 0.686}, 9.6};
					skyAroundSun[] = {{0.4, 0.32, 0.6}, 13.3888};
					fogColor[] = {{0.133, 0.204, 0.357}, 9.84};
					apertureMin = 8;
					apertureStandard = 16;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.027, 0.045};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting9 {
					height = 0;
					overcast = 0.25;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.65, 0.45}, 12.3};
					diffuseCloud[] = {{1, 0.65, 0.45}, 12.3};
					ambient[] = {{0.388, 0.471, 0.612}, 10.9};
					ambientCloud[] = {{0.388, 0.471, 0.612}, 10.9};
					ambientMid[] = {{0.482, 0.475, 0.506}, 9.81};
					ambientMidCloud[] = {{0.482, 0.475, 0.506}, 9.81};
					groundReflection[] = {{0.557, 0.51, 0.494}, 9.4176};
					groundReflectionCloud[] = {{0.557, 0.51, 0.494}, 9.4176};
					bidirect[] = {0.01875, 0.018, 0.01725};
					bidirectCloud[] = {0.01875, 0.018, 0.01725};
					sky[] = {{0.129, 0.259, 0.722}, 10.9};
					skyAroundSun[] = {{0.13, 0.25, 0.8}, 13.524};
					fogColor[] = {{0.145, 0.224, 0.396}, 11.1725};
					apertureMin = 20;
					apertureStandard = 25;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.018, 0.04};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 12.24};
					swBrightness = 1;
				};
				
				class Lighting10 {
					height = 0;
					overcast = 0.25;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.75, 0.62}, 15.8};
					diffuseCloud[] = {{1, 0.75, 0.62}, 15.8};
					ambient[] = {{0.435, 0.533, 0.698}, 13.8};
					ambientCloud[] = {{0.435, 0.533, 0.698}, 13.8};
					ambientMid[] = {{0.545, 0.541, 0.569}, 12.696};
					ambientMidCloud[] = {{0.545, 0.541, 0.569}, 12.696};
					groundReflection[] = {{0.635, 0.58, 0.557}, 12.1882};
					groundReflectionCloud[] = {{0.635, 0.58, 0.557}, 12.1882};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.118, 0.251, 0.753}, 13.8};
					skyAroundSun[] = {{0.115, 0.245, 0.8}, 13.662};
					fogColor[] = {{0.15, 0.251, 0.488}, 14.145};
					apertureMin = 45;
					apertureStandard = 60;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.4};
					swBrightness = 1;
				};
				
				class Lighting11 {
					height = 0;
					overcast = 0.25;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.87, 0.85}, 17.2};
					diffuseCloud[] = {{1, 0.87, 0.85}, 17.2};
					ambient[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientCloud[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientMid[] = {{0.635, 0.635, 0.663}, 14.504};
					ambientMidCloud[] = {{0.635, 0.635, 0.663}, 14.504};
					groundReflection[] = {{0.745, 0.671, 0.643}, 14.2139};
					groundReflectionCloud[] = {{0.745, 0.671, 0.643}, 14.2139};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting12 {
					height = 0;
					overcast = 0.25;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.87, 0.85}, 17.2};
					diffuseCloud[] = {{1, 0.87, 0.85}, 17.2};
					ambient[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientCloud[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientMid[] = {{0.635, 0.635, 0.663}, 14.504};
					ambientMidCloud[] = {{0.635, 0.635, 0.663}, 14.504};
					groundReflection[] = {{0.745, 0.671, 0.643}, 14.2139};
					groundReflectionCloud[] = {{0.745, 0.671, 0.643}, 14.2139};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting13 {
					height = 0;
					overcast = 0.6;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.14, 0.19, 0.3}, 4};
					diffuseCloud[] = {{0.14, 0.19, 0.3}, 3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.1384, 0.1912, 0.2984}, 0.88};
					ambientMidCloud[] = {{0.1384, 0.1912, 0.2984}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0.025, 0.025, 0.023};
					bidirectCloud[] = {0.0245, 0.0245, 0.02254};
					sky[] = {0.231, 0.314, 0.467};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.09, 0.137, 0.22}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{0.5, 0.65, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting14 {
					height = 0;
					overcast = 0.6;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting15 {
					height = 0;
					overcast = 0.6;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting16 {
					height = 0;
					overcast = 0.6;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.1, 0.18, 0.3};
					diffuseCloud[] = {0.1, 0.18, 0.3};
					ambient[] = {{0.173, 0.239, 0.373}, 1};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.88};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.88};
					groundReflection[] = {{0.173, 0.239, 0.373}, 0.8448};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 0.8448};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {{0.2, 0.25, 0.45}, 4.73491};
					fogColor[] = {{0.094, 0.141, 0.231}, 0.025};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting17 {
					height = 0;
					overcast = 0.6;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.16, 0.18, 0.28}, 2.25};
					diffuseCloud[] = {{0.16, 0.18, 0.28}, 1.6875};
					ambient[] = {{0.173, 0.239, 0.373}, 4.6};
					ambientCloud[] = {{0.173, 0.239, 0.373}, 4.6};
					ambientMid[] = {{0.173, 0.239, 0.373}, 4.048};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 4.048};
					groundReflection[] = {{0.173, 0.239, 0.373}, 3.88608};
					groundReflectionCloud[] = {{0.173, 0.239, 0.373}, 3.88608};
					bidirect[] = {0.0115, 0.012, 0.0125};
					bidirectCloud[] = {0.01127, 0.01176, 0.01225};
					sky[] = {{0.2, 0.298, 0.541}, 4.6};
					skyAroundSun[] = {{0.7, 0.35, 0.28}, 7.63695};
					fogColor[] = {{0.106, 0.161, 0.267}, 4.715};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting18 {
					height = 0;
					overcast = 0.6;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.25, 0.21, 0.2}, 3.75};
					diffuseCloud[] = {{0.25, 0.21, 0.2}, 2.8125};
					ambient[] = {{0.196, 0.275, 0.42}, 6.9};
					ambientCloud[] = {{0.196, 0.275, 0.42}, 6.9};
					ambientMid[] = {{0.196, 0.275, 0.42}, 6.072};
					ambientMidCloud[] = {{0.196, 0.275, 0.42}, 6.072};
					groundReflection[] = {{0.196, 0.275, 0.42}, 5.82912};
					groundReflectionCloud[] = {{0.196, 0.275, 0.42}, 5.82912};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.188, 0.29, 0.576}, 6.9};
					skyAroundSun[] = {{1.8, 0.42, 0.2}, 12.3177};
					fogColor[] = {{0.11, 0.169, 0.286}, 7.0725};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting19 {
					height = 0;
					overcast = 0.6;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.75, 0.38, 0.22}, 4.5};
					diffuseCloud[] = {{0.75, 0.38, 0.22}, 3.375};
					ambient[] = {{0.2497, 0.31, 0.467}, 7.8};
					ambientCloud[] = {{0.2497, 0.31, 0.467}, 7.8};
					ambientMid[] = {{0.2541, 0.314, 0.467}, 6.864};
					ambientMidCloud[] = {{0.2541, 0.314, 0.467}, 6.864};
					groundReflection[] = {{0.235, 0.318, 0.467}, 6.58944};
					groundReflectionCloud[] = {{0.235, 0.318, 0.467}, 6.58944};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.173, 0.282, 0.612}, 7.8};
					skyAroundSun[] = {{2, 0.42, 0.2}, 13.3888};
					fogColor[] = {{0.118, 0.18, 0.31}, 7.995};
					apertureMin = 8;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting20 {
					height = 0;
					overcast = 0.6;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.95, 0.42, 0.22}, 6.72};
					diffuseCloud[] = {{0.95, 0.42, 0.22}, 5.04};
					ambient[] = {{0.306, 0.357, 0.463}, 8.4};
					ambientCloud[] = {{0.306, 0.357, 0.463}, 8.4};
					ambientMid[] = {{0.365, 0.361, 0.396}, 7.392};
					ambientMidCloud[] = {{0.365, 0.361, 0.396}, 7.392};
					groundReflection[] = {{0.416, 0.38, 0.388}, 7.09632};
					groundReflectionCloud[] = {{0.416, 0.38, 0.388}, 7.09632};
					bidirect[] = {0.023, 0.024, 0.025};
					bidirectCloud[] = {0.023, 0.024, 0.025};
					sky[] = {{0.157, 0.275, 0.651}, 8.4};
					skyAroundSun[] = {{2.2, 0.8, 0.2}, 13.3888};
					fogColor[] = {{0.125, 0.192, 0.329}, 8.61};
					apertureMin = 8;
					apertureStandard = 10;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting21 {
					height = 0;
					overcast = 0.6;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.95, 0.55, 0.35}, 10.2};
					diffuseCloud[] = {{0.95, 0.55, 0.35}, 7.65};
					ambient[] = {{0.337, 0.404, 0.525}, 9.6};
					ambientCloud[] = {{0.337, 0.404, 0.525}, 9.6};
					ambientMid[] = {{0.412, 0.408, 0.443}, 8.448};
					ambientMidCloud[] = {{0.412, 0.408, 0.443}, 8.448};
					groundReflection[] = {{0.475, 0.435, 0.431}, 8.11008};
					groundReflectionCloud[] = {{0.475, 0.435, 0.431}, 8.11008};
					bidirect[] = {0.01375, 0.0132, 0.01265};
					bidirectCloud[] = {0.01375, 0.0132, 0.01265};
					sky[] = {{0.145, 0.263, 0.686}, 9.6};
					skyAroundSun[] = {{0.4, 0.32, 0.6}, 13.3888};
					fogColor[] = {{0.133, 0.204, 0.357}, 9.84};
					apertureMin = 8;
					apertureStandard = 16;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.027, 0.045};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting22 {
					height = 0;
					overcast = 0.6;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.65, 0.45}, 12.3};
					diffuseCloud[] = {{1, 0.65, 0.45}, 9.225};
					ambient[] = {{0.388, 0.471, 0.612}, 10.9};
					ambientCloud[] = {{0.388, 0.471, 0.612}, 10.9};
					ambientMid[] = {{0.482, 0.475, 0.506}, 9.81};
					ambientMidCloud[] = {{0.482, 0.475, 0.506}, 9.81};
					groundReflection[] = {{0.557, 0.51, 0.494}, 9.4176};
					groundReflectionCloud[] = {{0.557, 0.51, 0.494}, 9.4176};
					bidirect[] = {0.01875, 0.018, 0.01725};
					bidirectCloud[] = {0.01875, 0.018, 0.01725};
					sky[] = {{0.129, 0.259, 0.722}, 10.9};
					skyAroundSun[] = {{0.13, 0.25, 0.8}, 13.524};
					fogColor[] = {{0.145, 0.224, 0.396}, 11.1725};
					apertureMin = 20;
					apertureStandard = 25;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.018, 0.04};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 12.24};
					swBrightness = 1;
				};
				
				class Lighting23 {
					height = 0;
					overcast = 0.6;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.75, 0.62}, 15.8};
					diffuseCloud[] = {{1, 0.75, 0.62}, 11.85};
					ambient[] = {{0.435, 0.533, 0.698}, 13.8};
					ambientCloud[] = {{0.435, 0.533, 0.698}, 13.8};
					ambientMid[] = {{0.545, 0.541, 0.569}, 12.696};
					ambientMidCloud[] = {{0.545, 0.541, 0.569}, 12.696};
					groundReflection[] = {{0.635, 0.58, 0.557}, 12.1882};
					groundReflectionCloud[] = {{0.635, 0.58, 0.557}, 12.1882};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.118, 0.251, 0.753}, 13.8};
					skyAroundSun[] = {{0.115, 0.245, 0.8}, 13.662};
					fogColor[] = {{0.15, 0.251, 0.488}, 14.145};
					apertureMin = 45;
					apertureStandard = 60;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.4};
					swBrightness = 1;
				};
				
				class Lighting24 {
					height = 0;
					overcast = 0.6;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.87, 0.85}, 17};
					diffuseCloud[] = {{1, 0.87, 0.85}, 12.75};
					ambient[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientCloud[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientMid[] = {{0.635, 0.635, 0.663}, 13.616};
					ambientMidCloud[] = {{0.635, 0.635, 0.663}, 13.616};
					groundReflection[] = {{0.745, 0.671, 0.643}, 14.2139};
					groundReflectionCloud[] = {{0.745, 0.671, 0.643}, 14.2139};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 13.9564};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting25 {
					height = 0;
					overcast = 0.6;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{1, 0.87, 0.85}, 17};
					diffuseCloud[] = {{1, 0.87, 0.85}, 13.94};
					ambient[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientCloud[] = {{0.498, 0.602, 0.77}, 14.8};
					ambientMid[] = {{0.635, 0.635, 0.663}, 14.504};
					ambientMidCloud[] = {{0.635, 0.635, 0.663}, 14.504};
					groundReflection[] = {{0.745, 0.671, 0.643}, 14.2139};
					groundReflectionCloud[] = {{0.745, 0.671, 0.643}, 14.2139};
					bidirect[] = {0.025, 0.024, 0.018};
					bidirectCloud[] = {0.025, 0.024, 0.018};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 15};
					apertureMin = 70;
					apertureStandard = 120;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting26 {
					height = 0;
					overcast = 0.85;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.09, 0.137, 0.22}, 1};
					diffuseCloud[] = {{0, 0, 0}, 0.75};
					ambient[] = {{0.09, 0.137, 0.22}, 1};
					ambientCloud[] = {{0.09, 0.137, 0.22}, 1};
					ambientMid[] = {{0.09, 0.137, 0.22}, 0.8624};
					ambientMidCloud[] = {{0.09, 0.137, 0.22}, 0.8624};
					groundReflection[] = {{0.09, 0.137, 0.22}, 0.758912};
					groundReflectionCloud[] = {{0.09, 0.137, 0.22}, 0.758912};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {0.231, 0.314, 0.467};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {0.09, 0.137, 0.22};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting27 {
					height = 0;
					overcast = 0.85;
					sunAngle = -12;
					sunOrMoon = 0;
					diffuse[] = {0.16954, 0.239, 0.37673};
					diffuseCloud[] = {0.042385, 0.05975, 0.094183};
					ambient[] = {{0.16954, 0.239, 0.37673}, 1};
					ambientCloud[] = {{0.16954, 0.239, 0.37673}, 1};
					ambientMid[] = {{0.173, 0.239, 0.373}, 0.8624};
					ambientMidCloud[] = {{0.173, 0.239, 0.373}, 0.8624};
					groundReflection[] = {{0.14705, 0.20315, 0.31705}, 0.758912};
					groundReflectionCloud[] = {{0.14705, 0.20315, 0.31705}, 0.758912};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {0.122, 0.169, 0.255};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting28 {
					height = 0;
					overcast = 0.85;
					sunAngle = -11;
					sunOrMoon = 0.5;
					diffuse[] = {0.129, 0.18, 0.271};
					diffuseCloud[] = {0.03225, 0.045, 0.06775};
					ambient[] = {{0.129, 0.18, 0.271}, 1};
					ambientCloud[] = {{0.129, 0.18, 0.271}, 1};
					ambientMid[] = {{0.129, 0.184, 0.267}, 0.8624};
					ambientMidCloud[] = {{0.129, 0.184, 0.267}, 0.8624};
					groundReflection[] = {{0.125, 0.176, 0.263}, 0.758912};
					groundReflectionCloud[] = {{0.125, 0.176, 0.263}, 0.758912};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {0.2, 0.25, 0.45};
					fogColor[] = {0.122, 0.169, 0.255};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting29 {
					height = 0;
					overcast = 0.85;
					sunAngle = -10;
					sunOrMoon = 1;
					diffuse[] = {0.129, 0.18, 0.271};
					diffuseCloud[] = {0.03225, 0.045, 0.06775};
					ambient[] = {{0.129, 0.18, 0.271}, 1};
					ambientCloud[] = {{0.129, 0.18, 0.271}, 1};
					ambientMid[] = {{0.129, 0.184, 0.267}, 0.8624};
					ambientMidCloud[] = {{0.129, 0.184, 0.267}, 0.8624};
					groundReflection[] = {{0.125, 0.176, 0.263}, 0.758912};
					groundReflectionCloud[] = {{0.125, 0.176, 0.263}, 0.758912};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.212, 0.302, 0.51}, 1};
					skyAroundSun[] = {{0.2, 0.25, 0.45}, 4.73491};
					fogColor[] = {0.122, 0.169, 0.255};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting30 {
					height = 0;
					overcast = 0.85;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.157, 0.212, 0.306}, 0.5625};
					diffuseCloud[] = {{0.03925, 0.053, 0.0765}, 0.39375};
					ambient[] = {{0.157, 0.212, 0.306}, 3.22};
					ambientCloud[] = {{0.157, 0.212, 0.306}, 3.22};
					ambientMid[] = {{0.157, 0.208, 0.298}, 3.96704};
					ambientMidCloud[] = {{0.157, 0.208, 0.298}, 3.96704};
					groundReflection[] = {{0.149, 0.204, 0.29}, 3.64968};
					groundReflectionCloud[] = {{0.149, 0.204, 0.29}, 3.64968};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.2, 0.298, 0.541}, 4.6};
					skyAroundSun[] = {{0.7, 0.35, 0.28}, 7.63695};
					fogColor[] = {{0.141, 0.192, 0.282}, 3.96704};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting31 {
					height = 0;
					overcast = 0.85;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.184, 0.247, 0.341}, 0.9375};
					diffuseCloud[] = {{0.046, 0.06175, 0.08525}, 0.65625};
					ambient[] = {{0.184, 0.247, 0.341}, 6.9};
					ambientCloud[] = {{0.184, 0.247, 0.341}, 6.9};
					ambientMid[] = {{0.184, 0.243, 0.329}, 5.95056};
					ambientMidCloud[] = {{0.184, 0.243, 0.329}, 5.95056};
					groundReflection[] = {{0.176, 0.231, 0.322}, 5.59353};
					groundReflectionCloud[] = {{0.176, 0.231, 0.322}, 5.59353};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.188, 0.29, 0.576}, 6.9};
					skyAroundSun[] = {{1.8, 0.42, 0.2}, 12.3177};
					fogColor[] = {{0.165, 0.22, 0.31}, 5.95056};
					apertureMin = 7;
					apertureStandard = 7;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting32 {
					height = 0;
					overcast = 0.85;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.216, 0.286, 0.384}, 1.125};
					diffuseCloud[] = {{0.054, 0.0715, 0.096}, 0.7875};
					ambient[] = {{0.216, 0.286, 0.384}, 7.8};
					ambientCloud[] = {{0.216, 0.286, 0.384}, 7.8};
					ambientMid[] = {{0.22, 0.278, 0.365}, 6.72672};
					ambientMidCloud[] = {{0.22, 0.278, 0.365}, 6.72672};
					groundReflection[] = {{0.204, 0.267, 0.353}, 6.45765};
					groundReflectionCloud[] = {{0.204, 0.267, 0.353}, 6.45765};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.173, 0.282, 0.612}, 7.8};
					skyAroundSun[] = {{2, 0.42, 0.2}, 13.3888};
					fogColor[] = {{0.188, 0.247, 0.341}, 6.72672};
					apertureMin = 8;
					apertureStandard = 8;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting33 {
					height = 0;
					overcast = 0.85;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.255, 0.325, 0.42}, 1.68};
					diffuseCloud[] = {{0.06375, 0.08125, 0.105}, 1.176};
					ambient[] = {{0.255, 0.325, 0.42}, 8.4};
					ambientCloud[] = {{0.255, 0.325, 0.42}, 8.4};
					ambientMid[] = {{0.259, 0.314, 0.396}, 7.24416};
					ambientMidCloud[] = {{0.259, 0.314, 0.396}, 7.24416};
					groundReflection[] = {{0.239, 0.294, 0.376}, 7.09928};
					groundReflectionCloud[] = {{0.239, 0.294, 0.376}, 7.09928};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.157, 0.275, 0.651}, 8.4};
					skyAroundSun[] = {{2.2, 0.8, 0.2}, 13.3888};
					fogColor[] = {{0.216, 0.275, 0.373}, 7.24416};
					apertureMin = 8;
					apertureStandard = 8;
					apertureMax = 24;
					standardAvgLum = 50;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting34 {
					height = 0;
					overcast = 0.85;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.298, 0.365, 0.451}, 2.55};
					diffuseCloud[] = {{0.0745, 0.09125, 0.11275}, 1.785};
					ambient[] = {{0.298, 0.365, 0.451}, 9.6};
					ambientCloud[] = {{0.298, 0.365, 0.451}, 9.6};
					ambientMid[] = {{0.302, 0.349, 0.416}, 8.27904};
					ambientMidCloud[] = {{0.302, 0.349, 0.416}, 8.27904};
					groundReflection[] = {{0.275, 0.318, 0.384}, 8.11346};
					groundReflectionCloud[] = {{0.275, 0.318, 0.384}, 8.11346};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.145, 0.263, 0.686}, 9.6};
					skyAroundSun[] = {{0.4, 0.32, 0.6}, 13.3888};
					fogColor[] = {{0.243, 0.306, 0.408}, 8.27904};
					apertureMin = 8;
					apertureStandard = 14;
					apertureMax = 26;
					standardAvgLum = 100;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.027, 0.045};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting35 {
					height = 0;
					overcast = 0.85;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{0.376, 0.431, 0.506}, 3.075};
					diffuseCloud[] = {{0.094, 0.10775, 0.1265}, 2.1525};
					ambient[] = {{0.376, 0.431, 0.506}, 10.9};
					ambientCloud[] = {{0.376, 0.431, 0.506}, 10.9};
					ambientMid[] = {{0.38, 0.408, 0.447}, 9.6138};
					ambientMidCloud[] = {{0.38, 0.408, 0.447}, 9.6138};
					groundReflection[] = {{0.329, 0.361, 0.396}, 9.42152};
					groundReflectionCloud[] = {{0.329, 0.361, 0.396}, 9.42152};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.129, 0.259, 0.722}, 10.9};
					skyAroundSun[] = {{0.13, 0.25, 0.8}, 13.524};
					fogColor[] = {{0.286, 0.353, 0.463}, 9.6138};
					apertureMin = 20;
					apertureStandard = 22;
					apertureMax = 35;
					standardAvgLum = 250;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.018, 0.04};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 12.24};
					swBrightness = 1;
				};
				
				class Lighting36 {
					height = 0;
					overcast = 0.85;
					sunAngle = 24;
					sunOrMoon = 1;
					diffuse[] = {{0.447, 0.494, 0.557}, 3.95};
					diffuseCloud[] = {{0, 0, 0}, 2.765};
					ambient[] = {{0.447, 0.494, 0.557}, 13.8};
					ambientCloud[] = {{0.447, 0.494, 0.557}, 13.8};
					ambientMid[] = {{0.455, 0.467, 0.475}, 12.4421};
					ambientMidCloud[] = {{0.455, 0.467, 0.475}, 12.4421};
					groundReflection[] = {{0.388, 0.396, 0.408}, 12.1932};
					groundReflectionCloud[] = {{0.388, 0.396, 0.408}, 12.1932};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.118, 0.251, 0.753}, 13.8};
					skyAroundSun[] = {{0.115, 0.245, 0.8}, 13.662};
					fogColor[] = {{0.333, 0.404, 0.518}, 12.4421};
					apertureMin = 45;
					apertureStandard = 50;
					apertureMax = 80;
					standardAvgLum = 800;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.4};
					swBrightness = 1;
				};
				
				class Lighting37 {
					height = 0;
					overcast = 0.85;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.506, 0.553, 0.608}, 4.25};
					diffuseCloud[] = {0.1265, 0.13825, 0.152};
					ambient[] = {{0.506, 0.553, 0.608}, 14.8};
					ambientCloud[] = {{0.506, 0.553, 0.608}, 14.8};
					ambientMid[] = {{0.514, 0.518, 0.514}, 13.3437};
					ambientMidCloud[] = {{0.514, 0.518, 0.514}, 13.3437};
					groundReflection[] = {{0.435, 0.439, 0.439}, 13.0768};
					groundReflectionCloud[] = {{0.435, 0.439, 0.439}, 13.0768};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.369, 0.447, 0.565}, 13.3437};
					apertureMin = 70;
					apertureStandard = 100;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting38 {
					height = 0;
					overcast = 0.85;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{0.549, 0.596, 0.651}, 4.25};
					diffuseCloud[] = {0.13725, 0.149, 0.16275};
					ambient[] = {{0.549, 0.596, 0.651}, 14.8};
					ambientCloud[] = {{0.549, 0.596, 0.651}, 14.8};
					ambientMid[] = {{0.557, 0.557, 0.585}, 14.2139};
					ambientMidCloud[] = {{0.557, 0.557, 0.585}, 14.2139};
					groundReflection[] = {{0.471, 0.471, 0.463}, 13.9296};
					groundReflectionCloud[] = {{0.471, 0.471, 0.463}, 13.9296};
					bidirect[] = {0.0117, 0.0117, 0.0117};
					bidirectCloud[] = {0.0117, 0.0117, 0.0117};
					sky[] = {{0.02, 0.12, 0.8}, 13.8};
					skyAroundSun[] = {{0.02, 0.12, 0.8}, 13.8};
					fogColor[] = {{0.4, 0.48, 0.6}, 15};
					apertureMin = 70;
					apertureStandard = 110;
					apertureMax = 120;
					standardAvgLum = 8000;
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 0.5;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting39 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = -24;
					sunOrMoon = 0;
					diffuse[] = {{0.6, 0.8, 1}, 2.8};
					diffuseCloud[] = {{0.6, 0.8, 1}, 2.8};
					ambient[] = {{0.4, 0.9, 1}, 0.84};
					ambientCloud[] = {{0.4, 0.9, 1}, 0.84};
					ambientMid[] = {{0.24, 0.63, 1}, 0.9072};
					ambientMidCloud[] = {{0.24, 0.63, 1}, 0.9072};
					groundReflection[] = {{0.24, 0.63, 1}, 0.870912};
					groundReflectionCloud[] = {{0.24, 0.63, 1}, 0.870912};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0, 0.2355, 0.2335};
					skyAroundSun[] = {0, 0.2355, 0.2335};
					fogColor[] = {{0.09, 0.137, 0.22}, 0.0275};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting40 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {{0.6, 0.8, 1}, 2.1};
					diffuseCloud[] = {{0.6, 0.8, 1}, 2.1};
					ambient[] = {{0.4, 0.9, 1}, 3.68};
					ambientCloud[] = {{0.4, 0.9, 1}, 3.68};
					ambientMid[] = {{0.24, 0.63, 1}, 3.9744};
					ambientMidCloud[] = {{0.24, 0.63, 1}, 3.9744};
					groundReflection[] = {{0.24, 0.63, 1}, 3.81542};
					groundReflectionCloud[] = {{0.24, 0.63, 1}, 3.81542};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0, 0.2235, 0.2705}, 4.232};
					skyAroundSun[] = {{0, 0.2235, 0.2705}, 7.63695};
					fogColor[] = {{0.106, 0.161, 0.267}, 4.715};
					apertureMin = 6;
					apertureStandard = 6;
					apertureMax = 18;
					standardAvgLum = 4;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting41 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.6, 0.8, 1}, 3.5};
					diffuseCloud[] = {{0.6, 0.8, 1}, 3.5};
					ambient[] = {{0.4, 0.9, 1}, 5.52};
					ambientCloud[] = {{0.4, 0.9, 1}, 5.52};
					ambientMid[] = {{0.24, 0.63, 1}, 5.9616};
					ambientMidCloud[] = {{0.24, 0.63, 1}, 5.9616};
					groundReflection[] = {{0.24, 0.63, 1}, 5.72314};
					groundReflectionCloud[] = {{0.24, 0.63, 1}, 5.72314};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0, 0.2175, 0.288}, 6.348};
					skyAroundSun[] = {{0, 0.2175, 0.288}, 12.3177};
					fogColor[] = {{0.11, 0.169, 0.286}, 7.0725};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting42 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.6, 0.8, 1}, 4.2};
					diffuseCloud[] = {{0.6, 0.8, 1}, 4.2};
					ambient[] = {{0.4, 0.9, 1}, 6.24};
					ambientCloud[] = {{0.4, 0.9, 1}, 6.24};
					ambientMid[] = {{0.24, 0.63, 1}, 6.7392};
					ambientMidCloud[] = {{0.24, 0.63, 1}, 6.7392};
					groundReflection[] = {{0.24, 0.63, 1}, 6.46963};
					groundReflectionCloud[] = {{0.24, 0.63, 1}, 6.46963};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0, 0.2115, 0.306}, 7.176};
					skyAroundSun[] = {{0, 0.2115, 0.306}, 13.3888};
					fogColor[] = {{0.118, 0.18, 0.31}, 7.995};
					apertureMin = 8;
					apertureStandard = 9;
					apertureMax = 22;
					standardAvgLum = 45;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.038, 0.0675};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 11.016};
					swBrightness = 1;
				};
				
				class Lighting43 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.6, 0.8, 1}, 12.04};
					diffuseCloud[] = {{0.6, 0.8, 1}, 12.04};
					ambient[] = {{0.4, 0.9, 1}, 11.84};
					ambientCloud[] = {{0.4, 0.9, 1}, 11.84};
					ambientMid[] = {{0.36, 0.72, 1}, 11.4848};
					ambientMidCloud[] = {{0.36, 0.72, 1}, 11.4848};
					groundReflection[] = {{0.36, 0.72, 1}, 11.0254};
					groundReflectionCloud[] = {{0.36, 0.72, 1}, 11.0254};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0, 0.09, 0.4}, 13.8};
					skyAroundSun[] = {{0, 0.09, 0.4}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 16.5};
					apertureMin = 12;
					apertureStandard = 18;
					apertureMax = 25;
					standardAvgLum = 150;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				
				class Lighting44 {
					height = -0.1;
					overcast = 0.8;
					sunAngle = 90;
					sunOrMoon = 1;
					diffuse[] = {{0.6, 0.8, 1}, 12.04};
					diffuseCloud[] = {{0.6, 0.8, 1}, 12.04};
					ambient[] = {{0.4, 0.9, 1}, 11.84};
					ambientCloud[] = {{0.4, 0.9, 1}, 11.84};
					ambientMid[] = {{0.36, 0.72, 1}, 11.4848};
					ambientMidCloud[] = {{0.36, 0.72, 1}, 11.4848};
					groundReflection[] = {{0.36, 0.72, 1}, 11.0254};
					groundReflectionCloud[] = {{0.36, 0.72, 1}, 11.0254};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0, 0.09, 0.4}, 13.8};
					skyAroundSun[] = {{0, 0.09, 0.4}, 13.8};
					fogColor[] = {{0.3, 0.44, 0.74}, 16.5};
					apertureMin = 12;
					apertureStandard = 18;
					apertureMax = 25;
					standardAvgLum = 150;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.007, 0.01388, 0.035};
					mie[] = {0.005, 0.005, 0.005};
					cloudsColor[] = {{1, 1, 1}, 14.8};
					swBrightness = 1;
				};
				class Lighting45 {};
				class Lighting46 {};
				class Lighting47 {};
				class Lighting48 {};
				class Lighting49 {};
				class Lighting50 {};
				class Lighting51 {};
				class Lighting52 {};
				class Lighting53 {};
				class Lighting54 {};
				class Lighting55 {};
				class Lighting56 {};
				class Lighting57 {};
				class Lighting58 {};
				class Lighting59 {};
				class Lighting60 {};
				class Lighting61 {};
				class Lighting62 {};
				class Lighting63 {};
				class Lighting64 {};
				class Lighting65 {};
				class Lighting66 {};
				class Lighting67 {};
				class Lighting68 {};
				class Lighting69 {};
				class Lighting70 {};
				class Lighting71 {};
			};
			
			class Overcast : Overcast {
				class Weather1 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
				};
				
				class Weather7 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
					overcast = 0.07;
				};
				
				class Weather2 : Weather2 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_almostclear_lco.paa";
				};
				
				class Weather3 : Weather3 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
				};
				
				class Weather4 : Weather4 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
				};
				
				class Weather5 : Weather5 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
				};
				
				class Weather6 : Weather5 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
				};
			};
		};
		
		//class DayLightingBrightAlmost : DayLightingBrightAlmost {};
		//class DayLightingRainy : DayLightingRainy {};
		
		class Sea;	// External class reference
		
		class Underwater {
			waterColor[] = {0.04, 0.16, 0.22};
			deepWaterColor[] = {0, 0.001, 0.009};
			surfaceColor[] = {0.04, 0.16, 0.22};
			deepSurfaceColor[] = {0, 0.001, 0.009};
		};
		
		class SimulWeather {
			alphaSharpness = 0.85;
			cloudGridLength = 64;
			cloudGridWidth = 64;
			directLightCoef = 1;
			fogEnd = 50000;
			indirectLightCoef = 0.04;
			mieAsymmetry = 0.5087;
			minimumLightElevationDegrees = 6;
			opticalDensity = 0.5;
			selfShadowScale = 0.905;
			
			class DefaultKeyframe {
				ambientLight = 0.2;
				cloudBaseKm = 2.85;
				cloudHeightKm = 6;
				directLight = 1;
				extinction = 4.7;
				fractalAmplitude = 2.3;
				fractalWavelength = 240;
				noiseOctaves = 4.3;
				noisePersistence = 0.535;
			};
			
			class Overcast {
				class Weather1 : DefaultKeyframe {};
				
				class Weather2 : DefaultKeyframe {
					cloudiness = 0.25;
					diffusivity = 0.001;
				};
				
				class Weather3 : DefaultKeyframe {
					cloudiness = 0.45;
				};
				
				class Weather4 : DefaultKeyframe {
					cloudiness = 0.46;
				};
				
				class Weather5 : DefaultKeyframe {
					cloudiness = 0.8;
					seqFileKeyframe = 4;
				};
				
				class Weather6 : DefaultKeyframe {
					seqFileKeyframe = 4;
				};
			};
		};
		class envTexture {};
		forecastFogDecay = 0.014;
		hazeBaseBeta0 = 8e-005;
		hazeBaseHeight = 0;
		hazeDensityDecay = 0.00036;
		horizonParallaxCoef = 0;
		startFogDecay = 0.014;
	};
	
	class newhaven : CAWorld 
	{
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
		
		class Lighting : DefaultLighting {
			groundReflection[] = {0.132, 0.133, 0.122};
		};
		
		class DayLightingBrightAlmost : DayLightingBrightAlmost {
			deepNight[] = {-15, {0.005, 0.01, 0.01}, {0.0, 0.002, 0.003}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.002, 0.003}, {0.0, 0.002, 0.003}, 0};
			fullNight[] = {-5, {0.182, 0.213, 0.25}, {0.05, 0.111, 0.221}, {0.04, 0.034, 0.004}, {0.039, 0.049, 0.072}, {0.082, 0.128, 0.185}, {0.283, 0.35, 0.431}, 0};
			sunMoon[] = {-3.75, {0.377, 0.441, 0.518}, {0.103, 0.227, 0.453}, {0.04, 0.034, 0.004}, {0.039, 0.049, 0.072}, {0.174, 0.274, 0.395}, {0.582, 0.72, 0.887}, 0.5};
			earlySun[] = {-2.5, {0.675, 0.69, 0.784}, {0.22, 0.322, 0.471}, {0.04, 0.034, 0.004}, {0.039, 0.049, 0.072}, {0.424, 0.549, 0.745}, {0.698, 0.753, 0.894}, 1};
			sunrise[] = {0, {0.675, 0.69, 0.784}, {0.478, 0.51, 0.659}, {0.2, 0.19, 0.07}, {0.124, 0.161, 0.236}, {{0.847, 0.855, 0.965}, 0.2}, {{0.933, 0.949, 0.996}, 2}, 1};
			earlyMorning[] = {3, {{0.844, 0.61, 0.469}, 0.8}, {0.424, 0.557, 0.651}, {{1, 0.45, 0.2}, 1}, {0.12, 0.26, 0.38}, {{0.428, 0.579, 0.743}, 2}, {{0.844, 0.61, 0.469}, 2.7}, 1};
			midMorning[] = {8, {{0.822, 0.75, 0.646}, 3.8}, {{0.383, 0.58, 0.858}, 1.3}, {{1.3, 0.9, 0.61}, 2.8}, {{0.12, 0.18, 0.28}, 0.5}, {{0.322, 0.478, 0.675}, 3.5}, {{1.0, 0.929, 0.815}, 4.7}, 1};
			morning[] = {16, {{1, 0.95, 0.91}, 12.2}, {{0.12, 0.18, 0.28}, 9.2}, {{1, 0.95, 0.91}, 11.2}, {{0.12, 0.18, 0.28}, 8.5}, {{0.14, 0.18, 0.24}, 11.0}, {{0.5, 0.6, 0.9}, 13.2}, 1};
			noon[] = {45, {{0.98, 0.94, 0.94}, 13.8}, {{0.2, 0.27, 0.35}, 10.8}, {{0.98, 0.94, 0.94}, 13.8}, {{0.2, 0.27, 0.35}, 10.8}, {{0.5, 0.64, 1.0}, 12.0}, {{0.5, 0.5, 0.5}, 14.8}, 1, 0.5, 0.4, 0.5, 0.4};
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
		
		class Weather : Weather {
			class LightingNew {
				class Lighting0 {
					height = 0;
					overcast = 0.6;
					sunAngle = -10;
					sunOrMoon = 0;
					diffuse[] = {0.0297, 0.0539, 0.16005};
					diffuseCloud[] = {0.02673, 0.04851, 0.144045};
					ambient[] = {0, 0.00055, 0.0063};
					ambientCloud[] = {0, 0.000495, 0.00567};
					ambientMid[] = {0, 0.00033, 0.00378};
					ambientMidCloud[] = {0, 0.000297, 0.003402};
					groundReflection[] = {0, 0.000198, 0.002268};
					groundReflectionCloud[] = {0, 0.000178, 0.002041};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.002, 0.002, 0.0025};
					skyAroundSun[] = {3.2e-005, 0.000404, 0.000938};
					fogColor[] = {0.010224, 0.014418, 0.027709};
					apertureMin = 0.6517;
					apertureStandard = 0.7448;
					apertureMax = 1.17;
					standardAvgLum = 0.0012;
					desiredLuminanceCoef = 0.118098;
					desiredLuminanceCoefCloud = 0.059049;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.3, 0.4, 1}, 8};
					swBrightness = 1;
				};
				
				class Lighting1 {
					height = 0;
					overcast = 0.6;
					sunAngle = -9;
					sunOrMoon = 0;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.0044, 0.0077, 0.018};
					ambientCloud[] = {0.00396, 0.00693, 0.0162};
					ambientMid[] = {0.00264, 0.00462, 0.0108};
					ambientMidCloud[] = {0.002376, 0.004158, 0.00972};
					groundReflection[] = {0.001584, 0.002772, 0.00648};
					groundReflectionCloud[] = {0.001426, 0.002495, 0.005832};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.063536, 0.061948, 0.061081};
					skyAroundSun[] = {0.03249, 0.020216, 0.023458};
					fogColor[] = {0.01278, 0.018022, 0.034636};
					apertureMin = 6.517;
					apertureStandard = 7.448;
					apertureMax = 11.7;
					standardAvgLum = 1.2;
					desiredLuminanceCoef = 0.13122;
					desiredLuminanceCoefCloud = 0.06561;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {0.8, 0.81, 1};
					swBrightness = 1;
				};
				
				class Lighting2 {
					height = 0;
					overcast = 0.6;
					sunAngle = -8;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.024, 0.0385, 0.06345};
					ambientCloud[] = {0.0216, 0.03465, 0.057105};
					ambientMid[] = {0.0144, 0.0231, 0.03807};
					ambientMidCloud[] = {0.01296, 0.02079, 0.034263};
					groundReflection[] = {0.0072, 0.01155, 0.019035};
					groundReflectionCloud[] = {0.00648, 0.010395, 0.017132};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {{0.06688, 0.065208, 0.064296}, 0.135575};
					skyAroundSun[] = {{0.0342, 0.02128, 0.024692}, 0.4};
					fogColor[] = {0.015974, 0.022528, 0.043295};
					apertureMin = 6.86;
					apertureStandard = 7.84;
					apertureMax = 13;
					standardAvgLum = 3;
					desiredLuminanceCoef = 0.1458;
					desiredLuminanceCoefCloud = 0.0729;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 0.135575};
					swBrightness = 1;
				};
				
				class Lighting3 {
					height = 0;
					overcast = 0.6;
					sunAngle = -7;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.02, 0.11, 0.3411};
					ambientCloud[] = {0.018, 0.099, 0.30699};
					ambientMid[] = {0.016, 0.088, 0.27288};
					ambientMidCloud[] = {0.0144, 0.0792, 0.245592};
					groundReflection[] = {0.008, 0.044, 0.13644};
					groundReflectionCloud[] = {0.0072, 0.0396, 0.122796};
					bidirect[] = {0.000213, 0.000203, 0.000191};
					bidirectCloud[] = {0.000192, 0.000183, 0.000171};
					sky[] = {{0.0704, 0.06864, 0.06768}, 4.06725};
					skyAroundSun[] = {{0.036, 0.0224, 0.025992}, 4.2427};
					fogColor[] = {0.019968, 0.02816, 0.054118};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 5;
					desiredLuminanceCoef = 0.13122;
					desiredLuminanceCoefCloud = 0.06561;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 6.5076};
					swBrightness = 1;
				};
				
				class Lighting4 {
					height = 0;
					overcast = 0.6;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.2, 0.275, 0.6309}, 1.8183};
					ambientCloud[] = {{0.18, 0.2475, 0.56781}, 1.63647};
					ambientMid[] = {{0.2, 0.275, 0.6309}, 1.63647};
					ambientMidCloud[] = {{0.18, 0.2475, 0.56781}, 1.47282};
					groundReflection[] = {{0.1, 0.1375, 0.31545}, 1.14553};
					groundReflectionCloud[] = {{0.09, 0.12375, 0.283905}, 1.03098};
					bidirect[] = {0.00213, 0.002034, 0.001905};
					bidirectCloud[] = {0.001917, 0.001831, 0.001715};
					sky[] = {{0.352, 0.3432, 0.3384}, 8.1345};
					skyAroundSun[] = {{0.36, 0.224, 0.25992}, 7.57625};
					fogColor[] = {0.02496, 0.0352, 0.067648};
					apertureMin = 8;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 10;
					desiredLuminanceCoef = 0.1458;
					desiredLuminanceCoefCloud = 0.0729;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.0152};
					swBrightness = 1;
				};
				
				class Lighting5 {
					height = 0;
					overcast = 0.6;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {{0.66, 0.1764, 0.3007}, 1.595};
					diffuseCloud[] = {{0.594, 0.15876, 0.27063}, 1.4355};
					ambient[] = {{0.28, 0.33, 0.6345}, 2.12135};
					ambientCloud[] = {{0.252, 0.297, 0.57105}, 1.90921};
					ambientMid[] = {{0.28, 0.33, 0.6345}, 2.12135};
					ambientMidCloud[] = {{0.252, 0.297, 0.57105}, 1.90921};
					groundReflection[] = {{0.14, 0.165, 0.31725}, 1.48495};
					groundReflectionCloud[] = {{0.126, 0.1485, 0.285525}, 1.33645};
					bidirect[] = {0.00497, 0.004746, 0.004445};
					bidirectCloud[] = {0.004473, 0.004271, 0.004001};
					sky[] = {{0.44, 0.429, 0.423}, 8.40565};
					skyAroundSun[] = {{0.45, 0.28, 0.3249}, 7.8793};
					fogColor[] = {0.0312, 0.044, 0.08456};
					apertureMin = 7;
					apertureStandard = 9;
					apertureMax = 20;
					standardAvgLum = 20;
					desiredLuminanceCoef = 0.162;
					desiredLuminanceCoefCloud = 0.081;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 10.0868};
					swBrightness = 1;
				};
				
				class Lighting6 {
					height = 0;
					overcast = 0.6;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.99, 0.2744, 0.2134}, 6.061};
					diffuseCloud[] = {{0.891, 0.24696, 0.19206}, 5.4549};
					ambient[] = {{0.32, 0.42735, 0.6777}, 3.0305};
					ambientCloud[] = {{0.288, 0.384615, 0.60993}, 2.72745};
					ambientMid[] = {{0.4512, 0.485775, 0.7608}, 3.18202};
					ambientMidCloud[] = {{0.40608, 0.437198, 0.68472}, 2.86382};
					groundReflection[] = {{0.28187, 0.2712, 0.37973}, 3.11839};
					groundReflectionCloud[] = {{0.253683, 0.24408, 0.341757}, 2.80655};
					bidirect[] = {0.03408, 0.032544, 0.03048};
					bidirectCloud[] = {0.030672, 0.02929, 0.027432};
					sky[] = {{0.4392, 0.42735, 0.4239}, 8.81238};
					skyAroundSun[] = {{0.4472, 0.297605, 0.3249}, 8.33387};
					fogColor[] = {0.039, 0.055, 0.1057};
					apertureMin = 8;
					apertureStandard = 12;
					apertureMax = 20;
					standardAvgLum = 60;
					desiredLuminanceCoef = 0.18;
					desiredLuminanceCoefCloud = 0.09;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 10.3986};
					swBrightness = 1;
				};
				
				class Lighting7 {
					height = 0;
					overcast = 0.6;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{1.1, 0.4116, 0.194}, 8.7725};
					diffuseCloud[] = {{0.99, 0.37044, 0.1746}, 7.89525};
					ambient[] = {{0.424, 0.45925, 0.7371}, 4.38625};
					ambientCloud[] = {{0.3816, 0.413325, 0.66339}, 3.94762};
					ambientMid[] = {{0.4782, 0.52197, 0.784}, 4.82487};
					ambientMidCloud[] = {{0.43038, 0.469773, 0.7056}, 4.34239};
					groundReflection[] = {{0.3692, 0.35256, 0.438785}, 4.58363};
					groundReflectionCloud[] = {{0.33228, 0.317304, 0.394907}, 4.12527};
					bidirect[] = {0.03337, 0.031866, 0.029845};
					bidirectCloud[] = {0.030033, 0.028679, 0.026861};
					sky[] = {{0.4312, 0.4433, 0.5175}, 10.5749};
					skyAroundSun[] = {{0.4392, 0.32186, 0.3609}, 10.6067};
					fogColor[] = {0.087, 0.11165, 0.1743};
					apertureMin = 10;
					apertureStandard = 15;
					apertureMax = 20;
					standardAvgLum = 70;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 10.5749};
					swBrightness = 1;
				};
				
				class Lighting8 {
					height = 0;
					overcast = 0.6;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{1.1, 0.588, 0.291}, 12.76};
					diffuseCloud[] = {{0.99, 0.5292, 0.2619}, 11.484};
					ambient[] = {{0.4164, 0.4939, 0.7956}, 6.6352};
					ambientCloud[] = {{0.37476, 0.44451, 0.71604}, 5.97168};
					ambientMid[] = {{0.522, 0.56134, 0.796}, 7.43142};
					ambientMidCloud[] = {{0.4698, 0.505206, 0.7164}, 6.68828};
					groundReflection[] = {{0.48635, 0.467142, 0.509905}, 6.68828};
					groundReflectionCloud[] = {{0.437715, 0.420428, 0.458915}, 6.01945};
					bidirect[] = {0.03266, 0.031188, 0.02921};
					bidirectCloud[] = {0.029394, 0.028069, 0.026289};
					sky[] = {{0.42, 0.46255, 0.6507}, 12.2017};
					skyAroundSun[] = {{0.424, 0.344575, 0.396}, 12.8796};
					fogColor[] = {0.251, 0.28215, 0.36855};
					apertureMin = 15;
					apertureStandard = 28;
					apertureMax = 40;
					standardAvgLum = 120;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 12.2017};
					swBrightness = 1;
				};
				
				class Lighting9 {
					height = 0;
					overcast = 0.6;
					sunAngle = 16;
					sunOrMoon = 1;
					diffuse[] = {{1.1, 0.7252, 0.485}, 14.355};
					diffuseCloud[] = {{0.99, 0.65268, 0.4365}, 12.9195};
					ambient[] = {{0.408, 0.52195, 0.855}, 7.7517};
					ambientCloud[] = {{0.3672, 0.469755, 0.7695}, 6.97653};
					ambientMid[] = {{0.5652, 0.600075, 0.796}, 8.91446};
					ambientMidCloud[] = {{0.50868, 0.540068, 0.7164}, 8.02301};
					groundReflection[] = {{0.6035, 0.575622, 0.575945}, 7.13156};
					groundReflectionCloud[] = {{0.54315, 0.51806, 0.518351}, 6.41841};
					bidirect[] = {0.03195, 0.03051, 0.028575};
					bidirectCloud[] = {0.028755, 0.027459, 0.025718};
					sky[] = {{0.408, 0.48565, 0.8163}, 13.0152};
					skyAroundSun[] = {{0.412, 0.36498, 0.42435}, 13.6372};
					fogColor[] = {0.38, 0.4235, 0.5334};
					apertureMin = 25;
					apertureStandard = 35;
					apertureMax = 85;
					standardAvgLum = 540;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.0152};
					swBrightness = 1;
				};
				
				class Lighting10 {
					height = 0;
					overcast = 0.6;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{1.1, 0.98, 0.97}, 15.95};
					diffuseCloud[] = {{0.99, 0.882, 0.873}, 14.355};
					ambient[] = {{0.4, 0.55, 0.9}, 9.7295};
					ambientCloud[] = {{0.36, 0.495, 0.81}, 8.75655};
					ambientMid[] = {{0.6, 0.635, 0.8}, 10.7024};
					ambientMidCloud[] = {{0.54, 0.5715, 0.72}, 9.63221};
					groundReflection[] = {{0.71, 0.678, 0.635}, 8.56196};
					groundReflectionCloud[] = {{0.639, 0.6102, 0.5715}, 7.70576};
					bidirect[] = {0.02982, 0.028476, 0.02667};
					bidirectCloud[] = {0.026838, 0.025628, 0.024003};
					sky[] = {{0.4, 0.55, 0.9}, 13.5575};
					skyAroundSun[] = {{0.4, 0.385, 0.45}, 15.1525};
					fogColor[] = {{0.5, 0.55, 0.68}, 0.015};
					apertureMin = 35;
					apertureStandard = 65;
					apertureMax = 85;
					standardAvgLum = 800;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.006, 0.0046, 0.004};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.5575};
					swBrightness = 1;
				};
				
				class Lighting11 {
					height = 0;
					overcast = 0.8;
					sunAngle = -10;
					sunOrMoon = 0;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0, 0.000371, 0.004253};
					ambientCloud[] = {0, 0.000278, 0.003189};
					ambientMid[] = {0, 0.000223, 0.002552};
					ambientMidCloud[] = {0, 0.000167, 0.001914};
					groundReflection[] = {0, 0.000134, 0.001531};
					groundReflectionCloud[] = {0, 0.0001, 0.001148};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.002, 0.002, 0.0025};
					skyAroundSun[] = {6.4e-005, 0.001239, 0};
					fogColor[] = {0, 0, 0};
					apertureMin = 0.6517;
					apertureStandard = 0.7448;
					apertureMax = 1.17;
					standardAvgLum = 1e-006;
					desiredLuminanceCoef = 0.118098;
					desiredLuminanceCoefCloud = 0.059049;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.3, 0.4, 1}, 8};
					swBrightness = 1;
				};
				
				class Lighting12 {
					height = 0;
					overcast = 0.8;
					sunAngle = -9;
					sunOrMoon = 0;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.004, 0.08, 0.018};
					ambientCloud[] = {0.003, 0.06, 0.0135};
					ambientMid[] = {0.0024, 0.048, 0.0108};
					ambientMidCloud[] = {0.0018, 0.036, 0.0081};
					groundReflection[] = {0.00144, 0.0288, 0.00648};
					groundReflectionCloud[] = {0.00108, 0.0216, 0.00486};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.063536, 0.061948, 0.061081};
					skyAroundSun[] = {0.063536, 0.061948, 0.061081};
					fogColor[] = {0, 0, 0};
					apertureMin = 6.517;
					apertureStandard = 7.448;
					apertureMax = 11.7;
					standardAvgLum = 0.001;
					desiredLuminanceCoef = 0.13122;
					desiredLuminanceCoefCloud = 0.06561;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {0.8, 0.81, 1};
					swBrightness = 1;
				};
				
				class Lighting13 {
					height = 0;
					overcast = 0.8;
					sunAngle = -8;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.029, 0.028, 0.134};
					ambientCloud[] = {0.02175, 0.021, 0.1005};
					ambientMid[] = {0.0174, 0.0168, 0.0804};
					ambientMidCloud[] = {0.01305, 0.0126, 0.0603};
					groundReflection[] = {0.01044, 0.01008, 0.04824};
					groundReflectionCloud[] = {0.00783, 0.00756, 0.03618};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.06688, 0.065208, 0.064296};
					skyAroundSun[] = {0.06688, 0.065208, 0.064296};
					fogColor[] = {0, 0, 0};
					apertureMin = 6.86;
					apertureStandard = 7.84;
					apertureMax = 13;
					standardAvgLum = 0.002;
					desiredLuminanceCoef = 0.1458;
					desiredLuminanceCoefCloud = 0.0729;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 3};
					swBrightness = 1;
				};
				
				class Lighting14 {
					height = 0;
					overcast = 0.8;
					sunAngle = -7;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.047, 0.051, 0.183};
					ambientCloud[] = {0.03525, 0.03825, 0.13725};
					ambientMid[] = {0.0282, 0.0306, 0.1098};
					ambientMidCloud[] = {0.02115, 0.02295, 0.08235};
					groundReflection[] = {0.01692, 0.01836, 0.06588};
					groundReflectionCloud[] = {0.01269, 0.01377, 0.04941};
					bidirect[] = {0.000144, 0.000137, 0.000129};
					bidirectCloud[] = {0.000108, 0.000103, 9.6e-005};
					sky[] = {0.0704, 0.06864, 0.06768};
					skyAroundSun[] = {0.5, 0.5, 0.5};
					fogColor[] = {0.00256, 0.00512, 0.01536};
					apertureMin = 7;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 0.003;
					desiredLuminanceCoef = 0.13122;
					desiredLuminanceCoefCloud = 0.06561;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 8};
					swBrightness = 1;
				};
				
				class Lighting15 {
					height = 0;
					overcast = 0.8;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.07, 0.081, 0.245};
					ambientCloud[] = {0.0525, 0.06075, 0.18375};
					ambientMid[] = {0.042, 0.0486, 0.147};
					ambientMidCloud[] = {0.0315, 0.03645, 0.11025};
					groundReflection[] = {0.0252, 0.02916, 0.0882};
					groundReflectionCloud[] = {0.0189, 0.02187, 0.06615};
					bidirect[] = {0.001438, 0.001373, 0.001286};
					bidirectCloud[] = {0.001078, 0.00103, 0.000964};
					sky[] = {{0.352, 0.3432, 0.3384}, 1.21475};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 1.35766};
					fogColor[] = {0.0032, 0.0064, 0.0192};
					apertureMin = 8;
					apertureStandard = 8;
					apertureMax = 20;
					standardAvgLum = 0.006;
					desiredLuminanceCoef = 0.1458;
					desiredLuminanceCoefCloud = 0.0729;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 5.20608};
					swBrightness = 1;
				};
				
				class Lighting16 {
					height = 0;
					overcast = 0.8;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.097, 0.155, 0.318};
					ambientCloud[] = {0.07275, 0.11625, 0.2385};
					ambientMid[] = {0.0582, 0.093, 0.1908};
					ambientMidCloud[] = {0.04365, 0.06975, 0.1431};
					groundReflection[] = {0.03492, 0.0558, 0.11448};
					groundReflectionCloud[] = {0.02619, 0.04185, 0.08586};
					bidirect[] = {0.003355, 0.003204, 0.003};
					bidirectCloud[] = {0.002516, 0.002403, 0.00225};
					sky[] = {{0.44, 0.429, 0.423}, 2.4295};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 2.71533};
					fogColor[] = {0.004, 0.008, 0.024};
					apertureMin = 7;
					apertureStandard = 9;
					apertureMax = 20;
					standardAvgLum = 0.01;
					desiredLuminanceCoef = 0.162;
					desiredLuminanceCoefCloud = 0.081;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 6.05207};
					swBrightness = 1;
				};
				
				class Lighting17 {
					height = 0;
					overcast = 0.8;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.101, 0.187, 0.426}, 0.559845};
					ambientCloud[] = {{0.07575, 0.14025, 0.3195}, 0.419884};
					ambientMid[] = {{0.0606, 0.1122, 0.2556}, 0.515057};
					ambientMidCloud[] = {{0.04545, 0.08415, 0.1917}, 0.386293};
					groundReflection[] = {{0.03636, 0.06732, 0.15336}, 0.334787};
					groundReflectionCloud[] = {{0.02727, 0.05049, 0.11502}, 0.251091};
					bidirect[] = {0.023004, 0.021967, 0.020574};
					bidirectCloud[] = {0.017253, 0.016475, 0.015431};
					sky[] = {{0.4392, 0.42735, 0.4239}, 4.85901};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 5.43066};
					fogColor[] = {0.005, 0.01, 0.03};
					apertureMin = 8;
					apertureStandard = 12;
					apertureMax = 20;
					standardAvgLum = 1;
					desiredLuminanceCoef = 0.18;
					desiredLuminanceCoefCloud = 0.09;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 8.83881};
					swBrightness = 1;
				};
				
				class Lighting18 {
					height = 0;
					overcast = 0.8;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.27, 0.32, 0.554}, 3.35907};
					ambientCloud[] = {{0.2025, 0.24, 0.4155}, 2.5193};
					ambientMid[] = {{0.216, 0.256, 0.4432}, 3.2583};
					ambientMidCloud[] = {{0.162, 0.192, 0.3324}, 2.44372};
					groundReflection[] = {{0.1512, 0.1792, 0.31024}, 2.28081};
					groundReflectionCloud[] = {{0.1134, 0.1344, 0.23268}, 1.71061};
					bidirect[] = {0.022525, 0.02151, 0.020145};
					bidirectCloud[] = {0.016894, 0.016132, 0.015109};
					sky[] = {{0.4312, 0.4433, 0.5175}, 6.94144};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 7.75808};
					fogColor[] = {0.02, 0.025, 0.04};
					apertureMin = 10;
					apertureStandard = 15;
					apertureMax = 20;
					standardAvgLum = 5;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 9.51737};
					swBrightness = 1;
				};
				
				class Lighting19 {
					height = 0;
					overcast = 0.8;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.375, 0.442, 0.669}, 5.59845};
					ambientCloud[] = {{0.28125, 0.3315, 0.50175}, 4.19884};
					ambientMid[] = {{0.3, 0.3536, 0.5352}, 5.59845};
					ambientMidCloud[] = {{0.225, 0.2652, 0.4014}, 4.19884};
					groundReflection[] = {{0.21, 0.24752, 0.37464}, 4.19884};
					groundReflectionCloud[] = {{0.1575, 0.18564, 0.28098}, 3.14913};
					bidirect[] = {0.022046, 0.021052, 0.019717};
					bidirectCloud[] = {0.016534, 0.015789, 0.014788};
					sky[] = {{0.42, 0.46255, 0.6507}, 8.6768};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 9.6976};
					fogColor[] = {0.054, 0.055, 0.05};
					apertureMin = 15;
					apertureStandard = 25;
					apertureMax = 40;
					standardAvgLum = 60;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 11.5917};
					swBrightness = 1;
				};
				
				class Lighting20 {
					height = 0;
					overcast = 0.8;
					sunAngle = 16;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.465, 0.545, 0.767}, 10.0772};
					ambientCloud[] = {{0.34875, 0.40875, 0.57525}, 7.55791};
					ambientMid[] = {{0.372, 0.436, 0.6136}, 10.5811};
					ambientMidCloud[] = {{0.279, 0.327, 0.4602}, 7.9358};
					groundReflection[] = {{0.2604, 0.3052, 0.42952}, 8.46486};
					groundReflectionCloud[] = {{0.1953, 0.2289, 0.32214}, 6.34864};
					bidirect[] = {0.021566, 0.020594, 0.019288};
					bidirectCloud[] = {0.016175, 0.015446, 0.014466};
					sky[] = {{0.408, 0.48565, 0.8163}, 10.846};
					skyAroundSun[] = {{0.5, 0.5, 0.5}, 12.122};
					fogColor[] = {0.05, 0.052, 0.052};
					apertureMin = 25;
					apertureStandard = 30;
					apertureMax = 85;
					standardAvgLum = 30;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.0152};
					swBrightness = 1;
				};
				
				class Lighting21 {
					height = 0;
					overcast = 0.8;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {0, 0, 0};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {{0.587, 0.686, 0.9}, 11.1969};
					ambientCloud[] = {{0.44025, 0.5145, 0.675}, 8.39767};
					ambientMid[] = {{0.4696, 0.5488, 0.72}, 11.7568};
					ambientMidCloud[] = {{0.3522, 0.4116, 0.54}, 8.81756};
					groundReflection[] = {{0.32872, 0.38416, 0.504}, 9.99323};
					groundReflectionCloud[] = {{0.24654, 0.28812, 0.378}, 7.49493};
					bidirect[] = {0.020129, 0.019221, 0.018002};
					bidirectCloud[] = {0.015096, 0.014416, 0.013502};
					sky[] = {{0.4, 0.55, 0.9}, 13.5575};
					skyAroundSun[] = {{0.4, 0.385, 0.45}, 15.1525};
					fogColor[] = {0.05, 0.044, 0.042};
					apertureMin = 35;
					apertureStandard = 45;
					apertureMax = 85;
					standardAvgLum = 100;
					desiredLuminanceCoef = 0.2;
					desiredLuminanceCoefCloud = 0.4;
					luminanceRectCoef = 0.4;
					luminanceRectCoefCloud = 0.2;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.006, 0.0046, 0.004};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.5575};
					swBrightness = 1;
				};
				
				class Lighting22 {
					height = -0.001;
					overcast = 0;
					sunAngle = -10;
					sunOrMoon = 0;
					diffuse[] = {0.06, 0.09, 0.2};
					diffuseCloud[] = {0.054, 0.081, 0.18};
					ambient[] = {0.005, 0.009, 0.035};
					ambientCloud[] = {0.0045, 0.0081, 0.0315};
					ambientMid[] = {0.0005, 0.0009, 0.0035};
					ambientMidCloud[] = {0.00045, 0.00081, 0.00315};
					groundReflection[] = {0.0004, 0.00055, 0.00089};
					groundReflectionCloud[] = {0.00036, 0.000495, 0.000801};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0.002, 0.002, 0.0025};
					skyAroundSun[] = {4e-006, 0.000102, 0.00032};
					fogColor[] = {0.000391, 0.000653, 0.000706};
					apertureMin = 0.43;
					apertureStandard = 0.5;
					apertureMax = 0.66;
					standardAvgLum = 0.0016;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 0;
					luminanceRectCoefCloud = 0;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 8};
					swBrightness = 1;
				};
				
				class Lighting23 {
					height = -0.001;
					overcast = 0;
					sunAngle = -9;
					sunOrMoon = 0;
					diffuse[] = {0.06, 0.09, 0.2};
					diffuseCloud[] = {0.06, 0.09, 0.2};
					ambient[] = {0.006, 0.009, 0.02};
					ambientCloud[] = {0.006, 0.009, 0.02};
					ambientMid[] = {0.0048, 0.0072, 0.016};
					ambientMidCloud[] = {0.0048, 0.0072, 0.016};
					groundReflection[] = {0.00336, 0.00504, 0.0112};
					groundReflectionCloud[] = {0.00336, 0.00504, 0.0112};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0, 0.05, 0.07};
					sky[] = {0.0027, 0.01728, 0.027};
					skyAroundSun[] = {0.004, 0.00512, 0.008};
					fogColor[] = {0.000391, 0.000653, 0.000706};
					apertureMin = 0.43;
					apertureStandard = 0.5;
					apertureMax = 0.66;
					standardAvgLum = 0.00162;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {0.8, 0.81, 1};
					swBrightness = 1;
				};
				
				class Lighting24 {
					height = -0.001;
					overcast = 0;
					sunAngle = -8;
					sunOrMoon = 1;
					diffuse[] = {0.06, 0.09, 0.2};
					diffuseCloud[] = {0.06, 0.09, 0.2};
					ambient[] = {0.012, 0.018, 0.04};
					ambientCloud[] = {0.012, 0.018, 0.04};
					ambientMid[] = {0.0096, 0.0144, 0.032};
					ambientMidCloud[] = {0.0096, 0.0144, 0.032};
					groundReflection[] = {0.00672, 0.01008, 0.0224};
					groundReflectionCloud[] = {0.00672, 0.01008, 0.0224};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0, 0.05, 0.07};
					sky[] = {0.009, 0.0576, 0.09};
					skyAroundSun[] = {0.02, 0.0256, 0.04};
					fogColor[] = {0.000652, 0.001088, 0.001177};
					apertureMin = 0.43;
					apertureStandard = 0.5;
					apertureMax = 0.66;
					standardAvgLum = 0.00405;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 3};
					swBrightness = 1;
				};
				
				class Lighting25 {
					height = -0.001;
					overcast = 0;
					sunAngle = -7;
					sunOrMoon = 1;
					diffuse[] = {0.078, 0.117, 0.26};
					diffuseCloud[] = {0.078, 0.117, 0.26};
					ambient[] = {0.0702, 0.1053, 0.234};
					ambientCloud[] = {0.0702, 0.1053, 0.234};
					ambientMid[] = {0.05616, 0.08424, 0.1872};
					ambientMidCloud[] = {0.05616, 0.08424, 0.1872};
					groundReflection[] = {0.039312, 0.058968, 0.13104};
					groundReflectionCloud[] = {0.039312, 0.058968, 0.13104};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0, 0.05, 0.07};
					sky[] = {0.03, 0.192, 0.3};
					skyAroundSun[] = {0.1, 0.128, 0.2};
					fogColor[] = {0.001087, 0.001814, 0.001962};
					apertureMin = 0.559;
					apertureStandard = 0.65;
					apertureMax = 0.858;
					standardAvgLum = 0.00675;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 8};
					swBrightness = 1;
				};
				
				class Lighting26 {
					height = -0.001;
					overcast = 0;
					sunAngle = -5;
					sunOrMoon = 1;
					diffuse[] = {0.15, 0.9, 1.8};
					diffuseCloud[] = {0.15, 0.9, 1.8};
					ambient[] = {0.135, 0.81, 1.62};
					ambientCloud[] = {0.135, 0.81, 1.62};
					ambientMid[] = {0.108, 0.648, 1.296};
					ambientMidCloud[] = {0.108, 0.648, 1.296};
					groundReflection[] = {0.0756, 0.4536, 0.9072};
					groundReflectionCloud[] = {0.0756, 0.4536, 0.9072};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0, 0.05, 0.07};
					sky[] = {{0.1, 0.64, 1}, 1.21475};
					skyAroundSun[] = {{0.5, 0.64, 1}, 1.35766};
					fogColor[] = {0.001812, 0.003023, 0.00327};
					apertureMin = 1.118;
					apertureStandard = 1.3;
					apertureMax = 1.716;
					standardAvgLum = 0.135;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 5.20608};
					swBrightness = 1;
				};
				
				class Lighting27 {
					height = -0.001;
					overcast = 0;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {0.75, 4.5, 9};
					diffuseCloud[] = {0.75, 4.5, 9};
					ambient[] = {0.675, 4.05, 8.1};
					ambientCloud[] = {0.675, 4.05, 8.1};
					ambientMid[] = {0.54, 3.24, 6.48};
					ambientMidCloud[] = {0.54, 3.24, 6.48};
					groundReflection[] = {0.378, 2.268, 4.536};
					groundReflectionCloud[] = {0.378, 2.268, 4.536};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0, 0.05, 0.07};
					sky[] = {{0.1, 0.64, 1}, 2.4295};
					skyAroundSun[] = {{0.5, 0.64, 1}, 2.71533};
					fogColor[] = {0.00302, 0.005038, 0.005449};
					apertureMin = 2.236;
					apertureStandard = 2.6;
					apertureMax = 3.432;
					standardAvgLum = 2.25;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 6.05207};
					swBrightness = 1;
				};
				
				class Lighting28 {
					height = -0.001;
					overcast = 0;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {5, 30, 60};
					diffuseCloud[] = {5, 30, 60};
					ambient[] = {4.5, 27, 54};
					ambientCloud[] = {4.5, 27, 54};
					ambientMid[] = {3.6, 21.6, 43.2};
					ambientMidCloud[] = {3.6, 21.6, 43.2};
					groundReflection[] = {2.52, 15.12, 30.24};
					groundReflectionCloud[] = {2.52, 15.12, 30.24};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 4.85901};
					skyAroundSun[] = {{0.5, 0.64, 1}, 5.43066};
					fogColor[] = {0.005034, 0.008397, 0.009082};
					apertureMin = 5.5125;
					apertureStandard = 8.424;
					apertureMax = 22.1484;
					standardAvgLum = 7.5;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 8.83881};
					swBrightness = 1;
				};
				
				class Lighting29 {
					height = -0.001;
					overcast = 0;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {10, 60, 120};
					diffuseCloud[] = {10, 60, 120};
					ambient[] = {9, 54, 108};
					ambientCloud[] = {9, 54, 108};
					ambientMid[] = {7.2, 43.2, 86.4};
					ambientMidCloud[] = {7.2, 43.2, 86.4};
					groundReflection[] = {5.04, 30.24, 60.48};
					groundReflectionCloud[] = {5.04, 30.24, 60.48};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 6.94144};
					skyAroundSun[] = {{0.5, 0.64, 1}, 7.75808};
					fogColor[] = {0.00839, 0.013994, 0.015137};
					apertureMin = 7.35;
					apertureStandard = 12.96;
					apertureMax = 29.5313;
					standardAvgLum = 15;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 9.51737};
					swBrightness = 1;
				};
				
				class Lighting30 {
					height = -0.001;
					overcast = 0;
					sunAngle = 6;
					sunOrMoon = 1;
					diffuse[] = {{0.2, 0.45, 0.5}, 9.1872};
					diffuseCloud[] = {{0.2, 0.5, 0.5}, 9.1872};
					ambient[] = {{0.05, 0.17, 0.2}, 6.43104};
					ambientCloud[] = {{0, 0.5, 1}, 6.43104};
					ambientMid[] = {{0, 0.17, 0.2}, 4.50173};
					ambientMidCloud[] = {{0, 0.5, 1}, 4.50173};
					groundReflection[] = {{0, 0.45, 0.4}, 3.15121};
					groundReflectionCloud[] = {{0, 0.45, 0.4}, 3.15121};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 8.6768};
					skyAroundSun[] = {{0.5, 0.64, 1}, 9.6976};
					fogColor[] = {0.013983, 0.023324, 0.025228};
					apertureMin = 9.8;
					apertureStandard = 21.6;
					apertureMax = 39.375;
					standardAvgLum = 30;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 11.5917};
					swBrightness = 1;
				};
				
				class Lighting31 {
					height = -0.001;
					overcast = 0;
					sunAngle = 16;
					sunOrMoon = 1;
					diffuse[] = {{0.2, 0.45, 0.5}, 11.484};
					diffuseCloud[] = {{0.2, 0.5, 0.5}, 11.484};
					ambient[] = {{0.05, 0.17, 0.2}, 8.0388};
					ambientCloud[] = {{0, 0.5, 1}, 8.0388};
					ambientMid[] = {{0, 0.17, 0.2}, 5.62716};
					ambientMidCloud[] = {{0, 0.5, 1}, 5.62716};
					groundReflection[] = {{0, 0.45, 0.4}, 3.93901};
					groundReflectionCloud[] = {{0, 0.45, 0.4}, 3.93901};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 10.846};
					skyAroundSun[] = {{0.5, 0.64, 1}, 12.122};
					fogColor[] = {0.019975, 0.03332, 0.03604};
					apertureMin = 14;
					apertureStandard = 36;
					apertureMax = 52.5;
					standardAvgLum = 230;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.0152};
					swBrightness = 1;
				};
				
				class Lighting32 {
					height = -0.001;
					overcast = 0;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.2, 0.45, 0.5}, 14.355};
					diffuseCloud[] = {{0.2, 0.5, 0.5}, 14.355};
					ambient[] = {{0.05, 0.17, 0.2}, 12.2017};
					ambientCloud[] = {{0, 0.5, 1}, 12.2017};
					ambientMid[] = {{0, 0.17, 0.2}, 9.7614};
					ambientMidCloud[] = {{0, 0.5, 1}, 9.7614};
					groundReflection[] = {{0, 0.45, 0.4}, 6.83298};
					groundReflectionCloud[] = {{0, 0.45, 0.4}, 6.83298};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 13.5575};
					skyAroundSun[] = {{0.5, 0.64, 1}, 15.1525};
					fogColor[] = {0.0235, 0.0392, 0.0424};
					apertureMin = 20;
					apertureStandard = 60;
					apertureMax = 70;
					standardAvgLum = 400;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.006, 0.0046, 0.004};
					cloudsColor[] = {{0.8, 0.81, 1}, 13.5575};
					swBrightness = 1;
				};
				
				class Lighting33 {
					height = -150;
					overcast = 0;
					sunAngle = -10;
					sunOrMoon = 0;
					diffuse[] = {0.0005, 0.001, 0.001};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.0004, 0.0008, 0.0008};
					ambientCloud[] = {0, 0, 0};
					ambientMid[] = {0.000375, 0.00075, 0.00075};
					ambientMidCloud[] = {0, 0, 0};
					groundReflection[] = {0, 0, 0};
					groundReflectionCloud[] = {0, 0, 0};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0, 0.002, 0.003};
					skyAroundSun[] = {0, 0.002, 0.003};
					fogColor[] = {0, 0, 0};
					apertureMin = 0.3;
					apertureStandard = 0.5;
					apertureMax = 0.8;
					standardAvgLum = 0.001;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {0.8, 0.81, 1};
					swBrightness = 1;
				};
				
				class Lighting34 {
					height = -150;
					overcast = 0;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {0.4, 0.5, 0.5};
					diffuseCloud[] = {0.2, 0.5, 0.5};
					ambient[] = {0.1, 0.2, 0.2};
					ambientCloud[] = {0, 0.5, 1};
					ambientMid[] = {0.1, 0.2, 0.2};
					ambientMidCloud[] = {0, 0.5, 1};
					groundReflection[] = {0, 0.45, 0.4};
					groundReflectionCloud[] = {0.3, 0.3, 0.3};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 0.485901};
					skyAroundSun[] = {{0.5, 0.64, 1}, 0.543066};
					fogColor[] = {0.05, 0.05, 0.05};
					apertureMin = 8;
					apertureStandard = 12;
					apertureMax = 20;
					standardAvgLum = 1;
					desiredLuminanceCoef = 0.02;
					desiredLuminanceCoefCloud = 0.02;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 2};
					swBrightness = 1;
				};
				
				class Lighting35 {
					height = -150;
					overcast = 0;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.2, 0.45, 0.5}, 7.1775};
					diffuseCloud[] = {{0.2, 0.5, 0.5}, 7.1775};
					ambient[] = {{0, 0.17, 0.2}, 3.58875};
					ambientCloud[] = {{0, 0.5, 1}, 3.58875};
					ambientMid[] = {{0, 0.17, 0.2}, 1.79437};
					ambientMidCloud[] = {{0, 0.5, 1}, 1.79437};
					groundReflection[] = {{0, 0.45, 0.4}, 2.15325};
					groundReflectionCloud[] = {{0, 0.45, 0.4}, 2.15325};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 6.77875};
					skyAroundSun[] = {{0.5, 0.64, 1}, 7.57625};
					fogColor[] = {0.05, 0.055, 0.07};
					apertureMin = 5;
					apertureStandard = 8;
					apertureMax = 12;
					standardAvgLum = 8;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.006, 0.0046, 0.004};
					cloudsColor[] = {{0.8, 0.81, 1}, 9};
					swBrightness = 1;
				};
				
				class Lighting36 {
					height = -300;
					overcast = 0;
					sunAngle = -10;
					sunOrMoon = 0;
					diffuse[] = {0.0005, 0.001, 0.001};
					diffuseCloud[] = {0, 0, 0};
					ambient[] = {0.0004, 0.0008, 0.0008};
					ambientCloud[] = {0, 0, 0};
					ambientMid[] = {0.000375, 0.00075, 0.00075};
					ambientMidCloud[] = {0, 0, 0};
					groundReflection[] = {0, 0, 0};
					groundReflectionCloud[] = {0, 0, 0};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {0, 0.002, 0.003};
					skyAroundSun[] = {0, 0.002, 0.003};
					fogColor[] = {0, 0, 0};
					apertureMin = 0.3;
					apertureStandard = 0.5;
					apertureMax = 0.8;
					standardAvgLum = 0.001;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {0.8, 0.81, 1};
					swBrightness = 1;
				};
				
				class Lighting37 {
					height = -300;
					overcast = 0;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {0.4, 0.5, 0.5};
					diffuseCloud[] = {0.2, 0.5, 0.5};
					ambient[] = {0.1, 0.2, 0.2};
					ambientCloud[] = {0, 0.5, 1};
					ambientMid[] = {0.1, 0.2, 0.2};
					ambientMidCloud[] = {0, 0.5, 1};
					groundReflection[] = {0, 0.45, 0.4};
					groundReflectionCloud[] = {0.3, 0.3, 0.3};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 0.04859};
					skyAroundSun[] = {{0.5, 0.64, 1}, 0.054307};
					fogColor[] = {0.05, 0.05, 0.05};
					apertureMin = 5.5125;
					apertureStandard = 8.424;
					apertureMax = 22.1484;
					standardAvgLum = 7.5;
					desiredLuminanceCoef = 0.02;
					desiredLuminanceCoefCloud = 0.02;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {{0.8, 0.81, 1}, 2};
					swBrightness = 1;
				};
				
				class Lighting38 {
					height = -300;
					overcast = 0;
					sunAngle = 45;
					sunOrMoon = 1;
					diffuse[] = {{0.2, 0.45, 0.5}, 3.58875};
					diffuseCloud[] = {{0.2, 0.5, 0.5}, 3.58875};
					ambient[] = {{0.05, 0.17, 0.2}, 1.79437};
					ambientCloud[] = {{0, 0.5, 1}, 1.79437};
					ambientMid[] = {{0, 0.17, 0.2}, 0.897188};
					ambientMidCloud[] = {{0, 0.5, 1}, 0.897188};
					groundReflection[] = {{0, 0.45, 0.4}, 1.07662};
					groundReflectionCloud[] = {{0, 0.45, 0.4}, 1.07662};
					bidirect[] = {0, 0.05, 0.07};
					bidirectCloud[] = {0.03, 0.03, 0.03};
					sky[] = {{0.1, 0.64, 1}, 0.677875};
					skyAroundSun[] = {{0.5, 0.64, 1}, 0.757625};
					fogColor[] = {0.05, 0.055, 0.07};
					apertureMin = 10;
					apertureStandard = 20;
					apertureMax = 30;
					standardAvgLum = 8;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.006, 0.0046, 0.004};
					cloudsColor[] = {{0.8, 0.81, 1}, 10.5};
					swBrightness = 1;
				};
			};
			
			class Lighting : Lighting {
				class BrightAlmost : DayLightingBrightAlmost {
					overcast = 0.0;
				};
				
				class Rainy : DayLightingRainy {
					overcast = 1.0;
				};
			};
			
			class Overcast : Overcast {
				class Weather1 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_veryclear_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_veryclear_horizont_sky.paa";
				};
				
				class Weather7 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
				};
				
				class Weather2 : Weather2 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_almostclear_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_almostclear_horizont_sky.paa";
				};
				
				class Weather3 : Weather3 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_semicloudy_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_semicloudy_horizont_sky.paa";
				};
				
				class Weather4 : Weather4 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_cloudy_horizont_sky.paa";
				};
				
				class Weather5 : Weather5 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_mostlycloudy_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_mostlycloudy_horizont_sky.paa";
				};
				
				class Weather6 : Weather6 {
					sky = "A3\Map_Stratis\Data\sky_veryclear_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
					horizon = "A3\Map_Stratis\Data\sky_overcast_horizont_sky.paa";
				};
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
