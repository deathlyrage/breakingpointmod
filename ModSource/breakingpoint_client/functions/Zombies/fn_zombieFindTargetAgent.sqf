/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define RANGE 50

_agent = _this;
_target = objNull;

if (isNull _agent) exitWith { objNull };

_localtargets = _agent getVariable ["localtargets",[]];
_remotetargets = _agent getVariable ["remotetargets",[]];
_targets = _localtargets + _remotetargets;

//No Targets - Search For Nearby Objects
if (_targets isEqualTo []) then {
	_objects = nearestObjects [_agent,["ThrownObjects","SmokeShell"],RANGE];
	{
		if !(_x in _targets) then {
			if (local _x) then {
				0 = _localtargets pushBack _x;
			} else {
				0 = _remotetargets pushBack _x;
			};
		};
	} count _objects;
};

//Find The Best Targets
{
	call {
		//Prefer Valid Targets
		if (isNull _target) exitWith { _target = _x; };
		//Prefer Player Targets
		if (isPlayer _x && {!isPlayer _target}) exitWith { _target = _x; };
		//Prefer Closer Player Targets
		if (isPlayer _x && {isPlayer _target} && {(_agent distance _x) < (_agent distance _target)}) exitWith { _target = _x; };
	};
} count _targets;

if (uniform _target in BP_ZombieClothing && {count _targets > 1}) then {
	[_targets,_target] call BP_fnc_arrayDelete;
	_target = (_targets select 0);
};

//Remove Target If It's Too Far
if ((_agent distance _target) > RANGE) then { _target = objNull; };

_target
