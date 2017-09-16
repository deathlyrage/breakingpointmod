class CfgPatches
{
	class CARoads
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.10;
		requiredAddons[] = {};
	};
};

class CfgNonAIVehicles
{
  class Land_most_stred30
  {
    model = "\ca\Roads\most_stred30.p3d";
    simulation = "road";
    armor = 50;
    class Destruction
    {
      animations[]=
      {
        {"ca\Roads\Rtm\most_pad_01.rtm",0.2,17},
        {"ca\Roads\Rtm\most_pad_02.rtm",0.2,17},
        {"ca\Roads\Rtm\most_pad_03.rtm",0.2,17},
        {"ca\Roads\Rtm\most_pad_04.rtm",0.2,17},
        {"ca\Roads\Rtm\most_pad_05.rtm",0.2,17}
      };
    };
  };
  class Land_most_bez_lamp : Land_most_stred30
  {
    model = \ca\Roads\most_bez_lamp;
    class Destruction : Destruction {};
  };
  class Land_Kamenny_most30 : Land_most_stred30
  {
    model = "\ca\Roads\Kamenny_most30.p3d";
    class Destruction
    {
      animations[]=
      {
        {"ca\Roads\Rtm\Kamenny_most_01.rtm",0.1,7},
        {"ca\Roads\Rtm\Kamenny_most_02.rtm",0.1,7},
        {"ca\Roads\Rtm\Kamenny_most_03.rtm",0.1,7}
      };
    };
  };
  class Land_Kamenny_most30v2 : Land_Kamenny_most30
  {
    model = \ca\Roads\Kamenny_most30v2;
    class Destruction : Destruction {};
  };
};
