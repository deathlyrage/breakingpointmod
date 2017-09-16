/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_object","_dataList"];
_dataCount = (count _dataList);

if (_dataCount < 1) exitWith { ["Set Local Var: Recieved Invalid Variable List Count.~1001",_object,_var,_val] call BP_fnc_DebugConsoleFormat; };
if (_dataCount > 10) exitWith { ["Set Local Var: Recieved More Then Allowed Variable Count Limit.~1001",_object,_var,_val] call BP_fnc_DebugConsoleFormat; };	

{ _object setVariable [(_x select 0),(_x select 1)]; } count _dataList;
