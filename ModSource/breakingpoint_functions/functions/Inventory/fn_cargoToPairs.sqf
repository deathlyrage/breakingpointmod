/*
	Author: 
	AgentRev

	Description:
	Converts an array of items and quantities obtained from a get____Cargo command into an array of key-value pairs
	
	Parameter(s):
	_this: cargo array
		
	Returns: Array
	
	Example:
	 in:  [["a","b","c"],[1,2,3]]
	 out: [["a",1],["b",2],["c",3]]
*/

private "_array";
_array = [];

if (count _this > 1) then
{
	{ 0 = _array pushBack [_x, (_this select 1) select _forEachIndex]; } forEach (_this select 0);
};

_array
