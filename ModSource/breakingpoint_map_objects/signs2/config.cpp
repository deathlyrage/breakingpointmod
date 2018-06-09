////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 15:21:47 2014 : Source 'file' date Sun Mar 16 15:21:47 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class signs2 : config.bin{
class CfgPatches
{
	class CASigns2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CAData"};
	};
};
class CfgVehicles
{
	class HouseBase;
	class House: HouseBase
	{
		class DestructionEffects;
	};
	class Ruins;
	class Land_Company3_2: House
	{
		armor = 5;
		model = "\Ca\Signs2\Company3_2";
		class DestructionEffects
		{
			class DestroyPhase1
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				lifeTime = 2.5;
				position = "";
				intensity = 1;
				interval = 1;
			};
		};
	};
	class Land_sign_altar: Land_Company3_2
	{
		model = "\Ca\Signs2\sign_altar";
	};
	class Land_Sign_Bar_RU: Land_Company3_2
	{
		model = "\Ca\Signs2\Sign_Bar_RU";
	};
	class Land_Sign_BES: Land_Company3_2
	{
		model = "\Ca\Signs2\Sign_BES";
	};
	class Land_sign_TEC: Land_Company3_2
	{
		model = "\Ca\Signs2\sign_TEC";
	};
	class Land_sign_ulgano: Land_Company3_2
	{
		model = "\Ca\Signs2\sign_ulgano";
	};
	class Land_SignB_Gov: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Gov";
	};
	class Land_SignB_GovPolice: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_GovPolice";
	};
	class Land_SignB_GovSchool: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_GovSchool";
	};
	class Land_SignB_GovSign: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_GovSign";
	};
	class Land_SignB_Hotel_CZ: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Hotel_CZ";
	};
	class Land_SignB_Hotel_CZ2: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Hotel_CZ2";
	};
	class Land_SignB_Hotel_CZ3: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Hotel_CZ3";
	};
	class Land_SignB_Pharmacy: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pharmacy";
	};
	class Land_SignB_PostOffice: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_PostOffice";
	};
	class Land_SignB_Pub_CZ1: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_CZ1";
	};
	class Land_SignB_Pub_CZ2: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_CZ2";
	};
	class Land_SignB_Pub_CZ3: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_CZ3";
	};
	class Land_SignB_Pub_RU1: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_RU1";
	};
	class Land_SignB_Pub_RU2: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_RU2";
	};
	class Land_SignB_Pub_RU3: Land_Company3_2
	{
		model = "\Ca\Signs2\SignB_Pub_RU3";
	};
};
//};
