/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

scriptName "BPServer_fnc_weatherChange";

private "_passedWeatherIndex";

// Arg Passed Index Int (ceil)
_passedWeatherIndex = _this;

if (BP_Weather_Current == BP_Weather_None) then
{
	["Weather Engine: No Weather - Calling Random Weather #1110"] call BP_fnc_debugConsoleFormat;
	BP_Weather_Current = BP_Weather_Default;
	_passedWeatherIndex call BPServer_fnc_weatherChange;

} else {
	private ["_weatherRainFloat","_weatherOvercastFloat","_weatherWindDirection","_weatherWindVolFloat", "_weatherPropertieArray"];


	_weatherRainFloat = random 1;
	_weatherOvercastFloat = random 1;
	_weatherWindDirection = floor(random 359);
	_weatherWindVolFloat = random 1;

	if (_weatherOvercastFloat <= 0.5) then {
	 	_weatherRainFloat = 0;
	};

	switch (_passedWeatherIndex) do 
	{
		case 0:
		{
			["Weather Engine: Sunny #1110"] call BP_fnc_debugConsoleFormat;
			
			if (worldName == "Bornholm") then {
				1 setOvercast 0.4;
			} else {
				1 setOvercast 0;
			};
			6200 setLightnings 0;
			6300 setRain 0;
			6300 setFog 0;
			6100 setGusts 0.1;
			6100 setWindDir _weatherWindDirection;
			
			_wind = floor(random 100);
			if (_wind > 50) then {
				6100 setWindStr (random 0.1);
			} else {
				6100 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	

		};

		case 1:
		{
			["Weather Engine: Summer Shower #1110"] call BP_fnc_debugConsoleFormat;

			1 setOvercast 0.5;
			6200 setRain 0.3;
			6200 setFog 0;
			6100 setGusts 0.3;
			6100 setWindDir _weatherWindDirection;
			
			_wind = floor(random 100);
			if (_wind > 50) then {
				6100 setWindStr (random 0.3);
			} else {
				6100 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	
		};

		case 2:
		{
			["Weather Engine: Medium Overcast #1110"] call BP_fnc_debugConsoleFormat;

			1 setOvercast 0.8;
			6200 setFog [0.7, 0.04, 5];
			5800 setGusts 0.4;
			5800 setWindDir _weatherWindDirection;
			
			_wind = floor(random 100);
			if (_wind > 50) then {
				5800 setWindStr (random 0.4);
			} else {
				5800 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	
		};

		case 3:
		{
			["Weather Engine: Heavy Storm #1110"] call BP_fnc_debugConsoleFormat;

			1 setOvercast 1;
			6200 setRain 1;
			6000 setLightnings 1;
			6000 setFog [0.7, 0.03, 2];
			5600 setGusts 1;
			5600 setWindDir _weatherWindDirection;
			5600 setWindStr 1;

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	
		};

		case 4:
		{
			["Weather Engine: Random Weather #1110"] call BP_fnc_debugConsoleFormat;
			
			if (worldName == "Bornholm") then {
				if (_weatherOvercastFloat < 0.4) then { _weatherOvercastFloat = 0.4; };
			};

			1 setOvercast _weatherOvercastFloat;
			6200 setRain _weatherRainFloat;
			6200 setFog 0;
			//5700 setFog [_weatherFogFloat, _weatherFogDensity, _weatherFogHeight];
			6100 setLightnings _weatherRainFloat;
			5100 setGusts _weatherWindVolFloat;
			5100 setWindDir _weatherWindDirection;

			_wind = floor(random 100);
			if (_wind > 50) then {
				5100 setWindStr _weatherWindVolFloat;
			} else {
				5100 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	
		};

		case 5:
		{
			["Weather Engine: Random Weather #1110"] call BP_fnc_debugConsoleFormat;

			1 setOvercast _weatherOvercastFloat;
			6300 setRain _weatherRainFloat;
			6300 setFog 0;
			//5700 setFog [_weatherFogFloat, _weatherFogDensity, _weatherFogHeight];
			6200 setLightnings _weatherRainFloat;
			5400 setGusts _weatherWindVolFloat;
			5400 setWindDir _weatherWindDirection;
			
			_wind = floor(random 100);
			if (_wind > 50) then {
				5400 setWindStr _weatherWindVolFloat;
			} else {
				5400 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	
		};

		case 6:
		{
			["Weather Engine: |NIGHT| Random Weather #1110"] call BP_fnc_debugConsoleFormat;

			1 setOvercast 0;
			6200 setRain _weatherRainFloat;
			6200 setFog 0;
			//5700 setFog [_weatherFogFloat, _weatherFogDensity, _weatherFogHeight];
			6100 setLightnings _weatherRainFloat;
			5500 setGusts _weatherWindVolFloat;
			5500 setWindDir _weatherWindDirection;
			
			_wind = floor(random 100);
			if (_wind > 50) then {
				5500 setWindStr _weatherWindVolFloat;
			} else {
				5500 setWindStr 0;
			};

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	

		};

		case 7:
		{
			["Weather Engine: Random Fog #1110"] call BP_fnc_debugConsoleFormat;
			
			_fogs = 
			[
				[0.8, 0.04, 0],
				[1, 0.04, 4],
				[1, 0.01, 10],
				[0.1, 0.01, 10],
				[0.2, 0.01, 10],
				[0.3, 0.01, 10],
				[0.4, 0.01, 10],
				[0.5, 0.01, 10],
				[0.5, 0.01, 25],
				[0.5, 0.1, 35]
			];
			
			_fog = selectRandom _fogs;

			5700 setFog _fog;

			0 = [] spawn {
				sleep 0.1;
				simulWeatherSync;
			};	

		};
		
		default
		{
			["Weather Engine: Useless Index Called :: Skipped :: Keeping Current Weather #1110"] call BP_fnc_debugConsoleFormat;
 		};
	}; 
};


/*
private ["_transitionTime"];

_transitionTime = 120;

//Adjust Transition Time to 0 If Server Startup
if (BP_Weather_Current == BP_Weather_None) then { _transitionTime = 0; };

//If the weather is the same, don't change it
if (BP_Weather_Current == _this) exitWith { ["weatherChange: Skipping Weather Change. New Weather is same as current."] call BP_fnc_debugConsoleFormat; };

//Update Last Weather and Sync Time
BP_Weather_Current = _this;
BP_WeatherLastSync = diag_tickTime;

//Change Weather
switch (_this) do  {
	case BP_Weather_Sunny:  {
		0 = [_transitionTime] spawn 
		{
			_transitionTime = (_this select 0);
			
			["weatherChange: Weather is now Sunny."] call BP_fnc_debugConsoleFormat;
			
			//Reverse Time Back By 30 Minutes
			if (_transitionTime == 0) then { skipTime -0.5; };
			
			//Minor Delay to allow weather to update
			sleep 0.1;

			//Overcast ( 0% )
			[_transitionTime,0] call BPServer_fnc_weatherOvercast;
			
			//Minor Delay to allow weather to update
			sleep 0.1;
			
			//Increase Time Foward By 30 Minutes
			if (_transitionTime == 0) then { skipTime 0.5; };
			
			//Force Simulation Weather Sync
			simulWeatherSync; 
		};
	};
	
	case BP_Weather_Overcast:  {
		0 = [_transitionTime] spawn {
			//Log
			["weatherChange: Weather is now Overcast."] call BP_fnc_debugConsoleFormat;
		
			//Overcast ( 60 % )
			[(_this select 0),0.6] call BPServer_fnc_weatherOvercast;
			
			//Minor Delay to allow weather to update
			sleep 0.1; 
			
			//Force Simulation Weather Sync
			simulWeatherSync; 
		};
	};
	
	case BP_Weather_Rain:  {
		0 = [_transitionTime] spawn {
			//Log
			["weatherChange: Weather is now Rain."] call BP_fnc_debugConsoleFormat;
		
			//Overcast ( 85% )
			[(_this select 0),0.85] call BPServer_fnc_weatherOvercast;
			
			//Minor Delay to allow weather to update
			sleep 0.1; 
		
			//Rain ( 50% )
			[((_this select 0) + 5),0.5] call BPServer_fnc_weatherRain;
			
			//Minor Delay to allow weather to update
			sleep 0.1; 
			
			//Force Simulation Weather Sync
			simulWeatherSync; 
		};
	};
	
	case BP_Weather_Storm:  {
		0 = [_transitionTime] spawn {
			//Log
			["weatherChange: Weather is now Storm"] call BP_fnc_debugConsoleFormat;
		
			//Overcast ( 100% )
			[(_this select 0),1] call BPServer_fnc_weatherOvercast;
			
			//Minor Delay to allow weather to update
			sleep 0.1; 

			//Rain ( 100% )
			[((_this select 0) + 5),1] call BPServer_fnc_weatherRain;
			
			//Minor Delay to allow weather to update
			sleep 0.1;
			
			//Force Simulation Weather Sync
			simulWeatherSync;
		};
	};
	
	case BP_Weather_Fog:  {
		0 = [_transitionTime] spawn {
			//Log
			["weatherChange: Weather is now Fog and Moon"] call BP_fnc_debugConsoleFormat;
		
			//Overcast ( 0% )
			[60,0] call BPServer_fnc_weatherOvercast;
			
			//Wait Until Overcast is 0%
			sleep 60;  //waitUntil {overcast < 0.1};

			//Fog
			[60,0.25,0.03,100] call BPServer_fnc_weatherFog;
			
			//Minor Delay to allow weather to update
			sleep 0.1;
			
			//Force Simulation Weather Sync
			simulWeatherSync;
		};
	};
	
	case BP_Weather_Moon:  {
		0 = [_transitionTime] spawn {
			//Log
			["weatherChange: Weather is now Moon"] call BP_fnc_debugConsoleFormat;
		
			//Overcast ( 0% )
			[60,0] call BPServer_fnc_weatherOvercast;
			
			//Minor Delay to allow weather to update
			sleep 0.1;
			
			//Force Simulation Weather Sync
			simulWeatherSync;
		};
	};

	default 
	{
		["weatherChange: Error: Attempted to set Weather to Undefined Type ID %1.",_this] call BP_fnc_debugConsoleFormat;
	};
};

*/