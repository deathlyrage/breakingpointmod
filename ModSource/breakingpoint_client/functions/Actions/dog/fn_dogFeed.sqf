/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_dog", "_dogHandle", "_foodType"];
_array = _this select 3;
_dog = _array select 0;
_dogHandle = _array select 1;
_foodType = _array select 2;

if (isNull _dog) exitWith {};

player playActionNow "PutDown";

_hasFood = false;
_hasDrink = false;
_foodClassname = "";
_drinkClassname = "";
_foodTypes = 
[
	"FoodSteakRaw",
    "FoodMeatRaw",
	"FoodPlayerRaw",
    "FoodBeefRaw",
    "FoodMuttonRaw",
    "FoodChickenRaw",
    "FoodRabbitRaw",
    "FoodBaconRaw"
];

_drinkTypes = ["Waterbot","ItemWaterbotBoiled"];

//Go thru all magazines and check for food / water types
{
	if (_x in _foodTypes) then {
		_hasFood = true;
		_foodClassname = _x;
	};
	
	if (_x in _drinkTypes) then {
		_hasDrink = true;
		_drinkClassname = _x;
	};
	
} count (magazines player);

//Food
if (_foodType == 0) exitWith
{
	if (_hasFood) then
	{
		//Remove Food
		player removeMagazine _foodClassname;
		
		//Reset Hunger
		_dogHandle setFSMVariable ["_hunger",0];
		
		//Remove Action
		player removeAction s_player_dog_food;
		s_player_dog_food = -1;
		
		_dog playActionNow "GestureBark";
		[_dog,"dog_confirm",0,false] call BP_fnc_objSpeak;
	} else {
		//Error Message
		cutText ["You need either Raw Steak or Raw Mutton to feed this animal.","PLAIN DOWN"];
	};
};

//Water
if (_foodType == 1) exitWith
{
	if (_hasDrink) then
	{
		//Remove Water Bottle
		player removeMagazine _drinkClassname;
		
		//If water bottle was used, add a empty one
		if ((_drinkClassname == "Waterbot") or (_drinkClassname == "WaterbotBoiled")) then { player addMagazine "WaterbotEmpty"; };
		
		//Rest Thirst
		_dogHandle setFSMVariable ["_thirst",0];
		
		//Remove Action
		player removeAction s_player_dog_water;
		s_player_dog_water = -1;
		
		_dog playActionNow "GestureBark";
		[_dog,"dog_confirm",0,false] call BP_fnc_objSpeak;
	} else {
		//Error Message
		cutText ["You need a Water Bottle to feed this animal.","PLAIN DOWN"];
	};
};


