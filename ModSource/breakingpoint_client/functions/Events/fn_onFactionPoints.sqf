/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_points","_newPoints"];

_factionName = (player getVariable ["class",0]) call BP_fnc_getFactionName;
_factionVar = toLower _factionName;

//Add Local Points
player setVariable [_factionVar,_newPoints];

//Check Faction Clothing
call BP_fnc_checkFactionClothing;

//Show Points Message
//if (_points == 2) exitWith {}; //Don't Show Survivalist Point Gain
if (_points == 0) exitWith { cutText ["<t font='Sketch' color='#ffe000' size='3'>No Points Gained</t><br/>", "PLAIN DOWN", -1, true, true]; };
if (_points > 0) then {
	cutText [format ["<t font='Sketch' color='#ff0000' size='4'>+%1 POINTS</t><br/>",_points], "PLAIN DOWN", -1, true, true];
} else {
	cutText [format ["<t font='Sketch' color='#ff0000' size='4'>%1 POINTS</t><br/>",_points], "PLAIN DOWN", -1, true, true];
};
