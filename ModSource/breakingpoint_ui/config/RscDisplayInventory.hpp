#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW 10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_XKEYDESC 40
#define CT_XBUTTON 41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_USER 99
#define CT_MAP 100
#define CT_MAP_MAIN 101
#define ST_POS 0x0F
#define ST_HPOS 0x03
#define ST_VPOS 0x0C
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0c
#define ST_TYPE 0xF0
#define ST_SINGLE 0
#define ST_MULTI 16
#define ST_TITLE_BAR 32
#define ST_PICTURE 48
#define ST_FRAME 64
#define ST_BACKGROUND 80
#define ST_GROUP_BOX 96
#define ST_GROUP_BOX2 112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE 144
#define ST_WITH_RECT 160
#define ST_LINE 176
#define FontM "Zeppelin32"
#define LB_TEXTURES 0x10
#define LB_MULTI 0x20

class RscDisplayInventory 
{
	//onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	//onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	//idd = 602;
	//enableSimulation = 1;
	
	scriptName = "RscDisplayInventory";
	scriptPath = IGUI;
	onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	idd = 602;
	enableSimulation = 1;
	
	
	class Objects
	{
		class Ground_3dPreview
		{
			idc = 9999;
			//x = 0.146282 * safezoneW + safezoneX;
			//y = 0.2118 * safezoneH + safezoneY;
			//w = 0.139219 * safezoneW;
			//h = 0.099 * safezoneH;
			
			x = 0.216282 * safezoneW + safezoneX;
			y = 0.2518 * safezoneH + safezoneY;
			z = 3.2;
			
			//onObjectMoved = "systemChat str _this";
			onObjectMoved = "";
 
			//idc = -1; 
			type = 82;
			model = "\breakingpoint_weapons\models\M249\BP_M249.p3d";
			scale = 1;
 
			direction[] = {0, -0.35, -0.65};
			up[] = {0, 0.65, -0.35}; 
 
			//position[] = {0,0,0.2}; optional
			//positionBack[] = {0,0,1.2}; //.optional
 
			xBack = 0.5;
			yBack = 0.5;
			zBack = 1.2;
 
			inBack = 0;
			enableZoom = 1;
			zoomDuration = 0.001;
		};
	};
	
	
	class Colors {
		dragValidBgr[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
		dragInvalidBgr[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		dragValidBar[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])", 0.5};
		dragInvalidBar[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		progressBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 1};
		progressBarBgr[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])", 0.75};
		highlight[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
	};
	
	class controlsBackground 
	{
		class Background: RscPicture
		{
			idc = 1000;
			text = "\breakingpoint_ui\inventory\background_inventory_1.paa";
			x = 0.262815 * safezoneW + safezoneX;
			y = 0.126 * safezoneH + safezoneY;
			w = 0.510469 * safezoneW;
			h = 0.748 * safezoneH;
		};
		
		class CA_ContainerBackground : RscText {
			idc = 1001;
			style = 48;
			text = "\breakingpoint_ui\inventory\background_ground_1.paa";
			x = -0.227031 * safezoneW + safezoneX;
			y = 0.148 * safezoneH + safezoneY;
			w = 0.541406 * safezoneW;
			h = 0.759 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "";
			onMouseLeave = "";
			onMouseDown = "";
			//colorBackground[] = {0.05, 0.05, 0.05, 0.7};
		};
		
		class BP_HealthHuman: RscPicture
		{
			idc = 1229;
			text = "\breakingpoint_ui\inventory\health_human.paa";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.1194 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.176 * safezoneH;
		};
		
		class BP_HealthDog: RscPicture
		{
			idc = 1230;
			text = "\breakingpoint_ui\inventory\health_dog.paa";
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.1194 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.176 * safezoneH;
		};
		
