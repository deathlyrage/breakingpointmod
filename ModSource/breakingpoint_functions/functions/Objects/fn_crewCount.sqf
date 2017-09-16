/*
	Author: Karel Moricky

	Description:
	Return number of crew positions in vehicle

	Parameter(s):
		0: STRING - vehicle class
		1 (Optional): BOOL - true to include also cargo positions

	Returns:
	NUMBER
*/


private ["_class","_includeCargo","_crewCount"];
_class = [_this,0,"",[""]] call bis_fnc_param;
_includeCargo = [_this,1,false,[false]] call bis_fnc_param;

_crewCount = getnumber (configfile >> "cfgvehicles" >> _class >> "hasDriver");
_crewCount = _crewCount + ({getnumber (_x >> "hasGunner") > 0} count (_class call bis_fnc_getTurrets));
if (_includeCargo) then {_crewCount = _crewCount + getnumber (configfile >> "cfgvehicles" >> _class >> "transportSoldier");};
_crewCount