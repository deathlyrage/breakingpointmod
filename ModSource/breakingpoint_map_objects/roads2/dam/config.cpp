////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 15:21:51 2014 : Source 'file' date Sun Mar 16 15:21:51 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class Roads2 : dam\config.bin{
class CfgPatches
{
	class CARoads2Dam
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CARoads2"};
	};
};
class CfgVehicles
{
	class HouseBase;
	class House: HouseBase
	{
		class DestructionEffects;
	};
	class Land_Dam_Conc_20: House
	{
		scope = 1;
		model = "\CA\roads2\dam\dam_conc\dam_conc_20";
		destrType = "DestructBuilding";
		class DestructionEffects{};
	};
	class Land_Dam_ConcP_20: Land_Dam_Conc_20
	{
		model = "\CA\roads2\dam\dam_conc\dam_concP_20";
		ladders[] = {{ "start","end" }};
	};
	class Land_Dam_Barrier_40: Land_Dam_Conc_20
	{
		model = "\Ca\roads2\dam\dam_barrier_40\dam_barrier_40";
	};
};
//};
