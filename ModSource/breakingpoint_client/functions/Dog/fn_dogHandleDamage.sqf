/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_dog","_selectionName","_damage","_source","_ammo"];

if (isNull _dog) exitWith {0};
if (!alive _dog) exitWith {0};

["dogHandleDamage: %1",_this] call BP_fnc_debugConsoleFormat;

//Get FSM Data and Owner Character ID
_fsmID = _dog getVariable ["fsm_handle",0];
_charID = parseNumber (_dog getVariable ["CharacterID","0"]);
_playerDog = ((_fsmID > 0) and (_charID > 0));

//Not Player Dog
if (!_playerDog) exitWith {};

//Get Health
_blood = _fsmID getFSMVariable "_blood";
_type = [_damage,_ammo] call BP_fnc_medicalDamageType;
_isMinor = (_hit in med_MinorWounds);
_isHeadHit = (_hit == "head");
_selfDamage = (_dog == _source);

//Handle Nil Blood
if (isNil "_blood") then {
	_blood = 8000;
	_fsmID setFSMVariable ["_blood",_blood];
};

// Self Damage
if (_selfDamage) exitWith {0};

// Non-Lethal Rounds
if (_ammo isKindOf "BP_NonLethal") exitWith {0};

// Fire Damage
if (isBurning _dog) exitWith {
	_scale = 100;
	_burnRate = (getBurningValue _dog);
	//Calculate Blood Loss
	_blood = _blood - (_damage * _scale);
	//Update Blood
	_fsmID setFSMVariable ["_blood",_blood];
	0
};

// Zombie Damage
if (_ammo == "zombie") exitWith {0};

// PVP Damage
_scale = 100;

/// Player Damage
if (_ammo != "zombie") then {
	_scale = _scale + 50;
	if (_damage > 0.01) then 
	{
		//Headshot
		if (_isHeadHit) then { _scale = _scale + 375; };
		//Damage Was Caused By Another Player
		if (isPlayer _source) then 
		{
			_scale = _scale + 650;
			if (_isHeadHit) then { _scale = _scale + 3000; };
			switch (_type) do {
				case 1: { _scale = _scale + 100; };
				case 2: { _scale = _scale + 100; };
			};

		};
	};
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
	
	_lowBlood = _dog getVariable ["med_lowBlood",false];
	
	if (_blood < 8000 && {!_lowBlood}) then { _dog setVariable ["med_lowBlood",true,true]; };

	//Update Blood
	_fsmID setFSMVariable ["_blood",_blood];
};


0