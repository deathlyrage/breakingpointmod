/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

/*
	Breaking Point Mod: BP_fnc_isInsideBuilding
	
	Known Authors:
	-Deathlyrage

	Description:
	Function to calculate a array of all the medical details.
	
	Parameter(s):
	_this select 0: unit
	_this select 1: building (optional)
	
	Example:
	_isInside = call BP_fnc_isInsideBuilding;
	
	Returns:
	Boolean
	
*/

params [["_unit",player,[objNull]],["_building",objNull,[objNull]]];

//Exit If Null Unit
if (isNull _unit) exitWith {false};

//Select Nearest House If Not Specified
if (isNull _building) then { _building = nearestObject [_unit, "HouseBase"]; };

//Can't Find Building
if (isNull _building) exitWith {false};

private ["_inside","_relPos","_boundingBox"];
_inside = false;
_relPos = _building worldToModel (getPosATL _unit);
_boundingBox = boundingBox _building;

_boundingBox params ["_min","_max"];

_relPos params ["_myX","_myY","_myZ"];

if ((_myX > (_min select 0)) and (_myX < (_max select 0))) then 
{
	if ((_myY > (_min select 1)) and (_myY < (_max select 1))) then 
	{
		if ((_myZ > (_min select 2)) and (_myZ < (_max select 2))) then 
		{
			_inside = true;
		} else {
			_inside = false;
		};
	} else { 
		_inside = false; 
	};
} else { 
	_inside = false;
};

_inside