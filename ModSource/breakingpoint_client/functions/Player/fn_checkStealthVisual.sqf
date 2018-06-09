/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;

//Undead are Friendly to each other
if (BP_isUndead) exitWith {0};

//Zombie Clothing Isn't Visible
if ((uniform player) in BP_ZombieClothing) exitWith {40};

_scalePose = 0.9;
_stance = stance _unit;

call
{
	if (_stance == "STAND") exitWith { _scalePose = 45; };
	if (_stance == "CROUCH") exitWith { _scalePose = 30; };
	if (_stance == "UNDEFINED") exitWith { _scalePose = 10; };
	if (_stance == "PRONE") exitWith { _scalePose = 7; };
};

_scalePose
