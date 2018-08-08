/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/


#define DIK_ESCAPE          0x01
#define DIK_SPACE			   0x39
#define DIK_W               0x11
#define DIK_S               0x1F
#define DIK_A               0x1E
#define DIK_D               0x20

private ["_dikCode", "_handled"];
_dikCode = 	_this select 1;
_handled = false;

_inVehicle = ((vehicle player) != player);
_isHostage = player getVariable ["med_hostage", false];
_isWater = (surfaceIsWater (getPosATL player));

//Haven - Television Camera
_television = player getVariable ["television",objNull];
if (!isNull _television) then
{
	_cam = _television getVariable ["camera",objNull];
	_actualDir = _television getVariable ["cameraDir",0];
	_modHeight = _television getVariable ["cameraHMod",0];
	_modDir = _television getVariable ["cameraDirMod",0];

	if (_dikCode == DIK_ESCAPE) exitWith
	{
		_cam cameraEffect ["terminate","back"];
		_renderTarget = player getVariable "cameraRT";
		_camID = _television getVariable ["cameraID",0];
		player setVariable ["television",objNull];
		[nil,nil,nil,[_television,_camID]] spawn BP_fnc_teleCam;
		_handled = true;
	};

	if (_dikCode == DIK_W) then
	{
		_modHeight = _modHeight + 0.8;
		if (_modHeight > 30) then { _modHeight = 30; };
		_television setVariable ["cameraHMod",_modHeight];
		_handled = true;
	};
	
	if (_dikCode == DIK_S) then
	{
		_modHeight = _modHeight - 0.8;
		if (_modHeight < -30) then { _modHeight = -30; };
		_television setVariable ["cameraHMod",_modHeight];
		_handled = true;
	};

	if (_dikCode == DIK_A) then
	{
		_modDir = _modDir - 0.8;
		if (_modDir < -45) then { _modDir = -45; };
		_television setVariable ["cameraDirMod",_modDir];
		_handled = true;
	};
	
	if (_dikCode == DIK_D) then
	{
		_modDir = _modDir + 0.8;
		if (_modDir > 45) then { _modDir = 45; };
		_television setVariable ["cameraDirMod",_modDir];
		_handled = true;
	};

	_cam setDir (_actualDir + _modDir);
	[_cam,_modHeight,0] call bis_fnc_setpitchbank;
};

//Hide Commanding Menu
if (commandingMenu != "") then {showCommandingMenu ""};

//Disable F1-F10 Exploits
if ((_dikCode > 58) and (_dikCode < 69)) then {_handled = true};

//Disable Key and Menu Exploits
if (_dikCode in actionKeys "TacticalView") then {_handled = true};
if (_dikCode in actionKeys "ForceCommandingMode") then {_handled = true};
if (_dikCode in actionKeys "TimeInc") then {_handled = true};
if (_dikCode in actionKeys "TimeDec") then {_handled = true};
if (_dikCode in actionKeys "Cheat1") then {_handled = true};
if (_dikCode in actionKeys "Cheat2") then {_handled = true};
if (_dikCode in actionKeys "LiteUnitInfoToggle") then {_handled = true};
if (_dikCode in actionKeys "Help") then {_handled = true};
if (_dikCode in actionKeys "Diary") then {_handled = true};
if (_dikCode in actionKeys "DSInterface") then {_handled = true};
if (_dikCode in actionKeys "PushToTalkAll") then {_handled = true};
if (_dikCode in actionKeys "PushToTalkCommand") then {_handled = true};
if (_dikCode in actionKeys "PushToTalkSide") then {_handled = true};
if (_dikCode in actionKeys "RevealTarget") then {_handled = true};
if (_dikCode in actionKeys "Tank") then {_handled = true};
//if (_dikCode in actionKeys "lockTarget") then {_handled = true};
//if (_dikCode in actionKeys "TeamSwitch") then {_handled = true};
//if (_dikCode in actionKeys "TeamSwitchPrev") then {_handled = true};
//if (_dikCode in actionKeys "TeamSwitchNext") then {_handled = true};
//if (_dikCode in actionKeys "LockTarget") then {_handled = true};
//if (_dikCode in actionKeys "RevealTarget") then {_handled = true};
//if (_dikCode in actionKeys "lockTargetToggle") then {_handled = true};
//if (_dikCode in actionKeys "revealTarget") then {_handled = true};
//if (_dikCode in actionKeys "lockTargets") then {_handled = true};
//if (_dikCode in actionKeys "lockEmptyTargets") then {_handled = true};
//if (_dikCode in actionKeys "vehLockTargets") then {_handled = true};
//if (_dikCode in actionKeys "vehLockEmptyTargets") then {_handled = true};

