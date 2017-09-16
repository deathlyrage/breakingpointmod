/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
[] spawn {
	while {true} do
	{
		_zombie = (getPosATL player) nearestObject "zZombie_Base";
		
		if (!isNull _zombie and alive _zombie) then
		{
			_name = (name _zombie);
			_distance = player distance _zombie;
			_localtargets = _zombie getVariable ["localtargets",[]];
			_remotetargets = _zombie getVariable ["remotetargets",[]];
			_targets = _zombie getVariable ["targets",[]];
			_anim = animationState _zombie;
			
			_dest = _zombie getVariable ["myDest",(getPosATL _zombie)];
			_spr = _zombie getVariable ["myDestSprint",false];
			_dist = (player distance _dest);
			_fsm = _zombie getVariable ["fsm_handle",nil];
			
			_target = objNull;
			_state = "None";
			_stuck = false;
			_completed = "Null";
			_cantSee = true;
			
			if (!isNil "_fsm") then
			{
				_completed = completedFSM _fsm;
				_target = _fsm getFSMVariable "_target";
				if (isNil "_target") then { _target = objNull; };
				_state = _fsm getFSMVariable "_state";
				if (isNil "_state") then { _state = "None"; };
				_stuck = _fsm getFSMVariable "_stuck";
				if (isNil "_stuck") then { _stuck = false; };
				_cantSee = _fsm getFSMVariable "_cantSee";
				if (isNil "_cantSee") then { _cantSee = false; };
			} else {
				_fsm = "Null";
			};
			
			hintSilent format 
			[
				"Visual: %1\n
				Audio: %2\n
				Zombie: %3\n
				Distance: %4\n
				LocalTargets: %5\n
				RemoteTargets: %6\n
				Targets: %7\n
				Anim: %8\n
				Dest: %9\n
				Sprint: %10\n
				Dest Dist: %11\n
				Local: %12\n
				Target: %13\n
				FSM: %14\n
				State: %15\n
				Cant See: %16\n
				Stuck: %17\n
				Completed: %18\n",
				BP_disVisual,
				BP_disAudial,
				_zombie,
				_distance,
				_localtargets,
				_remotetargets,
				_targets,
				_anim,
				_dest,
				_spr,
				_dist,
				local _zombie,
				_target,
				_fsm,
				_state,
				_cantSee,
				_stuck,
				_completed
			];
		};
		sleep 0.1;
	};
};
*/

/*
[] spawn {
	while {true} do
	{
		_class = player getVariable ["class",0];
		_ranger = player getVariable ["ranger",0];
		_outlaw = player getVariable ["outlaw",0];
		_hunter = player getVariable ["hunter",0];
		_nomad = player getVariable ["nomad",0];
		_survivalist = player getVariable ["survivalist",0];
		_zombieKills = player getVariable ["zombieKills",0];
		_playerKills = player getVariable ["humanKills",0];
		_headshots = player getVariable ["headShots",0];
		
		hintSilent format 
		[
			"Blood: %1\n
			Class: %2\n
			Ranger: %3\n
			Outlaw: %4\n
			Hunter: %5\n
			Nomad: %6\n
			Survivalist: %7\n
			Zombie Kills: %8\n
			Player Kills: %9\n
			Headshots: %10\n",
			r_player_blood,
			_class,
			_ranger,
			_outlaw,
			_hunter,
			_nomad,
			_survivalist,
			_zombieKills,
			_playerKills,
			_headshots
		];
		sleep 1;
	};
};
*/

