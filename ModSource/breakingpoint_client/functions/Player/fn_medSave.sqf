/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Update Last Sync Time
BP_lastSaveMed = diag_tickTime;

//Get Medical Stats
_medicalSum = player call BP_fnc_sumMedical;

//Calculate to Skip Sync or Not
_skipMed = (_medicalSum isEqualTo BP_SyncLastMed);
if (!_skipMed) then 
{
	//Update Last Sync Medical Array
	BP_SyncLastMed = _medicalSum;

	//Sync Medical Data
	[(netID player),_medicalSum] remoteExecCall ["BPServer_fnc_medSync",2];
};