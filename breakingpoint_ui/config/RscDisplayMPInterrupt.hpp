
class RscDisplayMPInterrupt : RscStandardDisplay 
{
	onLoad = "[""onLoad"",_this,""RscDisplayMPInterrupt"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayMPInterrupt"",'GUI'] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\initDisplay.sqf""";
	//onLoad = "[""onLoad"",_this,""RscDisplayMPInterrupt""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\RscDisplayMPInterrupt.sqf""";
	//onUnload = "[""onUnload"",_this,""RscDisplayMPInterrupt""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\RscDisplayMPInterrupt.sqf""";
	movingEnable = 0;
	enableSimulation = 1;
	
	class controlsBackground 
	{
		delete Vignette;
		delete TileGroup;
		delete TitleBackground;
		delete MissionNameBackground;
		delete Pause1;
		delete Pause2;

		class Background_Blood: RscPicture
		{
			idc = 1200;
			text = "\breakingpoint_ui\pause\background_blood.paa";
			x = -0.00531252 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.407 * safezoneH;
		};
		
		class Title_Menu: RscPicture
		{
			idc = 1201;
			text = "\breakingpoint_ui\pause\title_menu.paa";
			x = 0.005 * safezoneW + safezoneX;
			y = 0.7926 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.0264 * safezoneH;
		};

		class Title_Config: RscPicture
		{
			idc = 1202;
			text = "\breakingpoint_ui\pause\title_config.paa";
			x = 0.00396872 * safezoneW + safezoneX;
			y = 0.8388 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.0286 * safezoneH;
		};
	};
	
	class controls {
		delete B_Players;
		delete B_Options;
		delete B_Abort;
		delete B_Retry;
		delete B_Load;
		delete B_Save;
		delete B_Continue;
		delete B_Diary;
		
		delete Title;
		delete PlayersName;
		delete ButtonSAVE;
		delete ButtonSkip;
		delete ButtonTutorialHints;

		class ButtonCancel : RscActiveText {
			idc = 2;
			style = 48;
			shortcuts[] = {0x00050000 + 1, 0x00050000 + 8};
			default = 1;
			text = "\breakingpoint_ui\pause\button_continue.paa";
			x = 0.005 * safezoneW + safezoneX;
			y = 0.8146 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_continue_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_continue.paa'";
		};
		
		class ButtonRespawn : RscActiveText {
			idc = 1010;
			style = 48;
			text = "\breakingpoint_ui\pause\button_respawn.paa";
			x = 0.00396872 * safezoneW + safezoneX;
			y = 0.9598 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_respawn_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_respawn.paa'";
		};
		
		delete ButtonOptions;
		
		class ButtonVideo : RscActiveText {
			idc = 301;
			style = 48;
			text = "\breakingpoint_ui\pause\button_video.paa";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.863 * safezoneH + safezoneY;
			w = 0.243375 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_video_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_video.paa'";
		};
		
		class ButtonAudio : RscActiveText {
			idc = 302;
			style = 48;
			text = "\breakingpoint_ui\pause\button_audio.paa";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.8872 * safezoneH + safezoneY;
			w = 0.254719 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_audio_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_audio.paa'";
		};
		
		class ButtonControls : RscActiveText {
			idc = 303;
			style = 48;
			text = "\breakingpoint_ui\pause\button_controls.paa";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.9114 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_controls_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_controls.paa'";
		};
		
		class ButtonGame : RscActiveText {
			idc = 307;
			style = 48;
			text = "\breakingpoint_ui\pause\button_game.paa";
			x = 0.0142812 * safezoneW + safezoneX;
			y = 0.9356 * safezoneH + safezoneY;
			w = 0.253688 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_game_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_game.paa'";
		};
		

		class ButtonAbort : RscActiveText {
			idc = 104;
			style = 48;
			text = "\breakingpoint_ui\pause\button_abort.paa";
			x = 0.00396872 * safezoneW + safezoneX;
			y = 0.9598 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.0286 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_abort_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\pause\button_abort.paa'";
		};
		
		//delete DebugConsole;

		delete Feedback;
		
		delete DifficultyTitle;
		/*
		class DifficultyTitle : RscText {
			idc = 121;
			style = 1;
			font = "PuristaLight";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = false;
			x = "SafezoneX + SafezoneW - (11 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 0};
		};
		*/
		
		delete MissionTitle;
		/*
		class MissionTitle : RscText {
			idc = 120;
			font = "PuristaLight";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = false;
			x = "SafezoneX + (1 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "SafezoneW - (12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 0};
		};
		*/
		
		class MessageBox : RscMessageBox {};
	};
};
