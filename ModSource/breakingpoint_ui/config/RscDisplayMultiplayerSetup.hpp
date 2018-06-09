
class RscDisplayMultiplayerSetup : RscStandardDisplay 
{
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	west = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
	east = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
	guer = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
	civl = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
	none = "#(argb,8,8,3)color(0,0,0,0)";
	westUnlocked = "A3\ui_f\data\map\diary\icons\playerWest_ca.paa";
	westLocked = "A3\ui_f\data\map\diary\icons\playerBriefWest_ca.paa";
	eastUnlocked = "A3\ui_f\data\map\diary\icons\playerEast_ca.paa";
	eastLocked = "A3\ui_f\data\map\diary\icons\playerBriefEast_ca.paa";
	guerUnlocked = "A3\ui_f\data\map\diary\icons\playerGuer_ca.paa";
	guerLocked = "A3\ui_f\data\map\diary\icons\playerBriefGuer_ca.paa";
	civlUnlocked = "A3\ui_f\data\map\diary\icons\playerCiv_ca.paa";
	civlLocked = "A3\ui_f\data\map\diary\icons\playerBriefCiv_ca.paa";
	disabledAllAI = $STR_DISP_MULTI_ENABLE_AI;
	enabledAllAI = $STR_DISP_MULTI_DISABLE_AI;
	hostLocked = $STR_DISP_MULTI_UNLOCK;
	hostUnlocked = $STR_DISP_MULTI_LOCK;
	colorNotAssigned[] = {1, 1, 1, 0.25};
	colorAssigned[] = {1, 1, 1, 1};
	colorConfirmed[] = {0, 1, 0, 1};
	
	class controlsbackground 
	{
		delete Vignette;
		delete TileGroup;
		
		class Background: RscPicture
		{
			idc = 1200;
			text = "\breakingpoint_ui\lobby\background.paa";
			x = -0.0341874 * safezoneW + safezoneX;
			y = -0.4504 * safezoneH + safezoneY;
			w = 1.0725 * safezoneW;
			h = 1.903 * safezoneH;
		};
		
		class Background_List1: RscPicture
		{
			idc = 1202;
			text = "\breakingpoint_ui\lobby\background_list1.paa";
			x = 0.0204688 * safezoneW + safezoneX;
			y = 0.148 * safezoneH + safezoneY;
			w = 0.232031 * safezoneW;
			h = 0.374 * safezoneH;
		};

		class Background_List2: RscPicture
		{
			idc = 1204;
			text = "\breakingpoint_ui\lobby\background_list2.paa";
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.363 * safezoneH;
		};
		
		class Button_Map: RscPicture
		{
			idc = 1201;
			text = "\breakingpoint_ui\lobby\button_map.paa";
			x = 0.0194375 * safezoneW + safezoneX;
			y = 0.0622 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class Button_Players: RscPicture
		{
			idc = 1203;
			text = "\breakingpoint_ui\lobby\button_players.paa";
			x = 0.0204687 * safezoneW + safezoneX;
			y = 0.1018 * safezoneH + safezoneY;
			w = 0.226875 * safezoneW;
			h = 0.033 * safezoneH;
		};

		delete RscTitleBackground;
		/*
		class RscTitleBackground : RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete MainBackground;
		/*
		class MainBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = 1081;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "SafezoneH - (4.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		*/
		
		delete MissionSettingsBackground;
		/*
		class MissionSettingsBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1082;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(29.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete NumOfPlayersBackground;
		/*
		class NumOfPlayersBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1083;
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "7.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete SideBackground;
		/*
		class SideBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1084;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		*/
		
		delete RolesBackground;
		/*
		class RolesBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1085;
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		*/
		
		delete ChatBackground;
		/*
		class ChatBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1086;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "17.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))+ 0.3*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		*/
		delete PlayersPoolHeaderBackground;
		delete PlayersPoolBackground;
		/*
		class PlayersPoolBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1087;
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		*/
	};
	
	class controls 
	{
		delete B_Civilian;
		delete B_Guerrila;
		delete B_East;
		delete B_West;
		delete B_Side;
		delete B_OK;
		delete B_Cancel;
		delete B_Kick;
		delete B_EnableAll;
		delete B_Lock;
		delete TextDescription;
		delete ValueDescription;
		delete TextMessage;
		delete ValueRoles;
		delete TextParam1;
		delete TextParam2;
		delete ValueParam1;
		delete ValueParam2;
		delete ValuePool;
		delete B_Params;
		delete TextPool;
		delete TextRoles;
		
		delete Title;
		/*
		class Title : RscTitle {
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1000;
			text = "$STR_A3_RscDisplayMultiplayerSetup_Title";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete PlayersName;
		/*
		class PlayersName : RscTitle {
			idc = 701;
			style = 1;
			shadow = false;
			x = "(SafezoneX) + (24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		class CA_TextVotingTimeLeft : RscTitle {
			idc = 121;
			style = 0;
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		delete ValueMission;
		/*
		class ValueMission : RscTitle {
			idc = 101;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			//w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			//x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		*/

