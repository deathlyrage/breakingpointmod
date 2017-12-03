/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_building = _this select 0;

if (isNull _building) exitWith {};

_buildingType = _x getVariable ["lootType",""];

if (_buildingType == "") exitWith {};

_buildingPos = getPosATL _building;
_buildingSize = _x getVariable ["lootRadius",5];
_lootMin = _x getVariable ["minLoot",1];
_lootMax = _x getVariable ["maxLoot",1];


if (_lootMax > 4) then { _lootMax = 4; };

_config = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_config = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};
_itemTypes =	[] + getArray (_config >> "itemType");

//Check Valid Logic Data
if (_buildingType == "") exitWith {};

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
_nearby = [_buildingPos,10] call BP_fnc_nearbyPlayers;
if (_nearby) exitWith {};

//Check if loot exists already
_nearByObj = nearestObjects [_buildingPos, ["BP_LootBox","WeaponHolder","WeaponHolderSimulated"],10];
if (count _nearByObj >= _lootMax) exitWith {};

for "_i" from 1 to _lootRnd do
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

		private "_iPos";
		if (_lootRnd == 1) then {
			_iPos = _buildingPos;
		} else {
			_iPos = [_buildingPos,_buildingSize,(random 360)] call BIS_fnc_relPos;
		};

		if (count _itemType > 2) then {
			[_itemType select 0, _itemType select 1, _itemType select 2, _iPos] call BP_fnc_spawnLoot;
		} else {
			[_itemType select 0, _itemType select 1, "Default", _iPos] call BP_fnc_spawnLoot;
		};
	} else {
		//["building_spawnLoot: Error: Building Type: %1 with Position %2 Not Found in BP-CBLBase.",_buildingType,_x] call BP_fnc_debugConsoleFormat;
	};
};

