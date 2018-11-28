/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_unit","_selection","_damage","_hitPoint","_dam","_total","_break","_selection","_total"];
_unit =	_this select 0;
_selection =	_this select 1;
_damage = _this select 2;
_hitPoint = _this select 3;

if (local _unit) then {
	_dam = _unit getHitPointDamage "HitLegs";
	_total = (_dam + _damage);
	_break = false;
	if (_hitPoint in med_MinorWounds and _total >= 1 and _unit == player) then 
	{
		if ((_hitPoint == "hitlegs") and !r_fracture_legs) then {
			r_fracture_legs = true;
			_break = true;
		};
		if (((_hitPoint == "hitarms") or (_hitPoint == "hithands")) and !r_fracture_arms) then {
			r_fracture_arms = true;
			_break = true;
		};
		_canStand = canStand player;
		if ((!_canStand) and !r_fracture_legs) then {
			r_fracture_legs = true;
			_break = true;
		};
	};
	if (_break) then {
		r_player_blood = r_player_blood - 100;
		[_unit,"fracture"] call BP_fnc_objSpeak;
		[_unit,"brokenleg"] call BP_fnc_objSpeak;
		BP_unsaved = true;
	};
};
