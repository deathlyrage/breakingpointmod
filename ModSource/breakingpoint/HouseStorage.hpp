/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Base Class
class BP_HouseStorage : BP_Storage 
{
	scope = private;
	hideDistance = 50;
};

class BP_Chest: BP_HouseStorage
{
	scope = public;
	model = "\breakingpoint\models\bp_crate1a.p3d";
	displayName = "Storage Chest";
	mapSize = 0.7;
	accuracy = 0.2;
	vehicleClass = "Survival";
	maximumLoad = 750;
	transportMaxMagazines = 50;
	transportMaxWeapons = 5;
	transportMaxBackpacks = 5;
	destrType = "DestructNo";
};

class BP_Chest_Ranger: BP_Chest
{
	displayName = "Ranger Storage Chest";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_ranger_co.paa"};
};

class BP_Chest_Outlaw: BP_Chest
{
	displayName = "Outlaw Storage Chest";
	maximumLoad = 1000;
	transportMaxMagazines = 60;
	transportMaxWeapons = 7;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_outlaw_co.paa"};
};

class BP_Chest_Nomad: BP_Chest
{
	displayName = "Nomad Storage Chest";
	transportMaxBackpacks = 7;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_nomad_co.paa"};
};

class BP_Chest_Hunter: BP_Chest
{
	displayName = "Hunter Storage Chest";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_hunter_co.paa"};
};

class BP_Chest_Survivalist: BP_Chest
{
	displayName = "Survivalist Storage Chest";
	transportMaxBackpacks = 8;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\crate1_survivalist_co.paa"};
};

class BP_Refrigerator: BP_HouseStorage
{
	scope = public;
	model = "\breakingpoint\models\bp_refrigerator.p3d";
	displayName = "Ice Box";
	maximumLoad = 1500;
	transportMaxMagazines = 100;
	transportMaxWeapons = 0;
	transportMaxBackpacks = 0;
};

class BP_Refrigerator_Ranger: BP_Refrigerator
{
	displayName = "Ranger Ice Box";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\refrigerator_ranger_co.paa"};
};

class BP_Refrigerator_Outlaw: BP_Refrigerator
{
	displayName = "Outlaw Ice Box";
	maximumLoad = 1700;
	transportMaxWeapons = 2;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\refrigerator_outlaw_co.paa"};
};

class BP_Refrigerator_Nomad: BP_Refrigerator
{
	displayName = "Nomad Ice Box";
	transportMaxBackpacks = 1;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\refrigerator_nomad_co.paa"};
};

class BP_Refrigerator_Hunter: BP_Refrigerator
{
	displayName = "Hunter Ice Box";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\refrigerator_hunter_co.paa"};
};

class BP_Refrigerator_Survivalist: BP_Refrigerator
{
	displayName = "Survivalist Ice Box";
	transportMaxBackpacks = 2;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\refrigerator_survivalist_co.paa"};
};

class BP_GunCabinet: BP_HouseStorage
{
	scope = public;
	model = "\breakingpoint\models\bp_guncab.p3d";
	displayName = "Gun Cabinet";
	maximumLoad = 1750;
	transportMaxMagazines = 50;
	transportMaxWeapons = 20;
	transportMaxBackpacks = 2;
};

class BP_GunCabinet_Ranger: BP_GunCabinet
{
	displayName = "Ranger Gun Cabinet";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\guncab_ranger_co.paa"};
};

class BP_GunCabinet_Outlaw: BP_GunCabinet
{
	displayName = "Outlaw Gun Cabinet";
	maximumLoad = 2000;
	transportMaxWeapons = 25;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\guncab_outlaw_co.paa"};
};

class BP_GunCabinet_Nomad: BP_GunCabinet
{
	displayName = "Nomad Gun Cabinet";
	transportMaxBackpacks = 1;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\guncab_nomad_co.paa"};
};

class BP_GunCabinet_Hunter: BP_GunCabinet
{
	displayName = "Hunter Gun Cabinet";
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\guncab_hunter_co.paa"};
};

class BP_GunCabinet_Survivalist: BP_GunCabinet
{
	displayName = "Survivalist Gun Cabinet";
	transportMaxBackpacks = 5;
	//hiddenSelections[] = {"camo"};
	//hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\guncab_survivalist_co.paa"};
};
