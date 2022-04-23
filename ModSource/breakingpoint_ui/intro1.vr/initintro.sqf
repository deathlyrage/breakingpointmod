enableSaving [ false, false ];
_timeOfDay = 12;
if (random 1 >= 0.5) then {_timeOfDay = 0};

skipTime (_timeOfDay - dayTime);

_timeOfDay spawn {
	while {TRUE} do {
		sleep 300;
		skipTime (_this - dayTime);
	};
};

BIS_TT_colorWarning = [0.8,0.5,0,1];

{
	_mrkr = [markerPos _x, "exit"] call BIS_fnc_VRSpawnSelector;
} forEach ["spawn_0", "spawn_1", "spawn_2", "spawn_3", "spawn_4", "spawn_5", "spawn_6", "spawn_7", "spawn_8"];

{
	_x allowDamage FALSE;
	_x allowFleeing 0;
	_x setUnitPos "UP";
	_x addMagazines ["BP_762x54_SVD", 5];
	_x addWeapon "BP_SVT40";
	_x spawn {
		while {TRUE} do {
			waitUntil {count magazines _this < 3};
			_this addMagazines ["BP_762x54_SVD", 2];
		};
	};
	if (dayTime < 1) then {_x addWeapon "NVGoggles"};
	_x spawn {
		_pos = "UP";
		while {TRUE} do {
			_rnd = 10 + random 20;
			sleep _rnd;
			if (_pos == "UP") then {_pos = "MIDDLE"} else {_pos = "UP"};
			_this setUnitPos _pos;
		};
	};
	_x spawn {
		while {TRUE} do {
			waitUntil {_this distance markerPos "BIS_center" > 100};
			_this setPos markerPos "BIS_center";
		};
	};
	[_x, 10] call BIS_fnc_traceBullets;
} forEach [BIS_protagonist];

createCenter EAST;

{
	_x spawn {
		_grp = createGroup EAST;
		while {TRUE} do {
			_rnd = random 30;
			sleep _rnd;
			waitUntil {{alive _x} count allUnits < 5};
			_unit = "O_Soldier_VR_F" createUnit [markerPos _this, _grp, "if (dayTime < 1) then {this addWeapon 'NVGoggles'}; this addVest 'V_TacVest_blk'; this addHeadgear 'H_HelmetB_black'; this addMagazines ['BP_556x45_Stanag_Tracer', 5]; this addWeapon 'BP_M16OLD';", 0.2];
			_unit = leader _grp;
			_unit setPos markerPos _this;
			_unit setUnitPos "UP";
			_unit allowFleeing 0;
			[_unit, nil, 5] call BIS_fnc_VREffectKilled;
			_wp = _grp addWaypoint [markerPos "BIS_center", 0];
			_wp setWaypointType "SAD";
			_unit spawn {sleep 60; if !(isNull _this) then {_this setDamage 1}};
			waitUntil {!alive _unit};
			sleep 5;
		};
	};
} forEach ["spawn_0", "spawn_1", "spawn_2", "spawn_3", "spawn_4", "spawn_5", "spawn_6", "spawn_7", "spawn_8"];
/*
showCinemaBorder FALSE;

_camera = "Camera" camCreate markerPos "BIS_center";
_camera cameraEffect ["Internal", "Back"];

_camera spawn {
	_camera = _this;
	_dist = 75;
	_rotTime = 120;
	_steps = 50;
	_camHeight = 50;
	_degStep = 360 / _steps;
	_camTime = _rotTime / _steps;

	_pos = [markerPos "BIS_center", _dist, 0] call BIS_fnc_relPos;
	_pos set [2, _camHeight];

	_camera camSetPos _pos;
	_camera camSetTarget markerPos "BIS_center";
	_camera camCommit 0;

	while {TRUE} do {
		for [{_i = _degStep}, {_i <= 360}, {_i = _i + _degStep}] do {
			_pos = [markerPos "BIS_center", _dist, _i] call BIS_fnc_relPos;
			_pos set [2, _camHeight];
			_camera camSetPos _pos;
			_camera camCommit _camTime;
			waitUntil {camCommitted _camera};
		};
	};
};*/

[
	markerPos "BIS_center",				// Target position
	"",						// SITREP text
	50,						// Altitude
	75,						// radius
	0,						// viewing angle
	1,						// Clockwise movement
	[],
	1						// World scene mode
] spawn BIS_fnc_establishingShot;

_null = [] spawn {
	while {TRUE} do {
		playMusic "LeadTrack06_F";
		sleep 60;
	};
};