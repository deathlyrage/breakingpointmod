
class RscDisplayMultiplayerSetup : RscStandardDisplay 
{
	scriptName = "RscDisplayMultiplayerSetup";
	scriptPath = GUI;
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	west = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
	east = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
	guer = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
	civl = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
	logic = "flag_logic";
	none = "#(argb,8,8,3)color(0,0,0,0)";
	westUnlocked = "a3\ui_f\data\map\diary\icons\playerwest_ca.paa";
	westLocked = "a3\ui_f\data\map\diary\icons\playerbriefwest_ca.paa";
	eastUnlocked = "a3\ui_f\data\map\diary\icons\playereast_ca.paa";
	eastLocked = "a3\ui_f\data\map\diary\icons\playerbriefeast_ca.paa";
	guerUnlocked = "a3\ui_f\data\map\diary\icons\playerguer_ca.paa";
	guerLocked = "a3\ui_f\data\map\diary\icons\playerbriefguer_ca.paa";
	civlUnlocked = "a3\ui_f\data\map\diary\icons\playerciv_ca.paa";
	civlLocked = "a3\ui_f\data\map\diary\icons\playerbriefciv_ca.paa";
	virtUnlocked = "a3\ui_f\data\map\diary\icons\playervirtual_ca.paa";
	virtLocked = "a3\ui_f\data\map\diary\icons\playerbriefvirtual_ca.paa";
	logicUnlocked = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\logicunlocked_ca.paa";
	logicLocked = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\logiclocked_ca.paa";
	sortUp = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_up_ca.paa";
	sortDown = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_down_ca.paa";
	disabledAllAI = $STR_DISP_MULTI_ENABLE_AI;
	enabledAllAI = $STR_DISP_MULTI_DISABLE_AI;
	hostLocked = $STR_DISP_MULTI_UNLOCK;
	hostUnlocked = $STR_DISP_MULTI_LOCK;
	colorNotAssigned[] = {1, 1, 1, 0.25};
	colorAssigned[] = {1, 1, 1, 1};
	colorConfirmed[] = {0, 1, 0, 1};
	
	class controlsbackground {
		class Vignette : RscVignette {
			idc = 114998;
		};
		
		class TileGroup : RscControlsGroupNoScrollbars {
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			
			class Controls {
				class TileFrame : RscFrame {
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0, 0, 0, 1};
				};
				
