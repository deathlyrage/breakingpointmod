/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_position","_preWaypointPos","_wp","_index","_itemType","_lootPos","_nearby","_RandStartPos","_BackupWaypoint","_CentreMarker","_CentreRadius","_CentreMarkerPos","_CentreVehicleID","_CentreVehicle","_preWaypoints","_guaranteedLoot","_randomizedLoot","_spawnFire","_fadeFire","_crashDamage","_heliModel","_crashModel","_exploRange","_lootRadius","_heliStart","_safetyPoint","_crashName","_lootTable","_position","_startTime","_crashwreck","_landingzone","_aigroup","_helipilot","_wp2","_wp3","_pos","_crash","_num","_config","_itemTypes","_weights","_cntWeights","_endTime"];

params [["_vehicles",[],[[]]]];

if (_vehicles isEqualTo []) exitWith {};

_RandStartPos = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "HeliCrash" >> "RandStartPos");

//Random-Startpositions
_heliStart = selectRandom _RandStartPos;

//Spawn the AI-Heli flying in the air
_startTime = time;
_crashwreck = createVehicle ["BP_Chinook",_heliStart, [], 0, "FLY"];
_crashwreck setVariable ["permaLoot",true];
_crashwreck engineOn true;
_crashwreck flyInHeight 60;
_crashwreck forceSpeed 360;
_crashwreck setSpeedMode "FULL";
_crashwreck allowDamage false;
_crashwreck enableDynamicSimulation true;

//Only a Woman could crash a Heli this way...
_aigroup = createGroup civilian;
_helipilot = _aigroup createUnit ["C_man_polo_BP",getPos _crashwreck,[],0,"FORM"];
_helipilot setVariable ["permaLoot",true,true];
_helipilot moveInDriver _crashwreck;
_helipilot assignAsDriver _crashwreck;
_helipilot allowDamage false;

//Delay for Init
sleep 0.5;

{
	//Get Vehicle Information
	_x params ["_type","_position"];
	["spawnCrashCar: Starting Spawn Of %1 @ %2 ",_type,_position] call BP_fnc_debugConsoleFormat;
	
	//Create Vehicle
	_vehicle = [_type,_position,true] call BP_fnc_spawnVehicle;
	_vehicle allowDamage false;
	_crashwreck setSlingLoad _vehicle;
	
	//Add Waypoint
	["spawnCrashCar: Adding Pre-POC-Waypoint %1 on %2~0001", _x,str(_position)] call BP_fnc_debugConsoleFormat;
	_wp = _aigroup addWaypoint [_position,0];
	_wp setWaypointType "MOVE";
	_wp setWaypointBehaviour "CARELESS";
	
	//Wait Until Near Waypoint
	["spawnCrashCar: Waiting Until Reached Waypoint Pos %1",_position] call BP_fnc_debugConsoleFormat;
	waitUntil {((getPosATL _crashwreck) distance _position) <= 100};
	["spawnCrashCar: Reached Waypoint Pos %1",_position] call BP_fnc_debugConsoleFormat;
	
	//Delay 5 Seconds to get to a closer position to the waypoint
	sleep 5;
	
	//Drop Vehicle
	_cargo = (getSlingLoad _crashwreck);
	_cargoPos = (getPos _cargo);
	["spawnCrashCar: Preparing to Drop Vehicle %1 @ Position %2",_cargo,_cargoPos] call BP_fnc_debugConsoleFormat;
	if (!isNull _cargo) then
	{
		//Cut The Ropes Of Sling Load
		["spawnCrashCar: Cutting Ropes %1",(ropes _crashwreck)] call BP_fnc_debugConsoleFormat;
		{ ropeCut [_x, 5]; } count (ropes _crashwreck);
		
		//Delay a Second
		sleep 1;
		
		//Create Parachute
		["spawnCrashCar: Deploying Parachute"] call BP_fnc_debugConsoleFormat;
		_para = createVehicle ["B_Parachute_02_F", [0,0,0], [], 0, "FLY"];  
		_para setDir getDir _cargo;
		_para setPos getPos _cargo;
		_cargo attachTo [_para, [0,1,0]]; 
		
		//Handle Parachute Cleanup when Crate Hits Ground
		_handle = [_para,_cargo] spawn 
		{
			params ["_para","_cargo"];
			
			//Wait Until Cargo Touching Ground
			_fallTime = diag_tickTime;
			waitUntil {isTouchingGround _cargo || ((diag_tickTime - _fallTime) > 15)};
			
			//Deattach Crate and Delete Parachute
			detach _cargo;
			deleteVehicle _para;
			_cargo allowDamage true;
		};
	};
} count _vehicles;

//Clean Up the Crashsite
deleteVehicle _crashwreck;
deleteVehicle _helipilot;
