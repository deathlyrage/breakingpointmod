/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

idd = 101;
onLoad = "[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\Loading\RscDisplayLoading.sqf""";
onUnload = "[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\Loading\RscDisplayLoading.sqf""";

class controlsBackground {
	delete CA_Vignette;
	delete Noise;

	class Black : RscText {
		colorBackground[] = {0, 0, 0, 1};
		x = "safezoneXAbs";
		y = "safezoneY";
		w = "safezoneWAbs";
		h = "safezoneH";
	};

	class Map : RscPicture {
		idc = 999;
		text = "\breakingpoint_ui\loading\main_title_01.jpg";
		colorText[] = {1, 1, 1, 1};
		x = "safezoneX";
		y = "safezoneY";
		w = "safezoneW";
		h = "safezoneH";
	};
};

class controls {
	delete Title;
	delete Name;
	delete Briefing;
	delete Progress;
	delete Progress2;
	delete Date; //
	delete MapBackTop;
	delete MapName;
	delete MapAuthor;
	delete MapBackBottom;
	delete MapDescription;
	delete Mission;
	delete ProgressMap;
	delete ProgressMission;
	delete Disclaimer;
	class LoadingStart : RscControlsGroup {
		idc = 2310;
		x = "0 * safezoneW + safezoneX";
		y = "0 * safezoneH + safezoneY";
		w = "1 * safezoneW";
		h = "1 * safezoneH";
		class controls {

			class Black : RscText {
				colorBackground[] = {0, 0, 0, 1};
				x = "safezoneXAbs";
				y = "safezoneY";
				w = "safezoneWAbs";
				h = "safezoneH";
			};

			delete Noise;

			class Logo : RscPicture {
				idc = 1200;
				text = "\breakingpoint_ui\loading\main_title_01.jpg";
				colorText[] = {1, 1, 1, 1};
				x = "0 * safezoneW";
				y = "0 * safezoneH";
				w = "1 * safezoneW";
				h = "1 * safezoneH";
			};
		};
	};
};
