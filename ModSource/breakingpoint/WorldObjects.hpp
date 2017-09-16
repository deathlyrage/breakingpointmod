/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Base Class
class BP_WorldObject : BP_SaveObject 
{
	scope = private;
	destrType = "DestructNo";
	mapSize = 0.7;
	accuracy = 0.2;
	vehicleClass = "Survival";
	maximumLoad = 0;
	transportMaxMagazines = 0;
	transportMaxWeapons = 0;
	transportMaxBackpacks = 0;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems {};
};

class BP_CamoNet: BP_WorldObject
{
	scope = public;
	model = "\A3\Structures_F\Mil\Shelters\CamoNet_F.p3d";
	displayName = "Camo Netting";
	destrType = "DestructTent";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {"\A3\Structures_F\Mil\Shelters\Data\CamoNet_INDP_CA.paa"};
};
