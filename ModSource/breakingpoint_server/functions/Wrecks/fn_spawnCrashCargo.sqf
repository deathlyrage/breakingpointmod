/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_position","_preWaypointPos","_wp","_index","_itemType","_lootPos","_nearby","_RandStartPos","_BackupWaypoint","_CentreMarker","_CentreRadius","_CentreMarkerPos","_CentreVehicleID","_CentreVehicle","_preWaypoints","_guaranteedLoot","_randomizedLoot","_spawnFire","_fadeFire","_crashDamage","_heliModel","_crashModel","_exploRange","_lootRadius","_heliStart","_safetyPoint","_crashName","_lootTable","_roll","_position","_startTime","_crashwreck","_landingzone","_aigroup","_helipilot","_wp2","_wp3","_pos","_crash","_num","_config","_itemTypes","_weights","_cntWeights","_endTime"];

if (!BP_CargoCrash) exitWith {};

_RandStartPos = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "HeliCrash" >> "RandStartPos");
_BackupWaypoint = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "HeliCrash" >> "BackupWaypoint");
_CentreMarker = getArray (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "HeliCrash" >> "CentreMarker");
_CentreRadius = getNumber (missionConfigFile >> "BreakingPoint" >> "CfgSettings" >> "HeliCrash" >> "CentreRadius");
_CentreMarkerPos = (_CentreMarker select 0);
_preWaypoints = 3;

_guaranteedLoot = 6;
_randomizedLoot = 3;
_spawnFire	= true;
_fadeFire	= false;
_crashDamage = 0.25;

_models = selectRandom BP_CargoCrashModels;

_heliModel = _models select 0;
_crashModel = _models select 1;

_exploRange = 750;
_lootRadius = 0.38;

//Random-Startpositions
_heliStart = selectRandom _RandStartPos;

//A Backup Waypoint, if not Chernarus, set some Coordinates far up in the north (behind all possible Crashsites)
_safetyPoint = (_BackupWaypoint select 0);

_crashName = getText (configFile >> "CfgVehicles" >> _heliModel >> "displayName");
_lootTables = getArray (configFile >> "CfgHelicrash" >> "loots");
_lootTable = selectRandom _lootTables;

//Select Random Position and Delete it out of the array
_roll = floor random (count BP_CargoCrashCrashpoints);
_position = BP_CargoCrashCrashpoints deleteAt _roll;

["spawnCrashSite: %1 started flying from %2 to %3 NOW!(TIME:%4||LT:%5)~0001", _crashName, _heliStart, _position, round(time), _lootTable] call BP_fnc_debugConsoleFormat;

//Spawn the AI-Heli flying in the air
_startTime = time;
_crashwreck = createVehicle [_heliModel,_heliStart, [], 0, "FLY"];
_crashwreck setVariable ["permaLoot",true];
_crashwreck engineOn true;
_crashwreck flyInHeight 80;
_crashwreck forceSpeed 360;
_crashwreck setSpeedMode "FULL";
_crashwreck allowDamage false;

//Create an Invisible Landingpad at the Crashside-Coordinates
_landingzone = createVehicle ["Land_HelipadEmpty_F", [_position select 0, _position select 1,0], [], 0, "CAN_COLLIDE"];

//Only a Woman could crash a Heli this way...
_aigroup = createGroup civilian;
_helipilot = _aigroup createUnit ["C_man_polo_BP",getPos _crashwreck,[],0,"FORM"];
_helipilot setVariable ["permaLoot",true,true];
_helipilot moveInDriver _crashwreck;
_helipilot assignAsDriver _crashwreck;
_helipilot allowDamage false;

//Delay for Init
sleep 0.5;

