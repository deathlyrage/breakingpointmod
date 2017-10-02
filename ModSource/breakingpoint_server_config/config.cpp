class CfgPatches {
	class breakingpoint_server_config {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"breakingpoint_code"};
	};
};
////////////////////////////////////////////////////////////////////////////////////
//////////////////		Breaking Point Server Configuration
////////////////////////////////////////////////////////////////////////////////////
class CfgBreakingPointServerSettings
{
	class StorageObjects
	{
		StorageLimit = 7;		// Storage object Limit
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