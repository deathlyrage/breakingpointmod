/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Base Class
class BP_HouseObject : BP_SaveObject
{
	scope = private;
	mapSize = 0.7;
	accuracy = 0.2;
	vehicleClass = "Survival";
	destrType = "DestructNo";
	hideDistance = 50;
};

class BP_Stove : BP_HouseObject 
{
	scope = public;
	model = "\breakingpoint\models\BP_ovenObject.p3d";
	displayName = "Stove";
};

class BP_BarrelWater : BP_HouseObject 
{
	scope = public;
	model = "\A3\Structures_F\Items\Vessels\BarrelWater_F.p3d";
	displayName = "Water Barrel";
};

class BP_BarrelFuel : BP_HouseObject 
{
	scope = public;
	model = "\A3\Structures_F\Items\Vessels\MetalBarrel_F.p3d";
	displayName = "Fuel Barrel";
    transportMaxMagazines = 0;
    transportMaxWeapons = 0;
    transportMaxBackpacks = 0;
	fuelCapacity = 100;
    transportFuel = 100;
};

class BP_Television: BP_HouseObject 
{
	scope = public;
	model = "\breakingpoint\models\bp_television1.p3d";
	displayName = "Old Television";
	hiddenSelections[] = {"base","screen"};
	hiddenSelectionsTextures[] = {"breakingpoint\textures\objects\television_co.paa","breakingpoint\textures\objects\television_screen0_co.paa"};
};
