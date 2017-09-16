/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_vehicle","_part","_hitpoint","_type","_selection","_array"];

if (r_action_refuel or r_action_siphon or r_action_repair) exitWith {
	cutText ["An action is already in progress.", "PLAIN DOWN"];
	["refuel: An action is already in progress.#1000"] call BP_fnc_debugConsoleFormat;
};

r_action = true;
r_action_repair = true;

_id = _this select 2;

(_this select 3) params ["_vehicle","_part","_hitpoint"];

_type = typeOf _vehicle;

if (vehicle player == _vehicle) exitWith { cutText ["You can't remove parts from a vehicle while inside it.", "PLAIN DOWN"]; };

_pos = getPosATL player;

_hasToolbox = 	"ItemToolbox" in assignedItems player;

_nameType = 		getText(configFile >> "cfgVehicles" >> _type >> "displayName");
_namePart = 		getText(configFile >> "cfgMagazines" >> _part >> "displayName");

if (_hasToolbox) then {
    if (getDammage _vehicle < 2) then {
		_damage = _vehicle getHitPointDamage _hitpoint;
        if ( _damage <= 0 ) then 
		{
			{BP_myCursorTarget removeAction _x} count s_player_repairActions;
			s_player_repairActions = [];
			{BP_myCursorTarget removeAction _x} count s_player_removeActions;
			s_player_removeActions = [];
			BP_myCursorTarget = objNull;

            _selection = getText (configFile >> "cfgVehicles" >> _type >> "HitPoints" >> _hitpoint >> "name");
            if( _hitpoint == "HitEngine" or _hitpoint == "HitFuel" ) then {
                _damage = 0.89;
            } else {
                _damage = 1;
            };
			
			//Enable Simulation If Disabled
			if (!simulationEnabled _vehicle) then {
				[(netID _vehicle),true] remoteExecCall ["BPServer_fnc_simulationToggle",2];
			};

			//Wait for simulation to be enabled
			waitUntil {simulationEnabled _vehicle};
			
			//Zombie Sound and SFX
            [player,"repair",0,false] call BP_fnc_objSpeak;
            [player,10,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
			
			_finished = call BP_fnc_medicAnim;
			if (_finished) then {
				[_vehicle,_hitpoint,_damage,_pos,_part] remoteExec ["BP_fnc_vehicleRemove",2];
				cutText [format["You have successfully taken %1 from the %2",_namePart,_nameType], "PLAIN DOWN"];
			};
        } else {
            cutText [format["Cannot remove %1 from %2, the part has been damaged.",_namePart,_nameType], "PLAIN DOWN"];
        };
    } else {
		{BP_myCursorTarget removeAction _x} count s_player_repairActions;
		s_player_repairActions = [];
		{BP_myCursorTarget removeAction _x} count s_player_removeActions;
		s_player_removeActions = [];
        BP_myCursorTarget = objNull;
    };
};

if( BP_myCursorTarget != objNull ) then {
	{BP_myCursorTarget removeAction _x} count s_player_repairActions;
	s_player_repairActions = [];
	{BP_myCursorTarget removeAction _x} count s_player_removeActions;
	s_player_removeActions = [];
    BP_myCursorTarget = objNull;
};

call BP_fnc_medicalRemoveMedicActions;
r_action = false;
r_action_repair = false;