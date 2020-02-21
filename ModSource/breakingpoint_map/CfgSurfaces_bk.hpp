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
	
	class CRGrass1 : GdtStratisDryGrass {
		files = "cr_trava1_*";
		character = "CRGrassClutter";
	};
	
	class CRGrass2 : GdtStratisGreenGrass {
		files = "cr_trava2_*";
		rough = 0.11;
		soundEnviron = "grass";
		character = "CRTallGrassClutter";
	};
	class GdtGrassWild;	// External class reference
	
	class CRGrassW1 : GdtGrassWild {
		files = "cr_travad1_*";
		rough = 0.11;
		soundEnviron = "grass";
		character = "CRGrassWClutter";
	};
	
	class CRGrassW2 : GdtGrassWild {
		files = "cr_travad2_*";
		rough = 0.11;
		soundEnviron = "grass";
		character = "CRTallGrassWClutter";
	};
	class GdtStratisForestPine;	// External class reference
	
	class CRForest1 : GdtStratisForestPine {
		files = "cr_les1_*";
		rough = 0.2;
		dust = 0.2;
		soundEnviron = "forest";
		character = "CRForestMixedClutter";
	};
	
	class CRForest2 : GdtStratisForestPine {
		files = "cr_les2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "forest";
		character = "CRForestFirClutter";
	};
	class GdtMud;	// External class reference
	
	class CRMudGround : GdtMud {
		files = "cr_pole_*";
		rough = 0.09;
		dust = 0.1;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
	};
	class GdtWildField;	// External class reference
	
	class CRField1 : GdtWildField {
		files = "cr_oranice_*";
		rough = 0.15;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class CRField2 : GdtWildField {
		files = "cr_strniste_*";
		rough = 0.13;
		dust = 0.3;
		soundEnviron = "dirt";
		character = "CRStubbleClutter";
	};
	class GdtRubble;	// External class reference
	
	class CRGrit1 : GdtRubble {
		files = "cr_sterk_*";
		rough = 0.1;
		dust = 0.25;
		character = "Empty";
	};
	
	class CRHeather : GdtStratisForestPine {
		files = "cr_vres_*";
		rough = 0.14;
		dust = 0.1;
		soundEnviron = "forest";
		character = "CRHeatherClutter";
	};
	class GdtStratisRocky;	// External class reference
	
	class CRRock : GdtStratisRocky {
		files = "cr_skala_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
	};
	class GdtStratisConcrete;	// External class reference
	
	class CRTarmac : GdtStratisConcrete {
		files = "cr_asfalt_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class CRConcrete : GdtStratisConcrete {
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
		files = "silnice*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Parkety : parquet {
		files = "parkety*";
		rough = 0.005;
		dust = 0.001;
		soundEnviron = "parkety";
		character = "Empty";
	};
	
	class Lepenka : cardboard {
		files = "lepenka*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "lepenka";
		character = "Empty";
	};
	
	class Tasky : tiling {
		files = "Tasky*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "lepenka";
		character = "Empty";
	};
	
	class Rost : grid {
		files = "Rost*";
		rough = 0.001;
		dust = 0.001;
		soundEnviron = "steel";
		character = "Empty";
	};
	
	class Asfalt : Roadway {
		files = "asfalt*";
		rough = 0.01;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Cesta : Roadway {
		files = "cesta*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class Sterk : rubble {
		files = "sterk*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel";
		character = "Empty";
	};
	
	class SterkBIG : Default {
		files = "sterkBIG*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel2";
		character = "Empty";
	};
	
	class Sutiny : BuildingRubble {
		files = "sutiny*";
		rough = 0.08;
		dust = 0.15;
		soundEnviron = "gravel2";
		character = "Empty";
	};
	
	class Wood : Default {
		files = "podlaha_prkna*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood";
		character = "Empty";
	};
	
	class Wood_ext : Default {
		files = "prknaOUT*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood";
		character = "Empty";
	};
	
	class PrknaINT : Default {
		files = "prknaIN*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wood_int";
		character = "Empty";
	};
	
	class Metal : metalPlate {
		files = "plechprolis*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "steel";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Plech : metalPlate {
		files = "plech*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "steel";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Iron : steel {
		files = "ocel*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "metal";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Wave_plate : wavyMetal {
		files = "vlnityplech*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "wave_plate";
		character = "Empty";
		impact = "Impact_Metal";
	};
	
	class Beton : concrete {
		files = "kameny";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
	};
	
	class CrCarpet : carpet_inside {
		files = "dum_mesto_koberec*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "carpet";
		character = "Empty";
	};
	
	class CrCarpet2 : carpet {
		files = "koberec*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "carpet";
		character = "Empty";
	};
	
	class SandBuilding : Default {
		files = "pisek01*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	class MudBuilding : Default {
		files = "hlinasterk*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class Hlina : GdtMud {
		files = "hlina*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class BetonNew : concrete {
		files = "beton*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class BetonIN : concrete {
		files = "chodba_beton*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "hallway";
		character = "Empty";
	};
	
	class DlazbaIN : concrete {
		files = "dlazbaIN*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "Concrete_int";
		character = "Empty";
	};
	
	class CubeRoad : GdtStratisConcrete {
		files = "sil_kos*";
		rough = 0.04;
		dust = 0.15;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Sil_new : GdtStratisConcrete {
		files = "sil_new*";
		rough = 0.005;
		dust = 0.01;
		soundEnviron = "road";
		character = "Empty";
	};
	
	class Asfalt_New : GdtStratisConcrete {
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
		files = "podldlzin02*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "hallway";
		character = "Empty";
	};
	
	class Grass : GdtStratisGreenGrass {
		files = "trava_*";
		rough = 0.1;
		dust = 0.1;
		soundEnviron = "grass";
		character = "GrassClutter";
	};
	
	class GrassSouth : GdtStratisDryGrass {
		files = "travajih*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "drygrass";
		character = "GrassSouthClutter";
	};
	
	class ForestLeaves : GdtStratisForestPine {
		files = "leslist*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "forest";
		character = "ForestLeavesClutter";
	};
	
	class ForestNeedles : GdtStratisForestPine {
		files = "lesjeh*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "forest";
		character = "ForestNeedlesClutter";
	};
	
	class RockSouth : Default {
		files = "skalajih*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "rock";
		character = "RockSouthClutter";
	};
	
	class RockNorth : Default {
		files = "skalas*";
		rough = 0.1;
		dust = 0.2;
		soundEnviron = "rock";
		character = "Empty";
	};
	
	class Mud2 : GdtMud {
		files = "blato*";
		rough = 0.1;
		dust = 0.3;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class CityGround : Default {
		files = "mesto*";
		rough = 0.01;
		dust = 0.05;
		soundEnviron = "dirt";
		character = "Empty";
	};
	
	class DryGround : GdtGrassDry {
		files = "mesto2*";
		rough = 0.05;
		dust = 0.05;
		soundEnviron = "gravel";
		character = "Empty";
	};
	
	class Field1 : GdtWildField {
		files = "pole1*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
	};
	
	class SandGeneral : Default {
		files = "pisek*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "SandGeneralClutter";
	};
	
	class Odpadky : Default {
		files = "odpadky*";
		soundEnviron = "gravel2";
	};
	class GdtStratisBeach;	// External class reference
	
	class SandDesert : GdtStratisBeach {
		files = "pisekpoust*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	class SandBeach : GdtStratisBeach {
		files = "pisekplaz*";
		rough = 0.1;
		dust = 0.5;
		soundEnviron = "sand";
		character = "Empty";
	};
	
	class DBTrava : Default {
		files = "baf_trava_*";
		rough = 0.08;
		dust = 0.5;
		soundEnviron = "drygrass";
		character = "DBGrassClutter";
		soundHit = "soft_ground";
	};
	
	class DBPolopoust : Default {
		files = "baf_polopoust_*";
		rough = 0.05;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "DBDenseAridClutter";
		soundHit = "soft_ground";
	};
	
	class DBSkalniSterk : Default {
		files = "baf_skalni_sterk_*";
		rough = 0.1;
		dust = 1;
		soundEnviron = "rock";
		character = "DBSparseAridClutter";
		soundHit = "hard_ground";
	};
	
	class DBAsfalt : Default {
		files = "baf_asfalt_*";
		rough = 0.005;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKAsfalt : Default {
		files = "tk_asfalt_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKBeton : Default {
		files = "tk_beton_*";
		rough = 0.01;
		dust = 0.08;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKHlina : Default {
		files = "tk_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class TKPlevel : GdtStratisDryGrass {
		files = "tk_plevel_*";
		rough = 0.11;
		dust = 0.7;
		soundEnviron = "drygrass";
		character = "TKWeedsClutter";
		soundHit = "soft_ground";
	};
	
	class TKPole : GdtDesert {
		files = "tk_pole_*";
		rough = 0.12;
		dust = 0.6;
		soundEnviron = "grass";
		character = "TKFieldGrassClutter";
		soundHit = "soft_ground";
	};
	
	class TKPolopoust : GdtDesert {
		files = "tk_polopoust_*";
		rough = 0.01;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "TKDesertClutter";
		soundHit = "soft_ground";
	};
	
	class TKSkala : GdtRock {
		files = "tk_skala_*";
		rough = 0.3;
		dust = 0.5;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKSkalniSterk : GdtRock {
		files = "tk_skalni_sterk_*";
		rough = 0.15;
		dust = 1;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKSterkNaDno : GdtRock {
		files = "tk_sterk_na_dno_*";
		rough = 0.2;
		dust = 0;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKValouny : GdtRock {
		files = "tk_valouny_*";
		rough = 0.15;
		dust = 0.4;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class TKTrava : GdtStratisDryGrass {
		files = "tk_trava_*";
		rough = 0.11;
		dust = 0.5;
		soundEnviron = "drygrass";
		character = "TKGrassClutter";
		soundHit = "soft_ground";
	};
	
	class TKDlazbaOld : Default {
		files = "tk_dlazba_old_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class TKForest : GdtStratisDryGrass {
		files = "tk_forest_*";
		rough = 0.01;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "TKForestClutter";
		soundHit = "soft_ground";
	};
	
	class TKMoutain : GdtRock {
		files = "tk_mountain_*";
		rough = 0.01;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "TKMountainsClutter";
		soundHit = "soft_ground";
	};
	
	class ZRAsfalt : Default {
		files = "zr_asfalt_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class ZRBeton : Default {
		files = "zr_beton_*";
		rough = 0.01;
		dust = 0.08;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class ZRHlina : GdtDirt {
		files = "zr_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class ZRPlevel : GdtStratisDryGrass {
		files = "zr_plevel_*";
		rough = 0.11;
		dust = 0.7;
		soundEnviron = "drygrass";
		character = "ZRWeedsClutter";
		soundHit = "soft_ground";
	};
	
	class ZRPole : GdtWildField {
		files = "zr_pole_*";
		rough = 0.12;
		dust = 0.6;
		soundEnviron = "grass";
		character = "ZRFieldGrassClutter";
		soundHit = "soft_ground";
	};
	
	class ZRPolopoust : GdtDesert {
		files = "zr_polopoust_*";
		rough = 0.01;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "ZRDesertClutter";
		soundHit = "soft_ground";
	};
	
	class ZRSkala : GdtRock {
		files = "zr_skala_*";
		rough = 0.3;
		dust = 0.5;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRSkalniSterk : GdtRock {
		files = "zr_skalni_sterk_*";
		rough = 0.15;
		dust = 1;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRSterkNaDno : GdtRock {
		files = "zr_sterk_na_dno_*";
		rough = 0.2;
		dust = 0;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRValouny : GdtRock {
		files = "zr_valouny_*";
		rough = 0.15;
		dust = 0.4;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class ZRTrava : GdtStratisDryGrass {
		files = "zr_trava_*";
		rough = 0.11;
		dust = 0.5;
		soundEnviron = "drygrass";
		character = "ZRGrassClutter";
		soundHit = "soft_ground";
	};
	
	class ZRDlazbaOld : Default {
		files = "zr_dlazba_old_*";
		rough = 0.001;
		dust = 0.1;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class DEPolopoust : GdtDesert {
		files = "de_polopoust_*";
		rough = 0.01;
		dust = 0.9;
		soundEnviron = "dirt";
		character = "DEDenseAridClutter";
		soundHit = "soft_ground";
	};
	
	class DESkalniSterk : GdtRock {
		files = "de_skalni_sterk_*";
		rough = 0.15;
		dust = 1;
		soundEnviron = "rock";
		character = "DESparseAridClutter";
		soundHit = "hard_ground";
	};
	
	class DETrava : GdtStratisDryGrass {
		files = "de_trava_*";
		rough = 0.11;
		dust = 0.5;
		soundEnviron = "drygrass";
		character = "DEGrassClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrass1 : GdtStratisGreenGrass {
		files = "wl_trava1_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLGrassClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrass2 : GdtStratisGreenGrass {
		files = "wl_trava2_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLTallGrassClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrassW1 : GdtStratisDryGrass {
		files = "wl_travad1_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLGrassWClutter";
		soundHit = "soft_ground";
	};
	
	class WLGrassW2 : GdtStratisDryGrass {
		files = "wl_travad2_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "WLTallGrassWClutter";
		soundHit = "soft_ground";
	};
	
	class WLForest1 : GdtStratisForestPine {
		files = "wl_les1_*";
		rough = 0.2;
		dust = 0.2;
		soundEnviron = "forest";
		character = "WLForestMixedClutter";
		soundHit = "soft_ground";
	};
	
	class WLForest2 : GdtStratisForestPine {
		files = "wl_les2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "forest";
		character = "WLForestFirClutter";
		soundHit = "soft_ground";
	};
	
	class WLMudGround : GdtDirt {
		files = "wl_pole_*";
		rough = 0.09;
		dust = 0.1;
		soundEnviron = "dirt";
		character = "SparseWeedsClutter";
		soundHit = "soft_ground";
	};
	
	class WLField1 : GdtWildField {
		files = "wl_oranice_*";
		rough = 0.15;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class WLGrit1 : GdtDirt {
		files = "wl_sterk_*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class WLHeather : Default {
		files = "wl_vres_*";
		rough = 0.14;
		dust = 0.1;
		soundEnviron = "forest";
		character = "WLHeatherClutter";
		soundHit = "soft_ground";
	};
	
	class WLRock : Default {
		files = "wl_skala_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class WLTarmac : Default {
		files = "wl_asfalt_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class WLConcrete : Default {
		files = "wl_beton_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class GZHlina : Default {
		files = "gz_hlina_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	
	class GZTrava : GdtStratisGreenGrass {
		files = "gz_trava_*";
		rough = 0.12;
		dust = 0.6;
		soundEnviron = "grass";
		character = "GZTravaClutter";
		soundHit = "soft_ground";
	};
	
	class GZasfalt : Default {
		files = "gz_asfalt_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "concrete";
	};
	
	class GZforest : GdtStratisForestPine {
		files = "gz_forest_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "GZTravaGreen";
		soundHit = "soft_ground";
	};
	
	class GZkameny : GdtDirt {
		files = "gz_kameny_*";
		rough = 0.1;
		dust = 0.8;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
};
