/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array", "_handle", "_speed", "_dog"];
_array = 	_this select 3;
_dog = _array select 0;
_handle = _array select 1;
_speed = _array select 2;

player removeAction s_player_dog_speed;
s_player_dog_speed =	-1;

_dog = 	_handle getFSMVariable "_dog";

//if(player distance _dog > 5) then {
//	[nil,player,rSAY,["dog_slowDown", 120]] call RE;
//};

_handle setFSMVariable ["_maxSpeed", _speed];
_dog setVariable ["currentSpeed", _speed];