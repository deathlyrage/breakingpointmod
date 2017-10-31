/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//Disable Time / Weather on Dev Servers
if (BP_Dev) exitWith {};

// Check time multiplier -server start-
if (BP_Weather_Current == BP_Weather_None) then 
{
	_config = (configFile >> "CfgTime" >> worldName);
	_startDateInfo = getArray (_config >> "date");
	_startDateInfo params ["_day","_month","_year"];
	
	_timeState = profileNameSpace getVariable ["timeState",true];
	if (_timeState) then { _timeState = false; } else { _timeState = true; };
	profileNameSpace setVariable ["timeState",_timeState];
	saveProfileNamespace;
	
	_startTimeInfo = [0,0];
	if (!_timeState) then {
		_startTimeInfo = getArray (_config >> "first");
	} else {
		_startTimeInfo = getArray (_config >> "second");
	};
	
	_startTimeInfo params ["_hour","_minute"];

	//Update Date
	setDate [_year,_month,_day,_hour,_minute];
	
	//Set Initial Weather
	BP_Weather_Current = BP_Weather_Sunny;
	
	//Thirsk Snow
	//if (worldName == "thirskw" || {worldName == "namalsk"}) then
	//{
	//	10 setRain 0;
	//	10 setOvercast 0.8;
	//	10 setFog 0.4;
	//	setWind [0.201112*2,0.204166*2,false];
	//	simulWeatherSync;
	//};
	
	[] spawn
	{
		_weatherTemplates = 
		[
			//Clear and Sunny
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			["Clear",[0.30,0,0,0,0,0]],
			
			
			//Stormy
			["Rainstorm",[0.80,0.9,0.1,0,0,1]],
			["Rainstorm",[0.632,0.513,0,0,0,0]],
			["Rainstorm",[0.722,0.513,0,0,0,0]],
			["Rainstorm",[0.786,0.513,0,0,0,1]],
			["Rainstorm",[0.722,0.626,0,0,0,0]],
			["Rainstorm",[0.786,0.626,0,0,0,0]],
			
			["Rainstorm",[0.8827,0.626,0,0,0,1]],
			["Rainstorm",[0.786,0.782,0,0,0,0]],
			["Rainstorm",[0.8827,0.782,0,0,0,0]],
			["Rainstorm",[0.927,0.920,0,0,0,1]],
			
			["Rainstorm",[1,1,0,0,0,1]],		
			["Rainstorm",[0.544,0.422,0,0,0,0]],
			["Rainstorm",[0.632,0.422,0,0,0,0]],
			["Rainstorm",[0.544,0.3,0,0,0,0]],
			
			//Rainy
			["Overcast",[0.50,0,0,0,0,0]],
			["Light Rain",[0.60,0.3,0.05,0,0]],
			["Medium Rain",[0.70,0.5,0.05,0,0]],
			
			["Medium Rain",[0.55,0.0344,0,0,0,0]],
			["Medium Rain",[0.557,0.0530,0,0,0,0]],
			["Medium Rain",[0.557,0.0800,0,0,0,0]],
			["Medium Rain",[0.568,0.1230,0,0,0,0]],
			["Medium Rain",[0.572,0.2130,0,0,0,0]],
			
			
			
			//Foggy
			["Light Fog",[0.4,0,0.2,0.01,15,0]],
			["Medium Fog",[0.4,0,0.4,0.005,25,0]],
			["Dense Fog",[0.5,0,0.4,0.0025,30,0]]
		];
		
		_weatherTemplate = selectRandom _weatherTemplates;
		(_weatherTemplate select 1) params ["_weatherInitialOvercast","_weatherInitialRainSnow","_weatherInitialFog","_weatherInitialWindEW","_weatherInitialWindNS","_weatherInitialLightning"];

		skipTime -24;
		86400 setOvercast _weatherInitialOvercast;
		86400 setRain _weatherInitialRainSnow;
		86400 setFog _weatherInitialFog;
		setWind [_weatherInitialWindEW,_weatherInitialWindNS,true];
		86400 setLightnings _weatherInitialLightning;
		skipTime 24;
		sleep 1;
		simulWeatherSync;
	};
};

/*

if (worldName == "thirskw" || {worldName == "namalsk"}) exitWith {};


//Get current time
private ["_dateArray", "_timeCurrentHour", "_timeCurrentMinute"];
_dateArray = date;
_timeCurrentHour = _dateArray select 3;
_timeCurrentMinute = _dateArray select 4;
["Weather Engine: Current Time: %1 : %2 #1110", _timeCurrentHour, _timeCurrentMinute] call BP_fnc_debugConsoleFormat;

/*
if ((_timeCurrentHour == 22) && (_timeCurrentHour == 1)) then {
  setTimeMultiplier 100;
} else {
	if ((_timeCurrentHour >= 3) && (_timeCurrentHour <= 23)) then {
	  setTimeMultiplier 6.8;
	};
};
*/

/*

// Call weather sync (usually 800+) 60 for debug
if ((diag_tickTime - BP_Weather_SyncTime) > 900 || (BP_Weather_SyncTime == 0)) then
{
	private ["_weatherRandomIndex", "_weatherNightIndex"];

	_weatherRandomIndex = floor(random 6);
	_weatherNightIndex = 6;

	// Call Weather
	if (_timeCurrentHour > 18) then {
		 _weatherNightIndex call BPServer_fnc_weatherChange;
	} else {
		 _weatherRandomIndex call BPServer_fnc_weatherChange;
	};

	//Set Weather Last Call
	BP_Weather_SyncTime = diag_tickTime;

	// Print
	["Weather Engine: Weather Update Called - Index: %1 || Last Sync: %2 || TickTime: %3 - #1110", _weatherRandomIndex, BP_Weather_SyncTime, diag_tickTime] call BP_fnc_debugConsoleFormat;

} else {
	["Weather Engine: Last Call Time: %1 #1110", (diag_tickTime - BP_Weather_SyncTime)] call BP_fnc_debugConsoleFormat;
};
*/