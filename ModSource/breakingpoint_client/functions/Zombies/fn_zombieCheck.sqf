/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_vehicle = vehicle player;
_isVehicle = (_vehicle != player);
_refObj = (driver _vehicle);
_refObjPos = getPosATL _refObj;
_attacked = false;

{
	//Only Alive Zombies Do Things :)
	if (alive _x) then 
	{
		//Calculate Distance and Initial Vars
		_dist = (_x distance _refObj);
		_targeted = false;
		
		//Fetch Zombie Targeting Data
		_localtargets = _x getVariable ["localtargets",[]];
		_remotetargets = _x getVariable ["remotetargets",[]];
		_targets = _localtargets + _remotetargets;

		//Known Target
		if (_refObj in _targets) then
		{
			if (_isVehicle) then
			{
				if (_dist < 3.6) then {
					_lastAttack = _x getVariable ["lastAttack",0];
					if ((diag_tickTime - _lastAttack) > 1) then {
						_handle = [_x,"zombie"] spawn BP_fnc_zombieAttack;
						[_handle] call BP_fnc_addThreadHandle;
						_x setVariable ["lastAttack", diag_tickTime];
					};
					_attacked = true;
				};
			} else {
				if (_dist < 2.5) then {
					_lastAttack = _x getVariable ["lastAttack",0];
					if ((diag_tickTime - _lastAttack) > 1) then {
						_handle = [_x,"zombie"] spawn BP_fnc_zombieAttack;
						[_handle] call BP_fnc_addThreadHandle;
						_x setVariable ["lastAttack", diag_tickTime];
					};
					_attacked = true;
				};
			};
		} else {
		
			//Noise Activation
			if ((_dist < BP_disAudial) && {!_targeted}) then
			{
				_targeted = true;
			};
			
			//Visual Activation
			if ((_dist < BP_disVisual) && {!_targeted}) then
			{
				_inAngle = [(getPosASL _x),(direction _x),30,(getPosASL _refObj)] call BP_fnc_inAngleSector;
				if (_inAngle) then {
					_cantSee = [_x,_refObj] call BP_fnc_losCheck;
					if (!_cantSee) then { _targeted = true; };
				};
			};
			
			//Update Targeting
			if (_targeted) then
			{
				if (local _x) then {
					0 = _localtargets pushBack _refObj;
					_x setVariable ["localtargets",_localtargets];
				} else {
					0 = _remotetargets pushBack _refObj;
					_x setVariable ["remotetargets",_remotetargets,true];
				};
			};

		};
	};
} count (_refObjPos nearEntities ["zZombie_Base", 50]);

_attacked
