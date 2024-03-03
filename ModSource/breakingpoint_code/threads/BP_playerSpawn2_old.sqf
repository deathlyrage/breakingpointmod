/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BP_playerSpawn2";

private ["_size","_vel","_speed","_hunger","_thirst","_array","_unsaved"];

waitUntil
{
	//Initialize
	_vehicle = (vehicle player);
	_inVehicle = (_vehicle != player);
	_size = (sizeOf typeOf _vehicle) * 0.6;
	_vel = velocity player;
	_speed = round((_vel distance [0,0,0]) * 3.5);
	_saveTimeMed = 60; // 1 Minutes
	
	//Reset Aim Coeff
	player setCustomAimCoef 0.1;
	
	//Check Player In Debug
	if (player call BP_fnc_isInDebug) exitWith {
		if (_inVehicle) then {
			_vehicle setDamage 1;
		} else {
			["BP_ServerFailure"] call BP_fnc_loginError;
		};
	};
	
	//Check Vehicle & Player Out Of Bounds
	if (player call BP_fnc_isOutOfBounds) exitWith
	{
		//Destroy Vehicle
		if (_inVehicle) then { _vehicle setDamage 1; };
		
		//Kill Player
		r_player_blood = 0;
	};
	
	if (!BP_isUndead) then
	{
		//Calculate Hunger
		if !(_inVehicle) then {
			_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5) + (_speed / 2)) * 4;
		} else {
			_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5)) * 4;
		};
		BP_hunger = BP_hunger + ((_hunger / 60) * 2);

		//Calculate Thirst
		_thirst = 27;
		if !(_inVehicle) then { _thirst = ((_speed / 2) + 4) * 5; };
		BP_thirst = BP_thirst + (_thirst / 60);

		//Player is Infected
		if (r_player_infected and !r_player_adrenaline) then
		{
			//Random Chance
			_rnd = ceil (random 8);
			
			//Coughing Sounds
			[player,"cough",_rnd,false,9] call BP_fnc_objSpeak;
			
			//Random Camera Shakes if Infected
			if (_rnd < 3) then { addCamShake [2, 1, 25]; };
			
			//Lower Health as a result of infection
			if (r_player_blood > 2500) then { r_player_blood = r_player_blood - 5; };
		};

		//Pain Shake Effects
		if (r_player_inpain and !r_player_unconscious and !r_player_adrenaline) then {
			addCamShake [2, 1, 25];
		};

		_foodVal = 1 - (BP_hunger / SleepFood);
		_thirstVal = 1 - (BP_thirst / SleepWater);
		
		//Thirst Effects
		if (_thirstVal < 0.3) then {
			_thirstSound = "thirst_0";
			if (_thirstVal < 0.2) then { _thirstSound = "thirst_1"; };
			if (_thirstVal < 0.1) then {
				_thirstSound = "thirst_2";
				cutText ["You are on the verge of dehydration.", "PLAIN DOWN"];
			};
			_rnd = ceil (random 8);
			[player,_thirstSound,_rnd,false,9] call BP_fnc_objSound;
		};

		//Hunger Damage
		if (_foodVal < 0.3) then {
			_foodSound = "hunger_0";
			if (_foodVal < 0.2) then { _foodSound = "hunger_1"; };
			if (_foodVal < 0.1) then {
				_foodSound = "hunger_2";
				cutText ["You are on the verge of starvation.", "PLAIN DOWN"];
			};
			_rnd = ceil (random 8);
			[player,_foodSound,_rnd,false,9] call BP_fnc_objSound;
		};
		
		//Thirst Damage
		if (_thirstVal <= 0) then {
			_newHealth = r_player_blood - 35;
			if (_newHealth < 1) then {
				//Death From Dehydration
				[10] call BP_fnc_death;
			} else {
				r_player_blood = _newHealth;
			};
		};
		
		//Hunger Damage
		if (_foodVal <= 0) then {
			_newHealth = r_player_blood - 35;
			if (_newHealth < 1) then {
				//Death From Starvation
				[9] call BP_fnc_death;
			} else {
				r_player_blood = _newHealth;
			};
		};

		//Save Medical Data - Every 1 Minute
		if ((diag_tickTime - BP_lastSaveMed) > _saveTimeMed) then {
			["playerSpawn2: Medical Sync"] call BP_fnc_debugConsoleFormat;
			player setVariable ["messing",[BP_hunger,BP_thirst]];
			call BP_fnc_medSave;
		};
	
	} else {

		//Disable Chat
//		showChat false;

		//Calculate Hunger
		if !(_inVehicle) then {
			_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5) + (_speed / 2)) * 4;
		} else {
			_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5)) * 4;
		};
		BP_hunger = BP_hunger + ((_hunger / 60) * 2);

		//Calculate Thirst
		_thirst = 27;
		if !(_inVehicle) then { _thirst = ((_speed / 2) + 4) * 5; };
		BP_thirst = BP_thirst + (_thirst / 60);

		//Player is Infected
		if (r_player_infected and !r_player_adrenaline) then
		{
			//Random Chance
			_rnd = ceil (random 8);
			
			//Coughing Sounds
			[player,"cough",_rnd,false,9] call BP_fnc_objSpeak;
			
			//Random Camera Shakes if Infected
			if (_rnd < 3) then { addCamShake [2, 1, 25]; };
			
			//Lower Health as a result of infection
			if (r_player_blood > 2500) then { r_player_blood = r_player_blood - 5; };
		};

		//Pain Shake Effects
		if (r_player_inpain and !r_player_unconscious and !r_player_adrenaline) then {
			addCamShake [2, 1, 25];
		};

		_foodVal = 1 - (BP_hunger / SleepFood);
		_thirstVal = 1 - (BP_thirst / SleepWater);
		
		//Thirst Effects
		if (_thirstVal < 0.3) then {
			_thirstSound = "thirst_0";
			if (_thirstVal < 0.2) then { _thirstSound = "thirst_1"; };
			if (_thirstVal < 0.1) then {
				_thirstSound = "thirst_2";
				cutText ["You are on the verge of dehydration.", "PLAIN DOWN"];
			};
			_rnd = ceil (random 8);
			[player,_thirstSound,_rnd,false,9] call BP_fnc_objSound;
		};

		//Hunger Damage
		if (_foodVal < 0.3) then {
			_foodSound = "hunger_0";
			if (_foodVal < 0.2) then { _foodSound = "hunger_1"; };
			if (_foodVal < 0.1) then {
				_foodSound = "hunger_2";
				cutText ["You are on the verge of starvation.", "PLAIN DOWN"];
			};
			_rnd = ceil (random 8);
			[player,_foodSound,_rnd,false,9] call BP_fnc_objSound;
		};
		
		//Thirst Damage
		if (_thirstVal <= 0) then {
			_newHealth = r_player_blood - 35;
			if (_newHealth < 1) then {
				//Death From Dehydration
				[10] call BP_fnc_death;
			} else {
				r_player_blood = _newHealth;
			};
		};
		
		//Hunger Damage
		if (_foodVal <= 0) then {
			_newHealth = r_player_blood - 35;
			if (_newHealth < 1) then {
				//Death From Starvation
				[9] call BP_fnc_death;
			} else {
				r_player_blood = _newHealth;
			};
		};

		//Save Medical Data - Every 1 Minute
		if ((diag_tickTime - BP_lastSaveMed) > _saveTimeMed) then {
			["playerSpawn2: Medical Sync"] call BP_fnc_debugConsoleFormat;
			player setVariable ["messing",[BP_hunger,BP_thirst]];
			call BP_fnc_medSave;
		};
		
		//Hunger
