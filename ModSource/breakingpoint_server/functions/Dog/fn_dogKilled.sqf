/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_dog","_killer"];

if (isNull _dog) exitWith {};

//Save Dog Death State for Person He Killed It From
_characterID = _dog getVariable ["CharacterID","0"];
if (_characterID != "0") then { _dog call BPServer_fnc_dogSync; };

//Handle Point Loss
if (!isNull _killer) then
{
	/*
	private ["_configName","_killerClass","_killerFactionName","_pointsChange"];
	_configName = getText (configFile >> "CfgVehicles" >> (typeOf _dog) >> "baseClass");
	_killerClass = _killer getVariable ["class",0];
	_killerFactionName = _killerClass call BP_fnc_getFactionName;
	_pointsChange = getNumber (configFile >> "CfgFactions" >> _killerFactionName >> "Points" >> "Hunt" >> "Kill" >> _configName);

	//Add Points (Local)
	[_killer,_pointsChange] call BPServer_fnc_addFactionPoints;

	//Add Points (Remote)
	BP_AddPoints = _pointsChange;
	(owner _killer) publicVariableClient "BP_AddPoints";

	["dogKilled: Dog: %1 | Killer: %2 | Faction: %3 | Points: %4",_dog,_killer,_killerFactionName,_pointsChange] call BP_fnc_debugConsoleFormat;
	*/
};




