/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class RscPicture;
class RscButton;
class CA_IGUI_Title;
class RscText;
class RscLineBreak;
class RscGearShortcutButton;
class RscIGUIListNBox;
class RscActiveText;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscProgress;
class RscProgressNotFreeze;
class RscButtonTextOnly;
class CA_Title;
class RscShortcutButton;
class CA_Black_Back;
class RscMapControl;
class IGUIBack;
class RscHTML;
class RscObject;
class RscDisplayGetReady;
class RscListBox;
class RscIGUIShortcutButton;
class RscCombo;
class RscControlsGroup;
class RscIGUIListBox;
class RscEdit;

#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)

class RscPictureGUI
{
	type = 0;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0.38,0.63,0.26,0.75};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	style = "0x30 + 0x100";
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
};

class RscStructuredText {
	class Attributes;
};
class RscStructuredTextGUI: RscStructuredText
{
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	class Attributes: Attributes
	{
		align = "center";
		valign = "middle";
	};
};
class RscStructuredTextStats: RscStructuredText
{
	colorBackground[]={0,0,0,0};
	class Attributes: Attributes
	{
		font="sketch";
		size="2 * 	(0.04)";
		color="#FFFFFF";
		align="center";
		valign="bottom";
	};
};

class CA_TextLanguage;
class RscXListBox;
class RscFrame;

class RscDisplaySafe
{
	idd = 6918;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\safe\BP_keypad.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class BP_Lights: RscPicture
		{
			idc = 1201;
			text = "\breakingpoint_ui\safe\lights_4_off.jpg";
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.033 * safezoneH;
		};