if (_dikCode in actionKeys "networkStats") then { if (r_player_unconscious) then { _handled = true; }; };
if (_dikCode in actionKeys "networkPlayers") then { if (r_player_unconscious) then { _handled = true; }; };
if (_dikCode in actionKeys "SwitchGunnerWeapon") then { if (r_player_unconscious) then { _handled = true; }; };
if (_dikCode in actionKeys "IngamePause") then { if (r_player_unconscious) then { _handled = true; }; };

//PushToTalk
//PushToTalkDirect
//PushToTalkGroup
//PushToTalkVehicle

_object = player getVariable ["constructionObject", objNull];
if (!isNull _object and _dikCode == 16) then {
	_dir = getDir _object - 3;
	_object setDir (_dir - getDir player);
	_handled = true;
};
if (!isNull _object and _dikCode == 18) then {
	_dir = getDir _object + 3;
	_object setDir (_dir - getDir player);
	_handled = true;
};

// Fast Weapon Switching Keys
_stance = stance player;
_isSwitch = if (_stance == "STAND" or {_stance == "CROUCH"} or {_stance == "PRONE"}) then {true} else {false};
	
_currentWeapon = currentWeapon player;
_rifle = primaryWeapon player;
_handgun = handgunWeapon player;
_launcher = secondaryWeapon player;

// 1 - Primary
if (_dikCode == 2) then {
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		if (r_doLoop) exitWith {};
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		if ((vehicle player) == player) then 
		{
			if (!r_player_unconscious and !_isHostage) then 
			{
				player selectWeapon _rifle;
			};
		};
	};
	_handled = true;
};

// 2 - Handgun
if (_dikCode == 3) then {
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		if (r_doLoop) exitWith {};
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		if ((vehicle player) == player) then 
		{
			if (!r_player_unconscious and !_isHostage) then 
			{
				player selectWeapon _handgun;
			};
		};
	};
	_handled = true;
};

// 3 - Launcher
if (_dikCode == 4) then 
{
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		if (r_doLoop) exitWith {};
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		if ((vehicle player) == player) then 
		{
			if (!r_player_unconscious and !_isHostage) then 
			{
				player selectWeapon _launcher;
			};
		};
	};
	_handled = true;
};

// 4 - Binoculars
if (_dikCode == 5) then 
{
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		if (r_doLoop) exitWith {};
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		if ((vehicle player) == player) then {
			if (!r_player_unconscious and !_isHostage) then {
				_hasRange = ("Rangefinder" in weapons player);
				_hasBino = ("Binocular" in weapons player);
				
				if (_currentWeapon == "Rangefinder") exitWith {};
				if (_currentWeapon == "Binocular") exitWith {};
				
				if (_hasRange) then {
					player selectWeapon "Rangefinder";
				} else {
					player selectWeapon "Binocular";
				};
			};
		};
	};
	_handled = true;
};

// 5 - No Weapon
if (_dikCode == 6) then {
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		if (r_doLoop) exitWith {};
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		if ((vehicle player) == player) then 
		{
			if (!r_player_unconscious and !_isHostage) then 
			{
				if ((vehicle player) == player) then {
					player action ["SwitchWeapon", player, player, 100];
					player switchcamera cameraView;
				};
			};
		};
	};
	_handled = true;
};

// 6 - Particle Effect to Check Wind
if (_dikCode == 7) then {
	if (time - BP_lastCheckBit > 1) then
	{
		if (BP_isUndead) exitWith {};
		BP_lastCheckBit = time;
		[] spawn BP_fnc_windCheck;
	};
	_handled = true;
};

