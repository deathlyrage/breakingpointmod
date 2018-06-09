/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgWorlds 
{
	class DefaultLighting;	// External class reference
	
	class DefaultWorld {
		class Weather {
			class Overcast {
				class Weather1;	// External class reference
				class Weather2;	// External class reference
				class Weather3;	// External class reference
				class Weather4;	// External class reference
				class Weather5;	// External class reference
			};
		};
		class DayLightingBrightAlmost;	// External class reference
		class DayLightingRainy;	// External class reference
	};
	
	class CAWorld : DefaultWorld {
		class Lighting : DefaultLighting {
			moonObjectColorFull[] = {460, 440, 400, 1};
			moonHaloObjectColorFull[] = {465, 477, 475, 1};
			moonsetObjectColor[] = {375, 350, 325, 1};
			moonsetHaloObjectColor[] = {515, 517, 525, 1};
			
			class ThunderBoltLight {
				diffuse[] = {2120, 3170, 5550};
			};
			starEmissivity = 25;
		};
		
		class Weather : Weather {
			class LightingNew {
				class Lighting0 {
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
		
		class DayLightingBrightAlmost : DayLightingBrightAlmost {};
		
		class DayLightingRainy : DayLightingRainy {};
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
	
	class utes : CAWorld {
		class DayLightingBrightAlmost : DayLightingBrightAlmost {};
		
		class DayLightingRainy : DayLightingRainy {};
	};

	class Chernarus : CAWorld {
		class DayLightingBrightAlmost : DayLightingBrightAlmost {};
		
		class DayLightingRainy : DayLightingRainy {};
		class sunObject {};
		
		class SimulWeather : SimulWeather {
			class Overcast {};
			
			class DefaultKeyframe : DefaultKeyframe {
				class haze {};
				class hazeBaseKm {};
				class hazeScaleKm {};
				class hazeEccentricity {};
			};
		};
		
		class Weather : Weather {
			class LightingNew {};
		};
		
		class Underwater : Underwater {
			deepWaterFog = 35;
			waterFogDistanceNear = 0.0001;
			waterFogDistance = 35;
			waterColor[] = {0.17, 0.27, 0.05};
			deepWaterColor[] = {0, 0.13, 0, 1};
			surfaceColor[] = {0.17, 0.27, 0.05};
			deepSurfaceColor[] = {0, 0.13, 0, 1};
		};
		
		class Sea : Sea {
			seaMaterial = "#AiA_Chernarus_Water";
			shoreMaterial = "#AiA_Chernarus_Shore";
		};
	};
	
	class Chernarus_Summer : Chernarus {};
	
	class Thirsk : CAWorld {
		class DayLightingBrightAlmost : DayLightingBrightAlmost {};
		
		class DayLightingRainy : DayLightingRainy {};
	};
	
	class namalsk : utes {};
	
};
