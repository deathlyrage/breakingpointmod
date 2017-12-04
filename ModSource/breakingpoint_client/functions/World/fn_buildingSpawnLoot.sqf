/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_building = _this select 0;

if (isNull _building) exitWith {};

_buildingPos = getPosATL _building;
_buildingType = 	typeOf _building;
_buildingSize = ((sizeOf _buildingType)+5);
_config = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_config = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

//Exit If Loot Is Disabled
if (!BP_Loot) exitWith {};

//Exit If Loot Above Global Limit
if (BP_LootGlobal > BP_LootMax) exitWith {};

//Check Building Isn't Locked
_locked = (_building getVariable ['bis_disabled_Door',0] == 1);
if (_locked) exitWith {};

//Check If Building Is A Haven
if ((netID _building) in BP_Buildings) exitWith {};

//Loot Doesn't Spawn In Faction Strongholds ( 100m )
//_nearStrongholdRadius = _buildingPos call BP_fnc_strongholdNearbyRadius;
//if (_nearStrongholdRadius < 100) exitWith {};

//--------------Check For Valid Building Config----------
_posOk = isArray (_config >> "lootPos");
_itemOk = isArray (_config >> "itemType");
_chanceOk = isNumber (_config >> "lootChance");
_lootMinOk = isNumber (_config >> "lootMin");
_lootMaxOk = isNumber (_config >> "lootMax");
if (!_posOk) exitWith {};// ["building_spawnLoot: %1 (%2) is missing lootPos Define. #1000",_buildingType,_config] call BP_fnc_debugConsoleFormat; };
if (!_itemOk) exitWith {};// ["building_spawnLoot: %1 (%2) is missing itemType Define. #1000",_buildingType,_config] call BP_fnc_debugConsoleFormat; };
if (!_chanceOk) exitWith {};// ["building_spawnLoot: %1 (%2) is missing lootChance Define. #1000",_buildingType,_config] call BP_fnc_debugConsoleFormat; };
if (!_lootMinOk) exitWith {};// ["building_spawnLoot: %1 (%2) is missing lootMin Define. #1000",_buildingType,_config] call BP_fnc_debugConsoleFormat; };
if (!_lootMaxOk) exitWith {};// ["building_spawnLoot: %1 (%2) is missing lootMax Define. #1000",_buildingType,_config] call BP_fnc_debugConsoleFormat; };

//-----------------Get Building Config Data--------------
_positions =	[] + getArray (_config >> "lootPos");
_itemTypes =	[] + getArray (_config >> "itemType");
_lootChance = getNumber (_config >> "lootChance");
_lootMin =	getNumber (_config >> "lootMin");
_lootMax =	getNumber (_config >> "lootMax");

//-------------------Process Building ------------------

//Fail-Safe Checks
if (_positions isEqualTo []) exitWith {};
if (_lootMax < 1) exitWith {};

//Process Loot Min / Max Random
private "_lootRnd";
if (_lootMin == _lootMax) then {
	_lootRnd = _lootMax;
} else {
	_lootRnd = floor (random _lootMax);
};
if (_lootRnd > _lootMax) then { _lootRnd = _lootMax; };
if (_lootRnd < _lootMin) then { _lootRnd = _lootMin; };
if (_lootRnd < 1) exitWith {};

//Make sure no nearby players in the building so they don't get crushed by spawning loot
_nearby = [_buildingPos,_buildingSize] call BP_fnc_nearbyPlayers;
if (_nearby) exitWith {};

//Check if loot exists already
_nearByObj = nearestObjects [_buildingPos, ["BP_LootBox","WeaponHolder","WeaponHolderSimulated"],_buildingSize];
if (count _nearByObj >= _lootMax) exitWith {};

//Shuffle Building Loot Positions
_positionsShuffle = [];
for "_i" from 1 to (count _positions) do {
	_positionsShuffle pushBack (_positions deleteAt (floor (random (count _positions))));
};

//Loop Through Each Position and Calculate the spawn.
{
	//Exit If Ran Out Of Spawn Count
	if (_lootRnd < 1) exitWith {};

	//Calculate Item Position in World Space
	_iPos = _building modelToWorld _x;

	//Check If Any Loot Boxes are in that world position
	_nearby = nearestObjects [_iPos, ["BP_LootBox","WeaponHolder","WeaponHolderSimulated"], 1];

	if (_nearby isEqualTo []) then
	{
		//Find Index Of Building Type
		_index = BP_CBLBase find _buildingType;

		//Check Index Building Type is Valid
		if (_index != -1) then
		{
			_weights = BP_CBLChances select _index;
			_cntWeights = count _weights;
			_index = floor(random _cntWeights);
			_index = _weights select _index;
			_itemType = _itemTypes select _index;

			if (count _itemType > 2) then {
				[_itemType select 0, _itemType select 1, _itemType select 2, _iPos] call BP_fnc_spawnLoot;
			} else {
				[_itemType select 0, _itemType select 1, "Default", _iPos] call BP_fnc_spawnLoot;
			};
			_lootRnd = _lootRnd - 1;
		} else {
			//["building_spawnLoot: Error: Building Type: %1 with Position %2 Not Found in BP-CBLBase.",_buildingType,_x] call BP_fnc_debugConsoleFormat;
		};
	};

	true
} count _positionsShuffle;