// Movement Keys
if (_dikCode in actionKeys "TurnLeft") then { 
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "TurnRight") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "MoveForward") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "MoveBack") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "MoveUp") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "MoveDown") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "Fire") then {
	r_interrupt = true;
	r_action_rest = false;
	
	if (r_player_unconscious and !_isHostage) exitWith { _handled = true; };
	
	//Car Horn Aggro Zombies
	//if (currentWeapon player in BP_VehicleHorns) then {
	//	[player,200,false,(getPosATL player)] spawn BP_fnc_zombieAlert;
	//};
};

//if (_dikCode == DIK_SPACE) then
//{
//	if (BP_isUndead && {alive player}) then
//	{
//		_lastAttack = player getVariable ["lastZedAttack",0];
//		_attackTime = 2.5;
//		_factionLevel = player call BP_fnc_getFactionLevel;
//		if (_factionLevel == 2) then { _attackTime = 2; };
//		if (_factionLevel == 3) then { _attackTIme = 1.2; };
//		if (diag_tickTime - _lastAttack > 1.8) then {
//			player setVariable ["lastZedAttack",diag_tickTime];
//			[player,"",nil,nil,"zombie","",objNull] call BP_fnc_fired;
//		};
//		_handled = true;
//	};
//};

if (_dikCode in actionKeys "reloadMagazine") then {
	r_interrupt = true;
	r_action_rest = false;
	
	if (BP_isUndead) then
	{
		//Sound FX
		[player,"spotted",0,false] call BP_fnc_objSpeak;
		
		//Handle Perk
		_lastHordeTime = player getVariable ["lastHorde",0];
		if ((diag_tickTime - _lastHordeTime) > 60) then
		{
			player setVariable ["lastHorde",diag_tickTime];
			//Horde Perk Distance
			_factionLevel = player call BP_fnc_getFactionLevel;
			_distance = 50;
			if (_factionLevel == 2) then { _distance = 100; };
			if (_factionlevel == 3) then { _distance = 250; };
			[player,_distance,false,(getPosATL player)] spawn BP_fnc_zombieAlert;
			cutText ["Zombie Horde Perk Activated","PLAIN DOWN"];
		} else {
			cutText ["Zombie Horde Perk on Cooldown.","PLAIN DOWN"];
		};
		
		_handled = true;
	};
	
	if (r_player_unconscious and !_isHostage) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "switchWeapon") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious and !_isHostage) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "nextWeapon") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious and !_isHostage) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "prevWeapon") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious and !_isHostage) then {
		_handled = true;
	};
};

if (_dikCode in actionKeys "Throw") then {
	r_interrupt = true;
	r_action_rest = false;
	if (r_player_unconscious and !_isHostage) exitWith { _handled = true; };
};