//		_hunger = player getVariable ["lastFeed",0];
//		if ((diag_tickTime - _hunger) > 240) then
//		{
//			cutText ["You are on the verge of starvation.", "PLAIN DOWN"];
//			if (!BP_isHungryUndead) then { BP_isHungryUndead = true; };
//		};
//		
//		//No Legions
//		_groupID = player getVariable ["group","0"];
//		if (_groupID != "0") then { player setVariable ["group","0",true]; };
		
		//Force Zombie Face
//		if (face player != "BP_Zombie1") then 
//		{ 
//			//player setFace "BP_Zombie1";
//			removeHeadgear player;
//			removeGoggles player;
//			player setIdentity "BP_Zombie1";
//		};
	
		//Heartbeat Sounds
//		_nearestPlayer = objNull;
//		{
//			if (alive _x && {!(_x getVariable ["class",0] == 7)} && {_x != player} && {isPlayer _x}) then
//			{
//				if ((player distance _x) < 250) then
//				{
//					if (isNull _nearestPlayer) exitWith { _nearestPlayer = _x; };
//					if ((player distance _x) < (_nearestPlayer distance player)) exitWith { _nearestPlayer = _x; };
//				};
//			};
//		} count allPlayers;
//
//		if (!isNull _nearestPlayer) then { _nearestPlayer say ["heartbeat_undead",250]; };
	};

	//Exit Thread If Player Is Dead
	if (r_player_dead) exitWith {};
	
	//Thread Delay
	sleep 2;
	
	//VON Check to Ensure Players Don't Speak over VON
	if (VoN_isOn) then {
		if ((VoN_currentTxt == "Alliance") or (VoN_currentTxt == "Outlaw") or (VoN_currentTxt == "Hunter") or (VoN_currentTxt == "Engineer") or (VoN_currentTxt == "Watchers") or (VoN_currentTxt == localize "str_channel_group")) then 
		{
			cutText ["Your faction cannot use faction voice! STOP OR YOU WILL GET KICKED!", "PLAIN DOWN"];
			VoN_Time = VoN_Time + 1;
			if (VoN_Time > 2) then { endMission "END1"; };
		};
	};
	
	//Check Magazines
	call BP_fnc_magazineCheck;
	
	//Check Strongholds
	//call BP_fnc_strongholdCheck;
	
	//Check Faction Specific Clothing
	call BP_fnc_checkFactionClothing;

	//Rating Fix - Commented out replaced with HandleRating Event Handler
	_score = rating player;
	if (_score < 0) then { player addRating (_score * -1); };
	
	//Update Chat - Enable / Disable Based on Stream Friendly UI
