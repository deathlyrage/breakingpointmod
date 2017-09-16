/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_trap",objNull,[objNull]]];

if (isNull _trap) exitWith {};

if (isServer) then
{
	_trigger = createTrigger ["EmptyDetector", getPosATL _trap,false];
	_trigger setPos getPosATL _trap;
	_trigger setVariable ["trap",_trap,false];
	_trigger setTriggerArea [0.5, 0.3, 0, true];
	_trigger setTriggerActivation ["ANY", "PRESENT", true];
	_trigger setTriggerStatements [
		"this",
		"[thisTrigger, thisList] call BP_fnc_trapTrigger;",
		""
	];
	[_trap] call BP_fnc_trapActivate;
};