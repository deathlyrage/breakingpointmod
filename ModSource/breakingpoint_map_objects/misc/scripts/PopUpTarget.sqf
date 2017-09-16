/*
	File: PopUpTarget.sqf
	Author: BIS
	
	Description:
	Script to make the pop-up target actually pop back up.
	
	Parameter(s):
	_this select 0: the pop-up target object.
*/

private ["_target"];
_target = _this select 0;
_target setDamage 0;

scopeName "root";

if ((_target animationPhase "terc") <= 0) then 
{
	_target animate["terc", 1];
	
	if (!isNil "nopop") then 
	{
		if (nopop) then 
		{
			breakTo "root"
		};
	};
	
	sleep 3;
	
	if (!isNil "nopop") then 
	{
		if (nopop) then 
		{
			breakTo "root";	
		};
	};
	
	if (alive _target) then 
	{
		_target animate["terc", 0];
	};
};

true