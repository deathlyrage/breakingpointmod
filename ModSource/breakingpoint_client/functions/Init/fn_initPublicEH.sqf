/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Client only
if (isDedicated) exitWith {};
if (isServer) exitWith {};
if (!hasInterface) exitWith {};

"BP_MedicalEvent"		addPublicVariableEventHandler {(_this select 1) call BP_fnc_medicalEvent};
"BP_DamageEvent"		addPublicVariableEventHandler {(_this select 1) call BP_fnc_damageEvent};
"BP_Anim"			addPublicVariableEventHandler {(_this select 1) call BP_fnc_switchMove};
"BP_Hit" 			addPublicVariableEventHandler {(_this select 1) call BP_fnc_damageHandler};
"BP_HitV" 			addPublicVariableEventHandler {(_this select 1) call BP_fnc_damageHandlerVehicle};
"BP_GameError" 		addPublicVariableEventHandler {(_this select 1) call BP_fnc_gameError};
//"BP_AddPoints" 		addPublicVariableEventHandler {(_this select 1) call BP_fnc_onFactionPoints};
"BP_WeaponSwitch" 	addPublicVariableEventHandler {(_this select 1) call BP_fnc_wpnSwitch_netSwitch};
"BP_CustomChat" 		addPublicVariableEventHandler {(_this select 1) call BP_fnc_customChat};
"BP_EventKill" 		addPublicVariableEventHandler {(_this select 1) call BP_fnc_localEventKill};

"BP_Traps"			addPublicVariableEventHandler {(_this select 1) call BP_fnc_trapUpdate};

"BP_BuildingLocks"	addPublicVariableEventHandler 
{
	(_this select 1) call BP_fnc_buildingUpdate;
	if (!isNull _player) then
	{
		if (alive _player) then {
			_nearbyObjects = nearestObjects [player, ["AllVehicles","GroundWeaponHolder","WeaponHolderSimulated","BP_Object","BP_LootBox"], 50]; 
			{ player reveal _x; } count _nearbyObjects;
		};
	};
};

"BP_PublishResult" addPublicVariableEventHandler
{
	(_this select 1) params ["_success","_blueprint"];
	
	_classname = getText (configFile >> "CfgMagazines" >> _blueprint >> "Construction" >> "Object");
	_objectName = getText (ConfigFile >> "CfgVehicles" >> _classname >> "displayName");

	if (_success) then {
		cutText [format ["You have successfully created a %1.",_objectName], "PLAIN DOWN"];
	} else {
		cutText [format ["Server Rejected Creation Of %1. You may reached the limit of this type of object on this server.",_objectName], "PLAIN DOWN"];
	};
};

//BP_SetLocalVar = [object,[["var",value],["var",value]]];
"BP_SetLocalVar" addPublicVariableEventHandler {
	_data = (_this select 1);
	_object = (_data select 0);
	_dataList = (_data select 1);
	_dataCount = (count _dataList);
	if (_dataCount < 1) exitWith { ["BP_SetLocalVar: Received Invalid Variable List Count.~1001",_object,_var,_val] call BP_fnc_DebugConsoleFormat; };
	if (_dataCount > 5) exitWith { ["BP_SetLocalVar: Received More Then Allowed Variable Count Limit.~1001",_object,_var,_val] call BP_fnc_DebugConsoleFormat; };
	//if (!(local _object)) exitWith { ["BP_SetLocalVar: Blocked RemEx for Object %1 variable %2 at value of %3.~1001",_object,_var,_val] call BP_fnc_DebugConsoleFormat; };
	{
		_x params ["_var","_val"];
		_object setVariable [_var,_val];
		["setLocalVar: Object: %1 | Var: %2 | Value: %3",_object,_var,_val] call BP_fnc_debugConsoleFormat;
	} count _dataList;
};

/*
"BP_BroSystemMatched" addPublicVariableEventHandler 
{
	(_this select 1) params ["_bro1","_bro2"];
	cutText [format["Buddy System: %1 has been matched with %2.",(name _bro1),(name _bro2)], "PLAIN DOWN"];
};
*/

"BP_GroupInvite" addPublicVariableEventHandler 
{
	(_this select 1) spawn 
	{
		_p1 = objectFromNetID (_this select 0);
		_newGroupUID = (_this select 1);
		_oldGroupUID = player getVariable ["group","0"];
		
		["groupInvite: %1 %2 %3",_p1,_newGroupUID,_oldGroupUID] call BP_fnc_debugConsoleFormat;

		BP_GroupSystem = false;

		if (!isStreamFriendlyUIEnabled) then {
			cutText [format ["%1 has invited you to join a group.",(name _p1)], "PLAIN DOWN"];
		} else {
			cutText ["A player has invited you to join a group.", "PLAIN DOWN"];
		};

		//Create Dialog
		createDialog "RscDisplayGroupInvite";
		
		//Reset Interrupt Flag
		r_interrupt = false;
		
		//Handle Wait For Dialog Result
		while {dialog} do
		{
			if (r_interrupt) exitWith { closeDialog 0; };
		};

		if (!BP_GroupSystem) exitWith {};
		
		player setVariable ["group",_newGroupUID,true];
		
		//Update Group Members
		BP_Group = call BP_fnc_groupGetMembers;

		cutText [format["Successfully Joined Group ID: %1",_newGroupUID], "PLAIN DOWN"];
	};
};

