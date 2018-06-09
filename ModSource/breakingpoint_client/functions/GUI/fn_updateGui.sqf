/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_foodVal","_thirstVal"];
_foodVal = 1 - (BP_hunger / SleepFood);
_thirstVal = 	1 - (BP_thirst / SleepWater);
([_foodVal,_thirstVal])