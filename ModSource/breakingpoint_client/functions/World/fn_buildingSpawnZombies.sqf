/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_building",objNull,[objNull]]];

//Check Building Isn't Null
if (isNull _building) exitWith {};

//Get Type and Config
_type = typeOf _building;
_config = configFile >> "CfgBuildingLoot" >> _type;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _type)) then
{
	_config = missionConfigFile >> "CfgBuildingLoot" >> _type;
};

//Check Building has class in config
if !(isClass _config) exitWith {};

//Check Building Isn't Haven
if ((netID _building) in BP_Buildings) exitWith {};

//Get Size and Pos
_buildingSize = (sizeOf _type);
_buildingPos = getPosATL _building;

//if (!BP_Zeds) exitWith {};
//if (BP_LocalZeds > BP_ZedMaxLocal) exitWith {};
//if (BP_NearbyZombies > BP_ZedMaxNearby) exitWith {};
//if (BP_SpawnZombies > BP_ZedMaxNearby) exitWith {};
//if (BP_RemoteZeds > BP_GlobalZeds) exitWith {};
//if (BP_GlobalZeds > BP_ZedMaxGlobal) exitWith {};

//Zombies Don't Spawn In Faction Strongholds ( 100m )
//_nearStrongholdRadius = _buildingPos call BP_fnc_strongholdNearbyRadius;
//if (_nearStrongholdRadius < 100) exitWith {};

//Zombies Don't Spawn Nearby Players && Only Spawn in Cleared Buildings with no other zombies
_noPlayerNear = (count (_buildingPos nearEntities ["CAManBase",_buildingSize])) == 0;
if (!_noPlayerNear) exitWith {};

//Zombies Only Spawn in Cleared Buildings with no other zombies
//_clean = {alive _x} count (_buildingPos nearEntities ["zZombie_Base",_buildingSize]) == 0;
//if (!_clean) exitWith {};

//_min = getNumber (_config >> "minRoaming");
//_max = getNumber (_config >> "maxRoaming");
//_zombieChance = getNumber (_config >> "zombieChance");

_positions = getArray (_config >> "zombiePos");

if (_positions isEqualTo []) exitWith {};

_chanceRnd = (floor random 100);
if (_chanceRnd > 75) then
{
	_unitTypes = getArray (_config >> "zombieClass");
	_position = selectRandom _positions;
	[(_building modelToWorld _position),_unitTypes,false] call BP_fnc_zombieGenerate;
};
