
class RscDisplayDebriefing : RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayDebriefing"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayDebriefing"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	statisticsLinks = 0;
	enableSimulation = 0;
	
	class ControlsBackground {
		delete Vignette;
		//class Vignette : RscVignette { idc = 114998; };
	};
	
	class controls {
		delete B_Continue;
		delete B_Restart;
		delete Title;
		delete MissionTitle;
		delete MissionResult;
		delete DebriefingInfo;
		delete DebriefingText;
		delete DebriefingObjectives;
		delete Right;
		delete Left;
		delete PlayersTitle;
		delete Players;
		delete MainTitle;
		delete PlayerName;
		delete Section;
		delete MainBackground;
		delete MissionPicture;
		delete Summary;
		delete DescriptionBackground;
		delete Description;
		delete DLCCountdown;
		delete DLCDebriefing;
		delete DLCStatistics;
		delete ObjectivesBackground;
		delete Objectives;
		delete StatBackground;
		delete Stat;
		delete Custom;		
		delete Data;
		delete Sides;
		delete ButtonOK;
		delete DLCBar;
		delete DLCGeneralGroup;
		class ButtonCancel : RscButtonMenuOK {
			idc = 2;
			text = "$STR_disp_continue";
			x = "33 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		delete ButtonSteamWorkshop;
	};
};