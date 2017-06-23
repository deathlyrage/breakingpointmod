/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_dog","_dogHandle","_newMode"];
_array = _this select 3;
_dog = _array select 0;
_dogHandle = _array select 1;
_newMode = _array select 2;

if (isNull _dog) then { _dog = _dogHandle getFSMVariable "_dog"; };

player removeAction s_player_dog_combat;
s_player_dog_combat = -1;

_dogHandle setFSMVariable ["_combat",_newMode];
