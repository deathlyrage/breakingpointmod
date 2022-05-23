/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define true	1
#define false	0

class CfgPatches {
	class breakingpoint_ui {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_UI_F","A3_UI_F_Bootcamp","A3_UI_F_Heli","A3_Ui_F_Exp","A3_Ui_F_Exp_A"};
	};
};

class CfgFontFamilies
{
	class sketch
	{
		fonts[] = 
		{
			{"breakingpoint_ui\fonts\Sketch\Sketch6","breakingpoint_ui\fonts\Sketch\Sketch6"},
			{"breakingpoint_ui\fonts\Sketch\Sketch10","breakingpoint_ui\fonts\Sketch\Sketch10"},
			{"breakingpoint_ui\fonts\Sketch\Sketch11","breakingpoint_ui\fonts\Sketch\Sketch11"},
			{"breakingpoint_ui\fonts\Sketch\Sketch12","breakingpoint_ui\fonts\Sketch\Sketch12"},
			{"breakingpoint_ui\fonts\Sketch\Sketch13","breakingpoint_ui\fonts\Sketch\Sketch13"},
			{"breakingpoint_ui\fonts\Sketch\Sketch14","breakingpoint_ui\fonts\Sketch\Sketch14"},
			{"breakingpoint_ui\fonts\Sketch\Sketch15","breakingpoint_ui\fonts\Sketch\Sketch15"},
			{"breakingpoint_ui\fonts\Sketch\Sketch16","breakingpoint_ui\fonts\Sketch\Sketch16"},
			{"breakingpoint_ui\fonts\Sketch\Sketch17","breakingpoint_ui\fonts\Sketch\Sketch17"},
			{"breakingpoint_ui\fonts\Sketch\Sketch18","breakingpoint_ui\fonts\Sketch\Sketch18"},
			{"breakingpoint_ui\fonts\Sketch\Sketch19","breakingpoint_ui\fonts\Sketch\Sketch19"},
			{"breakingpoint_ui\fonts\Sketch\Sketch20","breakingpoint_ui\fonts\Sketch\Sketch20"},
			{"breakingpoint_ui\fonts\Sketch\Sketch21","breakingpoint_ui\fonts\Sketch\Sketch21"},
			{"breakingpoint_ui\fonts\Sketch\Sketch22","breakingpoint_ui\fonts\Sketch\Sketch22"},
			{"breakingpoint_ui\fonts\Sketch\Sketch23","breakingpoint_ui\fonts\Sketch\Sketch23"},
			{"breakingpoint_ui\fonts\Sketch\Sketch24","breakingpoint_ui\fonts\Sketch\Sketch24"},
			{"breakingpoint_ui\fonts\Sketch\Sketch25","breakingpoint_ui\fonts\Sketch\Sketch25"},
			{"breakingpoint_ui\fonts\Sketch\Sketch26","breakingpoint_ui\fonts\Sketch\Sketch26"},
			{"breakingpoint_ui\fonts\Sketch\Sketch27","breakingpoint_ui\fonts\Sketch\Sketch27"},
			{"breakingpoint_ui\fonts\Sketch\Sketch28","breakingpoint_ui\fonts\Sketch\Sketch28"},
			{"breakingpoint_ui\fonts\Sketch\Sketch29","breakingpoint_ui\fonts\Sketch\Sketch29"},
			{"breakingpoint_ui\fonts\Sketch\Sketch30","breakingpoint_ui\fonts\Sketch\Sketch30"},
			{"breakingpoint_ui\fonts\Sketch\Sketch31","breakingpoint_ui\fonts\Sketch\Sketch31"},
			{"breakingpoint_ui\fonts\Sketch\Sketch34","breakingpoint_ui\fonts\Sketch\Sketch34"},
			{"breakingpoint_ui\fonts\Sketch\Sketch35","breakingpoint_ui\fonts\Sketch\Sketch35"},
			{"breakingpoint_ui\fonts\Sketch\Sketch37","breakingpoint_ui\fonts\Sketch\Sketch37"},
			{"breakingpoint_ui\fonts\Sketch\Sketch46","breakingpoint_ui\fonts\Sketch\Sketch46"}
		};
	};
};
class CfgMarkers
{
	class AIHunter
	{
	name="Mission";
	icon="\breakingpoint_ui\icons\huntericon.paa";
	color[]={1,1,1,1};
	size=32;
	shadow = 0;
	scope = 2;
	markerClass = "draw";
	};
	class AIIndependent
	{
	name="Mission";
	icon="\breakingpoint_ui\icons\noneicon.paa";
	color[]={1,1,1,1};
	size=32;
	shadow = 0;
	scope = 2;
	markerClass = "draw";
	};
};
class cfgScriptPaths {
	default = "breakingpoint_ui\scripts\GUI\";
	GUI = "breakingpoint_ui\scripts\GUI\";
	IGUI = "breakingpoint_ui\scripts\IGUI\";
	Loading = "breakingpoint_ui\scripts\Loading\";
};

