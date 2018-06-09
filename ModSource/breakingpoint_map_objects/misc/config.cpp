class CfgPatches
{
	class CAMisc
	{
		units[]=
		{
			"BarrelBase",
			"Barrels",
			"Barrel1",
			"Barrel2",
			"Barrel3",
			"Barrel4",
			"Camera1",
			"Computer",
			"TVStudio",
			"Radio",
			"PaletaBase",
			"Paleta1",
			"Paleta2",
			"JeepWreck1",
			"JeepWreck2",
			"JeepWreck3",
			"M113Wreck",
			"BMP2Wreck",
			"UralWreck",
			"datsun01Wreck",
			"datsun02Wreck",
			"hiluxWreck",
			"Body",
			"misc01",
			"Vysilacka",
			"WallMap",
			"Vec03",
			"Land_vez_ropa",
			"FlagCarrier",
			"FlagCarrierWest",
			"FlagCarrierEast",
			"Fire",
			"FireLit",
			"TargetE"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CAData"
		};
	};
};
class CfgDamageAround
{
	class DamageAroundPole
	{
		radiusRatio="0.3";
		indirectHit="900";
	};
};
class CfgDestructPos
{
	class DelayedDestruction
	{
		timeBeforeHiding="0.2";
		hideDuration="0.65+lifeTime*0.05";
	};
};
class cfgVehicles
{
	class Thing;
	class Strategic;
	class NonStrategic;
	class House;
	class Static;
	class snowman: Static
	{
		scope=1;
		displayName="$STR_DN_snowman";
		model="\ca\misc\snowman.p3d";
		vehicleClass="Misc";
	};
	class snow: Static
	{
		scope=1;
		displayName="$STR_DN_snow";
		model="\ca\misc\snow.p3d";
		destrType="DestructNo";
		vehicleClass="Misc";
	};
	class Land_fuel_tank_small: Strategic
	{
		model="\ca\misc\fuel_tank_small.p3d";
		icon="\Ca\misc\data\icons\i_fuel_CA.paa";
		armor=50;
		accuracy=0.5;
		destrType="DestructEngine";
	};
	class Land_Fuel_tank_big: Land_fuel_tank_small
	{
		model="\ca\misc\Fuel_tank_big.p3d";
		icon="\Ca\misc\data\icons\i_fuel_CA.paa";
		displayName="$STR_DN_FUEL_STATION";
	};
	class Land_Fuel_tank_stairs: Land_fuel_tank_small
	{
		model="\ca\misc\Fuel_tank_stairs.p3d";
		icon="\Ca\misc\data\icons\i_fuel_CA.paa";
		ladders[]=
		{
			
			{
				"start",
				"end"
			}
		};
	};
	class Land_water_tank: House
	{
		model="\ca\misc\water_tank.p3d";
		icon="\ca\data\data\Unknown_object.paa";
		destrType="DestructTree";
		ladders[]=
		{
			
			{
				"start",
				"end"
			}
		};
		armor=500;
	};
	class Land_sloup_vn: House
	{
		model="\ca\misc\sloup_vn.p3d";
		icon="\ca\data\data\Unknown_object.paa";
		armor=300;
		class DestructionEffects
		{
			class DamageAround1
			{
				simulation="damageAround";
				type="DamageAroundPole";
				position="map1";
				intensity=1;
				interval=1;
				lifeTime=1;
			};
		};
	};
	class Land_sloup_vn_dratZ: House
	{
		model="\ca\misc\sloup_vn_dratZ.p3d";
		icon="\ca\data\data\Unknown_object.paa";
		//armor=20;
		class DestructionEffects
		{
			class DestroyPhase1
			{
				simulation="destroy";
				type="DelayedDestruction";
				position="";
				intensity=1;
				interval=1;
				lifeTime=1;
			};
		};
	};
	class Land_sloup_vn_drat: House
	{
		model="\ca\misc\sloup_vn_drat.p3d";
		icon="\ca\data\data\Unknown_object.paa";
		//armor=20;
		class DestructionEffects
		{
			class DestroyPhase1
			{
				simulation="destroy";
				type="DelayedDestruction";
				position="";
				intensity=1;
				interval=1;
				lifeTime=1;
			};
		};
	};
	class Land_sloup_vn_drat_d: Land_sloup_vn_drat
	{
		model="\ca\misc\sloup_vn_drat_d.p3d";
	};
};
