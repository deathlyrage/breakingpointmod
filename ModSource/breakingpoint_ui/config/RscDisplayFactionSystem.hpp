
class RscDisplayFactionSystem
{
	idd = 6910;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\background.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class BP_Ranger: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\ranger.jpg";
			x = 0.0452187 * safezoneW + safezoneX;
			y = 0.1348 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3894 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;BP_selectClass = 1;";
			action = "closeDialog 0;createDialog 'RscDisplayFactionRanger';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\ranger_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\ranger.jpg'";
		};
		class BP_Nomad: RscActiveText
		{
			idc = 1203;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\nomad.jpg";
			x = 0.258687 * safezoneW + safezoneX;
			y = 0.1326 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;BP_selectClass = 4;";
			action = "closeDialog 0;createDialog 'RscDisplayFactionNomad';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\nomad_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\nomad.jpg'";
		};
		class BP_Hunter: RscActiveText
		{
			idc = 1202;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\hunter.jpg";
			x = 0.546406 * safezoneW + safezoneX;
			y = 0.1304 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;BP_selectClass = 3;";
			action = "closeDialog 0;createDialog 'RscDisplayFactionHunter';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\hunter_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\hunter.jpg'";
		};
		class BP_Outlaw: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\outlaw.jpg";
			x = 0.758844 * safezoneW + safezoneX;
			y = 0.1326 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;BP_selectClass = 2;";
			action = "closeDialog 0;createDialog 'RscDisplayFactionOutlaw';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\outlaw_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\outlaw.jpg'";
		};
		class BP_Undead: RscActiveText
		{
			idc = 1204;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\undead.jpg";
			x = 0.546406 * safezoneW + safezoneX;
			y = 0.555 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionUndead';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\undead_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\undead.jpg'";
		};
		class BP_None: RscActiveText
		{
			idc = 1205;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\none.jpg";
			x = 0.757813 * safezoneW + safezoneX;
			y = 0.555 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionOptOut';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\none_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\none.jpg'";
		};
		class BP_Survivalist: RscActiveText
		{
			idc = 1204;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\survivalist.jpg";
			x = 0.04625 * safezoneW + safezoneX;
			y = 0.555 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSurvivalist';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\survivalist_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\survivalist.jpg'";
		};
		class BP_Engineer: RscActiveText
		{
			idc = 1204;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\engineer_soon.jpg";
			x = 0.258687 * safezoneW + safezoneX;
			y = 0.5572 * safezoneH + safezoneY;
			w = 0.193875 * safezoneW;
			h = 0.3938 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			//action = "closeDialog 0;createDialog 'RscDisplayFactionEngineer';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\engineer_soon_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\engineer_soon.jpg'";
		};
	};
};

class RscDisplayFactionRanger
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\ranger.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 1;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionOutlaw
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\outlaw.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 2;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionHunter
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\hunter.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 3;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionNomad
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\nomad.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 4;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionSurvivalist
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\survivalist.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 5;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionEngineer
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\engineer.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 6;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionUndead
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\undead.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 7;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

class RscDisplayFactionOptOut
{
	idd = 6909;
	enableDisplay = 1;
	class controlsBackground {
		class Mainback : RscPicture {
			idc = 4080;
			text = "\breakingpoint_ui\factions\none.jpg";
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 1 * safezoneH;
		};
	};
	class controls
	{
		class Button_Confirm: RscActiveText
		{
			idc = 1200;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\select.jpg";
			x = 0.49278 * safezoneW + safezoneX;
			y = 0.8718 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;BP_selectClass = 0;";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\select.jpg'";
		};
		class Button_Back: RscActiveText
		{
			idc = 1201;
			style = 48;
			text = "\breakingpoint_ui\factions\buttons\cancel.jpg";
			x = 0.696968 * safezoneW + safezoneX;
			y = 0.8696 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.088 * safezoneH;
			color[] = { 1, 1, 1, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;createDialog 'RscDisplayFactionSystem';";
			onMouseEnter = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel_hover.jpg'";
			onMouseExit = "ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\breakingpoint_ui\factions\buttons\cancel.jpg'";
		};
	};
};

