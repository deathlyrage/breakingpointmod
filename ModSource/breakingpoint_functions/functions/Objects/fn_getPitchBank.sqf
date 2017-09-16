scriptName "Functions\objects\fn_getPitchBank.sqf";
/************************************************************
	Get Pitch and Bank
	By Andrew Barron

Parameters: object
Returns: [pitch, bank]

Returns the pitch and bank of an object, in degrees.

Yaw can be found using the getdir command.

Pitch is 0 when the object is level; 90 when pointing straight
up; and -90 when pointing straight down.

Bank is 0 when level; 90 when the object is rolled to the right,
-90 when rolled to the left, and 180 when rolled upside down.

The bank returned by this command is not fully accurate, it
can be off by up to 5% or so (depending on pitch), due to an unknown bug.
************************************************************/


//extract parameters
private ["_obj","_pitch","_bank","_yaw","_vdir","_vup","_sign"];

_obj = _this;


//find the yaw (direction) of the object
//note that map compass directions go CW, while coordinate (vector) directions go CCW
//so when we rotate vectors by this much (below), we are actually adjusting the vector as though the object were pointing north
_yaw = getdir _obj;


//----------------------------
//find pitch
//----------------------------

//get vector dir (pitch)
_vdir = vectordir _obj;

//rotate it around the origin according to the object's yaw (direction)
//we will then be left with the objects vectordir if it were facing north
_vdir = [_vdir, _yaw] call BIS_fnc_rotateVector2D;

//if we reverse the process we used to set pitch, we can now get pitch
_pitch = atan ((_vdir select 2) / (_vdir select 1));


//----------------------------
//find bank
//----------------------------

//repeat for bank (vectorup) with the same process as above
//for some reason, the results of this are not fully accurate
//the amount it is off depends on the pitch (you'd think I'd be able to figure it out from that clue...)

_vup = vectorup _obj;
_vup = [_vup, _yaw] call BIS_fnc_rotateVector2D;
_bank = atan ((_vup select 0) / (_vup select 2));

//if we are rolled over (abs bank > 90), we need to adjust our result
if((_vup select 2) < 0) then
{
	_sign = [1,-1] select (_bank < 0);
	_bank = _bank - _sign*180;
};


//----------------------------
//return value
//----------------------------

[_pitch, _bank];
