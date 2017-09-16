#include "\A3\ui_f\hpp\defineCommonGrids.inc"

disableSerialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	//--- Display load
	case "onLoad": {
		private ["_display","_ehCode","_ehMoving","_ehHolding"];

		//--- Color Init
		_display = _params select 0;
		_ehKeyDown = _display displayaddeventhandler ["keydown","with uinamespace do {['keyDown',_this,''] call RscDisplayMain_script;};"];
		
		//--- Hide player's name if Stream Friendly UI is on. It is shown via RscDisplayGameOptions.sqf
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//--- Assign default values
		//with uinamespace do {

		//	//--- Get colors and grids
		//	true call bis_fnc_displayColorGet;
		//	false call bis_fnc_guiGridToProfile;

		//	//--- Apply colors to main menu
		//	[configfile >> _class,_display] call bis_fnc_displayColorSet;
		//};
		
		//IDC_MAIN_CAMPAIGN 	      143
		//IDC_SP_MISSION              103
		//IDC_MAIN_MULTIPLAYER        105
	};
	
	/*  //IDCs info
	IDC_MAIN_SINGLEPLAYER       138
	IDC_SP_EDITOR 		    142 //IDC_MAIN_EDITOR 115 - this is 3D editor
	Profile              idc = 1001	//scripted
	IDC_MAIN_OPTIONS            102
	IDC_MAIN_MOD_LAUNCHER       140
	Credits		            none //scripted
	IDC_MAIN_CUSTOM             104  //All Missions - CONFLICT
	*/

	//--- Display onload
	case "onUnload": {

	};

	//--- Display onload
	case "keyDown":
	{
		_display = _params select 0;
		_key = _params select 1;
		_shift = _params select 2;
		_ctrlKey = _params select 3;
		_alt = _params select 4;
		
		// if( getNumber(configfile >> "isDemo") == 1 ) then
		// {
			// if (_ctrlKey && _shift && _alt) then {
			
				// if (_key == 0x18) then 						//CTRL + SHIFT + ALT + O (as Options) was pressed
				// {	
					// //invert the cheat value
					// uiNamespace setVariable ["BIS_isCheatOptions", !(uiNamespace getvariable "BIS_isCheatOptions")];
					
					// // NO NEED TO DO THIS FOR DEMO news:k1kt08$97g$1@new-server.localdomain
					// //Enable/disable buttons according the new cheat, but only when accordeon is expanded.
					// // if(ctrlFade (_display displayCtrl 301) < 0.5) then
					// if(uiNamespace getvariable "BIS_MainMenu_isOptionsExpanded") then
					// {
						// _isCheat = uiNamespace getvariable "BIS_isCheatOptions";
						// // (_display displayctrl 301) ctrlEnable _isCheat;	//Video
						// // (_display displayctrl 302) ctrlEnable _isCheat;	//Audio
						// // (_display displayctrl 307) ctrlEnable _isCheat;	//Game Options
						// (_display displayctrl 1001) ctrlEnable _isCheat;	//Profile
						// (_display displayctrl 140) ctrlEnable _isCheat;		//Expansions
					// };

					// // if(ctrlEnabled (_display displayCtrl 301)) then 	//Video enabled, disable Video, Audio, Game
					// // {
						// // (_display displayctrl 301) ctrlEnable false;	//Video
						// // (_display displayctrl 302) ctrlEnable false;	//Audio
						// // (_display displayctrl 307) ctrlEnable false;	//Game Options
					// // }
					// // else
					// // {
						// // (_display displayctrl 301) ctrlEnable true;	//Video
						// // (_display displayctrl 302) ctrlEnable true;	//Audio
						// // (_display displayctrl 307) ctrlEnable true;	//Game Options
					// //};
				// };
			// };
			
			// if (_ctrlKey && _alt && (_key == 0x2E)) then
			// {		
				// //Invert the cheat value
				// uiNamespace setVariable ["BIS_isCheatC", !(uiNamespace getvariable "BIS_isCheatC")];
				
				// _campaignButton = _display displayctrl 101;
				
				// if(uiNamespace getvariable "BIS_isCheatC") then
				// {
					// //if cheat is active
					// _campaignButton ctrlSetText "Presentation";
					// _campaignButton ctrlSetTooltip "Start or continue the presentation.";
				// }
				// else
				// {
					// //if cheat is not active
					// _campaignButton ctrlSetText "Campaign";
					// _campaignButton ctrlSetTooltip "Start or continue the campaign.";
				// };
				
				// //If Play is expanded, collapse it and then expand it again
				// if(uiNamespace getvariable "BIS_MainMenu_isPlayExpanded") then
				// {	
					// ['playButton', [_display displayctrl 138], ''] call RscDisplayMain_script; //simulate click on Play button (collapse)
					// ['playButton', [_display displayctrl 138], ''] call RscDisplayMain_script; //simulate click on Play button (expand)
				// };
			// };
			
			//E3 cheat, E-key
			// if (_ctrlKey && _alt && (_key == 0x12)) then
			// {
				// //Invert the cheat value
				// profileNamespace setVariable ["BIS_E3", !(profileNamespace getvariable ["BIS_E3", false])];
				// saveProfileNamespace;
				
				// if(profileNamespace getvariable "BIS_E3") then
				// {
					// //disable buttons
					// (_display displayctrl 105) ctrlEnable false;	//Multiplayer
					// (_display displayctrl 106) ctrlEnable false;	//Exit
					
					// //If Options are expanded, collapse them and disable the button
					// if(uiNamespace getvariable "BIS_MainMenu_isOptionsExpanded") then
					// {	
						// ['optionsButton', [_display displayctrl 102], ''] call RscDisplayMain_script; //simulate click on Options button (collapse)
					// };
					
					// (_display displayctrl 102) ctrlEnable false;	//Options
				// }
				// else
				// {
					// //enable buttons
					// (_display displayctrl 105) ctrlEnable true;	//Multiplayer
					// (_display displayctrl 102) ctrlEnable true;	//Options
					// (_display displayctrl 106) ctrlEnable true;	//Exit
				// };
			// };
		//};
		
	};

	//--- Nothing
	default {};
};