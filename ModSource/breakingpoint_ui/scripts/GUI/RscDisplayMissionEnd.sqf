#include "\A3\ui_f\hpp\defineCommonGrids.inc"
#include "\A3\ui_f\hpp\defineResincl.inc"
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;
		
		//if( getNumber(configfile >> "isDemo") != 1 ) then //test
		//{
			//--- E3 - Back to Hub button
			if (getnumber (missionconfigfile >> "replaceAbortButton") > 0) then
			{
				//Maxwell button ON - move all buttons except Abort up ---------------------------------------
				//Title background
				_control = _display displayctrl 1050;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];																												
				_control ctrlCommit 0;
				
				//Title - same position as title background
				_control = _display displayctrl 523;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Player's name - same position as title background
				_control = _display displayctrl 109;
				_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Restart/Revert
				_control = _display displayctrl 104;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (17.5 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				
				//Team Switch
				_control = _display displayctrl 107;
				_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (18.6 * GUI_GRID_H + GUI_GRID_Y)];																													
				_control ctrlCommit 0;
				//Maxwell button ON - move all buttons except Abort up ---------------------------------------
				
				//Enable Maxwell button
				_buttonBack = _display displayctrl 2403;
				_buttonBack ctrlenable true;
				_buttonBack ctrlsetfade 0;
				_buttonBack ctrlcommit 0;	
			}
			else
			{
				_buttonBack = _display displayctrl 2403;
				_buttonBack ctrlenable false;
				_buttonBack ctrlsetfade 1;
				_buttonBack ctrlcommit 0;
			};
		//};
		
		_control = _display displayctrl 2; //Abort/Suspend button (text is changed from code according to enabled/disabled save)
		if (str campaignConfigFile == "") then
		{
			//non campaign mission
			_control ctrlSetTooltip (localize "STR_TOOLTIP_MAIN_ABORT");
		}
		else
		{
			//campaign mission
			_control ctrlSetTooltip (localize "STR_TOOLTIP_MAIN_ABORT_CAMPAIGN");
		};
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Sets all texts toUpper
		["RscDisplayMissionEnd",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;

		//--- Disable load and team switch buttons in multiplayer
		if (ismultiplayer) then {
			{
				_control = _display displayctrl _x;
				_control ctrlenable false;
			} foreach [IDC_ME_TEAM_SWITCH,IDC_ME_RETRY];
		};
	};
};