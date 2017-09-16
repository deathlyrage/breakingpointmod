/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

({isPlayer _x and alive _x} count ((_this select 0) nearEntities ["CAManBase", (_this select 1)]) > 0)