/*
	Breaking Point Mod: BP_fnc_sumMedical

	Authors:
		-Deathlyrage

	Description:
		Function to calculate a array of all the medical details.
	
	Parameter(s):
		_this: player/character
	
	Example:
		_medical = player call BP_fnc_sumMedical;
	
	Returns:
		Array (Medical Details)
	
*/

_character = _this;


if (isServer) exitWith 
{
	[
		_character getVariable	["med_isDead",false],
		_character getVariable	["med_unconscious", false],
		_character getVariable	["med_infected",false],
		_character getVariable	["med_injured",false],
		_character getVariable	["med_inPain",false],
		_character getVariable	["med_isCardiac",false],
		_character getVariable	["med_lowBlood",false],
		_character getVariable	["med_bleedingLevel",0],
		_character getVariable	["med_BloodQty",12000],
		_character getVariable 	["med_fractures",[0,0]],
		_character getVariable	["messing",[0,0]],
		_character getVariable	["unconsciousTime",0]
	]
};

_legs = _character getHitPointDamage "HitLegs";
_arms = _character getHitPointDamage "HitHands";

if (_character == player) exitWith
{
	[
		r_player_dead,
		r_player_unconscious,
		r_player_infected,
		r_player_injured,
		r_player_inpain,
		r_player_cardiac,
		r_player_lowblood,
		r_player_bleedingLevel,
		r_player_blood,
		[_legs,_arms],
		player getVariable ["messing",[0,0]],
		player getVariable ["unconsciousTime",0]
	]
};		

[
	_character getVariable ["med_isDead",false],
	_character getVariable ["med_unconscious",false],
	_character getVariable ["med_infected",false],
	_character getVariable ["med_injured",false],
	_character getVariable ["med_inPain",false],
	_character getVariable ["med_isCardiac",false],
	_character getVariable ["med_lowBlood",false],
	_character getVariable ["med_bleedingLevel",0],
	_character getVariable ["med_BloodQty",12000],
	[_legs,_arms],
	_character getVariable ["messing",[0,0]],
	_character getVariable ["unconsciousTime",0]
]