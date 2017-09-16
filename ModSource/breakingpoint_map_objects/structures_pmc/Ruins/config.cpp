////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Fri Mar 21 17:33:10 2014 : Source 'file' date Fri Mar 21 17:33:10 2014
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

//Class structures_pmc : Ruins\config.bin{
class CfgPatches
{
	class CAStructures_PMC_Ruins
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class House;
	class Land_ruin_corner_1_PMC: House
	{
		scope = 1;
		armor = 800;
		model = "\ca\structures_PMC\Ruins\ruin_corner_1_PMC";
		destrType = "DestructNo";
	};
	class Land_ruin_corner_2_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_corner_2_PMC";
	};
	class Land_ruin_chimney_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_chimney_PMC";
	};
	class Land_ruin_wall_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_wall_PMC";
	};
	class Land_ruin_walldoor_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_walldoor_PMC";
	};
	class Land_ruin_rubble_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_rubble_PMC";
	};
	class Land_ruin_01_PMC: Land_ruin_corner_1_PMC
	{
		model = "\ca\structures_PMC\Ruins\ruin_01_PMC";
	};
};
//};
