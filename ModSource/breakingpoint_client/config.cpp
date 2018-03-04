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

class CfgPatches 
{
	class breakingpoint_client 
	{
		units[] = {"Altis","Stratis","Bornholm","newhaven"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"breakingpoint_functions","A3_Data_F","A3_Map_Altis","A3_Map_Stratis","breakingpoint_infected"};
	};
};

#include "CfgFunctions.hpp"

//class CfgLocationTypes
//{
//	class Hospital;
//	
//	class Stronghold : Hospital {
//		name = "Stronghold";
//		drawStyle = "icon";
//		color[] = {1, 1, 1, 1};
//		size = 32;
//		textSize = 0.04;
//		shadow = false;
//		importance = 10;
//		texture = "\newhaven\map_data_newhaven\icons\hosp32.paa";
//		font = "PuristaMedium";
//	};
//	
//	class Stronghold_Ranger : Stronghold { texture = "\breakingpoint_ui\icons\RangerIcon.paa"; };
//	class Stronghold_Nomad : Stronghold { texture = "\breakingpoint_ui\icons\NomadIcon.paa"; };
//	class Stronghold_Outlaw : Stronghold { texture = "\breakingpoint_ui\icons\OutlawIcon.paa"; };
//	class Stronghold_Hunter : Stronghold { texture = "\breakingpoint_ui\icons\HunterIcon.paa"; };
//	class Stronghold_Survivalist : Stronghold { texture = "\breakingpoint_ui\icons\SurvivalistIcon.paa"; };
//};

class CfgWorlds 
{
	class CAWorld;
	
	class newhaven : CAWorld
	{
		class Ambient {};
		
		class AmbientA3 
		{
			maxCost = 500;
			delete Radius440_500; //Kestrel / Seagull / Rabbit
			delete Radius40_60; //CatShark / Turtle / Snake / Salema / Ornate / Mackerel / Mullet / Tuna
			delete Radius30_40; //DragonFly / ButterFly / FireFly / Cicada
			delete Radius15_20; //FX / Wind / Paper / Pollen
			delete Radius6_10; //HoneyBee / HouseFly / Mosquito
		};
	};
	
	class Stratis : CAWorld 
	{ 
		midDetailTexture = "breakingpoint\textures\midrange\mid_range_stonesharp_mco.paa";
		
		class Ambient {};
		
		class AmbientA3 
		{
			maxCost = 500;
			delete Radius440_500; //Kestrel / Seagull / Rabbit
			delete Radius40_60; //CatShark / Turtle / Snake / Salema / Ornate / Mackerel / Mullet / Tuna
			delete Radius30_40; //DragonFly / ButterFly / FireFly / Cicada
			delete Radius15_20; //FX / Wind / Paper / Pollen
			delete Radius6_10; //HoneyBee / HouseFly / Mosquito
		};
	};

	class Altis : CAWorld 
	{
		midDetailTexture = "breakingpoint\textures\midrange\mid_range_stone_mco.paa";

		class Ambient {};
		
		class AmbientA3 
		{
			maxCost = 500;
			delete Radius440_500; //Kestrel / Seagull / Rabbit
			delete Radius40_60; //CatShark / Turtle / Snake / Salema / Ornate / Mackerel / Mullet / Tuna
			delete Radius30_40; //DragonFly / ButterFly / FireFly / Cicada
			delete Radius15_20; //FX / Wind / Paper / Pollen
			delete Radius6_10; //HoneyBee / HouseFly / Mosquito
		};
		
		class Names
		{
			//class ranger {
			//	name = "";
			//	position[] = {16930,21850};
			//	type = "Stronghold_Ranger";
			//	demography = CIV;
			//	radiusA = 200.0;
			//	radiusB = 200.0;
			//	angle = 0.0;
			//};
			//class nomad {
			//	name = "";
			//	position[] = {14770,10780};
			//	type = "Stronghold_Nomad";
			//	demography = CIV;
			//	radiusA = 200.0;
			//	radiusB = 200.0;
			//	angle = 0.0;
			//};
			//class outlaw {
			//	name = "";
			//	position[] = {05375.63,10290.0};
			//	type = "Stronghold_Outlaw";
			//	demography = CIV;
			//	radiusA = 200.0;
			//	radiusB = 200.0;
			//	angle = 0.0;
			//};
		};
	};
	
};