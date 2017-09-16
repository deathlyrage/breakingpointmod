/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_id","_array","_vehicle","_part","_hitpoint","_type","_hasToolbox","_section","_nameType","_namePart","_damage","_selection","_dis","_sfx","_hitpoints","_allFixed"];

if (r_action_refuel or r_action_siphon or r_action_repair) exitWith {
	cutText ["An action is already in progress.", "PLAIN DOWN"];
};

r_action = true;
r_action_repair = true;

_id = _this select 2;
_array = _this select 3;

_array params ["_vehicle","_part","_hitpoint"];

_type = typeOf _vehicle;
_isWater = (surfaceIsWater (position player)) or BP_isSwimming;

{BP_myCursorTarget removeAction _x} count s_player_repairActions;
s_player_repairActions = [];
{BP_myCursorTarget removeAction _x} count s_player_removeActions;
s_player_removeActions = [];
BP_myCursorTarget = objNull;

//Exit If Invalid Vehicle
if (isNull _vehicle) exitWith {};

//Exit If Player Inside Vehicle
if (vehicle player == _vehicle) exitWith {
	cutText ["You can't repair vehicle while inside it.", "PLAIN DOWN"];
	call BP_fnc_medicalRemoveMedicActions;
	r_action = false;
	r_action_repair = false;
};

//Exit If Player Doesn't Have a Toolbox
_hasToolbox = "ItemToolbox" in assignedItems player;
if (!_hasToolbox) exitWith {
	cutText ["You need a toolbox to repair this vehicle.", "PLAIN DOWN"];
	call BP_fnc_medicalRemoveMedicActions;
	r_action = false;
	r_action_repair = false;
};

//moving this here because we need to know which part needed if we don't have it
_nameType = 		getText(configFile >> "cfgVehicles" >> _type >> "displayName");
_namePart = 		getText(configFile >> "cfgMagazines" >> _part >> "displayName");

//Exit If Player Doesn't Have Part
_section = _part in magazines player;
if (!_section) exitWith {
	cutText [format["You need a %1 to repair this vehicle.",_namePart], "PLAIN DOWN"];
	call BP_fnc_medicalRemoveMedicActions;
	r_action = false;
	r_action_repair = false;
};

//Enable Simulation If Disabled
if (!simulationEnabled _vehicle) then {
	[(netID _vehicle),true] remoteExecCall ["BPServer_fnc_simulationToggle",2];
};

//Wait for simulation to be enabled
waitUntil {simulationEnabled _vehicle};

_damage = _vehicle getHitPointDamage _hitpoint;
_vehicle removeAction _id;

//don't waste loot on undamaged parts
if (_damage > 0) then 
{
	_selection = getText (configFile >> "CfgVehicles" >> _type >> "HitPoints" >> _hitpoint >> "name");
	
	//Zombie SFX and Sound
	[player,"repair",0,false,20] call BP_fnc_objSpeak;  
	[player,20,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
		
		
	//Animation Handles
	_finished = false;
	if (!_isWater) then {
		_finished = call BP_fnc_medicAnim;
	} else {
		_finished = true;
	};
	
	if (_finished) then 
	{
		[(netID player),(netID _vehicle),_hitpoint,_part] remoteExec ["BP_fnc_vehicleRepair",2];
		
		//Success!
		cutText [format["You have successfully attached the %1 on the %2.",_namePart,_nameType], "PLAIN DOWN"];
	};
};

call BP_fnc_medicalRemoveMedicActions;
r_action = false;
r_action_repair = false;