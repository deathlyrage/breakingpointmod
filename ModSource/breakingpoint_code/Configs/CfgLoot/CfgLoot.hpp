/*
  Breaking Point Mod for Arma 3

  Released under Arma Public Share Like Licence (APL-SA)
  https://www.bistudio.com/community/licenses/arma-public-license-share-alike

  Alderon Games Pty Ltd
*/

class CfgLoot 
{
	trash[] = {
		{
			"ItemBook1",
			"ItemBook2",
			"ItemBook3",
			"ItemMug",
			"ItemBrick1",
			"ItemBrick2",
			"ItemPottery",
			"ItemVideoTape",
			"ItemZipDisk",
			"ItemCards",
			"ItemTennisBall",
			"ItemToiletPaper",
			"ItemGlue",
			"ItemDuctTape",
			"ItemWaterTape",
			"ItemGlue",
			"BP_AlarmClock_Black",
			"BP_AlarmClock_Red"
		},
		{
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9,
			0.9
		}
	};
	civilian[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"BP_7Rnd_45acp",
			"BP_16Rnd_9x21_Mag",
			"BP_15Rnd_9x19OVP",
			"BP_12Rnd_9x18"
		},
		{
			0.06,	//venda
			0.06,	//painkiller
			0.02,	//m1911
			0.04,	//browning
			0.03,	//mksd
			0.01	//m93
			
		}
	};
    food[] = {
		{
			"ItemSoda1",
			"ItemSoda2",
			"ItemSoda3",
			"ItemSoda4",
			"ItemSoda5",
			"ItemCereal1",
			"ItemCereal2",
			"ItemCereal3",
			"ItemCereal4",
			"ItemCereal5",
			"ItemCan1",
			"ItemCan2",
			"ItemCan3",
			"ItemCan4",
			"ItemCan5"
			
		},
		{
			0.02, //ItemSoda1
			0.02, //ItemSoda2
			0.02, //ItemSoda3
			0.02, //ItemSoda4
			0.02, //ItemSoda5
			0.02, //ItemCereal1
			0.02, //ItemCereal2
			0.02, //ItemCereal3
			0.02, //ItemCereal4
			0.01, //ItemCereal5
			0.02, //ItemCan1
			0.02, //ItemCan2
			0.02, //ItemCan3
			0.02, //ItemCan4
			0.02 //ItemCan5
		}
	};
	generic[] = {
		{
			"Waterbot",
			"ItemBandage",
			"ItemBrick1",
			"ItemBrick2",
			"ItemAntibiotic",
			"BP_16Rnd_9x21_Mag",
			"ItemPainkiller",
			"BP_7Rnd_45acp",
			"BP_6Rnd_44Mag",
			"BP_10Rnd_303_Mag",
			"BP_12Rnd_9x18",
			"ItemKnife",
			"ChemG",
			"ChemR",
			"ChemY",
			"ChemB",
			"BP_AlarmClock_Black",
			"BP_AlarmClock_Red"
		},
		{
			0.03,
			0.11,
			0.10,
			0.10,
			0.07,
			0.07,
			0.06,
			0.01,	//m1911
			0.01,	//browning
			0.02,	//m93
			0.04,	//ppk
			0.05,
			0.08,
			0.08,
			0.08,
			0.08,
			0.10,
			0.10
		}
	};
	medical[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"ItemMorphine",
			"ItemFieldDressing",
			"ItemAntibiotic"
		},
		{
			0.8,
			0.5,
			0.5,
			0.2,
			0.1
		}
	};
	hospital[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"ItemMorphine",
			"ItemFieldDressing",
			"ItemAntibiotic"
		},
		{
			0.33,
			0.17,
			0.13,
			0.09,
			0.06
		}
	};
	military[] = {
		{
			"ItemBandage",
			"ItemAntibiotic",
			"ItemPainkiller",
			"ItemMorphine",
			"BP_5Rnd_762x51_Mag",
			"BP_556x45_Stanag",
			"BP_30Rnd_9x21_Mag",
			"BP_16Rnd_9x21_Mag",
			"BP_545x39_AK107",
			"1Rnd_HE_Grenade_shell",
			"HandGrenade",
			"BP_5Rnd_3006M_Mag",
			"BP_200Rnd_556x45_MINIMI",
			"SmokeShell",
			//"SmokeShellRed",
			//"SmokeShellGreen",
			"BP_556x45_StanagSD",
			"BP_100Rnd_762x51_MINIMI",
			"BP_15Rnd_9x19OVP",
			"BP_6Rnd_357_Mag",
			"BP_19Rnd_9x19",
			"BP_6Rnd_44Mag",
			"BP_30Rnd_65x39",
			"BP_100Rnd_65x39",
			"BP_20Rnd_762x51_BPMag",
			"BP_762x51_Box_Tracer",
			"BP_5Rnd_127x108_Mag",
			"BP_7Rnd_408Chey_Mag",
			"BP_30Rnd_65x39_SD",
			"BP_M84_Flash"
		},
		{
			0.40,	//BANDAGE
			0.10,	//ANTIBIOTIC
			0.40,	//PAINKILLER
			0.10,	//MORPHINE
			0.03,   //M24 CLIP
			0.10,	//STANAG
			0.15,	//30 ROUND 9MM
			0.12,	//AK107 MAG
			0.05,	//7.62 CLIP
			0.30,	//HE M203
			0.40,   //HAND GRENADE
			0.05,	//30-06M
			0.05,	//200 ROUND MINIMI 5.56 
			0.10,	//SMOKE
			//0.40,	//SMOKE RED
			//0.40,	//SMOKE GREEN
			0.10,	//STANAG SD
			0.05,	//7.62 MINIMI
			0.05,   //9MM OVP
			//0.05,	//357 MAG
			0.05,	//USP 45 MAG
			0.10,	//G17 MAG
			0.10,	//44 MAG
			0.10,	//30 ROUND 6.5
			0.05,	//100 ROUND 6.5 TRACER BOX
			0.08,	//20 ROUND 7.62 MAG
			0.10,	//150 7.62 BOX TRACER
			0.02,	//12x108 SNIPER
			0.02,	//408 CHEY
			0.10,    //MX SD MAG
			0.40	//Flashbang
			
		}
	};
	policeman[] = {
		{
			"ItemBandage",
			"FlareGreen_F",
			"BP_16Rnd_9x21_Mag",
			"BP_6Rnd_44Mag",
			"BP_7Rnd_45JHP" 
		},
		{
			1,
			0.3,
			0.4,
			0.2,
			0.01
		}
	};
	hunter[] = {
		{
			"ItemBandage",
			"WaterbotEmpty"
		},
		{
			1,
			0.2	
		}
	};
	specialammorifle[] = {
		{
			"BP_556x45_StanagM855A1",
			"BP_200Rnd_556x45_Minimi",
			"BP_100Rnd_762x51_Minimi",
			"BP_20Rnd_762x51_BPMag",
			"BP_20Rnd_762x51_M80A1",
			"BP_20Rnd_65x47_Lapua",
			"BP_10Rnd_338Lapua_Mag",
			"BP_762x51_Box_Tracer",
			"BP_30Rnd_65x39",
			"BP_100Rnd_65x39",
			"BP_5Rnd_127x108_Mag",
			"BP_556x45_Stanag",
			"BP_556x45_StanagSD",
			"BP_30Rnd_65x39_SD",
			"BP_5Rnd_300_Mag",
			"BP_5Rnd_300M_Mag",
			"BP_5Rnd_3006M_Mag",
			"BP_5Rnd_762x51_Mag",
			"BP_5Rnd_762m80a1_Mag",
			"BP_5Rnd_762mk316_Mag"
		},
		{
			0.2,
			0.7,
			0.4,
			0.2,
			0.07,
			0.1,
			0.03,
			0.2,
			0.4,
			0.6,
			0.03,
			0.4,
			0.15,
			0.15,
			0.03,
			0.01,
			0.03,
			0.20,
			0.02,
			0.09
		}
	};
	specialammopistol[] = {
		{
			"BP_6Rnd_44Mag",
			"BP_33Rnd_9x19OVP",
			"BP_19Rnd_9x19",
			"BP_17Rnd_9x19_SD",
			"BP_7Rnd_45JHP",
			"BP_7Rnd_45acp",
			"BP_12Rnd_45JHP"
	
		},
		{
			0.05,
			0.2,
			0.4,
			0.5,
			0.2,
			0.2,
			0.02,
			0.03
		}
	};
	
	survival[] = {
		{
			"ItemSoda1",
			"ItemSoda2",
			"ItemSoda3",
			"ItemSoda4",
			"ItemSoda5",
			"ItemCan1",
			"ItemCan2",
			"ItemCan3",
			"ItemCan4",
			"ItemCan5",
			"WaterbotEmpty",
			"Waterbot",
			"ItemBandage",
			"ItemAntibiotic"
			
		},
		{

			0.02, //ItemSoda1
			0.02, //ItemSoda2
			0.02, //ItemSoda3
			0.02, //ItemSoda4
			0.02, //ItemSoda5
			0.01, //ItemCan1
			0.01, //ItemCan2
			0.01, //ItemCan3
			0.01, //ItemCan4
			0.01, //ItemCan5
			0.04, //WaterbotEmpty
			0.01, //Waterbot
			0.11, //ItemBandage
			0.01  //ItemAntibiotic

		}
	};

    blueprints[] = {
		{
			"ItemBlueprint_RockStash",
			"ItemBlueprint_Crate1",
			"ItemBlueprint_Tent",
			"ItemBlueprint_CamoNet",
			"ItemBlueprint_Safe"
		},
		{
			0.50,
			0.50,
			0.40,
			0.40,
			0.05
		}
	};	
	carrier[] = {
		{
			"ItemCan1",
			"ItemCan2",
			"ItemCan3",
			"ItemAntibiotic",
			"ItemBandage"
		},
		{
			0.01,
			0.01,
			0.01,
			0.01,
			0.11
		}
	};
};