if ((_dikCode in actionKeys "PushToTalk") or (_dikCode in actionKeys "VoiceOverNet")) then 
{
	//Zombies can hear you
	if ((time - BP_lastCheckBit > 10)) then {
		BP_lastCheckBit = time;
		[player,50,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
	};
	
	//Disable VON on global channels
	if (VoN_isOn) then {
		if ((VoN_currentTxt == "Ranger") or (VoN_currentTxt == "Nomad") or (VoN_currentTxt == "Outlaw") or (VoN_currentTxt == localize "str_channel_group")) then {
			_handled = true;
		};
	};
};

if (_dikCode in actionKeys "PushToTalkDirect") then {
	//Zombies can hear you
	if (time - BP_lastCheckBit > 10) then {
		BP_lastCheckBit = time;
		[player,50,false,(getPosATL player)] spawn BP_fnc_zombieAlert;
	};
};

if (_dikCode in actionKeys "PushToTalkGroup") then { _handled = true; };
if (_dikCode in actionKeys "PushToTalkVehicle") then {};
if (_dikCode in actionKeys "Chat") then {};

//if ((_dikCode in actionKeys "Inventory") or (_dikCode in actionKeys "Gear")) then {
//	private ["_primary","_handgun","_current"];
//	disableSerialization;
//	if (!isNull (findDisplay 602)) exitWith {};
//	//Can't Open Inventory When Unconcious
//	if (r_player_unconscious) then {
//		_handled = true;
//	} else {
//		//Nearby Player Check
//		_nearbyPlayer = ({isPlayer _x and alive _x} count (player nearEntities ["AllVehicles", 5]) > 1);
//		if (_nearbyPlayer) then {
//			//closeDialog 602;
//			_handled = true;
//			cutText ["You cannot open your inventory while near a player.","PLAIN DOWN"];
//		};
//	};
//};

if (_dikCode in actionKeys "SitDown") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;

		if ((vehicle player) == player) then {
			if (!r_player_unconscious and !_isHostage and !_isWater) then {	
				r_action_restTime = 0;
				r_action_rest = true;
			};
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User1") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		if ((vehicle player) == player) then 
		{
			if (!r_player_unconscious and !_isHostage and !_isWater) then 
			{
				[] spawn
				{
					r_action_restTime = 0;
					r_action_rest = true;
					
					player action ["SwitchWeapon", player, player, 100];
					player switchcamera cameraView;
					sleep 1;
					
					_primary = primaryWeapon player;
					_handgun = handgunWeapon player;
					_current = currentWeapon player;

					if (_current == "") then {
						player playMoveNow "AmovPercMstpSnonWnonDnon_AmovPsitMstpSnonWnonDnon_ground";
					} else {
						if (_primary == _current) then {
							player playMoveNow "AmovPsitMstpSlowWrflDnon_Smoking";
						} else {
							if (_handgun == _current) then {
								player playMoveNow "AmovPercMstpSnonWpstDnon_AmovPsitMstpSnonWpstDnon_ground";
							};
						};
					};
				};
			};
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User2") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		private ["_onLadder","_canDo","_max_height","_height","_vel","_dir","_speed"];
		r_interrupt = true;
		r_action_rest = false;
		_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
		_canDo = (!r_action_refuel and !r_action_gut and !r_action_siphon and !r_action_repair and !r_player_unconscious and !_isHostage and !_onLadder);

		if (player == (vehicle player) && {isTouchingGround player} && {stance player != "PRONE"} && {_canDo} && {!_onLadder}) then {
			_max_height = 4.3;
			//_height = 6-((load player)*10);
			_height = 4.0;
			_vel = velocity player;
			_dir = direction player;
			_speed = 0.4;
			If (_height > _max_height) then {_height = _max_height};// MAXIMUM HEIGHT OF JUMP 
			player setVelocity [(_vel select 0)+(sin _dir*_speed),(_vel select 1)+(cos _dir*_speed),(_vel select 2)+_height];
			player playActionNow "BP_Jump";
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User3") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		if (!r_player_unconscious) then {
			[] spawn BP_fnc_groupDel;
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User4") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		if (!r_player_unconscious and !_isHostage) then {
			_foodClass = "";
			{
				if (_x in magazines player) exitWith { _foodClass = _x; };
			} count AllFood;
			if (_foodClass == "") exitWith {
				cutText ["You don't have any food.", "PLAIN DOWN"];
				_handled = true;
			};
			[_foodClass] spawn BP_fnc_eat;
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User5") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		if (!r_player_unconscious and !_isHostage) then {
			_drinkClass = "";
			{
				if (_x in magazines player) exitWith { _drinkClass = _x; };
			} count AllDrinks;
			if (_drinkClass == "") exitWith {
				cutText ["You don't have any drinks.", "PLAIN DOWN"];
				_handled = true;
			};
			[_drinkClass] spawn BP_fnc_drink;
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User6") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		if (!r_player_unconscious and !_isHostage) then {
			if ("ItemBandage" in magazines player) then {
				["ItemBandage"] spawn BP_fnc_useMeds;
			} else {
				cutText ["You don't have any bandages.", "PLAIN DOWN"];
			};
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "User7") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;

		cutText ["You have been removed from all chat channels.", "PLAIN DOWN"];
	};
	_handled = true;
};

/*
if (_dikCode in actionKeys "User8") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		r_interrupt = true;

		_object = objNull;
		//Dead Bodies
		if (isNull _object) then { _object = nearestObject [player, "BP_DeadBody"]; };
		
		//Weaponholders - Ground
		if (isNull _object) then { _object = nearestObject [player, "GroundWeaponHolder"]; };
		
		//Weaponholders - Simulated
		if (isNull _object) then { _object = nearestObject [player, "WeaponHolderSimulated"]; };
		
		//Storage / Save Objects
		if (isNull _object) then { _object = nearestObject [player, "BP_SaveObject"]; };
		
		//Loot Box
		if (isNull _object) then { _object = nearestObject [player, "BP_LootBox"]; };
		
		//Open Inventory
		if (!isNull _object) then {
			if ((player distance _object) < 4) then {
				_openInventory = [player,_object] call BP_fnc_onInventoryOpened;
				if (!_openInventory) then { player action ["Gear", _object]; };
			};
		};
	};
	_handled = true;
};
*/

if (_dikCode in actionKeys "User9") then 
{
	if (BP_isUndead) exitWith {};
	
	if (_isHostage) exitWith {};
	
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;
		r_interrupt = true;
		r_action_rest = false;
		
		if (surfaceIsWater (getPosATL player)) exitWith {};

		if (!BP_AutoRun && {!r_fracture_legs} && {!(r_hit_legs > 0)}) then 
		{
			BP_AutoRun = true;
			
			if (!isNull BP_AutoRunThread) then
			{
				terminate BP_AutoRunThread;
				BP_AutoRunThread = scriptNull;
			};
			
			BP_AutoRunThread = [] spawn 
			{
				sleep 0.05;
				r_interrupt = false;
	
				waitUntil
				{
					//No Resting While Autorunning
					if (r_action_rest) then { r_action_rest = false; };
					
					//No Autorun While Hostage
					if (player getVariable ["med_hostage",false]) exitWith {true};
					
					//Don't Autorun While TranQ
					if (r_player_unconscious) exitWith {true};
					
					//Autorun speed depends on terrain gradient
					_gradient = player call BP_fnc_getTerrainGradient;
					if (_gradient <= 15 && _gradient >= -15) then {
						player playActionNow "FastF";
					} else {
						if (_gradient >= 30 || _gradient <= -30) then {
							player playActionNow "WalkF";
						} else {
							player playActionNow "SlowF";
						};
					};

					//Delay
					sleep 0.01;
				
					//Condition Checks
					(r_interrupt || {!BP_AutoRun} || {!alive player} || {r_fracture_legs} || {r_hit_legs > 0} || {surfaceIsWater (getPosATL player)});
				};
				
				
				BP_AutoRun = false;
			};
			[BP_AutoRunThread] call BP_fnc_addThreadHandle;
		};
	};
	_handled = true;
};

