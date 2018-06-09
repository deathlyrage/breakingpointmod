class RscDisplayMultiplayer : RscStandardDisplay 
{
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayer"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayMultiplayer"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	sortUp = "\A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\arrow_up_ca.paa";
	sortDown = "\A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\arrow_down_ca.paa";
	showPassworded = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\showPassworded_ca.paa";
	hidePassworded = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hidePassworded_ca.paa";
	showBattlEye = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\showBattlEye_ca.paa";
	showNoBattlEye = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\showNoBattlEye_ca.paa";
	hideBattlEye = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hideBattleEye_ca.paa";
	showFull = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\showFull_ca.paa";
	hideFull = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hideFull_ca.paa";
	showExpansions = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\showExpansions_ca.paa";
	hideExpansions = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hideExpansions_ca.paa";
	colorPingUnknown[] = {0.4, 0.4, 0.4, 1};
	colorPingGood[] = {0, 1, 0, 1};
	colorPingPoor[] = {1, 0.6, 0, 1};
	colorPingBad[] = {1, 0, 0, 1};
	colorVersionGood[] = {1, 1, 1, 1.0};
	colorVersionBad[] = {1, 0, 0, 1};
	
	class controlsbackground 
	{
		delete MainbackTop;
		delete MainbackBottom;
		delete MainbackMiddle;
		delete CA_ServerDetailLanguage;
		delete CA_ServerDetailMission;
		delete CA_ServerDetailPing;
		delete CA_ServerDetailSlots;
		delete CA_ServerDetailState;
		delete CA_TextDetailState;
		delete CA_TextServerDetailLanguage;
		delete CA_TextServerDetailPing;
		delete CA_TextServerDetailSlots;
		
		delete Vignette;
		delete TileGroup;
		
		class LoadingStart : RscPicture {
			idc = 2310;
			text = "\breakingpoint_ui\loading\main_title_01.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
		
		class RscTitleBackground : RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class MainBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = 1081;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "SafezoneW - (2 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "SafezoneH - (4.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		
		class HeadersBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.6};
			idc = 1082;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "safezoneY + (3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "SafezoneW - (2.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	
	class controls {
		delete Title;
		delete ValueSessions;
		delete ColumnPlayers;
		delete ColumnPing;
		delete ColumnType;
		delete ColumnMission;
		delete ColumnState;
		delete ColumnServer;
		delete FilterPlayers;
		delete FilterPing;
		delete FilterMission;
		delete FilterType;
		delete FilterServer;
		delete ServerDetailType;
		delete ServerDetailMission;
		delete ServerDetailState;
		delete ServerDetailSlots;
		delete ServerDetailPing;
		delete ServerDetailLanguage;
		delete ServerDetailCountry;
		delete ServerDetailVersion;
		delete ServerDetailVersionRequired;
		delete ServerDetailMods;
		delete ServerDetailIsland;
		delete ServerDetailDifficulty;
		delete ServerDetailTimeLeft;
		delete ServerDetailPlatform;
		delete ServerDetailPlayers;
		delete ServerDetailPassword;
		delete ServerDetailHost;
		delete FilterBattlEyeServers;
		delete FilterPasswordedServers;
		delete FilterFullServers;
		delete IconPlayers;
		delete IconPing;
		delete IconType;
		delete IconState;
		delete IconMission;
		delete IconServer;
		delete B_DPlay;
		delete B_Internet;
		delete B_Remote;
		delete B_Password;
		delete B_Refresh;
		delete B_Filter;
		delete B_Port;
		delete Progress;
		delete B_Join;
		delete B_New;
		delete B_Cancel;
		
		class CA_FramePlayers : RscFrame {
			x = "safezoneX + (13.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			w = "(12.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1801;
			text = $STR_DISP_MP_PLAYERS;
			h = "7.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FrameExpansions : RscFrame {
			x = "safezoneX + (26.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.666*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			w = "(12.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1802;
			text = $STR_DISP_MP_EXPANSIONS;
			h = "7.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FrameMission : RscFrame {
			w = "(12.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1803;
			text = $STR_SECTION_MISSION;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "7.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailPassword : RscPicture {
			idc = 143;
			y = "16.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailHost : RscText {
			idc = 129;
			shadow = true;
			w = "(11 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailIsland : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = true;
			y = "16.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1019;
			text = $STR_DISP_XBOX_MULTI_ISLAND;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailIsland : RscText {
			idc = 132;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = true;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "16.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailDifficulty : CA_TextServerDetailIsland {
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1021;
			text = $STR_CA_DIFFICULTY;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailDifficulty : CA_ServerDetailIsland {
			idc = 138;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailPlatform : CA_TextServerDetailIsland {
			y = "18.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1014;
			text = $STR_DISP_ARCEFF_TITTYPE;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailPlatform : CA_ServerDetailIsland {
			idc = 130;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "18.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailountry : CA_TextServerDetailIsland {
			y = "18.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1012;
			text = $STR_DISP_MULTI_COUNTRY;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailCountry : CA_ServerDetailIsland {
			idc = 145;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "18.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailBE : CA_TextServerDetailIsland {
			y = "19.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1010;
			text = $STR_FILTER_BATTLEYE_TEXT;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailBE : CA_ServerDetailIsland {
			idc = 201;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "19.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextServerDetailTimeLeft : CA_TextServerDetailIsland {
			y = "20.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1017;
			text = $STRWFMISSIONENDTIME;
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailTimeLeft : CA_ServerDetailIsland {
			idc = 134;
			w = "(4.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.3*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "20.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class TextServerType : CA_TextServerDetailIsland {
			y = "21 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			idc = 1007;
			text = "$STR_A3_RscDisplayMultiplayer_TextServerType";
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailVersion : CA_ServerDetailIsland {
			idc = 144;
			y = "21 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "8.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailVersionRequired : CA_ServerDetailIsland {
			idc = 147;
			y = "21.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			x = "1.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailExpansion : CA_ServerDetailIsland {
			idc = 148;
			style = 0x00 + 0x10 + 0x200;
			linespacing = 1;
			x = "safezoneX + (26.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.666*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			w = "(12.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h = "6.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerDetailPlayers : CA_ServerDetailIsland {
			idc = 149;
			style = 0x00 + 0x10 + 0x200;
			linespacing = 1;
			x = "safezoneX + (13.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			w = "(12.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.333*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "15.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h = "6.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_Cancel : RscButtonMenuCancel {
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_Internet_Lan : CA_Cancel {
			idc = 122;
			shortcuts[] = {};
			x = "safezoneX + SafezoneW - (10.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "safezoneY + (2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "9.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		delete CA_New;
		//class CA_New : CA_Cancel {
		//	idc = 104;
		//	shortcuts[] = {0x00050000 + 2};
		//	y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		//	text = $STR_CA_MULTI_NEW;
		//	x = "7.35 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
		//	w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		//	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		//};
		
		class CA_Refresh : CA_Cancel {
			idc = 123;
			shortcuts[] = {0x00050000 + 3, 63};
			x = "safezoneX + SafezoneW - (7.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "14.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = $STR_DISP_MULTI_REFRESH;
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_Join : RscButtonMenuOK {
			idc = 105;
			x = "safezoneX + SafezoneW - (7.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = $STR_CA_MULTI_JOIN;
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_BFilter : CA_Cancel {
			idc = 124;
			shortcuts[] = {};
			y = "14.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = $STR_DISP_MULTI_FILTER;
			x = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_BRemote : CA_Cancel {
			idc = 103;
			shortcuts[] = {};
			x = "safezoneX + SafezoneW - (13.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = $STR_CA_MULTI_REMOTE;
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_Title2 : RscTitle {
			idc = 101;
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerCount : RscText {
			idc = 159;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class PlayersName : RscTitle {
			style = 1;
			shadow = false;
			x = "safezoneX + (21.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(17.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1008;
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FilterPasswordedServers : RscPicture {
			idc = 150;
			y = "14.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hidePassworded_ca.paa";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FilterFullServers : CA_FilterPasswordedServers {
			idc = 151;
			y = "14.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hidefull_ca.paa";
			x = "2.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerBEFilter : CA_FilterPasswordedServers {
			idc = 154;
			y = "14.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hidebattleeye_ca.paa";
			x = "3.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerExpansionsFilter : CA_FilterPasswordedServers {
			idc = 155;
			y = "14.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			text = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\hideexpansions_ca.paa";
			x = "4.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FavoriteColumn : RscShortcutButton {
			idc = 156;
			type = 16;
			style = 0;
			shadow = false;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			colorBackground2[] = {1, 1, 1, 0.5};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureOver = "#(argb,8,8,3)color(1,1,1,0.5)";
			animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
			animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
			
			class TextPos {
				left = 0;
				top = 0.003;
				right = 0.0;
				bottom = 0.0;
			};
			y = "safezoneY + (3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "<img image='A3\Ui_f\data\GUI\Rsc\RscDisplayMultiplayer\favouriteColumnTitle_ca.paa'>";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 0.8};
		};
		
		class CA_ServerColumn : RscButtonTextOnly {
			idc = 112;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			style = 0;
			colorFocused[] = {1, 1, 1, 0.5};
			colorFocused2[] = {1, 1, 1, 0.1};
			period = 1.2;
			y = "safezoneY + (3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_MP_SERVER;
			x = "2.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TypeColumn : CA_ServerColumn {
			idc = 141;
			x = "safezoneX + (15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_DISP_ARCSENS_TYPE;
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_MissionColumn : CA_ServerColumn {
			idc = 114;
			x = "safezoneX + (18.3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			w = "(10.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_SECTION_MISSION;
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_StateColumn : CA_ServerColumn {
			idc = 116;
			x = "safezoneX + (29.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_MENU_STATUS;
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_PlayersColumn : CA_ServerColumn {
			idc = 118;
			x = "safezoneX + (32.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_MP_PLAYERS;
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_PingColumn : CA_ServerColumn {
			idc = 120;
			x = "safezoneX + (35.7 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = $STR_DISP_MULTI_PING;
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_FavoriteIcon : RscPicture {
			idc = 157;
			y = "safezoneY + (3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ServerIcon : RscPicture {
			idc = 111;
			x = "safezoneX + (13.7 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			y = "safezoneY + (3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TypeIcon : CA_ServerIcon {
			idc = 140;
			x = "safezoneX + (17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_MissionIcon : CA_ServerIcon {
			idc = 113;
			x = "safezoneX + (27.8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_StateIcon : CA_ServerIcon {
			idc = 115;
			x = "safezoneX + (31.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_PlayersIcon : CA_ServerIcon {
			idc = 117;
			x = "safezoneX + (34.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_PingIcon : CA_ServerIcon {
			idc = 119;
			x = "safezoneX + (37.7 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ValueSessions : RscListBox {
			idc = 102;
			style = 16;
			colorPingUnknown[] = {0.4, 0.4, 0.4, 1};
			colorSelect[] = {0, 0, 0, 1};
			colorPingGood[] = {0, 1, 0, 1};
			colorPingPoor[] = {1, 0.6, 0, 1};
			colorPingBad[] = {1, 0, 0, 1};
			password = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_password_ca.paa";
			locked = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_locked_ca.paa";
			version = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_version_ca.paa";
			none = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_none_ca.paa";
			star = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_star_ca.paa";
			addons = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_addons_ca.paa";
			mods = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\sessions_mods_ca.paa";
			serverLike = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\mp_serverlike_ca.paa";
			serverDislike = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\mp_serverdislike_ca.paa";
			serverEmpty = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayer\mp_serverempty_ca.paa";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "safezoneY + (4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "SafezoneW - (2.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "SafezoneH - (15.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			
			class Columns {
				class ColumnFavorite {
					x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
					w = "(2 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
				};
				
				class ColumnServer {
					x = "2.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
					w = "(11 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
				};
				
				class ColumnType {
					x = "safezoneX + (15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
					w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				};
				
				class ColumnMission {
					x = "safezoneX + (18.3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
					w = "(10.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
				};
				
				class ColumnState {
					x = "safezoneX + (29.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
					w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				};
				
				class ColumnPlayers {
					x = "safezoneX + (32.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
					w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				};
				
				class ColumnPing {
					x = "safezoneX + (35.7 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.9*(safezoneW - 			((safezoneW / safezoneH) min 1.2))";
					w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				};
			};
		};
	};
};