//Add Waypoints, Drop Care Pkgs
if (_preWaypoints > 0) then
{
	for "_x" from 1 to _preWaypoints do
	{
		//Add Waypoint
		_preWaypointPos = selectRandom BP_CargoCrashDroppoints;
		if (!surfaceIsWater _preWaypointPos) then
		{
			//Create Care Pkg
			_carePkg = "BP_CarePkg" createVehicle (getPosATL _crashwreck);
			[_carePkg,"CarePackage",11,15] call BP_fnc_spawnLootBox;
			_carePkg allowDamage false;
			_carePkg setVariable ["permaLoot",true,true];
			_crashwreck setSlingLoad _carePkg;

			["spawnCrashSite: Adding Pre-POC-Waypoint #%1 on %2~0001", _x,str(_preWaypointPos)] call BP_fnc_debugConsoleFormat;
			_wp = _aigroup addWaypoint [_preWaypointPos,0];
			_wp setWaypointType "MOVE";
			_wp setWaypointBehaviour "CARELESS";

			//Wait Until Near Waypoint
			["spawnCrashSite: Waiting Until Reached Waypoint Pos %1",_preWaypointPos] call BP_fnc_debugConsoleFormat;
			waituntil {((getPosATL _crashwreck) distance _preWaypointPos) <= 150};
			["spawnCrashSite: Reached Waypoint Pos %1",_preWaypointPos] call BP_fnc_debugConsoleFormat;

			//Delay 2 Seconds to get to a closer position to the waypoint
			sleep 2;

			//Drop Care Pkg
			_cargo = (getSlingLoad _crashwreck);
			_cargoPos = (getPos _cargo);
			["spawnCrashSite: Preparing to Drop Cargo %1 @ Position %2",_cargo,_cargoPos] call BP_fnc_debugConsoleFormat;
			if (!isNull _cargo) then
			{
				//Cut The Ropes Of Sling Load
				["spawnCrashSite: Cutting Ropes %1",(ropes _crashwreck)] call BP_fnc_debugConsoleFormat;
				{ ropeCut [_x, 5]; } count (ropes _crashwreck);

				//Delay deployment of parachute to allow the package to gain some distance from the chopper
				sleep 2.5;

				//Create Parachute
				["spawnCrashSite: Deploying Parachute"] call BP_fnc_debugConsoleFormat;
				//_para = "B_Parachute_02_F" createVehicle [0, 0, 10000];
				_para = createVehicle ["B_Parachute_02_F", [0,0,0], [], 0, "FLY"];
				_para setDir getDir _cargo;
				_para setPos getPos _cargo;
				//_cargo attachTo [_para, [0,2,0]];
				_cargo attachTo [_para, [0,0,0.9]];

				//Handle Parachute Cleanup when Crate Hits Ground
				_handle = [_para,_cargo] spawn {
					_para = _this select 0;
					_cargo = _this select 1;

					//Wait Until Cargo Touching Ground
					_fallTime = diag_tickTime;
					waitUntil {((getPosATL _cargo) select 2 < 0.5 || (isTouchingGround _cargo) || ((diag_tickTime - _fallTime) > 30))};

					//Deattach Crate and Delete Parachute
					detach _cargo;
					deleteVehicle _para;

					//Start Smoke
					_smokeObj = createVehicle ["BP_SmokeShell", [0, 0, 0], [], 0, "CAN_COLLIDE"];
					_smokeObj attachTo [_cargo, [0,0.4,0]];
					_smokeObj setVariable ["permaLoot",true];
				};
			};
		};
	};
};

["spawnCrashSite: Landing Zone: %1",(position _landingzone)] call BP_fnc_debugConsoleFormat;

_wp = _aigroup addWaypoint [position _landingzone,0];
_wp setWaypointType "MOVE";
_wp setWaypointBehaviour "CARELESS";

//Get some more Speed when close to the Crashpoint and go on even if Heli died or hit the ground
waituntil {(_crashwreck distance _position) <= 150 || not alive _crashwreck || (getPosATL _crashwreck select 2) < 5 || (damage _crashwreck) >= _crashDamage};

_crashwreck flyInHeight 50;
_crashwreck forceSpeed 15;
_crashwreck setSpeedMode "LIMITED";