		delete CA_TextDescription;
		/*
		class CA_TextDescription : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1004;
			text = $STR_DISP_SRVSETUP_DESC;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete CA_ValueDescription;
		/*
		class CA_ValueDescription : RscText {
			idc = 103;
			style = 0x10 + 0x200;
			linespacing = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			//w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			//x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		*/
		
		delete TextIsland;
		/*
		class TextIsland : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1006;
			text = $STR_DISP_SRVSETUP_ISLAND;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete TextSide;
		/*
		class TextSide : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1008;
			text = $STR_DISP_MPSETUP_SIDE;
			//x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorBackground[] = {0, 0, 0, 1};
		};
		*/
		
		class CA_B_West : RscActiveText {
			picture = "\A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_empty_ca.paa";
			text = $STR_WEST;
			idc = 104;
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
			sideDisabled = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_none_ca.paa";
			pictureHeight = 1;
			pictureWidth = 1;
			color[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])", "(profilenamespace getvariable ['Map_BLUFOR_G',1])", "(profilenamespace getvariable ['Map_BLUFOR_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])", "(profilenamespace getvariable ['Map_BLUFOR_G',1])", "(profilenamespace getvariable ['Map_BLUFOR_B',1])", 1};
			colorDisabled[] = {1, 1, 1, 0};
			colorShade[] = {1, 1, 1, 1};
			colorText[] = {1, 1, 1, 1};
			textHeight = 0.38;
			//x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_B_East : CA_B_West {
			text = $STR_EAST;
			idc = 105;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])", "(profilenamespace getvariable ['Map_OPFOR_G',1])", "(profilenamespace getvariable ['Map_OPFOR_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])", "(profilenamespace getvariable ['Map_OPFOR_G',1])", "(profilenamespace getvariable ['Map_OPFOR_B',1])", 1};
			//x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "8.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};

		class CA_B_Guerrila : CA_B_West {
			text = $STR_GUERRILA;
			idc = 106;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Independent_R',0])", "(profilenamespace getvariable ['Map_Independent_G',1])", "(profilenamespace getvariable ['Map_Independent_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Independent_R',0])", "(profilenamespace getvariable ['Map_Independent_G',1])", "(profilenamespace getvariable ['Map_Independent_B',1])", 1};
			//x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "10.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_B_Civilian : CA_B_West {
			text = $STR_CIVILIAN;
			idc = 107;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])", "(profilenamespace getvariable ['Map_Civilian_G',1])", "(profilenamespace getvariable ['Map_Civilian_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])", "(profilenamespace getvariable ['Map_Civilian_G',1])", "(profilenamespace getvariable ['Map_Civilian_B',1])", 1};
			//x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//y = "12.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		delete CA_ValueRoles;
		/*
		class CA_ValueRoles : RscListBox {
			idc = 109;
			colorPlayer[] = {1, 1, 0, 1};
			colorAI[] = {1, 0, 0, 1};
			colorNobody[] = {1, 1, 1, 0.25};
			enabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\enabledAI_ca.paa";
			disabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\disabledAI_ca.paa";
			//rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			rowHeight = 0;
			rows = 0;
			colorSelectBackground[] = {1, 1, 1, 0.3};
			colorSelectBackground2[] = {1, 1, 1, 0.3};
			//x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			//w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			//h = "(9.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			//y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		*/
		
		class CA_ValuePool : RscListNBox {
			idc = 114;
			canDrag = 1;
			rows = 25;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = 0.0266562 * safezoneW + safezoneX;
			y = 0.1546 * safezoneH + safezoneY;
			h = "SafezoneH - (9.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = 0.159844 * safezoneW;
			colorSelectBackground[] = {1, 1, 1, 0.3};
			colorSelectBackground2[] = {1, 1, 1, 0.3};
			colorPictureSelected[] = {1, 1, 1, 1};
			columns[] = {"0.0266562 * safezoneW + safezoneX"};
			
			//x = 0.0266562 * safezoneW + safezoneX;
			//y = 0.1546 * safezoneH + safezoneY;
			//h = 0.726 * safezoneH;

			class MuteCheckBoxTemplate : RscCheckBox {
				x = 0;
				y = 0;
				w = "0.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				textureChecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_ca.paa";
				textureUnchecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_crossed_ca.paa";
				textureFocusedChecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_ca.paa";
				textureFocusedUnchecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_crossed_ca.paa";
				textureHoverChecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_ca.paa";
				textureHoverUnchecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_crossed_ca.paa";
				texturePressedChecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_ca.paa";
				texturePressedUnchecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_crossed_ca.paa";
				textureDisabledChecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_ca.paa";
				textureDisabledUnchecked = "\A3\Ui_f\data\IGUI\RscIngameUI\RscDisplayChannel\MuteVON_crossed_ca.paa";
			};
		};

		class CA_B_EnableAll : RscButtonMenu {
			idc = 117;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			//x = "13.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			//y = "16.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			//w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_B_Lock : RscButtonMenu {
			idc = 118;
			//x = "safezoneX + SafezoneW - (13.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			//y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			//w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_B_Params : RscButtonMenu {
			idc = 128;
			shortcuts[] = {0x00050000 + 2};
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			//x = "(26.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = $STR_DISP_XBOX_EDITOR_WIZARD_PARAMS;
			//y = "4.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			//w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class ButtonSteamWorkshop : RscButtonMenuSteam {
			idc = 130;
			text = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop";
			tooltip = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop_tooltip";
			//x = "safezoneX + SafezoneW - (19.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			//y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			//w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_B_Kick : RscButtonMenu {
			idc = 116;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			//x = "safezoneX + SafezoneW - (7.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			//y = "SafezoneY + SafezoneH - (3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = $STR_DISP_MP_KICKOFF;
			//w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class CA_ButtonContinue : RscActiveText {
			idc=1;
			style = 48;
			default = 1;
			shortcuts[]={"0x00050000 + 0",28,57,156};
			text = "\breakingpoint_ui\lobby\button_ok.paa";
			x = 0.0276874 * safezoneW + safezoneX;
			y = 0.8872 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.033 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_ok_hover.paa'";
			onMouseExit = "(_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_ok.paa'";
			soundPush[]={"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",0.09,1};
			//onMouseButtonClick = "disableSerialization; _display = ctrlParent (_this select 0); _ctrl1 =_display displayCtrl 1; ctrlActivate _ctrl1;";
		};
		
		class ButtonCancel : RscActiveText {
			idc=4;
			style = 48;
			default = 0;
			shortcuts[]={"0x00050000 + 0",28,57,156};
			text = "\breakingpoint_ui\lobby\button_disconnect.paa";
			x = 0.0276874 * safezoneW + safezoneX;
			y = 0.9202 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.033 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_disconnect_hover.paa'";
			onMouseExit = "(_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_disconnect.paa'";
			soundPush[]={"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",0.09,1};
			onMouseButtonClick = "disableSerialization; _display = ctrlParent (_this select 0); _ctrl2 =_display displayCtrl 2; ctrlActivate _ctrl2;";
		};
		
		
		//class CA_ButtonContinue : RscButtonMenuOK {
		//	x = 0;
		//	y = 0;
		//	w = 0;
		//	h = 0;
		//};
		
		//Fake Disconnect Button - Activated by cool looking custom bp version
		//DO NOT REMOVE use internally in the engine idc = 2;
		class CA_ButtonCancel : RscButtonMenuCancel {
			default = 0;
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		/*
		class CA_ButtonCancel : RscActiveText {
			idc=2;
			shortcuts[]={"0x00050000 + 1"};
			style = 48;
			text = "\breakingpoint_ui\lobby\button_disconnect.paa";
			x = 0.0276874 * safezoneW + safezoneX;
			y = 0.9202 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.033 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_disconnect_hover.paa'";
			onMouseExit = "(_this select 0) ctrlSetText '\breakingpoint_ui\lobby\button_disconnect.paa'";
			soundPush[]={"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",0.09,1};
		};
		*/
		
		delete TextMission;
		/*
		class TextMission : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1002;
			text = $STR_DISP_SRVSETUP_NAME;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete TextRole;
		/*
		class TextRole : RscText {
			idc = 108;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = $STR_DISP_MPSETUP_ROLES_WEST;
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 1};
		};
		*/

		delete TextPlayersPool;
		/*
		class TextPlayersPool : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1011;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextPlayersPool";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 1};
		};
		*/
		
		delete TextListedPlayers;
		/*
		class TextListedPlayers : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1013;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextListedPlayers";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "5.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		class ValueIsland : RscText {
			idc = 102;
			text = "Altis";
			style = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = -0.01 * safezoneW + safezoneX;
			y = 0.0554 * safezoneH + safezoneY;
			w = 0.175313 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ValueListedPlayers : RscText {
			idc = 1015;
			text = "0";
			style = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = -0.1 * safezoneW + safezoneX;
			y = 0.0974 * safezoneH + safezoneY;
			w = 0.175313 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ButtonPlayers : RscButtonTextOnly {
			idc = 133;
			style = 0;
			sizeEx = "0";
			colorFocused[] = {1, 1, 1, 0};
			colorFocused2[] = {1, 1, 1, 0};
			period = 1.2;
			x = 0;
			w = 0;
			y = 0;
			h = 0;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextPlayersPool";
		};
		
		//delete ButtonPlayers;
		delete SortPlayers;
		delete ButtonPing;
		delete SortPing;
		delete MuteAll;
		
	};
};
