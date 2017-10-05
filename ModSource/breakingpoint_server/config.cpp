/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

class CfgPatches {
	class breakingpoint_server {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"breakingpoint_code"};
	};
};

#include "CfgFunctions.hpp"
#include "CfgHelicrash.hpp"
#include "CfgCargocrash.hpp"
#include "CfgVehicleSpawns.hpp"
#include "CfgTime.hpp"

class CfgBreakingPointServerSettings
{
	class StorageObjects
	{
		storageLimit = 7;		// Storage object Limit
	};
	class CustomLoot
	{
		customLootSetting = 1;	// 0 = SC off 	1 = SC on 	2 = ghosthotel weapon insted of SC
	};
};

class CfgDifficultyPresets
{
	class Regular
	{
		class Options
		{
			waypoints=0;		// Waypoints Regular(3PP) (0 = never, 1 = fade out, 2 = always)
		};		
	};
	
	class Veteran
	{
		class Options
		{
			waypoints=0;		// Waypoints Veteran(1PP) (0 = never, 1 = fade out, 2 = always)
		};
	};
};