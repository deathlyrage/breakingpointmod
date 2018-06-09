/*
	Author: 
	AgentRev

	Description:
	Retrieves a unit's cargo magazines for each uniform part and combines them in a single array
	
	Parameter(s):
	_this: unit
		
	Returns: Array of arrays - [["mag class", "count", "container number"]]
	
	Example:
	 in:  [["a","b","c"],[1,2,3]]
	 out: [["a",1],["b",2],["c",3]]
*/

private ["_magsUniform", "_magsVest", "_magsBackpack", "_allCargoMags"];

_magsUniform = (getMagazineCargo uniformContainer _this) call BP_fnc_cargoToPairs;
_magsVest = (getMagazineCargo vestContainer _this) call BP_fnc_cargoToPairs;
_magsBackpack = (getMagazineCargo backpackContainer _this) call BP_fnc_cargoToPairs;

_allCargoMags = [];

{ 0 = _allCargoMags pushBack [_x select 0, _x select 1, 0]; } count _magsUniform;
{ 0 = _allCargoMags pushBack [_x select 0, _x select 1, 1]; } count _magsVest;
{ 0 = _allCargoMags pushBack [_x select 0, _x select 1, 2]; } count _magsBackpack;

_allCargoMags