		class Button_1: RscActiveText
		{
			idc = 1202;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\1.paa";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '1';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_2: RscActiveText
		{
			idc = 1203;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\2.paa";
			x = 0.711406 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '2';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_3: RscActiveText
		{
			idc = 1204;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\3.paa";
			x = 0.773281 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '3';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_4: RscActiveText
		{
			idc = 1205;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\4.paa";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '4';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_5: RscActiveText
		{
			idc = 1206;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\5.paa";
			x = 0.711406 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '5';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_6: RscActiveText
		{
			idc = 1207;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\6.paa";
			x = 0.773281 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '6';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_7: RscActiveText
		{
			idc = 1208;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\7.paa";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '7';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_8: RscActiveText
		{
			idc = 1209;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\8.paa";
			x = 0.711406 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '8';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_9: RscActiveText
		{
			idc = 1210;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\9.paa";
			x = 0.773281 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '9';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_0: RscActiveText
		{
			idc = 1212;
			style = 48;
			text = "\breakingpoint_ui\safe\buttons\0.paa";
			x = 0.711406 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_SafeButton = '0';";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		
		//Unused Stub Buttons
		class Button_A: RscPicture
		{
			idc = 1211;
			text = "\breakingpoint_ui\safe\buttons\A.paa";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
		};
		class Button_B: RscPicture
		{
			idc = 1213;
			text = "\breakingpoint_ui\safe\buttons\B.paa";
			x = 0.773281 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.099 * safezoneH;
		};
	};
};

class RscDisplayDogName
{
	idd = 6909;
	enableDisplay = 1;
	enableSimulation = 1;
	class controls
	{
		class BP_Text: RscEdit
		{
			idc = 1400;
			text = "Dog"; //--- ToDo: Localize;
			x = 0.408136 * safezoneW + safezoneX;
			y = 0.444 * safezoneH + safezoneY;
			w = 0.144358 * safezoneW;
			h = 0.042 * safezoneH;
		};
		class BP_Button: RscActiveText
		{
			idc = 1000;
			text = "Set Name"; //--- ToDo: Localize;
			x = 0.454068 * safezoneW + safezoneX;
			y = 0.514 * safezoneH + safezoneY;
			w = 0.0656173 * safezoneW;
			h = 0.042 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "BP_DogNameSet = true;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class BP_Title: RscText
		{
			idc = 1001;
			text = "Dog Name:"; //--- ToDo: Localize;
			x = 0.434383 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.104988 * safezoneW;
			h = 0.042 * safezoneH;
			sizeEx = 1.5 * GUI_GRID_H;
		};
	};
};

class RscDisplayGroupInvite
{
	idd = 6909;
	enableDisplay = 1;
	enableSimulation = 1;
	class controls
	{
		class BP_GroupSystem_Yes: RscButton
		{
			idc = 1600;
			text = "Yes"; //--- ToDo: Localize;
			x = 13.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.70588 * GUI_GRID_W;
			h = 2.94104 * GUI_GRID_H;
			tooltip = "Yes"; //--- ToDo: Localize;
			default = 0;
			action = "closeDialog 0;BP_GroupSystem = true;";
		};
		class BP_GroupSystem_No: RscButton
		{
			idc = 1601;
			text = "No"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.70588 * GUI_GRID_W;
			h = 2.94104 * GUI_GRID_H;
			tooltip = "No"; //--- ToDo: Localize;
			default = 1;
			action = "closeDialog 0;BP_GroupSystem = false;";
		};
		//class RscText_1000: RscText
		//{
		//	idc = 1000;
		//	text = "Player %1 would like to invite you to a group."; //--- ToDo: Localize;
		//	x = 7.5 * GUI_GRID_W + GUI_GRID_X;
		//	y = 5 * GUI_GRID_H + GUI_GRID_Y;
		//	w = 24.4 * GUI_GRID_W;
		//	h = 1.75 * GUI_GRID_H;
		//};
		class RscText_1001: RscText
		{
			idc = 1001;
			text = "Group System"; //--- ToDo: Localize;
			x = 12.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1 * GUI_GRID_H + GUI_GRID_Y;
			w = 14 * GUI_GRID_W;
			h = 2.75 * GUI_GRID_H;
			sizeEx = 0.09;
		};
	};
};

/*
class RscDisplayStrongholdAltis
{
	idd = 6911;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\strongholds\background_altis.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_World: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\strongholds\button_world.jpg";
			x = 0.660875 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.11 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_Strongholds = 0;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_Strongholds: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\strongholds\button_strongholds.jpg";
			x = 0.163811 * safezoneW + safezoneX;
			y = 0.4604 * safezoneH + safezoneY;
			w = 0.191812 * safezoneW;
			h = 0.1034 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_Strongholds = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
	};
};

class RscDisplayStrongholdBornholm
{
	idd = 6911;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\strongholds\background_altis.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_World: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\strongholds\button_world.jpg";
			x = 0.660875 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.11 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_Strongholds = 0;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_Strongholds: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\strongholds\button_strongholds.jpg";
			x = 0.163811 * safezoneW + safezoneX;
			y = 0.4604 * safezoneH + safezoneY;
			w = 0.191812 * safezoneW;
			h = 0.1034 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_Strongholds = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
	};
};
*/

class RscDisplaySpawnSelectAltis
{
	idd = 6911;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\general\BP_spawn_screen_2.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_West: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_west_button.jpg";
			x = 0.154531 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_East: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_east_button.jpg";
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 2;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_Central: RscActiveText
		{
			idc = 1202;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_central_button.jpg";
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.72 * safezoneH + safezoneY;
			w = 0.180469 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 3;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
	};
};

class RscDisplaySpawnSelectnewhaven
{
	idd = 6911;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\general\spawn_select\newhaven\background.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_West: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_west_button.jpg";
			x = 0.159687 * safezoneW + safezoneX;
			y = 0.17 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_East: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_east_button.jpg";
			x = 0.675312 * safezoneW + safezoneX;
			y = 0.17 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.099 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 2;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
	};
};


class RscDisplaySpawnSelectTanoa
{
	idd = 6911;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\spawn_select\tanoa\tanoa_Select_Demo.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_West: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_west_button.jpg";
			x = 0.158200 * safezoneW + safezoneX;
			y = 0.19 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.096 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_East: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_east_button.jpg";
			x = 0.673100 * safezoneW + safezoneX;
			y = 0.19 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.096 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 2;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		class Button_Central: RscActiveText
		{
			idc = 1202;
			style = 48;
			text = "\breakingpoint_ui\general\spawn_select\BP_central_button.jpg";
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.72 * safezoneH + safezoneY;
			w = 0.180469 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_spawnLocation = 3;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
	};
};


/*
			Breaking Point
	Custom Authentication Loading Screen
			By Deathlyrage
*/

class BP_Loading_Login
{
	onLoad = "UInamespace SetVariable ['BP_loadingScreen',_this Select 0];";
	idd = 1337;
	duration = 0;
	fadein = 0;
	fadeout = 0;
	enableDisplay = 1;
	name = "loading screen";
	class controlsBackground
	{
		class blackBG : RscText
		{
			x = safezoneX;
			y = safezoneY;
			w = safezoneW;
			h = safezoneH;
			text = "";
			colorText[] = {0,0,0,0};
			colorBackground[] = {0,0,0,1};
		};
		class nicePic : RscPicture
		{
			idc = 8399;
			//style = 48 + 0x800; // ST_PICTURE + ST_KEEP_ASPECT_RATIO
			x = safezoneX;
			y = safezoneY;
			w = safezoneW;
			h = safezoneH;
			text = "\breakingpoint_ui\blank.jpg";
		};
	};
	class controls
	{
		class Title1 : RscText {
			idc = 8400;
			style = 2;
			x = "0.35125 * safezoneW + safezoneX";
			y = "0.857016 * safezoneH + safezoneY";
			w = "0.300002 * safezoneW";
			h = "0.0333351 * safezoneH";
			//x = 0.325;
			//y = 0.92;
			//w = 0.352944;
			//h = 0.039216;
			sizeEx = 0.03;
			//colorText[] = {0.543,0.5742,0.4102,1.0};
			text = "Loading...";
		};
		class Title2: RscText
		{
			//[0.925,0.92,0.05,0.05]
			idc = 8401;
			x = "0.86125 * safezoneW + safezoneX";
			y = "0.857016 * safezoneH + safezoneY";
			w ="0.0425 * safezoneW";
			h = "0.042502 * safezoneH";
			//x = 0.05;
			//y = 0.029412;
			//w = 0.9;
			//h = 0.04902;
			text = "0";
			sizeEx = 0.03;
		};
	};
};

class RscShortcutButtonMain;
class RscVignette;
class RscButtonMenu;
class RscMessageBox;
class RscTitle;

/*
class RscDisplayInventory 
{
	onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";";
	onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";";
	idd = 602;
	enableSimulation = 1;
	
	class Colors {
		dragValidBgr[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
		dragInvalidBgr[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		dragValidBar[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])", 0.5};
		dragInvalidBar[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		progressBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 1};
		progressBarBgr[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])", 0.75};
		highlight[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
	};
	
	class controlsBackground {};
	
	class controls {
		class Background {};
		class Title {};
		class ButtonOK {};
		class ButtonCancel {};
		
		class CA_ContainerBackground : RscText {
			idc = 1001;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05, 0.05, 0.05, 0.7};
		};
		
		class CA_PlayerBackground : RscText {
			idc = 1002;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "22 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05, 0.05, 0.05, 0.7};
		};
		
		class TitleBackground : RscText {
			idc = 1020;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.1, 0.1, 0.1, 1};
		};
		
		class PlayersName : RscText {
			idc = 111;
			text = $STR_DIARY_PLAYER_NAME;
			x = "15.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class RankBackground : RscText {
			idc = 1014;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1, 1, 1, 0.2};
		};
		
		class RankPicture : RscPicture {
			idc = 1203;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ButtonBack : RscActiveText {
			idc = 2;
			style = 48;
			color[] = {1, 1, 1, 0.7};
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
			x = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1, 1, 1, 0.7};
			colorActive[] = {1, 1, 1, 1};
			tooltip = $STR_DISP_CLOSE;
		};
		
		class BackgroundSlotPrimary : RscPicture {
			idc = 1242;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotPrimaryMuzzle : BackgroundSlotPrimary {
			idc = 1243;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotPrimaryFlashlight : BackgroundSlotPrimary {
			idc = 1244;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotPrimaryOptics : BackgroundSlotPrimary {
			idc = 1245;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotPrimaryMagazine : BackgroundSlotPrimary {
			idc = 1246;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotSecondary : BackgroundSlotPrimary {
			idc = 1247;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotSecondaryMuzzle : BackgroundSlotPrimary {
			idc = 1248;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotSecondaryFlashlight : BackgroundSlotPrimary {
			idc = 1249;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotSecondaryOptics : BackgroundSlotPrimary {
			idc = 1250;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotSecondaryMagazine : BackgroundSlotPrimary {
			idc = 1251;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHandgun : BackgroundSlotPrimary {
			idc = 1252;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHandgunMuzzle : BackgroundSlotPrimary {
			idc = 1253;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHandgunFlashlight : BackgroundSlotPrimary {
			idc = 1254;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHandgunOptics : BackgroundSlotPrimary {
			idc = 1255;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHandgunMagazine : BackgroundSlotPrimary {
			idc = 1256;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHeadgear : BackgroundSlotPrimary {
			idc = 1257;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotGoggles : BackgroundSlotPrimary {
			idc = 1258;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotHMD : BackgroundSlotPrimary {
			idc = 1259;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotBinoculars : BackgroundSlotPrimary {
			idc = 1260;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotMap : BackgroundSlotPrimary {
			idc = 1261;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotGPS : BackgroundSlotPrimary {
			idc = 1262;
			x = "17.32 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotCompass : BackgroundSlotPrimary {
			idc = 1263;
			x = "21.76 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotRadio : BackgroundSlotPrimary {
			idc = 1264;
			x = "19.54 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackgroundSlotWatch : BackgroundSlotPrimary {
			idc = 1265;
			x = "23.98 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ExternalContainerBackground : RscPicture {
			colorText[] = {1, 1, 1, 0.1};
			idc = 1240;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class PlayerContainerBackground : ExternalContainerBackground {
			idc = 1241;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class GroundTab : RscActiveText {
			idc = 6321;
			colorBackgroundSelected[] = {1, 1, 1, 1};
			colorFocused[] = {1, 1, 1, 0};
			soundDoubleClick[] = {"", 0.1, 1};
			color[] = {1, 1, 1, 1};
			colorBackground[] = {0, 0, 0, 1};
			text = "";
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class SoldierTab : GroundTab {
			idc = 6401;
			x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class GroundContainer : RscListBox {
			idc = 632;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {0, 0, 0, 0};
			itemBackground[] = {1, 1, 1, 0.1};
			itemSpacing = 0.001;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class SoldierContainer : GroundContainer {
			idc = 640;
		};
		
		class GroundFilter : RscCombo {
			idc = 6554;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class GroundLoad : RscProgress {
			idc = 6307;
			texture = "";
			textureExt = "";
			colorBar[] = {0.9, 0.9, 0.9, 0.9};
			colorExtBar[] = {1, 1, 1, 1};
			colorFrame[] = {1, 1, 1, 1};
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class SlotPrimary : GroundTab {
			idc = 610;
			style = 0x30 + 0x800;
			color[] = {1, 1, 1, 1};
			colorBackground[] = {1, 1, 1, 0.1};
			colorBackgroundSelected[] = {1, 1, 1, 0.1};
			colorFocused[] = {0, 0, 0, 0};
			canDrag = 1;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryMuzzle : SlotPrimary {
			idc = 620;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryGrip : SlotPrimary {
			idc = -1;
			w = 0;
			h = 0;
			x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryFlashlight : SlotPrimary {
			idc = 622;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryOptics : SlotPrimary {
			idc = 621;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryMagazine : SlotPrimary {
			idc = 623;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondary : SlotPrimary {
			idc = 611;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryMuzzle : SlotPrimary {
			idc = 624;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryGrip : SlotPrimary {
			idc = -1;
			w = 0;
			h = 0;
			x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryFlashlight : SlotPrimary {
			idc = 626;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryOptics : SlotPrimary {
			idc = 625;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryMagazine : SlotPrimary {
			idc = 627;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgun : SlotPrimary {
			idc = 612;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunMuzzle : SlotPrimary {
			idc = 628;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunGrip : SlotPrimary {
			idc = -1;
			w = 0;
			h = 0;
			x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunFlashlight : SlotPrimary {
			idc = 630;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunOptics : SlotPrimary {
			idc = 629;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunMagazine : SlotPrimary {
			idc = 631;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHeadgear : SlotPrimary {
			idc = 6240;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotGoggles : SlotPrimary {
			idc = 6216;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHMD : SlotPrimary {
			idc = 6217;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotBinoculars : SlotPrimary {
			idc = 6238;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotMap : SlotPrimary {
			idc = 6211;
			x = "15.16 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotGPS : SlotPrimary {
			idc = 6215;
			x = "17.38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotCompass : SlotPrimary {
			idc = 6212;
			x = "21.82 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotRadio : SlotPrimary {
			idc = 6214;
			x = "19.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotWatch : SlotPrimary {
			idc = 6213;
			x = "24.04 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class UniformTab : GroundTab {
			idc = 6332;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1, 1, 1, 0.5};
		};
		
		class UniformSlot : SlotPrimary {
			idc = 6331;
			x = "15.35 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class UniformLoad : GroundLoad {
			idc = 6304;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class UniformContainer : GroundContainer {
			idc = 633;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			onLBDblClick = "[_this] call BP_InventorySelectItem";
		};
		
		class VestTab : UniformTab {
			idc = 6382;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class VestSlot : SlotPrimary {
			idc = 6381;
			x = "19.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class VestLoad : GroundLoad {
			idc = 6305;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class VestContainer : UniformContainer {
			idc = 638;
		};
		
		class BackpackTab : UniformTab {
			idc = 6192;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackpackSlot : SlotPrimary {
			idc = 6191;
			x = "22.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class BackpackLoad : GroundLoad {
			idc = 6306;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class BackpackContainer : UniformContainer {
			idc = 619;
		};
		
		class TotalLoad : GroundLoad {
			idc = 6308;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ContainerMarker : GroundTab {
			idc = 6325;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class GroundMarker : ContainerMarker {
			idc = 6385;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class SoldierMarker : ContainerMarker {
			idc = 6405;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
*/

class BP_InfoText : RscText
{
	sizeEx = 2 * GUI_GRID_H;
	font = "sketch";
	colorText[] = {1,1,1,1};
};
class BP_InfoText2: RscText
{
	sizeEx = "1.3 * 	(0.04)";
	font = "sketch";
	colorText[] = {1,1,1,1};
};
class RscTitles
{
	titles[] = {"RscBPTimer","RscDisplayInfoScreen","RscDisplayInfoScreenStats"};
	
	class Default
	{
		idd = -1;
		movingEnable = 0;
		duration = 0;
	};
	
	class RscDisplayInfoScreen
	{
		idd = 6941;
		enableSimulation = 1;
		//enableDisplay = 0;
		movingEnable = 0;
		duration = 10;
		fadein = 1;
		
		onLoad = "_this call BP_fnc_loginUILoaded";

		class controlsBackground 
		{
			class Mainback : RscPicture
			{
				idc = 1001;
//				text = "\breakingpoint_ui\info\InfoScreen.paa";
				x = 0.783594 * safezoneW + safezoneX;
				y = 0.401 * safezoneH + safezoneY;
				w = 0.262969 * safezoneW;
				h = 0.77 * safezoneH;
			};
		};
		class controls
		{
			class BP_Map: BP_InfoText
			{
				idc = 1002;
				text = "New Haven";
				x = "0.807500 * safezoneW + safezoneX";
				y = "0.855 * safezoneH + safezoneY";
				w = "0.104988 * safezoneW";
				h = "0.042 * safezoneH";
			};
			
//			class BP_Map2: BP_InfoText2
//			{
//				idc = 1003;
//				text = "New Haven";
//				x = 0.925000 * safezoneW + safezoneX;
//				y = 0.523 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Day: BP_InfoText
//			{
//				idc = 1004;
//				text = "35";
//				x = 0.937500 * safezoneW + safezoneX;
//				y = 0.442 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
			
			class BP_Location: BP_InfoText
			{
				idc = 1005;
				text = "AAC Airfield";
				x = "0.817500 * safezoneW + safezoneX";
				y = "0.893 * safezoneH + safezoneY";
				w = "0.13 * safezoneW";
				h = "0.042 * safezoneH";
			};
			
//			class BP_Ranger: BP_InfoText
//			{
//				idc = 1006;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.625 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Nomad: BP_InfoText
//			{
//				idc = 1007;
//				text = "99";
//				x = 0.865000 * safezoneW + safezoneX;
//				y = 0.625 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Survivalist: BP_InfoText
//			{
//				idc = 1008;
//				text = "99";
//				x = 0.917000 * safezoneW + safezoneX;
//				y = 0.625 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Engineer: BP_InfoText
//			{
//				idc = 1009;
//				text = "99";
//				x = 0.971500 * safezoneW + safezoneX;
//				y = 0.625 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};	
//			
//			class BP_Hunter: BP_InfoText
//			{
//				idc = 1010;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.715 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Outlaw: BP_InfoText
//			{
//				idc = 1011;
//				text = "99";
//				x = 0.865000 * safezoneW + safezoneX;
//				y = 0.715 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Independent: BP_InfoText
//			{
//				idc = 1012;
//				text = "99";
//				x = 0.917000 * safezoneW + safezoneX;
//				y = 0.715 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Undead: BP_InfoText
//			{
//				idc = 1013;
//				text = "99";
//				x = 0.971500 * safezoneW + safezoneX;
//				y = 0.715 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_UndeadKilled: BP_InfoText
//			{
//				idc = 1014;
//				text = "98";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.760 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_ZombiesKilled: BP_InfoText
//			{
//				idc = 1015;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.790 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_HumansKilled: BP_InfoText
//			{
//				idc = 1016;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.8225 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Headshots: BP_InfoText
//			{
//				idc = 1017;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.855 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
//			
//			class BP_Traveled: BP_InfoText
//			{
//				idc = 1018;
//				text = "99";
//				x = 0.811500 * safezoneW + safezoneX;
//				y = 0.885 * safezoneH + safezoneY;
//				w = 0.104988 * safezoneW;
//				h = 0.042 * safezoneH;
//			};
		};
	};
	class RscDisplayInfoScreenStats
	{
		idd=6942;
		enableSimulation=1;
		movingEnable=0;
		duration=10;
		fadein=0;
		fadeout=0;
		onLoad="_this call BP_fnc_factionStatsDiary";
		class controlsBackground
		{
			class MainbackStats: RscPicture
			{
				idc=1020;
				text="\breakingpoint_ui\info\InfoScreen.paa";
				x="0.783594 * safezoneW + safezoneX";
				y="0.401 * safezoneH + safezoneY";
				w="0.262969 * safezoneW";
				h="0.77 * safezoneH";
			};
		};
		class controls
		{
			class BP_MapStats: BP_InfoText
			{
				idc=1021;
				text="New Haven";
				x="0.807500 * safezoneW + safezoneX";
				y="0.442 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_Map2Stats: BP_InfoText2
			{
				idc=1022;
				text="New Haven";
				x="0.925000 * safezoneW + safezoneX";
				y="0.523 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_DayStats: BP_InfoText
			{
				idc=1023;
				text="35";
				x="0.937500 * safezoneW + safezoneX";
				y="0.442 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_LocationStats: BP_InfoText
			{
				idc=1024;
				text="AAC Airfield";
				x="0.834383 * safezoneW + safezoneX";
				y="0.480 * safezoneH + safezoneY";
				w="0.13 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_RangerStats: RscStructuredTextStats
			{
				idc=1025;
				text="9999";
				x="0.768000 * safezoneW + safezoneX";
				y="0.625 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_NomadStats: RscStructuredTextStats
			{
				idc=1026;
				text="9999";
				x="0.820500 * safezoneW + safezoneX";
				y="0.625 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_SurvivalistStats: RscStructuredTextStats
			{
				idc=1027;
				text="9999";
				x="0.872500 * safezoneW + safezoneX";
				y="0.625 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_EngineerStats: RscStructuredTextStats
			{
				idc=1028;
				text="9999";
				x="0.926000 * safezoneW + safezoneX";
				y="0.625 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_HunterStats: RscStructuredTextStats
			{
				idc=1029;
				text="9999";
				x="0.768000 * safezoneW + safezoneX";
				y="0.715 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_OutlawStats: RscStructuredTextStats
			{
				idc=1030;
				text="9999";
				x="0.820500 * safezoneW + safezoneX";
				y="0.715 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_IndependentStats: RscStructuredTextStats
			{
				idc=1031;
				text="9999";
				x="0.872500 * safezoneW + safezoneX";
				y="0.715 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_UndeadStats: RscStructuredTextStats
			{
				idc=1032;
				text="9999";
				x="0.926000 * safezoneW + safezoneX";
				y="0.715 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_UndeadKilledStats: BP_InfoText
			{
				idc=1033;
				text="98";
				x="0.811000 * safezoneW + safezoneX";
				y="0.760 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_ZombiesKilledStats: BP_InfoText
			{
				idc=1034;
				text="99";
				x="0.811500 * safezoneW + safezoneX";
				y="0.790 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_HumansKilledStats: BP_InfoText
			{
				idc=1035;
				text="99";
				x="0.811500 * safezoneW + safezoneX";
				y="0.8225 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_HeadshotsStats: BP_InfoText
			{
				idc=1036;
				text="99";
				x="0.811500 * safezoneW + safezoneX";
				y="0.855 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
			class BP_TraveledStats: BP_InfoText
			{
				idc=1037;
				text="99";
				x="0.811500 * safezoneW + safezoneX";
				y="0.885 * safezoneH + safezoneY";
				w="0.104988 * safezoneW";
				h="0.042 * safezoneH";
			};
		};
	};
	/* Anti Ghosting Timer */
	class RscRespawnCounter;
	class RscBPTimer : RscRespawnCounter {
		onLoad = "UInamespace SetVariable ['BP_Timer',_this Select 0];";
	};
	
	/* Remove Retarded UI Titles */
	class SplashNoise : Default {};
	class SplashBohemia : Default {};
	class SplashArma3 : Default {};
	class SplashArma3Lite : Default {};
	class SplashTagline : Default {};
	class SplashESRB : Default {};
	class SplashCopyright : Default {};
	class RscAAN : Default {};
	class RscAANnews : Default {};
	class RscUnitInfoUAV {
		delete RscUnitInfoUAV;
	};
	class RscCommMenuItems {
		delete Controls;
	};
};

/* Loading Screen Stuff - Previously BreakingPoint_UI

class RscDisplayClient : RscStandardDisplay {
	class controlsBackground {
		class LoadingPic : RscPicture {
			text = "\breakingpoint_ui\general\BP_screen_title.jpg";
		};
	};
};

class RscDisplayMPPlayers; //External Class Reference
class RscDisplayClientWait : RscDisplayMPPlayers {
	class LoadingPic : RscPicture {
		text = "\breakingpoint_ui\general\BP_screen_title.jpg";
	};
};

class RscDisplayLoadMission : RscStandardDisplay {
	class controlsBackground {
		class LoadingPic : RscPicture {
			text = "\breakingpoint_ui\general\BP_screen_title.jpg";
		};
	};
};

class RscDisplayLoadMissionBreakingPoint : RscStandardDisplay {
	class controlsBackground {
		class LoadingPic : RscPicture {
			text = "\breakingpoint_ui\general\BP_screen_title.jpg";
		};
	};
};


class RscDisplayStart : RscStandardDisplay {
	class controls {
		class LoadingPic : RscPicture {
			text = "\breakingpoint_ui\general\BP_screen_title.jpg";
		};
	};
};

class RscDisplayLoading {
	class Variants {
		class LoadingOne {
			class controls {
				class LoadingPic : RscPicture {
					x = "SafeZoneX";
					y = "SafeZoneY";
					h = "SafeZoneH";
					w = "SafeZoneW";
					text = "\breakingpoint_ui\general\BP_screen_title.jpg";
				};
			};
		};
		
		class Loading_West1 : LoadingOne {
			class controls : controls {
				class LoadingPic : LoadingPic {
					text = "\breakingpoint_ui\general\BP_screen_title.jpg";
				};
			};
		};
		
		class Loading_West2 : LoadingOne {
			class controls : controls {
				class LoadingPic : LoadingPic {
					text = "\breakingpoint_ui\general\BP_screen_title.jpg";
				};
			};
		};
		
		class Loading_East1 : LoadingOne {
			class controls : controls {
				class LoadingPic : LoadingPic {
					text = "\breakingpoint_ui\general\BP_screen_title.jpg";
				};
			};
		};
		
		class Loading_East2 : LoadingOne {
			class controls : controls {
				class LoadingPic : LoadingPic {
					text = "\breakingpoint_ui\general\BP_screen_title.jpg";
				};
			};
		};
	};
};

*/

class CfgRanks {
	class 0 {
		rank = "Private";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\private_gs.paa";
	};
	
	class 1 {
		rank = "Corporal";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
	};
	
	class 2 {
		rank = "Sergeant";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
	};
	
	class 3 {
		rank = "Lieutenant";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa";
	};
	
	class 4 {
		rank = "Captain";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\captain_gs.paa";
	};
	
	class 5 {
		rank = "Major";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa";
	};
	
	class 6 {
		rank = "Colonel";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
	};
	
	class 7 {
		rank = "General";
		displayName = "Survivor";
		displayNameShort = "Survivor";
		texture = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
	};
};


class RscUAVUAV {
	class Items {
		delete UAVDriver;
		delete UAVGunner;
		delete UAVWatch;
		delete Back;
	};
};

class RscUAVMainMenu {
	title = "$STR_hc_hc";
	atomic = 0;
	vocabulary = "";
	
	class Items {
		delete Move;
		delete Target;
		delete Engage;
		delete Speed;
		delete Mission;
		delete Action;
		delete CombatMode;
		delete Formations;
		delete Team;
		delete Reply;
		delete Back;
	};
};

class RscUAVTeam {};

class RscUAVFormations {
	title = $STR_FORMATION;
	atomic = 0;
	vocabulary = "";
	
	class items {
		delete Column;
		delete ColumnStag;
		delete Wedge;
		delete EchelonL;
		delete EchelonR;
		delete Vee;
		delete Line;
		delete ColumnCompact;
		delete Delta;
	};
};


