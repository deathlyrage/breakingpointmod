private ["_v","_int","_t"];
_v = _this select 0;
if (_v iskindof "helicopter" || _v iskindof "plane") then {
	//[[_v],"BIS_fnc_effectKilledAirDestruction",false] call BIS_fnc_mp;
};
if (_v iskindof "tank") then {
	_int = (fuel _v)*(2+random 2);
	_t=time;
	//[[_v,_int],"BIS_fnc_effectKilledSecondaries",false] call BIS_fnc_mp;
};
if (_v iskindof "car" || _v iskindof "ship") then {
	_int = 1;
	_t=time;
	//[[_v,_int],"BIS_fnc_effectKilledSecondaries",false] call BIS_fnc_mp;
};