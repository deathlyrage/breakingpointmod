/*
	Author: Jiri Wainar

	Description:
	Creates an objects or stack of objects at given position or on top of given object (eg. table).

	Parameter(s):
	0: _positionASL:array				- ASL position where the objects will be spawned

	0: [
		_anchorObject:object,			  - anchor object (eg. table) defining where the objects will be spawned
	 	_anchorPlacement:string (default = "TOP") - anchor placement definition, valid values are "BOTTOM","TOP","GROUND"
	 							"BOTTOM"  - at the bottom of the object
	 							"TOP"	  - top of the objects boundingbox
	 							"GROUND"  - sitting just on the ground
	 							"ROADWAY" - sitting just on the ground
	   ]

	1: _className:string				- class of the objects; all need to have same class
	2: _count:scalar (default = 1)			- number of the object; if > 1 object will be spawned of top of each other
	3: _offsetMatrix:array (default = [0,0,0])	- starting spawning position offset
	4: _offsetDir:scalar (default = 0)		- starting spawning direction offset
	5: _dirNoise:code (default = {0})		- spawned object direction delta from the starting direction, defined as code returning dir delta value
	6: _enableSimulation:bool (default = false)	- shall the simulation of the spawned objects be enabled or not?

	Returns:
	array of created objects

	Example:
	_objects = [_position:array,_className:string,_count:scalar,_offsetMatrix:array,_offsetDir:scalar,_dirNoise:code,_enableSimulation:bool] call BIS_fnc_spawnObjects;
	_objects = [[_table,"TOP"],"Box_NATO_Wps_F",1,[(random 0.2)-0.1,(random 0.2)-0.1,0],(random 20)-10] call BIS_fnc_spawnObjects;
*/

private["_position","_anchorObject","_anchorPlacement","_className","_count","_offsetMatrix","_offsetDir","_dirNoise","_dir","_enableSim","_objects"];

_position 	= [_this,0,[],[[]]] call BIS_fnc_param;
_className 	= [_this,1,"",[""]] call BIS_fnc_param;
_count 		= [_this,2,1,[123]] call BIS_fnc_param;
_offsetMatrix 	= [_this,3,[0,0,0],[[]]] call BIS_fnc_param;
_offsetDir 	= [_this,4,0,[123]] call BIS_fnc_param;
_dirNoise 	= [_this,5,{0},[{}]] call BIS_fnc_param;
_enableSim	= [_this,6,false,[true]] call BIS_fnc_param;
_anchorObject   = objNull;

_objects	= [];

if (count _position == 0) exitwith
{
	["Input parameter id 0 is mandatory!"] call BIS_fnc_error;
};

if (_className == "") exitwith
{
	["Input parameter id 1 is mandatory!"] call BIS_fnc_error;
};

//positions was not provided; _anchorObject & _anchorPlacement are used
if (count _position < 3) then
{
	_anchorObject 	 = [_position,0,objNull,[objNull]] call BIS_fnc_param;
	_anchorPlacement = [_position,1,"TOP",[""]] call BIS_fnc_param;

	if (isNull _anchorObject) exitwith
	{
		["Input parameter '_anchorObject' is mandatory!"] call BIS_fnc_halt;
	};

	//make sure the anchor object is horizontaly leveled
	_anchorObject setDir getDir _anchorObject;

	private["_pos"];

	_pos = getPosASL _anchorObject;

	_position = switch (_anchorPlacement) do
	{
		case "BOTTOM":
		{
			_pos
		};
		case "GROUND":
		{
			_pos set [2,getTerrainHeightASL _pos];
			_pos
		};
		case "TOP":
		{
			private["_anchorHeight"];

			_anchorHeight = _anchorObject call BIS_fnc_objectHeight;
			_pos set [2,(_pos select 2)+_anchorHeight];
			_pos
		};
		case "ROADWAY":
		{
			private["_airHeight","_aslHeight","_aslRoadwayHeight"];

			_aslHeight 	  = (getPosASL _anchorObject) select 2;
			_airHeight 	  = (getPos _anchorObject) select 2;
			_aslRoadwayHeight = _aslHeight - _airHeight;

			_pos = getPosASL _anchorObject;
			_pos set [2,_aslRoadwayHeight];
			_pos
		};
		default
		{
			_pos
		};
	};

	_dir = getDir _anchorObject;
}
else
{
	_dir = 0;	//if position is used instead of anchor object, teh starting direction is set to 0, can be adjusted using '_offsetDir'
};

//apply starting direction offset
_dir = _dir + _offsetDir;

//apply starting position offset
if !(isNull _anchorObject) then
{
	private["_height"];

	_height = _position select 2;

	_offsetMatrix = [_anchorObject worldToModel (getPosATL _anchorObject),_offsetMatrix] call BIS_fnc_vectorAdd;
	_position = _anchorObject modelToWorld _offsetMatrix;
	_position = ATLtoASL _position;
	_position set [2, _height];
}
else
{
	_position = [_position,_offsetMatrix] call BIS_fnc_vectorAdd;
};


private["_objHeight","_x","_y","_z","_obj","_pos","_dirDelta"];

_x = _position select 0;
_y = _position select 1;
_z = _position select 2;

//get the spawned object height
_objHeight = 0;

//spawn objects
for "_i" from 0 to (_count-1) do
{
	_pos = [_x,_y,_z + (_i*_objHeight)];
	_dirDelta = [] call _dirNoise;

	_obj = createVehicle [_className, _pos, [], 0, "CAN_COLLIDE"];
	_obj setPosASL _pos;
	_obj setDir (_dir +_dirDelta);

	if !(_enableSim) then
	{
		_obj enableSimulation false;
	}
	else
	{
		_obj enableSimulation true;
	};

	//calculate the object height only once to save resources
	if (_i == 0) then
	{
		_objHeight = _obj call BIS_fnc_objectHeight;
	};

	//add the reference to the created object
	_objects set [count _objects, _obj];

	//safe-check reposition
	[_obj,_pos,_enableSim] spawn
	{
		sleep 3;

		(_this select 0) setPosASL (_this select 1);
	};
};

_objects