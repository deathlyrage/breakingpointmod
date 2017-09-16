/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Base Class
class BP_WorldStorage : BP_Storage 
{
	scope = private;
	mapSize = 0.7;
	accuracy = 0.2;
	vehicleClass = "Survival";
	destrType = "DestructNo";
};

class BP_Crate1: BP_WorldStorage
{
	scope = public;
	displayName = "Military Crate";
	maximumLoad = 2000;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
	model = "\breakingpoint\models\bp_crate1.p3d";
	hiddenSelections[] = {"crate"};
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_co.paa"};
};
class BP_Crate1_Ranger : BP_Crate1 {
	displayName = "Ranger Military Crate";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\Crate1_ranger_co.paa"};
};
class BP_Crate1_Nomad : BP_Crate1 {
	displayName = "Nomad Military Crate";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\Crate1_nomad_co.paa"};
};	
class BP_Crate1_Outlaw : BP_Crate1 { 
	displayName = "Outlaw Military Crate";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\Crate1_outlaw_co.paa"};
};
class BP_Crate1_Hunter : BP_Crate1 {
	displayName = "Hunter Military Crate";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\Crate1_hunter_co.paa"};
};
class BP_Crate1_Survivalist : BP_Crate1 {
	displayName = "Survivalist Military Crate";
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\Crate1_survivalist_co.paa"};
};

class BP_Cache1: BP_WorldStorage
{
	scope = public;
	displayName = "Storage Cache";
	maximumLoad = 2800;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
	model = "\breakingpoint_classes\models\bp_CacheStandard.p3d";
	hiddenSelections[] = {"crate", "crate2", "net", "net2", "net3", "net4"};
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_wood_co.paa", "breakingpoint_classes\textures\rubasic_wood_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa"};
};
class BP_Cache1_Ranger : BP_Cache1 { 
	displayName = "Ranger Storage Cache";
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_ranger_co.paa", "breakingpoint_classes\textures\rubasic_ranger_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa"}; 
};
class BP_Cache1_Nomad : BP_Cache1 { 
	displayName = "Nomad Storage Cache";
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_outlaw_co.paa", "breakingpoint_classes\textures\rubasic_outlaw_co.paa", "breakingpoint_classes\textures\camo_outlaw_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa", "breakingpoint_classes\textures\camo_outlaw_co.paa", "breakingpoint_classes\textures\camo_texture_co.paa"}; 
};
class BP_Cache1_Outlaw : BP_Cache1 { 
	displayName = "Outlaw Storage Cache";
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_survivalist_co.paa", "breakingpoint_classes\textures\rubasic_survivalist_co.paa", "breakingpoint_classes\textures\camo_survivalist_co.paa", "breakingpoint_classes\textures\camo_survivalist2_co.paa", "breakingpoint_classes\textures\camo_survivalist_co.paa", "breakingpoint_classes\textures\camo_survivalist2_co.paa"};
};
class BP_Cache1_Hunter : BP_Cache1 { 
	displayName = "Hunter Storage Cache";
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_nomad_co.paa", "breakingpoint_classes\textures\rubasic_nomad_co.paa", "breakingpoint_classes\textures\camo_hunter_co.paa", "breakingpoint_classes\textures\camo_nomad_co.paa", "breakingpoint_classes\textures\camo_nomad_co.paa", "breakingpoint_classes\textures\camo_hunter_co.paa"}; 
};
class BP_Cache1_Survivalist : BP_Cache1 {
	displayName = "Survivalist Storage Cache";
	hiddenSelectionsTextures[] = {"breakingpoint_classes\textures\localbasic_ranger_co.paa", "breakingpoint_classes\textures\rubasic_ranger_co.paa", "breakingpoint_classes\textures\camo_hunter_co.paa", "breakingpoint_classes\textures\camo_hunter_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa", "breakingpoint_classes\textures\camo_texture2_co.paa"}; 
};

class BP_Tent: BP_WorldStorage
{
	scope = public;
	model = "\A3\Structures_F\Civ\Camping\TentDome_F.p3d";
	displayName = "Civilian Tent";
	destrType = "DestructTent";
	maximumLoad = 3000;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
};

class BP_RockStash: BP_WorldStorage
{
	scope = public;
	model = "\breakingpoint\models\bp_rock_stash.p3d";
	displayName = "Secret Stash";
	maximumLoad = 500;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
};

class BP_Safe: BP_WorldStorage
{
	scope = public;
	model = "\breakingpoint\models\bp_safe.p3d";
	displayName = "Cast Iron Safe";
	vehicleClass = "Survival";
	maximumLoad = 750;
	transportMaxMagazines = 50;
	transportMaxWeapons = 10;
	transportMaxBackpacks = 3;
};
