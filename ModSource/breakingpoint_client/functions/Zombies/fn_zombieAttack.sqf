/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_damage","_wound"];

params ["_unit","_type"];

_vehicle = (vehicle player);

if (!alive _unit) exitWith {};
if (!alive _vehicle) exitWith {};

//if ((uniform player) in BP_ZombieClothing) exitWith {};

//_zombieAttacks = ["BP_Zomb_Act_Attack1","BP_Zomb_Act_Attack2"];

//Play Attack
_dir = [_unit,player] call BIS_fnc_dirTo;
_unit setDir _dir;
//_unit playActionNow (selectRandom _zombieAttacks);
_unit playActionNow "BP_Zomb_Act_Attack2";

//Delay
sleep 0.451;

if (!alive _unit) exitWith {};
if (!alive _vehicle) exitWith {};

if (_vehicle != player) then 
{
	_hpList = _vehicle call BP_fnc_vehicleHitpoints;
	_hp = selectRandom _hpList;
	_chance = round(random 12);
	
	_isGlass = (["Glass",_hp,false] call BP_fnc_inString);
	_isHull = (["Hull",_hp,false] call BP_fnc_inString);
	_isEngine = (["Engine",_hp,false] call BP_fnc_inString);

	[_unit,"hit",4,false] call BP_fnc_objSpeak;

	_dam = _vehicle getHitPointDamage _hp;
	_damage = random 0.05;

	if (_isGlass) then { _damage = random 0.5; };
	if (_isEngine) then { _damage = 0; };

	_total = (_dam + _damage);

	if (_isGlass and _total >= 1) then
	{
		if (r_player_blood < (r_player_bloodTotal * 0.8)) then 
		{
			_cnt = count (BP_woundHit select 1);
			_index = floor (random _cnt);
			_index = (BP_woundHit select 1) select _index;
			_wound = (BP_woundHit select 0) select _index; 
		} else {
			_cnt = count (BP_woundHit_ok select 1);
			_index = floor (random _cnt);
			_index = (BP_woundHit_ok select 1) select _index;
			_wound = (BP_woundHit_ok select 0) select _index; 
		};
		_damage = 0.1;
		[player, _wound, _damage, _unit,"zombie"] call BP_fnc_damageHandler;
		[_unit,"hit",2,false] call BP_fnc_objSpeak;	
	} else {
		if (local _vehicle) then {
			[_vehicle, _hp, _total, _unit,"zombie"] call BP_fnc_damageHandlerVehicle;
		} else {
			//BP_HitV = [_vehicle, _hp, _total, _unit,"zombie"];
			//publicVariableServer "BP_HitV";
		};
	};
} else {
	if ((_unit distance player) <= 2.75) then
	{
		_tPos = (getPosASL _vehicle);
		_zPos = (getPosASL _unit);
		_inAngle = [_zPos,(getDir _unit),120,_tPos] call BIS_fnc_inAngleSector;
		if (_inAngle) then 
		{
			//LOS check
			_cantSee = [_unit,_vehicle] call BP_fnc_losCheck;
			if (!_cantSee) then {
				
				_cnt = count (BP_woundHit_ok select 1);
				_index = floor (random _cnt);
				_index = (BP_woundHit_ok select 1) select _index;
				_wound = (BP_woundHit_ok select 0) select _index;
				
				_damage = 0.45 + random (1.2);
				[player, _wound, _damage, _unit,"zombie"] call BP_fnc_damageHandler;
				[_unit,"hit",2,false] call BP_fnc_objSpeak;
			};
		};
	};
};