//Taking out the Tailrotor would be more realistic, but makes the POC not controllable
//_crashwreck setHitPointDamage ["HitVRotor", 1];

_crashwreck engineOn false;
_crashwreck setFuel 0;

sleep 5;

//Giving the crashed Heli some time to find its "Parkingposition"
_helipilot setDamage 1;
_crashwreck setDamage 1;

//Enough time to fall to ground level
_fallTime = diag_tickTime;

waitUntil {isTouchingGround _crashwreck || ((diag_tickTime - _fallTime) > 30)};

["spawnCrashSite: %1 just exploded at %2!, ~0001", _crashName, str(getPosATL _crashwreck)] call BP_fnc_debugConsoleFormat;

//Get position of the helis wreck, but make sure its on the ground;
_pos = [getPos _crashwreck select 0, getPos _crashwreck select 1,0];
//_pos = getPosATL _crashwreck;

sleep 5;

//Clean Up the Crashsite
deleteVehicle _crashwreck;
deleteVehicle _helipilot;
deleteVehicle _landingzone;

["spawnCrashSite: Cleaned up Crash Site, Creating Crash Model %1 @ %2...~0001",_crashModel,_pos] call BP_fnc_debugConsoleFormat;

//Animation is done, lets create the actual Crashside
_crash = createVehicle [_crashModel, _pos, [], 0, "CAN_COLLIDE"];

//Calculate loot
_num	 = round(random _randomizedLoot) + _guaranteedLoot;

// Mission config file loot table override.
_config = configFile >> "CfgBuildingLoot" >> _lootTable;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _lootTable)) then
{
	_config = missionConfigFile >> "CfgBuildingLoot" >> _lootTable;
};

_itemTypes =	[] + getArray (_config >> "itemType");
_index = BP_CBLBase  find _lootTable;
_weights = BP_CBLChances select _index;
_cntWeights = count _weights;

//Log Information about Size Of Helicrash, Loot Table and how many loot items to spawn
["spawnCrashSite: Spawning %1 Loot Piles with loot table %2 over %3 size of crash.~0001", _num, _lootTable,sizeOf(_crashModel)] call BP_fnc_debugConsoleFormat;

//Creating the Lootpiles outside of the _crashModel
//Loop that creates loot piles around a helicrash
_lootObjects = [];
for "_x" from 1 to _num do
{
	//Create loot
	_index = floor(random _cntWeights);
	_index = _weights select _index;
	_itemType = _itemTypes select _index;

	//Let the Loot spawn in a non-perfect circle around _crashModel
	_lootPos = [_pos, ((random 2) + (sizeOf(_crashModel) * _lootRadius)), random 360] call BIS_fnc_relPos;
	_lootObj = [_itemType select 0, _itemType select 1, _lootPos, 0] call BP_fnc_spawnLootHeliCrash;
	_lootObj setVariable ["permaLoot",true];
	_lootObj setVelocity [0,0,1];
	_lootObjects pushBack _lootObj;
};

//Set Variable on Crash Model to keep count of all loot
_crash setVariable ["loot",_lootObjects];

//Spawn Crash Fire
private ["_firePos","_fireObj"];
_firePos = getPosATL _crash;
_fireObj = createVehicle ["BP_Fire", _firePos, [], 0, "CAN_COLLIDE"];
_fireObj setPosATL _firePos;
_fireObj setVariable ["permaLoot",true];

//Set Variable on Crash Model to keep track of attached fire object
_crash setVariable ["fire",_fireObj];

//Delay 5 Seconds
sleep 5;

//Use Dynamic Simulation on Crash and Loot Objects
_crash enableDynamicSimulation true;
{ _x enableDynamicSimulation true; } count _lootObjects;

_endTime = time - _startTime;
["spawnCrashSite: Crash completed! Wreck at: %2 - Runtime: %1 Seconds || Distance from calculated POC: %3 meters~0001", round(_endTime), str(getPos _crash), round(_position distance _crash)] call BP_fnc_debugConsoleFormat;
