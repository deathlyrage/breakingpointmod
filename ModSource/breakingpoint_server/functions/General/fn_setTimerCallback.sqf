if !isServer exitWith {objNull};

_tr = createTrigger ["EmptyDetector", [0,0,0],false];
_tr setTriggerTimeout [_t, _t, _t, true];
_tr setTriggerStatements [
    "!triggerActivated thisTrigger", 
    "", 
    "0 = thisTrigger call " + _f
];

if (_this select 2) then {
	0 = _tr call (missionNamespace getVariable _f);
};

_tr