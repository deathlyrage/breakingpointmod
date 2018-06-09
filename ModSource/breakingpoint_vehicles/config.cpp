/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

class CfgPatches {
	class breakingpoint_vehicles {
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.02;
		requiredAddons[] = {};
	};
};

#include "bp_old_bike\bike.hpp"
