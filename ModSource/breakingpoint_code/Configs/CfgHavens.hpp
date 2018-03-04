/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//External Class Refs
class NonStrategic;
class Ruins_F;
class Strategic;

class HouseBase : NonStrategic
{
	mapSize=14.82;
	author="Bohemia Interactive";
	_generalMacro="HouseBase";
	displayName="House";
	model="";
	vehicleClass="Structures";
	simulation="house";
	accuracy=0.2;
	animated=0;
	armor=300;
	cost=5000;
	ladders[]={};
	class DestructionEffects;
};

class House : HouseBase
{
	author="Bohemia Interactive";
	_generalMacro="House";
	
	coefInside = 1; //2
	coefInsideHeur = 4.3;
	coefSpeedInside = 2;
	
	class DestructionEffects : DestructionEffects {
		class Smoke1 {
			simulation="particles";
			type="HouseDestructionSmoke3";
			position="destructionEffect1";
			qualityLevel=2;
			intensity=0.15;
			interval=1;
			lifeTime=0.05;
		};
		
		class Smoke2 : Smoke1 {
			type="HouseDestructionSmoke4";
			lifeTime=0.035;
		};
		
		class Smoke3 : Smoke1 {
			type="HouseDestrSmokeLong";
			lifeTime=0.035;
		};
		
		class Smoke1Med {
			simulation="particles";
			type="HouseDestructionSmoke3Med";
			position="destructionEffect1";
			qualityLevel=1;
			intensity=0.15;
			interval=1;
			lifeTime=0.05;
		};
		
		class Smoke2Med : Smoke1Med {
			type="HouseDestructionSmoke4Med";
			lifeTime=0.035;
		};
		
		class Smoke3Med : Smoke1Med {
			type="HouseDestrSmokeLongMed";
			lifeTime=0.035;
		};
		
		class Smoke1Low {
			simulation="particles";
			type="HouseDestructionSmoke3Low";
			position="destructionEffect1";
			qualityLevel=0;
			intensity=0.15;
			interval=1;
			lifeTime=0.05;
		};
		
		class Smoke2Low : Smoke1Low {
			type="HouseDestructionSmoke4Low";
			lifeTime=0.035;
		};
		
		class Smoke3Low : Smoke1Low {
			type="HouseDestrSmokeLongLow";
			lifeTime=0.035;
		};
	};
};

class House_F : House
{
	author = "Bohemia Interactive";
	_generalMacro = "House_F";
	scope = 0;
	model = "\A3\Weapons_F\empty.p3d";
	vehicleClass = "Structures";
	cost = 50000;
	armor = 5000; //300
	replaceDamagedLimit = 0.9999;
	class DestructionEffects : DestructionEffects {};
};

class House_Small_F : House_F
{
	mapSize = 8.86;
	_generalMacro = "House_Small_F";
	cost = 35000;
	class DestructionEffects : DestructionEffects
	{
		class Smoke1 : Smoke1 { type="HouseDestructionSmoke3Small"; };
		class Smoke2 : Smoke2 { type="HouseDestructionSmoke4Small"; };
		class Smoke3 : Smoke3 { type="HouseDestrSmokeLongSmall"; };
		class Smoke1Med : Smoke1Med { type="HouseDestructionSmoke3Small"; };
		class Smoke2Med : Smoke2Med { type="HouseDestructionSmoke4Small"; };
		class Smoke3Med : Smoke3Med { type="HouseDestrSmokeLongSmall"; };
		class Smoke1Low : Smoke1Low { type="HouseDestructionSmoke3Small"; };
		class Smoke2Low : Smoke2Low { type="HouseDestructionSmoke4Small"; };
		class Smoke3Low : Smoke3Low { type="HouseDestrSmokeLongSmall"; };
	};
};

class Land_House_Logic : House_F
{
	scope=1;
	armor=400;
	model="\A3\Weapons_f\dummyweapon.p3d";
};

class Land_Shed_Ind02 : House_F
{
	scope=1;
	armor=400;
	model="\CA\Structures\Shed_Ind\Shed_Ind02";
	class DestructionEffects : DestructionEffects {
        class Ruin1 {
			simulation="ruin";
			type="\Ca\Structures\Shed_Ind\Shed_Ind02_ruins.p3d";
			position="";
			intensity=1;
			interval=1;
			lifeTime=1;
        };
	};

	class HitPoints
	{
        class Hit1 {
            armor=0.1;
            material=-1;
            name="dam 1";
            visual="damT1";
            passThrough=0.5;
            convexComponent="dam 1";
            class DestructionEffects {
				class Dust {
					simulation="particles";
					type="HousePartDust";
					position="";
					intensity=1;
					interval=1;
					lifeTime=0.01;
				};
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
			};
		};

        class Hit2 {
            armor=0.1;
            material=-1;
            name="dam 2";
            visual="damT2";
            passThrough=0.5;
            convexComponent="dam 2";
            class DestructionEffects {
				class Dust {
						simulation="particles";
						type="HousePartDust";
						position="";
						intensity=1;
						interval=1;
						lifeTime=0.01;
				};
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
            };
        };

        class Hit3 {
			armor=0.1;
			material=-1;
			name="dam 3";
			visual="damT3";
			passThrough=0.5;
			convexComponent="dam 3";
			class DestructionEffects {
				class Dust {
					simulation="particles";
					type="HousePartDust";
					position="";
					intensity=1;
					interval=1;
					lifeTime=0.01;
				};
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
			};
        };

        class Hit4 {
			armor=0.1;
			material=-1;
			name="dam 4";
			visual="damT4";
			passThrough=0.5;
			convexComponent="dam 4";
			class DestructionEffects {
				class Dust {
						simulation="particles";
						type="HousePartDust";
						position="";
						intensity=1;
						interval=1;
						lifeTime=0.01;
				};
	
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
			};
        };

