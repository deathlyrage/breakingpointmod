/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_debugThread"];

_admins = ["76561198034785754","76561198062516199"];
_playerID = getPlayerUID player;
if (_playerID in _admins) then 
{
	//Debug HintSilent Thread
	_debugThread = [] execVM "\breakingpoint_code\threads\BP_Debug.sqf";
	[_debugThread] call BP_fnc_addThreadHandle;

	//Debug Console (ESC Menu)
	/*
	[] spawn {
		waitUntil {!isNull findDisplay 46};
		(findDisplay 46) displayAddEventHandler ["KeyDown","
			if ((_this select 1) in actionKeys 'IngamePause') then {
				[] spawn {
					waitUntil {!isNull findDisplay 49};
					waitUntil {isNull findDisplay 49};
					createDialog 'RscDisplayDebugPublic'
				};
				false
			};
		"];
	};
	*/
};