		class Player_Food: RscPicture
		{
			idc = 1233;
			text = "\breakingpoint_ui\inventory\icon_food.paa";
			x = 0.332938 * safezoneW + safezoneX;
			y = 0.2602 * safezoneH + safezoneY;
			w = 0.0154688 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class Player_Water: RscPicture
		{
			idc = 1237;
			text = "\breakingpoint_ui\inventory\icon_water.paa";
			x = 0.342219 * safezoneW + safezoneX;
			y = 0.2602 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class Dog_Food: RscPicture
		{
			idc = 1235;
			text = "\breakingpoint_ui\inventory\icon_food.paa";
			x = 0.44225 * safezoneW + safezoneX;
			y = 0.2602 * safezoneH + safezoneY;
			w = 0.0154688 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class Dog_Water: RscPicture
		{
			idc = 1236;
			text = "\breakingpoint_ui\inventory\icon_water.paa";
			x = 0.451532 * safezoneW + safezoneX;
			y = 0.2602 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.033 * safezoneH;
		};
	};
	
	class controls {
		delete Background;
		delete Title;
		delete ButtonOK;
		delete ButtonCancel;
		
		delete CA_ContainerBackground;
		/*
		class CA_ContainerBackground : RscText {
			idc = 1001;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05, 0.05, 0.05, 0.7};
		};
		*/
		
		delete CA_PlayerBackground;
		/*
		class CA_PlayerBackground : RscText {
			idc = 1002;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "22 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05, 0.05, 0.05, 0.7};
		};
		*/
		
		delete TitleBackground;
		/*
		class TitleBackground : RscText {
			idc = 1020;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.1, 0.1, 0.1, 1};
		};
		*/
		
		delete PlayersName;
		/*
		class PlayersName : RscText {
			idc = 111;
			text = $STR_DIARY_PLAYER_NAME;
			x = "15.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete RankBackground;
		/*
		class RankBackground : RscText {
			idc = 1014;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1, 1, 1, 0.2};
		};
		*/
		
		delete RankPicture;
		/*
		class RankPicture : RscPicture {
			idc = 1203;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete ButtonBack;
		/*
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
		*/
		
		class Button_Close: RscActiveText
		{
			idc = 1229;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_close.paa";
			x = 0.546406 * safezoneW + safezoneX;
			y = 0.7024 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};

		class Button_Move: RscActiveText
		{
			idc = 1230;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_move.paa";
			x = 0.578376 * safezoneW + safezoneX;
			y = 0.7024 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
			movingEnable = 1;
			moving = 1;
		};
		
		class Button_Help: RscStructuredText
		{
			idc = 1232;
			text = "<a href='https://github.com/deathlyrage/breakingpointmod/wiki/'><img size='1.72' image='\breakingpoint_ui\inventory\button_help_normal.paa'/></a>";
			x = 0.609313 * safezoneW + safezoneX;
			y = 0.7024 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
			onMouseEnter = "(_this select 0) ctrlSetStructuredText parseText ""<a href='https://github.com/deathlyrage/breakingpointmod/wiki/'><img size='1.72' image='\breakingpoint_ui\inventory\button_help_hover.paa'/></a>""";
			onMouseExit = "(_this select 0) ctrlSetStructuredText parseText ""<a href='https://github.com/deathlyrage/breakingpointmod/wiki/'><img size='1.72' image='\breakingpoint_ui\inventory\button_help_normal.paa'/></a>""";
		};

		class Button_Skin: RscActiveText
		{
			idc = 1231;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_skin.paa";
			x = 0.640251 * safezoneW + safezoneX;
			y = 0.7002 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0)";
		};
		
		
		class Button_TakeAll: RscActiveText
		{
			idc = 1239;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_takeall.paa";
			x = 0.218471 * safezoneW + safezoneX;
			y = 0.7662 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\inventory\button_takeall_hover.paa'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\inventory\button_takeall.paa'";
		};
		
		delete BackgroundSlotPrimaryMagazineGL;
		
		
		delete BackgroundSlotPrimary;
		/*
		class BackgroundSlotPrimary : RscPicture {
			idc = 1242;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotPrimaryMuzzle;
		/*
		class BackgroundSlotPrimaryMuzzle : BackgroundSlotPrimary {
			idc = 1243;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotPrimaryFlashlight;
		/*
		class BackgroundSlotPrimaryFlashlight : BackgroundSlotPrimary {
			idc = 1244;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotPrimaryOptics;
		/*
		class BackgroundSlotPrimaryOptics : BackgroundSlotPrimary {
			idc = 1245;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotPrimaryMagazine;
		/*
		class BackgroundSlotPrimaryMagazine : BackgroundSlotPrimary {
			idc = 1246;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotSecondary;
		/*
		class BackgroundSlotSecondary : BackgroundSlotPrimary {
			idc = 1247;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotSecondaryMuzzle;
		/*
		class BackgroundSlotSecondaryMuzzle : BackgroundSlotPrimary {
			idc = 1248;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotSecondaryFlashlight;
		/*
		class BackgroundSlotSecondaryFlashlight : BackgroundSlotPrimary {
			idc = 1249;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotSecondaryOptics;
		/*
		class BackgroundSlotSecondaryOptics : BackgroundSlotPrimary {
			idc = 1250;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotSecondaryMagazine;
		/*
		class BackgroundSlotSecondaryMagazine : BackgroundSlotPrimary {
			idc = 1251;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHandgun;
		/*
		class BackgroundSlotHandgun : BackgroundSlotPrimary {
			idc = 1252;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHandgunMuzzle;
		/*
		class BackgroundSlotHandgunMuzzle : BackgroundSlotPrimary {
			idc = 1253;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHandgunFlashlight;
		/*
		class BackgroundSlotHandgunFlashlight : BackgroundSlotPrimary {
			idc = 1254;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHandgunOptics;
		/*
		class BackgroundSlotHandgunOptics : BackgroundSlotPrimary {
			idc = 1255;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHandgunMagazine;
		/*
		class BackgroundSlotHandgunMagazine : BackgroundSlotPrimary {
			idc = 1256;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHeadgear;
		/*
		class BackgroundSlotHeadgear : BackgroundSlotPrimary {
			idc = 1257;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotGoggles;
		/*
		class BackgroundSlotGoggles : BackgroundSlotPrimary {
			idc = 1258;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotHMD;
		/*
		class BackgroundSlotHMD : BackgroundSlotPrimary {
			idc = 1259;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotBinoculars;
		/*
		class BackgroundSlotBinoculars : BackgroundSlotPrimary {
			idc = 1260;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotMap;
		/*
		class BackgroundSlotMap : BackgroundSlotPrimary {
			idc = 1261;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotGPS;
		/*
		class BackgroundSlotGPS : BackgroundSlotPrimary {
			idc = 1262;
			x = "17.32 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotCompass;
		/*
		class BackgroundSlotCompass : BackgroundSlotPrimary {
			idc = 1263;
			x = "21.76 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotRadio;
		/*
		class BackgroundSlotRadio : BackgroundSlotPrimary {
			idc = 1264;
			x = "19.54 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete BackgroundSlotWatch;
		/*
		class BackgroundSlotWatch : BackgroundSlotPrimary {
			idc = 1265;
			x = "23.98 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete ExternalContainerBackground;
		/*
		class ExternalContainerBackground : RscPicture {
			colorText[] = {1, 1, 1, 0.1};
			idc = 1240;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete PlayerContainerBackground;
		/*
		class PlayerContainerBackground : ExternalContainerBackground {
			idc = 1241;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		class BaseGroundTab : RscActiveText {
			idc = -1;
			colorBackgroundSelected[] = {1, 1, 1, 1};
			colorFocused[] = {1, 1, 1, 0};
			soundDoubleClick[] = {"", 0.1, 1};
			color[] = {1, 1, 1, 1};
			colorBackground[] = {0, 0, 0, 1};
		};
		
		class Image_Ground : RscText {
			idc = 6320;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_ground.paa";
			x = 0.146281 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.022 * safezoneH;
			color[] =  {255, 255, 255, 0.5};
			colorActive[] = {255, 255, 255, 1};
		};
		
		class Image_Crate : RscText {
			idc = 6400;
			style = 48;
			text = "\breakingpoint_ui\inventory\button_crate.paa";
			x = 0.214347 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			color[] =  {255, 255, 255, 0.5};
			colorActive[] = {255, 255, 255, 1};
		};
		
		class GroundTab : BaseGroundTab {
			idc = 6321;
			style = 48;
			x = 0.146281 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackgroundSelected[] = {0, 0, 0, 0};
			colorFocused[] = {0, 0, 0, 0};
			color[] = {0, 0, 0, 0};
			colorBackground[] = {0, 0, 0, 0};
			onMouseButtonClick = "";
		};
		
		
		class SoldierTab : BaseGroundTab {
			idc = 6401;
			style = 48;
			x = 0.214347 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackgroundSelected[] = {0, 0, 0, 0};
			colorFocused[] = {0, 0, 0, 0};
			color[] = {0, 0, 0, 0};
			colorBackground[] = {0, 0, 0, 0};
			onMouseButtonClick = "";
		};
		
		/*
		class GroundContainerBackground: RscPicture
		{
			idc = -1;
			text = "\breakingpoint_ui\inventory\background_ground.paa";
			x = -0.103281 * safezoneW + safezoneX;
			y = 0.148 * safezoneH + safezoneY;
			w = 0.417656 * safezoneW;
			h = 0.748 * safezoneH;
		};
		*/
		
		/*
		class RscListBox
		{
				access=0;
				type=5;
				w=0.4;
				h=0.4;
				rowHeight=0;
				colorText[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.25};
				colorScrollbar[]={1,0,0,0};
				colorSelect[]={0,0,0,1};
				colorSelect2[]={0,0,0,1};
				colorSelectBackground[]={0.95,0.95,0.95,1};
				colorSelectBackground2[]={1,1,1,0.5};
				colorBackground[]={0,0,0,0.3};
				soundSelect[]={"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
				arrowEmpty="#(argb,8,8,3)color(1,1,1,1)";
				arrowFull="#(argb,8,8,3)color(1,1,1,1)";
				class ScrollBar
						{
						color[]={1,1,1,0.6};
						colorActive[]={1,1,1,1};
						colorDisabled[]={1,1,1,0.3};
						shadow=0;
						thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
						arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
						arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
						border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
						};
		 
				style=16;
				font="PuristaMedium";
				sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				shadow=0;
				colorShadow[]={0,0,0,0.5};
				color[]={1,1,1,1};
				period=1.2;
				maxHistoryDelay=1;
				autoScrollSpeed=-1;
				autoScrollDelay=5;
				autoScrollRewind=0;
		 };
		*/

		class GroundContainer : RscListBox {
			idc = 632;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {0, 0, 0, 0};
			//itemBackground[] = {1, 1, 1, 0.1};
			itemBackground[] = {1, 1, 1, 0};
			
			colorSelect[]={0,0,0,0.5};
			colorSelect2[]={0,0,0,0.5};
			colorSelectBackground[]={0.95,0.95,0.95,0.5};
			colorSelectBackground2[]={1,1,1,0.25};

			itemSpacing = 0.001;
			//x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.147313 * safezoneW + safezoneX;
			y = 0.3372 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.407 * safezoneH;

			style = LB_TEXTURES; //style=16;
			shadow=0;
			font="PuristaMedium";
			color[]={0.95,0.95,0.95,1};
			colorDisabled[]={1,1,1,0.25};
			period=1.2;
			
			arrowFull="\breakingpoint_ui\inventory\scrollbar\ground\arrowFull_ca.paa";
			arrowEmpty="\breakingpoint_ui\inventory\scrollbar\ground\arrowEmpty_ca.paa";
			class ListScrollBar
			{
				color[]={1,1,1,0.6};
				colorActive[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.3};
				shadow=0;
				thumb="\breakingpoint_ui\inventory\scrollbar\ground\thumb_ca.paa";
				arrowFull="\breakingpoint_ui\inventory\scrollbar\ground\arrowFull_ca.paa";
				arrowEmpty="\breakingpoint_ui\inventory\scrollbar\ground\arrowEmpty_ca.paa";
				border="\breakingpoint_ui\inventory\scrollbar\ground\border_ca.paa";
			};
		};
		
		class SoldierContainer : GroundContainer {
			idc = 640;
			arrowFull="\breakingpoint_ui\inventory\scrollbar\inventory\arrowFull_ca.paa";
			arrowEmpty="\breakingpoint_ui\inventory\scrollbar\inventory\arrowEmpty_ca.paa";
			class ListScrollBar
			{
				color[]={1,1,1,0.6};
				colorActive[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.3};
				shadow=0;
				thumb="\breakingpoint_ui\inventory\scrollbar\inventory\thumb_ca.paa";
				arrowFull="\breakingpoint_ui\inventory\scrollbar\inventory\arrowFull_ca.paa";
				arrowEmpty="\breakingpoint_ui\inventory\scrollbar\inventory\arrowEmpty_ca.paa";
				border="\breakingpoint_ui\inventory\scrollbar\inventory\border_ca.paa";
			};
		};
		
		class GroundFilter : RscCombo {
			idc = 6554;
			//x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class GroundLoad : RscProgress {
			idc = 6307;
			texture = "";
			textureExt = "";
			colorBar[] = {0.9, 0.9, 0.9, 0.9};
			colorExtBar[] = {1, 1, 1, 1};
			colorFrame[] = {1, 1, 1, 1};
			//x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.224657 * safezoneW + safezoneX;
			y = 0.7508 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.0055 * safezoneH;
		};
		
		class SlotPrimary : BaseGroundTab {
			idc = 610;
			style = 0x30 + 0x800;
			color[] = {1, 1, 1, 1};
			colorBackground[] = {1, 1, 1, 0};
			colorBackgroundSelected[] = {1, 1, 1,0};
			colorFocused[] = {0, 0, 0, 0};
			canDrag = 1;
			x = 0.547438 * safezoneW + safezoneX;
			y = 0.4318 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.077 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryMuzzle : SlotPrimary {
			idc = 620;
			x = 0.579406 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryMagazineGL : SlotPrimary {
			idc = 644;
			x = 0.669125 * safezoneW + safezoneX;
			y = 0.438 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryUnderBarrel : SlotPrimary {
			idc = 641;
			x = 0.639219 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryGrip : SlotPrimary {
			idc = -1;
			w = 0;
			h = 0;
			x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryFlashlight : SlotPrimary {
			idc = 622;
			x = 0.5495 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryOptics : SlotPrimary {
			idc = 621;
			x = 0.609312 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotPrimaryMagazine : SlotPrimary {
			idc = 623;
			x = 0.669125 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondary : SlotPrimary {
			idc = 611;
			x = 0.547438 * safezoneW + safezoneX;
			y = 0.3746 * safezoneH + safezoneY;
			w = 0.149531 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryUnderBarrel : SlotPrimary {
			idc = 642;
			//x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "14.59 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryMuzzle : SlotPrimary {
			idc = 624;
			//x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryGrip : SlotPrimary {
			idc = -1;
			//w = 0;
			//h = 0;
			//x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryFlashlight : SlotPrimary {
			idc = 626;
			//x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryOptics : SlotPrimary {
			idc = 625;
			//x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotSecondaryMagazine : SlotPrimary {
			idc = 627;
			//x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgun : SlotPrimary {
			idc = 612;
			x = 0.55053 * safezoneW + safezoneX;
			y = 0.5638 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.077 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunMuzzle : SlotPrimary {
			idc = 628;
			x = 0.579406 * safezoneW + safezoneX;
			y = 0.6518 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunUnderBarrel : SlotPrimary {
			idc = 643;
			x = 0.639219 * safezoneW + safezoneX;
			y = 0.6518 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunGrip : SlotPrimary {
			idc = -1;
			w = 0;
			h = 0;
			x = "39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunFlashlight : SlotPrimary {
			idc = 630;
			x = 0.5495  * safezoneW + safezoneX;
			y = 0.6518 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunOptics : SlotPrimary {
			idc = 629;
			x = 0.609312 * safezoneW + safezoneX;
			y = 0.6518 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHandgunMagazine : SlotPrimary {
			idc = 631;
			x = 0.669125 * safezoneW + safezoneX;
			y = 0.6518 * safezoneH + safezoneY;
			w = 0.0257812 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHeadgear : SlotPrimary {
			idc = 6240;
			x = 0.547438 * safezoneW + safezoneX;
			y = 0.3064 * safezoneH + safezoneY;
			w = 0.0358875 * safezoneW;
			h = 0.0638 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotGoggles : SlotPrimary {
			idc = 6216;
			x = 0.584564 * safezoneW + safezoneX;
			y = 0.3064 * safezoneH + safezoneY;
			w = 0.0358875 * safezoneW;
			h = 0.0638 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotHMD : SlotPrimary {
			idc = 6217;
			x = 0.622728 * safezoneW + safezoneX;
			y = 0.3064 * safezoneH + safezoneY;
			w = 0.0358875 * safezoneW;
			h = 0.0638 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotBinoculars : SlotPrimary {
			idc = 6238;
			x = 0.660876 * safezoneW + safezoneX;
			y = 0.3064 * safezoneH + safezoneY;
			w = 0.0358875 * safezoneW;
			h = 0.0638 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotMap : SlotPrimary {
			idc = 6211;
			x = 0.345314 * safezoneW + safezoneX;
			y = 0.7178 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotGPS : SlotPrimary {
			idc = 6215;
			x = 0.409251 * safezoneW + safezoneX;
			y = 0.7178 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotCompass : SlotPrimary {
			idc = 6212;
			x = 0.473188 * safezoneW + safezoneX;
			y = 0.7178 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotRadio : SlotPrimary {
			idc = 6214;
			x = 0.345314 * safezoneW + safezoneX;
			y = 0.7596 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class SlotWatch : SlotPrimary {
			idc = 6213;
			x = 0.409251 * safezoneW + safezoneX;
			y = 0.7596 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class UniformTab : BaseGroundTab {
			idc = 6332;
			x = 0.330876 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
			colorBackground[] = {1, 1, 1, 0.5};
		};
		
		class UniformSlot : SlotPrimary {
			idc = 6331;
			//x = "15.35 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.330876 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class UniformLoad : GroundLoad {
			idc = 6304;
			//x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.332938 * safezoneW + safezoneX;
			y = 0.3636 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.011 * safezoneH;
		};
		
		class UniformContainer : SoldierContainer {
			idc = 633;
			x = 0.331906 * safezoneW + safezoneX;
			y = 0.3856 * safezoneH + safezoneY;
			w = 0.201094 * safezoneW;
			h = 0.286 * safezoneH;
		};
		
		class VestTab : UniformTab {
			idc = 6382;
			x = 0.398939 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
		};
		
		class VestSlot : SlotPrimary {
			idc = 6381;
			//x = "19.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.398939 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class VestLoad : GroundLoad {
			idc = 6305;
			//x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.402031 * safezoneW + safezoneX;
			y = 0.3636 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.011 * safezoneH;
		};
		
		class VestContainer : UniformContainer {
			idc = 638;
		};
		
		class BackpackTab : UniformTab {
			idc = 6192;
			x = 0.468033 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
		};
		
		class BackpackSlot : SlotPrimary {
			idc = 6191;
			//x = "22.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.468033 * safezoneW + safezoneX;
			y = 0.3086 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.066 * safezoneH;
			colorText[] = {0, 0, 0, 0.5};
		};
		
		class BackpackLoad : GroundLoad {
			idc = 6306;
			//x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.471124 * safezoneW + safezoneX;
			y = 0.3636 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.011 * safezoneH;
		};
		
		class BackpackContainer : UniformContainer {
			idc = 619;
		};
		
		class TotalLoad : GroundLoad {
			idc = 6308;
			//x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0.478344 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.011 * safezoneH;
		};
		
		class ContainerMarker : BaseGroundTab {
			idc = 6325;
			//x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class GroundMarker : ContainerMarker {
			idc = 6385;
			//x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		
		class SoldierMarker : ContainerMarker {
			idc = 6405;
			//x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			//y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			//w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
	};
};
