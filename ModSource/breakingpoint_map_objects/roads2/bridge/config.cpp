////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 15:21:43 2014 : Source 'file' date Sun Mar 16 15:21:43 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class Roads2 : bridge\config.bin{
class CfgPatches
{
	class CARoads2Bridge
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CARoads2"};
	};
};
class CfgNonAIVehicles
{
	class Land_Bridge_stone_asf2_25
	{
		model = "\Ca\roads2\bridge\Bridge_stone_asf2_25";
		simulation = "road";
		armor = 50;
		class Destruction
		{
			animations[] = {{ "Ca\roads2\bridge\data\anim\bridge_stone_asf2.rtm",0.2,3 }};
		};
	};
};
//};
