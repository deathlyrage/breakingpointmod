/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define ANIMALS ["BP_Dog","BP_Chicken_1","BP_Chicken_2","BP_Sheep_1","BP_Sheep_2","BP_Sheep_3","BP_Sheep_4"]
#define DOGS ["BP_Dog_1","BP_Dog_2","BP_Dog_3","BP_Dog_4","BP_Dog_5","BP_Dog_6","BP_Dog_7"]

_playerPos = getPosATL player;
_nearbyAnimals = [_playerPos,BP_AnimalDistance] call BP_fnc_nearbyAnimals;

if (_nearbyAnimals < BP_MaxAnimals) then
{
	//Variable Init
	_PosList = [];
	_PosSelect = [];

	//Find where animal likes
	_type = selectRandom ANIMALS;
	if (_type == "BP_Dog") then { _type = selectRandom DOGS; };
	_root = configFile >> "CfgVehicles" >> _type;
	
	//_favouritezones = getText ( _root >> "favouritezones");
	//http://forums.bistudio.com/showthread.php?93897-selectBestPlaces-%28do-it-yourself-documentation%29
	//http://community.bistudio.com/wiki/selectBestPlaces
	//http://resources.bisimulations.com/wiki/selectBestPlaces
	_favouritezones = "meadow + forest + trees";
	
	_PosList = selectBestPlaces [_playerPos,BP_AnimalDistance,_favouritezones,10,5];
	
	if (_PosList isEqualTo []) exitWith {};
	
	_num = (floor random (count _PosList));
	_PosSelect = (_PosList select _num);
	
	if (_PosSelect isEqualTo []) exitWith {};
	
	_Pos = _PosSelect select 0;
	
	_nearbyAnimals = [_playerPos,100] call BP_fnc_nearbyAnimals;
	if (player distance _Pos < BP_AnimalDistance and NOT surfaceIsWater _Pos and (_nearbyAnimals <= 1)) then 
	{
		_spawnType = "FORM";
		if (_type in DOGS) then { _spawnType = "NONE"; };
		_agent = createAgent [_type, _Pos, [], 0, _spawnType];
		_agent setPos _Pos;
		//_fsmid = [_pos,_agent] execFSM "\breakingpoint_code\system\animal_agent.fsm";
		//_fsmid setFSMVariable ["_handle", _fsmid];
		//_agent setVariable ["fsm_handle", _fsmid];
	};
};

