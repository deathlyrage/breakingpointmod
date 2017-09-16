/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private "_inside";

params [["_position",[0,0,0],[[]]],["_building",objNull,[objNull]]];

//Attempt To Locate Nearby Building
if (isNull _building) then { _building = _position nearestObject "HouseBase";  };

//Can't Find Building
if (isNull _building) exitWith {false};

_relPos = _building worldToModel _position;
_boundingBox = boundingBox _building;

_boundingBox params ["_min","_max"];

_relPos params ["_myX","_myY","_myZ"];

if ((_myX > (_min select 0)) and (_myX < (_max select 0))) then {
		if ((_myY > (_min select 1)) and (_myY < (_max select 1))) then {
				if ((_myZ > (_min select 2)) and (_myZ < (_max select 2))) then {
						_inside = true;
				} else { _inside = false; };
		} else { _inside = false; };
} else { _inside = false; };

_inside