/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

//Fetch Survival data from another thread
BP_LocalSurvivalData = _this select 0;

//Hope this fucking works
cutRsc ["RscDisplayInfoScreen","PLAIN"];
