/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_strongholdGetLogic";

_factionID = _this;
_logic = objNull;

//Strongholds Disabled
if (!BP_FactionStrongholds) exitWith {objNull};

//Check for Strongholds
{
	_strongholdClass = _x getVariable "class";
	if (_strongholdClass == _factionID) exitWith {
		_logic = _x;
	};
} count entities "BP_Stronghold";

_logic