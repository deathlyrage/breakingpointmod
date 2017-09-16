
class RscDisplayBPMessage
{
	idd = 6908;
	enableDisplay = 1;
	class controls
	{
		class BP_Message_Ok: RscButton
		{
			idc = 1600;
			text = "Ok";
			x = 0.45 * safezoneW + safezoneX;
			y = 0.4 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.1 * safezoneH;
			tooltip = "Ok";
			default = 1;
			action = "closeDialog 0;";
		};
	};
};