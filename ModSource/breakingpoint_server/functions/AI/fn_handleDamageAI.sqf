/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_unit","_selection","_damage","_source","_ammo"];

//Don't Allow Null Damage
if (isNull _source) exitWith {0};

//Don't Allow Self Damage
if (_unit == _source) exitWith {0};

//Only Allow Damage From Players
if (!isPlayer _source) exitWith {0};

//Reveal Attacking Unit
_unit reveal [_source,4];

//Non-Lethal Rounds
if (_ammo isKindOf "BP_NonLethal") exitWith
{
	if (_hit == "" && {!_inVehicle}) then {
		//r_player_unconscious = true;
		//r_player_unconsciousWeapon = true;
	};
	0
};

//Get FSM Data
_fsmID = _unit getVariable "fsm_handle";
_type = [_damage,_ammo] call BP_fnc_medicalDamageType;
_isMinor = (_hit in med_MinorWounds);
_isHeadHit = (_hit == "head");
_isPlayer = (isPlayer _source);
_inVehicle = ((vehicle _unit) != _unit);
_inVehicleSource = ((vehicle _source) != _source);
_blood = _fsmID getFSMVariable "_blood";

//Send the AI After the person who shot him
_fsmID setFSMVariable ["_fireTarget", _source];

// PVP Damage
_scale = 200;

// Zombie Damage
if (_ammo == "zombie") then {
	if (_damage > 0.4) then {
		_scale = _scale + 1125;
		if (_isHeadHit) then { _scale = _scale + 375; };
	};
};

/// Player Damage
if (_ammo != "zombie") then {
	_scale = _scale + 50;
	if (_damage > 0.01) then {
		//Headshot
		if (_isHeadHit) then { _scale = _scale + 750; };
		//Damage Was Caused By Another Player who isn't you.
		if ((isPlayer _source) and !(_unit == _source)) then {
			_scale = _scale + 650; //1300

			if (_isHeadHit) then {
				_scale = _scale + 6000;
			};

			switch (_type) do {
				case 1: { _scale = _scale + 200; };
				case 2: { _scale = _scale + 200; };
			};

		};
	};
};

// Medical Ammo Class Handler and Damage
if (_damage > 0.01) then 
{
	//Process who Killed Who Events.
	if (_source isKindOf "CAManBase") then {
		_unit setVariable ["killer",_source];
		[_unit,_source,_damage] call BP_fnc_damageHandlerHit;
	};

	//Calculate Blood Loss
	private "_bloodLoss";
	_bloodLoss = (_damage * _scale);
	_blood = (_blood - _bloodLoss);
};

// Blood Damage
if (_damage > 0.01) then 
{
	//Enable aggressor Actions
	if (_source isKindOf "CAManBase") then { _dog setVariable ["killer",_source]; };

	//Calculate Blood Loss
	private "_bloodLoss";
	_bloodLoss = (_damage * _scale);
	_blood = (_blood - _bloodLoss);

	//Update Blood
	_fsmID setFSMVariable ["_blood",_blood];
};

if (_blood < 1) then {
	//Clear Backpack Magazines and ALl Weapons
	clearMagazineCargoGlobal (backpackContainer _unit);
	removeAllWeapons _unit;
	
	//Add Lootable Weapon
	_lootWeapon = _unit getVariable ["lootWeapon",""];
	if (_lootWeapon != "") then { _unit addWeapon _lootWeapon; };
	
	//Kill Unit
	_unit setDamage 1;
};

0