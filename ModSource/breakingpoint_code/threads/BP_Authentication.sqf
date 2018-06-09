/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_Authentication";

private ["_display","_controlBG","_control1","_control2","_cfgLoading","_loadingScreens","_loadingImg"];
disableSerialization;

_cfgLoading = configFile >> "CfgLoadingScreens" >> "World";
_loadingScreens = getArray (_cfgLoading >> worldName);
_loadingImg = selectRandom _loadingScreens;

BP_TimeOut = 0;
BP_loadScreenMsg = "";
BP_authed = false;
BP_PauseAuth = false;

["BP_Auth: Started Thread..."] call BP_fnc_debugConsoleFormat;

waitUntil {!(isNull (findDisplay 46))};

["BP_Auth: Started Loading Screen Guard."] call BP_fnc_debugConsoleFormat;

startLoadingScreen ["","BP_Loading_Login"];
_display = uiNameSpace getVariable "BP_loadingScreen";
if (!isNil "_display") then {
	_controlBG = _display displayCtrl 8399;
	_control1 = _display displayCtrl 8400;
	_control2 = _display displayCtrl 8401;
};

// 60 sec timeout (6000 * 0.01)
while { BP_TimeOut < 6000 } do {
	if (BP_clientPreload and BP_authed) exitWith { endLoadingScreen; ["BP_Auth: Exit Thread... Login Already Completed."] call BP_fnc_debugConsoleFormat; };

	if (BP_AuthTimer) exitWith { endLoadingScreen; ["BP_Auth: Exit Thread... Anti Ghost Timer"] call BP_fnc_debugConsoleFormat; };
	
	if (BP_PauseAuth) then {
		waitUntil {!BP_PauseAuth};
	};
	
	if (!isNil "_display") then {
		if ( isNull _display ) then {
			waitUntil { !dialog; };
			endLoadingScreen;
			startLoadingScreen ["","BP_Loading_Login"];
			_display = uiNameSpace getVariable "BP_loadingScreen";
			_controlBG = _display displayCtrl 8399;
			_control1 = _display displayCtrl 8400;
			_control2 = _display displayCtrl 8401;
		};

		if ( BP_loadScreenMsg != "" ) then {
			_control1 ctrlSetText BP_loadScreenMsg;
			BP_loadScreenMsg = "";
		};

		_controlBG ctrlSetText _loadingImg;
		_control2 ctrlSetText format["%1",round(BP_TimeOut*0.01)];
	};
	
	BP_TimeOut = BP_TimeOut + 1;

	if (BP_TimeOut >= 7500) then {
		endLoadingScreen;
		player enableSimulation false;
		BP_AuthTimer = true;
		0 cutRsc ["Default","PLAIN",0];
		1 cutRsc ["BP_AuthFailed","PLAIN"];
		sleep 10;
		disableUserInput false;
		endMission "END6";
	};

	sleep 0.01;
};