"BP_PlayerGive" addPublicVariableEventHandler 
{
	private ["_classname","_config","_text","_sfx","_sfxdis","_zombieMeat"];
	(_this select 1) params ["_classname"];

	// Drink
	if (_classname in AllDrinks) exitWith 
	{
		_config = configFile >> "CfgMagazines" >> _classname;
		_text = getText (_config >> "displayName");
		_sfx =  getText (_config >> "sfx");
		_sfxdis = getNumber (_config >> "sfxdis");
		[player,_sfx,0,false,_sfxdis] call BP_fnc_objSpeak;
		BP_thirst = 0;
		player setVariable ["messing",[BP_hunger,BP_thirst]];
		cutText [format["A player has given you %1.",_text], "PLAIN DOWN"];
	};
	
	// Food
	if (_classname in AllFood) exitWith 
	{
		_rawfood = _classname in meatraw;
		_zombieMeat = _classname in meatzombie;
		_cookedfood = _classname in meatcooked;
		_hasoutput = _classname in food_with_output;
		_config =   configFile >> "CfgMagazines" >> _classname;
		_text =     getText (_config >> "displayName");
		_regen =    getNumber (_config >> "bloodRegen");
		if (_zombieMeat and (random 15 < 5)) then {
			r_player_infected = true;
		} else {
			if (_rawfood and (random 15 < 1)) then {
				r_player_infected = true;
			};
		};
		r_player_blood = r_player_blood + _regen;
		if (r_player_blood > r_player_bloodTotal) then {
			r_player_blood = r_player_bloodTotal;
		};
		BP_hunger = 0;
		player setVariable ["messing",[BP_hunger,BP_thirst]];
		[player,"eat",0,false,6] call BP_fnc_objSpeak;
		cutText [format["A player has given you %1.",_text], "PLAIN DOWN"];
	};
};

"BP_HostageGive" addPublicVariableEventHandler {
	private ["_classname","_config","_text","_sfx","_sfxdis","_zombieMeat"];
	_classname = (_this select 1);

	// Drink
	if (_classname in AllDrinks) exitWith {
		_config = configFile >> "CfgMagazines" >> _classname;
		_text = getText (_config >> "displayName");
		_sfx =  getText (_config >> "sfx");
		_sfxdis = getNumber (_config >> "sfxdis");
		[player,_sfx,0,false,_sfxdis] call BP_fnc_objSpeak;
		BP_thirst = 0;
		player setVariable ["messing",[BP_hunger,BP_thirst]];
		cutText [format["A player has given you %1.",_text], "PLAIN DOWN"];
	};
	
	// Food
	if (_classname in AllFood) exitWith {
		_rawfood = _classname in meatraw;
		_zombieMeat = _classname in meatzombie;
		_cookedfood = _classname in meatcooked;
		_hasoutput = _classname in food_with_output;
		_config =   configFile >> "CfgMagazines" >> _classname;
		_text =     getText (_config >> "displayName");
		_regen =    getNumber (_config >> "bloodRegen");
		if ( _zombieMeat and (random 15 < 5)) then {
			r_player_infected = true;
		} else {
			if ( _rawfood and (random 15 < 1)) then {
				r_player_infected = true;
			};
		};
		r_player_blood = r_player_blood + _regen;
		if (r_player_blood > r_player_bloodTotal) then {
			r_player_blood = r_player_bloodTotal;
		};
		BP_hunger = 0;
		player setVariable ["messing",[BP_hunger,BP_thirst]];
		[player,"eat",0,false,6] call BP_fnc_objSpeak;
		cutText [format["A player has given you %1.",_text], "PLAIN DOWN"];
	};
};

"BP_HostageAdd" addPublicVariableEventHandler 
{
	(_this select 1) params ["_playerNetID","_hostageNetID"];

	_player = objectFromNetID _playerNetID;
	_hostage = objectFromNetID _hostageNetID;
	
	if (isNull _player) exitWith {};
	if (isNull _hostage) exitWith {};
	
	_handle = [_player,_hostage] spawn 
	{
		params ["_player","_hostage"];
		
		//Hostage Message
		cutText ["A player has taken you hostage.", "PLAIN DOWN"];
		
		//Activate Hostage Thread...
		uiNamespace setVariable ["BP_LastHostageTime",diag_tickTime];
		while {player getVariable "med_hostage"} do {
			player playMove "AmovPercMstpSnonWnonDnon_Ease";
			waitUntil {animationState player != "AmovPercMstpSnonWnonDnon_Ease" || !(player getVariable "med_hostage")};
			if (!alive player) then { player setVariable ["med_hostage",false,true]; };
		};
		if (alive player) then {
			cutText ["You have been released from being a hostage.","PLAIN DOWN"];
			//player switchMove "";
			uiNamespace setVariable ["BP_LastHostageTime",0];
			player playActionNow "stop";
		};
	};
	[_handle] call BP_fnc_addThreadHandle;
};
