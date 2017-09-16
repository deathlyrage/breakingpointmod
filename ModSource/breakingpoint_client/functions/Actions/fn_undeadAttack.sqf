/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Don't Allow Dead Undead Players to Attack
if !(alive player) exitWith {};

//Handle Attack
_lastAttack = player getVariable ["lastZedAttack",0];

//_attackTime = 2.5;
//_factionLevel = player call BP_fnc_getFactionLevel;
//if (_factionLevel == 2) then { _attackTime = 2; };
//if (_factionLevel == 3) then { _attackTIme = 1.2; };

if (diag_tickTime - _lastAttack > 1.8) then {
	player setVariable ["lastZedAttack",diag_tickTime];
	[player,"",objNull,objNull,"zombie","",objNull] call BP_fnc_fired;
};