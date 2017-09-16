////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 15:21:14 2014 : Source 'file' date Sun Mar 16 15:21:14 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class misc_fix : config.bin{
class CfgPatches
{
	class CAMisc_fix
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.07;
		requiredAddons[] = {};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class CAMisc_fix
		{
			list[] = {"CASigns2","missions_ew","CA_AH64D","Warfare2Vehicles","CAMisc_fix","CAMisc_fix_Str","CAMisc_fix_Ch2","CAMisc_fix_air","CA_Dubbing","CAMisc_fix_Weap","CAMisc_fix_A2FREE"};
		};
	};
};
class CfgVoice
{
	class Male01EN;
	class Male01EN_A2: Male01EN
	{
		directories[] = {"\ca\dubbing\GLOBAL\RADIO\Male01\","\ca\dubbing\GLOBAL\RADIO\Male01\"};
		protocol = "RadioProtocolEN";
		identityTypes[] = {"Language_A2_EN","Language_auto_EN"};
	};
	class Male02EN;
	class Male02EN_A2: Male02EN
	{
		directories[] = {"\ca\dubbing\GLOBAL\RADIO\Male02\","\ca\dubbing\GLOBAL\RADIO\Male02\"};
		protocol = "RadioProtocolEN";
		identityTypes[] = {"Language_A2_EN","Language_auto_EN"};
	};
	class Male03EN;
	class Male03EN_A2: Male03EN
	{
		directories[] = {"\ca\dubbing\GLOBAL\RADIO\Male03\","\ca\dubbing\GLOBAL\RADIO\Male03\"};
		protocol = "RadioProtocolEN";
		identityTypes[] = {"Language_A2_EN","Language_auto_EN"};
	};
	class Male04EN;
	class Male04EN_A2: Male04EN
	{
		directories[] = {"\ca\dubbing\GLOBAL\RADIO\Male04\","\ca\dubbing\GLOBAL\RADIO\Male04\"};
		protocol = "RadioProtocolEN";
		identityTypes[] = {"Language_A2_EN","Language_auto_EN"};
	};
	class Male05EN;
	class Male05EN_A2: Male05EN
	{
		directories[] = {"\ca\dubbing\GLOBAL\RADIO\Male05\","\ca\dubbing\GLOBAL\RADIO\Male05\"};
		protocol = "RadioProtocolEN";
		identityTypes[] = {"Language_A2_EN","Language_auto_EN"};
	};
	class Male01CZ;
	class Male01CZ_A2: Male01CZ
	{
		identityTypes[] = {"Language_A2_CZ"};
	};
	class Male02CZ;
	class Male02CZ_A2: Male02CZ
	{
		identityTypes[] = {"Language_A2_CZ"};
	};
	class Male03CZ;
	class Male03CZ_A2: Male03CZ
	{
		identityTypes[] = {"Language_A2_CZ"};
	};
	class Male04CZ;
	class Male04CZ_A2: Male04CZ
	{
		identityTypes[] = {"Language_A2_CZ"};
	};
	class Male05CZ;
	class Male05CZ_A2: Male05CZ
	{
		identityTypes[] = {"Language_A2_CZ"};
	};
	class Male01RU;
	class Male01RU_A2: Male01RU
	{
		identityTypes[] = {"Language_A2_RU"};
	};
	class Male02RU;
	class Male02RU_A2: Male02RU
	{
		identityTypes[] = {"Language_A2_RU"};
	};
	class Male03RU;
	class Male03RU_A2: Male03RU
	{
		identityTypes[] = {"Language_A2_RU"};
	};
	class Male04RU;
	class Male04RU_A2: Male04RU
	{
		identityTypes[] = {"Language_A2_RU"};
	};
	class Male05RU;
	class Male05RU_A2: Male05RU
	{
		identityTypes[] = {"Language_A2_RU"};
	};
};
class RadioProtocolBase;
class RadioProtocolCZ: RadioProtocolBase
{
	class Words
	{
		obj_LaserTarget[] = {"CZ\objects\LaserTarget"};
		obj_LaserTargets[] = {"CZ\objects\LaserTarget"};
		obj_LaserTarget_CZ[] = {"CZ\objects\LaserTarget"};
		obj_LaserTargets_CZ[] = {"CZ\objects\LaserTarget"};
		obj_LaserTarget_CZ4P[] = {"CZ\objects\LaserTarget"};
		obj_LaserTargets_CZ4P[] = {"CZ\objects\LaserTarget"};
		obj_LaserTarget_RU[] = {"CZ\objects\LaserTarget"};
		obj_LaserTargets_RU[] = {"CZ\objects\LaserTarget"};
		CeaseFireE[] = {"CZ\ZastavitPalbuE"};
	};
};
class RadioProtocolRU: RadioProtocolBase
{
	class Words
	{
		obj_LaserTarget[] = {"RU\objects\LaserTarget"};
		obj_LaserTargets[] = {"RU\objects\LaserTarget"};
		obj_LaserTarget_CZ[] = {"RU\objects\LaserTarget"};
		obj_LaserTargets_CZ[] = {"RU\objects\LaserTarget"};
		obj_LaserTarget_CZ4P[] = {"RU\objects\LaserTarget"};
		obj_LaserTargets_CZ4P[] = {"RU\objects\LaserTarget"};
		obj_LaserTarget_RU[] = {"RU\objects\LaserTarget"};
		obj_LaserTargets_RU[] = {"RU\objects\LaserTarget"};
		EnemyFireE[] = {"RU\UnderFireE"};
		HealAt[] = {"RU\actions\OsetriSe"};
		NeedSITREPE[] = {"RU\ReportPositionE"};
		SendSITREP[] = {"RU\ReportStatus"};
		NoEnemiesInSight[] = {"RU\SectorClear"};
		AreaClear[] = {"RU\SectorClear"};
		ShouldBeSafeNow[] = {"RU\SectorClear"};
		RepairAt[] = {"RU\actions\OpravteSe"};
		VehicleIsFUBARE[] = {"RU\StatusRedE"};
		WereHeavilyDamagedE[] = {"RU\CriticalDamageE"};
		WhatIsYourLocationQ[] = {"RU\WhereAreYouQ"};
	};
};
class RadioProtocolEN: RadioProtocolBase
{
	class Words
	{
		obj_LaserTarget[] = {"EN\objects\LaserTarget"};
		obj_LaserTargets[] = {"EN\objects\LaserTarget"};
		obj_LaserTarget_CZ[] = {"EN\objects\LaserTarget"};
		obj_LaserTargets_CZ[] = {"EN\objects\LaserTarget"};
		obj_LaserTarget_CZ4P[] = {"EN\objects\LaserTarget"};
		obj_LaserTargets_CZ4P[] = {"EN\objects\LaserTarget"};
		obj_LaserTarget_RU[] = {"EN\objects\LaserTarget"};
		obj_LaserTargets_RU[] = {"EN\objects\LaserTarget"};
	};
};
class CfgWorlds
{
	class CAWorld;
	class Utes: CAWorld
	{
		class SecondaryAirports
		{
			class Carrier
			{
				ilsPosition[] = {1358,900};
				ilsDirection[] = {0,0.08,-1};
				ilsTaxiOff[] = {1358,950,1358,1130,1367,1133,1375,1130,1380,1125,1378,1120,1367,1100,1358.1,1090,1358.1,965,1362,960,1380,940,1380,935};
				ilsTaxiIn[] = {1380,930,1380,900,1375,898,1368,897,1359,905,1359,920};
			};
		};
	};
};
//};
