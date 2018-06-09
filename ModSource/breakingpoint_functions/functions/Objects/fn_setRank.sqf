/*
	Author: Karel Moricky

	Description:
	Set rank of vehicle crew

	Parameter(s):
	0: OBJECT
	1: STRING or NUMBER - rank or rank ID

	Returns:
	BOOL
*/
private ["_veh","_rank","_ranks","_rankID"];

_veh = [_this,0,objnull,[objnull]] call bis_fnc_param;
_rank = [_this,1,2,[0,""]] call bis_fnc_param;
_ranks = ["PRIVATE","CORPORAL","SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
_ranksCount = count _ranks;
_rankID = _rank;
if (typename _rankID == typename "") then {_rankID = _ranks find (toupper _rank);};

if (_rankID < 0 || _rankID > _ranksCount) exitwith {["%1 is not a valid rank",_rank] call bis_fnc_error; false};

if (effectivecommander _veh == _veh) then {
	_veh setrank (_ranks select _rankID);
} else {
	{
		switch (assignedvehiclerole _x select 0) do {
			case "Driver": {
				_x setrank (_ranks select _rankID);
			};
			case "Turret": {
				if (_x == commander _veh) then {
					_x setrank (_ranks select ((_rankID + 2) min (_ranksCount - 1)));
				} else {
					_x setrank (_ranks select ((_rankID + 1) min (_ranksCount - 1)));
				};
			};
			default {}
		};
	} foreach crew _veh;
};

true