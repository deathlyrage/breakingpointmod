scriptName "Functions\variables\fn_swapVars.sqf";
/************************************************************
	Swap Variables
	By Andrew Barron

Parameters: ["variable name 1", "variable name 2"]

Swaps the values of two variables, passed in quotes.

Nothing is returned, as this function modifies the variables
directly.

Example:

_a = 1;
_b = 2;
["_a","_b"] call BIS_fnc_swapVars
//_a now equals 2
//_b now equals 1

************************************************************/

private ["___v1","___v1","___tmp1","___tmp2"];

//get the names of the vars, in quotes
___v1 = _this select 0;
___v2 = _this select 1;

//get the values of the vars, these lines are equivalent to something like: ___tmp1 = call {_myvar};
//remember this function is being called within another script,
//so we still technically have access to the variables in that script
___tmp1 = call compile ___v1;
___tmp2 = call compile ___v2;

//swap the values of the variables
call compile format["%1 = ___tmp2; %2 = ___tmp1", ___v1, ___v2];
