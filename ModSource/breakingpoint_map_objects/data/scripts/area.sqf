//This scipt create a boards and markers around mission Area
//Call it from some object - invisible H can be best

//PARAMATERS:
//1st - mid point (name of the object)
//2nd - x axis
//3rd - y axis
//4th - how many tables (markers) have to be placed
//5th - angle of elipse

_xPos = position (_this select 0) select 0;
_yPos = position (_this select 0) select 1;

_howBigA = _this select 1;
_howBigB = _this select 2;
_tablesC = _this select 3;
_angle = _this select 4;

_i = 0;

while {_i < 360} do {
	_x = (_howBigA * (sin _i));
	_y = (_howBigB * (cos _i));
	_x_rot = _xPos + _x*(cos _angle) - _y*(sin _angle);
	_y_rot = _yPos + _x*(sin _angle) + _y*(cos _angle);
	_k = createVehicle ["Danger",[_x_rot, _y_rot,0], [], 0, "NONE"];
	_m = createMarker [format ["Marker" + str _i],[ _x_rot, _y_rot,0]];
	format ["Marker" + str _i] setMarkerType "Dot";
	_k setDir _i;
	format ["Marker" + str _i] setMarkerDir (_i - _angle);
	_i = _i + (360/_tablesC);
};