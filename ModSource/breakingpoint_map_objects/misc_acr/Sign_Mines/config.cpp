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

//Class misc_acr : Sign_Mines\config.bin{
class CfgPatches
{
	class CAMisc_ACR_Sign_Mines
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.5;
		requiredAddons[] = {"CAMisc_ACR"};
	};
};
class CfgVehicles
{
	class Sign_1L_Border;
	class Sign_DangerMines_ACR: Sign_1L_Border
	{
		expansion = 3;
		scope = 2;
		displayName = "Danger (mines)";
		model = "\Ca\Misc_ACR\Sign_Mines\sign_mineField_ACR.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\Ca\Misc_ACR\Sign_Mines\data\sign_mineField_CO.paa"};
	};
};
//};