        class Hit5 {
            armor=0.1;
            material=-1;
            name="dam 5";
            visual="damT5";
            passThrough=0.5;
            convexComponent="dam 5";
            class DestructionEffects {
				class Dust {
					simulation="particles";
					type="HousePartDust";
					position="";
					intensity=1;
					interval=1;
					lifeTime=0.01;
				};
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
			};
        };

        class Hit6 {
			armor=0.1;
			material=-1;
			name="dam 6";
			visual="damT6";
			passThrough=0.5;
			convexComponent="dam 6";
			class DestructionEffects {
				class Dust {
					simulation="particles";
					type="HousePartDust";
					position="";
					intensity=1;
					interval=1;
					lifeTime=0.01;
				};
				class Dust2 : Dust { type="HousePartDustLong"; };
				class Walls : Dust { type="HousePartWall"; };
			};
		};
	
	};

	class AnimationSources {
        class dvere1L {
			animPeriod=2;
			initPhase=1;
		};
        class dvere2L : dvere1L {};
        class dvere1R : dvere1L {};
        class dvere2R : dvere1L {};
	};

	class UserActions 
	{
        class OpenDoors {
            displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
            displayName="Open door";
            position="door_01_action";
            radius=3;
            onlyForPlayer=0;
			condition="((this animationPhase 'dvere1L') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
            statement="this animate ['dvere1L', 1];this animate ['dvere1R', 1]";
		};

        class CloseDoors1 {
            displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
            displayName="Close door";
            position="door_01_action";
            radius=3;
            onlyForPlayer=0;
			condition="((this animationPhase 'dvere1L') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
            statement="this animate ['dvere1L', 0];this animate ['dvere1R', 0]";
		};
		
        class OpenDoors2 {
            displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
            displayName="Open door";
            position="door_02_action";
            radius=2;
            onlyForPlayer=0;
			condition="((this animationPhase 'dvere2L') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
            statement="this animate ['dvere2L', 1];this animate ['dvere2R', 1]";
        };

        class CloseDoors2 {
            displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
            displayName="Close door";
            position="door_02_action";
            radius=2;
            onlyForPlayer=0;
			condition="((this animationPhase 'dvere2L') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
            statement="this animate ['dvere2L', 0];this animate ['dvere2R', 0]";
		};
	};
	numberOfDoors=2;
	actionBegin1="OpenDoors1";
	actionEnd1="OpenDoors1";
	actionBegin2="OpenDoors2";
	actionEnd2="OpenDoors2";
	replaceDamaged="Land_Shed_Ind02_dam";
	replaceDamagedHitpoints[]={"Hit1","Hit2","Hit3","Hit4","Hit5","Hit6"};
};


class Land_Hospital_F : House_F
{
	mapSize=44.79;
	author="Bohemia Interactive";
	scope=1;
	displayName="Hospital";
	model="\A3\Structures_f\Dominants\Hospital\Hospital_F.p3d";
	cost=80000;
	keepInEPESceneAfterDeath=1;
	replaceDamagedHitpoints[]={};
	replaceDamaged="";
	ladders[]={{"Ladder_1_start","Ladder_1_end"}};
	class DestructionEffects {};
};

class Land_FuelStation_Feed_F : House_Small_F
{
	mapSize=1.09;
	author="Bohemia Interactive";
	_generalMacro="Land_FuelStation_Feed_F";
	scope=1;
	displayName="Fuel Station (Feed)";
	model="\A3\Structures_F\Ind\FuelStation\FuelStation_Feed_F.p3d";
	cost=70000;
	memoryPointSupply="Refuel_pos";
	transportFuel=0; //50000
	class DestructionEffects
	{
        class FuelStationSmk1
		{
			simulation="particles";
			type="FuelStationSmk1";
			position="";
			intensity=0.15;
			interval=1;
			lifeTime=0.001;
		};

        class Light1
		{
			simulation="light";
			type="ObjectDestructionLight";
			position="DestructionFire";
			intensity=0.001;
			interval=1;
			lifeTime=0.5;
		};

        class FuelFire1
		{
			simulation="particles";
			type="FuelFire1";
			position="DestructionFire";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};

        class FuelDestr
		{
			simulation="destroy";
			type="FuelStationDestr";
			position="";
			intensity=1;
			interval=1;
			lifeTime=1;
		};

        class FuelSmoke1
		{
			simulation="particles";
			type="FuelFire1";
			position="ObjectDestructionSmokeFuelS";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};

        class FuelSmoke2
		{
			simulation="particles";
			type="ObjectDestructionSmokeFuelS1_2";
			position="DestructionFire";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};
	};
};

class Land_fs_feed_F : House_Small_F
{
	mapSize=0.89;
	author="Bohemia Interactive";
	_generalMacro="Land_fs_feed_F";
	scope=1;
	displayName="Fuel Station (Small, Feed)";
	model="\A3\Structures_f\Ind\FuelStation_Small\fs_feed_F.p3d";
	cost=10000;
	memoryPointSupply="Refuel_pos";
	transportFuel=0; //50000
	class DestructionEffects
	{
		class FuelStationSmk1
		{
			simulation="particles";
			type="FuelStationSmk1";
			position="";
			intensity=0.15;
			interval=1;
			lifeTime=0.001;
		};
		
		class Light1
		{
			simulation="light";
			type="ObjectDestructionLight";
			position="DestructionFire";
			intensity=0.001;
			interval=1;
			lifeTime=0.5;
		};
		
		class FuelFire1
		{
			simulation="particles";
			type="FuelFire1";
			position="DestructionFire";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};
		
		class FuelDestr
		{
			simulation="destroy";
			type="FuelStationDestr";
			position="";
			intensity=1;
			interval=1;
			lifeTime=1;
		};
		
		class FuelSmoke1
		{
			simulation="particles";
			type="FuelFire1";
			position="ObjectDestructionSmokeFuelS";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};
		
		class FuelSmoke2
		{
			simulation="particles";
			type="ObjectDestructionSmokeFuelS1_2";
			position="DestructionFire";
			intensity=0.15;
			interval=1;
			lifeTime=0.5;
		};
	};
};