				class Tile_0_0 : RscText {
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_1 : RscText {
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_2 : RscText {
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_3 : RscText {
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_4 : RscText {
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_5 : RscText {
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_0 : RscText {
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_1 : RscText {
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_2 : RscText {
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_3 : RscText {
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_4 : RscText {
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_5 : RscText {
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_0 : RscText {
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_1 : RscText {
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_2 : RscText {
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_3 : RscText {
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_4 : RscText {
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_5 : RscText {
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_0 : RscText {
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_1 : RscText {
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_2 : RscText {
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_3 : RscText {
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_4 : RscText {
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_5 : RscText {
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_0 : RscText {
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_1 : RscText {
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_2 : RscText {
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_3 : RscText {
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_4 : RscText {
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_5 : RscText {
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_0 : RscText {
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_1 : RscText {
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_2 : RscText {
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_3 : RscText {
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_4 : RscText {
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_5 : RscText {
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
			};
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
		
		class MissionSettingsBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1082;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(29.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class NumOfPlayersBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1083;
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "7.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class SideBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1084;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		
		class RolesBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1085;
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		
		class ChatBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1086;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "17.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))+ 0.3*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		
		class PlayersPoolBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1087;
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
	
	class controls {
		class B_Civilian {};
		class B_Guerrila {};
		class B_East {};
		class B_West {};
		class B_Side {};
		class B_OK {};
		class B_Cancel {};
		class B_Kick {};
		class B_EnableAll {};
		class B_Lock {};
		class TextDescription {};
		class ValueDescription {};
		class TextMessage {};
		class ValueRoles {};
		class TextParam1 {};
		class TextParam2 {};
		class ValueParam1 {};
		class ValueParam2 {};
		class ValuePool {};
		class B_Params {};
		class TextPool {};
		class TextRoles {};
		
		class Title : RscTitle {
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1000;
			text = "$STR_A3_RscDisplayMultiplayerSetup_Title";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class PlayersName : RscTitle {
			idc = 701;
			style = 1;
			shadow = false;
			x = "(SafezoneX) + (24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextVotingTimeLeft : RscTitle {
			idc = 121;
			style = 0;
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ValueMission : RscTitle {
			idc = 101;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_TextDescription : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1004;
			text = $STR_DISP_SRVSETUP_DESC;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ValueDescription : RscText {
			idc = 103;
			style = 0x10 + 0x200;
			linespacing = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class TextIsland : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1006;
			text = $STR_DISP_SRVSETUP_ISLAND;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ValueIsland : RscText {
			idc = 102;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(25.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			x = "5.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class TextSide : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1008;
			text = $STR_DISP_MPSETUP_SIDE;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 1};
		};
		
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
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_B_East : CA_B_West {
			text = $STR_EAST;
			idc = 105;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])", "(profilenamespace getvariable ['Map_OPFOR_G',1])", "(profilenamespace getvariable ['Map_OPFOR_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])", "(profilenamespace getvariable ['Map_OPFOR_G',1])", "(profilenamespace getvariable ['Map_OPFOR_B',1])", 1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "8.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_B_Guerrila : CA_B_West {
			text = $STR_GUERRILA;
			idc = 106;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Independent_R',0])", "(profilenamespace getvariable ['Map_Independent_G',1])", "(profilenamespace getvariable ['Map_Independent_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Independent_R',0])", "(profilenamespace getvariable ['Map_Independent_G',1])", "(profilenamespace getvariable ['Map_Independent_B',1])", 1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "10.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_B_Civilian : CA_B_West {
			text = $STR_CIVILIAN;
			idc = 107;
			picture = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_empty_ca.paa";
			sideToggle = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
			color[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])", "(profilenamespace getvariable ['Map_Civilian_G',1])", "(profilenamespace getvariable ['Map_Civilian_B',1])", 0.75};
			colorActive[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])", "(profilenamespace getvariable ['Map_Civilian_G',1])", "(profilenamespace getvariable ['Map_Civilian_B',1])", 1};
			x = "1.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "12.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ValueRoles : RscListBox {
			idc = 109;
			colorPlayer[] = {1, 1, 0, 1};
			colorAI[] = {1, 0, 0, 1};
			colorNobody[] = {1, 1, 1, 0.25};
			enabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\enabledAI_ca.paa";
			disabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\disabledAI_ca.paa";
			rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			x = "4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(9.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			colorSelectBackground[] = {1, 1, 1, 0.3};
			colorSelectBackground2[] = {1, 1, 1, 0.3};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		
		class CA_ValuePool : RscListBox {
			idc = 114;
			canDrag = 1;
			rows = 25;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + (19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			w = "(19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.55*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorSelectBackground[] = {1, 1, 1, 0.3};
			colorSelectBackground2[] = {1, 1, 1, 0.3};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		
		class CA_B_EnableAll : RscButtonMenu {
			idc = 117;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "13.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			y = "16.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_B_Lock : RscButtonMenu {
			idc = 118;
			x = "safezoneX + SafezoneW - (13.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_B_Params : RscButtonMenu {
			idc = 128;
			shortcuts[] = {0x00050000 + 2};
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "(26.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = $STR_DISP_XBOX_EDITOR_WIZARD_PARAMS;
			y = "4.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ButtonSteamWorkshop : RscButtonMenuSteam {
			x = "safezoneX + SafezoneW - (19.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			idc = 130;
			text = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscDisplayMultiplayerSetup_ButtonSteamWorkshop_tooltip";
		};
		
		class CA_B_Kick : RscButtonMenu {
			idc = 116;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "safezoneX + SafezoneW - (7.45 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = $STR_DISP_MP_KICKOFF;
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ButtonContinue : RscButtonMenuOK {
			x = "safezoneX + SafezoneW - (7.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CA_ButtonCancel : RscButtonMenuCancel {
			y = "SafezoneY + SafezoneH - (2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = $STR_DISP_BACK;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class TextMission : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			idc = 1002;
			text = $STR_DISP_SRVSETUP_NAME;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
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
		
		class TextListedPlayers : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "31.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1013;
			text = "$STR_A3_RscDisplayMultiplayerSetup_TextListedPlayers";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "5.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ValueListedPlayers : RscText {
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			style = 1;
			x = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX) + 1*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1015;
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
