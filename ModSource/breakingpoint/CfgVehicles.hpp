/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define private		0
#define protected	1
#define public		2

#define true 1
#define false 0

/*
private:
Only other classes inherit this class. It is not createVehicle'able, nor can the class be accessed via the Mission Editor.

public:
Any classes declared public are CamCreateabale, and selectable via the Editor.

protected:
Identical to public, except the class will not be listed in the mission editor. A very common form of use for this is
*/

enum 
{
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 2,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXESXYZ = 4,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

class CfgVehicles 
{
	//External Class References
	class NonStrategic;
	class NATO_Box_Base;
	class Building;
	class Camping_base_F;
	class House_F;
	class Thing;
	
	//Base Class for All Breaking Point Objects
	class BP_Object : NonStrategic 
	{
		scope = private;
		accuracy = 0.2;
		cost = 0;
		destrType = "DestructNo";
		displayname = "";
		icon = "iconObject";
		mapsize = 2.13;
		model = "\A3\Weapons_F\empty.p3d";
		vehicleClass = "Survival";
	};
	
	class BP_SodaMachine: BP_Object
	{
		scope = public;
		model = "\breakingpoint\models\bp_sodamachine.p3d";
		displayName = "Soda Machine";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "Survival";
		maximumLoad = 250;
		transportMaxMagazines = 20;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		destrType = "DestructNo";
		class transportmagazines {
			class _xx_ItemSoda1 {
				magazine = "ItemSoda1";
				count = 1;
			};
			class _xx_ItemSoda2 {
				magazine = "ItemSoda2";
				count = 1;
			};
			class _xx_ItemSoda3 {
				magazine = "ItemSoda3";
				count = 1;
			};
			class _xx_ItemSoda4 {
				magazine = "ItemSoda4";
				count = 1;
			};
			class _xx_ItemSoda5 {
				magazine = "ItemSoda5";
				count = 1;
			};
		};
	};
	
	class BP_Trap: BP_Object
	{
		scope = 0;
	};

	class BP_BearTrap : BP_Object 
	{
		scope = 2;
		model = "\breakingpoint\models\bp_beartrap.p3d";
		displayName = "Bear Trap";

		class EventHandlers {
			init = "[_this] call BP_fnc_trapInit;";
		};
		
		class AnimationSources 
		{
			class LeftShutter 
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};

			class RightShutter 
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};

		class UserActions 
		{
			class OpenTrap 
			{
				position = "";
				displayName = "Open Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "[this,player] call BP_fnc_trapActivate;";
			};

			class CloseTrap 
			{
				position = "";
				displayName = "Close Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 0";
				statement = "[this,player] call BP_fnc_trapActivate;";
			};

			class CollectTrap 
			{
				position = "";
				displayName = "Collect Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "[this,player] call BP_fnc_trapCollect;";
			};
		};
	};
	
	class BP_CardboardBox : BP_Object
	{
		scope = public;
		hiddenSelections[] = {"base"};
		hiddenSelectionsTextures[] = {"breakingpoint\textures\items\box1_co.paa"};
		model = "\breakingpoint\models\bp_box1.p3d";
		displayName = "Cardboard Box";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "Survival";
		maximumLoad = 750;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		destrType = "DestructNo";
	};
	
	//Base Class for All Breaking Point Savable Objects
	class BP_SaveObject : BP_Object 
	{
		scope = private;
		class EventHandlers 
		{
			init = "_this call BP_fnc_onStorageInit;";
			local = "_this call BP_fnc_onStorageLocal;";
			killed = "_this call BP_fnc_onStorageKilled;";
		};
		hideDistance = 1000;
	};
	
	//Base Class for All Breaking Point Storage Objects
	class BP_Storage : BP_SaveObject 
	{
		scope = private;
	};
	
	/***************************** HOUSE OBJECTS **************************************/
	
	#include "HouseStorage.hpp"
	#include "HouseObjects.hpp"
	#include "WorldStorage.hpp"
	#include "WorldObjects.hpp"
	#include "LootObjects.hpp"
	
/*	
	class BP_Sign1: BP_Object 
	{
		scope = 2;
		model = "\breakingpoint\models\bp_sign1.p3d";
		displayName = "Sign";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "Survival";
		destrType = "DestructNo";
	};
	
	class BP_Campfire: BP_Object {};

	class BP_Campfire: BP_Object 
	{
		scope = 2;
		model = "\A3\Structures_F\Civ\Camping\Campfire_F.p3d";
		displayName = "Campfire";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "Survival";
		destrType = "DestructNo";
		simulation = "fire";
		
		class Effects {
			class Light1 {
				simulation = "light";
				type = "SmallFireLight";
			};
			
			class sound {
				simulation = "sound";
				type = "Fire";
			};
			
			class Smoke1 {
				simulation = "particles";
				type = "SmallFireS";
			};
			
			class Fire1 : Smoke1 {
				simulation = "particles";
				type = "SmallFireF";
			};
			
			class Refract1 {
				simulation = "particles";
				type = "SmallFireFRefract";
			};
		};
	};

	class BP_SurvivalBox: BP_CardboardBox   {
		
		class TransportMagazines {
		
			class _xx_BP_10Rnd_762Rubber_Mag {
				magazine = "BP_10Rnd_762Rubber_Mag";
				count = 2;
			};

			class _xx_BP_5Rnd_762Rubber_Mag {
				magazine = "BP_5Rnd_762Rubber_Mag";
				count = 2;
			};

			class _xx_ItemKnife {
				magazine = "ItemKnife";
				count = 1;
			};
			
			class _xx_BP_15Rnd_9x21_Rubber {
				magazine = "BP_15Rnd_9x21_Rubber";
				count = 2;
			};
		};
		
		class TransportWeapons {
		
			class _xx_BP_TranQPistol {
				weapon = "BP_TranQPistol";
				count = 1;
			};

			class _xx_BP_TranQRifle {
				weapon = "BP_TranQRifle";
				count = 1;
			};
		};
		
		class TransportItems {
		
			class _xx_BP_Survivalist1 {
				name = "BP_Survivalist1";
				count = 1;
			};

			class _xx_BP_m3lr {
				name = "BP_m3lr";
				count = 1;
			};
		};
	};
	*/
	
	/*
	class BP_Medicalbox: BP_Object
	{
		scope = 2;
		model = "\breakingpoint\models\bp_medicalbox.p3d";
		displayName = "Medical Box";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "Survival";
		maximumLoad = 750;
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 3;
		destrType = "DestructNo";

		class transportmagazines {
			class _xx_ItemBandage {
				magazine = "ItemBandage";
				count = 10;
			};

			class _xx_ItemFieldDressing {
				magazine = "ItemFieldDressing";
				count = 3;
			};

			class _xx_ItemMorphine {
				magazine = "ItemMorphine";
				count = 3;
			};
			
			class _xx_ItemPainkiller {
				magazine = "ItemPainkiller";
				count = 3;
			};
		};
	};
	*/
};