//	if (!BP_isUndead) then {
	if (isNull findDisplay 49) then { showChat (!isStreamFriendlyUIEnabled); };
//	};

	//Broken Group System Fixes
	call BP_fnc_groupFix;
	
	//Check If Camera Is Legit
	if (cameraView == "Group") then { cameraOn switchCamera "internal"; };
	
	if ((vehicle player) == player) then
	{
		_uniform = (uniform player);
		if (_uniform in BP_ZombieClothing) then
		{
			//Weapon / Stuck Check
			_currentWep = currentWeapon player;
			if (_currentWep != "") then
			{
				player action ["SwitchWeapon", player, player, 100];
				player switchCamera cameraView;
			};
			
			//Out Of Animation Check
			_normalAnims = ["amovpercmstpsnonwnondnon","amovpercmwlksnonwnondf","amovpsitmstpsnonwnondnon_ground","amovpercmevasnonwnondf"];
			if (animationState player in _normalAnims) then {
				player playMoveNow "AmovPzmbMstpSnonWnonDnon_fast";
			};
		};
	};
	
	//Remove sidechat and global
	{
		_x params [["_chan",-1,[0]], ["_noText","false",[""]], ["_noVoice","false",[""]]];

		_noText = [false,true] select ((["false","true"] find toLower _noText) max 0);
		_noVoice = [false,true] select ((["false","true"] find toLower _noVoice) max 0);

		_chan enableChannel [!_noText, !_noVoice];

	} forEach getArray (missionConfigFile >> "disableChannels");
	
	
	
	//Thirsk Snow
	if (worldName == "thirskw" || {worldName == "namalsk"}) then
	{
		/*
		//Environment Snow Sounds
		_lastSnowSound = player getVariable ["snowTime",0];
		if ((diag_tickTime - _lastSnowSound) > 60) then
		{
			player setVariable ["snowTime",diag_tickTime];
			enableEnvironment false;
			playSound "snowsound";
		};
		*/
		
		//Snow FX
		call
		{
			private ["_snow"];
			_snow = player getVariable ["snow",objNull];
			
			//Create Snow SFX
			if (isNull _snow) then
			{
				_parray = [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 13,1], "",
					"Billboard", 1, 7, [0,0,0], [0,0,0], 1, 0.0000001, 0.000, 1.7,
					[0.07],
					[[1,1,1,1]],
					[0,1], 0.2, 1.2, "", "", player];
				_snow = "#particlesource" createVehicleLocal position player;
				player setVariable ["snow",_snow];
				_snow setParticleParams _parray;
				_snow setParticleRandom [0, [10, 10, 7], [0, 0, 0], 0, 0.01, [0, 0, 0, 0.1], 0, 0];
				_snow setParticleCircle [0.0, [0, 0, 0]];
				_snow setDropInterval 0.001;
			};
			
			//Teleport Snow SFX Near Player
			if ((_snow distance player) > 20) then { _snow setPos position player; };
		};
		
		//Ground Fog FX
		call
		{
			//Static Values
			_obj = player;
			_pos = position (vehicle _obj);
			_d = 15;
			_h = 12;
			_h1 = 8;
			_h2 = 0;
			_density = 5000;
			
			_fog1 = player getVariable ["fog1",objNull];
			_fog2 = player getVariable ["fog2",objNull];
			
			//Fog 1
			if (isNull _fog1) then
			{
				_fog1 = "#particlesource" createVehicleLocal _pos;
				player setVariable ["fog1",_fog1];
				_fog1 setParticleParams [
				["\A3\data_f\ParticleEffects\Universal\Universal.p3d" , 16, 12, 13, 0], "", "Billboard", 1, 10,
				[0, 0, -6], [0, 0, 0], 1, 1.275, 1, 0,
				[7,6], [[1, 1, 1, 0], [1, 1, 1, 0.04], [1, 1, 1, 0]], [1000], 1, 0, "", "", _obj];
				_fog1 setParticleRandom [3, [55, 55, 0.2], [0, 0, -0.1], 2, 0.45, [0, 0, 0, 0.1], 0, 0];
				_fog1 setParticleCircle [0.001, [0, 0, -0.12]];
				_fog1 setDropInterval 0.01;
			};
			
			//Fog 2
			if (isNull _fog2) then
			{
				_fog2 = "#particlesource" createVehicleLocal _pos;
				player setVariable ["fog2",_fog2];
				_fog2 setParticleParams [
				["\A3\data_f\ParticleEffects\Universal\Universal.p3d" , 16, 12, 13, 0], "", "Billboard", 1, 10,
				[0, 0, -6], [0, 0, 0], 1, 1.275, 1, 0,
				[7,6], [[1, 1, 1, 0], [1, 1, 1, 0.04], [1, 1, 1, 0]], [1000], 1, 0, "", "", _obj];
				_fog2 setParticleRandom [3, [55, 55, 0.2], [0, 0, -0.1], 2, 0.45, [0, 0, 0, 0.1], 0, 0];
				_fog2 setParticleCircle [0.001, [0, 0, -0.12]];
				_fog2 setDropInterval 0.01;
			};
			
			//Teleport Fog SFX Near Player
			if ((_fog1 distance player) > 20) then { _fog1 setPos position player; };
			if ((_fog2 distance player) > 20) then { _fog2 setPos position player; };
		};
		
		/*
		//Fog Breath On Players
		{
			_unit = _x;
			_isUndead = (_unit getVariable ["class",0] == 7);
			if (alive _unit and !_isUndead) then
			{
				_lastBreathTime = _unit getVariable ["breathTime",0];
				_rndTime = (random 3);
				if ((diag_tickTime - _lastBreathTime) > _rndTime) then
				{
					_unit setVariable ["breathTime",diag_tickTime];
					if ((_unit distance player) < 500) then
					{
						0 = [_unit] spawn 
						{
							_unit = _this select 0;
							_strength = 0.2;
							_source = "logic" createVehicleLocal (getPos _unit);
							_fog = "#particlesource" createVehicleLocal getPos _source;
							_fog setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 13,0],
							"", 
							"Billboard", 
							0.5, 
							0.5, 
							[0,0,0],
							[0, 0.2, -0.2], 
							1, 1.275,	1, 0.2, 
							[0, 0.2,0], 
							[[1,1,1, _strength], [1,1,1, 0.01], [1,1,1, 0]], 
							[1000], 
							1, 
							0.04, 
							"", 
							"", 
							_source];
							_fog setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
							_fog setDropInterval 0.001;

							_source attachTo [_unit,[0,0.15,0], "neck"]; // Position of player mouth

							sleep 0.5; // Time of the mist
							deleteVehicle _source;
							deleteVehicle _fog;
						};
					};
				};
			};
		} count allPlayers;
		*/
	};
	
	r_player_dead
};
