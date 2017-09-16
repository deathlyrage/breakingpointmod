/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_dog","_killer"];

//Console Logging
["dogKilled: %1",_this] call BP_fnc_debugConsoleFormat;

//Make sure Not Null
if (isNull _dog) exitWith {};

//Process Killer
_killerVar = _dog getVariable ["killer",objNull];
if (!(isNull _killerVar)) then
{
	if (_killerVar != _dog) then {
		if (_killer distance _dog > 800) then { 
			_killer = objNull; 
		} else {
			_killer = _killerVar;
		};
	};
	_dog setVariable ["killer", objNull];
};

//Dog Death Sound
[_dog,"dog_pain",0,false] call BP_fnc_objSpeak;

//Reset Player Dog
_playerDog = player getVariable ["dog",objNull];
if (_dog == _playerDog) then
{
	//Reset Dog + Group + IDs
	//[_dog] joinSilent grpNull;
	player setVariable ["dog",objNull];
	player setVariable ["dogID",0];
	
	//Force a Full Character Save After Taming
	BP_SyncLastInventory = [];
	BP_SyncLastStats = [];
	BP_SyncLastMed = [];
	BP_unsaved = true;
};

//Inform Server Of Event Handler
[_dog,_killer] remoteExecCall ["BP_fnc_dogKilled",2];