class RscPicture;	// External class reference
class RscStandardDisplay;	// External class reference
class RscText;
class RscLineBreak;
class RscButton;
class RscButtonMenu;
class RscButtonMenuOK;
class RscList;
class RscXListBox;
class RscPictureKeepAspect;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscStructuredText;
class RscControlsGroup;
class RscHTML;
class RscVignette;
class RscFrame;
class RscTitle;

class CA_Mainback;
class CA_Back;
class CA_Title_Back;
class CA_Logo_Small;
class CA_RscButton_dialog;

class CA_IGUI_Title;
class RscGearShortcutButton;
class RscIGUIListNBox;
class RscActiveText;
class RscProgress;
class RscProgressNotFreeze;
class RscButtonTextOnly;
class CA_Title;
class RscShortcutButton;
class CA_Black_Back;
class RscMapControl;
class IGUIBack;
class RscObject;
class RscDisplayGetReady;
class RscListBox;
class RscListNBox;
class RscIGUIShortcutButton;
class RscCombo;
class RscIGUIListBox;
class RscButtonMenuCancel;
class VScrollbar;
class HScrollbar;
class RscListBoxKeys;
class RscXSliderH;
class RscXSliderV;
class RscTextCheckBox;
class RscEdit;
class RscButtonMenuSteam;
class RscBackgroundGUI;
class RscBackgroundGUITop;
class RscBackgroundGUILeft;
class RscBackgroundGUIRight;
class RscBackgroundGUIBottom;
class RscCheckBox;
class RscTree;
class RscDebugConsole;
class RscMessageBox;

class Attributes;

class RscGearTemplates {
	class CA_Tooltip : RscStructuredText {
		idc = 9999;
		x = 0.5;
		y = 0.5;
		w = 0.5;
		h = 0.17;
		colorBackground[] = {0, 0, 0, 0.85};
		size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
		
		class Attributes : Attributes {
			align = "left";
		};
	};
	
	class EmbossIcons {
		uniformTab = "breakingpoint_ui\inventory\slot_uniform.paa";
		vestTab = "breakingpoint_ui\inventory\slot_vest.paa";
		backpackTab = "breakingpoint_ui\inventory\slot_backpack.paa";
		headGearSlot = "breakingpoint_ui\inventory\slot_helmet.paa";
		gogglesSlot = "breakingpoint_ui\inventory\slot_glasses.paa";
		hmdSlot = "breakingpoint_ui\inventory\slot_nvg.paa";
		binocSlot = "breakingpoint_ui\inventory\slot_binocular.paa";
		primarySlot = "breakingpoint_ui\inventory\slot_primary.paa";
		secondarySlot = "breakingpoint_ui\inventory\slot_melee.paa";
		handgunSlot = "breakingpoint_ui\inventory\slot_hgun.paa";
		muzzleSlot = "breakingpoint_ui\inventory\slot_muzzle.paa";
		opticsSlot = "breakingpoint_ui\inventory\slot_top.paa";
		flashlightSlot = "breakingpoint_ui\inventory\slot_side.paa";
		magazineSlot = "breakingpoint_ui\inventory\slot_magazine.paa";
		mapSlot = "breakingpoint_ui\inventory\slot_map.paa";
		compassSlot = "breakingpoint_ui\inventory\slot_compass.paa";
		watchSlot = "breakingpoint_ui\inventory\slot_watch.paa";
		radioSlot = "breakingpoint_ui\inventory\slot_radio.paa";
		gpsSlot = "breakingpoint_ui\inventory\slot_gps.paa";
	};
};

