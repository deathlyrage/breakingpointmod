/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

class CfgPatches {
	class breakingpoint {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Animals_F","breakingpoint_infected"};
	};
};

#include "CfgVehicles.hpp"
