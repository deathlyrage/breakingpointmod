class CfgPatches {
	class breakingpoint_server_config {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"breakingpoint_server"};
	};
};
////////////////////////////////////////////////////////////////////////////////////
//////////////////		Breaking Point Server Configuration
////////////////////////////////////////////////////////////////////////////////////
class CfgBreakingPointServerSettings
{
	class StorageObjects
	{
		storageLimit = 7;		// Storage object Limit
		immortalHavens = 0;		// make havens immortal 0 = Off 1 = On
	};
	class CustomLoot
	{
		customLootSetting = 1;	// 0 = SC off 		1 = SC on (default)	 	2 = ghosthotel weapon insted of SC
	};
	class MixedGroupPointsGain
	{
		disableMixedGroupPointsGain = 1;	//turns point gain for mixed group off, point lose still on 0 = off , 1 = on
	};
	class groupLeaveTimer
	{
		groupLeaveTimeOut = 600;	//time in seconds between leaving group and joining new/old one if  0 => Off
	};
	class applyMedicine
	{
		medicalCooldown = 900;	//time in seconds for point gain on medical assistance
	};
	class repairVehicle
	{
		repairCooldown = 900; //time in seconds for point gain on vehicle repair
	};
	class Faction
	{
		engineerRepairPoints = 15;
		outlawDestroyPoints = 10;
	};					  
	class BreakingPointExt
	{
		//Do not change this number unless you really know what you are doing!!!
		version = "0.002";
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
////////////////////////////////////////////////////////////////////////////////////
//////////////////		Breaking Point Server Configuration	End
////////////////////////////////////////////////////////////////////////////////////
