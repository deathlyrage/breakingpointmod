/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Close Inventory UI
closeDialog 0;

//Check for Ladder / Water / Vehicle
_onLadder =	(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_isWater = (surfaceIsWater (getPosATL player));
if (_onLadder) exitWith { cutText ["You can't build while on a ladder.","PLAIN DOWN"]; };
if (_isWater) exitWith { cutText ["You can't build while in water.","PLAIN DOWN"]; };
if ((vehicle player) != player) exitWith { cutText ["You can't build while in a vehicle.", "PLAIN DOWN"]; };

//Start Build Process
_magazine = _this select 0;

//Check If Magazine Exists
if !(_magazine in magazines player) exitWith {};

//Get Position / Location
_playerPos = getPosATL player;
_dir = round(direction player);
_location = player modelToWorld [0,0.3,0];
if ((_location select 2) < 0) then { _location set [2,0]; };

//Help Msg
cutText ["Use Q and E to rotate the trap then select desired action.", "PLAIN DOWN"];

_ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");

_object = _ammo createVehicleLocal _location;
_object hideObject true;
_boundingBox = boundingBox _object;
_maxPoint = ((_boundingBox select 1) select 0) max ((_boundingBox select 1) select 1);
_object attachTo [player, [0, _maxPoint + 1, ((_boundingBox select 1) select 2)]];
_object hideObject false;

player setVariable ["constructionObject",_object];
player setVariable ["constructionClassname",_ammo];
player setVariable ["constructionBlueprint",_magazine];

while {!isNull (player getVariable "constructionObject")} do { if (vehicle player != player) then { player action ["eject", vehicle player]; }; };

