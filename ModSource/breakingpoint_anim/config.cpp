/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define true	1
#define false	0

#define private		0
#define private		0
#define protected		1
#define public		2

#define VSoft		0
#define VArmor		1
#define VAir		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

class CfgPatches {
	class breakingpoint_anim {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
	class EMpatch
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Data_F","A3_Map_Altis","A3_Map_Stratis","breakingpoint_code"};
	};
	class exile_client{};
};
class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class LadderCivilStatic;
		class LadderCivilDownLoop;
		class AsswPercMrunSnonWnonDf;
		class AsswPercMstpSnonWnonDnon;
		class AsdvPercMrunSnonWrflDf;
		class AsdvPercMrunSnonWnonDf;
		class AbswPercMstpSnonWnonDnon;
		class LadderCivilUpLoop: LadderCivilStatic
		{
			speed = "1.04/(2/3)";
		};
		class LadderRifleDownLoop: LadderCivilDownLoop
		{
			speed = "1.04/(2/3)";
		};
		//WETSUIT//
		class AsdvPercMsprSnonWrflDf: AsdvPercMrunSnonWrflDf
		{
			speed=0.22336;
		};
		class AsdvPercMsprSnonWnonDf:AsdvPercMrunSnonWnonDf
		{
			speed=0.22336;
		};
		//REGULARSWIM//
		class AbswPercMrunSnonWnonDf: AbswPercMstpSnonWnonDnon
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDb: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDf_AbswPercMstpSnonWnonDnon: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDfl: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDfr: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDl: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMrunSnonWnonDr: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		//SPRINTSWIM//
		class AbswPercMsprSnonWnonDf: AbswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AbswPercMsprSnonWnonDFl: AbswPercMrunSnonWnonDfl
		{
			speed=0.42;
		};
		class AbswPercMsprSnonWnonDFr: AbswPercMrunSnonWnonDfr
		{
			speed=0.42;
		};
		class AsswPercMrunSnonWnonDb: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMrunSnonWnonDf: AsswPercMstpSnonWnonDnon
		{
			speed=0.52;
		};
		class AsswPercMrunSnonWnonDfl: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMrunSnonWnonDfr: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMrunSnonWnonDl: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMrunSnonWnonDr: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDb: AsswPercMrunSnonWnonDb
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDf: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDfl: AsswPercMrunSnonWnonDfl
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDfr: AsswPercMrunSnonWnonDfr
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDl: AsswPercMrunSnonWnonDl
		{
			speed=0.42;
		};
		class AsswPercMwlkSnonWnonDr: AsswPercMrunSnonWnonDr
		{
			speed=0.42;
		};
		class AsswPercMsprSnonWnonDf: AsswPercMrunSnonWnonDf
		{
			speed=0.42;
		};
		class AsswPercMstpSnonWnonDnon_AsswPercMrunSnonWnonDf: AsswPercMstpSnonWnonDnon
		{
			speed=0.64;
		};
		class AsswPercMstpSnonWnonDnon_goDown: AsswPercMstpSnonWnonDnon
		{
			speed=0.4;
		};
		class AsswPercMstpSnonWnonDnon_goup: AsswPercMstpSnonWnonDnon
		{
			speed=0.4;
		};
		class AsswPercMrunSnonWnonDf_AsswPercMstpSnonWnonDnon: AsswPercMrunSnonWnonDf
		{
			speed=0.95;
		};
	};
};
class CfgAnimation
{
	ladderSpeed = "0.5/(1/3)";
};