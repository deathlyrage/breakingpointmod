/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_isAir","_inVehicle","_spawnZombies"];
_isAir = vehicle player isKindOf "Air";
_inVehicle = (vehicle player != player);

_nearbyBuildings = (getPosATL player) nearObjects ["building",200];
_spawnZombies = true;

//Limit Zombie Spawning to 20 Local Zombies Per Player / Limit Zombie Spawning to 30 per 300m Bubble
if (BP_LocalZeds > 20 || {BP_NearbyZombies > 30}) then { _spawnZombies = false; };

{
	_type = typeOf _x;
	_config = configFile >> "CfgBuildingLoot" >> _type;
	if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
	{
		_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
	};
	_canLoot = isClass (_config);
	_dis = _x distance player;

	if (_x isKindOf "Land_House_Logic") then
	{
		if (_dis > 4) then
		{
			[_x] call BP_fnc_logicSpawnLoot;
		};
	} else {
		if (_canLoot && {damage _x < 0.8}) then
		{
			//Loot
			if (BP_LootGlobal < BP_LootMax) then // && {!BP_HC_Connected}) then
			{
				if (_dis < 175 && {_dis > 4} && {!_inVehicle}) then {
					[_x] call BP_fnc_buildingSpawnLoot;
					//_handle = [_x] spawn BP_fnc_buildingSpawnLoot;
					//[_handle] call BP_fnc_addThreadHandle;
					//waitUntil {scriptDone _handle};
				};
			};

			//Zombies
			if ((_dis < 75) && {_dis > 15} && {_spawnZombies}) then {
				[_x] call BP_fnc_buildingSpawnZombies;
				//_handle = [_x] spawn BP_fnc_buildingSpawnZombies;
				//[_handle] call BP_fnc_addThreadHandle;
				//waitUntil {scriptDone _handle};
			};
		};
	};
	true
} count _nearbyBuildings;
