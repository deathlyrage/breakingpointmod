/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

BP_COLChances = [];
BP_COLBase = [];

// Mission config file loot table override.
_config = configFile >> "CfgObjectLoot";
if (isClass (missionConfigFile >> "CfgObjectLoot")) then
{
	_config = missionConfigFile >> "CfgObjectLoot";
};

for "_i" from 0 to ((count _config) - 1) do {
	_classname = configName (_config select _i);
	_itemChances = [] + getArray (_config >> _classname >> "ItemChance");
	_itemCount = count _itemChances;
	if (_itemCount > 0) then
	{
		if (BP_COLBase find _classname < 0) then
		{
			_weighted = [];
			_j = 0;
			for "_l" from 0 to ((count _itemChances) - 1) do
			{
				_weight = round ((_itemChances select _l) * 100);
				for "_k" from 0 to _weight - 1 do {
					_weighted set [_j + _k, _l];
				};
				_j = _j + _weight;
			};
			0 = BP_COLChances pushBack _weighted;
			0 = BP_COLBase pushBack _classname;
		};
	} else {
		0 = BP_COLChances pushBack [0];
		0 = BP_COLBase pushBack _classname;
	};
};

BP_CBLChances = [];
BP_CBLBase = [];

_config = configFile >> "CfgBuildingLoot";
if (isClass (missionConfigFile >> "CfgBuildingLoot")) then
{
	_config = missionConfigFile >> "CfgBuildingLoot";
};
for "_i" from 0 to ((count _config) - 1) do {
	_classname = configName (_config select _i);
	_itemChances = [] + getArray (_config >> _classname >> "ItemChance");
	_itemCount = count _itemChances;
	if (_itemCount > 0) then
	{
		if (BP_CBLBase find _classname < 0) then
		{
			_weighted = [];
			_j = 0;
			for "_l" from 0 to ((count _itemChances) - 1) do {
			_weight = round ((_itemChances select _l) * 100);
				for "_k" from 0 to _weight - 1 do {
					_weighted set [_j + _k, _l];
				};
			_j = _j + _weight;
			};
		0 = BP_CBLChances pushBack _weighted;
		0 = BP_CBLBase pushBack _classname;
		} ;
	} else {
		0 = BP_CBLChances pushBack [0];
		0 = BP_CBLBase pushBack _classname;
	};
};

//Loop Through All Buildings and Generate a List that spawn Loot and can Spawn Zombies
BP_ZombieBuildings = [];
BP_LootBuildings = [];
for "_i" from 0 to ((count _config) - 1) do
{
	_type = _config select _i;
	_canZombie = 	getNumber (_type >> "zombieChance") > 0;
	_canLoot = 		getNumber (_type >> "lootChance") > 0;
	if (_canZombie) then {
		if !((configName _type) in BP_ZombieBuildings) then {
			0 = BP_ZombieBuildings pushBack (configName _type);
		};
	};
	if (_canLoot) then {
		if !((configName _type) in BP_LootBuildings) then {
			0 = BP_LootBuildings pushBack (configName _type);
		};
	};
};
