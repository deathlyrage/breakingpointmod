////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 14:49:07 2014 : Source 'file' date Sun Mar 16 14:49:07 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=8
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

//Class misc_acr : ScaffoldingSmall\config.bin{
class CfgPatches
{
	class CAMisc_ACR_ScaffoldingSmall
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.5;
		requiredAddons[] = {"CAMisc_ACR"};
	};
};
class CfgVehicles
{
	class House;
	class Land_Scaffolding_ACR: House
	{
		expansion = 3;
		scope = 1;
		model = "\Ca\Misc_ACR\ScaffoldingSmall\Misc_Scaffolding.p3d";
		armor = 500;
	};
	class NonStrategic;
	class FootBridge_Base_ACR: NonStrategic
	{
		expansion = 3;
		vehicleClass = "Misc";
		displayName = "Footbridge";
		destrType = "DestructNo";
		class DestructionEffects{};
	};
	class FootBridge_0_ACR: FootBridge_Base_ACR
	{
		scope = 2;
		displayName = "Footbridge (horizontal)";
		model = "\Ca\Misc_ACR\ScaffoldingSmall\Misc_Crossing0st.p3d";
		accuracy = 1000;
	};
	class FootBridge_30_ACR: FootBridge_Base_ACR
	{
		scope = 2;
		displayName = "Footbridge (aslope)";
		model = "\Ca\Misc_ACR\ScaffoldingSmall\Misc_Crossing30st.p3d";
		accuracy = 1000;
	};
};
//};