#include "config\RscDisplayInventory.hpp"
#include "config\RscDisplayBPMessage.hpp"
#include "config\RscDisplayDebriefing.hpp"
#include "config\RscDisplayFactionSystem.hpp"
#include "config\RscTitles.hpp"
#include "config\RscDisplayMain.hpp"
#include "config\RscDisplayMultiplayer.hpp"

#include "config\RscDisplayConfigure.hpp"
#include "config\RscDisplayGameOptions.hpp"
#include "config\RscDisplayOptionsLayout.hpp"
#include "config\RscDisplayOptionsAudio.hpp"
#include "config\RscDisplayOptionsVideo.hpp"
#include "config\RscDisplayModLauncher.hpp"
#include "config\RscDisplayNewUser.hpp"
#include "config\RscDisplayLogin.hpp"
#include "config\RscDisplayStart.hpp"

#include "config\RscDisplayDedicatedServerSettings.hpp"
#include "config\RscDisplaySingleMission.hpp"
#include "config\RscDisplayRemoteMissions.hpp"
#include "config\RscDisplayMPInterrupt.hpp"
#include "config\RscDisplayMultiplayerSetup.hpp"
#include "config\RscDisplayInsertMarker.hpp"
#include "config\RscDisplayMPPlayers.hpp"
#include "config\CfgDiary.hpp"

#include "CfgLoadingScreens.hpp"

class RscDisplayLoadingBlack {
	idd = -1;
	enableSimulation = 0;
	
	class controls {
		class FadeEffect : RscText {
			idc = 1099;
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
			colorBackground[] = {0, 0, 0, 1};
		};
	};
};

class CfgInGameUI {
	class PeripheralVision {
		bloodColor[] = {0, 0, 0, 0};
		cueColor[] = {0, 0, 0, 0};
		cueEnemyColor[] = {0, 0, 0, 0};
		cueFriendlyColor[] = {0, 0, 0, 0};
	};
	class Radar {
		left = "0";
		top = "0";
		width = "0";
		height = "0";
		shadow = false;
	};
	class Cursor {
		select = "#(argb,1,1,1)color(0,0,0,0)";
		outArrow = "#(argb,1,1,1)color(0,0,0,0)";
		leader = "#(argb,1,1,1)color(0,0,0,0)";
		mission = "#(argb,1,1,1)color(0,0,0,0)";
	};
	class CommandBar
	{
                elementSpacing=0;
                colorRedTeam[]={1,0,0,0};
                colorBlueTeam[]={0,0,1,0};
                colorGreenTeam[]={0.259,0.463,0.149,0};
                colorYellowTeam[]={0.8,0.8,0,0};
                colorWhiteTeam[]={0.95,0.95,0.95,0};
                colorText[]={1,1,1,0};
                colorIDNone[]={0,0,0,0};
                colorIDNormal[]={0.8,0.8,0.8,0};
                colorIDSelected[]={0,0.6,0,0};
                colorIDSelecting[]={0.8,0.8,0.8,0};
                colorIDPlayer[]={0.8,0.6,0,0};
                class prevPage
                        {
                        color[]={0.259,0.463,0.149,0};
                        shadow=0;
						x=0;
						y=0;
						w=0;
						h=0;
                        texture="A3\ui_f\data\igui\cfg\commandbar\prevPage_ca.paa";
                        };
 
                class nextPage
                        {
                        color[]={0.259,0.463,0.149,0};
                        shadow=0;
						x=0;
						y=0;
						w=0;
						h=0;
                        texture="A3\ui_f\data\igui\cfg\commandbar\nextPage_ca.paa";
                        };
 
