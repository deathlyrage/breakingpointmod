/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgSurfaces {
	class Default;	// External class reference
	class Water;	// External class reference
	class GdtStratisGreenGrass;	// External class reference
	class GdtStratisDryGrass;	// External class reference
	class GdtGrassDry;	// External class reference
	class GdtDesert;	// External class reference
	class GdtRock;	// External class reference
	class GdtDirt;	// External class reference
	
	//class CRGrass1 : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "cr_trava1_*";
	//	character = "CRGrassClutter";
	//};
	
	//class CRGrass2 : GdtStratisGreenGrass {
	//	access = ReadOnly;
	//	files = "cr_trava2_*";
	//	rough = 0.11;
	//	soundEnviron = "grass";
	//	character = "CRTallGrassClutter";
	//};
	class GdtGrassWild;	// External class reference
	
	//class CRGrassW1 : GdtGrassWild {
	//	access = ReadOnly;
	//	files = "cr_travad1_*";
	//	rough = 0.11;
	//	soundEnviron = "grass";
	//	character = "CRGrassWClutter";
	//};
	
	//class CRGrassW2 : GdtGrassWild {
	//	access = ReadOnly;
	//	files = "cr_travad2_*";
	//	rough = 0.11;
	//	soundEnviron = "grass";
	//	character = "CRTallGrassWClutter";
	//};
	class GdtStratisForestPine;	// External class reference
	
	//class CRForest1 : GdtStratisForestPine {
	//	access = ReadOnly;
	//	files = "cr_les1_*";
	//	rough = 0.2;
	//	dust = 0.2;
	//	soundEnviron = "forest";
	//	character = "CRForestMixedClutter";
	//};
	
	//class CRForest2 : GdtStratisForestPine {
	//	access = ReadOnly;
	//	files = "cr_les2_*";
	//	rough = 0.2;
	//	dust = 0.15;
	//	soundEnviron = "forest";
	//	character = "CRForestFirClutter";
	//};
	class GdtMud;	// External class reference
	
	class CRMudGround : GdtMud {
		access = ReadOnly;
		files = "cr_pole_*";
		rough = 0.09;
		dust = 0.1;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
	};
	class GdtWildField;	// External class reference
	
	class CRField1 : GdtWildField {
		access = ReadOnly;
		files = "cr_oranice_*";
		rough = 0.15;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	//class CRField2 : GdtWildField {
	//	access = ReadOnly;
	//	files = "cr_strniste_*";
	//	rough = 0.13;
	//	dust = 0.3;
	//	soundEnviron = "dirt";
	//	character = "CRStubbleClutter";
	//};
	class GdtRubble;	// External class reference
	
	class CRGrit1 : GdtRubble {
		access = ReadOnly;
		files = "cr_sterk_*";
		rough = 0.1;
		dust = 0.25;
		character = "Empty";
	};
	
	//class CRHeather : GdtStratisForestPine {
	//	access = ReadOnly;
	//	files = "cr_vres_*";
	//	rough = 0.14;
	//	dust = 0.1;
	//	soundEnviron = "forest";
	//	character = "CRHeatherClutter";
	//};
	class GdtStratisRocky;	// External class reference
	
	class CRRock : GdtStratisRocky {
		access = ReadOnly;
		files = "cr_skala_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
	};
	class GdtStratisConcrete;	// External class reference
	
	class CRTarmac : GdtStratisConcrete {
		access = ReadOnly;
		files = "cr_asfalt_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class CRConcrete : GdtStratisConcrete {
		access = ReadOnly;
		files = "cr_beton_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "concrete_ext";
		character = "Empty";
	};
	class concrete;	// External class reference
	class GdtConcrete;	// External class reference
	class SurfRoadDirt;	// External class reference
	
	class road : SurfRoadDirt {
		rough = 0.05;
		dust = 0.4;
		lucidity = 0.8;
		soundEnviron = "dirt";
		files = "cesta*";
		character = "Empty";
	};
	class floor;	// External class reference
	class carpet_inside;	// External class reference
	class carpet;	// External class reference
	class concrete_hall;	// External class reference
	class stones;	// External class reference
	class cardboard;	// External class reference
	class lino;	// External class reference
	class steel;	// External class reference
	class trash;	// External class reference
	class parquet;	// External class reference
	class sand;	// External class reference
	class metalPlate;	// External class reference
	class woodenFloor;	// External class reference
	class planks;	// External class reference
	class grid;	// External class reference
	class rubble;	// External class reference
	class BuildingRubble;	// External class reference
	class tiling;	// External class reference
	class wavyMetal;	// External class reference
	
	class Roadway : road {
		access = ReadOnly;
		files = "silnice*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Parkety : parquet {
		access = ReadOnly;
		files = "parkety*";
		rough = 0.005;
		dust = 0.001;
		soundEnviron = "parkety";
		character = "Empty";
	};
	
	class Lepenka : cardboard {
		access = ReadOnly;
		files = "lepenka*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "lepenka";
		character = "Empty";
	};
	
	class Tasky : tiling {
		access = ReadOnly;
		files = "Tasky*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "lepenka";
		character = "Empty";
	};
	
	class Rost : grid {
		access = ReadOnly;
		files = "Rost*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "steel";
		character = "Empty";
	};
	
	class Asfalt : Roadway {
		access = ReadOnly;
		files = "asfalt*";
		rough = 0.01;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Cesta : Roadway {
		access = ReadOnly;
		files = "cesta*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class Sterk : rubble {
		access = ReadOnly;
		files = "sterk*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel";
		character = "Empty";
	};
	
	class SterkBIG : Default {
		access = ReadOnly;
		files = "sterkBIG*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel2";
		character = "Empty";
	};
	
	class Sutiny : BuildingRubble {
		access = ReadOnly;
		files = "sutiny*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel2";
		character = "Empty";
	};
	
	class Wood : Default {
		access = ReadOnly;
		files = "podlaha_prkna*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood";
		character = "Empty";
	};
	
	class Wood_ext : Default {
		access = ReadOnly;
		files = "prknaOUT*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood";
		character = "Empty";
	};
	
	class PrknaINT : Default {
		access = ReadOnly;
		files = "prknaIN*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood_int";
		character = "Empty";
	};
	
	class Metal : metalPlate {
		access = ReadOnly;
		files = "plechprolis*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "steel";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Plech : metalPlate {
		access = ReadOnly;
		files = "plech*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "steel";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Iron : steel {
		access = ReadOnly;
		files = "ocel*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "metal";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Wave_plate : wavyMetal {
		access = ReadOnly;
		files = "vlnityplech*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wave_plate";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Beton : concrete {
		access = ReadOnly;
		files = "kameny";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
	};
	
	class CrCarpet : carpet_inside {
		access = ReadOnly;
		files = "dum_mesto_koberec*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "carpet";
		character = "Empty";
	};
	
	class CrCarpet2 : carpet {
		access = ReadOnly;
		files = "koberec*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "carpet";
		character = "Empty";
	};
	
	class SandBuilding : Default {
		access = ReadOnly;
		files = "pisek01*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	class MudBuilding : Default {
		access = ReadOnly;
		files = "hlinasterk*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class Hlina : GdtMud {
		access = ReadOnly;
		files = "hlina*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class BetonNew : concrete {
		access = ReadOnly;
		files = "beton*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class BetonIN : concrete {
		access = ReadOnly;
		files = "chodba_beton*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "hallway";
		character = "Empty";
	};
	
	class DlazbaIN : concrete {
		access = ReadOnly;
		files = "dlazbaIN*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "Concrete_int";
		character = "Empty";
	};
	
	class CubeRoad : GdtStratisConcrete {
		access = ReadOnly;
		files = "sil_kos*";
		rough = 0.04;
		dust = 0.15;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Sil_new : GdtStratisConcrete {
		access = ReadOnly;
		files = "sil_new*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Asfalt_New : GdtStratisConcrete {
		access = ReadOnly;
		files = "asf_new*";
		rough = 0.008;
		dust = 0.025;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Asf1 : Asfalt_New {
		files = "asf1*";
	};
	
	class Asf2 : Asfalt_New {
		files = "asf2*";
	};
	
	class Asf3 : Asfalt_New {
		files = "asf3*";
	};
	
	class runway_beton : Asfalt_New {
		files = "runway_beton*";
	};
	
	class city_dashedline : Asfalt_New {
		files = "city_dashedline*";
	};
	
	class Cesta_new : GdtStratisConcrete {
		access = ReadOnly;
		files = "ces_hned*";
		rough = 0.04;
		dust = 0.14;
		soundEnviron = "gravel";
		character = "Empty";
	};
	
	class grav_dirt : Cesta_new {
		files = "grav_dirt*";
		soundEnviron = "gravel2";
	};
	
	class mud_gravel : Cesta_new {
		files = "mud_gravel*";
		soundEnviron = "gravel";
	};
	
	class Pesina : Roadway {
		access = ReadOnly;
		files = "pesina*";
		rough = 0.1;
		dust = 0.15;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class path_dirt : Pesina {
		files = "path_dirt*";
	};
	
	class Hallway : Default {
		access = ReadOnly;
		files = "podldlzin02*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "hallway";
		character = "Empty";
	};
	
	class Grass : GdtStratisGreenGrass {
		access = ReadOnly;
		files = "trava_*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "grass";
		character = "GrassClutter";
	};
	
	class GrassSouth : GdtStratisDryGrass {
		access = ReadOnly;
		files = "travajih*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "drygrass";
		character = "GrassSouthClutter";
	};
	
	class ForestLeaves : GdtStratisForestPine {
		access = ReadOnly;
		files = "leslist*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "forest";
		character = "ForestLeavesClutter";
	};
	
	class ForestNeedles : GdtStratisForestPine {
		access = ReadOnly;
		files = "lesjeh*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "forest";
		character = "ForestNeedlesClutter";
	};
	
	class RockSouth : Default {
		access = ReadOnly;
		files = "skalajih*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "rock";
		character = "RockSouthClutter";
	};
	
	class RockNorth : Default {
		access = ReadOnly;
		files = "skalas*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "rock";
		character = "Empty";
	};
	
	class Mud2 : GdtMud {
		access = ReadOnly;
		files = "blato*";
		rough = 0.1;
		dust = 0.3;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class CityGround : Default {
		access = ReadOnly;
		files = "mesto*";
		rough = 0.01;
		dust = 0.05;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class DryGround : GdtGrassDry {
		access = ReadOnly;
		files = "mesto2*";
		rough = 0.05;
		dust = 0.05;
		soundEnviron = "gravel";
		character = "Empty";
	};
	
	class Field1 : GdtWildField {
		access = ReadOnly;
		files = "pole1*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
	};
	
	class SandGeneral : Default {
		access = ReadOnly;
		files = "pisek*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "SandGeneralClutter";
	};
	
	class Odpadky : Default {
		access = ReadOnly;
		files = "odpadky*";
		soundEnviron = "gravel2";
	};
	class GdtStratisBeach;	// External class reference
	
	class SandDesert : GdtStratisBeach {
		access = ReadOnly;
		files = "pisekpoust*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	class SandBeach : GdtStratisBeach {
		access = ReadOnly;
		files = "pisekplaz*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	//class DBTrava : Default {
	//	access = ReadOnly;
	//	files = "baf_trava_*";
	//	rough = 0.08;
	//	dust = 0.5;
	//	soundEnviron = "drygrass";
	//	character = "DBGrassClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class DBPolopoust : Default {
	//	access = ReadOnly;
	//	files = "baf_polopoust_*";
	//	rough = 0.05;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "DBDenseAridClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class DBSkalniSterk : Default {
	//	access = ReadOnly;
	//	files = "baf_skalni_sterk_*";
	//	rough = 0.1;
	//	dust = 1;
	//	soundEnviron = "rock";
	//	character = "DBSparseAridClutter";
	//	soundHit = "hard_ground";
	//};
	
	class DBAsfalt : Default {
		access = ReadOnly;
		files = "baf_asfalt_*";
		rough = 0.005;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKAsfalt : Default {
		access = ReadOnly;
		files = "tk_asfalt_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKBeton : Default {
		access = ReadOnly;
		files = "tk_beton_*";
		rough = 0.01;
		dust = 0.08;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKHlina : Default {
		access = ReadOnly;
		files = "tk_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	//class TKPlevel : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "tk_plevel_*";
	//	rough = 0.11;
	//	dust = 0.7;
	//	soundEnviron = "drygrass";
	//	character = "TKWeedsClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class TKPole : GdtDesert {
	//	access = ReadOnly;
	//	files = "tk_pole_*";
	//	rough = 0.12;
	//	dust = 0.6;
	//	soundEnviron = "grass";
	//	character = "TKFieldGrassClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class TKPolopoust : GdtDesert {
	//	access = ReadOnly;
	//	files = "tk_polopoust_*";
	//	rough = 0.01;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "TKDesertClutter";
	//	soundHit = "soft_ground";
	//};
	
	class TKSkala : GdtRock {
		access = ReadOnly;
		files = "tk_skala_*";
		rough = 0.3;
		dust = 0.5;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKSkalniSterk : GdtRock {
		access = ReadOnly;
		files = "tk_skalni_sterk_*";
		rough = 0.15;
		dust = 1;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKSterkNaDno : GdtRock {
		access = ReadOnly;
		files = "tk_sterk_na_dno_*";
		rough = 0.2;
		dust = 0;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKValouny : GdtRock {
		access = ReadOnly;
		files = "tk_valouny_*";
		rough = 0.15;
		dust = 0.4;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	//class TKTrava : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "tk_trava_*";
	//	rough = 0.11;
	//	dust = 0.5;
	//	soundEnviron = "drygrass";
	//	character = "TKGrassClutter";
	//	soundHit = "soft_ground";
	//};
	
	class TKDlazbaOld : Default {
		access = ReadOnly;
		files = "tk_dlazba_old_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	//class TKForest : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "tk_forest_*";
	//	rough = 0.01;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "TKForestClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class TKMoutain : GdtRock {
	//	access = ReadOnly;
	//	files = "tk_mountain_*";
	//	rough = 0.01;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "TKMountainsClutter";
	//	soundHit = "soft_ground";
	//};
	
	class ZRAsfalt : Default {
		access = ReadOnly;
		files = "zr_asfalt_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class ZRBeton : Default {
		access = ReadOnly;
		files = "zr_beton_*";
		rough = 0.01;
		dust = 0.08;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class ZRHlina : GdtDirt {
		access = ReadOnly;
		files = "zr_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	//class ZRPlevel : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "zr_plevel_*";
	//	rough = 0.11;
	//	dust = 0.7;
	//	soundEnviron = "drygrass";
	//	character = "ZRWeedsClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class ZRPole : GdtWildField {
	//	access = ReadOnly;
	//	files = "zr_pole_*";
	//	rough = 0.12;
	//	dust = 0.6;
	//	soundEnviron = "grass";
	//	character = "ZRFieldGrassClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class ZRPolopoust : GdtDesert {
	//	access = ReadOnly;
	//	files = "zr_polopoust_*";
	//	rough = 0.01;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "ZRDesertClutter";
	//	soundHit = "soft_ground";
	//};
	
	class ZRSkala : GdtRock {
		access = ReadOnly;
		files = "zr_skala_*";
		rough = 0.3;
		dust = 0.5;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRSkalniSterk : GdtRock {
		access = ReadOnly;
		files = "zr_skalni_sterk_*";
		rough = 0.15;
		dust = 1;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRSterkNaDno : GdtRock {
		access = ReadOnly;
		files = "zr_sterk_na_dno_*";
		rough = 0.2;
		dust = 0;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRValouny : GdtRock {
		access = ReadOnly;
		files = "zr_valouny_*";
		rough = 0.15;
		dust = 0.4;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	//class ZRTrava : GdtStratisDryGrass {
	//	access = ReadOnly;
	//	files = "zr_trava_*";
	//	rough = 0.11;
	//	dust = 0.5;
	//	soundEnviron = "drygrass";
	//	character = "ZRGrassClutter";
	//	soundHit = "soft_ground";
	//};
	
	class ZRDlazbaOld : Default {
		access = ReadOnly;
		files = "zr_dlazba_old_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	//class DEPolopoust : GdtDesert {
	//	access = ReadOnly;
	//	files = "de_polopoust_*";
	//	rough = 0.01;
	//	dust = 0.9;
	//	soundEnviron = "dirt";
	//	character = "DEDenseAridClutter";
	//	soundHit = "soft_ground";
	//};
	
	//class DESkalniSterk : GdtRock {
	//	access = ReadOnly;
	//	files = "de_skalni_sterk_*";
	//	rough = 0.15;
	//	dust = 1;
	//	soundEnviron = "rock";
	//	character = "DESparseAridClutter";
	//	soundHit = "hard_ground";
	//};
	/*
	class DETrava : GdtStratisDryGrass {
		access = ReadOnly;
		files = "de_trava_*";
		rough = 0.11;
		dust = 0.5;
		soundEnviron = "drygrass";
		character = "DEGrassClutter";
		soundHit = "soft_ground";
	};
	
	
	class WLGrass1 : GdtStratisGreenGrass {
		access = ReadOnly;
		files = "wl_trava1_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLGrassClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrass2 : GdtStratisGreenGrass {
		access = ReadOnly;
		files = "wl_trava2_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLTallGrassClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrassW1 : GdtStratisDryGrass {
		access = ReadOnly;
		files = "wl_travad1_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLGrassWClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrassW2 : GdtStratisDryGrass {
		access = ReadOnly;
		files = "wl_travad2_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLTallGrassWClutter";
		soundHit = "soft_ground";
	};
	
	class WLForest1 : GdtStratisForestPine {
		access = ReadOnly;
		files = "wl_les1_*";
		rough = 0.2;
		dust = 0.2;
		soundEnviron = "forest";
		character = "WLForestMixedClutter";
		soundHit = "soft_ground";
	};
	
	class WLForest2 : GdtStratisForestPine {
		access = ReadOnly;
		files = "wl_les2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "forest";
		character = "WLForestFirClutter";
		soundHit = "soft_ground";
	};
	*/
	
	class WLMudGround : GdtDirt {
		access = ReadOnly;
		files = "wl_pole_*";
		rough = 0.09;
		dust = 0.1;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
		soundHit = "soft_ground";
	};
	
	class WLField1 : GdtWildField {
		access = ReadOnly;
		files = "wl_oranice_*";
		rough = 0.15;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class WLGrit1 : GdtDirt {
		access = ReadOnly;
		files = "wl_sterk_*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	//class WLHeather : Default {
	//	access = ReadOnly;
	//	files = "wl_vres_*";
	//	rough = 0.14;
	//	dust = 0.1;
	//	soundEnviron = "forest";
	//	character = "WLHeatherClutter";
	//	soundHit = "soft_ground";
	//};
	
	class WLRock : Default {
		access = ReadOnly;
		files = "wl_skala_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class WLTarmac : Default {
		access = ReadOnly;
		files = "wl_asfalt_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class WLConcrete : Default {
		access = ReadOnly;
		files = "wl_beton_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class GZHlina : Default {
		access = ReadOnly;
		files = "gz_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	//class GZTrava : GdtStratisGreenGrass {
	//	access = ReadOnly;
	//	files = "gz_trava_*";
	//	rough = 0.12;
	//	dust = 0.6;
	//	soundEnviron = "grass";
	//	character = "GZTravaClutter";
	//	soundHit = "soft_ground";
	//};
	
	class GZasfalt : Default {
		access = ReadOnly;
		files = "gz_asfalt_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "concrete";
	};
	
	//class GZforest : GdtStratisForestPine {
	//	access = ReadOnly;
	//	files = "gz_forest_*";
	//	rough = 0.1;
	//	dust = 0.8;
	//	soundEnviron = "dirt";
	//	character = "GZTravaGreen";
	//	soundHit = "soft_ground";
	//};
	
	class GZkameny : GdtDirt {
		access = ReadOnly;
		files = "gz_kameny_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
};