class Land_A_FuelStation_Feed : Strategic
{
    model = "\ca\structures\House\A_FuelStation\A_FuelStation_Feed";
    transportFuel = 0;
    nameSound = "fuelstation";
    class DestructionEffects {
        class FuelStationExp {
                simulation="particles";
                type="FuelStationExp";
                position="";
                intensity=0.15;
                interval=1;
                lifeTime=0.001;
		};

        class FuelStationSmk1 {
                simulation="particles";
                type="FuelStationSmk1";
                position="";
                intensity=0.15;
                interval=1;
                lifeTime=0.001;
		};

        class Light1 {
                simulation="light";
                type="ObjectDestructionLight";
                position="DestructionFire";
                intensity=0.001;
                interval=1;
                lifeTime=0.5;
		};

        class FuelFire1 {
                simulation="particles";
                type="FuelFire1";
                position="DestructionFire";
                intensity=0.15;
                interval=1;
                lifeTime=0.5;
		};

        class FuelSmoke1 {
                simulation="particles";
                type="FuelSmoke1";
                position="DestructionFire";
                intensity=0.15;
                interval=1;
                lifeTime=0.5;
		};

        class FuelSmoke2 {
                simulation="particles";
                type="FuelSmoke2";
                position="DestructionFire";
                intensity=0.15;
                interval=1;
                lifeTime=0.5;
		};

        class FuelDestr {
                simulation="destroy";
                type="FuelStationDestr";
                position="";
                intensity=1;
                interval=1;
                lifeTime=1;
        };
	};
};

        class Land_Ind_FuelStation_Feed_EP1 : Strategic
                {
                model="\ca\Structures_E\Ind\Ind_FuelStation\Ind_FuelStation_Feed_ep1.p3d";
                transportFuel=0;
                nameSound="fuelstation";
                class DestructionEffects
                        {
                        class FuelStationExp
                                {
                                simulation="particles";
                                type="FuelStationExp";
                                position="";
                                intensity=0.15;
                                interval=1;
                                lifeTime=0.001;
                                };

                        class FuelStationSmk1
                                {
                                simulation="particles";
                                type="FuelStationSmk1";
                                position="";
                                intensity=0.15;
                                interval=1;
                                lifeTime=0.001;
                                };

                        class Light1
                                {
                                simulation="light";
                                type="ObjectDestructionLight";
                                position="DestructionFire";
                                intensity=0.001;
                                interval=1;
                                lifeTime=0.5;
                                };

                        class FuelFire1
                                {
                                simulation="particles";
                                type="FuelFire1";
                                position="DestructionFire";
                                intensity=0.15;
                                interval=1;
                                lifeTime=0.5;
                                };

                        class FuelSmoke1
                                {
                                simulation="particles";
                                type="FuelSmoke1";
                                position="DestructionFire";
                                intensity=0.15;
                                interval=1;
                                lifeTime=0.5;
                                };

                        class FuelSmoke2
                                {
                                simulation="particles";
                                type="FuelSmoke2";
                                position="DestructionFire";
                                intensity=0.15;
                                interval=1;
                                lifeTime=0.5;
                                };

                        class FuelDestr
                                {
                                simulation="destroy";
                                type="FuelStationDestr";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };

                        };

                };

class Land_i_Shed_Ind_F : House_F
{
	mapSize=32.94;
	author="Bohemia Interactive";
	_generalMacro="Land_i_Shed_Ind_F";
	scope=1;
	displayName="Industrial Shed";
	model="\A3\Structures_F\Ind\Shed\i_Shed_Ind_F.p3d";
	cost=1000;
	selectionDamage="DamT_1";
	class DestructionEffects : DestructionEffects {
		class Ruin1 {
			simulation="ruin";
			type="\A3\Structures_F\Ind\Shed\Shed_Ind_ruins_F.p3d";
			position="";
			intensity=1;
			interval=1;
			lifeTime=1;
		};
	};

	class AnimationSources 
	{
        class LockedDoor_source {
			source="user";
			initPhase=0;
			animPeriod=0.1;
		};

        class Door_1_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_2_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_3_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_4_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_5_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_6_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_7_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};

