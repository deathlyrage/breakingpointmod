////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Fri Mar 21 13:19:59 2014 : Source 'file' date Fri Mar 21 13:19:59 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=8
enum {
	OrdinalEnum = 7,
	destructengine = 2,
	destructdefault = 6,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

//Class misc3 : config.bin{
class CfgPatches
{
	class CAMisc3
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class smallfire;
class CfgVehicles
{
	class HouseBase;
	class House: HouseBase
	{
		class DestructionEffects;
	};
	class NonStrategic;
	class Strategic;
	class static;
	class Ruins;
	class Thing;
	class ThingEffect;
	class TransparentWall: ThingEffect
	{
		scope = 1;
		model = "\Ca\Misc3\TransparentWall";
	};
	class Land_HBarrier_large: NonStrategic
	{
		scope = 2;
		animated = 0;
		vehicleClass = "Fortifications";
		typicalCargo[] = {};
		irTarget = 0;
		mapSize = 9;
		model = "\ca\misc2\BigHBarrier.p3d";
		icon = "\Ca\misc2\data\Icons\icon_hescoBigBarrier_ca.paa";
		displayName = "$STR_DN_HBARRIER_LARGE";
		accuracy = 0.3;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		destrType = "DestructBuilding";
		armor = 500;
		coefInside = 0.5;
		coefInsideHeur = 0.8;
		cost = 0;
		GhostPreview = "Land_HBarrier_largePreview";
	};
	class Land_HBarrier_largePreview: Land_HBarrier_large
	{
		scope = 1;
		model = "\ca\misc2\BigHBarrier_select.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_HBarrier1: Land_HBarrier_large
	{
		model = "\ca\misc2\HBarrier1.p3d";
		icon = "\Ca\misc2\data\Icons\icon_hescoBarrier1_ca.paa";
		mapSize = 2;
		displayName = "$STR_DN_HBARRIER1";
		GhostPreview = "Land_HBarrier1Preview";
	};
	class Land_HBarrier1Preview: Land_HBarrier_large
	{
		scope = 1;
		model = "\ca\misc2\HBarrier1_select.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_HBarrier3: Land_HBarrier_large
	{
		model = "\ca\misc2\HBarrier3.p3d";
		icon = "\Ca\misc2\data\Icons\icon_hescoBarrier3_ca.paa";
		mapSize = 3.5;
		displayName = "$STR_DN_HBARRIER3";
		GhostPreview = "Land_HBarrier3ePreview";
	};
	class Land_HBarrier3ePreview: Land_HBarrier_large
	{
		scope = 1;
		model = "\ca\misc2\HBarrier3_select.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_HBarrier5: Land_HBarrier_large
	{
		model = "\ca\misc2\HBarrier5.p3d";
		icon = "\Ca\misc2\data\Icons\icon_hescoBarrier5_ca.paa";
		mapSize = 7;
		displayName = "$STR_DN_HBARRIER5";
		GhostPreview = "Land_HBarrier5Preview";
	};
	class Land_HBarrier5Preview: Land_HBarrier_large
	{
		scope = 1;
		model = "\ca\misc2\HBarrier5_select.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_fort_bagfence_corner: House
	{
		model = "\Ca\misc3\fort_bagfence_corner";
		displayName = "$STR_DN_FORT_BAGFENCE_CORNER";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceCorner_ca.paa";
		mapSize = 3.2;
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		GhostPreview = "Land_fort_bagfence_cornerPreview";
	};
	class Land_fort_bagfence_cornerPreview: Land_fort_bagfence_corner
	{
		scope = 1;
		model = "\Ca\misc3\fort_bagfence_corner_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_fort_bagfence_long: House
	{
		model = "\Ca\misc3\fort_bagfence_long";
		displayName = "$STR_DN_FORT_BAGFENCE_LONG";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		mapSize = 3.2;
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		GhostPreview = "Land_fort_bagfence_longPreview";
	};
	class Land_fort_bagfence_longPreview: Land_fort_bagfence_long
	{
		scope = 1;
		model = "\Ca\misc3\fort_bagfence_long_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_fort_bagfence_round: House
	{
		model = "\Ca\misc3\fort_bagfence_round";
		displayName = "$STR_DN_FORT_BAGFENCE_ROUND";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceRound_ca.paa";
		mapSize = 3.2;
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		GhostPreview = "Land_fort_bagfence_roundPreview";
	};
	class Land_fort_bagfence_roundPreview: Land_fort_bagfence_round
	{
		scope = 1;
		model = "\Ca\misc3\fort_bagfence_round_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_BagFenceCorner: Land_HBarrier_large
	{
		model = "\ca\misc2\BagFenceCorner.p3d";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceCorner_ca.paa";
		mapSize = 2;
		displayName = "$STR_DN_BAGFENCECORNER";
		destrType = "DestructBuilding";
		armor = 400;
		vehicleClass = "Fortifications";
	};
	class Land_BagFenceEnd: Land_BagFenceCorner
	{
		model = "\ca\misc2\BagFenceEnd.p3d";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		displayName = "$STR_DN_BAGFENCEEND";
		vehicleClass = "Fortifications";
	};
	class Land_BagFenceLong: Land_BagFenceCorner
	{
		model = "\ca\misc2\BagFenceLong.p3d";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		displayName = "$STR_DN_BAGFENCELONG";
		vehicleClass = "Fortifications";
	};
	class Land_BagFenceRound: Land_BagFenceCorner
	{
		model = "\ca\misc2\BagFenceRound.p3d";
		icon = "\Ca\misc3\data\Icons\icon_bagFenceRound_ca.paa";
		displayName = "$STR_DN_BAGFENCEROUND";
		vehicleClass = "Fortifications";
	};
	class Land_BagFenceShort: Land_BagFenceCorner
	{
		model = "\ca\misc2\BagFenceShort.p3d";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		displayName = "$STR_DN_BAGFENCESHORT";
		vehicleClass = "Fortifications";
	};
	class Land_fort_artillery_nest: House
	{
		model = "\Ca\misc3\fort_artillery_nest";
		displayName = "$STR_DN_FORT_ARTILLERY_NEST";
		icon = "\Ca\misc3\data\Icons\icon_fortArtilleryNest_ca.paa";
		mapSize = 20;
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		GhostView = "Land_fort_artillery_nestPreview";
	};
	class Land_fort_artillery_nestPreview: Land_fort_artillery_nest
	{
		scope = 1;
		model = "\Ca\misc3\fort_artillery_nest_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Land_fort_rampart: House
	{
		model = "\Ca\misc3\fort_rampart";
		displayName = "$STR_DN_FORT_RAMPART";
		icon = "\Ca\misc3\data\Icons\icon_fortRamPart_ca.paa";
		mapSize = 10;
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		GhostPreview = "Land_fort_rampartPreview";
	};
	class Land_fort_rampartPreview: Land_fort_rampart
	{
		scope = 1;
		model = "\Ca\misc3\fort_rampart_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Fort_RazorWire: NonStrategic
	{
		scope = 2;
		animated = 0;
		vehicleClass = "Fortifications";
		model = "\ca\misc\Fort_Razorwire";
		icon = "\Ca\misc\data\icons\I_drutkolczasty_CA.paa";
		accuracy = 0.3;
		mapSize = 5.5;
		displayName = "$STR_DN_WIRE";
		destrType = "DestructTent";
		armor = 100;
		GhostPreview = "Fort_RazorWirePreview";
	};
	class Fort_RazorWirePreview: Fort_RazorWire
	{
		scope = 1;
		model = "\ca\misc3\Fort_Razorwire_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Fort_Crate_wood: NonStrategic
	{
		scope = 2;
		displayName = "$STR_DN_FORT_CRATE_WOOD";
		side = 3;
		model = "\ca\misc\drevena_bedna.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		armor = 50;
		vehicleClass = "Fortifications";
	};
	class Fortress1: Strategic{};
	class WarfareBCamp: Fortress1{};
	class Fort_CAmp: WarfareBCamp
	{
		scope = 1;
		displayName = "$STR_DN_FORT_CAMP";
		armor = 20000;
		irTarget = 0;
		vehicleClass = "Fortifications";
		model = "\Ca\misc3\fortified_nest_big";
		icon = "\Ca\misc3\data\Icons\icon_fortNestBig_ca.paa";
		mapSize = 20;
	};
	class Land_fortified_nest_big: House
	{
		model = "\Ca\misc3\fortified_nest_big";
		displayName = "$STR_DN_FORTIFIED_NEST_BIG";
		icon = "\Ca\misc3\data\Icons\icon_fortNestBig_ca.paa";
		scope = 2;
		armor = 500;
		irTarget = 0;
		vehicleClass = "Fortifications";
	};
	class Land_fortified_nest_small: House
	{
		model = "\Ca\misc3\fortified_nest_small";
		displayName = "$STR_DN_FORTIFIED_NEST_SMALL";
		icon = "\Ca\misc3\data\Icons\icon_fortNestSmall_ca.paa";
		mapSize = 5;
		scope = 2;
		armor = 500;
		irTarget = 0;
		vehicleClass = "Fortifications";
		GhostPreview = "Land_fortified_nest_smallPreview";
	};
	class Land_fortified_nest_smallPreview: Land_fortified_nest_small
	{
		scope = 1;
		model = "\Ca\misc3\fortified_nest_small_select";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ca\Misc3\Data\select_GREEN_CA.paa"};
	};
	class Fort_Nest: Land_fortified_nest_small
	{
		scope = 1;
	};
	class Land_Fort_Watchtower: House
	{
		model = "\Ca\misc3\fort_watchtower";
		displayName = "$STR_DN_FORT_WATCHTOWER";
		icon = "\Ca\misc3\data\Icons\icon_fortWatchTower_ca.paa";
		scope = 2;
		armor = 150;
		vehicleClass = "Fortifications";
		ladders[] = {{ "start1","end1" }};
	};
	class WarfareBBaseStructure: House{};
	class Fort_Barracks_USMC: WarfareBBaseStructure
	{
		scope = 2;
		side = 1;
		displayName = "$STR_DN_FORT_BARRACKS_USMC";
		model = "\CA\Misc3\WF\WF_barracks_WEST.p3d";
		icon = "\Ca\misc3\data\Icons\icon_tentEast_ca.paa";
		mapSize = 12;
		vehicleClass = "Fortifications";
	};
	class Hedgehog: Strategic
	{
		scope = 2;
		destrType = "DestructNo";
		cost = 100;
		model = "\ca\misc\jezek_kov";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_HEDGEHOG";
		vehicleClass = "Fortifications";
	};
	class Hhedgehog_concrete: Strategic
	{
		scope = 2;
		destrType = "DestructNo";
		cost = 50;
		model = "\ca\misc3\dragonTeeth\dragonTeeth";
		icon = "\Ca\Misc3\Data\Icons\icon_dragonTeeth_CA.paa";
		mapSize = 2;
		displayName = "$STR_DN_HEDGEHOG_CONCRETE";
		vehicleClass = "Fortifications";
	};
	class Hhedgehog_concreteBig: Hhedgehog_concrete
	{
		model = "\ca\misc3\dragonTeeth\dragonTeethBig";
		displayName = "$STR_DN_HEDGEHOG_CONCRETE2";
		icon = "\Ca\Misc3\Data\Icons\icon_dragonTeethBig_CA.paa";
	};
	class Fort_EnvelopeSmall: House
	{
		scope = 2;
		destrType = "DestructNo";
		vehicleClass = "Fortifications";
		model = "\ca\misc\Fort_EnvelopeSmall";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceRound_ca.paa";
		mapSize = 2;
		displayName = "$STR_DN_ENVELOPESMALL";
	};
	class Fort_EnvelopeBig: House
	{
		scope = 2;
		destrType = "DestructNo";
		vehicleClass = "Fortifications";
		model = "\ca\misc\Fort_EnvelopeBig";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		mapSize = 4;
		displayName = "$STR_DN_ENVELOPEBIG";
	};
	class Fort_Barricade: Strategic
	{
		scope = 2;
		destrType = "DestructNo";
		cost = 10;
		vehicleClass = "Fortifications";
		model = "\ca\misc\Fort_Barricade";
		icon = "\Ca\misc3\data\Icons\icon_fortBagFenceLong_ca.paa";
		mapSize = 4;
		displayName = "$STR_DN_BARRICADE";
	};
	class FoldTable: Thing
	{
		simulation = "thing";
		animated = 0;
		scope = 2;
		vehicleClass = "Furniture";
		model = "\CA\misc2\Table\table.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_FOLDTABLE";
		accuracy = 0.2;
		destrType = "Destructno";
		class DestructionEffects{};
	};
	class FoldChair: Thing
	{
		animated = 0;
		scope = 2;
		vehicleClass = "Furniture";
		model = "\CA\misc2\Table\chair.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_FOLDCHAIR";
		accuracy = 0.2;
		destrType = "Destructno";
		class DestructionEffects{};
	};
	class WoodChair: FoldChair
	{
		model = "\CA\Structures\Furniture\Chairs\ch_mod_c\Ch_mod_c";
		displayName = "$STR_DN_WOODCHAIR";
	};
	class Desk: Thing
	{
		simulation = "thing";
		animated = 0;
		scope = 2;
		vehicleClass = "Furniture";
		model = "\CA\misc2\Desk\desk";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_DESK";
		destrType = "Destructno";
		accuracy = 0.2;
		class DestructionEffects{};
	};
	class SmallTable: Thing
	{
		scope = 2;
		animated = 0;
		vehicleClass = "Furniture";
		model = "\CA\misc2\SmallTable\SmallTable";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_SMALLTABLE";
		accuracy = 0.2;
		armor = 50;
		destrType = "Destructno";
	};
	class Park_bench1: WoodChair
	{
		model = "\ca\buildings\misc\Lavicka_3";
		displayName = "$STR_DN_PARK_BENCH1";
	};
	class Park_bench2: Park_bench1
	{
		model = "\ca\buildings\misc\Lavicka_4";
		displayName = "$STR_DN_PARK_BENCH2";
	};
	class Park_bench2_noRoad: Park_bench2
	{
		model = "\ca\buildings\misc\lavicka_4bezroadwaye";
		displayName = "$STR_DN_PARK_BENCH2_NOROAD";
		accuracy = 1000;
	};
	class Misc_thing: Thing
	{
		scope = 0;
		destrType = "DestructNo";
		animated = 0;
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		vehicleClass = "Misc";
	};
	class Misc_thing_NoInteractive: NonStrategic
	{
		scope = 0;
		destrType = "DestructNo";
		animated = 0;
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		vehicleClass = "Misc";
	};
	class Land_CncBlock: NonStrategic
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\Ca\misc3\CncBlock";
		Icon = "\Ca\misc3\Data\Icons\icon_cnc_con_barrier_CA.paa";
		mapSize = 4;
		displayName = "$STR_MISC_CNCBLOCK";
		armor = 150;
	};
	class Land_CncBlock_Stripes: NonStrategic
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\Ca\misc3\CncBlock_stripes";
		Icon = "\Ca\misc3\Data\Icons\icon_cnc_con_barrier_stripes_CA.paa";
		mapSize = 4;
		displayName = "$STR_MISC_CNCBLOCK_STRIPES";
		armor = 150;
	};
	class Land_CncBlock_D: NonStrategic
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\Ca\misc3\CncBlock_D";
		Icon = "\Ca\misc3\Data\Icons\icon_cnc_con_barrier_CA.paa";
		mapSize = 4;
		displayName = "$STR_MISC_CNCBLOCK_D";
		armor = 150;
	};
	class Land_Toilet: NonStrategic
	{
		scope = 2;
		animated = 1;
		vehicleClass = "Misc";
		typicalCargo[] = {};
		irTarget = 0;
		mapSize = 0.1;
		model = "\CA\Misc3\Toilet.p3d";
		icon = "\CA\Misc3\Data\Toilet_CA.paa";
		displayName = "$STR_MISC_TOILET";
		accuracy = 0.3;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		destrType = "DestructTree";
		armor = 500;
		coefInside = 0.5;
		coefInsideHeur = 0.8;
		cost = 0;
		class AnimationSources
		{
			class Door01
			{
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "Door01_axis";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""Door01"" < 0.5";
				statement = "this animate [""Door01"", 1]";
			};
			class CloseDoors1
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_DOOR";
				position = "Door01_axis";
				radius = 2;
				onlyForPlayer = 1;
				condition = "this animationPhase ""Door01"" >= 0.5";
				statement = "this animate [""Door01"", 0]";
			};
		};
		actionBegin1 = "OpenDoors1";
		actionEnd1 = "OpenDoors1";
	};
	class Land_Fire: House
	{
		model = "\Ca\misc3\fire";
		displayName = "$STR_MISC_FIRE";
		icon = "\ca\misc3\data\Icons\icon_fireplace_ca.paa";
		mapSize = 1;
		scope = 2;
		armor = 150;
		simulation = "fire";
		vehicleClass = "Misc";
		class effects: smallfire
		{
			class Light1
			{
				simulation = "light";
				type = "SmallFireLight";
			};
			class sound
			{
				simulation = "sound";
				type = "Fire";
			};
			class Fire1
			{
				simulation = "particles";
				type = "SmallFireF";
			};
			class Smoke1
			{
				simulation = "particles";
				type = "SmallFireS";
			};
		};
	};
	class Land_Fire_burning: Land_Fire
	{
		accuracy = 1000;
		displayName = "$STR_MISC_FIRE_BURNING";
		class EventHandlers
		{
			init = "(_this select 0) inflame true";
		};
	};
	class Land_Campfire: Land_Fire
	{
		model = "\Ca\misc3\Campfire";
		displayName = "$STR_MISC_CAMPFIRE";
	};
	class Land_Campfire_burning: Land_Campfire
	{
		accuracy = 1000;
		displayName = "$STR_MISC_CAMPFIREBURN";
		class EventHandlers
		{
			init = "(_this select 0) inflame true";
		};
	};
	class Land_Fire_barrel: Land_Fire
	{
		model = "\ca\misc\Barel7";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		displayName = "$STR_MISC_FIRE_BARREL";
		destrType = "DestructEngine";
	};
	class Land_Fire_barrel_burning: Land_Fire_barrel
	{
		accuracy = 1000;
		displayName = "$STR_MISC_FIRE_BARREL_BURNING";
		class EventHandlers
		{
			init = "(_this select 0) inflame true";
		};
	};
	class Misc_TyreHeap: Land_Fire
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\ca\misc\Misc_TyreHeap";
		icon = "\Ca\Misc3\Data\Icons\icomap_tyreHeap_CA.paa";
		mapSize = 2;
		displayName = "$STR_DN_TYREHEAP";
	};
	class Land_ladder: House
	{
		scope = 2;
		displayName = "$STR_MISC_LADDER";
		model = "\ca\misc\ladder.p3d";
		mapSize = 0.6;
		icon = "\Ca\misc\data\icons\i_ladder_CA.paa";
		armor = 50;
		ladders[] = {{ "start","end" }};
		vehicleClass = "Misc";
	};
	class Land_ladder_half: House
	{
		scope = 2;
		displayName = "$STR_MISC_LADDER_HALF";
		model = "\ca\misc\ladder_half.p3d";
		mapSize = 0.6;
		icon = "\Ca\misc\data\icons\i_ladder_CA.paa";
		armor = 50;
		ladders[] = {{ "start","end" }};
		vehicleClass = "Misc";
	};
	class Sr_border: NonStrategic
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\ca\misc2\Sr_border";
		mapSize = 2;
		displayName = "$STR_MISC_SR_BORDER";
		destrType = "DestructNo";
	};
	class Land_kolotoc: Strategic
	{
		scope = 1;
		animated = 0;
		vehicleClass = "misc";
		typicalCargo[] = {};
		irTarget = 0;
		mapSize = 0.7;
		nameSound = "obstacle";
		accuracy = 0.3;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		destrType = "DestructTent";
		coefInside = 0.5;
		coefInsideHeur = 0.8;
		cost = 0;
		armor = 20;
		displayName = "$STR_DN_CAROUSEL";
		model = "\ca\misc\kolotoc.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
	};
	class Land_Barrel_empty: Thing
	{
		scope = 2;
		vehicleClass = "misc";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_empty";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\barrel_CA.paa";
		mapSize = 0.7;
		displayName = "$STR_DN_BARREL_EMPTY";
	};
	class Land_Barrel_water: Thing
	{
		scope = 2;
		vehicleClass = "misc";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_water";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\barrel_CA.paa";
		mapSize = 0.7;
		displayName = "$STR_DN_BARREL_WATER";
	};
	class Land_Barrel_sand: Thing
	{
		scope = 2;
		vehicleClass = "misc";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_sand";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\barrel_CA.paa";
		mapSize = 0.7;
		displayName = "$STR_DN_BARREL_SAND";
	};
	class BarrelHelper: Misc_thing
	{
		vehicleClass = "";
		mapSize = 0.7;
		displayName = "$STR_DN_BARREL";
		accuracy = 0.2;
		transportFuel = 100;
		destrType = "DestructEngine";
	};
	class BarrelBase: BarrelHelper
	{
		accuracy = 1000;
		armor = 20;
		cost = 0;
		supplyRadius = 1.4;
		class DestructionEffects
		{
			class Light1
			{
				simulation = "light";
				type = "ObjectDestructionLight";
				position = "destructionEffect1";
				intensity = 0.001;
				interval = 1;
				lifeTime = 3;
			};
			class Sound
			{
				simulation = "sound";
				type = "Fire";
				position = "destructionEffect1";
				intensity = 1;
				interval = 1;
				lifeTime = 3;
			};
			class Fire1
			{
				simulation = "particles";
				type = "BarelDestructionFire";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Smoke1
			{
				simulation = "particles";
				type = "BarelDestructionSmoke";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.2;
			};
		};
	};
	class Wooden_barrel: BarrelBase
	{
		scope = 1;
		model = "\ca\misc\Barel1";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_WOODEN_BARREL";
		destrType = "DestructNo";
	};
	class Wooden_barrels: Wooden_barrel
	{
		scope = 1;
		model = "\ca\misc\Barels";
		icon = "\Ca\misc\data\icons\i_beczki_CA.paa";
		displayName = "$STR_MISC_WOODEN_BARRELS";
		transportFuel = 400;
		supplyRadius = 2.2;
	};
	class Barrels: BarrelBase
	{
		scope = 2;
		model = "\ca\misc\Barels.p3d";
		icon = "\Ca\misc\data\icons\i_beczki_CA.paa";
		vehicleClass = "Misc";
		displayName = "$STR_DN_BARRELS";
		transportFuel = 400;
		supplyRadius = 2.2;
	};
	class Barrel1: BarrelBase
	{
		scope = 2;
		model = "\ca\misc\Barel1.p3d";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_BARRELRED";
	};
	class Barrel4: BarrelBase
	{
		scope = 2;
		model = "\ca\misc\Barel4.p3d";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_BARRELBLACK";
	};
	class Barrel5: BarrelBase
	{
		scope = 2;
		model = "\ca\misc\Barel5.p3d";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_BARRELGREEN";
	};
	class PaletaBase: NonStrategic
	{
		cost = 0;
		class DestructionEffects{};
		destrType = "DestructNo";
		mapSize = 2;
		displayName = "$STR_DN_PALLET";
		accuracy = 1000;
		icon = "\Ca\Misc3\Data\Icons\icomap_pallete_CA.paa";
	};
	class Paleta1: PaletaBase
	{
		scope = 2;
		model = "\ca\misc\PaletaA.p3d";
		displayName = "$STR_DN_Paleta1";
		vehicleClass = "Misc";
	};
	class Paleta2: PaletaBase
	{
		scope = 2;
		model = "\ca\misc\PaletyC.p3d";
		displayName = "$STR_DN_Paleta2";
		vehicleClass = "Misc";
	};
	class FlagCarrierCore: Strategic{};
	class FlagCarrier: FlagCarrierCore
	{
		model = "\ca\misc\vlajkstozar.p3d";
		icon = "\Ca\misc\data\icons\I_flag_CA.paa";
		supplyRadius = 2;
		nameSound = "obj_flag";
		vehicleClass = "Misc";
	};
	class FlagCarrierUSA: FlagCarrier
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_MISC_FLAGCARRIERUSA";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\data\flag_usa_co.paa""";
		};
	};
	class FlagCarrierCDF: FlagCarrierUSA
	{
		displayName = "$STR_MISC_FLAGCARRIERCDF";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\data\flag_Chernarus_co.paa""";
		};
	};
	class FlagCarrierRU: FlagCarrierUSA
	{
		displayName = "$STR_MISC_FLAGCARRIERRU";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\data\flag_rus_co.paa""";
		};
	};
	class FlagCarrierINS: FlagCarrierUSA
	{
		displayName = "$STR_MISC_FLAGCARRIERINS";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\data\flag_ChDKZ_co.paa""";
		};
	};
	class FlagCarrierGUE: FlagCarrierUSA
	{
		displayName = "$STR_MISC_FLAGCARRIERGUE";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\data\flag_NAPA_co.paa""";
		};
	};
	class HeliH: NonStrategic
	{
		scope = 2;
		model = "\ca\misc\heli_h_army";
		icon = "\Ca\misc\data\icons\i_H_CA.paa";
		displayName = "$STR_DN_HELI_H";
		animated = 0;
		vehicleClass = "Misc";
		accuracy = 0.2;
		typicalCargo[] = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 9.8;
		cost = 0;
		destrType = "DestructNo";
	};
	class HeliHEmpty: HeliH
	{
		model = "\ca\misc\empty";
		displayName = "$STR_DN_HELI_H_EMPTY";
		nameSound = "";
	};
	class HeliHRescue: HeliH
	{
		model = "\ca\misc\Heli_H_rescue";
		displayName = "$STR_MISC_HELIHRESCUE";
	};
	class HeliHCivil: HeliH
	{
		model = "\ca\misc\heli_h_civil";
		displayName = "$STR_MISC_HELIHCIVIL";
	};
	class Land_Misc_deerstand: House
	{
		scope = 2;
		vehicleClass = "Misc";
		armor = 500;
		model = "\Ca\Structures\Misc\Misc_DeerStand\misc_deerstand";
		displayName = "$STR_MISC_DEERSTAND";
		ladders[] = {{ "start1","end1" }};
		icon = "\Ca\Structures\Misc\Misc_DeerStand\data\icon\icon_deerstand_ca.paa";
		mapSize = 3;
	};
	class Land_Misc_GContainer_Big: House
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\Ca\Structures\Misc\Misc_GContainer_Big\Misc_GContainer_Big";
		icon = "\Ca\Structures\Misc\Misc_GContainer_Big\Data\Icon\i_container_big_ca.paa";
		mapSize = 6.5;
		displayName = "$STR_MISC_GCONTAINER_BIG";
	};
	class Land_Misc_Scaffolding: House
	{
		scope = 2;
		vehicleClass = "Misc";
		armor = 500;
		model = "\Ca\Structures\Misc\Misc_Scaffolding\Misc_Scaffolding";
		icon = "\Ca\Structures\Data\Icons\icon_scaffolding_ca.paa";
		mapSize = 16;
		displayName = "$STR_MISC_SCAFFOLDING";
	};
	class Land_Ind_IlluminantTower: House
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\CA\Structures\Ind_SawMill\Ind_IlluminantTower";
		icon = "\Ca\Misc3\Data\Icons\icomap_illuminantTower_CA.paa";
		mapSize = 2;
		ladders[] = {{ "start","end" }};
		displayName = "$STR_MISC_ILLUMINANTTOWER";
	};
	class Land_Ind_Timbers: House
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\ca\structures\Ind_SawMill\Ind_Timbers";
		icon = "\Ca\Structures\Data\Icons\i_timbers_ca.paa";
		mapSize = 9;
		displayName = "$STR_MISC_TIMBERS";
	};
	class Pile_of_wood: Land_Ind_Timbers
	{
		model = "\ca\buildings\misc\drevo_hromada";
		displayName = "$STR_MISC_PILE_OF_WOOD";
	};
	class Land_Ind_BoardsPack1: House
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\ca\structures\Ind_SawMill\Ind_BoardsPack1";
		mapSize = 2;
		displayName = "$STR_MISC_BOARDSPACK";
		icon = "\Ca\Misc3\Data\Icons\icomap_BoardsPack_CA.paa";
	};
	class Land_Ind_BoardsPack2: Land_Ind_BoardsPack1
	{
		model = "\ca\structures\Ind_SawMill\Ind_BoardsPack2";
		displayName = "$STR_MISC_BOARDSPACK2";
	};
	class Land_vysilac_FM2;
	class Land_radar: Land_vysilac_FM2
	{
		armor = 80;
		scope = 2;
		vehicleClass = "Misc";
		displayName = "$STR_DN_RADAR";
	};
	class Fence;
	class Fence_Ind: Fence
	{
		displayName = "$STR_MISC_FENCE_IND";
		model = "\ca\structures\wall\Wall_IndFnc_3";
		scope = 2;
	};
	class Fence_Ind_long: Fence_Ind
	{
		displayName = "$STR_MISC_FENCE_IND_LONG";
		model = "\ca\structures\wall\Wall_IndFnc_9";
	};
	class Fence_corrugated_plate: Fence_Ind
	{
		displayName = "$STR_MISC_FENCE_CORRUGATED_PLATE";
		model = "\ca\structures\wall\Wall_Tin_4";
	};
	class InvisibleFence: Fence_Ind
	{
		scope = 1;
		destrType = "DestructNo";
		displayName = "$STR_DN_InvisibleFence";
		model = "\ca\misc3\InvisibleBarrier";
		icon = "\Ca\buildings\Icons\i_fence_CA.paa";
		mapSize = 25;
	};
	class InvisibleFence2: InvisibleFence
	{
		model = "\ca\misc3\InvisibleBarrier2";
		displayName = "$STR_DN_InvisibleFence2";
	};
	class InvisibleFence3: InvisibleFence
	{
		model = "\ca\misc3\InvisibleBarrier3";
		displayName = "$STR_DN_InvisibleFence3";
	};
	class Haystack: Land_Ind_Timbers
	{
		model = "\ca\buildings\misc\Stoh";
		icon = "\Ca\Misc3\Data\Icons\icomap_haystack_big_CA.paa";
		mapSize = 2;
		displayName = "$STR_MISC_HAYSTACK";
		vehicleClass = "Misc";
	};
	class Garbage_container: Strategic
	{
		scope = 2;
		model = "\ca\misc\Kontejner";
		mapSize = 2;
		displayName = "$STR_MISC_GARBAGE_CONTAINER";
		vehicleClass = "Misc";
	};
	class Garbage_can: Strategic
	{
		scope = 2;
		model = "\ca\misc\popelnice";
		mapSize = 2;
		displayName = "$STR_MISC_GARBAGE_CAN";
		vehicleClass = "Misc";
	};
	class Notice_board: Misc_thing
	{
		scope = 2;
		model = "\ca\misc\nastenkaX";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_NOTICE_BOARD";
	};
	class Axe_woodblock: Misc_thing
	{
		scope = 2;
		model = "\ca\misc\sekyraspalek";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_AXE_WOODBLOCK";
	};
	class Haystack_small: Misc_thing
	{
		scope = 2;
		icon = "\Ca\Misc3\Data\Icons\icomap_haystack_small_CA.paa";
		model = "\ca\misc\seno_balik";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_HAYSTACK_SMALL";
	};
	class Land_seno_balik: House
	{
		scope = 1;
		model = "\ca\misc\seno_balik";
		destrType = "DestructTree";
		armor = 100;
	};
	class Misc_concrete_High: Misc_thing
	{
		scope = 2;
		model = "\ca\buildings2\Misc_concrete\Misc_concrete_High";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_CONCRETE_HIGH";
	};
	class ZavoraAnim: NonStrategic
	{
		scope = 2;
		model = "\Ca\buildings\Misc\zavora_2.p3d";
		displayName = "$STR_MISC_ZAVORAANIM";
		vehicleClass = "Misc";
		icon = "\Ca\buildings\Icons\i_barGate_ca.paa";
		accuracy = 1000;
		animated = 1;
		cost = 0;
		armor = 150;
		mapSize = 7.5;
		destrType = "DestructTree";
		class AnimationSources
		{
			class BarGate
			{
				animPeriod = 6;
			};
		};
		class UserActions
		{
			class OpenGate
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_GATE";
				position = "osa_zavora";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""Bargate"" >= 0.5";
				statement = "this animate [""Bargate"", 0]";
			};
			class CloseGate
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_GATE";
				position = "osa_zavora";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""Bargate"" < 0.5";
				statement = "this animate [""Bargate"", 1]";
			};
		};
		actionBegin1 = "OpenGate";
		actionEnd1 = "OpenGate";
	};
	class Fuel_can: Misc_thing
	{
		scope = 2;
		model = "\ca\misc\FuelCan";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_FUEL_CAN";
	};
	class Wheel_barrow: Misc_thing
	{
		scope = 1;
		model = "\ca\misc\Barel4.p3d";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_WHEEL_BARROW";
	};
	class Unwrapped_sleeping_bag: Misc_thing
	{
		scope = 1;
		model = "\ca\misc\Barel4.p3d";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_UNWRAPPED_SLEEPING_BAG";
	};
	class Pallets_comlumn: Misc_thing
	{
		scope = 1;
		model = "\ca\misc\Barel4.p3d";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_PALLETS_COMLUMN";
	};
	class PowerGenerator: Misc_thing
	{
		scope = 2;
		model = "\ca\misc3\PowerGenerator\PowerGenerator";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_POWERGENERATOR";
	};
	class Satelit: Misc_thing
	{
		scope = 2;
		model = "\ca\misc3\parabola_big\parabola_big";
		vehicleClass = "Misc";
		displayName = "$STR_MISC_SATELIT";
	};
	class Land_psi_bouda: House
	{
		scope = 2;
		vehicleClass = "Misc";
		model = "\ca\buildings\psi_bouda.p3d";
		mapSize = 2;
		displayName = "$STR_MISC_PSI_BOUDA";
		simulation = "house";
	};
	class Land_Pneu: Thing
	{
		scope = 2;
		vehicleClass = "Misc";
		simulation = "thing";
		animated = 0;
		model = "\CA\Structures\Misc\Armory\Pneu\pneu";
		icon = "\Ca\Structures\Misc\Armory\Pneu\Data\icon\pneu_icon_ca.paa";
		displayName = "$STR_DN_PNEU";
		accuracy = 0.2;
		mapSize = 0.2;
		class DestructionEffects{};
	};
	class testsphere1: Thing
	{
		scope = 1;
		model = "\ca\misc\sphere";
		displayName = "$STR_DN_testsphere1";
		icon = "\Ca\misc\data\icons\i_beczka_CA.paa";
		simulation = "thing";
		animated = 0;
		mapSize = 0.4;
		destrType = "DestructNo";
		vehicleClass = "test";
	};
	class testsphere2: testsphere1
	{
		model = "\ca\misc\sphere2";
		displayName = "$STR_DN_testsphere2";
		vehicleClass = "test";
	};
	class Misc_palletsfoiled_heap: Misc_thing_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_palletsfoiled_heap";
		model = "\Ca\misc\Misc_palletsfoiled_heap";
	};
	class Misc_palletsfoiled: Misc_thing_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_palletsfoiled";
		model = "\Ca\misc\Misc_palletsfoiled.p3d";
	};
	class Gunrack1: NonStrategic
	{
		scope = 2;
		vehicleClass = "Ammo";
		model = "\ca\misc2\Gunrack1";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_GUNRACK1";
		transportMaxWeapons = 20;
		transportMaxMagazines = 100;
		supplyRadius = 1.4;
		class AnimationSources
		{
			class TakeWeapon_hide
			{
				source = "User";
				animPeriod = 0.0001;
				initPhase = 0;
			};
		};
	};
	class Gunrack2: Gunrack1
	{
		model = "\ca\misc2\Gunrack2";
		displayName = "$STR_DN_GUNRACK2";
	};
	class Sign_Danger: Thing
	{
		scope = 2;
		model = "\ca\misc\sign_board.p3d";
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		displayName = "$STR_DN_SIGN_DANGER";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		hiddenSelections[] = {"board"};
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_danger_co.paa"};
	};
	class Sign_Checkpoint: Sign_Danger
	{
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		displayName = "$STR_DN_SIGN_CHECKPOINT";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_checkpoint_co.paa"};
	};
	class Sign_Stop: Sign_Checkpoint
	{
		scope = 1;
	};
	class Sign_MP_blu: Sign_Danger
	{
		displayName = "$STR_DN_SIGN_DANGER_MPBLU";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_blufor_co.paa"};
	};
	class Sign_MP_op: Sign_Danger
	{
		displayName = "$STR_DN_SIGN_DANGER_MPOP";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_opfor_co.paa"};
	};
	class Sign_MP_ind: Sign_Danger
	{
		displayName = "$STR_DN_SIGN_DANGER_MPIND";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_board_mp_independent_co.paa"};
	};
	class Sign_1L_Border: Thing
	{
		scope = 2;
		model = "\ca\misc\sign_one_leg_h.p3d";
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		displayName = "$STR_DN_SIGN_1L_BORDER";
		destrType = "DestructNo";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "signs";
		hiddenSelections[] = {"plane"};
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_one_leg_h_border_co.paa"};
	};
	class Sign_1L_Firstaid: Sign_1L_Border
	{
		displayName = "$STR_DN_SIGN_1L_FIRSTAID";
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_one_leg_h_firstaid_co.paa"};
	};
	class Sign_1L_Noentry: Sign_1L_Border
	{
		displayName = "$STR_DN_SIGN_1L_NOENTRY";
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		hiddenSelectionsTextures[] = {"\ca\misc\data\sign_one_leg_h_noentry_co.paa"};
	};
	class Sign_tape_redwhite: Sign_Danger
	{
		model = "\ca\misc\tape_redwhite.p3d";
		icon = "\Ca\misc\data\icons\i_danger_CA.paa";
		displayName = "$STR_DN_SIGN_REDWHITETAPE";
	};
	class Land_arrows_desk_L: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_desk_L";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\arrow_left_desk_CA.paa";
		mapSize = 3;
		displayName = "$STR_DN_ARROWS_DESK_L";
	};
	class Land_arrows_desk_R: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_desk_R";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\arrow_right_desk_CA.paa";
		mapSize = 3;
		displayName = "$STR_DN_ARROWS_DESK_R";
	};
	class Land_arrows_yellow_R: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_yellow_R";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\arrow_yellow_right_CA.paa";
		mapSize = 1.5;
		displayName = "$STR_DN_ARROWS_YELLOW_R";
	};
	class Land_arrows_yellow_L: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_yellow_L";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\arrow_yellow_left_CA.paa";
		mapSize = 1.5;
		displayName = "$STR_DN_ARROWS_YELLOW_L";
	};
	class Land_coneLight: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		simulation = "thing";
		animated = 0;
		model = "\CA\Structures\Misc\Armory\coneLight\coneLight";
		icon = "\ca\data\library\data\icons\road_cone_CA.paa";
		mapSize = 0.1;
		displayName = "$STR_DN_CONELIGHT";
		accuracy = 0.2;
		class DestructionEffects{};
		class MarkerLights
		{
			class YellowBlinking
			{
				name = "zluty pozicni blik";
				color[] = {0.99,0.69,0.17,1.0};
				ambient[] = {0.099,0.069,0.017,1.0};
				brightness = 0.01;
				blinking = 1;
			};
		};
	};
	class Land_RedWhiteBarrier: House
	{
		scope = 2;
		vehicleClass = "signs";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\redWhiteBarrier\Svodidla_5m";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\redWhite_barrier_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_REDWHITEBARRIER";
	};
	class FlagCarrierChecked: FlagCarrierCore
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_DN_FLAGCARRIERCHECKED";
		model = "\ca\structures\misc\armory\checkered_flag\Checkered_flag_holder";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		vehicleClass = "signs";
		nameSound = "obj_flag";
		destrType = "DestructTree";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\ca\structures\misc\armory\checkered_flag\data\checker_flag_co.paa""";
		};
	};
	class FlagCarrierSmall: NonStrategic
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_DN_FLAGCARRIERSMALL";
		model = "\ca\structures\misc\armory\small_flag\small_flag";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		nameSound = "obj_flag";
		destrType = "DestructTree";
		vehicleClass = "signs";
	};
	class Sign_circle: Thing
	{
		scope = 2;
		vehicleClass = "signs";
		simulation = "thing";
		animated = 0;
		model = "\Ca\Data\Training_Ring_30";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 0.1;
		displayName = "$STR_DN_Sign_circle";
		accuracy = 0.2;
		class DestructionEffects{};
	};
	class Small_items: Thing
	{
		vehicleClass = "Small_items";
		destrType = "DestructNo";
		animated = 0;
		mapSize = 2;
	};
	class Small_items_NoInteractive: NonStrategic
	{
		vehicleClass = "Small_items";
		destrType = "DestructNo";
		animated = 0;
		mapSize = 2;
	};
	class SkeetMachine: Small_items
	{
		scope = 2;
		model = "\CA\misc2\SkeetMachine\SkeetMachine.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_SKEETMACHINE";
	};
	class SkeetDisk: Small_items
	{
		simulation = "thing";
		animated = 0;
		scope = 2;
		side = 4;
		cost = 0;
		model = "\CA\misc2\SkeetMachine\SkeetDisk.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		destrType = "DestructDefault";
		displayName = "$STR_DN_SKEETDISK";
		armor = 1;
		class DestructionEffects{};
	};
	class MetalBucket: Small_items
	{
		simulation = "thing";
		animated = 0;
		scope = 2;
		model = "\CA\misc2\MetalBucket\MetalBucket.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_METALBUCKET";
		accuracy = 0.2;
		class DestructionEffects{};
	};
	class FloorMop: Small_items
	{
		animated = 0;
		scope = 2;
		vehicleClass = "Small_items";
		model = "\CA\misc2\FloorMop\floormop.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_FLOORMOP";
		accuracy = 0.2;
		class DestructionEffects{};
	};
	class Baseball: Small_items
	{
		simulation = "thing";
		accuracy = 0.01;
		scope = 2;
		model = "\CA\misc2\Baseball\Baseball.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_BASEBALL";
	};
	class Notebook: Small_items
	{
		scope = 2;
		animated = 0;
		model = "\CA\misc2\Notebook\notebook";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_NOTEBOOK";
		accuracy = 0.2;
		armor = 50;
	};
	class SmallTV: Small_items
	{
		scope = 2;
		animated = 0;
		model = "\CA\misc2\SmallTV\smallTV";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_SMALLTV";
		accuracy = 0.2;
		armor = 50;
	};
	class Suitcase: Small_items
	{
		scope = 2;
		animated = 0;
		model = "\CA\misc3\briefcase";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "$STR_DN_SUITCASE";
		accuracy = 0.2;
		armor = 50;
	};
	class Can_small: Small_items
	{
		scope = 2;
		model = "\ca\misc\Plechovka_1";
		displayName = "$STR_DN_CAN_SMALL";
	};
	class Radio: Small_items
	{
		scope = 2;
		model = "\ca\misc\radio";
		displayName = "$STR_DN_RADIO";
	};
	class SatPhone: Small_items
	{
		scope = 2;
		model = "\CA\Misc3\satelitePhone\satellitePhone";
		displayName = "$STR_DN_SATPHONE";
	};
	class EvPhoto: Small_items
	{
		scope = 2;
		model = "\Ca\misc\SmallObj_File_photos";
		icon = "\CA\misc\data\icons\picture_photo_folder_ca.paa";
		displayName = "$STR_DN_EVIDENCEPHOTO";
	};
	class EvMap: EvPhoto
	{
		model = "\Ca\misc\SmallObj_file_map";
		icon = "\CA\misc\data\icons\picture_maps_CA.paa";
		displayName = "$STR_DN_EVIDENCEMAP";
	};
	class EvMoscow: EvPhoto
	{
		model = "\Ca\misc\SmallObj_moscow_docs";
		icon = "\CA\misc\data\icons\picture_moscow_docs_CA.paa";
		displayName = "$STR_DN_EVIDENCEMOSCOW";
	};
	class EvKobalt: EvPhoto
	{
		model = "\Ca\misc\SmallObj_spukayev_docs";
		icon = "\CA\misc\data\icons\picture_spukayev_docs_ca.paa";
		displayName = "$STR_DN_EVIDENCEKOBALT";
	};
	class EvMoney: EvPhoto
	{
		model = "\Ca\misc\smallObj_money";
		icon = "\CA\misc\data\icons\picture_money_CA.paa";
		displayName = "$STR_DN_EVIDENCEMONEY";
	};
	class EvDogTags: EvPhoto
	{
		model = "\Ca\misc\SmallObj_dog_tags";
		icon = "\CA\misc\data\icons\picture_dog_tags_CA.paa";
		displayName = "$STR_DN_EVIDENCETAGS";
	};
	class Explosive: Small_items_NoInteractive
	{
		scope = 2;
		model = "\CA\misc2\explosive\explosive";
		displayName = "$STR_DN_EXPLOSIVE";
	};
	class Loudspeaker: Small_items_NoInteractive
	{
		scope = 2;
		model = "\Ca\misc\Misc_loudspeakers";
		displayName = "$STR_DN_Loudspeaker";
	};
	class Misc_Wall_lamp: Small_items_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_Wall_lamp";
		vehicleClass = "Small_items";
		icon = "\ca\data\data\Unknown_object.paa";
		model = "\Ca\water2\LHD\Misc_wall_lamp";
	};
	class Misc_Videoprojektor: Small_items_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_Videoprojektor";
		vehicleClass = "Small_items";
		icon = "\ca\data\data\Unknown_object.paa";
		model = "\Ca\misc\misc_videoprojector";
	};
	class Misc_Videoprojektor_platno: Small_items_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_Videoprojektor_platno";
		vehicleClass = "Small_items";
		icon = "\ca\data\data\Unknown_object.paa";
		model = "\Ca\misc\misc_videoprojector_platno";
		hiddenSelections[] = {"obraz"};
	};
	class TargetBase: static
	{
		scope = 0;
		vehicleClass = "Targets";
		displayName = "$STR_DN_TARGET";
		ladders[] = {};
		nameSound = "obj_target";
		cost = 1;
		armor = 0.1;
		type = 0;
	};
	class TargetPopUpTarget: TargetBase
	{
		model = "\Ca\Structures\Misc\Armory\armor_popuptarget\popUpTarget";
		icon = "\Ca\misc\data\icons\i_terc_CA.paa";
		mapSize = 2;
		scope = 2;
		displayName = "$STR_DN_TARGETPOPUP_BIG";
		accuracy = 1000;
		destrType = "DestructEngine";
		class AnimationSources
		{
			class terc
			{
				animPeriod = 1;
			};
		};
		class EventHandlers
		{
			hit = "[(_this select 0)] execVM ""ca\misc\scripts\PopUpTarget.sqf""";
		};
		class DestructionEffects{};
	};
	class TargetEpopup: TargetBase
	{
		model = "\ca\Misc\Terc_Postava";
		icon = "\Ca\misc\data\icons\i_terc_CA.paa";
		mapSize = 2;
		scope = 2;
		displayName = "$STR_DN_TARGETEPOPUP";
		accuracy = 1000;
		destrType = "DestructEngine";
		class AnimationSources
		{
			class terc
			{
				animPeriod = 1;
			};
		};
		class EventHandlers
		{
			hit = "[(_this select 0)] execVM ""ca\misc\scripts\PopUpTarget.sqf""";
		};
		class DestructionEffects{};
	};
	class TargetE: TargetBase
	{
		scope = 2;
		vehicleClass = "Targets";
		displayName = "$STR_DN_TARGETE";
		accuracy = 1000;
		mapSize = 2;
		destrType = "DestructTree";
		icon = "\Ca\misc\data\icons\i_terc_CA.paa";
		model = "\ca\Misc\terc";
		class DestructionEffects{};
	};
	class TargetGrenadBase: TargetBase
	{
		displayName = "$STR_DN_TANK";
		nameSound = "veh_tank";
		accuracy = 0.01;
		cost = 1;
		type = 1;
		irTarget = 1;
		destrType = "DestructDefault";
		alwaysTarget = 1;
		animated = 0;
		memoryPointSupply = "";
		model = "\ca\Misc\drevtank";
		icon = "\Ca\misc\data\icons\i_Drewtank_CA.paa";
		mapSize = 10;
		armor = 70;
		class DestructionEffects
		{
			class Sound
			{
				simulation = "sound";
				type = "DestrHouse";
				position = "destructionEffect1";
				intensity = 1;
				interval = 1;
				lifeTime = 0.05;
			};
			class Ruin1
			{
				simulation = "ruin";
				type = "\CA\misc\Drevtank_ruin.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class TargetGrenade: TargetGrenadBase
	{
		scope = 2;
		displayName = "$STR_DN_TARGETGRENADE";
		accuracy = 1000;
	};
	class TargetFakeTankBase: TargetGrenade
	{
		side = 5;
	};
	class TargetFakeTank: TargetFakeTankBase
	{
		side = 5;
		displayName = "$STR_DN_TARGETGRENADE_LOCKABLE";
		accuracy = 1000;
	};
	class Land_drevtank_ruin: Ruins
	{
		model = "\ca\Misc\drevtank_ruin";
	};
	class Land_A_tent: House
	{
		scope = 2;
		vehicleClass = "Military";
		destrType = "DestructTent";
		armor = 10;
		model = "\CA\Misc3\A_tent";
		displayName = "$STR_DN_A_TENT";
		icon = "\Ca\misc3\data\Icons\icon_Atent_ca.paa";
		mapSize = 3;
	};
	class Land_tent_east: House
	{
		model = "\Ca\misc3\tent_east";
		displayName = "$STR_DN_TENT_EAST";
		icon = "\Ca\misc3\data\Icons\icon_tentEast_ca.paa";
		mapSize = 12;
		scope = 2;
		armor = 150;
		vehicleClass = "Military";
		destrType = "DestructTent";
	};
	class Camp_base: Strategic
	{
		scope = 0;
		displayName = "$STR_DN_TENT";
		destrType = "DestructTent";
		model = "\ca\buildings\Tents\stan";
		icon = "\Ca\buildings\Icons\i_Stan_CA.paa";
		animated = 0;
		vehicleClass = "Military";
		accuracy = 0.2;
		typicalCargo[] = {};
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		cost = 0;
		armor = 20;
		mapSize = 6.4;
	};
	class Camp: Camp_base
	{
		scope = 2;
		model = "\ca\buildings\Tents\stan";
		displayName = "$STR_DN_TENT";
		icon = "\Ca\buildings\Icons\i_Stan_CA.paa";
		accuracy = 1000;
	};
	class CampEast: Camp_base
	{
		scope = 2;
		model = "\ca\buildings\Tents\stan_east";
		icon = "\Ca\buildings\Icons\i_Stan_east_CA.paa";
		displayName = "$STR_DN_CAMPEAST";
		accuracy = 1000;
	};
	class ACamp: Camp_base
	{
		scope = 2;
		model = "\ca\buildings\Tents\astan";
		icon = "\Ca\buildings\Icons\i_Astan_CA.paa";
		displayName = "$STR_DN_ACAMP";
		accuracy = 1000;
		mapSize = 2.6;
	};
	class Military_Item_NoInteractive: Strategic
	{
		vehicleClass = "Military";
		destrType = "DestructNo";
	};
	class Land_GuardShed: House
	{
		scope = 2;
		vehicleClass = "Military";
		irTarget = 0;
		cost = 0;
		model = "\ca\misc2\GuardShed.p3d";
		icon = "\Ca\misc2\data\Icons\icon_guardShed_ca.paa";
		mapSize = 2.4;
		displayName = "$STR_DN_GUARDSHED";
		destrType = "DestructBuilding";
		armor = 150;
	};
	class Land_Antenna: House
	{
		model = "\Ca\misc3\antenna";
		displayName = "$STR_DN_ANTENNA";
		icon = "\Ca\misc3\data\Icons\icon_antenna_ca.paa";
		mapSize = 5;
		scope = 2;
		armor = 150;
		vehicleClass = "Military";
	};
	class Land_CamoNet_NATO: House
	{
		model = "\Ca\misc3\CamoNet_NATO";
		displayName = "$STR_DN_CAMONET_NATO";
		destrType = "DestructTent";
		icon = "\Ca\misc3\data\Icons\icon_camoNet_ca.paa";
		mapSize = 13.5;
		scope = 2;
		armor = 3;
		vehicleClass = "Military";
	};
	class Land_CamoNetVar_NATO: Land_CamoNet_NATO
	{
		model = "\Ca\misc3\CamoNet_NATO_var1";
		displayName = "$STR_DN_CAMONET_NATOVAR";
	};
	class Land_CamoNetB_NATO: Land_CamoNet_NATO
	{
		model = "\Ca\misc3\CamoNetB_NATO";
		displayName = "$STR_DN_CAMONETB_NATO";
		icon = "\Ca\misc3\data\Icons\icon_camoNetBig_ca.paa";
		mapSize = 18;
	};
	class Land_CamoNet_EAST: House
	{
		model = "\Ca\misc3\CamoNet_EAST";
		displayName = "$STR_DN_CAMONET_EAST";
		destrType = "DestructTent";
		icon = "\Ca\misc3\data\Icons\icon_camoNet_ca.paa";
		mapSize = 13.5;
		scope = 2;
		armor = 3;
		vehicleClass = "Military";
	};
	class Land_CamoNetVar_EAST: Land_CamoNet_EAST
	{
		model = "\Ca\misc3\CamoNet_EAST_var1";
		displayName = "$STR_DN_CAMONET_EASTVAR";
	};
	class Land_CamoNetB_EAST: Land_CamoNet_EAST
	{
		model = "\Ca\misc3\CamoNetB_EAST";
		displayName = "$STR_DN_CAMONETB_EAST";
		icon = "\Ca\misc3\data\Icons\icon_camoNetBig_ca.paa";
		mapSize = 18;
	};
	class 76n6ClamShell: Strategic
	{
		scope = 2;
		animated = 0;
		vehicleClass = "Military";
		model = "\CA\misc2\Samsite\76n6_ClamShell";
		displayName = "$STR_DN_76N6CLAMSHELL";
		icon = "\Ca\misc2\data\Icons\icon_samSite_ca.paa";
		mapSize = 16;
		accuracy = 0.2;
		armor = 100;
		destrType = "DestructTree";
	};
	class PowGen_Big: House
	{
		scope = 2;
		animated = 0;
		vehicleClass = "Military";
		model = "\CA\misc2\Samsite\PowGen_Big";
		displayName = "$STR_DN_POWGEN_BIG";
		icon = "\Ca\misc2\data\Icons\icon_powGen_ca.paa";
		mapSize = 7.5;
		ladders[] = {{ "start1","end1" }};
		accuracy = 0.2;
		armor = 50;
		class HitPoints
		{
			class Hit1
			{
				armor = 1;
				material = -1;
				name = "dam 1";
				visual = "damT1";
				passThrough = 0;
				convexComponent = "dam 1";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"CA\misc2\Samsite\Data\powgen_big.rvmat","CA\misc2\Samsite\Data\powgen_big_destruct.rvmat","CA\misc2\Samsite\Data\powgen_big_destruct.rvmat","CA\misc2\Samsite\Data\powgen_mlod.rvmat","CA\misc2\Samsite\Data\powgen_mlod_destruct.rvmat","CA\misc2\Samsite\Data\powgen_mlod_destruct.rvmat"};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\misc2\Samsite\PowGen_Big_ruins";
				position = "";
				intensity = 1;
				interval = 0.05;
				lifeTime = 1;
			};
		};
	};
	class Land_PowGen_Big_ruins: Ruins
	{
		scope = 1;
		vehicleClass = "Ruins";
		model = "\Ca\misc2\Samsite\PowGen_Big_ruins";
	};
	class Land_BarGate2: Land_HBarrier_large
	{
		animated = 1;
		model = "\ca\misc2\BarbGate.p3d";
		icon = "\Ca\misc2\data\Icons\icon_barGate2_ca.paa";
		mapSize = 3;
		displayName = "$STR_DN_BARGATE2";
		destrType = "DestructTree";
		vehicleClass = "Military";
		class AnimationSources
		{
			class Door01
			{
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "Door01_axis";
				radius = 3;
				onlyForPlayer = 1;
				condition = "this animationPhase ""Door01"" < 0.5";
				statement = "this animate [""Door01"", 1]";
			};
			class CloseDoors1
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_DOOR";
				position = "Door01_axis";
				radius = 3;
				onlyForPlayer = 1;
				condition = "this animationPhase ""Door01"" >= 0.5";
				statement = "this animate [""Door01"", 0]";
			};
		};
		actionBegin1 = "OpenDoors1";
		actionEnd1 = "OpenDoors1";
	};
	class Land_Barrack2: House
	{
		scope = 1;
		animated = 0;
		vehicleClass = "Military";
		model = "\CA\misc2\Barrack2\Barrack2";
		displayName = "$STR_DN_BARRACK2";
		icon = "\ca\misc2\data\icons\icon_barrack2_ca.paa";
		mapSize = 11;
		accuracy = 0.2;
		armor = 100;
		destrType = "Destructbuilding";
		class AnimationSources
		{
			class door
			{
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "$STR_DN_OUT_O_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "door_axis";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""door"" >= 0.5";
				statement = "this animate [""door"", 0]";
			};
			class CloseDoors1
			{
				displayNameDefault = "$STR_DN_OUT_C_DOOR_DEFAULT";
				displayName = "$STR_DN_OUT_C_DOOR";
				position = "door_axis";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""door"" < 0.5";
				statement = "this animate [""door"", 1]";
			};
		};
		actionBegin1 = "OpenDoors1";
		actionEnd1 = "OpenDoors1";
	};
	class Barrack2: Land_Barrack2
	{
		scope = 2;
		class Eventhandlers
		{
			init = "(_this select 0) setdir getdir (_this select 0)";
		};
	};
	class MASH: Camp_base
	{
		scope = 2;
		model = "ca\buildings\Tents\mash";
		icon = "\Ca\buildings\Icons\i_MASH_CA.paa";
		displayName = "$STR_DN_MASH";
		accuracy = 0.3;
		attendant = 1;
		mapSize = 6.4;
		supplyRadius = 9.3;
		vehicleClass = "Military";
	};
	class Misc_cargo_cont_small: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_small";
		model = "\Ca\misc\Misc_cargo_cont_small";
	};
	class Misc_cargo_cont_small2: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_small2";
		model = "\Ca\misc\Misc_cargo_cont_small2";
	};
	class Misc_cargo_cont_tiny: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_tiny";
		model = "\Ca\misc\Misc_cargo_cont_tiny";
	};
	class Misc_cargo_cont_net1: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_net1";
		model = "\Ca\misc\Misc_cargo_cont_net1";
	};
	class Misc_cargo_cont_net2: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_net2";
		model = "\Ca\misc\Misc_cargo_cont_net2";
	};
	class Misc_cargo_cont_net3: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_cargo_cont_net3";
		model = "\Ca\misc\Misc_cargo_cont_net3";
	};
	class Misc_Backpackheap: Military_Item_NoInteractive
	{
		scope = 2;
		displayName = "$STR_DN_Misc_Backpackheap";
		model = "\Ca\misc\Misc_Backpackheap";
	};
	class Land_Climbing_Obstacle: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructTree";
		armor = 50;
		model = "\Ca\Structures\Misc\Armory\climbing_obstacle\climbing_obstacle";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\climbing_obstacle_CA.paa";
		mapSize = 5.5;
		displayName = "$STR_DN_CLIMBING_OBSTACLE";
		ladders[] = {{ "start1","end1" },{ "start2","end2" }};
	};
	class PARACHUTE_TARGET: HeliH
	{
		model = "\ca\misc\Heli_H_cross";
		displayName = "$STR_DN_PARACHUTE_TARGET";
		vehicleClass = "training";
	};
	class Land_podlejzacka: Strategic
	{
		scope = 2;
		animated = 0;
		vehicleClass = "training";
		typicalCargo[] = {};
		irTarget = 0;
		mapSize = 0.7;
		model = "\ca\misc\podlejzacka.p3d";
		icon = "\Ca\Misc3\Data\Icons\icomap_crawling_CA.paa";
		displayName = "$STR_DN_PODLEJZACKA";
		accuracy = 0.3;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		destrType = "DestructTent";
		coefInside = 0.5;
		coefInsideHeur = 0.8;
		cost = 0;
		armor = 20;
	};
	class Land_prolejzacka: Land_podlejzacka
	{
		displayName = "$STR_DN_TRAINING_2";
		model = "\ca\misc\prolejzacka.p3d";
		icon = "\ca\misc\data\icons\i_trainingGate_ca.paa";
		destrType = "DestructTree";
	};
	class Land_prebehlavka: Land_podlejzacka
	{
		displayName = "$STR_DN_TRAINING_3";
		model = "\ca\misc\prebehlavka.p3d";
		icon = "\ca\misc\data\icons\i_trainingBridge_ca.paa";
	};
	class Land_obihacka: Land_podlejzacka
	{
		displayName = "$STR_DN_TRAINING_4";
		model = "\ca\misc\obihacka.p3d";
		icon = "\ca\misc\data\icons\i_trainingRailing_ca.paa";
	};
	class Land_obstacle_get_over: Land_podlejzacka
	{
		displayName = "$STR_DN_Land_obstacle_get_over";
		model = "\ca\misc\obstacle_get_over.p3d";
		destrType = "DestructBuilding";
	};
	class Land_obstacle_prone: Land_podlejzacka
	{
		displayName = "$STR_DN_Land_obstacle_prone";
		model = "\ca\misc\obstacle_prone.p3d";
		destrType = "DestructBuilding";
	};
	class Land_obstacle_run_duck: Land_podlejzacka
	{
		displayName = "$STR_DN_Land_obstacle_run_duck";
		model = "\ca\misc\obstacle_run_duck.p3d";
		destrType = "DestructBuilding";
	};
	class Land_WoodenRamp: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructTent";
		armor = 300;
		model = "\CA\Structures\Misc\Armory\woodenramp\woodenRamp";
		icon = "\ca\data\library\data\icons\ramp_concrete_CA.paa";
		displayName = "$STR_DN_WOODENRAMP";
	};
	class Land_ConcreteRamp: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Concrete_ramp\Concrete_ramp";
		icon = "\ca\data\library\data\icons\ramp_concrete_CA.paa";
		displayName = "$STR_DN_CONCRETERAMP2";
	};
	class Land_ConcreteBlock: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\Concrete_block\Concrete_block";
		icon = "\ca\data\library\data\icons\concreteBlock_CA.paa";
		displayName = "$STR_DN_CONCRETEBLOCK";
	};
	class Land_Dirthump01: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump01";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\dirt_hump_CA.paa";
		mapSize = 16;
		displayName = "$STR_DN_DIRTHUMP01";
	};
	class Land_Dirthump02: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump02";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\dirt_hump_CA.paa";
		mapSize = 20;
		displayName = "$STR_DN_DIRTHUMP02";
	};
	class Land_Dirthump03: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump03";
		icon = "\Ca\Structures\Misc\Armory\Data\Icons\dirt_hump_CA.paa";
		mapSize = 24;
		displayName = "$STR_DN_DIRTHUMP03";
	};
	class Land_Shooting_range: House
	{
		scope = 2;
		vehicleClass = "training";
		destrType = "DestructNo";
		model = "\Ca\misc3\shooting_range\shooting_range";
		mapSize = 24;
		displayName = "$STR_DN_Land_Shooting_range";
	};
	class Land_BoatSmall_1: House
	{
		model = "\Ca\misc3\BoatSmall_1";
		displayName = "$STR_DN_WBOATSMALL";
		icon = "Ca\misc3\data\Icons\icon_shipWreck_ca.paa";
		mapSize = 3.7;
		scope = 2;
		vehicleClass = "Wrecks";
	};
	class Land_BoatSmall_2a: Land_BoatSmall_1
	{
		model = "\Ca\misc3\BoatSmall_2a";
		displayName = "$STR_DN_WBOATSMALL_2A";
		icon = "Ca\misc3\data\Icons\icon_shipWreck_ca.paa";
		mapSize = 3.7;
	};
	class Land_BoatSmall_2b: Land_BoatSmall_1
	{
		model = "\Ca\misc3\BoatSmall_2b";
		displayName = "$STR_DN_WBOATSMALL_2B";
		icon = "Ca\misc3\data\Icons\icon_shipWreck_ca.paa";
		mapSize = 3.7;
	};
	class Wreck_Base: Strategic
	{
		scope = 0;
		mapSize = 7;
		animated = 0;
		vehicleClass = "Wrecks";
		accuracy = 0.3;
		destrType = "DestructBuilding";
		class DestructionEffects{};
		cost = 10000;
		armor = 20;
		typicalCargo[] = {};
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
	};
	class HMMWVWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\wheeled\hmmwv_wrecked.p3d";
		icon = "\Ca\misc\data\icons\i_Jeep_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_JEEPWRECK1";
	};
	class BMP2Wreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\bmp2_wrecked.p3d";
		icon = "\Ca\misc\data\icons\i_bmp2_W_CA.paa";
		mapSize = 8;
		displayName = "$STR_DN_BMP2WRECK";
	};
	class UralWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\ural_wrecked.p3d";
		icon = "\Ca\misc\data\icons\i_URAL_W_CA.paa";
		mapSize = 12;
		displayName = "$STR_DN_URALWRECK";
	};
	class datsun01Wreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\datsun01t.p3d";
		icon = "\Ca\misc\data\icons\i_datsun_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_DATSUN01WRECK";
	};
	class datsun02Wreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\datsun02t.p3d";
		icon = "\Ca\misc\data\icons\i_datsun_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_DATSUN02WRECK";
	};
	class hiluxWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\hiluxt.p3d";
		icon = "\Ca\misc\data\icons\i_hilux_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_HILUXWRECK";
	};
	class Mi8Wreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\Mi8_Crashed.p3d";
		Icon = "\ca\air\data\map_ico\icomap_mi17_mg_CA.paa";
		mapSize = 24;
		displayName = "$STR_DN_MI8WRECK";
	};
	class T72Wreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\T72_Wrecked.p3d";
		Icon = "\Ca\tracked\Data\map_ico\icomap_t72_CA.paa";
		mapSize = 9.5;
		displayName = "$STR_DN_T72WRECK";
	};
	class T72WreckTurret: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\t72_wrecked_turret.p3d";
		Icon = "\Ca\tracked\Data\map_ico\icomap_t72_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_T72WRECK_Turret";
	};
	class BRDMWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\BRDM2_Wrecked.p3d";
		Icon = "\Ca\wheeled\data\map_ico\icomap_brdm_CA.paa";
		mapSize = 6;
		displayName = "$STR_DN_BRDMWRECK";
	};
	class UAZWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\misc\UAZ_Wrecked.p3d";
		Icon = "\Ca\wheeled\data\map_ico\icomap_Uaz_CA.paa";
		mapSize = 4;
		displayName = "$STR_DN_UAZWRECK";
	};
	class SKODAWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\wheeled\skodovka_wrecked.p3d";
		icon = "\Ca\misc\data\icons\i_datsun_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_SKODAWRECK";
	};
	class LADAWreck: Wreck_Base
	{
		scope = 2;
		model = "\ca\wheeled2\lada\lada_wrecked.p3d";
		icon = "\Ca\misc\data\icons\i_datsun_W_CA.paa";
		mapSize = 7;
		displayName = "$STR_DN_LADAWRECK";
	};
	class Hanged: NonStrategic
	{
		scope = 2;
		displayName = "$STR_DN_HANGED";
		model = "\CA\characters2\Other\hanged";
		vehicleClass = "Dead_bodies";
		icon = "ca\data\data\Unknown_object.paa";
		mapSize = 2;
		animated = 0;
		accuracy = 0.2;
		cost = 0;
		ladders[] = {};
		destrType = "DestructNo";
	};
	class Hanged_MD: Hanged
	{
		model = "\CA\characters2\Other\Doctor_Hanged";
		displayName = "$STR_DN_HANGED_MD";
		accuracy = 1000;
	};
	class Grave: NonStrategic
	{
		scope = 2;
		model = "\ca\buildings\Misc\hrobecek.p3d";
		icon = "Ca\Structures\Data\Icons\i_grave_CA.paa";
		mapSize = 2;
		displayName = "$STR_DN_GRAVE";
		accuracy = 1000;
		destrType = "DestructNo";
		vehicleClass = "Dead_bodies";
		armor = 20;
	};
	class Body: Grave
	{
		model = "\ca\misc\Mrtvola_Army1.p3d";
		icon = "\ca\data\data\Unknown_object";
		displayName = "$STR_DN_BODY";
		vehicleClass = "Dead_bodies";
		scope = 2;
	};
	class GraveCross1: Grave
	{
		scope = 2;
		model = "\ca\buildings\Misc\hrobecek_krizek1.p3d";
		displayName = "$STR_DN_GRAVECROSS1";
	};
	class GraveCross2: Grave
	{
		scope = 2;
		model = "\ca\buildings\Misc\hrobecek_krizek2.p3d";
		displayName = "$STR_DN_GRAVECROSS2";
	};
	class GraveCrossHelmet: Grave
	{
		scope = 2;
		model = "\ca\buildings\Misc\hrobecek_krizekhelma.p3d";
		displayName = "$STR_DN_GRAVECROSSHELMET";
	};
	class Land_Church_tomb_1: Grave
	{
		scope = 2;
		model = "\Ca\Structures\Misc\church\Church_tomb_1";
		displayName = "$STR_DN_CHURCH_TOMB1";
	};
	class Land_Church_tomb_2: Grave
	{
		scope = 2;
		model = "\Ca\Structures\Misc\church\Church_tomb_2";
		displayName = "$STR_DN_CHURCH_TOMB2";
	};
	class Land_Church_tomb_3: Grave
	{
		scope = 2;
		model = "\Ca\Structures\Misc\church\Church_tomb_3";
		displayName = "$STR_DN_CHURCH_TOMB3";
	};
	class Mass_grave: Grave
	{
		scope = 2;
		model = "\CA\characters2\Other\MassGrave";
		displayName = "$STR_DN_MASS_GRAVE";
		destrType = "DestructBuilding";
		class DestructionEffects{};
		class EventHandlers
		{
			init = "dummy = _this execVM ""ca\characters2\OTHER\scripts\fly.sqf""";
		};
	};
};
class CfgNonAiVehicles
{
	class ProxyFlag
	{
		autocenter = 0;
		scope = 2;
		reversed = 0;
		model = "";
		simulation = "flag";
		selectionFabric = "latka";
	};
	class ProxyFlag_Stozar: ProxyFlag
	{
		model = "\ca\Misc\flag_stozar";
	};
	class ProxyCheckered_flag: ProxyFlag
	{
		model = "\Ca\structures\Misc\Armory\Checkered_flag\Checkered_flag";
	};
	class StreetLamp;
	class Wall_lamp: StreetLamp
	{
		scope = 2;
		displayName = "$STR_DN_Wall_lamp";
		vehicleClass = "Small_items";
		destrType = "DestructNo";
		model = "\Ca\water2\LHD\Misc_wall_lamp";
	};
};
//};
