/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_factionName","_factionID","_position","_combatMode","_positions"];

//["spawnAISquad: %1",_this] call BP_fnc_debugConsoleFormat;

_group = createGroup east;
_unit1 = [_group,format ["BP_%1_Assault1_F",_factionName],_position,_factionID] call BP_fnc_spawnAI;
_unit2 = [_group,format ["BP_%1_Assault2_F",_factionName],_position,_factionID] call BP_fnc_spawnAI;
_unit3 = [_group,format ["BP_%1_Sniper1_F",_factionName],_position,_factionID] call BP_fnc_spawnAI;
_unit4 = [_group,format ["BP_%1_Sniper2_F",_factionName],_position,_factionID] call BP_fnc_spawnAI;
_unit5 = [_group,format ["BP_%1_Sniper2_F",_factionName],_position,_factionID] call BP_fnc_spawnAI;
_units = [_unit1,_unit2,_unit3,_unit4,_unit5];
_group setCombatMode _combatMode;

{
	_x setVariable ["respawn",[]];
	_x setVariable ["roaming",true];
	_x allowFleeing 0;
} count _units;

switch (_factionName) do
{
	case "Ranger":
	{
		{
			_waypoint = _group addWaypoint [_x,_forEachIndex];
			_waypoint setWaypointType "MOVE";
			_waypoint setWaypointTimeout [5,10,15];
			_waypoint setWaypointSpeed "FAST";
			_waypoint setWaypointCombatMode "RED";
			_waypoint setWaypointBehaviour "AWARE";
		} forEach _positions;
		
		_waypoint = _group addWaypoint [(_positions select 0),(count waypoints _group)];
		_waypoint setWaypointType "CYCLE";
		_waypoint setWaypointTimeout [5,10,15];
		_waypoint setWaypointSpeed "FAST";
		_waypoint setWaypointCombatMode "RED";
		_waypoint setWaypointBehaviour "AWARE";
	};
	case "Nomad":
	{
		{
			_waypoint = _group addWaypoint [_x,_forEachIndex];
			_waypoint setWaypointType "MOVE";
			_waypoint setWaypointTimeout [5,10,15];
			_waypoint setWaypointSpeed "FAST";
			_waypoint setWaypointCombatMode "RED";
			_waypoint setWaypointBehaviour "AWARE";
		} forEach _positions;
		
		_waypoint = _group addWaypoint [(_positions select 0),(count waypoints _group)];
		_waypoint setWaypointType "CYCLE";
		_waypoint setWaypointTimeout [5,10,15];
		_waypoint setWaypointSpeed "FAST";
		_waypoint setWaypointCombatMode "RED";
		_waypoint setWaypointBehaviour "AWARE";
	};
	case "Outlaw":
	{
		{
			_waypoint = _group addWaypoint [_x,_forEachIndex];
			_waypoint setWaypointType "MOVE";
			_waypoint setWaypointTimeout [5,10,15];
			_waypoint setWaypointSpeed "FAST";
			_waypoint setWaypointCombatMode "RED";
			_waypoint setWaypointBehaviour "AWARE";
		} forEach _positions;
		
		_waypoint = _group addWaypoint [(_positions select 0),(count waypoints _group)];
		_waypoint setWaypointType "CYCLE";
		_waypoint setWaypointTimeout [5,10,15];
		_waypoint setWaypointSpeed "FAST";
		_waypoint setWaypointCombatMode "RED";
		_waypoint setWaypointBehaviour "AWARE";
	};
};

if (isServer) then {
	//Add Group to Respawn Group Queue
	0 = BP_AIRespawnGroups pushBack [_group,[_unit1,_unit2,_unit3,_unit4,_unit5],_factionName,_factionID,_position,_combatMode];
};

_group