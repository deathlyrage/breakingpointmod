/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_body = (_this select 3);

//Remove Action
player removeAction s_player_eatbody;
s_player_eatbody = -1;

//Check Body Isn't Null
if (isNull _body) exitWith {};

//Harvest Body
[(netID player),(netID _body)] remoteExecCall ["BPServer_fnc_playerLoot",2];

//Reset Hunger
player setVariable ["lastFeed",diag_tickTime];

//Full Health
r_player_blood = r_player_bloodTotal;