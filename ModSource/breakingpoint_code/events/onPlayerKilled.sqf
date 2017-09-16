/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_killer","_respawn","_respawnDelay"];

if (isServer) exitWith {};
if (isDedicated) exitWith {};
if (!hasInterface) exitWith {};
if (!isMultiplayer) exitWith {};

// Ensure Player Isn't In Debug
_debugPos = markerPos BP_DebugMarker;
if (_unit distance _debugPos < BP_DebugRadius) exitWith { ["onPlayerKilled: Skipped Death Event Registration. Player In Debug.",_unit,_killer,_killerVar] call BP_fnc_debugConsoleFormat; };

// Register Death Event Early
[BP_characterID] remoteExecCall ["BPServer_fnc_playerDeathReg",2];

// Close Default Open Dialog (Inventory etc)
closeDialog 0;

// Disable User Input
disableUserInput true;

// Fetch Player ID + Killer Source
_playerID =	(getPlayerUID _unit);
_killerVar = r_player_killer;

// Killer Distance Checks
if (!isNull _killerVar) then {
	if (_killerVar != _unit) then {
		if (_killer distance _unit > 2000) then {
			_killer = objNull;
		} else {
			_killer = _killerVar;
		};
	};
};

// Killer Extra Details Checks
_killWeapon = if (vehicle _killer != _killer) then { typeOf vehicle _killer } else { currentWeapon _killer };
_killDistance =  if (!isNull _killer) then { round (_unit distance _killer) } else { 0 };

// if not acquired from fn_death, try again
if (isNil "BP_playerInventoryOnDeath") then {  BP_playerInventoryOnDeath = _unit call BP_fnc_getFullInventory; };

// Local Death Processing
[0] call BP_fnc_death;

// Ensure Killer is Valid
if (isNull _killer) then { _killer = _unit; };

// Process Late & Detailed Death Event
[BP_characterID,(netID _unit),_playerID,BP_playerName,str(BP_playerInventoryOnDeath),(netID _killer),_killWeapon,str(_killDistance)] remoteExecCall ["BPServer_fnc_playerDeath",2];

// Clear Saved Death Inventory
BP_playerInventoryOnDeath = nil;

// Log Message
["onPlayerKilled: Unit: %1 | Killer: %2 | Killer Var: %3~0001",_unit,_killer,_killerVar] call BP_fnc_debugConsoleFormat;

//Clear Player Scroll Wheel Options
{BP_myCursorTarget removeAction _x} count s_player_repairActions;
s_player_repairActions = [];
{BP_myCursorTarget removeAction _x} count s_player_removeActions;
s_player_removeActions = [];

//Clear Currently Building Storage Object If In Progress
_object = _unit getVariable ["constructionObject", objNull];
if (!isNull _object) then { deleteVehicle _object; };
_unit setVariable ["constructionObject",objNull];
_unit setVariable ["constructionClassname",""];
_unit setVariable ["constructionBlueprint",""];
call BP_fnc_resetSelfActions;	
call BP_fnc_resetThreadHandles;

BIS_respawnInProgress = true;

_unit call BP_fnc_resetPlayerNamespace;

BP_combat = 0;
BP_hunger = 0;
BP_thirst = 0;
BP_combat = 0;
BP_Group = [];

r_group_count = 0;
r_group_members = [];
r_group_membersIcons = [];

BIS_teamSwitched = true;

sleep 1;

disableUserInput false;