//if (_dikCode in actionKeys "User10") then 
//{
//	if (BP_isUndead) exitWith {};
//	if (time - BP_lastCheckBit > 5) then
//	{
//		BP_lastCheckBit = time;
//		r_interrupt = true;
//		r_action_rest = false;
//		
//		if (surfaceIsWater (getPosATL player)) exitWith {};
//
//		//Make Sure Player Is In a Vehicle
//		if ((vehicle player) == player) then
//		{
//			//Make Player Unequip Weapon
//			player action ["SwitchWeapon", player, player, 100];
//			player switchCamera cameraView;
//			
//			//Turn Into Zombie Remote Server Event
//			["medZombie",(netID player),(netID player)] remoteExecCall ["BPServer_fnc_medicalUpdate",2];
//		};
//	};
//	_handled = true;
//};

if (_dikCode in actionKeys "User11") then
{
	if (soundVolume != 1) then {
		1 fadeSound 1;
	} else {
		1 fadeSound 0.2;
	};
	_handled = true;
};

if (_dikCode in actionKeys "User12") then {
	call BP_fnc_loadFactionStatsDiary;
	_handled = true;
};

if (_dikCode in actionKeys "User19") then {
	if (time - BP_lastCheckBit > 1) then
	{
		BP_lastCheckBit = time;

		if (BP_ZombieSounds) then {
			BP_ZombieSounds = false;
			cutText ["Zombie Sounds Disabled.", "PLAIN DOWN"];
		} else {
			cutText ["Zombie Sounds Enabled.", "PLAIN DOWN"];
		};
	};
	_handled = true;
};

if (_dikCode in actionKeys "Gear" || {_dikCode in actionKeys "Inventory"}) then 
{ 
	//Unconscious Players Can't Open Inventory
	if (r_player_unconscious) then  {
		_handled = true;
	} else {
		_handled = false;
	};
};

_handled