////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 14:49:04 2014 : Source 'file' date Sun Mar 16 14:49:04 2014
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

//Class misc_acr : Container\config.bin{
class CfgPatches
{
	class CAMisc_ACR_Container
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.5;
		requiredAddons[] = {"CAMisc_ACR"};
	};
};
class CfgVehicles
{
	class Military_Item_NoInteractive;
	class Misc_cargo_cont_small: Military_Item_NoInteractive
	{
		model = "\Ca\Misc_ACR\Container\Misc_cargo_cont_small_ACR.p3d";
	};
	class Misc_cargo_cont_small_EP1: Misc_cargo_cont_small
	{
		model = "\Ca\Misc_ACR\Container\Misc_cargo_cont_small_ACR.p3d";
	};
};
//};
