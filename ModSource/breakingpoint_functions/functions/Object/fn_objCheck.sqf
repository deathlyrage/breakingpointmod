/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_object","_valid","_list","_isRock","_xStr"];
_object = _this;
_objectPos = (getPosATL _object);
_objectType = (typeOf _object);
_valid = true;

//Check for Invalid Object Ref
if (isNull _object) exitWith {false};

_houseObject = (_objectType isKindOf "BP_HouseObject");
_houseStorage = (_objectType isKindOf "BP_HouseStorage");
_rockStash = (_objectType isKindOf "BP_RockStash");
_onRoad = isOnRoad _objectPos;

_isInsideObject = [_object] call BP_fnc_isInsideBuilding;
_isInsidePlayer = [player] call BP_fnc_isInsideBuilding;

_badStrings =
[
	"stone",
	"rock",
	"cargo",
	"spp_transformer",
	"garbage",
	"rampart",
	"wreck",
	"cargobox",
	"tyres",
	"statue01",
	"misc_concrete_high"
];

//Make sure the Object Isn't Near Rocks and the object is not a house Object
if (!_houseObject && {!_houseStorage}) then 
{
	_list = nearestObjects [player, [],10];
	_index = _list find _object;
	if (_index >= 0) then { _list deleteAt _index; };
	{
		_xStr = format ["%1",_x];
		{
			_contains = [_x,_xStr,false] call BP_fnc_inString;
			if (_contains) then { _valid = false; };
		} forEach _badStrings;
	} forEach _list;
};

//Make sure the object surface isn't in water
if (surfaceIsWater _objectPos) exitWith {false};

//Can't Place Rock Stashes On Roads
if (_rockStash) then {
	if (_onRoad) then {
		_valid = false;
	};
};

//HouseStorage / House Object can only be placed in houses. Non House Objects cannot be placed in houses.
if (_houseObject || {_houseStorage}) then {
	if (!_isInsideObject or !_isInsidePlayer) then { _valid = false; };
} else {
	if (_isInsideObject or _isInsidePlayer) then { _valid = false; };
};

//Make sure the object isn't glitched into something
//_location = getPosATL _object;
//if ((_location select 2) < 0) exitWith {false};

_valid