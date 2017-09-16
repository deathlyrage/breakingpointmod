/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_dog","_combatMode"];
_target = objNull;
_entities = (position _dog) nearEntities ["AllVehicles",45];

//Remove Invalid Entities From List
{
	_remove = ((_x isKindOf "Animal") or (_x == _dog) or (!alive _x) or (_x isKindOf "Car") or (_x == player));
	if (_remove) then { _entities = _entities - [_x]; };
} count _entities;

_playerGroup = player getVariable ["group","0"];
_playerClass = player getVariable ["class",0];
_playerFactionName = _playerClass call BP_fnc_getFactionName;

//Check and Process Player Attacks
if ((_combatMode == 2) or (_combatMode == 1)) then
{
	//Scan For Players
	if (isNull _target) then
	{
		{
			//Make Sure Target Is A Player
			if (isPlayer _x) then 
			{
				
				_targetGroup = _x getVariable ["group","0"];
				_traitorFlag = _x getVariable ["traitorFlag",false];
				_traitorUniform = (uniform _x in BP_TraitorClothing);
				_targetClass = _x getVariable ["class",0];
				_targetFactionName = _targetClass call BP_fnc_getFactionName;
				_killPoints = getNumber (configFile >> "CfgFactions" >> _playerFactionName >> "Points" >> "Kill" >> _targetFactionName >> "Level_1");
				_factionTarget = (_traitorFlag or _traitorUniform or _killPoints > -1);
				
				if ((_targetGroup == "0" or _targetGroup != _playerGroup) and _factionTarget) then
				{
					//Check Distance Against Target if null or not
					if (!(isNull _target)) then 
					{
						//Resign Target If Another One Is Closer
						if ((_dog distance _x) < (_dog distance _target)) then { _target = _x; };
					} else {
						//Assign Target because we have none
						_target = _x;
					};
				};
			};
		} count _entities;
	};
	
	//Scan For Zombies
	if (isNull _target) then
	{
		{
			//Make Sure Target Is A Zombie
			if (_x isKindOf "zZombie_Base") then
			{
				if (!(isNull _target)) then {
					//Resign Target If Another One Is Closer
					if ((_dog distance _x) < (_dog distance _target)) then {	_target = _x; };
				} else {
					//Assign Target because we have none
					_target = _x;
				};
			};
		} count _entities;
	};
};

_target