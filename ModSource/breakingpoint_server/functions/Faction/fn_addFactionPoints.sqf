/*  [_player,50] call BPServer_fnc_addFactionPoints; */

params [["_player",objNull,[objNull]],["_points",0,[0]],["_showMsg",true,[true]]];
_points = round (_points);

if (isNull _player) exitWith {};

_class = _player getVariable ["class",0];
if (_class > 0) then 
{
	private ["_factionName","_factionVar","_currentPoints","_newPoints","_min","_max"];
	_factionName = _class call BP_fnc_getFactionName;
	_factionVar = toLower _factionName;

	//Calculate New Points
	_currentPoints = _player getVariable [_factionVar,0];
	_newPoints = (_currentPoints + _points);

	//Ensure Points are within Min / Max
	_min = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "min");
	_max = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "max");
	if (_newPoints < _min) then { _newPoints = _min; };
	if (_newPoints > _max) then { _newPoints = _max; };

	//Set New Points
	_player setVariable [_factionVar,_newPoints];
	
	//Allow Messages to be hidden
	if (!_showMsg) exitWith {};
	
	//Add Points (Remote)
	[_points,_newPoints] remoteExecCall ["BP_fnc_onFactionPoints",_player];
		
	//Check Faction Radio Status
	_player call BPServer_fnc_radioCheck;
} else {
	//Allow Messages to be hidden
	if (!_showMsg) exitWith {};

	//No Points Gained Message for None Class
	[0,0] remoteExecCall ["BP_fnc_onFactionPoints",_player];
};