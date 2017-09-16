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

//Class misc_acr : config.bin{
class CfgPatches
{
	class CAMisc_ACR
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.5;
		requiredAddons[] = {"CAMisc3"};
	};
};
class CfgVehicles
{
	class House;
	class Pond_ACR: House
	{
		expansion = 3;
		scope = 1;
		displayName = "Pond";
		model = "\ca\structures\pond\pondtest.p3d";
	};
};
//};
