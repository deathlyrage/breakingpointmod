private ["_object","_result","_units","_sync"];
_object = [_this,0,objnull,[objnull]] call bis_fnc_param;
_result = [];
_units = parsenumber (_object getvariable ["units","0"]);

switch _units do {

	case 0;
	case 1: {

		//--- Scan synchronized objects
		{
			_sync = _x;
			if ({_sync iskindof _x} count ["Logic","EmptyDetector"] == 0) then {
				if (_units > 0) then {
					_result = _result + [_x] + (units _x - [_x]);
				} else {
					_result set [count _result,_x];
				};
			};
		} foreach (synchronizedobjects _object);

	};
	case 2: {
		{
			_result = _result + list _x;
		} foreach (_object call bis_fnc_moduleTriggers);
	};
};

_result