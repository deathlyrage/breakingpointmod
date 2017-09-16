/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_television"];
_television = _this select 3;

if (isNull _television) exitWith {};

player removeAction s_player_teleOn;
s_player_teleOn = -1;

_television setVariable ["active",true];

_television setObjectTexture [1,"breakingpoint\textures\objects\television_screen1_co.paa"];