/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd

	Using: _inStr = ["needle","needle in haystack"] call BP_fnc_inString;
*/

(((_this select 1) find (_this select 0)) >= 0)

//private ["_needle","_haystack","_result","_expectedResult"];
//_needle = _this select 0;
//_haystack = _this select 1;
//_result = "regex_match" callExtension format ["/%1/%2",_needle,_haystack];
//_expectedResult = format ["[%1]",_needle];
//(_result == _expectedResult)