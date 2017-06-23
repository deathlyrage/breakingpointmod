/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;

if (isNull _unit) exitWith {0};

//Undead are Friendly to each other
if (BP_isUndead) exitWith {0};

//Zombie Clothing Makes no Sound
if ((uniform player) in BP_ZombieClothing) exitWith {5};

_vel = velocity (vehicle _unit);
_speed = (_vel distance [0,0,0]);
_pos = getPosATL _unit;

_scaleMvmt = 0.2;
_initial = 0;

_stance = stance _unit;
switch (_stance) do {
	case "STAND": {
		_scaleMvmt = 1.15;
		_scalePose = 0.0;	
	};
	case "CROUCH": {
		_scaleMvmt = 0.60;
	};
	case "UNDEFINED": {
		_scaleMvmt = 0.2;
	};
	case "PRONE": {
		_scaleMvmt = 0.1; 
	};
};

if (isOnRoad _pos) then {
	_initial = _initial * 1.3;
	_scaleMvmt = _scaleMvmt + 1.0;
};

//Survivalist Perks

if (uniform _unit == "BP_Survivalist2_F") then
{
	switch (_stance) do {
		case "STAND": {
			_scaleMvmt = 0.85;
			_scalePose = 0.0;	
		};
		case "CROUCH": {
			_scaleMvmt = 0.45;
		};
		case "UNDEFINED": {
			_scaleMvmt = 0.1;
		};
		case "PRONE": {
			_scaleMvmt = 0.1; 
		};
	};
} else {
	if (uniform _unit == "BP_Survivalist3_F") then
	{
		switch (_stance) do {
			case "STAND": {
				_scaleMvmt = 0.65;
				_scalePose = 0.0;	
			};
			case "CROUCH": {
				_scaleMvmt = 0.25;
			};
			case "UNDEFINED": {
				_scaleMvmt = 0.05;
			};
			case "PRONE": {
				_scaleMvmt = 0.05; 
			};
		};
	};
};

//_building = nearestObject [_unit, "Building"];
//if (!isNull _building) then {
//	_isPlayerInside = [_unit,_building] call BP_fnc_isInsideBuilding;
//	if (_isPlayerInside) then {
//		if (_stance != "PRONE") then { _scaleMvmt = _scaleMvmt - 0.37; };
//	};
//};


_scaleSpeed = _initial + (_speed * 3);
_scaleTotal = round ((_scaleSpeed * _scaleMvmt) * 1.5);
_scaleTotal