        class Door_8_source {
			source="user";
			initPhase=0;
			animPeriod=1;
		};
	};

	class UserActions
	{
		class OpenDoor_1 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			priority=0.4;
			position="Door_1_trigger";
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleOpen)";
		};
		
		class CloseDoor_1 : OpenDoor_1 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleClose)";
		};
		
		class OpenLockedDoor_1 : OpenDoor_1 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
		};
		
		class OpenDoor_2 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			priority=0.4;
			position="Door_2_trigger";
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleOpen)";
		};
		
		class CloseDoor_2 : OpenDoor_2 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleClose)";
		};
		
		class OpenLockedDoor_2 : OpenDoor_2 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
		};
		
		class OpenDoor_3 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			position="Door_3_trigger";
			priority=0.4;
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorOpen)";
		};
		
		class CloseDoor_3 : OpenDoor_3 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorClose)";
		};
		
		class OpenLockedDoor_3 : OpenDoor_3 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Handle_3_rot_1', 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorOpen)";
		};
		
		class OpenDoor_4 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			position="Door_4_trigger";
			priority=0.4;
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_4_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorOpen)";
		};
		
		class CloseDoor_4 : OpenDoor_4 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_4_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorClose)";
		};
		
		class OpenLockedDoor_4 : OpenDoor_4 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_4_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Handle_4_rot_1', 'Door_Locked_4_rot'] spawn BIS_fnc_LockedDoorOpen)";
		};
		
		class OpenDoor_5 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			priority=0.4;
			position="Door_5_trigger";
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_5_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_5_rot'] call BIS_fnc_DoorNoHandleOpen)";
		};
		
		class CloseDoor_5 : OpenDoor_5 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_5_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_5_rot'] call BIS_fnc_DoorNoHandleClose)";
		};
		
		class OpenLockedDoor_5 : OpenDoor_5 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_5_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Locked_5_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
		};
		
		class OpenDoor_6 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			priority=0.4;
			position="Door_6_trigger";
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_6_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_6_rot'] call BIS_fnc_DoorNoHandleOpen)";
		};
		
		class CloseDoor_6 : OpenDoor_6 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_6_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_6_rot'] call BIS_fnc_DoorNoHandleClose)";
		};
		
		class OpenLockedDoor_6 : OpenDoor_6 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_6_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Locked_6_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
		};
		
		class OpenDoor_7 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			position="Door_7_trigger";
			priority=0.4;
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_7_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_7_rot', 'Door_Handle_7_rot_1', 'Door_Handle_7_rot_2'] call BIS_fnc_DoorOpen)";
		};
		
		class CloseDoor_7 : OpenDoor_7 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_7_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_7_rot', 'Door_Handle_7_rot_1', 'Door_Handle_7_rot_2'] call BIS_fnc_DoorClose)";
		};
		
		class OpenLockedDoor_7 : OpenDoor_7 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_7_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Handle_7_rot_1', 'Door_Locked_7_rot'] spawn BIS_fnc_LockedDoorOpen)";
		};
		
		class OpenDoor_8 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Open door";
			position="Door_8_trigger";
			priority=0.4;
			radius=1.5;
			onlyForPlayer=1;
			condition="((this animationPhase 'Door_8_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_8_rot', 'Door_Handle_8_rot_1', 'Door_Handle_8_rot_2'] call BIS_fnc_DoorOpen)";
		};
		
		class CloseDoor_8 : OpenDoor_8 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			displayName="Close door";
			priority=0.2;
			condition="((this animationPhase 'Door_8_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
			statement="([this, 'Door_8_rot', 'Door_Handle_8_rot_1', 'Door_Handle_8_rot_2'] call BIS_fnc_DoorClose)";
		};
		
		class OpenLockedDoor_8 : OpenDoor_8 {
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			condition="((this animationPhase 'Door_8_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
			statement="([this, 'Door_Handle_8_rot_1', 'Door_Locked_8_rot'] spawn BIS_fnc_LockedDoorOpen)";
		};
	};
	actionBegin1="OpenDoor_1";
	actionEnd1="OpenDoor_1";
	actionBegin2="OpenDoor_2";
	actionEnd2="OpenDoor_2";
	actionBegin3="OpenDoor_3";
	actionEnd3="OpenDoor_3";
	actionBegin4="OpenDoor_4";
	actionEnd4="OpenDoor_4";
	actionBegin5="OpenDoor_5";
	actionEnd5="OpenDoor_5";
	actionBegin6="OpenDoor_6";
	actionEnd6="OpenDoor_6";
	actionBegin7="OpenDoor_7";
	actionEnd7="OpenDoor_7";
	actionBegin8="OpenDoor_8";
	actionEnd8="OpenDoor_8";
	numberOfDoors=8;
};

class Land_i_House_Small_02_V1_F : House_Small_F {
	mapSize=16.41;
	author="Bohemia Interactive";
	_generalMacro="Land_i_House_Small_02_V1_F";
	scope=1;
	displayName="House (Small, White)";
	model="\A3\Structures_F\Households\House_Small02\i_House_Small_02_V1_F.p3d";
	cost=30000;
	selectionDamage="DamT_1";
	replaceDamagedHitpoints[]={"Hitzone_1_hitpoint"};
	replaceDamaged="Land_i_House_Small_02_V1_dam_F";
    class DestructionEffects : DestructionEffects {
		class Ruin1 {
			simulation="ruin";
			type="\A3\Structures_F\Households\House_Small02\House_Small_02_V1_ruins_F.p3d";
			position="";
			intensity=1;
			interval=1;
			lifeTime=1;
		};
	};
 
	class HitPoints {
		class Hitzone_1_hitpoint
		{
			armor=10000;
			material=-1;
			name="Dam_1";
			visual="DamT_1";
			passThrough=0.5;
			radius=0.375;
			convexComponent="Dam_1";
			explosionShielding=950;
			minimalHit=0.1;
			class DestructionEffects {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Glass_1_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_1";
                                visual="Glass_1_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_1_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_2_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_2";
                                visual="Glass_2_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_2_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_3_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_3";
                                visual="Glass_3_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_3_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_4_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_4";
                                visual="Glass_4_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_4_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage {
                    tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                    mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_V1_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V1_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V1_multi.rvmat"};
				};
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Glass_1_source
                                {
                                source="Hit";
                                hitpoint="Glass_1_hitpoint";
                                raw=1;
                                };
 
                        class Glass_2_source
                                {
                                source="Hit";
                                hitpoint="Glass_2_hitpoint";
                                raw=1;
                                };
 
                        class Glass_3_source
                                {
                                source="Hit";
                                hitpoint="Glass_3_hitpoint";
                                raw=1;
                                };
 
                        class Glass_4_source
                                {
                                source="Hit";
                                hitpoint="Glass_4_hitpoint";
                                raw=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                numberOfDoors=2;
                };

       class Land_i_House_Big_02_V1_F : House_F
                {
                mapSize=24.18;
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_02_V1_F";
                scope=1;
                displayName="House (Big, White)";
                model="\A3\Structures_F\Households\House_Big02\i_House_Big_02_V1_F.p3d";
                cost=60000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint","Hitzone_2_hitpoint"};
                replaceDamaged="Land_i_House_Big_02_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\House_Big02\House_Big_02_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Hitzone_2_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_2";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_2";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_2_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Glass_1_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_1";
                                visual="Glass_1_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_1_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_2_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_2";
                                visual="Glass_2_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_2_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_3_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_3";
                                visual="Glass_3_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_3_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_4_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_4";
                                visual="Glass_4_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_4_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_5_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_5";
                                visual="Glass_5_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_5_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_6_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_6";
                                visual="Glass_6_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_6_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_7_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_7";
                                visual="Glass_7_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_7_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_8_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_8";
                                visual="Glass_8_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_8_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_9_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_9";
                                visual="Glass_9_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_9_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V1_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_4_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_5_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_6_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Glass_1_source
                                {
                                source="Hit";
                                hitpoint="Glass_1_hitpoint";
                                raw=1;
                                };
 
