/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_nearbyPlayers = [];
_nearbyEntities = (_this select 0) nearEntities [["CAManBase","AllVehicles"], (_this select 1)];
{
	if (isPlayer _x && {alive _x}) then {
		0 = _nearbyPlayers pushBack _x;
	};
} count _nearbyEntities;

_nearbyPlayers