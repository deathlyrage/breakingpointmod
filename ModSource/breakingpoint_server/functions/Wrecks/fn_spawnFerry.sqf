/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_startPos = (_this select 0);
_waypoints = (_this select 1);

//Spawn Ferry
_ferry = createVehicle ["BP_Fishingboat", _startPos, [], 0, "CAN_COLLIDE"];

//Spawn Driver
_driverGroup = createGroup civilian;
_driver = _driverGroup createUnit ["BP_Optout2_F",getPos _ferry,[],0,"FORM"];
_driver moveInDriver _ferry;
_driver assignAsDriver _ferry;
_ferry engineOn true;

//God Mode
_driver allowDamage false;
_ferry allowDamage false;

//Lock Driver
_ferry lockDriver true;

//Add Waypoints
{
	_x params ["_pos","_speed","_type","_timeout"];
	
	_wp = _driverGroup addWaypoint [_pos,0];
	_wp setWaypointType _type;
	_wp setWaypointBehaviour "CARELESS";
	_wp setWaypointSpeed _speed;
	_wp setWaypointTimeout _timeout;
} forEach _waypoints;
