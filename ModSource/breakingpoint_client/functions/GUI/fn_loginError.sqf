/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_loginError";
endLoadingScreen;
_myTime = diag_tickTime;
BP_AuthTimer = true;
0 cutRsc ["Default","PLAIN",0];
1 cutRsc [(_this select 0),"PLAIN"];
endMission "END6";