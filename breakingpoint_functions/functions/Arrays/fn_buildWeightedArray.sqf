/*
	Breaking Point Mod: BP_fnc_buildWeightedArray

	Authors:
		-Joris-Jan van 't Land
		-Optimized by Karel Moricky
		-Deathlyrage

	Description:
		Function to select a random item from an array, taking into account item weights.
		The weights should be Numbers between 0 and 1, with a maximum precision of hundreds.
	
	Parameter(s):
		_this select 0: source Array (Array of Any Value)
		_this select 1: weights (Array of Number)
	
	Returns:
		Any Value selected item
	
	TODO:
		[*] Algorithm is inefficient?
*/

private ["_array", "_weights","_weightsTotal"];
_array = _this select 0;
_weights = +(_this select 1);

//Parameter validation.
if ((count _array) > (count _weights)) exitWith {"There must be at least as many elements in Weights (1) as there are in Array (0)!" call bis_fnc_error; nil};

_weightsTotal = count _weights;

if (_weightsTotal > 0) then 
{
	//Created weighted array of indices.
	private ["_weighted"];
	_weighted = [];
	{
		private ["_weight"];
		_weight = _x / _weightsTotal;

		//Normalize the weight for a precision of hundreds.
		_weight = round(_weight * 100);
	
		for "_k" from 0 to (_weight - 1) do 
		{
			0 = _weighted pushBack _forEachIndex;
		};
	} forEach _weights;

	_weighted
} else {
	["The sum of weights must be larger than 0"] call bis_fnc_error;
	nil
};