/*
[] spawn {
	while {true} do
	{

		_globalZeds = count (entities "zZombie_Base");
		_aliveZeds = {alive _x} count (entities "zZombie_Base");
		_deadZeds = {!alive _x} count (entities "zZombie_Base");
		_localZeds = {local _x} count (entities "zZombie_Base");
		_remoteZeds = {!local _x} count (entities "zZombie_Base");
		
		_globalLoot = count (entities "BP_LootBox");
		_localLoot = {local _x} count (entities "BP_LootBox");
		_remoteLoot = {!local _x} count (entities "BP_LootBox");
		
		_simulationEnabledLoot = {simulationEnabled _x} count (entities "BP_LootBox");
		_simulationDisabledLoot = {!simulationEnabled _x} count (entities "BP_LootBox");
		_simulationEnabledZeds = {simulationEnabled _x} count (entities "zZombie_Base");
		_simulationDisabledZeds = {!simulationEnabled _x} count (entities "zZombie_Base");
		
		_simulationEnabledStorage = {simulationEnabled _x} count (allMissionObjects "BP_SaveObject");
		_simulationDisabledStorage = {!simulationEnabled _x} count (allMissionObjects "BP_SaveObject");
		
		_simulationEnabledWeaponHolder = {simulationEnabled _x} count (allMissionObjects "WeaponHolder");
		_simulationDisabledWeaponHolder = {!simulationEnabled _x} count (allMissionObjects "WeaponHolder");
		
		_simulationEnabledSWeaponHolder = {simulationEnabled _x} count (allMissionObjects "WeaponHolderSimulated");
		_simulationDisabledSWeaponHolder = {!simulationEnabled _x} count (allMissionObjects "WeaponHolderSimulated");

		_simulationEnabledCars = {simulationEnabled _x} count (entities "Car_F");
		_simulationDisabledCars = {!simulationEnabled _x} count (entities "Car_F");
		
		hintSilent format 
		[

			"Global Zeds: %2\n
			Alive Zeds: %3\n
			Dead Zeds: %4\n
			Local Zeds: %5\n
			Remote Zeds: %6\n
			Global Loot: %7\n
			Local Loot: %8\n
			Remote Loot: %9\n
			SM Enabled Loot: %10\n
			SM Disabled Loot: %11\n
			SM Enabled Zeds: %12\n
			SM Disabled Zeds: %13\n
			SM Enabled Storage: %14\n
			SM Disabled Storage: %15\n
			SM Enabled Cars: %16\n
			SM Disabled Cars: %17\n
			SM Enabled WpnHolders: %18\n
			SM Disabled WpnHolders: %19\n",
			diag_fps,
			_globalZeds,
			_aliveZeds,
			_deadZeds,
			_localZeds,
			_remoteZeds,
			_globalLoot,
			_localLoot,
			_remoteLoot,
			_simulationEnabledLoot,
			_simulationDisabledLoot,
			_simulationEnabledZeds,
			_simulationDisabledZeds,
			_simulationEnabledStorage,
			_simulationDisabledStorage,
			_simulationEnabledCars,
			_simulationDisabledCars,
			_simulationEnabledWeaponHolder,
			_simulationDisabledWeaponHolder,
			_simulationEnabledSWeaponHolder,
			_simulationDisabledSWeaponHolder
		];
		sleep 1;
	};
};

*/

/*
[] spawn {
	while {true} do {
		_dog = player getVariable ["dog",objNull];
		if (!(isNull _dog)) then {
			_dogID = player getVariable ["dogID",0];
			_dogPos = (getPosATL _dog);
			_dogDir = (direction _dog);
			_dogSpeed = (speed _dog);

			_dogHunger = _dogID getFSMVariable "_hunger";
			_dogThrist = _dogID getFSMVariable "_thirst";
			_dogBlood = _dogID getFSMVariable "_blood";
			_dogZombieKills = _dogID getFSMVariable "_zombieKills";
			_dogPlayerKills = _dogID getFSMVariable "_playerKills";
			if (isNil "_dogHunger") then { _dogHunger = 0; };
			if (isNil "_dogThrist") then { _dogThrist = 0; };
			if (isNil "_dogBlood") then { _dogBlood = 8000; };
			if (isNil "_dogZombieKills") then { _dogZombieKills = 0; };
			if (isNil "_dogPlayerKills") then { _dogPlayerKills = 0; };
			
			_dogTarget = _dogID getFSMVariable "_target";
			_dogAttackTarget = _dogID getFSMVariable "_attackTarget";
			_dogCommand = _dogID getFSMVariable "_command";
			_dogCombat = _dogID getFSMVariable "_combat";
			if (isNil "_dogTarget") then { _dogTarget = objNull; };
			if (isNil "_dogAttackTarget") then { _dogAttackTarget = objNull; };
			if (isNil "_dogCommand") then { _dogCommand = ""; };
			if (isNil "_dogCombat") then { _dogCombat = ""; };
			
			hintSilent format 
			[
				"Dog: %1\n
				ID: %2\n
				Position: %3\n
				Direction: %4\n
				Speed: %5\n
				Blood: %6\n
				Thirst: %7\n
				Hunger: %8\n
				Zombie Kills: %9\n
				Player Kills: %10\n
				Target: %11\n
				Attack Target: %12\n
				Command: %13\n
				Combat: %14\n",
				_dog,
				_dogID,
				_dogPos,
				_dogDir,
				_dogSpeed,
				_dogBlood,
				_dogThrist,
				_dogHunger,
				_dogZombieKills,
				_dogPlayerKills,
				_dogTarget,
				_dogAttackTarget,
				_dogCommand,
				_dogCombat
			];
		};
		sleep 1;
	};
};
*/
