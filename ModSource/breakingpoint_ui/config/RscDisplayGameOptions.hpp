class RscDisplayGameOptions
{
	enableDisplay=1;
	scriptName="RscDisplayGameOptions";
	scriptPath="GUI";
	onLoad="[""onLoad"",_this,""RscDisplayGameOptions"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscDisplayGameOptions"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc=114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc=115099;
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
			class Controls
			{
				class Background: RscText
				{
					idc=114999;
					x=0;
					y=0;
					w="safezoneWAbs";
					h="safezoneH";
					colorBackground[]={0,0,0,0.5};
				};
			};
		};
		class BackgroundDisable: RscText
		{
		};
		class BackgroundDisableTiles: RscText
		{
		};
		class TitleBackground: RscText
		{
			colorBackground[]=
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
			};
			idc=1080;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabsBackground: RscText
		{
			colorBackground[]={0,0,0,1};
			idc=1081;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[]={0,0,0,0.69999999};
			idc=1082;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="19.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	class controls
	{
		delete RadioSubtitles;
		delete TextGore;
		delete TextLanguage;
		delete TextFloatingZone;
		delete TextSubtitles;
		delete ValueBlood;
		delete Radio;
		delete ValueLanguage;
		delete ValueFloatingZone;
		delete Subtitles;
		delete TextHeadBob;
		delete ValueHeadBob;
		delete B_Cancel;
		delete B_OK;
		delete B_Difficulty;
		class Title: RscTitle
		{
			style=0;
			idc=1000;
			text="$STR_DISP_OPTIONS_GAME_OPTIONS";
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PlayersName: Title
		{
			idc=601;
			style=1;
			colorBackground[]={0,0,0,0};
			x="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="23 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOKscripted: RscButtonMenuOK
		{
			idc=999;
			x="32.75 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonGeneral: RscButtonMenu
		{
			idc=2402;
			text="$STR_A3_RscDisplayGameOptions_ButtonGeneral";
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonDifficulty: RscButtonMenu
		{
			idc=304;
			text="$STR_DISP_OPTIONS_DIFFICULTY";
			x="9 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonGUI: RscButtonMenu
		{
			idc=2404;
			text="$STR_A3_RscDisplayGameOptions_ButtonGUI";
			x="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonLayout: RscButtonMenu
		{
			action="finddisplay 151 createdisplay 'RscDisplayOptionsLayout'";
			idc=2405;
			text="$STR_A3_RscDisplayGameOptions_ButtonLayout";
			x="25 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOK: RscButtonMenuOK
		{
			idc=1;
			default=0;
			x=-10;
			y=-10;
			text="$STR_DISP_OK";
			w="6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GeneralGroup: RscControlsGroup
		{
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			idc=2300;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="19.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CA_TextLanguage: RscText
				{
					style=1;
					idc=1002;
					text="$STR_DISP_OPT_LANGUAGE";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueLanguage: RscCombo
				{
					idc=135;
					wholeHeight="15 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_TextSubtitles: CA_TextLanguage
				{
					style=1;
					idc=1003;
					text="$STR_OPT_SUBTITLES";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueSubtitles: RscXListBox
				{
					idc=102;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_RadioSubtitles: CA_TextLanguage
				{
					style=1;
					idc=1004;
					text="$STR_OPT_RADIO_SUBTITLES";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueRadio: CA_ValueSubtitles
				{
					idc=103;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_TextGore: CA_TextLanguage
				{
					idc=122;
					style=1;
					text="$STR_DISP_OPT_BLOOD";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueBlood: CA_ValueSubtitles
				{
					idc=119;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TextTutorialHints: CA_TextLanguage
				{
					style=1;
					idc=1024;
					text="$STR_A3_RscDisplayGameOptions_TextTutorialHints";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueTutorialHints: CA_ValueSubtitles
				{
					idc=140;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TextInstructorFigure: CA_TextLanguage
				{
					style=1;
					idc=1029;
					text="$STR_A3_INSTRUCTORFIGURE";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueInstructorFigure: CA_ValueSubtitles
				{
					idc=145;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class VehicleFreelook: CA_TextLanguage
				{
					style=1;
					idc=1023;
					text="$STR_A3_RscDisplayGameOptions_VehicleFreelook";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueVehicleFreelook: CA_ValueSubtitles
				{
					idc=142;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TextStreamFriendlyUI: CA_TextLanguage
				{
					style=1;
					idc=1027;
					text="$STR_A3_RscDisplayGameOptions_TextStreamFriendlyUI";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueStreamFriendlyUI: CA_ValueSubtitles
				{
					idc=143;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TextAdaptiveCrosshair: CA_TextLanguage
				{
					style=1;
					idc=1028;
					text="$STR_A3_RscDisplayGameOptions_TextAdaptiveCrosshair";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="13 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueAdaptiveCrosshair: CA_ValueSubtitles
				{
					idc=144;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="13 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_TextFloatingZone: CA_TextLanguage
				{
					style=1;
					idc=1006;
					text="$STR_DISP_CONF_FLOATING_ZONE";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="14.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueFloatingZone: RscXSliderH
				{
					idc=109;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="14.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_TextHeadBob: CA_TextLanguage
				{
					style=1;
					idc=1007;
					text="$STR_DISP_OPT_HEADBOB";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="16 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueHeadBob: RscXSliderH
				{
					idc=138;
					x="9.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="16 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDTextEnable: RscText
				{
					style=1;
					idc=1030;
					text="$STR_A3_RscDisplayGameOptions_RTDTextEnable";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueEnable: CA_ValueSubtitles
				{
					idc=146;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTENABLE_TOOLTIP";
				};
				class RTDTextShowGauges: RscText
				{
					style=1;
					idc=1031;
					text="$STR_A3_RscDisplayGameOptions_RTDTextShowGauges";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueShowGauges: CA_ValueSubtitles
				{
					idc=147;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTSHOWGAUGES_TOOLTIP";
				};
				class RTDTextRoughLanding: RscText
				{
					style=1;
					idc=1032;
					text="$STR_A3_RscDisplayGameOptions_RTDTextRoughLanding";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueRoughLanding: CA_ValueSubtitles
				{
					idc=148;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTROUGHLANDING_TOOLTIP";
				};
				class RTDTextWindDyn: RscText
				{
					style=1;
					idc=1033;
					text="$STR_A3_RscDisplayGameOptions_RTDTextWindDyn";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueWindDyn: CA_ValueSubtitles
				{
					idc=149;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTWINDDYN_TOOLTIP";
				};
				class RTDTextAutoTrim: RscText
				{
					style=1;
					idc=1034;
					text="$STR_A3_RscDisplayGameOptions_RTDTextAutoTrim";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueAutoTrim: CA_ValueSubtitles
				{
					idc=150;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTAUTOTRIM_TOOLTIP";
				};
				class RTDTextStressDamage: RscText
				{
					style=1;
					idc=1035;
					text="$STR_A3_RscDisplayGameOptions_RTDTextStressDamage";
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class RTDValueStressDamage: CA_ValueSubtitles
				{
					idc=151;
					x="29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_RSCDISPLAYGAMEOPTIONS_RTDTEXTSTRESSDAMAGE_TOOLTIP";
				};
			};
		};
		class DifficultyGroup: RscControlsGroup
		{
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			idc=2302;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="19.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class EmptyText: RscText
				{
					idc=-1;
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DifficultyPicture: RscPicture
				{
					idc=1518;
					text="#(argb,8,8,3)color(0,0,0,0.3)";
					x="21.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DifficultyDescription: RscStructuredText
				{
					idc=1519;
					x="21.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="10.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.30000001};
				};
				class TextDifficulty: RscText
				{
					idc=1022;
					style=1;
					text="$STR_A3_RSCDISPLAYOPTIONSLAYOUT_PRESETSLABEL";
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class OverallDifficulty: RscCombo
				{
					idc=108;
					x="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="13.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DiffOptionsBackground: RscText
				{
					idc=1083;
					  
						  
																			   
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="16.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.30000001};
				};
				class DiffOptionsGroup: RscControlsGroup
				{
					idc=1520;
					class HScrollbar: HScrollbar
					{
						height=0;
					};
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="16.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					lineHeight="1.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					highlightColorFrom[]={1,1,1,0.25};
					highlightColorTo[]={1,1,1,0.5};
					highlightAnimLength=1.2;
					class controls
					{
						class SimulationText: RscText
						{
							idc=1036;
							shadow=0;
							text="$STR_DIFF_SIMULATION";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(0 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ReducedDamageText: RscText
						{
							idc=1037;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(1 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ReducedDamageOption: RscCheckBox
						{
							idc=1521;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(1 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class TextAILevel: RscText
						{
							idc=1510;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(2 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class AILevelOption: RscCombo
						{
							idc=1511;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(2 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class TextAISkill: RscText
						{
							idc=1512;
							shadow=0;
							text="N/A";
							x="2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(3 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class SliderAISkill: RscXSliderH
						{
							idc=1513;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(3 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ValueAISkill: RscEdit
						{
							idc=1514;
							x="18.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(3 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class TextAIPrecision: RscText
						{
							idc=1515;
							shadow=0;
							text="N/A";
							x="2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(4 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class SliderAIPrecision: RscXSliderH
						{
							idc=1516;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(4 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ValueAIPrecision: RscEdit
						{
							idc=1517;
							x="18.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(4 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class SituationalAwarenessText: RscText
						{
							idc=1038;
							shadow=0;
							text="$STR_DIFF_SITUATIONAL_AWARENESS";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(6 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class GroupIndicatorsText: RscText
						{
							idc=1039;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(7 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class GroupIndicatorsOption: RscCombo
						{
							idc=1522;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(7 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class FriendlyTagText: RscText
						{
							idc=1040;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(8 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class FriendlyTagOption: RscCombo
						{
							idc=1523;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(8 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class EnemyTagText: RscText
						{
							idc=1041;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(9 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class EnemyTagOption: RscCombo
						{
							idc=1524;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(9 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class MinesText: RscText
						{
							idc=1042;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(10 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class MinesOption: RscCombo
						{
							idc=1525;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(10 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class CommandsText: RscText
						{
							idc=1043;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(11 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class CommandsOption: RscCombo
						{
							idc=1526;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(11 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class WaypointsText: RscText
						{
							idc=1044;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(12 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class WaypointsOption: RscCombo
						{
							idc=1527;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(12 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class TacticalPingText: RscText
						{
							idc=1063;
							shadow=0;
							text="$STR_DIFF_TACTICAL_PING";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(13 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\A3\Ui_f\data\GUI\Rsc\RscDisplayGameOptions\Diff_TacticalPing_co.paa";
							optionDescription="$STR_DIFF_TACTICAL_PING_DESC";
						};
						class TacticalPingOption: RscCheckBox
						{
							idc=1542;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(13 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class PersonalAwarenessText: RscText
						{
							idc=1045;
							shadow=0;
							text="$STR_DIFF_PERSONAL_AWARENESS";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(15 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class WeaponInfoText: RscText
						{
							idc=1046;
							shadow=0;
							text="$STR_A3_CFGUIGRIDS_IGUI_VARIABLES_GRID_WEAPON_0";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(16 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\A3\Ui_f\data\GUI\Rsc\RscDisplayGameOptions\Diff_WeaponInfo_co.paa";
							optionDescription="$STR_DIFF_WEAPON_INFO_DESC";
						};
						class WeaponInfoOption: RscCombo
						{
							idc=1528;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(16 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class StanceIndicatorText: RscText
						{
							idc=1047;
							shadow=0;
							text="$STR_DIFF_STANCE_INDICATOR";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(17 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="11.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\A3\Ui_f\data\GUI\Rsc\RscDisplayGameOptions\Diff_StanceIndicator_co.paa";
							optionDescription="$STR_DIFF_STANCE_INDICATOR_DESC";
						};
						class StanceIndicatorOption: RscCombo
						{
							idc=1529;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(17 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class StaminaBarText: RscText
						{
							idc=1048;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(18 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class StaminaBarOption: RscCheckBox
						{
							idc=1530;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(18 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class CrosshairText: RscText
						{
							idc=1049;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(19 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class CrosshairOption: RscCheckBox
						{
							idc=1531;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(19 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class VisionAidText: RscText
						{
							idc=1050;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(20 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class VisionAidOption: RscCheckBox
						{
							idc=1532;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(20 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ViewText: RscText
						{
							idc=1051;
							shadow=0;
							text="$STR_A3_USERACTIONGROUPS_VIEW_0";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(22 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ThirdPersonText: RscText
						{
							idc=1052;
							shadow=0;
							text="$STR_DIFF_3RD_PERSON_VIEW";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(23 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ThirdPersonOption: RscCombo
						{
							idc=1533;
							x="12.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(23 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="7.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class CameraShakeText: RscText
						{
							idc=1053;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(24 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class CameraShakeOption: RscCheckBox
						{
							idc=1534;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(24 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class MultiplayerText: RscText
						{
							idc=1054;
							shadow=0;
							text="$STR_DISP_MAIN_MULTI";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(26 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ScoreTableText: RscText
						{
							idc=1055;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(27 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ScoreTableOption: RscCheckBox
						{
							idc=1535;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(27 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class KilledByText: RscText
						{
							idc=1056;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(28 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class KilledByOption: RscCheckBox
						{
							idc=1536;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(28 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class VONText: RscText
						{
							idc=1057;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(29 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class VONOption: RscCheckBox
						{
							idc=1537;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(29 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class MapText: RscText
						{
							idc=1058;
							shadow=0;
							text="$STR_DIFF_MAP_CONTENT";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(31 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ExtendedMapTextFriendly: RscText
						{
							idc=1059;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(32 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ExtendedMapOptionFriendy: RscCheckBox
						{
							idc=1538;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(32 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ExtendedMapTextEnemy: RscText
						{
							idc=1060;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(33 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ExtendedMapOptionEnemy: RscCheckBox
						{
							idc=1543;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(33 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ExtendedMapTextMines: RscText
						{
							idc=1061;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(34 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class ExtendedMapOptionMines: RscCheckBox
						{
							idc=1544;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(34 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class ExtendedMapTextPing: RscText
						{
							idc=1067;
							shadow=0;
							text="$STR_DIFF_TACTICAL_PING";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(35 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\A3\Ui_f\data\GUI\Rsc\RscDisplayGameOptions\Diff_Map_Ping_co.paa";
							optionDescription="$STR_DIFF_TACTICAL_PING_DESC";
						};
						class ExtendedMapOptionPing: RscCheckBox
						{
							idc=1546;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(35 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class MiscText: RscText
						{
							idc=1064;
							shadow=0;
							text="$STR_A3_MDL_CATEGORY_MISC";
							font="RobotoCondensedBold";
							x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(37 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class AutoReportText: RscText
						{
							idc=1065;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(38 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class AutoReportOption: RscCheckBox
						{
							idc=1539;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(38 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
						class MultipleSavesText: RscText
						{
							idc=1066;
							shadow=0;
							text="N/A";
							x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(39 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							optionPicture="\breakingpoint_ui\menu\gamemenuedit.paa";
							optionDescription="Most difficulty options in BreakingPoint are set server side";
						};
						class MultipleSavesOption: RscCheckBox
						{
							idc=1540;
							x="19.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							y="(39 * 1.2) * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
							h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
					};
				};
			};
		};
		class ColorsGroup: RscControlsGroup
		{
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			idc=2301;
			x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="3.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="19.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class Controls
			{
				class EmptyText: RscText
				{
					idc=-1;
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class listTags: RscCombo
				{
					idc=1504;
					x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class listVariables: RscListBox
				{
					colorPictureSelected[]={1,1,1,1};
					idc=1505;
					x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="12 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class listPresets: RscListBox
				{
					idc=1506;
					x="1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class sliderColorR: RscXSliderH
				{
					color[]={1,0,0,0.40000001};
					colorActive[]={1,0,0,1};
					idc=1903;
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class sliderColorG: RscXSliderH
				{
					color[]={0,1,0,0.40000001};
					colorActive[]={0,1,0,1};
					idc=1904;
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class sliderColorB: RscXSliderH
				{
					color[]={0,0,1,0.40000001};
					colorActive[]={0,0,1,1};
					idc=1905;
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class sliderColorA: RscXSliderH
				{
					idc=1906;
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class textColorR: RscText
				{
					style=1;
					idc=1009;
					text="$STR_A3_RscDisplayGameOptions_textColorR";
					x="13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class textColorG: RscText
				{
					style=1;
					idc=1010;
					text="$STR_A3_RscDisplayGameOptions_textColorG";
					x="13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class textColorB: RscText
				{
					style=1;
					idc=1011;
					text="$STR_A3_RscDisplayGameOptions_textColorB";
					x="13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class textColorA: RscText
				{
					style=1;
					idc=1012;
					text="$STR_A3_RscDisplayGameOptions_textColorA";
					x="13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class valueColorR: RscText
				{
					style=1;
					idc=1013;
					x="33.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class valueColorG: RscText
				{
					style=1;
					idc=1014;
					x="33.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class valueColorB: RscText
				{
					style=1;
					idc=1015;
					x="33.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class valueColorA: RscText
				{
					style=1;
					idc=1016;
					x="33.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class PreviewBackground: RscPicture
				{
					idc=1200;
					x="18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="7.75 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Preview: RscPicture
				{
					idc=1201;
					x="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="8.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
	};
};