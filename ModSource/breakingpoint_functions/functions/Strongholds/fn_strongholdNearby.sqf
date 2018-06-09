/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_strongholdNearby";

private ["_unit","_factionID"];
_unit = _this select 0;
_factionID = 0;

//Strongholds Disabled
if (!BP_FactionStrongholds) exitWith {0};

//Check Nearby Strongholds
{
	//Gather Stronghold Data
	_strongholdName = _x getVariable "name";
	_strongholdClass = _x getVariable "class";
	_strongholdRadius = _x getVariable "radius";
	
	//Check If Player is Within Radius
	if ((_x distance _unit) < _strongholdRadius) exitWith {
		_factionID = _strongholdClass;
	};
	
} count entities "BP_Stronghold";

_factionID