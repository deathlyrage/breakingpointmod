/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_loginWnd = _this select 0;

_survival = BP_LocalSurvivalData;
BP_LocalSurvivalData = nil;

hint str _display;

//Grab Controls
_ctrlMap1 = (_loginWnd displayCtrl 1002);
_ctrlMap2 = (_loginWnd displayCtrl 1003);
_ctrlDay = (_loginWnd displayCtrl 1004);
_ctrlLocation = (_loginWnd displayCtrl 1005);
_ctrlRanger = (_loginWnd displayCtrl 1006);
_ctrlNomad = (_loginWnd displayCtrl 1007); 
_ctrlSurvivalist = (_loginWnd displayCtrl 1008);
_ctrlEngineer = (_loginWnd displayCtrl 1009);
_ctrlHunter = (_loginWnd displayCtrl 1010);
_ctrlOutlaw = (_loginWnd displayCtrl 1011);
_ctrlIndie = (_loginWnd displayCtrl 1012);
_ctrlUndead = (_loginWnd displayCtrl 1013);
_ctrlUndeadKills = (_loginWnd displayCtrl 1014);
_ctrlZKills = (_loginWnd displayCtrl 1015);
_ctrlHKills = (_loginWnd displayCtrl 1016);
_ctrlHeadshots = (_loginWnd displayCtrl 1017);
_ctrlDistTravel = (_loginWnd displayCtrl 1018);

//World
_worldName = worldName;

//Location
_nearestCity = nearestLocations [getPos player, ["NameCityCapital","NameCity","NameVillage","NameLocal"],1000];
_location = "Wilderness";
if (count _nearestCity > 0) then 
{ 
	_location = text (_nearestCity select 0);
};

//Survival Time
_totalMins = _survival select 0;
_days = floor (_totalMins / 1440);
_totalMins = (_totalMins - (_days * 1440));
_hours = floor (_totalMins / 60);
_mins =  (_totalMins - (_hours * 60));

//Stats
_zombieKills = player getVariable ["zombieKills",0];
_humanKills = player getVariable ["humanKills",0];
_undeadKills = player getVariable ["undeadKills",0];
_headshots = player getVariable ["headShots",0];
_distTravel = player getVariable ["distTravel",0];

_rangerCnt = 0;
_nomadCnt = 0;
_survivalistCnt = 0;
_engineerCnt = 0;
_hunterCnt = 0;
_outlawCnt = 0;
_indieCnt = 0;
_undeadCnt = 0;

//Process all the players on the server and calc class data
{
	if (alive _x) then
	{
		_class = _x getVariable ["class",-1];
		if (_class == 0) then { _indieCnt = _indieCnt + 1; };
		if (_class == 1) then { _rangerCnt = _rangerCnt + 1; };
		if (_class == 2) then { _outlawCnt = _outlawCnt + 1; };
		if (_class == 3) then { _hunterCnt = _hunterCnt + 1; };
		if (_class == 4) then { _nomadCnt = _nomadCnt + 1; };
		if (_class == 5) then { _survivalistCnt = _survivalistCnt + 1; };
		if (_class == 6) then { _engineerCnt = _engineerCnt + 1; };
		if (_class == 7) then { _undeadCnt = _undeadCnt + 1; };
	};
} forEach allPlayers;

//Set Text
_ctrlMap1 ctrlSetText _worldName;
_ctrlMap2 ctrlSetText _worldName;
_ctrlLocation ctrlSetText _location;
_ctrlDay ctrlSetText (str _days);

_ctrlZKills ctrlSetText (str _zombieKills);
_ctrlHKills ctrlSetText (str _humanKills);
_ctrlUndeadKills ctrlSetText (str _undeadKills);
_ctrlHeadshots ctrlSetText (str _headshots);
_ctrlDistTravel ctrlSetText (str _distTravel);

_ctrlRanger ctrlSetText (str _rangerCnt);
_ctrlNomad ctrlSetText (str _nomadCnt);
_ctrlSurvivalist ctrlSetText (str _survivalistCnt);
_ctrlEngineer ctrlSetText (str _engineerCnt);
_ctrlHunter ctrlSetText (str _hunterCnt);
_ctrlOutlaw ctrlSetText (str _outlawCnt);
_ctrlIndie ctrlSetText (str _indieCnt);
_ctrlUndead ctrlSetText  (str _undeadCnt);
