/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_InitMedical";

#define ROLLANIMS ["amovppnemstpsnonwnondnon_amovppnemevasnonwnondl","amovppnemstpsnonwnondnon_amovppnemevasnonwnondr","amovppnemstpsraswrfldnon_amovppnemevaslowwrfldl","amovppnemstpsraswrfldnon_amovppnemevaslowwrfldr","amovppnemstpsraswpstdnon_amovppnemevaslowwpstdl","amovppnemstpsraswpstdnon_amovppnemevaslowwpstdr"]

waitUntil
{
	//Death / End Client
	if (isNil "r_player_dead") exitWith {true};
	if (r_player_dead) exitWith {true};
	
	//Update Config Values
	_class = player getVariable ["class",0];
	_factionName = _class call BP_fnc_getFactionName;
	_configFile = (configFile >> "CfgFactions" >> _factionName);
	_factionLevel = player call BP_fnc_getFactionLevel;
	_levelStr = format ["Level_%1",_factionLevel];
	_maxHealth = getNumber (_configFile >> "Levels" >> _levelStr >> "maxHealth");
	_regenRate = getNumber (_configFile >> "Levels" >> _levelStr >> "regenRate");
	_regenRateSitting = getNumber (_configFile >> "Levels" >> _levelStr >> "regenRateSitting");

	//Handle Undead Health
	if (BP_isUndead) then
	{
		if (r_player_bloodTotal < _maxHealth) then
		{
			r_player_bloodTotal = _maxHealth;
			r_player_blood = _maxHealth;
		};

		//Bypass Medical Effects
		r_player_inpain = false;
		r_player_infected = false;
		r_player_injured = false;
		r_action_rest = false;
		r_player_unconscious = false;
		r_fracture_legs = false;
		r_hit_hands = 0;
		r_hit_legs = 0;
		player enableStamina false;
		player enableFatigue false;
		player SetStamina 60;
	};
	
	//Max Blood
	if (r_player_blood > r_player_bloodTotal) then { r_player_blood = r_player_bloodTotal; };

	//Bleed Out
	if (r_player_blood <= 0) exitWith {
		[17] call BP_fnc_death;
		true
	};
	
	//Low Blood Unconscious
	if ((r_player_blood <= 3000) and (!r_player_handler1) and (!r_action_rest)) then 
	{
		_rnd = random 100;
		if (_rnd > 99) then { [] spawn BP_fnc_medicalUnconscious; };
	};
	
	//Burning
	if (isBurning player) then 
	{
		//Flame Screen Effects
		call BIS_fnc_flamesEffect;

		//Blood Loss Per Second
		r_player_blood = r_player_blood - 25;
		
		//Check If Player Is Lit
		_fire = player getVariable ["fire",objNull];
		if !(isNull _fire) then
		{
			_isWater = surfaceIsWater position player;
			if (_isWater) then
			{
				_fireTime = 0;
				[player,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
			};
		
			//Get Fire Time
			_fireTime = player getVariable ["fireTime",0];

			//Setup Fire Timer
			if (_fireTime < 1) then { _fireTime = 7; };
			
			//Check Backpack / Vest
			_backpack = backpackContainer player;
			_vest = vestContainer player;
			
			_isClear = (isNull _backpack and isNull _vest);

			//Check If Player Is Rolling
			if ((animationState player) in ROLLANIMS) then
			{
				//Lower Fire Duration If Rolling
				_fireTime = _fireTime - 1;
				
				//Lower Fire Time Extra If Clear
				if (_isClear) then { _fireTime = _fireTime - 1; };
				
				//Delete Fire If Expired
				if (_fireTime < 1) then
				{
					_fireTime = 0;
					[player,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
				};
			};
			
			//Set Current Fire Time
			player setVariable ["fireTime",_fireTime];
		} else {
			_fireNearTime = player getVariable ["fireNearTime",0];
			_fireNearTime = _fireNearTime + 1;
			
			if (_fireNearTime > 4) then
			{
				_fireNearTime = 0;
				[(netID player),(netID player)] remoteExecCall ["BPServer_fnc_igniteEntity",2];
			};
			
			player setVariable ["fireNearTime",_fireNearTime];
		};
	};
	
	//Blood Regen Per Second
	if (BP_isHungryUndead) then
	{
		_newHealth = (r_player_blood - _regenRate);
		if (_newHealth < 0) then {
			//Death From Starvation
			[9] call BP_fnc_death;
		} else {
			r_player_blood = _newHealth;
		};
	} else {
		r_player_blood = (r_player_blood + _regenRate);
	};

	//Resting
	if (r_action_rest) then 
	{
		//Can't Rest Inside Vehicle
		if ((vehicle player) != player) then { r_action_rest = false; };
		
		//Process Resting
		//private ["_isNomad","_isNomadTraitor"];
		_isNomad = (_factionName == "Nomad");
		_isNomadTraitor = (_isNomad and _factionLevel < 1);
		
		if (r_player_blood == 12000) exitWith { cutText ["Full health reached.", "PLAIN DOWN"]; };
		
		if ((r_player_blood > 9000) and (!_isNomad or _isNomadTraitor)) exitWith { cutText ["Maximum health regeneration reached.", "PLAIN DOWN"]; };
		if ((r_action_restTime > 15) or (_isNomad)) then {
			r_player_blood = r_player_blood + _regenRateSitting;
			titleRsc ["Default","PLAIN",0];
			titleRsc ["BP_Resting","PLAIN",0];
		} else {
			r_action_restTime = r_action_restTime + 1;
		};
	} else {
		if (r_action_restTime > 0) then {
			cutText ["", "PLAIN DOWN"];
			if !(isNil "BIS_UncCC") then { ppEffectDestroy BIS_UncCC; };
			if !(isNil "BIS_UncRadialBlur") then { ppEffectDestroy BIS_UncRadialBlur; };
			if !(isNil "BIS_UncBlur") then { ppEffectDestroy BIS_UncBlur; };
			if !(isNil "BIS_SuffCC") then { ppEffectDestroy BIS_SuffCC; };
			if !(isNil "BIS_SuffRadialBlur") then { ppEffectDestroy BIS_SuffRadialBlur; };
			if !(isNil "BIS_SuffBlur") then { ppEffectDestroy BIS_SuffBlur; };
			if !(isNil "BIS_TotDesatCC") then { ppEffectDestroy BIS_TotDesatCC; };
			if !(isNil "BIS_TotCC") then { ppEffectDestroy BIS_TotCC; };
			if !(isNil "BIS_TotRadialBlur") then { ppEffectDestroy BIS_TotRadialBlur; };
			if !(isNil "BIS_TotBlur") then { ppEffectDestroy BIS_TotBlur; };
			"dynamicBlur" ppEffectEnable false;
			titleRsc ["Default","PLAIN",0];
			r_action_restTime = 0;
		};
	};
	
	//Handle Unconscious Player
	if (r_player_unconscious) then
	{ 
		//Initially Going Unconscious
		if (!r_player_handler1) then {
			[player] spawn BP_fnc_medicalUnconscious;
		};
		
		//Make Sure Inventory Isn't Open While Unconscious
		if (!isNull (findDisplay 602)) then { closeDialog 0; };
	};
	
	//Handle player bleeding
	if (r_player_injured and !r_player_handler) then 
	{
		r_player_handler = true;
		[] spawn BP_fnc_medicalPlayerBleed;	//publicizes the blood value at regular intervals
	};

	//Removed: Broken
	//if ((r_player_injured or r_player_infected) and (!r_player_handler)) then {
	//	r_player_handler = true;
	//	[] spawn BP_fnc_medicalPlayerBleed;	//publicizes the blood value at regular intervals
	//	call BP_fnc_medSave;
	//};
	
	//Force-Update Factions
	_hitLegs = player getHitPointDamage "HitLegs";
	//_hitHands = player getHitPointDamage "HitHands";
	
	if (r_fracture_legs) then {
		r_hit_legs = 1;
	} else {
		if (_hitLegs > 0.49) then {
			r_hit_legs = 0.4;
		};
	};
	
	if (_hitLegs != r_hit_legs) then 
	{ 
		player setHitPointDamage ["HitLegs",r_hit_legs];
		call BP_fnc_medSave;
	};
	
	//Handle Recoil and Fatigue
	_recoil = 1 + (r_hit_hands * 10);
	if (_recoil > 10) then { _recoil = 10; };
	if (_recoil < 1) then { _recoil = 1; };
	
	//Standard Recoil If on Adrenaline
	if (r_player_adrenaline) then { _recoil = 1; };
		
	//Handle Enabling and Disabling Fatigue
	if (r_hit_legs > 0 and !r_player_adrenaline) then {
		player enableStamina true;
	} else {
		player enableStamina false;
	};
		
	//Set Player Recoil
	player setUnitRecoilCoefficient _recoil;

	//Add player actions
	call BP_fnc_damageActions;
	call BP_fnc_selfActions;
	
	//Low Blood Effects
	if (!r_player_unconscious and !r_player_adrenaline) then 
	{
		if (((r_player_blood/r_player_bloodTotal) < 0.35)) then {
			r_player_lowblood = true;
			if (!BP_isUndead) then { playSound "heartbeat_1"; };
			addCamShake [2, 0.3, 25];
			if (r_player_lowblood) then {
				0 fadeSound ((r_player_blood/r_player_bloodTotal) + 0.5);
				"dynamicBlur" ppEffectEnable true;"dynamicBlur" ppEffectAdjust [2]; "dynamicBlur" ppEffectCommit 0.2;
			};
			sleep 0.5;
			if (r_player_lowblood) then {
				"dynamicBlur" ppEffectEnable true;"dynamicBlur" ppEffectAdjust [0.3]; "dynamicBlur" ppEffectCommit 0.5;
			};
		};
	};
	
	if (r_player_adrenaline) then { 
		playSound "heartbeat_1";
		if ((diag_tickTime - r_player_adrenalineTime) > 60) then {
			r_player_adrenaline = false;
			r_hit_legs = 0.001;
			player enableStamina true;
			player setFatigue 1;
		};
	};
	
	//Screen FX Based on Health / Max Health
	if (BP_isUndead) then {
		"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.5, 0.5, -1.0], [1, 1, 1, (r_player_blood/r_player_bloodTotal)],  [0.3, 0.3, 1, 0.0]];
	} else {
		if (r_player_adrenaline) then {
			"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, (r_player_bloodTotal/r_player_bloodTotal)],  [0.3, 0.3, 1, 0.0]];
		} else {
			"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, (r_player_blood/r_player_bloodTotal)],  [0.3, 0.3, 1, 0.0]];
		};
	};
	"colorCorrections" ppEffectCommit 0;
	
	//Delay
	sleep 1;

	//Publish Any Network Variables to Server / Other Clients
	call BP_fnc_medicalSync;
	
	false
};