                        class Glass_2_source
                                {
                                source="Hit";
                                hitpoint="Glass_2_hitpoint";
                                raw=1;
                                };
 
                        class Glass_3_source
                                {
                                source="Hit";
                                hitpoint="Glass_3_hitpoint";
                                raw=1;
                                };
 
                        class Glass_4_source
                                {
                                source="Hit";
                                hitpoint="Glass_4_hitpoint";
                                raw=1;
                                };
 
                        class Glass_5_source
                                {
                                source="Hit";
                                hitpoint="Glass_5_hitpoint";
                                raw=1;
                                };
 
                        class Glass_6_source
                                {
                                source="Hit";
                                hitpoint="Glass_6_hitpoint";
                                raw=1;
                                };
 
                        class Glass_7_source
                                {
                                source="Hit";
                                hitpoint="Glass_7_hitpoint";
                                raw=1;
                                };
 
                        class Glass_8_source
                                {
                                source="Hit";
                                hitpoint="Glass_8_hitpoint";
                                raw=1;
                                };
 
                        class Glass_9_source
                                {
                                source="Hit";
                                hitpoint="Glass_9_hitpoint";
                                raw=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_3_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_3_rot_1', 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_4_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_4_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_4_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_4_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_4_rot_1', 'Door_Locked_4_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_5
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_5_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_5_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_5_rot', 'Door_Handle_5_rot_1', 'Door_Handle_5_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_5 : OpenDoor_5
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_5_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_5_rot', 'Door_Handle_5_rot_1', 'Door_Handle_5_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_5 : OpenDoor_5
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_5_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_5_rot_1', 'Door_Locked_5_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_6
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_6_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_6_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_6_rot', 'Door_Handle_6_rot_1', 'Door_Handle_6_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_6 : OpenDoor_6
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_6_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_6_rot', 'Door_Handle_6_rot_1', 'Door_Handle_6_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_6 : OpenDoor_6
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_6_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_Handle_6_rot_1', 'Door_Locked_6_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                actionBegin3="OpenDoor_3";
                actionEnd3="OpenDoor_3";
                actionBegin4="OpenDoor_4";
                actionEnd4="OpenDoor_4";
                actionBegin5="OpenDoor_5";
                actionEnd5="OpenDoor_5";
                actionBegin6="OpenDoor_6";
                actionEnd6="OpenDoor_6";
                numberOfDoors=6;
                };
				
        class Land_i_House_Big_02_V1_dam_F : Land_i_House_Big_02_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_02_V1_dam_F";
                scope=1;
                displayName="Damaged Building";
                model="\A3\Structures_F\Households\House_Big02\i_House_Big_02_V1_dam_F.p3d";
                replaceDamagedHitpoints[]={};
                replaceDamaged="";
                class Damage
                        {
                        tex[]={};
                        mat[]={};
                        };
 
                class AnimationSources
                        {
                        class Hitzone_1_source
                                {
                                source="Hit";
                                hitpoint="Hitzone_1_hitpoint";
                                raw=1;
                                };
 
                        class Hitzone_2_source
                                {
                                source="Hit";
                                hitpoint="Hitzone_2_hitpoint";
                                raw=1;
                                };
 
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_4_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_5_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_6_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        };
 
                };

        class Land_i_Stone_Shed_V1_F : House_Small_F
                {
                mapSize=9.91;
                author="Bohemia Interactive";
                _generalMacro="Land_i_Stone_Shed_V1_F";
                scope=1;
                displayName="Stone House (Small, Grey)";
                model="\A3\Structures_F\Households\Stone_Shed\i_Stone_Shed_V1_F.p3d";
                cost=20000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint"};
                replaceDamaged="Land_i_Stone_Shed_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\Stone_Shed\Stone_Shed_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={};
                        mat[]={"A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_ext_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                numberOfDoors=1;
                };
				
class Land_i_Stone_Shed_V2_F : Land_i_Stone_Shed_V1_F
{
	author="Bohemia Interactive";
	_generalMacro="Land_i_Stone_Shed_V2_F";
	displayName="Stone House (Small, Brown)";
	model="\A3\Structures_F\Households\Stone_Shed\i_Stone_Shed_V2_F.p3d";
	replaceDamaged="Land_i_Stone_Shed_V2_dam_F";
	class Damage {
		tex[]={};
		mat[]={"A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_ext_V2_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V2_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V2_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat"};
	};
};
				
        class Land_i_House_Small_03_V1_F : House_F
                {
                mapSize=18.54;
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_03_V1_F";
                scope=1;
                displayName="Bungalow";
                model="\A3\Structures_F\Households\House_Small03\i_House_Small_03_V1_F.p3d";
                cost=30000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint","Hitzone_2_hitpoint"};
                replaceDamaged="Land_i_House_Small_03_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\House_Small03\House_Small_03_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Hitzone_2_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_2";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_2";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_2_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Glass_1_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_1";
                                visual="Glass_1_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_1_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_2_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_2";
                                visual="Glass_2_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_2_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_3_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_3";
                                visual="Glass_3_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_3_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_4_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_4";
                                visual="Glass_4_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_4_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_5_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_5";
                                visual="Glass_5_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_5_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_6_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_6";
                                visual="Glass_6_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_6_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small03\Data\i_HouseSmall_03_V1_interier_multi.rvmat","A3\Structures_F\Households\House_Small03\Data\destruct_i_HouseSmall_03_V1_interier_multi.rvmat","A3\Structures_F\Households\House_Small03\Data\destruct_i_HouseSmall_03_V1_interier_multi.rvmat","A3\Structures_F\Households\House_Small03\Data\i_HouseSmall_03_V1_multi.rvmat","A3\Structures_F\Households\House_Small03\Data\destruct_i_HouseSmall_03_V1_multi.rvmat","A3\Structures_F\Households\House_Small03\Data\destruct_i_HouseSmall_03_V1_multi.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_4_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Glass_1_source
                                {
                                source="Hit";
                                hitpoint="Glass_1_hitpoint";
                                raw=1;
                                };
 