                class UnitInfo
                        {
                        w=0;
                        h=0;
                        class GroupIcon
                                {
                                shadow=0;
                                color[]={1,1,1,0};
								x=0;
								y=0;
								w=0;
								h=0;
                                };
 
                        class UnitBackground
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                textureNormal="#(argb,8,8,3)color(1,1,1,1)";
                                textureSelected="#(argb,8,8,3)color(1,1,1,1)";
                                texturePlayer="#(argb,8,8,3)color(1,1,1,1)";
                                textureFocus="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class UnitFocus
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class UnitIcon
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                color[]={1,1,1,1};
                                colorPlayer[]={1,1,1,1};
                                colorNoAmmo[]={0.8,0.4,0.5,1};
                                colorWounded[]={0.8,0,0,1};
                                colorNoFuel[]={0.8,0.7,0,1};
                                colorWoundedFade[]={0,0,0,1};
                                colorFocus[]={0,0,0,1};
                                colorSelected[]={0,0,0,1};
                                colorNormal[]={0,0,0,1};
                                colorDamaged[]={1,0,0,1};
                                shadow=0;
                                };
 
                        class UnitVehicleStatus
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                texture="#(argb,8,8,3)color(0,0,0,1)";
                                };
 
                        class Semaphore
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                color[]={0.8,0,0,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class CommandBackground
                                {
                                color[]={"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
                                shadow=0;
                                texture="\a3\Ui_f\data\IGUI\Cfg\CommandBar\commandBackground_ca.paa";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class HoldFire
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                color[]={1,1,1,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class OrderBackground
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                color[]={1,1,1,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class OrderText
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={1,1,1,0};
                                font="TahomaB";
                                SizeEx=0.05;
                                shadow=0;
                                };
 
                        class VehicleBackground
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                color[]={1,1,1,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=0;
                                };
 
                        class VehicleText
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={1,1,1,0};
                                font="TahomaB";
                                SizeEx=0;
                                shadow=0;
                                };
 
                        class UnitSpecialRole
                                {
                                color[]={1,1,1,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=2;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitRole
                                {
                                color[]={1,1,1,0};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                shadow=2;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitNumberBackground
                                {
                                color[]={"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
                                shadow=0;
                                texture="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitNumberBackground_ca.paa";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitNumberText
                                {
                                text="";
                                font="PuristaMedium";
                                shadow=2;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={0,0,0,0};
                                sizeEx="0";
                                };
 
                        class CommandText
                                {
								text="";
                                color[]={0,0,0,0};
                                font="PuristaMedium";
                                shadow=1;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={0,0,0,0};
                                sizeEx="0";
                                };
 
                        class VehicleNumberText
                                {
								text="";
                                color[]={0,0,0,0};
                                font="PuristaMedium";
                                shadow=1;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={0,0,0,0};
                                sizeEx="0";
                                };
 
                        class VehicleNumberBackground
                                {
                                color[]={"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
                                shadow=0;
                                texture="\a3\Ui_f\data\IGUI\Cfg\CommandBar\vehicleNumberBackground_ca.paa";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class CombatMode
                                {
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                textureMCareless="#(argb,8,8,3)color(1,1,1,1)";
                                textureMSafe="#(argb,8,8,3)color(0,1,0,1)";
                                textureMAware="#(argb,8,8,3)color(1,1,0,1)";
                                textureMCombat="#(argb,8,8,3)color(1,0,0,1)";
                                textureMStealth="#(argb,8,8,3)color(0,0,0,1)";
                                shadow=0;
                                };
 
                        class VehicleStatus
                                {
                                color[]={0,0,0,0};
                                shadow=0;
                                colorDamaged[]={"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",0.8};
                                colorNoAmmo[]={"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",0.6};
                                colorNoFuel[]={"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",0.6};
                                texture="#(argb,8,8,3)color(1,1,1,1)";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitCombatMode
                                {
                                textureMCareless="#(argb,8,8,3)color(1,1,1,1)";
                                textureMSafe="#(argb,8,8,3)color(0,1,0,1)";
                                textureMAware="#(argb,8,8,3)color(1,1,0,1)";
                                textureMCombat="#(argb,8,8,3)color(1,0,0,1)";
                                textureMStealth="#(argb,8,8,3)color(0,0,0,1)";
                                texture="#(argb,8,8,3)color(0,0,0,1)";
                                colorBlue[]={1,0,0,0.5};
                                colorGreen[]={1,0,0,0.7};
                                colorWhite[]={1,0,0,0.7};
                                colorYellow[]={0,0,0,0};
                                colorRed[]={0,0,0,0};
                                shadow=0;
                                class UnitCombatMode
                                        {
                                        textureBlue="#(argb,8,8,3)color(0,0,1,1)";
                                        textureWhite="#(argb,8,8,3)color(1,1,1,1)";
                                        textureYellow="#(argb,8,8,3)color(1,1,0,1)";
                                        textureRed="#(argb,8,8,3)color(1,0,0,1)";
                                        textureGreen="#(argb,8,8,3)color(0,1,0,1)";
                                        };
 
                                textureBlue="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                textureGreen="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                textureWhite="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                textureYellow="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                textureRed="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                text="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitCombatMode_ca.paa";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={0,0,0,0};
                                };
 
                        class UnitNameBackground
                                {
                                colorBlue[]={0,0,0,0};
                                colorGreen[]={0,0,0,0};
                                colorWhite[]={0,0,0,0};
                                colorYellow[]={0,0,0,0};
                                colorRed[]={0,0,0,0};
                                shadow=0;
                                textureNormal="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitNameBackground_normal_ca.paa";
                                texturePlayer="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitNameBackground_normal_ca.paa";
                                textureSelected="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitNameBackground_selected_ca.paa";
                                textureFocus="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitNameBackground_selected_ca.paa";
                                colorNormal[]={"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.8};
                                colorPlayer[]={"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",0.4};
                                colorFocus[]={"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.8};
                                colorSelected[]={"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",0.8};
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                colorText[]={0,0,0,0};
                                };
 
                        class UnitName
                                {
                                colorText[]={1,1,1,1};
                                font="PuristaMedium";
                                shadow=1;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                sizeEx="0";
                                };
 
                        class UnitBehavior
                                {
                                textureMAware="#(argb,8,8,3)color(0,0,0,0)";
                                colorCareless[]={0,0,0,0};
                                colorSafe[]={0,0,0,0};
                                colorAware[]={0,0,0,0};
                                colorCombat[]={1,0.25,0,0.7};
                                colorStealth[]={0,0.8,1,0.7};
                                shadow=0;
                                textureMCareless="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                textureMSafe="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                textureMCombat="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                textureMYellow="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                textureMStealth="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                text="\a3\Ui_f\data\IGUI\Cfg\CommandBar\unitBehavior_ca.paa";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class VehicleRole
                                {
                                color[]={0,0,0,0.5};
                                shadow=0;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class VehicleIcon
                                {
                                color[]={1,1,1,1};
                                shadow=2;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitRank
                                {
                                color[]={0,0,0,0.5};
                                shadow=0;
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        class UnitStatus
                                {
                                color[]={0,0,0,0};
                                shadow=0;
                                colorWounded[]={"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",0.8};
                                colorWoundedFade[]={"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",1};
                                colorNoAmmo[]={"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",0.8};
                                texture="#(argb,8,8,3)color(0,0,0,0)";
                                x=0;
                                y=0;
                                w=0;
                                h=0;
                                };
 
                        font="FontMono";
                        };
 
                left="0";
                top="0";
                width="0";
                height="0";
                imageDefaultWeapons="A3\ui_f\data\igui\cfg\commandbar\imageDefaultWeapons_ca.paa";
                imageNoWeapons="A3\ui_f\data\igui\cfg\commandbar\imageNoWeapons_ca.paa";
                imageCommander="A3\ui_f\data\igui\cfg\commandbar\imageCommander_ca.paa";
                imageDriver="A3\ui_f\data\igui\cfg\commandbar\imageDriver_ca.paa";
                imageGunner="A3\ui_f\data\igui\cfg\commandbar\imageGunner_ca.paa";
                imageCargo="A3\ui_f\data\igui\cfg\commandbar\imageCargo_ca.paa";
                dimm=0;
                };
};

class RscInGameUI {

	class RscUnitInfo {
		onLoad = "[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		onUnload = "[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight", "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_SpeedBackground", "CA_SpeedUnits", "CA_Speed", "CA_ValueFuel"};
		
		class CA_Radar : RscControlsGroupNoScrollbars {
			idc = 2301;
			x = "0";
			y = "0";
			w = "0";
			h = "0";
			//x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_RADAR_X"",		(safezoneX + safezoneW / 2 - 2.8 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			//y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_RADAR_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			//w = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			//h = "5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			
			class controls {
				class CA_RadarBackground : RscPicture {
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1200;
					text = "A3\Ui_f\data\igui\cfg\radar\radarBackground_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class CA_RadarIcon : RscPicture {
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					idc = 250;
					x = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class CA_Heading : RscText {
					idc = 148;
					style = 2;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					text =  359;
					x = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
	};
};


class RscGroupRootMenu {
	title = "";
	atomic = 0;
	vocabulary = "";
	contexsensitive = 1;

	class Items {
		class Empty {
			title = "";
			shortcuts[] = {0};
			command = "";
			show = "0";
			enable = "0";
			speechId = 0;
		};
		class Empty1 : Empty {};
		class EmptyBlank1 : Empty {};
		class Surpress : Empty {};
		class GetIn : Empty {};
		class GetInCurrent : Empty {};
		class GetOut : Empty {};
		class Attack : Empty {};
		class FireAtPosition : Empty {};
		class Heal : Empty {};
		class FirstAid : Empty {};
		class RepairVehicle : Empty {};
		class CancelTarget : Empty {};
		class Copy : Empty {};
		class OpenParachute : Empty {};
		class Move : Empty {};
		class Watch : Empty {};
		class NextWP : Empty {};
		class Repeat : Empty {};
		class Regroup : Empty {};
		class Stop : Empty {};
		class FormationDiamond : Empty {};
		class FormationLine : Empty {};
		class Done : Empty {};
		class OpenFire : Empty {};
		class HoldFire : Empty {};
		class Fail : Empty {};
		class JoinAuto : Empty {};
		class StopAuto : Empty {};
		class OneLess : Empty {};
		class OpenFireAuto : Empty {};
		class HoldFireAuto : Empty {};
		class WhereAreYou : Empty {};
		class Select : Empty {};
		class SelectAdd : Empty {};
		class Deselect : Empty {};
		class UserRadio : Empty {};
		class SelectUnitFromBar : Empty {};
		class DeselectUnitFromBar : Empty {};
		class SelectVehicleFromBar : Empty {};
		class DeselectVehicleFromBar : Empty {};
		class SelectTeamFromBar : Empty {};
		class DeselectTeamFromBar : Empty {};
		class SwitchToLeader : Empty {};
		class SwitchToSelected : Empty {};
		class Team : Empty {};
		class Injured : Empty {};
		class AmmoLow : Empty {};
		class FuelLow : Empty {};
		class Communication : Empty {};
		class HealSelf : Empty {};
		class PatchSoldier : Empty {};
	};
};


class RscHCMainMenu {
	title = "";
	atomic = 0;
	vocabulary = "";
	
	class Items {
		class Empty {
			title = "";
			shortcuts[] = {};
			show = "0";
			enable = "0";
			command = 0;
			speechId = 0;
		};
		class Move : Empty {};
		class Target : Empty {};
		class Engage : Empty {};
		class Speed : Empty {};
		class Mission : Empty {};
		class Action : Empty {};
		class CombatMode : Empty {};
		class Formations : Empty {};
		class Team : Empty {};
		class Reply : Empty {};
		class Back {
			title = "";
			shortcuts[] = {BACK};
			command = -4;
			speechId = 0;
		};
	};
};


class RscSubmenu;

class RscMenuReply : RscSubmenu {
	title = "";
	class Items {
		class Empty {
			title = "";
			shortcuts[] = {};
			command = "";
			enable = "0";
		};
		class Done : Empty {};
		class Fail : Empty {};
		class RireReady : Empty {};
		class FireNotReady : Empty {};
		class Repeat : Empty {};
		class Copy : Empty {};
		class Separator : Empty {};
		class Communication : Empty {};
		class UserRadio : Empty {};
		class Radio : Empty {};
	};
};


class RscMenuMove : RscSubmenu {
	title = "";
	vocabulary = "";
	
	class Items {
		class Empty {
			title = "";
			shortcuts[] = {};
			command = "";
			enable = "0";
		};
		class Join : Empty {};
		class Separator1 : Empty {};
		class Advance : Empty {};
		class StayBack : Empty {};
		class FlankLeft : Empty {};
		class FlankRight : Empty {};
		class Separator2 : Empty {};
		class Stop : Empty {};
		class Expect : Empty {};
		class Separator3 : Empty {};
		class Hide : Empty {};
		class NextWP : Empty {};
	};
};


class RscCallSupport : RscSubmenu {
	title = "";
	vocabulary = "";
	
	class Items {
		class Empty {
			title = "";
			shortcuts[] = {};
			command = "";
			enable = "0";
		};
		class Medic : Empty {};
		class Ambulance : Empty {};
		class Repair : Empty {};
		class Rearm : Empty {};
		class Refuel : Empty {};
		class Done : Empty {};
	};
};

class CfgCommunicationMenu {
	class Default {
		text = "";
		submenu = "";
		expression = "";
		icon = "\a3\Ui_f\data\GUI\Cfg\CommunicationMenu\call_ca.paa";
		iconText = "";
		cursor = "";
		enable = "";
	};
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	delete G;
	delete H;
	delete I;
	delete J;
	delete K;
	delete L;
	delete M;
	delete N;
	delete O;
	delete P;
	delete Q;
	delete R;
	delete S;
	delete T;
	delete U;
	delete V;
	delete W;
	delete X;
	delete Y;
	delete Z;
	delete Call;
	delete Attack;
	delete Defend;
	delete ArtilleryBase;
	delete MortarBase;
	delete CASBase;
	delete SupplyDropBase;
	delete TransportBase;
};

class CfgVideoOptions
{
	class Visibility
	{
		minValue = 500;
		maxValue = 10000;
	};
	class ObjectsVisibility
	{
		minValue = 500;
		maxValue = 5000;
	};
	class ShadowsVisibility
	{
		minValue = 30;
		maxValue = 100;
	};
	class PiP
	{
		class Disabled
		{
			text = "Disabled";
			value = 0;
		};
		class VeryLow
		{
			text = "Low";
			value = 500;
		};
		class Low
		{
			text = "Standard";
			value = 800;
		};
		delete High;
		delete Normal;
		delete VeryHigh;
		delete Ultra;
	};
	class TextureQuality
	{
		class VeryLow
		{
			text = "Very Low";
			mipBias = 13;
			vramNeeded = 0;
		};
	};
	class TerrainQuality
	{
		class Low
		{
			terrainGrid = 25;
			text = "Standard";
		};
		class Normal
		{
			terrainGrid = 12.5;
			text = "High";
		};
		class High
		{
			terrainGrid = 6.25;
			text = "Very High";
		};
		class VeryHigh
		{
			terrainGrid = 3.125;
			text = "Ultra";
		};
		delete VeryLow;
	};
	class WaterSSReflectionsQuality
	{
		delete Normal;
		delete High;
		class Disabled
		{
			text = "Disabled";
			value = 0;
		};
		class Low
		{
			text = "Standard";
			value = 0.3;
		};
	};
	class ShadowQuality
	{
		delete Disabled;
	};
	class ATOCQuality
	{
		class Disabled
		{
			grass = 0;
			newTrees = 0;
			oldTrees = 0;
			other = 0;
			text = "Disabled";
		};
		delete All;
		delete Grass;
		delete OldTreeGrass;
		delete OldTreeNewTree;
		delete OldTree;
		delete NewTreeGrass;
		delete NewTree;
	};
};