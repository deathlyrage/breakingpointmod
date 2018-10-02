/*
	Breaking Point Mod: BP_fnc_medicalEvent

	Description:
		Called to determine the functionality when a medical event happens to the local player.
	
	Parameter(s):
		- Type (STRING) - Medical Event Name
		- Data (ARRAY) - Array Of [Unit,Medic] Objects.

	Returns:
		True
*/

private ["_type","_unit","_medic","_data"];
_type = _this select 0;
_data = [(_this select 1),(_this select 2)];
_unit = objectFromNetId (_data select 0);
_medic = objectFromNetId (_data select 1);

["medicalEvent: %1",_this] call BP_fnc_debugConsoleFormat;

if (_unit != player) exitWith {};

switch (_type) do {
	case "medBandage": {
		r_player_injured = false;
		r_player_bleedingLevel = 0;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
		r_player_handler = false;
		if (r_player_blood == r_player_bloodTotal) then {
			player setVariable ["med_lowBlood",false,true];
		};
	};
	case "medFieldDressing": {
		r_player_injured = false;
		r_player_bleedingLevel = 0;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
		r_player_handler = false;
		if (r_player_blood == r_player_bloodTotal) then {
			player setVariable ["med_lowBlood",false,true];
		};
	};
	case "medSurgery": {
		_rndInfection = (random 10);
		_TransfusionInfection = (_rndInfection < 0.3);
		if (_TransfusionInfection) then { r_player_infected = true; };
		if ("ItemFieldDressing" in magazines _medic) then
		{
		_medic removeMagazineGlobal "ItemFieldDressing"; 
		r_player_blood = r_player_bloodTotal;
		r_player_lowblood = false;
		10 fadeSound 1;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
		"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 1],  [1, 1, 1, 1]];"colorCorrections" ppEffectCommit 5;
		r_player_injured = false;
		r_player_bleedingLevel = 0;
		r_player_handler = false;
		player setVariable ["med_lowBlood",false,true];
		} else {
		if (_rndInfection <= 5) then
			{
				r_player_infected = true;
			};
		};
		
		if ("ItemMorphine" in magazines _medic) then
		{
		_medic removeMagazineGlobal "ItemMorphine"; 
		player setVariable ["hit_legs",0];
		player setVariable ["hit_hands",0];
		r_hit_legs = 0;
		r_hit_hands = 0;
		r_fracture_legs = false;
		r_fracture_arms = false;
		r_player_inpain = false;
		} else {
		player say3D ["z_dog_damage_0", 100];
		r_player_unconscious = true;
		r_player_unconsciousWeapon = true;
		};
	};
	case "medSurgeryDog": {
		_dog = player getVariable ["dog",objNull];
		if (!isNull _dog) then {
			_dogID = player getVariable "dogID";
			_dogID setFSMVariable ["_blood",8000];
			_dog setVariable ["med_lowBlood",false,true];
		};		
	};
	case "medMorphine": 	{
		player setVariable ["hit_legs",0];
		player setVariable ["hit_hands",0];
		r_hit_legs = 0;
		r_hit_hands = 0;
		r_fracture_legs = false;
		r_fracture_arms = false;
		r_player_inpain = false;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
	};
	case "medAdrenaline": {
		if (r_player_adrenaline) then {
			[15] call BP_fnc_death;
		} else {	
			r_player_adrenaline = true;
			r_player_adrenalineTime = diag_tickTime;
			"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
			//Random Chance of Death if High health
			if (r_player_blood > 11000) then
			{
				_random = floor (random 100);
				if (_random > 90) then {
					[15] call BP_fnc_death;
				};
			};
		};
	};
	case "medZombie": {
		if ((uniform player) in BP_ZombieClothing) then {
			player playMoveNow "AmovPzmbMstpSnonWnonDnon_fast";
		};
	};
	case "medMedkit": 	{
		r_player_injured = false;
		r_player_bleedingLevel = 0;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
		r_player_handler = false;
		if (r_player_blood == r_player_bloodTotal) then {
			player setVariable ["med_lowBlood",false,true];
		};
		player setVariable ["hit_legs",0];
		player setVariable ["hit_hands",0];
		r_hit_legs = 0;
		r_hit_hands = 0;
		r_fracture_legs = false;
		r_fracture_arms = false;
		r_player_inpain = false;
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
	};
	case "medPainK": {
		r_player_inpain = false;
		
		//Non Effective Message
		if ((r_hit_legs > 0.4) or (r_hit_hands > 0.4)) then {
			cutText ["Painkillers were not effective, Morphine required.", "PLAIN DOWN"];
		};
		if (r_hit_legs < 0.4) then { r_hit_legs = 0; };
		if (r_hit_hands < 0.4) then { r_hit_hands = 0; };
		"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
	};
	case "medAntibiotic": {
		r_player_infected = false;
	};
	case "medBearTrap": {
		r_player_infected = true;
		r_player_injured = true;
		r_player_inpain = true;
		r_hit_legs = 1;
		r_fracture_legs = true;
		[player,"dog_damage",0,false] call BP_fnc_objSpeak;
	};
	case "medGut": {
		private "_BloodHitFX";
		r_player_injured = true;
		r_player_inpain = true;
		r_player_bleedingLevel = 2;
		r_player_lowblood = true;
		r_fracture_arms = true;
		r_player_cardiac = true;
		r_player_infected = true;
		_BloodHitFX = [] spawn
		{
			scriptName "BP_BloodHitFX";
			sleep 0.25;
			"dynamicBlur" ppEffectAdjust [3];
			"dynamicBlur" ppEffectCommit 0.01;
			"dynamicBlur" ppEffectEnable true;
			titleRsc ["BP_BloodsprayLarge","PLAIN",1];
			r_player_blood = r_player_blood - 5000;
			[player,"dog_damage",0,false] call BP_fnc_objSpeak;
			sleep 0.15;
			"dynamicBlur" ppEffectAdjust [0];
			"dynamicBlur" ppEffectCommit 3;
			r_player_blood = r_player_blood - 5000;
			sleep 3;
			"dynamicBlur" ppEffectEnable true;
			r_player_blood = r_player_blood - 5000;
		};
		[_BloodHitFX] call BP_fnc_addThreadHandle;
	};
	case "medBite": {
		private "_BloodHitFX";
		if (!r_player_injured) then 
		{
			r_player_injured = true;
			r_player_inpain = true;
			[player,"dog_damage",0,false] call BP_fnc_objSpeak;
			_BloodHitFX = [] spawn
			{
				scriptName "BP_BloodHitFX";
				sleep 0.25;
				"dynamicBlur" ppEffectAdjust [3];
				"dynamicBlur" ppEffectCommit 0.01;
				"dynamicBlur" ppEffectEnable true;
				r_player_blood = r_player_blood - 250;
				
				//titleRsc ["BP_BloodspraySmall","PLAIN",1];
				//Dog Hit Overlay
				_randomMin = 1;
				_randomMax = 6;
				_random = floor (random _randomMax);
				if (_random > _randomMax) then { _random = _randomMax; };
				if (_random < _randomMin) then { _random = _randomMin; };
				_titleRscImg = format ["BP_Dog_%1",_random];
				titleRsc [_titleRscImg,"PLAIN",1];
				
				r_player_blood = r_player_blood - 250;
				sleep 0.15;
				"dynamicBlur" ppEffectAdjust [0];
				"dynamicBlur" ppEffectCommit 3;
				r_player_blood = r_player_blood - 250;
				sleep 1;
				"dynamicBlur" ppEffectEnable true;
				r_player_blood = r_player_blood - 250;
			};
			[_BloodHitFX] call BP_fnc_addThreadHandle;
		} else {
			r_player_blood = r_player_blood - 450;
		};
	};
};

//Sync / Publish Updated Medical Values
call BP_fnc_medicalSync;

//Save Updated Medical Values
call BP_fnc_medSave;
