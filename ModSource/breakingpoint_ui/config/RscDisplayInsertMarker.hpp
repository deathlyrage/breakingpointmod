class RscDisplayInsertMarker
{
	onLoad="['onLoad',_this,'RscDisplayInsertMarker','GUI'] call compile preprocessfilelinenumbers 'A3\ui_f\scripts\initDisplay.sqf'";
	onUnload="['onUnload',_this,'RscDisplayInsertMarker','GUI'] call compile preprocessfilelinenumbers 'A3\ui_f\scripts\initDisplay.sqf'";
	idd=54;
	movingEnable=0;
	class controls
	{
		delete Picture;
		/*
		class Picture : RscPicture
		{
			colorText[]={0,0,0,1};
			idc=102;
			x=0.259984;
			y=0.4;
			w=0.05;
			h=0.0666667;
		};
		*/
		
		delete Text;
		/*
		class Text : RscEdit
		{
			text="";
			idc=101;
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="10.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete ButtonMenuOK;
		/*
		class ButtonMenuOK : RscButtonMenuOK
		{
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="12.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/

		delete ButtonMenuCancel;
		/*
		class ButtonMenuCancel : RscButtonMenuCancel
		{
			x="19 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="12.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete ButtonMenuInfo;
		/*
		class ButtonMenuInfo : RscButtonMenu
		{
			idc=2400;
			text="Show info";
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="13.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
		
		delete Title;
		/*
		class Title : RscText
		{
			colorBackground[]={"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc=1001;
			text="INSERT MARKER";
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="8.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/

		delete Description;
		/*
		class Description : RscStructuredText
		{
			colorBackground[]={0,0,0,0.7};
			idc=1100;
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="9.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/

		delete Info;
		/*
		class Info : RscStructuredText
		{
			colorBackground[]={0,0,0,0.7};
			idc=1101;
			x="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="11.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		*/
	};

	class controlsBackground
	{
		delete RscText_1000;
		/*
		class RscText_1000 : RscText
		{
			idc=1000;
			x="0 * GUI_GRID_INSERTMARKER_W + GUI_GRID_INSERTMARKER_X";
			y="0 * GUI_GRID_INSERTMARKER_H + GUI_GRID_INSERTMARKER_Y";
			w="8 * GUI_GRID_INSERTMARKER_W";
			h="2.5 * GUI_GRID_INSERTMARKER_H";
			colorBackground[]={0,0,0,0.5};
		};
		*/
	};
};