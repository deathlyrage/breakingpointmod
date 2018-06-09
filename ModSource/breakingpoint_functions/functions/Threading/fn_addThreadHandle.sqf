/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_handle",scriptNull,[scriptNull]]];

//Don't Add a Handle for Null Scripts
if (isNull _handle) exitWith {false};

//Don't Add a Handle If It has Already Finished
if (scriptDone _handle) exitWith {false};

//Setup Threads Array If is Nil
if (isNil "BP_Threads") then { BP_Threads = []; };

//Add The Thread Handle to Threads Array
0 = BP_Threads pushBack _handle;

//Remove Invalid Handles from Threads Array
{
	if (isNull _x || {scriptDone _x}) then 
	{ 
		0 = BP_Threads deleteAt _forEachIndex;
	};
} forEach BP_Threads;

//Return Success
true