                        class Glass_2_source
                                {
                                source="Hit";
                                hitpoint="Glass_2_hitpoint";
                                raw=1;
                                };
 
                        class Glass_3_source
                                {
                                source="Hit";
                                hitpoint="Glass_3_hitpoint";
                                raw=1;
                                };
 
                        class Glass_4_source
                                {
                                source="Hit";
                                hitpoint="Glass_4_hitpoint";
                                raw=1;
                                };
 
                        class Glass_5_source
                                {
                                source="Hit";
                                hitpoint="Glass_5_hitpoint";
                                raw=1;
                                };
 
                        class Glass_6_source
                                {
                                source="Hit";
                                hitpoint="Glass_6_hitpoint";
                                raw=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_3_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_3_rot_1', 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_4_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_4_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_4_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_4_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_4_rot_1', 'Door_Locked_4_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                actionBegin3="OpenDoor_3";
                actionEnd3="OpenDoor_3";
                actionBegin4="OpenDoor_4";
                actionEnd4="OpenDoor_4";
                numberOfDoors=4;
                };
				
       class Land_i_Stone_HouseSmall_V1_F : House_F
                {
                mapSize=20.41;
                author="Bohemia Interactive";
                _generalMacro="Land_i_Stone_HouseSmall_V1_F";
                scope=1;
                displayName="Stone House (Grey)";
                model="\A3\Structures_f\Households\Stone_Small\i_Stone_HouseSmall_V1_F.p3d";
                cost=30000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint","Hitzone_2_hitpoint"};
                replaceDamaged="Land_i_Stone_HouseSmall_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\Stone_Small\Stone_HouseSmall_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Hitzone_2_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_2";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_2";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_2_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={};
                        mat[]={"A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_V1_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V1_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V1_multi.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1) && ((this animationPhase 'Hitzone_2_hide') < 0.99999				)";
                                statement="([this, 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
                                };
 
                        class OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                priority=0.4;
                                position="Door_3_trigger";
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot'] call BIS_fnc_DoorNoHandleOpen)";
                                };
 
                        class CloseDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot'] call BIS_fnc_DoorNoHandleClose)";
                                };
 
                        class OpenLockedDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorNoHandleOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                actionBegin3="OpenDoor_3";
                actionEnd3="OpenDoor_3";
                numberOfDoors=3;
                };
				
class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F
{
    author="Bohemia Interactive";
    _generalMacro="Land_i_Stone_HouseSmall_V2_F";
    displayName="Stone House (White)";
    model="\A3\Structures_f\Households\Stone_Small\i_Stone_HouseSmall_V2_F.p3d";
    replaceDamaged="Land_i_Stone_HouseSmall_V2_dam_F";
    class Damage {
		tex[]={};
		mat[]={"A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_V2_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V2_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V2_multi.rvmat"};
	}; 
};
				
        class Land_i_Stone_Shed_V3_F : Land_i_Stone_Shed_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_Stone_Shed_V3_F";
                displayName="Stone House (Small, White)";
                model="\A3\Structures_F\Households\Stone_Shed\i_Stone_Shed_V3_F.p3d";
                replaceDamaged="Land_i_Stone_Shed_V3_dam_F";
                class Damage
                        {
                        tex[]={};
                        mat[]={"A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_ext_V3_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V3_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_ext_V3_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat","A3\Structures_F\Households\Stone_Shed\Data\destruct_i_StoneShed_int_V1_multi.rvmat"};
                        };
 
                };
				
