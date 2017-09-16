/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_location","_dir"];
_location = player modelToWorld [0,0.3,0];
if ((_location select 2) < 0) then { _location set [2,0]; };

if !("PartWoodPile" in magazines player) exitWith { cutText ["You need wood to build a small camp fire.", "PLAIN DOWN"]; };

// Remove Wood and Play Animation
player removeMagazine "PartWoodPile";
_dir = getDir player;
player playActionNow "Medic";
sleep 6;

// Only One Active Fireplace per player
if (!isNull BP_hasFire) then {
	if (player distance BP_hasFire < 750) then {
		cutText ["You can only have one active camp fire at a time. Your previous one has been destroyed.", "PLAIN DOWN"];
	};
	deleteVehicle BP_hasFire;
	BP_hasFire = objNull;
};

BP_hasFire = createVehicle ["BP_SmallCampfire", _location, [], 0, "CAN_COLLIDE"];
BP_hasFire setDir _dir;
BP_hasFire enableDynamicSimulation true;

cutText ["You have created a fireplace.", "PLAIN DOWN"];

player reveal BP_hasFire;

