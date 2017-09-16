/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_groupFix";

//No Player Object
if (isNull player) exitWith {};

// Check For Invalid Group Situations
_invalid = false;
_dog = player getVariable ["dog",objNull];
_groupUnits = (units group player);

_groupUnits = _groupUnits - [player];
_groupUnits = _groupUnits - [_dog];

{
	if (!isPlayer _x) then
	{
		_groupUnits = _groupUnits - [_x];
	};
} count _groupUnits;


if (count _groupUnits > 0) then { _invalid = true; };

// Cleanup Groups and Join a new one 
if (_invalid) then {
	// Join a Null Group 
	[player] joinSilent grpNull;
	
	// Create a New Group and Join It
	_group = createGroup civilian;
	_group setBehaviour "CARELESS";
	[player] joinSilent _group;
	
	//Setup Group ID
	//player setVariable ["group","0",true];
	
	//Make sure dog is in group
	if (!isNull _dog) then { [_dog] joinSilent (group player); };
};