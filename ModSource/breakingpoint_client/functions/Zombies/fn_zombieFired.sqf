/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_ammo","_distance","_audible","_unit","_unitPos"];

if ((diag_tickTime - BP_FiredTime) > 10 || {_ammo != BP_FiredAmmo}) then
{
	BP_FiredTime = diag_tickTime;
	BP_FiredAmmo = _ammo;

	_chance = 0;
	_zombieMin = 0;
	_zombieMax = 0;
	_sprint = false;

	if (_audible > 0 && {_audible < 5}) then
	{
		_chance = 10;
		_zombieMin = 1;
		_zombieMax = 2;
	};
	if (_audible > 5 && {_audible < 10}) then
	{
		_chance = 25;
		_zombieMin = 2;
		_zombieMax = 4;
	};
	if (_audible > 10 && {_audible < 15}) then
	{
		_chance = 50;
		_zombieMin = 2;
		_zombieMax = 6;
	};
	if (_audible > 15 && {_audible < 20}) then
	{
		_chance = 50;
		_zombieMin = 3;
		_zombieMax = 6;
		_sprint = true;
	};
	if (_audible > 20 && {_audible < 30}) then
	{
		_chance = 75;
		_zombieMin = 3;
		_zombieMax = 7;
		_sprint = true;
	};
	if (_audible > 30) then
	{
		_chance = 95;
		_zombieMin = 5;
		_zombieMax = 10;
		_sprint = true;
	};

	_spawnZombies = true;
	_nearHaven = false;

	//Limit Zombie Spawning to 20 Local Zombies Per Player and 30 per 300m Bubble
	if (BP_LocalZeds > 20 or BP_NearbyZombies > 30) then { _spawnZombies = false; };

	if (_spawnZombies) then
	{
		if (_chance > (floor random 100)) then
		{
			_zombies = (floor random _zombieMax);
			if (_zombies < _zombieMin) then { _zombies = _zombieMin; };
			if (_zombies > _zombieMax) then { _zombies = _zombieMax };
			_nearbyBuildings = _unitPos nearObjects ["Building",300];

			//Remove Nearest Building
			_nearestBuilding = nearestObject [player, "HouseBase"];
			[_nearbyBuildings,_nearestBuilding] call BP_fnc_arrayDelete;

			for "_i" from 1 to _zombies do
			{
				if (count _nearbyBuildings > 0) then
				{
					_building = selectRandom _nearbyBuildings;
					if (!isNull _building) then
					{
						_buildingPos = getPosATL _building;
						_type = typeOf _building;
						_config = configFile >> "CfgBuildingLoot" >> _type;
						if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
						{
							_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
						};
						_canLoot = isClass (_config);
						if ((netID _building) in BP_Buildings) exitWith {
							_canLoot = false;
							_nearHaven = true;
						};

						if (_canLoot) then {
							_unitTypes = getArray (_config >> "zombieClass");
							_positions = getArray (_config >> "zombiePos");
							if !(_positions isEqualTo []) then
							{
								_position = selectRandom _positions;
								_iPos = _building modelToWorld _position;
								[_iPos,_unitTypes,true] call BP_fnc_zombieGenerate;
							};
						};
						[_nearbyBuildings,_building] call BP_fnc_arrayDelete;
					};
				};
			};
		};
	};
	if (!_nearHaven) then { [_unit,_distance,_sprint,_unitPos] call BP_fnc_zombieAlert; };
} else {
	_nearbyZombies = _unitPos nearEntities ["zZombie_Base",_distance];
	{ _x setVariable ["myDest",_unitPos,(!local _x)]; } count _nearbyZombies;
};
