scriptName "Functions\variables\fn_areEqual.sqf";
/************************************************************
	Are Equal
	By Andrew Barron

Parameters: [anything1, anything2, anything3, ...]

Two or more elements can be passed.

This returns true if all of the passed data elements are of the same
type and value.

NOTES:

-This function is an improvement over the == operator, because
it can handle any data type in any combination.

-For arrays, it returns true if both arrays hold the same elements
in the same order.

-If both values are undefined / nil / null, then this function will return
true.

-WARNING: EXTREMELY large strings (>4k) or compiled code (from
a file, for example) might not be properly compared, if they are
only different near the end of the file.

************************************************************/

private ["_i","_r","_d1","_d2","_d1t","_d2t"];

_r = true;

//loop thru all passed data, comparing each item to the next
//break out of loop as soon as two elements do not match
for[{_i=1},{_i < (count _this) && _r},{_i=_i+1}] do
{
	_d1 = _this select (_i-1);
	_d2 = _this select _i;

	//check data types
	if(isnil "_d1") then {_d1t = "UNDEF"} else {_d1t = typename _d1};
	if(isnil "_d2") then {_d2t = "UNDEF"} else {_d2t = typename _d2};

	//check if data types are the same
	if(_d1t != _d2t) then
	{
		_r=false;
	}
	else
	{
		//comparison operator differs depending on what data type we have
		//some data types can not use == for comparison
		switch _d1t do
		{
			//for arrays, we need to recurse with each element
			case "ARRAY":
			{
				private ["_c","_j"];
				_c = count _d1;
				if(_c!=count _d2)then
				{
					_r=false;
				}
				else
				{
					//loop thru all elements of the array, abort as soon as we find a mismatch of elements
					_j=0;
					while{_j<_c && _r}do
					{
						_r = [_d1 select _j, _d2 select _j] call BIS_fnc_areEqual;
						_j = _j + 1;
					};
				};
			};

			//for bool and code, we will convert to strings and compare
			case "BOOL":  {_r = (str _d1) == (str _d2)};
			case (typename {}):  {_r = (str _d1) == (str _d2)};

			//for scripts, converting to string will show the script path, but only only if they are still running. Assume scripts are unequal if one or both are complete
			case "SCRIPT":{if(scriptdone _d1) then {_r = false} else {_r = (str _d1) == (str _d2)}};

			//we'll always consider undefined data "equal" to itself; note it would return false if we used the == operator
			case "UNDEF": {_r = true};

			//these data types can have "null" values; we need to make sure we evaluate them as equal if both are null
			case "OBJECT":  {if(isnull _d1) then {_r = isnull _d2} else {_r = _d1 == _d2}};
			case "GROUP":   {if(isnull _d1) then {_r = isnull _d2} else {_r = _d1 == _d2}};
			case "CONTROL": {if(isnull _d1) then {_r = isnull _d2} else {_r = _d1 == _d2}};
			case "DISPLAY": {if(isnull _d1) then {_r = isnull _d2} else {_r = _d1 == _d2}};

			//for all other data types, we can use the == operator ("CONFIG", "SCALAR", "SIDE", "STRING", "TEXT")
			case default {_r = _d1 == _d2};
		};
	};
};
_r
