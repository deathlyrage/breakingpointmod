/*
	Breaking Point - JSRS
   Created By JSRS + Valtiel
*/

#define true	1
#define false	0

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

class CfgPatches {
	class breakingpoint_jsrs {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"breakingpoint_code"};
	};
};