        class Land_i_House_Big_02_V3_F : Land_i_House_Big_02_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_02_V3_F";
                displayName="House (Big, Stone)";
                model="\A3\Structures_F\Households\House_Big02\i_House_Big_02_V3_F.p3d";
                replaceDamaged="Land_i_House_Big_02_V3_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V3_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V3_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V3_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat"};
                        };
 
                };
				
        class Land_i_House_Big_02_V2_F : Land_i_House_Big_02_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_02_V2_F";
                displayName="House (Big, Yellow)";
                model="\A3\Structures_F\Households\House_Big02\i_House_Big_02_V2_F.p3d";
                replaceDamaged="Land_i_House_Big_02_V2_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V2_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V2_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V2_multi1.rvmat","A3\Structures_F\Households\House_Big02\Data\i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat","A3\Structures_F\Households\House_Big02\Data\destruct_i_HouseBig_02_V1_multi2.rvmat"};
                        };
 
                };
				
      class Land_i_House_Big_01_V1_F : House_F
                {
                mapSize=16.81;
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_01_V1_F";
                scope=1;
                displayName="House (Large, White)";
                model="\A3\Structures_F\Households\House_Big01\i_House_Big_01_V1_F.p3d";
                cost=60000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint","Hitzone_2_hitpoint"};
                replaceDamaged="Land_i_House_Big_01_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\House_Big01\House_Big_01_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Hitzone_2_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_2";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_2";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_2_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Glass_1_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_1";
                                visual="Glass_1_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_1_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_2_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_2";
                                visual="Glass_2_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_2_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_3_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_3";
                                visual="Glass_3_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_3_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_4_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_4";
                                visual="Glass_4_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_4_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_4_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_5_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_5";
                                visual="Glass_5_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_5_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_5_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_6_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_6";
                                visual="Glass_6_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_6_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_6_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_7_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_7";
                                visual="Glass_7_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_7_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_7_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_8_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_8";
                                visual="Glass_8_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_8_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_8_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_9_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_9";
                                visual="Glass_9_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_9_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_9_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_10_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_10";
                                visual="Glass_10_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_10_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_10_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_11_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_11";
                                visual="Glass_11_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_11_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_11_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_12_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_12";
                                visual="Glass_12_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_12_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_12_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_13_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_13";
                                visual="Glass_13_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_13_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_13_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_14_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_14";
                                visual="Glass_14_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_14_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_14_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v1_multi.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Glass_1_source
                                {
                                source="Hit";
                                hitpoint="Glass_1_hitpoint";
                                raw=1;
                                };
 
                        class Glass_2_source
                                {
                                source="Hit";
                                hitpoint="Glass_2_hitpoint";
                                raw=1;
                                };
 
                        class Glass_3_source
                                {
                                source="Hit";
                                hitpoint="Glass_3_hitpoint";
                                raw=1;
                                };
 
                        class Glass_4_source
                                {
                                source="Hit";
                                hitpoint="Glass_4_hitpoint";
                                raw=1;
                                };
 
                        class Glass_5_source
                                {
                                source="Hit";
                                hitpoint="Glass_5_hitpoint";
                                raw=1;
                                };
 
                        class Glass_6_source
                                {
                                source="Hit";
                                hitpoint="Glass_6_hitpoint";
                                raw=1;
                                };
 
                        class Glass_7_source
                                {
                                source="Hit";
                                hitpoint="Glass_7_hitpoint";
                                raw=1;
                                };
 
                        class Glass_8_source
                                {
                                source="Hit";
                                hitpoint="Glass_8_hitpoint";
                                raw=1;
                                };
 
                        class Glass_9_source
                                {
                                source="Hit";
                                hitpoint="Glass_9_hitpoint";
                                raw=1;
                                };
 
                        class Glass_10_source
                                {
                                source="Hit";
                                hitpoint="Glass_10_hitpoint";
                                raw=1;
                                };
 
                        class Glass_11_source
                                {
                                source="Hit";
                                hitpoint="Glass_11_hitpoint";
                                raw=1;
                                };
 
                        class Glass_12_source
                                {
                                source="Hit";
                                hitpoint="Glass_12_hitpoint";
                                raw=1;
                                };
 
                        class Glass_13_source
                                {
                                source="Hit";
                                hitpoint="Glass_13_hitpoint";
                                raw=1;
                                };
 
                        class Glass_14_source
                                {
                                source="Hit";
                                hitpoint="Glass_14_hitpoint";
                                raw=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1) && ((this animationPhase 'Hitzone_1_hide') < 0.99999				)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_3_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_3_rot_1', 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                actionBegin3="OpenDoor_3";
                actionEnd3="OpenDoor_3";
                numberOfDoors=3;
                };

        class Land_i_House_Big_01_V3_F : Land_i_House_Big_01_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_01_V3_F";
                displayName="House (Large, Stone)";
                model="\A3\Structures_F\Households\House_Big01\i_House_Big_01_V3_F.p3d";
                replaceDamaged="Land_i_House_Big_01_V3_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_v3_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v3_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v3_multi.rvmat"};
                        };
 
                };
				
        class Land_i_House_Big_01_V2_F : Land_i_House_Big_01_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Big_01_V2_F";
                displayName="House (Large, Yellow)";
                model="\A3\Structures_F\Households\House_Big01\i_House_Big_01_V2_F.p3d";
                replaceDamaged="Land_i_House_Big_01_V2_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_add_v1_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\i_House_Big_v2_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v2_multi.rvmat","A3\Structures_F\Households\House_Big01\Data\destruct_i_House_Big_v2_multi.rvmat"};
                        };
 
                };
			
 
         class Land_i_House_Small_02_V2_F : Land_i_House_Small_02_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_02_V2_F";
                displayName="House (Small, Yellow)";
                model="\A3\Structures_F\Households\House_Small02\i_House_Small_02_V2_F.p3d";
                replaceDamaged="Land_i_House_Small_02_V2_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_V2_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V2_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V2_multi.rvmat"};
                        };
                };
				
        class Land_i_House_Small_02_V3_F : Land_i_House_Small_02_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_02_V3_F";
                displayName="House (Small, Stone)";
                model="\A3\Structures_F\Households\House_Small02\i_House_Small_02_V3_F.p3d";
                replaceDamaged="Land_i_House_Small_02_V3_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_add_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\i_HouseSmall_02_V3_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V3_multi.rvmat","A3\Structures_F\Households\House_Small02\Data\destruct_i_HouseSmall_02_V3_multi.rvmat"};
                        };
 
                };
				
       class Land_i_House_Small_01_V1_F : House_F
                {
                mapSize=15.29;
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_01_V1_F";
                scope=1;
                displayName="House (White)";
                model="\A3\Structures_F\Households\House_Small01\i_House_Small_01_V1_F.p3d";
                cost=30000;
                selectionDamage="DamT_1";
                replaceDamagedHitpoints[]={"Hitzone_1_hitpoint","Hitzone_2_hitpoint"};
                replaceDamaged="Land_i_House_Small_01_V1_dam_F";
                class DestructionEffects : DestructionEffects
                        {
                        class Ruin1
                                {
                                simulation="ruin";
                                type="\A3\Structures_F\Households\House_Small01\House_Small_01_V1_ruins_F.p3d";
                                position="";
                                intensity=1;
                                interval=1;
                                lifeTime=1;
                                };
 
                        };
 
                class HitPoints
                        {
                        class Hitzone_1_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_1";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_1";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_1_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Hitzone_2_hitpoint
                                {
                                armor=10000;
                                material=-1;
                                name="Dam_2";
                                visual="DamT_1";
                                passThrough=0.5;
                                radius=0.375;
                                convexComponent="Dam_2";
                                explosionShielding=950;
                                minimalHit=0.1;
                                class DestructionEffects
                                        {
                                        class Dust
                                                {
                                                simulation="particles";
                                                type="HousePartDust";
                                                position="Dam_2_effects";
                                                intensity=1;
                                                interval=1;
                                                lifeTime=0.01;
                                                };
 
                                        class Dust2 : Dust
                                                {
                                                type="HousePartDustLong";
                                                };
 
                                        class Walls : Dust
                                                {
                                                type="HousePartWall";
                                                };
 
                                        };
 
                                };
 
                        class Glass_1_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_1";
                                visual="Glass_1_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_1_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_1_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_2_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_2";
                                visual="Glass_2_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_2_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_2_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        class Glass_3_hitpoint
                                {
                                armor=0.001;
                                material=-1;
                                name="Glass_3";
                                visual="Glass_3_hide";
                                passThrough=1;
                                radius=0.175;
                                convexComponent="Glass_3_hide";
                                class DestructionEffects
                                        {
                                        class BrokenGlass1
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7NN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass1S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass1SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass2S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass2SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass3S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass3SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass4S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass4SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass5S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass5SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass6S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass6SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        class BrokenGlass7S
                                                {
                                                simulation="particles";
                                                type="BrokenGlass7SN";
                                                position="Glass_3_effects";
                                                intensity=0.15;
                                                interval=1;
                                                lifeTime=0.05;
                                                };
 
                                        };
 
                                };
 
                        };
 
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V1_multi.rvmat"};
                        };
 
                class AnimationSources
                        {
                        class LockedDoor_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=0.1;
                                };
 
                        class Door_1_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_2_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_3_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Door_4_source
                                {
                                source="user";
                                initPhase=0;
                                animPeriod=1;
                                };
 
                        class Glass_1_source
                                {
                                source="Hit";
                                hitpoint="Glass_1_hitpoint";
                                raw=1;
                                };
 
                        class Glass_2_source
                                {
                                source="Hit";
                                hitpoint="Glass_2_hitpoint";
                                raw=1;
                                };
 
                        class Glass_3_source
                                {
                                source="Hit";
                                hitpoint="Glass_3_hitpoint";
                                raw=1;
                                };
 
                        };
 
                class UserActions
                        {
                        class OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_1_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_1 : OpenDoor_1
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_2_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_2 : OpenDoor_2
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_3_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_3_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_3_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_3_rot', 'Door_Handle_3_rot_1', 'Door_Handle_3_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_3 : OpenDoor_3
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_3_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_3_rot_1', 'Door_Locked_3_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        class OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Open door";
                                position="Door_4_trigger";
                                priority=0.4;
                                radius=1.5;
                                onlyForPlayer=1;
                                condition="((this animationPhase 'Door_4_rot') < 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorOpen)";
                                };
 
                        class CloseDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                displayName="Close door";
                                priority=0.2;
                                condition="((this animationPhase 'Door_4_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door',0]) != 1)";
                                statement="([this, 'Door_4_rot', 'Door_Handle_4_rot_1', 'Door_Handle_4_rot_2'] call BIS_fnc_DoorClose)";
                                };
 
                        class OpenLockedDoor_4 : OpenDoor_4
                                {
                                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                                condition="((this animationPhase 'Door_4_rot') < 0.1) && ((this getVariable ['bis_disabled_Door',0]) == 1)";
                                statement="([this, 'Door_Handle_4_rot_1', 'Door_Locked_4_rot'] spawn BIS_fnc_LockedDoorOpen)";
                                };
 
                        };
 
                actionBegin1="OpenDoor_1";
                actionEnd1="OpenDoor_1";
                actionBegin2="OpenDoor_2";
                actionEnd2="OpenDoor_2";
                actionBegin3="OpenDoor_3";
                actionEnd3="OpenDoor_3";
                actionBegin4="OpenDoor_4";
                actionEnd4="OpenDoor_4";
                numberOfDoors=4;
                };
				
        class Land_i_House_Small_01_V2_F : Land_i_House_Small_01_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_01_V2_F";
                displayName="House (Yellow)";
                model="\A3\Structures_F\Households\House_Small01\i_House_Small_01_V2_F.p3d";
                replaceDamaged="Land_i_House_Small_01_V2_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_01_V2_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V2_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V2_multi.rvmat"};
                        };
 
                };
				
        class Land_i_House_Small_01_V3_F : Land_i_House_Small_01_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_House_Small_01_V3_F";
                displayName="House (Stone)";
                model="\A3\Structures_F\Households\House_Small01\i_House_Small_01_V3_F.p3d";
                replaceDamaged="Land_i_House_Small_01_V3_dam_F";
                class Damage
                        {
                        tex[]={"A3\Structures_F\Data\Windows\window_set_CA.paa","A3\Structures_F\Data\Windows\destruct_half_window_set_CA.paa"};
                        mat[]={"A3\Structures_F\Data\Windows\window_set.rvmat","A3\Structures_F\Data\Windows\destruct_half_window_set.rvmat","A3\Structures_F\Data\Windows\destruct_full_window_set.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_add_01_V1_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\i_HouseSmall_01_V3_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V3_multi.rvmat","A3\Structures_F\Households\House_Small01\Data\destruct_i_HouseSmall_01_V3_multi.rvmat"};
                        };
 
                };

        class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F
                {
                author="Bohemia Interactive";
                _generalMacro="Land_i_Stone_HouseSmall_V3_F";
                displayName="Stone House (Brown)";
                model="\A3\Structures_f\Households\Stone_Small\i_Stone_HouseSmall_V3_F.p3d";
                replaceDamaged="Land_i_Stone_HouseSmall_V3_dam_F";
                class Damage
                        {
                        tex[]={};
                        mat[]={"A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_addons_V1.rvmat","A3\Structures_F\Households\Stone_Small\Data\i_StoneSmall_V3_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V3_multi.rvmat","A3\Structures_F\Households\Stone_Small\Data\destruct_i_StoneSmall_V3_multi.rvmat"};
                        };
 
                };
