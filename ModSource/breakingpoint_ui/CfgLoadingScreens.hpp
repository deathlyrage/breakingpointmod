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

class CfgLoadingScreens
{
	class World
	{
		General[] =
		{
			"\breakingpoint_ui\loading\loading_1.jpg",
			"\breakingpoint_ui\loading\loading_2.jpg",
			"\breakingpoint_ui\loading\loading_3.jpg",
			"\breakingpoint_ui\loading\loading_4.jpg",
			"\breakingpoint_ui\loading\loading_5.jpg",
			"\breakingpoint_ui\loading\loading_6.jpg",
			"\breakingpoint_ui\loading\loading_7.jpg",
			"\breakingpoint_ui\loading\loading_8.jpg",
			"\breakingpoint_ui\loading\loading_9.jpg",
			"\breakingpoint_ui\loading\loading_10.jpg",
			"\breakingpoint_ui\loading\loading_11.jpg",
			"\breakingpoint_ui\loading\loading_12.jpg",
			"\breakingpoint_ui\loading\loading_13.jpg",
			"\breakingpoint_ui\loading\loading_14.jpg"
		};
		Altis[] = 
		{
			"\breakingpoint_ui\loading\Altis\loading_1.jpg",
			"\breakingpoint_ui\loading\Altis\loading_2.jpg",
			"\breakingpoint_ui\loading\Altis\loading_3.jpg"
		};
		
		Stratis[] = 
		{
			"\breakingpoint_ui\loading\Stratis\loading_1.jpg"
		};

		thirsk[] = 
		{
			"\breakingpoint_ui\loading\thrisk\loading_1.jpg",
			"\breakingpoint_ui\loading\thrisk\loading_2.jpg"
		};

		thirskw[] = 
		{
			"\breakingpoint_ui\loading\thriskw\loading_1.jpg",
			"\breakingpoint_ui\loading\thriskw\loading_2.jpg"
		};

		newhaven[] = 
		{
			"\breakingpoint_ui\loading\newhaven\loading_1.jpg",
			"\breakingpoint_ui\loading\newhaven\loading_2.jpg",
			"\breakingpoint_ui\loading\newhaven\loading_3.jpg",
			"\breakingpoint_ui\loading\newhaven\loading_4.jpg"
		};
		
		Bornholm[] = 
		{
			"\breakingpoint_ui\loading\Bornholm\loading_1.jpg",
			"\breakingpoint_ui\loading\Bornholm\loading_2.jpg",
			"\breakingpoint_ui\loading\Bornholm\loading_3.jpg",
			"\breakingpoint_ui\loading\Bornholm\loading_4.jpg",
			"\breakingpoint_ui\loading\Bornholm\loading_5.jpg",
			"\breakingpoint_ui\loading\Bornholm\loading_6.jpg"
		};
		
		Esseker[] =
		{
			"\breakingpoint_ui\loading\Esseker\loading_1.jpg",
			"\breakingpoint_ui\loading\Esseker\loading_2.jpg",
			"\breakingpoint_ui\loading\Esseker\loading_3.jpg"
		};
		
		Chernarus[] =
		{
			"\breakingpoint_ui\loading\Chernarus\loading_1.jpg",
			"\breakingpoint_ui\loading\Chernarus\loading_2.jpg",
			"\breakingpoint_ui\loading\Chernarus\loading_3.jpg"
		};
		
		namalsk[] =
		{
			"\breakingpoint_ui\loading\Namalsk\loading_1.jpg",
			"\breakingpoint_ui\loading\Namalsk\loading_2.jpg",
			"\breakingpoint_ui\loading\Namalsk\loading_3.jpg"
		};
		
		tanoa[] =
		{
			"\breakingpoint_ui\loading\Tanoa\loading_1.jpg",
			"\breakingpoint_ui\loading\Tanoa\loading_2.jpg",
			"\breakingpoint_ui\loading\Tanoa\loading_3.jpg"
		};
		malden[] =
		{
			"\breakingpoint_ui\loading\Malden\loading_1.jpg",
			"\breakingpoint_ui\loading\Malden\loading_2.jpg",
			"\breakingpoint_ui\loading\Malden\loading_3.jpg",
			"\breakingpoint_ui\loading\Malden\loading_4.jpg"
		};
		Tembelan[] =
		{
			"\breakingpoint_ui\loading\Tembelan\loading_1.jpg",
			"\breakingpoint_ui\loading\Tembelan\loading_2.jpg",
			"\breakingpoint_ui\loading\Tembelan\loading_3.jpg"
		};
		egl_laghisola[] =
		{
			"\breakingpoint_ui\loading\egl_laghisola\loading_1.jpg",
			"\breakingpoint_ui\loading\egl_laghisola\loading_2.jpg",
			"\breakingpoint_ui\loading\egl_laghisola\loading_3.jpg"
		};
	};
};

class RscDisplayLoadBreakingPoint : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};

class RscDisplayLoadMission : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};

class RscDisplayLoadCustom : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};

class RscDisplayNotFreeze : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};

class RscDisplayClientWait : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};

/*
class RscDisplayClient : RscStandardDisplay 
{
	#include "LoadingScreenBase.hpp"
};


*/

class RscDisplayLoading {
	idd = 102;
	onLoad = "[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\Loading\RscDisplayLoading.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""breakingpoint_ui\scripts\Loading\RscDisplayLoading.sqf""";
	
	class Variants {
		class LoadingOne : RscDisplayLoadBreakingPoint {};
		class Loading : RscDisplayLoadBreakingPoint {};
	};
};
