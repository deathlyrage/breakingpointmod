////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.32
//Sun Mar 16 15:21:21 2014 : Source 'file' date Sun Mar 16 15:21:21 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class misc2 : config.bin{
class CfgPatches
{
	class CAMisc2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CAData","CABuildings2","CABuildings"};
	};
};
class cfgVehicles
{
	class WeaponHolder;
	class Building;
	class NonStrategic: Building
	{
		class DestructionEffects;
	};
	class Strategic;
	class Thing;
	class HouseBase;
	class House;
	class Car;
	class FoldChair_with_Cargo: Car
	{
		animated = 0;
		scope = 1;
		hasDriver = 0;
		transportSoldier = 1;
		class turrets{};
		cargoAction[] = {"Chair_Cargo"};
		model = "\CA\misc2\Table\chair_cargo.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		mapSize = 2;
		displayName = "$STR_DN_FOLDCHAIR";
		accuracy = 0.2;
		destrType = "DestructNo";
		class DestructionEffects{};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Chair_Cargo = "Chair_Cargo";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_Chair_Cargo: DefaultDie
		{
			actions = "DeadActions";
			file = "\ca\wheeled\Data\Anim\KIA_Skodovka_Cargo01.rtm";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = {"DeadState",0.1};
		};
		class Chair_Cargo: Crew
		{
			file = "\ca\wheeled\Data\Anim\UAZ_Cargo03.rtm";
			interpolateTo[] = {"KIA_Chair_Cargo",0.1};
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class ManActions
	{
		Chair_Cargo = "";
	};
};
//};
